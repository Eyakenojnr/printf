#ifndef _PRINTF_H
#define _PRINTF_H

<<<<<<< HEAD
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>

#define BUF_FLUSH -1
#define OUTPUT_BUF_SIZE 1024

#define FIELD_BUF_SIZE 50

#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/**
 * struct parameters - the attributes the general structure
 * @unsign: flag if unsigned value
 *
 * @plus_flag: on fi plus_flag specified
 * @space_flag: on if hashtag_flag specified
 * @hashtag_flag: on if _flag is given
 * @zero_flag: on if _flag is given
 * @minus_flag: on if _flag is given
 *
 * @width: field width specified
 * @precision: field precision specified
 *
 * @h_modifier: on if h_modifier is given
 * @l_modifier: on if l_modifier is give
 *
 */
typedef struct parameters
{
	unsigned int unsign		: 1;
	unsigned int plus_flag		: 1;
	unsigned int hashtag_flag	: 1;
	unsigned int zero_flag		: 1;
	unsigned int minus_flag		: 1;
=======
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
>>>>>>> 70699c45feccaa5f517da9ab29fec5c04a374524

	unsigned int width;
	unsigned int precision;

<<<<<<< HEAD
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
=======
	unsigned int h_modifier    : 1;
	unsigned int l_modifier    : 1;
} params_t;
>>>>>>> 70699c45feccaa5f517da9ab29fec5c04a374524
/* _put.c module */
int _puts(char *str);
int _putchar(int c);

/* print_functions.c module */
int print_char(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);
int print_S(va_list ap, params_t *params);
