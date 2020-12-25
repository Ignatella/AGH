import queue


# region Helpers
def add3(num):
    return num + 3


def multiply_by_2(num):
    return num * 2


def increase_even(num):
    num = str(num)
    result = ""
    for i in num:
        if int(i) % 2 == 0:
            result += str(int(i) + 1)
            continue
        result += i
    return int(result)


# endregion

def build_chain(gol, cur, lifo: queue, op_count, op_max) -> int:
    if cur > gol or op_count > op_max:
        return 0

    if cur == gol:
        return 1

    result = 0

    prev_operation = "" if lifo.empty() else lifo.get()

    if prev_operation != 'A':
        lifo.put('A')
        result += build_chain(gol, add3(cur), lifo, op_count + 1, op_max)

    if prev_operation != 'B':
        lifo.put('B')
        result += build_chain(gol, multiply_by_2(cur), lifo, op_count + 1, op_max)

    if prev_operation != 'C':
        lifo.put('C')
        result += build_chain(gol, increase_even(cur), lifo, op_count + 1, op_max)

    return result


if __name__ == '__main__':
    queue = queue.LifoQueue()
    start = 11
    goal = 31
    res = build_chain(goal, start, queue, 0, 4)
    print(res)
