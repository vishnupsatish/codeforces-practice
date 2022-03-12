# Idea: determine how many times each digit will change.

n = int(input())

while n != 0:
    l, r = input().split()
    
    ans = 0

    l = ''.join(['0'] * (len(r) - len(l))) + l

    for i in range(len(l)):
        ans += int(int(r[:i + 1]) - int(l[:i + 1]))

    print(ans)
        
    n -= 1
