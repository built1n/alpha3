/*
 *  Alpha emulation library - CGI interface
 *  Copyright (C) 2014 Franklin Wei
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <cctype>
#include <cstdio>
#include <csignal>
#include <cstring>
#include <sstream>
#include <alpha.h>
#include <ctime>
#define MAX_PROGSIZE 16384
#define MAX_TIME 5
using namespace std;
char hex_chars[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
alpha_ctx* ctx;
bool disasm=false;
istream* in=&cin;
void run()
{
  int start=time(0), stop=start+MAX_TIME;
  if(!disasm)
    {
      while(ctx->running && time(0)<=stop)
	{
	  alpha_exec(ctx);
	}
    }
  else
    {
      while(ctx->running && time(0)<=stop)
	{
	  alpha_disasm(ctx);
	}
    }
  if(time(0)>=stop)
    cout << "Maximum execution time exceded.<br>Program terminated."; 
}
void parse_args(char* query) /* program is passed through GET */
{
  stringstream ss(query);
  while(ss)
    {
      string str;
      getline(ss, str, '&');
      if(str=="disasm=on")
	{
	  disasm=true;
	}
      else if(str=="disasm=off")
	{
	  disasm=false;
	}
      else if(str.substr(0, strlen("program="))==string("program="))
	{
          stringstream *ss=new stringstream(str.substr(strlen("program="), -1));
          in=ss;
        }
    }
}
int main(int argc, char* argv[])
{
  cout << "Content-type: text/html; charset=utf-8\n\n";
  vector<byte> prog;
  cout << "<html><head><title>Executing Alpha3 Program...</title></head><body>Output:<br>" << flush;
  parse_args(getenv("QUERY_STRING"));
  while(in->good() and prog.size()<MAX_PROGSIZE)
    {
      string line;
      getline(*in, line);
      for(unsigned int i=0;i<line.length();i+=2)
        {
          byte val=0xFF;
          bool good=false;
          for(int j=0;j<16;++j)
            {
              if(toupper(line[i+1])==hex_chars[j])
                {
                  val=j;
                  good=true;
                }
            }
          if(!good)
            {
              cout << "Bad hex input.\n";
              return 1;
            }
          good=false;
          for(int j=0;j<16;++j)
            {
              if(toupper(line[i])==hex_chars[j])
                {
                  val|=((j&0xF)<<4);
                  good=true;
                }
            }
          if(!good)
            {
              cout << "Bad hex input.\n";
              return 1;
            }
          prog.push_back(val);
        }
    }
  in->clear();
  byte* p=(byte*)malloc(prog.size());
  for(unsigned int i=0;i<prog.size();++i)
    p[i]=prog[i];
  ctx=alpha_init((byte*)p, // memory
		 prog.size());
  run();
  if(ctx->error_code!=0)
    {
      switch(ctx->error_code)
        {
        case ALPHA_OUT_OF_BOUNDS:
          cerr << "Bad memory access.";
          break;
        case ALPHA_DIVIDE_BY_ZERO:
          cerr << "Attempted division by zero.";
          break;
        default:
          cerr << "Unknown error.";
          break;
        }
    }
  cout << "</body></html>" << flush;
  return 0;
}
