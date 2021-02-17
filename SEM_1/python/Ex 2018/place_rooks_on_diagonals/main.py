class position:
    def __init__(self, x: int, y: int):
        self.x = x
        self.y = y


def print_array(array):
    for i in array:
        for j in i:
            print("{:2d}".format(j), end="")
        print()


def get_sum(chessboard, pos: position):
    result = 0
    for y in chessboard[pos.x]:
        result += y
    for x in chessboard:
        result += x[pos.y]

    result -= chessboard[pos.x][pos.y]
    return result


def get_sums_for_row(chessboard, row):
    col = row
    if row > (len(chessboard) - 1) / 2:
        col = len(chessboard) - row - 1
    s1 = get_sum(chessboard, position(x=row, y=col))
    s2 = get_sum(chessboard, position(x=row, y=len(chessboard) - 1 - col))
    return [s1, s2]


def place_rook(chessboard, cur_row=0, cur_sum=0, d1_count=0, d2_count=0):
    if cur_row == len(chessboard) and cur_sum == 0 and d1_count == d2_count:
        return True

    if cur_row == len(chessboard):
        return False

    sums = get_sums_for_row(chessboard, cur_row)
    for s in range(len(sums)):
        # res = False
        if s == 0:
            res = place_rook(chessboard, cur_row + 1, cur_sum + sums[s], d1_count + 1, d2_count)
        else:
            res = place_rook(chessboard, cur_row + 1, cur_sum + sums[s], d1_count, d2_count + 1)

        if res:
            return True

    return False


if __name__ == '__main__':
    cb = [[1, 0, 0, -1], [0, 0, 0, 0], [0, 0, 0, 0], [1, 0, 0, -1]]
    print_array(cb)
    print(place_rook(cb))
