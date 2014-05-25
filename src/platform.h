/*
 * Provides the platform-specific interface
 */
#include <stdbool.h>
#include <alpha.h>
bool kbd_supported(void);
bool term_supported(void);
bool file_supported(void);
byte kbd_read(void);
void term_write(byte);
void file_open(const char*);
byte file_read(void);
void file_write(byte);
void file_close(void);
void mem_out_of_bounds(void);
