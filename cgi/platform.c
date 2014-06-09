#include <platform.h>
#include <stdio.h>
const char* newline="<br>";
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
  return false;
}
byte kbd_read(void)
{
  return getchar();
}
void term_write(byte c)
{
  if(c!='\n')
    putchar((char)c);
  else
    puts("<br>");
  fflush(stdout);
}
void file_open(alpha_ctx* ctx, const char* file)
{
  printf("Access to file ABI denied.<br>");
}
byte file_read(alpha_ctx* ctx)
{
  printf("Access to file ABI denied.<br>");
  return 0;
}
void file_write(alpha_ctx* ctx, byte b)
{
  printf("Access to file ABI denied.<br>");
} 
void file_close(alpha_ctx* ctx)
{
  printf("Access to file ABI denied.<br>");
}
void mem_out_of_bounds(alpha_ctx* ctx, word attempt)
{
  printf("Bad memory access at 0x%08X<br>Attempted address: 0x%08X", ctx->regs[PC], attempt);
}
void invalid_instruction(alpha_ctx* ctx)
{
  printf("Invalid instruction at address 0x%08X<br>", ctx->regs[PC]);
}
