class Solution:
    def calculateSpan(self, arr):
        n = len(arr)
        stack = []  
        span = [0] * n

        for i in range(n):
           
            while stack and stack[-1][0] <= arr[i]:
                stack.pop()
            
          
            if not stack:
                span[i] = i + 1
            else:
                span[i] = i - stack[-1][1]
            
          
            stack.append((arr[i], i))
        
        return span