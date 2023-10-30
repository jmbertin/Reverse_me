# level1

## Overview
This program is a straightforward password checker that prompts the user for a key. If the provided key matches the hardcoded value __stack_check, a success message is displayed. If not, a failure message is shown.

## How the Program Works
- The program prompts the user with the message "Please enter key: ".
- The user's input is read and compared to the hardcoded password: __stack_check.
- If the user's input matches this hardcoded value, the success message "Good job." is displayed. Otherwise, the message "Nope." is shown.

## How to Determine the Correct Password
Given that the password is hardcoded in the source code itself, the correct password is simply __stack_check.

----

## How to patch

1. Copy the binary inside the folder

2. Launch the script

``python3 patch.py``

### Patch explaination

We have to replace the check :
````
0x00001241 <+129>:   cmp    eax,0x0
0x00001244 <+132>:   jne    0x1260 <main+160>
````
**83 F8 00 0F 85 16 00 00 00**
83 = cmp
F8 = eac
00 = 0x0
0F 85 = jne
16 00 00 00 = 0x16 in little endian

by NOP to remove it :
````
    0x1241: b"\x90\x90\x90\x90\x90\x90\x90\x90\x90",
````
**90 90 90 90 90 90 90 90 90**
CMP (1 byte) + EAX (1 byte) + 0x0 (1 byte) + JNE (2 bytes) + adress (4 bytes)
