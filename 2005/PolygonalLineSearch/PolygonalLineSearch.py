# coding: utf-8

import sys

def shift(points):
	new_points = []
	offset_x = points[0][0]
	offset_y = points[0][1]
	m = len(points)
	for i in xrange(m):
		new_x = points[i][0] - offset_x
		new_y = points[i][1] - offset_y
		new_points.append((new_x, new_y))
	return new_points

def rot90(points):
	new_points = []
	m = len(points)
	for i in xrange(m):
		new_x = points[i][1]
		new_y = -points[i][0]
		new_points.append((new_x, new_y))
	return new_points

if __name__ == '__main__':
	f = open(sys.argv[1], 'r')

	while True:
		key = []
		n = int(f.readline()[:-1])
		if n == 0: break
		m = int(f.readline()[:-1])
		for i in xrange(m):
			l = f.readline()[:-1].split(' ')
			x_i, y_i = l
			key.append((int(x_i), int(y_i)))
		key = shift(key)
		for i in xrange(n):
			f.readline()
			points = []
			for j in xrange(m):
				l = f.readline()[:-1].split(' ')
				x_j, y_j = l
				points.append((int(x_j), int(y_j)))
			points = shift(points)
			for j in xrange(4):
				points = rot90(points)
				if key == points:
					print i+1
					break
				points.reverse()
				if key == points:
					print i+1
					break
				points.reverse()
		print '+'*5

	f.close()
