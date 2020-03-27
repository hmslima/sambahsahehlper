#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#include "special_characters.h"
#include "pronunciation.h"

extern char argument[256];
extern short int lang;

void if_it_is_a_thing (short int lang)
{
	if (lang == 2) printf(", if it is a thing");
	else if (lang == 4) printf(", se for uma coisa");
	else if (lang == 6) printf(", si c\'est une chose");
	else if (lang == 8 || lang == 9) printf(", si es una cosa");
	else if (lang == 10) printf(", se estas a" SMALL_J_CIRCUMFLEX "o");
	else printf(", sei est un ject");
}

void if_it_is_a_living_being (short int lang)
{
	if (lang == 2) printf(", if it is a living being\n");
	else if (lang == 4) printf(", se for um ser vivo\n");
	else if (lang == 6) printf(", ssi c\'est un " SMALL_E_CIRCUMFLEX "tre vivant\n");
	else if (lang == 8 || lang == 9) printf(", si es un ser vivo\n");
	else if (lang == 10) printf(", se estas viva estulo\n");
	else printf(", sei est un gwiv\n");
}

void plural ()
{
    char word[256];
    char word2[256];

    short int arg_counter;

    // For converting all capital letter into small letters
	for (arg_counter = 0; arg_counter < strlen(argument) ; arg_counter++)
	{
		if (argument[arg_counter] == 'A') argument[arg_counter] = 'a';
		else if (argument[arg_counter] == 'B') argument[arg_counter] = 'b';
		else if (argument[arg_counter] == 'C') argument[arg_counter] = 'c';
		else if (argument[arg_counter] == 'D') argument[arg_counter] = 'd';
		else if (argument[arg_counter] == 'E') argument[arg_counter] = 'e';
		else if (argument[arg_counter] == 'F') argument[arg_counter] = 'f';
		else if (argument[arg_counter] == 'G') argument[arg_counter] = 'g';
		else if (argument[arg_counter] == 'H') argument[arg_counter] = 'h';
		else if (argument[arg_counter] == 'I') argument[arg_counter] = 'i';
		else if (argument[arg_counter] == 'J') argument[arg_counter] = 'j';
		else if (argument[arg_counter] == 'K') argument[arg_counter] = 'k';
		else if (argument[arg_counter] == 'L') argument[arg_counter] = 'l';
		else if (argument[arg_counter] == 'M') argument[arg_counter] = 'm';
		else if (argument[arg_counter] == 'N') argument[arg_counter] = 'n';
		else if (argument[arg_counter] == 'O') argument[arg_counter] = 'o';
		else if (argument[arg_counter] == 'P') argument[arg_counter] = 'p';
		else if (argument[arg_counter] == 'Q') argument[arg_counter] = 'q';
		else if (argument[arg_counter] == 'R') argument[arg_counter] = 'r';
		else if (argument[arg_counter] == 'S') argument[arg_counter] = 's';
		else if (argument[arg_counter] == 'T') argument[arg_counter] = 't';
		else if (argument[arg_counter] == 'U') argument[arg_counter] = 'u';
		else if (argument[arg_counter] == 'V') argument[arg_counter] = 'v';
		else if (argument[arg_counter] == 'W') argument[arg_counter] = 'w';
		else if (argument[arg_counter] == 'X') argument[arg_counter] = 'x';
		else if (argument[arg_counter] == 'Y') argument[arg_counter] = 'y';
		else if (argument[arg_counter] == 'Z') argument[arg_counter] = 'z';
	}

    strcpy(word, argument);
    strcpy(word2, argument);

    /***************************************************************************
	************* -OS
	***************************************************************************/

    if (argument[strlen(argument) - 2] == 'o' && argument[strlen(argument) - 1] == 's')
    {
    	// For a thing

		if (is_it_vowel(word[strlen(word) - 4]) || is_it_vowel(word[strlen(word) - 5]) || is_it_vowel(word[strlen(word) - 6]) || is_it_vowel(word[strlen(word) - 7]))
		{
			word[strlen(word) - 2] = 's';
			word[strlen(word) - 1] = 'a';
			printf("\n\"");
			printf("%s", word);
			printf("\"");
			if_it_is_a_thing (lang);
		}
		else
		{
			word[strlen(word)] = 'a';
			printf("\n\"");
			printf("%s", word);
			printf("\"");
			if_it_is_a_thing (lang);
		}

		// For a animated being

		if (is_it_vowel(word2[strlen(word2) - 4]) || is_it_vowel(word2[strlen(word2) - 5]) || is_it_vowel(word2[strlen(word2) - 6]) || is_it_vowel(word2[strlen(word2) - 7]))
		{
			word2[strlen(word2) - 2] = 'i';
    		word2[strlen(word2) - 1] = '\0';
    		printf("\n\"");
			printf("%s", word2);
			printf("\"");
			if_it_is_a_living_being (lang);
		}
		else
		{
			word2[strlen(word2)] = 'i';
			printf("\n\"");
			printf("%s", word2);
			printf("\"");
			if_it_is_a_living_being (lang);
		}
    }

    /***************************************************************************
	************* -ES
	***************************************************************************/

    else if (argument[strlen(argument) - 2] == 'e' && argument[strlen(argument) - 1] == 's')
    {
    	// For a thing

    	if (is_it_vowel(word[strlen(word) - 4]) || is_it_vowel(word[strlen(word) - 5]) || is_it_vowel(word[strlen(word) - 6]) || is_it_vowel(word[strlen(word) - 7]))
		{
			word[strlen(word) - 2] = 's';
			word[strlen(word) - 1] = 'a';
			printf("\n\"");
			printf("%s", word);
			printf("\"");
			if_it_is_a_thing (lang);
		}
		else
		{
			word[strlen(word)] = 'a';
			printf("\n\"");
			printf("%s", word);
			printf("\"");
			if_it_is_a_thing (lang);
		}

		// For a animated being

		if (is_it_vowel(word2[strlen(word2) - 4]) || is_it_vowel(word2[strlen(word2) - 5]) || is_it_vowel(word2[strlen(word2) - 6]) || is_it_vowel(word2[strlen(word2) - 7]))
		{
			word2[strlen(word2) - 2] = 's';
    		word2[strlen(word2) - 1] = 'i';
    		printf("\n\"");
			printf("%s", word2);
			printf("\"");
			if_it_is_a_living_being (lang);
		}
		else
		{
			word2[strlen(word2)] = 'i';
			printf("\n\"");
			printf("%s", word2);
			printf("\"");
			if_it_is_a_living_being (lang);
		}
    }

    /***************************************************************************
	************* -UM
	***************************************************************************/

    else if (argument[strlen(argument) - 3] == 'i' && argument[strlen(argument) - 2] == 'u' && argument[strlen(argument) - 1] == 'm')
    {
		word[strlen(word) - 2] = 'a';
		word[strlen(word) - 1] = '\0';
		printf("\n");
		printf("%s", word);
		printf("\n");
    }

    /***************************************************************************
	************* THE REST
	***************************************************************************/

    else
    {
    	word[strlen(word)] = 's';
    	printf("\n\"");
    	printf("%s", word);
    	printf("\"");
    }

    // For cleaning
	memset(argument, '\0', strlen(argument));
	memset(word, '\0', strlen(word));
	memset(word2, '\0', strlen(word2));
}
