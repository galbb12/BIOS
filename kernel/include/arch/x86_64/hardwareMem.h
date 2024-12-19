#ifndef HARDWARE_MEM_H

#define HARDWARE_MEM_H

#include <arch/x86_64/mlayout.h>
#include <memory.h>
#include <stdio.h>
#include <linkedList.h>

// Contains code to manage hardware devices memory

extern uint64_t hardware_alloc_size;


void *hardware_allocate_mem(size_t size, size_t alignment);


// Create a new node
static inline linkedListNode *create_node_mem(void *data) {
    linkedListNode *new_node_mem = (linkedListNode *)hardware_allocate_mem(sizeof(linkedListNode), 0);
    if (new_node_mem) {
        new_node_mem->data = data;
        new_node_mem->next = NULL;
    }
    return new_node_mem;
}

// Add a node to the end of the list
static inline void append_node_mem(linkedListNode **head, void *data) {
    linkedListNode *new_node_mem = create_node_mem(data);
    if (!new_node_mem) {
        printf("Failed to create node");
        return;
    }
    if (*head == NULL) {
        new_node_mem->next = NULL;
        (*head) = new_node_mem;
        return;
    }
    new_node_mem->next = (*head);
    (*head) = new_node_mem;
}

// // Remove a node from the list
// static inline void remove_node_mem(linkedListNode **head, void *data,
//                                int (*cmp)(void *, void *)) {
//     linkedListNode *current = *head;
//     linkedListNode *previous = NULL;
//     while (current != NULL) {
//         if (cmp(current->data, data) == 0) {
//             if (previous == NULL) {
//                 *head = current->next;
//             } else {
//                 previous->next = current->next;
//             }
//             free(current);
//             return;
//         }
//         previous = current;
//         current = current->next;
//     }
// }

#endif