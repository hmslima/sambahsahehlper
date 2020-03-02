#ifndef SYSTEM_TEXT_H
#define SYSTEM_TEXT_H

// Name of the software

void logo ();

// Very basic system messages

void help (short int lang);
void command_not_found (short int lang);
void invalid_argument (short int lang);
void transcription_is_not_perfect (short int lang);

#endif
