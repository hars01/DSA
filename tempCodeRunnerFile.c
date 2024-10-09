int dequeue(struct queue *q)
{
    int a=-1;
    if(isEmpty(q))
    printf("This Queue is Empty\n");
    else {
        q->f++;
        return q ->arr[q->f];
    }
    return a;
}