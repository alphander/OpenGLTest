#pragma once

typedef struct List List;

List* _List();
void* list_get(List* list, int index);
void list_set(List* list, int index, void* object);
void list_append(List* list, void* object);
void list_remove(List* list, int index);
int list_contains(List* list, void* object);

int list_getCapacity(List* list);
int list_getSize(List* list);