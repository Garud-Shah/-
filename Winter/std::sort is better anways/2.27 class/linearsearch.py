def find(array, key)
    index = 0
    while index < array.size():
        if array[index] == key:
            return index
        else:
            index += 1
    return array.size()
# ugh python is CuRsEd
