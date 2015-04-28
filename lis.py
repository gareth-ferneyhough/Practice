# Return longest increasing subsequence of one iterable
# using dynamic programming.
def lis(d):
    if len(d) == 0:
        return []
    
    l = [[] for i in range(len(d))]
    l[0].append(d[0])
    for i in range(1, len(d)):
        for j in range(i):
            if len(l[j]) > len(l[i]) and l[j][-1] < d[i]:               
                l[i] = list(l[j])
        l[i].append(d[i])

    return l

if __name__ == '__main__':
    d = [3,2,4,1,6,7]
    l = lis(d)
    for i in range(len(l)):
        print l[i]
