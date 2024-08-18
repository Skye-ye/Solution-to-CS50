from cs50 import SQL

db = SQL("sqlite:///favorites.db")

favorite = input("Favorite:")

rows = db.execute("select count(*) as n from favorites where problem = ?", favorite)
row = rows[0]
print(row["n"])
