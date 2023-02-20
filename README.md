# Ag2-Unesp-ArquivoTxt

Exercícios de Algoritmos 2 sobre Arquivo Texto

---
&nbsp;

EX 1 - Faça um programa que conte o número de vogais e consoantes de um arquivo texto.

&nbsp;

---

&nbsp;

EX 2 - Considere um arquivo de dados do tipo texto com o seguinte conteúdo:  
3  
Cida Souza   
5.5   
4.0   
José Silva e Silva   
7.5   
8.5   
Maria das Dores   
5.0   
6.0  

O arquivo acima é apenas um exemplo. Neste arquivo de alunos a primeira linha contém o 
número de alunos no arquivo. As linhas seguintes contém os seguintes dados:  

nome do aluno com no máximo 50 caracteres;  
nota da primeira prova;  
nota da segunda prova

Escreva um programa que imprima os nomes de todos os alunos que têm a média das duas 
notas menor que 5.0

&nbsp;

---

&nbsp;

EX 3 - Escreva um programa que armazene em um arquivo binário os dados de pessoas, de acordo 
com a estrutura a seguir.

struct pessoa{  
char nome[50];   
int idade;   
float altura;   
char telefone[10];   
} amigos[20]  

Em seguida, faça um programa que leia os dados do arquivo gerado anteriormente e salve-os num novo arquivo (formato texto) utilizando uma saída formatada.

FORMATO: 
[nome] tem [idade] anos e [altura] de altura.   
Tel.: [telefone].

&nbsp;

---

&nbsp;

EX 4 - Considere um arquivo texto (denominado “dados.txt”) que contém, em cada linha, as se-
guintes informações sobre os modelos de uma determinada agência:  
• nome (cadeia de 30 caracteres);  
• sexo (um caractere, podendo ser ‘M’ ou ‘F’);  
• cor dos olhos (um caractere, podendo ser ‘A’, ‘B’, ‘C’, ou ‘D’);  
• altura (valor real em metros);  
• peso (valor real em quilos).  
Faça um programa que separe este arquivo texto em dois arquivos binários de registros cujos 
campos são as informações descritas acima: o 1º arquivo deve conter apenas os modelos do 
sexo masculino (‘M’) e o 2º arquivo deve conter apenas os modelos do sexo feminino (‘F’).

&nbsp;

---
