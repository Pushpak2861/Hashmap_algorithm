#include "common.h"


unsigned int hash(char* c , int size){
    unsigned int key = 0;
    while(*c){
        key = (key*31)+*c++;
    }
    return key % size;
}

void initMap(hashmap* map , int size){
    map->capacity = size;
    map->buckets = calloc(size , sizeof(node*));
    if(!map->buckets){
        fprintf(stderr , "error in memory allocation");
        exit(1);
    }
}


void insert(char* key , int val , hashmap* map){
    unsigned int id = hash(key , map->capacity);
    node* new_node = malloc(sizeof(node));

    if(!new_node){
        fprintf(stderr , "node memory assignment failed");
    }

    strncpy(new_node->data.key , key , sizeof(new_node->data.key)-1);
    new_node->data.key[sizeof(new_node->data.key)-1] = '\0';
    new_node->data.val = val;
    new_node->next = map->buckets[id];
    map->buckets[id] = new_node;
}

static int* lookup(hashmap* map , char* c){
    unsigned int id = hash(c ,map->capacity);
    node* cursor = map->buckets[id];

    while(cursor){
        if(strcmp(cursor->data.key , c) == 0){
            return &cursor->data.val;
        }
        cursor = cursor->next;
    }

    return NULL;
    
}

void freeMap(hashmap* map){
    for(int i =0 ; i<map->capacity;i++){
        node*cursor = map->buckets[i];
        while(cursor){
            node* temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }

    free(map->buckets);
}




int main() {
    hashmap myMap;
    initMap(&myMap, 16);

    insert("apple", 10,&myMap);
    insert("banana", 20, &myMap);

    int* val = lookup(&myMap, "banana");
    if (val) printf("banana: %d\n", *val);

    freeMap(&myMap);
    return 0;
}
