#include <cstdio>
#include <queue>

using namespace std;

int directionX[6] = {1, -1, 0, };
int directionY[6] = {0, 0, 1, -1, 0};
int directionZ[6] = {0, 0, 0, 0, 1, -1};

struct Position
{
    int x; int y; int z;
    explicit Position(int x, int y, int z){this->x = x; this->y = y; this->z = z;}
    Position(){x = y = z = 0;}
};

bool slice[1286][128][60] = {false};
int count = 0;
int tempCount = 0;

//void getCount(int x, int y, int z, int m, int n, int l);
void getCount(Position p, int m, int n, int l);

int main(int argc, char const *argv[])
{
    int m, n, l, t, val;
    scanf("%d %d %d %d", &m, &n, &l, &t);

    for(int i = 0; i < l; i++)
    {
        for(int j = 0; j < m; j++)
        {
            for(int k = 0; k < n; k++)
            {
                scanf("%d", &val);
                slice[j][k][i] = (val == 1);
            }
        }
    }

    for(int i = 0; i < l; i++)
        for(int j = 0; j < m; j++)
            for(int k = 0; k < n; k++)
            {
                if(slice[j][k][i])
                {
                    tempCount = 1;
                    slice[j][k][i] = false;
                   // getCount(j, k, i, m, n, l);
                    getCount(Position(j, k, i), m, n, l);
                    if(tempCount >= t)
                        count += tempCount;
                }
            }
    printf("%d\n", count);
    return 0;
}

//Use BFS
void getCount(Position p, int m, int n, int l)
{
    Position currentPosition;
    int x, y, z, newX, newY, newZ;
    queue<Position> q;
    q.push(p);
    while(!q.empty())
    {
        currentPosition = q.front();
        q.pop();
        x = currentPosition.x; y = currentPosition.y, z = currentPosition.z;
        for(int i = 0; i < 6; i++)
        {
            newX = x + directionX[i];
            newY = y + directionY[i];
            newZ = z + directionZ[i];
            if(newX >= 0 && newX < m && newY >= 0 && newY < n && newZ >= 0 && newZ < l)
            {
                if (slice[newX][newY][newZ])
                {
                    tempCount++;
                    slice[newX][newY][newZ] = false;
                    q.push(Position(newX, newY, newZ));
                }
            }
        }
    }
}


//Don't use DFS
//void getCount(int x, int y, int z, int m, int n, int l)
//{
//    for(int i = 0; i < 6; i++)
//    {
//        int newX = x + directionX[i];
//        int newY = y + directionY[i];
//        int newZ = z + directionZ[i];
//        if(newX >= 0 && newX < m && newY >= 0 && newY < n &&
//           newZ >= 0 && newZ < l)
//        {
//            if(slice[newX][newY][newZ])
//            {
//                tempCount++;
//                slice[newX][newY][newZ] = false;
//                getCount(newX, newY, newZ, m, n, l);
//            }
//        }
//    }
//}