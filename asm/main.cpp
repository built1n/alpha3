#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <alpha.h>
#include <cstdlib>
#include <cstdio>
#include <opcodes.h>
using namespace std;
void write(int b)
{
  printf("%c", b&0xFF);
}
int main(int argc, char* argv[])
{
  int current_line=1;
  cout << "FW";
  while(cin)
    {
      string line;
      getline(cin, line);
      stringstream ss(line);
      string opcode;
      int op1, op2, op3; /* all operands can be simplified to ints */
      int num_args=0;
      ss >> opcode;

      if(ss)
        ++num_args;
      ss >> op1;

      if(ss)
        ++num_args;
      ss >> op2;

      if(ss)
        ++num_args;
      ss >> op3;
      if(opcode=="BYTE" && num_args==1)
        {
          write(op1);
        }
      /* now assemble */
      for(int i=0;i<NUM_OPCODES;++i)
        {    
          if(opcode==string(opcode_table[i].mnemonic))
            {
              if(num_args!=opcode_table[i].num_operands)
                {
                  cout << "line " << current_line << ": error: need " << opcode_table[i].num_operands << " operands, got " << num_args << "!\n";
                  return 1;
                }
              write(opcode_table[i].opcode);
              switch(opcode_table[i].first)
                {
                case NONE:
                  write(0x00);
                  break;
                case REG:
                case ADDR:
                case EXP_HI:
                case EXP_LO:
                case EXP_BYTE:
                  write(op1);
                  break;
                default:
                  break;
                }
              switch(opcode_table[i].second)
                {
                case NONE:
                  write(0x00);
                  break;
                case REG:
                case ADDR:
                case EXP_HI:
                case EXP_LO:
                case EXP_BYTE:
                  write(op2);
                  break;
                default:
                  break;
                }
              switch(opcode_table[i].third)
                {
                case NONE:
                  write(0x00);
                  break;
                case REG:
                case ADDR:
                case EXP_HI:
                case EXP_LO:
                case EXP_BYTE:
                  write(op3);
                  break;
                default:
                  break;
                } /* if */
            } /* for */
        } /* while */
      ++current_line;
    }
}
