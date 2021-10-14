import sys
import copy
import random


class MinHeap:
    def __init__(self):
        self.size=0
        self.heap=[]
    
    def insert(self,val):
        self.heap.append(val)
        self.size+=1
        pointer=self.size-1
        parent=(pointer-1)//2
        while(parent>=0 and self.heap[parent]>self.heap[pointer]):
            self.heap[pointer],self.heap[parent]=self.heap[parent],self.heap[pointer]
            pointer=parent
            parent=(pointer-1)//2
        
    def popmin(self):
        popedval=self.heap[0]
        self.heap[self.size-1],self.heap[0]=self.heap[0],self.heap[self.size-1]
        self.heap.pop(self.size-1)
        self.size-=1
        pointer=0
        lchild=pointer*2+1
        rchild=pointer*2+2
        while(lchild<self.size and rchild<self.size):
            if(self.heap[lchild]>=self.heap[pointer] and self.heap[rchild]>=self.heap[pointer]):
                break
            if(self.heap[lchild]<self.heap[pointer]):
                if(self.heap[rchild]<self.heap[pointer] and self.heap[lchild]<self.heap[rchild]):
                    self.heap[pointer],self.heap[lchild]=self.heap[lchild],self.heap[pointer]
                    pointer=lchild
                elif(self.heap[rchild]<self.heap[pointer] and self.heap[rchild]<self.heap[lchild]):
                    self.heap[pointer],self.heap[rchild]=self.heap[rchild],self.heap[pointer]
                    pointer=rchild
                else:
                    self.heap[pointer],self.heap[lchild]=self.heap[lchild],self.heap[pointer]
                    pointer=lchild
            elif(self.heap[rchild]<self.heap[pointer]):
                self.heap[pointer],self.heap[rchild]=self.heap[rchild],self.heap[pointer]
                pointer=rchild
            else:
                break
            lchild=pointer*2+1
            rchild=pointer*2+2
        return popedval
    



if __name__=="__main__":
    minheap=MinHeap()
    minheap.insert(5)
    minheap.insert(2)
    minheap.insert(10)
    minheap.insert(20)
    minheap.insert(1)
    print(minheap.heap)
    print(minheap.popmin())
    print(minheap.popmin())
    print(minheap.heap)
    print(minheap.popmin())
    print(minheap.popmin())
    print(minheap.popmin())
    print(minheap.heap)
