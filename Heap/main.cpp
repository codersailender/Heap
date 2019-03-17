//
//  main.cpp
//  HeapPractice
//
//  Created by Sailender Singh on 17/03/19.
//  Copyright © 2019 Sailender Singh. All rights reserved.
//

#include <iostream>
#define MAX_SIZE 1000

using namespace std;

int heap[MAX_SIZE] = { 0 };
int heapCounter = 0;

bool compare(int a, int b) {
    return a>b;
}

void swapData(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void upHeapify()
{
    if (heapCounter>1) {
        int currentIndex = heapCounter-1;
        int parent = (currentIndex-1)/2;
        while (compare(heap[parent], heap[currentIndex])) {
            swapData(&heap[currentIndex], &heap[parent]);
            currentIndex = parent;
            parent = (currentIndex-1)/2;
        }
    }
}

void downHeapify()
{
    if (heapCounter>1) {
        int parent = 0;
        int left = 2*parent + 1;
        int right = 2*parent + 2;
        while (left<heapCounter) {
            int idx = left;
            if (right<heapCounter && compare(heap[left], heap[right])) {
                idx = right;
            }
            if (compare(heap[parent], heap[idx])) {
                swapData(&heap[parent], &heap[idx]);
                parent = idx;
                left = 2*parent + 1;
                right = 2*parent + 2;
            } else {
                break;
            }
        }
    }
}

void addElement(int ele) {
    heap[heapCounter++] = ele;
    upHeapify();
}

void deleteElement() {
    heap[0] = heap[--heapCounter];
    downHeapify();
}

void printElements()
{
    for(int i=0; i<heapCounter; i++) {
        cout << heap[i] <<" ";
    }
    cout<<endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    cout << "Enter no of elemnts" << endl;
    cin >> n;
    while (n > MAX_SIZE || n==0) {
        cout << "Please enter a no fo elemnts <0 && >= "<<MAX_SIZE<<endl;
    }
    for (int i=0; i<n; i++) {
        int ele;
        cin >> ele;
        addElement(ele);
    }
    
    printElements();
    deleteElement();
    printElements();
    deleteElement();
    printElements();
    
    return 0;
}

