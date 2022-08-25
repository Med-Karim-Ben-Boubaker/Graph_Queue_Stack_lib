#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "queue.h"

// Creating a node
struct node* createNode(int v, int weight) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  newNode->weight = weight;
  return newNode;
}

// Creating a graph
struct Graph* createGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjLists = malloc(vertices * sizeof(struct node*));
  graph->visited = malloc(vertices * sizeof(int));

  int i;
  for (i = 0; i < vertices; i++) {
    graph->adjLists[i] = NULL;
    graph->visited[i] = 0;
  }

  return graph;
}

// Add edge
void addEdge(struct Graph* graph, int src, int dest) {
  // Add edge from src to dest
  struct node* newNode = createNode(dest, 0);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;

  // Add edge from dest to src
  newNode = createNode(src, 0);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}

// Add weighted edge
void addWeightEdge(struct Graph* graph, int src, int dest, int weight){
  // Add edge from src to dest
  struct node* newNode = createNode(dest, weight);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;

  // Add edge from dest tp src
  newNode = createNode(src, weight);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}

// BFS algorithm
void bfs(struct Graph* graph, int startVertex) {
  struct queue* q = createQueue(graph->numVertices + 10);

  graph->visited[startVertex] = 1;
  enqueue(q, startVertex);

  while (!isEmptyQueue(q)) {
    int currentVertex = dequeue(q);
    printf("Visited %d \n", currentVertex);

    struct node* temp = graph->adjLists[currentVertex];

    while (temp) {
      int adjVertex = temp->vertex;

      if (graph->visited[adjVertex] == 0) {
        graph->visited[adjVertex] = 1;
        enqueue(q, adjVertex);
      }
      temp = temp->next;
    }
  }
}


// DFS algorithm
void dfs(struct Graph* graph, int startVertex){
    struct node* adjList = graph->adjLists[startVertex];
    struct node* temp = adjList;

    graph->visited[startVertex] = 1;
    printf("Visited %d \n", startVertex);

    while(temp != NULL){
        int connectedVertex = temp->vertex;

        if(graph->visited[connectedVertex] == 0){
            dfs(graph, connectedVertex);
        }
        temp = temp->next;
    }

}