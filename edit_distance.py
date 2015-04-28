## Returns the edit distance of two strings

def diff(char1, char2):
    return 0 if char1 == char2 else 1 

def edit_distance(word1, word2):
    subproblems = [[-1 for i in word2] for j in word1]
    
    for i in range(len(word1)):
        subproblems[i][0] = i
    for j in range(len(word2)):
        subproblems[0][j] = j

    for i in range(1, len(word1)):
        for j in range(1, len(word2)):
            subproblems[i][j] = min(
                subproblems[i-1][j] + 1,
                subproblems[i][j-1] + 1,
                subproblems[i-1][j-1] + diff(word1[i], word2[j])
                )

    return subproblems[len(word1) - 1][len(word2) - 1]

def main():
    print edit_distance("exponential", "polynomial")

if __name__ == '__main__':
    main()
