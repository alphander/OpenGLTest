#include<stdlib.h>

typedef struct List
{
    int capacity;
    int size;
    void** data;
} List;

List* _List()
{
    List* list = malloc(sizeof(List));
    list->capacity = 1;
    list->size = 0;
    list->data = calloc(1, sizeof(void*));
    return list;
}

void List_(List* list)
{
    free(list->data);
    free(list);
}

void list_append(List* list, void* object)
{
    if(list->size >= list->capacity)
    {
        list->capacity <<= 1;
        list->data = realloc(list->data, sizeof(void*) * list->capacity);
    }

    list->data[list->size] = object;
    list->size++;
}

void* list_get(List* list, int index)
{
    if(index >= list->size) return NULL;

    return list->data[index];
}

void list_set(List* list, int index, void* object)
{
    if(index > list->size) return;

    list->data[index] = object;
}

void list_remove(List* list, int index)
{
    if(index >= list->size) return;

    list->size--;
    for(int i = index; i < list->size - index; i++)
        list->data[i] = list->data[i+1];

    if(list->size <= list->capacity >> 1)
    {
        list->capacity >>= 1;
        list->data = realloc(list->data, sizeof(void*) * list->capacity);
    }
}

int list_contains(List* list, void* object)
{
    for(int i = 0; i < list->size; i++)
        if(list->data[i] == object) return 1;
    return 0;
}

int list_getCapacity(List* list)
{
    return list->capacity;
}

int list_getSize(List* list)
{
    return list->size;
}