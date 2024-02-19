#include <iostream>
#include <vector>
#include <cmath>


void myswap(int heap [], int i, int j){
    int temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;

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
void heapify(int heap [], int lastHeapIndex){
    for(int i = 0; i <= lastHeapIndex; i++){
        int parentIndex = std::floor(((i - 1) / 2));
        int tempIndex = i;

        while(heap[tempIndex] > heap[parentIndex]){
            myswap(heap, tempIndex, parentIndex);
            tempIndex = parentIndex;
            parentIndex = std::floor((tempIndex - 1) / 2);
        }

    }

}

void myheapsort(int heap [], int lastHeapIndex){
    heapify(heap,lastHeapIndex);
    for(int i = 0; i < 8; i++){
        std::cout << heap[i] << " ";
    }
    while(lastHeapIndex > 0){
        myswap(heap, 0, lastHeapIndex);
        lastHeapIndex -= 1;
        std::cout << "Last Heap Index: " << lastHeapIndex << std::endl;
        heapify(heap,lastHeapIndex);
        for(int i = 0; i < 8; i++){
            std::cout << heap[i] << " ";
        }
        std::cout << std::endl;
    }


}

int main (int argc, char *argv[]) {
    // left child = 2i + 1
    // right child = 2i + 2
    // parent = floor((i - 1) / 2)  )
    // In the case of a max heap, the largest element is at the root, and for a min-heap, the smallest element is at the root.
    //  In order for heapsort to work, we must START with a heap.
    // swap, chop, and heapify
    int intHeap [8] {75,80,60,68,55,40,52,67};

    myheapsort(intHeap, 7);
    std::cout << std::endl;

}
