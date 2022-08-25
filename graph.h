#ifndef __GRAPH_H__
#define __GRAPH_H__
struct node {
  int vertex;
  struct node* next;
};

struct node* createNode(int);

struct Graph {
  int numVertices;
  struct node** adjLists;
  int* visited;
};

struct node* createNode(int);
struct Graph* createGraph(int);
void addEdge(struct Graph* graph, int src, int dest);
void dfs(struct Graph* graph, int startVertex);
void bfs(struct Graph* graph, int startVertex);

#endif