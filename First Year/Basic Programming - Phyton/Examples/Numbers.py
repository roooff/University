x = 1    # int
y = 2.8  # float
z = 1j   # complex
print(x)
# Getting the types of the variables:
print(type(x))
print(y)
print(type(y))
print(z)
print(type(z))

# Only ints:
x = 1
y = 35656222554887711
z = -3255522

print(type(x))
print(type(y))
print(type(z))
# Only Floats:
x = 1.10
y = 1.0
z = -35.59

print(type(x))
print(type(y))
print(type(z))
# Float also represents scientific numbers too:
x = 35e3
y = 12E4
z = -87.7e100

print(type(x))
print(type(y))
print(type(z))

# Complex numbers: Where j is the imaginary part: 
x = 3+5j
y = 5j
z = -5j

print(type(x))
print(type(y))
print(type(z))
