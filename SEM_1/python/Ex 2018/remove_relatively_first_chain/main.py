def are_first(a, b):
    if a == 1 or b == 1:
        return False

    while a > 0:
        tmp = a
        a = b % a
        b = tmp

    if b == 1:
        return True
    return False


def rem(array):
    max_len = 0
    max_start_from = 0

    curr_len = 0
    curr_start_from = 0

    for i in range(1, len(array)):
        if are_first(array[i], array[i - 1]):
            if curr_len == 0:
                curr_start_from = i - 1
                curr_len += 1
            curr_len += 1
            if curr_len > max_len:
                max_len = curr_len
                max_start_from = curr_start_from
            continue

        curr_start_from = i
        curr_len = 0

    result = array[0: max_start_from] + array[max_start_from + max_len: len(array)]
    return result


if __name__ == '__main__':
    arr = [4, 9]
    res = rem(arr)
    for i in res:
        print(i)
    print("hello")
