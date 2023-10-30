# level2

## Overview
This program is a simple password checker which expects the user to input a key. The key undergoes a transformation, and if the transformed key matches the hardcoded value "delabere", a success message is displayed; otherwise, a failure message is shown.

## How the Program Works
- The program prompts the user for a key with the message "Please enter key: ".
- The key must satisfy the following criteria:
- The first two characters must be '0'.
- Every subsequent triplet (group of 3 characters) of the key is transformed into a character. Specifically, the triplet is treated as an ASCII integer, and it is converted to its corresponding character.
- The transformed characters are concatenated to form a string. The initial value of this string is "d".
- After the transformation, if the resulting string equals "delabere", the success message "Good job." is displayed. Otherwise, the message "Nope." is shown.

## How to Determine the Correct Password
Given the transformation process:

- The password should start with "00".
- The next parts of the password should be the ASCII values of the characters of the string "elabere", because the initial character is already 'd'.

For example, the ASCII value of 'e' is 101. So the next part of the password should be 101. Similarly, for 'l', it's 108, and so on.

By following this pattern, the complete password is derived as **00101108097098101114101**.

----

## How to patch

1. Copy the binary inside the folder

2. Launch the script

``python3 patch.py``

### Patch explaination

We have to replace the first check :
````
   0x0000131e <+78>:    je     0x132c <main+92>
````
**0F 84 08 00 00 00**
0F 84 = je
08 00 00 00 = 0x08 in little endian

by a jmp to go here (0x158 after the je condition) :
````
   0x00001476 <+422>:   call   0x12a0 <ok>
````

**E9 53 01 00 00 00**
E9 = jmp
0x0000131e + 5 (bytes for the jmp instruction) = 0x00001323
0x00001476 - 0x00001323 = 0x153 = 53 01 00 00 00 in little endian.
