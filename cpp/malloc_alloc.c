#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    // malloc 申请的内存不会初始化
    printf("====malloc 申请内存=======\n");
    int *pmalloc = NULL;
    pmalloc = (int*)malloc(10 * sizeof(int));
    for(int i = 0; i < 10; ++i) {
        printf("Index %d: %d\n", i, pmalloc[i]);
    }
    free(pmalloc);

    // calloc 申请的内存会初始化
    printf("====calloc 申请内存====\n");
    int *pcalloc = NULL;
    pcalloc = (int*)calloc(10, sizeof(int));
    for(int i = 0; i < 10; ++i) {
        printf("Index %d: %d\n", i, pcalloc[i]);
    }
    free(pcalloc);

    // recalloc 扩展内存大小

    return 0;
}
