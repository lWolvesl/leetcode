static int max(int a, int b) {
    return a > b ? a : b;
}

static int min(int a, int b) {
    return a < b ? a : b;
}

int storeWater(int* bucket, int bucketSize, int* vat, int vatSize) {
    int maxk = 0;
    for (int i = 0; i < vatSize; i++) {
        maxk = max(maxk, vat[i]);
    }
    if (maxk == 0) {
        return 0;
    }
    int res = INT_MAX;
    for (int k = 1; k <= maxk && k < res; ++k) {
        int t = 0;
        for (int i = 0; i < bucketSize; ++i) {
            t += max(0, (vat[i] + k - 1) / k - bucket[i]);
        }
        res = min(res, t + k);
    }
    return res;
}