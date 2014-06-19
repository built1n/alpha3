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

/* 
 *  A platform implementation for POSIX-like systems
 */

#include <platform.h>
#include <stdio.h>
const char* newline="\n";
bool kbd_supported(void)
{
  return true;
}
bool term_supported(void)
{
  return true;
}
bool file_supported(void)
{
  return true;
}
byte kbd_read(void)
{
  return getchar();
}
void term_write(byte c)
{
  putchar((char)c);
  fflush(stdout);
}
void file_open(alpha_ctx* ctx, const char* file)
{
  ctx->file_ptr=fopen(file, "rw+");
}
byte file_read(alpha_ctx* ctx)
{
  if(ctx->ports.file_open)
    {
      char c;
      fread(&c, 1, 1, (FILE*)ctx->file_ptr);
      return c;
    }
  return 0;
}
void file_write(alpha_ctx* ctx, byte b)
{
  if(ctx->ports.file_open)
    fwrite(&b, 1, 1, ctx->file_ptr);
  return;
} 
void file_close(alpha_ctx* ctx)
{
  fclose(ctx->file_ptr);
  return;
}
void mem_out_of_bounds(alpha_ctx* ctx, word attempt)
{
  printf("Bad memory access at 0x%08X\nAttempted address: 0x%08X", ctx->regs[PC], attempt);  
}
void invalid_instruction(alpha_ctx* ctx)
{
  printf("Invalid instruction at address 0x%08X\n", ctx->regs[PC]);
}
