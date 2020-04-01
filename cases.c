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
	else if (lang == 6) printf("NOMINATIF                                  | ");
	else if (lang == 8 || lang == 9) printf("NOMINATIVO                                 | ");
	else if (lang == 10) printf("NOMINATIVO                                 | ");
	else printf("NOMINATIVE\t\t\t\t  | ");

	if (lang == 2) printf("ACCUSATIVE | ");
	else if (lang == 4) printf("ACUSATIVO  | ");
	else if (lang == 6) printf("ACCUSATIF  | ");
	else if (lang == 8 || lang == 9) printf("ACUSATIVO  | ");
	else if (lang == 10) printf("AKUZATIVO  | ");
	else printf("ACCUSATIVE | ");

	if (lang == 2) printf("DATIVE    | ");
	else if (lang == 4) printf("DATIVO    | ");
	else if (lang == 6) printf("DATIF     | ");
	else if (lang == 8 || lang == 9) printf("DATIVO    | ");
	else if (lang == 10) printf("DATIVO    | ");
	else printf("DATIVE    | ");

	if (lang == 2) printf("GENITIVE");
	else if (lang == 4) printf("GENITIVO");
	else if (lang == 6) printf("G" CAPITAL_E_ACUTE "NITIF");
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
	printf ("tib       | ");
	printf (" ");

	/***************************************************************************
	************* IS
	***************************************************************************/

	printf ("\n");
	printf ("is");
	if (lang == 2) printf(" = he ");
	else if (lang == 4) printf(" = ele");
	else if (lang == 6) printf(" = il ");
	else if (lang == 8 || lang == 9) printf(" = " SMALL_E_ACUTE "l, el");
	else if (lang == 10) printf(" = li ");

	// White space until the next column
	if (lang == 1) printf ("\t\t\t\t\t  | ");
	else if (lang == 8 || lang == 9) printf ("\t\t\t\t   | ");
	else printf ("\t\t\t\t   | ");

	printf ("iom        | ");
	printf ("ei        | ");
	printf ("ios" SUPERSCRIPT_ONE "");

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
	printf ("ias" SUPERSCRIPT_ONE "");

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
		printf(" = el, lo, " SMALL_E_ACUTE "l (neutro)");
		printf ("\t\t   | ");
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
	printf ("ios" SUPERSCRIPT_ONE "");

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
		printf(" = ele, ela (indeterminado)");
		printf ("\t\t   | ");
	}
	else if (lang == 6)
	{
		printf(" = il, le ");
		printf ("\t\t\t\t   | ");
	}
	else if (lang == 8 || lang == 9)
	{
		printf(" = el, lo, la, él, ella (indeterminado)");
		printf ("  | ");
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
	printf ("al" SUPERSCRIPT_ONE "");

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
	if (lang == 1) printf ("\t\t\t\t\t  | ");
	else if (lang == 2)
	{
		printf(" = they (masculine)");
		printf ("\t\t\t   | ");
	}
	else if (lang == 4)
	{
		printf(" = eles");
		printf ("\t\t\t\t   | ");
	}
	else if (lang == 6)
	{
		printf(" = les (masculin)");
		printf ("\t\t\t   | ");
	}
	else if (lang == 8 || lang == 9)
	{
		printf(" = los, ellos");
		printf ("\t\t\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = ili (vira) ");
		printf ("\t\t\t   | ");
	}

	printf ("iens       | ");
	printf ("ibs       | ");
	printf ("iom" SUPERSCRIPT_ONE "");

	/***************************************************************************
	************* IAS
	***************************************************************************/

	printf ("\n");
	printf ("ias");
	if (lang == 1) printf ("\t\t\t\t\t  | ");
	else if (lang == 2)
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
		printf(" = les / elles (f" SMALL_E_ACUTE "minin)");
		printf ("\t\t   | ");
	}
	else if (lang == 8 || lang == 9)
	{
		printf(" = las, ellas");
		printf ("\t\t\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = ili (virina) ");
		printf ("\t\t\t   | ");
	}

	printf ("ians       | ");
	printf ("iabs      | ");
	printf ("iam" SUPERSCRIPT_ONE "");

	/***************************************************************************
	************* IA (PLURAL)
	***************************************************************************/

	printf ("\n");
	printf ("ia");
	if (lang == 1) printf ("\t\t\t\t\t  | ");
	else if (lang == 2)
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

	printf ("ia         | ");
	printf ("ibs       | ");
	printf ("iom" SUPERSCRIPT_ONE "");

	/***************************************************************************
	************* I
	***************************************************************************/

	printf ("\n");
	printf ("i");
	if (lang == 1) printf ("\t\t\t\t\t  | ");
	else if (lang == 2)
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

	printf ("i          | ");
	printf ("im        | ");
	printf ("im" SUPERSCRIPT_ONE "");

	/***************************************************************************
	************* SO
	***************************************************************************/

	printf ("\n");
	printf ("so");
	if (lang == 1) printf ("\t\t\t\t\t  | ");
	else if (lang == 2)
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

	printf ("tom        | ");
	printf ("tei       | ");
	printf ("tos");

	/***************************************************************************
	************* TOY
	***************************************************************************/

	printf ("\n");
	printf ("toy");
	if (lang == 1) printf ("\t\t\t\t\t  | ");
	else if (lang == 2)
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
		printf(" = estos ");
		printf ("\t\t\t\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = " SMALL_C_CIRCUMFLEX "i tiuj (vira) ");
		printf ("\t\t\t   | ");
	}

	printf ("tens       | ");
	printf ("tibs      | ");
	printf ("tom");

	/***************************************************************************
	************* SA
	***************************************************************************/

	printf ("\n");
	printf ("sa");
	if (lang == 1) printf ("\t\t\t\t\t  | ");
	else if (lang == 2)
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

	printf ("tam        | ");
	printf ("tay       | ");
	printf ("tas");

	/***************************************************************************
	************* TAS
	***************************************************************************/

	printf ("\n");
	printf ("tas");
	if (lang == 1) printf ("\t\t\t\t\t  | ");
	else if (lang == 2)
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

	printf ("tans       | ");
	printf ("tabs      | ");
	printf ("tam");

	/***************************************************************************
	************* TOD
	***************************************************************************/

	printf ("\n");
	printf ("tod");
	if (lang == 1) printf ("\t\t\t\t\t  | ");
	else if (lang == 2)
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

	printf ("tod        | ");
	printf ("tei       | ");
	printf ("tos");

	/***************************************************************************
	************* TA
	***************************************************************************/

	printf ("\n");
	printf ("ta");
	if (lang == 1) printf ("\t\t\t\t\t  | ");
	else if (lang == 2)
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
		printf(" = estos (neutro) ");
		printf ("\t\t\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = " SMALL_C_CIRCUMFLEX "i tiuj (ne" SMALL_U_BREVE "tra)");
		printf ("\t\t\t   | ");
	}

	printf ("ta         | ");
	printf ("tibs      | ");
	printf ("tom");

	/***************************************************************************
	************* TEL
	***************************************************************************/

	printf ("\n");
	printf ("tel");
	if (lang == 1) printf ("\t\t\t\t\t  | ");
	else if (lang == 2)
	{
		printf(" = this (undetermined)");
		printf ("\t\t   | ");
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

	printf ("tel        | ");
	printf ("tal       | ");
	printf ("tal");

	/***************************************************************************
	************* TI
	***************************************************************************/

	printf ("\n");
	printf ("ti");
	if (lang == 1) printf ("\t\t\t\t\t  | ");
	else if (lang == 2)
	{
		printf(" = these (undetermined)");
		printf ("\t\t   | ");
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
		printf(" = estos (indeterminado)");
		printf ("\t\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = " SMALL_C_CIRCUMFLEX "i tiuj (nedeterminita)");
		printf ("\t\t   | ");
	}

	printf ("ti         | ");
	printf ("tim       | ");
	printf ("tim");

	/***************************************************************************
	************* CIS
	***************************************************************************/

	printf ("\n");
	printf ("cis");
	if (lang == 1) printf ("\t\t\t\t\t  | ");
	else if (lang == 2)
	{
		printf(" = that (masculine)");
		printf ("\t\t\t   | ");
	}
	else if (lang == 4)
	{
		printf(" = aquele");
		printf ("\t\t\t\t   | ");
	}
	else if (lang == 6)
	{
		printf(" = cet");
		printf ("\t\t\t\t   | ");
	}
	else if (lang == 8 || lang == 9)
	{
		printf(" = aquel");
		printf ("\t\t\t\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = tiu (vira)");
		printf ("\t\t\t   | ");
	}

	printf ("ciom       | ");
	printf ("cei       | ");
	printf ("cios");

	/***************************************************************************
	************* CIES
	***************************************************************************/

	printf ("\n");
	printf ("cies");
	if (lang == 1) printf ("\t\t\t\t\t  | ");
	else if (lang == 2)
	{
		printf(" = those (masculine)");
		printf ("\t\t   | ");
	}
	else if (lang == 4)
	{
		printf(" = aqueles");
		printf ("\t\t\t\t   | ");
	}
	else if (lang == 6)
	{
		printf(" = ces (masculin)");
		printf ("\t\t\t   | ");
	}
	else if (lang == 8 || lang == 9)
	{
		printf(" = aquellos");
		printf ("\t\t\t\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = tiuj (vira)");
		printf ("\t\t\t   | ");
	}

	printf ("ciens      | ");
	printf ("cibs      | ");
	printf ("ciom");

	/***************************************************************************
	************* CIA
	***************************************************************************/

	printf ("\n");
	printf ("cia");
	if (lang == 1) printf ("\t\t\t\t\t  | ");
	else if (lang == 2)
	{
		printf(" = that (feminine)");
		printf ("\t\t\t   | ");
	}
	else if (lang == 4)
	{
		printf(" = aquela");
		printf ("\t\t\t\t   | ");
	}
	else if (lang == 6)
	{
		printf(" = cette");
		printf ("\t\t\t\t   | ");
	}
	else if (lang == 8 || lang == 9)
	{
		printf(" = aquella");
		printf ("\t\t\t\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = tiu (virina)");
		printf ("\t\t\t   | ");
	}

	printf ("ciam       | ");
	printf ("ciay      | ");
	printf ("cias");

	/***************************************************************************
	************* CIAS
	***************************************************************************/

	printf ("\n");
	printf ("cias");
	if (lang == 1) printf ("\t\t\t\t\t  | ");
	else if (lang == 2)
	{
		printf(" = those (feminine)");
		printf ("\t\t\t   | ");
	}
	else if (lang == 4)
	{
		printf(" = aquelas");
		printf ("\t\t\t\t   | ");
	}
	else if (lang == 6)
	{
		printf(" = ces (f" SMALL_E_ACUTE "minin)");
		printf ("\t\t\t   | ");
	}
	else if (lang == 8 || lang == 9)
	{
		printf(" = aquellas");
		printf ("\t\t\t\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = tiuj (virina)");
		printf ("\t\t\t   | ");
	}

	printf ("cians      | ");
	printf ("ciabs     | ");
	printf ("ciam");

	/***************************************************************************
	************* CID
	***************************************************************************/

	printf ("\n");
	printf ("cid");
	if (lang == 1) printf ("\t\t\t\t\t  | ");
	else if (lang == 2)
	{
		printf(" = that (neutral)");
		printf ("\t\t\t   | ");
	}
	else if (lang == 4)
	{
		printf(" = aquele (neutro)");
		printf ("\t\t\t   | ");
	}
	else if (lang == 6)
	{
		printf(" = cet, cette (neutre)");
		printf ("\t\t   | ");
	}
	else if (lang == 8 || lang == 9)
	{
		printf(" = aquel (neutro)");
		printf ("\t\t\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = tiu (ne" SMALL_U_BREVE "tra)");
		printf ("\t\t\t   | ");
	}

	printf ("cid        | ");
	printf ("cei       | ");
	printf ("cios");

	/***************************************************************************
	************* CIA
	***************************************************************************/

	printf ("\n");
	printf ("cia");
	if (lang == 1) printf ("\t\t\t\t\t  | ");
	else if (lang == 2)
	{
		printf(" = those (neutral)");
		printf ("\t\t\t   | ");
	}
	else if (lang == 4)
	{
		printf(" = aqueles (neutro)");
		printf ("\t\t\t   | ");
	}
	else if (lang == 6)
	{
		printf(" = ces (neutre)");
		printf ("\t\t\t   | ");
	}
	else if (lang == 8 || lang == 9)
	{
		printf(" = aquellos (neutro)");
		printf ("\t\t\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = tiuj (ne" SMALL_U_BREVE "tra)");
		printf ("\t\t\t   | ");
	}

	printf ("cia        | ");
	printf ("cibs      | ");
	printf ("ciom");

	/***************************************************************************
	************* CEL
	***************************************************************************/

	printf ("\n");
	printf ("cel");
	if (lang == 1) printf ("\t\t\t\t\t  | ");
	else if (lang == 2)
	{
		printf(" = that (undetermined)");
		printf ("\t\t   | ");
	}
	else if (lang == 4)
	{
		printf(" = aquele, aquela (indeterminado)");
		printf ("\t   | ");
	}
	else if (lang == 6)
	{
		printf(" = cet, cette (ind" SMALL_E_ACUTE "termin" SMALL_E_ACUTE ")");
		printf ("\t\t   | ");
	}
	else if (lang == 8 || lang == 9)
	{
		printf(" = aquel (indeterminado)");
		printf ("\t\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = tiu (nedeterminita)");
		printf ("\t\t   | ");
	}

	printf ("cel        | ");
	printf ("cial      | ");
	printf ("cial");

	/***************************************************************************
	************* CI
	***************************************************************************/

	printf ("\n");
	printf ("ci");
	if (lang == 1) printf ("\t\t\t\t\t  | ");
	else if (lang == 2)
	{
		printf(" = those (undetermined)");
		printf ("\t\t   | ");
	}
	else if (lang == 4)
	{
		printf(" = aqueles (indeterminado)");
		printf ("\t\t   | ");
	}
	else if (lang == 6)
	{
		printf(" = ces (ind" SMALL_E_ACUTE "termin" SMALL_E_ACUTE ")");
		printf ("\t\t\t   | ");
	}
	else if (lang == 8 || lang == 9)
	{
		printf(" = aquellos (indeterminado)");
		printf ("\t\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = tiuj (nedeterminita)");
		printf ("\t\t   | ");
	}

	printf ("ci         | ");
	printf ("cim       | ");
	printf ("cim");

	/***************************************************************************
	************* QUIS
	***************************************************************************/

	printf ("\n");
	printf ("quis...?");
	if (lang == 1) printf ("\t\t\t\t  | ");
	else if (lang == 2)
	{
		printf(" = who...? (masculine, singular)");
		printf ("   | ");
	}
	else if (lang == 4)
	{
		printf(" = que, quem, qual...? (masculino)");
		printf (" | ");
	}
	else if (lang == 6)
	{
		printf(" = qui...? (singulier masculin)");
		printf ("    | ");
	}
	else if (lang == 8 || lang == 9)
	{
		printf(" = qui" SMALL_E_ACUTE "n...? (masculino)");
		printf ("\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = kiu...? (vira)");
		printf ("\t\t   | ");
	}

	printf ("quom...?   | ");
	printf ("quei...?  | ");
	printf ("quos...?");

	/***************************************************************************
	************* QUI
	***************************************************************************/

	printf ("\n");
	printf ("qui");
	if (lang == 1) printf ("\t\t\t\t\t  | ");
	else if (lang == 2)
	{
		printf(" = who (masculine, singular)");
		printf ("\t\t   | ");
	}
	else if (lang == 4)
	{
		printf(" = que, quem, qual (masculino)");
		printf ("\t   | ");
	}
	else if (lang == 6)
	{
		printf(" = qui (singulier masculin)");
		printf ("\t\t   | ");
	}
	else if (lang == 8 || lang == 9)
	{
		printf(" = qui" SMALL_E_ACUTE "n (masculino)");
		printf ("\t\t\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = kiu (vira)");
		printf ("\t\t\t   | ");
	}

	printf ("quom       | ");
	printf ("quei      | ");
	printf ("quos");

	/***************************************************************************
	************* QUOY
	***************************************************************************/

	printf ("\n");
	printf ("quoy");
	if (lang == 1) printf ("\t\t\t\t\t  | ");
	else if (lang == 2)
	{
		printf(" = who (masculine, plural)");
		printf ("\t\t   | ");
	}
	else if (lang == 4)
	{
		printf(" = quais (plural masculino)");
		printf ("\t\t   | ");
	}
	else if (lang == 6)
	{
		printf(" = qui (pluriel masculin)");
		printf ("\t\t   | ");
	}
	else if (lang == 8 || lang == 9)
	{
		printf(" = cu" SMALL_A_ACUTE "les (masculino)");
		printf ("\t\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = kiuj (vira)");
		printf ("\t\t\t   | ");
	}

	printf ("quens      | ");
	printf ("quibs     | ");
	printf ("quom");

	/***************************************************************************
	************* QUA
	***************************************************************************/

	printf ("\n");
	printf ("qua");
	if (lang == 1) printf ("\t\t\t\t\t  | ");
	else if (lang == 2)
	{
		printf(" = who (feminine, singular)");
		printf ("\t\t   | ");
	}
	else if (lang == 4)
	{
		printf(" = que, quem, qual (feminino)");
		printf ("\t   | ");
	}
	else if (lang == 6)
	{
		printf(" = qui (singulier f" SMALL_E_ACUTE "minin)");
		printf ("\t\t   | ");
	}
	else if (lang == 8 || lang == 9)
	{
		printf(" = qui" SMALL_E_ACUTE "n (feminino)");
		printf ("\t\t\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = kiu (virina)");
		printf ("\t\t\t   | ");
	}

	printf ("quam       | ");
	printf ("quay      | ");
	printf ("quas");

	/***************************************************************************
	************* QUAS
	***************************************************************************/

	printf ("\n");
	printf ("quas");
	if (lang == 1) printf ("\t\t\t\t\t  | ");
	else if (lang == 2)
	{
		printf(" = who (feminine, plural)");
		printf ("\t\t   | ");
	}
	else if (lang == 4)
	{
		printf(" = quais (plural feminino)");
		printf ("\t\t   | ");
	}
	else if (lang == 6)
	{
		printf(" = qui (pluriel f" SMALL_E_ACUTE "minin)");
		printf ("\t\t   | ");
	}
	else if (lang == 8 || lang == 9)
	{
		printf(" = cu" SMALL_A_ACUTE "les (feminino)");
		printf ("\t\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = kiuj (virina)");
		printf ("\t\t\t   | ");
	}

	printf ("quans      | ");
	printf ("quabs     | ");
	printf ("quam");

	/***************************************************************************
	************* QUOD
	***************************************************************************/

	printf ("\n");
	printf ("quod");
	if (lang == 1) printf ("\t\t\t\t\t  | ");
	else if (lang == 2)
	{
		printf(" = what (neutral, singular)");
		printf ("\t\t   | ");
	}
	else if (lang == 4)
	{
		printf(" = que, quem, o qual (neutro)");
		printf ("\t   | ");
	}
	else if (lang == 6)
	{
		printf(" = qui, que (singulier neutre)");
		printf ("\t   | ");
	}
	else if (lang == 8 || lang == 9)
	{
		printf(" = qu" SMALL_E_ACUTE ", cual, que (neutro)");
		printf ("\t\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = kiu (ne" SMALL_U_BREVE "tra)");
		printf ("\t\t\t   | ");
	}

	printf ("quod       | ");
	printf ("quei      | ");
	printf ("quos");

	/***************************************************************************
	************* QUA
	***************************************************************************/

	printf ("\n");
	printf ("qua");
	if (lang == 1) printf ("\t\t\t\t\t  | ");
	else if (lang == 2)
	{
		printf(" = what (neutral, plural)");
		printf ("\t\t   | ");
	}
	else if (lang == 4)
	{
		printf(" = os quais (neutro)");
		printf ("\t\t\t   | ");
	}
	else if (lang == 6)
	{
		printf(" = qui, que (pluriel neutre)");
		printf ("\t\t   | ");
	}
	else if (lang == 8 || lang == 9)
	{
		printf(" = que, cu" SMALL_A_ACUTE "les (neutro plural)");
		printf ("\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = kiuj (ne" SMALL_U_BREVE "tra)");
		printf ("\t\t\t   | ");
	}

	printf ("qua        | ");
	printf ("quibs     | ");
	printf ("quom");

	/***************************************************************************
	************* QUEL
	***************************************************************************/

	printf ("\n");
	printf ("quel");
	if (lang == 1) printf ("\t\t\t\t\t  | ");
	else if (lang == 2)
	{
		printf(" = who (undetermined, singular)");
		printf ("\t   | ");
	}
	else if (lang == 4)
	{
		printf(" = que, quem, o qual (indeterminado)");
		printf ("   | ");
	}
	else if (lang == 6)
	{
		printf(" = qui, que (singulier ind" SMALL_E_ACUTE "termin" SMALL_E_ACUTE ")");
		printf ("\t   | ");
	}
	else if (lang == 8 || lang == 9)
	{
		printf(" = qui" SMALL_E_ACUTE "n (indeterminado)");
		printf ("\t\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = kiu (nedeterminita)");
		printf ("\t\t   | ");
	}

	printf ("quel       | ");
	printf ("qual      | ");
	printf ("qual");

	/***************************************************************************
	************* QUI
	***************************************************************************/

	printf ("\n");
	printf ("qui");
	if (lang == 1) printf ("\t\t\t\t\t  | ");
	else if (lang == 2)
	{
		printf(" = who (undetermined, plural)");
		printf ("\t   | ");
	}
	else if (lang == 4)
	{
		printf(" = os quais (indeterminado)");
		printf ("\t\t   | ");
	}
	else if (lang == 6)
	{
		printf(" = qui, que (pluriel ind" SMALL_E_ACUTE "termin" SMALL_E_ACUTE ")");
		printf ("\t   | ");
	}
	else if (lang == 8 || lang == 9)
	{
		printf(" = cu" SMALL_A_ACUTE "les (indeterminado)");
		printf ("\t\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = kiuj (nedeterminita)");
		printf ("\t\t   | ");
	}

	printf ("qui        | ");
	printf ("quim      | ");
	printf ("quim");

	/***************************************************************************
	************* NEIS
	***************************************************************************/

	printf ("\n");
	printf ("neis");
	if (lang == 1) printf ("\t\t\t\t\t  | ");
	else if (lang == 2)
	{
		printf(" = none (masculine, singular)");
		printf ("\t   | ");
	}
	else if (lang == 4)
	{
		printf(" = nenhum");
		printf ("\t\t\t\t   | ");
	}
	else if (lang == 6)
	{
		printf(" = aucun (singulier masculin)");
		printf ("\t   | ");
	}
	else if (lang == 8 || lang == 9)
	{
		printf(" = ninguno (masculino)");
		printf ("\t\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = neniu (vira)");
		printf ("\t\t\t   | ");
	}

	printf ("niom       | ");
	printf ("nei       | ");
	printf ("nios");

	/***************************************************************************
	************* NOY
	***************************************************************************/

	printf ("\n");
	printf ("noy");
	if (lang == 1) printf ("\t\t\t\t\t  | ");
	else if (lang == 2)
	{
		printf(" = none (masculine, plural)");
		printf ("\t\t   | ");
	}
	else if (lang == 4)
	{
		printf(" = nenhuns");
		printf ("\t\t\t\t   | ");
	}
	else if (lang == 6)
	{
		printf(" = aucuns (pluriel masculin)");
		printf ("\t\t   | ");
	}
	else if (lang == 8 || lang == 9)
	{
		printf(" = ningunos (masculino)");
		printf ("\t\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = neniuj (vira)");
		printf ("\t\t\t   | ");
	}

	printf ("niens      | ");
	printf ("neibs     | ");
	printf ("niom");

	/***************************************************************************
	************* NIA
	***************************************************************************/

	printf ("\n");
	printf ("nia");
	if (lang == 1) printf ("\t\t\t\t\t  | ");
	else if (lang == 2)
	{
		printf(" = none (feminine, singular)");
		printf ("\t\t   | ");
	}
	else if (lang == 4)
	{
		printf(" = nenhuma");
		printf ("\t\t\t\t   | ");
	}
	else if (lang == 6)
	{
		printf(" = aucune (singulier f" SMALL_E_ACUTE "minin)");
		printf ("\t   | ");
	}
	else if (lang == 8 || lang == 9)
	{
		printf(" = ninguna (feminino)");
		printf ("\t\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = neniu (virina)");
		printf ("\t\t\t   | ");
	}

	printf ("niam       | ");
	printf ("niay      | ");
	printf ("nias");

	/***************************************************************************
	************* NIAS
	***************************************************************************/

	printf ("\n");
	printf ("nias");
	if (lang == 1) printf ("\t\t\t\t\t  | ");
	else if (lang == 2)
	{
		printf(" = none (masculine, plural)");
		printf ("\t\t   | ");
	}
	else if (lang == 4)
	{
		printf(" = nenhumas");
		printf ("\t\t\t\t   | ");
	}
	else if (lang == 6)
	{
		printf(" = aucunes (pluriel f" SMALL_E_ACUTE "minin)");
		printf ("\t   | ");
	}
	else if (lang == 8 || lang == 9)
	{
		printf(" = ningunas (feminino)");
		printf ("\t\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = neniuj (virina)");
		printf ("\t\t\t   | ");
	}

	printf ("nians      | ");
	printf ("niabs     | ");
	printf ("niam");

	/***************************************************************************
	************* NEID
	***************************************************************************/

	printf ("\n");
	printf ("neid");
	if (lang == 1) printf ("\t\t\t\t\t  | ");
	else if (lang == 2)
	{
		printf(" = none (neutral, singular)");
		printf ("\t\t   | ");
	}
	else if (lang == 4)
	{
		printf(" = nenhum (neutro)");
		printf ("\t\t\t   | ");
	}
	else if (lang == 6)
	{
		printf(" = aucun (singulier neutre)");
		printf ("\t\t   | ");
	}
	else if (lang == 8 || lang == 9)
	{
		printf(" = ninguno (neutro)");
		printf ("\t\t\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = neniu (ne" SMALL_U_BREVE "tra)");
		printf ("\t\t\t   | ");
	}

	printf ("neid       | ");
	printf ("nei       | ");
	printf ("nios");

	/***************************************************************************
	************* NIA
	***************************************************************************/

	printf ("\n");
	printf ("nia");
	if (lang == 1) printf ("\t\t\t\t\t  | ");
	else if (lang == 2)
	{
		printf(" = none (neutral, plural)");
		printf ("\t\t   | ");
	}
	else if (lang == 4)
	{
		printf(" = nenhuns (neutro)");
		printf ("\t\t\t   | ");
	}
	else if (lang == 6)
	{
		printf(" = aucuns (pluriel neutre)");
		printf ("\t\t   | ");
	}
	else if (lang == 8 || lang == 9)
	{
		printf(" = ningunos (neutro)");
		printf ("\t\t\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = neniuj (ne" SMALL_U_BREVE "tra)");
		printf ("\t\t\t   | ");
	}

	printf ("nia        | ");
	printf ("neibs     | ");
	printf ("niom");

	/***************************************************************************
	************* NEL
	***************************************************************************/

	printf ("\n");
	printf ("nel");
	if (lang == 1) printf ("\t\t\t\t\t  | ");
	else if (lang == 2)
	{
		printf(" = none (undetermined, singular)");
		printf ("\t   | ");
	}
	else if (lang == 4)
	{
		printf(" = nenhum (indeterminado)");
		printf ("\t\t   | ");
	}
	else if (lang == 6)
	{
		printf(" = aucun (singulier ind" SMALL_E_ACUTE "termin" SMALL_E_ACUTE ")");
		printf ("\t   | ");
	}
	else if (lang == 8 || lang == 9)
	{
		printf(" = ninguno (indeterminado)");
		printf ("\t\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = neniu (nedeterminita)");
		printf ("\t\t   | ");
	}

	printf ("nel        | ");
	printf ("nal       | ");
	printf ("nal");

	/***************************************************************************
	************* NEI
	***************************************************************************/

	printf ("\n");
	printf ("nei");
	if (lang == 1) printf ("\t\t\t\t\t  | ");
	else if (lang == 2)
	{
		printf(" = none (undetermined, plural)");
		printf ("\t   | ");
	}
	else if (lang == 4)
	{
		printf(" = nenhuns (indeterminado)");
		printf ("\t\t   | ");
	}
	else if (lang == 6)
	{
		printf(" = aucuns (pluriel ind" SMALL_E_ACUTE "termin" SMALL_E_ACUTE ")");
		printf ("\t   | ");
	}
	else if (lang == 8 || lang == 9)
	{
		printf(" = ningunos (indeterminado)");
		printf ("\t\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = neniuj (nedeterminita)");
		printf ("\t\t   | ");
	}

	printf ("nei        | ");
	printf ("neim/nim  | ");
	printf ("neim/nim");

	/***************************************************************************
	************* EMPTY SPACE
	***************************************************************************/

	 // I don't know why the hell when I set a language different from Sambahsa I lost one empty space
	if (lang ==1) printf ("\n\t\t\t\t          |            |           |");
	else printf ("\n\t\t\t\t           |            |           |");


	/***************************************************************************
	************* TO
	***************************************************************************/

	printf ("\n");
	printf ("to");
	if (lang == 1) printf ("\t\t\t\t\t  | ");
	else if (lang == 2)
	{
		printf(" = this (generic pronoun)");
		printf ("\t\t   | ");
	}
	else if (lang == 4)
	{
		printf(" = esse, este (pronome gen" SMALL_E_ACUTE "rico)");
		printf ("\t   | ");
	}
	else if (lang == 6)
	{
		printf(" = " SMALL_C_CEDILLA "a, ce (pronom g" SMALL_E_ACUTE "n" SMALL_E_ACUTE "rique)");
		printf ("\t\t   | ");
	}
	else if (lang == 8 || lang == 9)
	{
		printf(" = esto, lo (pronombre gen" SMALL_E_ACUTE "rico)");
		printf ("\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = tio (" SMALL_G_CIRCUMFLEX "enerala pronomo) ");
		printf ("\t\t   | ");
	}

	printf ("to         | ");
	printf ("ad to     | ");
	printf ("os to");

	/***************************************************************************
	************* QUO
	***************************************************************************/

	printf ("\n");
	printf ("quo");
	if (lang == 1) printf ("\t\t\t\t\t  | ");
	else if (lang == 2)
	{
		printf(" = what (generic pronoun)");
		printf ("\t\t   | ");
	}
	else if (lang == 4)
	{
		printf(" = que (pronome gen" SMALL_E_ACUTE "rico)");
		printf ("\t\t   | ");
	}
	else if (lang == 6)
	{
		printf(" = ce qui, ce que (pronom g" SMALL_E_ACUTE "n" SMALL_E_ACUTE "rique)");
		printf ("\t   | ");
	}
	else if (lang == 8 || lang == 9)
	{
		printf(" = que (pronombre gen" SMALL_E_ACUTE "rico)");
		printf ("\t\t   | ");
	}
	else if (lang == 10)
	{
		printf(" = kio (" SMALL_G_CIRCUMFLEX "enerala pronomo)");
		printf ("\t\t   | ");
	}

	printf ("quo        | ");
	printf ("ad quo    | ");
	printf ("os quo");

	/***************************************************************************
	************* NOTES
	***************************************************************************/

	printf ("\n-------------------------------------------------------------------------------");

	if (lang == 2)
	{
		printf ("\n" SUPERSCRIPT_ONE " It is applied only to the definite articles");
	}
	else if (lang == 4)
	{
		printf ("\n" SUPERSCRIPT_ONE " Isso vale apenas para os artigos definidos");
	}
	else if (lang == 6)
	{
		printf ("\n" SUPERSCRIPT_ONE " " CAPITAL_C_CEDILLA "a s\'applique uniquement aux articles d" SMALL_E_ACUTE "finis");
	}
	else if (lang == 8 || lang == 9)
	{
		printf ("\n" SUPERSCRIPT_ONE " Esto aplica solo a art" SMALL_I_ACUTE "culos definidos");
	}
	else if (lang == 10)
	{
		printf ("\n" SUPERSCRIPT_ONE " Tio estas aplikata nur al difinaj artikoloj");
	}
	else
	{
		printf ("\n" SUPERSCRIPT_ONE " To ghehldt tik pro ia definiht articles");
	}


	printf ("\n-------------------------------------------------------------------------------");

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
