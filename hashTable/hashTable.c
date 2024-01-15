#include "hashTable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

HashTable* hashTableInit()
{
    int ret = 0;
    HashTable *pHashtable = (HashTable *)malloc(sizeof(HashTable) * 1);
    if (!pHashtable)
    {
        return NULL;
    }
    memset(pHashtable, 0, sizeof(HashTable) * 1);

    pHashtable->slotKeyId = malloc(sizeof(hashNode) * SLOT_CAPACITY);
    if (!(pHashtable->slotKeyId))
    {
        return NULL;
    }
    memset(pHashtable->slotKeyId, 0, sizeof(hashNode) * SLOT_CAPACITY);
    
    return pHashtable;
}

/* 使用循环的方式获取slotId. */
static int calHashValue(int key)
{
    int slotId = key % SLOT_CAPACITY;
}

int hashTableInsert(HashTable *pHashtable, int key, int value) // 11 79   13 56
{

    if (!pHashtable)
    {
        return -1;
    }

    int slotId = calHashValue(key); // 1 79   3 56
#if 0
    pHashtable->slotId->key = key;
    pHashtable->slotId->value = value;
#else
    // pHashtable->slotKeyId[slotId].real_key = key; // 11  13
    // pHashtable->slotKeyId[slotId].value = value;  // 79  56
#endif

    /* 将传进来的实际key和value封装成一个节点，并将其插入到链表中.  */
    hashNode *newNode = (hashNode *)malloc(sizeof(hashNode));
    if (!newNode)
    {
        return -1;
    }

    newNode->real_key = key;
    newNode->value = value;
    newNode->next = NULL;


    if (pHashtable->slotKeyId[slotId].next == NULL)
    {
        pHashtable->slotKeyId[slotId].next = newNode;
        newNode->next = NULL;
    }
    else
    {
        hashNode *curNode = pHashtable->slotKeyId[slotId].next;
        while (curNode->next != NULL)
        {
            curNode = curNode->next;
        }
        curNode->next = newNode;
    }
       
    return 0;
}

int getAppointKeyValue(HashTable *pHashtable, int key)
{
    return pHashtable->slotKeyId[calHashValue(key)].value;
}