/*
----------------------------------------------------------
Nome: Guilherme Goncalves      
----------------------------------------------------------

Faça um programa que conte o número de vogais e consoantes de um arquivo texto.
*/

#include <stdio.h>
#include <windows.h>
#define MAX 1000


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
    printf("1 - Mostrar conteudo do arquivo\n");
    printf("2 - Contar vogais do arquivo\n");
    printf("3 - Contar consoantes do arquivo\n");
    printf("Digite 0 para sair...\n");
    printf("\n---> ");
    scanf("%d", &opcao);

    return opcao;
}


// salva o conteudo digitado pelo usuario em um arquivo txt
void SalvaArquivo (char conteudo[]) {

    FILE *arquivo = fopen("arquivo.txt", "w");

    if (!arquivo) {
        printf("\nERRO AO ABRIR O ARQUIVO\n");
        printf("Pressione a tecla 'ENTER' para voltar ao menu...\n");
        getchar();
        return;
    }

    // salva caracter por caracter no arquivo
    for (int i = 0; conteudo[i]; i++) {
        fputc(conteudo[i], arquivo);
    }

    fclose(arquivo);
    printf("\nConteudo salvo no arquivo!\n");
    printf("Pressione a tecla 'ENTER' para voltar ao menu...\n");
    getchar();
}


// Mostra o conteudo do arquivo
void MostrarConteudo () {

    char caracter;
    system("cls");
    printf("----- CONTEUDO DO ARQUIVO -----\n\n");

    FILE *arquivo = fopen("arquivo.txt", "r");

    if (!arquivo) {
        printf("\nERRO AO ABRIR O ARQUIVO\n");
        printf("-------------------------------\n");
        printf("Pressione a tecla 'ENTER' para voltar ao menu...\n");
        LimparBuffer();
        getchar();
        return;
    }

    // enquanto o arquivo nao tiver chego ao fim, le os caracters e mostra na tela para o usuario
    while (!feof(arquivo)) {
        caracter = getc(arquivo);
        printf("%c", caracter);
    }

    fclose(arquivo);
    printf("\n-------------------------------\n");
    printf("Pressione a tecla 'ENTER' para voltar ao menu...\n");
    LimparBuffer();
    getchar();
}


// conta o numero de vogais ou consoantes escritos no arquivo
void Contagem (int escolha) {

    // escolha == 1 -> o usuario escolheu contar as vogais do arquivo
    // escolha == 2 -> o usuario escolheu contar as consoantes do arquivo

    int vogais = 0, consoantes = 0;
    char ch;
    system("cls");

    if (escolha == 1) {
        printf("----- CONTAGEM DE VOGAIS -----\n\n");
    }
    if (escolha == 2) {
        printf("----- CONTAGEM DE CONSOANTES -----\n\n");
    }

    FILE *arquivo = fopen("arquivo.txt", "r");
    if (!arquivo) {
        printf("\nERRO AO ABRIR O ARQUIVO\n");
        printf("-------------------------------\n");
        printf("Pressione a tecla 'ENTER' para voltar ao menu...\n");
        LimparBuffer();
        getchar();
        return;
    }

    while (!feof(arquivo)) {

        ch = getc(arquivo);

        // se o usuario escolheu a contagem de vogais
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            vogais++;
        }

        // se o usuario escolheu a contagem de consoantes
        if (ch == 'b' || ch == 'c' || ch == 'd' || ch == 'f' || ch == 'g' || ch == 'h' || ch == 'j' || 
            ch == 'k' || ch == 'l' || ch == 'm' || ch == 'n' || ch == 'p' || ch == 'q' || ch == 'r' || 
            ch == 's' || ch == 't' || ch == 'v' || ch == 'w' || ch == 'x' || ch == 'y' || ch == 'z') {
            consoantes++;
        }
    }

    fclose(arquivo);
    
    if (escolha == 1) {
        printf("Numero de vogais no conteudo do arquivo: %d", vogais);
        printf("\n------------------------------\n");
        printf("Pressione a tecla 'ENTER' para voltar ao menu...\n");
        LimparBuffer();
        getchar();
    }
    else {
        printf("Numero de consoantes no conteudo do arquivo: %d", consoantes);
        printf("\n----------------------------------\n");
        printf("Pressione a tecla 'ENTER' para voltar ao menu...\n");
        LimparBuffer();
        getchar();
    }
}


int main () {

    int opcao;
    char conteudo[MAX];

    printf("Digite o conteudo do arquivo (No maximo 1000 caracteres): ");
    fgets(conteudo, MAX, stdin);

    SalvaArquivo(conteudo);

    do {
        opcao = Menu();

        switch (opcao) {
            case 0: printf("Programa encerrado...\n"); break;
            case 1: MostrarConteudo(); break;
            case 2: Contagem(1); break;
            case 3: Contagem(2); break;
            default: break;
        }
    } while (opcao != 0);

    printf("-----------------------------");
    return 0;
}
