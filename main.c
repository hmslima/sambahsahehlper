#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#include "special_characters.h"

char command[256]; // Variable where all commands will be stored.
char command_name[64]; // The command itself
short int command_number;
char argument[192]; // The argument of the command .... 192 = 256 - 64

char c; // For reading files
char file_name[1024]; // For storing the filename
int line_number = 1; // Counts each new line

short int html_mode = FALSE;
short int htmlt_mode = FALSE;

short int program_active = TRUE;
short int dealing_with_file = FALSE;
short int using_command_cjgd = FALSE;

short int show_system_messages = FALSE; // Show message errors
short int is_testpnc_active = FALSE;

short int lang = 1; /* Defines the language of the system through integer numbers, look below which languages each number represents:
1 - Sambahsa Mundialect
2 - General American English
3 - British English
4 - Brazilian Portuguese
5 - European Portuguese
6 - French from France
7 - French from Africa
8 - European Spanish
9 - Latin American Spanish
10 - Esperanto
[...]
*/

FILE *input_file, *output_file;
char output_file_name[256];

#include "system_text.h" // Collection of basic system messages in different languages
#include "command.h" // Functions to make the program be able to receive and interpret commands
#include "small_functions.h" // A miscellaneous of small functions that don't require individual header files

#include "pronunciation.h"
#include "conjugation.h"
#include "cases.h"

int main ()
{
	// Shows the name of the software
	logo ();
	printf("\nSB: Kwe tod est id prest ker yu neudte tod programme? In fall os positive");
	printf("\nantwehrd, plais uset id commande \"hehlp\" kay vide quosmed id programme wehrct");
	printf("\ned woide de ids imkans ed also ids LIMITATIONS.");
	printf("\nInserte ia commandes aun alamats os mathal ed vergeihte insere werds samt");
	printf("\nprefixe au quodkwe type os composit werd.");
	printf("\n");
	printf("\nEN: Is this the first time you use this program? In case of affirmative answer,");
	printf("\nplease use the command \"help\" to see how the program works and to know about");
	printf("\nits capacities and also its LIMITATIONS");
	printf("\n* Use the command \"setlang en\" to change the program's language to English");
	printf("\nInsert the commands without quotation marks and avoid inserting words with");
	printf("\nprefix or any kind of compound word!");
	printf("\n");
	printf("\nES: Use el comando \"deflang es\" para cambiar el idioma del programa a espa" SMALL_N_TILDE "ol");
	printf("\nPT: Use o comando \"deflang pt\" para mudar o idioma do programa para portugu" SMALL_E_CIRCUMFLEX "s");
	printf("\nFR: Utilisez la commande \"deflang fr\" pour changer la langue en fran" SMALL_C_CEDILLA "ais");
	printf("\nEO: Uzu la ordonon \"deflang eo\" por " SMALL_S_CIRCUMFLEX "an" SMALL_G_CIRCUMFLEX "i la lingvon por esperanto");
	printf("\n");

	// MAIN LOOP
	while (program_active)
	{

		command_field (); // it makes appear the area where you type the commands

		#include "command_chain.h" // All possible commands

	}
	return 0; // Only to avoid the problem of "c warning: control reaches end of non-void function [-Wreturn-type]|"
}
