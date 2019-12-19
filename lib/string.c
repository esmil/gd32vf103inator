/*
 * Copyright (c) 2019, Emil Renner Berthing
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
#include <stdint.h>
#include <string.h>

int memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *p1;
	const unsigned char *p2;

	if (s1 == s2)
		return 0;

	p1 = s1;
	p2 = s2;
	for (size_t i = 0; i < n; i++) {
		int a = p1[i];
		int b = p2[i];

		if (a != b)
			return a - b;
	}

	return 0;
}

void *memset(void *s, int c, size_t n)
{
	unsigned char *dest = s;
	unsigned char *end = dest + n;

	while (dest < end) {
		*dest = c;
		dest++;
	}

	return s;
}

void *memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	char *cdest = dest;
	const char *csrc = src;

	for (; n; n--)
		*cdest++ = *csrc++;

	return dest;
}

void *memmove(void *dest, const void *src, size_t n)
{
	char *cdest = dest;
	const char *csrc = src;

	if (cdest > csrc && cdest < csrc + n) {
		cdest += n;
		csrc += n;
		for (; n; n--)
			*--cdest = *--csrc;
	} else {
		for (; n; n--)
			*cdest++ = *csrc++;
	}

	return dest;
}

size_t strlen(const char *s)
{
	const char *e = s;

	while (*e != '\0')
		e++;

	return (uintptr_t)e - (uintptr_t)s;
}

int strcmp(const char *s1, const char *s2)
{
	int a;
	int b;

	do {
		a = *s1++;
		b = *s2++;
	} while (a == b && a != '\0');

	return a - b;
}

int strncmp(const char *s1, const char *s2, size_t n)
{
	int a;
	int b;

	if (n == 0)
		return 0;

	for (size_t i = 0; i < n; i++) {
		a = s1[i];
		b = s2[i];
		if (a != b || a == '\0')
			break;
	}

	return a - b;
}

char *strchr(const char *s, int c)
{
	while (1) {
		int b = *s;

		if (b == c)
			return (char *)s;
		if (b == '\0')
			return NULL;

		s++;
	}
}

char *strrchr(const char *s, int c)
{
	char *ret = NULL;

	while (1) {
		int b = *s;

		if (b == c)
			ret = (char *)s;
		if (b == '\0')
			return ret;

		s++;
	}
}
