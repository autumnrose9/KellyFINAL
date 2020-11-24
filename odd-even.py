numbers = [5, 1, 4, 8, 12, 7, 4, 9, 11, 14, 32, 2, 7, 12]
even = []
odd = []
for i in [5, 1, 4, 8, 12, 7, 4, 9, 11, 14, 32, 2, 7, 12]:
	if i%2 == 1:
		odd.append(i)
	else:
		even.append(i)
print "\n"
print "Numbers: ", numbers
print "\n"
print "Even List: ", even
print "\n"
print "Odd List", odd
print "\n"
