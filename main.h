#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1
#define FIELD_BUF_SIZE 50
#define NULL_STRING "(null)"
#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/**
 * struct parameters - parameters of struct
 *
 * @unsign: flag if unsigned value
 *
 * @plus_flag: on if plus_flag is specified
 * @space_flag: on if hashtag_flag is specified
 * @hashtag_flag: on if _flag is specified
 * @zero_flag: on if _flag is specified
 * @minus_flag: on if _flag is specified
 *
 * @width: field width
 * @precision: field precision
 *
 * @h_modifier: on if h_modifier is specified
 * @l_modifier: on if a l_modifier is specified
 */
typedef struct parameters
{
	unsigned int unsign        : 1;
	
	unsigned int plus_flag     : 1;
	unsigned int space_flag    : 1;
	unsigned int hashtag_flag  : 1;
	unsigned int zero_flag     : 1;
	unsigned int minus_flag    : 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier		: 1;
	unsigned int l_modifier		: 1;
} params_t;

/**
 * struct specifier - Struct token
 *
 * @specifier: format token
 * @f: The function associated
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

/* _put.c module */
int _puts(char *str);
int _putchar(int c);

/* print_functions.c module */
int print_char(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);
int print_S(va_list ap, params_t *params);

/* number.c module */
char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list ap, params_t *params);
int print_address(va_list ap, params_t *params);

/* specifier.c module */
int (*get_specifier(char *s))(va_list ap, params_t *params);
int get_print_func(char *s, va_list ap, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list ap);

/* convert_number.c module */
int print_hex(va_list ap, params_t *params);
int print_HEX(va_list ap, params_t *params);
int print_binary(va_list ap, params_t *params);
int print_octal(va_list ap, params_t *params);

/* simple_printers.c module */
int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list ap, params_t *params);
int print_rot13(va_list ap, params_t *params);
