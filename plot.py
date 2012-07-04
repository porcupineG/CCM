import numpy as np
import matplotlib
matplotlib.use('QT4Agg')

import matplotlib.pyplot as plt

f = open('y.dat', 'r')
y = [float(x) for x in f.read().split('\n')[0:-1]]
x = np.arange(0, len(y), 1);
print len(y)
plt.plot(x, y)
plt.show()
f.close()

#f = open('in.dat', 'r')
#y = [float(x) for x in f.read().split('\n')[0:-1]]
#x = np.arange(0, len(y), 1);
#print len(y)
#plt.plot(x, y)
#plt.show()
#f.close()

#f = open('qp.dat', 'r')
#y = [float(x) for x in f.read().split('\n')[0:-1]]
#x = np.arange(0, len(y), 1);
#print len(y)
#plt.plot(x, y)
#plt.show()
#f.close()

f = open('x.dat', 'r')
y = [float(x) for x in f.read().split('\n')[0:-1]]
x = np.arange(0, len(y), 1);
print len(y)
plt.plot(x, y)
plt.show()
f.close()