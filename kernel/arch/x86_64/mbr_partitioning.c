#include <mbr_partitioning.h>

mbr_partition_entry* get_mbr_partitions(void* mbr_sector){
    return (mbr_partition_entry*) ((uint8_t*)mbr_sector) + 0x01BE;
}