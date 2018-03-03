#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int inputCSR(int V[], int E[], int W[], int n, int m){

  int counter = 0, i;
  for(i=0; i<n+1; i++){
    counter += scanf("%d", &V[i]);
  }

  if(counter != n+1){ //too many or too little elements scanned
    return EXIT_FAILURE;
  }

  counter = 0;
  for(i=0; i<m; i++){
    counter += scanf("%d", &E[i]);
  }
  if(counter != m){ //too many or too little elements scanned
    return EXIT_FAILURE;
  }

  counter = 0;
  for(i=0; i<m; i++){
    counter += scanf("%d", &W[i]);
  }
  if(counter != m){ //too many or too little elements scanned
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

int main(){
  int n, m, i, j;
  scanf("%d%d", &n, &m);

  int V[n+1];
  int E[m], W[m];
  inputCSR(V, E, W, n, m);

  int vert;
  scanf("%d", &vert);

  int queue[n], inQueue[n], D[n], P[n];
  int front = 0;
  int size = 1;

  for(i = 0; i<n; i++){
    P[i] = -1;
    D[i] = INT_MAX;
    queue[i] = 0;
    inQueue[i] = 0;
  }

  queue[0] = vert;
  inQueue[vert] = 1;
  D[vert] = 0;
  P[vert] = 0;

  while(front != size){ //while list != 0 do
    i = queue[front];
    front = (front + 1) % n;
    inQueue[i] = 0;

    for(j = V[i]; j<V[i+1]; j++){ // relax each out-edge of vertex i
      if(D[E[j]] > D[i] + W[j]){
        D[E[j]] = D[i] + W[j];
        P[E[j]] = i;
        if(inQueue[E[j]] == 0){
            queue[size] = E[j];
            inQueue[E[j]] = 1;
            size = (size + 1) % n;
        }
      }
    }
  }
  printf("source vertex: %d\nP: ", vert);
  for(i=0; i<n; i++){
    printf("%d ", P[i]);
  }
  printf("\nD: ");
  for(i=0; i<n; i++){
    printf("%d ", D[i]);
  }
  printf("\n");

  return EXIT_SUCCESS;
}
