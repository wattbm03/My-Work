import pandas as pd
import matplotlib.pyplot as plt

def covid():
    t=("https://raw.githubusercontent.com/owid/covid-19-data/master/public/data/latest/owid-covid-latest.csv")
    df=pd.read_csv(t, index_col=0, parse_dates=True)
    df = df.sort_values(by='total_cases', ascending=False)
    ax = df['total_cases'].head(10).plot(title='Total Covid Cases',kind='bar')
    ax.set_xlabel('location',fontsize=12)
    ax.set_ylabel('total_cases',fontsize=12)
    plt.show()
def us():
    t=("https://raw.githubusercontent.com/nytimes/covid-19-data/master/rolling-averages/us.csv")
    df=pd.read_csv(t, index_col=0, parse_dates=True)
    ax = df['2020-01-21':'2021-10-31'].plot(y='cases',title='US Covid Cases', legend=False, kind='line')
    ax.set_xlabel('date', fontsize=12)
    ax.set_ylabel('cases', fontsize=12)

    plt.show()
covid()
us()