#ifndef HARDWARE_MEM_H

#define HARDWARE_MEM_H
#include <dataStructs/linkedList.h>
// Contains code to manage hardware devices memory

extern uint64_t hardware_alloc_size;


void *hardware_allocate_mem(size_t size, size_t alignment);

// Create a new node
static inline linkedListNode *create_node_hardware(void *data) {
    linkedListNode *new_node = (linkedListNode *)hardware_allocate_mem(sizeof(linkedListNode), 0);
    if (new_node) {
        new_node->data = data;
        new_node->next = NULL;
    }
    return new_node;
}

// Add a node to the end of the list
static inline void append_node_hardware(linkedListNode **head, void *data) {
    linkedListNode *new_node = create_node_hardware(data);
    if (!new_node) {
        printf("Failed to create node");
        return;
    }
    if (*head == NULL) {
        new_node->next = NULL;
        (*head) = new_node;
        return;
    }
    new_node->next = (*head);
    (*head) = new_node;
}


#endif