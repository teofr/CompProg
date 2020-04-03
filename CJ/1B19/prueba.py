
n = 0
while (1):
    n = int(input())

    inter = []

    for x in range(1, 7):
        a = (n//x) % 63
        inter.append((a+7, a))
    print(inter)

def isUnique(i, inter):
    i-=1
    for x in range(len(inter)):
        if (i != x and abs(inter[i] - inter[x]) <= 7):
            return False
    return True

for x in range(400):
    for y in range(500):
        covered = [0]*6

        interx = [(x//i)%63 for i in range(1, 7)]
        intery = [(y//i)%63 for i in range(1, 7)]

        for i in range(1, 7):
            if isUnique(i, interx):
                covered[i-1] = 1
            elif isUnique(i, intery):
                covered[i-1] = 2
        vale = True
        for x in covered:
            if x == 0:
                vale = False
        if vale:
            print("x: {} y: {} cov: {}".format(x, y, covered))

