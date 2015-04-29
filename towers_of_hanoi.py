# Towers of Hanoi recursive solution
towers = []

def printTowers():
    tallest = max((len(tower) for tower in towers))
    for i in range(tallest - 1, -1, -1):
        for tower in towers:
            if len(tower) > i:
                print tower[i],
            else:
                print '.',
            print '\t',
        print '\n',
    print '\n\n'

def move(fromPole, toPole):
    towers
    towers[toPole].append(towers[fromPole].pop())
    #printTowers()

def calculate(n, fromPole, toPole, bufferPole):
    if n == 1:
        move(fromPole, toPole)
        return

    calculate(n-1, fromPole, bufferPole, toPole)
    calculate(1, fromPole, toPole, bufferPole)
    calculate(n-1, bufferPole, toPole, fromPole)

def solve(n):
    global towers
    towers = [[i for i in range(n)], [], []]            
    calculate(n, 0, 2, 1)      

if __name__ == '__main__':  
    n = 5
    solve(n)
    printTowers() 
