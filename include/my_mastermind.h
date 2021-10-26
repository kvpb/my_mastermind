/*// Copyright 2021 Karl V. P. Bertin
////
//// Redistribution and use in source and binary forms, with or without modifi-
//// cation, are permitted provided that the following conditions are met:
////
////   1.  Redistributions of source code must retain the above copyright noti-
////       ce, this list of conditions and the following disclaimer.
////
////   2.  Redistributions in binary form must reproduce the above copyright
////       notice, this list of conditions and the following disclaimer in the
////       documentation and/or other materials provided with the distribution.
////
////   3.  Neither the name of the copyright holder nor the names of its con-
////       tributors may be used to endorse or promote products derived from
////       this software without specific prior written permission.
////
//// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
//// IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
//// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
//// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRI-
//// BUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLA-
//// RY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
//// OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSI-
//// NESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
//// IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHER-
//// WISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
*/// OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef MY_MASTERMIND_H
# define MY_MASTERMIND_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# include <sys/time.h>
# include <string.h>
# include "libc.h"

int		isnum(char* s);
int		isset(char* s);
int		strsth(char* s_1, char* s_2);
int		strwtv(char* secret, char* code);
void	my_mastermind(char* secret, int attempts);

#endif

/*	my_mastermind.h

	Karl Bertin `bertin_k`
	bertin_k@qwasar.io
	https://upskill.us.qwasar.io/users/bertin_k

*///	It's been a while, Karl. Welcome back, in the driver's seat this time.