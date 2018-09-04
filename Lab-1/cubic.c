#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
  FILE *p;
  int i, j, k, l, n, temp = 0;
  int test[] = {5, 10, 15, 20, 25};
  clock_t time;
  p = fopen("cubic.txt", "a+");
  fprintf(p, "%-10s   %-15s\n", "N Value ", "Time Taken  ");
  for (i = 0; i < 5; i++) {
    n = test[i];
    time = clock();
    for (j = 0; j < n; j++)
      for (k = 0; k < n; k++)
        for (l = 0; l < n; l++)
          temp++;
    time = clock() - time;
    fprintf(p, "%-10d: %-15lf\n", n, ((double)(time)) / CLOCKS_PER_SEC);
  }
  fclose(p);
  return 0;
}
