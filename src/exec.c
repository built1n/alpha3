#include <exec.h>
#include <util.h>
#include <platform.h>
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
  ctx->regs[op1]=(((op2 << 8)| op3) << 16)|ctx->regs[op1]&0xFFFF;
}
static void exec_04(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  ctx->regs[op1]=(ctx->regs[op1]<<16)|((op2<<8)|op1);
}
static void exec_05(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  ctx->regs[op2]^=ctx->regs[op3]; /* an old trick... */
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
#include <null-table.h>
  };
  if(exec_table[opcode])
    {
      exec_table[opcode](ctx, op1, op2, op3);
    }
}
