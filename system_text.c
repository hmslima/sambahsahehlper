#include <stdio.h>
#include <string.h>

#include "special_characters.h"

extern short int lang;

// ############################################################
// ################## NAME OF THE SOFTWARE ####################

void logo ()
{
	printf ("#######################################################################\n");
	printf ("####################### SAMBAHSA HEHLPER v 0.9 ########################\n");
	printf ("#######################################################################\n");
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
			printf ("\n    Dayir id transcriptor, yu naudhte  gweup quar jects in ment:");
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
			printf ("\n        Druve-ye yu vidsiete \"gouvernement\" ses correct-ye transcriben");
			printf ("\n        ob io (is programmer) wihand-ye sieygim ei programme quod est");
			printf ("\n        id transcription tos specific werd, bet to maght ne ses id fall");
			printf ("\n        alters werds. Kwohrim un internal liste tom problematic werds,");
			printf ("\n        bet khako dahe un tayar transcription pro vasya ex ia, ithan");
			printf ("\n        yu tehrbsiete antruses id programmes transcriptor. Kay woide");
			printf ("\n        qua werds hant tayar transcriptions, uset id commande");
			printf ("\n        \"pncliste\" au \"listepnc\"");
			printf ("\n    4 - Tod est un programmation probleme. To est dayir id buksteiv");
			printf ("\n    \"e\" quan tod ne est accenten. In to fall, est daht vos auter \"{e}\"");
			printf ("\n    au \"{"SMALL_E_DIAERESIS_IN_TEXT"}\". Eger ne est facil deil con tod special harif \""SMALL_E_DIAERESIS_IN_TEXT"\", id");
			printf ("\n    programme maght linkwes un \"e\" quer dehlgiet wehse un \""SMALL_E_DIAERESIS_IN_TEXT"\". Tik");
			printf ("\n    woid de to. To ne est un serieus probleme ob id meist important");
			printf ("\n    ject est accentihes id correct voyel.");
			printf ("\n* \"cjg\" au \"conjuge\": daht id conjugation ios insert werd");
			printf ("\n    * Mathalan: \"cjg edd\"");
			printf ("\n    Io nert-ye recommende vos kay tik insere verbs aun prefix. Ma?");
			printf ("\n    Un gohd exempel est id verb \"naporg\" (na- her est un prefix),");
			printf ("\n    quos correct conjugation pro id prev est \"napors\", lakin id");
			printf ("\n    programme dahsiet vos \"niepors\" ob id programme mehnsiet od");
			printf ("\n    tod werd subeiht un ablaut bi-sabab tod extra buksteiv \"a\".");
			printf ("\n");
			printf ("\nTod programme ne est perfect, mien druve objective con tod programme");
			printf ("\nest dahe un orientation im inkapants, un facil ed comfortable");
			printf ("\nkwehrmen os chehxe id pronunciation ed conjugation iom meist basic");
			printf ("\nwerds. Tod est un programme quod kwerhrt maung jects pro vos, bet yu");
			printf ("\ntehrpte orbate con id in id sense od yu tehrpte vide ia resultats con");
			printf ("\ncritic okwi ed gohd sense.");
			printf ("\n");
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
			printf ("\n    About the transcriptor, you need to keep four things in mind:");
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
			printf ("\n        Actually you'll see \"gouvernement\" being correctly transcribed");
			printf ("\n        because I (the programmer) manually told the program what is");
			printf ("\n        the transcription of this specific word, but it can not be the");
			printf ("\n        case of other words. I made an internal list of these");
			printf ("\n        problematic words, but I cannot give a ready-made transcription");
			printf ("\n        for all of them, so you will have to rely on the program\'s");
			printf ("\n        transcriber. In order to know what words have ready-made");
			printf ("\n        transcriptions, use the command \"pnclist\" or \"listpnc\"");
			printf ("\n    4 - This is a programming problem. It\'s about the letter \"e\" when");
			printf ("\n    this one is not stressed. In this case it\'s given to you either");
			printf ("\n    \"{e}\" or \"{"SMALL_E_DIAERESIS_IN_TEXT"}\". Since it\'s not easy to deal with this special");
			printf ("\n    character \""SMALL_E_DIAERESIS_IN_TEXT"\", the program may leave an \"e\" where should be");
			printf ("\n    an \""SMALL_E_DIAERESIS_IN_TEXT"\". Just know it. It\'s not a serious problem because the most");
			printf ("\n    important thing is to stress the correct vowel.");
			printf ("\n* \"cjg\" or \"conjuge\": gives the conjugation of the inserted word");
			printf ("\n    * For example: \"cjg edd\"");
			printf ("\n    I strongly recommend you to only insert verbs without prefixes.");
			printf ("\n    Why? An good example is the verb \"naporg\" (na- here is a prefix),");
			printf ("\n    whose correct conjugation to the past is \"napors\", however the");
			printf ("\n    program will give you \"niepors\" because the program will");
			printf ("\n    think that this word undergoes an ablaut because of this extra");
			printf ("\n    letter \"a\".");
			printf ("\n");
			printf ("\nThis program is not perfect, my actual objective with this program");
			printf ("\nis to give an orientation to the beginners, an easy and comfortable");
			printf ("\nway of checking the pronunciation and conjugation of the most basic");
			printf ("\nwords. This is a program that do a lot for you, but you have to work");
			printf ("\nwith it in the sense that you have to see its results with a critical");
			printf ("\neye and good common sense.");
			printf ("\n");
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
			printf ("\n    * \"deflang en\": para ingl" SMALL_E_CIRCUMFLEX "s");
			printf ("\n* \"pnc\" ou \"pronunce\": d" SMALL_A_ACUTE " a pron" SMALL_U_ACUTE "ncia da palavra inserida");
			printf ("\n    * Por exemplo: \"pnc plateau\" resultar" SMALL_A_ACUTE " em \"{platO:}\"");
			printf ("\n    Sobre o transcritor, voc" SMALL_E_CIRCUMFLEX " precisa ter quatro coisas na sua mente:");
			printf ("\n    1 - Lembre-se que essas transcri" SMALL_C_CEDILLA SMALL_O_TILDE "es seguem em demasiado a teoria,");
			printf ("\n    por exemplo, em teoria a transcri" SMALL_C_CEDILLA SMALL_A_TILDE "o de \"yoinkjiae\" " SMALL_E_ACUTE " {yoynkjyAy},");
			printf ("\n    mas na pr" SMALL_A_ACUTE "tica a sua transcri" SMALL_C_CEDILLA SMALL_A_TILDE "o recomendada " SMALL_E_ACUTE " {yoynkjiAy} porque");
			printf ("\n    esta " SMALL_E_ACUTE " mais pronunciável. Portanto n" SMALL_A_TILDE "o se preocupe se uma palavra");
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
			printf ("\n        Na verdade voc" SMALL_E_CIRCUMFLEX " ver" SMALL_A_ACUTE " \"gouvernement\" ser transcrito corretamente");
			printf ("\n        porque eu (o programador) manualmente disse ao programa qual " SMALL_E_ACUTE "");
			printf ("\n        a transcri" SMALL_C_CEDILLA SMALL_A_TILDE "o desta palavra espec" SMALL_I_ACUTE "fica, mas este pode n" SMALL_A_TILDE "o ser o");
			printf ("\n        caso de outras palavras. Eu fiz uma lista interna dessas");
			printf ("\n        palavras problem" SMALL_A_ACUTE "ticas, mas eu não posso dar uma transcri" SMALL_C_CEDILLA SMALL_A_TILDE "o");
			printf ("\n        pronta para todas elas, ent" SMALL_A_TILDE "o voc" SMALL_E_CIRCUMFLEX " ter" SMALL_A_ACUTE " que contar com o");
			printf ("\n        transcritor do programa. Para saber quais palavras j" SMALL_A_ACUTE " foram");
			printf ("\n        manualmente transcritas, use o comando \"pncliste\" ou \"listepnc\"");
			printf ("\n    4 - Este " SMALL_E_ACUTE " um problema de programa" SMALL_C_CEDILLA SMALL_A_TILDE "o. " CAPITAL_E_ACUTE " sobre a letra \"e\" quando");
			printf ("\n    ela n" SMALL_A_TILDE "o tem um acento t" SMALL_O_CIRCUMFLEX "nico. Nesse caso lhe " SMALL_E_ACUTE " dado ou \"{e}\" ou");
			printf ("\n    \"{"SMALL_E_DIAERESIS_IN_TEXT"}\". Uma vez que n" SMALL_A_TILDE "o " SMALL_E_ACUTE " f" SMALL_A_ACUTE "cil lidar com este caractere especial");
			printf ("\n    \""SMALL_E_DIAERESIS_IN_TEXT"\", o programa pode deixar um \"e\" onde deveria ser um");
			printf ("\n    \""SMALL_E_DIAERESIS_IN_TEXT"\". Apenas saiba disso. Não " SMALL_E_ACUTE " um problema s" SMALL_E_ACUTE "rio porque a coisa");
			printf ("\n    mais important " SMALL_E_ACUTE " acentuar t" SMALL_O_CIRCUMFLEX "nicamente a vogal correta.");
			printf ("\n* \"cjg\" ou \"conjuge\": d" SMALL_A_ACUTE " a conjuga" SMALL_C_CEDILLA SMALL_A_TILDE "o da palavra inserida");
			printf ("\n    * Por examplo: \"cjg edd\"");
			printf ("\n    Eu fortemente lhe recomendo a somente inserir verbos sem prefixos.");
			printf ("\n    Por qu" SMALL_E_CIRCUMFLEX "? Um bom exemplo " SMALL_E_ACUTE " o verbo \"naporg\" (na- aqui " SMALL_E_ACUTE " um prefixo),");
			printf ("\n    cuja conjuga" SMALL_C_CEDILLA SMALL_A_TILDE "o correta para o pret" SMALL_E_ACUTE "rito " SMALL_E_ACUTE " \"napors\", entretanto o");
			printf ("\n    programa lhe dar" SMALL_A_ACUTE " \"niepors\" porque o programa pensar" SMALL_A_ACUTE " que esta");
			printf ("\n    palavra sofre com apofonia por causa deste \"a\" extra");
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
			printf ("\n* Tod werd est long... SEI (tik SEI!!!) tod est un composite werd, ter eest un SMULK probabilitat od id programme hat ne ghehden ciautaung-ye transcribe id\n");
		break;
		case 2:
			printf ("\n* This word is long... IF (only IF!!!) it is a compound word, there is a SMALL probability that the program may not have properly transcribed it.\n");
		break;
		case 4:
			printf ("\n* Esta palavra " SMALL_E_ACUTE " longa... SE (somente SE!!!) isso for uma palavra composta, h" SMALL_A_ACUTE " uma PEQUENA probabilidade de que o programa n" SMALL_A_TILDE "o p" SMALL_O_CIRCUMFLEX "de transcrev" SMALL_E_CIRCUMFLEX "-la apropriadamente\n");
		break;
	}
}

void this_program_cannot_guess_prefixes (short int lang)
{
	switch (lang)
	{
		default:
		case 1:
			printf ("----------\nTod programme khact gvaedde an id daht werd hat au ne hat un real prefix, quod NAIWO est accenten. SEI (tik SEI!!!) BO conditions ender sont makbul...\n* Id werd hakan hat un prefix (sem prefixes: per, de, pre, re, be, ee, ex, beghs, fer, ne, se, exyer, ender, ep, epter, des, en, eti, ken, niter, peri, step)\n* Tod werd est accenten in id prefix\n...ithan id accent druve-ye buit deht in id rhalt syllab ab tod programme. Mathalan, id pronunciation ios werd \"decret\" est {d" SMALL_E_DIAERESIS_IN_TEXT "krEt}, bet tod programme baygh-shayad vos dahsiet {dEkr" SMALL_E_DIAERESIS_IN_TEXT "t}. Maaf bi-sabab tod limitation.\n\nATTENTION: Saygo to iter, yu dehlcte chehxe an id werd hakan hat un prefix, dwo gohd exempels om werds AUN prefixes sont \"beid\" ed \"rened\"\n----------\n");
		break;
		case 2:
			printf ("----------\nThis program cannot guess whether or not the given word has a real prefix, which is NEVER stressed. IF (only IF!!!) BOTH conditions below are satisfied...\n* The word really has a prefix (some prefixes: per, de, pre, re, be, ee, ex, beghs, fer, ne, se, exyer, ender, ep, epter, des, en, eti, ken, niter, peri, step)\n* This word is stressed in the prefix\n...then the stress actually was set in the wrong syllable by this program. For example, the pronunciation of the word \"decret\" is {d" SMALL_E_DIAERESIS_IN_TEXT "krEt}, but this program may give you {dEkr" SMALL_E_DIAERESIS_IN_TEXT "t}. I am sorry for this limitation.\n\nATTENTION: I say it again, you must check whether the word really has a prefix, two good examples of words WITHOUT prefixes are \"beid\" and \"rened\"\n----------\n");
		break;
		case 4:
			printf ("----------\nEste programa n" SMALL_A_TILDE "o pode adivinhar se a palavra dada tem ou n" SMALL_A_TILDE "o um prefixo real, que NUNCA " SMALL_E_ACUTE " acentuado tonicamente. SE (somente SE!!!) AMBAS condi" SMALL_C_CEDILLA SMALL_O_TILDE "es abaixo forem satisfeitas...\n* A palavra realmente tem um prefixo (alguns prefixos: per, de, pre, re, be, ee, ex, beghs, fer, ne, se, exyer, ender, ep, epter, des, en, eti, ken, niter, peri, step)\n* Esta palavra " SMALL_E_ACUTE " acentuada tonicamente no prefixo\n...ent" SMALL_A_TILDE "o a acentua" SMALL_C_CEDILLA SMALL_A_TILDE "o t" SMALL_O_CIRCUMFLEX "nica, na verdade, foi posta na s" SMALL_I_ACUTE "laba errada por este programa. Por exemplo, a pron" SMALL_U_ACUTE "ncia da palavra \"decret\" " SMALL_E_ACUTE " {d" SMALL_E_DIAERESIS_IN_TEXT "krEt}, mas este programa pode te dar {dEkr" SMALL_E_DIAERESIS_IN_TEXT "t}. Desculpe-me por esta limita" SMALL_C_CEDILLA SMALL_A_TILDE "o.\n\nATEN" CAPITAL_C_CEDILLA CAPITAL_A_TILDE "O: Digo isso novamente, voc" SMALL_E_CIRCUMFLEX " deve checar se a palavra realmente tem um prefixo, dois exemplos de palavras SEM preficos s" SMALL_A_TILDE "o \"beid\" e \"rened\"\n----------\n");
		break;
	}
}
