#ifndef VFS_H 

#define VFS_H

#define VFS_NODE_NAME_NUM_OF_CHARS 256// 255 chars not including null like in linux

#include <dataStructs/linkedList.h>

enum vfs_node_type{VFS_NODE_TYPE_DIR, VFS_NODE_TYPE_DEVICE, VFS_NODE_TYPE_FILE};

typedef struct vfs_node{
    enum vfs_node_type type;
    char name[VFS_NODE_NAME_NUM_OF_CHARS];// Max name size 
    void* data;
} vfs_node;

#endif