#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#include "special_characters.h"
#include "pronunciation.h"

extern char argument[256];
extern short int lang;

extern short int show_system_messages;

short int arg_counter;
short int word_counter;

short int a_for_ie = 0;
short int eu_for_u = 0;
short int ei_for_i = 0;
short int von_wahl = 0;
	short int ct = FALSE; // For dealing with the ct Von Wahl

char infinitive[256];
char present[256];
char past[256];
char participe_t[256];
char participe_en[256];
char present_t[256];
char present_2s[256];
char presentnv[256]; // Present verb without its ending vowel
char pastnv[256]; // Past verb without its ending vowel
char pastcopy[256];
char conditional_icie[256];
char participe_t_v[256];

char nasal[256];

short int check_nasal_infix ()
{
    if ((strstr(argument, "en")) || (strstr(argument, "em")) || (strstr(argument, "ne")) || (strstr(argument, "me")))
    	return TRUE;
	else
		return FALSE;
}

short int check_eh ()
{
	short int x = 0;

	for (arg_counter = 0; arg_counter <= strlen(argument) ; arg_counter++)
	{
		if (argument[arg_counter] == 'e' && argument[arg_counter + 1] == 'h' && is_it_consonant(argument[arg_counter + 2]))
			x++;
	}

	return x; // Have the same effect of TRUE or FALSE
}

short int check_eu ()
{
	short int x = 0;

	for (arg_counter = 0; arg_counter <= strlen(argument) ; arg_counter++)
	{
		if (argument[arg_counter] == 'e' && argument[arg_counter + 1] == 'u' && (is_it_consonant(argument[arg_counter + 2]) || argument[arg_counter + 2] == 'y' || argument[arg_counter + 2] == 'w'))
			x++;
	}

	return x; // Have the same effect of TRUE or FALSE
}

short int check_ei ()
{
    short int x = 0;

	for (arg_counter = 0; arg_counter <= strlen(argument) ; arg_counter++)
	{
		if (argument[arg_counter] == 'e' && argument[arg_counter + 1] == 'i' && is_it_consonant(argument[arg_counter - 1]) && (is_it_consonant(argument[arg_counter + 2]) || argument[arg_counter + 2] == 'y' || argument[arg_counter + 2] == 'w'))
			x++;
	}

	return x; // Have the same effect of TRUE or FALSE
}

short int check_a ()
{
    short int x = 0;

	for (arg_counter = 0; arg_counter <= strlen(argument) ; arg_counter++)
	{
		if (argument[arg_counter] == 'a' && is_it_consonant(argument[arg_counter - 1]) && (is_it_consonant(argument[arg_counter + 1]) || argument[arg_counter + 1] == 'y' || argument[arg_counter + 1] == 'w'))
			x++;
	}

	return x; // Have the same effect of TRUE or FALSE
}

short int check_von_wahl ()
{
    short int x = 0;

	for (arg_counter = 0; arg_counter <= strlen(argument) ; arg_counter++)
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

	return x; // Have the same effect of TRUE or FALSE
}

short int check_von_wahl_v ()
{
    short int x = 0;

	for (arg_counter = 0; arg_counter <= strlen(argument) ; arg_counter++)
	{
		if (argument[arg_counter] == 'v' && argument[arg_counter + 1] == '\0')
			x++;
	}

	return x; // Have the same effect of TRUE or FALSE
}

short int the_last_letter_has_vowel_sound ()
{
    if (argument[strlen(argument) - 1] == 'a' || argument[strlen(argument) - 1] == 'e' || argument[strlen(argument) - 1] == 'i' || argument[strlen(argument) - 1] == 'o' || argument[strlen(argument) - 1] == 'u' || argument[strlen(argument) - 1] == 'y' || argument[strlen(argument) - 1] == 'w')
		return TRUE;
	else
		return FALSE;
}

short int the_last_letter_has_vowel_sound_without_w ()
{
    if (argument[strlen(argument) - 1] == 'a' || argument[strlen(argument) - 1] == 'e' || argument[strlen(argument) - 1] == 'i' || argument[strlen(argument) - 1] == 'o' || argument[strlen(argument) - 1] == 'u' || argument[strlen(argument) - 1] == 'y')
		return TRUE;
	else
		return FALSE;
}

void present_tense ()
{
	if (check_nasal_infix ())
	{
		strcpy(present, nasal);
		strcpy(present_t, nasal);
		strcpy(present_2s, nasal);
	}
	else
	{
		strcpy(present, argument);
		strcpy(present_t, argument);
		strcpy(present_2s, argument);
	}

	if (present_t[strlen(present_t) - 1] == 'g') present_t[strlen(present_t) - 1] = 'c';
	if (present_2s[strlen(present_2s) - 1] == 's') present_2s[strlen(present_2s) - 1] = '\0';
}

void infinitive_verb ()
{
	short int counter;

	if (check_nasal_infix ())
	{
		strcpy(infinitive, nasal);
		counter = strlen(infinitive); // It seems redundant, but I had to do it because the line "infinitive[strlen(infinitive) + 1] = 's';" did'nt worked
		infinitive[counter] = 'e';
		infinitive[counter + 1] = 's';
	}
	else if (check_eu () || check_ei ())
	{
		strcpy(infinitive, past);
		counter = strlen(infinitive);
		infinitive[counter] = 'e';
		infinitive[counter + 1] = 's';
	}
	else
	{
		strcpy(infinitive, argument);
		if (infinitive[strlen(infinitive) - 1] != 'e')
			infinitive[strlen(infinitive)] = 'e';
	}
}

void past_participe ()
{
	if (check_nasal_infix () || check_eh () || check_eu () || check_ei ())
	{
		strcpy(participe_t, past);
		strcpy(participe_en, past);
	}
	else if (check_von_wahl())
	{
		strcpy(participe_t, past);
		strcpy(participe_en, present);
	}
	else if (check_von_wahl_v())
	{
		strcpy(participe_t, participe_t_v);
		strcpy(participe_en, present);
	}
	else
	{
		strcpy(participe_t, present);
		strcpy(participe_en, present);
	}


	if (!(check_von_wahl()))
	{
		if (participe_t[strlen(participe_t) - 1] == 'g') participe_t[strlen(participe_t) - 1] = 'c';
		if (participe_t[strlen(participe_t) - 1] != 't') participe_t[strlen(participe_t)] = 't';
	}


	if (!is_it_vowel(participe_en[strlen(participe_en) - 1])) participe_en[strlen(participe_en)] = 'e';
	participe_en[strlen(participe_en)] = 'n';
}

void conjugation ()
{

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

	if (check_nasal_infix ())
	{
		word_counter = 0;
		for (arg_counter = 0; arg_counter < strlen(argument) ; arg_counter++)
		{
			if (argument[arg_counter] == 'e' && (argument[arg_counter - 1] == 'n' || argument[arg_counter + 1] == 'n' || argument[arg_counter - 1] == 'm' || argument[arg_counter + 1] == 'm'))
			{
				// Do nothing
			}
			else if (argument[arg_counter] == 's' && (argument[arg_counter + 2] == 'e' || argument[arg_counter + 1] == 'e'))
			{
				// Do nothing
			}
			else
			{
				nasal[word_counter] = argument[arg_counter];
				word_counter++;
			}
		}

		// Infinitive
		infinitive_verb ();

		// Present tense
		present_tense ();

		// Past tense
		strcpy(past, nasal);

		// Past participle
		past_participe ();
	}
	else if (check_eh ())
	{
		// Past tense
		strcpy(past, argument);

		for (arg_counter = 0; arg_counter <= strlen(argument) ; arg_counter++)
		{
			if (argument[arg_counter] == 'e' && argument[arg_counter + 1] == 'h' && is_it_consonant(argument[arg_counter + 2]))
			{
				past[arg_counter] = 'o';
			}
		}
		// Infinitive
		infinitive_verb ();

		// Present tense
		present_tense ();

		// Past participle
		past_participe ();
	}
	else if (check_eu ())
	{
		// Past tense
		strcpy(past, argument);

		for (arg_counter = 0; arg_counter <= strlen(argument) ; arg_counter++)
		{
			if ((argument[arg_counter] == 'e' && argument[arg_counter + 1] == 'u') && (is_it_consonant(argument[arg_counter + 2]) || argument[arg_counter + 2] == 'y' || argument[arg_counter + 2] == 'w'))
			{
				past[arg_counter] = 'u';
				// I store the value just below to
				eu_for_u = arg_counter + 1; // The position where will be the "e" of "ie"

				strcpy(pastcopy, past);
			}
		}

		if (eu_for_u > 0)
		{
			for (arg_counter = (eu_for_u); arg_counter <= strlen(past) ; arg_counter++)
			{
				past[arg_counter] = pastcopy[arg_counter + 1];
			}
		}
		// Infinitive
		infinitive_verb ();

		// Present tense
		present_tense ();

		// Past participle
		past_participe ();
	}
	else if (check_ei ())
	{
		// Past tense
		strcpy(past, argument);

		for (arg_counter = 0; arg_counter <= strlen(argument) ; arg_counter++)
		{
			if (argument[arg_counter] == 'e' && argument[arg_counter + 1] == 'i' && is_it_consonant(argument[arg_counter - 1]) && (is_it_consonant(argument[arg_counter + 2]) || argument[arg_counter + 2] == 'y' || argument[arg_counter + 2] == 'w'))
			{
				past[arg_counter] = 'i';
				// I store the value just below to
				eu_for_u = arg_counter + 1; // The position where will be the "e" of "ie"

				strcpy(pastcopy, past);
			}
		}

		if (eu_for_u > 0)
		{
			for (arg_counter = (eu_for_u); arg_counter <= strlen(past) ; arg_counter++)
			{
				past[arg_counter] = pastcopy[arg_counter + 1];
			}
		}
		// Infinitive
		infinitive_verb ();

		// Present tense
		present_tense ();

		// Past participle
		past_participe ();
	}
	else if (check_von_wahl())
	{
		// Past tense
		strcpy(past, argument);

		for (arg_counter = 0; arg_counter <= strlen(argument) ; arg_counter++)
		{
			if (!(argument[arg_counter - 1] == 'd') && (argument[arg_counter] == 'd') && (argument[arg_counter + 1] == '\0'))
			{
				past[arg_counter] = 's';
				// I store the value just below to

				strcpy(pastcopy, past);
			}
			else if ((argument[arg_counter] == 'd' && argument[arg_counter + 1] == 'd' && argument[arg_counter + 2] == '\0') || (argument[arg_counter] == 't' && argument[arg_counter + 1] == 't' && argument[arg_counter + 2] == '\0'))
			{
				past[arg_counter] = 's';
				past[arg_counter + 1] = 's';

				strcpy(pastcopy, past);
			}
			else if ((argument[arg_counter] == 'r' && argument[arg_counter + 1] == 't' && argument[arg_counter + 2] == '\0') || (argument[arg_counter] == 'r' && argument[arg_counter + 1] == 'r' && argument[arg_counter + 2] == '\0') || (argument[arg_counter] == 'r' && argument[arg_counter + 1] == 'g' && argument[arg_counter + 2] == '\0'))
			{
				past[arg_counter + 1] = 's';

				strcpy(pastcopy, past);
			}
			else if (argument[arg_counter] == 'l' && argument[arg_counter + 1] == 'g' && argument[arg_counter + 2] == '\0')
			{
				past[arg_counter + 1] = 's';

				strcpy(pastcopy, past);
			}
			else if (argument[arg_counter] == 'c' && argument[arg_counter + 1] == 't' && argument[arg_counter + 2] == '\0')
			{
				past[arg_counter] = 'x';

				strcpy(pastcopy, past);
				// I store the value just below to
				von_wahl = arg_counter + 1; // The position where will be the "e" of "ie"

				strcpy(pastcopy, past);

				ct = TRUE;
			}
		}

		if (von_wahl > 0 && ct)
		{
			for (arg_counter = (von_wahl); arg_counter <= strlen(past) ; arg_counter++)
			{
				past[arg_counter] = pastcopy[arg_counter + 1];
			}
		}

		// Infinitive
		infinitive_verb ();

		// Present tense
		present_tense ();

		// Past participle
		past_participe ();
	}
	else if (check_von_wahl_v())
	{
		// Past tense
		strcpy(past, argument);
		strcpy(participe_t_v, argument);

		for (arg_counter = 0; arg_counter <= strlen(argument) ; arg_counter++)
		{
			if ((argument[arg_counter] == 'v') && (argument[arg_counter + 1] == '\0'))
			{
				if ((argument[arg_counter - 1] == 'o') || (argument[arg_counter - 1] == 'u'))
				{
					participe_t_v[arg_counter] = '\0';
				}
				else
					participe_t_v[arg_counter] = 'w';
			}
		}

		// Infinitive
		infinitive_verb ();

		// Present tense
		present_tense ();

		// Past participle
		past_participe ();
	}
	else if (check_a ())
	{
		// Past tense
		strcpy(past, argument);

		for (arg_counter = 0; arg_counter <= strlen(argument) ; arg_counter++)
		{
			if (argument[arg_counter] == 'a' && is_it_consonant(argument[arg_counter - 1]) && (is_it_consonant(argument[arg_counter + 1]) || argument[arg_counter + 1] == 'y' || argument[arg_counter + 1] == 'w'))
			{
				past[arg_counter] = 'i';
				// I store the value just below to
				a_for_ie = arg_counter + 1; // The position where will be the "e" of "ie"

				strcpy(pastcopy, past);
			}
		}

		if (a_for_ie > 0)
		{
			for (arg_counter = (a_for_ie + 1); arg_counter <= strlen(past) ; arg_counter++)
			{
				past[arg_counter] = pastcopy[arg_counter - 1];
			}
			past[a_for_ie] = 'e';
		}

		// Infinitive
		infinitive_verb ();

		// Present tense
		present_tense ();

		// Past participle
		past_participe ();
	}
	else
	{
		// Infinitive
		infinitive_verb ();

		// Present tense
		present_tense ();

		// Past tense
		strcpy(past, argument);

		// Past participle
		past_participe ();
	}

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
		else if (check_eh()) printf("\nLOG: This verb has an ehC");
		else if (check_a()) printf("\nLOG: This verb has an internal \"a\"");
		else if (check_eu()) printf("\nLOG: This verb has an internal \"eu\"");
		else if (check_ei()) printf("\nLOG: This verb has an internal \"ei\"");
		else if (check_von_wahl()) printf("\nLOG: This verb follow the Von Wahl rules");
		else if (check_von_wahl_v()) printf("\nLOG: The letter \"v\" of this verb is modified");
		printf("\n-------");
	}

	// The verb
	if (lang == 2) printf("\nVerb: ");
	else if (lang == 4) printf("\nVerbo: ");
	else printf("\nVerb: ");
	printf("%s", argument);


	// Infinitive
	if (lang == 2) printf("\nInfinitive: ");
	else if (lang == 4) printf("\nInfinitivo: ");
	else printf("\nInfinitive: ");
	printf("%s", infinitive);

	// Present tense
	if (lang == 2) printf("\nPresent tense: ");
	else if (lang == 4) printf("\nPresente: ");
	else printf("\nPresent tid: ");
	if (present[strlen(present) - 1] == 'e')
	{
		printf("io %s, ", present);
	}
	else if (the_last_letter_has_vowel_sound_without_w ())
		printf("%sm, ", present);
	else
		printf("%so, ", present);
	printf("%ss, %st, %sm(o)s, yu %st(e), ", present_2s, present_t, present, present_t);

	if (the_last_letter_has_vowel_sound ())
		printf("%snt, ", present);
	else printf("%sent, ", present);

	// Past tense
	if (lang == 2) printf("\nPast tense: ");
	else if (lang == 4) printf("\nPret" SMALL_E_ACUTE "rito: ");
	else printf("\nPrev tid: ");
	// -----
	if (past[strlen(past) - 1] == 'a' || past[strlen(past) - 1] == 'e' || past[strlen(past) - 1] == 'o')
	{
		strcpy(pastnv, past);
		pastnv[strlen(pastnv) - 1] = '\0';
		printf("%sim, %s(i)st(a), %sit, %sam, %sat, ", pastnv, pastnv, pastnv, pastnv, pastnv);
	}
	else if ((past[strlen(past) - 1] == 'h' && (past[strlen(past) - 2] == 'a' || past[strlen(past) - 2] == 'e' || past[strlen(past) - 2] == 'i')) || (past[strlen(past) - 1] == 'i' && past[strlen(past) - 2] == 'e'))
		printf("%s(s)im, %sst(a), %s(s)it, %s(s)am, %s(s)at, ", past, past, past, past, past);
	else
		printf("%sim, %s(i)st(a), %sit, %sam, %sat, ", past, past, past, past, past);
	// -----
	if ((past[strlen(past) - 1] == 'h' && (past[strlen(past) - 2] == 'a' || past[strlen(past) - 2] == 'e' || past[strlen(past) - 2] == 'i')) || (past[strlen(past) - 1] == 'i' && past[strlen(past) - 2] == 'e'))
		printf("%sr", past);
	else
		printf("%seer", past);

	// Future tense
	if (lang == 2) printf("\nFuture tense: ");
	else if (lang == 4) printf("\nFuturo: ");
	else printf("\nFuture tid: ");
	if (the_last_letter_has_vowel_sound ())
		printf("%sssiem, %sssies, %sssiet, %sssiemos, %sssiete, %sssient", present_2s, present_2s, present_2s, present_2s, present_2s, present_2s);
	else if (present[strlen(present) - 1] == 's' && present[strlen(present) - 2] == 's')
		printf("siem %s, sies %s, siet %s, siem(o)s %s, yu siete %s, sient %s", infinitive, infinitive, infinitive, infinitive, infinitive, infinitive);
	else if (present[strlen(present) - 1] == 's')
		printf("%sssiem, %sssies, %sssiet, %sssiemos, %sssiete, %sssient", present_2s, present_2s, present_2s, present_2s, present_2s, present_2s);
	else
		printf("%ssiem, %ssies, %ssiet, %ssiemos, %ssiete, %ssient", present_2s, present_2s, present_2s, present_2s, present_2s, present_2s);

	// Conditional
	if (lang == 2) printf("\nConditional: ");
	else if (lang == 4) printf("\nCondicional: ");
	else printf("\nConditional: ");
	if ((past[strlen(past) - 1] == 'a' || past[strlen(past) - 1] == 'e' || past[strlen(past) - 1] == 'o') && !(past[strlen(past) - 1] == 'e' && (past[strlen(past) - 2] == 'y' || past[strlen(past) - 2] == 'i')))
	{
		strcpy(presentnv, present);
		presentnv[strlen(presentnv) - 1] = '\0';
		printf("%siem, %sies, %siet, %siemos, %siete, %sient", presentnv, presentnv, presentnv, presentnv, presentnv, presentnv);
	}
	else if (present[strlen(argument) - 2] == 'y' && present[strlen(argument) - 1] == 'e')
	{
		present[strlen(argument) - 1] = 'i';
		printf("%sem, %ses, %ssiet, %semos, %sete, %sent", present, present, present, present, present, present);
	}
	else if (present[strlen(argument) - 2] == 'i' && present[strlen(argument) - 1] == 'e')
	{
		strcpy(conditional_icie, present);
		conditional_icie[strlen(argument) - 1] = 'c';
		conditional_icie[strlen(argument)] = 'i';
		conditional_icie[strlen(argument) + 1] = 'e';
		printf("%sm, %ss, %sst, %smos, %ste, %snt", conditional_icie, conditional_icie, conditional_icie, conditional_icie, conditional_icie, conditional_icie);
	}
	else
		printf("%siem, %sies, %siet, %siemos, %siete, %sient", present, present, present, present, present, present);

	// Past participle
	if (lang == 2) printf("\nPast participle: ");
	else if (lang == 4) printf("\nPartic" SMALL_I_ACUTE "pio do passado: ");
	else printf("\nPrev participe: ");
	printf("%s / %s", participe_t, participe_en);


    printf("\n");




    // For cleaning
	memset(argument, '\0', strlen(argument));
	memset(infinitive, '\0', strlen(infinitive));
	memset(present, '\0', strlen(present));
	memset(past, '\0', strlen(past));
	memset(participe_t, '\0', strlen(participe_t));
	memset(participe_en, '\0', strlen(participe_en));
	memset(present_t, '\0', strlen(present_t));
	memset(present_2s, '\0', strlen(present_2s));
	memset(presentnv, '\0', strlen(presentnv));
	memset(pastnv, '\0', strlen(pastnv));
	memset(pastcopy, '\0', strlen(pastcopy));
	memset(conditional_icie, '\0', strlen(conditional_icie));
	memset(participe_t_v, '\0', strlen(participe_t_v));

	a_for_ie = 0;
	eu_for_u = 0;
	ei_for_i = 0;
	von_wahl = 0;
}
