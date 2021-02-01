from cs50 import get_string

l = 0
w = 1
s = 0
p = [".", "?", "!"]
text = get_string("Text: ")

for c in text:
    if c.isalpha():
        l += 1
    if c.isspace():
        w += 1
    if c in p:
        s += 1
if round(0.0588 * ((l / w) * 100) - 0.296 * ((s / w) * 100) - 15.8) > 16:
    print("Grade 16+")
elif round(0.0588 * ((l / w) * 100) - 0.296 * ((s / w) * 100) - 15.8) < 1:
    print("Before Grade 1")
else:
    print("Grade", round((0.0588 * ((l / w) * 100) - 0.296 * ((s / w) * 100) - 15.8)))
    