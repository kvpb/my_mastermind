/*
	SYNOPSIS
	my_mastermind [-ct]
	
	DESCRIPTION
	Mastermind is a game composed of 8 pieces of different colors.
	A secret code is then composed of 4 distinct pieces.
	
	The player has 10 attempts to find the secret code.
	After each input, the game indicates to the player the number of well placed pieces and the number of misplaced pieces.
	
	Pieces will be '0' '1' '2' '3' '4' '5' '6' '7'.
	
	If the player finds the code, he wins, and the game stops.
	A misplaced piece is a piece that is present in the secret code butthat is not in a good position.
	
	You must read the player's input from the standard input.
	
	Your program will also receive the following parameters:
	-c [CODE]: specifies the secret code. If no code is specified, a random code will be generated.
	-t [ATTEMPTS]: specifies the number of attempts; by default, the playerhas 10 attempts.
*/

// on a scanf?  sinon check whether read stdin marcherait
// faire du turn by turn avec scanf je suppose
//
// initialiser le nombre de tours a 0, enfin 1, enfin non 0 plutot cf apres
//
// greet
//
// output separator (a chaque tour) ADADADADADA<-------,
// a chaque tour demander une input                    |
// incrementer le nombre de tours de 1                 |
//                                                     |
// check for valid input  if invalid do it again       |
// match l'input a la string stored dans le buffer     |
//   si fully matches c'est gagne donc finir           |
//   si ne ou partially matches ne rien faire          |
//   output le nombre de pieces mal ou bien placees    |
//                                                     |
// match le nombre de tours et si c'est fini game over |
// boucler a ADADADADADA<------------------------------'
//
//
//	int R = ( rand() % ( 7 + 1 - 0 ) ) + 0 //int min = 0; int max = 7; int R = ( rand() % ( max + 1 - min ) ) + min;
//
//	char[4] code;// = itoa(rand());
//	int attempts;
//	
//	if ( !C )
//	{
//		int i = 0;
//		while ( i < 4 )
//			code += strcat(itoa(rand())); // das garbaj i kno
//	}
//	if ( !t )
//		t = 10;
//
//
//	if ( argv[1] == "-c" )
//	{
//		if ( strlen(argv[2]) == 4 )
//		{
//			while (isdigit(*argv[2]++))
//			{
//				// check for a given code, and if there is, check whether it is valid, and if it is, use it, or else make one
//
//
//    time_t t_a = time(NULL);
//    struct timeval t_b;
//    gettimeofday(&t_b, NULL);
//    printf("%ld\n", t_a);
//    printf("%ld, %ld\n", t_b.tv_sec, t_b.tv_usec);
//
//    if ( strlen(secret) % 2 == 0 )
//        t = t_a;
//    else if ( strlen(secret) % 2 == 1 )
//        t = 1000000 * t_b.tv_sec + t_b.tv_usec;
//    srand(t);
//    ...

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h> // 	debug code
// 	debug code


int kvpbstrlen(char* s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return i;
} // KVPB's STRLEN
// 	debug code


char* kvpbstrrev(char* s)
{
	char c;
	int l = kvpbstrlen(s);
	int i = 0;
	int j = l - 1;

	while ( i < j )
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		i++;
		j--;
	}
	return s;
} // KVPB's STRREV
// 	debug code


//char* kvpbitoa(int n); // KVPB's ITOA
// 	debug code


#define INT_DIGITS 19		/* enough for 64 bit integer */
#define UINT_DIGITS 20

#ifdef __cplusplus
extern "C" {
#endif

char *i_to_a(int i)
{
  /* Room for INT_DIGITS digits, - and '\0' */
  static char buf[INT_DIGITS + 2];
  char *p = buf + INT_DIGITS + 1;	/* points to terminating '\0' */
  if (i >= 0) {
    do {
      *--p = '0' + (i % 10);
      i /= 10;
    } while (i != 0);
    return p;
  }
  else {			/* i < 0 */
    do {
      *--p = '0' - (i % 10);
      i /= 10;
    } while (i != 0);
    *--p = '-';
  }
  return p;
}

char *ui_to_a(unsigned int i)
{
  /* Room for UINT_DIGITS digits and '\0' */
  static char buf[UINT_DIGITS + 1];
  char *p = buf + UINT_DIGITS;	/* points to terminating '\0' */
  do {
    *--p = '0' + (i % 10);
    i /= 10;
  } while (i != 0);
  return p;
}

#ifdef __cplusplus
}
#endif
// Apple Inc's ITOA
// 	debug code


//void reverse(char s[])
//{
//    int c, i, j;
//
//    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
//        c = s[i];
//        s[i] = s[j];
//        s[j] = c;
//    }
//} // Brian Kernighan & Dennis Ritchie's reverse (page 62, The C Programming Language (2st Edition))
// 	debug code


//void itoa(int n, char s[])
//{
//    int i, sign;
//
//    if ((sign = n) < 0)  /* record sign */
//        n = -n;          /* make n positive */
//    i = 0;
//    do {       /* generate digits in reverse order */
//        s[i++] = n % 10 + '0';   /* get next digit */
//    } while ((n /= 10) > 0);     /* delete it */
//    if (sign < 0)
//        s[i++] = '-';
//    s[i] = '\0';
//    reverse(s);
//} // Brian Kernighan & Dennis Ritchie's ITOA (page 64, The C Programming Language (2st Edition))
// 	debug code


int isnum(char* s)
{
    int l = strlen(s);
    int i = 0;

    while ( s[i] != 0 && ( 48 <= s[i] && s[i] <= 57 ) )
        i++;
    return ( ( i == l ) ? 1 : 0 );
}


int isset(char* s)
{
    int l = strlen(s);
    int i = 0;

	while ( s[i] != 0 && ( 48 <= s[i] && s[i] <= 55 ) )
        i++;
    return ( ( i == l ) ? 1 : 0 );
} // KVPB's IsSet
//     debug code


char* kvpbstrcpy(char* s_2, char* s) //char* strcpy(char* dst, char* src)
{
	int i = 0;

	while (s[i] != '\0')
	{
		s_2[i] = s[i];
		i++;
	}
	s_2[i] = 0;
	return s_2;
} // KVPB's STRCPY
// 	debug code


char* kvpbstrcat(char *s_2, char *s)
{
	kvpbstrcpy( s_2 + kvpbstrlen( s_2 ), s );
	return s_2;
} // KVPB's STRCAT
// 	debug code


int kvpbstrcmp(char* s_1, char* s_2)
{
	int i = 0;

	if (!s_1 || !s_2)
		return 0;
	while (s_1[i] == s_2[i] && s_1[i] != '\0' && s_2[i] != '\0')
		i++;
	return ( s_1[i] - s_2[i] );
} // KVPB's STRCMP
// 	debug code


//int kvpbstrncmp(const char* s_1, const char* s_2, size_t n); // KVPB's STRnCMP
// 	debug code


int stridk(char* s_1, char* s_2)
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
} // KVPB's STRidontknowitjustcountsthenumberofmatchingcharacters
// 	debug code


//int strwtv(char* s_1, char* s_2)
//{
//	int i = 0;
//	int j = 0;
//    int k = 0;
//    int l = 0;
//
//	if ( strlen(s_2) != strlen(s_1) )
//		return 0;
//    // for each element of string 1 go through string 2
//	//while (s_2[k] != '\0')
//    //{
//    //    while (s_1[j] != '\0')
//    //    {
//    //        if (s_1[j] != s_1[ j - 1 ] && s_1[j] == s_2[k]) // Either this will count each match up to four times, unless I write && s_1[j] != s_1[ j - 1 ]...
//    //            i++;
//    //        j++;
//    //    }
//    //    j = 0;
//    //    k++;
//    //} // Or it will fail another way, because each previous and next do not necessarily differ...
//    //while (s_2[k] != '\0' && s_1[k] != '\0')
//    //{
//    //    while ( j < 7 )
//    //    {
//    //        if (s_2[j] == itoa(k) && s_1[j] == itoa(k))
//    //            i++;
//    //        j++;
//    //    }
//    //    j = 0;
//    //    k++;
//    //} // This is another STRIDK...
//    while (  )
//    {
//
//    }
//	return i;
//} // KVPB's STRwhateverthisonecountshowmanymisplacedpiecesthereare
//  debug code


int strsth(char* secret, char* code) //int strsth(char* pieces, char* secret, char* code)
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
//	printf("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW\n"); //     debug code
//	printf("\\n\\t:\\t%%;\n\tsecret:\t%s;\n\tcode:\t%s;\n\tpieces:\t%s;\n\tbuf1:\t%s;\n\tbuf2:\t%s;\n\td:\t%d;\n\ti:\t%d;\n\tj:\t%d;\n\tk:\t%d;\n\tl_1:\t%d;\n\tl_2:\t%d;\n\tn:\t%d;\n", secret, code, pieces, buffer1, buffer2, d, i, j, k, l_1, l_2, n); //printf("debug:\n\t:\t%;\n", ); //     debug code
//	for ( int i_d = 0; pieces[i_d] != '\0'; i_d++ )      //     debug
//		printf("\tpieces[%d]:\t%c\n", i_d, pieces[i_d]); //     code
//	for ( int i_d = 0; i_d < m; i_d++ )                    //     debug
//		printf("\tbuffer1[%d]:\t%d\n", i_d, buffer1[i_d]); //     code
//	for ( int i_d = 0; i_d < m; i_d++ )                    //     debug
//		printf("\tbuffer2[%d]:\t%d\n", i_d, buffer2[i_d]); //     code

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
//			printf("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW                                     \n\tk:\t\t%d;\n\tm:\t\t%d;\n\tpieces[k]:\t%d;\n\ti:\t\t%d;\n\tl_1:\t\t%d;\n\tsecret[i]:\t%d;\n\tbuffer1[k]:\t%d;\n", k, m, pieces[k], i, l_1, secret[i], buffer1[k]); //     debug code
			i++;
		}
//		for ( int i_d = 0; i_d < m; i_d++ )                    //     debug
//			printf("\tbuffer1[%d]:\t%d\n", i_d, buffer1[i_d]); //     code
		j = 0;
		while ( j < l_2 ) //while (code[j] != '\0') //while ( j < l )
		{
			if (code[j] == pieces[k])
				buffer2[k] += 1; //buffer2[code[j]] += 1;
//			printf("                                     WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW\n\tk:\t\t%d;\n\tm:\t\t%d;\n\tpieces[k]:\t%d;\n\tj:\t\t%d;\n\tl_2:\t\t%d;\n\tcode[j]:\t%d;\n\tbuffer2[k]:\t%d;\n", k, m, pieces[k], j, l_2, code[j], buffer2[k]); //     debug code
			j++;
		}
//		for ( int i_d = 0; i_d < m; i_d++ )                    //     debug
//			printf("\tbuffer2[%d]:\t%d\n", i_d, buffer2[i_d]); //     code
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
} // KVPB's STHwhocaresatthispointimgettingtiredimightaswellrewriteitaccordingtomyinitialdraftonpaperbutseriouslyfuckthat
//  debug code


void help()
{
	char* string = "my_mastermind: my_mastermind [-c code] [-t attempts]\n";
	int l = strlen(string);

	write(1, string, l);
}

//const char* generate(int b); // receives a bool, returns a string.

//const int match(char* secret, char* code); // receives two strings of secret and entered codes, returns the number of matching characters.

//void my_mastermind(int argc, char** argv)
//{
//	//int pieces[8] = {0, 1, 2, 3, 4, 5, 6, 7}; //int charset[8] //int C[8]
//	//int m = 0;
//	//int M = sizeof(pieces) / sizeof(pieces[0]);
//	char* secret; //char secret[4]; //char* s_0 = malloc( l * sizeof(char) );
//	struct timeval t_0; //time_t t_0;
//	//struct timeval t_1;
//	unsigned long t;
//	int d; //int R; //int digit;
//	//int l_1 = strlen(secret);
//	int attempts = 10; //int a
//	char* code = malloc( 4 * sizeof(char) ); //char code[4]; //char* s_1 = malloc( l * sizeof(char) );
//	//int l_2 = strlen(code);
//	int b = 0; //bool t = false;
//	int n_O;
//	int n_K;
//	int i = 0;
//	int j = 0;
//
//	secret = malloc( 4 * sizeof(char) );
//	while ( strlen(secret) < 4 )
//	{
//        gettimeofday(&t_0, NULL); // 2021.10.21@16:45:00?  No ANSI C Time-like function provides a time resolution better than one second, but the POSIX C function GetTimeOfDay does provide one of one millionth of a second. //t_0 = time( NULL ); // time elapsed since 01.01.1970 at 00:00:00 in Greenwich.
//        /*gettimeofday(&t_1, NULL); // 2021.10.21@17:15:00  I add this, because it still goes too fast, and I end up with twice the same leading number.
//        if ( strlen(secret) % 2 == 0 )
//            t = 1000000 * t_1.tv_sec + t_0.tv_usec; //t = 1000000 * t_0.tv_sec + t_0.tv_usec; // 2021.10.21@17:00:00?  Get the microseconds of the time, because SRAND takes time_t-type data, and GetTimeOfDay returns a struct timeval-type value. https://github.com/openbsd/src/blob/master/sys/sys/time.h#L40-L50
//        else if ( strlen(secret) % 2 == 1 )
//            t = 1000000 * t_0.tv_sec + t_1.tv_usec;*/ // 2021.10.21@17:47:11  t_0 = t_1... It changed nothing. I guess I need nanosecond-level precision.
//        t = 1000000 * t_0.tv_sec + t_0.tv_usec; //t = 1000000 * t_0.tv_sec + t_0.tv_usec; // 2021.10.21@17:00:00?  Get the microseconds of the time, because SRAND takes time_t-type data, and GetTimeOfDay returns a struct timeval-type value. https://github.com/openbsd/src/blob/master/sys/sys/time.h#L40-L50
//        srand(t); // 2021.10.21@17:21:21!  Seed RAND.
//        d = rand() % ( 7 + 1 - 0 ) + 0; // 2021.10.21@16:30:00?  I always got 7112 and 7613, because RAND is seeded with 1 by default, if one does not use SRAND.
//		secret = strcat(secret, i_to_a( d )); //secret = strcat(secret, i_to_a( rand() % ( 7 + 1 - 0 ) + 0 )); //strcat(secret, snprintf(secret, 4, "%d", ( ( rand() % ( 7 + 1 - 0 ) ) + 0 ))); //strcat(secret, itoa( ( rand() % ( M + 1 - m ) ) + m ) ); // 'my_mastermind.c:105:18: warning: implicit declaration of function ‘itoa’ [-Wimplicit-function-declaration]'? Seriously? http://www.strudel.org.uk/itoa/
//	    //printf("debug:\t\n\tstrlen(secret):\t\t\t%ld;\n\tt_0.tv_sec:\t\t\t%ld;\n\tt_0.tv_usec:\t\t\t%ld;\n\tt:\t\t\t\t%ld;\n\td = rand() %% ( M + 1 - m ) + m:\t%d;\n\ti_to_a( d ):\t\t\t%s;\n\tsecret:\t\t\t\t%s;\n", strlen(secret), t_0.tv_sec, t_0.tv_usec, t, d, i_to_a( d ), secret); //printf("debug:\t\n\tstrlen(secret):\t\t\t%ld;\n\tt_0.tv_sec:\t\t\t%ld;\n\tt_0.tv_usec:\t\t\t%ld;\n\tt_1.tv_sec:\t\t\t%ld;\n\tt_1.tv_usec:\t\t\t%ld;\n\tt:\t\t\t\t%ld;\n\td = rand() %% ( M + 1 - m ) + m:\t%d;\n\ti_to_a( d ):\t\t\t%s;\n\tsecret:\t\t\t\t%s;\n", strlen(secret), t_0.tv_sec, t_0.tv_usec, t_1.tv_sec, t_1.tv_usec, t, d, i_to_a( d ), secret); //     debug code
//	}
//	// Generate the 4-char secret code.
//
//	if ( b != 1 )
//	{
//		while ( i < attempts ) //while ( 0 < attempts )
//		{
//			if ( i == 0 )
//				printf("Will you find the secret code?\n");
//			printf("---\nRound %d\n>", i);
//			/*while ( strlen(code) != 4 )
//				scanf("%s", code);*/
//			while ( strlen(code) != 4 || !isset(code) ) //while ( strlen(code) != 4 )
//            {
//                //int s_0 = GetInt(); // 2021.10.22@15:15:00  https://cs50.stackexchange.com/questions/9404/how-to-prompt-user-for-input-again-if-the-input-is-empty
//                scanf("%s", code); //code = i_to_a( s ); // 2021.10.22@15:17:15  It would require importing a whole library. It only is a 6.9kB file named cs50.c, but I did not make it.
//                if ( !isset(code) || ( strlen(code) < 4 || strlen(code) > 4 ) ) // Simple as. I overthought it. //if ( !code || 
//                    printf("Wrong input!\n>");
//            }
////			printf("debug:\t\t\n\tsecret:\t\t%s;\n\tattempts:\t%d;\n\tcode:\t\t%s;\n\tb:\t\t%d;\n\tn_O:\t\t;\n\tn_K:\t\t;\n\ti:\t\t%d;\n", secret, attempts, code, b, i); //     debug code
//            // Receive a valid code.
//			if (strcmp(secret, code)) //if (strncmp(secret, code, 4))
//			{
//				n_O = stridk(secret, code);
//				n_K = strsth(secret, code) - n_O; //n_K = 4 - stridk(secret, code); // 'misplaced' means 'exists in the secret code at another index', not 'does not match with it'...
//				printf("Well placed pieces: %d\nMisplaced pieces: %d\n", n_O, n_K); //printf("Well placed pieces: %d\nMisplaced pieces: %d\n", stridk(secret, code), strwtv(secret, code));
//			}
//			else
//			{
//				b = 1;
//				i = attempts;
////				printf("Congratz! You did it!\n");
//			}
//			memset(code, 0, strlen(code));
//            // Match the secret and the code against each other.
//			i += 1;
//		}
//	}
//	if ( b == 1 )
//		printf("Congratz! You did it!\n");
//    // Play Mastermind.
//}


void my_mastermind(char* secret, int attempts)
{
	/*int pieces[8] = {0, 1, 2, 3, 4, 5, 6, 7}; //int charset[8] //int C[8]
	int m = 0;
	int M = sizeof(pieces) / sizeof(pieces[0]);*/
	//char* secret; //char* s_0 = malloc( l * sizeof(char) );
	struct timeval t_0;
	unsigned long t;
	int R; //int d
	//int l = strlen(secret); //int l_1
	//int attempts = 10; //int a
	char* code = malloc( 4 * sizeof(char) ); //char* s_1 = malloc( l * sizeof(char) );
	//int l_2 = strlen(code);
	int b = 0;
	int n_O;
	int n_K;
	int i = 0;
	int j = 0;
	//printf("debug\t\n\tsecret\t\t%s\n\tt_0.tv_sec\t%ld\n\tt_0.tv_usec\t%ld\n\tt\t\t%ld\n\tR\t\t%d\n\tl\t\t%d\n\tattempts\t%d\n\tcode\t\t%s\n\tb\t\t%d\n\tn_O\t\t%d\n\tn_K\t\t%d\n\ti\t\t%d\n\tj\t\t%d\n", secret, t_0.tv_sec, t_0.tv_usec, t, R, l, attempts, code, b, n_O, n_K, i, j); //printf("debug\t\n\tpieces\t%s\n\tm\t%d\n\tM\t%d\n\tsecret\t%s\n\tt_0.tv_sec\t%ld\n\tt_0.tv_usec\t%ld\n\tt\t%ld\n\tR\t%d\n\tl_1\t%d\n\tattempts\t%d\n\tcode\t%s\n\tl_2\t%d\n\tb\t%d\n\tn_O\t%d\n\tn_K\t%d\n\ti\t%d\n\tj\t%d", iatoa(pieces), m, M, secret, t_0.tv_sec, t_0.tv_usec, t, R, l_1, attempts, code, l_2, b, n_O, n_K, i, j);

    if ( secret == "\0" ) //secret == NULL )
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
	        printf("debug:\t\n\tstrlen(secret):\t\t\t%ld;\n\tt_0.tv_sec:\t\t\t%ld;\n\tt_0.tv_usec:\t\t\t%ld;\n\tt:\t\t\t\t%ld;\n\tR:\t\t\t\t%d;\n\tsecret:\t\t\t\t%s;\n", strlen(secret), t_0.tv_sec, t_0.tv_usec, t, R, secret); //printf("debug:\t\n\tstrlen(secret):\t\t\t%ld;\n\tt_0.tv_sec:\t\t\t%ld;\n\tt_0.tv_usec:\t\t\t%ld;\n\tt_1.tv_sec:\t\t\t%ld;\n\tt_1.tv_usec:\t\t\t%ld;\n\tt:\t\t\t\t%ld;\n\td = rand() %% ( M + 1 - m ) + m:\t%d;\n\tsecret:\t\t\t\t%s;\n", strlen(secret), t_0.tv_sec, t_0.tv_usec, t_1.tv_sec, t_1.tv_usec, t, d, secret); //     debug code
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
				n_O = stridk(secret, code);
				n_K = strsth(secret, code) - n_O;
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


int main(int argc, char** argv)
{
	//int pieces[n] = malloc( n * sizeof(int) );
	//int l;
	char* code = malloc( 4 * sizeof(char) );
	int attempts;
	int i = 0;
	//int j = 0;
	//int k = 0;
	printf("debug\n\targc:\t\t%d;\n", argc); // 	debug code
	for ( int i_d = 0; i_d < argc; i_d++ )            // 	debug
		printf("\targv[%d]:\t%s;\n", i_d, argv[i_d]); // 	      code

//	if ( argc == 1 || argc != 3 && argc != 5 )
//	{
//		code = NULL;
//		attempts = 10;
//	}
//	else
//	{
//		if ( strcmp(argv[1], "c") == 0 || strcmp(argv[1], "-c") == 0 || strcmp(argv[1], "code") == 0 || strcmp(argv[1], "--code") == 0 ) //if ( argv[1] == "c" || argv[1] == "-c" || argv[1] == "code" || argv[1] == "--code" ) // Because argv[n] == "string" compares two pointers.
//			code = argv[2];
//		if ( strcmp(argv[3], "t") == 0 || strcmp(argv[3], "-t") == 0 || strcmp(argv[3], "attempts") == 0 || strcmp(argv[3], "--attempts") == 0 )
//			attempts = atoi(argv[4]);
//	} // If I use an if-else statement, one must enter in a specific order the arguments. I should use a while loop. But first, let's make get it to work. And then, I'll better remake it.
	/*if ( argc < 2 || 5 < argc || argc % 2 == 0 )
	{
		if ( argc > 5 || argc % 2 == 0 )
			help();
		code = NULL;
		attempts = 10;
	}
	else
	{
		while ( i + 1 < argc )
		{
			if ( strcmp(argv[i], "c") == 0 || strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "code") == 0 || strcmp(argv[i], "--code") == 0 )
				code = argv[ i + 1 ]; // 5275 passes, but how about 5872? ;)
			if ( strcmp(argv[i], "t") == 0 || strcmp(argv[i], "-t") == 0 || strcmp(argv[i], "attempts") == 0 || strcmp(argv[i], "--attempts") == 0 )
				attempts = atoi(argv[ i + 1 ]);
			i++;
		}
	}*/ 
	if ( argc < 2 || 5 < argc || argc % 2 == 0 )
	{
		if ( argc > 5 || argc % 2 == 0 )
			help();
		//code = "\0"; //code = NULL;
		//attempts = 10;
	}
	else
	{
		while ( i + 1 < argc )
		{
			if ( strcmp(argv[i], "c") == 0 || strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "code") == 0 || strcmp(argv[i], "--code") == 0 )
			{
				if ( strlen(argv[ i + 1 ]) == 4 && isset(argv[ i + 1 ]) ) // 2021.10.22@19:40:00  I gotchu, buddy. A few more braces, some more indentation, a bunch of conditionals, and there, you have it.
					code = argv[ i + 1 ]; // 2021.10.22@17:55:00  5275 passes, but how about 5872? ;)
				else
                    code = "\0"; //code = NULL; // 2021.10.25@15:00:00  Wait. This causes it to crash. Why? What is NULL?
            }
            if ( strcmp(argv[i], "t") == 0 || strcmp(argv[i], "-t") == 0 || strcmp(argv[i], "attempts") == 0 || strcmp(argv[i], "--attempts") == 0 )
            {
                if ( isnum(argv[ i + 1 ]) )
    				attempts = atoi(argv[ i + 1 ]);
                else
                    attempts = 10;
            }
			i++;
		}
        my_mastermind(code, attempts);
	}
	//my_mastermind(code, attempts);
	return 0;
}