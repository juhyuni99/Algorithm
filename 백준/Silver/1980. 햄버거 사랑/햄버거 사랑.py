n, m, t = map(int, input().split())

coke = t
sum = 0

for i in range((t//n),-1,-1):
	a = i
	for j in range((t//m), -1, -1):
		b = j
		temp = (n * a) + (m * b)

		if(t-temp)<coke and (t-temp) >= 0:
			sum = a+b
			coke = t-temp
		elif (t-temp)==coke:
			if a+b>sum:
				sum = a+b
				coke = (t-temp)
print(sum, coke)