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
void file_open(alpha_ctx*, const char*);
byte file_read(alpha_ctx*);
void file_write(alpha_ctx*, byte);
void file_close(alpha_ctx*);
void mem_out_of_bounds(alpha_ctx*, word attempt);
extern const char *newline; /* string to allow for multi-char newline sequences, or HTML line breaks */
