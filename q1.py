class MyStack:
    def __init__(self):
        self.arr = []
    
   
    def push(self, data):
        self.arr.append(data)
    

    def pop(self):
        if not self.arr:
            return -1
        return self.arr.pop()