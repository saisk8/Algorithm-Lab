#include <stdio.h>
#include <stdlib.h>
#define WEIGHT_LIMIT 200

int main() {
  FILE *p;
  p = fopen("in-matrix.txt", "w");
  int sizes[4] = {10, 100, 1000, 10000};
  fprintf(p, "4\n");
  for (size_t i = 0; i < 4; i++) {
    srand(i);
    fprintf(p, "%d\n", sizes[i]);
    for (int j = 0; j < sizes[i]; j++) {
      for (int k = 0; k < sizes[i]; k++)
        fprintf(p, "%d ", rand() % WEIGHT_LIMIT);
      fprintf(p, "\n");
    }
    fprintf(p, "%d\n", (rand() % sizes[i]));
  }
  fclose(p);
  return 0;
}
