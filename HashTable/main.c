#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#define HASH_KEYTYPE void *
#define HASH_VALUETYPE void *

typedef struct hashNode
{
    HASH_KEYTYPE real_key;
    HASH_VALUETYPE value;
}hashNode;

typedef struct hashTable
{
    /* 哈希表的槽位数 */
    int slotNums;

    /*  */
};

#endif