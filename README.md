# Sambahsa Hehlper

This is a program that I created for helping beginner students of the auxiliary language Sambahsa-Mundialect, it can conjugate verbs and transcribe any word to SPT. *If anything that I've said here is alien to you, maybe you should see my grammar in [this link](https://github.com/hmslima/sambahsacompletegrammar).*

**ATTENTION:** _*The SPT transcriptor of this program is deprecated, please use [JS Sambahsa Transcriptor](https://github.com/hmslima/JS-Sambahsapronunciator) instead. But the conjugagtor of this program still is recomendable*_

## For users

In order to ask the conjugation of a verb you must use the command `cjg` or `conjuge` plus the verb, for example:

`cjg linekw`

In order to ask the transcription of a word to SPT, you must use the command `pnc` or `pronunce` plus the word, for example:

`pnc bahsa`

_Remember, as I said, it's preferable that you use the transcriptor of JS Sambahsa Transcriptor_

You can get the conjugations of many verbs at once and store them in an file through the command `cjgd` or `conjugedatia`. For example:

`cjgd verbs.txt`

*All words inside the file must be separeted by lines, not by commas or spaces, so your file must be in this way:*

    ananec
    importe
    edd
    preges
    
*NOT in this way:*

    ananec, importe, edd, preges


***For Windows users:*** *pay attention that Windows usually hides the extension of files. Let's say you have the file "words.txt", Windows Explorer will show this file with the name "words". When you try to open a file, please don't forget to put the file extension.*

There is a similar command that is `pncd` or `pronuncedatia`, but this one gets for you the phonetic thanscriptions of words. For example:

`pncd words.txt`

*All warning said to the command `cjgd` are valid for the command `pncd`*

Still about the commands `cjgd` and `pncd`. Their output file is in TXT format. But you can use the command `html` to make these commands generate HTML files. For example:

    > html
    > cjgd verbs.txt

You can change the language of the texts of the program through the command `deflang` or `setlang`:

`deflang sb` for Sambahsa-Mundialect _(the standard language of the program)_

`deflang en` for English

`deflang pt` for Portuguese

`deflang fr` for French

`deflang eo` for Esperanto

One of the commands just below shows a table of declination cases. If you configure the program to show texts in a language that is not Sambahsa, you'll also get the translations of these cases.

`falls`

`cases`

`casos`

`cas`

`kazoj`

For more informations, you can go to the "help" section of the program by using one of the commands below:

`hehlp`

`help`

`ajuda`

`aide`

`helpo`

`ayuda`

_Keep in mind that although these commands are translations of the Sambahsa word "hehlp", they will give you the text in the configured language, so if you configured the program to show texts in French (so you used `deflang fr`) and you use the command `help`, you still will get a text in French._

### Download

You can download the executable in [this link](https://github.com/hmslima/sambahsahehlper/releases). I usually offer binaries for Linux and Windows.

## For programmers

I have to say that I am not a programmer, actually I am not even a "computer guy" and probably this is the first and last program that I am doing. So know in advance that I am very amateur in programming and perhaps you may find the code of this program a mess, full of redundancies, full of bad practices and "childish". **But the program does the job and it's what matters!**

I chose C because it's the language I bothered to learn and I like the idea that I can run the compiled program without worring with dependencies, like would happen with interpreted languages. People may say that a person like me should use an easer language like Python, but C is easy enough for my purpose and I have no intention in using other language. And most of my strugglings are with the logic, that should be the same with any other language. Since this program is written in very simple C, I suppose this code can be compiled in any operating system, at least it compiles with no warning for me in Windows and Linux.

For helping me in the process, I use the command `log` to activate some messages that help me to identify where are the problems. These messages may look amateur to you, but they help me a lot.
