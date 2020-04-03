from random import randint
casos = int(input())

for x in range(casos):
    vacio = randint(1, 20)
    day = int(input())
    nxt = 1
    chabon = 100
    while day != 100:
        if nxt == 20:
            chabon -= 1
            nxt = 1
        print ("{} {}".format(nxt if nxt != vacio else 20, chabon))
        nxt += 1
        day = int(input())

    print("{} 100".format(vacio))