n = int(input())
arr = []

for i in range(n):
    c, s = map(int, input().split())
    arr.append((c, s, i))

arr.sort(key = lambda x : x[1])
sum = 0
color_sum = [0] * 200001
res = [[] for _ in range(n)]
start = 0

while start < n:
    end = start
    
    while end < n and arr[start][1] == arr[end][1]:
        end += 1
    
    for i in range(start, end):
        res[arr[i][2]] = sum - color_sum[arr[i][0]]
        
    for i in range(start, end):
        color_sum[arr[i][0]] += arr[i][1]
        sum += arr[i][1]
    
    start = end
    
for i in res:
    print(i)