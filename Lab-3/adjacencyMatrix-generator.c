#include <stdio.h>
#include <stdlib.h>
#define WEIGHT_LIMIT 200

int main() {
  FILE *p;
  p = fopen("in-matrix.txt", "w");
  int sizes[3] = {10, 100, 500};
  fprintf(p, "3\n");
  for (size_t i = 0; i < 3; i++) {
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
