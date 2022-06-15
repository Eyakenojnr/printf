#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * _print - print all parameters
 * @format: list of types of arguments passed to the function
 * Return: int
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int i, j, m = 0, n = 0;
	printer ss[] = {
		{"s", print_string},{"c", print_char},
		{"d", print_int},{"i", print_int},
		{"b", print_in_bin},{"u", print_unsint},
		{"o", print_octint},{"x", print_hex},
		{"X", print_uphex},{"S", print_stringx},
		{"p", print_addr},{"R", print_rot13},
		{"r", print_rev},{"%", print_perc},
		{"l", print_long},{"h", print_short}
	};

	if (format == NULL)
		return (-1);
	va_start (ap, format);
	for (i = 0; format[i] && format; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; j < 16; j++)
			{
				if (*(format + i + 1) == *(ss[j].sign))
				{
					m += ss[j].print(ap, format, i);
					n++;
					i++;
					if (j == 14 || j == 15)
					{
						i++;
						m--;
					}
					break;
				}
				if (j == 15 && format[i + 1] == '\0')
					m--;
				if (j == 15 && format[i + 1] != '\0')
					_putchar('%');
			}
		}
		else
			_putchar(format[i]);
	}
	va_end (ap);
    return ((i - (n * 2)) + m);
}
