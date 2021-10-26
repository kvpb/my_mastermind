#	My Mastermind

>###	DESCRIPTION
>
>Mastermind is a game composed of 8 pieces of different colors.
>A secret code is then composed of 4 distinct pieces.
>
>The player has 10 attempts to find the secret code.
>After each input, the game indicates to the player the number of well placed pieces and the number of misplaced pieces.
>
>Pieces will be '0' '1' '2' '3' '4' '5' '6' '7'.
>
>If the player finds the code, he wins, and the game stops.
>A misplaced piece is a piece that is present in the secret code butthat is not 
>in a good position.
>
>You must read the player's input from the standard input.
>
>Your program will also receive the following parameters:
>-c [CODE]: specifies the secret code. If no code is specified, a random code 
>will be generated.
>-t [ATTEMPTS]: specifies the number of attempts; by default, the playerhas 10 
>attempts.
>
>**Example 00**
>```
>PROMPT>./my_mastermind -c "0123"
>Will you find the secret code?
>---
>Round 0
>>1456
>Well placed pieces: 0
>Misplaced pieces: 1
>---
>Round 1
>>tata
>Wrong input!
>>4132
>Well placed pieces: 1
>Misplaced pieces: 2
>---
>Round 2
>>0123
>Congratz! You did it!
>```
[https://upskill.us.qwasar.io/projects/my_mastermind](https://upskill.us.qwasar.io/projects/my_mastermind)

---

##	How-to

1.	First spin [some](https://youtu.be/iNLR-EMugb4?t=2940) [real](https://youtu.be/YYkim4Uog1k?t=26) [music](https://youtu.be/RmLYHkqLc0s?t=16).

2.	Launch a terminal emulator, e.g. [Terminator](https://gnome-terminator.org), [iTerm2](https://iterm2.com) or [VS Code's Integrated Terminal](https://code.visualstudio.com/docs/editor/integrated-terminal), and enter this:
```sh
#wd=$(pwd)
#cd
mkdir my_mastermind_32390_2txyp4
cd my_mastermind_32390_2txyp4
git clone https://git.us.qwasar.io/my_mastermind_32390_2txyp4/my_mastermind
cd my_mastermind
make
#cd "${wd}"
```

3.	Run the program, play the game:
```sh
./my_mastermind
```

4.	Then test it, and here are a bunch of test cases:

-	*`-c code` option test cases:*
```sh
./my_mastermind -c 0000 # must work.
```
```sh
./my_mastermind -c 5275 # must work.
```
```sh
./my_mastermind -c # should fail.
```
```sh
./my_mastermind -c 0089 # should fail.
```
```sh
./my_mastermind -c 00FF # should fail.
```
```sh
./my_mastermind -c 0 # should fail.
```
```sh
./my_mastermind -c A # should fail.
```

-	*`-t attempts` option test cases:*
```sh
./my_mastermind -t 10 # must work.
```
```sh
./my_mastermind -t 1 # must work.
```
```sh
./my_mastermind -t 2147483647 # must work.
```
```sh
./my_mastermind -t # should fail.
```
```sh
./my_mastermind -t 0 # should fail.
```
```sh
./my_mastermind -t -1 # should fail.
```
```sh
./my_mastermind -t FF # should fail.
```
```sh
./my_mastermind -t Z # should fail.
```

-	*`-c code` and `-t attempts` options test cases:*
```sh
./my_mastermind -c 0000 -t 10 # must work.
```
```sh
./my_mastermind -c 5275 -t 7 # must work.
```
```sh
./my_mastermind -t 13 -c 0666 # must work.
```
```sh
./my_mastermind -t 2147483647 -c 0255 # must work.
```
```sh
./my_mastermind -c  -t  # should fail.
```
```sh
./my_mastermind -c 5872 -t 13 # should fail.
```
```sh
./my_mastermind -c 0000 -t 10 AV5 # should fail.
```

---

<p align='center'><a href='https://upskill.us.qwasar.io/users/bertin_k'><img src='https://gist.githack.com/kvpb/bfed748ac5c509985c89ea613a2bfd02/raw/8c0b311b7c848fabddf61672ba6bb72c8754fed9/karlbertinssymbol.svg'></a><br>
<b>Karl V. P. B. `<code>kvpb</code>`</b><br>
<br>
<span style="display:block;text-align:center"><a href='https://www.linkedin.com/in/karlbertin'><img src='https://gist.githack.com/kvpb/4d0c98dbf62d45a48efd38a011981163/raw/f43c91ed4b3c561f12a57be96e1f429528610d61/linkedin.svg' alt='LinkedIn'></a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href='https://www.instagram.com/karlbertin/'><img src='https://gist.githack.com/kvpb/b7f2a52ae60036fa14d5d9ccd94c471a/raw/4c6931b55f46de2bd1d325a0a5b665f048822ab8/instagram.svg' alt='Instagram'></a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href='https://vm.tiktok.com/ZSwAmcFh/'><img src='https://gist.githack.com/kvpb/71a693f696d87330e5c73f03767cd57e/raw/d08999b2a8a1b29d8fa7ada6fadd83f9cc23112c/tiktok.svg' alt='TikTok'></a></span></p>