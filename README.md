<h1 align="center">Estruturas de Representação e Caminhamento em Grafos</h1>

### Sumário
<!--ts-->
   * [Copilação](#Copilação)
   * [Grafos](#Grafos)
   * [MatrizAdjacenre](#MatrizAdjacente)
   * [MatrizIncidente](#MatrizIncidente)
   * [BFS](#BFS)
   * [DFS](#BFS)
   * [Resultados](#Resultados)
<!--te-->

### Copilação

Para copilar, abra uma das pastas e rode

    gcc Main.c -o executavel
    ./executavel

### MatrizAdjacente
Esse tipo de representação consiste em uma matriz N x N ( ADJ[N][N] ), na qual N é o número de vértices do grafo. As posições (i,j) da matriz representam se há ou não ligação entre os vétices indicados. Suponha que exista um grafo G, tal que G contenha pelo menos dois ou mais vértices, um vértice X(origem) e um vértice Y(destino), caso o valor contido na matirz ADJ na posição: ADJ[X][Y] for igual a 1, significa há uma aresta que parte de X e incide em Y.

A pasta matriz adjacente contem um arquivo que contem os dados do para criar o grafo chamado "input.txt", o codigo da matgriz se encontra em Adj.h. Ao copilar e executar o código de Matriz Adjacencia epesra-se com a leitura de "input.txt" obtem-se o seguinte resultado:
![image](https://user-images.githubusercontent.com/84408875/153783321-1a7013d4-13dc-4a3d-89a1-709dedcc288c.png)

### MatrizIncidencia
Esse tipo de representação consiste em uma matriz N x M (INC[N][M]), na qual N é o número de vértices e M o número de arestas do grafo. As posições (i,j) da matriz representa se há ou não incidencia da aresta no vétice indicado. Diferente da matriz de ajacência as conxões na matriz de incidência são representadas pelas colunas. Suponha que exista um grafo G, tal que G contenha pelo menos dois ou mais vértices, um vértice X(origem) e um vértice Y(destino), caso haja uma aresta J que parte de X e incide em Y a representação na matriz será indicada da seguinte forma: INC[X][J] = -1 e INC[Y][J] = 1. Dessa forma cada coluna contem somente no máximo 2 valores, -1 para idicar a origem da aresta e 1 para indicar o destino.

Na pasta da matriz de incidencia contem um arquivo que contem os dados do para criar o grafo chamado "input.txt", o codigo fica se encontra em Inc.h.  Ao copilar e executar o código de Matriz Incidencia epesra-se com a leitura de "input.txt" obtem-se o seguinte resultado:
![image](https://user-images.githubusercontent.com/84408875/153783523-5d02beee-ee81-4937-a044-df023eef87b0.png)

### BFS
As alterações realizadas no método BFS, comparando com o método de Lista de Adjacencia foram poucas. Dentro do laço While, para percorrer os vértices adjacentes agora é necessário um laço for que caminha nas colunas da matriz adj:

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
  
A alteração realizada nesse método também se deu no laço while, para acessar os vértices adjacentes agora é preciso de dois laços for. Um para caminhar nas colunas da matriz INC e achar uma aresta que tenha origem no vértice analisado e outro para caminha nas linhas da matriz e encontrar o vértice de destino.

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
          int aux2;
          for(int i = 0; i < G->E; i++){
              if(G->inc[aux->data][i]->value == -1)
                  for(int aux2 = 0; aux2 < G->V; aux2++)
                      if(G->inc[aux2][i]->value == 1)
                          if(cor[aux2] == 0){
                              cor[aux2] = 1;
                              d[aux2] = d[aux->data]+1;
                              pi[aux2] = aux->data;
                              Queue(f,aux2);
                          }
          }
          cor[aux->data] = -1;
          printf("\n\t\tVertice:%d", aux->data);
      }
    }
    
### DFS
Comparado com a função DFS de lista de adjacência a alteração se deu na função: DFS_VISIT(). Para percorrer os vértices adjacentes precisa agora caminhar pelaS colunas da matriz adj.

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

As alterações aqui também se resumem a função: DFS_VISIT(), para percorrer os vértices adjacentes foram inclusos dois laços for. Um para caminhar nas colunas da matriz INC e achar uma aresta que tenha origem no vértice analisado e outro para caminha nas linhas da matriz e encontrar o vértice de destino.

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

        for(int aux = 0; aux < G->E; aux++)
            if(G->inc[indice][aux]->value == -1)
                for(int aux2 = 0; aux2 < G->V; aux2++)
                    if(G->inc[aux2][aux]->value == 1)
                        if(cor[aux2] == 0)
                            DFS_VISIT(G, aux2, cor, d, f, tempo);

        cor[indice]     = -1;
        *tempo          += 1;
        f[indice]       = *tempo;

        printf("\n\t\tVertice:%d D:%d, F:%d ", indice, d[indice], f[indice]);

    }
    
### Resultados
Como o grafo inserido nos dois casos é o mesmo os resultados obtidos também serão iguais:
![image](https://user-images.githubusercontent.com/84408875/153783818-878d5a44-be61-4876-85f7-5feaa2ce2925.png)

A atividade contempla uma comparação entre os métodos de busca e as estruturas apresentadas. Para isso fora realizado testes com grafos esparsos com cerca de 100 vértices e grafos densos com cerca de 10000 vértices. As comparações serão baseadas em tempo para execução e consumo de memória RAM de cada estrutura. A codificação para gerar as entradas aleatórias de grafos para as funções se encontram no main de cada uma. Para realizar medições de tempo foi usada as funções da biblioteca: < time.h > e para medir o consumo de memória RAM utilizou-se o seguinte comando no terminal:

    valgrind --leak-check=yes ./teste
    
Os Resultados obtidos foram:

Matriz Adjacente:
![image](https://user-images.githubusercontent.com/84408875/153784003-de716c19-c1c1-4990-b68f-8c722dbb7483.png)
![image](https://user-images.githubusercontent.com/84408875/153784007-284a2941-2977-43dc-88f5-124dd6c8a3c0.png)

Matriz Incidente:
![image](https://user-images.githubusercontent.com/84408875/153784027-4202f4c5-5f62-4918-9212-34b3e15f40b7.png)
![image](https://user-images.githubusercontent.com/84408875/153784032-abef7d1c-5718-4655-b277-228ddafe519f.png)

A partir desses resultados percebe-se que para grandes entradas de dados é muito viável utilizar Listas de adjacência e vasicamente inviável a utilização de matrizes de incidência. Já para pequenas entradas de dados é mais vantajoso matriz de adjacência, pelo se baixo consumo de memória, a diferênça de tempo é basicamente imperceptível.

A única estrutura que não se mostrou muito vantajosa em nunhum caso foi a matriz de incidência, em todos os casos ela apresenta piores resultados
