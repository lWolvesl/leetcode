#ifndef Q1552_H
#define Q1552_H

static int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

static bool check(int x, const int* position, int positionSize, int m) {
    int pre = position[0], cnt = 1;
    for (int i = 1; i < positionSize; ++i) {
        if (position[i] - pre >= x) {
            pre = position[i];
            cnt += 1;
        }
    }
    return cnt >= m;
}

int maxDistance(int* position, int positionSize, int m) {
    qsort(position, positionSize, sizeof(int), compare);
    int left = 1, right = position[positionSize - 1] - position[0], ans = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (check(mid, position, positionSize, m)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

#endif