/*
 *  Alpha emulation library
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
#include <ports.h>
#include <platform.h>
void port_out(alpha_ctx* ctx, byte port, byte val)
{
  switch(port)
    {
    case 0:
      term_write(val);
      break;
    case 32:
      file_write(ctx, val);
      break;
    case 128:
      if(ctx->ports.reading_filename && ctx->ports.file_back<MAX_FILE_NAME-1)
	{
	  ctx->ports.file_name[ctx->ports.file_back]=val;
	  if(!val)
	    {
	      ctx->ports.reading_filename=false;
	      file_open(ctx, ctx->ports.file_name);
	      ctx->ports.file_open=true;
	    }
	  ++ctx->ports.file_back;
	}
      else
	{
	  switch(val)
	    {
	    case 0xFF:
	      ctx->running=false;
 	      ctx->return_value=ctx->regs[0];
	      break;
	    case 0x80:
	      if(!ctx->ports.file_open)
		{
		  ctx->ports.file_back=0;
		  ctx->ports.reading_filename=true;
		  break;
		}
	      else
		{
		  ctx->ports.file_open=false;
		  file_close(ctx);
		}
	    }
	}
    default:
      ctx->ports.values[port]=val;
    }
}
byte port_in(alpha_ctx* ctx, byte port)
{
  switch(port)
    {
    case 1:
      return kbd_read();
    case 32:
      return file_read(ctx);
    case 255:
      return kbd_supported()|(term_supported()<<1)|(file_supported()<<2)|(ALPHA_INSTRUCTION_SET_VERSION<<3);
    default:
      return ctx->ports.values[port];
    }
}
