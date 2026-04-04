#write a program that build a mario pyramid like below:
#without loop: 

num = int(input('enter the levels of the pyramid: '))

print("*" * 1)
print("*" * 2)
print("*" * 3)
print("*" * num)





#write a program that prints the locations of 'i' character in any string ypu added

#without loop:
string = input("Enter a string: ")

loc1 = string.find('i')
loc2 = string.find('i', loc1 + 1)
loc3 = string.find('i', loc2 + 1)
loc4 = string.find('i', loc3 + 1)
loc5 = string.find('i', loc4 + 1)

print("The character 'i' is found at indexes: {} {} {} {} {}".format(loc1, loc2, loc3, loc4, loc5))

#with loop
string = input("Enter a string: ")

locations = []
loc = string.find('i')

while loc != -1:
    locations.append(loc)
    loc = string.find('i', loc + 1)

print("The character 'i' is found at indexes: {}".format(locations))
