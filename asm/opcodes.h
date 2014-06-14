#include <alpha.h>
enum operand_type {NONE, REG, ADDR, EXP_HI, EXP_LO, EXP_BYTE};
/* Map mnemonics to opcodes */
typedef struct opcode_mapping {
  const char* mnemonic;
  byte opcode;
  int num_operands;
  enum operand_type first, second, third;
} opcode_mapping;
opcode_mapping opcode_table[] = {
  {"LDR", 0x00, 2, NONE, REG, REG},
  {"LDM", 0x01, 2, NONE, ADDR, REG},
  {"LDS", 0x02, 2, NONE, REG, ADDR},
  {"LDHI", 0x03, 3, REG, EXP_HI, EXP_LO},
  {"LDLO", 0x04, 3, REG, EXP_HI, EXP_LO},
  
  {"ADD", 0x10, 3, REG, REG, REG},
  {"SUB", 0x11, 3, REG, REG, REG},
  {"MUL", 0x12, 3, REG, REG, REG},
  {"DIV", 0x13, 3, REG, REG, REG},
  {"MOD", 0x14, 3, REG, REG, REG},
  
  {"ADDX", 0x15, 3, REG, EXP_HI, EXP_LO},
  {"SUBX", 0x16, 3, REG, EXP_HI, EXP_LO},
  {"MULX", 0x17, 3, REG, EXP_HI, EXP_LO},
  {"DIVX", 0x18, 3, REG, EXP_HI, EXP_LO},
  {"MODX", 0x19, 3, REG, EXP_HI, EXP_LO},
  
  {"JE", 0x30, 3, REG, REG, REG},
  {"JNE", 0x31, 3, REG, REG, REG},
  {"JL", 0x32, 3, REG, REG, REG},
  {"JG", 0x33, 3, REG, REG, REG},
  {"JLE", 0x34, 3, REG, REG, REG},
  {"JGE", 0x35, 3, REG, REG, REG},
  
  {"AND", 0x50, 3, REG, REG, REG},
  {"OR", 0x51, 3, REG, REG, REG},
  {"XOR", 0x52, 3, REG, REG, REG},
  {"LSH", 0x53, 3, REG, REG, REG},
  {"RSH", 0x54, 3, REG, REG, REG},
  {"LSHX", 0x55, 3, REG, EXP_BYTE, REG},
  {"RSHX", 0x56, 3, REG, EXP_BYTE, REG},
  {"NOT", 0x57, 2, NONE, REG, REG},
  
  {"OUT", 0x80, 2, NONE, REG, REG},
  {"IN", 0x81, 2, NONE, REG, REG},
  {"OUTX", 0x82, 2, NONE, REG, EXP_BYTE},
  {"INX", 0x83, 2, NONE, EXP_BYTE, REG},
  
  {"PUSH", 0x90, 2, NONE, REG, REG},
  {"POP", 0x91, 2, NONE, REG, REG},
  
  {"ZERO", 0xC0, 2, NONE, EXP_BYTE, EXP_BYTE},
  {"NOP", 0xFF, 0, NONE, NONE, NONE}
};
    
#define NUM_OPCODES 37
