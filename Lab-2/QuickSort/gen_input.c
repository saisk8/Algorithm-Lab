#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  FILE *r;
  int c, n;
  // 100 numbers
  r = fopen("in_ran100.txt", "w");
  // Random order
  fprintf(r, "100\n");
  srand(4);
  for (c = 1; c <= 100; c++) {
    n = (rand() % 200 + 1) - 100;
    fprintf(r, "%d\n", n);
  }
  fclose(r);

  // 1000 numbers
  r = fopen("in_ran1000.txt", "w");
  // Random order
  fprintf(r, "1000\n");
  srand(7);
  for (c = 1; c <= 1000; c++) {
    n = (rand() % 2000 + 1) - 1000;
    fprintf(r, "%d\n", n);
  }
  fclose(r);

  // 10000 numbers
  r = fopen("in_ran10000.txt", "w");
  // Random order
  fprintf(r, "10000\n");
  srand(10);
  for (c = 1; c <= 10000; c++) {
    n = (rand() % 20000 + 1) - 10000;
    fprintf(r, "%d\n", n);
  }
  fclose(r);

  // 100000 numbers
  r = fopen("in_ran100000.txt", "w");
  // Random order
  fprintf(r, "100000\n");
  srand(13);
  for (c = 1; c <= 100000; c++) {
    n = (rand() % 200000 + 1) - 100000;
    fprintf(r, "%d\n", n);
  }
  fclose(r);
  return 0;
}
