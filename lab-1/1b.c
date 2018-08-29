#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int i, temp;
  FILE *p, *q;
  p = fopen("ans-1a.txt", "r");
  q = fopen("ans-1b.txt", "w");
  for (i = 0; i < 10; i++) {
    fscanf(p, "%d", &temp);
    fprintf(q, "%d\n", temp);
  }
  fclose(p);
  return 0;
}
