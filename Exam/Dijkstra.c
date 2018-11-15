#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int nodes;
void minHeapify(unsigned int heap[][2], unsigned int index, unsigned int n) {
    unsigned int leftChild = 2 * index;
    unsigned int rightChild = 2 * index + 1;
    unsigned int smallest = 0;

    if (leftChild <= n && heap[leftChild - 1][0] < heap[index - 1][0]) {
        smallest = leftChild;
    } else {
        smallest = index;
    }
    if (rightChild <= n && heap[rightChild - 1][0] < heap[smallest - 1][0]) {
        smallest = rightChild;
    }
    if (smallest != index) {
        unsigned int temp1 = heap[index - 1][0];
        unsigned int temp2 = heap[index - 1][1];

        heap[index - 1][0] = heap[smallest - 1][0];
        heap[index - 1][1] = heap[smallest - 1][1];
        heap[smallest - 1][0] = temp1;
        heap[smallest - 1][1] = temp2;

        minHeapify(heap, smallest, n);
    }
}

void buildMinHeap(unsigned int A[][2], unsigned int n) {
    for (int i = (n / 2); i > 0; i--) {
        minHeapify(A, i, n);
    }
}

unsigned int extractMinFromHeap(unsigned int heap[][2], unsigned int n,
                                unsigned int *node_index) {
    if (n < 1) {
        printf("error: underflow\n");
        return -1;
    }

    unsigned int min = heap[0][0];
    unsigned int u = heap[0][1];

    if (n > 1) {
        heap[0][0] = heap[n - 1][0];
        heap[0][1] = heap[n - 1][1];
        buildMinHeap(heap, n - 1);
    }
    *node_index = u;
    return min;
}

void heapDecreaseKey(unsigned int heap[][2], unsigned int u,
                     unsigned int weight, unsigned int n) {
    for (int i = 0; i < n; i++) {
        if (heap[i][1] == u) {
            if (weight < heap[i][0]) {
                heap[i][0] = weight;
                unsigned int parent = i / 2;
                while (i > 0 && heap[parent][0] > heap[i][0]) {
                    // swap
                    unsigned int temp1 = heap[parent][0];
                    unsigned int temp2 = heap[parent][1];
                    heap[parent][0] = heap[i][0];
                    heap[parent][1] = heap[i][1];
                    heap[i][0] = temp1;
                    heap[i][1] = temp2;
                    i = parent;
                    parent = i / 2;
                }
            }
            break;
        }
    }
}

void dijkstra(unsigned int adjacencyMatrix[][nodes], unsigned int distance[][2],
              int source, int n) {
    unsigned int heap[n][2];
    unsigned int S[n];

    for (int i = 0; i < n; i++) {
        distance[i][0] = UINT_MAX;
        distance[i][1] = UINT_MAX;
        heap[i][0] = UINT_MAX;
        heap[i][1] = i;
        S[i] = 0;
    }
    distance[source][0] = 0;
    distance[source][1] = 0;
    heap[source][0] = 0;

    unsigned int heap_size = n;

    buildMinHeap(heap, heap_size);

    while (heap_size > 0) {
        unsigned int u = UINT_MAX;
        unsigned int min_val = extractMinFromHeap(heap, heap_size, &u);

        if (u == -1) {
            printf("unexpected case\n");
            break;
        }
        S[u] = 1;
        heap_size--;
        if (min_val == UINT_MAX) {
            break;
        } else {
            for (unsigned int v = 0; v < n; v++) {
                unsigned int w = adjacencyMatrix[u][v];
                if (w != UINT_MAX && S[v] != 1) {
                    if (distance[v][0] > distance[u][0] + w) {
                        distance[v][0] = distance[u][0] + w;
                        distance[v][1] = u;
                        heapDecreaseKey(heap, v, distance[u][0] + w, n);
                    }
                }
            }
        }
    }
}

int main() {
    int testCases, source;
    FILE *p, *q, *r;
    p = fopen("in-matrix.txt", "r");
    q = fopen("out-matrix.txt", "w");
    r = fopen("readme.txt", "a+");
    clock_t time = 0;
    fscanf(p, "%d", &testCases);
    fprintf(r, "%s\n", "For adjacency matrix and min heap algorithm: ");
    fprintf(r, "%-10s   %-15s\n", "N Value ", "Time Taken  ");
    for (int i = 0; i < testCases; i++) {
        fprintf(q, "Test Case: %d\n", i + 1);
        fscanf(p, "%d", &nodes);

        unsigned int adjacencyMatrix[nodes][nodes];
        unsigned int shortestDistance[nodes][2];
        memset(adjacencyMatrix, -1, sizeof(adjacencyMatrix));
        memset(shortestDistance, -1, sizeof(shortestDistance));
        for (int i = 0; i < nodes; i++) {
            for (int j = 0; j < nodes; j++) {
                fscanf(p, "%d", &adjacencyMatrix[i][j]);
                if (!adjacencyMatrix[i][j]) {
                    adjacencyMatrix[i][j] = UINT_MAX;
                }
            }
        }
        fscanf(p, "%d", &source);
        time = clock();
        dijkstra(adjacencyMatrix, shortestDistance, source - 1, nodes);
        time = clock() - time;
        fprintf(r, "%-10d: %-15lf\n", nodes, ((double)(time)) / CLOCKS_PER_SEC);
        fprintf(q, "%s\n", "Shortest distances-");
        for (int i = 0; i < nodes; i++) {
            fprintf(q, "Node: %d, Distance: %d\n", i + 1,
                    shortestDistance[i][0]);
        }
        fprintf(q, "\n\n");
    }
    fclose(p);
    fclose(q);
    fclose(r);
    return 0;
}