#include <ctype.h>

typedef struct __attribute__((packed)) mbr_partition_entry{
    uint8_t boot_indicator;
    uint8_t starting_head;
    uint8_t starting_sector : 6;
    uint16_t starting_cylinder : 10;
    uint8_t system_id;
    uint8_t ending_head;
    uint8_t ending_sector : 6;
    uint16_t ending_cylinder : 10;
    uint32_t relative_sector;
    uint32_t partition_size_in_sectors;
} mbr_partition_entry;