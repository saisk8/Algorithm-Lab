#include <stdio.h>

int main(int argc, char const *argv[]) {
  int n;
  FILE *p, *q;
  p = fopen(argv[1], "r");
  q = fopen(argv[2], "w");
  fscanf(p, "%d", &n);
  int a[n], b[n];
  for (int i = 0; i < n; i++) {
    fscanf(p, "%d", &a[i]);
    b[i] = 0;
  }
  for (int i = 0; i < n; i++)
    b[a[i]]++;
  for (int i = 0; i < n; i++)
    while (b[i]--)
      fprintf(q, "%d\n", i);
  return 0;
}
