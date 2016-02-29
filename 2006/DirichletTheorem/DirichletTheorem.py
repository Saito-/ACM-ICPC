# coding: utf-8

import sys

N = int(10e6)
prime = [0] * N
is_prime = [True]*(N+1)

def Furui(n):
	p = 0
	is_prime[0] = False
	is_prime[1] = False
	for i in xrange(2, n+1):
		if is_prime[i]:
			prime[p] = i
			p += 1
			for j in xrange(2*i, n+1, i):
				is_prime[j] = False
	return p

if __name__ == '__main__':
	f = open(sys.argv[1], 'r')
	Furui(N)

	while True:
		line = f.readline()[:-1].split(' ')
		a, d, n = line
		a = int(a)
		d = int(d)
		n = int(n)
		if a == 0 and d == 0 and n == 0: break
		num = 0
		tmp = a
		while num < n:
			if is_prime[tmp]: num += 1
			tmp += d
		print tmp - d

	f.close()
