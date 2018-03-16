#ifndef count_h
#define count_h
#include <stdlib.h>
#include <stdio.h>

void initializeArr(int ** arr, int numRow, int numCol);
void printArr(int ** arr, int numRow, int numCol);
int checkBound(int i, int j, int numRow, int numCol);
int countTotalBlob(int ** arr, int numRow, int numCol);
int countBlob(int ** arr, int i, int j, int numRow, int numCol);
void originalfunction(int ** arr, int numRow, int numCol);

#endif
