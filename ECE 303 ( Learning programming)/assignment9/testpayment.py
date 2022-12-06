#It does not graph the data but, it will print the month you will have enought to own the car
#  and when you have enoght for the down payment.
#I also know what the graph should look like, because I graphed it in excel
import matplotlib.pyplot as plt
def months4car(price, down_payment, monthlysavings, annualreturn):
    month=1
    current_savings=0
    while current_savings<=down_payment:
        current_savings =current_savings+monthlysavings+(current_savings +monthlysavings)*annualreturn/12
        month=month+1
        
    current_savings=current_savings-down_payment
    print(current_savings, month, "For down payment")
    while current_savings<=(price-down_payment):
        current_savings =current_savings+monthlysavings+(current_savings +monthlysavings)*annualreturn/12
        month=month+1 
    plt.plot(month, current_savings, label="current savings")
    plt.legend()
    plt.show() 
    return print(current_savings, month, "For rest of cost of car")
months4car(50000, 10000, 200, 0.04)
