#include <stdio.h>
#include <string.h>

#include "special_characters.h"

#include "system_text.h"

#define TRUE 1
#define FALSE 0

extern char argument[256];
extern short int lang;

extern short int show_system_messages;
extern short int is_testpnc_active;

char SPT_word[256];
char corrected_SPT_word[256];
char correct_vowel;

short int stress = FALSE;

short int occurrence_of_the_small_e_diaeresis = 0;

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

short int is_it_vowel_without_w (char ch)
{
	if (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || ch =='o' || ch=='O' || ch == 'u' || ch == 'U' || ch == 'y' || ch == 'Y')
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
		else if (argument[arg_counter] == 'e' && argument[arg_counter + 1] == '\0')
		{
			// IGNORE!!!!
		}
		else if (argument[arg_counter] == 'e' && argument[arg_counter + 1] == 's' && argument[arg_counter + 2] == '\0')
		{
			if (argument[arg_counter - 1] == 'y' || argument[arg_counter - 1] == 'w' || argument[arg_counter - 1] == 'c' || argument[arg_counter - 1] == 's')
			{
				// In this case the "e" appears; as a {ë}, but it still is a vowel
				vowel++;
			}
			else
			{
				// IGNORE!!!!
			}

		}
		else if (argument[arg_counter] == 'e' && !(argument[arg_counter - 1] == 's' && argument[arg_counter + 1] == 's' && argument[arg_counter + 2] == '\0')) vowel++;
		else if (argument[arg_counter] == 'e' && !(argument[arg_counter - 1] == 'c' && argument[arg_counter + 1] == 's' && argument[arg_counter + 2] == '\0')) vowel++;
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

short int is_there_only_one_vowel_ignoring_last_diaeresis_e ()
{
	short int arg_counter;
	short int vowel = 0;
	for (arg_counter = 0; arg_counter < strlen(argument) ; arg_counter++)
	{
		if (argument[arg_counter] == 'a') vowel++;
		else if ((argument[arg_counter] == 'a') && ((argument[arg_counter + 1] == 'i') || (argument[arg_counter + 1] == 'e') || (argument[arg_counter + 1] == 'y')))
		{
			vowel++;
			arg_counter++;
		}
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

	if (vowel == 1 && is_there_more_than_one_vowel ()) // If I don't add this condition "is_there_more_than_one_vowel", words like hehlp will be considered here
	{
		if (argument[strlen(argument) - 1] == 'e' && argument[strlen(argument)] == '\0')
			return FALSE;
		else if (!(argument[strlen(argument) - 2] == 's' || argument[strlen(argument) - 2] == 'c') && (is_it_consonant(argument[strlen(argument) - 3]) && argument[strlen(argument) - 2] == 'e' && argument[strlen(argument) - 1] == 's' && argument[strlen(argument)] == '\0'))
			return FALSE;
		else
			return TRUE;
	}
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
			if (is_there_more_than_one_vowel_ignoring_last_e()) printf("\nLOG: There is more than one vowel ignoring any possible last e");
			else if (is_there_more_than_one_vowel ()) printf("\nLOG: There is more than one vowel");
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

			//ia\0 || io\0 || iu\0
			else if ((argument[arg_counter] == 'i') && (argument[arg_counter + 1] == 'a' || argument[arg_counter + 1] == 'o' || argument[arg_counter + 1] == 'u') && (argument[arg_counter + 2] == '\0' || argument[arg_counter + 2] == 's' || !(argument[arg_counter + 2] == 'e')))
			{
				SPT_word[SPT_counter] = 'y';
				SPT_counter++;
			}
			//\0ie(s)\0
			else if ((argument[arg_counter] == 'i' && argument[arg_counter + 1] == 'e' && argument[arg_counter - 1] == '\0') && (argument[arg_counter + 2] == '\0' || (argument[arg_counter + 2] == 's' && argument[arg_counter + 3] == '\0')))
			{
				SPT_word[SPT_counter] = 'y';
				SPT_counter++;
			}
			//ia
			else if ((argument[arg_counter] == 'i') && (argument[arg_counter + 1] == 'a'))
			{
				SPT_word[SPT_counter] = 'y';
				SPT_counter++;
			}
			//ei || oi
			else if ((argument[arg_counter] == 'i') && (argument[arg_counter - 1] == 'e' || argument[arg_counter - 1] == 'o'))
			{
				SPT_word[SPT_counter] = 'y';
				SPT_counter++;
			}
			//ua || ui || uo
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
					//aiCV
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 2])) && (is_it_vowel(argument[arg_counter + 3])) && (argument[arg_counter + 4] == '\0'))
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
					//aiCCV
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 2])) && (is_it_consonant(argument[arg_counter + 3])) && (is_it_vowel(argument[arg_counter + 4])) && (argument[arg_counter + 5] == '\0'))
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
					//aiCVs
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 2])) && (is_it_vowel(argument[arg_counter + 3])) && (argument[arg_counter + 4] == 's') && (argument[arg_counter + 5] == '\0'))
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
					//aiCCVs
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 2])) && (is_it_consonant(argument[arg_counter + 3])) && (is_it_vowel(argument[arg_counter + 4])) && (argument[arg_counter + 5] == 's') && (argument[arg_counter + 6] == '\0'))
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
					//aiCyV
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
						//aiCyVs
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
					// ahC || ah\0
					if (!(stress) && (is_there_more_than_one_vowel ()) && (argument[arg_counter + 1] == 'h') && (is_it_consonant (argument[arg_counter + 2]) || argument[arg_counter + 2] == '\0'))
					{
						if (show_system_messages) printf("\npoint ah(C)0");
						SPT_word[SPT_counter] = 'A';
						stress = TRUE;
					}
					// aC=C\0 || ack\0
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (((is_it_consonant (argument[arg_counter + 1])) && (argument[arg_counter + 1] == argument[arg_counter + 2])) || ((argument[arg_counter + 1] == 'c') && (argument[arg_counter + 2] == 'k'))) && (argument[arg_counter + 3] == '\0'))
					{
						if (show_system_messages) printf("\npoint ac=c0 || ack0");
						SPT_word[SPT_counter] = 'A';
						stress = TRUE;
					}
					// aC0 || ay0
					else if (!(stress) && (is_there_more_than_one_vowel ()) && ((is_it_consonant(argument[arg_counter + 1])) || (argument[arg_counter + 1] == 'y')) && !(argument[arg_counter + 1] == 's') && (argument[arg_counter + 2] == '\0'))
					{
						if (show_system_messages) printf("\npoint aC0 || ay0");
						SPT_word[SPT_counter] = 'A';
						stress = TRUE;
					}
					// ae
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (argument[arg_counter + 1] == 'e'))
					{
						// ae\0
						if ((is_it_vowel(argument[arg_counter - 1]) || is_it_vowel(argument[arg_counter - 2]) || is_it_vowel(argument[arg_counter - 3])) && argument[arg_counter + 2] == '\0')
						{
							if (show_system_messages) printf("\npoint Ae0");
							SPT_word[SPT_counter] = 'A';
							stress = TRUE;
						}
						// aes\0
						else if ((is_it_vowel(argument[arg_counter - 1]) || is_it_vowel(argument[arg_counter - 2]) || is_it_vowel(argument[arg_counter - 3])) && argument[arg_counter + 2] == 's' && argument[arg_counter + 3] == '\0')
						{
							if (show_system_messages) printf("\npoint Aes0");
							SPT_word[SPT_counter] = 'A';
							stress = TRUE;
						}
						else
							SPT_word[SPT_counter] = 'a';
					}
					//aCV\0
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (is_it_vowel(argument[arg_counter + 2])) && (argument[arg_counter + 3] == '\0'))
					{
						if (show_system_messages) printf("\npoint aCV0");
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
					//aCCV\0
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (is_it_consonant(argument[arg_counter + 2])) && (is_it_vowel(argument[arg_counter + 3])) && (argument[arg_counter + 4] == '\0'))
					{
						if (show_system_messages) printf("\npoint aCCV0");
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
					//aCeC\0
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (argument[arg_counter + 2] == 'e') && (is_it_consonant(argument[arg_counter + 3])) && (argument[arg_counter + 4] == '\0'))
					{
						if (show_system_messages) printf("\npoint aCeC");
						SPT_word[SPT_counter] = 'A';
						stress = TRUE;
					}
					//aCCeC\0
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (is_it_consonant(argument[arg_counter + 2])) && (argument[arg_counter + 3] == 'e') && (is_it_consonant(argument[arg_counter + 4])) && (argument[arg_counter + 5] == '\0'))
					{
						if (show_system_messages) printf("\npoint aCCeC");
						SPT_word[SPT_counter] = 'A';
						stress = TRUE;
					}
					//aCCCeC\0
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (is_it_consonant(argument[arg_counter + 2])) && (is_it_consonant(argument[arg_counter + 3])) && (argument[arg_counter + 4] == 'e') && (is_it_consonant(argument[arg_counter + 5])) && (argument[arg_counter + 6] == '\0'))
					{
						if (show_system_messages) printf("\npoint aCCCeC");
						SPT_word[SPT_counter] = 'A';
						stress = TRUE;
					}
					//aCeCs\0
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (argument[arg_counter + 2] == 'e') && (is_it_consonant(argument[arg_counter + 3]))  && (argument[arg_counter + 4] == 's') && (argument[arg_counter + 5] == '\0'))
					{
						if (show_system_messages) printf("\npoint aCeCs");
						if (argument[arg_counter + 3] == 's')
						{
							SPT_word[SPT_counter] = 'a';
						}
						else
						{
							SPT_word[SPT_counter] = 'A';
							stress = TRUE;
						}
					}
					//aCCeCs\0
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (is_it_consonant(argument[arg_counter + 2])) && (argument[arg_counter + 3] == 'e') && (is_it_consonant(argument[arg_counter + 4]))  && (argument[arg_counter + 5] == 's') && (argument[arg_counter + 6] == '\0'))
					{
						if (show_system_messages) printf("\npoint aCCeCs");
						if (argument[arg_counter + 4] == 's')
						{
							SPT_word[SPT_counter] = 'a';
						}
						else
						{
							SPT_word[SPT_counter] = 'A';
							stress = TRUE;
						}
					}
					//aCCCeCs\0
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (is_it_consonant(argument[arg_counter + 2])) && (is_it_consonant(argument[arg_counter + 3])) && (argument[arg_counter + 4] == 'e') && (is_it_consonant(argument[arg_counter + 5])) && (argument[arg_counter + 6] == 's') && (argument[arg_counter + 7] == '\0'))
					{
						if (show_system_messages) printf("\npoint aCCCeCs");
						if (argument[arg_counter + 5] == 's')
						{
							SPT_word[SPT_counter] = 'a';
						}
						else
						{
							SPT_word[SPT_counter] = 'A';
							stress = TRUE;
						}
					}
					//ast\0
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (argument[arg_counter + 1] == 's') && (argument[arg_counter + 2] == 't') && (argument[arg_counter + 3] == '\0'))
					{
						if (show_system_messages) printf("\npoint ast0");

						SPT_word[SPT_counter] = 'A';
						stress = TRUE;
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
					// euCC\0 ex: cancersieugs
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 2])) && (is_it_consonant(argument[arg_counter + 3])) && (argument[arg_counter + 4] == '\0'))
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
					if (!is_there_more_than_one_vowel())
					{
						if (show_system_messages) printf("\npoint final_e_fully_pronounceable");
						SPT_word[SPT_counter] = 'e';
						SPT_counter++;
					}
					else if (argument[strlen(argument) - 2] == 'y' && is_it_consonant(argument[strlen(argument) - 3]))
					{
						if (show_system_messages) printf("\npoint -Cye");
						SPT_word[SPT_counter] = '(';
						SPT_counter++;
						#ifdef _WIN32
						SPT_word[SPT_counter] = SMALL_E_DIAERESIS;
						SPT_counter++;
						#else
						strncat(SPT_word, SMALL_E_DIAERESIS, 6);
						SPT_counter = SPT_counter + 2;
						#endif
						occurrence_of_the_small_e_diaeresis++;
						SPT_word[SPT_counter] = ')';
						SPT_counter++;
					}
					else if (argument[strlen(argument) - 2] == 'w' && is_it_consonant(argument[strlen(argument) - 3]))
					{
						if (show_system_messages) printf("\npoint -Cwe");
						SPT_word[SPT_counter] = '(';
						SPT_counter++;
						#ifdef _WIN32
						SPT_word[SPT_counter] = SMALL_E_DIAERESIS;
						SPT_counter++;
						#else
						strncat(SPT_word, SMALL_E_DIAERESIS, 6);
						SPT_counter = SPT_counter + 2;
						#endif
						occurrence_of_the_small_e_diaeresis++;
						SPT_word[SPT_counter] = ')';
						SPT_counter++;
					}
					else
						SPT_counter++; // The letter "e" at the end of a verb is not pronounced
				}

				/*******************/

				else
				{
					if (show_system_messages) printf("\npoint else_to_many_decisions_of_e");

					//ehC\0 || eh\0
					if (!(stress) && (is_there_more_than_one_vowel ()) && (argument[arg_counter + 1] == 'h') && (is_it_consonant (argument[arg_counter + 2]) || argument[arg_counter + 2] == '\0'))
					{
						if (is_it_vowel(argument[arg_counter + 2]) || is_it_vowel(argument[arg_counter + 3]) || is_it_vowel(argument[arg_counter + 4]) || is_it_vowel(argument[arg_counter + 5]))
						{
							if (show_system_messages) printf("\npoint eh");
							SPT_word[SPT_counter] = 'e';
							SPT_counter++;
						}
						else
						{
							if (show_system_messages) printf("\npoint Eh");
							SPT_word[SPT_counter] = 'E';
							SPT_counter++;
							stress = TRUE;
						}
					}
					//eC=C\0 || eck\0
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (((is_it_consonant (argument[arg_counter + 1])) && (argument[arg_counter + 1] == argument[arg_counter + 2])) || ((argument[arg_counter + 1] == 'c') && (argument[arg_counter + 2] == 'k'))) && (argument[arg_counter + 3] == '\0'))
					{
						if (show_system_messages) printf("\npoint ECC0");
						SPT_word[SPT_counter] = 'E';
						SPT_counter++;
						stress = TRUE;
					}
					//exter-
					else if ((argument[arg_counter - 3] == 'e' && argument[arg_counter - 2] == 'x' && argument[arg_counter - 1] == 't' && argument[arg_counter + 1] == 'r') && (is_it_vowel(argument[arg_counter + 2]) || is_it_vowel(argument[arg_counter + 3]) || is_it_vowel(argument[arg_counter + 4])))
					{
						if (show_system_messages) printf("\npoint exter-");
						#ifdef _WIN32
						SPT_word[SPT_counter] = SMALL_E_DIAERESIS;
						SPT_counter++;
						#else
						strncat(SPT_word, SMALL_E_DIAERESIS, 6);
						SPT_counter = SPT_counter + 2;
						#endif
						occurrence_of_the_small_e_diaeresis++;
					}
					//ender-
					else if ((argument[arg_counter - 3] == 'e' && argument[arg_counter - 2] == 'n' && argument[arg_counter - 1] == 'd' && argument[arg_counter + 1] == 'r') && (is_it_vowel(argument[arg_counter + 2]) || is_it_vowel(argument[arg_counter + 3]) || is_it_vowel(argument[arg_counter + 4])))
					{
						if (show_system_messages) printf("\npoint ender-");
						#ifdef _WIN32
						SPT_word[SPT_counter] = SMALL_E_DIAERESIS;
						SPT_counter++;
						#else
						strncat(SPT_word, SMALL_E_DIAERESIS, 6);
						SPT_counter = SPT_counter + 2;
						#endif
						occurrence_of_the_small_e_diaeresis++;
					}
					//epter-
					else if ((argument[arg_counter - 3] == 'e' && argument[arg_counter - 2] == 'p' && argument[arg_counter - 1] == 't' && argument[arg_counter + 1] == 'r') && (is_it_vowel(argument[arg_counter + 2]) || is_it_vowel(argument[arg_counter + 3]) || is_it_vowel(argument[arg_counter + 4])))
					{
						if (show_system_messages) printf("\npoint epter-");
						#ifdef _WIN32
						SPT_word[SPT_counter] = SMALL_E_DIAERESIS;
						SPT_counter++;
						#else
						strncat(SPT_word, SMALL_E_DIAERESIS, 6);
						SPT_counter = SPT_counter + 2;
						#endif
						occurrence_of_the_small_e_diaeresis++;
					}
					//niter-
					else if ((argument[arg_counter - 3] == 'n' && argument[arg_counter - 2] == 'i' && argument[arg_counter - 1] == 't' && argument[arg_counter + 1] == 'r') && (is_it_vowel(argument[arg_counter + 2]) || is_it_vowel(argument[arg_counter + 3]) || is_it_vowel(argument[arg_counter + 4])))
					{
						if (show_system_messages) printf("\npoint exter-");
						#ifdef _WIN32
						SPT_word[SPT_counter] = SMALL_E_DIAERESIS;
						SPT_counter++;
						#else
						strncat(SPT_word, SMALL_E_DIAERESIS, 6);
						SPT_counter = SPT_counter + 2;
						#endif
						occurrence_of_the_small_e_diaeresis++;
					}
					//peri-
					else if ((argument[arg_counter - 1] == 'p' && argument[arg_counter + 1] == 'r' && argument[arg_counter + 2] == 'i') && (is_it_vowel(argument[arg_counter + 3]) || is_it_vowel(argument[arg_counter + 4]) || is_it_vowel(argument[arg_counter + 5])))
					{
						if (show_system_messages) printf("\npoint peri-");
						#ifdef _WIN32
						SPT_word[SPT_counter] = SMALL_E_DIAERESIS;
						SPT_counter++;
						#else
						strncat(SPT_word, SMALL_E_DIAERESIS, 6);
						SPT_counter = SPT_counter + 2;
						#endif
						occurrence_of_the_small_e_diaeresis++;
					}
					//eCV\0
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (is_it_vowel(argument[arg_counter + 2])) && (argument[arg_counter + 3] == '\0'))
					{
						if (show_system_messages) printf("\npoint ECV0");
						if ((argument[arg_counter + 2] == 'e') && ((is_it_vowel(argument[arg_counter - 2])) || (is_it_vowel(argument[arg_counter - 3]))) && !(argument[arg_counter + 2] == 'e'))
						{
							SPT_word[SPT_counter] = 'E';
							SPT_counter++;
							stress = TRUE;
						}
						else if (argument[arg_counter + 2] == 'e' && (is_it_vowel(argument[arg_counter - 1]) || is_it_vowel(argument[arg_counter - 2]) || is_it_vowel(argument[arg_counter - 3]) || is_it_vowel(argument[arg_counter - 4])))
						{
							SPT_word[SPT_counter] = 'E';
							SPT_counter++;
							stress = TRUE;
						}
						else if (!(argument[arg_counter + 2] == 'e') && !(argument[arg_counter + 2] == 'w'))
						{
							SPT_word[SPT_counter] = 'E';
							SPT_counter++;
							stress = TRUE;
						}
						else
							goto PROBLEMATIC_E;
					}
					//eCCV
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (is_it_consonant(argument[arg_counter + 2])) && (is_it_vowel(argument[arg_counter + 3])) && (argument[arg_counter + 4] == '\0'))
					{
						if (show_system_messages) printf("\npoint ECCV");
						if ((argument[arg_counter + 3] == 'e') && ((is_it_vowel(argument[arg_counter - 2])) || (is_it_vowel(argument[arg_counter - 3]))))
						{
							SPT_word[SPT_counter] = 'E';
							SPT_counter++;
							stress = TRUE;
						}
						else if (argument[arg_counter + 3] == 'e' && (is_it_vowel(argument[arg_counter - 1]) || is_it_vowel(argument[arg_counter - 2]) || is_it_vowel(argument[arg_counter - 3]) || is_it_vowel(argument[arg_counter - 4])))
						{
							SPT_word[SPT_counter] = 'E';
							SPT_counter++;
							stress = TRUE;
						}
						else if (!(argument[arg_counter + 3] == 'e') && !(argument[arg_counter + 3] == 'w'))
						{
							SPT_word[SPT_counter] = 'E';
							SPT_counter++;
							stress = TRUE;
						}
						else
							goto PROBLEMATIC_E;
					}
					//eCVs
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (is_it_vowel(argument[arg_counter + 2])) && (argument[arg_counter + 3] == 's') && (argument[arg_counter + 4] == '\0'))
					{
						if (show_system_messages) printf("\npoint eCVs");
						if ((argument[arg_counter + 2] == 'e') && ((is_it_vowel(argument[arg_counter - 2])) || (is_it_vowel(argument[arg_counter - 3]))))
						{
							SPT_word[SPT_counter] = 'E';
							SPT_counter++;
							stress = TRUE;
						}
						else if (argument[arg_counter + 2] == 'e' && (is_it_vowel(argument[arg_counter - 1]) || is_it_vowel(argument[arg_counter - 2]) || is_it_vowel(argument[arg_counter - 3]) || is_it_vowel(argument[arg_counter - 4])))
						{
							SPT_word[SPT_counter] = 'E';
							SPT_counter++;
							stress = TRUE;
						}
						else if (!(argument[arg_counter + 2] == 'e') && !(argument[arg_counter + 2] == 'w'))
						{
							SPT_word[SPT_counter] = 'E';
							SPT_counter++;
							stress = TRUE;
						}
						else if (argument[arg_counter + 2] == 'w' && is_it_consonant(argument[arg_counter + 3]))
						{
							SPT_word[SPT_counter] = 'E';
							SPT_counter++;
							stress = TRUE;
						}
						else
							goto PROBLEMATIC_E;
					}
					//eCCVs
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (is_it_consonant(argument[arg_counter + 2])) && (is_it_vowel(argument[arg_counter + 3])) && (argument[arg_counter + 4] == 's') && (argument[arg_counter + 5] == '\0'))
					{
						if (show_system_messages) printf("\npoint eCCVs");
						if ((argument[arg_counter + 3] == 'e') && ((is_it_vowel(argument[arg_counter - 2])) || (is_it_vowel(argument[arg_counter - 3]))))
						{
							SPT_word[SPT_counter] = 'E';
							SPT_counter++;
							stress = TRUE;
						}
						else if (argument[arg_counter + 3] == 'e' && (is_it_vowel(argument[arg_counter - 1]) || is_it_vowel(argument[arg_counter - 2]) || is_it_vowel(argument[arg_counter - 3]) || is_it_vowel(argument[arg_counter - 4])))
						{
							SPT_word[SPT_counter] = 'E';
							SPT_counter++;
							stress = TRUE;
						}
						else if (!(argument[arg_counter + 3] == 'e') && !(argument[arg_counter + 3] == 'w'))
						{
							SPT_word[SPT_counter] = 'E';
							SPT_counter++;
							stress = TRUE;
						}
						else
							goto PROBLEMATIC_E;
					}
					//eCwC\0
					else if (!(stress) && is_there_more_than_one_vowel () && is_it_consonant(argument[arg_counter + 1]) && argument[arg_counter + 2] == 'w' && is_it_consonant(argument[arg_counter + 3]) && argument[arg_counter + 4] == '\0')
					{
						if (show_system_messages) printf("\npoint eCwC0");
						SPT_word[SPT_counter] = 'E';
						SPT_counter++;
						stress = TRUE;
					}
					//eCwCC\0
					else if (!(stress) && is_there_more_than_one_vowel () && is_it_consonant(argument[arg_counter + 1]) && argument[arg_counter + 2] == 'w' && is_it_consonant(argument[arg_counter + 3]) && is_it_consonant(argument[arg_counter + 4]) && argument[arg_counter + 5] == '\0')
					{
						if (show_system_messages) printf("\npoint eCwCC0");
						SPT_word[SPT_counter] = 'E';
						SPT_counter++;
						stress = TRUE;
					}
					//eCwCVC\0
					else if (!(stress) && is_there_more_than_one_vowel () && is_it_consonant(argument[arg_counter + 1]) && argument[arg_counter + 2] == 'w' && is_it_consonant(argument[arg_counter + 3]) && is_it_vowel(argument[arg_counter + 4]) && is_it_consonant(argument[arg_counter + 5]) && argument[arg_counter + 6] == '\0')
					{
						if (show_system_messages) printf("\npoint eCwCVC0");
						SPT_word[SPT_counter] = 'E';
						SPT_counter++;
						stress = TRUE;
					}
					//eCwCV\0
					else if (!(stress) && is_there_more_than_one_vowel () && is_it_consonant(argument[arg_counter + 1]) && argument[arg_counter + 2] == 'w' && is_it_consonant(argument[arg_counter + 3]) && is_it_vowel(argument[arg_counter + 4]) && argument[arg_counter + 5] == '\0')
					{
						if (show_system_messages) printf("\npoint eCwCV0");
						SPT_word[SPT_counter] = 'E';
						SPT_counter++;
						stress = TRUE;
					}
					//eCwCCV\0
					else if (!(stress) && is_there_more_than_one_vowel () && is_it_consonant(argument[arg_counter + 1]) && argument[arg_counter + 2] == 'w' && is_it_consonant(argument[arg_counter + 3]) && is_it_consonant(argument[arg_counter + 4]) && is_it_vowel(argument[arg_counter + 5]) && argument[arg_counter + 6] == '\0')
					{
						if (show_system_messages) printf("\npoint eCwCCV0");
						SPT_word[SPT_counter] = 'E';
						SPT_counter++;
						stress = TRUE;
					}
					//eCyV
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (argument[arg_counter + 2] == 'y' || argument[arg_counter + 2] == 'i') && (is_it_vowel(argument[arg_counter + 3])) && (argument[arg_counter + 4] == '\0') && !(argument[arg_counter + 2] == 'i' && argument[arg_counter + 3] == 'e'))
					{
						if (show_system_messages) printf("\npoint eCyV");
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
					//eCyVs
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (argument[arg_counter + 2] == 'y' || argument[arg_counter + 2] == 'i') && (is_it_vowel(argument[arg_counter + 3])) && (argument[arg_counter + 4] == 's') && (argument[arg_counter + 5] == '\0') && !(argument[arg_counter + 2] == 'i' && argument[arg_counter + 3] == 'e'))
					{
						if (show_system_messages) printf("\npoint eCyVs");
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
					//eCeC\0
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (argument[arg_counter + 2] == 'e') && (is_it_consonant(argument[arg_counter + 3])) && (argument[arg_counter + 4] == '\0'))
					{
						if (show_system_messages) printf("\npoint ecec0");
						SPT_word[SPT_counter] = 'E';
						SPT_counter++;
						stress = TRUE;
					}
					//eCCeC\0
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (is_it_consonant(argument[arg_counter + 2])) && (argument[arg_counter + 3] == 'e') && (is_it_consonant(argument[arg_counter + 4])) && (argument[arg_counter + 5] == '\0'))
					{
						if (show_system_messages) printf("\npoint eccec0");
						SPT_word[SPT_counter] = 'E';
						SPT_counter++;
						stress = TRUE;
					}
					//eCCCeC\0
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (is_it_consonant(argument[arg_counter + 2])) && (is_it_consonant(argument[arg_counter + 3])) && (argument[arg_counter + 4] == 'e') && (is_it_consonant(argument[arg_counter + 5])) && (argument[arg_counter + 6] == '\0'))
					{
						if (show_system_messages) printf("\npoint ecccec0");
						SPT_word[SPT_counter] = 'E';
						SPT_counter++;
						stress = TRUE;
					}
					//eCeCs\0
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (argument[arg_counter + 2] == 'e') && (is_it_consonant(argument[arg_counter + 3]))  && (argument[arg_counter + 4] == 's') && (argument[arg_counter + 5] == '\0'))
					{
						if (show_system_messages) printf("\npoint ececs0");
						SPT_word[SPT_counter] = 'E';
						SPT_counter++;
						stress = TRUE;
					}
					//eCCeCs\0
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (is_it_consonant(argument[arg_counter + 2])) && (argument[arg_counter + 3] == 'e') && (is_it_consonant(argument[arg_counter + 4]))  && (argument[arg_counter + 5] == 's') && (argument[arg_counter + 6] == '\0'))
					{
						if (show_system_messages) printf("\npoint eccecs0");
						SPT_word[SPT_counter] = 'E';
						SPT_counter++;
						stress = TRUE;
					}
					//eCCCeCs\0
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (is_it_consonant(argument[arg_counter + 2])) && (is_it_consonant(argument[arg_counter + 3])) && (argument[arg_counter + 4] == 'e') && (is_it_consonant(argument[arg_counter + 5])) && (argument[arg_counter + 6] == 's') && (argument[arg_counter + 7] == '\0'))
					{
						if (show_system_messages) printf("\npoint ecccecs0");
						SPT_word[SPT_counter] = 'E';
						SPT_counter++;
						stress = TRUE;
					}
					else // No sctress accent
					{

					// I hat to do this, but this "e" is very problematic. I evoke the power of GOTO!
					PROBLEMATIC_E:

						if (show_system_messages) printf("\npoint problematic_e");

						// "e" is the first letter of the word
						if (!(is_it_consonant (argument[arg_counter - 1])) && !(is_it_vowel (argument[arg_counter - 1])))
						{
							if (show_system_messages) printf("\npoint e_first_letter");
							SPT_word[SPT_counter] = 'e';
							SPT_counter++;
						}
						// eC=C || eck
						else if (((is_it_consonant (argument[arg_counter + 1])) && (argument[arg_counter + 1] == argument[arg_counter + 2])) || ((argument[arg_counter + 1] == 'c') && (argument[arg_counter + 2] == 'k')))
						{
							if (show_system_messages) printf("\npoint ec=c || eck");

							if (argument[arg_counter + 1] == 's' && argument[arg_counter + 3] == '\0')
							{
								if (show_system_messages) printf("\npoint ec=c || eck => ess");
								#ifdef _WIN32
								SPT_word[SPT_counter] = SMALL_E_DIAERESIS;
								SPT_counter++;
								#else
								strncat(SPT_word, SMALL_E_DIAERESIS, 6);
								SPT_counter = SPT_counter + 2;
								#endif
								occurrence_of_the_small_e_diaeresis++;
							}
							else
							{
								SPT_word[SPT_counter] = 'e';
								SPT_counter++;
							}
						}
						// eCC\0
						else if ((is_it_consonant (argument[arg_counter + 1]) && is_it_consonant (argument[arg_counter + 2]) && argument[arg_counter + 3] == '\0') && !(!(stress) && (is_there_more_than_one_vowel ()) && (((is_it_consonant (argument[arg_counter + 1])) && (argument[arg_counter + 1] == argument[arg_counter + 2])) || ((argument[arg_counter + 1] == 'c') && (argument[arg_counter + 2] == 'k'))) && (argument[arg_counter + 3] == '\0')))
						{
							if (show_system_messages) printf("\npoint -ecc");
							if (is_there_more_than_one_vowel())
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
							else
							{
								SPT_word[SPT_counter] = 'e';
								SPT_counter++;
							}
						}
						// eV\0 || eVs\0
						else if ((is_it_vowel(argument[arg_counter + 1]) && argument[arg_counter + 2] == '\0') || (is_it_vowel(argument[arg_counter + 1]) && argument[arg_counter + 2] == 's' && argument[arg_counter + 3] == '\0'))
						{
							if (show_system_messages) printf("\npoint evs");
							SPT_word[SPT_counter] = 'e';
							SPT_counter++;
						}
						// there is no more other vowel
						else if (!is_there_more_than_one_vowel ())
						{
							if (show_system_messages) printf("\npoint e_there_more_than_one_vowel");
							SPT_word[SPT_counter] = 'e';
							SPT_counter++;
						}
						// -Cer\0
						else if (is_there_more_than_one_vowel () && is_it_consonant(SPT_word[SPT_counter - 1]) && argument[arg_counter + 1] == 'r' && argument[arg_counter + 2] == '\0')
						{
							if (show_system_messages) printf("\npoint -cer0");
							#ifdef _WIN32
							SPT_word[SPT_counter] = SMALL_E_DIAERESIS;
							SPT_counter++;
							#else
							strncat(SPT_word, SMALL_E_DIAERESIS, 6);
							SPT_counter = SPT_counter + 2;
							#endif
							occurrence_of_the_small_e_diaeresis++;
						}
						// there is a semivowel
						else if ((argument[arg_counter - 1] == 'y') || (argument[arg_counter + 1] == 'y') || (argument[arg_counter - 1] == 'i') || (argument[arg_counter + 1] == 'i') || (argument[arg_counter - 1] == 'w') || (argument[arg_counter + 1] == 'w'))
						{
							// ien\0 || yen\0 || wen\0
							if (argument[arg_counter + 1] == 'n' && argument[arg_counter + 2] == '\0')
							{
								if (show_system_messages) printf("\npoint wyen");
								#ifdef _WIN32
								SPT_word[SPT_counter] = SMALL_E_DIAERESIS;
								SPT_counter++;
								#else
								strncat(SPT_word, SMALL_E_DIAERESIS, 6);
								SPT_counter = SPT_counter + 2;
								#endif
								occurrence_of_the_small_e_diaeresis++;
							}
							// ies\0 || yes\0 || wes\0
							else if (argument[arg_counter + 1] == 's' && argument[arg_counter + 2] == '\0')
							{
								if (show_system_messages) printf("\npoint wyes");
								#ifdef _WIN32
								SPT_word[SPT_counter] = SMALL_E_DIAERESIS;
								SPT_counter++;
								#else
								strncat(SPT_word, SMALL_E_DIAERESIS, 6);
								SPT_counter = SPT_counter + 2;
								#endif
								occurrence_of_the_small_e_diaeresis++;
							}
							else
							{
								if (show_system_messages) printf("\nsemivowel_with_e");
								SPT_word[SPT_counter] = 'e';
								SPT_counter++;
							}
						}
						// eCe\0
						else if ((is_it_consonant(argument[arg_counter + 1])) && (argument[arg_counter + 2] == 'e') && (argument[arg_counter + 3] == '\0'))
						{
							if (show_system_messages) printf("\npoint ece");
							SPT_word[SPT_counter] = 'e';
							SPT_counter++;
						}
						// eCer\0 ex: member
						else if ((is_it_consonant(argument[arg_counter + 1])) && (argument[arg_counter + 2] == 'e') && (argument[arg_counter + 3] == 'r') && (argument[arg_counter + 4] == '\0'))
						{
							if (show_system_messages) printf("\npoint ecer");
							SPT_word[SPT_counter] = 'e';
							SPT_counter++;
						}
						// eCCer\0 ex: november
						else if ((is_it_consonant(argument[arg_counter + 1])) && (is_it_consonant(argument[arg_counter + 2])) && (argument[arg_counter + 3] == 'e') && (argument[arg_counter + 4] == 'r') && (argument[arg_counter + 5] == '\0'))
						{
							if (show_system_messages) printf("\npoint eccer");
							SPT_word[SPT_counter] = 'e';
							SPT_counter++;
						}
						// eCCCer\0 ex: novembrer
						else if ((is_it_consonant(argument[arg_counter + 1])) && (is_it_consonant(argument[arg_counter + 2])) && (is_it_consonant(argument[arg_counter + 3])) && (argument[arg_counter + 4] == 'e') && (argument[arg_counter + 5] == 'r') && (argument[arg_counter + 6] == '\0'))
						{
							if (show_system_messages) printf("\npoint ecccer");
							SPT_word[SPT_counter] = 'e';
							SPT_counter++;
						}
						// ing\0 For preventing "e" becoming {ë}, it's for words like "reling"
						else if (argument[(strlen(argument) - 1)] == 'g' && argument[(strlen(argument) - 2)] == 'n' && argument[(strlen(argument) - 3)] == 'i')
						{
							if (show_system_messages) printf("\npoint e_ing");
							SPT_word[SPT_counter] = 'e';
							SPT_counter++;
						}
						// There is more an non-final "e" ahead
						else if ((argument[arg_counter + 1] == 'e' && !(argument[arg_counter + 2] == '\0')) || (argument[arg_counter + 2] == 'e' && !(argument[arg_counter + 3] == '\0')) || (argument[arg_counter + 3] == 'e' && !(argument[arg_counter + 4] == '\0')) || (argument[arg_counter + 4] == 'e' && !(argument[arg_counter + 5] == '\0')))
						{
							if (show_system_messages) printf("\npoint there_is_more_an_non_final_e");
							SPT_word[SPT_counter] = 'e';
							SPT_counter++;
						}
						// eCyV\0 || eCwV\0
						else if ((is_it_consonant(argument[arg_counter + 1])) && (argument[arg_counter + 2] == 'y' || argument[arg_counter + 2] == 'w') && is_it_vowel(argument[arg_counter + 3]) && argument[arg_counter + 4] == '\0')
						{
							if (show_system_messages) printf("\npoint ecyv || ecwv");
							SPT_word[SPT_counter] = 'e';
							SPT_counter++;
						}
						// eCCyV\0 || eCCwV\0
						else if ((is_it_consonant(argument[arg_counter + 1]) && is_it_consonant(argument[arg_counter + 2])) && (argument[arg_counter + 3] == 'y' || argument[arg_counter + 3] == 'w') && is_it_vowel(argument[arg_counter + 4]) && argument[arg_counter + 5] == '\0')
						{
							if (show_system_messages) printf("\npoint eccyv || eccwv");
							SPT_word[SPT_counter] = 'e';
							SPT_counter++;
						}
						// visible CeC\0
						else if ((is_it_consonant(argument[arg_counter - 1])) && (is_it_consonant(argument[arg_counter + 1])) && (argument[arg_counter + 2] == '\0') && (is_it_vowel(argument[arg_counter -2]) || is_it_vowel(argument[arg_counter -3]) || is_it_vowel(argument[arg_counter -4])))
						{
							if (show_system_messages) printf("\npoint -cec0");

							if (argument[arg_counter + 1] == 's' && (argument[arg_counter - 1] == 'c' || argument[arg_counter - 1] == 's' || argument[arg_counter - 1] == 'z' || argument[arg_counter - 1] == 'g' || argument[arg_counter - 1] == 'j' || argument[arg_counter - 1] == 'x' || argument[arg_counter - 1] == 'w' || argument[arg_counter - 1] == 'y' || (argument[arg_counter - 3] == 's' && argument[arg_counter - 2] == 'c' && argument[arg_counter - 1] == 'h') || (argument[arg_counter - 2] == 't' && argument[arg_counter - 1] == 'h') || (argument[arg_counter - 2] == 'q' && argument[arg_counter - 1] == 'u')))
							{
								if (show_system_messages) printf("\npoint visible_Ces");
								#ifdef _WIN32
								SPT_word[SPT_counter] = SMALL_E_DIAERESIS;
								SPT_counter++;
								#else
								strncat(SPT_word, SMALL_E_DIAERESIS, 6);
								SPT_counter = SPT_counter + 2;
								#endif
								occurrence_of_the_small_e_diaeresis++;
							}
							else if (argument[arg_counter + 1] == 't' && (argument[arg_counter - 1] == 'c' || argument[arg_counter - 1] == 'z' || argument[arg_counter - 1] == 'g' || argument[arg_counter - 1] == 'd' || argument[arg_counter - 1] == 't' || argument[arg_counter - 1] == 'w' || argument[arg_counter - 1] == 'y' || (argument[arg_counter - 2] == 'q' && argument[arg_counter - 1] == 'u')))
							{
								if (show_system_messages) printf("\npoint visible_Cet");
								#ifdef _WIN32
								SPT_word[SPT_counter] = SMALL_E_DIAERESIS;
								SPT_counter++;
								#else
								strncat(SPT_word, SMALL_E_DIAERESIS, 6);
								SPT_counter = SPT_counter + 2;
								#endif
								occurrence_of_the_small_e_diaeresis++;
							}
							else if (argument[arg_counter + 1] == 's' || argument[arg_counter + 1] == 't')
							{
								if (show_system_messages) printf("\npoint INvisible_CeC");
								// Do nothing
							}
							else
							{
								if (show_system_messages) printf("\npoint visible_CeC");
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
						// Cess\0
						else if ((is_it_consonant(argument[arg_counter - 1])) && (argument[arg_counter + 1] == 's') && (argument[arg_counter + 2] == 's') && (argument[arg_counter + 3] == '\0') && (is_it_vowel(argument[arg_counter -2]) || is_it_vowel(argument[arg_counter -3]) || is_it_vowel(argument[arg_counter -4])))
						{
							if (show_system_messages) printf("\npoint Cess");
							if (argument[arg_counter - 1] == 's' || argument[arg_counter - 1] == 'c') // Thus ses\0
							{
								if (show_system_messages) printf("\npoint scess");
								#ifdef _WIN32
								SPT_word[SPT_counter] = SMALL_E_DIAERESIS;
								SPT_counter++;
								#else
								strncat(SPT_word, SMALL_E_DIAERESIS, 6);
								SPT_counter = SPT_counter + 2;
								#endif
								occurrence_of_the_small_e_diaeresis++;
							}
							else
							{
								// Do nothing
							}
						}
						// eCVCC\0 ex: ametyst
						else if (is_it_consonant(argument[arg_counter + 1]) && is_it_vowel(argument[arg_counter + 2]) && is_it_consonant(argument[arg_counter + 3]) && is_it_consonant(argument[arg_counter + 4]) && argument[arg_counter + 5] == '\0')
						{
							if (show_system_messages) printf("\npoint eCVCC0");
							SPT_word[SPT_counter] = 'e';
							SPT_counter++;
						}
						// eCVCCs\0
						else if (is_it_consonant(argument[arg_counter + 1]) && is_it_vowel(argument[arg_counter + 2]) && is_it_consonant(argument[arg_counter + 3]) && is_it_consonant(argument[arg_counter + 4]) && argument[arg_counter + 5] == 's' && argument[arg_counter + 6] == '\0')
						{
							if (show_system_messages) printf("\npoint eCVCCs0");
							SPT_word[SPT_counter] = 'e';
							SPT_counter++;
						}
						// eCCVCC\0 ex: ametyst
						else if (is_it_consonant(argument[arg_counter + 1]) && is_it_consonant(argument[arg_counter + 2]) && is_it_vowel(argument[arg_counter + 3]) && is_it_consonant(argument[arg_counter + 4]) && is_it_consonant(argument[arg_counter + 5]) && argument[arg_counter + 6] == '\0')
						{
							if (show_system_messages) printf("\npoint eCCVCC0");
							SPT_word[SPT_counter] = 'e';
							SPT_counter++;
						}
						// eCCVCCs\0
						else if (is_it_consonant(argument[arg_counter + 1]) && is_it_consonant(argument[arg_counter + 2]) && is_it_vowel(argument[arg_counter + 3]) && is_it_consonant(argument[arg_counter + 4]) && is_it_consonant(argument[arg_counter + 5]) && argument[arg_counter + 6] == 's' && argument[arg_counter + 7] == '\0')
						{
							if (show_system_messages) printf("\npoint eCCVCCs0");
							SPT_word[SPT_counter] = 'e';
							SPT_counter++;
						}
						else
						{
							if (show_system_messages) printf("\npoint e_else");

							if ((argument[arg_counter + 1] == 't' || argument[arg_counter + 1] == 's') && argument[arg_counter + 2] == '\0')
							{
								// Do nothing, this is a silent e
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
					//iCV
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
					//iCCV
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
					//iCeC\0
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (argument[arg_counter + 2] == 'e') && (is_it_consonant(argument[arg_counter + 3])) && (argument[arg_counter + 4] == '\0'))
					{
						SPT_word[SPT_counter] = 'I';
						stress = TRUE;
					}
					//iCCeC\0
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (is_it_consonant(argument[arg_counter + 2])) && (argument[arg_counter + 3] == 'e') && (is_it_consonant(argument[arg_counter + 4])) && (argument[arg_counter + 5] == '\0'))
					{
						SPT_word[SPT_counter] = 'I';
						stress = TRUE;
					}
					//aiCCCeC\0
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (is_it_consonant(argument[arg_counter + 2])) && (is_it_consonant(argument[arg_counter + 3])) && (argument[arg_counter + 4] == 'e') && (is_it_consonant(argument[arg_counter + 5])) && (argument[arg_counter + 6] == '\0'))
					{
						SPT_word[SPT_counter] = 'I';
						stress = TRUE;
					}
					//iCeCs\0
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (argument[arg_counter + 2] == 'e') && (is_it_consonant(argument[arg_counter + 3]))  && (argument[arg_counter + 4] == 's') && (argument[arg_counter + 5] == '\0'))
					{
						SPT_word[SPT_counter] = 'I';
						stress = TRUE;
					}
					//iCCeCs\0
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (is_it_consonant(argument[arg_counter + 2])) && (argument[arg_counter + 3] == 'e') && (is_it_consonant(argument[arg_counter + 4]))  && (argument[arg_counter + 5] == 's') && (argument[arg_counter + 6] == '\0'))
					{
						SPT_word[SPT_counter] = 'I';
						stress = TRUE;
					}
					//iCCCeCs\0
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (is_it_consonant(argument[arg_counter + 2])) && (is_it_consonant(argument[arg_counter + 3])) && (argument[arg_counter + 4] == 'e') && (is_it_consonant(argument[arg_counter + 5])) && (argument[arg_counter + 6] == 's') && (argument[arg_counter + 7] == '\0'))
					{
						SPT_word[SPT_counter] = 'I';
						stress = TRUE;
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
					//oCV
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
					//oCCV
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
					//ost\0
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (argument[arg_counter + 1] == 's') && (argument[arg_counter + 2] == 't') && (argument[arg_counter + 3] == '\0'))
					{
						if (show_system_messages) printf("\npoint ost0");

						SPT_word[SPT_counter] = 'O';
						SPT_counter++;
						stress = TRUE;
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
					else if (!(is_there_more_than_one_vowel ()))
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
					else
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
				}

				/************* uCe **/

				else if ((is_it_consonant(argument[arg_counter + 1])) && (argument[arg_counter + 2] == 'e'))
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
					//uCV
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
					//uCCV
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
					//ust\0
					else if (!(stress) && (is_there_more_than_one_vowel ()) && (argument[arg_counter + 1] == 's') && (argument[arg_counter + 2] == 't') && (argument[arg_counter + 3] == '\0'))
					{
						if (show_system_messages) printf("\npoint ust0");

						SPT_word[SPT_counter] = 'U';
						SPT_counter++;
						stress = TRUE;
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
						// yCic\0
						if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (argument[arg_counter + 2] == 'i') && (argument[arg_counter + 3] == 'c') && (argument[arg_counter + 4] == '\0'))
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
						// yhV || yh10
						else if (!(stress) && (is_there_more_than_one_vowel ()) && (argument[arg_counter + 1] == 'h') && (is_it_consonant (argument[arg_counter + 2]) || argument[arg_counter + 2] == '\0'))
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
						// yC=C\0 || yck\0
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
						//yCV
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
						//yCCV
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
						//yCVs
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
						//yCCVs
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
						//yCyV
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
						//yCyVs
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
						// yCer\0 ex: myber
						else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (argument[arg_counter + 2] == 'e') && (argument[arg_counter + 3] == 'r') && (argument[arg_counter + 4] == '\0'))
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
						// yCCer\0 ex: mymber
						else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (is_it_consonant(argument[arg_counter + 2])) && (argument[arg_counter + 3] == 'e') && (argument[arg_counter + 4] == 'r') && (argument[arg_counter + 5] == '\0'))
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
						// yCCCer\0 ex: novymbrer
						else if (!(stress) && (is_there_more_than_one_vowel ()) && (is_it_consonant(argument[arg_counter + 1])) && (is_it_consonant(argument[arg_counter + 2])) && (is_it_consonant(argument[arg_counter + 3])) && (argument[arg_counter + 4] == 'e') && (argument[arg_counter + 5] == 'r') && (argument[arg_counter + 6] == '\0'))
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
			if ((argument[arg_counter + 1] == 'e' || argument[arg_counter + 1] == 'i' || argument[arg_counter + 1] == 'y') && argument[arg_counter - 1] != 'g')
			{
				SPT_word[SPT_counter] = 'd';
				SPT_counter++;
				SPT_word[SPT_counter] = 'j';
				SPT_counter++;
			}
			else if ((argument[arg_counter + 1] == 'e' || argument[arg_counter + 1] == 'i' || argument[arg_counter + 1] == 'y') && argument[arg_counter - 1] == 'g')
			{
				SPT_word[SPT_counter] = '(';
				SPT_counter++;
				SPT_word[SPT_counter] = 'd';
				SPT_counter++;
				SPT_word[SPT_counter] = ')';
				SPT_counter++;
				SPT_word[SPT_counter] = 'j';
				SPT_counter++;
			}
			else if (argument[arg_counter - 1] == 'g')
			{
				// Do nothing
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
			else if (is_it_vowel (argument[arg_counter + 1]) && !(argument[arg_counter + 1] == 'e' && argument[arg_counter + 2] == '\0') && !(argument[arg_counter + 1] == 'e' && argument[arg_counter + 2] == 's' && argument[arg_counter + 3] == '\0'))
			{
				if (show_system_messages) printf("\npoint hV");
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
				if (show_system_messages) printf("\npoint else_h");
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
				else if (SPT_word[SPT_counter] == 'i' && !(SPT_word[SPT_counter - 1] == 'a') && !(SPT_word[SPT_counter + 1] == 'n' && SPT_word[SPT_counter + 2] == 'g') && !(is_it_consonant(SPT_word[SPT_counter + 1]) && SPT_word[SPT_counter + 2] == '\0') && !(is_it_consonant(SPT_word[SPT_counter + 1]) && is_it_consonant(SPT_word[SPT_counter + 2]) && SPT_word[SPT_counter + 3] == '\0'))
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

	// The piace of code below warns the user that the word might have a prefix
	/*if (!is_testpnc_active && (is_there_more_than_one_vowel ()))
	{
		if ((argument[0] == 'p' && argument[1] == 'e' && argument[2] == 'r') || (argument[0] == 'd' && argument[1] == 'e') || (argument[0] == 'p' && argument[1] == 'r' && argument[2] == 'e') || (argument[0] == 'r' && argument[1] == 'e') || (argument[0] == 'b' && argument[1] == 'e') || (argument[0] == 'e' && argument[1] == 'e') || (argument[0] == 'e' && argument[1] == 'x') || (argument[0] == 'b' && argument[1] == 'e' && argument[2] == 'g' && argument[3] == 'h' && argument[4] == 's') || (argument[0] == 'f' && argument[1] == 'e' && argument[2] == 'r') || (argument[0] == 'n' && argument[1] == 'e') || (argument[0] == 's' && argument[1] == 'e') || (argument[0] == 'e' && argument[1] == 'x' && argument[2] == 't' && argument[3] == 'e' && argument[4] == 'r') || (argument[0] == 'e' && argument[1] == 'n' && argument[2] == 'd' && argument[3] == 'e' && argument[4] == 'r') || (argument[0] == 'e' && argument[1] == 'p') || (argument[0] == 'e' && argument[1] == 'p' && argument[2] == 't' && argument[3] == 'e' && argument[4] == 'r') || (argument[0] == 'd' && argument[1] == 'e' && argument[2] == 's') || (argument[0] == 'e' && argument[1] == 'n') || (argument[0] == 'e' && argument[1] == 't' && argument[2] == 'i') || (argument[0] == 'k' && argument[1] == 'e' && argument[2] == 'n') || (argument[0] == 'n' && argument[1] == 'i' && argument[2] == 't' && argument[3] == 'e' && argument[4] == 'r') || (argument[0] == 'p' && argument[1] == 'e' && argument[2] == 'r' && argument[3] == 'i') || (argument[0] == 's' && argument[1] == 't' && argument[2] == 'e' && argument[3] == 'p'))
		{
			if (!(argument[0] == 'e' && argument[1] == 'x' && argument[2] == 't' && argument[3] == 'e' && argument[4] == 'r' && argument[5] == '\0') && !(argument[0] == 'e' && argument[1] == 'n' && argument[2] == 'd' && argument[3] == 'e' && argument[4] == 'r' && argument[5] == '\0') && !(argument[0] == 'e' && argument[1] == 'p' && argument[2] == 't' && argument[3] == 'e' && argument[4] == 'r' && argument[5] == '\0') && !(argument[0] == 'e' && argument[1] == 't' && argument[2] == 'i' && argument[3] == '\0') && !(argument[0] == 'n' && argument[1] == 'i' && argument[2] == 't' && argument[3] == 'e' && argument[4] == 'r' && argument[5] == '\0') && !(argument[0] == 'p' && argument[1] == 'e' && argument[2] == 'r' && argument[3] == 'i' && argument[4] == '\0'))
			{
				this_program_cannot_guess_prefixes (lang);
			}

		}
    }*/

    // Before giving the program's own transcription, we will test if we already have a ready-made solution for the given word. There are words with "illogic" transcription because of ethymologic reasons that the program cannot predict
    if (strcmp(argument, "suggest") == 0)
	{
		if (show_system_messages) printf("\npoint ready_made_solution\n");
		strcpy(SPT_word, "sugdjEst");
	}
	else if (strcmp(argument, "comprehend") == 0)
	{
		if (show_system_messages) printf("\npoint ready_made_solution\n");
		strcpy(SPT_word, "komprëhEnd");
	}
	else if (strcmp(argument, "decret") == 0)
	{
		if (show_system_messages) printf("\npoint ready_made_solution\n");
		strcpy(SPT_word, "dëkrEt");
	}
	else if (strcmp(argument, "fortrehc") == 0)
	{
		if (show_system_messages) printf("\npoint ready_made_solution\n");
		strcpy(SPT_word, "fortrE:k");
	}
	else if (strcmp(argument, "negleg") == 0)
	{
		if (show_system_messages) printf("\npoint ready_made_solution\n");
		strcpy(SPT_word, "nëglEg");
	}
	else if (strcmp(argument, "respect") == 0)
	{
		if (show_system_messages) printf("\npoint ready_made_solution\n");
		strcpy(SPT_word, "rëspEkt");
	}
	else if (strcmp(argument, "recess") == 0 || strcmp(argument, "reccess") == 0)
	{
		if (show_system_messages) printf("\npoint ready_made_solution\n");
		strcpy(SPT_word, "rëtsEs(s)");
	}
	else if (strcmp(argument, "bevid") == 0)
	{
		if (show_system_messages) printf("\npoint ready_made_solution\n");
		strcpy(SPT_word, "bëvId");
	}





	// Brute correction of words
	if (strcmp(argument, "decret") == 0)
	{
        strcpy(SPT_word, "dëkrEt");
	}



	// Shows the SPT word given by the own program
	if (is_testpnc_active)
		printf("{%s}\n", SPT_word);
	else
		printf("\n{%s}\n", SPT_word);



	// For cleaning
	memset(SPT_word, '\0', strlen(SPT_word));
	SPT_counter = 0;
	stress = FALSE;
	occurrence_of_the_small_e_diaeresis = 0;

}
