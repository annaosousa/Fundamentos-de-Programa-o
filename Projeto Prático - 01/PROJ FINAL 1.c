#include<stdio.h>

int calendario (int calend, int ano);
int ehbissexto(int ano);
int mes(int mes);
int zeller(int ano, int m);

int main(){
    int ano, calend;
    printf("Digite o ano:\n");
    scanf("%d", &ano);

    calendario(calend, ano); //executa o calendario;
}

/*A funcao reconhece quais anos sao bissextos.*/
int ehbissexto(int ano){
    int ehbissexto = 0; //variavel marcadora;
    if(ano%4 == 0 &&(ano%400 == 0 || ano%100 != 0)){
       return ehbissexto = 1;
    }
    else{
      return ehbissexto = 0;
    }
}

/*A funcao identifica o dia da semana de cada mes. Alem disso, nessa formula janeiro e fevereiro correspodem ao mes 13 e 14 do ano anterior,
logo eh necessario diminuir o numero do mes e dividi-lo por 12; Nao obstante, devido essa condicao eh necessario atualizacao do ano.
  Nesse sentido, eh notorio que a funcao de zeller (d) retornara o dia da semana correspondente.*/
int zeller(int ano, int m){
    int a = (14 - m)/12; // a == converte o valor do mes de jan e fev;
    int y = ano - a; // y == identifica em qual ano esta situado;
    int aux = m + 12 * a - 2; //converte o calendario com os meses 13 e 14;
    int dia = 1, d; //d == valor da funcao para saber que dia ira cair;
    d = (dia + y + y / 4 - y / 100 + y / 400 + (31 * aux) / 12) % 7;
    return d;
    }

/*A funcao retorna os meses e as demais caracteristicas pertencentes ao calendario;*/
int calendario (int calend, int ano){
    int cont, q, m, aux2, i, z; /*cont == quantidade de dias; q == dia da semana; m == mes; i == auxilia a determinar os especos entre os dias;
    z == recebe o valor da funcao zeller e incrementa cada dia percorrido;*/
    for(m=1; m<=12; m++){
        if(m==1){
            printf("\n\t\t   JANEIRO DE %d",ano);
        }
        else if(m==2){
            printf("\n\n\t\t   FEVEREIRO DE %d",ano);
        }
        else if(m==3){
            printf("\n\n\t\t   MARCO DE %d",ano);
        }
        else if(m==4){
            printf("\n\n\t\t   ABRIL DE %d", ano);
        }
        else if(m==5){
            printf("\n\n\t\t   MAIO DE %d", ano);
        }
        else if(m==6){
            printf("\n\n\t\t   JUNHO DE %d", ano);
        }
        else if(m==7){
            printf("\n\n\t\t   JULHO DE %d", ano);
        }
        else if(m==8){
            printf("\n\n\t\t   AGOSTO DE %d", ano);
        }
        else if(m==9){
            printf("\n\n\t\t   SETEMBRO DE %d", ano);
        }
        else if(m==10){
            printf("\n\n\t\t   OUTUBRO DE %d",ano);
        }
        else if(m==11){
            printf("\n\n\t\t   NOVEMBRO DE %d",ano);
        }
        else{
            printf("\n\n\t\t   DEZEMBRO DE %d",ano);
        }

        printf("\nDOM\tSEG\tTER\tQUA\tQUI\tSEX\tSAB\n");

        z = zeller(ano,m); //retoma o valor da funcao;
        for(int i=0; i<z; i++){
            printf("\t"); //espaco entre os dias da semana;
        }

        /*Estas condicoes sao para implementar a quant de dias no mes;*/
        if(m==4 || m==6 || m==9 || m==11 ){
            for(q=1; q<=30; q++){
                printf("%d\t", q);
                cont=q;
                z++; //z==conta a quant de dias que tem na semana;
                if(z%7 == 0)
                    printf("\n");
                cont ++;
            }
        }
        else if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12){
            for(q=1; q<=31; q++){
                printf("%d\t", q);
                cont=q;
                z++;
                if(z%7 == 0)
                    printf("\n");
                cont ++;

            }
        }
        else{
            aux2 = ehbissexto(ano); //retorna o valor da funcao que verifica se o ano eh bissexto;
            if(aux2 == 1){
                for(q=1; q<=29; q++){
                    printf("%d\t", q);
                    z++;
                    cont=q;
                    if(z%7 == 0)
                        printf("\n");
                        cont ++;

                }
            }
            else{
                for(q=1; q<=28; q++){
                    printf("%d\t", q);
                    z++;
                    cont=q;
                    if(z%7 == 0)
                        printf("\n");
                        cont ++;
                }
            }
        }
    }
}
