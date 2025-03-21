# print("hello")
# print("hello")
# print("hello")
# print("hello")
# print("hello")
#print("thj","hello",sep='|',end='~')
#print()
#可以多次对同一变量赋值，且数据类型可以不一样；
"""
a=10
print(a)
a=11.5
print(a)
a="啊哈哈哈"
print(a)
#if=100错误
print(type(a))
print(True+2)
z=2+6j
print(type(z))
str="tthhjj"
print("我的名字：%s"%str)
age=18.8
print("姓名：%s  年龄：%f"%(str,age))
print("%7.3f"%age)
print(f"我的名字是{str}，年龄{age}")
print(r"hello\tthj")
i=10
while(i>0):
    print("%d\t"%i)
    i-=1
print("%d",i)
for i in str:
    print(i)
for i in range(0,10,3):
    print(i)
#计算1-100之和：
sum=0
for i in range(1,101,1):
    sum+=i
print(sum)
"""
#字符串解码编码
"""
str="你"
str1=str.encode("utf-8")
print(str1)
str2=str1.decode("utf-8")
print(str2)
"""
#字符串切片
"""str="abcdefgh"
print(str[0:3])
print(str[-1:-4:-1])"""
#切割字符串
#str="hellopython"
#print(str.split('o',1))
#import time
"""
def outer(fn):
    def inner(*args):
        print("登录\n")
        fn(args)
    return inner

def send(*args):
    print("发送消息给%s"%args)
"""


"""
@outer
def send(name):
    print("发送消息给%s"%name)
send("thj")
"""
#ot=outer(send)
#ot('thj','ywj')
"""
class monkey:
    color=""
    age=0
    def eat(self):
        print("i can eat")
        print(self)

mon1=monkey()
mon1.sex="雄性"#实例化属性
mon1.eat()
print(monkey.age)
#print(monkey.sex)类名不可访问
print(mon1.sex)

"""

"""
class Person:
    nation=""
    def __init__(self,nat,name,age):
        print("我是构造函数")
        self.nation="nat"
        self.name=name
        self.age=age
p1=Person("china","thj",18)
print(p1.nation,p1.name,p1.age)

"""
"""
class Person:
    name=""
    __age=18
    def __init__(self,name,age):
        self.name=name
        Person.__age=age
    def introduce(self):
        print("%s的年纪是%d"%(self.name,Person.__age))
p1=Person("thj",19)
print(p1._Person__age)#非正常访问私有变量
p1.introduce()#通过行为正常访问私有变量

"""
"""
class Person:
    nation="china"
    def __init__(self,name,age):
        self.name=name
        self.age=age

p1=Person("thj",19)
p2=Person("wsy",49)
p1.sex="男"
p1.nation="USA"
print(p1.nation,p1.name,p1.age,p1.sex)
print(p2.nation,p2.name,p2.age)
Person.nation="RUSS"
print(p1.nation,p1.name,p1.age,p1.sex)
print(p2.nation,p2.name,p2.age)

"""




"""
class Person:
    add=None
    nation="china"
    # 重写__new__实现单例方法
    def __new__(cls):
        print("这里是——new——方法")
        if cls.add == None:
            cls.add = object.__new__(cls)
            return cls.add
        else:
            return cls.add

p1=Person()
print(p1)
p2=Person()
print(p1)


"""


"""
f=open("test.txt","a+")
f.write("\nhello world")
pos=f.tell()
print("当前指针位置：%d"%pos)
f.seek(0,0)
pos=f.tell()
print("移动后指针位置：%d"%pos)
print(f.read())
f.close()
"""




"""
with open("test.txt","w+") as f:
    f.write("hello fucker")
    f.seek(0,0)
    print(f.closed)
    print(f.read())
print(f.closed)

 
"""





"""
f=open("C:\\Users\\tangh\\Pictures\\pic.jpg","rb")
pic=f.read()
f.close()
f=open("pic.jpg","wb")
f.write(pic)
f.close()

"""


L=[1,2,3,4,5]
it=L.__iter__()
print(it.__next__())
print("thj")






