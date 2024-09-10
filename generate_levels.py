import random

n = 100

fruits = ["BANANA", "ORANGE", "COCONUT", "APPLE"]


def printOne(f, t):
    ss = '{' + str(t) + ',' + f  + '},'
    print(ss)

print('{')
ft = 0
for i in range(n):
    ft += random.randrange(0, 5)

    printOne(fruits[random.randrange(0, 4)], ft)
print('}')