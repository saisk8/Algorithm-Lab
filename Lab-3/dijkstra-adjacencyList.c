#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    unsigned int vertex, weight;
    struct node *next;
};

struct vertex {
    unsigned int vertex, dist;
};

struct node *addEdge(struct node *head, unsigned int vertex,
                     unsigned int weight) {
    struct node *newNode = (struct node *)calloc(1, sizeof(struct node));

    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = head;

    return newNode;
}

void heapify(struct vertex minHeap[], unsigned int size, unsigned int i,
             unsigned int position[]) {
    struct vertex temp;

    while ((2 * i) <= size) {
        if ((2 * i) + 1 > size) {
            if (minHeap[i].dist > minHeap[2 * i].dist) {
                position[minHeap[i].vertex] = 2 * i;
                position[minHeap[2 * i].vertex] = i;

                temp = minHeap[i];
                minHeap[i] = minHeap[2 * i];
                minHeap[2 * i] = temp;
            }

            break;
        }

        if (minHeap[i].dist > minHeap[2 * i].dist ||
            minHeap[i].dist > minHeap[2 * i + 1].dist) {
            if (minHeap[2 * i].dist <= minHeap[(2 * i) + 1].dist) {
                position[minHeap[i].vertex] = 2 * i;
                position[minHeap[2 * i].vertex] = i;

                temp = minHeap[2 * i];
                minHeap[2 * i] = minHeap[i];
                minHeap[i] = temp;

                i = 2 * i;
            } else if (minHeap[2 * i].dist > minHeap[(2 * i) + 1].dist) {
                position[minHeap[i].vertex] = 2 * i + 1;
                position[minHeap[2 * i + 1].vertex] = i;

                temp = minHeap[(2 * i) + 1];
                minHeap[(2 * i) + 1] = minHeap[i];
                minHeap[i] = temp;

                i = (2 * i) + 1;
            }
        } else {
            break;
        }
    }
}

void buildHeap(struct vertex minHeap[], unsigned int size,
               unsigned int position[]) {
    unsigned int i;

    for (i = size / 2; i >= 1; --i) {
        heapify(minHeap, size, i, position);
    }
}

void decreaseKey(struct vertex minHeap[], struct vertex newNode,
                 unsigned int position[]) {
    minHeap[position[newNode.vertex]].dist = newNode.dist;

    unsigned int i = position[newNode.vertex];
    struct vertex temp;

    while (i > 1) {
        if (minHeap[i / 2].dist > minHeap[i].dist) {
            position[minHeap[i].vertex] = i / 2;
            position[minHeap[i / 2].vertex] = i;

            temp = minHeap[i / 2];
            minHeap[i / 2] = minHeap[i];
            minHeap[i] = temp;

            i = i / 2;
        } else {
            break;
        }
    }
}

struct vertex extractMin(struct vertex minHeap[], unsigned int size,
                         unsigned int position[]) {
    position[minHeap[1].vertex] = size;
    position[minHeap[size].vertex] = 1;

    struct vertex min = minHeap[1];

    minHeap[1] = minHeap[size];
    --size;
    heapify(minHeap, size, 1, position);

    return min;
}

void dijkstra(struct node *adjacencyList[], unsigned int vertices,
              unsigned int startVertex, unsigned int distances[]) {
    unsigned int i;
    struct vertex minVertex;
    struct vertex priorityQueue[vertices + 1];
    unsigned int position[vertices + 1];

    for (i = 1; i <= vertices; ++i) {
        distances[i] = UINT_MAX;
        priorityQueue[i].dist = UINT_MAX;
        priorityQueue[i].vertex = i;
        position[i] = priorityQueue[i].vertex;
    }

    distances[startVertex] = 0;
    priorityQueue[startVertex].dist = 0;
    buildHeap(priorityQueue, vertices, position);

    for (i = 1; i <= vertices; ++i) {
        minVertex = extractMin(priorityQueue, vertices, position);
        struct node *adjacent = adjacencyList[minVertex.vertex];

        while (adjacent != NULL) {
            unsigned int u = minVertex.vertex;
            unsigned int v = adjacent->vertex;
            unsigned int w = adjacent->weight;

            if (distances[u] != UINT_MAX && distances[v] > distances[u] + w) {
                distances[v] = distances[u] + w;
                struct vertex changedVertex;

                changedVertex.vertex = v;
                changedVertex.dist = distances[v];
                decreaseKey(priorityQueue, changedVertex, position);
            }

            adjacent = adjacent->next;
        }
    }
}

int main() {
    unsigned int vertices, edges, i, v1, v2, w, startVertex;
    FILE *p, *q, *r;
    p = fopen("in-list.txt", "r");
    q = fopen("out-list.txt", "w");
    r = fopen("readme.txt", "a+");
    int testCases, count = 0;
    clock_t time = 0;
    fscanf(p, "%d", &testCases);
    fprintf(r, "%s\n", "For adjacency list and min heap algorithm: ");
    fprintf(r, "%-10s   %-15s\n", "N Value ", "Time Taken  ");
    while (testCases--) {
        fprintf(q, "Test Case: %d\n", ++count);
        fscanf(p, "%d", &vertices);
        fscanf(p, "%d", &edges);

        struct node *adjacencyList[vertices + 1];
        unsigned int distances[vertices + 1];

        for (i = 0; i <= vertices; ++i) {
            adjacencyList[i] = NULL;
        }

        for (i = 1; i <= edges; ++i) {
            fscanf(p, "%d%d%d", &v1, &v2, &w);
            adjacencyList[v1] = addEdge(adjacencyList[v1], v2, w);
        }

        fscanf(p, "%d", &startVertex);
        time = clock();
        dijkstra(adjacencyList, vertices, startVertex, distances);
        time = clock() - time;
        fprintf(r, "%-10d: %-15lf\n", vertices, ((double)(time)) / CLOCKS_PER_SEC);
        fprintf(q, "Shortest distances -\n");

        for (i = 1; i <= vertices; ++i) {
            fprintf(q, "Node: %d, Distance = %d\n", i, distances[i]);
        }
        fprintf(q, "\n\n");
    }
    fclose(p);
    fclose(q);
    fclose(r);
    return 0;
}
