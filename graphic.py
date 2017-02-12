import os
import sys
import matplotlib.pyplot as plt

x = []
y_time = []
y_operation = []

directory = sys.argv[1]

def mean(numbers):
    return float(sum(numbers)) / max(len(numbers), 1)

for fname in sorted(os.listdir(sys.argv[1])):
    times = []
    operations = []

    print fname

    f = open(os.path.join(directory, fname), 'r')
    x.append(int(f.readline())) #len

    for line in f.readlines():
        data = line.split()
        times.append(int(data[0])) #time
        operations.append(float(data[1])) #operations

    f.close()

    y_time.append(mean(times))
    y_operation.append(mean(operations))

plt.title('Sort')

plt.subplot(2, 1, 1, aspect='equal')
plt.plot(x, y_time, 'b.-')
plt.xlabel('len')
plt.ylabel('time')

plt.subplot(2, 1, 2)
plt.plot(x, y_operation, 'r.-')
plt.xlabel('len')
plt.ylabel('operations')

plt.show()
