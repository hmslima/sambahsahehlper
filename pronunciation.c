#include <stdio.h>
#include <string.h>

#include "special_characters.h"

#include "system_text.h"

#define TRUE 1
#define FALSE 0

extern char argument[256];
extern short int lang;

extern short int show_system_messages;

char SPT_word[256];
char corrected_SPT_word[256];
char correct_vowel;

char *ptr[50];

short int stress = FALSE;

short int occurrence_of_the_small_e_diaeresis;

short int is_it_vowel (char ch)
{
	if (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || ch =='o' || ch=='O' || ch == 'u' || ch == 'U' || ch == 'w' || ch == 'W' || ch == 'y' || ch == 'Y')
		return TRUE;
	else
		return FALSE;
}

short int is_it_vowel_without_some_letters (char ch)
{
	if (ch == 'a' || ch == 'A' || ch == 'i' || ch == 'I' || ch =='o' || ch=='O' || ch == 'u' || ch == 'U' || ch == 'w' || ch == 'W' || ch == 'y' || ch == 'Y')
		return TRUE;
	else
		return FALSE;
}

short int is_it_consonant (char ch)
{
	if (ch == 'b' || ch == 'c' || ch == 'd' || ch == 'f' || ch == 'g' || ch == 'h' || ch == 'j' || ch == 'k' || ch == 'l' || ch == 'm' || ch =='n' || ch == 'p' || ch == 'q' || ch == 'r' || ch == 's' || ch == 't' || ch == 'v' || ch == 'x' || ch == 'z')
		return TRUE;
	else
		return FALSE;
}

// It's for the correction
short int is_it_consonant_without_some_letters (char ch)
{
	if (ch == 'b' || ch == 'c' || ch == 'd' || ch == 'f' || ch == 'g' || ch == 'j' || ch == 'k' || ch == 'l' || ch == 'm' || ch =='n' || ch == 'p' || ch == 'q' || ch == 'r' || ch == 's' || ch == 't' || ch == 'v' || ch == 'x' || ch == 'z')
		return TRUE;
	else
		return FALSE;
}

short int is_there_something_here (char ch)
{
	if (ch == 'a' || ch == 'b' || ch == 'c' || ch == 'd' || ch == 'e' || ch == 'f' || ch == 'g' || ch == 'h' || ch == 'i' || ch == 'j' || ch == 'k' || ch == 'l' || ch == 'm' || ch =='n' || ch == 'o' || ch == 'p' || ch == 'q' || ch == 'r' || ch == 's' || ch == 't' || ch == 'u' || ch == 'v' || ch == 'w' || ch == 'x' || ch == 'y' || ch == 'z')
		return TRUE;
	else
		return FALSE;
}

// For consonants that have only one possible SPT transcription
short int is_it_simple_consonant (char ch)
{
	if (ch == 'j' || ch == 'm' || ch =='n' || ch == 'v')
		return TRUE;
	else
		return FALSE;
}

short int is_there_more_than_one_vowel ()
{
	short int arg_counter;
	short int vowel = 0;
	for (arg_counter = 0; arg_counter < strlen(argument) ; arg_counter++)
	{
		if (argument[arg_counter] == 'a') vowel++;
		else if ((argument[arg_counter] == 'e') && ((argument[arg_counter + 1] == 'u') || (argument[arg_counter + 1] == 'o')))
		{
			vowel++;
			arg_counter++;
		}
		else if (argument[arg_counter] == 'e') vowel++;
		else if ((argument[arg_counter] == 'i') && !(is_it_vowel(argument[arg_counter - 1])) && !(is_it_vowel(argument[arg_counter + 1]))) vowel++;
		else if ((argument[arg_counter] == 'i') && (argument[arg_counter + 1] == 'e') && (argument[arg_counter + 2] == '\0')) vowel++;
		else if ((argument[arg_counter] == 'i') && (is_it_consonant(argument[arg_counter - 1]) || argument[arg_counter - 1] == 'w') && (argument[arg_counter + 1] == '\0')) vowel++;
		else if (argument[arg_counter] == 'o') vowel++;
		else if ((argument[arg_counter] == 'u') && !(is_it_vowel(argument[arg_counter - 1])) && !(is_it_vowel(argument[arg_counter + 1]))) vowel++;
		else if ((argument[arg_counter] == 'u') && (argument[arg_counter + 1] == 'e'))
		{
			vowel++;
			arg_counter++;
		}
		else if (argument[arg_counter] == 'u') vowel++;
		else if ((argument[arg_counter] == 'y') && (is_it_consonant (argument[arg_counter - 1]) || argument[arg_counter - 1] == '\0') && (is_it_consonant (argument[arg_counter + 1]))) vowel++;
		else if ((argument[arg_counter] == 'y') && (is_it_consonant (argument[arg_counter - 1]) || argument[arg_counter - 1] == '\0') && (argument[arg_counter + 1] == '\0')) vowel++;
		else if ((argument[arg_counter] == 'w') && (is_it_consonant (argument[arg_counter - 1])) && (is_it_consonant (argument[arg_counter + 1]))) vowel++;
	}

	if (vowel > 1) return TRUE;
	else return FALSE;
}

short int is_there_more_than_one_vowel_ignoring_last_e ()
{
	short int arg_counter;
	short int vowel = 0;
	for (arg_counter = 0; arg_counter < strlen(argument) ; arg_counter++)
	{
		if (argument[arg_counter] == 'a') vowel++;
		else if ((argument[arg_counter] == 'e') && ((argument[arg_counter + 1] == 'u') || (argument[arg_counter + 1] == 'o')))
		{
			vowel++;
			arg_counter++;
		}
		else if (argument[arg_counter] == 'e' && !(argument[arg_counter + 1] == '\0' || (argument[arg_counter + 1] == 's' && argument[arg_counter + 2] == '\0'))) vowel++;
		else if ((argument[arg_counter] == 'i') && !(is_it_vowel(argument[arg_counter - 1])) && !(is_it_vowel(argument[arg_counter + 1]))) vowel++;
		else if ((argument[arg_counter] == 'i') && (argument[arg_counter + 1] == 'e') && (argument[arg_counter + 2] == '\0')) vowel++;
		else if ((argument[arg_counter] == 'i') && (is_it_consonant(argument[arg_counter - 1]) || argument[arg_counter - 1] == 'w') && (argument[arg_counter + 1] == '\0')) vowel++;
		else if (argument[arg_counter] == 'o') vowel++;
		else if ((argument[arg_counter] == 'u') && !(is_it_vowel(argument[arg_counter - 1])) && !(is_it_vowel(argument[arg_counter + 1]))) vowel++;
		else if ((argument[arg_counter] == 'u') && (argument[arg_counter + 1] == 'e'))
		{
			vowel++;
			arg_counter++;
		}
		else if (argument[arg_counter] == 'u') vowel++;
		else if ((argument[arg_counter] == 'y') && (is_it_consonant (argument[arg_counter - 1]) || argument[arg_counter - 1] == '\0') && (is_it_consonant (argument[arg_counter + 1]))) vowel++;
		else if ((argument[arg_counter] == 'y') && (is_it_consonant (argument[arg_counter - 1]) || argument[arg_counter - 1] == '\0') && (argument[arg_counter + 1] == '\0')) vowel++;
		else if ((argument[arg_counter] == 'w') && (is_it_consonant (argument[arg_counter - 1])) && (is_it_consonant (argument[arg_counter + 1]))) vowel++;
	}

	if (vowel > 1) return TRUE;
	else return FALSE;
}


void pronunciation ()
{
	short int arg_counter;
	short int SPT_counter = 0;

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

	for (arg_counter = 0; arg_counter < strlen(argument) ; arg_counter++)
	{
		/***********************************************************************/
		if (show_system_messages)
		{
			printf("\nLOG: argument[%d] = %c", arg_counter, argument[arg_counter]);
			if (is_there_more_than_one_vowel ()) printf("\nLOG: There is more than one vowel");
			else printf("\nLOG: There is NO more than one vowel");
			if (!stress) printf("\nLOG: A vowel still ca be stressed");
			else printf("\nLOG: There is already a stressed vowel");
			printf("\n-------");
		}
		/***********************************************************************/


		/***************************************************************************
		****************************************************************************
		************* SIMPLE CONSONANTS, THEY ARE EXACT THE SAME IN SPT
		****************************************************************************
		****************************************************************************/

		if (is_it_simple_consonant(argument[arg_counter]))
		{
			SPT_word[SPT_counter] = argument[arg_counter];
			SPT_counter++;
		}

		/***************************************************************************
		****************************************************************************
		************* VOWEL AND SEMIVOWELS
		****************************************************************************
		****************************************************************************/


		if (is_it_vowel(argument[arg_counter]))
		{
			/***************************************************************************
			************* Semivowel u
			***************************************************************************/

			if ((argument[arg_counter] == 'u') && (argument[arg_counter - 1] == 'o'))
			{
				SPT_word[SPT_counter] = 'w';
				SPT_counter++;
			}
			else if ((argument[arg_counter] == 'u') && (argument[arg_counter - 1] == 'a'))
			{
				SPT_word[SPT_counter] = 'o';
				SPT_counter++;
			}
			else if ((argument[arg_counter] == 'u') && (argument[arg_counter - 1] == 'e'))
			{
				// Do nothing
			}

			/***************************************************************************
			************* Semivowel i
			***************************************************************************/

			else if ((argument[arg_counter] == 'i') && (argument[arg_counter + 1] == 'a' || argument[arg_counter + 1] == 'o' || argument[arg_counter + 1] == 'u') && (argument[arg_counter + 2] == '\0' || argument[arg_counter + 2] == 's' || !(argument[arg_counter + 2] == 'e')))
			{
				SPT_word[SPT_counter] = 'y';
				SPT_counter++;
			}
			else if ((argument[arg_counter] == 'i' && argument[arg_counter + 1] == 'e' && argument[arg_counter - 1] == '\0') && (argument[arg_counter + 2] == '\0' || (argument[arg_counter + 2] == 's' && argument[arg_counter + 3] == '\0')))
			{
				SPT_word[SPT_counter] = 'y';
				SPT_counter++;
			}
			else if ((argument[arg_counter] == 'i') && (argument[arg_counter + 1] == 'a'))
			{
				SPT_word[SPT_counter] = 'y';
				SPT_counter++;
			}
			else if ((argument[arg_counter] == 'i') && (argument[arg_counter - 1] == 'e' || argument[arg_counter - 1] == 'o'))
			{
				SPT_word[SPT_counter] = 'y';
				SPT_counter++;
			}
			else if ((argument[arg_counter] == 'u') && (argument[arg_counter + 1] == 'a' || argument[arg_counter + 1] == 'i' || argument[arg_counter + 1] == 'o'))
			{
				SPT_word[SPT_counter] = 'w';
				SPT_counter++;
			}

			/***************************************************************************
			************* a
			***************************************************************************/

			else if (argument[arg_counter] == 'a')
			{

				/************* ai **/

				if (argument[arg_counter + 1] == 'i')
				{
					if (!(stress) && (is_there_more_than_one_vowel ()) && (argument[arg_counter + 2] == 'h') && (is_it_consonant (argument[arg_counter + 3]) || argument[arg_counter + 4] == '\0'))
					{
						#ifdef _WIN32
						SPT_word[SPT_counter] = CAPITAL_A_DIAERESIS;
						SPT_counter++;
						#else
						strncat(SPT_word, CAPITAL_A_DIAERESIS, 6);
						SPT_counter = SPT_counter + 2;
						#endif
						stress = TRUE;
					}
					else if ((is_there_more_than_one_vowel ()) && (((is_it_consonant (argument[arg_counter + 2])) && (argument[arg_counter + 2] == argument[arg_counter + 3])) || ((argument[arg_counter + 2] == 'c') && (argument[arg_counter + 3] == 'k'))) && (argument[arg_counter + 4] == '\0'))
					{
						#ifdef _WIN32
						SPT_word[SPT_counter] = CAPITAL_A_DIAERESIS;
						SPT_counter++;
						#else
						strncat(SPT_word, CAPITAL_A_DIAERESIS, 6);
						SPT_counter = SPT_counter + 2;
						#endif
						stress = TRUE;
					}
					//V-CV
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 2])) && (is_it_vowel(argument[arg_counter + 3])) && (argument[arg_counter + 4] == '\0'))
					{
						if ((argument[arg_counter + 2] == 'e') && ((is_it_vowel(argument[arg_counter - 2])) || (is_it_vowel(argument[arg_counter - 3]))))
						{
							#ifdef _WIN32
							SPT_word[SPT_counter] = CAPITAL_A_DIAERESIS;
							SPT_counter++;
							#else
							strncat(SPT_word, CAPITAL_A_DIAERESIS, 6);
							SPT_counter = SPT_counter + 2;
							#endif
							stress = TRUE;
						}
						else if (!(argument[arg_counter + 2] == 'e'))
						{
							#ifdef _WIN32
							SPT_word[SPT_counter] = CAPITAL_A_DIAERESIS;
							SPT_counter++;
							#else
							strncat(SPT_word, CAPITAL_A_DIAERESIS, 6);
							SPT_counter = SPT_counter + 2;
							#endif
							stress = TRUE;
						}
						else
						{
							#ifdef _WIN32
							SPT_word[SPT_counter] = SMALL_A_DIAERESIS;
							SPT_counter++;
							#else
							strncat(SPT_word, SMALL_A_DIAERESIS, 6);
							SPT_counter = SPT_counter + 2;
							#endif
						}
					}
					//V-CCV
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 2])) && (is_it_consonant(argument[arg_counter + 3])) && (is_it_vowel(argument[arg_counter + 4])) && (argument[arg_counter + 5] == '\0'))
					{
						if ((argument[arg_counter + 3] == 'e') && ((is_it_vowel(argument[arg_counter - 2])) || (is_it_vowel(argument[arg_counter - 3]))))
						{
							#ifdef _WIN32
							SPT_word[SPT_counter] = CAPITAL_A_DIAERESIS;
							SPT_counter++;
							#else
							strncat(SPT_word, CAPITAL_A_DIAERESIS, 6);
							SPT_counter = SPT_counter + 2;
							#endif
							stress = TRUE;
						}
						else if (!(argument[arg_counter + 3] == 'e'))
						{
							#ifdef _WIN32
							SPT_word[SPT_counter] = CAPITAL_A_DIAERESIS;
							SPT_counter++;
							#else
							strncat(SPT_word, CAPITAL_A_DIAERESIS, 6);
							SPT_counter = SPT_counter + 2;
							#endif
							stress = TRUE;
						}
						else
						{
							#ifdef _WIN32
							SPT_word[SPT_counter] = SMALL_A_DIAERESIS;
							SPT_counter++;
							#else
							strncat(SPT_word, SMALL_A_DIAERESIS, 6);
							SPT_counter = SPT_counter + 2;
							#endif
						}
					}
					//V-CVs
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 2])) && (is_it_vowel(argument[arg_counter + 3])) && (argument[arg_counter + 4] == 's') && (argument[arg_counter + 5] == '\0'))
					{
						if ((argument[arg_counter + 2] == 'e') && ((is_it_vowel(argument[arg_counter - 2])) || (is_it_vowel(argument[arg_counter - 3]))))
						{
							#ifdef _WIN32
							SPT_word[SPT_counter] = CAPITAL_A_DIAERESIS;
							SPT_counter++;
							#else
							strncat(SPT_word, CAPITAL_A_DIAERESIS, 6);
							SPT_counter = SPT_counter + 2;
							#endif
							stress = TRUE;
						}
						else if (!(argument[arg_counter + 2] == 'e'))
						{
							#ifdef _WIN32
							SPT_word[SPT_counter] = CAPITAL_A_DIAERESIS;
							SPT_counter++;
							#else
							strncat(SPT_word, CAPITAL_A_DIAERESIS, 6);
							SPT_counter = SPT_counter + 2;
							#endif
							stress = TRUE;
						}
						else
						{
							#ifdef _WIN32
							SPT_word[SPT_counter] = SMALL_A_DIAERESIS;
							SPT_counter++;
							#else
							strncat(SPT_word, SMALL_A_DIAERESIS, 6);
							SPT_counter = SPT_counter + 2;
							#endif
						}
					}
					//V-CCVs
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 2])) && (is_it_consonant(argument[arg_counter + 3])) && (is_it_vowel(argument[arg_counter + 4])) && (argument[arg_counter + 5] == 's') && (argument[arg_counter + 6] == '\0'))
					{
						if ((argument[arg_counter + 3] == 'e') && ((is_it_vowel(argument[arg_counter - 2])) || (is_it_vowel(argument[arg_counter - 3]))))
						{
							#ifdef _WIN32
							SPT_word[SPT_counter] = CAPITAL_A_DIAERESIS;
							SPT_counter++;
							#else
							strncat(SPT_word, CAPITAL_A_DIAERESIS, 6);
							SPT_counter = SPT_counter + 2;
							#endif
							stress = TRUE;
						}
						else if (!(argument[arg_counter + 3] == 'e'))
						{
							#ifdef _WIN32
							SPT_word[SPT_counter] = CAPITAL_A_DIAERESIS;
							SPT_counter++;
							#else
							strncat(SPT_word, CAPITAL_A_DIAERESIS, 6);
							SPT_counter = SPT_counter + 2;
							#endif
							stress = TRUE;
						}
						else
						{
							#ifdef _WIN32
							SPT_word[SPT_counter] = SMALL_A_DIAERESIS;
							SPT_counter++;
							#else
							strncat(SPT_word, SMALL_A_DIAERESIS, 6);
							SPT_counter = SPT_counter + 2;
							#endif
						}
					}
					//V-CyV
						else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 2])) && (argument[arg_counter + 3] == 'y' || argument[arg_counter + 3] == 'i') && (is_it_vowel(argument[arg_counter + 4])) && (argument[arg_counter + 5] == '\0') && !(argument[arg_counter + 3] == 'i' && argument[arg_counter + 4] == 'e'))
						{
							if ((argument[arg_counter + 4] == 'e') && ((is_it_vowel(argument[arg_counter - 2])) || (is_it_vowel(argument[arg_counter - 3]))))
							{
								#ifdef _WIN32
								SPT_word[SPT_counter] = CAPITAL_A_DIAERESIS;
								SPT_counter++;
								#else
								strncat(SPT_word, CAPITAL_A_DIAERESIS, 6);
								SPT_counter = SPT_counter + 2;
								#endif
								stress = TRUE;
							}
							else if (!(argument[arg_counter + 4] == 'e'))
							{
								#ifdef _WIN32
								SPT_word[SPT_counter] = CAPITAL_A_DIAERESIS;
								SPT_counter++;
								#else
								strncat(SPT_word, CAPITAL_A_DIAERESIS, 6);
								SPT_counter = SPT_counter + 2;
								#endif
								stress = TRUE;
							}
							else
							{
								#ifdef _WIN32
								SPT_word[SPT_counter] = SMALL_A_DIAERESIS;
								SPT_counter++;
								#else
								strncat(SPT_word, SMALL_A_DIAERESIS, 6);
								SPT_counter = SPT_counter + 2;
								#endif
							}
						}
						//V-CyVs
						else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (argument[arg_counter + 3] == 'y' || argument[arg_counter + 3] == 'i') && (is_it_vowel(argument[arg_counter + 4])) && (argument[arg_counter + 5] == 's') && (argument[arg_counter + 6] == '\0') && !(argument[arg_counter + 3] == 'i' && argument[arg_counter + 4] == 'e'))
						{
							if ((argument[arg_counter + 4] == 'e') && ((is_it_vowel(argument[arg_counter - 2])) || (is_it_vowel(argument[arg_counter - 3]))))
							{
								#ifdef _WIN32
								SPT_word[SPT_counter] = CAPITAL_A_DIAERESIS;
								SPT_counter++;
								#else
								strncat(SPT_word, CAPITAL_U_DIAERESIS, 6);
								SPT_counter = SPT_counter + 2;
								#endif
								stress = TRUE;
							}
							else if (!(argument[arg_counter + 4] == 'e'))
							{
								#ifdef _WIN32
								SPT_word[SPT_counter] = CAPITAL_A_DIAERESIS;
								SPT_counter++;
								#else
								strncat(SPT_word, CAPITAL_A_DIAERESIS, 6);
								SPT_counter = SPT_counter + 2;
								#endif
								stress = TRUE;
							}
							else
							{
								#ifdef _WIN32
								SPT_word[SPT_counter] = SMALL_A_DIAERESIS;
								SPT_counter++;
								#else
								strncat(SPT_word, SMALL_A_DIAERESIS, 6);
								SPT_counter = SPT_counter + 2;
								#endif
							}
						}
					else
					{
						#ifdef _WIN32
						SPT_word[SPT_counter] = SMALL_A_DIAERESIS;
						SPT_counter++;
						#else
						strncat(SPT_word, SMALL_A_DIAERESIS, 6);
						SPT_counter = SPT_counter + 2;
						#endif
					}
					arg_counter++;
				}

				/************* aa **/

				else if (!(stress) && argument[arg_counter - 1] == 'a' && !(is_there_something_here(argument[arg_counter + 1]) && is_there_something_here(argument[arg_counter + 2]) && is_there_something_here(argument[arg_counter + 3])))
				{
					SPT_word[SPT_counter] = 'A';
					SPT_counter++;
					stress = TRUE;
				}

				/*******************/

				else
				{
					if (!(stress) && (is_there_more_than_one_vowel ()) && (argument[arg_counter + 1] == 'h') && (is_it_consonant (argument[arg_counter + 2]) || argument[arg_counter + 2] == '\0'))
					{
						SPT_word[SPT_counter] = 'A';
						stress = TRUE;
					}
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (((is_it_consonant (argument[arg_counter + 1])) && (argument[arg_counter + 1] == argument[arg_counter + 2])) || ((argument[arg_counter + 1] == 'c') && (argument[arg_counter + 2] == 'k'))) && (argument[arg_counter + 3] == '\0'))
					{
						SPT_word[SPT_counter] = 'A';
						stress = TRUE;
					}
					else if (!(stress) && (is_there_more_than_one_vowel ()) && ((is_it_consonant(argument[arg_counter + 1])) || (argument[arg_counter + 1] == 'y')) && !(argument[arg_counter + 1] == 's') && (argument[arg_counter + 2] == '\0'))
					{
						SPT_word[SPT_counter] = 'A';
						stress = TRUE;
					}
					// ae
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (argument[arg_counter + 1] == 'e'))
					{
						// ae\0
						if ((is_it_vowel(argument[arg_counter - 1]) || is_it_vowel(argument[arg_counter - 2]) || is_it_vowel(argument[arg_counter - 3])) && argument[arg_counter + 2] == '\0')
						{
							SPT_word[SPT_counter] = 'A';
							stress = TRUE;
						}
						// aes\0
						else if ((is_it_vowel(argument[arg_counter - 1]) || is_it_vowel(argument[arg_counter - 2]) || is_it_vowel(argument[arg_counter - 3])) && argument[arg_counter + 2] == 's' && argument[arg_counter + 3] == '\0')
						{
							SPT_word[SPT_counter] = 'A';
							stress = TRUE;
						}
						else
							SPT_word[SPT_counter] = 'a';
					}
					//V-CV
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (is_it_vowel(argument[arg_counter + 2])) && (argument[arg_counter + 3] == '\0'))
					{
						if ((argument[arg_counter + 2] == 'e') && ((is_it_vowel(argument[arg_counter - 2])) || (is_it_vowel(argument[arg_counter - 3]))))
						{
							SPT_word[SPT_counter] = 'A';
							stress = TRUE;
						}
						else if (!(argument[arg_counter + 2] == 'e'))
						{
							SPT_word[SPT_counter] = 'A';
							stress = TRUE;
						}
						else
						{
							SPT_word[SPT_counter] = 'a';
						}
					}
					//V-CCV
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (is_it_consonant(argument[arg_counter + 2])) && (is_it_vowel(argument[arg_counter + 3])) && (argument[arg_counter + 4] == '\0'))
					{
						if ((argument[arg_counter + 3] == 'e') && ((is_it_vowel(argument[arg_counter - 2])) || (is_it_vowel(argument[arg_counter - 3]))))
						{
							SPT_word[SPT_counter] = 'A';
							stress = TRUE;
						}
						else if (!(argument[arg_counter + 3] == 'e'))
						{
							SPT_word[SPT_counter] = 'A';
							stress = TRUE;
						}
						else
						{
							SPT_word[SPT_counter] = 'a';
						}
					}
					else // No sctress accent
					{
						SPT_word[SPT_counter] = 'a';
					}
					SPT_counter++;
				}
			}

			/***************************************************************************
			************* e
			***************************************************************************/

			else if (argument[arg_counter] == 'e')
			{

				/************* eih **/

				if ((argument[arg_counter + 1] == 'i') && (argument[arg_counter + 2] == 'h'))
				{
					if (!(stress) && is_there_more_than_one_vowel ())
					{
						SPT_word[SPT_counter] = 'E';
						SPT_counter++;
						stress = TRUE;
					}
					else
					{
						SPT_word[SPT_counter] = 'e';
						SPT_counter++;
					}
					SPT_word[SPT_counter] = ':';
					SPT_counter++;
					SPT_word[SPT_counter] = 'y';
					SPT_counter++;
					arg_counter = arg_counter + 2;
				}

				/************* eau **/

				else if ((argument[arg_counter + 1] == 'a') && (argument[arg_counter + 2] == 'u'))
				{
					if (!(stress) && (is_there_more_than_one_vowel ()) && (argument[arg_counter + 3] == 'h') && (is_it_consonant (argument[arg_counter + 4]) || argument[arg_counter + 4] == '\0'))
					{
						SPT_word[SPT_counter] = 'O';
						stress = TRUE;
					}
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (((is_it_consonant (argument[arg_counter + 3])) && (argument[arg_counter + 3] == argument[arg_counter + 4])) || ((argument[arg_counter + 3] == 'c') && (argument[arg_counter + 4] == 'k'))) && (argument[arg_counter + 5] == '\0'))
					{
						SPT_word[SPT_counter] = 'O';
						stress = TRUE;
					}
					else if (!(stress) && argument[arg_counter + 3] == '\0')
					{
						SPT_word[SPT_counter] = 'O';
						stress = TRUE;
					}
					else if (!(stress) && argument[arg_counter + 3] == 's' && argument[arg_counter + 4] == '\0')
					{
						SPT_word[SPT_counter] = 'O';
						stress = TRUE;
					}
					else // No sctress accent
					{
						SPT_word[SPT_counter] = 'o';
					}
					SPT_counter++;
					SPT_word[SPT_counter] = ':';
					SPT_counter++;
					arg_counter = arg_counter + 2;
				}

				/************* ea **/

				else if (!(stress) && (argument[arg_counter + 1] == 'a') && (argument[arg_counter + 2] == '\0'))
				{
					SPT_word[SPT_counter] = 'E';
					SPT_counter++;
					stress = TRUE;
				}
				else if ((argument[arg_counter + 1] == 'a') && !(argument[arg_counter + 2] == '\0'))
				{
					#ifdef _WIN32
					SPT_word[SPT_counter] = SMALL_E_DIAERESIS;
					SPT_counter++;
					#else
					strncat(SPT_word, SMALL_E_DIAERESIS, 6);
					SPT_counter = SPT_counter + 2;
					#endif
					occurrence_of_the_small_e_diaeresis++;
				}

				/************* ey **/

				else if (!(stress) && (is_there_more_than_one_vowel ()) && (argument[arg_counter + 1] == 'y') && (argument[arg_counter + 2] == '\0'))
				{
					SPT_word[SPT_counter] = 'E';
					SPT_counter++;
					stress = TRUE;
				}

				/************* oCel **/

				else if (!(stress) && (is_there_more_than_one_vowel ()) && (argument[arg_counter + 1] == 'l') && (is_it_consonant (argument[arg_counter - 1]) && (argument[arg_counter - 2] == 'o') && (argument[arg_counter + 2] == '\0')))
				{
					SPT_word[SPT_counter] = 'E';
					SPT_counter++;
					stress = TRUE;
				}

				/************* ae **/

				else if (argument[arg_counter - 1] == 'a')
				{
					SPT_word[SPT_counter] = 'y';
					SPT_counter++;
				}

				/************* oe **/

				else if (argument[arg_counter - 1] == 'o')
				{
					SPT_word[SPT_counter] = 'y';
					SPT_counter++;
				}

				/************* ee **/

				else if (!(stress) && (argument[arg_counter + 1] == 'e'))
				{
					SPT_word[SPT_counter] = 'E';
					SPT_counter++;
					stress = TRUE;
				}
				else if (argument[arg_counter - 1] == 'e')
				{
					#ifdef _WIN32
					SPT_word[SPT_counter] = SMALL_E_DIAERESIS;
					SPT_counter++;
					#else
					strncat(SPT_word, SMALL_E_DIAERESIS, 6);
					SPT_counter = SPT_counter + 2;
					#endif
					occurrence_of_the_small_e_diaeresis++;
				}

				/************* eu **/

				else if (argument[arg_counter + 1] == 'u')
				{
					//euhC || euh\0
					if (!(stress) && (is_there_more_than_one_vowel ()) && (argument[arg_counter + 2] == 'h') && (is_it_consonant (argument[arg_counter + 3]) || argument[arg_counter + 3] == '\0'))
					{
						#ifdef _WIN32
						SPT_word[SPT_counter] = CAPITAL_O_DIAERESIS;
						SPT_counter++;
						#else
						strncat(SPT_word, CAPITAL_O_DIAERESIS, 6);
						SPT_counter = SPT_counter + 2;
						#endif
						stress = TRUE;
					}
					//euC=C || euck
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (((is_it_consonant (argument[arg_counter + 2])) && (argument[arg_counter + 2] == argument[arg_counter + 3])) || ((argument[arg_counter + 2] == 'c') && (argument[arg_counter + 3] == 'k'))) && (argument[arg_counter + 4] == '\0'))
					{
						#ifdef _WIN32
						SPT_word[SPT_counter] = CAPITAL_O_DIAERESIS;
						SPT_counter++;
						#else
						strncat(SPT_word, CAPITAL_O_DIAERESIS, 6);
						SPT_counter = SPT_counter + 2;
						#endif
						stress = TRUE;
					}
					// euCer\0 ex: member
					else if ((is_it_consonant(argument[arg_counter + 2])) && (argument[arg_counter + 3] == 'e') && (argument[arg_counter + 4] == 'r') && (argument[arg_counter + 5] == '\0'))
					{
						#ifdef _WIN32
						SPT_word[SPT_counter] = CAPITAL_O_DIAERESIS;
						SPT_counter++;
						#else
						strncat(SPT_word, CAPITAL_O_DIAERESIS, 6);
						SPT_counter = SPT_counter + 2;
						#endif
						stress = TRUE;
					}
					// euCCer\0 ex: november
					else if ((is_it_consonant(argument[arg_counter + 2])) && (is_it_consonant(argument[arg_counter + 3])) && (argument[arg_counter + 4] == 'e') && (argument[arg_counter + 5] == 'r') && (argument[arg_counter + 6] == '\0'))
					{
						#ifdef _WIN32
						SPT_word[SPT_counter] = CAPITAL_O_DIAERESIS;
						SPT_counter++;
						#else
						strncat(SPT_word, CAPITAL_O_DIAERESIS, 6);
						SPT_counter = SPT_counter + 2;
						#endif
						stress = TRUE;
					}
					// euCCCer\0 ex: novembrer
					else if ((is_it_consonant(argument[arg_counter + 2])) && (is_it_consonant(argument[arg_counter + 3])) && (is_it_consonant(argument[arg_counter + 4])) && (argument[arg_counter + 5] == 'e') && (argument[arg_counter + 6] == 'r') && (argument[arg_counter + 7] == '\0'))
					{
						#ifdef _WIN32
						SPT_word[SPT_counter] = CAPITAL_O_DIAERESIS;
						SPT_counter++;
						#else
						strncat(SPT_word, CAPITAL_O_DIAERESIS, 6);
						SPT_counter = SPT_counter + 2;
						#endif
						stress = TRUE;
					}
					else // No sctress accent
					{
						#ifdef _WIN32
						SPT_word[SPT_counter] = SMALL_O_DIAERESIS;
						SPT_counter++;
						#else
						strncat(SPT_word, SMALL_O_DIAERESIS, 6);
						SPT_counter = SPT_counter + 2;
						#endif
					}

				}

				/************* -e **/

				else if ((arg_counter == (strlen(argument) - 1)) && !(argument[strlen(argument) - 2] == 'i'))
				{
					SPT_counter++; // The letter "e" at the end of a verb is not pronounced
				}

				/*******************/

				else
				{
					if (!(stress) && (is_there_more_than_one_vowel ()) && (argument[arg_counter + 1] == 'h') && (is_it_consonant (argument[arg_counter + 2]) || argument[arg_counter + 2] == '\0'))
					{
						if (is_it_vowel(argument[arg_counter + 2]) || is_it_vowel(argument[arg_counter + 3]) || is_it_vowel(argument[arg_counter + 4]) || is_it_vowel(argument[arg_counter + 5]))
						{
							SPT_word[SPT_counter] = 'e';
							SPT_counter++;
						}
						else
						{
							SPT_word[SPT_counter] = 'E';
							SPT_counter++;
							stress = TRUE;
						}
					}
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (((is_it_consonant (argument[arg_counter + 1])) && (argument[arg_counter + 1] == argument[arg_counter + 2])) || ((argument[arg_counter + 1] == 'c') && (argument[arg_counter + 2] == 'k'))) && (argument[arg_counter + 3] == '\0'))
					{
						SPT_word[SPT_counter] = 'E';
						SPT_counter++;
						stress = TRUE;
					}
					//V-CV
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (is_it_vowel(argument[arg_counter + 2])) && (argument[arg_counter + 3] == '\0'))
					{
						if ((argument[arg_counter + 2] == 'e') && ((is_it_vowel(argument[arg_counter - 2])) || (is_it_vowel(argument[arg_counter - 3]))))
						{
							SPT_word[SPT_counter] = 'E';
							SPT_counter++;
							stress = TRUE;
						}
						else if (!(argument[arg_counter + 2] == 'e'))
						{
							SPT_word[SPT_counter] = 'E';
							SPT_counter++;
							stress = TRUE;
						}
						else
							goto PROBLEMATIC_E;
					}
					//V-CCV
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (is_it_consonant(argument[arg_counter + 2])) && (is_it_vowel(argument[arg_counter + 3])) && (argument[arg_counter + 4] == '\0'))
					{
						if ((argument[arg_counter + 3] == 'e') && ((is_it_vowel(argument[arg_counter - 2])) || (is_it_vowel(argument[arg_counter - 3]))))
						{
							SPT_word[SPT_counter] = 'E';
							SPT_counter++;
							stress = TRUE;
						}
						else if (!(argument[arg_counter + 3] == 'e'))
						{
							SPT_word[SPT_counter] = 'E';
							SPT_counter++;
							stress = TRUE;
						}
						else
							goto PROBLEMATIC_E;
					}
					//V-CVs
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (is_it_vowel(argument[arg_counter + 2])) && (argument[arg_counter + 3] == 's') && (argument[arg_counter + 4] == '\0'))
					{
						if ((argument[arg_counter + 2] == 'e') && ((is_it_vowel(argument[arg_counter - 2])) || (is_it_vowel(argument[arg_counter - 3]))))
						{
							SPT_word[SPT_counter] = 'E';
							SPT_counter++;
							stress = TRUE;
						}
						else if (!(argument[arg_counter + 2] == 'e'))
						{
							SPT_word[SPT_counter] = 'E';
							SPT_counter++;
							stress = TRUE;
						}
						else
							goto PROBLEMATIC_E;
					}
					//V-CCVs
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (is_it_consonant(argument[arg_counter + 2])) && (is_it_vowel(argument[arg_counter + 3])) && (argument[arg_counter + 4] == 's') && (argument[arg_counter + 5] == '\0'))
					{
						if ((argument[arg_counter + 3] == 'e') && ((is_it_vowel(argument[arg_counter - 2])) || (is_it_vowel(argument[arg_counter - 3]))))
						{
							SPT_word[SPT_counter] = 'E';
							SPT_counter++;
							stress = TRUE;
						}
						else if (!(argument[arg_counter + 3] == 'e'))
						{
							SPT_word[SPT_counter] = 'E';
							SPT_counter++;
							stress = TRUE;
						}
						else
							goto PROBLEMATIC_E;
					}
					//V-CyV
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (argument[arg_counter + 2] == 'y' || argument[arg_counter + 2] == 'i') && (is_it_vowel(argument[arg_counter + 3])) && (argument[arg_counter + 4] == '\0') && !(argument[arg_counter + 2] == 'i' && argument[arg_counter + 3] == 'e'))
					{
						if ((argument[arg_counter + 3] == 'e') && ((is_it_vowel(argument[arg_counter - 2])) || (is_it_vowel(argument[arg_counter - 3]))))
						{
							SPT_word[SPT_counter] = 'E';
							SPT_counter++;
							stress = TRUE;
						}
						else if (!(argument[arg_counter + 3] == 'e'))
						{
							SPT_word[SPT_counter] = 'E';
							SPT_counter++;
							stress = TRUE;
						}
						else
							goto PROBLEMATIC_E;
					}
					//V-CyVs
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (argument[arg_counter + 2] == 'y' || argument[arg_counter + 2] == 'i') && (is_it_vowel(argument[arg_counter + 3])) && (argument[arg_counter + 4] == 's') && (argument[arg_counter + 5] == '\0') && !(argument[arg_counter + 2] == 'i' && argument[arg_counter + 3] == 'e'))
					{
						if ((argument[arg_counter + 3] == 'e') && ((is_it_vowel(argument[arg_counter - 2])) || (is_it_vowel(argument[arg_counter - 3]))))
						{
							SPT_word[SPT_counter] = 'E';
							SPT_counter++;
							stress = TRUE;
						}
						else if (!(argument[arg_counter + 3] == 'e'))
						{
							SPT_word[SPT_counter] = 'E';
							SPT_counter++;
							stress = TRUE;
						}
						else
							goto PROBLEMATIC_E;
					}
					else // No sctress accent
					{

					// I hat to do this, but this "e" is very problematic. I evoke the power of GOTO!
					PROBLEMATIC_E:

						// "e" is the first letter of the word
						if (!(is_it_consonant (argument[arg_counter - 1])) && !(is_it_vowel (argument[arg_counter - 1])))
						{
							SPT_word[SPT_counter] = 'e';
							SPT_counter++;
						}
						// eCC
						else if (((is_it_consonant (argument[arg_counter + 1])) && (argument[arg_counter + 1] == argument[arg_counter + 2])) || ((argument[arg_counter + 1] == 'c') && (argument[arg_counter + 2] == 'k')))
						{
							SPT_word[SPT_counter] = 'e';
							SPT_counter++;
						}
						// eV\0
						else if ((is_it_vowel(argument[arg_counter + 1]) && argument[arg_counter + 2] == '\0') || (is_it_vowel(argument[arg_counter + 1]) && argument[arg_counter + 2] == 's' && argument[arg_counter + 3] == '\0'))
						{
							SPT_word[SPT_counter] = 'e';
							SPT_counter++;
						}
						// there is no more other vowel
						else if (!is_there_more_than_one_vowel ())
						{
							SPT_word[SPT_counter] = 'e';
							SPT_counter++;
						}
						// there is a semivowel
						else if ((argument[arg_counter - 1] == 'y') || (argument[arg_counter + 1] == 'y') || (argument[arg_counter - 1] == 'i') || (argument[arg_counter + 1] == 'i') || (argument[arg_counter - 1] == 'w') || (argument[arg_counter + 1] == 'w'))
						{
							SPT_word[SPT_counter] = 'e';
							SPT_counter++;
						}
						// eCe\0
						else if ((is_it_consonant(argument[arg_counter + 1])) && (argument[arg_counter + 2] == 'e') && (argument[arg_counter + 3] == '\0'))
						{
							SPT_word[SPT_counter] = 'e';
							SPT_counter++;
						}
						// eCer\0 ex: member
						else if ((is_it_consonant(argument[arg_counter + 1])) && (argument[arg_counter + 2] == 'e') && (argument[arg_counter + 3] == 'r') && (argument[arg_counter + 4] == '\0'))
						{
							SPT_word[SPT_counter] = 'e';
							SPT_counter++;
						}
						// eCCer\0 ex: november
						else if ((is_it_consonant(argument[arg_counter + 1])) && (is_it_consonant(argument[arg_counter + 2])) && (argument[arg_counter + 3] == 'e') && (argument[arg_counter + 4] == 'r') && (argument[arg_counter + 5] == '\0'))
						{
							SPT_word[SPT_counter] = 'e';
							SPT_counter++;
						}
						// eCCCer\0 ex: novembrer
						else if ((is_it_consonant(argument[arg_counter + 1])) && (is_it_consonant(argument[arg_counter + 2])) && (is_it_consonant(argument[arg_counter + 3])) && (argument[arg_counter + 4] == 'e') && (argument[arg_counter + 5] == 'r') && (argument[arg_counter + 6] == '\0'))
						{
							SPT_word[SPT_counter] = 'e';
							SPT_counter++;
						}
						// ing\0 For preventing "e" becoming {ë}, it's for words like "reling"
						else if (argument[(strlen(argument) - 1)] == 'g' && argument[(strlen(argument) - 2)] == 'n' && argument[(strlen(argument) - 3)] == 'i')
						{
							SPT_word[SPT_counter] = 'e';
							SPT_counter++;
						}
						// There is more an non-final "e" ahead
						// else if (argument[arg_counter + 1] == 'e' || argument[arg_counter + 2] == 'e' || argument[arg_counter + 3] == 'e' || argument[arg_counter + 4] == 'e')
						else if ((argument[arg_counter + 1] == 'e' && !(argument[arg_counter + 2] == '\0')) || (argument[arg_counter + 2] == 'e' && !(argument[arg_counter + 3] == '\0')) || (argument[arg_counter + 3] == 'e' && !(argument[arg_counter + 4] == '\0')) || (argument[arg_counter + 4] == 'e' && !(argument[arg_counter + 5] == '\0')))
						{
							SPT_word[SPT_counter] = 'e';
							SPT_counter++;
						}
						// Ces\0
						else if ((is_it_consonant(argument[arg_counter - 1])) && (argument[arg_counter + 1] == 's') && (argument[arg_counter + 2] == '\0') && (is_it_vowel(argument[arg_counter -2]) || is_it_vowel(argument[arg_counter -3]) || is_it_vowel(argument[arg_counter -4])))
						{
							if (argument[arg_counter - 1] == 's' || argument[arg_counter - 1] == 'c') // Thus ses\0
							{
								#ifdef _WIN32
								SPT_word[SPT_counter] = SMALL_E_DIAERESIS;
								SPT_counter++;
								#else
								strncat(SPT_word, SMALL_E_DIAERESIS, 6);
								SPT_counter = SPT_counter + 2;
								#endif
								occurrence_of_the_small_e_diaeresis++;
							}
						}
						else
						{
							#ifdef _WIN32
							SPT_word[SPT_counter] = SMALL_E_DIAERESIS;
							SPT_counter++;
							#else
							strncat(SPT_word, SMALL_E_DIAERESIS, 6);
							SPT_counter = SPT_counter + 2;
							#endif
							occurrence_of_the_small_e_diaeresis++;
						}
					}
				}
			}


			/***************************************************************************
			************* i
			***************************************************************************/

			else if (argument[arg_counter] == 'i')
			{

				/************* -ie **/

				if (!(stress) && (argument[arg_counter + 1] == 'e') && argument[arg_counter + 2] == '\0')
				{
					SPT_word[SPT_counter] = 'I';
					SPT_counter++;
					SPT_word[SPT_counter] = ':';
					SPT_counter++;
					arg_counter = arg_counter + 2;
					stress = TRUE;
				}

				/************* -ieC / -ieV **/

				else if ((argument[arg_counter + 1] == 'e') && !(argument[arg_counter + 2] == '\0'))
				{
					SPT_word[SPT_counter] = 'y';
					SPT_counter++;
				}

				/************* -in **/

				else if (!(stress) && (is_there_more_than_one_vowel ()) && (argument[arg_counter + 1] == 'n') && (argument[arg_counter + 2] == '\0'))
				{
					SPT_word[SPT_counter] = 'I';
					stress = TRUE;
					SPT_counter++;
				}

				/************* oi **/

				else if (argument[arg_counter - 1] == 'o')
				{
					SPT_word[SPT_counter] = 'y';
					SPT_counter++;
				}

				/*******************/

				else
				{
					if (!(stress) && (is_there_more_than_one_vowel ()) && (argument[arg_counter + 1] == 'h') && (is_it_consonant (argument[arg_counter + 2]) || argument[arg_counter + 2] == '\0'))
					{
						SPT_word[SPT_counter] = 'I';
						stress = TRUE;
					}
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (((is_it_consonant (argument[arg_counter + 1])) && (argument[arg_counter + 1] == argument[arg_counter + 2])) || ((argument[arg_counter + 1] == 'c') && (argument[arg_counter + 2] == 'k'))) && (argument[arg_counter + 3] == '\0'))
					{
						SPT_word[SPT_counter] = 'I';
						stress = TRUE;
					}
					//V-CV
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (is_it_vowel(argument[arg_counter + 2])) && (argument[arg_counter + 3] == '\0'))
					{
						if ((argument[arg_counter + 2] == 'e') && ((is_it_vowel(argument[arg_counter - 2])) || (is_it_vowel(argument[arg_counter - 3]))))
						{
							SPT_word[SPT_counter] = 'I';
							stress = TRUE;
						}
						else if (!(argument[arg_counter + 2] == 'e'))
						{
							SPT_word[SPT_counter] = 'I';
							stress = TRUE;
						}
						else
						{
							SPT_word[SPT_counter] = 'i';
						}
					}
					//V-CCV
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (is_it_consonant(argument[arg_counter + 2])) && (is_it_vowel(argument[arg_counter + 3])) && (argument[arg_counter + 4] == '\0'))
					{
						if ((argument[arg_counter + 3] == 'e') && ((is_it_vowel(argument[arg_counter - 2])) || (is_it_vowel(argument[arg_counter - 3]))))
						{
							SPT_word[SPT_counter] = 'I';
							stress = TRUE;
						}
						else if (!(argument[arg_counter + 3] == 'e'))
						{
							SPT_word[SPT_counter] = 'I';
							stress = TRUE;
						}
						else
						{
							SPT_word[SPT_counter] = 'i';
						}
					}
					else // No sctress accent
					{
						SPT_word[SPT_counter] = 'i';
					}
					SPT_counter++;
				}
			}

			/***************************************************************************
			************* o
			***************************************************************************/

			else if (argument[arg_counter] == 'o')
			{

				/************* ou **/

				if (argument[arg_counter + 1] == 'u')
				{
					if (!(stress) && (is_there_more_than_one_vowel ()) && (argument[arg_counter + 1] == 'h') && (is_it_consonant (argument[arg_counter + 2]) || argument[arg_counter + 2] == '\0'))
					{
						SPT_word[SPT_counter] = 'U';
						stress = TRUE;
					}
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (((is_it_consonant (argument[arg_counter + 1])) && (argument[arg_counter + 1] == argument[arg_counter + 2])) || ((argument[arg_counter + 1] == 'c') && (argument[arg_counter + 2] == 'k'))) && (argument[arg_counter + 3] == '\0'))
					{
						SPT_word[SPT_counter] = 'U';
						stress = TRUE;
					}
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_vowel(argument[arg_counter + 2])) && (argument[arg_counter + 3] == '\0'))
					{
						SPT_word[SPT_counter] = 'U';
						stress = TRUE;
						arg_counter--; // For correct the arg_counter = arg_counter + 2; below
					}
					else // No sctress accent
					{
						SPT_word[SPT_counter] = 'u';
						arg_counter--; // For correct the arg_counter = arg_counter + 2; below
					}

					SPT_counter++;
					SPT_word[SPT_counter] = ':';
					SPT_counter++;
					arg_counter = arg_counter + 2;
				}

				/******************/

				else
				{
					if (!(stress) && (is_there_more_than_one_vowel ()) && (argument[arg_counter + 1] == 'h') && (is_it_consonant (argument[arg_counter + 2]) || argument[arg_counter + 2] == '\0'))
					{
						SPT_word[SPT_counter] = 'O';
						SPT_counter++;
						stress = TRUE;
					}
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (((is_it_consonant (argument[arg_counter + 1])) && (argument[arg_counter + 1] == argument[arg_counter + 2])) || ((argument[arg_counter + 1] == 'c') && (argument[arg_counter + 2] == 'k'))) && (argument[arg_counter + 3] == '\0'))
					{
						SPT_word[SPT_counter] = 'O';
						SPT_counter++;
						stress = TRUE;
					}
					else if (!(stress) && (is_there_more_than_one_vowel ()) && ((is_it_consonant(argument[arg_counter + 1])) || (argument[arg_counter + 1] == 'y') || (argument[arg_counter + 1] == 'i')) && !(argument[arg_counter + 1] == 's') && (argument[arg_counter + 2] == '\0'))
					{
						SPT_word[SPT_counter] = 'O';
						SPT_counter++;
						stress = TRUE;
					}
					//V-CV
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (is_it_vowel(argument[arg_counter + 2])) && (argument[arg_counter + 3] == '\0'))
					{
						if ((argument[arg_counter + 2] == 'e') && ((is_it_vowel(argument[arg_counter - 2])) || (is_it_vowel(argument[arg_counter - 3]))))
						{
							SPT_word[SPT_counter] = 'O';
							SPT_counter++;
							stress = TRUE;
						}
						else if (!(argument[arg_counter + 2] == 'e'))
						{
							SPT_word[SPT_counter] = 'O';
							SPT_counter++;
							stress = TRUE;
						}
						else
						{
							SPT_word[SPT_counter] = 'o';
							SPT_counter++;
						}
					}
					//V-CCV
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (is_it_consonant(argument[arg_counter + 2])) && (is_it_vowel(argument[arg_counter + 3])) && (argument[arg_counter + 4] == '\0'))
					{
						if ((argument[arg_counter + 3] == 'e') && ((is_it_vowel(argument[arg_counter - 2])) || (is_it_vowel(argument[arg_counter - 3]))))
						{
							SPT_word[SPT_counter] = 'O';
							SPT_counter++;
							stress = TRUE;
						}
						else if (!(argument[arg_counter + 3] == 'e'))
						{
							SPT_word[SPT_counter] = 'O';
							SPT_counter++;
							stress = TRUE;
						}
						else
						{
							SPT_word[SPT_counter] = 'o';
							SPT_counter++;
						}
					}
					else // No sctress accent
					{
						SPT_word[SPT_counter] = 'o';
						SPT_counter++;
					}
				}
			}

			/***************************************************************************
			************* u
			***************************************************************************/

			else if (argument[arg_counter] == 'u')
			{

				/************* ue **/

				if (argument[arg_counter + 1] == 'e')
				{
					if (argument[arg_counter - 1] == 'g')
					{
						SPT_word[SPT_counter] = 'u';
						SPT_counter++;
					}
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (argument[arg_counter + 2] == '\0'))
					{
						#ifdef _WIN32
						SPT_word[SPT_counter] = CAPITAL_U_DIAERESIS;
						SPT_counter++;
						#else
						strncat(SPT_word, CAPITAL_U_DIAERESIS, 6);
						SPT_counter = SPT_counter + 2;
						#endif
						stress = TRUE;
						SPT_word[SPT_counter] = ':';
						SPT_counter++;
						arg_counter++;
					}
					else
					{
						#ifdef _WIN32
						SPT_word[SPT_counter] = SMALL_U_DIAERESIS;
						SPT_counter++;
						#else
						strncat(SPT_word, SMALL_U_DIAERESIS, 6);
						SPT_counter = SPT_counter + 2;
						#endif
						SPT_word[SPT_counter] = ':';
						SPT_counter++;
						arg_counter++;
					}
				}

				/************* uCe **/

				else if ((is_it_consonant(argument[arg_counter + 1])) && (argument[arg_counter + 2] == 'e') && ((argument[arg_counter + 3] == '\0') || (argument[arg_counter + 3] == 's')))
				{
					if ((is_there_something_here(argument[arg_counter - 3]) || is_it_vowel(argument[arg_counter - 2])) && !(argument[arg_counter + 1] == 'l'))
					{
						#ifdef _WIN32
						SPT_word[SPT_counter] = CAPITAL_U_DIAERESIS;
						SPT_counter++;
						#else
						strncat(SPT_word, CAPITAL_U_DIAERESIS, 6);
						SPT_counter = SPT_counter + 2;
						#endif
						stress = TRUE;
					}
					else // No sctress accent
					{
						#ifdef _WIN32
						SPT_word[SPT_counter] = SMALL_U_DIAERESIS;
						SPT_counter++;
						#else
						strncat(SPT_word, SMALL_U_DIAERESIS, 6);
						SPT_counter = SPT_counter + 2;
						#endif
					}
				}

				/******************/

				else
				{
					if (!(stress) && (is_there_more_than_one_vowel ()) && (argument[arg_counter + 1] == 'h') && (is_it_consonant (argument[arg_counter + 2]) || argument[arg_counter + 2] == '\0'))
					{
						SPT_word[SPT_counter] = 'U';
						SPT_counter++;
						stress = TRUE;
					}
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (((is_it_consonant (argument[arg_counter + 1])) && (argument[arg_counter + 1] == argument[arg_counter + 2])) || ((argument[arg_counter + 1] == 'c') && (argument[arg_counter + 2] == 'k'))) && (argument[arg_counter + 3] == '\0'))
					{
						SPT_word[SPT_counter] = 'U';
						SPT_counter++;
						stress = TRUE;
					}
					// For the -(i)um case
					else if (argument[arg_counter + 1] == 'm' && argument[arg_counter + 2] == '\0')
					{
						SPT_word[SPT_counter] = 'u';
						SPT_counter++;
					}
					// For the -ule case
					else if (argument[arg_counter + 1] == 'l' && argument[arg_counter + 2] == 'e' && argument[arg_counter + 3] == '\0')
					{
						#ifdef _WIN32
						SPT_word[SPT_counter] = SMALL_U_DIAERESIS;
						SPT_counter++;
						#else
						strncat(SPT_word, SMALL_U_DIAERESIS, 6);
						SPT_counter = SPT_counter + 2;
						#endif
					}
					else if (!(stress) && (is_there_more_than_one_vowel ()) && ((is_it_consonant(argument[arg_counter + 1])) || (argument[arg_counter + 1] == 'y') || (argument[arg_counter + 1] == 'i')) && !(argument[arg_counter + 1] == 's') && (argument[arg_counter + 2] == '\0'))
					{
						SPT_word[SPT_counter] = 'U';
						SPT_counter++;
						stress = TRUE;
					}
					//V-CV
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (is_it_vowel(argument[arg_counter + 2])) && (argument[arg_counter + 3] == '\0'))
					{
						if ((argument[arg_counter + 2] == 'e') && ((is_it_vowel(argument[arg_counter - 2])) || (is_it_vowel(argument[arg_counter - 3]))))
						{
							SPT_word[SPT_counter] = 'U';
							SPT_counter++;
							stress = TRUE;
						}
						else if (!(argument[arg_counter + 2] == 'e'))
						{
							SPT_word[SPT_counter] = 'U';
							SPT_counter++;
							stress = TRUE;
						}
						else
						{
							SPT_word[SPT_counter] = 'u';
							SPT_counter++;
						}
					}
					//V-CCV
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (is_it_consonant(argument[arg_counter + 2])) && (is_it_vowel(argument[arg_counter + 3])) && (argument[arg_counter + 4] == '\0'))
					{
						if ((argument[arg_counter + 3] == 'e') && ((is_it_vowel(argument[arg_counter - 2])) || (is_it_vowel(argument[arg_counter - 3]))))
						{
							SPT_word[SPT_counter] = 'U';
							SPT_counter++;
							stress = TRUE;
						}
						else if (!(argument[arg_counter + 3] == 'e'))
						{
							SPT_word[SPT_counter] = 'U';
							SPT_counter++;
							stress = TRUE;
						}
						else
						{
							SPT_word[SPT_counter] = 'u';
							SPT_counter++;
						}
					}
					else // No sctress accent
					{
						SPT_word[SPT_counter] = 'u';
						SPT_counter++;
					}
				}
			}

			/***************************************************************************
			************* y
			***************************************************************************/

			else if (argument[arg_counter] == 'y')
			{

				/************* Cy / CyC **/

				if ((!is_it_vowel(argument[arg_counter - 1])) && (!is_it_vowel(argument[arg_counter + 1])))
				{
					if ((argument[arg_counter + 1] == '\0') || ((argument[arg_counter + 1] == 's') && (argument[arg_counter + 2] == '\0')))
					{
						SPT_word[SPT_counter] = 'i';
						SPT_counter++;
					}
					else
					{
						if (!(stress) && (is_there_more_than_one_vowel ()) && (argument[arg_counter + 1] == 'h') && (is_it_consonant (argument[arg_counter + 2]) || argument[arg_counter + 2] == '\0'))
						{
							#ifdef _WIN32
							SPT_word[SPT_counter] = CAPITAL_U_DIAERESIS;
							SPT_counter++;
							#else
							strncat(SPT_word, CAPITAL_U_DIAERESIS, 6);
							SPT_counter = SPT_counter + 2;
							#endif
							stress = TRUE;
						}
						else if (!(stress) && (is_there_more_than_one_vowel ()) && (((is_it_consonant (argument[arg_counter + 1])) && (argument[arg_counter + 1] == argument[arg_counter + 2])) || ((argument[arg_counter + 1] == 'c') && (argument[arg_counter + 2] == 'k'))) && (argument[arg_counter + 3] == '\0'))
						{
							#ifdef _WIN32
							SPT_word[SPT_counter] = CAPITAL_U_DIAERESIS;
							SPT_counter++;
							#else
							strncat(SPT_word, CAPITAL_U_DIAERESIS, 6);
							SPT_counter = SPT_counter + 2;
							#endif
							stress = TRUE;
						}
						//V-CV
						else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (is_it_vowel(argument[arg_counter + 2])) && (argument[arg_counter + 3] == '\0'))
						{
							if ((argument[arg_counter + 2] == 'e') && ((is_it_vowel(argument[arg_counter - 2])) || (is_it_vowel(argument[arg_counter - 3]))))
							{
								#ifdef _WIN32
								SPT_word[SPT_counter] = CAPITAL_U_DIAERESIS;
								SPT_counter++;
								#else
								strncat(SPT_word, CAPITAL_U_DIAERESIS, 6);
								SPT_counter = SPT_counter + 2;
								#endif
								stress = TRUE;
							}
							else if (!(argument[arg_counter + 2] == 'e'))
							{
								#ifdef _WIN32
								SPT_word[SPT_counter] = CAPITAL_U_DIAERESIS;
								SPT_counter++;
								#else
								strncat(SPT_word, CAPITAL_U_DIAERESIS, 6);
								SPT_counter = SPT_counter + 2;
								#endif
								stress = TRUE;
							}
							else
							{
								#ifdef _WIN32
								SPT_word[SPT_counter] = SMALL_U_DIAERESIS;
								SPT_counter++;
								#else
								strncat(SPT_word, SMALL_U_DIAERESIS, 6);
								SPT_counter = SPT_counter + 2;
								#endif
							}
						}
						//V-CCV
						else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (is_it_consonant(argument[arg_counter + 2])) && (is_it_vowel(argument[arg_counter + 3])) && (argument[arg_counter + 4] == '\0'))
						{
							if ((argument[arg_counter + 3] == 'e') && ((is_it_vowel(argument[arg_counter - 2])) || (is_it_vowel(argument[arg_counter - 3]))))
							{
								#ifdef _WIN32
								SPT_word[SPT_counter] = CAPITAL_U_DIAERESIS;
								SPT_counter++;
								#else
								strncat(SPT_word, CAPITAL_U_DIAERESIS, 6);
								SPT_counter = SPT_counter + 2;
								#endif
								stress = TRUE;
							}
							else if (!(argument[arg_counter + 3] == 'e'))
							{
								#ifdef _WIN32
								SPT_word[SPT_counter] = CAPITAL_U_DIAERESIS;
								SPT_counter++;
								#else
								strncat(SPT_word, CAPITAL_U_DIAERESIS, 6);
								SPT_counter = SPT_counter + 2;
								#endif
								stress = TRUE;
							}
							else
							{
								#ifdef _WIN32
								SPT_word[SPT_counter] = SMALL_U_DIAERESIS;
								SPT_counter++;
								#else
								strncat(SPT_word, SMALL_U_DIAERESIS, 6);
								SPT_counter = SPT_counter + 2;
								#endif
							}
						}
						//V-CVs
						else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (is_it_vowel(argument[arg_counter + 2])) && (argument[arg_counter + 3] == 's') && (argument[arg_counter + 4] == '\0'))
						{
							if ((argument[arg_counter + 2] == 'e') && ((is_it_vowel(argument[arg_counter - 2])) || (is_it_vowel(argument[arg_counter - 3]))))
							{
								#ifdef _WIN32
								SPT_word[SPT_counter] = CAPITAL_U_DIAERESIS;
								SPT_counter++;
								#else
								strncat(SPT_word, CAPITAL_U_DIAERESIS, 6);
								SPT_counter = SPT_counter + 2;
								#endif
								stress = TRUE;
							}
							else if (!(argument[arg_counter + 2] == 'e'))
							{
								#ifdef _WIN32
								SPT_word[SPT_counter] = CAPITAL_U_DIAERESIS;
								SPT_counter++;
								#else
								strncat(SPT_word, CAPITAL_U_DIAERESIS, 6);
								SPT_counter = SPT_counter + 2;
								#endif
								stress = TRUE;
							}
							else
							{
								#ifdef _WIN32
								SPT_word[SPT_counter] = SMALL_U_DIAERESIS;
								SPT_counter++;
								#else
								strncat(SPT_word, SMALL_U_DIAERESIS, 6);
								SPT_counter = SPT_counter + 2;
								#endif
							}
						}
						//V-CCVs
						else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (is_it_consonant(argument[arg_counter + 2])) && (is_it_vowel(argument[arg_counter + 3])) && (argument[arg_counter + 4] == 's') && (argument[arg_counter + 5] == '\0'))
						{
							if ((argument[arg_counter + 3] == 'e') && ((is_it_vowel(argument[arg_counter - 2])) || (is_it_vowel(argument[arg_counter - 3]))))
							{
								#ifdef _WIN32
								SPT_word[SPT_counter] = CAPITAL_U_DIAERESIS;
								SPT_counter++;
								#else
								strncat(SPT_word, CAPITAL_U_DIAERESIS, 6);
								SPT_counter = SPT_counter + 2;
								#endif
								stress = TRUE;
							}
							else if (!(argument[arg_counter + 3] == 'e'))
							{
								#ifdef _WIN32
								SPT_word[SPT_counter] = CAPITAL_U_DIAERESIS;
								SPT_counter++;
								#else
								strncat(SPT_word, CAPITAL_U_DIAERESIS, 6);
								SPT_counter = SPT_counter + 2;
								#endif
								stress = TRUE;
							}
							else
							{
								#ifdef _WIN32
								SPT_word[SPT_counter] = SMALL_U_DIAERESIS;
								SPT_counter++;
								#else
								strncat(SPT_word, SMALL_U_DIAERESIS, 6);
								SPT_counter = SPT_counter + 2;
								#endif
							}
						}
						//V-CyV
						else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (argument[arg_counter + 2] == 'y' || argument[arg_counter + 2] == 'i') && (is_it_vowel(argument[arg_counter + 3])) && (argument[arg_counter + 4] == '\0') && !(argument[arg_counter + 2] == 'i' && argument[arg_counter + 3] == 'e'))
						{
							if ((argument[arg_counter + 3] == 'e') && ((is_it_vowel(argument[arg_counter - 2])) || (is_it_vowel(argument[arg_counter - 3]))))
							{
								#ifdef _WIN32
								SPT_word[SPT_counter] = CAPITAL_U_DIAERESIS;
								SPT_counter++;
								#else
								strncat(SPT_word, CAPITAL_U_DIAERESIS, 6);
								SPT_counter = SPT_counter + 2;
								#endif
								stress = TRUE;
							}
							else if (!(argument[arg_counter + 3] == 'e'))
							{
								#ifdef _WIN32
								SPT_word[SPT_counter] = CAPITAL_U_DIAERESIS;
								SPT_counter++;
								#else
								strncat(SPT_word, CAPITAL_U_DIAERESIS, 6);
								SPT_counter = SPT_counter + 2;
								#endif
								stress = TRUE;
							}
							else
							{
								#ifdef _WIN32
								SPT_word[SPT_counter] = SMALL_U_DIAERESIS;
								SPT_counter++;
								#else
								strncat(SPT_word, SMALL_U_DIAERESIS, 6);
								SPT_counter = SPT_counter + 2;
								#endif
							}
						}
						//V-CyVs
						else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (argument[arg_counter + 2] == 'y' || argument[arg_counter + 2] == 'i') && (is_it_vowel(argument[arg_counter + 3])) && (argument[arg_counter + 4] == 's') && (argument[arg_counter + 5] == '\0') && !(argument[arg_counter + 2] == 'i' && argument[arg_counter + 3] == 'e'))
						{
							if ((argument[arg_counter + 3] == 'e') && ((is_it_vowel(argument[arg_counter - 2])) || (is_it_vowel(argument[arg_counter - 3]))))
							{
								#ifdef _WIN32
								SPT_word[SPT_counter] = CAPITAL_U_DIAERESIS;
								SPT_counter++;
								#else
								strncat(SPT_word, CAPITAL_U_DIAERESIS, 6);
								SPT_counter = SPT_counter + 2;
								#endif
								stress = TRUE;
							}
							else if (!(argument[arg_counter + 3] == 'e'))
							{
								#ifdef _WIN32
								SPT_word[SPT_counter] = CAPITAL_U_DIAERESIS;
								SPT_counter++;
								#else
								strncat(SPT_word, CAPITAL_U_DIAERESIS, 6);
								SPT_counter = SPT_counter + 2;
								#endif
								stress = TRUE;
							}
							else
							{
								#ifdef _WIN32
								SPT_word[SPT_counter] = SMALL_U_DIAERESIS;
								SPT_counter++;
								#else
								strncat(SPT_word, SMALL_U_DIAERESIS, 6);
								SPT_counter = SPT_counter + 2;
								#endif
							}
						}
						// eCer\0 ex: member
						else if ((is_it_consonant(argument[arg_counter + 1])) && (argument[arg_counter + 2] == 'e') && (argument[arg_counter + 3] == 'r') && (argument[arg_counter + 4] == '\0'))
						{
							#ifdef _WIN32
							SPT_word[SPT_counter] = CAPITAL_U_DIAERESIS;
							SPT_counter++;
							#else
							strncat(SPT_word, CAPITAL_U_DIAERESIS, 6);
							SPT_counter = SPT_counter + 2;
							#endif
							stress = TRUE;
						}
						// eCCer\0 ex: november
						else if ((is_it_consonant(argument[arg_counter + 1])) && (is_it_consonant(argument[arg_counter + 2])) && (argument[arg_counter + 3] == 'e') && (argument[arg_counter + 4] == 'r') && (argument[arg_counter + 5] == '\0'))
						{
							#ifdef _WIN32
							SPT_word[SPT_counter] = CAPITAL_U_DIAERESIS;
							SPT_counter++;
							#else
							strncat(SPT_word, CAPITAL_U_DIAERESIS, 6);
							SPT_counter = SPT_counter + 2;
							#endif
							stress = TRUE;
						}
						// eCCCer\0 ex: novembrer
						else if ((is_it_consonant(argument[arg_counter + 1])) && (is_it_consonant(argument[arg_counter + 2])) && (is_it_consonant(argument[arg_counter + 3])) && (argument[arg_counter + 4] == 'e') && (argument[arg_counter + 5] == 'r') && (argument[arg_counter + 6] == '\0'))
						{
							#ifdef _WIN32
							SPT_word[SPT_counter] = CAPITAL_U_DIAERESIS;
							SPT_counter++;
							#else
							strncat(SPT_word, CAPITAL_U_DIAERESIS, 6);
							SPT_counter = SPT_counter + 2;
							#endif
							stress = TRUE;
						}
						else // No sctress accent
						{
							#ifdef _WIN32
							SPT_word[SPT_counter] = SMALL_U_DIAERESIS;
							SPT_counter++;
							#else
							strncat(SPT_word, SMALL_U_DIAERESIS, 6);
							SPT_counter = SPT_counter + 2;
							#endif
						}
					}
				}

				/********************/

				else
				{
					SPT_word[SPT_counter] = 'y';
					SPT_counter++;
				}
			}

			/***************************************************************************
			************* w
			***************************************************************************/

			else if ((argument[arg_counter] == 'w') && (is_it_consonant (argument[arg_counter - 1])) && (is_it_consonant (argument[arg_counter + 1])))
			{
				SPT_word[SPT_counter] = 'u';
				SPT_counter++;
			}


			/********************/
			/********************/
			/********************/

			else
			{
				SPT_word[SPT_counter] = argument[arg_counter];
				SPT_counter++;
			}
		}

		/***************************************************************************
		****************************************************************************
		************* CONSONANTS
		****************************************************************************
		****************************************************************************/

		/***************************************************************************
		************* b
		***************************************************************************/

		if (argument[arg_counter] == 'b')
		{
			if (argument[arg_counter - 1] == 'b')
			{
				// Do nothing, it's just a repeated letter
			}
			else
			{
				SPT_word[SPT_counter] = 'b';
				SPT_counter++;
			}
		}

		/***************************************************************************
		************* c
		***************************************************************************/

		if (argument[arg_counter] == 'c')
		{
			if ((argument[arg_counter - 1] == 'c') && !(argument[arg_counter + 1] == 'e' || argument[arg_counter + 1] == 'i' || argument[arg_counter + 1] == 'y'))
			{
				// Do nothing, it's just a repeated letter
			}
			else if (argument[arg_counter + 1] == 'a' || argument[arg_counter + 1] == 'o' || argument[arg_counter + 1] == 'u' || argument[arg_counter + 1] == 'c')
			{
				SPT_word[SPT_counter] = 'k';
				SPT_counter++;
			}
			else if (argument[arg_counter + 1] == 'e' || argument[arg_counter + 1] == 'i' || argument[arg_counter + 1] == 'y')
			{
				SPT_word[SPT_counter] = 't';
				SPT_counter++;
				SPT_word[SPT_counter] = 's';
				SPT_counter++;
			}
			else if ((argument[arg_counter + 1] == 'h') && (is_it_vowel(argument[arg_counter + 2])))
			{
				SPT_word[SPT_counter] = 't';
				SPT_counter++;
				SPT_word[SPT_counter] = 'c';
				SPT_counter++;
				// arg_counter++;  // Yeah, you must jump one letter
			}
			else if ((argument[arg_counter + 1] == 'h') && (!is_it_vowel(argument[arg_counter + 2])))
			{
				SPT_word[SPT_counter] = 'k';
				SPT_counter++;
				arg_counter++; arg_counter++; // Yeah, you must jump one letter
			}
			else
			{
				SPT_word[SPT_counter] = 'k';
				SPT_counter++;
			}
		}

		/***************************************************************************
		************* d
		***************************************************************************/

		if (argument[arg_counter] == 'd')
		{
			SPT_word[SPT_counter] = 'd';
			SPT_counter++;
			if (argument[arg_counter + 1] == 'd') arg_counter++; // Yeah, you must jump one letter
		}

		/***************************************************************************
		************* f
		***************************************************************************/

		if (argument[arg_counter] == 'f')
		{
			if (argument[arg_counter - 1] == 'f')
			{
				// Do nothing, it's just a repeated letter
			}
			else
			{
				SPT_word[SPT_counter] = 'f';
				SPT_counter++;
			}
		}

		/***************************************************************************
		************* g
		***************************************************************************/

		if (argument[arg_counter] == 'g')
		{
			if (argument[arg_counter - 1] == 'g')
			{
				// Do nothing, it's just a repeated letter
			}
			else if (argument[arg_counter + 1] == 'e' || argument[arg_counter + 1] == 'i' || argument[arg_counter + 1] == 'y')
			{
				SPT_word[SPT_counter] = 'd';
				SPT_counter++;
				SPT_word[SPT_counter] = 'j';
				SPT_counter++;
			}
			else if (argument[arg_counter + 1] == 'n')
			{
				SPT_word[SPT_counter] = 'n';
				SPT_counter++;
				SPT_word[SPT_counter] = 'y';
				SPT_counter++;
				arg_counter++; // Yeah, you must jump one letter
			}
			else
			{
				SPT_word[SPT_counter] = 'g';
				SPT_counter++;
			}
		}

		/***************************************************************************
		************* h
		***************************************************************************/

		if (argument[arg_counter] == 'h')
		{
			if ((argument[arg_counter - 1] == 'i') && (argument[arg_counter - 2] == 'e'))
			{
				// Do nothing, it's the only way I found to avoid the bug of when I put something like "eihb" I get "{e:y:b} (there is an extra :)
			}
			else if (argument[arg_counter - 1] == 'c')
			{
				// Do nothing, it's the only way I found to avoid the bug of when I put something like "chacra" I get "{tchakra} (this "{h}" shoouldn't appear)
			}
			else if ((argument[arg_counter - 1] == 'g') || (argument[arg_counter - 1] == 'b') || (argument[arg_counter - 1] == 'd'))
			{
				// DO nothing. For words like "yunghy", "lambhel" or "brozdhos"
			}
			else if (is_it_vowel (argument[arg_counter - 1]) && is_it_consonant(argument[arg_counter + 1]))
			{
				SPT_word[SPT_counter] = ':';
				SPT_counter++;
			}
			//VhC
			else if (is_it_vowel (argument[arg_counter - 1]) && is_it_consonant(argument[arg_counter + 1]))
			{
				SPT_word[SPT_counter] = ':';
				SPT_counter++;
			}
			//Vh\0
			else if (is_it_vowel (argument[arg_counter - 1]) && argument[arg_counter + 1] == '\0')
			{
				SPT_word[SPT_counter] = ':';
				SPT_counter++;
			}
			//Vhe\0
			else if (is_it_vowel (argument[arg_counter - 1]) && argument[arg_counter + 1] == 'e' && argument[arg_counter + 2] == '\0')
			{
				SPT_word[SPT_counter] = ':';
				SPT_counter++;
			}
			else if (is_it_vowel (argument[arg_counter + 1]) || !(argument[arg_counter + 1] == 'e' && argument[arg_counter + 2] == '\0'))
			{
				SPT_word[SPT_counter] = 'h';
				SPT_counter++;
			}
			else if (!(SPT_word[SPT_counter - 1] == ':'))
			{
				SPT_word[SPT_counter] = ':';
				SPT_counter++;
			}
			else
			{
				SPT_word[SPT_counter] = 'h';
				SPT_counter++;
			}
		}

		/***************************************************************************
		************* k
		***************************************************************************/

		if (argument[arg_counter] == 'k')
		{
			if (argument[arg_counter + 1] == 'h')
			{
				SPT_word[SPT_counter] = 'q';
				SPT_counter++;
				arg_counter++; // Yeah, you must jump one letter
			}
			else if (argument[arg_counter - 1] == 'c')
			{
				SPT_word[SPT_counter] = '(';
				SPT_counter++;
				SPT_word[SPT_counter] = 'k';
				SPT_counter++;
				SPT_word[SPT_counter] = ')';
				SPT_counter++;
			}
			else
			{
				SPT_word[SPT_counter] = 'k';
				SPT_counter++;
			}
		}

		/***************************************************************************
		************* l
		***************************************************************************/

		if (argument[arg_counter] == 'l')
		{
			SPT_word[SPT_counter] = 'l';
			SPT_counter++;
			if (argument[arg_counter + 1] == 'l') arg_counter++; // Yeah, you must jump one letter
		}

		/***************************************************************************
		************* p
		***************************************************************************/

		if (argument[arg_counter] == 'p')
		{
			if (argument[arg_counter + 1] == 'h')
			{
				SPT_word[SPT_counter] = 'f';
				SPT_counter++;
				arg_counter++; // Yeah, you must jump one letter
			}
			else
			{
				SPT_word[SPT_counter] = 'p';
				SPT_counter++;
			}
		}

		/***************************************************************************
		************* q
		***************************************************************************/

		if (argument[arg_counter] == 'q')
		{
			if (argument[arg_counter + 2] == 'a' || argument[arg_counter + 2] == 'o' || argument[arg_counter + 2] == 'u')
			{
				SPT_word[SPT_counter] = 'k';
				SPT_counter++;
				SPT_word[SPT_counter] = 'w';
				SPT_counter++;
				arg_counter++; // Yeah, you must jump one letter
			}
			else
			{
				SPT_word[SPT_counter] = 'k';
				SPT_counter++;
				arg_counter++; // Yeah, you must jump one letter
			}
		}

		/***************************************************************************
		************* r
		***************************************************************************/

		if (argument[arg_counter] == 'r')
		{
			if (argument[arg_counter + 1] == 'r' || argument[arg_counter + 1] == 'l')
			{
				SPT_word[SPT_counter] = 'r';
				SPT_counter++;
				arg_counter++; // Yeah, you must jump one letter
			}
			else
			{
				SPT_word[SPT_counter] = 'r';
				SPT_counter++;
			}
		}

		/***************************************************************************
		************* s
		***************************************************************************/

		if (argument[arg_counter] == 's')
		{
			if (argument[arg_counter - 1] == 's')
			{
				if (is_it_vowel(argument[arg_counter + 1]))
				{
					// Do nothing
				}
				else
				{
					SPT_word[SPT_counter] = '(';
					SPT_counter++;
					SPT_word[SPT_counter] = 's';
					SPT_counter++;
					SPT_word[SPT_counter] = ')';
					SPT_counter++;
				}
			}
			else if ((is_it_vowel (argument[arg_counter - 1])) && (is_it_vowel (argument[arg_counter + 1])))
			{
				SPT_word[SPT_counter] = 'z';
				SPT_counter++;
			}
			else if (argument[arg_counter - 1] == 't') // For preventing the following "else if" to make "ts" sound {tz}
			{
				SPT_word[SPT_counter] = 's';
				SPT_counter++;
			}
			/*else if (is_it_consonant (argument[arg_counter - 1]) && !(argument[arg_counter + 1] == 'c') && !(is_it_vowel(argument[arg_counter + 1])))
			{
				SPT_word[SPT_counter] = 'z';
				SPT_counter++;
			}*/
			else if ((argument[arg_counter + 1] == 'c') && (argument[arg_counter + 2] == 'a' || argument[arg_counter + 2] == 'o' || argument[arg_counter + 2] == 'u'))
			{
				SPT_word[SPT_counter] = 's';
				SPT_counter++;
				SPT_word[SPT_counter] = 'k';
				SPT_counter++;
				arg_counter++; // Yeah, you must jump one letter
			}
			else if ((argument[arg_counter + 1] == 'c') && (argument[arg_counter + 2] == 'e' || argument[arg_counter + 2] == 'i' || argument[arg_counter + 2] == 'y'))
			{
				SPT_word[SPT_counter] = 's';
				SPT_counter++;
				arg_counter++; // Yeah, you must jump one letter
			}
			else if ((argument[arg_counter + 1] == 'c') && (argument[arg_counter + 2] == 'h'))
			{
				SPT_word[SPT_counter] = 'c';
				SPT_counter++;
				arg_counter++; arg_counter++; // Yeah, you must jump two letters
			}
			else if (argument[arg_counter + 1] == 'h')
			{
				SPT_word[SPT_counter] = 'x';
				SPT_counter++;
				arg_counter++; // Yeah, you must jump one letter
			}
			else
			{
				SPT_word[SPT_counter] = 's';
				SPT_counter++;
			}
		}

		/***************************************************************************
		************* t
		***************************************************************************/

		if (argument[arg_counter] == 't')
		{
			if (argument[arg_counter + 1] == 'h')
			{
				if ((SPT_word[SPT_counter - 1] == 's') || (SPT_word[SPT_counter - 1] == 'c') || (SPT_word[SPT_counter - 1] == 'j'))
				{
					SPT_word[SPT_counter] = 't';
					SPT_counter++;
				}
				else
				{
					#ifdef _WIN32
					SPT_word[SPT_counter] = SECTION_SIGN;
					SPT_counter++;
					#else
					strncat(SPT_word, SECTION_SIGN, 6);
					SPT_counter = SPT_counter + 2;
					#endif
				}
				arg_counter++; // Yeah, you must jump one letter
			}
			else
			{
				SPT_word[SPT_counter] = 't';
				SPT_counter++;
			}
		}

		/***************************************************************************
		************* x
		***************************************************************************/

		if (argument[arg_counter] == 'x')
		{
			SPT_word[SPT_counter] = 'k';
			SPT_counter++;
			SPT_word[SPT_counter] = 's';
			SPT_counter++;
		}

		/***************************************************************************
		************* z
		***************************************************************************/

		if (argument[arg_counter] == 'z')
		{
			SPT_word[SPT_counter] = 'd';
			SPT_counter++;
			SPT_word[SPT_counter] = 'z';
			SPT_counter++;
		}

		/***********************************************************************/
		/****************************FOR TESTING********************************/
		/***********************************************************************/
		if (show_system_messages)
		{
			printf("\n{%s}\n", SPT_word);
		}
		/***********************************************************************/

	}

	/***************************************************************************
	****************************************************************************
	************* CORRECTIONS
	****************************************************************************
	****************************************************************************/

	if (!(stress) && (is_there_more_than_one_vowel_ignoring_last_e ()))
	{

		strcpy(corrected_SPT_word, SPT_word); // I have to copy the word because the process below erases the stringsd, I don't know why.

		for (SPT_counter = (strlen(SPT_word) - 1); SPT_counter >= 0 ; SPT_counter--)
		{

			/***********************************************************************/
			/**************************JUST FOR TESTING ****************************/
			/***********************************************************************/
			if (show_system_messages)
			{
				printf("\nCORRECTION FASE: (char) SPT_word[%d] = %c", SPT_counter, SPT_word[SPT_counter]);
				printf("\nCORRECTION FASE: (string) SPT_word[%d] = %s", SPT_counter, SPT_word);
				printf("\nCORRECTION FASE: (strlen) argument = %d", (int)strlen(argument));
				printf("\nCORRECTION FASE: (strlen) SPT_word = %d", (int)strlen(SPT_word));
				if (SPT_word[SPT_counter + 1] == 's' && SPT_word[SPT_counter + 2] == '\0')
				{
					printf("\nCORRECTION FASE: This is the last letter of the word before a \"s\"");
				}
				else if (SPT_word[SPT_counter + 1] == '\0')
				{
					printf("\nCORRECTION FASE: This is the last letter of the word");
				}
				printf("\n-------");
			}
			/***********************************************************************/

			// This first condition is buggy because it considers the penultimate letter as ultimate, but it still does the job
			if (SPT_word[SPT_counter + 1] == 's' && SPT_word[SPT_counter + 2] == '\0')
			{
				// Do nothing
			}
			else if (SPT_word[SPT_counter + 1] == '\0')
			{
				// Do nothing
			}
			else
			{
				if (SPT_word[SPT_counter] == 'a')
				{
					SPT_word[SPT_counter] = 'A';
					correct_vowel = 'A';
					break;
				}
				else if (SPT_word[SPT_counter] == 'e')
				{
					SPT_word[SPT_counter] = 'E';
					correct_vowel = 'E';
					break;
				}
				else if (SPT_word[SPT_counter] == 'i' && !(SPT_word[SPT_counter - 1] == 'a') && !(SPT_word[SPT_counter + 1] == 'n' && SPT_word[SPT_counter + 2] == 'g') && !(is_it_consonant(SPT_word[SPT_counter + 1]) && SPT_word[SPT_counter + 2] == '\0'))
				{
					SPT_word[SPT_counter] = 'I';
					correct_vowel = 'I';
					break;
				}
				else if (SPT_word[SPT_counter] == 'o' && !(SPT_word[SPT_counter - 1] == 'e') && !(SPT_word[SPT_counter - 1] == 'a'))
				{
					SPT_word[SPT_counter] = 'O';
					correct_vowel = 'O';
					break;
				}
				else if (SPT_word[SPT_counter] == 'u' && !(SPT_word[SPT_counter - 1] == 'a') && !(SPT_word[SPT_counter - 1] == 'e') && !(SPT_word[SPT_counter - 1] == 'o') && !(argument[SPT_counter - 3] == 'w' || argument[SPT_counter - 2] == 'w' || argument[SPT_counter - 1] == 'w' || argument[SPT_counter] == 'w' || argument[SPT_counter + 1] == 'w' || argument[SPT_counter + 2] == 'w' || argument[SPT_counter + 3] == 'w') && !(SPT_word[SPT_counter - 1] == 'y' && SPT_word[SPT_counter + 1] == 'm'))
				// This line !(argument[SPT_counter - 3] == 'w' || ... || agument[SPT_counter + 3] == 'w') if for if the original letter was a "w"
				{
					SPT_word[SPT_counter] = 'U';
					correct_vowel = 'U';
					break;
				}
				else
				{
					SPT_word[SPT_counter] = SPT_word[SPT_counter];
				}
			}
		}
		strcpy(SPT_word, corrected_SPT_word); // Give the correct string back to its place
		SPT_word[SPT_counter] = correct_vowel;
	}


	printf("\n{%s}\n", SPT_word);

	if (strlen(SPT_word) > 10)
		too_long_word (lang);

	// For cleaning the string
	memset(SPT_word, '\0', strlen(SPT_word));
	SPT_counter = 0;
	stress = FALSE;

}
