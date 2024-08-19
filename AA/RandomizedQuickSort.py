import time
import random

def hoarePartition(arr, low, high):
    pivot_ind = low # random.randint(low, high)
    pivot = arr[pivot_ind] #low
    
    i = low - 1
    j = high + 1

    while (True):
        i += 1
        while (arr[i] < pivot):
            i += 1

        j -= 1
        while (arr[j] > pivot):
            j -= 1

        if (i >= j):
            return j

        arr[i], arr[j] = arr[j], arr[i]


def hoareQuickSort(arr, low, high):
    if (low < high):

        pi = hoarePartition(arr, low, high)

        hoareQuickSort(arr, low, pi)
        hoareQuickSort(arr, pi + 1, high)



def lomutoPartition(arr, low, high):
    pivot_ind = high # random.randint(low, high)
    pivot = arr[pivot_ind] #high
    
    i = (low - 1)
    for j in range(low, high):
        
        if (arr[j] <= pivot):
            i += 1 
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[pivot_ind] = arr[pivot_ind], arr[i + 1]
    return (i + 1)
    

def lomutoQuickSort(arr, low, high):
    if (low < high):
        pi = lomutoPartition(arr, low, high)
        
        lomutoQuickSort(arr, low, pi - 1)
        lomutoQuickSort(arr, pi + 1, high)
        
def printArray(arr, n):
    for i in range(n):
        print(arr[i], end=" ")
    print()

def Hoare(arr):
    n = len(arr)
    # printArray(arr, n)
    hoareQuickSort(arr, 0, n - 1)
    # printArray(arr, n)

def Lomuto(arr):
    n = len(arr)
    # printArray(arr, n)
    lomutoQuickSort(arr, 0, n - 1)
    # printArray(arr, n)



amount = 1000000
arr = [random.choice(range(5555555)) for _ in range(amount)]
arr_copy = arr.copy()

start_time = time.time()
Lomuto(arr_copy)
end_time = time.time()
print("---Lomuto: ", (end_time - start_time))


start_time = time.time()
Hoare(arr)
end_time = time.time()
print("---Hoare: " , (end_time - start_time))

