#ifndef __GRAPH_H__
#define __GRAPH_H__
struct node {
  int vertex;
  int weight;
  struct node* next;
};

struct Graph {
  int numVertices;
  struct node** adjLists;
  int* visited;
};

struct node* createNode(int value, int weight);
struct Graph* createGraph(int);
void addEdge(struct Graph* graph, int src, int dest);
void addWeightEdge(struct Graph* graph, int src, int dest, int weight);
void dfs(struct Graph* graph, int startVertex);
void bfs(struct Graph* graph, int startVertex);
void bfsw(struct Graph* graph, int startVertex);

#endif