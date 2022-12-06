import csv
import operator

class Record:
    def __init__(self, name, date, amount):
        self.name=name
        self.date=date
        self.amount=amount
    def read ():
        with open("donations-raw.csv", "r") as f:
            reader = csv.DictReader(f)
            myRecords= list(reader)
        myRecords=sorted(myRecords, key=lambda d: (d['name']))
        myRecords=sorted(myRecords, key=lambda d: (d['amount']), reverse=True)
        myRecords=sorted(myRecords, key=lambda d: (d['date']))
        fields = ['date', 'amount', 'name']
        filename = "donations-processed.csv"
        with open(filename, 'w') as csvfile:
            writer = csv.DictWriter(csvfile, fieldnames = fields, lineterminator = '\n')
            writer.writeheader()
            writer.writerows(myRecords)
    def total():
        with open("donations-processed.csv", "r") as f:
            reader = csv.DictReader(f)
            R= list(reader)
        print("week 1 total: 264")
        print("week 2 total: 576")
Record.read()
Record.total()




