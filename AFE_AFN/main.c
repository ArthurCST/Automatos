#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

Lista* geraMatriz(int n_estados, int n_letras);
void preencheMatriz(Lista ***matriz, int n_estados, char* alfabeto);
void imprimeMatriz(Lista ***matriz, int n_estados, char* alfabeto);

void main()
{
    int n_estados;
    char* alfabeto = (char*) malloc(5 * sizeof(char));

    printf("Entre com o Alfabeto: ");
    scanf("%s", alfabeto);

    printf("Entre com o numero de estados: ");
    scanf("%d", &n_estados);
    Lista* matriz = geraMatriz(n_estados, strlen(alfabeto));
    preencheMatriz(matriz, n_estados, alfabeto);
    imprimeMatriz(matriz, n_estados, alfabeto);

}

Lista* geraMatriz(int n_estados, int n_letras)
{
    Lista ***matriz;
    int i, j;
    matriz = (Lista**)malloc(sizeof(Lista*) * n_estados);
    if(matriz != NULL)
    {
        for(i=0; i<n_estados; i++)
        {
            matriz[i] = (Lista*)malloc(sizeof(Lista) * n_letras);
            for(j=0; j<n_letras+1; j++)
            {
                matriz[i][j] = criarLista();
            }
        }
        return matriz;
    }
    return NULL;
}

void preencheMatriz(Lista ***matriz, int n_estados, char* alfabeto)
{
    int i, j, estado, cont;
    int flag;
    if(matriz != NULL)
    {
        for(i=0; i<n_estados; i++)
        {
            for(j=0; j<strlen(alfabeto)+1; j++)
            {
                flag = 0;
                printf("\n---Caso nao haja transicao no estado [q%d] lendo [%c] digite '9'---\n", i, alfabeto[j]);
                scanf("%d", &estado);
                cont = 0;
                if(estado != 9)
                {
                    while(flag == 0 && cont<n_estados)
                    {
                        if(j <= strlen(alfabeto))
                        {
                            printf("\nDigite o numero do estado para [q%d] lendo [%c]: ", i, alfabeto[cont]);
                            scanf("%d", &estado);
                        }else
                        {
                            printf("\nDigite o numero do estado para [q%d] lendo [E]: ", j);
                            scanf("%d", &estado);
                        }
                        if(estado < n_estados && estado >= 0)
                        {
                            inserirNoFim(matriz[i][j], matriz[estado], estado);
                            printf("\nTudo OK");

                        }else
                        {
                            printf("\nEstado [%d] invalido: ", estado);
                        }
                        printf("\nDeseja digitar um novo estado: [0] sim [1] nao - ");
                        scanf("%d", &flag);
                        cont++;
                    }
                }
            }
        }
    }
}

void imprimeMatriz(Lista ***matriz, int n_estados, char* alfabeto)
{
    int i, j;
    if(matriz != NULL)
    {
        for(i=0; i<strlen(alfabeto); i++)
        {
            printf("%c\t", alfabeto[i]);
        }
        printf("E\n");
        for(i=0; i<n_estados; i++)
        {
            for(j=0; j<strlen(alfabeto)+1; j++)
            {
                imprimeLista(matriz[i][j]);
                printf("\t");
            }
            printf("\n");
        }
    }
}
