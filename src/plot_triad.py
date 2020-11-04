import matplotlib.pyplot as plt 
import numpy as np 
n, c, mflops = np.loadtxt('triad.out', unpack=True)
plt.semilogx(n, mflops, 'k')
plt.xlabel('N')
plt.ylabel('GFLOP/S')
plt.show()