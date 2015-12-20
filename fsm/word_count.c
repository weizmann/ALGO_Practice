#include <stdio.h>

#define OUT 0 // out of a word
#define IN	1 // inside a word

int main() {
	char c, state;
	int count = 0;
	state = OUT;
	while (scanf("%c", &c) && c != '\n') {
		if (state == OUT) {
			if (c == ' ' || c == '\t') {
				state = OUT;
			} else {
				count++;
				state = IN;
			}
		} else {
			if (c == ' ' || c == '\t') {
				state = OUT;
			} else {
				state = IN;
			}
		}
	}

	printf("total word count is %d\n", count);
	return 0;
}
