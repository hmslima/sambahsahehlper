#include <stdio.h>
#include <string.h>

#include "special_characters.h"

extern short int lang;

// ############################################################
// ################## NAME OF THE SOFTWARE ####################

void logo ()
{
	printf ("###############################################################################\n");
	printf ("########################### SAMBAHSA HEHLPER v 2.11 ###########################\n");
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
			printf ("\nPre wey continuemos, yu tehrpte comprehende od tod est un simple programme quod");
			printf ("\nne correct ia rhalts im nudtors, ithan woidte od:");
			printf ("\n* Tod programme ghehdt analyse tik oin werd per ker");
			printf ("\n* Aunnecessar blankrewsa resultesient in stragn sulouk, schowi yu dehlcte,");
			printf ("\nmathalan, scribe \"pnc werd\", ne \"pnc  werd\" au \" pnc werd\" au \"pnc werd \"");
			printf ("\nKwe habmos un boidos?");
			printf ("\n");
			printf ("\nEn ia commandes:\n");
			printf ("\n* \"salg\" au \"exit\": exeiht id programme");
			printf ("\n* \"falls\": skaut un tabell om declination falls");
			printf ("\n* \"deflang\": meitht id bahsa ios programme");
			printf ("\n    * \"deflang sb\": pro sambahsa-mundialect");
			printf ("\n    * \"deflang pt\": pro portughesche");
			printf ("\n    * \"deflang en\": pro englisch");
			printf ("\n    * \"deflang es\": pro espaniol");
			printf ("\n    * \"deflang fr\": pro franceois");
			printf ("\n    * \"deflang eo\": pro esperanto");
			printf ("\n* \"pnc\" au \"pronunce\": daht id pronunciation ios insert werd");
			printf ("\n> ID PRONUNCIATOR TOS PROGRAMME EST OBSOLETE, PLAIS NEUD ID JAVASCRIPT");
			printf ("\n  SAMBAHSA PRONUNCIATOR");
			printf ("\n    * Mathalan: \"pnc plateau\" resultesiet in \"{platO:}\"");
			printf ("\n    Dayir id transcriptor, yu naudhte gwupes quar jects in ment. Bet pre wey");
			printf ("\n    natolcsiemos de to, woidte od tod programme est baygh competent in sien");
			printf ("\n    job, lakin ter sont sem RAR situations qua naudhe vies attention.");
			printf ("\n    1 - Mehmte od ia transcriptions pior sehkwnt id theoria. Mathalan in");
			printf ("\n    theoria id transcription os \"yoinkjiae\" est {yoynkjyAy}, bet in praxis ids");
			printf ("\n    radhen transcription est {yoynkjiAy} ob tod est meis pronunceable. Ithan ne");
			printf ("\n    pior sweurghte sei un werd kwehct baygh impronunceable");
			printf ("\n    2 - Alyo gohd exempel est \"Kaapstad\". Eger id est un afrikaans werd, ids");
			printf ("\n    correct transcription est {kA:pstat}, lakin tod werd esiet pronuncen kam");
			printf ("\n    {kaapstAd} in \"pure\" Sambahsa. Tod situation est commun con proper nomens.");
			printf ("\n    3 - Sehkwent id aum describen uper: tod est un software, ne un conscieus");
			printf ("\n    anghen. Tod programme khact correct-ye transcribe un werd kam \"defend\" med");
			printf ("\n    ids wi capacitats ob id khact gvaedde od tod werd est composen (hat un");
			printf ("\n    prefixe).");
			printf ("\n        Druve-ye yu vidsiete \"defend\" ed \"Kaapstad\" ses correct-ye");
			printf ("\n        transcriben ob io (is programmer) wihand-ye sieygim ei programme qua");
			printf ("\n        sont ia transcriptions tom specific werds, bet to maght ne ses id fall");
			printf ("\n        altern problematic werds. Khako dahe un tayar transcription pro vasya");
			printf ("\n        ex ta werds (yoitkwe yu tehrpsiete antruses id programmes");
			printf ("\n        transcriptor), bet kwohrim un internal liste tom werds. Kay woide qua");
			printf ("\n        problematic werds hant tayar transcriptions, uset id commande");
			printf ("\n        \"pncliste\" au \"listepnc\"");
			printf ("\n    4 - Tod est un programmation probleme. To est dayir id buksteiv \"e\" quan");
			printf ("\n    tod ne est accentuen. In tod fall, est daht vos auter \"{e}\" au \"{"SMALL_E_DIAERESIS_IN_TEXT"}\". Eger");
			printf ("\n    ne est facil diles con tod special harif \""SMALL_E_DIAERESIS_IN_TEXT"\", id programme maght linkwes");
			printf ("\n    un \"e\" quer dehlgiet wehse un \""SMALL_E_DIAERESIS_IN_TEXT"\". Tik woidte de to. To ne est un serieus");
			printf ("\n    probleme ob id meis important ject est accentue id correct voyel.");
			printf ("\n* \"pncd\" au \"pronuncedatia\": id sam os \"pnc\", bet pro hol datias");
			printf ("\n    * Mathalan: \"pncd werds.txt\"");
			printf ("\n    Ia werds dehlgent ses separen med lignes, ne med commas au rewos!");
			printf ("\n* \"cjg\" au \"conjuge\": daht id conjugation ios insert werd");
			printf ("\n    * Mathalan: \"cjg edd\"");
			printf ("\n    Un observation: yu kausiete od id conjugator daht werds samt sem");
			printf ("\n    buksteivs inter kawsa. Mathalan: id dahn preterit singular second person");
			printf ("\n    ios verb \"beud\" est \"bud(i)st(a)\", bet tod ne maynt od \"budista\" est un");
			printf ("\n    valid pronunciation. Yu tehrpte habe un critic ok ed gohd sense kay");
			printf ("\n    trehve id ciautaung pronunciation, quod est \"budst(a)\". Comleiste tod");
			printf ("\n    programme ed id sambahsa grammatic.");
			printf ("\n* \"cjgd\" au \"conjugedatia\": id sam os \"cjg\", bet pro hol datias");
			printf ("\n    * Mathalan: \"cjgd verbs.txt\"");
			printf ("\n    Ia werds dehlgent ses separen med lignes, ne med commas au rewos!");
			printf ("\n* \"html\": enwehrct id HTML mode pro ia commandes \"pncd\" ed \"cjgd\"");
			printf ("\n* \"htmlt\": enwehrct id TiddlyDict HTML mode pro ia commandes \"pncd\" ed \"cjgd\"");
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
			printf ("\nThe goal of this program is to help beginners by showing the pronunciation and");
			printf ("\nconjugation of the words.");
			printf ("\nBefore we continue, you must understand that this is a simple program that does");
			printf ("\nnot correct the user\'s mistakes, so know that:");
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
			printf ("\n    * \"setlang es\": for Spanish");
			printf ("\n    * \"setlang fr\": for French");
			printf ("\n    * \"setlang eo\": for Esperanto");
			printf ("\n* \"pnc\" or \"pronunce\": gives the pronunciation of the inserted word");
			printf ("\n> THE PRONUNCIATOR OF THIS PROGRAM IS OBSOLETE, PLEASE USE THE JAVASCRIPT");
			printf ("\n  SAMBAHSA PRONUNCIATOR");
			printf ("\n    * For example: \"pnc plateau\" will result in \"{platO:}\"");
			printf ("\n    About the transcriptor, you need to keep four things in mind. But before we");
			printf ("\n    go forward in this discussion, know that this program is very competent in");
			printf ("\n    its job, however there are some RARE situations that require your");
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
			printf ("\n    3 - Following the reasoning described above: this is a software, not a");
			printf ("\n    conscious person. This program cannot correctly transcribe a word like");
			printf ("\n    \"defend\" through its own capacities because the program cannot guess that");
			printf ("\n    this is a compound word (it has a prefix).");
			printf ("\n        Actually you'll see \"defend\" and \"Kaapstad\" being correctly");
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
			printf ("\n* \"pncd\" or \"pronuncedatia\": the same as \"pnc\", but for whole files");
			printf ("\n    * For example: \"pncd werds.txt\"");
			printf ("\n    The words must be separeted by lines, not by commas or spaces!");
			printf ("\n* \"cjg\" or \"conjuge\": gives the conjugation of the inserted word");
			printf ("\n    * For example: \"cjg edd\"");
			printf ("\n    An observation: you\'ll note that the conjugator gives words with some");
			printf ("\n    letters between parenthesis. For example: it given past singular second");
			printf ("\n    person of the verb \"beud\" is \"bud(i)st(a)\", but it doesn\'t mean that");
			printf ("\n    \"budista\" is a valid pronunciation. You must have a critical eye and good");
			printf ("\n    sense to find the appropriate pronunciation, which is \"budst(a)\". Ally this");
			printf ("\n    program with the grammar.");
			printf ("\n* \"cjgd\" or \"conjugedatia\": the same as \"cjg\", but for whole files");
			printf ("\n    * For example: \"cjgd verbs.txt\"");
			printf ("\n    The words must be separeted by lines, not by commas or spaces!");
			printf ("\n* \"html\": activates the HTML mode for the commands \"pncd\" and \"cjgd\"");
			printf ("\n* \"htmlt\": activates the TiddlyDict HTML mode for the commands \"pncd\" and \"cjgd\"");
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
			printf ("\n    * \"deflang es\": para espanhol");
			printf ("\n    * \"deflang fr\": para franc" SMALL_E_CIRCUMFLEX "s");
			printf ("\n    * \"deflang eo\": para esperanto");
			printf ("\n* \"pnc\" ou \"pronunce\": d" SMALL_A_ACUTE " a pron" SMALL_U_ACUTE "ncia da palavra inserida");
			printf ("\n> O PRONUNCIADOR DESTE PROGRAMA EST" CAPITAL_A_ACUTE " OBSOLETO, POR FAVOR USE O PRONUNCIADOR");
			printf ("\n  DE SAMBAHSA EM JAVASCRIPT");
			printf ("\n    * Por exemplo: \"pnc plateau\" resultar" SMALL_A_ACUTE " em \"{platO:}\"");
			printf ("\n    Sobre o transcritor, voc" SMALL_E_CIRCUMFLEX " precisa ter quatro coisas na sua mente. Mas antes");
			printf ("\n    de prosseguirmos, saiba que este programa " SMALL_E_ACUTE " muito competente em seu");
			printf ("\n    trabalho, entretanto h" SMALL_A_ACUTE " algumas RARAS situa" SMALL_C_CEDILLA SMALL_O_TILDE "es que requerem a sua aten" SMALL_C_CEDILLA SMALL_A_TILDE "o.");
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
			printf ("\n    pessoa consciente. Este programa n" SMALL_A_TILDE "o pode transcrever corretamente uma");
			printf ("\n    palavra como \"defend\" pela sua pr" SMALL_O_ACUTE "pria capacidade porque o programa n" SMALL_A_TILDE "o");
			printf ("\n    pode adivinhar que esta palavra " SMALL_E_ACUTE " composta (tem um prefixo).");
			printf ("\n        Na verdade, voc" SMALL_E_CIRCUMFLEX " ver" SMALL_A_ACUTE " \"defend\" e \"Kaapstad\" serem transcritos");
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
			printf ("\n* \"pncd\" ou \"pronuncedatia\": o mesmo que \"pnc\", mas para arquivos inteiros");
			printf ("\n    * Por examplo: \"pncd werds.txt\"");
			printf ("\n    As palavras devem ser separadas por linhas, não por v" SMALL_I_ACUTE "rgulas ou espa" SMALL_C_CEDILLA "os!");
			printf ("\n* \"cjg\" ou \"conjuge\": d" SMALL_A_ACUTE " a conjuga" SMALL_C_CEDILLA SMALL_A_TILDE "o da palavra inserida");
			printf ("\n    * Por examplo: \"cjg edd\"");
			printf ("\n    Uma observa" SMALL_C_CEDILLA SMALL_A_TILDE "o: voc" SMALL_E_CIRCUMFLEX " notar" SMALL_A_ACUTE " que o conjugador d" SMALL_A_ACUTE " verbos com algumas");
			printf ("\n    letras entre par" SMALL_E_CIRCUMFLEX "nteses. Por exemplo: a segunda pessoa do singular do");
			printf ("\n    pret" SMALL_E_ACUTE "rito do verbo \"beud\" que o programa d" SMALL_A_ACUTE " " SMALL_E_ACUTE " \"bud(i)st(a)\", mas isso");
			printf ("\n    n" SMALL_A_TILDE "o significa que \"budista\" " SMALL_E_ACUTE " uma pron" SMALL_U_ACUTE "ncia v" SMALL_A_ACUTE "lida. Voc" SMALL_E_CIRCUMFLEX " tem que ter um");
			printf ("\n    olhar cr" SMALL_I_ACUTE "tico e bom senso para achar a pron" SMALL_U_ACUTE "ncia apropriada, que " SMALL_E_ACUTE "");
			printf ("\n    \"budst(a)\". Alie este programa com a gram" SMALL_A_ACUTE "tica.");
			printf ("\n* \"cjgd\" ou \"conjugedatia\": o mesmo que \"cjg\", mas para arquivos inteiros");
			printf ("\n    * Por examplo: \"cjgd verbs.txt\"");
			printf ("\n    As palavras devem ser separadas por linhas, não por v" SMALL_I_ACUTE "rgulas ou espa" SMALL_C_CEDILLA "os!");
			printf ("\n* \"html\": ativa o modo HTML para os comandos \"pncd\" e \"cjgd\"");
			printf ("\n* \"htmlt\": ativa o modo HTML TiddlyDict para os comandos \"pncd\" e \"cjgd\"");
			printf ("\n");
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
			printf ("\n    * \"deflang es\" : espagnol");
			printf ("\n    * \"deflang fr\" : fran" SMALL_C_CEDILLA "ais");
			printf ("\n    * \"deflang eo\" : esperanto");
			printf ("\n* \"pnc\" ou \"pronunce\" : donne la prononciation du mot ins" SMALL_E_ACUTE "r" SMALL_E_ACUTE "");
			printf ("\n> LE PRONONCIATEUR DE CE PROGRAMME EST OBSOL" CAPITAL_E_GRAVE "TE, VEUILLEZ UTILISER LE");
			printf ("\n  PRONONCIATEUR DE SAMBAHSA DANS JAVASCRIPT");
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
			printf ("\n    un impact sur la prononciation.");
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
		case 8:
		case 9:
			printf ("\nAYUDA");
			printf ("\n-------------------------------------------------------------------------------\n");
			printf ("\nEste programa fue creado por el brasile" SMALL_N_TILDE "o Henrique Matheus da Silva Lima para");
			printf ("\nla lengua sambahsa-mundialect. Durante todo el proceso de creaci" SMALL_O_ACUTE "n de este");
			printf ("\nprograma, " SMALL_E_ACUTE "l cont" SMALL_O_ACUTE " con la ayuda del creador de la lengua, el franc" SMALL_E_ACUTE "s Olivier");
			printf ("\nSimon.");
			printf ("\nEl prop" SMALL_O_ACUTE "sito de este programa es ayudar a los principiantes mostrando la");
			printf ("\npronunciaci" SMALL_O_ACUTE "n y conjugaci" SMALL_O_ACUTE "n de palabras.");
			printf ("\nAntes de continuar, debe comprender que este es un programa simple que");
			printf ("\nno corrige los errores del usuario, as" SMALL_I_ACUTE " que tenga en cuenta que:");
			printf ("\n* Este programa puede analizar solo una palabra a la vez");
			printf ("\n* Los espacios en blanco innecesarios dar" SMALL_A_ACUTE "n lugar a un comportamiento extra" SMALL_N_TILDE "o,");
			printf ("\nas" SMALL_I_ACUTE " que, por ejemplo, deber" SMALL_I_ACUTE "a escribir \"pnc werd\", no \"pnc  werd\" o");
			printf ("\n\" pnc werd\" o \"pnc werd \". " INVERTED_QUESTION_MARK "Tenemos un trato?");
			printf ("\n");
			printf ("\nAqu" SMALL_I_ACUTE " est" SMALL_A_ACUTE "n los comandos:\n");
			printf ("\n* \"salir\": cierra el programa");
			printf ("\n* \"casos\": muestra una tabla de casos de declinaci" SMALL_O_ACUTE "n");
			printf ("\n* \"deflang\": cambia el idioma del programa");
			printf ("\n    * \"deflang sb\": para sambahsa-mundialect");
			printf ("\n    * \"deflang pt\": para portugu" SMALL_E_ACUTE "s");
			printf ("\n    * \"deflang en\": para ingl" SMALL_E_ACUTE "s");
			printf ("\n    * \"deflang es\": para espa" SMALL_N_TILDE "ol");
			printf ("\n    * \"deflang fr\": para franc" SMALL_E_ACUTE "s");
			printf ("\n    * \"deflang eo\": para esperanto");
			printf ("\n* \"pnc\" o \"pronunce\": proporciona la pronunciaci" SMALL_O_ACUTE "n de la palabra insertada");
			printf ("\n> EL PRONUNCIADOR DE ESTE PROGRAMA EST" CAPITAL_A_ACUTE " OBSOLETO, POR FAVOR UTILICE EL");
			printf ("\n  PRONUNCIADOR DE SAMBAHSA EM JAVASCRIPT");
			printf ("\n    * Por ejemplo: \"pnc plateau\" dar" SMALL_A_ACUTE " como resultado \"{platO:}\"");
			printf ("\n    Sobre el transcriptor, debe tener cuatro cosas en mente. Pero antes de");
			printf ("\n    proceder, sepa que este programa es muy competente en su trabajo,");
			printf ("\n    sin embargo, hay algunas situaciones RARAS que requieren su atenci" SMALL_O_ACUTE "n.");
			printf ("\n    1 - Recuerda que estas transcripciones siguen demasiada teor" SMALL_I_ACUTE "a. Por");
			printf ("\n    ejemplo, en teor" SMALL_I_ACUTE "a la transcripci" SMALL_O_ACUTE "n de \"yoinkjiae\" es {yoynkjyAy}, pero su");
			printf ("\n    transcripci" SMALL_O_ACUTE "n recomendada es {yoynkjiAy} porque esto es m" SMALL_A_ACUTE "s pronunciable.");
			printf ("\n    As" SMALL_I_ACUTE " que no te preocupes si una palabra parece ser impronunciable.");
			printf ("\n    2 - Otro bueno ejemplo es \"Kaapstad\". Ya que esa es una palabra afrik" SMALL_A_ACUTE "ans,");
			printf ("\n    su transcripci" SMALL_O_ACUTE "n correcta es {kA:pstat}, sin embargo, esta palabra");
			printf ("\n    se pronunciar" SMALL_I_ACUTE "a como {kaapstAd} en sambahsa \"puro\". Esta situaci" SMALL_O_ACUTE "n es com" SMALL_U_ACUTE "n");
			printf ("\n    con sustantivos propios.");
			printf ("\n    3 - Siguiendo el razonamiento descrito anteriormente: este es un software,");
			printf ("\n    no una persona consciente. Este programa no puede transcribir correctamente");
			printf ("\n    una palabra como \"defend\" por su propia capacidad porque el programa no");
			printf ("\n    puedes adivinar que esta palabra es compuesta (tiene un prefijo).");
			printf ("\n        En verdad, ver" SMALL_A_ACUTE " \"defend\" y \"Kaapstad\" transcritos correctamente");
			printf ("\n        porque yo (el programador) le dije manualmente al programa");
			printf ("\n        cu" SMALL_A_ACUTE "les son las transcripciones de esas palabras espec" SMALL_I_ACUTE "ficas, pero esto");
			printf ("\n        puede no ser el caso para otras palabras problem" SMALL_A_ACUTE "ticas. No puedo dar");
			printf ("\n        una transcripci" SMALL_O_ACUTE "n lista para todas esas palabras (para que tendr" SMALL_A_ACUTE " que");
			printf ("\n        confiar en el transcriptor del programa), pero hice una lista");
			printf ("\n        interna que muestra qu" SMALL_E_ACUTE " palabras problem" SMALL_A_ACUTE "ticas ya han sido");
			printf ("\n        transcritas manualmente, use el comando \"pncliste\" o \"listepnc\"");
			printf ("\n    4 - Este es un problema de programaci" SMALL_O_ACUTE "n. Se trata de la letra \"e\" cuando no");
			printf ("\n    tiene un acento t" SMALL_O_ACUTE "nico. En ese caso, se le dar" SMALL_A_ACUTE " \"{e}\" o \"{" SMALL_E_DIAERESIS_IN_TEXT "}\". Una vez que");
			printf ("\n    no es f" SMALL_A_ACUTE "cil tratar con este car" SMALL_A_ACUTE "cter especial \"" SMALL_E_DIAERESIS_IN_TEXT "\", el programa puede dar");
			printf ("\n    un \"e\" donde deber" SMALL_I_ACUTE "a estar un \"" SMALL_E_DIAERESIS_IN_TEXT "\". Solo s" SMALL_E_ACUTE " eso. No es un problema grave");
			printf ("\n    porque lo m" SMALL_A_ACUTE "s importante es acentuar t" SMALL_O_ACUTE "nicamente la vocal correcta.");
			printf ("\n* \"pncd\" o \"pronuncedatia\": igual que \"pnc\", pero para archivos completos");
			printf ("\n    * Por ejemplo: \"pncd werds.txt\"");
			printf ("\n    " INVERTED_EXCLAMATION_MARK "Las palabras deben estar separadas por l" SMALL_I_ACUTE "neas, no por comas o espacios!");
			printf ("\n* \"cjg\" o \"conjuge\": da la conjugaci" SMALL_O_ACUTE "n de la palabra insertada");
			printf ("\n    * Por ejemplo: \"cjg edd\"");
			printf ("\n    Una nota: notar" SMALL_A_ACUTE " que el conjugador da verbos con algunas letras");
			printf ("\n    entre par" SMALL_E_ACUTE "ntesis. Por ejemplo: la segunda persona del singular del");
			printf ("\n    tiempo pasado del verbo \"beud\" que el programa da es \"bud(i)st(a)\", pero");
			printf ("\n    eso no significa que \"budista\" sea una pronunciaci" SMALL_O_ACUTE "n v" SMALL_A_ACUTE "lida. Tenga que");
			printf ("\n    tener uno ojo cr" SMALL_I_ACUTE "tico y sentido com" SMALL_U_ACUTE "n para encontrar la pronunciaci" SMALL_O_ACUTE "n");
			printf ("\n    correcta, que es \"budst(a)\". Combina este programa con la gram" SMALL_A_ACUTE "tica.");
			printf ("\n* \"cjgd\" o \"conjugedatia\": igual que \"cjg\", pero para archivos completos");
			printf ("\n    * For example: \"cjgd verbs.txt\"");
			printf ("\n    " INVERTED_EXCLAMATION_MARK "Las palabras deben estar separadas por l" SMALL_I_ACUTE "neas, no por comas o espacios!");
			printf ("\n* \"html\": activa el modo HTML para los comandos \"pncd\" y \"cjgd\"");
			printf ("\n* \"htmlt\": activa el modo HTML TiddlyDict para los comandos \"pncd\" y \"cjgd\"");
			printf ("\n");
			printf ("\n* \"log\": habilita o deshabilita las mensajes del sistema. Esto es muy");
			printf ("\n" SMALL_U_ACUTE "til para quienes maneja el c" SMALL_O_ACUTE "digo de este programa. Las mensajes del sistema");
			printf ("\nson todas en ingl" SMALL_E_ACUTE "s.");
			printf ("\n");
			printf ("\n# ESTE TEXTO ES LARGO, TAL VEZ HAY QUE RODAR ESTA VENTANA EN SU EMULADOR");
			printf ("\nDE TERMINAL (O MAXIMIZAR ESTA VENTANA) PARA VER EL INICIO DE ESTE TEXTO");

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
			printf ("\n    * \"deflang es\": por la hispana");
			printf ("\n    * \"deflang fr\": por la franca");
			printf ("\n    * \"deflang eo\": por esperanto");
			printf ("\n* \"pnc\" a" SMALL_U_BREVE " \"pronunce\": donas la prononcon de la vorto enmetita");
			printf ("\n> LA PRONONCISTO DE " CAPITAL_C_CIRCUMFLEX "I PROGRAMO ESTAS MALMODERNA, BONVOLU UZI LA JAVASCRIPT-A");
			printf ("\n  PRONONCISTO DE SAMBASO");
			printf ("\n    * Ekzemple: \"pnc plateau\" resultos en \"{platO:}\"");
			printf ("\n    Pri la transskribisto, tenu en menso kvar a" SMALL_J_CIRCUMFLEX "ojn. Sed anta" SMALL_U_BREVE " ni iros");
			printf ("\n    anta" SMALL_U_BREVE "e en " SMALL_C_CIRCUMFLEX "i tiu diskuto, sciu ol " SMALL_C_CIRCUMFLEX "i tiu programo estas tre kompetenta en");
			printf ("\n    " SMALL_G_CIRCUMFLEX "ia laboro, tamen estas kelkaj MALOFTAJ situacioj kio petas vian atenton");
			printf ("\n    1 - Memoru ol " SMALL_C_CIRCUMFLEX "i tiu transsckriboj tro sekvas teorion. Ekzemple:");
			printf ("\n    en teorio, la transskribo de \"yoinkjiae\" estas {yoynkjyAy}, sed en");
			printf ("\n    praktiko " SMALL_G_CIRCUMFLEX "ia sugestan transskribo estas {yoynkjiAy} " SMALL_C_CIRCUMFLEX "ar " SMALL_C_CIRCUMFLEX "i tiu estas pli");
			printf ("\n    prononcebla. Tial ne tro zorgu " SMALL_C_CIRCUMFLEX "u vorto " SMALL_S_CIRCUMFLEX "ajnas esti neprononcebla");
			printf ("\n    2 - Alia bona ekzemplo estas \"Kaapstad\". " CAPITAL_C_CIRCUMFLEX "ar estas afrikansa vorto, " SMALL_G_CIRCUMFLEX "ia");
			printf ("\n    " SMALL_G_CIRCUMFLEX "usta transskribo estas {kA:pstat}, tamen " SMALL_C_CIRCUMFLEX "i tiu vorto estus prononcita");
			printf ("\n    kiel {kaapstAd} en \"pura\" sambaso. " CAPITAL_C_CIRCUMFLEX "i situacio estas komuna kun propraj");
			printf ("\n    nomoj.");
			printf ("\n    3 - Sekvanta la priskribitan rezonon super: " SMALL_C_CIRCUMFLEX "i tiu estas programaro, ne");
			printf ("\n    konscia persono. " CAPITAL_C_CIRCUMFLEX "i tiu programo ne povas " SMALL_G_CIRCUMFLEX "uste transskribi ion kiel la");
			printf ("\n    vorton \"defend\" per " SMALL_G_CIRCUMFLEX "ia propra kapablo " SMALL_C_CIRCUMFLEX "ar la programo ne povas diveni ol");
			printf ("\n    " SMALL_C_CIRCUMFLEX "i vorto estas kombinita (tio havas prefikson).");
			printf ("\n        Vere vi vidos la vortojn \"defend\" kaj \"Kaapstad\" esti " SMALL_G_CIRCUMFLEX "uste");
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
			printf ("\n    probleme ob id meis important ject est accentue id correct voyel.");
			printf ("\n* \"pncd\" a" SMALL_U_BREVE " \"pronuncedatia\": la samo de \"pnc\", sed por tutaj dosieroj");
			printf ("\n    * Ekzemple: \"pncd vortoj.txt\"");
			printf ("\n    La vortoj devas esti separitaj per linioj, ne per komoj a" SMALL_U_BREVE " spacoj!");
			printf ("\n* \"cjg\" a" SMALL_U_BREVE " \"conjuge\": donas la konjagucion de la vorto enmetita");
			printf ("\n    * Ekzemple: \"cjg edd\"");
			printf ("\n    Alia rimarko: vi rimarkos ol la konjugacisto donas vortojn kun kelkaj");
			printf ("\n    literoj inter parentezoj. Ekzemple: la donita preterita ununombra dua");
			printf ("\n    persono de la verbo \"beud\" estas \"bud(i)st(a)\", sed tio ne signifas ol");
			printf ("\n    \"budista\" estas valida prononco. Vi devas havi kritikan rigardon kaj bonan");
			printf ("\n    sa" SMALL_G_CIRCUMFLEX "on por trovi la ta" SMALL_U_BREVE "ga  prononcon, kiu estas \"budst(a)\". Aligu " SMALL_C_CIRCUMFLEX "i");
			printf ("\n    programon kun la gramatiko.");
			printf ("\n* \"cjgd\" a" SMALL_U_BREVE " \"conjugedatia\": la samo de \"cjg\", sed por tutaj dosieroj");
			printf ("\n    * Ekzemple: \"cjgd verboj.txt\"");
			printf ("\n    La vortoj devas esti separitaj per linioj, ne per komoj a" SMALL_U_BREVE " spacoj!");
			printf ("\n* \"html\": aktivigas la HTML-modon por la ordonoj \"pncd\" kaj \"cjgd\"");
			printf ("\n* \"htmlt\": aktivigas la TiddlyDict-HTML-modon por la ordonoj \"pncd\" kaj \"cjgd\"");
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
		case 8:
		case 9:
			printf ("\nERROR: Comando no v" SMALL_A_ACUTE "lido. En caso de duda, utilice el comando \"ayuda\" para obtener ayuda.\n");
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
		case 8:
		case 9:
			printf ("\nERROR: Argumento no v" SMALL_A_ACUTE "lido. En caso de duda, utilice el comando \"ayuda\" para obtener ayuda.\n");
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
		case 8:
		case 9:
			printf ("\n* Esta palabra es larga... SI (" INVERTED_EXCLAMATION_MARK "solo SI!) Esta es una palabra compuesta, existe una PEQUE" CAPITAL_N_TILDE "A probabilidad de que el programa no pueda transcribirla correctamente\n");
		break;
		case 10:
			printf ("\n* " CAPITAL_C_CIRCUMFLEX "i tie vorto est tro longa... SE (kaj apena" SMALL_U_BREVE " SE!!!), ĉi tiu estas kombinita vorto, estas malgranda " SMALL_S_CIRCUMFLEX "anco ol la programo ne ta" SMALL_U_BREVE "ge povis transscribe tiun vorton\n");
		break;
	}
}
