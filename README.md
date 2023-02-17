# Minishell

Minishell é um projeto da 42SP que consiste em recriar o shell do bash.

## Conceitos básicos

Envolve a criação de um programa que leia uma linha de comando, interprete os comandos e execute-os. O programa deve ser capaz de executar comandos simples, comandos com pipes, redirecionamento de entrada e saída, variáveis de ambiente, comandos internos e comandos externos.

minishell é basicamente em modificar a string de entrada do `readline` e para isso é necessário dividir o projeto em 3 partes:

1. Análise léxica
2. Expansão de variáveis
3. Parsing
4. Execução

## Análise léxica

A análise léxica é a primeira parte do projeto, onde é necessário separar a string de entrada em tokens. Para isso, é necessário identificar os caracteres especiais e separar a string de entrada em tokens. Os caracteres especiais são: `|`, `>`, `<`, `;`, `&`, `(`, `)`, ` ` e `\`. Os tokens são separados por espaços, exceto quando o caractere especial é precedido por uma barra invertida `\`. A barra invertida é um caractere especial que deve ser ignorado, exceto quando precede um caractere especial. A barra invertida também pode ser precedida por outra barra invertida, nesse caso, a barra invertida deve ser ignorada.

## Expansão de variáveis

A expansão de variáveis é a segunda parte do projeto, onde é necessário substituir as variáveis de ambiente por seus valores. Para isso, é necessário identificar as variáveis de ambiente e substituir por seus valores. As variáveis de ambiente são precedidas por um cifrão `$` e são formadas por letras maiúsculas e minúsculas, números e o caractere de sublinhado `_`. As variáveis de ambiente podem ser precedidas por uma barra invertida `\`, nesse caso, a barra invertida deve ser ignorada e a variável de ambiente deve ser considerada como um caractere normal.

## Parsing

O parsing é a terceira parte do projeto, onde é necessário separar os tokens em comandos. Para isso, é necessário identificar os tokens de redirecionamento de entrada e saída, os tokens de pipe e os tokens de separação de comandos. Os tokens de redirecionamento de entrada e saída são precedidos por um caractere especial `<` ou `>`, respectivamente. Os tokens de pipe são precedidos por um caractere especial `|`. Os tokens de separação de comandos são precedidos por um caractere especial `;`. Os tokens de separação de comandos também podem ser precedidos por um caractere especial `&`, nesse caso, o comando seguinte deve ser executado em background. Os tokens de separação de comandos também podem ser precedidos por um caractere especial `(`, nesse caso, o comando seguinte deve ser executado em background e o comando anterior deve ser executado em foreground. Os tokens de separação de comandos também podem ser precedidos por um caractere especial `)`, nesse caso, o comando anterior deve ser executado em background e o comando seguinte deve ser executado em foreground.

## Execução

A execução é a quarta parte do projeto, onde é necessário executar os comandos. Para isso, é necessário identificar os comandos internos e executá-los. Os comandos internos são: `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`. 

## Comandos internos

### echo

`echo` é um comando interno que imprime uma string na saída padrão. Deve pode utilizar o `-n` para não imprimir uma nova linha no final da string.

### cd

`cd` é um comando interno que muda o diretório atual. Deve pode utilizar o `..` para voltar ao diretório anterior.

### pwd

`pwd` é um comando interno que imprime o diretório atual na saída padrão.

### export

`export` é um comando interno que define uma variável de ambiente. Deve pode utilizar o `=` para definir o valor da variável de ambiente.

### unset

`unset` é um comando interno que remove uma variável de ambiente.

### env

`env` é um comando interno que imprime as variáveis de ambiente na saída padrão.

### exit

`exit` é um comando interno que encerra o programa.
