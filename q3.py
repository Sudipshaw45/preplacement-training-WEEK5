def isBalanced(s):
    stack = []
    pairs = {')': '(', ']': '[', '}': '{'}
    
    for ch in s:
        if ch in "({[":
            stack.append(ch)
        else:
            if not stack or stack[-1] != pairs[ch]:
                return "NO"
            stack.pop()
    
    return "YES" if not stack else "NO"


if __name__ == '__main__':
    t = int(input().strip())
    for _ in range(t):
        s = input().strip()
        print(isBalanced(s))
