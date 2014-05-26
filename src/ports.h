#ifndef PORTS_H_
#define PORTS_H_
#include <alpha.h>
#define MAX_FILE_NAME 256
void port_out(alpha_ctx* ctx, byte port, byte val);
byte port_in(alpha_ctx* ctx, byte port);
#endif
