#include <stdio.h>
#include <string.h>

#include "special_characters.h"

#include "system_text.h"

#define TRUE 1
#define FALSE 0

extern short int lang;

void cases (short int lang)
{
	printf ("\n-------------------------------------------------------------------------------");

	if (lang == 2) printf("\nDECLENSION CASES");
	else if (lang == 4) printf("\nCASOS DE DECLINA" CAPITAL_C_CEDILLA CAPITAL_A_TILDE "O");
	else if (lang == 6) printf("\nCAS DE D" CAPITAL_E_ACUTE "CLINAISON");
	else if (lang == 8 || lang == 9) printf("\nCASOS DE DECLINACI" CAPITAL_O_ACUTE "N");
	else if (lang == 10) printf("\nDEKLINI" CAPITAL_G_CIRCUMFLEX "AJ KAZOJ");
	else printf("\nDECLINATION FALLS");

	printf ("\n-------------------------------------------------------------------------------\n");

	if (lang == 2) printf("NOMINATIVE                                 | ");
	else if (lang == 4) printf("NOMINATIVO                                 | ");
	else if (lang == 6) printf("NOMINATIVE                                 | ");
	else if (lang == 8 || lang == 9) printf("NOMINATIVO                                 | ");
	else if (lang == 10) printf("NOMINATIVO                                 | ");
	// else printf("NOMINATIVE                                 | ");
	else printf("NOMINATIVE\t\t\t\t  | ");

	if (lang == 2) printf("ACCUSATIVE | ");
	else if (lang == 4) printf("ACUSATIVO  | ");
	else if (lang == 6) printf("ACCUSATEUR | ");
	else if (lang == 8 || lang == 9) printf("ACUSATIVO  | ");
	else if (lang == 10) printf("ACUSATIVO  | ");
	else printf("ACCUSATIVE | ");

	if (lang == 2) printf("DATIVE    | ");
	else if (lang == 4) printf("DATIVO    | ");
	else if (lang == 6) printf("DATIVE    | ");
	else if (lang == 8 || lang == 9) printf("DATIVO    | ");
	else if (lang == 10) printf("DATIVO    | ");
	else printf("DATIVE    | ");

	if (lang == 2) printf("GENITIVE");
	else if (lang == 4) printf("GENITIVO");
	else if (lang == 6) printf("GENITIVE");
	else if (lang == 8 || lang == 9) printf("GENITIVO");
	else if (lang == 10) printf("GENITIVO");
	else printf("GENITIVE");

	printf ("\n-------------------------------------------------------------------------------\n");

	/***************************************************************************
	************* EGO / IO
	***************************************************************************/

	printf ("ego / io");
	if (lang == 2) printf(" = I  ");
	else if (lang == 4) printf(" = eu ");
	else if (lang == 6) printf(" = je ");
	else if (lang == 8 || lang == 9) printf(" = yo ");
	else if (lang == 10) printf(" = mi ");

	// White space until the next column
	if (lang == 1) printf ("\t\t\t\t  | ");
	else printf ("\t\t\t\t   | ");

	printf ("me         | ");
	printf ("mi        | ");
	printf (" ");

	/***************************************************************************
	************* TU
	***************************************************************************/

	printf ("\n");
	printf ("tu");
	if (lang == 2) printf(" = you");
	else if (lang == 4) printf(" = tu ");
	else if (lang == 6) printf(" = toi");
	else if (lang == 8 || lang == 9) printf(" = tu ");
	else if (lang == 10) printf(" = vi ");

	// White space until the next column
	if (lang == 1) printf ("\t\t\t\t\t  | ");
	else printf ("\t\t\t\t   | ");

	printf ("te         | ");
	printf ("ti        | ");
	printf (" ");

	/***************************************************************************
	************* IS
	***************************************************************************/

	printf ("\n");
	printf ("is");
	if (lang == 2) printf(" = he ");
	else if (lang == 4) printf(" = ele");
	else if (lang == 6) printf(" = il ");
	else if (lang == 8 || lang == 9) printf(" = tu ");
	else if (lang == 10) printf(" = li ");

	// White space until the next column
	if (lang == 1) printf ("\t\t\t\t\t  | ");
	else printf ("\t\t\t\t   | ");

	printf ("iom        | ");
	printf ("ei        | ");
	printf ("ios");

	/***************************************************************************
	************* IA
	***************************************************************************/

	printf ("\n");
	printf ("ia");
	if (lang == 2) printf(" = she");
	else if (lang == 4) printf(" = ela");
	else if (lang == 6) printf(" = elle");
	else if (lang == 8 || lang == 9) printf(" = ella");
	else if (lang == 10) printf(" = " SMALL_S_CIRCUMFLEX "i ");

	// White space until the next column
	if (lang == 1) printf ("\t\t\t\t\t  | ");
	else printf ("\t\t\t\t   | ");

	printf ("iam        | ");
	printf ("ay        | ");
	printf ("ias");

	/***************************************************************************
	************* ID
	***************************************************************************/

	printf ("\n");
	printf ("id");
	if (lang == 2)
	{
		printf(" = it ");
		printf ("\t\t\t\t   | ");
	}
	else if (lang == 4)
	{
		printf(" = ele/ela (neutro)");
		printf ("\t\t\t   | ");
	}
	else if (lang == 6)
	{
		printf(" = le / " SMALL_C_CEDILLA "a ");
		printf ("\t\t\t\t   | ");
	}
	else if (lang == 8 || lang == 9)
	{
		printf(" = el, lo, " SMALL_E_ACUTE "l ");
		printf ("\t\t\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = " SMALL_G_CIRCUMFLEX "i ");
		printf ("\t\t\t\t   | ");
	}

	// White space until the next column
	if (lang == 1) printf ("\t\t\t\t\t  | ");

	printf ("id         | ");
	printf ("ei        | ");
	printf ("ios");

	/***************************************************************************
	************* EL
	***************************************************************************/

	printf ("\n");
	printf ("el");
	if (lang == 2)
	{
		printf(" = he / she");
		printf ("\t\t\t\t   | ");
	}
	else if (lang == 4)
	{
		printf(" = ele / ela");
		printf ("\t\t\t\t   | ");
	}
	else if (lang == 6)
	{
		printf(" = il, le ");
		printf ("\t\t\t\t   | ");
	}
	else if (lang == 8 || lang == 9)
	{
		printf(" = el, lo, la, él, ella ");
		printf ("\t\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = li/" SMALL_S_CIRCUMFLEX "i ");
		printf ("\t\t\t\t   | ");
	}

	// White space until the next column
	if (lang == 1) printf ("\t\t\t\t\t  | ");

	printf ("el         | ");
	printf ("al        | ");
	printf ("al");

	/***************************************************************************
	************* WEY
	***************************************************************************/

	printf ("\n");
	printf ("wey");
	if (lang == 2) printf(" = we");
	else if (lang == 4) printf(" = n" SMALL_O_ACUTE "s");
	else if (lang == 6) printf(" = nous");
	else if (lang == 8 || lang == 9) printf(" = nosotros");
	else if (lang == 10) printf(" = ni ");

	// White space until the next column
	if (lang == 1) printf ("\t\t\t\t\t  | ");
	else printf ("\t\t\t\t   | ");

	printf ("nos        | ");
	printf ("nos       | ");
	printf (" ");

	/***************************************************************************
	************* YU
	***************************************************************************/

	printf ("\n");
	printf ("yu");
	if (lang == 2) printf(" = you");
	else if (lang == 4) printf(" = v" SMALL_O_ACUTE "s");
	else if (lang == 6) printf(" = vous");
	else if (lang == 8 || lang == 9) printf(" = vosotros");
	else if (lang == 10) printf(" = vi ");

	// White space until the next column
	if (lang == 1) printf ("\t\t\t\t\t  | ");
	else printf ("\t\t\t\t   | ");

	printf ("vos        | ");
	printf ("vos       | ");
	printf (" ");

	/***************************************************************************
	************* IES
	***************************************************************************/

	printf ("\n");
	printf ("ies");
	if (lang == 2)
	{
		printf(" = they (masculine)");
		printf ("\t\t\t   | ");
	}
	else if (lang == 4)
	{
		printf(" = eles (masculino)");
		printf ("\t\t\t   | ");
	}
	else if (lang == 6)
	{
		printf(" = les (masculin)");
		printf ("\t\t\t   | ");
	}
	else if (lang == 8 || lang == 9)
	{
		printf(" = los, ellos (masculino) ");
		printf ("\t\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = ili (vira) ");
		printf ("\t\t\t   | ");
	}

	// White space until the next column
	if (lang == 1) printf ("\t\t\t\t\t  | ");

	printf ("iens       | ");
	printf ("ibs       | ");
	printf ("iom");

	/***************************************************************************
	************* IAS
	***************************************************************************/

	printf ("\n");
	printf ("ias");
	if (lang == 2)
	{
		printf(" = they (feminine)");
		printf ("\t\t\t   | ");
	}
	else if (lang == 4)
	{
		printf(" = elas");
		printf ("\t\t\t\t   | ");
	}
	else if (lang == 6)
	{
		printf(" = les / elles");
		printf ("\t\t\t   | ");
	}
	else if (lang == 8 || lang == 9)
	{
		printf(" = las (feminino) ");
		printf ("\t\t\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = ili (virina) ");
		printf ("\t\t\t   | ");
	}

	// White space until the next column
	if (lang == 1) printf ("\t\t\t\t\t  | ");

	printf ("ians       | ");
	printf ("iabs      | ");
	printf ("iam");

	/***************************************************************************
	************* IA (PLURAL)
	***************************************************************************/

	printf ("\n");
	printf ("ia");
	if (lang == 2)
	{
		printf(" = they (neutral)");
		printf ("\t\t\t   | ");
	}
	else if (lang == 4)
	{
		printf(" = eles (neutro)");
		printf ("\t\t\t   | ");
	}
	else if (lang == 6)
	{
		printf(" = ils, eux, les (neutre) ");
		printf ("\t\t   | ");
	}
	else if (lang == 8 || lang == 9)
	{
		printf(" = los, ellos (neutro) ");
		printf ("\t\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = ili (ne" SMALL_U_BREVE "tra) ");
		printf ("\t\t\t   | ");
	}

	// White space until the next column
	if (lang == 1) printf ("\t\t\t\t\t  | ");

	printf ("el         | ");
	printf ("al        | ");
	printf ("al");

	/***************************************************************************
	************* I
	***************************************************************************/

	printf ("\n");
	printf ("i");
	if (lang == 2)
	{
		printf(" = they (undetermined)");
		printf ("\t\t\t   | ");
	}
	else if (lang == 4)
	{
		printf(" = eles (indeterminado)");
		printf ("\t\t   | ");
	}
	else if (lang == 6)
	{
		printf(" = ils, eux, les (ind" SMALL_E_ACUTE "termin" SMALL_E_ACUTE ")");
		printf ("\t\t   | ");
	}
	else if (lang == 8 || lang == 9)
	{
		printf(" = los, ellos (indeterminado) ");
		printf ("\t\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = ili (nedeterminita) ");
		printf ("\t\t   | ");
	}

	// White space until the next column
	if (lang == 1) printf ("\t\t\t\t\t  | ");

	printf ("i          | ");
	printf ("im        | ");
	printf ("im");

	/***************************************************************************
	************* SO
	***************************************************************************/

	printf ("\n");
	printf ("so");
	if (lang == 2)
	{
		printf(" = this (masculine)");
		printf ("\t\t\t   | ");
	}
	else if (lang == 4)
	{
		printf(" = esse, este");
		printf ("\t\t\t\t   | ");
	}
	else if (lang == 6)
	{
		printf(" = ce (lui-ci/l" SMALL_A_GRAVE ")");
		printf ("\t\t\t   | ");
	}
	else if (lang == 8 || lang == 9)
	{
		printf(" = este ");
		printf ("\t\t\t\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = " SMALL_C_CIRCUMFLEX "i tiu (vira) ");
		printf ("\t\t\t   | ");
	}

	// White space until the next column
	if (lang == 1) printf ("\t\t\t\t\t  | ");

	printf ("tom        | ");
	printf ("tei       | ");
	printf ("tos");

	/***************************************************************************
	************* TOY
	***************************************************************************/

	printf ("\n");
	printf ("toy");
	if (lang == 2)
	{
		printf(" = these (masculine)");
		printf ("\t\t\t   | ");
	}
	else if (lang == 4)
	{
		printf(" = esses, estes");
		printf ("\t\t\t   | ");
	}
	else if (lang == 6)
	{
		printf(" = ces/ceux-l" SMALL_A_GRAVE "");
		printf ("\t\t\t   | ");
	}
	else if (lang == 8 || lang == 9)
	{
		printf(" = estes ");
		printf ("\t\t\t\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = " SMALL_C_CIRCUMFLEX "i tiuj (vira) ");
		printf ("\t\t\t   | ");
	}

	// White space until the next column
	if (lang == 1) printf ("\t\t\t\t\t  | ");

	printf ("tens       | ");
	printf ("tibs      | ");
	printf ("tom");

	/***************************************************************************
	************* SA
	***************************************************************************/

	printf ("\n");
	printf ("sa");
	if (lang == 2)
	{
		printf(" = this (feminine)");
		printf ("\t\t\t   | ");
	}
	else if (lang == 4)
	{
		printf(" = essa, esta");
		printf ("\t\t\t\t   | ");
	}
	else if (lang == 6)
	{
		printf(" = celle");
		printf ("\t\t\t\t   | ");
	}
	else if (lang == 8 || lang == 9)
	{
		printf(" = esta");
		printf ("\t\t\t\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = " SMALL_C_CIRCUMFLEX "i tiu (virina) ");
		printf ("\t\t\t   | ");
	}

	// White space until the next column
	if (lang == 1) printf ("\t\t\t\t\t  | ");

	printf ("tam        | ");
	printf ("tay       | ");
	printf ("tas");

	/***************************************************************************
	************* TAS
	***************************************************************************/

	printf ("\n");
	printf ("tas");
	if (lang == 2)
	{
		printf(" = these (feminine)");
		printf ("\t\t\t   | ");
	}
	else if (lang == 4)
	{
		printf(" = essas, estas");
		printf ("\t\t\t   | ");
	}
	else if (lang == 6)
	{
		printf(" = de cette/celle-l" SMALL_A_GRAVE " - ces/celles-l" SMALL_A_GRAVE "");
		printf ("\t   | ");
	}
	else if (lang == 8 || lang == 9)
	{
		printf(" = estas ");
		printf ("\t\t\t\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = " SMALL_C_CIRCUMFLEX "i tiuj (virina)");
		printf ("\t\t\t   | ");
	}

	// White space until the next column
	if (lang == 1) printf ("\t\t\t\t\t  | ");

	printf ("tans       | ");
	printf ("tabs      | ");
	printf ("tam");

	/***************************************************************************
	************* TOD
	***************************************************************************/

	printf ("\n");
	printf ("tod");
	if (lang == 2)
	{
		printf(" = this (neutral)");
		printf ("\t\t\t   | ");
	}
	else if (lang == 4)
	{
		printf(" = esse, este (neutro)");
		printf ("\t\t   | ");
	}
	else if (lang == 6)
	{
		printf(" = ce, celui-l" SMALL_A_GRAVE " (neutre)");
		printf ("\t\t   | ");
	}
	else if (lang == 8 || lang == 9)
	{
		printf(" = este (neutro) ");
		printf ("\t\t\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = " SMALL_C_CIRCUMFLEX "i tiu (ne" SMALL_U_BREVE "tra)");
		printf ("\t\t\t   | ");
	}

	// White space until the next column
	if (lang == 1) printf ("\t\t\t\t\t  | ");

	printf ("tod        | ");
	printf ("tei       | ");
	printf ("tos");

	/***************************************************************************
	************* TA
	***************************************************************************/

	printf ("\n");
	printf ("ta");
	if (lang == 2)
	{
		printf(" = these (neutral)");
		printf ("\t\t\t   | ");
	}
	else if (lang == 4)
	{
		printf(" = esses, estes (neutro)");
		printf ("\t\t   | ");
	}
	else if (lang == 6)
	{
		printf(" = ces, ceux-ci (neutre)");
		printf ("\t\t   | ");
	}
	else if (lang == 8 || lang == 9)
	{
		printf(" = estes (neutro) ");
		printf ("\t\t\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = " SMALL_C_CIRCUMFLEX "i tiuj (ne" SMALL_U_BREVE "tra)");
		printf ("\t\t\t   | ");
	}

	// White space until the next column
	if (lang == 1) printf ("\t\t\t\t\t  | ");

	printf ("ta         | ");
	printf ("tibs      | ");
	printf ("tom");

	/***************************************************************************
	************* TEL
	***************************************************************************/

	printf ("\n");
	printf ("tel");
	if (lang == 2)
	{
		printf(" = this (undetermined)");
		printf ("\t\t\t   | ");
	}
	else if (lang == 4)
	{
		printf(" = esse, este (indeterminado)");
		printf ("\t   | ");
	}
	else if (lang == 6)
	{
		printf(" = ce, celui-l" SMALL_A_GRAVE " (ind" SMALL_E_ACUTE "termin" SMALL_E_ACUTE ")");
		printf ("\t   | ");
	}
	else if (lang == 8 || lang == 9)
	{
		printf(" = este (indeterminado)");
		printf ("\t\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = " SMALL_C_CIRCUMFLEX "i tiu (nedeterminita)");
		printf ("\t\t   | ");
	}

	// White space until the next column
	if (lang == 1) printf ("\t\t\t\t\t  | ");

	printf ("tel        | ");
	printf ("tal       | ");
	printf ("tal");

	/***************************************************************************
	************* TI
	***************************************************************************/

	printf ("\n");
	printf ("ti");
	if (lang == 2)
	{
		printf(" = these (undetermined)");
		printf ("\t\t\t   | ");
	}
	else if (lang == 4)
	{
		printf(" = esses, estes (indeterminado)");
		printf ("\t   | ");
	}
	else if (lang == 6)
	{
		printf(" = ces, ceux-ci (ind" SMALL_E_ACUTE "termin" SMALL_E_ACUTE ")");
		printf ("\t\t   | ");
	}
	else if (lang == 8 || lang == 9)
	{
		printf(" = estes (indeterminado)");
		printf ("\t\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = " SMALL_C_CIRCUMFLEX "i tiuj (nedeterminita)");
		printf ("\t\t   | ");
	}

	// White space until the next column
	if (lang == 1) printf ("\t\t\t\t\t  | ");

	printf ("ti         | ");
	printf ("tim       | ");
	printf ("tim");

	/***************************************************************************
	****************************************************************************
	***************************************************************************/

	printf ("\n");

	if (lang == 2)
	{
		printf ("\n# THIS IS A LONG TABLE, PERHAPS YOU WILL HAVE TO ROLL UP THIS WINDOW IN YOUR");
		printf ("\nTERMINAL EMULATOR (OR MAXIMISE THIS WINDOW) IN ORDER TO SEE THE BEGINNING");
		printf ("\nOF THIS TABLE");
	}
	else if (lang == 4)
	{
		printf ("\n# ESTA TABELA " CAPITAL_E_ACUTE " LONGA, TALVEZ VOC" CAPITAL_E_CIRCUMFLEX " TENHA QUE ROLAR ESTA JANELA PARA CIMA NO SEU");
		printf ("\nEMULADOR DE TERMINAL (OU MAXIMIZAR ESTA JANELA) PARA VER O IN" CAPITAL_I_ACUTE "CIO DESTA TABELA");
	}
	else if (lang == 6)
	{
		printf ("\n# CE TABLEAU EST ASSEZ LONG, PEUT-" CAPITAL_E_CIRCUMFLEX "TRE FAUT-IL QUE VOUS REMONTIEZ VERS LE HAUT");
		printf ("\nPOUR EN LIRE LE DEBUT");
	}
	else if (lang == 8 || lang == 9)
	{
		printf("\nESTA TABLA ES LARGA, PUEDE TENER QUE RODAR ESTA VENTANA EN SU EMULADOR TERMINAL");
		printf("\n(O MAXIMIZAR ESTA VENTANA) PARA VER EL COMIENZO DE ESTA TABLA");
	}
	else if (lang == 10)
	{
		printf ("\n# " CAPITAL_C_CIRCUMFLEX "I TIO ESTAS LONGA TABELO, EBLE VI BEZONOS RULI SUPER " CAPITAL_C_CIRCUMFLEX "I TERMINALFENESTRON");
		printf ("\n(A" CAPITAL_U_BREVE " MAKSIMUMIGI " CAPITAL_C_CIRCUMFLEX "I TERMINALFENESTRON) POR VIDI LA KOMENCON DE " CAPITAL_C_CIRCUMFLEX "I TIU TABELO");
	}
	else
	{
		printf ("\n# TOD EST UN LONG TABELL, KAD YU TEHRPSIETE ROLLE UB TOD FENSTER IN VIES");
		printf ("\nTERMINAL EMULATOR (WE MAXIMISE TOD FENSTER) KAY VIDE ID INKAP TOS TABELL.");
	}

	printf ("\n");

}
