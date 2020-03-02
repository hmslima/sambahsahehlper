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

	/* ************************************
	* Anything beyond 999 needs an argument
	************************************ */

	case 1000: // Change the system's language
		if  (checklang (argument))
		{
			if (strcmp(argument, "sb") == 0) lang = 1;
			else if (strcmp(argument, "en") == 0 || strcmp(argument, "en-us") == 0) lang = 2;
			else if (strcmp(argument, "pt") == 0 || strcmp(argument, "pt-br") == 0) lang = 4;
		}
		else
			invalid_argument (lang);
	break;
	case 1001:
		pronunciation ();
	break;
	case 1002:
		conjugation ();
	break;
}
