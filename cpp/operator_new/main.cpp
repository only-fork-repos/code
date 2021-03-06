#include <stdio.h>
#include <stdlib.h>

#include "ClassA.h"
#include "ClassB.h"

using namespace Test;

int total = 0;

// add int with size before pointer
inline void * operator new(size_t size) {
    printf("%s()\n", __func__);
    int* ptr = (int*)malloc(size+sizeof(int));
    *ptr = size;
    total += size;
    return ptr+1;
};

inline void operator delete(void *p) {
    int* real = (int*)p;
    real--;
    int size = *real;
    total -= size;
    free(real);
};

void printMem() {
    printf("using %d bytes\n", total);
}

int main(int argc, const char *argv[])
{
    ClassA aa;
    ClassA* a = new ClassA(); 
    printMem();

    delete a;
    printMem();
    return 0;
}


