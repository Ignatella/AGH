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

    tree.print_tree()
    tree.destroy_excess_nodes(1, tree.root)
    tree.print_tree()

    print("HELLO")

"""

     ____54____            
    /          \ 
   13          33      
  /  \        /  \
10    20    40    50
  
  
  
           __________54_________              h = 1  l = 0  k = 1  (4 - 0 - 3)
          /                     \  
     ____53____              ____90____       h = 2  l = 1  k = 0  (4 - 1 - 3)
    /          \            /          \     
   13          33          70          95     h = 3  l = 2  k < 0   
  /  \        /  \        /  \        /  \  
10    20    40    50    69    71    83    99  h = 4  l = 3  k < 0  

Итого: a(k) = 2^k*6-2 - the number of _ preceding the number (given that the number occupies 2 positions)
       a(n) = 6 * 2^(total_h - layer_n - 3) - 2


                       ______________________50______________________
                      /                                              \ 
           __________25__________                          __________75__________   
          /                      \                        /                      \ 
     ____15____              ____40____              ____65____              ____90____    
    /          \            /          \            /          \            /          \  
   10          17          35          45          55          70          80          95
  /  \        /  \        /  \        /  \        /  \        /  \        /  \        /  \ 
09    11    16    18    34    36    44    46    54    56    69    71    79    81    94    99  
       
"""
