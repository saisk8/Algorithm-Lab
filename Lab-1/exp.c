#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int fibo(int n) {
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  return fibo(n - 1) + fibo(n - 2);
}

int main() {
  FILE *p;
  int i, n = 0;
  int test[] = {5, 10, 15, 20, 25};
  clock_t time = 0;
  p = fopen("exp.txt", "a+");
  fprintf(p, "%-10s   %-15s\n", "N Value ", "Time Taken  ");
  for (i = 0; i < 5; i++) {
    n = test[i];
    time = clock();
    fibo(n);
    time = clock() - time;
    fprintf(p, "%-10d: %-15lf\n", n, ((double)(time)) / CLOCKS_PER_SEC);
  }
  fclose(p);
  return 0;
}
