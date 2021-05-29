n = int(input()) 
arr = [] 

for i in range(n): 
    arr.append(input()) 
    
increasing = True 
decreasing = True 

for i in range(n - 1): 
    if arr[i] < arr[i + 1]: 
        decreasing = False 
        
    elif arr[i] > arr[i + 1]: 
        increasing = False 
        
if increasing: 
    print('INCREASING')
    
elif decreasing: 
    print('DECREASING') 
    
else: 
    print('NEITHER') 