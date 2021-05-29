n = int(input())
arr = []

for i in range(n):
    arr.append(int(input()))
    
arr.sort()
res = -1

for i in range(n - 2):
    if arr[i] + arr[i + 1] > arr[i + 2]:
        res = arr[i] + arr[i + 1] + arr[i + 2]

print(res)