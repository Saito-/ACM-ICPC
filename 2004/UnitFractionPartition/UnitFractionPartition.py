# coding: utf-8

import sys

if __name__ == '__main__':
	f = open(sys.argv[1], 'r')

	while True:
		line = f.readline()[:-1].split(' ')
		p, q, a, n = line
		p = int(p)
		q = int(q)
		a = int(a)
		n = int(n)
		print p, q, a, n
		if p == 0 and q == 0 and a == 0 and n == 0: break
		div = float(p)/q
		print div
	f.close()
