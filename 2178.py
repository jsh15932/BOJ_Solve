from collections import deque
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]
arr = [list((input())) for _ in range(n)]

q = deque([[0, 0]])
arr[0][0] = 1

while q:
    x, y = q.popleft()
    
    for i in range(4):
        if 0 <= x + dx[i] < n and 0 <= y + dy[i] < m:
            if arr[x + dx[i]][y + dy[i]] == "1":
                arr[x + dx[i]][y + dy[i]] = arr[x][y] + 1
                q.append([x + dx[i], y + dy[i]])
                
print(arr[n - 1][m - 1])