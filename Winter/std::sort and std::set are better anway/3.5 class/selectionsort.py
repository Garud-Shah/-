import random
mylist = list({})
for i in range(10):
    mylist.append(random.randint(1,10000))
def selectionsort(Amylist):
    integer = len(Amylist)
    mylist = Amylist
    for i in range(integer - 1):
        pos = i
        j = pos
        while (j < integer):
            if (mylist[j] < mylist[pos]):
                pos = j
    temp = mylist[pos]
    mylist[pos] = mylist[i]
    mylist[i] = temp
    return mylist
print("Our list is: ", mylist)
print("Sorted Edition: ", selectionsort(mylist))
        