import sys
with open(sys.argv[1], 'r') as file:
	while True:
		line = file.readline()
		n, r = line.split(' ')
		n = int(n)
		r = int(r)
		if n == 0 and r == 0:
			sys.exit()
		hanafuda = range(n, 0, -1)
		for i in range(r):
			line = file.readline()
			p, c = line.split(' ')
			p = int(p)
			c = int(c)
			fuda_p = hanafuda[:p-1]
			fuda_c = hanafuda[p-1:p+c-1]
			for j in range(c):
				hanafuda[j] = fuda_c[j]
			for j in range(p-1):
				hanafuda[j+c] = fuda_p[j]
		print hanafuda[0]
