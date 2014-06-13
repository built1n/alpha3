#include <alpha.h>
#include <stdio.h>
#include <stdint.h>
#include <platform.h>
static void disasm_00(alpha_ctx* ctx, byte opcode, byte op1, byte op2, byte op3)
{
  printf("LD R%d, R%d%s", op3, op2, newline);
}
static void disasm_01(alpha_ctx* ctx, byte opcode, byte op1, byte op2, byte op3)
{
  printf("LD R%d, (R%d)%s", op3, op2, newline);
}
static void disasm_02(alpha_ctx* ctx, byte opcode, byte op1, byte op2, byte op3)
{
  printf("LD (R%d), R%d%s", op3, op2, newline);
}
static void disasm_03(alpha_ctx* ctx, byte opcode, byte op1, byte op2, byte op3)
{
  printf("LDHI R%d, $0x%04X%s", op1, (op2<<8)|op3, newline);
}
static void disasm_04(alpha_ctx* ctx, byte opcode, byte op1, byte op2, byte op3)
{
  printf("LDLO R%d, $0x%04X%s", op1, (op2<<8)|op3, newline);
}
static void disasm_05(alpha_ctx* ctx, byte opcode, byte op1, byte op2, byte op3)
{
  printf("EXCHG R%d, R%d%s", op2, op3, newline);
}
static void disasm_10(alpha_ctx* ctx, byte opcode, byte op1, byte op2, byte op3)
{
  printf("ADD R%d, R%d, R%d%s", op1, op2, op3, newline);
}
static void disasm_11(alpha_ctx* ctx, byte opcode, byte op1, byte op2, byte op3)
{
  printf("SUB R%d, R%d, R%d%s", op1, op2, op3, newline);
}
static void disasm_12(alpha_ctx* ctx, byte opcode, byte op1, byte op2, byte op3)
{
  printf("MUL R%d, R%d, R%d%s", op1, op2, op3, newline);
}
static void disasm_13(alpha_ctx* ctx, byte opcode, byte op1, byte op2, byte op3)
{
  printf("DIV R%d, R%d, R%d%s", op1, op2, op3, newline);
}
static void disasm_14(alpha_ctx* ctx, byte opcode, byte op1, byte op2, byte op3)
{
  printf("MOD R%d, R%d, R%d%s", op1, op2, op3, newline);
}
static void disasm_15(alpha_ctx* ctx, byte opcode, byte op1, byte op2, byte op3)
{
  printf("ADD R%d, $0x%04X%s", op1, ((op2<<8)|op3), newline);
}
static void disasm_16(alpha_ctx* ctx, byte opcode, byte op1, byte op2, byte op3)
{
  printf("SUB R%d, $0x%04X%s", op1, ((op2<<8)|op3), newline);
}
static void disasm_17(alpha_ctx* ctx, byte opcode, byte op1, byte op2, byte op3)
{
  printf("MUL R%d, $0x%04X%s", op1, ((op2<<8)|op3), newline);
}
static void disasm_18(alpha_ctx* ctx, byte opcode, byte op1, byte op2, byte op3)
{
  printf("DIV R%d, $0x%04X%s", op1, ((op2<<8)|op3), newline);
}
static void disasm_19(alpha_ctx* ctx, byte opcode, byte op1, byte op2, byte op3)
{
  printf("MOD R%d, $0x%04X%s", op1, ((op2<<8)|op3), newline);
}
static void disasm_30(alpha_ctx* ctx, byte opcode, byte op1, byte op2, byte op3)
{
  printf("JE R%d, R%d, R%d%s", op3, op1, op2, newline);
}
static void disasm_31(alpha_ctx* ctx, byte opcode, byte op1, byte op2, byte op3)
{
  printf("JNE R%d, R%d, R%d%s", op3, op1, op2, newline);
}
static void disasm_32(alpha_ctx* ctx, byte opcode, byte op1, byte op2, byte op3)
{
  printf("JL R%d, R%d, R%d%s", op3, op1, op2, newline);
}
static void disasm_33(alpha_ctx* ctx, byte opcode, byte op1, byte op2, byte op3)
{
  printf("JG R%d, R%d, R%d%s", op3, op1, op2, newline);
}
static void disasm_34(alpha_ctx* ctx, byte opcode, byte op1, byte op2, byte op3)
{
  printf("JLE R%d, R%d, R%d%s", op3, op1, op2, newline);
}
static void disasm_35(alpha_ctx* ctx, byte opcode, byte op1, byte op2, byte op3)
{
  printf("JGE R%d, R%d, R%d%s", op3, op1, op2, newline);
}
static void disasm_50(alpha_ctx* ctx, byte opcode, byte op1, byte op2, byte op3)
{
  printf("AND R%d, R%d, R%d%s", op3, op1, op2, newline);
}
static void disasm_51(alpha_ctx* ctx, byte opcode, byte op1, byte op2, byte op3)
{
  printf("OR R%d, R%d, R%d%s", op3, op1, op2, newline);
}
static void disasm_52(alpha_ctx* ctx, byte opcode, byte op1, byte op2, byte op3)
{
  printf("XOR R%d, R%d, R%d%s", op3, op1, op2, newline);
}
static void disasm_53(alpha_ctx* ctx, byte opcode, byte op1, byte op2, byte op3)
{
  printf("LSH R%d, R%d, R%d%s", op3, op1, op2, newline);
}
static void disasm_54(alpha_ctx* ctx, byte opcode, byte op1, byte op2, byte op3)
{
  printf("RSH R%d, R%d, R%d%s", op3, op1, op2, newline);
}
static void disasm_55(alpha_ctx* ctx, byte opcode, byte op1, byte op2, byte op3)
{
  printf("LSH R%d, $0x%02X, R%d%s", op1, op2, op3, newline);
}
static void disasm_56(alpha_ctx* ctx, byte opcode, byte op1, byte op2, byte op3)
{
  printf("RSH R%d, $0x%02X, R%d%s", op1, op2, op3, newline);
}
static void disasm_57(alpha_ctx* ctx, byte opcode, byte op1, byte op2, byte op3)
{
  printf("NOT R%d, R%d%s", op3, op2, newline);
}
static void disasm_80(alpha_ctx* ctx, byte opcode, byte op1, byte op2, byte op3)
{
  printf("OUT R%d, R%d%s", op3, op2, newline);
}
static void disasm_81(alpha_ctx* ctx, byte opcode, byte op1, byte op2, byte op3)
{
  printf("IN R%d, R%d%s", op3, op2, newline);
}
static void disasm_82(alpha_ctx* ctx, byte opcode, byte op1, byte op2, byte op3)
{
  printf("OUT R%d, $0x%02X%s", op3, op2, newline);
}
static void disasm_83(alpha_ctx* ctx, byte opcode, byte op1, byte op2, byte op3)
{
  printf("IN R%d, $0x%02X%s", op3, op2, newline);
}
static void disasm_90(alpha_ctx* ctx, byte opcode, byte op1, byte op2, byte op3)
{
  printf("PUSH R%d, R%d%s", op2, op3, newline);
}
static void disasm_91(alpha_ctx* ctx, byte opcode, byte op1, byte op2, byte op3)
{
  printf("POP R%d, R%d%s", op3, op2, newline);
}
static void disasm_C0(alpha_ctx* ctx, byte opcode, byte op1, byte op2, byte op3)
{
  printf("ZERO R%d, R%d%s", op2, op3, newline);
}
static void disasm_nop(alpha_ctx* ctx, byte opcode, byte op1, byte op2, byte op3)
{
  printf("NOP%s", newline);
}
static void disasm_unknown(alpha_ctx* ctx, byte opcode, byte op1, byte op2, byte op3)
{
  printf("DATA 0x%08X%s", (opcode<<24)|(op1<<16)|(op2<<8)|op3, newline);
}
static void (*disasm_table[256])(alpha_ctx*, byte, byte, byte, byte) = {
#include "disasm_table.h"
};
void disasm_opcode(alpha_ctx* ctx, byte opcode, byte op1, byte op2, byte op3)
{
  printf("0x%08X: ", ctx->regs[PC]);
  disasm_table[opcode](ctx, opcode, op1, op2, op3);
}
