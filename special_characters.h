/* **********************************************************

Just for future reference, here are the hexadecimal codes
for "special" characters:

á = 0xa0
Á = 0xb5

à = 0x85
À = 0xb7

â = 0x83
Â = 0xb6

é = 0x82
É = 0x90

è = 0x8a
È = 0xd4

ê = 0x88
Ê = 0xd2

í = 0xa1
Í = 0xd6

î = 0x8c
Î = 0xd7

ó = 0xa2
Ó = 0xe0

ô = 0x93
Ô = 0xe2

ú = 0xa3
Ú = 0xe9

ù = 0x97
Ù = 0xeb

û = 0x96
Û = 0xea

ã = 0xc6
Ã = 0xc7

õ = 0xe4
Õ = 0xe5

ë = 0x89
Ë = 0xd3

ï = 0x8b
Ï = 0xd8

ü = 0x81
Ü = 0x9a

ç = 0x87
Ç = 0x80

æ = 0x91
Æ = 0x92

ñ = 0xa4
Ñ = 0xa5

ß = 0xe1

ª = 0xa6
º = 0xa7
° = 0xf8
² = 0xfd
³ = 0xfc

¡ = 0xad
¿ = 0xa8

*********************************************************** */


#ifdef _WIN32

#define SMALL_A_ACUTE "\xa0"
#define CAPITAL_A_ACUTE "\xb5"

#define SMALL_A_GRAVE "\x85"

#define SMALL_E_ACUTE "\x82"
#define CAPITAL_E_ACUTE "\x90"

#define SMALL_E_GRAVE "\x8a"
#define CAPITAL_E_GRAVE "\xd4"

#define SMALL_A_CIRCUMFLEX "\x83"

#define SMALL_E_CIRCUMFLEX "\x88"
#define CAPITAL_E_CIRCUMFLEX "\xd2"

#define SMALL_I_CIRCUMFLEX "\x8c"

#define SMALL_O_CIRCUMFLEX "\x93"

#define SMALL_I_ACUTE "\xa1"
#define CAPITAL_I_ACUTE "\xd6"

#define SMALL_O_ACUTE "\xa2"

#define SMALL_U_ACUTE "\xa3"

#define SMALL_U_GRAVE "\x97"

#define SMALL_A_TILDE "\xc6"
#define CAPITAL_A_TILDE "\xc7"

#define SMALL_O_TILDE "\xe4"
#define CAPITAL_O_TILDE "\xe5"

#define SMALL_C_CEDILLA "\x87"
#define CAPITAL_C_CEDILLA "\x80"

#define SMALL_N_TILDE "\xa4"
#define CAPITAL_N_TILDE "\xa5"

#define SMALL_J_CIRCUMFLEX "jh"
#define CAPITAL_J_CIRCUMFLEX "JH"
#define SMALL_S_CIRCUMFLEX "sh"
#define CAPITAL_S_CIRCUMFLEX "SH"
#define SMALL_C_CIRCUMFLEX "ch"
#define CAPITAL_C_CIRCUMFLEX "CH"
#define SMALL_G_CIRCUMFLEX "gh"
#define CAPITAL_G_CIRCUMFLEX "GH"
#define SMALL_H_CIRCUMFLEX "hh"
#define CAPITAL_H_CIRCUMFLEX "HH"
#define SMALL_U_BREVE "u"
#define CAPITAL_U_BREVE "U"

#define SMALL_A_DIAERESIS '\x84'
#define CAPITAL_A_DIAERESIS '\x8e'
#define SMALL_E_DIAERESIS '\x89'
#define CAPITAL_E_DIAERESIS '\xd3'
#define SMALL_O_DIAERESIS '\x94'
#define CAPITAL_O_DIAERESIS '\x99'
#define SMALL_U_DIAERESIS '\x81'
#define CAPITAL_U_DIAERESIS '\x9a'

#define SECTION_SIGN '\xf5'

#define SMALL_A_DIAERESIS_IN_TEXT "\x84"
#define CAPITAL_A_DIAERESIS_IN_TEXT "\x8e"
#define SMALL_E_DIAERESIS_IN_TEXT "\x89"
#define CAPITAL_E_DIAERESIS_IN_TEXT "\xd3"
#define SMALL_O_DIAERESIS_IN_TEXT "\x94"
#define CAPITAL_O_DIAERESIS_IN_TEXT "\x99"
#define SMALL_U_DIAERESIS_IN_TEXT "\x81"
#define CAPITAL_U_DIAERESIS_IN_TEXT "\x9a"

#define SECTION_SIGN_IN_TEXT "\xf5"

#else

#define SMALL_A_ACUTE "\u00e1"
#define CAPITAL_A_ACUTE "\u00c1"

#define SMALL_A_GRAVE "\u00e0 "

#define SMALL_E_ACUTE "\u00e9"
#define CAPITAL_E_ACUTE "\u00c9"

#define SMALL_E_GRAVE "\u00e8"
#define CAPITAL_E_GRAVE "\u00c8"

#define SMALL_A_CIRCUMFLEX "\u00e2"

#define SMALL_E_CIRCUMFLEX "\u00ea"
#define CAPITAL_E_CIRCUMFLEX "\u00ca"

#define SMALL_I_CIRCUMFLEX "\u00ee"

#define SMALL_O_CIRCUMFLEX "\u00f4"

#define SMALL_I_ACUTE "\u00ed"
#define CAPITAL_I_ACUTE "\u00cd"

#define SMALL_O_ACUTE "\u00f3"

#define SMALL_U_ACUTE "\u00fA"

#define SMALL_U_GRAVE "\u00f9"

#define SMALL_A_TILDE "\u00e3"
#define CAPITAL_A_TILDE "\u00c3"

#define SMALL_O_TILDE "\u00f5"
#define CAPITAL_O_TILDE "\u00d5"

#define SMALL_C_CEDILLA "\u00e7"
#define CAPITAL_C_CEDILLA "\u00c7"

#define SMALL_N_TILDE "\u00f1"
#define CAPITAL_N_TILDE "\u00d1"

#define SMALL_J_CIRCUMFLEX "\u0135"
#define CAPITAL_J_CIRCUMFLEX "\u0134"
#define SMALL_S_CIRCUMFLEX "\u015d"
#define CAPITAL_S_CIRCUMFLEX "\u015c"
#define SMALL_C_CIRCUMFLEX "\u0109"
#define CAPITAL_C_CIRCUMFLEX "\u0108"
#define SMALL_G_CIRCUMFLEX "\u011d"
#define CAPITAL_G_CIRCUMFLEX "\u011c"
#define SMALL_H_CIRCUMFLEX "\u0125"
#define CAPITAL_H_CIRCUMFLEX "\u0124"
#define SMALL_U_BREVE "\u016d"
#define CAPITAL_U_BREVE "\u016c"

#define SMALL_A_DIAERESIS "\u00e4"
#define CAPITAL_A_DIAERESIS "\u00c4"
#define SMALL_E_DIAERESIS "\u00eb"
#define CAPITAL_E_DIAERESIS "\u00cb"
#define SMALL_O_DIAERESIS "\u00f6"
#define CAPITAL_O_DIAERESIS "\u00d6"
#define SMALL_U_DIAERESIS "\u00fc"
#define CAPITAL_U_DIAERESIS "\u00dc"

#define SECTION_SIGN "\u00a7"

#define SMALL_A_DIAERESIS_IN_TEXT "\u00e4"
#define CAPITAL_A_DIAERESIS_IN_TEXT "\u00c4"
#define SMALL_E_DIAERESIS_IN_TEXT "\u00eb"
#define CAPITAL_E_DIAERESIS_IN_TEXT "\u00cb"
#define SMALL_O_DIAERESIS_IN_TEXT "\u00f6"
#define CAPITAL_O_DIAERESIS_IN_TEXT "\u00d6"
#define SMALL_U_DIAERESIS_IN_TEXT "\u00fc"
#define CAPITAL_U_DIAERESIS_IN_TEXT "\u00dc"

#define SECTION_SIGN_IN_TEXT "\u00a7"

#endif

