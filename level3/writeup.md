# level3

## Overview
This program challenges the user to input a specific password or key. The correct password begins with the characters "42" and has subsequent characters that decode to the ASCII value of the character '*'.

## How the Program Works
- The program asks the user to input a password with the message: "Please enter key: ".
- The initial two characters of the password should be '4' and '2'.
- Following these characters, the password is decoded in groups of three characters. Each group of three characters is converted to an integer which is then cast to a character.
- The resulting sequence of characters is matched against a pre-defined pattern of eight '*' characters.
- If the sequence matches the pattern, the program prints "Good job.". Otherwise, it prints "Nope." and exits.

## How to Find the Correct Password
- The password must start with the characters "42".
- To identify the complete password, you have to determine the groups of three characters that, when converted to integers, generate the characters of the pattern "********".
- The character '*' is represented as 042 in this challenge.
- The password you're aiming for is: **42042042042042042042042**

## Hint
Each character after the "42" prefix is represented in the form of a three-digit ASCII value in the password. Given that '*' = 042, your goal is to find the sequence that matches a string made up of '*' characters.

----

## How to patch

1. Copy the binary inside the folder

2. Launch the script

``python3 patch.py``

### Patch explaination

We have to replace the first check :
````
   0x000000000000135a <+58>:    je     0x1365 <main+69>
````
**0F 84 05 00 00 00**
0F 84 = je
05 00 00 00 = 0x05 in little endian

by a jmp to go here :
````
   0x000000000000155e <+574>:   call   0x1300 <____syscall_malloc>
````
**E9 FF 01 00 00 00**
E9 = jmp
0x000000000000135a + 5 (bytes for the jmp instruction) = 0x000000000000135f
0x000000000000155e - 0x000000000000135f = 0x1FF = FF 01 00 00 00 in little endian.
