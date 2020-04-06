#include<stdio.h>
#include<stdlib.h>
void convertemenA (char menA);
void convertemenB (int menB);
int main(){
    int menB;  //menB = mensagem digita na opcao B;
    char opcao, menA, A; //menA = mensagem digita na opcao A;

    printf("Selecione uma opcao: A(digitar uma mensagem) ou B(digitar um bit ):\n");
    scanf("%c", &opcao);

    if( opcao == 'A'){
        printf("Digite a mensagem e quando terminar digite um ponto:\n");
        while(menA!= '.'){ // para interromper a leitura de dados;
            scanf(" %c", &menA);
            convertemenA(menA); // retorna a conversao modificada do que o usuario digitou;
       }
    }

    else{
        printf("Digite o bit e quando terminar digite 46:\n");
        while(menB!=46){ // para interromper a leitura de dados;
            scanf(" %d", &menB);
            convertemenB(menB); // retorna a conversao modificada do que o usuario digitou;
        }

    }
}
/*A funcao abaixo modifica o valor de entrada da opcao A, fazendo os ajustes necessarios.*/
void convertemenA(char menA){
    int acumuladora=0;
    char auxA=menA; //aux criada devido ao valor de menA precisar ser atualizado;
    while(menA!=0){
        if(menA%2!=0) //saber a quant. de digitos um;
             acumuladora++;
             menA/=2;
    }
    if(acumuladora%2==0){ //confere se eh impar ou par;
        printf("  %d   ", auxA);
    }
    else{
        printf("  %d  ",auxA+128); //soma 2^8, ou seja, muda pra 1 a oitava posicao do termo em binario;
    }
}

/*A funcao abaixo modifica o valor de entrada da opcao B, fazendo os ajustes necessarios.*/
void convertemenB(int menB){
    int acumuladoraB=0;
    int auxB=menB;
    while(menB!=0){
        if(menB%2!=0)
            acumuladoraB++;
            menB/=2;
    }
    if(acumuladoraB%2==0 ){
        if(auxB>>7&1){ // desloca e verifica se o oitavo bit eh 1;
            auxB=auxB-128; //se for 1 o oitavo bit, entao muda para zero;
            printf("%c", auxB);
        }
        else
            printf("%c", auxB);
    }
    else{
        printf("*");
    }

}


