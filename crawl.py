import requests
import re
import string
from itertools import permutations

imWrong = "<p style=\"text-align:center;color:red\"><strong>Incorrect Password</strong></font></p>"

# r = requests.post("http://bitwixt.com/jsite/dashboard-worksheets", \
# 	data={"password": attempt})

# if(re.search(imWrong, r.text)):
# 	print("wrong")
# else:
# 	print("HOLY SHIT")

# allChars = ["0","1","2","3","4","5","6","7","8","9","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","!","\"","#","$","%","&"]
# result = permutations(allChars, 4)
# print(list(result))

print(string.printable)