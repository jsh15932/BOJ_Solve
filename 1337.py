n = int(input())
arr = []

for i in range(n):
    arr.append(int(input()))
    
arr.sort()
res = 0

for i in range(n):
    cnt = 0
    
    for j in range(5):
        if arr[i] + j in arr[i : i + 5]:
            cnt += 1
        
        res = max(res, cnt)
        
print(5 - res)