#ifndef _PRINTF_H
#define _PRINTF_H

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
