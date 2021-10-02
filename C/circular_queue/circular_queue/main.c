//
//  main.c
//  circular_queue
//
//  Created by Harry O'Brien on 23/02/2021.
//

#include <stdio.h>
#include "Queue.h"

int main(int argc, const char * argv[]) {
	
	Queue_t *q = queue_new(6);
	
	node_t *arr = CALLOC(node_t, 4);
	for(int i = 0; i < 4; i++){
		arr[i] = i;
	}
	
	queue_push(q, &arr[0]);
	
	size_t x = *queue_pop(q);
	print_queue(q);

	queue_push(q, &arr[1]);
	queue_push(q, &arr[2]);
	queue_push(q, &arr[3]);
	
	print_queue(q);
	
	for(int i = 0; i < 3; i++){
		x = *queue_pop(q);
		printf("%zu\n", x);
	}
	
	return 0;
}
