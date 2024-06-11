#include "coins.h"

int coin_change(int d[], int n, int k) {
    const int INF = 10000;
    int M[n+1];
    M[0] = 0;

    int i, j;
    for(j=1; j<=n; j++) {
        int minimum = INF;

        for(i=1; i<=k; i++) {
            if(j >= d[i]) {
                if((1+M[j-d[i]]) < minimum)
                    minimum = 1+M[j-d[i]];
            }
        }
        M[j] = minimum;
    }
    return M[n];
}