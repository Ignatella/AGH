class Number:
    def __init__(self, num: int, next_num=None):
        self.num = num
        self.next_num = next_num


def print_chain(root: Number):
    current = None
    while current != root:
        if current is None:
            current = root
        print(current.num, end="")
        print("(", count_binary_1(current.num), ")", end="")
        print("--->", end="")
        current = current.next_num
    print()


def count_binary_1(num):
    result = 0
    while num != 0:
        if num & 1 != 0:
            result += 1
        num = num >> 1
    return result


def divide(root: Number) -> (Number, Number, int):
    even_root = None
    odd_root = None
    current_even = None
    current_odd = None
    current = None
    delete_count = 0
    next_num = root.next_num

    while current is not root:
        if current is None:
            current = root

        if count_binary_1(current.num) % 2 == 0 and current.num % 2 == 0:
            if current_even is None:
                if even_root is None:
                    even_root = current
            else:
                current_even.next_num = current
            current_even = current
            current = current.next_num
            next_num = next_num.next_num
            continue

        if count_binary_1(current.num) % 2 == 1 and current.num % 2 == 1:
            if current_odd is None:
                if odd_root is None:
                    odd_root = current
            else:
                current_odd.next_num = current
            current_odd = current
            current = current.next_num
            next_num = next_num.next_num
            continue

        delete_count += 1
        current = next_num
        next_num = next_num.next_num

    if current_even is not None:
        current_even.next_num = even_root
    if current_odd is not None:
        current_odd.next_num = odd_root

    return even_root, odd_root, delete_count


if __name__ == '__main__':
    r0 = Number(5)
    r1 = Number(90)
    r2 = Number(14)
    r3 = Number(19)
    r4 = Number(24)
    r5 = Number(25)
    r6 = Number(26)
    r7 = Number(30)

    r0.next_num = r1
    r1.next_num = r2
    r2.next_num = r3
    r3.next_num = r4
    r4.next_num = r5
    r5.next_num = r6
    r6.next_num = r7
    r7.next_num = r0

    print_chain(r0)

    ev_r, odd_r, del_c = divide(r0)

    print("Even")
    print_chain(ev_r)
    print("Odd")
    print_chain(odd_r)
    print("Deleted: ", del_c)
