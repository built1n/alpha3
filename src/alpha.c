#include <alpha.h>
alpha_ctx* alpha_init(byte* mem, word memsz)
{
  alpha_ctx* ret=malloc(sizeof(alpha_ctx));
  ret->memsz=memsz;
  ret->mem=mem;
  for(int i=0;i<256;++i)
    {
      ret->regs[i]=0;
    }
  ret->running=true;
  return ret;
}
void alpha_exec(alpha_ctx* ctx)
{
  word instr=readWord(ctx, ctx->regs[PC]);
  exec_opcode(ctx, (instr&0xFF000000)>>24, (instr&0xFF0000)>>16, (instr&0xFF00)>>8, (instr&0xFF));
  ctx->regs[PC]+=4;
}
