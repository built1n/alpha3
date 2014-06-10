#include <exec.h>
#include <util.h>
#include <platform.h>
#include <ports.h>
static void exec_00(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  ctx->regs[op3]=ctx->regs[op2];
}
static void exec_01(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  ctx->regs[op3]=readWord(ctx, ctx->regs[op2]);
}
static void exec_02(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  writeWord(ctx, ctx->regs[op3], ctx->regs[op2]);
}
static void exec_03(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  ctx->regs[op1]=(((op2 << 8)| op3) << 16)|(ctx->regs[op1]&0xFFFF);
}
static void exec_04(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  ctx->regs[op1]=(ctx->regs[op1]<<16) | ( (op2<<8) | op3);
}
static void exec_05(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  ctx->regs[op2]^=ctx->regs[op3]; /* an old IBM trick... */
  ctx->regs[op3]^=ctx->regs[op2];
  ctx->regs[op2]^=ctx->regs[op3];
}
static void exec_10(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  ctx->regs[op3]=ctx->regs[op2]+ctx->regs[op1];
}
static void exec_11(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  ctx->regs[op3]=ctx->regs[op1]-ctx->regs[op2];
}
static void exec_12(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  ctx->regs[op3]=ctx->regs[op1]*ctx->regs[op2];
}
static void exec_13(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  ctx->regs[op3]=ctx->regs[op1]/ctx->regs[op2];
}
static void exec_14(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  ctx->regs[op3]=ctx->regs[op1]%ctx->regs[op2];
}
static void exec_15(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  ctx->regs[op1]+=(op2<<8)|op3;
}
static void exec_16(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  ctx->regs[op1]-=(op2<<8)|op3;
}
static void exec_17(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  ctx->regs[op1]*=(op2<<8)|op3;
}
static void exec_18(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  ctx->regs[op1]/=(op2<<8)|op3;
}
static void exec_19(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  ctx->regs[op1]%=(op2<<8)|op3;
}
static void exec_30(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  if(ctx->regs[op1]==ctx->regs[op2])
    ctx->regs[PC]=ctx->regs[op3]-4;
}
static void exec_31(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  if(ctx->regs[op1]!=ctx->regs[op2])
    ctx->regs[PC]=ctx->regs[op3]-4;
}
static void exec_32(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  if(ctx->regs[op1]<ctx->regs[op2])
    ctx->regs[PC]=ctx->regs[op3]-4;
}
static void exec_33(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  if(ctx->regs[op1]>ctx->regs[op2])
    ctx->regs[PC]=ctx->regs[op3]-4;
}
static void exec_34(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  if(ctx->regs[op1]<=ctx->regs[op2])
    ctx->regs[PC]=ctx->regs[op3]-4;
}
static void exec_35(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  if(ctx->regs[op1]>=ctx->regs[op2])
    ctx->regs[PC]=ctx->regs[op3]-4;
}
static void exec_36(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  if(ctx->regs[op1]==0)
    {
      ctx->regs[PC]=ctx->regs[op2]+op3-4;
    }
}
static void exec_50(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  ctx->regs[op3]=ctx->regs[op1]&ctx->regs[op2];
}
static void exec_51(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  ctx->regs[op3]=ctx->regs[op1]|ctx->regs[op2];
}
static void exec_52(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  ctx->regs[op3]=ctx->regs[op1]^ctx->regs[op2];
}
static void exec_53(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  ctx->regs[op3]=ctx->regs[op1]<<ctx->regs[op2];
}
static void exec_54(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  ctx->regs[op3]=ctx->regs[op1]>>ctx->regs[op2];
}
static void exec_55(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  ctx->regs[op3]=ctx->regs[op1]<<op2;
}
static void exec_56(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  ctx->regs[op3]=ctx->regs[op1]>>op2;
}
static void exec_57(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  ctx->regs[op3]=~ctx->regs[op2];
}
static void exec_80(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  port_out(ctx, ctx->regs[op3]&0xFF, ctx->regs[op2]&0xFF);
}
static void exec_81(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  ctx->regs[op3]=port_in(ctx, ctx->regs[op2]);
}
static void exec_82(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  port_out(ctx, op2, ctx->regs[op3]&0xFF);
}
static void exec_83(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  ctx->regs[op3]=port_in(ctx, op2);
}
static void exec_90(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  writeWord(ctx, ctx->regs[op3], ctx->regs[op2]);
  ctx->regs[op3]+=4;
}
static void exec_91(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  ctx->regs[op3]-=4;
  ctx->regs[op2]=readWord(ctx, ctx->regs[op3]);
}
static void exec_C0(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  if(op2<=op3)
    {
      for(byte i=op2;i<=op3;++i)
        {
          ctx->regs[i]=0;
        }
    }
  else
    {
      invalid_instruction(ctx);
      ctx->running=false;
      ctx->return_value=ALPHA_ERROR;
    }     
}
static void exec_unknown(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  invalid_instruction(ctx);
}
static void exec_nop(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
}
static void (*exec_table[256])(alpha_ctx*, byte, byte, byte)={
#include "exec_table.h"
};
void exec_opcode(alpha_ctx* ctx, byte opcode, byte op1, byte op2, byte op3)
{
  if(exec_table[opcode])
    {
      exec_table[opcode](ctx, op1, op2, op3);
    }
}
