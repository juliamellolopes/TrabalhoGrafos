#ifndef __ADJ__
#define __ADJ__

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

/*Estruturas*/

    typedef struct TipoItem Item;
    typedef struct TipoFila Fila;
    typedef struct Graph *graph;
    typedef struct Vertex *vertex;

    //Fila
    struct TipoItem{
        int data;
        Item *prox;
    };
    struct TipoFila{
        Item *head;
        Item *tail;
        int size;
    };

    //Grafos
    struct  Vertex{
        int value;
    };
    struct Graph{
        int V;                  // Número de Vértices
        int E;                  //Número de Arestas
        vertex **adj;
    };
/*Fim Estruturas*/


/*Métodos*/

    //Estrutura de Fila
        Fila* FFVazia();
        void Queue(Fila *f, int vertex);
        Item* Dequeue(Fila *f);

    vertex InitializeVertex(int value);
    graph InitializeGraph(char *adress);
    void GraphInsert(graph G, int v1, int v2); 

    void PrintMatrix(graph G);
    void PrintGraph(graph G);
/*Fim métodos*/


/*Implementações*/

    /*Estruturas de fila*/
        Fila* FFVazia(){
            Fila *f = (Fila*) malloc(sizeof(Fila));
            f->head = NULL;
            f->tail = NULL;
            return f;
        }

        void Queue(Fila *f, int vertex){
            Item *d = (Item *) malloc (sizeof(Item));
            d->data = vertex;
            d->prox = NULL;

            if(f->head == NULL){
                f->head = d;
                f->tail = d;
            }else{
                f->tail->prox = d;
                f->tail = d;
            }

            f->size ++;
        }

        Item* Dequeue(Fila *f){
            Item *aux;

            if(f->head == NULL)
                return NULL;

            aux = f->head;
            f->head = f->head->prox;
            f->size --;

            return aux;
        }
    /*Fim Estrutura de Fila */
    
    vertex InitializeVertex(int value){
        vertex aux = malloc(sizeof(vertex));
        aux->value = value;
        return aux;
    }

    graph InitializeGraph(char *adrees){
        FILE  *arq;
        int V;                                                  //Número de Vértices
        int origem = 0, destino;                                //Variáveis auxiliares para leitura de arq
        arq = fopen(adrees,"r");

        /*Verificando se foi possível abrir o arquivo*/
        if (arq == NULL){ printf("Erro: Nao foi possivel abrir o arquivo"); return NULL;}
        
        fscanf(arq,"%d",&V);                                    //Lendo o número de vértices

        graph G = malloc(sizeof(graph));
        G->V = V;                                            
        G->E = 0;
        G->adj = (vertex **)calloc(V,sizeof(vertex));
        for(int i = 0; i < V; i++)
            G->adj[i] = (vertex *)calloc(V,sizeof(vertex));

        for(int i = 0; i < V; i++)
            for(int j = 0; j < V; j++)
                G->adj[i][j] = InitializeVertex(0);             //Atribuindo valores default a matriz

        while (!feof(arq)){                                     //Leitura dos demais dados do arquivo
            if(origem >= V) break;

            fscanf(arq,"%d",&destino);
            if(destino != -1)
                GraphInsert(G,origem,destino);
            else
                origem++;
            
        }
        fclose(arq);
            
        return G;
    }
    void GraphInsert(graph G, int v1, int v2){
        vertex origem = InitializeVertex(v1);
        vertex destino = InitializeVertex(v2);

        if( (origem->value >= G->V) || (destino->value >= G->V) ) return; 
        
        if(G->adj[origem->value][destino->value]->value == 0){
            G->adj[origem->value][destino->value]->value = 1;
            G->E++;
        }

        free(origem);
        free(destino);
    }


    void PrintMatrix(graph G){
        printf("\n\n==================================================================================================");
        printf("\n\n\tMatriz de Adjacencia:\n\n");
        for(int i = 0; i < G->V; i++){
            if(i == 0){
                printf("\t\t    ");
                for(int j = 0; j < G->V; j++)
                    printf(" %d  ",j);
                printf("\n");
            }
            printf("\t\t");
            for(int j = 0; j < G->V; j++){
                if(j==0){
                    printf("%d-> ",i);
                }
                printf("[%d] ", G->adj[i][j]->value);
            }
            printf("\n");
        }
    }
    void PrintGraph(graph G){
        printf("\n\n\tVertices e Arestas:\n");
        for(int i = 0; i < G->V; i++){
                printf("\n\t\t%d-> ",i);
            for(int j = 0; j < G->V; j++)
                if(G->adj[i][j]->value == 1)
                    printf("%d ",j);
        }
        printf("\n\n\tInformacoes do Grafo:");
        printf("\n\n\t\tNumero de vertices: %d", G->V);
        printf("  Numero de arestas: %d",G->E);
        printf("\n==================================================================================================\n");

    }
/*Fim Implementações*/


#endif