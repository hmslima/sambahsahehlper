#ifndef COMMAND_H
#define COMMAND_H

const char* insert_command();
const char* define_command_name (char command[256]);
short int define_command_number (char command_name[64]);
const char* define_argument (char command[256]);
void command_field (); // Use this function to enable the command field

#endif
