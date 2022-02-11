#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ListaAdj.h"
#include "busca.h"

#define EEsparso 101	//Arestas em um grafo esparço, ordem de V
#define EDenso 10000	//Arestas em um grafo denso, ordem de v² 
int main(){

	 //Código disponiblizado em Aula

		Graph G = GraphInitialize(8);

		//Modelo de Grafo do slide 9 / aula 11
		//S=0, W=1, R=2, V=3, T=4, X=5, U=6, Y=7
		GraphInsertEdge(G, G->adj[0], G->adj[2]);
		GraphInsertEdge(G, G->adj[0], G->adj[1]);
		GraphInsertEdge(G, G->adj[1], G->adj[0]);
		GraphInsertEdge(G, G->adj[1], G->adj[4]);
		GraphInsertEdge(G, G->adj[1], G->adj[5]);
		GraphInsertEdge(G, G->adj[2], G->adj[0]);
		GraphInsertEdge(G, G->adj[2], G->adj[3]);
		GraphInsertEdge(G, G->adj[3], G->adj[2]);
		GraphInsertEdge(G, G->adj[4], G->adj[1]);
		GraphInsertEdge(G, G->adj[4], G->adj[5]);
		GraphInsertEdge(G, G->adj[4], G->adj[6]);
		GraphInsertEdge(G, G->adj[5], G->adj[1]);
		GraphInsertEdge(G, G->adj[5], G->adj[4]);
		GraphInsertEdge(G, G->adj[5], G->adj[6]);
		GraphInsertEdge(G, G->adj[5], G->adj[7]);
		GraphInsertEdge(G, G->adj[6], G->adj[4]);
		GraphInsertEdge(G, G->adj[6], G->adj[5]);
		GraphInsertEdge(G, G->adj[6], G->adj[7]);
		GraphInsertEdge(G, G->adj[7], G->adj[6]);
		GraphInsertEdge(G, G->adj[7], G->adj[5]);

		ImprimeGraph(G);
		DFS(G);
		BFS(G, G->adj[0]);
		printf("\n\n");
	
	// Fim -> Código disponiblizado em Aula */ 


/*=========================================Coleta de dados========================================================*/	

	/*//GRAFO ESPARSO
		clock_t t;
		t = clock();

		int V=110;																						//Número de Vértices
		Graph G = GraphInitialize(V);																	//Iniciando o grafo

		for (int i = 0; i < V-1; i++){
			GraphInsertEdge(G, G->adj[i], G->adj[i+1]);
		}
		GraphInsertEdge(G, G->adj[V-1], G->adj[0]);

		DFS(G);
		BFS(G, G->adj[0]);
		

		t = clock() - t; 																				//Tempo final menos inicial
		printf("\n\nTempo de execução: %lf milissegundos\n", ((double)t)/((CLOCKS_PER_SEC/1000)));		//Tempo em milisegundos
	//FIm -> GRAFO ESPARSO */
	

	/*//GRAFO DENSO
		srand(time(NULL));

		clock_t t;
		t = clock();

		int V = 10000;																					//Número de vértices
		Graph G = GraphInitialize(V);																	//Iniciando o Grafo
		
		for (int i = 0; i < V-1; i++){
			GraphInsertEdge(G, G->adj[i], G->adj[i+1]);
		}
		GraphInsertEdge(G, G->adj[V-1], G->adj[0]);

		
		for (int i = 0; i < V-1; i++)
			GraphInsertEdge(G, G->adj[(rand() % 9999)], G->adj[(rand() % 9999)]);
		
		
		DFS(G);
		BFS(G, G->adj[0]);
		
		t = clock() - t;
		printf("\n\nTempo de execução: %lf milissegundos\n", ((double)t)/((CLOCKS_PER_SEC/1000)));// Tempo em milisegundos
	
	//Fim-> GRAFO DENSO*/

	
	return 0;
}





