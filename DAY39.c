#include <stdio.h>
#include <string.h>

#define MAX 1000

int heap[MAX];
int size = 0;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int i){
    while(i > 0 && heap[(i-1)/2] > heap[i]){
        swap(&heap[(i-1)/2], &heap[i]);
        i = (i-1)/2;
    }
}

void heapifyDown(int i){
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < size && heap[left] < heap[smallest])
        smallest = left;

    if(right < size && heap[right] < heap[smallest])
        smallest = right;

    if(smallest != i){
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

void insert(int x){
    heap[size] = x;
    heapifyUp(size);
    size++;
}

int peek(){
    if(size == 0)
        return -1;
    return heap[0];
}

int extractMin(){
    if(size == 0)
        return -1;

    int min = heap[0];
    heap[0] = heap[size-1];
    size--;

    heapifyDown(0);

    return min;
}

int main(){
    int n;
    scanf("%d",&n);

    char operation[20];
    int value;

    for(int i=0;i<n;i++){
        scanf("%s",operation);

        if(strcmp(operation,"insert")==0){
            scanf("%d",&value);
            insert(value);
        }
        else if(strcmp(operation,"peek")==0){
            printf("%d\n",peek());
        }
        else if(strcmp(operation,"extractMin")==0){
            printf("%d\n",extractMin());
        }
    }

    return 0;
}
