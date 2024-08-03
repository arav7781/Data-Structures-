#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/sha.h>

// Define the block structure
typedef struct Block {
    int index;
    time_t timestamp;
    char data[256];
    char prevHash[SHA256_DIGEST_LENGTH*2 + 1];
    char hash[SHA256_DIGEST_LENGTH*2 + 1];
    struct Block *next;
} Block;

// Function to convert bytes to hex string
void bytes_to_hex_string(unsigned char *bytes, char *hex_string, int length) {
    for (int i = 0; i < length; i++) {
        sprintf(hex_string + (i * 2), "%02x", bytes[i]);
    }
    hex_string[length * 2] = '\0';
}

// Function to calculate SHA-256 hash
void calculate_sha256(char *string, char outputBuffer[SHA256_DIGEST_LENGTH*2 + 1]) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, string, strlen(string));
    SHA256_Final(hash, &sha256);
    bytes_to_hex_string(hash, outputBuffer, SHA256_DIGEST_LENGTH);
}

// Function to create a new block
Block* create_block(int index, const char *data, const char *prevHash) {
    Block *new_block = (Block *)malloc(sizeof(Block));
    new_block->index = index;
    new_block->timestamp = time(NULL);
    strncpy(new_block->data, data, sizeof(new_block->data));
    strncpy(new_block->prevHash, prevHash, sizeof(new_block->prevHash));
    
    char toHash[512];
    snprintf(toHash, sizeof(toHash), "%d%ld%s%s", index, new_block->timestamp, data, prevHash);
    calculate_sha256(toHash, new_block->hash);
    
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

// Exported functions for WebAssembly
Block* create_genesis_block() {
    return create_block(0, "Genesis Block", "0");
}

Block* add_block_to_chain(Block *head, const char *data) {
    return add_block(head, data);
}
