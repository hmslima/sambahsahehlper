# Sambahsa Hehlper

This is a program that I created for helping beginner students of the auxiliary language Sambahsa-Mundialect, it can conjugate verbs and transcribe any word to SPT. *If anything that I've said here is alien to you, maybe you should see my grammar in [this link](https://github.com/hmslima/sambahsacompletegrammar).*

## For users

In order to ask the conjugation of a verb you must use the command `cjg` or `conjuge` plus the verb, for example:

`cjg linekw`

In order to ask the transcription of a word to SPT, you must use the command `pnc` or `pronunce` plus the word, for example:

`pnc bahsa`

You can change the language of the texts of the program through the command `deflang` or `setlang`:

`deflang sb` for Sambahsa-Mundialect _(the standard language of the program)_

`deflang en` for English

`deflang pt` for Portuguese

`deflang fr` for French

`deflang eo` for Esperanto

For more informations, you can go to the "help" section of the program by using one of the commands below:

`hehlp`

`help`

`ajuda`

`aide`

`helpo`

`ayuda`

_Keep in mind that although these commands are translations of the Sambahsa word "hehlp", they will give you the text in the configured language, so if you configured the program to show texts in French (so you used `deflang fr`) and you use the command `help`, you still will get a text in French._

## For programmers

I have to say that I am not a programmer, actually I am not even a "computer guy" and probably this is the first and last program that I am doing. So know in advance that I am very amateur in programming and perhaps you may find the code of this program a mess, full of redundancies, full of bad practices and "childish". **But the program does the job and it's what matters!**

I chose C because it's the language I bothered to learn and I like the idea that I can run the compiled program without worring with dependencies, like would happen with interpreted languages. People may say that a person like me should use an easer language like Python, but C is easy enough for my purpose and I have no intention in using other language. And most of my strugglings are with the logic, that should be the same with any other language. Since this program is written in very simple C, I suppose this code can be compiled in any operating system, at least it compiles with no warning for me in Windows and Linux.

For helping me in the process, I use the command `log` to activate some messages that help me to identify where are the problems. These messages may look amateur to you, but they help me a lot.
