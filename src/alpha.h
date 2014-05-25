#ifndef ALPHA_H_
#define ALPHA_H_
#include <stdint.h>
#include <stdbool.h>
typedef uint8_t byte;
typedef uint32_t word;
#define PC 255
typedef struct alpha_ctx {
  word regs[256];
  byte* mem;
  word memsz;
  bool running;
} alpha_ctx;
void alpha_exec(alpha_ctx*);
alpha_ctx* alpha_init(byte* mem, word memsz);
#endif
