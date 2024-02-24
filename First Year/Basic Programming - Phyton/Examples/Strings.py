# String replacement:
a = "Hello, World!"
print(a.replace("H", "J"))

# Split string:
a = "Hello, World!"
print(a.split(",")) # returns ['Hello', ' World!']

# Concatenation:
a = "Hello"
b = "World"
c = a + b
print(c)

# String formatting:
age = 36
txt = "My name is John, and I am {}"
print(txt.format(age))

# Slicing strings:
b = "Hello, World!"
print(b[2:5])


# Cases:
# Upper:
a = "Hello, World!"
print(a.upper())
# Lower:
a = "Hello, World!"
print(a.lower())


# Removing whitespaces:
a = " Hello, World! "
print(a.strip())

# Average string
print("Hello World!")

# Multiple strings:
a = """Lorem ipsum dolor sit amet,
consectetur adipiscing elit,
sed do eiusmod tempor incididunt
ut labore et dolore magna aliqua."""
print(a)
# Single quotes:
a = '''Lorem ipsum dolor sit amet,
consectetur adipiscing elit,
sed do eiusmod tempor incididunt
ut labore et dolore magna aliqua.'''
print(a)

