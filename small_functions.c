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
