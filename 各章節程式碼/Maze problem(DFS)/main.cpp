
#include <iostream>


#define GRAPH_SIZE 10
#define ACT 4
const int dx[ACT] = {1, 0, -1, 0};    // 四種方向
const int dy[ACT] = {0, 1, 0, -1};

struct point
{
    int x;
    int y;
};

//"-1" 表示牆壁
//"0"  表示可走的路
int maze[GRAPH_SIZE][GRAPH_SIZE] = { {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                                     {-1, 0,0, -1, 0, 0, 0, 0, 0,-1},
                                     {-1, 0,0,-1, 0, 0, 0, 0, 0,-1},
                                     {-1, 0,-1,-1, 0, 0, 0, 0, 0,-1},
                                     {-1,0,-1, 0, 0, 0, 0, 0, 0,-1},
                                     {-1, 0, 0, 0, 0, -1, 0, 0, 0,-1},
                                     {-1, 0, 0, 0, 0, -1, 0, 0, 0,-1},
                                     {-1, 0, 0, 0, 0, -1, 0, 0, 0,-1},
                                     {-1, 0, 0, 0, 0, -1, 0, 0, 0,-1},
                                     {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}};

int DFS(int x, int y, int target_x, int target_y, int d)
{
    if ( !(maze[x][y] == -1 || maze[x][y] > 0) ) {      //沒碰到牆壁或走過的路才會繼續
        maze[x][y] = d;
        printf("maze[%d][%d]\n",x,y);
        if ( !(x == target_x && y == target_y) ) {      //還沒走到目的地則繼續
            int i;
            for (i=0; i<ACT; ++i)
            {
                DFS(x + dx[i], y + dy[i], target_x, target_y, d + 1);
                if (maze[target_x][target_y] != 0)      //當以走到目的地時就不用再往其他方向走,所以跳出迴圈
                    break;
            }
            //當走到無路可走時,就會往回走,所以把目前這個點設為0,代表走到目的地時,不會顯示走過這個點
            if(i == ACT)
                maze[x][y] = 0;
        }
    }
    return maze[target_x][target_y];
}

int main(int argc, char* argv[])
{
    int ans = 0;
    struct point start    ={1,1};
    struct point end      ={7,7};

    ans = DFS(start.x, start.y, end.x, end.y,1);

    if (ans < 1)
        std::cout << "Mouse can't find the exit\n" << !2 <<std::endl;
    else
        std::cout << "Mouse find a path is " << ans << std::endl;

    for(int i=0; i<GRAPH_SIZE; i++) {
        for(int j=0; j<GRAPH_SIZE; j++) {
            if(maze[i][j] == -1)
                printf("██");
            else if(maze[i][j] == 0)
                printf("  ");
            else
                printf("%2d",maze[i][j]);
        }
        std::cout << std::endl ;
    }
    return 0;
}