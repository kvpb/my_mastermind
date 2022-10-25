/*//	Copyright 2021 Karl Vincent Pierre Bertin
////
////	Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
////
////	1.	Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
////
////	2.	Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
////
////	3.	Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
////
*///	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include "../include/my_mastermind.h"

int strwtv(char* secret, char* code)
{
    int n = 0;
    char pieces[8] = {'0', '1', '2', '3', '4', '5', '6', '7'};
    int m = sizeof(pieces) / sizeof(pieces[ 0 ]);
    int buffer1[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    int buffer2[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    int l_1 = strlen(secret);
    int l_2 = strlen(code);
    int i = 0;
    int j = 0;
    int k = 0;

	if ( l_2 != l_1 )
		return -1;

	k = 0;
	while ( k < m )
	{
		i = 0;
		while ( i < l_1 )
		{
			if (secret[ i ] == pieces[ k ])
				buffer1[ k ] += 1;
			i++;
		}
		j = 0;
		while ( j < l_2 )
		{
			if (code[ j ] == pieces[ k ])
				buffer2[ k ] += 1;
			j++;
		}
		k++;
	}

	k = 0;
	while ( k < m )
	{
		if ( buffer2[ k ] >= buffer1[ k ] && buffer1[ k ] >= 1 )
			n += buffer1[ k ];
		else if ( buffer2[ k ] <= buffer1[ k ] && buffer2[ k ] >= 1 )
			n += buffer2[ k ];
		k++;
	}

	return n;
}

/*//	strwtv.c
////	STRWhatever
////
////	Karl Bertin `bertin_k`
////	bertin_k@qwasar.io
*///	https://upskill.us.qwasar.io/users/bertin_k
