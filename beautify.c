/* Created by gabixdev
 * Licensed under WTFPL
 * 
 * Updated and optimized by
 * Kamila Palaiologos Szewczyk
 */

#include <stdio.h>

int main(void) {
	const char whitespace = ' ', wl = 4;

	unsigned long level = 0, i;
	char c, ignore_next = 0, in_string = 0, j;

	while (!feof(stdin) && (c = getchar()) + 1) {
		switch (c) {
			case '[':
			case '{':
				putchar(c);
				if (!in_string) {
					++level;
					putchar('\n');
					for (i = 0; i < level; i++)
						for(j = 0; j < wl; j++)
							putchar(whitespace);
				}
				break;
			case ']':
			case '}':
				if (!in_string) {
					if (level != 0)
						level--;
					putchar('\n');
					for (i = 0; i < level; i++)
						for(j = 0; j < wl; j++)
							putchar(whitespace);
				}
				putchar(c);
				break;
			case ',':
				putchar(c);
				if (!in_string) {
					putchar('\n');
					for (i = 0; i < level; i++)
						for(j = 0; j < wl; j++)
							putchar(whitespace);
				}
				break;
			case '\\':
				ignore_next = !ignore_next;
				putchar(c);
				break;
			case '"':
				if (!ignore_next)
					in_string = !in_string;
				putchar(c);
				break;
			case ' ':
				if (in_string)
					putchar(c);
				break;
			case ':':
				putchar(c);
				if (!in_string)
					putchar(' ');
				break;
			case '\r':
			case '\n':
				break;
			default:
				if (ignore_next)
					ignore_next = 0;
				putchar(c);
				break;
		}
	}
}
