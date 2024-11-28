#include <stdio.h>
#include "funcs.h"
#include <string.h>
#include <locale.h>
typedef struct
{
  char placa[10], nome[25], tipo[15], pgto[10], modelo[20];
  int dia, mes, ano, fabri, cnh;
  float valor;
}Veiculo;
float valorMulta(float a);
void registra(Veiculo* ptr);
void boasvindas();
void alternativas();
void linha();
int main()
{
    setlocale(LC_ALL,"");
    FILE *arq;
    int esc; float valor;
    Veiculo v1;
    Veiculo *ptrveiculo = &v1; //O ponteiro ptrveiculo vai recever o endere�o da variavel v1, que � do tipo Veiculo.

    boasvindas(); //Puxei a fun��o de boas-vindas.
    alternativas(); //Puxei as fun��es de alternativas.
    scanf("%d", &esc);//Aqui recebemos a escolha do usu�rio.
    getchar(); //Aqui vamos limpar o buffer do teclado, pois o scanf deixa o "\n" como "rastro". Sem ele, nosso c�digo n�o vai rodar corretamente.
    system("cls"); //Usado para limpar a tela
    arq = fopen("multas.txt", "a"); //"a" se houver arquivos existentes, ele ir� escrever abaixo, sen�o, ir� criar um arquivo novo.
    switch(esc){
    case 1:
        registra(ptrveiculo);
        getchar();
        valor = valorMulta(valor);
        system("cls");
        printf("Esses s�o os dados do condutor e do ve�culo:\n\nModelo do ve�culo: %s\nPlaca do ve�culo: %s\nNome do condutor: %s\nN� da CNH: %d\nValor da multa: %.2f\nConfirmar dados?\n1. Sim\n2. N�o\n",ptrveiculo->modelo, ptrveiculo->placa, ptrveiculo->nome, ptrveiculo->cnh, valor);
        scanf("%d", &esc);
        if(esc == 1){
           fprintf(arq,"-----------------------------\nModelo do ve�culo: %s\nPlaca do ve�culo: %s\nNome do condutor: %s\nN� da CNH: %d\n-----------------------------\n",ptrveiculo->modelo,ptrveiculo->placa, ptrveiculo->nome, ptrveiculo->cnh);
            printf("Dados enviados ao arquivo de armazenamento!");
        } else if(esc == 2){
            printf("Confirma��o negada!");}
        }

    return 0;
}


void registra(Veiculo* car){
    int esc;
    printf("------Voc� escolheu registrar uma multa------\n");
    printf("Escreva o modelo do ve�culo: ");
        fgets(car->modelo, 20, stdin); getchar();
    printf("Escreva a placa do ve�culo: ");
        fgets(car->placa, 10, stdin); getchar();
    printf("Escreva o nome do condutor: ");
        fgets(car->nome, 25, stdin); getchar();
    printf("Escreva o n� da CNH do condutor: ");
        scanf("%d", &car->cnh); getchar();
}
float valorMulta(float a){
    int b;
    printf("Escolha o peso da infra��o: \n");
    printf("1.Grav�ssima    2.Grave     3.M�dia     4.Leve\n");
        scanf("%d", &b);
        switch(b){
    case 1: return 293.47;
    case 2: return 195.23;
    case 3: return 130.16;
    case 4: return 88.38;
    default:
        printf("Escolha errada! Tente novamente.");}
    }
