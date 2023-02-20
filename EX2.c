/*
----------------------------------------------------------
Nome: Guilherme Goncalves
----------------------------------------------------------

Considere um arquivo de dados do tipo texto com o seguinte conteúdo:  
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
*/

#include <stdio.h>
#include <windows.h>
#define MAX 50


typedef struct {
    char nome[MAX];
    float nota1, nota2, media;
}DadosAlunos;

DadosAlunos Lista[MAX];
int Quant = 0; // quantidade de alunos cadastrados


// funcao para limpar o buffer do teclado
void LimparBuffer() {
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF) {}
    return;
}


// funcao que cria o menu para o usuario
int Menu () {

    int opcao;
    system("cls");
    printf("---------- M E N U ----------\n");
    printf("1 - Cadastrar novo aluno\n");
    printf("2 - Mostrar todos alunos\n");
    printf("3 - Mostrar alunos reprovados\n");
    printf("Digite 0 para sair...\n");
    printf("\n---> ");
    scanf("%d", &opcao);

    return opcao;
}


// cadastra o aluno 
void CadastroDeAluno () {

    system("cls");
    printf("----- CADASTRO DE ALUNO -----\n\n");

    if (Quant < MAX) {

        // leitura dos dados
        DadosAlunos a;
        printf("Nome: ");
        LimparBuffer();
        fgets(a.nome, MAX, stdin);
        printf("Nota da primeira prova: ");
        scanf("%f", &a.nota1);
        printf("Nota da segunda prova: ");
        scanf("%f", &a.nota2);
        a.media = (a.nota1 + a.nota2) / 2;
        Lista[Quant] = a;
        Quant++;

        printf("\nAluno Cadastrado!\n");
    }
    else {
        printf("ERRO: VETOR CHEIO\n");
    }
    printf("-----------------------------\n");
    printf("Pressione 'ENTER' para voltar ao menu...\n");
    LimparBuffer();
    getchar();
}


// mostra todos os alunos
void MostrarTodos () {

    system("cls");
    printf("----- MOSTRAR TODOS ALUNOS -----\n");


    // imprime na tela o nome e as notas dos alunos
    for (int i = 0; i < Quant; i++) {
        printf("\n");
        printf("Nome: %s", Lista[i].nome);
        printf("Nota da primeira prova: %.2f\n", Lista[i].nota1);
        printf("Nota da segunda prova: %.2f\n", Lista[i].nota2);
        printf("Media: %.2f\n", Lista[i].media);
    }
    printf("\n--------------------------------\n");
    printf("Pressione 'ENTER' para voltar ao menu...\n");
    LimparBuffer();
    getchar();
}


// mostra os alunos que foram reprovados
void MostrarReprovados () {

    system("cls");
    printf("----- MOSTRAR ALUNOS REPROVADOS -----\n");

    for (int i = 0; i < Quant; i++) {
        if (Lista[i].media < 5.0) { // mostra os alunos que tiveram media menor que 5
            printf("\n");
            printf("Nome: %s", Lista[i].nome);
            printf("Nota da primeira prova: %.2f\n", Lista[i].nota1);
            printf("Nota da segunda prova: %.2f\n", Lista[i].nota2);
            printf("Media: %.2f\n", Lista[i].media);
        }
    }

    printf("\n-------------------------------------\n");
    printf("Pressione 'ENTER' para voltar ao menu...\n");
    LimparBuffer();
    getchar();
}


// salva o vetor de alunos em arquivo txt formatado
void SalvaArquivo () {

    FILE *arquivo = fopen("Alunos.txt", "w");

    if (!arquivo) {
        printf("\nERRO AO SALVAR O ARQUIVO\n");
        return;
    }

    fprintf(arquivo, "%d\n", Quant);

    for (int i = 0; i < Quant; i++) {
        fprintf(arquivo, "%s", Lista[i].nome);
        fprintf(arquivo, "%.2f\n", Lista[i].nota1);
        fprintf(arquivo, "%.2f\n", Lista[i].nota2);
    }
    fclose(arquivo);
    printf("\nARQUIVO SALVO COM SUCESSO!\n");
}


// le o arquivo e salva os dados dos alunos no vetor
void LeArquivo () {

    DadosAlunos a;
    FILE *arquivo = fopen("Alunos.txt", "r");

    if (!arquivo) {
        printf("\nERRO AO LER O ARQUIVO\n");
        return;
    }

    fscanf(arquivo, "%d\n", &Quant);
    for (int i = 0; i < Quant; i++) {
        fgets(a.nome, MAX, arquivo);
        fscanf(arquivo, "%f\n", &a.nota1);
        fscanf(arquivo, "%f\n", &a.nota2);
        a.media = (a.nota1 + a.nota2) / 2;
        Lista[i] = a;
    }
    fclose(arquivo);
    printf("\nARQUIVO LIDO COM SUCESSO\n");
    printf("Pressione 'ENTER' para voltar ao menu...\n");
    getchar();
}


int main () {

    LeArquivo ();

    int opcao;
    do {
        opcao = Menu();

        switch (opcao) {
            case 0: printf("\nPrograma encerrado...\n"); break;
            case 1: CadastroDeAluno(); break;
            case 2: MostrarTodos(); break;
            case 3: MostrarReprovados(); break;
            default: break;
        }
    } while (opcao != 0);

    SalvaArquivo();

    printf("-----------------------------");
    return 0;
}
