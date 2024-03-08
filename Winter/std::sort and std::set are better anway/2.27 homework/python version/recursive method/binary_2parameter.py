import random
mylist = list({})
for i in range(100):
    mylist.append(random.randint(1,10000))
mylist.sort()
def binary(left, right):
    if (left == right):
        if (mylist[left] == myelement):
            return left
        else:
            return len(mylist)
    else:
        mid = (left + right)//2
        if (mylist[mid] > myelement):
            return binary(left, mid - 1)
        elif (mylist[mid] == myelement):
            return mid
        elif (mylist[mid] < myelement):
            return binary(mid + 1, right)
myelement = int(input("Enter a element here: "))
print("Our list is: ", mylist)
print("The element's location (returns 100 if not found, list 0-indexed): ", binary(0,len(mylist) - 1))