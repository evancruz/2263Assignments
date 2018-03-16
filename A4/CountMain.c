#include <time.h>
#include "Count.h"

int main (int argc, char ** argv){
  if(argc < 3){
    printf("need more than %d arguments\n", argc);
    return EXIT_FAILURE;
  }
  int numRow = strtol(argv[1], NULL, 10);
  int numCol = strtol(argv[2], NULL, 10);
  int ** arrRows = malloc(numRow * sizeof(int*));
  int *arrCols = malloc(numRow * numCol * sizeof(int));
  for(int i = 0; i < numRow; i++){
    arrRows[i] = arrCols + numRow*i;
  }
  srand(time(NULL));
  initializeArr(arrRows, numRow, numCol);
  printArr(arrRows, numRow, numCol);
  int totalBlob = countTotalBlob(arrRows, numRow, numCol);
  int index1 = -1;
  int index2 = -1;
  int *x = &index1;
  int *y = &index2;
  do{
    if(index1 > -1){
      if(checkBound(*x, *y, numRow, numCol) == -1){
        printf("invalid coordinate\n");
      } else {
        int numBlobs = countBlob(arrRows, *x, *y, numRow, numCol);
        double percentage = ((double)numBlobs / (double)totalBlob) * 100;
        printf("Blob size: %d (%lf %% of all 1's)\n", numBlobs, percentage);
        originalfunction(arrRows, numRow, numCol);
      }
    }
    printf("enter coordinate i,j (non-numeric to quit):");
  } while(scanf("%d,%d", x, y) == 2);

  //free arrays
  free(arrCols);
  free(arrRows);
  return EXIT_SUCCESS;
}

void initializeArr(int ** arr, int numRow, int numCol){
    for(int i = 0; i < numRow; i++){
      for(int j = 0; j < numCol; j++){
        arr[i][j] = rand() % 2;
      }
    }
}

void printArr(int ** arr, int numRow, int numCol){
  for(int i = 0; i < numRow; i++){
    for(int j = 0; j < numCol; j++){
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

int checkBound(int i, int j, int numRow, int numCol){
  if(i >= numRow || i < 0){
    return -1;
  }
  if(j >= numCol || j < 0){
    return -1;
  }
  return 0;
}

int countTotalBlob(int ** arr, int numRow, int numCol){
  int count = 0;
  for(int i = 0; i < numRow; i++){
    for(int j = 0; j < numCol; j++){
      if(arr[i][j]== 1)
        count++;
    }
  }
  return count;
}

int countBlob(int ** arr, int i, int j, int numRow, int numCol){
  int total = 0;
  if((checkBound(i, j, numRow, numCol)==-1) || arr[i][j] != 1) {
    return 0;
  }
  if(arr[i][j] == 1){
    total++;
    arr[i][j] = 2;
  }
  return total + countBlob(arr, i-1, j, numRow, numCol)
  + countBlob(arr, i, j-1, numRow, numCol)
  + countBlob(arr, i+1, j, numRow, numCol)
  + countBlob(arr, i, j+1, numRow, numCol)
  + countBlob(arr, i+1, j+1, numRow, numCol)
  + countBlob(arr, i+1, j-1, numRow, numCol)
  + countBlob(arr, i-1, j-1, numRow, numCol)
  + countBlob(arr, i-1, j+1, numRow, numCol);
}

void originalfunction(int ** arr, int numRow, int numCol){
      for(int i = 0; i < numRow; i++){
        for(int j = 0; j < numCol; j++){
          if(arr[i][j] == 2){
            arr[i][j] = 1;
          }
        }
      }
}
