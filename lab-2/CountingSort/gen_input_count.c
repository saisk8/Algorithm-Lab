#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  FILE *r;
  int c, n;
  // 50 numbers
  r = fopen("in_random50.txt", "w");
  // Random order
  fprintf(r, "50\n");
  srand(25);
  for (c = 1; c <= 50; c++) {
    n = (rand() % 11);
    fprintf(r, "%d\n", n);
  }
  fclose(r);

  // 100 numbers
  r = fopen("in_random100.txt", "w");
  // Random order
  fprintf(r, "100\n");
  srand(16);
  for (c = 1; c <= 100; c++) {
    n = (rand() % 26);
    fprintf(r, "%d\n", n);
  }
  fclose(r);

  // 500 numbers
  r = fopen("in_random500.txt", "w");
  // Random order
  fprintf(r, "500\n");
  srand(15);
  for (c = 1; c <= 500; c++) {
    n = (rand() % 126);
    fprintf(r, "%d\n", n);
  }
  fclose(r);

  // 1000 numbers
  r = fopen("in_random1000.txt", "w");
  // Random order
  fprintf(r, "1000\n");
  srand(19);
  for (c = 1; c <= 1000; c++) {
    n = (rand() % 251);
    fprintf(r, "%d\n", n);
  }
  fclose(r);
  return 0;
}
