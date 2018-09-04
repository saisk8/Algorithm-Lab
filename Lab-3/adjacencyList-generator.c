#include <stdio.h>
#include <stdlib.h>
#define WEIGHT_LIMIT 200

int main() {
  FILE *p;
  p = fopen("in-list.txt", "w");
  int sizes[4] = {10, 100, 1000, 10000};
  fprintf(p, "4\n");
  for (size_t i = 0; i < 4; i++) {
    srand(i);
    fprintf(p, "%d\n", sizes[i]);
    int edges = rand() % (sizes[i] * sizes[i]);
    fprintf(p, "%d\n", edges);
    for (int j = 0; j < edges; j++) {
      fprintf(p, "%d %d %d\n", (rand() % sizes[i]), (rand() % sizes[i]),
              rand() % WEIGHT_LIMIT);
    }
    fprintf(p, "%d\n", (rand() % sizes[i]));
  }
  fclose(p);
  return 0;
}
