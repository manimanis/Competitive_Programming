clavier = input()
mot = input()
s = 0
lastpos = -1
for c in mot:
    pos = clavier.find(c)
    if (lastpos == -1):
        lastpos = pos
    s += abs(pos-lastpos)
    lastpos = pos
print(s)
