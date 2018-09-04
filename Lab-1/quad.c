#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
  FILE *p;
  int i, j, k, n, temp = 0;
  int test[] = {10, 100, 1000, 10000, 100000};
  clock_t time;
  p = fopen("quad.txt", "a+");
  fprintf(p, "%-10s   %-15s\n", "N Value ", "Time Taken  ");
  for (i = 0; i < 5; i++) {
    n = test[i];
    time = clock();
    for (j = 0; j < n; j++)
      for (k = 0; k < n; k++)
        temp++;
    time = clock() - time;
    fprintf(p, "%-10d: %-15lf\n", n, ((double)(time)) / CLOCKS_PER_SEC);
  }
  fclose(p);
  return 0;
}
