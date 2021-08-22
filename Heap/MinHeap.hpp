#include<iostream>
#include<vector>
using namespace std;

/* create a MinHeap -
    MinHeap mh;  O(1)
    MinHeap mh(vector<int>);   O(n)
    MinHeap mh=vector<int>;   O(n)
    
    mh.createheapFromVector(vector<int>); // use this only if not initialized  O(n)

  inserting elements
    mh.insert(int);  O(log(n))
    
  getting the minimum element
    int e=mh.extractMin();  O(log(n));
*/


//************************************Class MinHeap***********************************************
class MinHeap{
    private:
        void heapifyUp(int);
        void heapifyDown(int);
    public:
        vector<int> heap;
        int size;
        MinHeap(void);
        MinHeap(vector<int>);
        void insert(int);
        int extractMin(void);
        void createHeapFromVector(vector<int>);
};

//****************************************Member Functions****************************************
void MinHeap::heapifyUp(int i){
    int parentIndex=(i-1)/2;
    while(parentIndex>=0){
        if(this->heap[parentIndex]>this->heap[i]){
            swap(this->heap[parentIndex],this->heap[i]);
            i=parentIndex;
            parentIndex=(i-1)/2;
        }
        else
            break;
    }
}

void MinHeap::heapifyDown(int i){
    int leftChildIndex=2*i+1;
    int rightChildIndex=2*i+2;
    while(leftChildIndex<this->size || rightChildIndex<this->size){
        int smallest=i;
        if(this->heap[i]>this->heap[leftChildIndex])
            smallest=leftChildIndex;
        if(rightChildIndex<this->size){
            if(this->heap[i]>this->heap[rightChildIndex] && this->heap[leftChildIndex]>this->heap[rightChildIndex])
                smallest=rightChildIndex;
        }
        if(smallest==i)
            break;
        swap(this->heap[i],this->heap[smallest]);
        i=smallest;
        leftChildIndex=2*i+1;
        rightChildIndex=2*i+2;
    }   
}

MinHeap::MinHeap(void){
    this->heap={};
    this->size=0;
}

MinHeap::MinHeap(vector<int> v){
    this->heap=v;
    this->size=v.size();
    for(int i=this->size/2+1;i>=0;i--)
        this->heapifyDown(i);
}

void MinHeap::insert(int n){
    this->heap.push_back(n);
    this->size++;
    this->heapifyUp(this->size-1);
}

int MinHeap::extractMin(void){
    if(this->size==0)
        return -1;
    int minElement=this->heap[0];
    swap(this->heap[0],this->heap[this->size-1]);
    this->heap.pop_back();
    this->size--;
    this->heapifyDown(0);
    return minElement;
}

void MinHeap::createHeapFromVector(vector<int> v){
    this->heap=v;
    this->size=v.size();
    for(int i=this->size/2+1;i>=0;i--)
        this->heapifyDown(i);
}