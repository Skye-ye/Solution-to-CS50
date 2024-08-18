def is_number(s):
    try:
        int(s)
        return True
    except ValueError:
        return False

while True:
    height = input("Height: ")
    if is_number(height) and int(height) in range(1,9):
        height = int(height)
        break    
for i in range(height):
    print(" " * (height - i - 1), end="")
    print("#" * (i + 1))