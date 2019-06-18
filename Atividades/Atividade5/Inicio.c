#include <stdio.h>
#include <stdlib.h>
#include <string.h>






void inicia_Matriz (){

}

void inicia_Lista(){

}








int main() {
    FILE *ENTRADA = NULL;
    FILE *SAIDA= NULL;
    char caraio[100];
    char rato,demonio;

    ENTRADA = fopen("entrada.txt","r");
    SAIDA = fopen("entrada.txt", "w");

    if(ENTRADA == NULL || SAIDA == NULL){
        printf("erro ao abrir");
        exit(1);
    }

    fscanf(ENTRADA, "%c\n", &rato);
    printf("%c", rato);
    if(rato == 'M'){
        inicia_Matriz();
    }
    if(rato == 'L'){
        inicia_Lista();
    }

    fscanf(ENTRADA, "%c\n", &demonio);

    if(demonio == 'B'){
        printf("busca em largura\n");
    }
    if(demonio == 'D'){
        printf("busca em profundidade\n");
    }





    fclose(ENTRADA);
    fclose(SAIDA);
    return 0;
}
