import random
mylist = []
for i in range(100):
    mylist.append(random.randint(1, 1000))  
def shell(alist):
    mylist = alist
    gap = len(mylist)//2
    while (gap > 0):
        i = gap
        while (i < len(mylist)):
            val = mylist[i]
            j = i - gap
            while ((j > 0) and (mylist[j] > val)):
                mylist[j + gap] = mylist[j]
                j -= gap
                mylist[j + gap] = val
            i += 1
        gap = gap // 2
    return mylist
print("List is: ", mylist)
print("Sorted list is: ", shell(mylist))