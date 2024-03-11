import random
def selectionsort(alist):
    n = len(alist)
    mylist = alist
    for i in range(n-1):
        pos = i
        j = pos
        while (j < n):
            if (mylist[pos] >= mylist[j]):
                pos = j
            j += 1
        temp = mylist[i]
        mylist[i] = mylist[pos]
        mylist[pos] = temp
    return mylist
def main():
    mylist = list({})
    for i in range(10):
        mylist.append(random.randint(1,10000))
    print("Intial List: ", mylist)
    selectionsort(mylist)
    print("Sorted List: ", mylist)
main()