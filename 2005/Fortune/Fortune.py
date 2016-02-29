import sys
f = open(sys.argv[1], 'r')
m = int(f.readline()[:-1])
print m
for i in xrange(m):

f.close()
