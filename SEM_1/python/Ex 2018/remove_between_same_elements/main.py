def remove_between_duplicates(arr):
    arr_len = len(arr)
    i = 1
    while i < arr_len - 1:
        if arr[i - 1] == arr[i + 1]:
            arr = arr[0: i] + arr[i + 1: len(arr)]
            arr_len = len(arr)
            i -= 1
        i += 1

    return arr


if __name__ == '__main__':
    array = [10, 12, 10, 10, 10]
    result = remove_between_duplicates(array)
    for i in result:
        print(i)
    print("Hello world!")
