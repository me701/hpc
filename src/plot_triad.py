import matplotlib.pyplot as plt 
import numpy as np 
from scipy.interpolate import UnivariateSpline
n, c, gflops = np.loadtxt('triad.txt', unpack=True)
spline = UnivariateSpline(n, np.log10(gflops))
#spline.set_smoothing_factor(0.5)
plt.semilogx(n, gflops, 'ko')
#plt.semilogx(n, 10**spline(n), 'k', alpha=0.5)
plt.xlabel('N')
plt.ylabel('GFLOP/S')
plt.show()