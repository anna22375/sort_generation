import numpy as np
import matplotlib.pyplot as plt

x = [100, 1000, 10000, 20000]
y_time = []
y_operation = []

for i in x:
    times = []
    operations = []

    f = open(str(i) + '.txt', 'r')

    for line in f:
        data = line.split()
        times.append(int(data[0]))
        operations.append(int(data[1]) + int(data[2]))
    
    y_time.append(np.mean(times))
    y_operation.append(np.mean(operations))


print y_time
print y_operation

plt.title('Sort')

plt.subplot(2, 1, 1, aspect='equal')
plt.plot(x, y_time, 'b.-')
plt.xlabel('len')
plt.ylabel('time')

plt.subplot(2, 1, 2, aspect='equal')
plt.plot(x, y_operation, 'r.-')
plt.xlabel('len')
plt.ylabel('operations')

plt.show()
