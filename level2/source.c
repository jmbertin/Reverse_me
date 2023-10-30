#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void no(void)
{
	puts("Nope.");
	exit(1);
}

void ok(void)
{
	puts("Good job.");
	return;
}

int main(void)
{
	char input[24] = {0};
	char decoded[9] = "d";

	printf("Please enter key: ");
	if (scanf("%23s", input) != 1)
		no();

	if (input[0] != '0' || input[1] != '0')
		no();

	for (int i = 2, j = 1; j < 8 && i < strlen(input); i += 3, j++)
	{
		char temp[4] = {input[i], input[i+1], input[i+2], '\0'};
		int num = atoi(temp);
		decoded[j] = (char)num;
	}

	if (strcmp(decoded, "delabere") == 0)
		ok();
	else
		no();
	return 0;
}
