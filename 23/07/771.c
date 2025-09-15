#include "math.h"
#include "stdio.h"

// 未验证，leecode使用了 uthash.h 库进行处理
typedef struct linked {
    char val;
    struct linked *next;
} *HashTable;

HashTable *createTable(int hashCode, const char *jewels) {
    HashTable table[hashCode];
    for (int i = 0; i < sizeof(jewels) / sizeof(jewels[0]); ++i) {
        int temp = jewels[i] % hashCode;
        struct linked link = {jewels[i], NULL};
        if (table[temp] == NULL) {
            table[temp] = &link;
        } else {
            HashTable temps = table[temp];
            if (temps->val == jewels[i]) {
                continue;
            }
            while (temps->next != NULL) {
                temps = temps->next;
                if (temps->val == jewels[i]) {
                    continue;
                }
            }
            temps->next = &link;
        }
    }
    return table;
}

int contained(char x, HashTable *table, int hashCode) {
    int temp = x % hashCode;
    HashTable temps = table[temp];
    while (temps){
        if (temps->val == x){
            return 1;
        }
    }
    return 0;
}

int numJewelsInStones(char *jewels, char *stones) {
    int count = 0;
    int hashCode = (int) sqrt(sizeof(jewels) / sizeof(jewels[0])) + 1;
    HashTable *table = createTable(hashCode, jewels);
    for (int i = 0; i < sizeof(stones) / sizeof(stones[0]); ++i) {
        if (contained(stones[i], table, hashCode)) {
            count++;
        }
    }
    return count;
}