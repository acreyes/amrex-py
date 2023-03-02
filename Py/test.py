from build.Units import *

class test(Units):
    def Init(self):
        print ("hey there from test")

t = test()
t.Init()
b = Units()
b.Init()