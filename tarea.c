#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
typedef struct nodo
{
struct nodo *liga;
char info[MAX];
}*LISTA;
int creaNodo(LISTA *nuevo, char dato[]);
int insFinalIt(LISTA *cab, char dato[]);
void leerlista(LISTA cab);
int main()
{
LISTA cab1=NULL;
char texto[MAX],resp;
 FILE *arch;
 arch=fopen("gramatica1.txt","r");
  if (arch)
  {
            while (fgets(texto, sizeof(texto), arch)) {
                insFinalIt(&cab1,texto);
            }
  }
 fclose(arch);
 printf("---CONTENIDO DE LISTA---\n");
 leerlista(cab1);
    return 0;
}
int creaNodo(LISTA *nuevo, char dato[])
{
 int res = 0;
 *nuevo = (LISTA) malloc(sizeof(struct nodo));
 if(*nuevo)
 {
 strcpy((*nuevo)->info,dato);
 (*nuevo)->liga = NULL;
 res = 1;
 }
 return(res);
}
void leerlista(LISTA cab)
{
    while(cab)
    {
        printf("%s",cab->info);
        cab=cab->liga;
    }
}
int insFinalIt(LISTA *cab, char dato[]) {
    LISTA nuevo;
    if (creaNodo(&nuevo, dato)) {
        if (!*cab) {
            *cab = nuevo;
        } else {
            LISTA aux = *cab;
            while (aux->liga) {
                aux = aux->liga;
            }
            aux->liga = nuevo;
        }
        return 1;
    }
    return 0;
}
 