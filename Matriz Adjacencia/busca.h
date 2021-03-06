#ifndef __BUSCA__
#define __BUSCA__

#include "Adj.h"

void BFS(graph G, vertex v);
void DFS(graph G);
void DFS_VISIT(graph G, int indice, int *cor, int *d, int *f, int *tempo);

/*=====================BFS====================================*/
void BFS(graph G, vertex v){
    int cor[G->V];          // -1 = Preto, 0 = Branco, 1 = Cinza
    int d[G->V];
    int pi[G->V];
    Fila *f =FFVazia();

    printf("\n\n\tMetodo de busca BFS: \n");
    for(int i = 0; i < G->V; i++)
        if(i != v->value){
            cor[i] = 0;
            d[i] = -1;      //Infinito
            pi[i] = -1;
        }
    cor[v->value] = 1;
    d[v->value] = 0;
    pi[v->value] = -1;

    Queue(f,v->value);

    while(f->size > 0){
        Item *aux = Dequeue(f);
        for(int i = 0; i < G->V; i++){
            if(G->adj[aux->data][i]->value == 1)
                if(cor[i] == 0){
                    cor[i] = 1;
                    d[i] = d[aux->data]+1;
                    pi[i] = aux->data;
                    Queue(f,i);
                }
        }
        cor[aux->data] = -1;
        printf("\n\t\tVertice:%d", aux->data);
    }
}
/*=====================BFS====================================*/

/*=====================DFS====================================*/
void DFS(graph G){
    printf("\n\n\tMetodo de busca DFS: \n");
    int cor[G->V];                                      //-1 = Preto; 0 = Branco; 1 = Cinza
    int d[G->V];                                        //Tempo de deslocação
    int f[G->V];                                        //Tempo de Finalização
    int tempo = 0;

    for(int i = 0; i < G->V; i++)   cor[i] = 0;         //Branco para todos os vértices

    for(int i = 0; i < G->V; i++)
        if(cor[i] == 0)
            DFS_VISIT(G,i,cor,d,f,&tempo);


}
void DFS_VISIT(graph G, int indice, int *cor, int *d, int *f, int *tempo){
    cor[indice]     = 1;
    *tempo          +=1;
    d[indice]       = *tempo;

    for(int aux = 0; aux < G->V; aux++)
        if(G->adj[indice][aux]->value == 1)
            if(cor[aux] == 0)
                DFS_VISIT(G, aux, cor, d, f, tempo);
    
    cor[indice]     = -1;
    *tempo          += 1;
    f[indice]       = *tempo;

    printf("\n\t\tVertice:%d D:%d, F:%d ", indice, d[indice], f[indice]);
}



#endif