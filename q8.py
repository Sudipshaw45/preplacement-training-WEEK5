class Solution:
    def celebrity(self, mat):
        n = len(mat)
        stack = [i for i in range(n)] 

       
        while len(stack) > 1:
            a = stack.pop()
            b = stack.pop()

            
            if mat[a][b] == 1:
                stack.append(b)
            else:
              
                stack.append(a)

        if not stack:
            return -1

        cand = stack.pop()

        for i in range(n):
            if i != cand:
                
                if mat[cand][i] == 1 or mat[i][cand] == 0:
                    return -1

        return cand