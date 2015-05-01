# Return True if a binary tree
# is balanced, that is, the height
# of its subtrees are different by
# no more than 1.

class Node:
    def __init__(self):
        self.left = None
        self.right = None

def calc_height(node):
    if node is None:
        return 0
    left = calc_height(node.left)
    if left == -1:
        return -1
    right = calc_height(node.right)
    if right == -1:
        return -1
    if abs(left - right) > 1:
        return -1
    return max(left, right) + 1

def is_balanced(node):
    if calc_height(node) == -1:
        return False
    return True


def test_unbalanced1():
    # unbalanced:
    #        a
    #      b   c
    #     d e
    #    f
    #

    a = Node()
    b = Node()
    c = Node()
    d = Node()
    e = Node()
    f = Node()
    g = Node()
    
    a.left = b
    a.right = c
    b.left = d
    b.right = e
    d.left = f

    assert is_balanced(a) == False

def test_unbalanced2():
    # unbalanced:
    #        a
    #      b   c
    #     d e    f
    #           g   
    #
    #

    a = Node()
    b = Node()
    c = Node()
    d = Node()
    e = Node()
    f = Node()
    g = Node()
    
    a.left = b
    a.right = c
    b.left = d
    b.right = e
    c.right = f
    f.left = g

    assert is_balanced(a) == False

def test_balanced1():
    # balanced:
    #        a
    #      b   c
    #     d e f g
    
    a = Node()
    b = Node()
    c = Node()
    d = Node()
    e = Node()
    f = Node()
    g = Node()
    
    a.left = b
    a.right = c
    b.left = d
    b.right = e
    c.left = f
    c.right = g

    assert is_balanced(a) == True

def main():
    test_unbalanced1()
    test_unbalanced2()
    test_balanced1()

if __name__ == '__main__':
    main()
