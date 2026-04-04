# 1. Count the vowels [u,a,e,i,o] contained in string
print("--------------------------------------------------")
string = "Welcome to UAE"
vowels = "aeiou"

count = 0
for char in string.lower():
    if char in vowels:
        count += 1

print("The number of vowels in the string is {}".format(count))

print("--------------------------------------------------")

# 2. Fill an array of 5 elements from the user,
# Sort it in descending and ascending orders then display the output.
arr = []
for i in range(1, 6):                                                               #add + isDigit check 
    par = int(input("Parameter {} : ".format(i)))
    arr.append(par)

print("Ascending:", sorted(arr))
print("Descending:", sorted(arr, reverse=True))

print("--------------------------------------------------")

# 3. Write a program that prints the number of times the string 'iti'
# occurs in any string.
sentence = "Welcome to ITI. ITI stands for Information Technology Institute. The main purpose for which ITI was established..."
occurrence = sentence.lower().count("iti")

print("The ITI occurred {} times".format(occurrence))

print("--------------------------------------------------")

# 4. Write a program that remove all vowels from the input word and
# generate a brief version of it.
word = input("Enter the word: ")                                                #check alpha not numirc
result = ""

for char in word.lower():
    if char not in vowels:
        result += char

print("The word after removing vowels is: {}".format(result))
print("--------------------------------------------------")
