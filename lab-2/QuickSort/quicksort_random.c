#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long int swaps, comps;

int quickSort(int a[], int low, int high);
int partition(int a[], int low, int high);
void fnSwap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
  swaps++;
}

int main(int argc, char *argv[]) {
  int n, i;
  FILE *p, *q, *r;
  p = fopen(argv[1], "r");
  q = fopen(argv[2], "w");
  r = fopen("readme.txt", "a");
  // Read the number of elements
  fscanf(p, "%d", &n);
  int a[n + 1];
  for (i = 1; i <= n; i++) {
    fscanf(p, "%d", &a[i]);
  }

  quickSort(a, 1, n);

  fprintf(q, "%lld\n%lld\n", comps, swaps);
  for (i = 1; i <= n; i++)
    fprintf(q, "%d\n", a[i]);
  fprintf(
      r,
      "File name: %-18s, Input Size: %-6d, Number of Swaps = %-8lld, Number "
      "of Comparisons = %-12lld\n",
      argv[1], n, swaps, comps);
  fclose(p);
  fclose(q);
  return 0;
}

int quickSort(int a[], int low, int high) {
  int j;

  if (low < high) {
    j = partition(a, low, high);
    quickSort(a, low, j - 1);
    quickSort(a, j + 1, high);
  }

  return 0;
}

int partition(int a[], int low, int high) {
  srand(time(NULL));
  int random = low + rand() % (high - low);
  fnSwap(&a[random], &a[low]);
  int key = a[low], i = low + 1, j = high;

  for (;;) {
    while (key >= a[i] && i < high && ++comps)
      i++;

    while (key < a[j] && ++comps)
      j--;

    if (i < j) {
      fnSwap(&a[i], &a[j]);
    } else {
      fnSwap(&a[low], &a[j]);
      return j;
    }
  }
}
