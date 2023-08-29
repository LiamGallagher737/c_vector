#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct Vec3
{
    int x;
    int y;
    int z;
} Vec3_t;

int main(int argc, char *argv[])
{
    Vector_t vec = with_capacity(10);

    for (int n = 0; n < 10; n++)
    {
        Vec3_t *ptr = (Vec3_t *)malloc(sizeof(Vec3_t));
        *ptr = (Vec3_t){n * 10, n, n * 100};
        append(&vec, ptr);
    }

    Vec3_t *v = (Vec3_t *)take(&vec, 1);
    free(v);

    for (int n = 0; n < 5; n++)
    {
        Vec3_t *ptr = (Vec3_t *)malloc(sizeof(Vec3_t));
        *ptr = (Vec3_t){n * 10, n, n * 100};
        append(&vec, ptr);
    }

    for (int n = 0; n < vec.length; n++)
    {
        Vec3_t *ptr = (Vec3_t *)get_index(&vec, n);
        printf("Index %d is %d, %d, %d\n", n, ptr->x, ptr->y, ptr->z);
    }

    printf("Length: %d, Capacity: %d\n", vec.length, vec.capacity);

    return 0;
}
