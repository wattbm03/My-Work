import numpy as np
def f(x, coef):
    j=np.cumprod(coef)
    k=np.multiply(j,x)
    k[0]=j[0]
    y=np.sum(k)
    return y
print(f(2.0, [1, 2, 3]))