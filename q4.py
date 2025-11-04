class Solution:
    def infixtoPostfix(self, s):
        # precedence map
        precedence = {'^': 3, '*': 2, '/': 2, '+': 1, '-': 1}
        
        def isRightAssociative(op):
            return op == '^'
        
        stack = []
        result = []
        
        for c in s:
            # If operand → add to result
            if c.isalnum():  
                result.append(c)
            
            # If '(' → push to stack
            elif c == '(':
                stack.append(c)
            
            # If ')' → pop until '('
            elif c == ')':
                while stack and stack[-1] != '(':
                    result.append(stack.pop())
                stack.pop()  # remove '('
            
            # If operator
            else:
                while (stack and stack[-1] != '(' and
                       ((not isRightAssociative(c) and precedence.get(c, 0) <= precedence.get(stack[-1], 0)) or
                        (isRightAssociative(c) and precedence.get(c, 0) < precedence.get(stack[-1], 0)))):
                    result.append(stack.pop())
                stack.append(c)
        
        # Pop remaining operators
        while stack:
            result.append(stack.pop())
        
        return "".join(result)
