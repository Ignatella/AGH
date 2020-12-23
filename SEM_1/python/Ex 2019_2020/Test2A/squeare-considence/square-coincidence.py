from random import randint


def fill_array(arr, length):
    for a in range(length):
        for b in range(length):
            arr[a][b] = randint(0, 100)


def count_even(number):
    result = 0
    while number > 1:
        rest = number % 5
        number = number // 5
        if rest % 2 == 0:
            result += 1

    return result


def print_arr(arr):
    for c in range(len(arr)):
        for d in range(len(arr[1])):
            print("{0:5d}".format((arr[c][d])), end='')
        print("")

    print()


if __name__ == '__main__':
    count_even(25)
    count_even(97)
    count_even(4)
    count_even(73)
    count_even(35)
    count_even(92)

    size1 = 3
    size2 = 6
    arr1 = [[0 for x in range(size1)] for y in range(size1)]
    arr2 = [[0 for x in range(size2)] for y in range(size2)]
    fill_array(arr1, size1)
    fill_array(arr2, size2)
    print_arr(arr1)
    print_arr(arr2)

    x = 0 - size1 + 1
    y = 0 - size1 + 1
    for i in range(x, size2 + size1 - 1):
        for j in range(y, size2 + size1 - 1):
            coincident = 0
            count = 0
            for k in range(size1):
                for l in range(size1):
                    if size2 > i + k >= 0 and size2 > j + l >= 0:
                        count += 1
                        # print("from arr1 ", arr1[k][l], "form arr2", arr2[i + k][j + l])
                        in_first_arr = count_even(arr1[k][l])
                        in_second_arr = count_even(arr2[i + k][j + l])
                        if in_first_arr == in_second_arr and in_second_arr > 0:
                            coincident += 1
            if count == 0:
                continue
            if coincident / count >= 0.9:
                print("It exists and (small square) starts from x =", i, "y =", j)
                quit(0)

    print("Sad, does not exists")
