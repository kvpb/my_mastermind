<!-- Let the good times roll, baby! -->

<p align="center"><img src="https://media.tenor.com/5PepR8rD4U0AAAAC/throwing-dice-quavo.gif"><br>
<i>Let's play a game.</i> &#x1F3B2;</p>

# My Mastermind

![C](https://img.shields.io/badge/-C-1B75B3?style=flat&logo=c&logoColor=A8B9CC) ![Makefile](https://img.shields.io/badge/-Makefile-848484?style=flat&logo=cmake&logoColor=D2D2D2) ![macOS](https://img.shields.io/badge/-macOS-FFFFFF?style=flat&logo=apple&logoColor=A7A9AC) ![Linux](https://img.shields.io/badge/-Linux-0094FF?style=flat&logo=linux&logoColor=003778) ![platform](https://gistcdn.githack.com/kvpb/ed57eb3a03f2b5338fbede97e7cf296b/raw/ea6556bb04f592433023533ddbd931cc7d23e92b/apple-F6F6F6D5E1ED1E72F21AD5FD-madeona-1AD5FD1E72F2-mac-F6F6F6D5E1ED.svg) ![platform](https://gistcdn.githack.com/kvpb/ed57eb3a03f2b5338fbede97e7cf296b/raw/ea6556bb04f592433023533ddbd931cc7d23e92b/ubuntu-F6F6F6D5E1ED1E72F21AD5FD-madeona-1AD5FD1E72F2-linuxbox-F6F6F6D5E1ED.svg)

> Mastermind is a game composed of 8 pieces of different colors.
> A secret code is then composed of 4 distinct pieces.
>
> The player has 10 attempts to find the secret code.
> After each input, the game indicates to the player the number of well placed pieces and the number of misplaced pieces.
>
> Pieces will be '0' '1' '2' '3' '4' '5' '6' '7'.
>
> If the player finds the code, he wins, and the game stops.
> A misplaced piece is a piece that is present in the secret code butthat is not in a good position.
>
> You must read the player's input from the standard input.
>
> Your program will also receive the following parameters:
> -c [CODE]: specifies the secret code. If no code is specified, a random code will be generated.
> -t [ATTEMPTS]: specifies the number of attempts; by default, the playerhas 10 attempts.
>
> **Example 00**
> ```
> PROMPT>./my_mastermind -c "0123"
> Will you find the secret code?
> ---
> Round 0
> >1456
> Well placed pieces: 0
> Misplaced pieces: 1
> ---
> Round 1
> >tata
> Wrong input!
> >4132
> Well placed pieces: 1
> Misplaced pieces: 2
> ---
> Round 2
> >0123
> Congratz! You did it!
> ```
&nbsp;&nbsp;[Qwasar Silicon Valley](https://upskill.us.qwasar.io/projects/my_mastermind)

## Setup

First spin [some](https://youtu.be/iNLR-EMugb4?t=2940) [real](https://youtu.be/YYkim4Uog1k?t=26) [music](https://youtu.be/RmLYHkqLc0s?t=16).

This software is an UNIX command-line game programmed in [C](https://www.open-std.org/jtc1/sc22/wg14/). It as such requires an [UNIX](http://opengroup.org/unix)-certified or [POSIX](http://get.posixcertified.ieee.org/)-compliant operating system or operating environment, e.g. [macOS](https://www.apple.com/macos) with [Command Line Tools](https://developer.apple.com/library/archive/technotes/tn2339/_index.html), [FreeBSD](https://www.freebsd.org/), [Arch Linux](https://archlinux.org/), [CRUX](https://crux.nu/) or [Alpine Linux](https://alpinelinux.org/), a command-line shell, e.g. [BASH](https://www.gnu.org/software/bash/), [ZSH](https://www.zsh.org/) or [TCSH](https://www.tcsh.org/), and a standard C optimizing compiler, e.g. [GNU C Compiler](https://gcc.gnu.org/) or [CLANG](https://clang.llvm.org/). The user may set it up and use it from a command-line interface in a graphical user interface via a terminal emulator, e.g. [iTerm2](https://iterm2.com), [Terminator](https://gnome-terminator.org) or [the integrated terminal of Visual Studio Code](https://code.visualstudio.com/docs/editor/integrated-terminal). These instructions assume the user knows how to use an UNIX shell in a POSIX-compliant development and runtime environment.

We now declare a few SH functions and variables for the sake of brevity. The user of course can forgo this and do it all by themselves manually.

```sh
pathname()
{
	printf "$(cd "$(dirname "${1}")" && pwd -P)/$(basename "${1}")"'\n'
}

URL="https://git.us.qwasar.io/my_mastermind_32390_2txyp4/my_mastermind"
dir="${URL%/*}" && dir="${dir##*/}"
repo="${URL##*/}"
progname="${repo}"
bin="$(pathname)${dir}/${repo}/${progname}"
n=1
i=0
R=$[RANDOM%7]$[RANDOM%7]$[RANDOM%7]$[RANDOM%7] && R=$(printf "%04d" ${R})
```

**The user should avoid setting this software up from a critical location in the file system, e.g. `/` or the parent directory of other software.** We advise doing so from a dedicated, throwaway directory. The user therefore optionally can:

```sh
mkdir ${dir} # preferably from ${HOME}.
cd ${dir}
```

Once the user has obtained the sources of this software, they may proceed to compile them. They should do thus:

```sh
git clone https://github.com/kvpb/my_mastermind #${URL}
cd ${repo}
# preferably from ${dir}/.
make # from ${repo}/.
```

The executable file at this point should be in `${repo}/`. The user should be able to run it tel quel.

## Use

The user now may test the software. They simply have to compare it to the requirements of the topic. They could do thus:

```sh
./my_mastermind -c ${R}
./my_mastermind
./my_mastermind -a $(( 10 - $[RANDOM%10] ))
./my_mastermind -c ${R} -a $(( 10 - $[RANDOM%10] ))
```

*`-c number_code` option test cases:*
```sh
./my_mastermind -c 0000 # must work.
```
```sh
./my_mastermind -c 0137 # must work.
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

*`-t number_attempts` option test cases:*
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

*`-c number_code` and `-t number_attempts` options test cases:*
```sh
./my_mastermind -c 0000 -t 10 # must work.
```
```sh
./my_mastermind -c 0137 -t 7 # must work.
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
./my_mastermind -c 0088 -t 13 # should fail.
```
```sh
./my_mastermind -c 0000 -t 10 AV5 # should fail.
```

The user then should examine how the program behaves. They simply have to compare this submission to the requirements of the subject. Using [Qwasar Silicon Valley's Gandalf](https://api.docode.us.qwasar.io/workspaces/kd8e8b976-1cf3) or the [DIFF](https://www.freebsd.org/cgi/man.cgi?diff) command-line utilities and [redirecting the standard output with BASH](https://www.gnu.org/software/bash/manual/html_node/Redirections.html) may help them achieve this. If the user can access Qwasar Silicon Valley's DoCode, they can do thus from it:
```sh
cd ${PROJECT_NAME}
git checkout
git pull --rebase
# ... If DoCode still has that bug.
for (( ; i < n; ))
do
	gandalf ex${(l:2::0:)i} # from the landing directory on DoCode.
	i=$(( i + 1 ))
done
```

---

<p align="center"><i>Made at <img alt="Qwasar Silicon Valley Logo" src="https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png" width="12px"> <a href="https://qwasar.io">Qwasar Silicon Valley</a> by</i><br>
<a href="http://kvpb.co"><img src="https://gistcdn.githack.com/kvpb/c80594e9079e857c55c36dec49a1a2d7/raw/eec54d5821dc092ad910635141c4e4feebf07565/kvpbssymbol.svg"></a><br>
<b>Karl V. P. B. `<code>kvpb</code>`<br>AKA&nbsp;&nbsp;Karl <!--&lsquo;T.G.&rsquo;--> Thomas George <!--<span style="font-variant: small-caps;">-->West<!--</span>--> `<code>ktgw</code>`</b><br>
<a href="https://www.linkedin.com/in/karlbertin">LinkedIn</a>&nbsp;&nbsp;<a href="https://github.com/kvpb">GitHub</a><br>
<br>
<br>
<br>
<img src="https://gistcdn.githack.com/kvpb/f5f75716dd024cc48f8dc28176c0b642/raw/e5344bebf926b378faeb208724ae97f4e06639ca/kvpbsesrbrating.svg"></p>

<!-- I'm european, baby! -->
