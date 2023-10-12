#include <iostream>
#include <cstring>

bool checkRow(char grid[50][50], int yToCheck, int xStart, int xEnd) {
    if (yToCheck < 0 || yToCheck > 49) {
        return false;
    }
    if (xStart < 0) {
        xStart = 0;
    }
    if (xEnd > 49) {
        xEnd = 49;
    }
    for (int x = xStart; x <= xEnd; x++) {
        if (grid[yToCheck][x] == '1') {
            return true;
        }
    }
    return false;
}

bool checkColumn(char grid[50][50], int xToCheck, int yStart, int yEnd) {
    if (xToCheck < 0 || xToCheck > 49) {
        return false;
    }
    if (yStart < 0) {
        yStart = 0;
    }
    if (yEnd > 49) {
        yEnd = 49;
    }
    for (int y = yStart; y <= yEnd; y++) {
        if (grid[y][xToCheck] == '1') {
            return true;
        }
    }
    return false;
}

int getSafeDistance(char grid[50][50], int y, int x, int n, int m) {
    int maxYDist = n - y > y ? n - y : y;
    int maxXDist = m - x > x ? m - x : x;
    int maxDist = maxYDist > maxXDist ? maxYDist : maxXDist;

    int yStart, yEnd, xStart, xEnd;
    for (int dist = 1; dist <= maxDist; dist++) {
        yStart = y - dist;
        yEnd = y + dist;
        xStart = x - dist;
        xEnd = x + dist;

        if (checkRow(grid, yStart, xStart, xEnd)
            || checkRow(grid, yEnd, xStart, xEnd)
            || checkColumn(grid, xStart, yStart, yEnd)
            || checkColumn(grid, xEnd, yStart, yEnd)) {
            return dist;
        }
    }
    return 0;
}

int main(void) {
    char grid[50][50];
    int n, m;

    std::cin >> n >> m;
    std::cin.ignore();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> grid[i][j];
        }
        std::cin.ignore();
    }

    int safeDistance = 0;
    int temp;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (grid[y][x] == '1') {
                continue ;
            }
            temp = getSafeDistance(grid, y, x, n, m);
            if (temp > safeDistance) {
                safeDistance = temp;
            }
        }
    }
    
    std::cout << safeDistance << '\n';

    return 0;
}