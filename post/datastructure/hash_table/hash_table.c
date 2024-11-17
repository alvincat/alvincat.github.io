#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define FREE(ptr) \
    free(ptr); \
    ptr = NULL;

typedef int KEY;
typedef int VALUE;

struct HashNode {
    KEY  key;
    VALUE value;
    struct HashNode* next;
};
typedef struct HashNode HashNode;

struct HashTable {
    int (*initHashTable)(struct HashTable* table, int bucket_num);
    void (*destroyHashTable)(struct HashTable* table);
    int (*hashFunc)(struct HashTable* table, KEY key);
    HashNode* (*findHashNode)(struct HashTable* table, KEY key);
    void (*insertHashNode)(struct HashTable* table, HashNode* node);
    HashNode** bucket;
    int bucket_num;
};
typedef struct HashTable HashTable;

int initHashTable(HashTable* table, int bucket_num)
{
   table->bucket_num = bucket_num;
   table->bucket = (HashNode**)malloc(sizeof(HashNode*) * bucket_num);
   if (table->bucket == NULL) {
       printf("Alloc memory failed.\n");
       return -1;
   }
   memset(table->bucket, 0, sizeof(HashNode*) * bucket_num);
   return 0;
}

HashNode* findLinkListNode(HashNode* head, KEY key) 
{
    if (head == NULL) {
        return NULL;
    }        

    while (head) {
        if (head->key == key) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

void destroyLinkList(HashNode* head)
{
    if (head == NULL) {
        return;
    }

    HashNode* cur = head->next;
    while (cur) {
        HashNode* prev = cur->next;
        head->next = prev;
        FREE(cur);
        cur = head->next;
    }
} 

void destroyHashTable(HashTable* table)
{
    int num = table->bucket_num; 
    HashNode** arr = table->bucket;
    for (int i = 0; i < num; ++i) {
        if (arr[i]) {
             destroyLinkList(arr[i]);
        }
    }
    FREE(arr);
    FREE(table);
}

int hashFunc(HashTable* table, KEY key)
{
   return key % table->bucket_num; 
}    

HashNode* findHashNode(HashTable* table, KEY key)
{
    int index = table->hashFunc(table, key); 
    assert(index >= 0 && index < table->bucket_num);
    return findLinkListNode(table->bucket[index], key);
}

void insertHashNode(HashTable* table, HashNode* node)
{
    if (node == NULL) {
        return;
    } 

    int index = table->hashFunc(table, node->key);
    assert(index >= 0 && index < table->bucket_num);
    HashNode* head = table->bucket[index];
    if (head) {
        HashNode* prev = head->next;
        node->next = prev;
        head->next = node;
    } else {
        table->bucket[index] = node;
    }
}

HashTable* InitializeHashTable(void)
{
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    if (table == NULL) {
        printf("Melloc memory failed.\n");
        return NULL;
    }
    memset(table, 0, sizeof(HashTable));

    table->initHashTable = initHashTable; 
    table->destroyHashTable = destroyHashTable;
    table->hashFunc = hashFunc;
    table->findHashNode = findHashNode;
    table->insertHashNode =  insertHashNode;

    return table;
}    

HashNode* initHashNode(KEY key, VALUE value)
{
    HashNode* node = (HashNode*)malloc(sizeof(HashNode));
    if (node == NULL) {
        printf("Melloc memory failed.\n");
        return NULL;
    }

    node->key = key;
    node->value = value;
    node->next = NULL;
    return node;
}

int main(void)
{
    int arr[] = {2, 7, 13, 15, 29};
    int two_sum = 9;

    HashTable* hashTb = InitializeHashTable();
    if (hashTb == NULL) {
       printf("init HashTabel failed.\n");
       goto ret;
    }

    hashTb->initHashTable(hashTb, 23);
    int len = sizeof(arr)/ sizeof(arr[0]);
    for (int i = 0; i < len; ++i) {
        HashNode* node = initHashNode(arr[i], i);
        hashTb->insertHashNode(hashTb, node);
    }

    for (int i = 0; i < len; ++i) {
        HashNode* node = hashTb->findHashNode(hashTb, abs(two_sum - arr[i]));
        if (node) {
            printf("Found it, i(%d),j(%d).\n", i, node->value);
        }
    }

    hashTb->destroyHashTable(hashTb);
ret:
    return 0;
}

