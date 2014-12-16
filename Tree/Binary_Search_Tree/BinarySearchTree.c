struct TreeNode {
  ElementType element;
  SearchTree left;
  SearchTree right;
};

SearchTree MakeEmpty(SearchTree T) {
  if (T != NULL) {
    MakeEmpty(T->left);
    MakeEmpty(T->right);
    free(T);
  }

  return NULL;
}

Position Find(ElementType X, SearchTree T) {
  if (T == NULL) 
    return NULL;
  if (X < T->element)
    return Find(X, T->left);
  else
  if (X > T->element)
    return Find(X, T->right);
  else
    return T;
}

Position FindMin(SearchTree T) {
  if (T == NULL) 
    return T;
  else
    if (T->left == NULL)
      return T;
    else
      return FindMin(T->left);
}

Position FindMax(SearchTree T) {
  if (T != NULL) 
    while (T->right != NULL)
      T = T->right;

  return T;
}

SearchTree Insert(ElementType X, SearchTree T) {
  if (T == NULL) {
    /* Create and return a one-node tree */
    T = malloc(sizeof(struct TreeNode));
    if (T == NULL)
      FatalError("Out of space!!!");
    else {
      T->element = X;
      T->left = T->right = NULL;
    }
  }
  else 
    if (X < T->element)
      T->left = Insert(X, T->left);
    else if (X > T->element)
      T->right = Insert(X, T->right);
    /* Else X is in the tree already; we'll do nothing */

  return T;
}