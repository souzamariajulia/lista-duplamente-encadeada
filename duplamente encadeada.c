#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int valor;
    struct no * prox;
    struct no * ant;
}NO;

NO * inicio = NULL;
NO * fim = NULL;
int tam = 0;


void add(int pos, int valor){
    
    if(pos >= 0 && pos <= tam){
        //Passo 1 - aloco espaco de memoria e coloco os valores no NO novo
        NO * novo = malloc(sizeof(NO));
        novo->valor = valor;
        novo->prox = NULL;
        novo->ant = NULL;
        //Passo 2 - encaixo esse no na lista
        if(inicio == NULL){//vazia
            inicio = novo;
            fim = novo;
        }else if(pos == 0){  //inicio
            novo->prox = inicio;
            inicio->ant = novo;
            inicio = novo;
        }else if(pos == tam){//fim!
                fim->prox = novo;
                novo->ant = fim;
                fim = novo;
        }else{//entre os elementos da lista ("meio")
                NO * aux = inicio;
                for(int i = 0; i<pos; i++){
                    aux = aux->prox; //caminhada
                }
                //operacoes de encaixe! A ORDEM IMPORTA!
                novo->prox = aux;
                aux->ant->prox = novo;
                aux->ant = novo->ant;
                aux->ant = novo;
        }
        tam++;
    }
}

void imprimir(){
    
     NO * aux = inicio;
                   
    for(int i = 0; i<tam; i++){
        printf("idade: %d\n", aux->valor);
        aux = aux->prox;
    }
    
    
}

int remover(pos){
    
    //DICA e necessario desalocar o no com a funcao free()
    if(pos >=0 && pos <=tam - 1){
        NO * lixo;
        if(tam == 1){ //lista so tem um elemento
            
            //etapa 1: aponto o lixo para no a ser removido
            lixo = inicio;
            //etapa 2: removo o no da lista (logica)
            inicio = NULL;
            fim = NULL;

            
        }else if (pos == 0){//inicio
            //etapa 1: aponto o lixo para no a ser removido
            lixo = inicio;
             //etapa 2: removo o no da lista (logica)
            inicio = inicio->prox;
            inicio->ant = NULL;
            
            
        }else if(pos == tam -1){//fim
            //etapa 1: aponto o lixo para no a ser removido
            lixo = fim;
            //etapa 2: removo o no da lista (logica)
            fim = fim->ant;
            fim->prox = NULL;
            
            
        }else{//entre os elementos da lista ("meio")
             lixo = inicio;
            for(int i = 0; i<pos; i++){
                lixo = lixo->prox; //caminhada
            }
            
            lixo->ant->prox = lixo->prox;
            lixo->prox->ant = lixo->ant;
        }
        
        //etapa 3: removo o no da memoria
        int aux = lixo->valor;
        free(lixo);
        tam--;
        return aux;
    }
    return 0;
}

void add_ordenado(int valor){
        NO* novo= malloc(sizeof(NO));
        novo-> valor= valor;
        novo-> prox=NULL;
        novo-> ant=NULL;
        if(inicio==NULL){
            inicio=novo;
            fim=novo;}
        else if(inicio-> valor> novo-> valor){
            inicio-> ant= novo;
            novo-> prox= inicio;
            inicio=novo; }
        else if (fim-> valor < novo-> valor){
            fim-> prox= novo;
            novo-> ant= fim;
            fim=novo;}
        else{
            if ((novo -> valor - inicio -> valor) < (fim -> valor - novo -> valor)){
                NO* aux= inicio;
                while(aux-> valor < novo -> valor){
                    aux= aux -> prox;
                }
            aux-> ant-> prox=novo;
            novo-> ant = aux-> ant;
            novo-> prox= aux;
            aux-> ant= novo;
            }
        else{
            NO* aux= fim;
            while(aux-> valor> novo-> valor){
                aux=aux-> ant;  }
            aux -> prox -> ant= novo;
            novo-> prox= aux->prox;
            novo -> ant= aux;
            aux-> prox= novo;
        }

} tam++;
}


void remover_por_valor(int valor){
    NO * aux = inicio;
    int pos = 0;
    
    while (aux != NULL && aux->valor != valor) {
        aux = aux->prox;
        pos++;
    }
    
    if (aux != NULL) {
        remover(pos);
    }
}
  
int main(){
    add(0, 18);
    add(2, 34);
    add_ordenado(50);
    add_ordenado(1);
    add_ordenado(4);
    add_ordenado(2);
    add_ordenado(5);
    remover_por_valor(2);
    remover_por_valor(1);
    imprimir();
   
    return 0;
}


