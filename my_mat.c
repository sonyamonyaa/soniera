#include "my_mat.h"
#include <math.h>
#include <stdio.h>

/** pseudo for all pairs shortest path
n=10
for(k=0; k<n;k++)
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            a[i,j] = min {a[i,j], a[i,k]+a[k+j]}
*/
int mat[N][N];

int inputMat()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (scanf("%d", &mat[i][j]) < 1)
                return 1;
        }
    }
    return 0;
}

int shortestPathConfig()
{
    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                //have to consider that no path is indicated by 0
                mat[i][j] = fmin(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }
    return 0;
}

int isPathed(int i, int j)
{
    shortestPathConfig();
    if (mat[i][j] > 0)
    {
        return True;
    }
    else
    {
        return False;
    }
}

int shortestPath(int i, int j)
{
    if(is_pathed(i,j))
        return mat[i][j];
    else
        return -1;
}