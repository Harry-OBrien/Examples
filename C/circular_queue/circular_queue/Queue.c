#include "Queue.h"
#include "general.h"

/**
 * Circular buffer
 */
struct _Queue_t
{
    size_t size;
    size_t head, tail;
    size_t length;
    node_t **data;
};

/**
 * Initialise the queue
 */
Queue_t *queue_new(size_t N)
{
    Queue_t *queue = CALLOC(Queue_t, 1);
    queue_init(queue, N);

    return queue;
}

void queue_init(Queue_t *queue, size_t N)
{
    queue->data = malloc(sizeof(node_t *) * N);
    queue->head = 0;
    queue->tail = 0;
    queue->size = N;
    queue->length = 0;
}

/**
 * Push node to the queue
 */
int queue_push(Queue_t *queue, node_t *node)
{
    if (((queue->head + 1) % queue->size) == queue->tail)
    {
        return -1;
    }
    queue->data[queue->head] = node;
    queue->head = (queue->head + 1) % queue->size;
    queue->length++;
    return 0;
}

/**
 * Pop node from front of queue
 */
node_t *queue_pop(Queue_t *queue)
{
    if (queue->tail == queue->head)
    {
        return NULL;
    }
    node_t *node = queue->data[queue->tail];
    queue->data[queue->tail] = NULL;
    queue->tail = (queue->tail + 1) % queue->size;
    queue->length--;
    return node;
}

size_t queue_length(Queue_t *queue)
{
    return queue->length;
}

void print_queue(Queue_t* queue) {
	if (queue->length == 0) {
		printf("Queue empty\n");
	}
	
	for (int i = 0; i < queue->length; i++){
		printf("%d: %zu\n", i, *queue->data[(queue->tail + i) % queue->size]);
	}
}
