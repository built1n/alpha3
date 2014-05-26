#include <platform.h>
#include <stdio.h>
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
  putchar((char)c);
}
void file_open(alpha_ctx* ctx, const char* file)
{
  return;
}
byte file_read(alpha_ctx* ctx)
{
  return 0;
}
void file_write(alpha_ctx* ctx, byte b)
{
  return;
} 
void file_close(alpha_ctx* ctx)
{
  return;
}
void mem_out_of_bounds(alpha_ctx* ctx)
{
  printf("Bad memory access at 0x%08X\n", ctx->regs[PC]);
}
