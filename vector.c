#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

const int PTR_SIZE = sizeof(void*);

Vector_t empty()
{
    return (Vector_t){
        0,
        0,
        NULL};
}

Vector_t with_capacity(unsigned int capacity)
{
    return (Vector_t){
        0,
        capacity,
        malloc(PTR_SIZE * capacity)};
}

void *get_index(Vector_t *vec, unsigned int index)
{
    if (index > vec->length - 1)
    {
        return NULL;
    }

    return *(void**)(vec->data + (PTR_SIZE * index));
}

void *set_index(Vector_t *vec, unsigned int index, void *data)
{
    if (index > vec->length - 1)
    {
        return NULL;
    }

    void **ptr = (void**)(vec->data + (PTR_SIZE * index));

    *ptr = data;

    return *ptr;
}

unsigned int append(Vector_t *vec, void *data)
{
    if (vec->length == vec->capacity) {
        // Double capacity
        extend(vec, vec->capacity);
    }

    void **ptr = (void**)(vec->data + (PTR_SIZE * vec->length));

    *ptr = data;
    vec->length++;

    return vec->length - 1;
}

void *take(Vector_t *vec, unsigned int index)
{
    if (index > vec->length - 1)
    {
        return NULL;
    }

    void *removed_ptr = *(void**)(vec->data + (PTR_SIZE * index));

    for (int n = index + 1; n < vec->length; n++) {
        void **old_ptr = (void**)(vec->data + (PTR_SIZE * n));
        void **new_ptr = (void**)(old_ptr - 1);
        *new_ptr = *old_ptr;
    }

    vec->length--;

    return removed_ptr;
}

unsigned int extend(Vector_t *vec, unsigned int capacity)
{
    unsigned int new_capacity = vec->capacity + capacity;
    void *new_data = malloc(PTR_SIZE * new_capacity);

    for (int n = 0; n < vec->length; n++) {
        void **old_ptr = (void**)(vec->data + (PTR_SIZE * n));
        void **new_ptr = (void**)(new_data + (PTR_SIZE * n));
        *new_ptr = *old_ptr;
    }

    free(vec->data);
    vec->data = new_data;
    vec->capacity = new_capacity;

    return new_capacity;
}
