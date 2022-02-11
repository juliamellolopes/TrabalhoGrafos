#include "Adj.h"
#include "busca.h"
#include <time.h>


void entradas();

int main(){

    //Estrutura Teste usa como entrada "input.txt" 
    
        char *str = "input.txt";
        graph G;
        vertex v2 = InitializeVertex(0);

        G = InitializeGraph(str);
        PrintMatrix(G);
        PrintGraph(G);

        BFS(G,v2);
        printf("\n\n");
        DFS(G);
        printf("\n\n");
    
    /*Fim estrutura Teste*/ 

/*=========================================Coleta de dados========================================================*/	

    //entradas();                                       //Criação dos arquivos de entradas


    /*//Grtafos Esparsos 
    
        printf("\n\tGrafo esparso: ");      
        vertex v2 = InitializeVertex(0);
        graph E;
        char *str2 = "Esparso.txt";                         

        clock_t t;
        t = clock();

        E = InitializeGraph(str2);                                  //Criação de um grafo Esparso

        BFS(E,v2);
        DFS(E);

        t = clock() - t;                                            //Tempo final menos inicial
        printf("\n\nTempo de execução: %lf milissegundos\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
    
    //Fim ->Grtafos Esparsos*/ 


    /*//Teste em Grafos Densos

        printf("\n\tGrafo Denso: ");
        vertex v2 = InitializeVertex(0);
        graph D;
        char *str3 = "Denso.txt";
        

        clock_t t;
        t = clock();
        
        D = InitializeGraph(str3);
        
        BFS(D,v2);
        DFS(D);
        
        t = clock() - t;                                             //Tempo final menos inicial
        printf("\n\nTempo de execução: %lf milissegundos\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

    //Fim -> teste em Grafos Densos*/

}


void entradas(){
    /*Essa Função Cria as entradas mais aleatórias a as salva em arquivos .txt*/

    srand(time(NULL));
    /*//Entrada de Grafos esparsos
        
        int V = 110;                                      //Número de vértices
        int aux;
        int grau;
        
        FILE *arq;
        arq = fopen("Esparso.txt","a");

        fprintf(arq,"%d" "%c",V,'\n');                   //Incluindo o número de vértices no arquivo
        
        for(int i = 1; i < V; i++){
            grau = rand() % 10;
            for(int j = 0; j < grau; j++){
                aux = rand() % 99;
                fprintf(arq,"%d" "%c",i+1,' ');
                fprintf(arq,"%d" "%c",aux,' ');
                if(j == grau-1)
                    fprintf(arq,"%d" "%c",-1,'\n');

            }
        }
        fclose(arq);*/
    
    //FIM-> Entrada de Grafos esparsos*/

    /*//Entrada de Grafos Densos:
    
        int V = 7000;                                               //Número de vértices
        int aux;
        int grau;
        FILE *arq;
        arq = fopen("Denso.txt","a");

        fprintf(arq,"%d" "%c",V,'\n');                              //Incluindo o número de vértices no arquivo
        
        for(int i = 1; i < V; i++){
            grau = rand() % 10;
            for(int j = 0; j < grau; j++){
                aux = rand() % 99;
                fprintf(arq,"%d" "%c",i+1,' ');
                fprintf(arq,"%d" "%c",aux,' ');
                if(j == grau-1)
                    fprintf(arq,"%d" "%c",-1,'\n');

            }
        }
        fclose(arq);
    //Entrada de Grafos Densos:*/

}
