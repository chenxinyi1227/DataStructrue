#include "hashTable.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h> 

#define VLAUE_NUM   10
#define RANDOM_NUM  666

int main(int argc, char const *argv[])
{
    // srand(time(NULL));

    HashTable *hashtable = hashTableInit();
    if (hashtable == NULL)
    {
        return -1;
    }
    
    // for (int idx = 0; idx < VLAUE_NUM; idx++)
    // {
    //     // int value = rand() % 1000;
    //     hashTableInsert(&hashtable, idx, RANDOM_NUM);
    // }
    hashTableInsert(hashtable, 1, 68);
    hashTableInsert(hashtable, 11, 79);
    int value = getAppointKeyValue(hashtable, 1);
    printf ("value:%d\n", value);
    return 0;
}
