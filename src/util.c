#include <util.h>
#include <platform.h>
#include <stdlib.h>
void writeWord(alpha_ctx* ctx, word addr, word val)
{
  if(addr<ctx->memsz-3)
    {
      ctx->mem[addr+3]=val&0xFF;
      ctx->mem[addr+2]=(val&0xFF00)<<8;
      ctx->mem[addr+1]=(val&0xFF0000)<<16;
      ctx->mem[addr]=(val&0xFF000000)<<24;
    }
  else
    {
      mem_out_of_bounds(ctx, addr);
      ctx->running=false;
      ctx->return_value=ALPHA_ERROR;
    }
}
word readWord(alpha_ctx* ctx, word addr)
{
  if(addr<ctx->memsz-3)
    {
      word ret=ctx->mem[addr+3];
      ret|=ctx->mem[addr+2]<<8;
      ret|=ctx->mem[addr+1]<<16;
      ret|=ctx->mem[addr]<<24;
      return ret;
    }
  else
    {
      mem_out_of_bounds(ctx, addr);
      ctx->running=false;
      ctx->return_value=ALPHA_ERROR;
      return 0;
    }
}
