import re

f = open('alice_in_wonderland.txt', 'r')
fileText = f.read()

fileText, n = re.subn("[,!,?,`,.,`,0,1,2,3,4,5,6,7,8,9,-,(,),',:,;,*,]", ' ', fileText)
fileText, n = re.subn('[",-]', ' ', fileText)

characters = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']

print('space' + ' : ' + str(fileText.count(' ')))

for i in range(65, 91):
    print(characters[i-65] + ' : ', end = '')
    print(fileText.count(chr(i)) + fileText.count(chr(i + 32)))

f.close