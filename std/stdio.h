/*
 * Copyright (c) 2019-2020, Emil Renner Berthing
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its contributors
 *    may be used to endorse or promote products derived from this software without
 *    specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 */
#ifndef _STDIO_H
#define _STDIO_H

#include <stddef.h>
#include <stdarg.h>

typedef struct __file FILE;

typedef void __putc_t(FILE *stream, char c);
typedef int __done_t(FILE *stream);

struct __file {
	__putc_t *putc;
	__done_t *done;
};

extern FILE *stdout;
extern FILE *stderr;

int fputc(int c, FILE *stream);
int fputs(const char *s, FILE *stream);

int putchar(int c);
int puts(const char *s);

__attribute__((format(printf, 2, 3)))
int fprintf(FILE *stream, const char *format, ...);
int vfprintf(FILE *stream, const char *format, va_list ap);

__attribute__((format(printf, 1, 2)))
int printf(const char *restrict, ...);
int vprintf(const char *restrict, va_list ap);

__attribute__((format(printf, 2, 3)))
int sprintf(char *restrict str, const char *restrict, ...);
int vsprintf(char *restrict str, const char *restrict, va_list ap);

__attribute__((format(printf, 3, 4)))
int snprintf(char *restrict str, size_t size, const char *restrict, ...);
int vsnprintf(char *restrict str, size_t size, const char *restrict, va_list ap);

#endif
