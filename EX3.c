/*
----------------------------------------------------------
Nome: Guilherme Goncalves     
----------------------------------------------------------

Escreva um programa que armazene em um arquivo binário os dados de pessoas, de acordo 
com a estrutura a seguir.

struct pessoa{ 
char nome[50]; 
int idade; 
float altura; 
char telefone[10]; 
} amigos[20]

Em seguida, faça um programa que leia os dados do arquivo gerado anteriormente e salve-
os num novo arquivo (formato texto) utilizando uma saída formatada.

FORMATO: 
-------- 
[nome] tem [idade] anos e [altura] de altura. 
Tel.: [telefone].
*/

#include <stdio.h>
#include <windows.h>
#include <string.h>
#define MAX_VETOR 20
#define MAX_STRING 50


typedef struct {
    char nome[MAX_STRING], telefone[MAX_STRING];
    int idade;
    float altura;
}Pessoa;


// funcao para limpar o buffer do teclado
void LimparBuffer() {
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF) {}
    return;
}


// cria o menu para o usuario
int Menu () {

    int opcao;
    system("cls");
    printf("---------- M E N U ----------\n");
    printf("1 - Cadastrar nova pessoa\n");
    printf("2 - Salvar em arquivo formatado\n");
    printf("3 - Mostra arquivo formatado\n");
    printf("Digite 0 para sair...\n");
    printf("\n---> ");
    scanf("%d", &opcao);

    return opcao;
}


// cadastra nova pessoa e armazena em um arquivo binario
void CadastrarPessoa () {
    
    Pessoa p;

    system("cls");
    printf("----- CADASTRO DE PESSOA -----\n\n");

    FILE *arqBin = fopen("arquivoBinario.dat", "ab");

    if (!arqBin) {
        printf("\nERRO AO ABRIR O ARQUIVO\n");
        printf("------------------------------\n");
        printf("Pressione a tecla 'ENTER' para voltar ao menu...\n");
        LimparBuffer();
        getchar();
        return;
    }

    // leitura dos dados
    printf("Nome: ");
    LimparBuffer();
    fgets(p.nome, MAX_STRING, stdin);
    strtok(p.nome, "\n"); // para tirar a quebra de linha na hora de formatar a string
    printf("Telefone: ");
    fgets(p.telefone, MAX_STRING, stdin);
    printf("Idade: ");
    scanf("%d", &p.idade);
    printf("Altura: ");
    scanf("%f", &p.altura);

    // salvando no arquivo
    fwrite(&p, sizeof(Pessoa), 1, arqBin);
    fclose(arqBin);
    
    printf("\nPessoa cadastrada!\n");
    printf("------------------------------\n");
    printf("Pressione a tecla 'ENTER' para voltar ao menu...\n");
    LimparBuffer();
    getchar();
}


// salva os dados em um arquivo formatado
void SalvarEFormatar () {

    Pessoa p;

    system("cls");
    printf("----- SALVAR EM ARQUIVO FORMATADO -----\n\n");

    FILE *arqFormatado = fopen("arquivoFormatado.txt", "w");
    FILE *arqBin = fopen("arquivoBinario.dat", "rb");

    if (!arqFormatado || !arqBin) {
        printf("\nERRO AO ABRIR O ARQUIVO\n");
        printf("---------------------------------------\n");
        printf("Pressione a tecla 'ENTER' para voltar ao menu...\n");
        LimparBuffer();
        getchar();
        return;
    }

    while (fread(&p, sizeof(Pessoa), 1, arqBin) == 1) {
        fprintf(arqFormatado, "%s tem %d anos e %.2f de altura\n", p.nome, p.idade, p.altura);
        fprintf(arqFormatado, "Tel.: %s", p.telefone);
    }

    fclose(arqBin);
    fclose(arqFormatado);

    printf("Arquivo formatado!\n");
    printf("---------------------------------------\n");
    printf("Pressione a tecla 'ENTER' para voltar ao menu...\n");
    LimparBuffer();
    getchar();
}


// mostra o arquivo formatado na tela
void MostrarArquivoF () {

    char c;

    system("cls");
    printf("----- ARQUIVO FORMATADO -----\n\n");

    FILE *arqFormatado = fopen("arquivoFormatado.txt", "r");

    if (!arqFormatado) {
        printf("\nERRO AO ABRIR O ARQUIVO\n");
        printf("---------------------------------------\n");
        printf("Pressione a tecla 'ENTER' para voltar ao menu...\n");
        LimparBuffer();
        getchar();
        return;
    }

    while (!feof(arqFormatado)) {
        c = getc(arqFormatado);
        printf("%c", c);
    }

    fclose(arqFormatado);
    printf("\n\n---------------------------------------\n");
    printf("Pressione a tecla 'ENTER' para voltar ao menu...\n");
    LimparBuffer();
    getchar();
}


int main () {

    int opcao;
    do {
        opcao = Menu();

        switch (opcao) {
            case 0: printf("\nPrograma encerrado...\n"); break;
            case 1: CadastrarPessoa(); break;
            case 2:  SalvarEFormatar(); break;
            case 3: MostrarArquivoF(); break;
            default: break;
        }
    } while (opcao != 0);

    printf("-----------------------------");
    return 0;
}
