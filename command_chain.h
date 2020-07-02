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
	case 8: // Habilitates HTML, it's useful for output files
		if (!html_mode)
		{
			htmlt_mode = TRUE;
			html_mode = TRUE;
		}
		else
		{
			htmlt_mode = FALSE;
			html_mode = FALSE;
		}
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
	case 1003: // Uses the function that transcribes the words from a file to SPT
        // Opens the input file
        input_file = fopen(argument, "r");

        // Creates the output file
        if (!html_mode)
        	output_file = fopen("output_sambahsa_pnc.txt", "w");
		else
			output_file = fopen("output_sambahsa_pnc.html", "w");

        if ((input_file = fopen(argument, "r")) == NULL)
        {
            printf ("\nERROR: It was not possible to open the file! Check whether you wrote the name\n");
            printf ("of the file correctly or you have permission to open files from this folder\n");
            printf ("Did you remember of informing the file\'s extension?\n");
            break;
        }

        // Te name of the file is no more necessary
        memset(argument, '\0', strlen(argument));

		// For cleaning this variable
        line_number = 1;

        // Writes the beginning of the HTML file
        if (html_mode && !htmlt_mode)
        {
        	fprintf (output_file, "%s\n%s\n\t%s", "<!DOCTYPE html>", "<html>", "<head>");
			fprintf (output_file, "\n\t%s\n\t%s\n\n", "</head>", "<body>");
        }

        //Message for Windows users
        #ifdef _WIN32
        	if (!html_mode) fprintf (output_file, "%s", "The Windows version of this program cannot copy properly special characters from SPT (the vowels with diaresis and the section sign), but it is easy to fix, just use a text editor to find and replace all occurencies of wrong character for the correct ones\n\n");
        	else fprintf (output_file, "%s", "The Windows version of this program cannot copy properly special characters from SPT (the vowels with diaresis(like \"&#235;\" and \"&#220;\" ) and the section sign (\"&#167;\") ), but it is easy to fix, just use a text editor to find and replace all occurencies of wrong character for the correct ones<br><br>");
        #endif

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
			else if ((c == '\n' || c == EOF) && (strlen(argument) > 0))
			{
				if (!html_mode)
					fprintf (output_file, "%s", argument);
				else
				{
					if (!htmlt_mode) fprintf (output_file, "<b>%s", argument);
					else fprintf (output_file, "%s", argument);
				}


				if (!html_mode)
					fprintf (output_file, " = ");
				else
				{
					if (!htmlt_mode) fprintf (output_file, " =</b> ");
					else fprintf (output_file, "\t&gt;\t");
				}

				remove_capital_letters (argument);

				if (!html_mode)
					fprintf (output_file, "{%s}\n", pronunciation ());
				else
				{
					if (!htmlt_mode) fprintf (output_file, "{%s}<br>\n", pronunciation ());
					else fprintf (output_file, "{%s}\n", pronunciation ());
				}

				memset(argument, '\0', strlen(argument));

				// Counts the lines
				if (line_number == 1)
					line_number = line_number + 1;
				else
					line_number++;
			}
			else if (c == ' ')
			{
				printf("\nERROR: (line: %d) Sambahsa Helper doesn\'t support inputs with spaces,\nplease remove this one.\n", line_number);
				printf("\nAborting proccess!\n");
				printf("\nPress Any Key to Continue\n\n");
				getchar();
				break;
			}
			else if ((c == '(') || (c == ')') || (c == '=') || (c == '{') || (c == '}') || (c == '[') || (c == ']'))
			{
				printf("\nERROR: (line: %d) Sambahsa Helper doesn\'t support inputs with characters\nlike \"}\", \"=\", \"(\", etc. Please remove this one.\n", line_number);
				printf("\nAborting proccess!\n");
				printf("\nPress Any Key to Continue\n\n");
				getchar();
				break;
			}
			else
			{
				if ((c != ' ') && (c != '\n') && (c == 'a' || c == 'A' || c == 'b' || c == 'B' || c == 'c' || c == 'C' || c == 'd' || c == 'D' || c == 'e' || c == 'E' || c == 'f' || c == 'F' || c == 'g' || c == 'G' || c == 'h' || c == 'H' || c == 'i' || c == 'I' || c == 'j' || c == 'J' || c == 'k' || c == 'K' || c == 'l' || c == 'L' || c == 'm' || c == 'M' || c == 'n' || c == 'N' || c == 'o' || c == 'O' || c == 'p' || c == 'P' || c == 'q' || c == 'Q' || c == 'r' || c == 'R' || c == 's' || c == 'S' || c == 't' || c == 'T' || c == 'u' || c == 'U' || c == 'v' || c == 'V' || c == 'x' || c == 'X' || c == 'y' || c == 'Y' || c == 'w' || c == 'W' || c == 'z' || c == 'Z' || c == '-' || c == '\''))
					strncat(argument, &c, 1);
			}
		}

		// Writes the ending of the HTML file
        if (html_mode && !htmlt_mode)
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
	case 1004: // Uses the function that transcribes the words from a file to SPT
		dealing_with_file = TRUE;

		// Opens the input file
        input_file = fopen(argument, "r");

        // Creates the output file
        if (!html_mode)
        	output_file = fopen("output_sambahsa_cjg.txt", "w");
		else
			output_file = fopen("output_sambahsa_cjg.html", "w");

        if ((input_file = fopen(argument, "r")) == NULL)
        {
            printf ("\nERROR: It was not possible to open the file! Check whether you wrote the name\n");
            printf ("of the file correctly or you have permission to open files from this folder\n");
            printf ("Did you remember of informing the file\'s extension?\n");
            break;
        }

		// Te name of the file is no more necessary
		strcpy(file_name, argument);
        memset(argument, '\0', strlen(argument));

        // For cleaning this variable
        line_number = 1;

        // Writes the beginning of the HTML file
        if (html_mode && !htmlt_mode)
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
			else if ((c == '\n' || c == EOF) && (strlen(argument) > 0))
			{
				// Counts the lines
				if (line_number == 1)
					line_number = line_number + 1;
				else
					line_number++;

				//Calls the function
				conjugation ();
			}
			else if (c == ' ')
			{
				printf("\nERROR: (line: %d) Sambahsa Helper doesn\'t support inputs with spaces,\nplease remove this one.\n", line_number);
				printf("\nAborting proccess!\n");
				printf("\nPress Any Key to Continue\n\n");
				getchar();
				break;
			}
			else if ((c == '(') || (c == ')') || (c == '=') || (c == '-') || (c == '{') || (c == '}') || (c == '[') || (c == ']'))
			{
				printf("\nERROR: (line: %d) Sambahsa Helper doesn\'t support inputs with characters\nlike \"}\", \"=\", \"(\", \"-\", etc. Please remove this one.\n", line_number);
				printf("\nAborting proccess!\n");
				printf("\nPress Any Key to Continue\n\n");
				getchar();
				break;
			}
			else
			{
				if ((c != ' ') && (c != '\n') && (c == 'a' || c == 'A' || c == 'b' || c == 'B' || c == 'c' || c == 'C' || c == 'd' || c == 'D' || c == 'e' || c == 'E' || c == 'f' || c == 'F' || c == 'g' || c == 'G' || c == 'h' || c == 'H' || c == 'i' || c == 'I' || c == 'j' || c == 'J' || c == 'k' || c == 'K' || c == 'l' || c == 'L' || c == 'm' || c == 'M' || c == 'n' || c == 'N' || c == 'o' || c == 'O' || c == 'p' || c == 'P' || c == 'q' || c == 'Q' || c == 'r' || c == 'R' || c == 's' || c == 'S' || c == 't' || c == 'T' || c == 'u' || c == 'U' || c == 'v' || c == 'V' || c == 'x' || c == 'X' || c == 'y' || c == 'Y' || c == 'w' || c == 'W' || c == 'z' || c == 'Z'))
					strncat(argument, &c, 1);
			}
		}

		// Writes the ending of the HTML file
        if (html_mode && !htmlt_mode)
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
