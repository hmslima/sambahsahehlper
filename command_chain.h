switch (command_number)
{
	case 0: // An invalid command
		command_not_found (lang);
	break;
	case 1: // Exit the program
		program_active = FALSE;
	break;
	case 2: // Help
		help (lang);
	break;
	case 3: // Makes the program show system messages, vety useful for who is programming
		if (!show_system_messages)
			show_system_messages = TRUE;
		else
			show_system_messages = FALSE;
	break;
	case 4: // Useful command for programmers. It tests a set of words in order to see if everything is working fine
		#include "testpnc.h"
	break;
	case 5: // Sow the list of words that were manually transcribed by the programmer
		#include "manual_transcription_list.h"
		printf("\n");
	break;
	case 6: // Show cases
		cases (lang);
	break;
	case 7: // Habilitates HTML, it's useful for output files
		if (!html_mode)
			html_mode = TRUE;
		else
			html_mode = FALSE;
	break;

	/* ************************************
	* Anything beyond 999 needs an argument
	************************************ */

	case 1000: // Change the system's language
		if  (checklang (argument))
		{
			if (strcmp(argument, "sb") == 0) lang = 1;
			else if (strcmp(argument, "en") == 0 || strcmp(argument, "en-us") == 0) lang = 2;
			else if (strcmp(argument, "pt") == 0 || strcmp(argument, "pt-br") == 0) lang = 4;
			else if (strcmp(argument, "fr") == 0 || strcmp(argument, "fr-eu") == 0) lang = 6;
			else if (strcmp(argument, "es") == 0 || strcmp(argument, "es-eu") == 0) lang = 8;
			else if (strcmp(argument, "eo") == 0) lang = 10;
		}
		else
			invalid_argument (lang);
	break;
	case 1001: // Uses the function that transcribes the given word to SPT
		if (strcmp(argument, "no_argument") == 0 || argument[0] == '\0') invalid_argument (lang);
		else printf("\n%s\n", pronunciation ());
	break;
	case 1002: // Conjugates the given word
		if (strcmp(argument, "no_argument") == 0 || argument[0] == '\0') invalid_argument (lang);
		else conjugation ();
	break;
	case 1003: // Uses the function that transcribes the words from the file "input_werd.txt" to SPT
        // Opens the input file
        input_file = fopen(argument, "r");

        // Creates the output file
        if (!html_mode)
        	output_file = fopen("output_sambahsa_pnc.txt", "w");
		else
			output_file = fopen("output_sambahsa_pnc.html", "w");

        if ((input_file = fopen(argument, "r")) == NULL)
        {
            printf ("\nERROR: It\'s was not possible to open the file!\n");
            break;
        }

        // Te name of the file is no more necessary
        memset(argument, '\0', strlen(argument));

		// For cleaning this variable
        line_number = 1;

        //Message for Windows users
        #ifdef _WIN32
        	fprintf (output_file, "%s", "<!-- The Windows version of this program cannot copy properly special characters from SPT (the vowels with diaresis and the section sign), but it is easy to fix, just use a text editor to find and replace all occurencies of wrong character for the correct ones -->\n\n");
        #endif

        // Writes the beginning of the HTML file
        if (html_mode)
        {
        	fprintf (output_file, "%s\n%s\n\t%s", "<!DOCTYPE html>", "<html>", "<head>");
			fprintf (output_file, "\n\t%s\n\t%s\n\n", "</head>", "<body>");
        }

        while (c != EOF)
		{
			// Read contents from file
			c = fgetc(input_file);

			if (c == '\n' && (strlen(argument) == 0))
			{
				// Do nothing special, it's just an empty line

				// Counts the lines
				if (line_number == 1)
					line_number = line_number + 1;
				else
					line_number++;
			}
			else if ((c == '\n') && (strlen(argument) > 0))
			{
				if (!html_mode)
					fprintf (output_file, "%s", argument);
				else
					fprintf (output_file, "<b>%s", argument);

				if (!html_mode)
					fprintf (output_file, " = ");
				else
					fprintf (output_file, " =</b> ");

				if (!html_mode)
					fprintf (output_file, "%s\n", pronunciation ());
				else
					fprintf (output_file, "%s<br>\n", pronunciation ());

				memset(argument, '\0', strlen(argument));

				// Counts the lines
				if (line_number == 1)
					line_number = line_number + 1;
				else
					line_number++;
			}
			else if (c == ' ')
			{
				printf("\nERROR: (line: %d) Sambahsa Helper doesn\'t support inputs with spaces, please remove this one\n", line_number);
				printf("Aborting proccess!\n");
				break;
			}
			else if ((c == '(') || (c == ')') || (c == '=') || (c == '-') || (c == '{') || (c == '}') || (c == '[') || (c == ']'))
			{
				printf("\nERROR: (line: %d) Sambahsa Helper doesn\'t support inputs with characters like \"(\", \"=\", etc, please remove this one\n", line_number);
				printf("Aborting proccess!\n");
				break;
			}
			else
			{
				if ((c != ' ') && (c != '\n') && (c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f' || c == 'g' || c == 'h' || c == 'i' || c == 'j' || c == 'l' || c == 'm' || c == 'n' || c == 'o' || c == 'p' || c == 'q' || c == 'r' || c == 's' || c == 't' || c == 'u' || c == 'v' || c == 'x' || c == 'y' || c == 'w' || c == 'z'))
					strncat(argument, &c, 1);
			}
		}

		// Writes the ending of the HTML file
        if (html_mode)
        {
        	fprintf (output_file, "\n\t%s\n%s", "</body>", "</html>");
        }

		// Closes the files
		fclose(input_file);
		fclose(output_file);

		// Closes the program because you cannot read the input file again
		printf("\nProcess terminated. Ending the program\n");
		program_active = FALSE;
	break;
}
