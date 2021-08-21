'''
Has Average ratio problem 
and Genaerate Parenthesis currenlty
'''


# class MaxHeap:
#     def __init__(self):
#         self.size=0
#         self.heap=[]
    
#     def insert(self,val):
#         self.heap.append(val)
#         self.size+=1
#         pointer=self.size-1
#         parent=(pointer-1)//2
#         while(parent>=0 and self.heap[parent][1]<self.heap[pointer][1]):
#             self.heap[pointer],self.heap[parent]=self.heap[parent],self.heap[pointer]
#             pointer=parent
#             parent=(pointer-1)//2
        
#     def popmax(self):
#         popedval=self.heap[0]
#         self.heap[self.size-1],self.heap[0]=self.heap[0],self.heap[self.size-1]
#         self.heap.pop(self.size-1)
#         self.size-=1
#         pointer=0
#         lchild=pointer*2+1
#         rchild=pointer*2+2
#         while(lchild<self.size and rchild<self.size):
#             if(self.heap[lchild][1]<=self.heap[pointer][1] and self.heap[rchild][1]<=self.heap[pointer][1]):
#                 break
#             if(self.heap[lchild][1]>self.heap[pointer][1]):
#                 if(self.heap[rchild]>self.heap[pointer] and self.heap[lchild]>self.heap[rchild]):
#                     self.heap[pointer],self.heap[lchild]=self.heap[lchild],self.heap[pointer]
#                     pointer=lchild
#                 elif(self.heap[rchild][1]>self.heap[pointer][1] and self.heap[rchild][1]>self.heap[lchild][1]):
#                     self.heap[pointer],self.heap[rchild]=self.heap[rchild],self.heap[pointer]
#                     pointer=rchild
#                 else:
#                     self.heap[pointer],self.heap[lchild]=self.heap[lchild],self.heap[pointer]
#                     pointer=lchild
#             elif(self.heap[rchild][1]>self.heap[pointer][1]):
#                 self.heap[pointer],self.heap[rchild]=self.heap[rchild],self.heap[pointer]
#                 pointer=rchild
#             else:
#                 break
#             lchild=pointer*2+1
#             rchild=pointer*2+2
#         return popedval


# class Solution:
#     def maxAverageRatio(self,classes,extraStudents):
#         l=len(classes)
#         maxheap=MaxHeap()
#         for i in range(0,l):
#             p=classes[i][0]
#             t=classes[i][1]
#             increase=(t-p)/((t+1)*t)
#             maxheap.insert((i,increase))
#         while(extraStudents):
#             popedclass=maxheap.popmax()
#             i=popedclass[0]
#             classes[i][0]+=1
#             classes[i][1]+=1
#             p=classes[i][0]
#             t=classes[i][1]
#             increase=(t-p)/((t+1)*t)
#             maxheap.insert((i,increase))
#             extraStudents-=1
#         averageratio=0
#         print(classes)
#         for i in range(0,l):
#             averageratio+=classes[i][0]/classes[i][1]
#         return averageratio/l


# if __name__=="__main__":
#     sol=Solution()
#     print(sol.maxAverageRatio([[1,2],[3,5],[2,2]],2))
#     print(sol.maxAverageRatio([[2,4],[3,9],[4,5],[2,10]],4))


class Stack:
    def __init__(self):
        self.stack=[]
        self.top=0

    def push(self,val):
        self.stack.append(val)
        self.top+=1

    def pop(self):
        if(self.top==0):
            print("Stack is empty!!")
            return
        popedval=self.stack[self.top-1]
        self.stack.pop(self.top-1)
        self.top-=1
        return popedval

    def isEmpty(self):
        if(self.top==0):
            return True
        else:
            return False
        
    def __del__(self):
        del self.stack
        

class Solution():
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        ans=[]
        self.genPar(n-1,1,'(',ans)
        return ans
    
    
    def genPar(self,n,o,st,ans):
        if(n==0):
            while(o):
                st+=')'
                o-=1
            ans.append(st)
            return
        self.genPar(n-1,o+1,st+'(',ans)
        if(o>0):
            self.genPar(n,o-1,st+')',ans)
           







if __name__=="__main__":
    C=Solution()
    print(C.generateParenthesis(8))




