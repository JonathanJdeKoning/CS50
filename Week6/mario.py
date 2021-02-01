from cs50 import get_int
while(True):
    h = get_int("Height: ")
    if (h > 0 and h < 9):
        break
k = h - 1
c = 1
for i in range(h):
    print(" " * k + "#" * c + "  " + "#" * c)
    k -= 1
    c += 1