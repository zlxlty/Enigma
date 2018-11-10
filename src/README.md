Enigma
======

## Content
* [Environment](#environment)
* [Instruction](#instruction)
    * Basic Function
    * Special Feature
    * Reminder
* [Hello_World](#hello_world)
* [verify](#verify)
* [txttodic](#txttodic)

***
## Environment
* For `Windows` 7+ **ONLY**
* `DEV C++` 5.11(for editing)
If you haven't installed DEV C++ on your computer, here is the URL link to [Download DEV C++](https://sourceforge.net/projects/orwelldevcpp)

***
## Instruction
### Basic Function
To use the `Enigma simulator`, you just have to `double click` the `Enigma.exe`  
A terminal-like window will appear with output as followed:
```
ENIGMA MACHINE

Enter the Sequnce of the Rotor:
```
As most of other ciphers, `Enigma` requires key to encrypt and and decrypt messages  
I am simulating an early version of `Enigma` which has three keys:
* The Sequence of `Rotors`: A **three-digit number** made up of `1` `2` `3`
* The initial position of each `Rotor`: **Three English letters**
* The settings of `Plugboard`: **Six pairs of letters**

There is no need for you to know all the theories and processes behind the mechanism of `Enigma Machine`. If you are interested, you can go to [this website](http://enigma.louisedade.co.uk/howitworks.html) for more information

  <img width="150" height="150" src="https://github.com/zlxlty/Enigma/tree/master/pic/pic1.png"/>
  ![image](https://github.com/zlxlty/Enigma/tree/master/pic/pic1.png)
This is a sample setting for `Enigma Machine`. You can use any valid combination you like.  
After entering the keys, the arrangements of all the `Rotors` will be printed on the window:

  <img width="150" height="150" src="https://github.com/zlxlty/Enigma/tree/master/pic/pic2.png"/>
  ![image](https://github.com/zlxlty/Enigma/tree/master/pic/pic2.png)
This is just for visual effect and debug. You can simply ignore it.
```
Enter the Mode(E or D):
```
There are two mode to chose from:  
* **`Mode E`** means en/decrypting only one letter at a time, making it more realistic comparing with the real machine.
![image]()
* **`Mode D`** means en/decrypting one sentence at a time. However, all the `rotors` will return to their original states once a sentence is en/decrepted.

The program will then ask students to fill in their **name**, **email** and **grade** for registration.  
Here is an example:
```
Enter your first name:	tianyi

Enter your last name:	lu

	 0 people have already signed in.

Enter your Email:	tylu17@uwcchina.org

Enter your Grade (FP or DP1 or DP2):	dp1

THANK YOU!
```

***
### Special Feature
* **SPACE** `''` will be identified as invalid input
```
Enter your first name:

Enter your first name:

Enter your first name:

Enter your first name:

Enter your first name:

Enter your first name:
```
* **Name repetition** can be detected by comparing with names in `data.txt`
```
Enter your first name:	tianyi

Enter your last name:	lu

You have already signed in!
```
* Only **UWC School Email** that end with `uwcchina.org` can be accepted
```
Enter your Email:	2924312854@qq.com

Please Enter the CORRECT school Email!
```
* **Expired** school email is invalid
```
Enter your Email:	tylu15@uwcchina.org

Email expired!
```
* Grade other than **`FP`**, **`DP1`** or **`DP2`** is invalid
```
Enter your Grade (FP or DP1 or DP2):	dp4

Please enter the CORRECT Grade!
```

***
### Reminder
* For students who are not familiar with terminal operation, please remind them to press **`Enter`** every time they finish typing.
* The number of students in `data.txt` and `members.txt` must be the same.

***
## Hello_World
`Hello_World.py` program is used for registering people who are interested to join this zhixing.  
I will explain `classes` and `functions` in this file respectively
```python
class CODE_with_UWC(object):
    def __init__(self):
        pass
    def mission(self):
        pass
```
The only application of this `class` is to print the mission of this zhixing

```python
def name_repetition(fname, lname, members, index):
    pass
```
This function will check whether the name input is in `memebers.txt` already  
if the name dose repeat, the function will return **`TRUE`**, otherwise it will return **`FALSE`**

```python
def clear():
    pass
```
Once a student finish all the inputs, this function will be used to clear the terminal  
All the information will be temporarily stored in a `list` of `dictionaries`. Then, those `dictionaries` will be `serialize` by `json` and stored in `data.txt`

***
## verify
`verify.py` includes many functions that are used to validate user's input such as `first name`, `last name`, `email` and `grade`.

```python
def verifyed_fname():
    pass
def verifyed_lname():
    pass
```
Those two functions will return verified names if the input is not `''` or `'\n'`

```python
def verifyed_email():
    pass
```
This function only return valid email address if and only if the address end with `uwcchina.org` and the year number is in `16`, `17`, `18`  
```python
m = re.match(r'^\w+?(\d{2})@uwcchina\.org$', email)
```
`Regular Expressions` is used to comparing the `expressions` with the `input`

```python
def verifyed_grade():
    pass
```
It will only return one of the valid grades in UWCCSC

## txttodic
```Python
import json

def getdata(filename):

    members = []
    with open(filename, 'r') as f:
        for line in f.readlines():
            dic = json.loads(line)
            members.append(dic)

    return members
```
This function can transform serialized content in `data.txt` to a list of dictionaries

***
The results will be recorded in `members.txt` so that my girlfriend can make an Excel sheet out of it conveniently  

****

|Author|SkyL|
|---|---
|E-mail|2924312854@qq.com


****


Introduction:
-------------
  This is a simulator of Enigma machine which is a kind of cipher ued by Germany army in the WW2.

Instruction:
-------------
  I will use an example to show how this program work.
  Firstly, we enter every components of the key. In this case they are `123` (the rotor sequence) `TIP` (the rotors` starting positions) and six pair of random letters. On the console interface, the inputs are operated as followed

  <img width="150" height="150" src="https://github.com/zlxlty/Enigma/blob/master/pic1.png"/>
  ![image](https://github.com/zlxlty/Enigma/blob/master/pic1.png)

  Then the corresponding rotor settings will be automatically printed

  <img width="150" height="150" src="https://github.com/zlxlty/Enigma/blob/master/pic2.png"/>
  ![image](https://github.com/zlxlty/Enigma/blob/master/pic2.png)

  After that, we need to enter the letter of `plaintext` (HELLOWORLD) one by one and ciphertext will be printed in the following position.

  <img width="150" height="150" src="https://github.com/zlxlty/Enigma/blob/master/pic3.png"/>
  <img width="150" height="150" src="https://github.com/zlxlty/Enigma/blob/master/pic4.png"/>
  ![image](https://github.com/zlxlty/Enigma/blob/master/pic3.png)
  ![image](https://github.com/zlxlty/Enigma/blob/master/pic4.png)

  Finally, we end the input with the symbol '-' and the complete plaintext and ciphertext will be shown again.

  <img width="150" height="150" src="https://github.com/zlxlty/Enigma/blob/master/pic5.png"/>
  ![image](https://github.com/zlxlty/Enigma/blob/master/pic5.png)

  Reminding that all the letters must be `capitalized` and space is `not` accepted.

  We can also check whether the encryption is right by using the same key to encrypt the ciphertext we got previously.

  <img width="150" height="150" src="https://github.com/zlxlty/Enigma/blob/master/pic6.png"/>
  ![image](https://github.com/zlxlty/Enigma/blob/master/pic6.png)
