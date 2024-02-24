# Using global variable inside a function:

x = "awesome"


def myfunc():
    print("Python is " + x)


myfunc()

# Declaring one global and one local variable with the same name:
x = "awesome"


def myfunc():
    x = "fantastic"
    print("Python is " + x)


myfunc()
print("Python is " + x)


# Declaring a global variable inside the scope of a funtion:


def myfunc():
  global x
  x = "fantastic"

myfunc()

print("Python is " + x)