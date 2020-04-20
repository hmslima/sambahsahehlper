#include <stdio.h>
#include <string.h>

#include "special_characters.h"

extern short int lang;

// ############################################################
// ################## NAME OF THE SOFTWARE ####################

void logo ()
{
	printf ("###############################################################################\n");
	printf ("########################### SAMBAHSA HEHLPER v 0.30 ###########################\n");
	printf ("###############################################################################\n");
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
			printf ("\n-------------------------------------------------------------------------------\n");
			printf ("\nTod programme buit creen ab iom brasileir Henrique Matheus da Silva Lima pro id");
			printf ("\nbahsa sambahsa-mundialect. In id hol process os creation tos programme, is hieb");
			printf ("\nid hehlp ios creator ios bahsa, ios franceois Olivier Simon.");
			printf ("\nId objective tos programme est hehlpe i inkapants skaund-ye ia pronunciation");
			printf ("\ned conjugation iom werds.");
			printf ("\nPre wey continuemos, yu tehrpte comprehende od tod est un simple programme od");
			printf ("\n ne correct ia rhalts im nudtors, ithan woidte od:");
			printf ("\n* Tod programme ghehdt analyse tik oin werd per ker dehlcte,");
			printf ("\n* Aunnecessar blankrewsa resultesient in stragn sulouk, schowi yu dehlcte,");
			printf ("\n mathalan, scribe \"pnc werd\", ne \"pnc  werd\" au \" pnc werd\" au \"pnc werd \"");
			printf ("\nKwe habmos un boidos?");
			printf ("\n");
			printf ("\nEn ia commandes:\n");
			printf ("\n* \"salg\" au \"exit\": exeiht id programme");
			printf ("\n* \"falls\": skaut un tabell om declination falls");
			printf ("\n* \"deflang\": meitht id bahsa ios programme");
			printf ("\n    * \"deflang sb\": pro sambahsa-mundialect");
			printf ("\n    * \"deflang pt\": pro portughesche");
			printf ("\n    * \"deflang en\": pro englisch");
			printf ("\n    * \"deflang fr\": pro franceois");
			printf ("\n    * \"deflang eo\": pro esperanto");
			printf ("\n* \"pnc\" au \"pronunce\": daht id pronunciation ios insert werd");
			printf ("\n    * Mathalan: \"pnc plateau\" resultesiet in \"{platO:}\"");
			printf ("\n    Dayir id transcriptor, yu naudhte gwupes quar jects in ment. Bet pre wey");
			printf ("\n    natolcsiemos de to, woidte od tod programme est baygh competent in sien");
			printf ("\n    job, lakin ter sont sem rar situations qua naudhe vies attention.");
			printf ("\n    1 - Mehmte od cia transcriptions pior sehkwnt id theoria. Mathalan in");
			printf ("\n    theoria id transcription os \"yoinkjiae\" est {yoynkjyAy}, bet in praxis ids");
			printf ("\n    radhen transcription est {yoynkjiAy} ob tod est meis pronunceable. Ithan ne");
			printf ("\n    pior sweurghte sei un werd kwehct baygh impronunceable");
			printf ("\n    2 - Alyo gohd exempel est \"Kaapstad\". Eger id est un afrikaans werd, ids");
			printf ("\n    correct transcription est {kA:pstat}, lakin tod werd esiet pronuncen kam");
			printf ("\n    {kaapstAd} in \"pure\" Sambahsa. Tod situatuion est commun con proper nams.");
			printf ("\n    3 - Sehkwent id aum describen uper: tod est un software, ne un conscieus");
			printf ("\n    anghen. Tod programme ghehdt correct-ye transcribe un werd kam \"gouverne\",");
			printf ("\n    bet ne \"gouvernement\" ob tod programme khact gvaedde od tod senst werd");
			printf ("\n    est un composen werd!");
			printf ("\n        Druve-ye yu vidsiete \"gouvernement\" ed \"Kaapstad\" ses correct-ye");
			printf ("\n        transcriben ob io (is programmer) wihand-ye sieygim ei programme qua");
			printf ("\n        sont ia transcriptions tom specific werds, bet to maght ne ses id fall");
			printf ("\n        altern problematic werds. Khako dahe un tayar transcription pro vasya");
			printf ("\n        ex ta werds (yoitkwe yu tehrbsiete antruses id programmes transcriptor),");
			printf ("\n        bet kwohrim un internal liste tom werds. Kay woide qua problematic");
			printf ("\n        werds hant tayar transcriptions, uset id commande \"pncliste\" au");
			printf ("\n        \"listepnc\"");
			printf ("\n    4 - Tod est un programmation probleme. To est dayir id buksteiv \"e\" quan");
			printf ("\n    tod ne est accentuen. In tod fall, est daht vos auter \"{e}\" au \"{"SMALL_E_DIAERESIS_IN_TEXT"}\". Eger");
			printf ("\n    ne est facil diles con tod special harif \""SMALL_E_DIAERESIS_IN_TEXT"\", id programme maght linkwes");
			printf ("\n    un \"e\" quer dehlgiet wehse un \""SMALL_E_DIAERESIS_IN_TEXT"\". Tik woidte de to. To ne est un serieus");
			printf ("\n    probleme ob id meis important ject est accentue id correct voyel.");
			printf ("\n* \"cjg\" au \"conjuge\": daht id conjugation ios insert werd");
			printf ("\n    * Mathalan: \"cjg edd\"");
			printf ("\n    Io akster-ye recommande vos tik insere verbs aun prefixe. Ma? Un gohd");
			printf ("\n    exempel est id verb \"naporg\" (na- her est un prefixe), quos correct");
			printf ("\n    conjugation pro id prev est \"napors\", lakin id programme dahsiet vos");
			printf ("\n    \"niepors\" ob id programme mehnsiet od tod werd subeiht un ablaut bi-sabab");
			printf ("\n    tod extra buksteiv \"a\".");
			printf ("\n");
			printf ("\nTod programme ne est perfect, mien druv objective con tod programme est dahe un");
			printf ("\norientation im inkapants, un facil ed comfortable kwehrmen os chehxe id");
			printf ("\npronunciation ed conjugation iom meist basic werds. Tod est un programme quod");
			printf ("\nkwehrt maung jects pro vos, bet yu tehrpte orbate con id in id sense od yu");
			printf ("\ntehrpte vide ia resultats con critic okwi ed gohd sense.");
			printf ("\n");
			printf ("\n* \"log\": enwehrct we swehrct ia programme messages. Tod est un baygh util");
			printf ("\nressurce pro quel deilt con id code tos programme. Ia programmes messages sont");
			printf ("\nvasya in englisch");
			printf ("\n");
			printf ("\n# TOD EST UN LONG TEXTE, KAD YU TEHRPSIETE ROLLE UB TOD FENSTER IN VIES");
			printf ("\nTERMINAL EMULATOR (WE MAXIMISE TOD FENSTER) KAY VIDE ID INKAP TOS TEXTE.");

			printf("\n");
		break;
		case 2:
			printf ("\nHELP");
			printf ("\n-------------------------------------------------------------------------------\n");
			printf ("\nThis program was created by the Brazilian Henrique Matheus da Silva Lima for");
			printf ("\nthe language Sambahsa-Mundialect. In the whole process of creation of this");
			printf ("\nprogram, he had the help of the creator of the language, the French Olivier");
			printf ("\nSimon.");
			printf ("\nThe goal of this program is to help the beginners showing the pronunciation and");
			printf ("\nconjugation of the words. Before we continue, you must understand that this");
			printf ("\nis a simple program that does not correct the user\'s mistakes, so know that:");
			printf ("\n* This program can only analyze only one word at a time");
			printf ("\n* Unnecessary white spaces will result in strange behavior, therefore you must,");
			printf ("\nfor example, write \"pnc werd\", not \"pnc  werd\" or \" pnc werd\" or \"pnc werd \".");
			printf ("\nAre we understood?");
			printf ("\n");
			printf ("\nHere are the commands:\n");
			printf ("\n* \"exit\": exits the program");
			printf ("\n* \"cases\": shows a table of declination cases");
			printf ("\n* \"setlang\": changes the language of the program");
			printf ("\n    * \"setlang sb\": for Sambahsa-Mundialect");
			printf ("\n    * \"setlang pt\": for Portuguese");
			printf ("\n    * \"setlang en\": for English");
			printf ("\n    * \"setlang fr\": for French");
			printf ("\n    * \"setlang eo\": for Esperanto");
			printf ("\n* \"pnc\" or \"pronunce\": gives the pronunciation of the inserted word");
			printf ("\n    * For example: \"pnc plateau\" will result in \"{platO:}\"");
			printf ("\n    About the transcriptor, you need to keep four things in mind. But before we");
			printf ("\n    go forward in this discussion, know that this program is very competent in");
			printf ("\n    its job, however there are some rare situations that require your");
			printf ("\n    attention.");
			printf ("\n    1 - Remember that these transcriptions follow too much the theory. For");
			printf ("\n    example, in theory the transcription of \"yoinkjiae\" is {yoynkjyAy}, but in");
			printf ("\n    practice its suggested transcription is {yoynkjiAy} because this one is");
			printf ("\n    more pronounceable. So don\'t worry too much if a word seems to be very");
			printf ("\n    unpronounceable.");
			printf ("\n    2 - Other good example is \"Kaapstad\". Since it\'s a Afrikaans word, its");
			printf ("\n    correct transcription is {kA:pstat}, however this word would be pronounced");
			printf ("\n    as {kaapstAd} in \"pure\" Sambahsa. This situation is common with proper");
			printf ("\n    nouns.");
			printf ("\n    3 - Following the reasoning described above: this is a software not a");
			printf ("\n    conscious person. This program can correctly transcribe a word like");
			printf ("\n    \"gouverne\", but not \"gouvernement\" because the program cannot guess that");
			printf ("\n    this last one is a compound word!");
			printf ("\n        Actually you'll see \"gouvernement\" and \"Kaapstad\" being correctly");
			printf ("\n        transcribed because I (the programmer) manually told the program what");
			printf ("\n        are the transcriptions of these specific words, but it can not be the");
			printf ("\n        case of other problematic words. I cannot give a ready-made ");
			printf ("\n        transcription for all of these words (so you will have to rely on the");
			printf ("\n        program\'s transcriber), but I made an internal list of them. In order");
			printf ("\n        to know what problematic words have ready-made transcriptions, use the");
			printf ("\n        command \"pnclist\" or \"listpnc\"");
			printf ("\n    4 - This is a programming problem. It\'s about the letter \"e\" when this one");
			printf ("\n    is not stressed. In this case it\'s given to you either \"{e}\" or \"{"SMALL_E_DIAERESIS_IN_TEXT"}\".");
			printf ("\n    Since it\'s not easy to deal with this special character \""SMALL_E_DIAERESIS_IN_TEXT"\", the program");
			printf ("\n    may leave an \"e\" where should be an \""SMALL_E_DIAERESIS_IN_TEXT"\". Just know it. It\'s not a serious");
			printf ("\n    problem because the most important thing is to stress the correct vowel");
			printf ("\n* \"cjg\" or \"conjuge\": gives the conjugation of the inserted word");
			printf ("\n    * For example: \"cjg edd\"");
			printf ("\n    I strongly recommend you to only insert verbs without prefixes. Why? A");
			printf ("\n    good example is the verb \"naporg\" (na- here is a prefix), whose correct");
			printf ("\n    conjugation to the past is \"napors\", however the program will give you");
			printf ("\n    \"niepors\" because the program will think that this word undergoes an");
			printf ("\n    ablaut because of this extra letter \"a\".");
			printf ("\n");
			printf ("\n* \"log\": activates or deactivates the system messages. It\'s a very useful");
			printf ("\nresource for who deals with the code of this program.");
			printf ("\n");
			printf ("\n# THIS IS A LONG TEXT, PERHAPS YOU WILL HAVE TO ROLL UP THIS WINDOW IN YOUR");
			printf ("\nTERMINAL EMULATOR (OR MAXIMISE THIS WINDOW) IN ORDER TO SEE THE BEGINNING");
			printf ("\nOF THIS TEXT");

			printf("\n");
		break;
		case 4:
			printf ("\nAJUDA");
			printf ("\n-------------------------------------------------------------------------------\n");
			printf ("\nEste programa foi criado pelo brasileiro Henrique Matheus da Silva Lima para a");
			printf ("\nl" SMALL_I_ACUTE "ngua sambahsa-mundialect. Em todo o processo de cria" SMALL_C_CEDILLA SMALL_A_TILDE "o deste programa, ele");
			printf ("\nteve a ajuda do criador da l" SMALL_I_ACUTE "ngua, o franc" SMALL_E_CIRCUMFLEX "s Olivier Simon.");
			printf ("\nO objetivo deste programa " SMALL_E_ACUTE " ajudar iniciantes exibindo a pron" SMALL_U_ACUTE "ncia e");
			printf ("\nconjuga" SMALL_C_CEDILLA SMALL_A_TILDE "o das palavras.");
			printf ("\nAntes de continuarmos, voc" SMALL_E_CIRCUMFLEX " tem que entender que este " SMALL_E_ACUTE " um programa simples que");
			printf ("\nn" SMALL_A_TILDE "o corrige os erros do usu" SMALL_A_ACUTE "rio, ent" SMALL_A_TILDE "o saiba que:");
			printf ("\n* Este programa pode analisar apenas uma palavra por vez");
			printf ("\n* Espa" SMALL_C_CEDILLA "os em branco desnecess" SMALL_A_ACUTE "rios resultar" SMALL_A_TILDE "o em comportamento estranho,");
			printf ("\nportanto voc" SMALL_E_CIRCUMFLEX " deve, por exemplo, escrever \"pnc werd\", n" SMALL_A_TILDE "o \"pnc  werd\" ou");
			printf ("\n\" pnc werd\" ou \"pnc werd \". Estamos entendidos?");
			printf ("\n");
			printf ("\nEis os comandos:\n");
			printf ("\n* \"sair\": fecha o programa");
			printf ("\n* \"casos\": exibe uma tabela de casos de declina" SMALL_C_CEDILLA SMALL_A_TILDE "o");
			printf ("\n* \"deflang\": muda o idioma do programa");
			printf ("\n    * \"deflang sb\": para sambahsa-mundialect");
			printf ("\n    * \"deflang pt\": para portugu" SMALL_E_CIRCUMFLEX "s");
			printf ("\n    * \"deflang en\": para ingl" SMALL_E_CIRCUMFLEX "s");
			printf ("\n    * \"deflang fr\": para franc" SMALL_E_CIRCUMFLEX "s");
			printf ("\n    * \"deflang eo\": para esperanto");
			printf ("\n* \"pnc\" ou \"pronunce\": d" SMALL_A_ACUTE " a pron" SMALL_U_ACUTE "ncia da palavra inserida");
			printf ("\n    * Por exemplo: \"pnc plateau\" resultar" SMALL_A_ACUTE " em \"{platO:}\"");
			printf ("\n    Sobre o transcritor, voc" SMALL_E_CIRCUMFLEX " precisa ter quatro coisas na sua mente. Mas antes");
			printf ("\n    de prosseguirmos, saiba que este programa " SMALL_E_ACUTE " muito competente em seu");
			printf ("\n    trabalho, entretanto h" SMALL_A_ACUTE " algumas raras situa" SMALL_C_CEDILLA SMALL_O_TILDE "es que requerem a sua aten" SMALL_C_CEDILLA SMALL_A_TILDE "o.");
			printf ("\n    1 - Lembre-se que essas transcri" SMALL_C_CEDILLA SMALL_O_TILDE "es seguem em demasiado a teoria. Por");
			printf ("\n    exemplo, em teoria a transcri" SMALL_C_CEDILLA SMALL_A_TILDE "o de \"yoinkjiae\" " SMALL_E_ACUTE " {yoynkjyAy}, mas na");
			printf ("\n    pr" SMALL_A_ACUTE "tica a sua transcri" SMALL_C_CEDILLA SMALL_A_TILDE "o recomendada " SMALL_E_ACUTE " {yoynkjiAy} porque esta " SMALL_E_ACUTE " mais");
			printf ("\n    pronunci" SMALL_A_ACUTE "vel. Portanto n" SMALL_A_TILDE "o se preocupe se uma palavra parece ser");
			printf ("\n    impronunci" SMALL_A_ACUTE "vel.");
			printf ("\n    2 - Outro bom exemplo " SMALL_E_ACUTE " \"Kaapstad\". Uma vez que essa " SMALL_E_ACUTE " uma palavra");
			printf ("\n    afric" SMALL_A_CIRCUMFLEX "ner, sua transcri" SMALL_C_CEDILLA SMALL_A_TILDE "o correta " SMALL_E_ACUTE " {kA:pstat}, entretanto esta palavra");
			printf ("\n    seria pronunciada como {kaapstAd} em sambahsa \"puro\". Essa situa" SMALL_C_CEDILLA SMALL_A_TILDE "o " SMALL_E_ACUTE " comum");
			printf ("\n    com substantivos pr" SMALL_O_ACUTE "prios.");
			printf ("\n    3 - Seguindo o racioc" SMALL_I_ACUTE "nio descrito acima: isto " SMALL_E_ACUTE " um software, n" SMALL_A_TILDE "o uma");
			printf ("\n    pessoa consciente. Este programa pode transcrever corretamente uma palavra");
			printf ("\n    como \"gouverne\", mas n" SMALL_A_TILDE "o \"gouvernement\" porque o programa n" SMALL_A_TILDE "o pode");
			printf ("\n    adivinhar que esta " SMALL_U_ACUTE "ltima " SMALL_E_ACUTE " uma palavra composta!");
			printf ("\n        Na verdade voc" SMALL_E_CIRCUMFLEX " ver" SMALL_A_ACUTE " \"gouvernement\" e \"Kaapstad\" serem transcritos");
			printf ("\n        corretamente porque eu (o programador) manualmente disse ao programa");
			printf ("\n        quais s" SMALL_A_TILDE "o as transcri" SMALL_C_CEDILLA SMALL_O_TILDE "es dessas palavras espec" SMALL_I_ACUTE "ficas, mas este pode");
			printf ("\n        n" SMALL_A_TILDE "o ser o caso de outras palavras problem" SMALL_A_ACUTE "ticas. Eu n" SMALL_A_TILDE "o posso dar uma");
			printf ("\n        transcri" SMALL_C_CEDILLA SMALL_A_TILDE "o pronta para todas essas palavras (de forma que voc" SMALL_E_CIRCUMFLEX "");
			printf ("\n        ter" SMALL_A_ACUTE " que contar com o transcritor do programa), mas eu fiz uma lista ");
			printf ("\n        interna delas. Para saber quais palavras problem" SMALL_A_ACUTE "ticas j" SMALL_A_ACUTE " foram");
			printf ("\n        manualmente transcritas, use o comando \"pncliste\" ou \"listepnc\"");
			printf ("\n    4 - Este " SMALL_E_ACUTE " um problema de programa" SMALL_C_CEDILLA SMALL_A_TILDE "o. " CAPITAL_E_ACUTE " sobre a letra \"e\" quando ela n" SMALL_A_TILDE "o");
			printf ("\n    tem um acento t" SMALL_O_CIRCUMFLEX "nico. Nesse caso lhe " SMALL_E_ACUTE " dado ou \"{e}\" ou \"{"SMALL_E_DIAERESIS_IN_TEXT"}\". Uma vez que");
			printf ("\n    n" SMALL_A_TILDE "o " SMALL_E_ACUTE " f" SMALL_A_ACUTE "cil lidar com este caractere especial \""SMALL_E_DIAERESIS_IN_TEXT"\", o programa pode deixar");
			printf ("\n    um \"e\" onde deveria ser um \""SMALL_E_DIAERESIS_IN_TEXT"\". Apenas saiba disso. N" SMALL_A_TILDE "o " SMALL_E_ACUTE " um problema s" SMALL_E_ACUTE "rio");
			printf ("\n    porque a coisa mais important " SMALL_E_ACUTE " acentuar t" SMALL_O_CIRCUMFLEX "nicamente a vogal correta.");
			printf ("\n* \"cjg\" ou \"conjuge\": d" SMALL_A_ACUTE " a conjuga" SMALL_C_CEDILLA SMALL_A_TILDE "o da palavra inserida");
			printf ("\n    * Por examplo: \"cjg edd\"");
			printf ("\n    Eu fortemente lhe recomendo a somente inserir verbos sem prefixos. Por qu" SMALL_E_CIRCUMFLEX "?");
			printf ("\n    Um bom exemplo " SMALL_E_ACUTE " o verbo \"naporg\" (na- aqui " SMALL_E_ACUTE " um prefixo), cuja conjuga" SMALL_C_CEDILLA SMALL_A_TILDE "o");
			printf ("\n    correta para o pret" SMALL_E_ACUTE "rito " SMALL_E_ACUTE " \"napors\", entretanto o programa lhe dar" SMALL_A_ACUTE "");
			printf ("\n    \"niepors\" porque o programa pensar" SMALL_A_ACUTE " que esta palavra sofre com apofonia");
			printf ("\n    por causa deste \"a\" extra.");
			printf ("\n* \"log\": ativa ou desativa as mensagens de sistema. Este " SMALL_E_ACUTE " um recurso muito");
			printf ("\n" SMALL_U_ACUTE "til pra quem lida com o c" SMALL_O_ACUTE "digo deste programa. As mensagens de sistema s" SMALL_A_TILDE "o");
			printf ("\ntodas em ingl" SMALL_E_CIRCUMFLEX "s.");
			printf ("\n");
			printf ("\n# ESTE TEXTO " CAPITAL_E_ACUTE " LONGO, TALVEZ VOC" CAPITAL_E_CIRCUMFLEX " TENHA QUE ROLAR ESTA JANELA PARA CIMA NO SEU");
			printf ("\nEMULADOR DE TERMINAL (OU MAXIMIZAR ESTA JANELA) PARA VER O IN" CAPITAL_I_ACUTE "CIO DESTE TEXTO");

			printf("\n");
		break;
		case 6:
			printf ("\nAIDE");
			printf ("\n-------------------------------------------------------------------------------\n");
			printf ("\nCe programme a " SMALL_E_ACUTE "t" SMALL_E_ACUTE " cr" SMALL_E_ACUTE SMALL_E_ACUTE " par le br" SMALL_E_ACUTE "silien Henrique Matheus da Silva Lima pour la");
			printf ("\nlangue sambahsa-mundialect. Durant tout le processus de cr" SMALL_E_ACUTE "ation de celui-ci,");
			printf ("\nil a pu b" SMALL_E_ACUTE "n" SMALL_E_ACUTE "ficier de l\'aide de l\'inventeur de cette langue, Olivier Simon.");
			printf ("\nL\'objectif de ce programme est d'aider les d" SMALL_E_ACUTE "butants en leur montrant la");
			printf ("\nprononciation et la conjugaison des mots.");
			printf ("\nAvant de continuer, vous devez comprendre qu\'il s\'agit d\'un simple programme");
			printf ("\nqui ne corrige pas les erreurs des utilisateurs, c\'est pourquoi il faut que");
			printf ("\nvous sachiez que :");
			printf ("\n* ce programme ne peut analyser qu'un seul mot " SMALL_A_GRAVE " la fois.");
			printf ("\n* les espaces inutiles cr" SMALL_E_ACUTE "eront des aberrations, c\'est pourquoi vous devez");
			printf ("\n" SMALL_E_ACUTE "crire \"pnc werd\", et non \"pnc  werd\" ni \" pnc werd\", ni \"pnc mot \". D\'accord ?");
			printf ("\n");
			printf ("\nVoici les commandes : :\n");
			printf ("\n* \"sortir\" : sort du programme");
			printf ("\n* \"cas\": donne un tableau des cas de d" SMALL_E_ACUTE "clinaison");
			printf ("\n* \"deflang\" : change la langue du programme");
			printf ("\n    * \"deflang sb\" : sambahsa-mundialect");
			printf ("\n    * \"deflang pt\" : portugais");
			printf ("\n    * \"deflang en\" : anglais");
			printf ("\n    * \"deflang fr\" : fran" SMALL_C_CEDILLA "ais");
			printf ("\n    * \"deflang eo\" : esperanto");
			printf ("\n* \"pnc\" ou \"pronunce\" : donne la prononciation du mot ins" SMALL_E_ACUTE "r" SMALL_E_ACUTE "");
			printf ("\n    * Par exemple, \"pnc plateau\" donnera \"{platO:}\"");
			printf ("\n    Sur le transcripteur, vous devez garder quatre choses " SMALL_A_GRAVE " l\'esprit. Mais");
			printf ("\n    avant que nous rediscutions de " SMALL_C_CEDILLA "a, sachez que ce programme conna" SMALL_I_CIRCUMFLEX "t bien");
			printf ("\n    son m" SMALL_E_ACUTE "tier; cependant certaines situations requi" SMALL_E_GRAVE "rent votre attention.");
			printf ("\n    1 - Ces transcriptions sont des prononciations \"th" SMALL_E_ACUTE "oriques\". Par exemple,");
			printf ("\n    \"yoinkjiae\" est transcrit {yoynkjyAy}, dans les faits sera prononc" SMALL_E_ACUTE "");
			printf ("\n    {yoynkjiAy} pour " SMALL_E_ACUTE "viter une succession de semi-voyeles.");
			printf ("\n    2 - Les noms propres (lieux, personnes...) peuvent avoir une prononciation");
			printf ("\n    diff" SMALL_E_ACUTE "rente de leur SPT th" SMALL_E_ACUTE "orique.");
			printf ("\n    3- Ce logiciel ne peut pas reconna" SMALL_I_CIRCUMFLEX "tre les pr" SMALL_E_ACUTE "fixes et les suffixes qui ont");
			printf ("\n    un impact sur la prononciation. Ainsi tel est le cas des suffixes \"-ment\"");
			printf ("\n    ed \"-went\".");
			printf ("\n    4- Ce logiciel peut se tromper en ce qui concerne les {e} et {" SMALL_E_DIAERESIS_IN_TEXT "}, ce qui");
			printf ("\n    n\'est pas excessivement grave dans la mesure o" SMALL_U_GRAVE " ces deux sons sont tous");
			printf ("\n    " SMALL_E_ACUTE "crits \"e\" en sambahsa.");
			printf ("\n* \"cjg\" ou \"conjuge\" : donne la conjugaison du verbe ins" SMALL_E_ACUTE "r" SMALL_E_ACUTE ".");
			printf ("\n    * Par exemple : \"cjg edd\"");
			printf ("\n    Nous vous recommandons fortement d\'ins" SMALL_E_ACUTE "rer des verbes sans pr" SMALL_E_ACUTE "fixe dans la");
			printf ("\n    mesure o" SMALL_U_GRAVE " les pr" SMALL_E_ACUTE "fixes perturbent l\'accentuation des verbes et l\'analyse");
			printf ("\n    qu\'en fait ce logiciel.");
			printf ("\n");
			printf ("\n* \"log\" : active ou d" SMALL_E_ACUTE "sactive les messages du programme. Ces messages sont");
			printf ("\ntoujours en anglais.");
			printf ("\n");
			printf ("\n# CE TEXTE EST ASSEZ LONG, PEUT-" CAPITAL_E_CIRCUMFLEX "TRE FAUT-IL QUE VOUS REMONTIEZ VERS LE HAUT");
			printf ("\nPOUR EN LIRE LE DEBUT");

			printf("\n");
		break;
		case 10:
			printf ("\nHELPO");
			printf ("\n-------------------------------------------------------------------------------\n");
			printf ("\n" CAPITAL_C_CIRCUMFLEX "i tiu programo estis kreita de la brazilano Henrique Matheus da Silva Lima");
			printf ("\npor la lingvo sambaso-mundialekto. En la tuta procedo de kreado de " SMALL_C_CIRCUMFLEX "i tiu");
			printf ("\nprogramo, li havis la helpon de la kreinto de la lingvo, la franco Olivier");
			printf ("\nSimon.");
			printf ("\nLa celo de la programo estas helpi la komencantojn montranta la prononcon kaj");
			printf ("\nkonjugacion de la vortoj. Anta" SMALL_U_BREVE " oni da" SMALL_U_BREVE "rigos, vi devas kompreni ol " SMALL_C_CIRCUMFLEX "i estas");
			printf ("\nsimpla programo kiu ne korektas la erarojn de la uzanto, tial sciu ol:");
			printf ("\n* " CAPITAL_C_CIRCUMFLEX "i tiu programo povas analizi nur unu vorto per fojo");
			printf ("\n* Nenecesaj blankaj spacoj resultos en stragna konduto, do vi devas, ekzemple,");
			printf ("\nscribe \"pnc werd\", ne \"pnc  werd\" a" SMALL_U_BREVE " \" pnc werd\" a" SMALL_U_BREVE " \"pnc werd \".");
			printf ("\n" CAPITAL_C_CIRCUMFLEX "u ni estas komprenitaj?");
			printf ("\n");
			printf ("\nJen la ordonoj:\n");
			printf ("\n* \"eliri\": fermas la programon");
			printf ("\n* \"kazoj\": montras tabelon de deklini" SMALL_G_CIRCUMFLEX "aj kazoj");
			printf ("\n* \"setlang\": " SMALL_S_CIRCUMFLEX "an" SMALL_G_CIRCUMFLEX "as la lingvon de la programo");
			printf ("\n    * \"deflang sb\": por sambaso-mundialekto");
			printf ("\n    * \"deflang pt\": por la portugala");
			printf ("\n    * \"deflang en\": por la angla");
			printf ("\n    * \"deflang fr\": por la franca");
			printf ("\n    * \"deflang eo\": por esperanto");
			printf ("\n* \"pnc\" a" SMALL_U_BREVE " \"pronunce\": donas la prononcon de la vorto enmetita");
			printf ("\n    * Ekzemple: \"pnc plateau\" resultos en \"{platO:}\"");
			printf ("\n    Pri la transskribisto, tenu en menso kvar a" SMALL_J_CIRCUMFLEX "ojn. Sed anta" SMALL_U_BREVE " ni iros");
			printf ("\n    anta" SMALL_U_BREVE "e en " SMALL_C_CIRCUMFLEX "i tiu diskuto, sciu ol " SMALL_C_CIRCUMFLEX "i tiu programo estas tre kompetenta en");
			printf ("\n    " SMALL_G_CIRCUMFLEX "ia laboro, tamen estas kelkaj maloftaj situacioj kio petas vian atenton");
			printf ("\n    1 - Memoru ol " SMALL_C_CIRCUMFLEX "i tiu transsckriboj tro sekvas teorion. Ekzemple:");
			printf ("\n    en teorio, la transskribo de \"yoinkjiae\" estas {yoynkjyAy}, sed en");
			printf ("\n    praktiko " SMALL_G_CIRCUMFLEX "ia sugestan transskribo estas {yoynkjiAy} " SMALL_C_CIRCUMFLEX "ar " SMALL_C_CIRCUMFLEX "i tiu estas pli");
			printf ("\n    prononcebla. Tial ne tro zorgu " SMALL_C_CIRCUMFLEX "u vorto " SMALL_S_CIRCUMFLEX "ajnas esti neprononcebla");
			printf ("\n    2 - Alia bona ekzemplo estas \"Kaapstad\". " CAPITAL_C_CIRCUMFLEX "ar estas afrikansa vorto, " SMALL_G_CIRCUMFLEX "ia");
			printf ("\n    " SMALL_G_CIRCUMFLEX "usta transskribo estas {kA:pstat}, tamen " SMALL_C_CIRCUMFLEX "i tiu vorto estus prononcita");
			printf ("\n    kiel {kaapstAd} en \"pura\" sambaso. " CAPITAL_C_CIRCUMFLEX "i situacio estas komuna kun propraj");
			printf ("\n    nomoj.");
			printf ("\n    3 - Sekvanta la priskribitan rezonon super: " SMALL_C_CIRCUMFLEX "i tiu estas programaro, ne");
			printf ("\n    konscia persono. " CAPITAL_C_CIRCUMFLEX "i tiu programo povas " SMALL_G_CIRCUMFLEX "uste transskribi ion kiel la");
			printf ("\n    vorton \"gouverne\", sed ne la vorton \"gouvernement\" " SMALL_C_CIRCUMFLEX "ar la programo ne");
			printf ("\n    povas diveni ol " SMALL_C_CIRCUMFLEX "i lasta estas kombinata!");
			printf ("\n        Vere vi vidos la vortojn \"gouvernement\" kaj \"Kaapstad\" esti " SMALL_G_CIRCUMFLEX "uste");
			printf ("\n        transskribitaj " SMALL_C_CIRCUMFLEX "ar mi (la programisto) mane diris al programo kiujn");
			printf ("\n        estas la transskriboj de " SMALL_C_CIRCUMFLEX "i specifaj vortoj, sed tio ne povas esti la");
			printf ("\n        kazon de aliaj problemaj vortoj. Mi ne povas doni pretajn transskrinojn");
			printf ("\n        por " SMALL_C_CIRCUMFLEX "io de " SMALL_C_CIRCUMFLEX "i vortoj (tiel vi devos fidi la transskribiston de la");
			printf ("\n        programo), sed mi faris internan liston de ili. Por scii kiujn");
			printf ("\n        problemajn vortojn havas pretajn transskribojn, uzu la ordonon");
			printf ("\n        \"pncliste\" a" SMALL_U_BREVE " \"listepnc\"");
			printf ("\n    4 - " CAPITAL_C_CIRCUMFLEX "i tio estas programada problemo. Tio estas pri la litero \"e\" kiam " SMALL_C_CIRCUMFLEX "i");
			printf ("\n    tiu ne estas akcenta. En " SMALL_C_CIRCUMFLEX "i kazo, estas donita al vi a" SMALL_U_BREVE " \"{e}\" a" SMALL_U_BREVE " \"{"SMALL_E_DIAERESIS_IN_TEXT"}\".");
			printf ("\n    " CAPITAL_C_CIRCUMFLEX "ar ne estas facila labori kun " SMALL_C_CIRCUMFLEX "i speciala litero \""SMALL_E_DIAERESIS_IN_TEXT"\", la programo povas");
			printf ("\n    lasi \"e\" kie devus esti \""SMALL_E_DIAERESIS_IN_TEXT"\". Nur scii tion. Tio ne estas serioza");
			printf ("\n    problemo " SMALL_C_CIRCUMFLEX "ar la plej grava afero estas akcentigi la " SMALL_G_CIRCUMFLEX "ustan vokalon");
			printf ("\n* \"cjg\" a" SMALL_U_BREVE " \"conjuge\": donas la konjagucion de la vorto enmetita");
			printf ("\n    * Ekzemple: \"cjg edd\"");
			printf ("\n    Mi forte rekomendas al vi por nur enmeti verbojn sen anta" SMALL_U_BREVE "afikso. Kial?");
			printf ("\n    Bona ekzemplo estas la verbo \"naporg\" (na- " SMALL_C_CIRCUMFLEX "i tie estas anta" SMALL_U_BREVE "afikso), kies");
			printf ("\n    " SMALL_G_CIRCUMFLEX "usta conjugacion por la pasinta estas \"napors\", tamen la programo donos");
			printf ("\n    al vi \"niepors\" " SMALL_C_CIRCUMFLEX "ar la programo pensos ol " SMALL_C_CIRCUMFLEX "i vorto suferas abla" SMALL_U_BREVE "ton ka" SMALL_U_BREVE "ze");
			printf ("\n    " SMALL_C_CIRCUMFLEX "i ekstra litero \"a\".");
			printf ("\n");
			printf ("\n* \"log\": aktivigas a" SMALL_U_BREVE " malaktivigas la sistemajn mesa" SMALL_G_CIRCUMFLEX "ojn. Tio estas tre");
			printf ("\nutila rimedo pro kiu(j) laboras kun la kodo de " SMALL_C_CIRCUMFLEX "i programo.");
			printf ("\n");
			printf ("\n# " CAPITAL_C_CIRCUMFLEX "I TIO ESTAS LONGA TEKSTO, EBLE VI BEZONOS RULI SUPER " CAPITAL_C_CIRCUMFLEX "I TERMINALFENESTRON");
			printf ("\n(A" CAPITAL_U_BREVE " MAKSIMUMIGI " CAPITAL_C_CIRCUMFLEX "I TERMINALFENESTRON) POR VIDI LA KOMENCON DE " CAPITAL_C_CIRCUMFLEX "I TIU TEKSTO");

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
			printf ("\nERROR: Commande ne trohven. In fall os dwoi, neudte id commande \"helhp\"\n");
		break;
		case 2:
			printf ("\nERROR: Command not found. In case of doubt, use the command \"help\"\n");
		break;
		case 4:
			printf ("\nERRO: Comando n" SMALL_A_TILDE "o encontrado. Em caso de d" SMALL_U_ACUTE "vida, use o comando \"ajuda\"\n");
		break;
		case 6:
			printf ("\nERROR: Commande introuvable. En cas de doute, utilisez la commande \"aide\"\n");
		break;
		case 10:
			printf ("\nERARO: Netrovita ordono. En kazo de dubo, uzu la ordonon \"helpo\"\n");
		break;
	}
}

void invalid_argument (short int lang)
{
	switch (lang)
	{
		default:
		case 1:
			printf ("\nERROR: Invalid argument. In fall os dwoi, neudte id command \"helhp\"\n");
		break;
		case 2:
			printf ("\nERROR: Invalid argument. In case of doubt, use the command \"help\"\n");
		break;
		case 4:
			printf ("\nERRO: Argumento inv" SMALL_A_ACUTE "lido. Em caso de d" SMALL_U_ACUTE "vida, use o comando \"ajuda\" para obter ajuda\n");
		break;
		case 6:
			printf ("\nERROR: Argument invalide. En cas de doute, utilisez la commande \"aide\"\n");
		break;
		case 10:
			printf ("\nERARO: Nevalida argumento. En kazo de dubo, uzu la ordonon \"helpo\"\n");
		break;
	}
}

void too_long_word (short int lang)
{
	switch (lang)
	{
		default:
		case 1:
			printf ("\n* Tod werd est long... SEI (tik SEI!!!) tod est un composite werd, ter est un SMULK probabilitat od id programme ne hat ghohden ciautaung-ye transcribe id\n");
		break;
		case 2:
			printf ("\n* This word is long... IF (only IF!!!) it is a compound word, there is a SMALL probability that the program may not have properly transcribed it.\n");
		break;
		case 4:
			printf ("\n* Esta palavra " SMALL_E_ACUTE " longa... SE (somente SE!!!) isso for uma palavra composta, h" SMALL_A_ACUTE " uma PEQUENA probabilidade de que o programa n" SMALL_A_TILDE "o p" SMALL_O_CIRCUMFLEX "de transcrev" SMALL_E_CIRCUMFLEX "-la apropriadamente\n");
		break;
		case 6:
			printf ("\n* Ce mot est long... SI (et seulement SI!!!) c'est un mot compos" SMALL_E_ACUTE ", il y a une petite probabilit" SMALL_E_ACUTE " que le programme n'ait pas pu le transcrire de mani" SMALL_E_GRAVE "re appropri" SMALL_E_ACUTE "e\n");
		break;
		case 10:
			printf ("\n* " CAPITAL_C_CIRCUMFLEX "i tie vorto est tro longa... SE (kaj apena" SMALL_U_BREVE " SE!!!), ĉi tiu estas kombinita vorto, estas malgranda " SMALL_S_CIRCUMFLEX "anco ol la programo ne ta" SMALL_U_BREVE "ge povis transscribe tiun vorton\n");
		break;
	}
}
