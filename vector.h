#ifndef VECTOR_H
#define VECTOR_H

typedef struct Vector
{
    int length;
    int capacity;
    int data_size;
    void *data;
} Vector_t;

Vector_t empty(int data_size);
Vector_t with_capacity(int data_size, int capacity);
void *get_index(Vector_t vec, int index);
void set_index(Vector_t vec, int index, void *data);

#endif
