from random import randint


class Position:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __eq__(self, other):
        return self.x == other.x and self.y == other.y


def fill_array_with_randoms(arr):
    for a in range(len(arr)):
        for b in range(len(arr[0])):
            arr[a][b] = randint(0, 100)


def print_arr(arr):
    for c in range(len(arr)):
        for d in range(len(arr[1])):
            print("{0:5d}".format((arr[c][d])), end='')
        print("")

    print()


def is_num_first(num):
    if num == 0 or num == 1:
        return False

    for i in range(2, int(num ** 0.5) + 1):
        if num % i == 0:
            return False

    return True


def get_first_divisors(num):
    if is_num_first(num):
        return [num]

    for i in range(2, int(num ** 0.5) + 1):
        if num % i == 0:
            res = []
            res.extend(get_first_divisors(i))
            res.extend(get_first_divisors(int(num / i)))
            return res

    return []


def get_numbers_knight_jumps(chessboard, position: Position, max_move_count, except_positions=None, curr_move=1):
    if except_positions is None:
        except_positions = []
    result = []
    chessboard_size = len(chessboard[0])
    x = position.x
    y = position.y
    except_positions.append(Position(x, y))
    where_bishop_can_jump = [
        Position(x - 1, y + 2),
        Position(x - 2, y + 1),
        Position(x - 2, y - 1),
        Position(x - 1, y - 2),
        Position(x + 1, y - 2),
        Position(x + 2, y - 1),
        Position(x + 2, y + 1),
        Position(x + 1, y + 2)
    ]

    for pos in where_bishop_can_jump:
        if -1 < pos.x < chessboard_size and - 1 < pos.y < chessboard_size and pos not in except_positions:
            if curr_move == max_move_count:
                except_positions.append(Position(pos.x, pos.y))
                if chessboard[pos.x][pos.y] in result:
                    continue
                result.append(chessboard[pos.x][pos.y])
            else:
                result.extend(
                    get_numbers_knight_jumps(chessboard, Position(pos.x, pos.y), max_move_count, except_positions,
                                             curr_move + 1))
    return result


def are_2_numbers_consists_of_first_nums(array, count_of_first_divisors, max_knights_jump):
    for i in range(len(array)):
        for j in range(len(array[0])):
            res = get_numbers_knight_jumps(array, Position(i, j), max_knights_jump)
            for q in res:
                product = q * array[i][j]
                first_divs = get_first_divisors(product)
                if len(first_divs) == count_of_first_divisors:
                    print('My position: i and j', i, j)
                    print('My position, val: ', array[i][j])
                    print('Value of another num: ', q)
                    print('Product', product)
                    print('Product divisors: ', first_divs)
                    return True
    return False


if __name__ == '__main__':
    size = 8
    first_divs_count = 3
    max_knights_jump_count = 2
    array = [[0 for x in range(size)] for y in range(size)]
    fill_array_with_randoms(array)
    print_arr(array)

    result = are_2_numbers_consists_of_first_nums(array, first_divs_count, max_knights_jump_count)
    print(result)
