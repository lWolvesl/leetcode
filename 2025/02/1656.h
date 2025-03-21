#include <stdlib.h>

typedef struct {
    char **stream;
    int streamSize;
    int ptr;
} OrderedStream;

OrderedStream* orderedStreamCreate(int n) {
    OrderedStream *obj = (OrderedStream *)malloc(sizeof(OrderedStream));
    obj->stream = (char **)malloc(sizeof(char *) * (n + 1));
    for (int i = 0; i <= n; i++) {
        obj->stream[i] = NULL;
    }
    obj->streamSize = n + 1;
    obj->ptr = 1;
    return obj;
}

char ** orderedStreamInsert(OrderedStream* obj, int idKey, char * value, int* retSize) {
    obj->stream[idKey] = value;
    char **res = (char **)malloc(sizeof(char *) * obj->streamSize);
    int pos = 0;
    while (obj->ptr < obj->streamSize && obj->stream[obj->ptr]) {
        res[pos++] = obj->stream[obj->ptr];
        obj->ptr++;
    }
    *retSize = pos;
    return res;
}

void orderedStreamFree(OrderedStream* obj) {
    free(obj->stream);
    free(obj);
}
