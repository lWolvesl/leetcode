#define INF 0x3f3f3f3f

int minimumWhiteTiles(char* floor, int numCarpets, int carpetLen) {
    int n = strlen(floor);
    int d[n + 1][numCarpets + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= numCarpets; j++) {
            d[i][j] = INF;
        }
    }
    for (int j = 0; j <= numCarpets; j++) {
        d[0][j] = 0;
    }
    for (int i = 1; i <= n; i++) {
        d[i][0] = d[i - 1][0] + (floor[i - 1] == '1' ? 1 : 0);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= numCarpets; j++) {
            d[i][j] = d[i - 1][j] + (floor[i - 1] == '1' ? 1 : 0);
            d[i][j] = fmin(d[i][j], d[(int)fmax(0, i - carpetLen)][j - 1]);
        }
    }
    int result = d[n][numCarpets];
    return result;
}