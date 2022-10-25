/*//	Copyright 2021, 2022 Karl Vincent Pierre Bertin
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
/*#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>*/ //	debug code

void use_help()
{
	char* s = "my_mastermind: my_mastermind [-c code] [-t attempts]\n";
	int l_s = strlen(s);

	write( 1, s, l_s );
}

void play(char* s_secret, int n_attempts )
{
	struct timeval t_0;
	unsigned long t = 0;
	int R = 0;
	char* s_code = malloc( 4 * sizeof( char ) );
	int b = 0;
	int n_O = 0;
	int n_K = 0;
	int i = 0;

	if ( strcmp(s_secret, "\0") == 0 )
	{
		memset(s_secret, 0, strlen(s_secret) );
		s_secret = malloc( 4 * sizeof( char ) );
		while ( strlen(s_secret) < 4 )
		{
			gettimeofday( &t_0, NULL );
			t = 1000000 * t_0.tv_sec + t_0.tv_usec;
			srand( t );
			R = rand() % ( 7 + 1 - 0 ) + 0;
			s_secret = strcat(s_secret, i_to_a( R ));
		}
	}

	if ( b != 1 )
	{
		while ( i < n_attempts )
		{
			if ( i == 0 )
				printf("Will you find the secret code?\n");
			printf("---\nRound %d\n>", i );
			while ( strlen(s_code) != 4 || !isset(s_code) )
			{
				scanf("%s", s_code);
				if ( !isset(s_code) || ( strlen(s_code) < 4 || strlen(s_code) > 4 ) )
					printf("Wrong input!\n>");
			}
			if ( strcmp(s_secret, s_code) )
			{
				n_O = strsth(s_secret, s_code);
				n_K = strwtv(s_secret, s_code) - n_O;
				printf("Well placed pieces: %d\nMisplaced pieces: %d\n", n_O, n_K );
			}
			else
			{
				b = 1;
				i = n_attempts;
			}
			memset(s_code, 0, strlen(s_code) );
			i += 1;
		}
	}
	if ( b == 1 )
		printf("Congratz! You did it!\n");
}

int main( int c_argument, char** v_argument )
{
	char* s_code = malloc( 4 * sizeof( char ) );
	int n_attempts;
	int i = 0;

	if ( c_argument == 1 )
	{
		s_code = "\0";
		n_attempts = 10;
	}
	if ( c_argument < 1 || 5 < c_argument || c_argument % 2 == 0 )
	{
		if ( c_argument > 5 || c_argument % 2 == 0 )
			use_help();
	}
	else
	{
		while ( i + 1 < c_argument )
		{
			if ( strcmp(v_argument[ i ], "c") == 0 || strcmp(v_argument[ i ], "-c") == 0 || strcmp(v_argument[ i ], "code") == 0 || strcmp(v_argument[ i ], "--code") == 0 )
			{
				if ( strlen(v_argument[ i + 1 ]) == 4 && isset(v_argument[ i + 1 ]) )
					s_code = v_argument[ i + 1 ];
				else
					s_code = "\0";
			}
			if ( strcmp(v_argument[ i ], "t") == 0 || strcmp(v_argument[ i ], "-t") == 0 || strcmp(v_argument[ i ], "attempts") == 0 || strcmp(v_argument[ i ], "--attempts") == 0 )
			{
				if ( isnum(v_argument[ i + 1 ]) )
					n_attempts = atoi(v_argument[ i + 1 ]);
				else
					n_attempts = 10;
			}
			else
				n_attempts = 10;
			i++;
		}
		play(s_code, n_attempts );
	}
	return 0;
}

/*//	play.c
////	My Mastermind
////
////	Karl V. P. B. `kvpb` AKA Karl Thomas George West `ktgw`
////	bertin_k@qwasar.io
*///	https://upskill.us.qwasar.io/users/bertin_k
