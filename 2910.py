n, c = map(int, input().split())
tmp = input().split()
arr = {}

for i in tmp:
    if i in arr:
        arr[i] += 1
    
    else:
        arr[i] = 1
        
answer = sorted(arr.items(), key = lambda x : x[1], reverse=True)

for i in answer:
    for _ in range(i[1]):
        print(i[0], end = ' ')