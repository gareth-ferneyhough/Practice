# Returns True if a given directed graph has a route
# from node to target.

def has_route(graph, node, target, visited=None):
    if visited is None:
        visited = set()

    if node == target:
        return True

    visited.add(node)
    for neighbor in graph[node]:
        if neighbor in visited:
            continue
        if has_route(graph, neighbor, target, visited):
            return True
    return False

def make_graph():
    graph = {
        'a': ['b', 'c'],
        'b': ['d'],
        'c': ['d'],
        'd': ['a', 'e'],
        'e': []
    }
    return graph

def test_has_route1():
    g = make_graph()
    assert has_route(g, 'a', 'd') is True

def test_has_route2():
        g = make_graph()
        assert has_route(g, 'a', 'e') is True

def test_no_route1():
        g = make_graph()
        assert has_route(g, 'e', 'a') is False

def main():
    test_has_route1()
    test_has_route2()
    test_no_route1()
    
if __name__ == '__main__':
    main()
