import re
import random

d = 0

f = open('alice_in_wonderland.txt', 'r')
fileText = f.read()

fileText, n = re.subn("[,!,?,`,.,`,0,1,2,3,4,5,6,7,8,9,-,(,),',:,;,*,]", ' ', fileText)
fileText, n = re.subn('[",-]', ' ', fileText)

for i in range(65, 91):
    n = fileText.count(chr(i)) + fileText.count(chr(i + 32))
    d = d + n

for j in range(100):
    random_number = random.randint(0, (d + fileText.count(' ')))

    print(fileText[random_number], end = '')

f.close