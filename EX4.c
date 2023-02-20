/*
----------------------------------------------------------
Nome: Guilherme Goncalves      
----------------------------------------------------------

Considere um arquivo texto (denominado “dados.txt”) que contém, em cada linha, as se-
guintes informações sobre os modelos de uma determinada agência:  
• nome (cadeia de 30 caracteres);  
• sexo (um caractere, podendo ser ‘M’ ou ‘F’);  
• cor dos olhos (um caractere, podendo ser ‘A’, ‘B’, ‘C’, ou ‘D’);  
• altura (valor real em metros);  
• peso (valor real em quilos).  
Faça um programa que separe este arquivo texto em dois arquivos binários de registros cujos 
campos são as informações descritas acima: o 1º arquivo deve conter apenas os modelos do 
sexo masculino (‘M’) e o 2º arquivo deve conter apenas os modelos do sexo feminino (‘F’).
*/


#include <stdio.h>
#include <windows.h>
#include <ctype.h>
#define MAX_STRING 30


// struct para cadastrar os modelos
typedef struct {
    char nome[MAX_STRING], sexo, olhos;
    float altura, peso;
}Modelo;


// ----- delcaracao das funcoes -----
void LimparBuffer();
int Menu();
void CadastrarModelo();
void DividirArquivos(Modelo m);
void MostrarModelos(int escolha);
// ----------------------------------


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
    printf("1 - Cadastrar novo modelo\n");
    printf("2 - Mostrar arquivo com modelos masculinos\n");
    printf("3 - Mostrar arquivo com modelos femininos\n");
    printf("Digite 0 para sair...\n");
    printf("\n---> ");
    scanf("%d", &opcao);

    return opcao;
}


// cadastra um novo modelo e salva em um arquivo
void CadastrarModelo () {

    Modelo m;

    system("cls");
    printf("----- CADASTRO DE MODELO -----\n\n");

    FILE *arq = fopen("dados.txt", "a");

    if (!arq) {
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
    fgets(m.nome, MAX_STRING, stdin);
    printf("Sexo (M ou F): ");
    scanf("%c", &m.sexo);
    m.sexo = toupper(m.sexo);
    printf("Cor dos olhos: ");
    printf("\tA -> Azul, B -> Verde, C -> Preto, D -> Castanho: ");
    LimparBuffer();
    scanf("%c", &m.olhos);
    m.olhos = toupper(m.olhos);
    printf("Altura: ");
    scanf("%f", &m.altura);
    printf("Peso: ");
    scanf("%f", &m.peso);

    fprintf(arq, "%s", m.nome);
    fprintf(arq, "%c\n", m.sexo);
    fprintf(arq, "%c\n", m.olhos);
    fprintf(arq, "%.2f\n", m.altura);
    fprintf(arq, "%.2f\n", m.peso);
    fclose(arq);

    DividirArquivos(m);

    printf("\nModelo cadastrado!\n");
    printf("------------------------------\n");
    printf("Pressione a tecla 'ENTER' para voltar ao menu...\n");
    LimparBuffer();
    getchar();
}   


// divide o arquivo principal com todos modelos em 2 novos, sendo um para modelos M e outro modelos F
void DividirArquivos (Modelo m) {

    FILE *arq1, *arq2; // arq1 para modelos M;   arq2 para modelos F

    // cadastrando no arquivo de modelos masculinos caso o sexo seja 'M'
    if (m.sexo == 'M') {
        arq1 =  fopen("ModelosM.txt", "a");
        if (!arq1) {
            printf("\nERRO AO DIVIDIR ARQUIVO\n");
            return;
        }
        fprintf(arq1, "%s", m.nome);
        fprintf(arq1, "%c\n", m.sexo);
        fprintf(arq1, "%c\n", m.olhos);
        fprintf(arq1, "%.2f\n", m.altura);
        fprintf(arq1, "%.2f\n\n", m.peso);
        fclose(arq1);
        printf("\nARQUIVO CRIADO\n");
    }

    // cadastrando no arquivo de modelos masculinos caso o sexo seja 'M'
    if (m.sexo == 'F') {
        arq2 = fopen("ModelosF.txt", "a");
        if (!arq2) {
            printf("\nERRO AO DIVIDIR ARQUIVO\n");
            return;
        }
        fprintf(arq2, "%s", m.nome);
        fprintf(arq2, "%c\n", m.sexo);
        fprintf(arq2, "%c\n", m.olhos);
        fprintf(arq2, "%.2f\n", m.altura);
        fprintf(arq2, "%.2f\n\n", m.peso);
        fclose(arq2);
        printf("\nARQUIVO CRIADO\n");
    }
}


// mostra os modeelos de determinado sexo escolhido pelo usuario
void MostrarModelos (int escolha) {

    char c;
    system("cls");
    printf("----- MOSTRANDO MODELOS -----\n\n");

    // se o usuario quer ver os modelos M
    if (escolha == 1) {

        FILE *arq1 =  fopen("ModelosM.txt", "r");
        if (!arq1) {printf("\nERRO AO ABRIR ARQUIVO\n"); return;}

        while (!feof(arq1)) {
            c = getc(arq1);
            printf("%c", c);
        }
        fclose(arq1);
    }

    // se o usuario quer ver os modelos F
    if (escolha == 2) {
        FILE *arq2 = fopen("ModelosF.txt", "r");
        if (!arq2) {printf("\nERRO AO ABRIR ARQUIVO!\n"); return;}

        while (!feof(arq2)) {
            c = getc(arq2);
            printf("%c", c);
        }
        fclose(arq2);
    }

    printf("-----------------------------\n");
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
            case 1: CadastrarModelo(); break;
            case 2: MostrarModelos(1); break;
            case 3: MostrarModelos(2); break;
            default: break;
        }
    } while (opcao != 0);

    printf("-----------------------------");
    return 0;
}
