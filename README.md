# Spelling Checker

This is a spelling checker for brazilian portuguese; the second project for my CI067 programming class.

Here we receive a text via standard input: (example from the project specs)

>Para que o pocessador possa interromper a execução de uma tarefa
e retornar a ela mais tarde, sem corromper seu estado interno,
é necessário definir operações para salvar e restaurrar o
contexto da tarefa.

>O ato de salvar os valores do contexto atual em seu TCB e
possivelmente restaurar o contexto de outra tarefa, previamente
salvo em outro TCB, é denominado "troca de contexto".

And then the text with `[]`'s around mispelled words will be returned on standard output:

>Para que o [pocessador] possa interromper a execução de uma tarefa
e retornar a ela mais tarde, sem corromper seu estado interno, 
é necessário definir operações para salvar e [restaurrar] o
contexto da tarefa.

>O ato de salvar os valores do contexto atual em seu [TCB] e
possivelmente restaurar o contexto de outra tarefa, previamente
salvo em outro [TCB], é denominado "troca de contexto".

## Compiling

Just run `make` and the `ortografia` binary will be compiled.

There are also avalible the following targets:

* `clean`: to remove object files (.o)
* `purge`: clean; plus remove the binary file
* `compress`: generate a .tar.gz ready to send for my profesor 

## Dependencies

* gcc to compile the code
* wbrazilian package for the list of words 
* make to run the targets
* tar to generate tarball
