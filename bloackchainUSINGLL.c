#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the block structure
typedef struct Block {
    int index;
    time_t timestamp;
    char data[256];
    char prevHash[64];
    char hash[64];
    struct Block *next;
} Block;

// Function to create a new block
Block* create_block(int index, const char *data, const char *prevHash){
    Block *new_block = (Block *)malloc(sizeof(Block));
    new_block->index = index;
    new_block->timestamp = time(NULL);
    strncpy(new_block->data, data, sizeof(new_block->data));
    strncpy(new_block->prevHash, prevHash, sizeof(new_block->prevHash));
    // Simple hash function (for demonstration purposes)
    snprintf(new_block->hash, sizeof(new_block->hash), "%d%s%s", index, data, prevHash);
    new_block->next = NULL;
    return new_block;
}

// Function to add a block to the blockchain
Block* add_block(Block *head, const char *data) {
    Block *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    Block *new_block = create_block(current->index + 1, data, current->hash);
    current->next = new_block;
    return new_block;
}

// Function to print the blockchain
void print_blockchain(Block *head) {
    Block *current = head;
    while (current != NULL) {
        printf("Block %d:\n", current->index);
        printf("Timestamp: %ld\n", current->timestamp);
        printf("Data: %s\n", current->data);
        printf("Previous Hash: %s\n", current->prevHash);
        printf("Hash: %s\n\n", current->hash);
        current = current->next;
    }
}

int main() {
    // Create the genesis block
    Block *blockchain = create_block(0, "Genesis Block", "0");

    // Add new blocks to the blockchain
    add_block(blockchain, "Block 1 Data");
    add_block(blockchain, "Block 2 Data");

    // Print the blockchain
    print_blockchain(blockchain);

    return 0;
}
