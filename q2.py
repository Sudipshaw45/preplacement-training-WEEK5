class StackNode:
    def __init__(self, data):
        self.data = data
        self.next = None

class MyStack:
    def __init__(self):
        self.top = None

    # Function to push an integer into the stack
    def push(self, data):
        newNode = StackNode(data)
        newNode.next = self.top
        self.top = newNode

    # Function to remove an item from top of the stack
    def pop(self):
        if self.top is None:
            return -1
        val = self.top.data
        self.top = self.top.next
        return val