from scipy.fft import fft, ifft
import numpy as np
import math
def Rotate(l, y=1):
   if len(l) == 0:
      return l
   y = -y % len(l)     # flip rotation direction
   return l[y:] + l[:y]
def PointAdd(arrA,arrB):
    return list(map(lambda x, y: x + y, arrA, arrB))
def PointMul(ArrA,ArrB):
    return [ArrB[0] * ArrA[0],ArrA[1]*ArrB[1] ,ArrA[2] * ArrB[2],ArrA[3] * ArrB[3]]

def  mixa(arrA,arrB):
    tmp = arrA
    arrA = PointAdd(arrA,arrB)
    arrB = PointAdd(Rotate(arrB,2),tmp)
    return [arrA,arrB]
def  mixb(arrA,arrB):
    tmp = Rotate(arrA,1)
    arrA = PointAdd(arrA,arrB)
    arrB = PointAdd(Rotate(arrB,1),tmp)
    return [arrA,arrB]
def  mixbi(arrA,arrB):
    tmp = Rotate(arrA,-1)
    arrA = PointAdd(arrA,Rotate(arrB,-1))
    arrB = PointAdd(arrB,tmp)
    return [arrA,arrB]

def idft(arrA):
    tmp = mixa(arrA[0],arrA[1])
    arrA[0] = tmp[0]
    arrA[1] = tmp[1]
    tmp = mixa(arrA[2],arrA[3])
    arrA[2] = tmp[0]
    arrA[3] = tmp[1]
    tmp = mixa(arrA[0],arrA[2])
    arrA[0] = tmp[0]
    arrA[2] = tmp[1]
    tmp = mixbi(arrA[1],arrA[3])
    arrA[1] = tmp[0]
    arrA[3] = tmp[1]    #part 2
    #need to div by number of elements
    for i in range(len(arrA)):
        for b in range(4):
            arrA[i][b] = math.floor(arrA[i][b]/len(arrA))
    #need to subtract by the opposite

    for i in range(len(arrA)):
        arrA[i][0] = arrA[i][0] - arrA[i][2]
        arrA[i][1] = arrA[i][1] - arrA[i][3]
        arrA[i][3] = 0
        arrA[i][2] = 0
    return arrA
def dft(arrA):
    tmp = mixa(arrA[0],arrA[2])
    arrA[0] = tmp[0]
    arrA[2] = tmp[1]
    tmp = mixb(arrA[1],arrA[3])
    arrA[1] = tmp[0]
    arrA[3] = tmp[1]    #part 2
    tmp = mixa(arrA[0],arrA[1])
    arrA[0] = tmp[0]
    arrA[1] = tmp[1]
    tmp = mixa(arrA[2],arrA[3])
    arrA[2] = tmp[0]
    arrA[3] = tmp[1]
    return arrA



num = 64
a = [0] * 4
for i in range(len(a)):
    a[i] = [math.floor(num/pow(10,i))%10,0,0,0]
print(str(a) + "setp 1")
#a = [[1, 0, 0, 0],[2, 0, 0, 0],[0, 0, 0, 0],[0, 0, 0, 0]]
#num2 = 34
#b = [0] * 4
#for i in range(len(a)):
#    b[i] = [math.floor((num2/pow(10,math.floor(1)-i))%10),0,0,0]
a = dft(a)
for i in range(len(a)):
    a[i] = PointAdd(a[i],a[i])
print(str(a) + "dtf")
a = idft(a)


print(str(a) + "restult")


#print(a)
#print(idft(a))

# [3, 0, 0, 0], [4, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]
# +x -y +x -y
#  e  n  w  s
#
# (3, 0, 0, 0) (1, 0, 2, 0) (1, 2, 0, 0) (1, 0, 0, 2)
# the real fft of 
# it is 
# {1.5 + 0 i, 0.5 + i, -0.5 + 0 i, 0.5 - i} 
# we multiply every thing by 2 and put the values into there respective places and get the same






