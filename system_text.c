#include <stdio.h>
#include <string.h>

#include "special_characters.h"

extern short int lang;

// ############################################################
// ################## NAME OF THE SOFTWARE ####################

void logo ()
{
	printf ("#######################################################################\n");
	printf ("########################### SAMBAHSA HEHLPER ##########################\n");
	printf ("#######################################################################\n\n");
}


// ############################################################
// ################### VERY BASIC MESSAGES ####################

void help (short int lang)
{
	switch (lang)
	{
		default:
		case 1:
			printf ("\nHEHLP");
			printf ("\n-----------------------------------------------------------------------\n");
			printf ("\nTod programme buit creen ab is brasileir Henrique Matheus da Silva Lima");
			printf ("\npro id bahsa sambahsa-mundialect");
			printf ("\nId objective tos programme est hehlpe i inkapants skaund-ye ia");
			printf ("\npronunciation ed conjugation iom werds.");
			printf ("\nPre wey continuemos, yu tehrbte comprehende od tod est un simple");
			printf ("\nprogramme od ne correct ia nudtors rhalts, ithan woidte od:");
			printf ("\n* Tod programme ghehdt analyse tik oin werd per ker");
			printf ("\n* Aunnecessar blankrewsa resultsient in stragn sulouk, schowi yu dehlct,");
			printf ("\nmathalan, scribe \"pnc werd\", ne \"pnc  write\" au");
			printf ("\n\" pnc werd\" au \"pnc werd \". Kwe habmos un boidos?");
			printf ("\n");
			printf ("\n\nEn ia commandes:\n");
			printf ("\n* \"exit\": exit id programme");
			printf ("\n* \"deflang\": meitht id bahsa ios programme");
			printf ("\n    * \"deflang sb\": pro sambahsa-mundialect");
			printf ("\n    * \"deflang pt\": pro portughesche");
			printf ("\n    * \"deflang en\": pro englisch");
			printf ("\n* \"pnc\" au \"pronunce\": daht id pronunciation ios insert werd");
			printf ("\n    * Mathalan: \"pnc plateau\" resultsiet in \"{platO:}\"");
			printf ("\n    Dayir id transcriptor, yu naudhte  gweup tri jects in ment:");
			printf ("\n    1 - Mehm od cia transtranscriptions pior sehkwnt id theoria,");
			printf ("\n    mathalan in theoria id transcription os \"yoinkjiae\" est");
			printf ("\n    {yoynkjyAy}, bet in praxis ids radhen transcription est");
			printf ("\n    {yoynkjiAy} ob tod est meis pronuncable. Ithan ne pior sweurgh");
			printf ("\n    sei un werd kwehct baygh inpronuncable");
			printf ("\n    2 - Alyo gohd exempel est \"Kaapstad\". Eger id est un afrikaans");
			printf ("\n    werd, ids correct transcription est {kA:pstat}, lakin tod werd est");
			printf ("\n    pronuncen kam {kaapstAd} in \"pure\" Sambahsa. Tod program ne");
			printf ("\n    woidt an id werd est pure Sambahsa au ne.");
			printf ("\n    3 - Sehkwent id aum describen uper, tod est un software, ne un");
			printf ("\n    conscieus anghen. Tod programme ghehdt correg-ye transcribe un");
			printf ("\n    werd kam \"gouverne\", bet ne \"gouvernement\" ob tod programme");
			printf ("\n    khact gvaedde od tod senst werd est un composen werd!");
			printf ("\n* \"cjg\" au \"conjuge\": daht id conjugation ios insert werd");
			printf ("\n    * Mathalan: \"cjg edd\"");
			printf ("\n* \"log\": enwehrct au swehrct id systeme messages. Tod est un baygh");
			printf ("\nutil resurce pro quel deilt con id code tos programme. Ia sisteme ");
			printf ("\nmessages sont vasya in englisch");
			printf ("\n");
			printf ("\n# TOD EST UN LONG TEXTE, KAD YU TERHBSIETE ROLLE UB TOD FENSTER IN VIES");
			printf ("\nTERMINAL EMULATOR (WE MAXIMISE TOD FENSTER) KAY VIDE ID INKAP TOS TEXTE.");

			printf("\n");
		break;
		case 2:
			printf ("\nHELP");
			printf ("\n-----------------------------------------------------------------------\n");
			printf ("\nThis program was created by the brasilianHenrique Matheus da Silva Lima");
			printf ("\nfor the language Sambahsa-Mundialect");
			printf ("\nThe goal of this program is to help the beginners showing the");
			printf ("\npronunciation and conjugation of the words.");
			printf ("\nBefore we continue, you must understand that this is a simple program");
			printf ("\nthat does not correct the user\'s mistakes, so know that:");
			printf ("\n* This program can only analyze only one word at a time");
			printf ("\n* Unnecessary white spaces will result in strange behavior, therefore");
			printf ("\nyou must, for example, werd \"pnc write\", not \"pnc  write\" or");
			printf ("\n\" pnc werd\" or \"pnc werd \". Are we understood?");
			printf ("\n");
			printf ("\n\nHere are the commands:\n");
			printf ("\n* \"exit\": exits the program");
			printf ("\n* \"setlang\": changes the language of the program");
			printf ("\n    * \"setlang sb\": for Sambahsa-Mundialect");
			printf ("\n    * \"setlang pt\": for Portuguese");
			printf ("\n    * \"setlang en\": for English");
			printf ("\n* \"pnc\" or \"pronunce\": gives the pronunciation of the inserted word");
			printf ("\n    * For example: \"pnc plateau\" will result in \"{platO:}\"");
			printf ("\n    About the transcriptor, you need to keep three things in mind:");
			printf ("\n    1 - Remember that these transcriptions follow too much the theory,");
			printf ("\n    for example, in theory the transcription of \"yoinkjiae\" is");
			printf ("\n    {yoynkjyAy}, but in practice its suggested transcription is");
			printf ("\n    {yoynkjiAy} because this one is more pronounceable. So don\'t worry");
			printf ("\n    too much if a word seems to be very unpronounceable");
			printf ("\n    2 - Other good example is \"Kaapstad\". Since it\'s a Afrikaans word,");
			printf ("\n    its correct transcription is {kA:pstat}, however this word is");
			printf ("\n    pronounced as {kaapstAd} in \"pure\" Sambahsa. This program doesn\'t");
			printf ("\n    know whether the word is pure Sambahsa or not.");
			printf ("\n    3 - Following the reasoning above described, this is a software,");
			printf ("\n    not a conscious person. This program can correctly transcribe a ");
			printf ("\n    word like \"gouverne\", but not \"gouvernement\" because the ");
			printf ("\n    program cannot guess that this last one is a compound word!");
			printf ("\n* \"cjg\" or \"conjuge\": gives the conjugation of the inserted word");
			printf ("\n    * For example: \"cjg edd\"");
			printf ("\n* \"log\": activates or deactivates the system messages. It\'s a very");
			printf ("\nuseful resource for who deals with the code of this program.");
			printf ("\n");
			printf ("\n# THIS IS A LONG TEXT, PERHAPS YOU WILL HAVE TO ROLL UP THIS WINDOW IN");
			printf ("\nYOUR TERMINAL EMULATOR (OR MAXIMISE THIS WINDOW) IN ORDER TO SEE THE");
			printf ("\nBEGINNING OF THIS TEXT");

			printf("\n");
		break;
		case 4:
			printf ("\nAJUDA");
			printf ("\n-----------------------------------------------------------------------\n");
			printf ("\nEste programa foi criado pelo brasileiro Henrique Matheus da Silva Lima");
			printf ("\npara a l" SMALL_I_ACUTE "ngua sambahsa-mundialect");
			printf ("\nO objetivo deste programa " SMALL_E_ACUTE " ajudar iniciantes exibindo a pron" SMALL_U_ACUTE "ncia e");
			printf ("\nconjuga" SMALL_C_CEDILLA SMALL_A_TILDE "o das palavras.");
			printf ("\nAntes de continuarmos, voc" SMALL_E_CIRCUMFLEX " tem que entender que este " SMALL_E_ACUTE " um programa");
			printf ("\nsimples que n" SMALL_A_TILDE "o corrige os erros do usu" SMALL_A_ACUTE "rio, ent" SMALL_A_TILDE "o saiba que:");
			printf ("\n* Este programa pode analisar apenas uma palavra por vez");
			printf ("\n* Espa" SMALL_C_CEDILLA "os em branco desnecess" SMALL_A_ACUTE "rios resultar" SMALL_A_TILDE "o em comportamento estranho,");
			printf ("\nportanto voc" SMALL_E_CIRCUMFLEX " deve, por exemplo, escrever \"pnc write\", n" SMALL_A_TILDE "o \"pnc  werd\"");
			printf ("\nou \" pnc werd\" ou \"pnc werd \". Estamos entendidos?");
			printf ("\n");
			printf ("\n\nEis os comandos:\n");
			printf ("\n* \"exit\": fecha o programa");
			printf ("\n* \"deflang\": muda o idioma do programa");
			printf ("\n    * \"deflang sb\": para sambahsa-mundialect");
			printf ("\n    * \"deflang pt\": para portugu" SMALL_E_CIRCUMFLEX "s");
			printf ("\n    * \"deflang en\": for ingl" SMALL_E_CIRCUMFLEX "s");
			printf ("\n* \"pnc\" ou \"pronunce\": d" SMALL_A_ACUTE " a pron" SMALL_U_ACUTE "ncia da palavra inserida");
			printf ("\n    * Por examplo: \"pnc plateau\" resultar" SMALL_A_ACUTE " em \"{platO:}\"");
			printf ("\n    Sobre o transcritor, voc" SMALL_E_CIRCUMFLEX " precisa ter tr" SMALL_E_CIRCUMFLEX "s coisas na sua mente:");
			printf ("\n    1 - Lembre-se que essas transcri" SMALL_C_CEDILLA SMALL_O_TILDE "es seguem em demasiado a teoria,");
			printf ("\n    por exemplo, em teoria a transcri" SMALL_C_CEDILLA SMALL_A_TILDE "o de \"yoinkjiae\" " SMALL_E_ACUTE " {yoynkjyAy},");
			printf ("\n    mas na pr" SMALL_A_ACUTE "tica a sua transcri" SMALL_C_CEDILLA SMALL_A_TILDE "o recomendada " SMALL_E_ACUTE " {yoynkjiAy} porque");
			printf ("\n    est" SMALL_A_ACUTE " " SMALL_E_ACUTE " mais pronunciável. Portanto n" SMALL_A_TILDE "o se preocupe se uma palavra");
			printf ("\n    parece ser impronunci" SMALL_A_ACUTE "vel.");
			printf ("\n    2 - Outro bom exemplo " SMALL_E_ACUTE " \"Kaapstad\". Uma vez que essa " SMALL_E_ACUTE " uma palavra");
			printf ("\n    afric" SMALL_A_CIRCUMFLEX "ner, sua transcri" SMALL_C_CEDILLA SMALL_A_TILDE "o correta " SMALL_E_ACUTE " {kA:pstat}, entretanto esta");
			printf ("\n    palavra " SMALL_E_ACUTE " pronunciada como {kaapstAd} em \"puro\" sambahsa. Este");
			printf ("\n    programa n" SMALL_A_TILDE "o sabe se a palavra " SMALL_E_ACUTE " \"puramente sambahsa\" ou n" SMALL_A_TILDE "o,");
			printf ("\n    tenha isso em mente.");
			printf ("\n    3 - Seguindo o racioc" SMALL_I_ACUTE "nio descrito acima, isto " SMALL_E_ACUTE " um software,");
			printf ("\n    n" SMALL_A_TILDE "o uma pessoa consci" SMALL_E_CIRCUMFLEX "nte. Este programa pode transcrever ");
			printf ("\n    corretamente uma palavra como \"gouverne\", mas n" SMALL_A_TILDE "o \"gouvernement\"");
			printf ("\n    porque o programa n" SMALL_A_TILDE "o pode adivinhar que esta " SMALL_U_ACUTE "ltima " SMALL_E_ACUTE " uma palavra");
			printf ("\n    composta!");
			printf ("\n* \"cjg\" ou \"conjuge\": d" SMALL_A_ACUTE " a conjuga" SMALL_C_CEDILLA SMALL_A_TILDE "o da palavra inserida");
			printf ("\n    * Por examplo: \"cjg edd\"");
			printf ("\n* \"log\": ativa ou desativa as mensagens de sistema. Este " SMALL_E_ACUTE " um recurso");
			printf ("\nmuito " SMALL_U_ACUTE "til pra quem lida com o c" SMALL_O_ACUTE "digo deste programa As mensagens de.");
			printf ("\nsistema s" SMALL_A_TILDE "o todas em ingl" SMALL_E_CIRCUMFLEX "s.");
			printf ("\n");
			printf ("\n# ESTE TEXTO " CAPITAL_E_ACUTE " LONGO, TALVEZ VOC" CAPITAL_E_CIRCUMFLEX " TENHA QUE ROLAR ESTA JANELA PARA");
			printf ("\nCIMA NO SEU EMULADOR DE TERMINAL (OU MAXIMIZAR ESTA JANELA) PARA VER O");
			printf ("\nIN" CAPITAL_I_ACUTE "CIO DESTE TEXTO");

			printf("\n");
		break;
	}
}

void command_not_found (short int lang)
{
	switch (lang)
	{
		default:
		case 1:
			printf ("\nERROR: Commande ne trohven. In fall os doubt, neudte id commande \"helhp\"\n");
		break;
		case 2:
			printf ("\nERROR: Command not found. In case of doubt, use the command \"help\"\n");
		break;
		case 4:
			printf ("\nERRO: Comando n" SMALL_A_TILDE "o encontrado. Em caso de d" SMALL_U_ACUTE "vida, use o comando \"ajuda\"\n");
		break;
	}
}

void invalid_argument (short int lang)
{
	switch (lang)
	{
		default:
		case 1:
			printf ("\nERROR: Invalid argument. In fall os doubt, neudte id command \"helhp\"\n");
		break;
		case 2:
			printf ("\nERROR: Invalid argument. In case of doubt, use the command \"help\"\n");
		break;
		case 4:
			printf ("\nERRO: Argumento inv" SMALL_A_ACUTE "lido. Em caso de d" SMALL_U_ACUTE "vida, use o comando \"ajuda\" para obter ajuda\n");
		break;
	}
}


void too_long_word (short int lang)
{
	switch (lang)
	{
		default:
		case 1:
			printf ("\n* Tod werd est long... SEI (tik SEI!!!) tod est un composite werd, kad id programme hat ne ghehden ciautaung-ye transcribe id\n");
		break;
		case 2:
			printf ("\n* This word is long... IF (only IF!!!) it is a compound word, maybe the program couldn\'t properly transcribe it.\n");
		break;
		case 4:
			printf ("\n* Esta palavra " SMALL_E_ACUTE " longa... SE (somente SE!!!) isso for uma palavra composta, talvez o programa n" SMALL_A_TILDE "o p" SMALL_O_CIRCUMFLEX "de transcrev" SMALL_E_CIRCUMFLEX "-la apropriadamente\n");
		break;
	}
}
