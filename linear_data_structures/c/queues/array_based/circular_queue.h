/* Circular queue / ring buffer implementation */

#ifndef ARRAY_BASED_QUEUE_H
#define ARRAY_BASED_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>     /* INT_MIN */
#include <stdbool.h>    

#define QUEUE_EMPTY INT_MIN

typedef struct {
    int * values;
    int head, tail, num_entries, size;
} queue;

/* init_queue: If size less than 1, defaults to 1 */
void init_queue(queue *q, int size) 
{
    if(size < 1) {
        size = 1;
    }
    q->size = size;
    q->values = malloc(sizeof(int) * q->size);
    q->head = -1;
    q->tail = -1;
    q->num_entries = 0; //empty queue
}

bool queue_full(queue *q) 
{
    return q->num_entries == q->size;
}

bool queue_empty(queue *q)
{
    return q->num_entries == 0;
}

int queue_size(queue *q)
{
    return q->size;
}

void dalloc_queue(queue *q) 
{
    free(q->values);
}

/* enqueue: Checks if there is capacity in the queue. If so, adds the value to the back of the queue and returns true. Else returns false */
bool enqueue(queue *q, int value)
{
    /* Tail cannot overlap head */
    if(!queue_full(q)) {
        q->values[(++q->tail % q->size)] = value;
        ++q->num_entries;
        return true;
    }
    return false;
}

/* dequeue: If the number of entries > 0, returns the value at the front of the queue and increments the head. Else, returns EMPTY_QUEUE (INT_MIN) */
int dequeue(queue *q)
{
    /* Head cannot overlapping tail */
    if(!queue_empty(q)) {
        --q->num_entries;
        return q->values[(++q->head % q->size)];
    }
    return QUEUE_EMPTY;
}

#endif //ARRAY_BASED_QUEUE_H
