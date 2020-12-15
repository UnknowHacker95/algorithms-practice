import matplotlib.pyplot as plt
x = [i for i in range(0,100)]
y = list(map(int, input().split()))
y1 = y[0:100]
y2 = y[100:200]
y3 = y[200:300]
y4 = y[300:400]

plt.plot(x, y1, '*-m', label="sort", lw=2, mec='b', mew=1, ms=0.5)
plt.plot(x, y2, '*-c', label="quick", mec='r', lw=2, mew=1, ms=0.5)
plt.plot(x, y3, '*-k', label="heap", mec='b', lw=2, mew=1, ms=0.5)
plt.plot(x, y4, '*-b', label="intro", mec='r', lw=2, mew=1, ms=0.5)
plt.legend()
plt.grid(True)
plt.show()