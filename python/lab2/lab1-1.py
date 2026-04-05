'''
helper:

'''
import re,random
def validate_string(prompt):
    while True:
        var = input(prompt)
        if var == "":
            print("enter string value")
        elif var.isnumeric():
            print("entrrr string value")
        else:
            return var
        
def validate_number(prompt):
    while True:
        try:
            var = int(input(prompt))
            return var  
        except ValueError:
            print("Please enter a  number!")
            
def validate_email(email):
    pattern = r'^[\w.-]+@[\w.-]+\.\w{2,}$'
    return re.match(pattern, email)
#====================

'''
function accepts 2 arg to generate
Takes length and start as arguments
Returns a list of numbers starting 
from start, counting up by 1
Example: (4, 3) → [3, 4, 5, 6]
'''

def generate_numbers(len,start):
    arr = []
    for i in range(len):
        arr.append(start+i)
    return arr

#print(generate_numbers(4, 3))  
#print(generate_numbers(5, 99))        

'''
Takes a number
Returns 
"Fizz" if divisible by 3, 
"Buzz" if by 5, 
"FizzBuzz" if by both
'''
def division_game():

    num = validate_number("Enter you Number: ")

    if(num%5 == 0  and num%3 == 0 ):
        print("FizzBuzz")
    elif(num%3 == 0):
        print("Fizz")
    elif (num%5 == 0):
        print("Buzz")
    else:
        print("No place in FizzBuzz game :(")
    
#division_game()

'''
Takes a string input from the user
Returns it reversed
Example: "hello" → "olleh"
'''

def reverse_string():
    str = validate_string("Enter you string: ")
    reversed = str[::-1]
    print("Your reversed string: ", reversed)
    
#reverse_string()

'''
Asks for name → validates it's not empty or a number
Asks for email → prints both
Bonus: checks if the email is valid format (using re module)
'''

def fill_info():
    user_name = validate_string("Enter your name: ")
    while True:
        email = input("Enter your email: ")
        if validate_email(email):
            break
        print("Invalid email!")
    
    print(f"Name  : {user_name}")
    print(f"Email : {email}")
    
#fill_info()

'''
need total, count variables before the loop
continue skips to the next iteration
break exits the loop
average = total / count
'''

def loop_summ():
    total = 0
    count = 0
    while True:
        var = input("Enter number: ")
        if var == "done":
            break
        
        try:
            num = int(var)
            total += num
            count += 1
        except ValueError :
            print ("please enter a number or 'done' ")
            continue
    
    print(f"Total   : {total}")
    print(f"Count   : {count}")
    print(f"Average : {total / count}")

#loop_summ()
    
'''
Start with current = longest = s[0] (first)
Loop from index 1 
— compare each char with the one before it s[i] >= s[i-1] 
    If in order → append to current
    If order breaks → 
            compare current with longest, then reset current
            
After loop → 
    check one last time (most common mistake to forget this)
'''
def longest_alpha(str):
    current = str[0]
    longest = str[0]
    
    for i in range(1, len(str)):
        if str[i] >= str[i-1]: # c > a -> c comes after a -> involved
            current += str[i]
        else:
            if len(current) > len(longest):
                longest = current
            current = str[i]
            
    if len(current) > len(longest):
        longest = current
        
    print("Longest alpha substring is : ",longest )

#longest_alpha("abdulrahman")
#longest_alpha("abcdefgh")
#longest_alpha("zyxw")

'''
hangman::

'''

def hangman_game():
    words = ["python", "lambda", "hangman" ,"variable", "function"]
    #word = random.choice(words)
    word = "python"
    player_name = validate_string("Enter you name: ")
    
    hidden = ["_"] * len(word)
    turns = 7
    guessed = []
    
    print(("Welcome {} , let's play (*_*)").format(player_name))
    print(("The word has {} letters").format(len(word)))
    
    while turns > 0:
        print("Word:    ", " ".join(hidden))
        print("Turns left:", turns)
        print("Guessed: ", guessed)
        
        letter = input("Guess a letter: ").lower()
        if len(letter) != 1 or not letter.isalpha():
            print("please enter a single letter!\n")
            continue
        if letter in guessed:
            print("Foucus it's already gussed")
            continue
        
        guessed.append(letter)
        
        if letter in word:
            for i in range(len(word)):
                if word[i] == letter:
                    hidden[i] = letter
            print(("{} is in the word , you got it Goooo").format(letter))
            if "_" not in hidden:
                print(("Perfect Game {} , you gessed the word:{}").format(player_name,word))
                return
        else:
            turns -= 1
            print(("focus the letter {} is wrong").format(letter))
            
    print(("GAME OVERR!! ,the word was {}").format(word))
    
hangman_game()