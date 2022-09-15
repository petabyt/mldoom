#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ????
struct _reent *_impure_ptr __ATTRIBUTE_IMPURE_PTR__;

extern void * __mem_malloc( size_t len, unsigned int flags, const char *file, unsigned int line);
extern void __mem_free( void * buf);

// IO Game saving functions
int rename(const char *a, const char *b) {
	return 0;
}

size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream) {
	return 0;
}

int fprintf(FILE *stream, const char *format, ...) {
	return 0;
}

int fclose(FILE *stream) {
	return 0;
}

size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream) {
	return 0;
}

int fseek(FILE *stream, long offset, int whence) {
	return 0;
}

int mkdir(const char *f) {
	return 0;
}

int remove(const char *pathname) {
	return 0;
}

int fputs(const char *s, FILE *stream) {
	return 0;
}

FILE *fopen(const char *pathname, const char *mode) {
	return 0;
}

int fflush(FILE *stream) {
	return 0;
}

// ????
long ftell(FILE *stream) {
	return 0;
}

void exit(int status) {
	// ?????
}

int vfprintf(FILE *stream, const char *format, va_list ap) {
	return 0;
}

int __locale_ctype_ptr(int x) {
	return 0;
}

int __swbuf_r(struct _reent *x, int z, FILE *y) {
	return 0;
}

// Return 1 on every sys call to pretend that shell doesn't exist
int system(const char *command) {
	return 1;
}

// Somewhat important string functions
int scanf(const char *format, ...) {
	return 0;
}

int sscanf(const char *str, const char *format, ...) {
	return 0;
}

int strncasecmp(const char *a, const char *b, size_t n) {
	return strncmp(a, b, n);
}

void *malloc(size_t size) {
	__mem_malloc(size, 0, __FILE__, __LINE__);
}

void free(void *buf) {
	__mem_free(buf);
}
