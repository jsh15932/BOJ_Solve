n = int(input())
s = [input() for _ in range(n)]
k = sorted(s)

if s == k:
    print("INCREASING")

elif s == sorted(k, reverse=True):
    print("DECREASING")
    
else:
    print("NEITHER")