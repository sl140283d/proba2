#include "BoundedBuffer.h"
#include <stdio.h>

BoundedBuffer::BoundedBuffer(int size){
	length = size;
	a = new int[length];
	head = tail = 0;
	cnt = 0;
}

BoundedBuffer::~BoundedBuffer(){
	delete[] a;
	length = head = tail = cnt = 0;
}

void BoundedBuffer::put(int item){
	if(cnt < length){
		a[head] = item;
		head = (head + 1)%length;
		cnt++;
		printf("put %d\n", item);
	}
	else{
		printf("Buffer is full. Element %d can't be put.\n", item);
	}
}

int BoundedBuffer::get(){
	int item = 0;
	if(cnt > 0){
		item = a[tail];
		tail = (tail+1)%length;
		cnt--;
		printf("get %d\n", item);
	}
	else{
		printf("Buffer is empty.\n");
	}
	return item;
}

void BoundedBuffer::dump(){
	for(int i=tail; i<head; i=(i+1)%length){
		printf("%d ", a[i]);
	}
	printf("\n");
}