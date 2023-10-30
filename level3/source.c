#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void no(void)
{
	puts("Nope.");
	exit(1);
}

void ok(void)
{
	puts("Good job.");
}

int main(void)
{
	char userInput[31];
	char decoded[9];
	int indexDecoded = 1;

	printf("Please enter key: ");
	if (scanf("%30s", userInput) != 1)
		no();

	if (userInput[0] != '4' || userInput[1] != '2')
		no();

	memset(decoded, 0, sizeof(decoded));
	decoded[0] = '*';

	for (int i = 2; i < strlen(userInput) && indexDecoded < 8; i += 3)
	{
		char group[4] = {userInput[i], userInput[i + 1], userInput[i + 2], '\0'};
		int asciiVal = atoi(group);
		decoded[indexDecoded++] = (char)asciiVal;
	}

	if (strcmp(decoded, "********") == 0)
		ok();
	else
		no();

	return 0;
}
