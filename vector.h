#ifndef VECTOR_H
#define VECTOR_H

typedef struct Vector
{
    unsigned int length;
    unsigned int capacity;
    void *data;
} Vector_t;

/// @return An empty Vector
Vector_t empty();

/// @brief Create an empty vector and allocate some memory
/// @param capacity The amount of values to allocate for
/// @return The new vector
Vector_t with_capacity(unsigned int capacity);

/// @brief Get the item at the choosen index of a vector
/// @param vec The vector to index in to
/// @param index The index of the value you want to get
/// @return The item at the choosen index or NULL
void *get_index(Vector_t *vec, unsigned int index);

/// @brief Set the value at the choosen index of a vector
/// @param vec The vector to set the value on
/// @param index The index to place the value in
/// @param data The value to set in the index
/// @return The previous value at the index or NULL if index out of range
void *set_index(Vector_t *vec, unsigned int index, void *data);

/// @brief Add a value to the end of the vector and allocate more memory if needed
/// @param vec The vector to add the value to
/// @param data The value to append to the end
/// @return The index of the new value
unsigned int append(Vector_t *vec, void *data);

/// @brief Take the value at the choosen index and remove it from the vector
/// @param vec The vector to take from
/// @param index The index of the value to take
/// @return The taken value
void *take(Vector_t *vec, unsigned int index);

/// @brief Increase the capacity of the vector
/// @param vec The vector to increase the capacity of
/// @param capacity The amount to increase the capacity by
/// @return The new capacity of the vector
unsigned int extend(Vector_t *vec, unsigned int capacity);

#endif
