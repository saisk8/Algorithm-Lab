#include <stdio.h>

// A utility function that returns maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n) {
    int i, w;
    int K[n + 1][W + 1];
    int x[n + 1];  // intilaise with zeros;

    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] =
                    max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    int a = n, b = W;
    while (a != 0 && b != 0) {
        if (K[a][b] != K[a - 1][b]) {
            x[i] = 1;
            b = b - wt[i];
            a--;
        } else
            a--;
    }
    int count = 0;
    printf("Items included are\n");
    printf("Sl.no\tweight\tprofit\n");
    for (i = 1; i <= n; i++)
        if (x[i]) printf("%d\t%d\t%d\n", ++count, wt[i], val[i]);
    return K[n][W];
}

int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    printf("%d", knapSack(W, wt, val, n));
    return 0;
}