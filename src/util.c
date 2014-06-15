#include <util.h>
#include <platform.h>
#include <stdlib.h>
void writeWord(alpha_ctx* ctx, word addr, word val)
{
  if(addr<(int64_t)ctx->memsz-3)
    {
      ctx->mem[addr+3]=val&0xFF;
      ctx->mem[addr+2]=(val&0xFF00)<<8;
      ctx->mem[addr+1]=(val&0xFF0000)<<16;
      ctx->mem[addr]=(val&0xFF000000)<<24;
    }
  else
    {
      invalid_instruction(ctx);
      ctx->running=false;
      ctx->return_value=ALPHA_ERROR;
      ctx->error_code=ALPHA_OUT_OF_BOUNDS;
    }
}
word readWord(alpha_ctx* ctx, word addr)
{
  if(addr<(int64_t)ctx->memsz-3)
    {
      word ret=ctx->mem[addr+3];
      ret|=ctx->mem[addr+2]<<8;
      ret|=ctx->mem[addr+1]<<16;
      ret|=ctx->mem[addr]<<24;
      return ret;
    }
  else
    {
      invalid_instruction(ctx);
      ctx->running=false;
      ctx->return_value=ALPHA_ERROR;
      ctx->error_code=ALPHA_OUT_OF_BOUNDS;
      return 0;
    }
}
