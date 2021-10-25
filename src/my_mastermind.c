/*// Copyright 2021 Karl V. P. Bertin
////
//// Redistribution and use in source and binary forms, with or without modifi-
//// cation, are permitted provided that the following conditions are met:
////
////   1.  Redistributions of source code must retain the above copyright noti-
////	   ce, this list of conditions and the following disclaimer.
////
////   2.  Redistributions in binary form must reproduce the above copyright
////	   notice, this list of conditions and the following disclaimer in the
////	   documentation and/or other materials provided with the distribution.
////
////   3.  Neither the name of the copyright holder nor the names of its con-
////	   tributors may be used to endorse or promote products derived from
////	   this software without specific prior written permission.
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

#include "../include/my_mastermind.h"
/*#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>*/
// 	debug code

/*int isnum(char* s)
{
	int l = strlen(s);
	int i = 0;

	while ( s[i] != 0 && ( 48 <= s[i] && s[i] <= 57 ) )
		i++;
	return ( ( i == l ) ? 1 : 0 );
} // KVPB's IsNumber*/
//	 debug code

/*int isset(char* s)
{
	int l = strlen(s);
	int i = 0;

	while ( s[i] != 0 && ( 48 <= s[i] && s[i] <= 55 ) )
		i++;
	return ( ( i == l ) ? 1 : 0 );
} // KVPB's IsSet*/
//	 debug code

/*int strsth(char* s_1, char* s_2) // receives the string of the secret code and that of the attempted code, returns the number of matching characters.
{
	int i = 0;
	int j = 0;

	if ( strlen(s_2) != strlen(s_1) )
		return 0;
	while ( j < strlen(s_1) )
	{
		if (s_2[j] == s_1[j]) //if ( strcmp(&s_2[i], &s_1[i]) == 0 ) // Why did I write this? top kek
			i += 1;
		j++;
	}
	return i;
} // KVPB's STRsomething*/
// 	debug code

/*int strwtv(char* secret, char* code) // receives the strings of the secret and attempted codes, returns the number of shared characters. //int strwtv(char* pieces, char* secret, char* code)
{
	int n = 0;
	char pieces[8] = {'0', '1', '2', '3', '4', '5', '6', '7'}; //char pieces[8] = {0, 1, 2, 3, 4, 5, 6, 7};
	int m = sizeof(pieces) / sizeof(pieces[0]); //int m = arrlen(pieces); //int m = strlen(pieces);
	//char* buf1 = malloc( n * sizeof(char) );
	int buffer1[8] = {0, 0, 0, 0, 0, 0, 0, 0}; //char buf1[m] = "00000000"; //char buf1[8] = {0, 0, 0, 0, 0, 0, 0, 0}; //buf1 = {0, 0, 0, 0, 0, 0, 0, 0};
	int buffer2[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	int l_1 = strlen(secret);
	int l_2 = strlen(code);
	int i = 0; //int i, j, k;
	int j = 0;
	int k = 0;
//	printf("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW\n"); //	 debug code
//	printf("\\n\\t:\\t%%;\n\tsecret:\t%s;\n\tcode:\t%s;\n\tpieces:\t%s;\n\tbuf1:\t%s;\n\tbuf2:\t%s;\n\td:\t%d;\n\ti:\t%d;\n\tj:\t%d;\n\tk:\t%d;\n\tl_1:\t%d;\n\tl_2:\t%d;\n\tn:\t%d;\n", secret, code, pieces, buffer1, buffer2, d, i, j, k, l_1, l_2, n); //printf("debug:\n\t:\t%;\n", ); //	 debug code
//	for ( int i_d = 0; pieces[i_d] != '\0'; i_d++ )	  //	 debug
//		printf("\tpieces[%d]:\t%c\n", i_d, pieces[i_d]); //	 code
//	for ( int i_d = 0; i_d < m; i_d++ )					//	 debug
//		printf("\tbuffer1[%d]:\t%d\n", i_d, buffer1[i_d]); //	 code
//	for ( int i_d = 0; i_d < m; i_d++ )					//	 debug
//		printf("\tbuffer2[%d]:\t%d\n", i_d, buffer2[i_d]); //	 code

	if ( l_2 != l_1 )
		return -1;
	// Part 0.
	k = 0;
	while ( k < m ) //while (pieces[k] != '\0') // does not work, because A[] does not have '\0'...
	{
		i = 0;
		while ( i < l_1 ) //while (secret[i] != '\0') //while ( i < l )
		{
			if (secret[i] == pieces[k])
				buffer1[k] += 1; //buffer1[ secret[i] - 48 ] += 1; //buffer1[secret[i]] += 1;
//			printf("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW									 \n\tk:\t\t%d;\n\tm:\t\t%d;\n\tpieces[k]:\t%d;\n\ti:\t\t%d;\n\tl_1:\t\t%d;\n\tsecret[i]:\t%d;\n\tbuffer1[k]:\t%d;\n", k, m, pieces[k], i, l_1, secret[i], buffer1[k]); //	 debug code
			i++;
		}
//		for ( int i_d = 0; i_d < m; i_d++ )					//	 debug
//			printf("\tbuffer1[%d]:\t%d\n", i_d, buffer1[i_d]); //	 code
		j = 0;
		while ( j < l_2 ) //while (code[j] != '\0') //while ( j < l )
		{
			if (code[j] == pieces[k])
				buffer2[k] += 1; //buffer2[code[j]] += 1;
//			printf("									 WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW\n\tk:\t\t%d;\n\tm:\t\t%d;\n\tpieces[k]:\t%d;\n\tj:\t\t%d;\n\tl_2:\t\t%d;\n\tcode[j]:\t%d;\n\tbuffer2[k]:\t%d;\n", k, m, pieces[k], j, l_2, code[j], buffer2[k]); //	 debug code
			j++;
		}
//		for ( int i_d = 0; i_d < m; i_d++ )					//	 debug
//			printf("\tbuffer2[%d]:\t%d\n", i_d, buffer2[i_d]); //	 code
		k++;
	}
	// Part 1: Count the amounts of pieces in both the secret and the code.
	k = 0;
	while ( k < m )
	{
		if ( buffer2[k] >= buffer1[k] && buffer1[k] >= 1 ) //if ( buffer2[k] <= buffer1[k] && buffer1[k] >= 1 ) //if ( buffer2[k] == buffer1[k] && buffer1[k] >= 1 ) //if ( buffer2[k] == buffer1[k] ) // The amount of piece k in the code must at least equate that of the secret must not equate 0.
			n += buffer1[k]; //n += buffer2[k]; //n += 1;
		else if ( buffer2[k] <= buffer1[k] && buffer2[k] >= 1 ) // Le nombre de pieces k dans le code doit au mieux egaler celui du secret, et le nombre de pieces k dans le secret doit ne pas valoir 0.
			n += buffer2[k];
//		printf("W W W W W W W W W W W W W W W W W W W W W W W W W W W W W W W W W W W W \n\tsecret:\t\t%s;\n\tcode:\t\t%s;\n\tk:\t\t%d;\n\tm:\t\t%d;\n\tpiece:\t\t%c;\n\tbuffer1[k]:\t%d;\n\tbuffer2[k]:\t%d;\n\tn:\t\t%d;\n", secret, code, k, m, pieces[k], buffer1[k], buffer2[k], n);
		k++;
	}
	// Part 2: Count shared pieces.
	return n;
} // KVPB's STHwhatever*/
// 	debug code

//const char* prng(int b); // receives a bool, returns a string.

void my_mastermind(char* secret, int attempts)
{
	/*int pieces[8] = {0, 1, 2, 3, 4, 5, 6, 7}; //int charset[8] //int C[8]
	int m = 0;
	int M = sizeof(pieces) / sizeof(pieces[0]);*/
	//char* secret; //char* s_0 = malloc( l * sizeof(char) );
	struct timeval t_0;
	unsigned long t = 0;
	int R = 0; //int d
	//int l = strlen(secret); //int l_1
	//int attempts = 10; //int a
	char* code = malloc( 4 * sizeof(char) ); //char* s_1 = malloc( l * sizeof(char) );
	//int l_2 = strlen(code);
	int b = 0;
	int n_O = 0;
	int n_K = 0;
	int i = 0;
	//printf("debug\t\n\tsecret\t\t%s\n\tt\t\t%ld\n\tR\t\t%d\n\tattempts\t%d\n\tcode\t\t%s\n\tb\t\t%d\n\tn_O\t\t%d\n\tn_K\t\t%d\n\ti\t\t%d\n", secret, t, R, attempts, code, b, n_O, n_K, i); //printf("debug\t\n\tpieces\t%s\n\tm\t%d\n\tM\t%d\n\tsecret\t%s\n\tt_0.tv_sec\t%ld\n\tt_0.tv_usec\t%ld\n\tt\t%ld\n\tR\t%d\n\tl_1\t%d\n\tattempts\t%d\n\tcode\t%s\n\tl_2\t%d\n\tb\t%d\n\tn_O\t%d\n\tn_K\t%d\n\ti\t%d\n\tj\t%d", iatoa(pieces), m, M, secret, t_0.tv_sec, t_0.tv_usec, t, R, l_1, attempts, code, l_2, b, n_O, n_K, i, j);

	if ( strcmp(secret, "\0") == 0 ) //secret == "\0" ) //secret == NULL )
	{
		memset(secret, 0, strlen(secret));
		secret = malloc( 4 * sizeof(char) );
		while ( strlen(secret) < 4 )
		{
			gettimeofday(&t_0, NULL);
			t = 1000000 * t_0.tv_sec + t_0.tv_usec;
			srand(t);
			R = rand() % ( 7 + 1 - 0 ) + 0;
			secret = strcat(secret, i_to_a( R ));
			//printf("debug:\t\n\tstrlen(secret):\t\t\t%ld;\n\tt_0.tv_sec:\t\t\t%ld;\n\tt_0.tv_usec:\t\t\t%ld;\n\tt:\t\t\t\t%ld;\n\tR:\t\t\t\t%d;\n\tsecret:\t\t\t\t%s;\n", strlen(secret), t_0.tv_sec, t_0.tv_usec, t, R, secret); //printf("debug:\t\n\tstrlen(secret):\t\t\t%ld;\n\tt_0.tv_sec:\t\t\t%ld;\n\tt_0.tv_usec:\t\t\t%ld;\n\tt_1.tv_sec:\t\t\t%ld;\n\tt_1.tv_usec:\t\t\t%ld;\n\tt:\t\t\t\t%ld;\n\td = rand() %% ( M + 1 - m ) + m:\t%d;\n\tsecret:\t\t\t\t%s;\n", strlen(secret), t_0.tv_sec, t_0.tv_usec, t_1.tv_sec, t_1.tv_usec, t, d, secret); //	 debug code
		}
	}
	// Generate the 4-char secret code.

	if ( b != 1 )
	{
		while ( i < attempts )
		{
			if ( i == 0 )
				printf("Will you find the secret code?\n");
			printf("---\nRound %d\n>", i);
			while ( strlen(code) != 4 || !isset(code) )
			{
				scanf("%s", code);
				if ( !isset(code) || ( strlen(code) < 4 || strlen(code) > 4 ) )
					printf("Wrong input!\n>");
			}
			// Receive a valid code.
			if (strcmp(secret, code))
			{
				n_O = strsth(secret, code);
				n_K = strwtv(secret, code) - n_O;
				printf("Well placed pieces: %d\nMisplaced pieces: %d\n", n_O, n_K);
			}
			else
			{
				b = 1;
				i = attempts;
			}
			memset(code, 0, strlen(code));
			// Match the secret and the code against each other.
			i += 1;
		}
	}
	if ( b == 1 )
		printf("Congratz! You did it!\n");
	// Play Mastermind.
}

void help()
{
	char* string = "my_mastermind: my_mastermind [-c code] [-t attempts]\n";
	int l = strlen(string);

	write(1, string, l);
}

int main(int argc, char** argv)
{
	//int pieces[n] = malloc( n * sizeof(int) );
	char* code = malloc( 4 * sizeof(char) );
	int attempts;
	int i = 0;
	//printf("debug\n\targc:\t\t%d;\n", argc); // 	debug code
	//for ( int i_d = 0; i_d < argc; i_d++ )			// 	debug
	//	printf("\targv[%d]:\t%s;\n", i_d, argv[i_d]); // 		  code

	if ( argc == 1 )
	{
		code = "\0";
		attempts = 10;
	}
	if ( argc < 1 || 5 < argc || argc % 2 == 0 )
	{
		if ( argc > 5 || argc % 2 == 0 )
			help();
	}
	else
	{
		while ( i + 1 < argc )
		{
			if ( strcmp(argv[i], "c") == 0 || strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "code") == 0 || strcmp(argv[i], "--code") == 0 )
			{
				if ( strlen(argv[ i + 1 ]) == 4 && isset(argv[ i + 1 ]) )
					code = argv[ i + 1 ];
				else
					code = "\0";
			}
			if ( strcmp(argv[i], "t") == 0 || strcmp(argv[i], "-t") == 0 || strcmp(argv[i], "attempts") == 0 || strcmp(argv[i], "--attempts") == 0 )
			{
				if ( isnum(argv[ i + 1 ]) )
					attempts = atoi(argv[ i + 1 ]);
				else
					attempts = 10;
			}
			else
				attempts = 10;
			i++;
		}
		my_mastermind(code, attempts);
	} // I should rewrite this last part. It looks like shit. I can simplify it. But it works, and it satisfies all requirements, so fuck off. :D KVPB, out. https://youtu.be/iNLR-EMugb4?t=3540
	return 0;
}

/*	my_mastermind.c
	My Mastermind

	Karl Bertin `bertin_k`
	bertin_k@qwasar.io
	https://upskill.us.qwasar.io/users/bertin_k

*///	Cf https://upskill.us.qwasar.io/projects/my_mastermind.