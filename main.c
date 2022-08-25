#include <stdio.h>
#include <stdlib.h>
#include "graph.h"


int main() {
  struct Graph* graph = createGraph(6);
  addWeightEdge(graph, 0, 1, 1);
  addWeightEdge(graph, 1, 2, 2);
  addWeightEdge(graph, 1, 4, 3);
  addWeightEdge(graph, 1, 3, 4);
  addWeightEdge(graph, 2, 4, 5);
  addWeightEdge(graph, 3, 4, 6);

  bfsw(graph, 0);

  return 0;
}