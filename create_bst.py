# Creates a minimum-height BST given
# a sorted (increasing) array of nodes.

class BinaryTree:
    def __init__(self, value=0):
        self.value = value
        self.left = None
        self.right = None

    def __str__(self, depth=0):
        ret = ""

        # Print right branch
        if self.right != None:
            ret += self.right.__str__(depth + 1)

        # Print own value
        ret += "\n" + ("    "*depth) + str(self.value)

        # Print left branch
        if self.left != None:
            ret += self.left.__str__(depth + 1)

        return ret

def create_bst(array):        
    if len(array) == 0:
        return None

    node_index = (len(array) - 1) / 2
    node_data = array[node_index]    
    n = BinaryTree(node_data)

    n.left = create_bst(array[0:node_index])        
    n.right = create_bst(array[node_index + 1: len(array)])    
    return n

def test1():
    array = [i for i in range(1, 10)]
    root = create_bst(array)
    print root

def main():
    test1()

if __name__ == '__main__':
    main()
