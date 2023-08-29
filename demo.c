#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

// Just to showcase something other than ints
typedef struct Vec3
{
    int x;
    int y;
    int z;
} Vec3_t;

int main(int argc, char *argv[])
{
    // Create a new vector with room for 10 elements
    Vector_t vec = with_capacity(10);

    // Initialize with some values
    for (int n = 0; n < 10; n++)
    {
        Vec3_t *ptr = (Vec3_t *)malloc(sizeof(Vec3_t));
        *ptr = (Vec3_t){n * 10, n, n * 100};
        append(&vec, ptr);
    }

    // Remove an element
    Vec3_t *v = (Vec3_t *)take(&vec, 1);
    free(v);

    // Add another 5 elements to showcase reallocating when length exceeds capacity
    for (int n = 0; n < 5; n++)
    {
        Vec3_t *ptr = (Vec3_t *)malloc(sizeof(Vec3_t));
        *ptr = (Vec3_t){n * 10, n, n * 100};
        append(&vec, ptr);
    }

    // Print values
    for (int n = 0; n < vec.length; n++)
    {
        Vec3_t *ptr = (Vec3_t *)get_index(&vec, n);
        printf("Index %d is %d, %d, %d\n", n, ptr->x, ptr->y, ptr->z);
    }

    printf("Length: %d, Capacity: %d\n", vec.length, vec.capacity);

    return 0;
}
