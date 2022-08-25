#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"
#include "graph.h"


int main() {
  struct Graph* graph = createGraph(6);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 4);
  addEdge(graph, 1, 3);
  addEdge(graph, 2, 4);
  addEdge(graph, 3, 4);

  dfs(graph, 0);

  return 0;
}