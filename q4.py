class Solution:
    def infixtoPostfix(self, s):
       
        precedence = {'^': 3, '*': 2, '/': 2, '+': 1, '-': 1}
        
        def isRightAssociative(op):
            return op == '^'
        
        stack = []
        result = []
        
        for c in s:
          
            if c.isalnum():  
                result.append(c)
            
           
            elif c == '(':
                stack.append(c)
            
            
            elif c == ')':
                while stack and stack[-1] != '(':
                    result.append(stack.pop())
                stack.pop()  
            
            
            else:
                while (stack and stack[-1] != '(' and
                       ((not isRightAssociative(c) and precedence.get(c, 0) <= precedence.get(stack[-1], 0)) or
                        (isRightAssociative(c) and precedence.get(c, 0) < precedence.get(stack[-1], 0)))):
                    result.append(stack.pop())
                stack.append(c)
        
       
        while stack:
            result.append(stack.pop())
        
        return "".join(result)
