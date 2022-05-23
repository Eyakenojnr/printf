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
	unsigned int unsign :1;
	
	unsigned int plus_flag :1;
	unsigned int space_flag :1;
	unsigned int hashtag_flag :1;
	unsigned int zero_flag :1;
	unsigned int minus_flag :1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier :1;
	unsigned int l_modifier :1;
} params_t;
