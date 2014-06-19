/*
 *  Alpha emulation library
 *  Copyright (C) 2014 Franklin Wei
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * Provides the platform-specific interface for the simulator
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
void invalid_instruction(alpha_ctx* ctx);
extern const char *newline; /* string to allow for multi-char newline sequences, or HTML line breaks */
