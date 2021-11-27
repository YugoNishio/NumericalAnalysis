import re

f = open('alice_in_wonderland.txt', 'r')
fileText = f.read()

fileText, n = re.subn("[,!,?,`,.,`,0,1,2,3,4,5,6,7,8,9,-,(,),',:,;,*,]", ' ', fileText)
fileText, n = re.subn('[",-]', ' ', fileText)

w = open('task_1.txt', 'w')
w.write(fileText)

f.close
w.close