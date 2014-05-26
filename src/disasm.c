#include <alpha.h>
#include <stdio.h>
static void disasm_00(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  printf("LD R%d, R%d\n", op3, op2);
}
static void disasm_01(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  printf("LD R%d, R%d\n", op3, op2);
}
static void disasm_02(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  printf("LD (R%d), R%d\n", op3, op2);
}
static void disasm_03(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  printf("LDHI R%d, $0x%04X\n", op1, (op2<<8)|op3);
}
static void disasm_04(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  printf("LDLO R%d, $0x%04X\n", op1, (op2<<8)|op3);
}
static void disasm_05(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  printf("EXCHG R%d, R%d\n", op2, op3);
}
static void disasm_06(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  printf("ADD R%d, R%d, R%d\n", op3, op2, op1);
}
static void disasm_07(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  printf("SUB R%d, R%d, R%d\n", op3, op2, op1);
}
static void disasm_08(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  printf("MUL R%d, R%d, R%d\n", op3, op2, op1);
}
static void disasm_09(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  printf("DIV R%d, R%d, R%d\n", op3, op2, op1);
}
static void disasm_0A(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  printf("MOD R%d, R%d, R%d\n", op3, op2, op1);
}
static void disasm_0B(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  printf("JE R%d, R%d, R%d\n", op3, op1, op2);
}
static void disasm_0C(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  printf("JNE R%d, R%d, R%d\n", op3, op1, op2);
}
static void disasm_0D(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  printf("JL R%d, R%d, R%d\n", op3, op1, op2);
}
static void disasm_0E(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  printf("JG R%d, R%d, R%d\n", op3, op1, op2);
}
static void disasm_0F(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  printf("JLE R%d, R%d, R%d\n", op3, op1, op2);
}
static void disasm_10(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  printf("JGE R%d, R%d, R%d\n", op3, op1, op2);
}
static void disasm_11(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  printf("AND R%d, R%d, R%d\n", op3, op1, op2);
}
static void disasm_12(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  printf("OR R%d, R%d, R%d\n", op3, op1, op2);
}
static void disasm_13(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  printf("XOR R%d, R%d, R%d\n", op3, op1, op2);
}
static void disasm_14(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  printf("LSH R%d, R%d, R%d\n", op3, op1, op2);
}
static void disasm_15(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  printf("RSH R%d, R%d, R%d\n", op3, op1, op2);
}
static void disasm_16(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  printf("NOT R%d, R%d\n", op3, op2);
}
static void disasm_17(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  printf("OUT R%d, R%d\n", op3, op2);
}
static void disasm_18(alpha_ctx* ctx, byte op1, byte op2, byte op3)
{
  printf("IN R%d, R%d\n", op3, op2);
}
void disasm_opcode(alpha_ctx* ctx, byte opcode, byte op1, byte op2, byte op3)
{
  void (*disasm_table[256])(alpha_ctx*, byte, byte, byte) = {
    &disasm_00,
    &disasm_01,
    &disasm_02,
    &disasm_03,
    &disasm_04,
    &disasm_05,
    &disasm_06,
    &disasm_07,
    &disasm_08,
    &disasm_09,
    &disasm_0A,
    &disasm_0B,
    &disasm_0C,
    &disasm_0D,
    &disasm_0E,
    &disasm_0F,
    &disasm_10,
    &disasm_11,
    &disasm_12,
    &disasm_13,
    &disasm_14,
    &disasm_15,
    &disasm_16,
    &disasm_17,
    &disasm_18,
#include <null-table.h>
  };
  if(disasm_table[opcode])
    {
      disasm_table[opcode](ctx, op1, op2, op3);
    }
}
