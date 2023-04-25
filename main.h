#ifndef PRINTF_H
#define PRINTF_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define IDLE(x) (void)(x)
#define BUF_SIZE 1024

/* FLAGS */
#define FMINUS 1
#define FPLUS 2
#define FHASH 8
#define FSPACE 16
#define FZERO 4

/* SIZES */
#define SLONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct operator
 *
 * @fmt: format.
 * @fm_t: function.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list lists, char buffer[], int flags, int width, int precision, int size);

int print_char(va_list lists, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list lists, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list lists, char buffer[],
	int flags, int width, int precision, int size);


int print_int(va_list lists, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list lists, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list lists, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list lists, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list lists, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list lists, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa(va_list lists, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

int non_prints(va_list lists, char buffer[],
	int flags, int width, int precision, int size);

int print_pointer(va_list lists, char buffer[],
	int flags, int width, int precision, int size);

int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list lists);
int get_precision(const char *format, int *i, va_list lists);
int get_size(const char *format, int *i);

int print_rot13string(va_list lists, char buffer[],
	int flags, int width, int precision, int size);

int print_reverse(va_list lists, char buffer[],
	int flags, int width, int precision, int size);

int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);

int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* PRINTF_H */
