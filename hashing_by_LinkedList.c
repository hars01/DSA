#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct HashTable {
    int size;
    struct Node** table;
};


struct Node* newNode(int data) {
    struct Node* new_Node = (struct Node*)malloc(sizeof(struct Node));
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

struct HashTable* createHashTable(int size) {
    struct HashTable* hashTable = (struct HashTable*)malloc(sizeof(struct HashTable));
    hashTable->size = size;
    hashTable->table = (struct Node*)malloc(size * sizeof(struct Node));
    int i;
    for (i = 0; i < size; i++) {
        hashTable->table[i] = NULL;
    }
    return hashTable;
}

int hashFunction(int key, int size) {
    return key % size;
}


void insert(struct HashTable* hashTable, int data) {
    int index = hashFunction(data, hashTable->size);
    struct Node* new_Node = newNode(data);
    if (hashTable->table[index] == NULL) {
        hashTable->table[index] = new_Node;
    } else {
        struct Node* temp = hashTable->table[index];
        while (temp->next != NULL) {
            
            temp = temp->next;
        }
        temp->next = new_Node;
    }
}


int search(struct HashTable* hashTable, int data) {
    int i=0;
    int index = hashFunction(data, hashTable->size);
    struct Node* temp = hashTable->table[index];
    while (temp != NULL) {
        i++;
        if (temp->data == data) {
            return i;
        }
        temp = temp->next;
    }
    return -1; 
}

// Function to display the hash table
void display(struct HashTable* hashTable) {
    int i;
    for (i = 0; i < hashTable->size; i++) {
        printf("Index %d: ", i);
        struct Node* temp = hashTable->table[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int size, i;
    
    printf("Enter the size of the hash table: ");
    scanf("%d", &size);
    
    struct HashTable* hashTable = createHashTable(size);

    
    printf("Enter the elements to insert:\n");
    for (i = 0; i < size; i++) {
        int data;
        scanf("%d", &data);
        insert(hashTable, data);
    }

    printf("Hash Table:\n");
    display(hashTable);

    int searchValue;
    printf("Enter a value to search: ");
    scanf("%d", &searchValue);
 int index = search(hashTable, searchValue);
    if (index>0) {
        printf("%d is found in the hash table. at the index %d \n", searchValue,index);
    } else {
        printf("%d is not found in the hash table.\n", searchValue);
    }

    return 0;
}