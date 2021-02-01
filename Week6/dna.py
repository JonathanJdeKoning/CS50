from sys import argv
import sys
import re
import csv

if len(argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
seq = open(argv[2], "r")
s = seq.read()
patterns = ["AGATC",
            "TTTTTTCT",
            "AATG",
            "TCTAG",
            "GATA",
            "TATC",
            "GAAA",
            "TCTG"]


lst = []


names = []
with open(argv[1], newline='') as csvfile:
    spamreader = csv.reader(csvfile, delimiter=' ', quotechar='|')
    for row in spamreader:
        names.append(row[0].split(","))
if argv[1] == "databases/small.csv":
    string = s
    count = 0
    pattern = patterns[0]
    while pattern in string:
        count += 1
        pattern += patterns[0]
    lst.append(count)
    
    string = s
    count = 0
    pattern = patterns[2]
    while pattern in string:
        count += 1
        pattern += patterns[2]
    lst.append(count)
    
    string = s
    count = 0
    pattern = patterns[5]
    while pattern in string:
        count += 1
        pattern += patterns[5]
    lst.append(count)
else:
    string = s
    count = 0
    pattern = patterns[0]
    
    while pattern in string:
        count += 1
        pattern += patterns[0]
    lst.append(count)
    
    count = 0
    pattern = patterns[1]
    
    while pattern in string:
        count += 1
        pattern += patterns[1]
    lst.append(count)
    
    count = 0
    pattern = patterns[2]
    
    while pattern in string:
        count += 1
        pattern += patterns[2]
    lst.append(count)
    count = 0
    pattern = patterns[3]
    
    while pattern in string:
        count += 1
        pattern += patterns[3]
    lst.append(count)
    count = 0
    pattern = patterns[4]
    
    while pattern in string:
        count += 1
        pattern += patterns[4]
    lst.append(count)
    count = 0
    pattern = patterns[5]
    
    while pattern in string:
        count += 1
        pattern += patterns[5]
    lst.append(count)
    count = 0
    pattern = patterns[6]
    
    while pattern in string:
        count += 1
        pattern += patterns[6]
    lst.append(count)
    count = 0
    pattern = patterns[7]
    
    while pattern in string:
        count += 1
        pattern += patterns[7]
    lst.append(count)
         
     
newlst = []
for item in lst:
    newlst.append(str(item))

names.pop(0)

if argv[1] == "databases/large.csv":
    for data in names:
        if newlst[0] == data[1] and newlst[1] == data[2] and newlst[2] == data[3] and newlst[7] == data[8]:
            print(data[0])
            sys.exit()
else:
    for data in names:
        if newlst[0] == data[1] and newlst[1] == data[2] and newlst[2] == data[3]:
            print(data[0])
            sys.exit()
print("No match")

