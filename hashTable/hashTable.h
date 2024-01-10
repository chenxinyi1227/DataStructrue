#ifndef __HASH_TABLE_H_
#define __HASH_TABLE_H_

#define SLOT_CAPACITY   10

#if 0
typedef struct valueNode
{

};
#endif

typedef struct hashNode
{
    int real_key;
    int value;
    struct hashNode *next;
}hashNode;

typedef struct hashTable
{
#if 0
    int *slotId;  /* 动态数组 作为哈希表的key */
    int * value;   /* 作为哈希表的value. */
#else
    hashNode *slotKeyId;
#endif
} HashTable;


HashTable* hashTableInit();

int hashTableInsert(HashTable *hashtable, int key, int value);

int getAppointKeyValue(HashTable *pHashtable, int key);

/* 销毁哈希表 */

#endif //__HASH_TABLE_H_