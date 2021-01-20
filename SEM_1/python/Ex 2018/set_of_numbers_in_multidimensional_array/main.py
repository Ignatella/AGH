from random import randint


def print_array(array):
    for i in range(len(array)):
        for j in range(len(array)):
            print("{:6d}".format(array[i][j]), end="")
        print()


def fill_with_randoms(array):
    for i in range(len(array)):
        for j in range(len(array)):
            array[i][j] = randint(0, 100000)


def check_nums(num1, num2, num3):
    nums = []
    for num in [num1, num2, num3]:
        for letter in str(num):
            if letter.isdigit():
                if letter not in nums:
                    nums.append(letter)
                else:
                    return False

    if len(nums) == 10:
        return True

    return False


def check_square(array, x, y, square_size):
    num1 = array[x][y]
    num2 = array[x][y + square_size - 1]
    num3 = array[x + square_size - 1][y + square_size - 1]
    num4 = array[x + square_size - 1][y]

    res1 = check_nums(num1, num2, num3)
    res2 = check_nums(num1, num3, num4)
    res3 = check_nums(num1, num2, num4)
    res4 = check_nums(num2, num3, num4)

    return res1 or res2 or res3 or res4


def check_array(array, square_size=2):
    if square_size > len(array):
        return 0

    bound = len(array) - square_size + 1
    for i in range(bound):
        for j in range(bound):
            exists = check_square(array, i, j, square_size)
            if exists:
                return square_size

    return check_array(array, square_size + 1)


if __name__ == '__main__':
    array_size = 10
    array = [[0] * array_size for i in range(array_size)]
    fill_with_randoms(array)
    array[1][1] = 1234
    array[2][2] = 5678
    array[1][2] = 90

    res = check_array(array)

    print_array(array)
    print(res)
