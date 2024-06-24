#include<stdio.h>

int main() {
    int n, r, c, i, j;
    printf("Enter no of vertices:");
    scanf("%d", &n);
    int a[n][n];

    printf("enter cost adjacency matrix of a graph with %d vertices\n", n);

    // Reading adjacency matrix
    for(int i=1;i <=n;i++) {
        for(int j=1;j<=n;j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter rows and columns of path array");
    scanf("%d%d",&r,&c);

    int temp[r][c];

    // Reading paths
    printf("Enter paths");
    for(int i=1;i<=r;i++) {
        for(int j=1;j<=c;j++) {
            scanf("%d", &temp[i][j]);
        }
    }

    int mincost=1000000;
    int minr=0;
    for(int i=1;i<=r;i++) {
        int cost = 0;
        int flag=1;
        for(int j=1;j<c;j++) {
            if(a[temp[i][j]][temp[i][j+1]]!=0) {
                cost = cost + a[temp[i][j]][temp[i][j+1]];
            } else {
                flag = 0;
                break;
            }
        }
        if (flag) {
            if (mincost >= cost) {
                mincost = cost;
                minr = i;
            }
        }
    }

    if (minr == 0) {
        printf("No valid path found\n");
    } else {
        printf("Minimum cost path: ");
        for(int i=1;i<=c;i++) {
            printf("%d->", temp[minr][i]);
        }
        printf("\nMinimum cost: %d\n", mincost);
    }

    return 0;
}
