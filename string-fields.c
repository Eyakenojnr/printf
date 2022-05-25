#include "main.h"

/**
 * *get_precision - function that gets the precision from the format string
 *
 * @p: format string
 * @params: the parameters struct
 * @ap: argument pointer
 *
 * Return: new pointer
 */
char *get_precision(char *p, params_t *params, va_list ap)
{
	int d = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		d = va_arg(ap, int);
		p++;
	}
	else
		while (_isdigit(*p))
			d = d * 10 + (*ptr - '0');
	params->precision = d;
	return (p);
}
