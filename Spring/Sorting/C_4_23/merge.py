import random
mylist = []
for i in range(100):
    mylist.append(random.randint(1, 1000))  
def doublesort(list1, list2):
    
def merge(alist, l, r):
    if (l < r):
        mid = (l + r)/2
        mergesort(alist, l, mid)
        megresort(alist, mid + 1, r)
        doublesort(l, r)    
print("List is: ", mylist)
print("Sorted list is: ", merge(mylist))