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
static void exec_06(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  ctx->regs[op3]=ctx->regs[op2]+ctx->regs[op1];
}
static void exec_07(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  ctx->regs[op3]=ctx->regs[op1]-ctx->regs[op2];
}
static void exec_08(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  ctx->regs[op3]=ctx->regs[op1]*ctx->regs[op2];
}
static void exec_09(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  ctx->regs[op3]=ctx->regs[op1]/ctx->regs[op2];
}
static void exec_0A(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  ctx->regs[op3]=ctx->regs[op1]%ctx->regs[op2];
}
static void exec_0B(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  if(ctx->regs[op1]==ctx->regs[op2])
    ctx->regs[PC]=ctx->regs[op3]-4;
}
static void exec_0C(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  if(ctx->regs[op1]!=ctx->regs[op2])
    ctx->regs[PC]=ctx->regs[op3]-4;
}
static void exec_0D(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  if(ctx->regs[op1]<ctx->regs[op2])
    ctx->regs[PC]=ctx->regs[op3]-4;
}
static void exec_0E(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  if(ctx->regs[op1]>ctx->regs[op2])
    ctx->regs[PC]=ctx->regs[op3]-4;
}
static void exec_0F(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  if(ctx->regs[op1]<=ctx->regs[op2])
    ctx->regs[PC]=ctx->regs[op3]-4;
}
static void exec_10(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  if(ctx->regs[op1]>=ctx->regs[op2])
    ctx->regs[PC]=ctx->regs[op3]-4;
}
static void exec_11(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  ctx->regs[op3]=ctx->regs[op1]&ctx->regs[op2];
}
static void exec_12(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  ctx->regs[op3]=ctx->regs[op1]|ctx->regs[op2];
}
static void exec_13(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  ctx->regs[op3]=ctx->regs[op1]^ctx->regs[op2];
}
static void exec_14(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  ctx->regs[op3]=ctx->regs[op1]<<ctx->regs[op2];
}
static void exec_15(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  ctx->regs[op3]=ctx->regs[op1]>>ctx->regs[op2];
}
static void exec_16(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  ctx->regs[op3]=~ctx->regs[op2];
}
static void exec_17(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  port_out(ctx, ctx->regs[op3]&0xFF, ctx->regs[op2]&0xFF);
}
static void exec_18(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  ctx->regs[op3]=port_in(ctx, ctx->regs[op2]);
}
static void exec_19(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  writeWord(ctx, ctx->regs[op3], ctx->regs[op2]);
  ctx->regs[op3]+=4;
}
static void exec_1A(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  ctx->regs[op3]-=4;
  ctx->regs[op2]=readWord(ctx, ctx->regs[op3]);
}
void exec_opcode(alpha_ctx* ctx, byte opcode, byte op1, byte op2, byte op3)
{
  void (*exec_table[256])(alpha_ctx*, byte, byte, byte) = {
    &exec_00,
    &exec_01,
    &exec_02,
    &exec_03,
    &exec_04,
    &exec_05,
    &exec_06,
    &exec_07,
    &exec_08,
    &exec_09,
    &exec_0A,
    &exec_0B,
    &exec_0C,
    &exec_0D,
    &exec_0E,
    &exec_0F,
    &exec_10,
    &exec_11,
    &exec_12,
    &exec_13,
    &exec_14,
    &exec_15,
    &exec_16,
    &exec_17,
    &exec_18,
    &exec_19,
    &exec_1A,
#include <null-table.h>
  };
  if(exec_table[opcode])
    {
      exec_table[opcode](ctx, op1, op2, op3);
    }
}
