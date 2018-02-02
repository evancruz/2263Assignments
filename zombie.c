#include <stdio.h>
#include <stdlib.h>

void set_zombies(int n, char fred[n][n]);
void print_zombies(int n, char fred[n][n]);
void block_zombies(int n, char fred[n][n]);

int main() {
  int n;
  int r;
  int c;

  scanf("%d", &n);
  r = n;
  c = n;

  char zArray[r+2][c+2];
  for(int i = 1; i < r+1; i++) {
    for(int j = 1; j < c+1; j++) {
      zArray[i][j] = '.';
    }
  }
  set_zombies(n+2, zArray);
  printf("Original map\n");
  print_zombies(n+2, zArray);
  block_zombies(n+2, zArray);
  printf("\nMap with blocking info\n");
  print_zombies(n+2, zArray);

} //end

void set_zombies(int n, char fred[n][n]){
  int zRow;
  int zColumn;
  while(scanf("%d%d", &zRow, &zColumn) == 2) {
    zRow++;
    zColumn++;
    fred[zRow][zColumn] = 'Z';
  }
}

void print_zombies(int n, char fred[n][n]){
  for(int i = 1; i < n-1; i++) {
    for(int j = 1; j < n-1; j++) {
      printf("%c", fred[i][j]);
      if(j == n-2)
        printf("\n");
    }
  }
}

void block_zombies(int n, char fred[n][n]){
  for(int i = 1; i < n-1; i++) {
    for(int j = 1; j < n-1; j++) {
      if(fred[i][j] == 'Z') {
      if(fred[i-1][j] != 'Z')
        fred[i-1][j] = 'B';
      if(fred[i+1][j] != 'Z')
        fred[i+1][j] = 'B';
      if(fred[i][j-1] != 'Z')
        fred[i][j-1] = 'B';
      if(fred[i][j+1] != 'Z')
        fred[i][j+1] = 'B';
      }
    }
  }
}
