import sys

n = int(input())
arr = []
result = 0

for _ in range(n):
    arr.append(int(sys.stdin.readline()))
    
arr.sort(reverse=True)

while(True):
    if arr[0] < (arr[1] + arr[2]):
        result = arr[0] + arr[1] + arr[2]
        break
    
    elif len(arr) > 3:
        arr.pop(0)
        
    else:
        result = -1
        break

print(result)