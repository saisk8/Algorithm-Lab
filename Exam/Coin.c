// C++ program for coin change problem.
#include <limits.h>
#include <stdio.h>
int N = 5, A = 11, INF = 999;
int count(int S[], int m, int n) {
    // table[i] will be storing the number of solutions for
    // value i. We need n+1 rows as the table is constructed
    // in bottom up manner using the base case (n = 0)
    int table[n + 1];

    // Initialize all table values as 0
    memset(table, 0, sizeof(table));

    // Base case (If given value is 0)
    table[0] = 1;

    // Pick all coins one by one and update the table[] values
    // after the index greater than or equal to the value of the
    // picked coin
    for (int i = 0; i < m; i++)
        for (int j = S[i]; j <= n; j++) table[j] += table[j - S[i]];

    return table[n];
}

// m is size of coins array (number of different coins)
// V is amount
int minCoins(int coins[], int m, int V) {
    // table[i] will be storing the minimum number of coins
    // required for i value.  So table[V] will have result
    int table[V + 1];

    // Base case (If given value V is 0)
    table[0] = 0;

    // Initialize all table values as Infinite
    for (int i = 1; i <= V; i++) table[i] = INT_MAX;

    // Compute minimum coins required for all
    // values from 1 to V
    for (int i = 1; i <= V; i++) {
        // Go through all coins smaller than i
        for (int j = 0; j < m; j++)
            if (coins[j] <= i) {
                int sub_res = table[i - coins[j]];
                if (sub_res != INT_MAX && sub_res + 1 < table[i])
                    table[i] = sub_res + 1;
            }
    }
    return table[V];
}

// Driver Code
int main() {
    int arr[] = {1, 2, 3};
    int coins[] = {9, 6, 5};
    int V = 11;
    int m = sizeof(arr) / sizeof(arr[0]);
    int n = 4;
    count(arr, m, n);
    minCoins(coins, m, V);
    return 0;
}

void coinChange(int d[N + 1], int C[A + 1], int S[A + 1]) {
    int i, p, min, coin;

    // when amount is 0
    // then min coin required is 0
    C[0] = 0;
    S[0] = 0;

    for (p = 1; p <= A; p++) {
        min = INF;
        for (i = 1; i <= N; i++) {
            if (d[i] <= p) {
                if (1 + C[p - d[i]] < min) {
                    min = 1 + C[p - d[i]];
                    coin = i;
                }
            }
        }
        C[p] = min;
        S[p] = coin;
    }
}

void coinSet(int d[N + 1], int S[A + 1]) {
    int a = A;
    while (a > 0) {
        printf("Use coin of denomination: %d\n", d[S[a]]);
        a = a - d[S[a]];
    }
}
