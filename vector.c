#include <stdlib.h>
#include "vector.h"

Vector_t empty(int data_size)
{
    return (Vector_t){
        0,
        0,
        data_size,
        NULL};
}

Vector_t with_capacity(int data_size, int capacity)
{
    return (Vector_t){
        0,
        0,
        data_size,
        malloc(data_size * capacity)};
}

void *get_index(Vector_t vec, int index)
{
    if (index > vec.length - 1)
    {
        return NULL;
    }

    return vec.data + (vec.data_size * index);
}

void set_index(Vector_t vec, int index, void *data)
{
    if (index > vec.length - 1)
    {
        return NULL;
    }

    void *ptr = vec.data + (vec.data_size * index);

    *ptr = data;
}
