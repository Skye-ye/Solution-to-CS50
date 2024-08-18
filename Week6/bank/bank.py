from cs50 import get_string
greet = get_string("Greeting:")
if greet.lower().startswith("hello"):
    print("$0")
elif greet.lower().startswith("h"):
    print("$20")
else:
    print("$100")