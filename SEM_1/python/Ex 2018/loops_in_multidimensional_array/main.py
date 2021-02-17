def print_array(arr):
    for i in arr:
        for j in i:
            print("{:2d}".format(j), end="")
        print()


def has_loops(arr):
    for i in range(len(arr)):
        if len(arr[i]) < 3:
            continue

        els = [arr[i][0], arr[i][1]]
        k = 0
        for j in range(2, len(arr[i])):
            if len(els) > len(arr[i]) / 2:
                break
            if arr[i][j] == els[k]:
                k += 1
            else:
                els = els + els[0: k] + [arr[i][j]]
                k = 0

            if k == len(els):
                k = 0

        if k == 0 and len(els) <= len(arr[i]) / 2:
            return i

    return -1


if __name__ == '__main__':
    size = 10
    a = [[1, 1, 2], [1, 2, 3, 1, 2, 3, 4], [5, 4, 5, 4, 5, 4, 5, 4]]
    print_array(a)
    res = has_loops(a)
    print("Result:", res)
