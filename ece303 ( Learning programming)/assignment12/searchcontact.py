from urllib.request import urlopen
from urllib.request import Request
import re 
def search(f):
    j = urlopen(f).read().decode('utf8')
    p=re.compile(r'\d\d\d-\d\d\d-\d\d\d\d')
    w=re.compile(r'^[A-Za-z0-9]+[\._]?[A-Za-z0-9]+[@]+[A-Za-z0-9]+[\._]?[A-Za-z0-9]+[.]\w{2,4}$')
    print(p.findall(j))
    print(w.findall(j))#works when you add singilar emails throught it but not from the website read.
search("https://www.pfw.edu/offices/information-technology-services/about/contact")