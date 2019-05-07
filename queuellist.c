#include <stdio.h>
#include <stdlib.h>

typedef struct _queue
{
    int val;
    struct _queue* prev;
    struct _queue* next;
}
queue;

typedef struct _dlqueue
{
    queue* head_node;
    queue* tail_node;
}
dlqueue;

dlqueue* new_queue;
int size = -1;


queue* create(queue* tail, int n);
queue* create2(queue* tail, int n);
queue* enqueue(queue* q, int n);
int dequeue(dlqueue* head);


int main(void)
{
    
    new_queue->head_node = new_queue->tail_node;
    new_queue->head_node = create(new_queue->tail_node, 4);
    new_queue->tail_node = create2(new_queue->head_node, 19);
    new_queue->tail_node = enqueue(new_queue->tail_node, 23);
    new_queue->tail_node = enqueue(new_queue->tail_node, 72);
    new_queue->tail_node = enqueue(new_queue->tail_node, 24);
    new_queue->tail_node = enqueue(new_queue->tail_node, 30);
    printf("\tthis is the current size of our queue after enqueuing: %i\n", size);

    int x,  y;

    x = dequeue(new_queue);
    y = dequeue(new_queue->head_node);

    printf("\tthe values of x and y are: %i and %i\n", x, y);
    printf("\tthis is the current size of our queue after dequeuing: %i", size);
}


queue* create(queue* tail, int n)
{
    queue* head = malloc(sizeof(queue));
    if (head != NULL)
    {
        head->val = n;
        head->next = tail;
        head->prev = NULL;
        size++;
        return head;
    }
}

queue* create2(queue* tail, int n)
{
    queue* head = malloc(sizeof(queue));
    if (head != NULL)
    {
        head->val = n;
        head->next = NULL;
        head->prev = tail;
        return head;
    }
}


queue* enqueue(queue* q, int n)
{
    queue* new = malloc(sizeof(queue));
    if ( new != NULL)
    {
        new->val = n;
        new->next = NULL;
        new->prev = q;
        q->next = new;
        size++;
        return new;
   }
}

int dequeue(dlqueue* head)
{
    int x = head->head_node->val;
    dlqueue* p = head->head_node;
    head->head_node = head->head_node->next;
    free(p);
    size--; 
    return x;
}