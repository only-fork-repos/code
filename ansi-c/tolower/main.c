#include <stdio.h>
#include <string.h>

const char* lower(const char* input) {
    static char buffer[100];
    int i;
    for (i=0; i<strlen(input); i++) {
        buffer[i] = tolower(input[i]);
    }
    buffer[strlen(input)] = 0;
    return buffer;
}


int main(int argc, const char *argv[])
{
    printf("'%s' -> '%s'\n", argv[1], lower(argv[1]));
    return 0;
}

