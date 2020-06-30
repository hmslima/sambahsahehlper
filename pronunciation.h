#ifndef PRONUNCIATION_H
#define PRONUNCIATION_H

short int is_it_vowel (char ch);
short int is_it_vowel_without_some_letters (char ch);
short int is_it_consonant (char ch);
short int is_it_consonant_without_some_letters (char ch);
short int is_it_vowel_without_w (char ch);
short int is_it_vowel_without_wy (char ch);
short int is_there_something_here (char ch);
short int is_it_simple_consonant (char ch);
short int is_there_more_than_one_vowel ();
short int is_there_more_than_one_vowel_ignoring_last_e ();
short int is_there_only_one_vowel_ignoring_last_diaeresis_e ();
const char* pronunciation ();

#endif
