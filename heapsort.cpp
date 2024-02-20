#include <iostream>
#include <vector>
#include <cmath>


void myswap(int heap [], int i, int j, long long &counter){
    int temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
    counter+=2;

}


bool checkIsHeap(int heap [], int heapSize){
    int largest = heap[0];
    for(int i = 0; i < heapSize; i++){
        int leftChildIndex = (2 * i) + 1;
        int rightChildIndex  = (2 * i) + 2;
        bool hasChildLeft = !(leftChildIndex >= heapSize);
        bool hasChildRight = !(rightChildIndex >= heapSize);
    

   //     std::cout << "Current:" << heap[i] << " Left: " << heap[leftChildIndex] << " Right: " << heap[rightChildIndex] << std::endl;
        if(((heap[i] > largest && i !=0)) || hasChildLeft && heap[i] < heap[leftChildIndex] || hasChildRight && heap[i] < heap[rightChildIndex] ){
             std::cout << "Not a heap" << std::endl;
                return false;
        }
    }
    return true;

}
// MAX HEAP
void heapify(int heap [], int lastHeapIndex, long long &counter){
    for(int i = 0; i < lastHeapIndex; i++){
        int parentIndex = std::floor(((i - 1) / 2));
        int tempIndex = i;

        while(heap[tempIndex] > heap[parentIndex]){
            myswap(heap, tempIndex, parentIndex, counter);
            tempIndex = parentIndex;
            parentIndex = std::floor((tempIndex - 1) / 2);
        }

    }


}

void myheapsort(int heap [], int lastHeapIndex, long long &counter){
    heapify(heap,lastHeapIndex, counter);

    while(lastHeapIndex > 0){
        myswap(heap, 0, lastHeapIndex, counter);
        lastHeapIndex -= 1;
        heapify(heap,lastHeapIndex, counter);
    }

}


