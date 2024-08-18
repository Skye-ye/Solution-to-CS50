from pyfiglet import Figlet
import sys
import random

figlet = Figlet()
if len(sys.argv) == 1:
    figlet.setFont(font = random.choice(figlet.getFonts()))
elif len(sys.argv) == 3 and (sys.argv[1] in ["-f", "-font"]) and (sys.argv[2] in figlet.getFonts()):
    figlet.setFont(font = sys.argv[2])
else:
    print("Invalid Commandline Arguments!")
    sys.exit(1)

word = input("Input: ")
print(f"{figlet.renderText(word)}")
sys.exit(0)