#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

extern char command[256];

// ############################################################
// ######################### CHECKLANG ##########################

// Checks whether there is support for this language

// For checking whether the given language is supported
short int checklang (char argument[192])
{
	if (strcmp(argument, "sb") == 0)
		return TRUE;
	else if (strcmp(argument, "en") == 0 || strcmp(argument, "en-us") == 0 || strcmp(argument, "en-br") == 0)
		return TRUE;
	else if (strcmp(argument, "pt") == 0 || strcmp(argument, "pt-br") == 0 || strcmp(argument, "pt-eu") == 0)
		return TRUE;
	else if (strcmp(argument, "fr") == 0 || strcmp(argument, "fr-eu") == 0)
		return TRUE;
	else if (strcmp(argument, "es") == 0)
		return TRUE;
	else if (strcmp(argument, "eo") == 0)
		return TRUE;
	else
		return FALSE;
}

void remove_capital_letters (char argument[192])
{
	short int counter = 0;

	while (argument[counter] != '\0')
	{
		if (argument[counter]	 == 'A') argument[counter]	 = 'a';
		else if (argument[counter]	 == 'B') argument[counter]	 = 'b';
		else if (argument[counter]	 == 'C') argument[counter]	 = 'c';
		else if (argument[counter]	 == 'D') argument[counter]	 = 'd';
		else if (argument[counter]	 == 'E') argument[counter]	 = 'e';
		else if (argument[counter]	 == 'F') argument[counter]	 = 'f';
		else if (argument[counter]	 == 'G') argument[counter]	 = 'g';
		else if (argument[counter]	 == 'H') argument[counter]	 = 'h';
		else if (argument[counter]	 == 'I') argument[counter]	 = 'i';
		else if (argument[counter]	 == 'J') argument[counter]	 = 'j';
		else if (argument[counter]	 == 'K') argument[counter]	 = 'k';
		else if (argument[counter]	 == 'L') argument[counter]	 = 'l';
		else if (argument[counter]	 == 'M') argument[counter]	 = 'm';
		else if (argument[counter]	 == 'N') argument[counter]	 = 'n';
		else if (argument[counter]	 == 'O') argument[counter]	 = 'o';
		else if (argument[counter]	 == 'P') argument[counter]	 = 'p';
		else if (argument[counter]	 == 'Q') argument[counter]	 = 'q';
		else if (argument[counter]	 == 'R') argument[counter]	 = 'r';
		else if (argument[counter]	 == 'S') argument[counter]	 = 's';
		else if (argument[counter]	 == 'T') argument[counter]	 = 't';
		else if (argument[counter]	 == 'U') argument[counter]	 = 'u';
		else if (argument[counter]	 == 'V') argument[counter]	 = 'v';
		else if (argument[counter]	 == 'W') argument[counter]	 = 'w';
		else if (argument[counter]	 == 'X') argument[counter]	 = 'x';
		else if (argument[counter]	 == 'Y') argument[counter]	 = 'y';
		else if (argument[counter]	 == 'Z') argument[counter]	 = 'z';

		counter++;
	}
}
