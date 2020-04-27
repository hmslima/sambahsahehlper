#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#include "special_characters.h"
#include "pronunciation.h"

extern char argument[192];
extern short int lang;

extern short int show_system_messages;

short int arg_counter;
short int word_counter;

short int a_for_ie = 0;
short int eu_for_u = 0;
short int ei_for_i = 0;
short int von_wahl = 0;
	short int ct = FALSE; // For dealing with the ct Von Wahl

short int illogic_er = FALSE; // TRUE for words enden in -er that is stressed, like "inser"
short int illogic_el = FALSE; // TRUE for words enden in -el that is stressed, like "korel"

char infinitive[192];
char present_basis[192];
char present_basis2[192];
char present_1ps[192];
char present_2ps[192];
char present_3ps[192];
char present_1pp[192];
char present_2pp[192];
char present_3pp[192];
char past_basis[192];
char past_1ps[192];
char past_2ps[192];
char past_3ps[192];
char past_1pp[192];
char past_2pp[192];
char past_3pp[192];
char future_1ps[192];
char future_2ps[192];
char future_3ps[192];
char future_1pp[192];
char future_2pp[192];
char future_3pp[192];
char conditional_1ps[192];
char conditional_2ps[192];
char conditional_3ps[192];
char conditional_1pp[192];
char conditional_2pp[192];
char conditional_3pp[192];
char participe_t[192];
char participe_en[192];
char io_pronoun[10];

/********************************************************************
**** For checking the words
********************************************************************/

short int check_nasal_infix ()
{
    short int x = 0;

	for (arg_counter = strlen(argument); arg_counter >= 0 ; arg_counter--)
	{
		if ((is_it_consonant(argument[arg_counter - 1]) || argument[arg_counter - 1] == 'w' || argument[arg_counter - 1] == 'y') && argument[arg_counter] == 'e' && argument[arg_counter + 1] == 'm' && (is_it_consonant(argument[arg_counter + 2]) || argument[arg_counter + 2] == '\0') && argument[arg_counter - 1] != '\0' && !((argument[arg_counter - 1] == 'n' || argument[arg_counter - 1] == 'm')))
			x++;
		else if ((is_it_consonant(argument[arg_counter - 1]) || argument[arg_counter - 1] == 'w' || argument[arg_counter - 1] == 'y') && argument[arg_counter] == 'e' && argument[arg_counter + 1] == 'n' && (is_it_consonant(argument[arg_counter + 2]) || argument[arg_counter + 2] == '\0') && argument[arg_counter - 1] != '\0' && !((argument[arg_counter - 1] == 'n' || argument[arg_counter - 1] == 'm')))
			x++;
		else if (!(argument[arg_counter - 1] == 'm') && argument[arg_counter] == 'm' && argument[arg_counter + 1] == 'e' && !(argument[arg_counter + 2] == '\0' || argument[arg_counter + 2] == 'h' || is_it_vowel_without_w(argument[arg_counter + 2])))
			x++;
		else if (!(argument[arg_counter - 1] == 'n') && argument[arg_counter] == 'n' && argument[arg_counter + 1] == 'e' && !(argument[arg_counter + 2] == '\0' || argument[arg_counter + 2] == 'h' || is_it_vowel_without_w(argument[arg_counter + 2])))
			x++;
	}

	if (argument[strlen(argument) - 1] == 'e') x = 0; // Verbs ended in -e cannot have nasal infix
	if (!(is_there_more_than_one_vowel())) x = 0; // If there is only one vowel, like the invented word "men", there cannot be a nasal infix
	if (argument[strlen(argument) - 3] == 'e' && argument[strlen(argument) - 2] == 'n' && argument[strlen(argument) - 1] == 'd') x = 0; // Verbs ended in -end cannot have nasal infix
	if (argument[strlen(argument) - 3] == 'e' && argument[strlen(argument) - 2] == 'n' && argument[strlen(argument) - 1] == 't') x = 0; // Verbs ended in -ent cannot have nasal infix

	// Some "illogic" words that have no nasal infix because their "e" are stressed
	#include "illogic_nasal_infix.h"

	return x; // Have the same effect of TRUE or FALSE
}

short int check_eh ()
{
	short int x = 0;

	for (arg_counter = strlen(argument); arg_counter >= 0 ; arg_counter--)
	{
		if (argument[arg_counter] == 'e' && argument[arg_counter + 1] == 'h' && is_it_consonant(argument[arg_counter + 2]))
			x++;
	}

	if (argument[strlen(argument) - 1] == 'e') x = 0; // Verbs ended in -e have no ablaut
	else if (argument[strlen(argument) - 2] == 'i' && argument[strlen(argument) - 1] == 'n') x = 0; // The stress is in -in
	else if (argument[strlen(argument) - 2] == 'e' && argument[strlen(argument) - 1] == 'y') x = 0; // The stress is in -ey
	else if (argument[strlen(argument) - 2] == 'i' && argument[strlen(argument) - 1] == 'e') x = 0; // The stress is in -ie
	else if (argument[strlen(argument) - 3] == 'i' && argument[strlen(argument) - 2] == 'e' && is_it_consonant(argument[strlen(argument) - 1])) x = 0; // The stress is in -ieC
	else if (argument[strlen(argument) - 3] != 'q' && argument[strlen(argument) - 2] == 'u' && argument[strlen(argument) - 1] == 'i') x = 0; // The stress is in -ui
	else if (argument[strlen(argument) - 4] == 'o' && is_it_consonant(argument[strlen(argument) - 3]) && argument[strlen(argument) - 2] == 'e' && argument[strlen(argument) - 1] == 'l') x = 0; // The stress is in -oCel
	else if ((argument[strlen(argument) - 2] == 'a' || argument[strlen(argument) - 2] == 'o' || argument[strlen(argument) - 2] == 'u') && is_it_consonant(argument[strlen(argument) - 1]) && argument[strlen(argument) - 1] != 's') x = 0; // The stress is in -aC || -oC || -uC
	else if (is_it_vowel(argument[strlen(argument) - 3]) && is_it_consonant(argument[strlen(argument) - 2]) && is_it_consonant(argument[strlen(argument) - 1]) && ((argument[strlen(argument) - 2] == argument[strlen(argument) - 1]) || (argument[strlen(argument) - 2] == 'c' && argument[strlen(argument) - 1] == 'k'))) x = 0; // The stressed vowel is in the vowel VCC
	else if (argument[strlen(argument) - 2] == 'a' && argument[strlen(argument) - 1] == 'h') x = 0; // The stress is in -ah

	return x; // Have the same effect of TRUE or FALSE
}

short int check_eu ()
{
	short int x = 0;

	for (arg_counter = strlen(argument); arg_counter >= 0 ; arg_counter--)
	{
		if (argument[arg_counter] == 'e' && argument[arg_counter + 1] == 'u' && (is_it_consonant(argument[arg_counter + 2]) || argument[arg_counter + 2] == 'y' || argument[arg_counter + 2] == 'w'))
			x++;
	}

	if (argument[strlen(argument) - 1] == 'e') x = 0; // Verbs ended in -e have no ablaut
	else if (argument[strlen(argument) - 2] == 'i' && argument[strlen(argument) - 1] == 'n') x = 0; // The stress is in -in
	else if (argument[strlen(argument) - 2] == 'e' && argument[strlen(argument) - 1] == 'y') x = 0; // The stress is in -ey
	else if (argument[strlen(argument) - 2] == 'i' && argument[strlen(argument) - 1] == 'e') x = 0; // The stress is in -ie
	else if (argument[strlen(argument) - 3] == 'i' && argument[strlen(argument) - 2] == 'e' && is_it_consonant(argument[strlen(argument) - 1])) x = 0; // The stress is in -ieC
	else if (argument[strlen(argument) - 3] != 'q' && argument[strlen(argument) - 2] == 'u' && argument[strlen(argument) - 1] == 'i') x = 0; // The stress is in -ui
	else if (argument[strlen(argument) - 4] == 'o' && is_it_consonant(argument[strlen(argument) - 3]) && argument[strlen(argument) - 2] == 'e' && argument[strlen(argument) - 1] == 'l') x = 0; // The stress is in -oCel
	else if ((argument[strlen(argument) - 2] == 'a' || argument[strlen(argument) - 2] == 'o' || argument[strlen(argument) - 2] == 'u') && is_it_consonant(argument[strlen(argument) - 1]) && argument[strlen(argument) - 1] != 's') // The stress is in -aC || -oC || -uC
	{
		if (argument[strlen(argument) - 3] == 'e' && argument[strlen(argument) - 2] == 'u')
		{/*Do nothing*/}
		else x = 0;
	}
	else if (is_it_vowel(argument[strlen(argument) - 3]) && is_it_consonant(argument[strlen(argument) - 2]) && is_it_consonant(argument[strlen(argument) - 1]) && ((argument[strlen(argument) - 2] == argument[strlen(argument) - 1]) || (argument[strlen(argument) - 2] == 'c' && argument[strlen(argument) - 1] == 'k'))) // The stressed vowel is in the vowel VCC
	{
		if (argument[strlen(argument) - 4] == 'e' && argument[strlen(argument) - 3] == 'u')
		{/*Do nothing*/}
		else x = 0;
	}
	else if (argument[strlen(argument) - 2] == 'a' && argument[strlen(argument) - 1] == 'h') x = 0; // The stress is in -ah

	return x; // Have the same effect of TRUE or FALSE
}

short int check_ei ()
{
    short int x = 0;

	for (arg_counter = strlen(argument); arg_counter >= 0 ; arg_counter--)
	{
		if (argument[arg_counter] == 'e' && argument[arg_counter + 1] == 'i' && (is_it_consonant(argument[arg_counter + 2]) || argument[arg_counter + 2] == 'y' || argument[arg_counter + 2] == 'w') && /*skeir is a prefix*/ !(argument[arg_counter - 2] == 's' && argument[arg_counter - 1] == 'k' && argument[arg_counter + 2] == 'r'))
			x++;
	}

	if (argument[strlen(argument) - 1] == 'e') x = 0; // Verbs ended in -e have no ablaut
	else if (argument[strlen(argument) - 2] == 'i' && argument[strlen(argument) - 1] == 'n') x = 0; // The stress is in -in
	else if (argument[strlen(argument) - 2] == 'e' && argument[strlen(argument) - 1] == 'y') x = 0; // The stress is in -ey
	else if (argument[strlen(argument) - 2] == 'i' && argument[strlen(argument) - 1] == 'e') x = 0; // The stress is in -ie
	else if (argument[strlen(argument) - 3] == 'i' && argument[strlen(argument) - 2] == 'e' && is_it_consonant(argument[strlen(argument) - 1])) x = 0; // The stress is in -ieC
	else if (argument[strlen(argument) - 3] != 'q' && argument[strlen(argument) - 2] == 'u' && argument[strlen(argument) - 1] == 'i') x = 0; // The stress is in -ui
	else if (argument[strlen(argument) - 4] == 'o' && is_it_consonant(argument[strlen(argument) - 3]) && argument[strlen(argument) - 2] == 'e' && argument[strlen(argument) - 1] == 'l') x = 0; // The stress is in -oCel
	else if ((argument[strlen(argument) - 2] == 'a' || argument[strlen(argument) - 2] == 'o' || argument[strlen(argument) - 2] == 'u') && is_it_consonant(argument[strlen(argument) - 1]) && argument[strlen(argument) - 1] != 's') // The stress is in -aC || -oC || -uC
	{
		if (argument[strlen(argument) - 3] == 'e' && argument[strlen(argument) - 2] == 'i')
		{/*Do nothing*/}
		else x = 0;
	}
	else if (is_it_vowel(argument[strlen(argument) - 3]) && is_it_consonant(argument[strlen(argument) - 2]) && is_it_consonant(argument[strlen(argument) - 1]) && ((argument[strlen(argument) - 2] == argument[strlen(argument) - 1]) || (argument[strlen(argument) - 2] == 'c' && argument[strlen(argument) - 1] == 'k'))) // The stressed vowel is in the vowel VCC
	{
		if (argument[strlen(argument) - 4] == 'e' && argument[strlen(argument) - 3] == 'i')
		{/*Do nothing*/}
		else x = 0;
	}
	else if (argument[strlen(argument) - 2] == 'a' && argument[strlen(argument) - 1] == 'h') x = 0; // The stress is in -ah

	return x; // Have the same effect of TRUE or FALSE
}

short int check_a ()
{
    short int x = 0;

	for (arg_counter = strlen(argument); arg_counter >= 0 ; arg_counter--)
	{
		// Test verbs that start with an a-
		if (argument[arg_counter - 1] == '\0' && argument[arg_counter] == 'a') // I believe that any a- verb with more than 6 letters has no ablaut in the firs "a"
		{
			if (strcmp(argument, "ag") == 0 || strcmp(argument, "aghel") == 0 || strcmp(argument, "al") == 0 || strcmp(argument, "algv") == 0 || strcmp(argument, "ammer") == 0 || strcmp(argument, "andh") == 0 || strcmp(argument, "angh") == 0 || strcmp(argument, "ap") == 0 || strcmp(argument, "ar") == 0 || strcmp(argument, "ark") == 0 || strcmp(argument, "aug") == 0 || strcmp(argument, "aum") == 0 || strcmp(argument, "aumber") == 0 || strcmp(argument, "aur") == 0 || strcmp(argument, "aurgh") == 0 || strcmp(argument, "ausk") == 0 || strcmp(argument, "ay") == 0 || strcmp(argument, "aygw") == 0 || strcmp(argument, "ayr") == 0 || strcmp(argument, "aysgwn") == 0 || strcmp(argument, "azwl") == 0)
				x++;
		}
		// Test the "a" in other positions

		// sua- is a prefix
		else if (argument[arg_counter - 3] == '\0' && argument[arg_counter - 2] == 's' && argument[arg_counter - 1] == 'u' && argument[arg_counter] == 'a')
		{
			// Do nothing
		}
		else if (argument[arg_counter - 1] != '\0' && argument[arg_counter] == 'a' && argument[arg_counter + 1] != '\0' && (is_it_consonant(argument[arg_counter + 1]) || argument[arg_counter + 1] == 'y' || argument[arg_counter + 1] == 'u') && !(argument[arg_counter + 1] == 'h' && argument[arg_counter + 2] == '\0'))
		{
			x++;
		}
	}

	if (argument[strlen(argument) - 1] == 'e') x = 0; // Verbs ended in -e have no ablaut
	else if (argument[strlen(argument) - 2] == 'i' && argument[strlen(argument) - 1] == 'n') x = 0; // The stress is in -in
	else if (argument[strlen(argument) - 2] == 'e' && argument[strlen(argument) - 1] == 'y') x = 0; // The stress is in -ey
	else if (argument[strlen(argument) - 2] == 'i' && argument[strlen(argument) - 1] == 'e') x = 0; // The stress is in -ie
	else if (argument[strlen(argument) - 3] == 'i' && argument[strlen(argument) - 2] == 'e' && is_it_consonant(argument[strlen(argument) - 1])) x = 0; // The stress is in -ieC
	else if (argument[strlen(argument) - 3] != 'q' && argument[strlen(argument) - 2] == 'u' && argument[strlen(argument) - 1] == 'i') x = 0; // The stress is in -ui
	else if (argument[strlen(argument) - 4] == 'o' && is_it_consonant(argument[strlen(argument) - 3]) && argument[strlen(argument) - 2] == 'e' && argument[strlen(argument) - 1] == 'l') x = 0; // The stress is in -oCel
	else if ((argument[strlen(argument) - 2] == 'o' || argument[strlen(argument) - 2] == 'u') && is_it_consonant(argument[strlen(argument) - 1]) && argument[strlen(argument) - 1] != 's') x = 0; // The stress is in -oC || -uC
	else if (is_it_vowel(argument[strlen(argument) - 3]) && argument[strlen(argument) - 3] != 'a' && is_it_consonant(argument[strlen(argument) - 2]) && is_it_consonant(argument[strlen(argument) - 1]) && ((argument[strlen(argument) - 2] == argument[strlen(argument) - 1]) || (argument[strlen(argument) - 2] == 'c' && argument[strlen(argument) - 1] == 'k'))) x = 0; // The stressed vowel is in the vowel VCC
	else if (argument[strlen(argument) - 2] == 'a' && argument[strlen(argument) - 1] == 'h') x = 0; // The stress is in -ah

	return x; // Have the same effect of TRUE or FALSE
}

short int check_von_wahl ()
{
    short int x = 0;

	for (arg_counter = strlen(argument); arg_counter >= 0 ; arg_counter--)
	{
		if (argument[arg_counter] == 'd' && argument[arg_counter + 1] == '\0')
			x++;
		else if (argument[arg_counter] == 't' && argument[arg_counter + 1] == 't' && argument[arg_counter + 2] == '\0')
			x++;
		else if (argument[arg_counter] == 'r' && argument[arg_counter + 1] == 't' && argument[arg_counter + 2] == '\0')
			x++;
		else if (argument[arg_counter] == 'r' && argument[arg_counter + 1] == 'r' && argument[arg_counter + 2] == '\0')
			x++;
		else if (argument[arg_counter] == 'r' && argument[arg_counter + 1] == 'g' && argument[arg_counter + 2] == '\0')
			x++;
		else if (argument[arg_counter] == 'l' && argument[arg_counter + 1] == 'g' && argument[arg_counter + 2] == '\0')
			x++;
		else if (argument[arg_counter] == 'c' && argument[arg_counter + 1] == 't' && argument[arg_counter + 2] == '\0')
			x++;
	}

	if (check_eh() || check_ei() || check_eu()) x = 0;

	return x; // Have the same effect of TRUE or FALSE
}

short int check_von_wahl_v ()
{
    short int x = 0;

	for (arg_counter = strlen(argument); arg_counter >= 0 ; arg_counter--)
	{
		if (argument[arg_counter - 1] != 'g' && argument[arg_counter] == 'v' && argument[arg_counter + 1] == '\0')
			x++;
	}

	if (check_eh() || check_ei() || check_eu()) x = 0;

	return x; // Have the same effect of TRUE or FALSE
}

/********************************************************************
**** The tenses
********************************************************************/

void present_tense ()
{
	short int present_1pp_counter;
	short int present_2pp_counter;
	short int present_3pp_counter;

	/********************************************************************
	********************************************************************/

	if (check_nasal_infix ())
	{
		// For the first person singular, first person plural and third person plural
		word_counter = 0;
		for (arg_counter = 0; arg_counter < strlen(argument) ; arg_counter++)
		{
			if (argument[arg_counter - 1] != '\0' && argument[arg_counter] == 'e' && (argument[arg_counter - 1] == 'n' || argument[arg_counter + 1] == 'n' || argument[arg_counter - 1] == 'm' || argument[arg_counter + 1] == 'm') && !((argument[arg_counter - 1] != 'n' && argument[arg_counter - 1] != 'm') && is_it_consonant(argument[arg_counter + 2]) && argument[arg_counter + 3] == '\0'))
			{
				// I check before whether there is not another syllable with the same
				if (argument[arg_counter + 2] == 'e' && (argument[arg_counter + 1] == 'n' || argument[arg_counter + 3] == 'n' || argument[arg_counter + 1] == 'm' || argument[arg_counter + 3] == 'm'))
				{
					present_basis[word_counter] = argument[arg_counter];
					word_counter++;
				}
				else if (argument[arg_counter + 3] == 'e' && (argument[arg_counter + 2] == 'n' || argument[arg_counter + 4] == 'n' || argument[arg_counter + 2] == 'm' || argument[arg_counter + 4] == 'm'))
				{
					present_basis[word_counter] = argument[arg_counter];
					word_counter++;
				}
				else if (argument[arg_counter + 4] == 'e' && (argument[arg_counter + 3] == 'n' || argument[arg_counter + 5] == 'n' || argument[arg_counter + 3] == 'm' || argument[arg_counter + 5] == 'm'))
				{
					present_basis[word_counter] = argument[arg_counter];
					word_counter++;
				}
				else if (argument[arg_counter + 5] == 'e' && (argument[arg_counter + 4] == 'n' || argument[arg_counter + 6] == 'n' || argument[arg_counter + 4] == 'm' || argument[arg_counter + 6] == 'm'))
				{
					present_basis[word_counter] = argument[arg_counter];
					word_counter++;
				}
				// Now we can safely erase this letter
				else
				{
					// Do nothing
				}
			}
			else if (argument[arg_counter] == 's' && argument[arg_counter + 1] == 's' && argument[arg_counter + 2] == 'e' && (argument[arg_counter + 3] == 'm' || argument[arg_counter + 3] == 'n'))
			{
				// Do nothing
			}
			else if (argument[arg_counter] == 's' && argument[arg_counter + 1] == 'e' && (argument[arg_counter + 2] == 'm' || argument[arg_counter + 2] == 'n'))
			{
				// Do nothing
			}
			else if (argument[arg_counter] == 's' && argument[arg_counter - 1] == 'e' && is_it_vowel(argument[arg_counter - 3]))
			{
				// Do nothing
			}
			else if (argument[arg_counter] == 's' && argument[arg_counter - 1] == 's' && argument[arg_counter - 2] == 'e' && is_it_vowel(argument[arg_counter - 4]))
			{
				// Do nothing
			}
			else
			{
				present_basis[word_counter] = argument[arg_counter];
				word_counter++;
			}
		}

		// For the second person singular, third person singular and second person plural
		word_counter = 0;
		for (arg_counter = 0; arg_counter < strlen(argument) ; arg_counter++)
		{
			if (argument[arg_counter - 1] != '\0' && argument[arg_counter] == 'e' && (argument[arg_counter - 1] == 'n' || argument[arg_counter + 1] == 'n' || argument[arg_counter - 1] == 'm' || argument[arg_counter + 1] == 'm'))
			{
				// I check before whether there is not another syllable with the same
				if (argument[arg_counter + 2] == 'e' && (argument[arg_counter + 1] == 'n' || argument[arg_counter + 3] == 'n' || argument[arg_counter + 1] == 'm' || argument[arg_counter + 3] == 'm'))
				{
					present_basis2[word_counter] = argument[arg_counter];
					word_counter++;
				}
				else if (argument[arg_counter + 3] == 'e' && (argument[arg_counter + 2] == 'n' || argument[arg_counter + 4] == 'n' || argument[arg_counter + 2] == 'm' || argument[arg_counter + 4] == 'm'))
				{
					present_basis2[word_counter] = argument[arg_counter];
					word_counter++;
				}
				else if (argument[arg_counter + 4] == 'e' && (argument[arg_counter + 3] == 'n' || argument[arg_counter + 5] == 'n' || argument[arg_counter + 3] == 'm' || argument[arg_counter + 5] == 'm'))
				{
					present_basis2[word_counter] = argument[arg_counter];
					word_counter++;
				}
				else if (argument[arg_counter + 5] == 'e' && (argument[arg_counter + 4] == 'n' || argument[arg_counter + 6] == 'n' || argument[arg_counter + 4] == 'm' || argument[arg_counter + 6] == 'm'))
				{
					present_basis2[word_counter] = argument[arg_counter];
					word_counter++;
				}
				else
				{
					if (argument[arg_counter] == 'e' && argument[arg_counter + 1] == 'n' && is_it_consonant(argument[arg_counter - 1]) && !(argument[arg_counter - 1] == 's'))
					{
						present_basis2[word_counter] = argument[arg_counter];
						word_counter++;
					}
					else if (argument[arg_counter] == 'e' && argument[arg_counter + 1] == 'm' && is_it_consonant(argument[arg_counter - 1]) && !(argument[arg_counter - 1] == 's'))
					{
						present_basis2[word_counter] = argument[arg_counter];
						word_counter++;
					}
					else
					{
						// Do nothing
					}
				}
			}
			else if (argument[arg_counter] == 's'  && argument[arg_counter + 1] == 's' && argument[arg_counter + 2] == 'e' && (argument[arg_counter + 3] == 'm' || argument[arg_counter + 3] == 'n'))
			{
				// Do nothing
			}
			else if (argument[arg_counter] == 's' && argument[arg_counter + 1] == 'e' && (argument[arg_counter + 2] == 'm' || argument[arg_counter + 2] == 'n'))
			{
				// Do nothing
			}
			else if (argument[arg_counter] == 's' && argument[arg_counter - 1] == 'e' && is_it_vowel(argument[arg_counter - 3]))
			{
				// Do nothing
			}
			else if (argument[arg_counter] == 's' && argument[arg_counter - 1] == 's' && argument[arg_counter - 2] == 'e' && is_it_vowel(argument[arg_counter - 4]))
			{
				// Do nothing
			}
			else
			{
				present_basis2[word_counter] = argument[arg_counter];
				word_counter++;
			}
		}
	}
	else
	{
		strcpy(present_basis, argument);
		strcpy(present_basis2, argument);
	}

	// First person singular
	strcpy(present_1ps, present_basis);
	if (strcmp(argument, "es") == 0) // Irregular verb
	{
        strcpy(present_1ps, "som");
	}
	else if (strcmp(argument, "hab") == 0) // Irregular verb
	{
        strcpy(present_1ps, "ho");
	}
	else if (strcmp(argument, "woid") == 0) // Irregular verb
	{
        strcpy(present_1ps, "woidim");
	}
	else if (present_1ps[strlen(present_1ps) - 1] == 'e' || (present_basis[strlen(present_basis) - 3] != 'i' && !(illogic_er) && present_1ps[strlen(present_1ps) - 2] == 'e' && present_1ps[strlen(present_1ps) - 1] == 'r'))
	{
		// Do nothing
	}
	else if (present_basis[strlen(present_basis) - 3] != 'i' && !(illogic_el) && present_basis[strlen(present_basis) - 2] == 'e' && present_basis[strlen(present_basis) - 1] == 'l')
	{
		// Do nothing
	}
	else if (present_1ps[strlen(present_1ps) - 1] == 'w' || present_1ps[strlen(present_1ps) - 1] == 'y') present_1ps[strlen(present_1ps)] = 'o';
	else if (is_it_vowel(present_1ps[strlen(present_1ps) - 1])) present_1ps[strlen(present_1ps)] = 'm';
	else if (is_it_vowel(present_1ps[strlen(present_1ps) - 2]) && present_1ps[strlen(present_1ps) - 1] == 'h') present_1ps[strlen(present_1ps)] = 'm';
	else present_1ps[strlen(present_1ps)] = 'o';

	// Second person singular
	strcpy(present_2ps, present_basis2);
	if (strcmp(argument, "es") == 0) // Irregular verb
	{
        strcpy(present_2ps, "es");
	}
	else if (strcmp(argument, "hab") == 0) // Irregular verb
	{
        strcpy(present_2ps, "has");
	}
	else if (strcmp(argument, "woid") == 0) // Irregular verb
	{
        strcpy(present_2ps, "woidst(a)");
	}
	else if (present_basis2[strlen(present_basis2) - 1] == 's')
	{
		// Do nothing
	}
	else if (present_basis2[strlen(present_basis2) - 1] == 'g')
	{
		present_2ps[strlen(present_2ps) - 1] = 'c';
		present_2ps[strlen(present_2ps)] = 's';
	}
	else if (present_basis2[strlen(present_basis2) - 1] == 'k')
	{
		present_2ps[strlen(present_2ps) - 1] = 'c';
		present_2ps[strlen(present_2ps)] = 's';
	}
	else if (present_basis2[strlen(present_basis2) - 1] == 'b')
	{
		present_2ps[strlen(present_2ps) - 1] = 'p';
		present_2ps[strlen(present_2ps)] = 's';
	}
	else if (present_basis2[strlen(present_basis2) - 1] == 'v' && present_basis2[strlen(present_basis2) - 2] != 'g' && (check_eh() || check_ei() || check_eu()))
	{
		present_2ps[strlen(present_2ps) - 1] = 'f';
		present_2ps[strlen(present_2ps)] = 's';
	}
	else present_2ps[strlen(present_2ps)] = 's';

	// Third person singular
	strcpy(present_3ps, present_basis2);
	if (strcmp(argument, "es") == 0) // Irregular verb
	{
        strcpy(present_3ps, "est");
	}
	else if (strcmp(argument, "hab") == 0) // Irregular verb
	{
        strcpy(present_3ps, "hat");
	}
	else if (strcmp(argument, "woid") == 0) // Irregular verb
	{
        strcpy(present_3ps, "woidit");
	}
	else if (present_3ps[strlen(present_3ps) - 1] == 'g') present_3ps[strlen(present_3ps) - 1] = 'c';
	else if (present_3ps[strlen(present_3ps) - 1] == 'k') present_3ps[strlen(present_3ps) - 1] = 'c';
	else if (present_3ps[strlen(present_3ps) - 1] == 'b') present_3ps[strlen(present_3ps) - 1] = 'p';
	else if (present_3ps[strlen(present_3ps) - 1] == 'v' && present_3ps[strlen(present_3ps) - 2] != 'g' && (check_eh() || check_ei() || check_eu())) present_3ps[strlen(present_3ps) - 1] = 'f';
	if (!((strcmp(argument, "es") == 0) || (strcmp(argument, "hab") == 0) || (strcmp(argument, "woid") == 0)))
	{
		if (present_3ps[strlen(present_3ps) - 1] != 't') present_3ps[strlen(present_3ps)] = 't';
	}

	// First person plural
	strcpy(present_1pp, present_basis);
	if (strcmp(argument, "es") == 0) // Irregular verb
	{
        strcpy(present_1pp, "smos");
	}
	else if (strcmp(argument, "hab") == 0) // Irregular verb
	{
        strcpy(present_1pp, "habmos/hams");
	}
	else if (strcmp(argument, "woid") == 0) // Irregular verb
	{
        strcpy(present_1pp, "woidam");
	}
	else if (check_nasal_infix())
	{
		if (is_it_vowel(present_1pp[strlen(present_1pp) - 3]) && is_it_consonant(present_1pp[strlen(present_1pp) - 2]) && is_it_consonant(present_1pp[strlen(present_1pp) - 1]))
		{
			if ((present_1pp[strlen(present_1pp) - 2] == 'g' && present_1pp[strlen(present_1pp) - 1] == 'n') || (present_1pp[strlen(present_1pp) - 2] == 'm' && present_1pp[strlen(present_1pp) - 1] == 'n'))
			{
				present_1pp_counter = strlen(present_1pp);
				present_1pp[present_1pp_counter] = 'e';
				present_1pp[present_1pp_counter + 1] = 'm';
				present_1pp[present_1pp_counter + 2] = 's';
			}
			else
			{
				present_1pp_counter = strlen(present_1pp);
				present_1pp[present_1pp_counter] = 'm';
				present_1pp[present_1pp_counter + 1] = '(';
				present_1pp[present_1pp_counter + 2] = 'o';
				present_1pp[present_1pp_counter + 3] = ')';
				present_1pp[present_1pp_counter + 4] = 's';
			}
		}
		else
		{
			present_1pp_counter = strlen(present_1pp);
			present_1pp[present_1pp_counter] = 'm';
			present_1pp[present_1pp_counter + 1] = '(';
			present_1pp[present_1pp_counter + 2] = 'o';
			present_1pp[present_1pp_counter + 3] = ')';
			present_1pp[present_1pp_counter + 4] = 's';
		}
	}
	else if (present_1pp[strlen(present_1pp) - 1] == 'e')
	{
		present_1pp_counter = strlen(present_1pp);
		present_1pp[present_1pp_counter] = 'm';
		present_1pp[present_1pp_counter + 1] = 's';
	}
	else if (present_1pp[strlen(present_1pp) - 3] != 'i' && !(illogic_er) && present_1pp[strlen(present_1pp) - 2] == 'e' && present_1pp[strlen(present_1pp) - 1] == 'r')
	{
		present_1pp_counter = strlen(present_1pp);
		present_1pp[present_1pp_counter] = 'm';
		present_1pp[present_1pp_counter + 1] = 's';
	}
	else if (present_1pp[strlen(present_1pp) - 3] != 'i' && !(illogic_el) && present_1pp[strlen(present_1pp) - 2] == 'e' && present_1pp[strlen(present_1pp) - 1] == 'l')
	{
		present_1pp_counter = strlen(present_1pp);
		present_1pp[present_1pp_counter] = 'm';
		present_1pp[present_1pp_counter + 1] = 's';
	}
	else
	{
		if (((present_1pp[strlen(present_1pp) - 2] == 'g' && present_1pp[strlen(present_1pp) - 1] == 'n')))
		{
			present_1pp_counter = strlen(present_1pp);
			present_1pp[present_1pp_counter] = 'e';
			present_1pp[present_1pp_counter + 1] = 'm';
			present_1pp[present_1pp_counter + 2] = 's';
		}
		else
		{
			present_1pp_counter = strlen(present_1pp);
			present_1pp[present_1pp_counter] = 'm';
			present_1pp[present_1pp_counter + 1] = '(';
			present_1pp[present_1pp_counter + 2] = 'o';
			present_1pp[present_1pp_counter + 3] = ')';
			present_1pp[present_1pp_counter + 4] = 's';
		}
	}

	// Second person plural
	strcpy(present_2pp, present_basis2);
	if (strcmp(argument, "es") == 0) // Irregular verb
	{
        strcpy(present_2pp, "ste");
	}
	else if (strcmp(argument, "hab") == 0) // Irregular verb
	{
        strcpy(present_2pp, "habte");
	}
	else if (strcmp(argument, "woid") == 0) // Irregular verb
	{
        strcpy(present_2pp, "woidat");
	}
	else
	{
		present_2pp_counter = strlen(present_2pp);
		if (present_2pp[strlen(present_2pp) - 1] == 'g') present_2pp[strlen(present_2pp) - 1] = 'c';
		else if (present_2pp[strlen(present_2pp) - 1] == 'k') present_2pp[strlen(present_2pp) - 1] = 'c';
		else if (present_2pp[strlen(present_2pp) - 1] == 'b') present_2pp[strlen(present_2pp) - 1] = 'p';
		else if (present_2pp[strlen(present_2pp) - 1] == 'v' && present_2pp[strlen(present_2pp) - 2] != 'g' && (check_eh() || check_ei() || check_eu())) present_2pp[strlen(present_2pp) - 1] = 'f';

		if ((present_2pp[present_2pp_counter - 3] != 'i' && !(illogic_er) && present_2pp[present_2pp_counter - 2] == 'e' && present_2pp[present_2pp_counter - 1] == 'r') || (present_2pp[present_2pp_counter - 3] != 'i' && !(illogic_el) && present_2pp[present_2pp_counter - 2] == 'e' && present_2pp[present_2pp_counter - 1] == 'l'))
		{
			present_2pp[present_2pp_counter] = 't';
		}
		else if (present_2pp[present_2pp_counter - 1] != 't')
		{
			present_2pp[present_2pp_counter] = 't';
			present_2pp[present_2pp_counter + 1] = '(';
			present_2pp[present_2pp_counter + 2] = 'e';
			present_2pp[present_2pp_counter + 3] = ')';
		}
		else
		{
			present_2pp[present_2pp_counter] = 'e';
		}
	}

	// Third person plural
	strcpy(present_3pp, present_basis);
	if (strcmp(argument, "es") == 0) // Irregular verb
	{
        strcpy(present_3pp, "sont");
	}
	else if (strcmp(argument, "hab") == 0) // Irregular verb
	{
        strcpy(present_3pp, "habent/hant");
	}
	else if (strcmp(argument, "woid") == 0) // Irregular verb
	{
        strcpy(present_3pp, "woideer");
	}
	else
	{
		present_3pp_counter = strlen(present_3pp);
		if (is_it_vowel(present_3pp[present_3pp_counter - 1]) || (present_3pp[present_3pp_counter - 1] == 'h' && is_it_vowel(present_3pp[present_3pp_counter - 2])) || (present_3pp[present_3pp_counter - 3] != 'i' && !(illogic_er) && present_3pp[present_3pp_counter - 2] == 'e' && present_3pp[present_3pp_counter - 1] == 'r') || (present_3pp[present_3pp_counter - 3] != 'i' && !(illogic_el) && present_3pp[present_3pp_counter - 2] == 'e' && present_3pp[present_3pp_counter - 1] == 'l'))
		{
			present_3pp[present_3pp_counter] = 'n';
			present_3pp[present_3pp_counter + 1] = 't';
		}
		else
		{
			present_3pp[present_3pp_counter] = 'e';
			present_3pp[present_3pp_counter + 1] = '(';
			present_3pp[present_3pp_counter + 2] = 'n';
			present_3pp[present_3pp_counter + 3] = 't';
			present_3pp[present_3pp_counter + 4] = ')';
		}
	}
}

void past_tense ()
{
	short int past_basis_counter;

	short int nasal_infix_counter_e = 0;
	short int nasal_infix_counter_mn = 0;

	if (check_eh() && check_ei())
	{
		for (arg_counter = strlen(argument); arg_counter >= 0 ; arg_counter--)
		{
			if (argument[arg_counter] == 'e' && argument[arg_counter + 1] == 'h') goto GOTO_EH;
			else if (argument[arg_counter] == 'e' && argument[arg_counter + 1] == 'i') goto GOTO_EI;
		}
	}
	else if (check_eh() && check_eu())
	{
		for (arg_counter = strlen(argument); arg_counter >= 0 ; arg_counter--)
		{
			if (argument[arg_counter] == 'e' && argument[arg_counter + 1] == 'h') goto GOTO_EH;
			else if (argument[arg_counter] == 'e' && argument[arg_counter + 1] == 'u') goto GOTO_EU;
		}
	}
	else if (check_a() && check_nasal_infix())
	{
		goto GOTO_NASAL;
	}


	if (check_eh())
	{
		GOTO_EH:
		word_counter = 0;

		for (arg_counter = 0; arg_counter < strlen(argument) ; arg_counter++)
		{
			if (argument[arg_counter] == 'e' && argument[arg_counter + 1] == 'h')
			{
				if (argument[arg_counter + 2] == 'e' && argument[arg_counter + 3] == 'h')
				{
					past_basis[word_counter] = argument[arg_counter];
					word_counter++;
				}
				else if (argument[arg_counter + 3] == 'e' && argument[arg_counter + 4] == 'h')
				{
					past_basis[word_counter] = argument[arg_counter];
					word_counter++;
				}
				else if (argument[arg_counter + 4] == 'e' && argument[arg_counter + 5] == 'h')
				{
					past_basis[word_counter] = argument[arg_counter];
					word_counter++;
				}
				else if (argument[arg_counter + 5] == 'e' && argument[arg_counter + 6] == 'h')
				{
					past_basis[word_counter] = argument[arg_counter];
					word_counter++;
				}
				else
				{
					past_basis[arg_counter] = 'o';
					word_counter++;
				}
			}
			else
			{
				past_basis[word_counter] = argument[arg_counter];
				word_counter++;
			}
		}
	}
	else if (check_nasal_infix())
	{
		GOTO_NASAL:
		word_counter = 0;

		for (arg_counter = 0; arg_counter < strlen(argument) ; arg_counter++)
		{
			if (argument[arg_counter - 1] != '\0' && argument[arg_counter] == 'e' && (argument[arg_counter - 1] == 'n' || argument[arg_counter + 1] == 'n' || argument[arg_counter - 1] == 'm' || argument[arg_counter + 1] == 'm'))
			{
				// I check before whether there is not another syllable with the same
				if (argument[arg_counter + 2] == 'e' && (argument[arg_counter + 1] == 'n' || argument[arg_counter + 3] == 'n' || argument[arg_counter + 1] == 'm' || argument[arg_counter + 3] == 'm'))
				{
					past_basis[word_counter] = argument[arg_counter];
					word_counter++;
				}
				else if (argument[arg_counter + 3] == 'e' && (argument[arg_counter + 2] == 'n' || argument[arg_counter + 4] == 'n' || argument[arg_counter + 2] == 'm' || argument[arg_counter + 4] == 'm'))
				{
					past_basis[word_counter] = argument[arg_counter];
					word_counter++;
				}
				else if (argument[arg_counter + 4] == 'e' && (argument[arg_counter + 3] == 'n' || argument[arg_counter + 5] == 'n' || argument[arg_counter + 3] == 'm' || argument[arg_counter + 5] == 'm'))
				{
					past_basis[word_counter] = argument[arg_counter];
					word_counter++;
				}
				else if (argument[arg_counter + 5] == 'e' && (argument[arg_counter + 4] == 'n' || argument[arg_counter + 6] == 'n' || argument[arg_counter + 4] == 'm' || argument[arg_counter + 6] == 'm'))
				{
					past_basis[word_counter] = argument[arg_counter];
					word_counter++;
				}
				// Now we can safely erase this letter
				else
				{
					if (nasal_infix_counter_e == 0)
					{
						// Do nothing
						nasal_infix_counter_e++;
					}
					else
					{
						past_basis[word_counter] = argument[arg_counter];
						word_counter++;
					}
				}
			}
			else if (!(argument[arg_counter - 1] == '\0' || (argument[arg_counter - 2] == '\0' && argument[arg_counter - 1] == 'e')) && argument[arg_counter] == 'n' && (argument[arg_counter - 1] == 'e' || argument[arg_counter + 1] == 'e') && !(argument[arg_counter - 1] == 'n' || argument[arg_counter + 1] == 'n'))
			{
				if (argument[arg_counter + 2] == 'n' && (argument[arg_counter + 1] == 'e' || argument[arg_counter + 3] == 'e') && !(argument[arg_counter + 1] == 'n' || argument[arg_counter + 3] == 'n'))
				{
					past_basis[word_counter] = argument[arg_counter];
					word_counter++;
				}
				else if (argument[arg_counter + 3] == 'n' && (argument[arg_counter + 2] == 'e' || argument[arg_counter + 4] == 'e') && !(argument[arg_counter + 2] == 'n' || argument[arg_counter + 4] == 'n'))
				{
					past_basis[word_counter] = argument[arg_counter];
					word_counter++;
				}
				else if (argument[arg_counter + 4] == 'n' && (argument[arg_counter + 3] == 'e' || argument[arg_counter + 5] == 'e') && !(argument[arg_counter + 3] == 'n' || argument[arg_counter + 5] == 'n'))
				{
					past_basis[word_counter] = argument[arg_counter];
					word_counter++;
				}
				else if (argument[arg_counter + 5] == 'n' && (argument[arg_counter + 4] == 'e' || argument[arg_counter + 6] == 'e') && !(argument[arg_counter + 4] == 'n' || argument[arg_counter + 6] == 'n'))
				{
					past_basis[word_counter] = argument[arg_counter];
					word_counter++;
				}
				else if (argument[arg_counter + 1] == 'e' && (argument[arg_counter + 2] == 'n' || argument[arg_counter + 2] == 'm') && argument[arg_counter + 3] == '\0')
				{
					if (show_system_messages) printf("\npoint past_n+emn");
					past_basis[word_counter] = argument[arg_counter];
					word_counter++;
				}
				else
				{
					if (nasal_infix_counter_mn == 0)
					{
						// Do nothing
						nasal_infix_counter_mn++;
					}
					else
					{
						past_basis[word_counter] = argument[arg_counter];
						word_counter++;
					}
				}
			}
			else if (!(argument[arg_counter - 1] == '\0' || (argument[arg_counter - 2] == '\0' && argument[arg_counter - 1] == 'e')) && argument[arg_counter] == 'm' && (argument[arg_counter - 1] == 'e' || argument[arg_counter + 1] == 'e') && !(argument[arg_counter - 1] == 'm' || argument[arg_counter + 1] == 'm'))
			{
				if (argument[arg_counter + 2] == 'm' && (argument[arg_counter + 1] == 'e' || argument[arg_counter + 3] == 'e') && !(argument[arg_counter + 1] == 'n' || argument[arg_counter + 3] == 'n'))
				{
					if (show_system_messages) printf("\npoint past_m2+m");
					past_basis[word_counter] = argument[arg_counter];
					word_counter++;
				}
				else if (argument[arg_counter + 3] == 'm' && (argument[arg_counter + 2] == 'e' || argument[arg_counter + 4] == 'e') && !(argument[arg_counter + 2] == 'n' || argument[arg_counter + 4] == 'n'))
				{
					if (show_system_messages) printf("\npoint past_m3+m");
					past_basis[word_counter] = argument[arg_counter];
					word_counter++;
				}
				else if (argument[arg_counter + 4] == 'm' && (argument[arg_counter + 3] == 'e' || argument[arg_counter + 5] == 'e') && !(argument[arg_counter + 3] == 'n' || argument[arg_counter + 5] == 'n'))
				{
					if (show_system_messages) printf("\npoint past_m4+m");
					past_basis[word_counter] = argument[arg_counter];
					word_counter++;
				}
				else if (argument[arg_counter + 5] == 'm' && (argument[arg_counter + 4] == 'e' || argument[arg_counter + 6] == 'e') && !(argument[arg_counter + 4] == 'n' || argument[arg_counter + 6] == 'n'))
				{
					if (show_system_messages) printf("\npoint past_m5+m");
					past_basis[word_counter] = argument[arg_counter];
					word_counter++;
				}
				else if (argument[arg_counter + 1] == 'e' && (argument[arg_counter + 2] == 'n' || argument[arg_counter + 2] == 'm') && argument[arg_counter + 3] == '\0')
				{
					if (show_system_messages) printf("\npoint past_m+emn");
					past_basis[word_counter] = argument[arg_counter];
					word_counter++;
				}
				else
				{
					if (nasal_infix_counter_mn == 0)
					{
						if (show_system_messages) printf("\npoint past_m_do nothing");
						// Do nothing
						nasal_infix_counter_mn++;
					}
					else
					{
						if (show_system_messages) printf("\npoint past_m_else");
						past_basis[word_counter] = argument[arg_counter];
						word_counter++;
					}
				}
			}
			else
			{
				past_basis[word_counter] = argument[arg_counter];
				word_counter++;
			}
		}
	}
	else if (check_ei())
	{
		GOTO_EI:
		word_counter = 0;

		for (arg_counter = 0; arg_counter < strlen(argument) ; arg_counter++)
		{
			if (argument[arg_counter] == 'e' && argument[arg_counter + 1] == 'i')
			{
				if (argument[arg_counter + 2] == 'e' && argument[arg_counter + 3] == 'i')
				{
					past_basis[word_counter] = argument[arg_counter];
					word_counter++;
				}
				else if (argument[arg_counter + 3] == 'e' && argument[arg_counter + 4] == 'i')
				{
					past_basis[word_counter] = argument[arg_counter];
					word_counter++;
				}
				else if (argument[arg_counter + 4] == 'e' && argument[arg_counter + 5] == 'i')
				{
					past_basis[word_counter] = argument[arg_counter];
					word_counter++;
				}
				else if (argument[arg_counter + 5] == 'e' && argument[arg_counter + 6] == 'i')
				{
					past_basis[word_counter] = argument[arg_counter];
					word_counter++;
				}
				else if (argument[arg_counter + 6] == 'e' && argument[arg_counter + 7] == 'i')
				{
					past_basis[word_counter] = argument[arg_counter];
					word_counter++;
				}
				else
				{
					past_basis[arg_counter] = 'i';
				}
			}
			else
			{
				past_basis[word_counter] = argument[arg_counter];
				word_counter++;
			}
		}
	}
	else if (check_eu())
	{
		GOTO_EU:
		word_counter = 0;

		for (arg_counter = 0; arg_counter < strlen(argument) ; arg_counter++)
		{
			if (argument[arg_counter] == 'e' && argument[arg_counter + 1] == 'u')
			{
				if (argument[arg_counter + 2] == 'e' && argument[arg_counter + 3] == 'u')
				{
					past_basis[word_counter] = argument[arg_counter];
					word_counter++;
				}
				else if (argument[arg_counter + 3] == 'e' && argument[arg_counter + 4] == 'u')
				{
					past_basis[word_counter] = argument[arg_counter];
					word_counter++;
				}
				else if (argument[arg_counter + 4] == 'e' && argument[arg_counter + 5] == 'u')
				{
					past_basis[word_counter] = argument[arg_counter];
					word_counter++;
				}
				else if (argument[arg_counter + 5] == 'e' && argument[arg_counter + 6] == 'u')
				{
					past_basis[word_counter] = argument[arg_counter];
					word_counter++;
				}
				else if (argument[arg_counter + 6] == 'e' && argument[arg_counter + 7] == 'u')
				{
					past_basis[word_counter] = argument[arg_counter];
					word_counter++;
				}
				else
				{
					past_basis[arg_counter] = 'u';
				}
			}
			else
			{
				past_basis[word_counter] = argument[arg_counter];
				word_counter++;
			}
		}
	}
	else if (check_a())
	{
		word_counter = 0;

		for (arg_counter = 0; arg_counter < strlen(argument) ; arg_counter++)
		{
			if (argument[arg_counter] == 'a' && argument[arg_counter + 1] != '\0' && (is_it_consonant(argument[arg_counter + 1]) || argument[arg_counter + 1] == 'y' || argument[arg_counter + 1] == 'u'))
			{
				if (argument[arg_counter + 2] == 'a' && argument[arg_counter + 3] != '\0' && (is_it_consonant(argument[arg_counter + 3]) || argument[arg_counter + 3] == 'y' || argument[arg_counter + 3] == 'u'))
				{
					past_basis[word_counter] = argument[arg_counter];
					word_counter++;
				}
				else if (argument[arg_counter + 3] == 'a' && argument[arg_counter + 4] != '\0' && (is_it_consonant(argument[arg_counter + 4]) || argument[arg_counter + 4] == 'y' || argument[arg_counter + 4] == 'u'))
				{
					past_basis[word_counter] = argument[arg_counter];
					word_counter++;
				}
				else if (argument[arg_counter + 4] == 'a' && argument[arg_counter + 5] != '\0' && (is_it_consonant(argument[arg_counter + 5]) || argument[arg_counter + 5] == 'y' || argument[arg_counter + 5] == 'u'))
				{
					past_basis[word_counter] = argument[arg_counter];
					word_counter++;
				}
				else if (argument[arg_counter + 5] == 'a' && argument[arg_counter + 6] != '\0' && (is_it_consonant(argument[arg_counter + 6]) || argument[arg_counter + 6] == 'y' || argument[arg_counter + 6] == 'u'))
				{
					past_basis[word_counter] = argument[arg_counter];
					word_counter++;
				}
				else
				{
					past_basis[arg_counter] = 'i';
					word_counter = arg_counter;
					word_counter++;
					past_basis[word_counter] = 'e';
					word_counter++;
				}
			}
			else
			{
				past_basis[word_counter] = argument[arg_counter];
				word_counter++;
			}
		}
	}
	else
	{
		strcpy(past_basis, present_basis);
	}

	// I check Von Wahl separetely
	if (check_von_wahl() && !(check_a()))
	{
		word_counter = 0;

		if (!(check_eh() || check_ei() || check_eu() || check_nasal_infix()))
		{
			for (arg_counter = 0; arg_counter < strlen(argument) ; arg_counter++)
			{
				if (argument[arg_counter] == 'd' && argument[arg_counter + 1] == '\0')
				{
					past_basis[arg_counter] = 's';
				}
				else if (argument[arg_counter] == 'd' && argument[arg_counter + 1] == 'd' && argument[arg_counter + 2] == '\0')
				{
					past_basis[arg_counter] = 's';
				}
				else if (argument[arg_counter] == 't' && argument[arg_counter + 1] == '\0' && !(argument[arg_counter - 1] == 'c'))
				{
					past_basis[arg_counter] = 's';
				}
				else if (argument[arg_counter] == 't' && argument[arg_counter + 1] == 't' && argument[arg_counter + 2] == '\0')
				{
					past_basis[arg_counter] = 's';
				}
				else if (argument[arg_counter] == 'r' && argument[arg_counter + 1] == '\0')
				{
					past_basis[arg_counter] = 's';
				}
				else if (argument[arg_counter] == 'g' && argument[arg_counter + 1] == '\0')
				{
					past_basis[arg_counter] = 's';
				}
				else if (argument[arg_counter] == 'c' && argument[arg_counter + 1] == 't' && argument[arg_counter + 2] == '\0')
				{
					past_basis[arg_counter] = 'x';
					past_basis[arg_counter + 1] = '\0';
				}
			}
		}
		else
		{
			for (arg_counter = 0; arg_counter < strlen(past_basis) ; arg_counter++)
			{
				if (past_basis[arg_counter] == 'd' && past_basis[arg_counter + 1] == '\0')
				{
					past_basis[arg_counter] = 's';
				}
				else if (past_basis[arg_counter] == 'd' && past_basis[arg_counter + 1] == 'd' && past_basis[arg_counter + 2] == '\0')
				{
					past_basis[arg_counter] = 's';
				}
				else if (past_basis[arg_counter] == 't' && past_basis[arg_counter + 1] == '\0' && !(past_basis[arg_counter - 1] == 'c'))
				{
					past_basis[arg_counter] = 's';
				}
				else if (past_basis[arg_counter] == 't' && past_basis[arg_counter + 1] == 't' && past_basis[arg_counter + 2] == '\0')
				{
					past_basis[arg_counter] = 's';
				}
				else if (past_basis[arg_counter] == 'r' && past_basis[arg_counter + 1] == '\0')
				{
					past_basis[arg_counter] = 's';
				}
				else if (past_basis[arg_counter] == 'g' && past_basis[arg_counter + 1] == '\0')
				{
					past_basis[arg_counter] = 's';
				}
				else if (past_basis[arg_counter] == 'c' && past_basis[arg_counter + 1] == 't' && past_basis[arg_counter + 2] == '\0')
				{
					past_basis[arg_counter] = 'x';
					past_basis[arg_counter + 1] = '\0';
				}
			}
		}
	}

	// First person singular
	strcpy(past_1ps, past_basis);
	past_basis_counter = strlen(past_basis);
	if (strcmp(argument, "es") == 0) // Irregular verb
	{
        strcpy(past_1ps, "buim//eem");
	}
	else if (strcmp(argument, "hab") == 0) // Irregular verb
	{
        strcpy(past_1ps, "hiebim");
	}
	else if (strcmp(argument, "woid") == 0) // Irregular verb
	{
        strcpy(past_1ps, "woisim");
	}
	else if (past_1ps[strlen(past_1ps) - 3] != 'i' && !(illogic_er) && past_1ps[strlen(past_1ps) - 2] == 'e' && past_1ps[strlen(past_1ps) - 1] == 'r')
	{
		if (past_basis[strlen(past_basis) - 3] == 'c' || past_basis[strlen(past_basis) - 3] == 'g' || (past_basis[strlen(past_basis) - 4] == 'q' && past_basis[strlen(past_basis) - 3] == 'u') || past_basis[strlen(past_basis) - 3] == 'r')
		{
			// Do nothing
		}
		else
		{
			past_1ps[past_basis_counter - 2] = 'r';
			past_1ps[past_basis_counter - 1] = 'i';
			past_1ps[past_basis_counter] = 'm';
		}
	}
	else if (past_1ps[strlen(past_1ps) - 3] != 'i' && !(illogic_el) && past_1ps[strlen(past_1ps) - 2] == 'e' && past_1ps[strlen(past_1ps) - 1] == 'l')
	{
		past_1ps[strlen(past_1ps) - 2] = 'l';
		past_1ps[strlen(past_1ps) - 1] = 'i';
		past_1ps[strlen(past_1ps)] = 'm';
	}
	else if (past_basis[strlen(past_basis) - 2] == 'i' && past_basis[strlen(past_basis) - 1] == 'e')
	{
		past_1ps[past_basis_counter - 1] = 'c';
		past_1ps[past_basis_counter] = 'i';
		past_1ps[past_basis_counter + 1] = 'm';
	}
	else if (past_1ps[strlen(past_1ps) - 1] == 'w' || past_1ps[strlen(past_1ps) - 1] == 'y')
	{
		past_1ps[past_basis_counter] = 'i';
		past_1ps[past_basis_counter + 1] = 'm';
	}
	else if (past_basis[past_basis_counter - 1] == 'e')
	{
		past_1ps[past_basis_counter - 1] = 'i';
		past_1ps[past_basis_counter] = 'm';
	}
	else if ((is_it_vowel(past_basis[past_basis_counter - 2]) && past_basis[past_basis_counter - 1] == 'h') || (is_it_vowel(past_basis[past_basis_counter - 1])))
	{
		past_1ps[past_basis_counter] = 's';
		past_1ps[past_basis_counter + 1] = 'i';
		past_1ps[past_basis_counter + 2] = 'm';
	}
	else
	{
		past_1ps[past_basis_counter] = 'i';
		past_1ps[past_basis_counter + 1] = 'm';
	}

	// Second person singular
	strcpy(past_2ps, past_basis);
	if (strcmp(argument, "es") == 0) // Irregular verb
	{
        strcpy(past_2ps, "buist(a)//ees");
	}
	else if (strcmp(argument, "hab") == 0) // Irregular verb
	{
        strcpy(past_2ps, "hiebst(a)");
	}
	else if (strcmp(argument, "woid") == 0) // Irregular verb
	{
        strcpy(past_2ps, "woisist");
	}
	else if (past_2ps[strlen(past_2ps) - 3] != 'i' && !(illogic_er) && past_basis[strlen(past_basis) - 2] == 'e' && past_basis[strlen(past_basis) - 1] == 'r')
	{
		if (past_basis[strlen(past_basis) - 3] == 'c' || past_basis[strlen(past_basis) - 3] == 'g' || (past_basis[strlen(past_basis) - 4] == 'q' && past_basis[strlen(past_basis) - 3] == 'u') || past_basis[strlen(past_basis) - 3] == 'r')
		{
			past_2ps[past_basis_counter] = 's';
			past_2ps[past_basis_counter + 1] = 't';
		}
		else
		{
			past_2ps[past_basis_counter - 2] = 'r';
			past_2ps[past_basis_counter - 1] = 'i';
			past_2ps[past_basis_counter] = 's';
			past_2ps[past_basis_counter + 1] = 't';
		}
	}
	else if (past_2ps[strlen(past_2ps) - 3] != 'i' && !(illogic_el) && past_2ps[strlen(past_2ps) - 2] == 'e' && past_2ps[strlen(past_2ps) - 1] == 'l')
	{
		past_2ps[past_basis_counter - 2] = 'l';
		past_2ps[past_basis_counter - 1] = 's';
		past_2ps[past_basis_counter] = 't';
	}
	else if (past_basis[strlen(past_basis) - 2] == 'i' && past_basis[strlen(past_basis) - 1] == 'e')
	{
		past_2ps[past_basis_counter] = 's';
		past_2ps[past_basis_counter + 1] = 't';
	}
	else if (past_basis[past_basis_counter - 1] == 'e')
	{
		past_2ps[past_basis_counter - 1] = 'i';
		past_2ps[past_basis_counter] = 's';
		past_2ps[past_basis_counter + 1] = 't';
		past_2ps[past_basis_counter + 2] = '(';
		past_2ps[past_basis_counter + 3] = 'a';
		past_2ps[past_basis_counter + 4] = ')';
	}
	else if (is_it_vowel(past_basis[past_basis_counter - 1]) || (is_it_vowel(past_basis[past_basis_counter - 2]) && past_basis[past_basis_counter - 1] == 'h'))
	{
		past_2ps[past_basis_counter] = 's';
		past_2ps[past_basis_counter + 1] = 't';
		past_2ps[past_basis_counter + 2] = '(';
		past_2ps[past_basis_counter + 3] = 'a';
		past_2ps[past_basis_counter + 4] = ')';
	}
	else
	{
		past_2ps[past_basis_counter] = '(';
		past_2ps[past_basis_counter + 1] = 'i';
		past_2ps[past_basis_counter + 2] = ')';
		past_2ps[past_basis_counter + 3] = 's';
		past_2ps[past_basis_counter + 4] = 't';
		past_2ps[past_basis_counter + 5] = '(';
		past_2ps[past_basis_counter + 6] = 'a';
		past_2ps[past_basis_counter + 7] = ')';
	}

	// Third person singular
	strcpy(past_3ps, past_basis);
	if (strcmp(argument, "es") == 0) // Irregular verb
	{
        strcpy(past_3ps, "buit//eet");
	}
	else if (strcmp(argument, "hab") == 0) // Irregular verb
	{
        strcpy(past_3ps, "hiebit");
	}
	else if (strcmp(argument, "woid") == 0) // Irregular verb
	{
        strcpy(past_3ps, "woisit");
	}
	else if (past_3ps[strlen(past_3ps) - 3] != 'i' && !(illogic_er) && past_basis[strlen(past_basis) - 2] == 'e' && past_basis[strlen(past_basis) - 1] == 'r')
	{
		if (past_basis[strlen(past_basis) - 3] == 'c' || past_basis[strlen(past_basis) - 3] == 'g' || (past_basis[strlen(past_basis) - 4] == 'q' && past_basis[strlen(past_basis) - 3] == 'u') || past_basis[strlen(past_basis) - 3] == 'r')
		{
			// Do nothing
		}
		else
		{
			past_3ps[past_basis_counter - 2] = 'r';
			past_3ps[past_basis_counter - 1] = 'i';
			past_3ps[past_basis_counter] = 't';
		}
	}
	else if (past_3ps[strlen(past_3ps) - 3] != 'i' && !(illogic_el) && past_3ps[strlen(past_3ps) - 2] == 'e' && past_3ps[strlen(past_3ps) - 1] == 'l')
	{
		past_3ps[past_basis_counter - 2] = 'l';
		past_3ps[past_basis_counter - 1] = 'i';
		past_3ps[past_basis_counter] = 't';
	}
	else if (past_basis[strlen(past_basis) - 2] == 'i' && past_basis[strlen(past_basis) - 1] == 'e')
	{
		past_3ps[past_basis_counter - 1] = 'c';
		past_3ps[past_basis_counter] = 'i';
		past_3ps[past_basis_counter + 1] = 't';
	}
	else if (past_3ps[strlen(past_3ps) - 1] == 'w' || past_3ps[strlen(past_3ps) - 1] == 'y')
	{
		past_3ps[past_basis_counter] = 'i';
		past_3ps[past_basis_counter + 1] = 't';
	}
	else if (past_basis[past_basis_counter - 1] == 'e')
	{
		past_3ps[past_basis_counter - 1] = 'i';
		past_3ps[past_basis_counter] = 't';
	}
	else if ((is_it_vowel(past_basis[past_basis_counter - 2]) && past_basis[past_basis_counter - 1] == 'h') || (is_it_vowel(past_basis[past_basis_counter - 1])))
	{
		past_3ps[past_basis_counter] = 's';
		past_3ps[past_basis_counter + 1] = 'i';
		past_3ps[past_basis_counter + 2] = 't';
	}
	else
	{
		past_3ps[past_basis_counter] = 'i';
		past_3ps[past_basis_counter + 1] = 't';
	}

	// First person plural
	strcpy(past_1pp, past_basis);
	if (strcmp(argument, "es") == 0) // Irregular verb
	{
        strcpy(past_1pp, "buam//eemos");
	}
	else if (strcmp(argument, "hab") == 0) // Irregular verb
	{
        strcpy(past_1pp, "hiebam");
	}
	else if (strcmp(argument, "woid") == 0) // Irregular verb
	{
        strcpy(past_1pp, "woisam");
	}
	else if (past_1pp[strlen(past_1pp) - 3] != 'i' && !(illogic_er) && past_basis[strlen(past_basis) - 2] == 'e' && past_basis[strlen(past_basis) - 1] == 'r')
	{
		if (past_basis[strlen(past_basis) - 3] == 'c' || past_basis[strlen(past_basis) - 3] == 'g' || (past_basis[strlen(past_basis) - 4] == 'q' && past_basis[strlen(past_basis) - 3] == 'u') || past_basis[strlen(past_basis) - 3] == 'r')
		{
			past_1pp[past_basis_counter] = '(';
			past_1pp[past_basis_counter + 1] = 'a';
			past_1pp[past_basis_counter + 2] = 'm';
			past_1pp[past_basis_counter + 3] = ')';
		}
		else
		{
			past_1pp[past_basis_counter - 2] = '(';
			past_1pp[past_basis_counter - 1] = 'e';
			past_1pp[past_basis_counter] = ')';
			past_1pp[past_basis_counter + 1] = 'r';
			past_1pp[past_basis_counter + 2] = 'a';
			past_1pp[past_basis_counter + 3] = 'm';
		}
	}
	else if (past_1pp[strlen(past_1pp) - 3] != 'i' && !(illogic_el) && past_1pp[strlen(past_1pp) - 2] == 'e' && past_1pp[strlen(past_1pp) - 1] == 'l')
	{
		past_1pp[past_basis_counter - 2] = '(';
		past_1pp[past_basis_counter - 1] = 'e';
		past_1pp[past_basis_counter] = ')';
		past_1pp[past_basis_counter + 1] = 'l';
		past_1pp[past_basis_counter + 2] = 'a';
		past_1pp[past_basis_counter + 3] = 'm';
	}
	else if (past_basis[strlen(past_basis) - 2] == 'i' && past_basis[strlen(past_basis) - 1] == 'e')
	{
		past_1pp[past_basis_counter - 1] = 'a';
		past_1pp[past_basis_counter] = 'm';
	}
	else if (past_1pp[strlen(past_1pp) - 1] == 'w' || past_1pp[strlen(past_1pp) - 1] == 'y')
	{
		past_1pp[past_basis_counter] = 'a';
		past_1pp[past_basis_counter + 1] = 'm';
	}
	else if (past_basis[past_basis_counter - 1] == 'a')
	{
		past_1pp[past_basis_counter] = 'm';
	}
	else if ((past_basis[past_basis_counter - 2] == 'c' || past_basis[past_basis_counter - 2] == 'g') && past_basis[past_basis_counter - 1] == 'e')
	{
		past_1pp[past_basis_counter] = 'a';
		past_1pp[past_basis_counter + 1] = 'm';
	}
	else if (is_it_vowel(past_basis[past_basis_counter - 1]))
	{
		past_1pp[past_basis_counter - 1] = 'a';
		past_1pp[past_basis_counter] = 'm';
	}
	else if (((is_it_vowel(past_basis[past_basis_counter - 2]) && past_basis[past_basis_counter - 1] == 'h')))
	{
		past_1pp[past_basis_counter] = 's';
		past_1pp[past_basis_counter + 1] = 'a';
		past_1pp[past_basis_counter + 2] = 'm';
	}
	else
	{
		past_1pp[past_basis_counter] = 'a';
		past_1pp[past_basis_counter + 1] = 'm';
	}

	// Second person plural
	strcpy(past_2pp, past_basis);
	if (strcmp(argument, "es") == 0) // Irregular verb
	{
        strcpy(past_2pp, "buat//eete");
	}
	else if (strcmp(argument, "hab") == 0) // Irregular verb
	{
        strcpy(past_2pp, "hiebat");
	}
	else if (strcmp(argument, "woid") == 0) // Irregular verb
	{
        strcpy(past_2pp, "woisat");
	}
	else if (past_2pp[strlen(past_2pp) - 3] != 'i' && !(illogic_er) && past_basis[strlen(past_basis) - 2] == 'e' && past_basis[strlen(past_basis) - 1] == 'r')
	{
		if (past_basis[strlen(past_basis) - 3] == 'c' || past_basis[strlen(past_basis) - 3] == 'g' || (past_basis[strlen(past_basis) - 4] == 'q' && past_basis[strlen(past_basis) - 3] == 'u') || past_basis[strlen(past_basis) - 3] == 'r')
		{
			past_2pp[past_basis_counter] = '(';
			past_2pp[past_basis_counter + 1] = 'a';
			past_2pp[past_basis_counter + 2] = 't';
			past_2pp[past_basis_counter + 3] = ')';
		}
		else
		{
			past_2pp[past_basis_counter - 2] = '(';
			past_2pp[past_basis_counter - 1] = 'e';
			past_2pp[past_basis_counter] = ')';
			past_2pp[past_basis_counter + 1] = 'r';
			past_2pp[past_basis_counter + 2] = 'a';
			past_2pp[past_basis_counter + 3] = 't';
		}
	}
	else if (past_2pp[strlen(past_2pp) - 3] != 'i' && !(illogic_el) && past_2pp[strlen(past_2pp) - 2] == 'e' && past_2pp[strlen(past_2pp) - 1] == 'l')
	{
		past_2pp[past_basis_counter - 2] = '(';
		past_2pp[past_basis_counter - 1] = 'e';
		past_2pp[past_basis_counter] = ')';
		past_2pp[past_basis_counter + 1] = 'l';
		past_2pp[past_basis_counter + 2] = 'a';
		past_2pp[past_basis_counter + 3] = 't';
	}
	else if (past_basis[strlen(past_basis) - 2] == 'i' && past_basis[strlen(past_basis) - 1] == 'e')
	{
		past_2pp[past_basis_counter - 1] = 'a';
		past_2pp[past_basis_counter] = 't';
	}
	else if (past_2pp[strlen(past_2pp) - 1] == 'w' || past_2pp[strlen(past_2pp) - 1] == 'y')
	{
		past_2pp[past_basis_counter] = 'a';
		past_2pp[past_basis_counter + 1] = 't';
	}
	else if (past_basis[past_basis_counter - 1] == 'a')
	{
		past_2pp[past_basis_counter] = 't';
	}
	else if ((past_basis[past_basis_counter - 2] == 'c' || past_basis[past_basis_counter - 2] == 'g') && past_basis[past_basis_counter - 1] == 'e')
	{
		past_2pp[past_basis_counter] = 'a';
		past_2pp[past_basis_counter + 1] = 't';
	}
	else if (is_it_vowel(past_basis[past_basis_counter - 1]))
	{
		past_2pp[past_basis_counter - 1] = 'a';
		past_2pp[past_basis_counter] = 't';
	}
	else if (((is_it_vowel(past_basis[past_basis_counter - 2]) && past_basis[past_basis_counter - 1] == 'h')))
	{
		past_2pp[past_basis_counter] = 's';
		past_2pp[past_basis_counter + 1] = 'a';
		past_2pp[past_basis_counter + 2] = 't';
	}
	else
	{
		past_2pp[past_basis_counter] = 'a';
		past_2pp[past_basis_counter + 1] = 't';
	}

	// Third person plural
	strcpy(past_3pp, past_basis);
	if (strcmp(argument, "es") == 0) // Irregular verb
	{
        strcpy(past_3pp, "buir//eent");
	}
	else if (strcmp(argument, "hab") == 0) // Irregular verb
	{
        strcpy(past_3pp, "hiebeer");
	}
	else if (strcmp(argument, "woid") == 0) // Irregular verb
	{
        strcpy(past_3pp, "woiseer");
	}
	else if (past_3pp[strlen(past_3pp) - 3] != 'i' && !(illogic_er) && past_basis[strlen(past_basis) - 2] == 'e' && past_basis[strlen(past_basis) - 1] == 'r')
	{
		if (past_basis[strlen(past_basis) - 3] == 'c' || past_basis[strlen(past_basis) - 3] == 'g' || (past_basis[strlen(past_basis) - 4] == 'q' && past_basis[strlen(past_basis) - 3] == 'u') || past_basis[strlen(past_basis) - 3] == 'r')
		{
			past_3pp[past_basis_counter] = '(';
			past_3pp[past_basis_counter + 1] = 'e';
			past_3pp[past_basis_counter + 2] = 'e';
			past_3pp[past_basis_counter + 3] = 'r';
			past_3pp[past_basis_counter + 4] = ')';
		}
		else
		{
			past_3pp[past_basis_counter - 2] = '(';
			past_3pp[past_basis_counter - 1] = 'e';
			past_3pp[past_basis_counter] = ')';
			past_3pp[past_basis_counter + 1] = 'r';
			past_3pp[past_basis_counter + 2] = 'e';
			past_3pp[past_basis_counter + 3] = 'e';
			past_3pp[past_basis_counter + 4] = 'r';
		}
	}
	else if (past_3pp[strlen(past_3pp) - 3] != 'i' && !(illogic_el) && past_3pp[strlen(past_3pp) - 2] == 'e' && past_3pp[strlen(past_3pp) - 1] == 'l')
	{
		past_3pp[past_basis_counter - 2] = '(';
		past_3pp[past_basis_counter - 1] = 'e';
		past_3pp[past_basis_counter] = ')';
		past_3pp[past_basis_counter + 1] = 'l';
		past_3pp[past_basis_counter + 2] = 'e';
		past_3pp[past_basis_counter + 3] = 'e';
		past_3pp[past_basis_counter + 4] = 'r';
	}
	else if (past_basis[strlen(past_basis) - 2] == 'i' && past_basis[strlen(past_basis) - 1] == 'e')
	{
		past_3pp[past_basis_counter - 1] = 'e';
		past_3pp[past_basis_counter] = 'r';
	}
	else if (past_3pp[strlen(past_3pp) - 1] == 'w' || past_3pp[strlen(past_3pp) - 1] == 'y')
	{
		past_3pp[past_basis_counter] = 'e';
		past_3pp[past_basis_counter + 1] = 'e';
		past_3pp[past_basis_counter + 2] = 'r';
	}
	else if (past_3pp[strlen(past_3pp) - 1] == 'e')
	{
		past_3pp[past_basis_counter] = 'e';
		past_3pp[past_basis_counter + 1] = 'r';
	}
	else if (((is_it_vowel(past_basis[past_basis_counter - 2]) && past_basis[past_basis_counter - 1] == 'h') || (is_it_vowel(past_basis[past_basis_counter - 1]))))
	{
		past_3pp[past_basis_counter] = 'r';
	}
	else
	{
		past_3pp[past_basis_counter] = 'e';
		past_3pp[past_basis_counter + 1] = 'e';
		past_3pp[past_basis_counter + 2] = 'r';
	}

}

void infinitive_verb ()
{
	short int counter;

	if (check_eh() && check_ei())
	{
		for (arg_counter = strlen(argument); arg_counter >= 0 ; arg_counter--)
		{
			if (argument[arg_counter] == 'e' && argument[arg_counter + 1] == 'h') goto GOTO_EH2;
			else if (argument[arg_counter] == 'e' && argument[arg_counter + 1] == 'i') goto GOTO_EI2;
		}
	}
	else if (check_eh() && check_eu())
	{
		for (arg_counter = strlen(argument); arg_counter >= 0 ; arg_counter--)
		{
			if (argument[arg_counter] == 'e' && argument[arg_counter + 1] == 'h') goto GOTO_EH2;
			else if (argument[arg_counter] == 'e' && argument[arg_counter + 1] == 'u') goto GOTO_EU2;
		}
	}
	else if (check_a() && check_nasal_infix())
	{
		goto GOTO_NASAL2;
	}

	// ------------------------------------

	if (strcmp(argument, "es") == 0) // Irregular verb
	{
        strcpy(infinitive, "ses");
	}
	else if (strcmp(argument, "hab") == 0) // Irregular verb
	{
        strcpy(infinitive, "habe");
	}
	else if (strcmp(argument, "woid") == 0) // Irregular verb
	{
        strcpy(infinitive, "woide");
	}
	else if (check_ei() || check_eu())
	{
		GOTO_EU2:
		GOTO_EI2:
		strcpy(infinitive, past_basis);
		counter = strlen(infinitive);
		if (infinitive[strlen(infinitive) - 1] == 'e')
        {
        	infinitive[counter] = 's';
        }
        else
        {
			infinitive[counter] = 'e';
			infinitive[counter + 1] = 's';
		}
	}
	else if (check_nasal_infix())
	{
		GOTO_NASAL2:
		strcpy(infinitive, present_basis);
		counter = strlen(infinitive);
		if (infinitive[strlen(infinitive) - 1] == 'e')
        {
        	infinitive[counter] = 's';
        }
        else
        {
			infinitive[counter] = 'e';
			infinitive[counter + 1] = 's';
		}
	}
	else if (argument[strlen(argument) - 3] != 'i' && !(illogic_el) && argument[strlen(argument) - 2] == 'e' && argument[strlen(argument) - 1] == 'l')
	{
		strcpy(infinitive, argument);
	}
	else
	{
		GOTO_EH2:
		strcpy(infinitive, present_basis);
		if (infinitive[strlen(infinitive) - 1] == 'e' || (argument[strlen(argument) - 3] != 'i' && !(illogic_er) && infinitive[strlen(infinitive) - 2] == 'e' && infinitive[strlen(infinitive) - 1] == 'r'))
        {
            // Do nothing
        }
        else
			infinitive[strlen(infinitive)] = 'e';
	}
}

void future_tense ()
{
	short int present_2ps_counter = strlen(present_2ps);

	// First person singular
	strcpy(future_1ps, present_2ps);
	if (strcmp(argument, "es") == 0) // Irregular verb
	{
        strcpy(future_1ps, "sessiem");
	}
	else if (strcmp(argument, "hab") == 0) // Irregular verb
	{
        strcpy(future_1ps, "habsiem");
	}
	else if (strcmp(argument, "woid") == 0) // Irregular verb
	{
        strcpy(future_1ps, "woidsiem");
	}
	else
	{
		future_1ps[present_2ps_counter] = 'i';
		future_1ps[present_2ps_counter + 1] = 'e';
		future_1ps[present_2ps_counter + 2] = 'm';
	}

	// Second person singular
	strcpy(future_2ps, present_2ps);
	if (strcmp(argument, "es") == 0) // Irregular verb
	{
        strcpy(future_2ps, "sessies");
	}
	else if (strcmp(argument, "hab") == 0) // Irregular verb
	{
        strcpy(future_2ps, "habsies");
	}
	else if (strcmp(argument, "woid") == 0) // Irregular verb
	{
        strcpy(future_2ps, "woidsies");
	}
	else
	{
		future_2ps[present_2ps_counter] = 'i';
		future_2ps[present_2ps_counter + 1] = 'e';
		future_2ps[present_2ps_counter + 2] = 's';
	}

	// Third person singular
	strcpy(future_3ps, present_2ps);
	if (strcmp(argument, "es") == 0) // Irregular verb
	{
        strcpy(future_3ps, "sessiet");
	}
	else if (strcmp(argument, "hab") == 0) // Irregular verb
	{
        strcpy(future_3ps, "habsiet");
	}
	else if (strcmp(argument, "woid") == 0) // Irregular verb
	{
        strcpy(future_3ps, "woidsiet");
	}
	else
	{
		future_3ps[present_2ps_counter] = 'i';
		future_3ps[present_2ps_counter + 1] = 'e';
		future_3ps[present_2ps_counter + 2] = 't';
	}

	// First person plural
	strcpy(future_1pp, present_2ps);
	if (strcmp(argument, "es") == 0) // Irregular verb
	{
        strcpy(future_1pp, "sessiemos");
	}
	else if (strcmp(argument, "hab") == 0) // Irregular verb
	{
        strcpy(future_1pp, "habsiem(o)s");
	}
	else if (strcmp(argument, "woid") == 0) // Irregular verb
	{
        strcpy(future_1pp, "woidsiem(o)s");
	}
	else
	{
		future_1pp[present_2ps_counter] = 'i';
		future_1pp[present_2ps_counter + 1] = 'e';
		future_1pp[present_2ps_counter + 2] = 'm';
		future_1pp[present_2ps_counter + 3] = '(';
		future_1pp[present_2ps_counter + 4] = 'o';
		future_1pp[present_2ps_counter + 5] = ')';
		future_1pp[present_2ps_counter + 6] = 's';
	}

	// Second person plural
	strcpy(future_2pp, present_2ps);
	if (strcmp(argument, "es") == 0) // Irregular verb
	{
        strcpy(future_2pp, "sessiete");
	}
	else if (strcmp(argument, "hab") == 0) // Irregular verb
	{
        strcpy(future_2pp, "habsiete");
	}
	else if (strcmp(argument, "woid") == 0) // Irregular verb
	{
        strcpy(future_2pp, "woidsiete");
	}
	else
	{
		future_2pp[present_2ps_counter] = 'i';
		future_2pp[present_2ps_counter + 1] = 'e';
		future_2pp[present_2ps_counter + 2] = 't';
		future_2pp[present_2ps_counter + 3] = 'e';
	}

	// Third person  plural
	strcpy(future_3pp, present_2ps);
	if (strcmp(argument, "es") == 0) // Irregular verb
	{
        strcpy(future_3pp, "sessient");
	}
	else if (strcmp(argument, "hab") == 0) // Irregular verb
	{
        strcpy(future_3pp, "habsient");
	}
	else if (strcmp(argument, "woid") == 0) // Irregular verb
	{
        strcpy(future_3pp, "woidsient");
	}
	else
	{
		future_3pp[present_2ps_counter] = 'i';
		future_3pp[present_2ps_counter + 1] = 'e';
		future_3pp[present_2ps_counter + 2] = 'n';
		future_3pp[present_2ps_counter + 3] = 't';
	}
}

void conditional ()
{
	short int conditional_counter = strlen(present_basis);

	strcpy(conditional_1ps, present_basis);
	strcpy(conditional_2ps, present_basis);
	strcpy(conditional_3ps, present_basis);
	strcpy(conditional_1pp, present_basis);
	strcpy(conditional_2pp, present_basis);
	strcpy(conditional_3pp, present_basis);

	if (present_basis[strlen(present_basis) - 2] == 'i' && present_basis[strlen(present_basis) - 1] == 'e')
	{
		// First person singular
		conditional_1ps[conditional_counter - 1] = 'c';
		conditional_1ps[conditional_counter] = 'i';
		conditional_1ps[conditional_counter + 1] = 'e';
		conditional_1ps[conditional_counter + 2] = 'm';

		// Second person singular
		conditional_2ps[conditional_counter - 1] = 'c';
		conditional_2ps[conditional_counter] = 'i';
		conditional_2ps[conditional_counter + 1] = 'e';
		conditional_2ps[conditional_counter + 2] = 's';

		// Third person singular
		conditional_3ps[conditional_counter - 1] = 'c';
		conditional_3ps[conditional_counter] = 'i';
		conditional_3ps[conditional_counter + 1] = 'e';
		conditional_3ps[conditional_counter + 2] = 't';

		// First person plural
		conditional_1pp[conditional_counter - 1] = 'c';
		conditional_1pp[conditional_counter] = 'i';
		conditional_1pp[conditional_counter + 1] = 'e';
		conditional_1pp[conditional_counter + 2] = 'm';
		conditional_1pp[conditional_counter + 3] = '(';
		conditional_1pp[conditional_counter + 4] = 'o';
		conditional_1pp[conditional_counter + 5] = ')';
		conditional_1pp[conditional_counter + 6] = 's';

		// Second person plural
		conditional_2pp[conditional_counter - 1] = 'c';
		conditional_2pp[conditional_counter] = 'i';
		conditional_2pp[conditional_counter + 1] = 'e';
		conditional_2pp[conditional_counter + 2] = 't';
		conditional_2pp[conditional_counter + 3] = 'e';

		// Third person  plural
		conditional_3pp[conditional_counter - 1] = 'c';
		conditional_3pp[conditional_counter] = 'i';
		conditional_3pp[conditional_counter + 1] = 'e';
		conditional_3pp[conditional_counter + 2] = 'n';
		conditional_3pp[conditional_counter + 3] = 't';
	}
	else if (is_it_vowel(present_basis[strlen(present_basis) - 1]) && present_basis[strlen(present_basis) - 1] != 'w' && present_basis[strlen(present_basis) - 1] != 'y')
	{
		// First person singular
		conditional_1ps[conditional_counter - 1] = 'i';
		conditional_1ps[conditional_counter] = 'e';
		conditional_1ps[conditional_counter + 1] = 'm';

		// Second person singular
		conditional_2ps[conditional_counter - 1] = 'i';
		conditional_2ps[conditional_counter] = 'e';
		conditional_2ps[conditional_counter + 1] = 's';

		// Third person singular
		conditional_3ps[conditional_counter - 1] = 'i';
		conditional_3ps[conditional_counter] = 'e';
		conditional_3ps[conditional_counter + 1] = 't';

		// First person plural
		conditional_1pp[conditional_counter - 1] = 'i';
		conditional_1pp[conditional_counter] = 'e';
		conditional_1pp[conditional_counter + 1] = 'm';
		conditional_1pp[conditional_counter + 2] = '(';
		conditional_1pp[conditional_counter + 3] = 'o';
		conditional_1pp[conditional_counter + 4] = ')';
		conditional_1pp[conditional_counter + 5] = 's';

		// Second person plural
		conditional_2pp[conditional_counter - 1] = 'i';
		conditional_2pp[conditional_counter] = 'e';
		conditional_2pp[conditional_counter + 1] = 't';
		conditional_2pp[conditional_counter + 2] = 'e';

		// Third person  plural
		conditional_3pp[conditional_counter - 1] = 'i';
		conditional_3pp[conditional_counter] = 'e';
		conditional_3pp[conditional_counter + 1] = 'n';
		conditional_3pp[conditional_counter + 2] = 't';
	}
	else
	{
		// First person singular
		conditional_1ps[conditional_counter] = 'i';
		conditional_1ps[conditional_counter + 1] = 'e';
		conditional_1ps[conditional_counter + 2] = 'm';

		// Second person singular
		conditional_2ps[conditional_counter] = 'i';
		conditional_2ps[conditional_counter + 1] = 'e';
		conditional_2ps[conditional_counter + 2] = 's';

		// Third person singular
		conditional_3ps[conditional_counter] = 'i';
		conditional_3ps[conditional_counter + 1] = 'e';
		conditional_3ps[conditional_counter + 2] = 't';

		// First person plural
		conditional_1pp[conditional_counter] = 'i';
		conditional_1pp[conditional_counter + 1] = 'e';
		conditional_1pp[conditional_counter + 2] = 'm';
		conditional_1pp[conditional_counter + 3] = '(';
		conditional_1pp[conditional_counter + 4] = 'o';
		conditional_1pp[conditional_counter + 5] = ')';
		conditional_1pp[conditional_counter + 6] = 's';

		// Second person plural
		conditional_2pp[conditional_counter] = 'i';
		conditional_2pp[conditional_counter + 1] = 'e';
		conditional_2pp[conditional_counter + 2] = 't';
		conditional_2pp[conditional_counter + 3] = 'e';

		// Third person  plural
		conditional_3pp[conditional_counter] = 'i';
		conditional_3pp[conditional_counter + 1] = 'e';
		conditional_3pp[conditional_counter + 2] = 'n';
		conditional_3pp[conditional_counter + 3] = 't';
	}
}

void past_participe ()
{
	if (check_nasal_infix () || check_eh () || check_eu () || check_ei ())
	{
		strcpy(participe_t, past_basis);
		strcpy(participe_en, past_basis);
	}
	else
	{
		strcpy(participe_t, present_basis);
		strcpy(participe_en, present_basis);
	}

	if (check_von_wahl() && !(check_a()))
	{
		memset(participe_t, '\0', strlen(participe_t));
		//memset(participe_en, '\0', strlen(participe_en));
		strcpy(participe_t, past_basis);
		//strcpy(participe_en, present_basis);
	}
	else if (check_von_wahl_v())
	{
		strcpy(participe_t, argument);
		if (participe_t[strlen(participe_t) - 2] == 'o' || participe_t[strlen(participe_t) - 2] == 'u')
		{
			participe_t[strlen(participe_t) - 1] = 't';
		}
		else
		{
			participe_t[strlen(participe_t) - 1] = 'w';
			participe_t[strlen(participe_t)] = 't';
		}
		strcpy(participe_en, present_basis);
	}


	if (!(check_von_wahl()))
	{
		if (participe_t[strlen(participe_t) - 1] == 'g') participe_t[strlen(participe_t) - 1] = 'c';
		else if (participe_t[strlen(participe_t) - 1] == 'k') participe_t[strlen(participe_t) - 1] = 'c';
		else if (participe_t[strlen(participe_t) - 1] == 'b') participe_t[strlen(participe_t) - 1] = 'p';
		else if (participe_t[strlen(participe_t) - 1] == 'v' && participe_t[strlen(participe_t) - 2] != 'g' && (check_eh() || check_ei() || check_eu())) participe_t[strlen(participe_t) - 1] = 'f';

		if (participe_t[strlen(participe_t) - 1] != 't') participe_t[strlen(participe_t)] = 't';
	}
	else
	{
        if (participe_t[strlen(participe_t) - 1] == 'd') participe_t[strlen(participe_t) - 1] = 's';
	}


	if (!is_it_vowel_without_wy(participe_en[strlen(participe_en) - 1]) && !(is_it_vowel(participe_en[strlen(participe_en) - 2]) && participe_en[strlen(participe_en) - 1] == 'h') && !(participe_en[strlen(participe_en) - 3] != 'i' && !(illogic_er) && participe_en[strlen(participe_en) - 2] == 'e' && participe_en[strlen(participe_en) - 1] == 'r') && !(participe_en[strlen(participe_en) - 3] != 'i' && !(illogic_el) && participe_en[strlen(participe_en) - 2] == 'e' && participe_en[strlen(participe_en) - 1] == 'l') && !(is_it_consonant(participe_en[strlen(participe_en) - 2]) && participe_en[strlen(participe_en) - 1] == 'w') && !(is_it_consonant(participe_en[strlen(participe_en) - 2]) && participe_en[strlen(participe_en) - 1] == 'y')) participe_en[strlen(participe_en)] = 'e';

	participe_en[strlen(participe_en)] = 'n';


	if (check_von_wahl())
	{
		if (argument[strlen(argument) - 2] == 's' && argument[strlen(argument) - 1] == 'd') // For correcting words like scinesd, otherwise we will get "scinden" instead the correct "scisden"
		{
			participe_en[strlen(participe_en) - 3] = 'd';
		}
		else if (participe_en[strlen(participe_en) - 3] == 's' && participe_en[strlen(participe_en) - 2] == 'e' && participe_en[strlen(participe_en) - 1] == 'n') // For correcting words like "funed", otherwise we eil get "fusen" instead the correct "fuden"
		{
			participe_en[strlen(participe_en) - 3] = 'd';
		}
	}
}

/********************************************************************
**** The main function
********************************************************************/

void conjugation ()
{
	if (argument[strlen(argument) - 3] != 'i' && argument[strlen(argument) - 2] == 'e' && argument[strlen(argument) - 1] == 'r')
	{
		if ((strcmp(argument, "confer") == 0) || (strcmp(argument, "defer") == 0) || (strcmp(argument, "deser") == 0) || (strcmp(argument, "differ") == 0) || (strcmp(argument, "infer") == 0) || (strcmp(argument, "inser") == 0) || (strcmp(argument, "interfer") == 0) || (strcmp(argument, "prefer") == 0) || (strcmp(argument, "refer") == 0) || (strcmp(argument, "reper") == 0) || (strcmp(argument, "transfer") == 0))
			illogic_er = TRUE;
		else
			illogic_er = FALSE;
	}
	if (argument[strlen(argument) - 3] != 'i' && argument[strlen(argument) - 2] == 'e' && argument[strlen(argument) - 1] == 'l')
	{
		// test the oCel rule
		if (argument[strlen(argument) - 4] == 'o' && (is_it_consonant(argument[strlen(argument) - 3]) || argument[strlen(argument) - 3] == 'w' || argument[strlen(argument) - 3] == 'y'))
			illogic_el = TRUE;
		else
			illogic_el = FALSE;
	}

	// Call the functions
	present_tense();
	past_tense ();
	infinitive_verb();
	future_tense ();
	conditional ();
	past_participe();


	/***************************************************************************
	****************************************************************************
	************* THE TEXT TO BE SHOWN
	****************************************************************************
	****************************************************************************/

	if (show_system_messages)
	{
		printf("\nLOG: argument: %s", argument);
		printf("\nLOG: argument (size): %d", (int)strlen(argument));
		printf("\nLOG: argument[strlen(argument) - 1]: %c", argument[strlen(argument) - 1]);
		if (check_nasal_infix()) printf("\nLOG: This verb has nasal infix");
		if (check_eh()) printf("\nLOG: This verb has an ehC");
		if (check_a()) printf("\nLOG: This verb has an internal \"a\"");
		if (check_eu()) printf("\nLOG: This verb has an internal \"eu\"");
		if (check_ei()) printf("\nLOG: This verb has an internal \"ei\"");
		if (check_von_wahl()) printf("\nLOG: This verb follow the Von Wahl rules");
		if (check_von_wahl_v()) printf("\nLOG: The letter \"v\" of this verb is modified");
		printf("\n-------");
	}

	// The verb
	if (lang == 2) printf("\nVerb: ");
	else if (lang == 4) printf("\nVerbo: ");
	else if (lang == 6) printf("\nVerbe : ");
	else if (lang == 8 || lang == 9) printf("\nVerbo: ");
	else if (lang == 10) printf("\nVerbo: ");
	else printf("\nVerb: ");
	printf("%s", argument);


	// Infinitive
	if (lang == 2) printf("\nInfinitive: ");
	else if (lang == 4) printf("\nInfinitivo: ");
	else if (lang == 6) printf("\nInfinitif : ");
	else if (lang == 8 || lang == 9) printf("\nInfinitivo: ");
	else if (lang == 10) printf("\nInfinitivo: ");
	else printf("\nInfinitive: ");
	printf("%s", infinitive);

	// Present tense
	if (lang == 2) printf("\nPresent tense: ");
	else if (lang == 4) printf("\nPresente: ");
	else if (lang == 6) printf("\nPr" SMALL_E_ACUTE "sent : ");
	else if (lang == 8 || lang == 9) printf("\nPresente: ");
	else if (lang == 10) printf("\nPrezenco: ");
	else printf("\nPresent tid: ");
	// -----
	if (present_1ps[strlen(present_1ps) - 1] == 'e' || (present_1ps[strlen(present_1ps) - 2] == 'e' && present_1ps[strlen(present_1ps) - 1] == 'r') || (present_1ps[strlen(present_1ps) - 2] == 'e' && present_1ps[strlen(present_1ps) - 1] == 'l')) strcpy(io_pronoun, "io ");
	else strcpy(io_pronoun, "");
	printf("%s%s, %s, %s, %s, yu %s, %s", io_pronoun, present_1ps, present_2ps, present_3ps, present_1pp, present_2pp, present_3pp);

	// Past tense
	if (lang == 2) printf("\nPast tense: ");
	else if (lang == 4) printf("\nPret" SMALL_E_ACUTE "rito: ");
	else if (lang == 6) printf("\nPass" SMALL_E_ACUTE " : ");
	else if (lang == 8 || lang == 9) printf("\nPasado: ");
	else if (lang == 10) printf("\nPreterito: ");
	else printf("\nPreterit: ");
	// -----
	printf("%s, %s, %s, %s, %s, %s", past_1ps, past_2ps, past_3ps, past_1pp, past_2pp, past_3pp);

	// Future tense
	if (lang == 2) printf("\nFuture tense: ");
	else if (lang == 4) printf("\nFuturo: ");
	else if (lang == 6) printf("\nFutur : ");
	else if (lang == 8 || lang == 9) printf("\nFuturo: ");
	else if (lang == 10) printf("\nFuturo: ");
	else printf("\nFuture tid: ");
	if (present_basis[strlen(present_basis) - 1] == 's')
		printf("siem %s, sies %s, siet %s, siem(o)s %s, yu siete %s, sient %s", infinitive, infinitive, infinitive, infinitive, infinitive, infinitive);
	else
		printf("%s, %s, %s, %s, yu %s, %s", future_1ps, future_2ps, future_3ps, future_1pp, future_2pp, future_3pp);

	// Conditional
	if (lang == 2) printf("\nConditional: ");
	else if (lang == 4) printf("\nCondicional: ");
	else if (lang == 6) printf("\nConditionnel : ");
	else if (lang == 8 || lang == 9) printf("\nCondicional: ");
	else if (lang == 10) printf("\nKondicionalo: ");
	else printf("\nConditional: ");
	// -----
	printf("%s, %s, %s, %s, yu %s, %s", conditional_1ps, conditional_2ps, conditional_3ps, conditional_1pp, conditional_2pp, conditional_3pp);

	// Past participle
	if (lang == 2) printf("\nPast participle: ");
	else if (lang == 4) printf("\nPartic" SMALL_I_ACUTE "pio do passado: ");
	else if (lang == 6) printf("\nParticipe pass" SMALL_E_ACUTE " : ");
	else if (lang == 8 || lang == 9) printf("\nPasado participio: ");
	else if (lang == 10) printf("\nPasinta pasiva participo: ");
	else printf("\nPrev participe: ");
	// -----
	printf("%s / %s", participe_t, participe_en);


    printf("\n");


    // For cleaning
	memset(argument, '\0', strlen(argument));
	memset(infinitive, '\0', strlen(infinitive));
	memset(present_basis, '\0', strlen(present_basis));
	memset(present_basis2, '\0', strlen(present_basis2));
	memset(present_1ps, '\0', strlen(present_1ps));
	memset(present_2ps, '\0', strlen(present_2ps));
	memset(present_3ps, '\0', strlen(present_3ps));
	memset(present_1pp, '\0', strlen(present_1pp));
	memset(present_2pp, '\0', strlen(present_2pp));
	memset(present_3pp, '\0', strlen(present_3pp));
	memset(past_basis, '\0', strlen(past_basis));
	memset(past_1ps, '\0', strlen(past_1ps));
	memset(past_2ps, '\0', strlen(past_2ps));
	memset(past_3ps, '\0', strlen(past_3ps));
	memset(past_1pp, '\0', strlen(past_1pp));
	memset(past_2pp, '\0', strlen(past_2pp));
	memset(past_3pp, '\0', strlen(past_3pp));
	memset(future_1ps, '\0', strlen(future_1ps));
	memset(future_2ps, '\0', strlen(future_2ps));
	memset(future_3ps, '\0', strlen(future_3ps));
	memset(future_1pp, '\0', strlen(future_1pp));
	memset(future_2pp, '\0', strlen(future_2pp));
	memset(future_3pp, '\0', strlen(future_3pp));
	memset(conditional_1ps, '\0', strlen(conditional_1ps));
	memset(conditional_2ps, '\0', strlen(conditional_2ps));
	memset(conditional_3ps, '\0', strlen(conditional_3ps));
	memset(conditional_1pp, '\0', strlen(conditional_1pp));
	memset(conditional_2pp, '\0', strlen(conditional_2pp));
	memset(conditional_3pp, '\0', strlen(conditional_3pp));
	memset(participe_t, '\0', strlen(participe_t));
	memset(participe_en, '\0', strlen(participe_en));
	memset(io_pronoun, '\0', strlen(io_pronoun));

	a_for_ie = 0;
	eu_for_u = 0;
	ei_for_i = 0;
	von_wahl = 0;
}
