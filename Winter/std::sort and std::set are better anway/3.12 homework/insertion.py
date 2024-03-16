import random
mylist = list({})
for i in range(10):
    mylist.append(random.randint(1,10000))
def insertion_sort(Alist):
    List = Alist
    for i in range(len(List) - 1):
        index = i + 1
        while ((List[index] < List[index - 1]) and (index > 0)):
            temp = List[index]
            List[index] = List[index - 1]
            List[index - 1] = temp
            index -= 1
    return List
print("Unsorted list: ", mylist)
print("Sorted List: ", insertion_sort(mylist))