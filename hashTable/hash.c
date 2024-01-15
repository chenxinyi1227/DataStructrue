#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

// 哈希节点
typedef struct Node 
{
    char* key;
    int value;
    struct Node* next;
} Node;

// 哈希表
typedef struct HashTable 
{
    Node* buckets[TABLE_SIZE];
} HashTable;

// 哈希函数
unsigned int hash(const char* key) 
{
    unsigned int hash_value = 0;
    while (*key != '\0') 
    {
        hash_value = hash_value * 31 + *key;
        key++;
    }
    return hash_value % TABLE_SIZE;
}

// 创建哈希表
HashTable* createHashTable() 
{
    HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));
    if (hashTable == NULL) 
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < TABLE_SIZE; i++) 
    {
        hashTable->buckets[i] = NULL;
    }

    return hashTable;
}

// 插入键值对
void insert(HashTable* hashTable, const char* key, int value) 
{
    unsigned int index = hash(key);

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) 
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    newNode->key = strdup(key);
    newNode->value = value;
    newNode->next = NULL;

    // 插入到链表头部
    newNode->next = hashTable->buckets[index];
    hashTable->buckets[index] = newNode;
}

// 查找键对应的值
int search(HashTable* hashTable, const char* key) 
{
    unsigned int index = hash(key);

    Node* current = hashTable->buckets[index];
    while (current != NULL) 
    {
        if (strcmp(current->key, key) == 0) 
        {
            return current->value;
        }
        current = current->next;
    }

    return -1;  // 未找到
}

// 销毁哈希表
void destroyHashTable(HashTable* hashTable) 
{
    for (int i = 0; i < TABLE_SIZE; i++) 
    {
        Node* current = hashTable->buckets[i];
        while (current != NULL) 
        {
            Node* temp = current;
            current = current->next;
            free(temp->key);
            free(temp);
        }
    }

    free(hashTable);
}

int main() 
{
    HashTable* hashTable = createHashTable();

    // 插入键值对
    insert(hashTable, "apple", 5);
    insert(hashTable, "banana", 8);
    insert(hashTable, "orange", 12);

    // 查找键对应的值
    printf("Value for key 'apple': %d\n", search(hashTable, "apple"));
    printf("Value for key 'banana': %d\n", search(hashTable, "banana"));
    printf("Value for key 'orange': %d\n", search(hashTable, "orange"));
    printf("Value for key 'grape': %d\n", search(hashTable, "grape"));

    // 销毁哈希表
    destroyHashTable(hashTable);

    return 0;
}
