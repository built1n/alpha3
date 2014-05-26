#include <alpha.h>
#include <exec.h>
#include <stdlib.h>
#include <util.h>
#include <stdio.h>
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
void alpha_disasm(alpha_ctx* ctx)
{
  return;
}
void alpha_print_state(alpha_ctx* ctx)
{
  printf("==Registers==\n");
  for(int i=0;i<64;++i)
    {
      printf("R%d: 0x%08X R%d: 0x%08X R%d 0x%08X R%d: 0x%08X\n", i, ctx->regs[i], 64+i, ctx->regs[64+i], 128+i, ctx->regs[128+i], 192+i, ctx->regs[192+i]);
    }
}
void alpha_exec(alpha_ctx* ctx)
{
  if(ctx->running && ctx->regs[PC]<ctx->memsz-4)
    {
      alpha_print_state(ctx);
      word instr=readWord(ctx, ctx->regs[PC]);
      exec_opcode(ctx, (instr&0xFF000000)>>24, (instr&0xFF0000)>>16, (instr&0xFF00)>>8, (instr&0xFF));
      ctx->regs[PC]+=4;
    }
  else
    ctx->running=false;
}
