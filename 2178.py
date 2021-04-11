from collections import deque
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]
s = []

for i in range(n):
    s.append(list(input()))

q = deque([[0, 0]])
s[0][0] = 1

while q:
    x, y = q.popleft()
    
    for i in range(4):
        if 0 <= x + dx[i] < n and 0 <= y + dy[i] < m:
            if s[x + dx[i]][y + dy[i]] == "1":
                s[x + dx[i]][y + dy[i]] = s[x][y] + 1
                q.append([x + dx[i], y + dy[i]])
                
print(s[n - 1][m - 1])