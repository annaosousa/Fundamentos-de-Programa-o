#include <stdio.h>

#define SIZE (1 << 4)
//SIZE (1 << 4) = 10000; == 16;
//SIZE (1 << 7) = 10000000; == 128;

int main()
{
    int x, y, i;
    for (y = SIZE - 1; y >= 0; y--, putchar('\n')) {
        for (i = 0; i < y; i++)
            putchar('  ');
        for (x = 0; x + y < SIZE; x++)
            printf((x & y) ? "  " : "* ");
    }
 return 0;
 }

/*
Quando SIZE (1<<4) = 16;

y = 15;y >= 0; y-- (pula linha));
i = 0; i<15; i++ (espaço); (i = 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14)
x = 0; x+y(0 + 15)< 16; x++ ; (x = 0)
printf (se x e y forem verdadeiros printf(espaço), se não printf(*))
- 0000 (x) & 1111(y) - printf (    *   );

O programa executara o primeiro valor de y para a condicao de i e depois para a condicao
de x, seguindo seus comandos ate a condicao de i se tornar falsa e da mesma maneira para
o x. Em seguida, muda o valor de y, decrementadando-o e entrando nos lacos novamente.

Exemplo (teste de mesa) para condicao de i: y = 15 e i = 0; y = 14  e i = 0; y = 13 e i = 0; y = 12 e i = 0 e assim sucessivamente
               <--- 14 espacos
             <--- 13 espacos
            <--- 12 espacos
Ou seja, este sera o triangulo inverso que tem ao lado do triangulo de asteriscos.


y = 14; y >= 0; y-- (pula linha); (y = 14)
i = 0; i<14; i++ (espaco); (i = 0,1,2,3,4,5,6,7,8,9,10,11,12,13)
x = 0; x+y(0+14)<16;x ++; (x = 0, 1)
//ENQUANTO AS CONDICOES DO 'FOR' ESTIVEREM CORRETAS SERA EXECUTADO OS MESMOS COMANDOS.
             <--- 13 espacos
- 0000 (x) & 1110(y) - printf (    *   );
- 0001 (x) & 1110(y) - printf (    *   );

y = 13; y >= 0; y-- (pula linha); (y = 13)
i = 0; i<13; i++ (espaco); (i = 0,1,2,3,4,5,6,7,8,9,10,11,12)
x = 0; x+y(0+13)<16; x ++; (x = 0,1,2)
//ENQUANTO AS CONDICOES DO 'FOR' ESTIVEREM CORRETAS SERA EXECUTADO OS MESMOS COMANDOS.
            <---- 12 espacos
- 0000 (x) & 1101(y) - printf (    *   );
- 0001 (x) & 1101(y) - printf (    *   );
- 0010 (x) & 1101(y) - printf (    *   );

y = 12; y >= 0; y-- (pula linha); (y = 12)
i = 0; i<12; i++ (espaco); (i = 0,1,2,3,4,5,6,7,8,9,10,11)
x = 0; x+y(0+12)<16; x ++; (x = 0,1,2,3)
//ENQUANTO AS CONDICOES DO 'FOR' ESTIVEREM CORRETAS SERA EXECUTADO OS MESMOS COMANDOS.
           <--- 11 espacos
- 0000 (x) & 1100(y) - printf (    *   );
- 0001 (x) & 1100(y) - printf (    *   );
- 0010 (x) & 1100(y) - printf (    *   );
- 0011 (x) & 1100(y) - printf (    *   );

...

y = 1; y >= 0; y-- (pula linha); (y = 1)
i = 0; i<1; i++ (espaco); (i = 0)
x = 0; x+y(0+1)<16; x ++; (x = 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14)
//ENQUANTO AS CONDICOES DO 'FOR' ESTIVEREM CORRETAS SERA EXECUTADO OS MESMOS COMANDOS.
 <--- 1 espaco
- 0000 (x) & 0001(y) - printf (    *   );
- 0001 (x) & 0001(y) - printf (        );
- 0010 (x) & 0001(y) - printf (    *   );
- 0011 (x) & 0001(y) - printf (        );
- 0100 (x) & 0001(y) - printf (    *   );
- 0101 (x) & 0001(y) - printf (        );
- 0110 (x) & 0001(y) - printf (    *   );
- 0111 (x) & 0001(y) - printf (        );
- 1000 (x) & 0001(y) - printf (    *   );
- 1001 (x) & 0001(y) - printf (        );
- 1010 (x) & 0001(y) - printf (    *   );
- 1011 (x) & 0001(y) - printf (        );
- 1100 (x) & 0001(y) - printf (    *   );
- 1101 (x) & 0001(y) - printf (        );
- 1010 (x) & 0001(y) - printf (    *   );
- 1111 (x) & 0001(y) - printf (        );

Desse modo, aparecera na tela varios triangulos equilateros formados por asteriscos. Estes, podem variar de tamanho e quantidade
dependendo do numero que esta na constante SIZE.
*/
