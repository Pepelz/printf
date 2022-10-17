#include "main.h"
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

/**
 * _printf - my print function
 * @format: string to be passed
 * Return: no of characters printed
 */

int _printf(const char *format, ...)
{
	char buffer[100];
	char *str;
	int i = 0, j = 0;
	va_list tob;

	va_start(tob, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
				{
					buffer[j] = (char)va_arg(tob, int);
					j++;
					break;
				}
				case 's':
				{
					str = va_arg(tob, char*);
					strcpy(&buffer[j], str);
					j += strlen(str);
					break;
				}
			}
		}
		else
		{
			buffer[j] = format[i];
			j++;
		}
		i++;
	}
	va_end(tob);

	write(1, buffer, j);
	return (j);
}
