from cs50 import get_float
while (True):
    raw = get_float("Change owed: ")
    if raw > 0:
        break

coins = 0
step = raw * 100
change = round(step)
while change >= 25:
    change -= 25
    coins += 1
    
while change >= 10:
    change -= 10
    coins += 1
    
while change >= 5:
    change -= 5
    coins += 1
    
while change >= 1:
    change -= 1
    coins += 1
print(coins)