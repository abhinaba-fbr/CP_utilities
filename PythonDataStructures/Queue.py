'''
Contains Class Queue which can be used to form a queue of any object or datatype(without modification in code)
Uses a link list to form a Queue

# needs no Constructor argument, to make a queue simply use -> Queue()
 
User has the following abstract function to work with the Queue -
1. enqueue(val) -> takes an argument the value or object to be enqued
2. dequeue() -> returns the dequed element
3. isEnpty() -> returns true if Queue is empty else returns False
'''


class QNode():
    def __init__(self,val):
        self.val=val
        self.next=None

class Queue:
    def __init__(self):
        self.front=None
        self.rear=None

    def enqueue(self,val):
        newNode=QNode(val)
        if(self.front==None and self.rear==None):
            self.front=newNode
            self.rear=newNode
        else:
            self.rear.next=newNode
            self.rear=newNode

    def dequeue(self):
        if(self.front==None):
            print("Queue empty!!")
            return
        returnNode=self.front
        self.front=self.front.next
        if(self.front==None):
            self.rear=None
        return returnNode.val

    def isEmpty(self):
        if(self.front==self.rear==None):
            return True
        else:
            return False

if __name__=="__main__":
    Q=Queue()
    Q.enqueue(5)
    Q.enqueue(3)
    Q.enqueue(6)
    print(Q.dequeue())
    print(Q.dequeue())
    print(Q.dequeue())
    print(Q.dequeue())
    Q.enqueue(1)
    print(Q.dequeue())

