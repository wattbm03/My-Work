#code written by Breeanna Watters undergrad student
#perceptron

#mike did help with lines 49 to 62 about after comments might change


import matplotlib.pyplot as plt
import numpy as np
import random
from sklearn.model_selection import train_test_split

#does the code to use peceptron
class Perceptron:
    
    def __init__(self, 
                 weights,
                 learning_rate):
        self.weights = np.array(weights)
        self.learning_rate = learning_rate
    def unit_step_function(x):
        if  x < 0:
            return 0
        else:
            return 1
    def __call__(self, in_data):
        weighted_input = self.weights * in_data
        weighted_sum = weighted_input.sum()
        return Perceptron.unit_step_function(weighted_sum)
    
    def adjust(self, 
               target_result, 
               calculated_result,
               in_data):
        if type(in_data) != np.ndarray:
            in_data = np.array(in_data)  
        error = target_result - calculated_result
        if error != 0:
            correction = error * in_data * self.learning_rate
            self.weights += correction
            
#sets constants to use            
n = 400
j= 200
x = 0
y = 0
z = 1
u= (10-3*x)/4
Numbers1 = [None]*j
Numbers2 = [None]*j

#make positive rand vaiables
for inc in range(0,200):
    x = random.random() * (10/3)
    y =u
    x = x + random.random()*3
    y = y + random.random()*3
    Numbers1[inc] = [x, y, 1, 0]
    
#makes the negative version 
for inc in range(0,200):
    x = random.random() * (10/3)
    y =u
    x = x - random.random()*3
    y = y - random.random()*3
    Numbers2[inc] = [x, y, -1, 0]

#to have a data set with data got
labelled_data = list(zip(Numbers1[inc]+Numbers2[inc],[0] * 200 + [1] * 200))

#sets variables to some thing
data, labels = zip(*labelled_data)
 

#used for train perceptron, did not work the best   
res = train_test_split(data, labels, 
                       train_size=0.5,
                       test_size=0.5,
                       random_state=5)
train_data, test_data, train_labels, test_labels = res
p = Perceptron(weights=[0.8, 0.3],
               learning_rate=0.5)

for index in range(len(train_data)):
    p.adjust(train_labels[index], 
             p(train_data[index]), 
             train_data[index])

#makes final slope
w1 = p.weights[0]
w2 = p.weights[1]
m = (-1)*w1 / w2
print(w1, w2, m)             


#x cords size
X = np.arange(-4, 7)
a=np.linspace(-4,7,100)
#what y is
b=(10-3*a)/4
fig, ax = plt.subplots()
#plots the scatter plot points
for inc in range(0,200):
    Temp = Numbers1[inc]
    plt.scatter(Temp[0], Temp[1], marker = "+", c = 'purple')  
for inc in range(0,200):
    Temp = Numbers2[inc]
    plt.scatter(Temp[0], Temp[1], marker =  ".", c = 'orange') 
#plots the thin red line for starter equation
ax.plot(a,b, c='red', label="Initial", linewidth=.4)
#does the final one
ax.plot(X, m * X, c='red',label="Final", linewidth=.8)
#done to make dotted itermidiate steps   
s=Numbers1[0]
w=Numbers1[1]
c, d= np.polyfit(s,w , deg=1)
ax.plot(a, c*a+d, c='yellow', marker=".", linewidth=.2, label="Purple Data")

n=Numbers2[0]
c=Numbers2[1]
e, f= np.polyfit(n,c, deg=1)

ax.plot(a, e*a+f, c='green', marker=".", linewidth=.2, label="Orange Data")           
plt.legend()
plt.show()
