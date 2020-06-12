#include <stdio.h>

int main() {
    int anInt = 42;
    long aLong = 42;
    short aShort = 42;

    unsigned int anUnsignedInt = 42;
    unsigned long anUnsignedLong = 42;
    unsigned short anUnsignedShort = 42;

    printf("anInt contains: %d and is size: %lu\n", anInt, sizeof(anInt));
    printf("aLong contains: %ld and is size: %lu\n", aLong, sizeof(aLong));
    printf("aShort contains: %hd and is size: %lu\n", aShort, sizeof(aShort));

    printf("anUnsignedInt contains: %u and is size: %lu\n", anUnsignedInt, sizeof(anUnsignedInt));
    printf("anUnsignedLong contains: %lu and is size: %lu\n", anUnsignedLong, sizeof(anUnsignedLong));
    printf("anUnsignedShort contains: %hu and is size: %lu\n", anUnsignedShort, sizeof(anUnsignedShort));

    return(0);
}
