
print("thaihoa")
num1 = int(input("num_1= "))
num2 = int(input("num_2= "))
num3 = int(input("num_3= "))
arr = [num1,num2,num3]
n = len(arr)
for i in range (0,n-1):
    for j in range (i+1,n-1):
        if arr[j] < arr[j+1]:
            arr[j+1], arr[j] = arr[j], arr[j+1]
for i in range(n):
    print(arr[i], end = " ")