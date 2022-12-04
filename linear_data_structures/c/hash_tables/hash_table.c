#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define TABLE_SIZE 10

struct record {
    char * 
};

unsigned int hash(char * s, int table_size) 
{
    /* Collisions are possible */
    int length = strlen(s); 
    unsigned int hash_value = 0;
    for(int i = 0; i < length; ++i) { 
        hash_value += s[i];
        /* Spread hash values out more */
        hash_value = (hash_value * s[i]) % table_size;

    }
    return hash_value;
}

int main(int argc, char * * argv)
{
    printf("John => %u\n", hash("John", TABLE_SIZE));
    printf("Jane => %u\n", hash("Jane", TABLE_SIZE));
    printf("Doe => %u\n", hash("Doe", TABLE_SIZE));
    return 0;
}
