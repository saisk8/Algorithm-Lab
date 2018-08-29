#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int i;
  FILE *p;
  p = fopen("ans-1a.txt", "w+");
  for (i = 0; i < 10; i++) {
    fprintf(p, "%d\n", rand());
  }
  fclose(p);
  return 0;
}
