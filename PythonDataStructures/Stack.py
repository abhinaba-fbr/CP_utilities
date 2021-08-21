'''
Contains Class Stack which can be easily used to create a stack
#No need of constructor parameter, can simply create a stack using -> Stack()

Contains the following abstract function for the user-
1. push(val) -> takes a val as paremeter which can be and simple or derived data
2. pop() -> returns the top element pf the stack
3. isEmpty() -> returns True if the stack is empty else false
'''

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



if __name__=="__main__":
    S=Stack()
    S.push(5)
    S.push(6)
    S.push(7)
    print(S.pop())
    print(S.pop())
