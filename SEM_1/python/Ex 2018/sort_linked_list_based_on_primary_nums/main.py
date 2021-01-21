class Number:
    def __init__(self, num, next_num=None):
        self.num = num
        self.next_num = next_num


def is_first(num):
    for i in range(2, int((num ** 0.5) + 1)):
        if num % i == 0:
            return False

    return True


def print_chain(number: Number):
    current = None
    while current is not number:
        if current is None:
            current = number

        print("---->", end="")
        print(current.num, end="")

        current = current.next_num
    print()


def sort_linked_list(root: Number):
    prime_head = None
    prime_tail = None
    complex_head = None
    complex_tail = None

    current = None

    while current is not root:
        if current is None:
            current = root

        if is_first(current.num):
            if prime_head is None:
                prime_head = current
                prime_tail = current
            else:
                prime_tail.next_num = current
                prime_tail = current
        else:
            if complex_head is None:
                complex_head = current
                complex_tail = current
            else:
                complex_tail.next_num = current
                complex_tail = current

        current = current.next_num

    if complex_head is None and prime_head is None:
        return None
    if complex_head is None:
        prime_tail.next_num = prime_head
        return prime_head
    if prime_head is None:
        complex_tail.next_num = complex_head
    else:
        complex_tail.next_num = prime_head
        prime_tail.next_num = complex_head

    return complex_head


if __name__ == '__main__':
    r0 = Number(11)
    r1 = Number(10)
    r2 = Number(15)
    r3 = Number(12)
    r4 = Number(11)
    r5 = Number(8)
    r6 = Number(7)
    r7 = Number(101)
    r8 = Number(102)
    r9 = Number(103)
    r10 = Number(3)
    r11 = Number(18)

    r0.next_num = r1
    r1.next_num = r0
    r2.next_num = r3
    r3.next_num = r4
    r4.next_num = r5
    r5.next_num = r6
    r6.next_num = r7
    r7.next_num = r8
    r8.next_num = r9
    r9.next_num = r10
    r10.next_num = r11
    r11.next_num = r0

    print_chain(r0)
    res = sort_linked_list(r0)
    print_chain(res)

    print("hello")
