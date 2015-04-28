# Longest common subsequence using dynamic programming
def lcs(N, M):
    # creates M*N matrix
    lcs = [[0 for i in range(len(N) + 1)] for j in range(len(M) + 1)]
    #initial conditions
    
    for i in range(len(M)):
        for j in range(len(N)):
            if M[i] == N[j]:
                lcs[i+1][j+1] = 1 + lcs[i][j]
            else:
                lcs[i+1][j+1] = max(
                    lcs[i+1][j],
                    lcs[i][j+1])

    return lcs[len(M)][len(N)]

if __name__ == '__main__':
    print lcs('AGGTAB', 'GXTXAYB')
