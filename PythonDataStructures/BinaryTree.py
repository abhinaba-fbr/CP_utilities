'''
Class BinaryTree is used to create a simple Binary tree, (*Not a Binary Search tree)
Makes use of the Class Queue(), for BFS related functions

# needs no constructor argument, can simply create a tree using -> Binarytree()

Internally it uses a Linked Data Structures to maintain the tree

User has following abstract functions to create a tree -
1. CreateTreeDFS(arr) -> Takes an array as an argument, basically a array representation of a Tree
2. CreateTreeBFS(arr) -> Takes an array as an argument, an array which represents a BFS traversal of a tree

user has following abstract functions to traverse the tree -
1. DFS() -> takes no argument, and returns an array containig the inorder traversal of the tree
2. BFS() -> takes no arguments, and returns an array containing the BFS traversal of the tree
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
        

class Node:
    def __init__(self,val):
        self.val=val
        self.rchild=None
        self.lchild=None

class BinaryTree:
    def ___init__(self):
        self.root=None

    def createTreeDFS(self,arr):
        if(arr[0]==None):
            return
        newNode=Node(arr[0])
        newNode.lchild=self.__createSubTreeDFS(arr,1)
        newNode.rchild=self.__createSubTreeDFS(arr,2)
        self.root=newNode

    def __createSubTreeDFS(self,arr,i):
        if(i>=len(arr) or arr[i]==None):
            return None
        newNode=Node(arr[i])
        newNode.lchild=self.__createSubTreeDFS(arr,i*2+1)
        newNode.rchild=self.__createSubTreeDFS(arr,i*2+2)
        return newNode

    def createTreeBFS(self,arr):
        l=len(arr)
        if(l<1):
            return
        self.root=Node(arr[0])
        Q=Queue()
        Q.enqueue(self.root)
        for i in range(1,l,2):
            currentNode=Q.dequeue()
            lnode=None
            rnode=None
            if(arr[i]!='null' or arr[i]!=None):
                lnode=Node(arr[i])
                currentNode.lchild=lnode
            if(i+1<l):
                if(arr[i+1]!='null' or arr[i+1]!=None):
                    rnode=Node(arr[i+1])
                    currentNode.rchild=rnode
            if(lnode!=None):
                Q.enqueue(lnode)
            if(rnode!=None):
                Q.enqueue(rnode)

    def DFS(self):
        res=[]
        if(self.root==None):
            return
        self.__DFS(self.root.lchild,res)
        res.append(self.root.val)
        self.__DFS(self.root.rchild,res)
        return res

    def __DFS(self,node,res):
        if(node==None):
            return
        self.__DFS(node.lchild,res)
        res.append(node.val)
        self.__DFS(node.rchild,res)

    def BFS(self):
        res=[]
        Q=Queue()
        Q.enqueue(self.root)
        while(not(Q.isEmpty())):
            currentNode=Q.dequeue()
            if(currentNode==None):
                res.append('null')
            else:
                res.append(currentNode.val)
                Q.enqueue(currentNode.lchild)
                Q.enqueue(currentNode.rchild)
        l=len(res)
        while(res[l-1]=='null'):
            res.pop(l-1)
            l=l-1
        return res

if __name__=="__main__":
    T=BinaryTree()
    T.createTreeBFS([1,0,1,'null','null',1,0,'null',1])
    print(T.DFS())
    print(T.BFS())

