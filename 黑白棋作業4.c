#include <stdio.h>


int canMove(int chess[8][8], int i, int j, int color) {
    // 定義8個方向
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    // 檢查8個方向
    for (int d = 0; d < 8; d++) {
        int x = i + dx[d];
        int y = j + dy[d];

        // 如果相鄰的位置在棋盤範圍內
        if (x >= 0 && x < 8 && y >= 0 && y < 8) {
            // 如果相鄰的位置是對方的棋子
            if (chess[x][y] == 3 - color) {
                // 持續往該方向前進，直到找到空白或者找到自己的棋子
                while (x >= 0 && x < 8 && y >= 0 && y < 8 && chess[x][y] == 3 - color) {
                    x += dx[d];
                    y += dy[d];
                }
                // 如果在該方向上找到了自己的棋子，則這個移動是合法的
                if (x >= 0 && x < 8 && y >= 0 && y < 8 && chess[x][y] == color) {
                    return 1;
                }
            }
        }
    }
    // 如果在所有方向上都沒有找到合法的移動，那這個移動就不合法
    return 0;
}

int findLegalMove(int chess[8][8], int x, int y, int xDir, int yDir, int color) {
    int step = 0;
    while (1) {
        x += xDir;
        y += yDir;
        step++;

        if (x < 0 || x >= 8 || y < 0 || y >= 8) {
            return -1; // 沒找到合法落子點
        }
        if (canMove(chess, x, y, color)) {
            return step;
        }
    }
}

int main(){
    int chess[8][8] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 2, 0, 0, 0},
        {0, 0, 0, 2, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };
    int i = 3, j = 5, color = 1;
    int xDir, yDir, step = 0, x, y;
    printf("輸入x,y方向:");
    scanf("%d%d", &xDir, &yDir);
    x = i; 
    y = j;
    step = findLegalMove(chess, x, y, xDir, yDir, color);
    if (step == -1){
    printf("此方向無合法位置\n");
    }else{
    x = i + step * xDir;
    y = j + step * yDir;
    printf("(%d,%d)\n", x, y);
    printf("距離%d步\n", step);
    }
    return 0;
}