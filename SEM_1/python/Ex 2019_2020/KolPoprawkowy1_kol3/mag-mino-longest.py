class Domino:
    head: int
    tail: int

    def __init__(self, head: int, tail: int):
        self.head = head
        self.tail = tail


def find_max_length(dominos: [Domino], tail: int) -> int:
    result_length = 0
    found = False

    for i, domino in enumerate(dominos):
        len1 = 0
        len2 = 0

        if tail == -1:
            len1 = find_max_length(dominos[0:i] + dominos[i + 1:], domino.tail)
            len2 = find_max_length(dominos[0:i] + dominos[i + 1:], domino.head)
            if len1 != 0 or len2 != 0:
                found = True

        if domino.head == tail:
            found = True
            len1 = find_max_length(dominos[0:i] + dominos[i + 1:], domino.tail)
        if domino.tail == tail:
            found = True
            len2 = find_max_length(dominos[0:i] + dominos[i + 1:], domino.head)

        if len1 > result_length or len2 > result_length:
            result_length = len1 if len1 - len2 > 0 else len2

    if found:
        result_length += 1

    return result_length


if __name__ == '__main__':
    dom1 = Domino(2, 8)
    dom2 = Domino(0, 1)
    dom3 = Domino(2, 3)
    dom4 = Domino(3, 6)
    dom5 = Domino(2, 6)
    dom6 = Domino(2, 9)
    dom7 = Domino(3, 4)
    dom8 = Domino(6, 7)
    res: int = find_max_length([dom1, dom2, dom3, dom4, dom5, dom6, dom7, dom8], -1)

    print(res)
