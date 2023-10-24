#include <stdio.h>

int isValidMove(int chess[8][8], int i, int j, int color) {
    // 定義8個方向的位移
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
    // 如果在所有方向上都沒有找到合法的移動，則這個移動是不合法的
    return 0;
}

int main() {
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

    int i = 3, j = 5, color = 1; // 測試座標 (3, 5)，下黑子(1)
    if (chess[i][j] == 0 && isValidMove(chess, i, j, color)) {
        printf("(%d, %d) 是空白且可以下黑子。\n", i, j);
    } else if (chess[i][j] == 1) {
        printf("(%d, %d) 是黑子。\n", i, j);
    } else if (chess[i][j] == 2) {
        printf("(%d, %d) 是白子。\n", i, j);
    } else {
        printf("(%d, %d) 不合法。\n",i, j);
    }

    return 0;
}