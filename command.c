// ############################################################
// ######################### COMMAND ##########################

#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

extern char command[256]; // Variable where all commands will be stored.
extern char command_name[64]; // The command itself
extern short int command_number;
extern char argument[192]; // The argument of the command

extern short int show_system_messages;

const char* insert_command() // It just receives what the user has typed and stores in the "command" variable
{
	char letter = 'x'; // Defining an initial value avoids an infinite loop
	memset(command,0,strlen(command)); // Cleans any previous commands
	short int counter = 0; // Sets the initial value of the counter
	// Draw the character "> " that will be put before any command
	printf ("\n");
	if (show_system_messages) printf ("#");
	printf ("> ");
	while (letter != '\n') // \n means the moment when the user types ENTER
	{
		letter = getchar();

		/***************************************************************************
		************* Here correct all inadequate letters
		***************************************************************************/
		if (letter == 'A') letter = 'a';
		else if (letter == 'B') letter = 'b';
		else if (letter == 'C') letter = 'c';
		else if (letter == 'D') letter = 'd';
		else if (letter == 'E') letter = 'e';
		else if (letter == 'F') letter = 'f';
		else if (letter == 'G') letter = 'g';
		else if (letter == 'H') letter = 'h';
		else if (letter == 'I') letter = 'i';
		else if (letter == 'J') letter = 'j';
		else if (letter == 'K') letter = 'k';
		else if (letter == 'L') letter = 'l';
		else if (letter == 'M') letter = 'm';
		else if (letter == 'N') letter = 'n';
		else if (letter == 'O') letter = 'o';
		else if (letter == 'P') letter = 'p';
		else if (letter == 'Q') letter = 'q';
		else if (letter == 'R') letter = 'r';
		else if (letter == 'S') letter = 's';
		else if (letter == 'T') letter = 't';
		else if (letter == 'U') letter = 'u';
		else if (letter == 'V') letter = 'v';
		else if (letter == 'W') letter = 'w';
		else if (letter == 'X') letter = 'x';
		else if (letter == 'Y') letter = 'y';
		else if (letter == 'Z') letter = 'z';


		if (letter != '\n') command[counter] = letter; // This condition avoids the character \n to be stored in the variable "command"
		counter++;
	}
	return command;
}
// ###########################
// Basically a command is divided in three parts: the commands itself, the options and the argument, the functions below help to separate these parts

// Separates the command name from the full command
const char* define_command_name (char command[256])
{
	memset(command_name,0,strlen(command_name)); // Cleans any previous values
	short int counter = 0;

	while (TRUE)
	{
		if (command[counter] == ' ' || command[counter] == '\0') break;

		command_name[counter] = command[counter];
		counter++;
	}
	return command_name;
}

// Converts the command's name to a number. Commands with arguments receive a number superior to 999
short int define_command_number (char command_name[64])
{
	short int command_number;
	if ((strcmp(command_name, "salg") == 0) || (strcmp(command_name, "exit") == 0) || (strcmp(command_name, "sair") == 0) || (strcmp(command_name, "salir") == 0) || (strcmp(command_name, "sortir") == 0) || (strcmp(command_name, "eliri") == 0)) command_number = 1;
	else if ((strcmp(command_name, "hehlp") == 0) || (strcmp(command_name, "help") == 0) || (strcmp(command_name, "ajuda") == 0) || (strcmp(command_name, "aide") == 0) || (strcmp(command_name, "helpo") == 0) || (strcmp(command_name, "ayuda") == 0)) command_number = 2;
	else if (strcmp(command_name, "log") == 0) command_number = 3;
	else if (strcmp(command_name, "testpnc") == 0) command_number = 4;
	else if ((strcmp(command_name, "pncliste") == 0) || (strcmp(command_name, "listepnc") == 0) || (strcmp(command_name, "pnclist") == 0) || (strcmp(command_name, "listpnc") == 0)) command_number = 5;
	else if ((strcmp(command_name, "falls") == 0) || (strcmp(command_name, "casos") == 0) || (strcmp(command_name, "cases") == 0) || (strcmp(command_name, "kazoj") == 0) || (strcmp(command_name, "cas") == 0)) command_number = 6;
	else if (strcmp(command_name, "html") == 0) command_number = 7;
	else if (strcmp(command_name, "htmlt") == 0) command_number = 8;
	else if ((strcmp(command_name, "deflang") == 0) || (strcmp(command_name, "setlang") == 0)) command_number = 1000;
	else if ((strcmp(command_name, "pnc") == 0) || (strcmp(command_name, "pronunce") == 0)) command_number = 1001;
	else if ((strcmp(command_name, "cjg") == 0) || (strcmp(command_name, "conjuge") == 0)) command_number = 1002;
	else if ((strcmp(command_name, "pncd") == 0) || (strcmp(command_name, "pronuncedatia") == 0)) command_number = 1003;
	else if ((strcmp(command_name, "cjgd") == 0) || (strcmp(command_name, "conjugedatia") == 0)) command_number = 1004;
	else command_number = 0; // 0 means invalid command

	return command_number;
}

// Separates the argument from the command
const char* define_argument (char command[256])
{
	memset(argument,0,strlen(argument)); // Cleans any previous values
	short int counter = 0; // Counter for the string "command"
	short int counter_argument = 0; // Counter for the string "argument"

	if (command_number < 1000) // All commands with number inferior to 1000 don't have arguments
		strcpy (argument, "no_argument");
	else // This condition is activated for valid commands that demand an argument
	{
		while (TRUE) // The objective here is to pass the command's name and reach the argument
		{
            if (command[counter] != ' ' && command[counter] != '\0') counter++; // If it's true, it means that there's a letter here, it will pass until find a space with no characters
            else if (command[counter] == '\0') // There is no valid argument
			{
				strcpy (argument, "no_argument");
				break;
			}
			else if (command[counter] == ' ') // There is a white space, add 1 to the counter and breaks the loop
			{
				counter++; // For putting the counter at the beginning of the argument
				break;
			}
			else  break;// Something went very wrong!
		}

		while (TRUE) // Here we read the argument
		{
			if (command[counter] == ' ' || command[counter] == '\0') break; // For when the NULL character be found when the loop restarts
			else
			{
				argument[counter_argument] = command[counter];
				counter++;
				counter_argument++;
			}
		}
	}
	return argument;
}

void command_field ()
{
	strcpy (command, insert_command()); // Copy returned value from the function "read_command()" to the variable "command"
	strcpy (command_name, define_command_name (command)); // Stores the value in the variable "command_name"
	command_number = define_command_number(command_name); // Stores the value in the variable "command_number"
	strcpy (argument, define_argument (command)); // Stores the value in the variable "argument"
}
