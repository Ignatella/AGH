def find(array, curr_line=0, curr_sum=0) -> (bool, []):
    result = []

    if curr_sum == 0 and curr_line >= len(array):
        return True, result

    if curr_line >= len(array):
        return False, result

    for i in range(len(array[curr_line]) + 1):
        if i == len(array[curr_line]):
            return False, result
        element = array[curr_line][i]
        res, arr = find(array, curr_line + 1, curr_sum + element)
        result.extend(arr)
        if res is True:
            result.append("{} from line {}".format(element, curr_line))
            return True, result


if __name__ == '__main__':
    array = [[3, 4, 5], [1, 2, 3, 4, -5], [1, 2, 3, 4, 5]]
    result, nums = find(array)
    for i in nums:
        print(i)
    print()
    print(result)
