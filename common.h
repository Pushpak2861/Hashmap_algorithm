#ifndef hash_common_h
#define hash_common_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node node;

typedef struct {
    char key[100];
    int val;
}product;

struct node{
    product data;
    node* next;
};

typedef struct{
    node** buckets;
    int capacity;
}hashmap;

unsigned int hash(char* c , int size);
void initMap(hashmap* map , int size);
void insert(char* key , int val , hashmap* map);
void freeMap(hashmap* map);

#endif