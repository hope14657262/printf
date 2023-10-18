#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
va_list args;
va_start(args, format);

int chars_printed = 0;

for(int i = 0; format[i] != '\0'; i++)
{
	if(format[i] == '%')
	{
		i++;
		switch(format[i]
		{
			case 'c':
				chars_printed += printf("%c", va_arg(args, int));
				break;
			case 's':
				chars_printed += printf("%s", va_arg(args, char*)); 
				break;
			case '%':
				chars_printed += printf("%%");
				break;
			default:
				break;
		}
	} else {
		printf("%c", format[i]);
		chars_printed++;
	}
}

va_end(args);
return chars_printed;
}

int main(void) {
int chars_printed = _printf("Hello %s%c\n", "World", '!');
printf("Chars printed: %d\n", chars_printed);
  
return 0;
}
