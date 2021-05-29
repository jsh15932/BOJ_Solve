arr = []
arr.append(0)
arr.append(1)

while arr[-1] < int(1e9):
    arr.append(arr[-2] + arr[-1])
    
for _ in range(int(input())):
    n = int(input())
    res = []
    idx = len(arr) - 1
    
    while n > 0:
        if n >= arr[idx]:
            n -= arr[idx]
            res.append(arr[idx])
        
        idx -= 1
        
    for i in res[::-1]:
        print(i, end = ' ')
    
    print()