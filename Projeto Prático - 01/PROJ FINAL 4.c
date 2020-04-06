#include <stdio.h>

long long int operadora(long long int cartao); //identifica operadora;
long long int digitos (long long int cartao);  //realiza as operacoes necessarias com o numero do cartao e verifica a validade;

int main()
{
    long long int cartao, aux;
    char caractere;

    printf("Digite um numero:\n");
    scanf("%lld", &cartao);

    while (caractere!=10){
        scanf("%c", &caractere);
        if (caractere == 10)
            break;
        cartao = (int)caractere-48; /* confere se eh numero; */
        if(cartao<0 || cartao >9){
            printf("caracteres invalidos");
            return 0;
        }
        else{
            printf("%lld", cartao);
        }
        return 0;
    }

    cartao = operadora(cartao); //retorna operadora a que o cartao pertence;
    digitos(cartao);  //retorna se o cartão é valido ou não;

}

/* A função apresentada abaixo possui como principal objetivo identificar a qual operadora pertence o numero do cartão  digitado pelo usuário.Além
disso, a mesma utiliza como parametro o numero digitado (cartao) sendo dividida com um numero especifico o qual permite identificar os primeiros digitos do
numero apresentado, com base no exposto eh possivel identificar a operadora.*/
long long int operadora(long long int cartao){
    int aux = 0;
    while(aux == 0){
        aux = 1;  //troca o valor da variavel quando nenhuma das condições abaixos forem verdadeiras, ou seja, o  laço seria interrompido;
        if (cartao < 10000000000){
            printf("Numero muito pequeno!\nDigite novamente:\n");
            scanf("%lld",&cartao);
            aux = 0;
        }
        if (cartao > 10000000000000000){
            printf("Numero muito grande!\nDigite novamente:\n");
            scanf("%lld",&cartao);
            aux = 0;
        }
    }
    /*identificação da operadora */
    if(cartao / 100000000000000 == 51 || cartao / 100000000000000 == 55 ){
        printf("Mastercard\n");
        return cartao;
    }
    else if(cartao / 1000000000000 == 4 || cartao/1000000000000000 == 4){
        printf("Visa\n");
        return cartao;
    }
    else if(cartao / 10000000000000 == 34 ||cartao / 10000000000000 == 37){
         printf("Amex\n");
         return cartao;
    }
    else if(cartao / 1000000000000 == 30 ||cartao / 1000000000000 == 36 ||cartao / 1000000000000 == 38){
        printf("Diners\n");
        return cartao;
    }
    else if(cartao / 1000000000000 == 6011){
         printf("Discover\n");
         return cartao;
    }
    else if(cartao / 1000000000000 == 2014 ||cartao / 1000000000000 == 2149){
         printf("enRoute\n");
         return cartao;
    }
    else if(cartao / 1000000000000000 == 3){
        printf("JCB\n");
        return cartao;
    }
    else if(cartao / 10000000000000 == 2131 ||cartao / 10000000000000 == 1800){
        printf("JCB\n");
        return cartao;
    }
    else{
        printf("Operadora desconhecida\n");
        return cartao;
    }
}

/*A função apresentada abaixo dispõem dos seguintes objetivos: multiplicação dos digitos pertencentes as posições pares do numero (cartao), além de multiplicar
esses digitos por 2; e a verificação da validade do cartão.*/
long long int digitos (long long int cartao){
    int  aux, soma = 0;    //aux = o resto da divisao do numero do cartao, ou seja, sempre recebe o ultimo digito do mesmo;
    while(cartao > 0){     //soma = guarda os valores das posicoes impares e pares, respectivamente, somando-os;
       aux = cartao % 10;
       soma += aux;

       cartao /= 10;
       aux = cartao % 10;
       aux *= 2;

       soma += (aux/10 + aux%10);

       cartao /= 10;
    }
    if(soma %10 == 0){
        return printf("Numero valido");
    }
    else{
        return  printf("Numero invalido");
    }
}


