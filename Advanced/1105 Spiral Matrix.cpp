#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int** matrix;
int sequence[10000];

int directionX[4] = {0, 1, 0, -1};
int directionY[4] = {1, 0, -1, 0};

void getRowColomn(int n, int& row, int& colomn);
void fillMatrix(int n, int row, int colomn);

int main(int argc, char const *argv[])
{
    int n, row, colomn;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &sequence[i]);
    sort(sequence, sequence + n);
    getRowColomn(n, row, colomn);
    matrix = (int**)malloc(sizeof(int*) * row);
    for(int i = 0; i < row; i++)
    {
        matrix[i] = (int*)malloc(sizeof(int) * colomn);
        for(int j = 0; j < colomn; j++)
            matrix[i][j] = 0;
    }
    fillMatrix(n, row, colomn);
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < colomn - 1; j++)
            printf("%d ", matrix[i][j]);
        printf("%d\n", matrix[i][colomn - 1]);
    }
    return 0;
}

void getRowColomn(int n, int& row, int& colomn)
{
    int up = (int)sqrt(n);
    for(int i = 1; i <= up; i++)
    {
        if(n % i == 0)
            colomn = i;
    }
    row = n / colomn;
}

void fillMatrix(int n, int row, int colomn)
{
    int x = 0, y = 0;
    int i = 0;
    while(n > 0)
    {
        matrix[x][y] = sequence[n - 1];
        n--;
        x += directionX[i % 4];
        y += directionY[i % 4];
        if(x < 0 || x >= row || y < 0 || y >= colomn || matrix[x][y] != 0)
        {
            x -= directionX[i % 4];
            y -= directionY[i % 4];
            i++;
            x += directionX[i % 4];
            y += directionY[i % 4];
        }
    }
}