import matplotlib.pyplot as plt
import numpy as np
from scipy.stats import binom
def f(j):
    b=binom(n=20,p=0.5)
    b.rvs(size=j)
    q=b.rvs(size=j)
    bin=np.arange(0, 20, 1)
    a=binom(n=20,p=0.7)
    a.rvs(size=j)
    c=binom(n=40,p=0.5)
    c.rvs(size=j)
    cin=np.arange(0, 40, 1)
    plt.figure(1)
    plt.hist(q, bins=bin, density=True, label="amount in data")
    plt.plot(bin, b.pmf(bin), label="PMF")
    plt.legend()
    plt.title("Histogram")
    plt.xlabel("Frozen values")
    plt.ylabel("Density")
    plt.show()

    plt.figure(2)
    plt.scatter(bin, b.pmf(bin), label="n=20 p=0.5")
    plt.scatter(bin, a.pmf(bin), label="n=20 p=0.7")
    plt.scatter(cin, c.pmf(cin), label="n=40 p=0.5")
    plt.title("Scatter of 3 Paramiters")
    plt.legend()
    plt.xlabel("Frozen values")
    plt.ylabel("Density")
    plt.show()
    return 0
f(1000)
