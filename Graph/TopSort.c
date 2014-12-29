void TopSort_1(Graph G) {
  int counter;
  Vertex v, w;

  for (counter = 0; counter < numVertex; counter++) {
    v = FindNewVertexOfIndegreeZero();
    if (v == NotAVertex) {
      Error("Graph has a cycle");
      break;
    }
    topNum[v] = counter;
    for each W adjacent to V
      indegree[w]--;
  }
}

void TopSort_2(Graph G) {
  Queue q;
  int counter = 0;
  Vertex v, w;

  q = CreateQueue(numVertex);
  MakeEmpty(Q);
  for each vertex v
    if (indegree[v] == 0)
      Enqueue(v, q);

  while (!IsEmpty(q)) {
    v = Dequeue(q);
    topNum[v] = ++counter;    /* Assign next number */

    for each w adjacent to v
      if (--indegree[w] == 0)
        Enqueue(w, q);
  }

  if (counter != numVertex)
    Error("Graph has a cycle");

  DisposeQueue(q);     /* Free the memory */
}