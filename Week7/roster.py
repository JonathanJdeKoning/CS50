import sys
from cs50 import SQL

db = SQL("sqlite:///students.db")
houses = db.execute("SELECT first, middle, last, birth FROM students WHERE house = (?) ORDER BY last, first", sys.argv[1])


for row in houses:
    
    if row["middle"] is None:
        
        print(row["first"] + " " + row["last"] + ", born" + " " + str(row["birth"]))
        
    else:
        
        print(row["first"] + " " + row["middle"] + " " + row["last"] + " " + ",born" + " " + str(row["birth"]))