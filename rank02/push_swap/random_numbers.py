import random
import sys

size = int(sys.argv[1])
liste = []

for i in range(size + 1):
	nb = random.randint(-4 * size, 4 * size)
	while (str(nb) in liste):
		nb = random.randint(-4 * size, 4 * size)
	liste.append(str(nb))
print(f"\"{' '.join(liste)}\"")

