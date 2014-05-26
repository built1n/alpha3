#ifndef ALPHA_H_
#define ALPHA_H_
#define ALPHA_VERSION 1
#define ALPHA_IMPLEMENTED_REVISION 1
#include <stdint.h>
#include <stdbool.h>
typedef uint8_t byte;
typedef uint32_t word;
#define PC 255
typedef struct ports_ctx {
  bool file_open;
  bool reading_filename;
  char file_name[256];
  int file_back;
  byte values[256];
} ports_ctx;

typedef struct alpha_ctx {
  word regs[256];
  byte* mem;
  word memsz;
  bool running;
  word return_value;
  struct ports_ctx ports;
} alpha_ctx;
#ifdef __cplusplus
extern "C"
{
#endif
  void alpha_exec(alpha_ctx*);
  void alpha_disasm(alpha_ctx*);  
  void alpha_print_state(alpha_ctx*);
  alpha_ctx* alpha_init(byte* mem, word memsz);
#ifdef __cplusplus
}
#endif
#endif
