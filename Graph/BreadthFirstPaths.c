void BreadthFirstPaths_1(Table T) { /* Assume T is initialized */
  int currDist;
  Vertex v, w;

  for (currDist = 0; currDist < numVertex; currDist++) {
    for each Vertex V
      if (!T[v].known && T[v].dist == currDist) {
        T[v].known = true;
        for each w adjacent to v
          if (T[w].dist == Infinity) {
            T[w].dist = currDist + 1;
            T[w].path = v;
          }
      }
  }
}

void BreadthFirstPaths_2(Table T) { /* Assume T is initialized */
  Queue q;
  Vertex v, w;

  q = CreateQueue(newVertex);
  MakeEmpty(q);

  /* Enqueue the start vertex s, determined elsewhere */
  Enqueue(s, q);

  while (!IsEmpty(q)) {
    v = Dequeue(q);
    T[v].known = true;   /* Not really needed anymore */

    for each w adjacent to v
      if （T[w].dist == Infinity) {
        T[w].dist = currDist + 1;
        T[w].path = v;
        Enqueue(w, q);
      }
  }
  DisposeQueue(q);
}