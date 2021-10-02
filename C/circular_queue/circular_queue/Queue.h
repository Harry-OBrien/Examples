#include <stdlib.h>

typedef size_t node_t;
typedef struct _Queue_t Queue_t;

void *calloc_fail(size_t elsize, size_t num);

#define CALLOC(ty, num) ((ty *)calloc_fail(sizeof(ty), num))

/**
 * Allocate a new queue
 */
Queue_t *queue_new(size_t);

/**
 * Initialise the queue
 */
void queue_init(Queue_t *queue, size_t N);

/**
 * Push node to the queue
 */
int queue_push(Queue_t *, node_t *);

/**
 * Pop node from front of queue
 */
node_t *queue_pop(Queue_t *);

/**
 * Get length of queue
 */
size_t queue_length(Queue_t *queue);


void print_queue(Queue_t* queue);
