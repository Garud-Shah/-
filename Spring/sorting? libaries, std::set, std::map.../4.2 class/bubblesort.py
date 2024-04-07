import random
mylist = []
for i in range(100):
    mylist.append(random.randint(1, 1000))
def bubblesort(alist):
    mylist = alist
    for i in range(len(mylist) - 1):
        for j in range(len(mylist) - 1):
            if (mylist[j] > mylist[j+1]):
                temp = mylist[j]
                mylist[j] = mylist[j+1]
                mylist[j+1] = temp
    return mylist
         

print("List is: ")