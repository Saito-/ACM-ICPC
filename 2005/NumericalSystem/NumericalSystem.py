# coding: utf-8

import sys

nums = '23456789'
chars = 'ixcm'
dic = { 'm':1000, 'c':100, 'x':10, 'i':1 }

f = open(sys.argv[1], "r")

line = f.readline()
n = int(line[:-1])
for i in range(n):
	line = f.readline()
	tokens = line.split()
	a = tokens[0]
	b = tokens[1]
	a_10 = 0
	b_10 = 0
	base = 1
	for ch in a:
		if ch in nums:
			base = int(ch)
		else:
			a_10 += base * dic[ch]
			base = 1
	for ch in b:
		if ch in nums:
			base = int(ch)
		else:
			b_10 += base * dic[ch]
			base = 1
	s = a_10 + b_10
	res = []
	ch = 0
	while True:
		tmp = ''
		quo = s / 10
		rem = s % 10
		if rem != 0:
			if rem != 1:
				tmp += str(rem)
			tmp += chars[ch]
		res.append(tmp)
		ch += 1
		if quo == 0: break
		s = quo
	ans = ''
	for strs in reversed(res):
		ans += strs
	print ans

f.close()
