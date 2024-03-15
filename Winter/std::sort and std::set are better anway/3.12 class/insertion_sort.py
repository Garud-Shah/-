import random
mylist = list({})
for i in range(10):
    mylist.append(random.randint(1,10000))
def insertionsort(Amylist):
    mylist = Amylist
    length = len(mylist)
    for i in range(length - 1):
        i += 1
        current_value = mylist[i]
        current_position = i
        while ((mylist[current_position - 1] > current_value) and (current_position >= 0)):  
            temp = mylist[current_position]
            mylist[current_position] = mylist[current_position - 1]
            mylist[current_position - 1] = temp
            current_position -= 1
    return mylist
print("Original List: ", mylist)
print("Sorted List: ", insertionsort(mylist))
