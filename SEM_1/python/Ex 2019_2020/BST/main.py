class Node:
    def __init__(self, value, left_child=None, right_child=None):
        self.value = value
        self.left_child = left_child
        self.right_child = right_child


class BST:
    def __init__(self, root_val):
        self.root = Node(root_val)

    # region Shared
    def print_tree(self):
        total_h = self.get_height(self.root)
        for i in range(total_h):
            layer = self.__get_layer(i, self.root)

            underscore_count = 6 * (2 ** (total_h - i - 3)) - 2 if (total_h - i - 3) >= 0 else 0
            ll_count = 2 ** (total_h - 1 - i)  # last layer elements count
            left_indent = (ll_count * 2 + 4 * (ll_count - 1)) / 2 - 1 - underscore_count
            between_indent = 6 * (2 ** (total_h - i - 1)) - 2 - 2 * underscore_count

            for _ in range(int(left_indent)):
                print(" ", end="")

            for k in layer:
                for _ in range(int(underscore_count)):
                    print("_", end="")

                if k is None:
                    print("__", end="")
                else:
                    print("{:02d}".format(k.value), end="")

                for _ in range(int(underscore_count)):
                    print("_", end="")

                for _ in range(int(between_indent)):
                    print(" ", end="")

            print()

            if i != total_h - 1:
                for _ in range(int(left_indent - 1)):
                    print(" ", end="")

                for k in layer:
                    print("/", end="")

                    for _ in range(int(2 + underscore_count * 2)):
                        print(" ", end="")

                    print("\\", end="")

                    for _ in range(between_indent - 2):
                        print(" ", end="")
            print()

    # endregion

    # region Recursively
    def insert(self, value, node=None):
        if node is None:
            if self.root is None:
                self.root = Node(value)
                return
            return self.insert(value, self.root)

        if value <= node.value:
            if node.left_child is None:
                node.left_child = Node(value)
                return
            return self.insert(value, node.left_child)

        if value > node.value:
            if node.right_child is None:
                node.right_child = Node(value)
                return
            return self.insert(value, node.right_child)

    def get_height(self, node=None):
        if node is None:
            return 0

        h1 = self.get_height(node.right_child)
        h2 = self.get_height(node.left_child)

        if h1 > h2:
            return h1 + 1

        return h2 + 1

    def count(self, node):
        if node is None:
            return 0

        res = 1

        res += self.count(node.left_child)
        res += self.count(node.right_child)
        return res

    def get_leaf_count(self, node):
        if node is None:
            return 1

        res = 0

        res += self.get_leaf_count(node.left_child)
        res += self.get_leaf_count(node.right_child)

        return res

    def get_node_count(self, layer_n, node=None, cur_layer_n=0):
        if node is None:
            return 0

        res = 0
        if layer_n != cur_layer_n:
            res += self.get_node_count(layer_n, node.left_child, cur_layer_n + 1)
            res += self.get_node_count(layer_n, node.right_child, cur_layer_n + 1)
            return res

        return 1

    def is_presented(self, value, node):
        if node is None:
            return False

        if value > node.value:
            return self.is_presented(value, node.right_child)
        if value < node.value:
            return self.is_presented(value, node.left_child)

        return True

    def destroy_tree(self, node, should_root_be_destroyed=True):
        if node is None:
            return

        if node.left_child is not None:
            self.destroy_tree(node.left_child)
            node.left_child = None

        if node.right_child is not None:
            self.destroy_tree(node.right_child)
            node.right_child = None

        if node == self.root and should_root_be_destroyed:
            self.root = None

        del node

    def destroy_excess_nodes(self, layer_n, node, current_layer=0):
        if node is None:
            return

        if current_layer >= layer_n:
            return self.destroy_tree(node, False)

        self.destroy_excess_nodes(layer_n, node.left_child, current_layer + 1)
        self.destroy_excess_nodes(layer_n, node.right_child, current_layer + 1)

    def __get_layer(self, layer_n, node=None, cur_layer_n=0):
        if node is None:
            return [None] * (2 ** (layer_n - cur_layer_n))

        if cur_layer_n != layer_n:
            left_nodes = self.__get_layer(layer_n, node.left_child, cur_layer_n + 1)
            right_nodes = self.__get_layer(layer_n, node.right_child, cur_layer_n + 1)
            return left_nodes + right_nodes

        return [node]

    # endregion

    # region Iteratively

    def i_count(self):
        curr = self.root
        result = 0
        actions = []
        mode = "Count"
        while True:
            while mode == "Count":
                if curr is None or (curr.left_child is None and curr.right_child is None):
                    if curr is not None:
                        result += 1
                    mode = "Wander"
                    continue
                if curr.left_child is not None:
                    result += 1
                    actions.append("Left")
                    curr = curr.left_child
                if curr.left_child is None and curr.right_child is not None:
                    result += 1
                    actions.append("Right")
                    curr = curr.right_child

            while mode == "Wander":
                for i in reversed(range(len(actions))):
                    if actions[i] == "Left":
                        actions[i] = "Right"
                        break
                    else:
                        actions.pop()

                if len(actions) == 0:
                    return result

                curr = self.root
                for i in range(len(actions)):
                    if actions[i] == "Left":
                        curr = curr.left_child
                    if actions[i] == "Right":
                        curr = curr.right_child

                mode = "Count"

    def i_get_height(self):
        curr = self.root
        result = 0
        actions = []
        mode = "Count"
        tmp_height = 0
        while True:
            while mode == "Count":
                if curr is None or (curr.left_child is None and curr.right_child is None):
                    mode = "Wander"
                    continue
                if curr.left_child is not None:
                    tmp_height += 1
                    actions.append("Left")
                    curr = curr.left_child
                if curr.left_child is None and curr.right_child is not None:
                    tmp_height += 1
                    actions.append("Right")
                    curr = curr.right_child

            while mode == "Wander":
                if tmp_height > result:
                    result = tmp_height

                for i in reversed(range(len(actions))):
                    if actions[i] == "Left":
                        actions[i] = "Right"
                        break
                    else:
                        tmp_height -= 1
                        actions.pop()

                if len(actions) == 0:
                    return result + 1

                curr = self.root
                for i in range(len(actions)):
                    if actions[i] == "Left":
                        curr = curr.left_child
                    if actions[i] == "Right":
                        curr = curr.right_child

                mode = "Count"

    def i_get_leaf_count(self):
        curr = self.root
        result = 0
        actions = []
        mode = "Count"
        while True:
            while mode == "Count":
                if curr is None or (curr.left_child is None and curr.right_child is None):
                    if curr is not None:
                        result += 2
                    if curr is None:
                        result += 1
                    mode = "Wander"
                    continue
                if curr.left_child is not None:
                    actions.append("Left")
                    curr = curr.left_child
                if curr.left_child is None and curr.right_child is not None:
                    result += 1
                    actions.append("Right")
                    curr = curr.right_child

            while mode == "Wander":
                for i in reversed(range(len(actions))):
                    if actions[i] == "Left":
                        actions[i] = "Right"
                        break
                    else:
                        actions.pop()

                if len(actions) == 0:
                    return result

                curr = self.root
                for i in range(len(actions)):
                    if actions[i] == "Left":
                        curr = curr.left_child
                    if actions[i] == "Right":
                        curr = curr.right_child

                mode = "Count"

    def i_get_node_count(self, layer_n):
        layer = self.__i_get_layer(layer_n)
        res = [x for x in layer if x is not None]
        return len(res)

    def i_is_presented(self, value):
        curr = self.root
        while True:
            if curr is None:
                return False
            if value > curr.value:
                curr = curr.right_child
                continue
            if value < curr.value:
                curr = curr.left_child
                continue
            if value == curr.value:
                return True

    def i_destroy_tree(self, from_node, should_root_be_destroyed=True):
        curr = from_node
        mode = "Count"
        while from_node is not None and (from_node.left_child is not None or from_node.right_child is not None):
            if curr.left_child is not None:
                if curr.left_child.left_child is None and curr.left_child.right_child is None:
                    del curr.left_child
                    curr.left_child = None
                    continue
                curr = curr.left_child
                continue

            if curr.left_child is None and curr.right_child is not None:
                if curr.right_child.left_child is None and curr.right_child.right_child is None:
                    del curr.right_child
                    curr.right_child = None
                    continue
                curr = curr.right_child
                continue

            curr = from_node

        if should_root_be_destroyed:
            self.root = None

    def i_destroy_excess_nodes(self, layer_n):
        curr = self.root
        actions = []
        mode = "Count"
        while True:
            while mode == "Count":
                if curr is None or (curr.left_child is None and curr.right_child is None):
                    if layer_n == len(actions):
                        self.i_destroy_tree(curr, False)
                    mode = "Wander"
                    continue
                if curr.left_child is not None:
                    if layer_n == len(actions):
                        self.i_destroy_tree(curr, False)
                        mode = "Wander"
                        continue
                    actions.append("Left")
                    curr = curr.left_child
                if curr.left_child is None and curr.right_child is not None:
                    if layer_n == len(actions):
                        self.i_destroy_tree(curr, False)
                        mode = "Wander"
                        continue
                    actions.append("Right")
                    curr = curr.right_child

            while mode == "Wander":
                for i in reversed(range(len(actions))):
                    if actions[i] == "Left":
                        actions[i] = "Right"
                        break
                    else:
                        actions.pop()

                if len(actions) == 0:
                    return

                curr = self.root
                for i in range(len(actions)):
                    if actions[i] == "Left":
                        curr = curr.left_child
                    if actions[i] == "Right":
                        curr = curr.right_child

                mode = "Count"

    def __i_get_layer(self, layer_n):
        curr = self.root
        result = []
        actions = []
        mode = "Count"
        while True:
            while mode == "Count":
                if curr is None or (curr.left_child is None and curr.right_child is None):
                    if layer_n == len(actions):
                        result += [curr]
                    else:
                        result += [None] * int(2 ** (layer_n - len(actions)))

                    mode = "Wander"
                    continue
                if curr.left_child is not None:
                    if layer_n == len(actions):
                        result += [curr]
                        mode = "Wander"
                        continue

                    actions.append("Left")
                    curr = curr.left_child
                if curr.left_child is None and curr.right_child is not None:
                    if layer_n == len(actions):
                        result += [curr]
                        mode = "Wander"
                        continue
                    else:
                        result += [None] * int(2 ** (layer_n - len(actions) - 1))

                    actions.append("Right")
                    curr = curr.right_child

            while mode == "Wander":
                for i in reversed(range(len(actions))):
                    if actions[i] == "Left":
                        actions[i] = "Right"
                        break
                    else:
                        actions.pop()

                if len(actions) == 0:
                    return result

                curr = self.root
                for i in range(len(actions)):
                    if actions[i] == "Left":
                        curr = curr.left_child
                    if actions[i] == "Right":
                        curr = curr.right_child

                mode = "Count"
    # endregion


if __name__ == '__main__':
    tree = BST(10)

    tree.insert(52)
    tree.insert(20)

    tree.insert(4)
    tree.insert(60)
    tree.insert(25)
    tree.insert(5)
    tree.insert(3)
    tree.insert(19)
    tree.insert(26)
    tree.insert(3)
    tree.insert(2)
    tree.insert(25)

    tree.print_tree()
    print("HELLO")
