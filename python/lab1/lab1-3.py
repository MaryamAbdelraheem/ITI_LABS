#0. pyramid:
number = int(input("Enter the number: "))

for i in range(number):
    print(" " * (number - i - 1) + "*" * (i+1))
    
# 1. Locations of 'i' in a string
string = input("Enter a string: ")
print("--------------------------------------------------")

locations = []                         #lowerr
for i in range(len(string)):
    if string[i] == 'i':
        locations.append(i)

print("The character 'i' is found at indexes: {}".format(locations))

print("--------------------------------------------------")

# 2. Multiplication table      checkkk
number = int(input("Enter a number: "))

for i in range(1, 11):
    print("{} x {} = {}".format(number, i, number * i))