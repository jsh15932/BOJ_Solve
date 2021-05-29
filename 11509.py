n = int(input())
data = list(map(int, input().split()))
res = 0
arr = [0] * 1000001

for i in data:
    if arr[i] > 0:
        arr[i] -= 1
        arr[i - 1] += 1
    
    else:
        arr[i - 1] += 1
        res += 1
        
print(res)