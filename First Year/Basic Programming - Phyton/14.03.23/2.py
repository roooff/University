my_list = input("Enter a list of numbers separated by commas (e.g., 1, 2, 3): ").split(",")

for i in range(len(my_list)):
    my_list[i] = int(my_list[i])

list_length = len(my_list)

for i in range(list_length):
    if i % 2 != 0:
        print(my_list[i])
