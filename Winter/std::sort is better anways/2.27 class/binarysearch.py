def binary(lowerbound, upperbound, array, element)
    if lowerbound == upperbound:
        if array[lowerbound] == element:
            return lowerbound
        else:
            return array.size()
    else:
        number = (lowerbound + upperbound) // 2 
        if array[number] < element:
            return binary(lowerbound, number, array, element)
        else:
            return binary(number, upperbound, array, element)

