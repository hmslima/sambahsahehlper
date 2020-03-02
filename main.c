#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#include "special_characters.h"

char command[256]; // Variable where all commands will be stored.
char command_name[64]; // The command itself
short int command_number;
char argument[192]; // The argument of the command

short int program_active = TRUE;

short int show_system_messages = FALSE; // Show message errors

short int lang = 1; /* Defines the language of the system through integer numbers, look below which languages each number represents:
1 - Sambahsa Mundialect
2 - General American English
3 - British English
4 - Brazilian Portuguese
5 - European Portuguese
6 - Mandarin
7 - French from France
8 - European Spanish
9 - Russian
10 - Modern Standard Arabic
11 - Esperanto
[...]
*/

#include "system_text.h" // Collection of basic system messages in different languages
#include "command.h" // Functions to make the program be able to receive and interpret commands
#include "small_functions.h" // A miscellaneous of small functions that don't require individual header files

#include "pronunciation.h"
#include "conjugation.h"

int main ()
{
	// Shows the name of the software
	logo ();
	printf ("-----------------------------------------------------------------------\n");
	printf("\nSB: Kwe tod est id prest ker yu neudte tod programme? In fall os");
	printf("\npositive antwehrd, plais use id command \"hehlp\" kay vide quosmed id");
	printf("\nprogramme wehrct ed woide de ids imkans ed also ids limitations.");
	printf("\nSEMPER inserte ia commandes in minuscule buksteivs ed aun ia alamats os");
	printf("\nmathal!");
	printf("\n");
	printf("\nEN: Is this the first time you use this program? In case of affirmative");
	printf("\nanswer, please use the command \"help\" to see how the programm works");
	printf("\nand know about its capacities and also its limitations");
	printf("\n* Use the command \"setlang en\" to change the program's language to ");
	printf("\n  English");
	printf("\nALWAYS insert the commands in lowercase letters and without quotation");
	printf("\nmarks!");
	printf("\n");
	printf("\nPT-BR: " CAPITAL_E_ACUTE " a primeira vez que voc" SMALL_E_CIRCUMFLEX " usa este programa? Em caso de resposta");
	printf("\nafirmativa, por favor use o comando \"ajuda\" para ver como programa");
	printf("\nfunciona e saber de suas capacidades e tamb" SMALL_E_ACUTE "m suas limita" SMALL_C_CEDILLA SMALL_O_TILDE "es.");
	printf("\n* Use o comando \"deflang pt\" para mudar o idioma do programa para ");
	printf("\n  portugu" SMALL_E_CIRCUMFLEX "s");
	printf("\nSEMPRE insira os comandos em letras min" SMALL_U_ACUTE "sculas e sem as aspas!");
	printf("\n");

	// MAIN LOOP
	while (program_active)
	{
		command_field (); // it makes appear the area where you type the commands

		#include "command_chain.h" // All possible commands

	}
	return 0; // Only to avoid the problem of "c warning: control reaches end of non-void function [-Wreturn-type]|"
}

