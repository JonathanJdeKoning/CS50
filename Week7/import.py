from cs50 import SQL
from sys import argv
from sys import exit
import csv

db = SQL("sqlite:///students.db")
# Check for correct usage
    
    
with open(argv[1], "r") as characters: 
    
    reader = csv.DictReader(characters)
    
    for row in reader:
        name = row["name"]
        
        name = name.split()
        if len(name) == 2:
            first = name[0]
            middle = None
            last = name[1]
        else:
            first = name[0]
            middle = name[1]
            last = name[2]
        
        house = row["house"]
        birth = row["birth"]
        db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?,?,?,?,?)",
                   first, middle, last, house, birth)
        