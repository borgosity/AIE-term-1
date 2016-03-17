#include "MersenneTwister.h"
#include <stdlib.h>
#include <time.h>

/* 
A C-program for MT19937, with initialization improved 2002/1/26.
Coded by Takuji Nishimura and Makoto Matsumoto.

Before using, initialize the state by using setSeed(seed)  
or init_by_array(init_key, key_length).

Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,
All rights reserved.                          

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

1. Redistributions of source code must retain the above copyright
notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
notice, this list of conditions and the following disclaimer in the
documentation and/or other materials provided with the distribution.

3. The names of its contributors may not be used to endorse or promote 
products derived from this software without specific prior written 
permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


Any feedback is very welcome.
http://www.math.sci.hiroshima-u.ac.jp/~m-mat/MT/emt.html
email: m-mat @ math.sci.hiroshima-u.ac.jp (remove space)
*/

#include <stdio.h>


namespace aie
{
    namespace detail
    {
        static const unsigned M = 397;
        static const unsigned MATRIX_A = 0x9908b0dfUL;   // constant vector a
        static const unsigned UPPER_MASK = 0x80000000UL; // most significant w-r bits
        static const unsigned LOWER_MASK = 0x7fffffffUL; // least significant r bits
    }
}

/*****************************************************************************
******************************************************************************/
aie::MersenneTwister::MersenneTwister() : mti( N+1 ) // mti==N+1 means mt[N] is not initialized
{
    setSeed( (unsigned)time(NULL) );
}

/*****************************************************************************
******************************************************************************/
void aie::MersenneTwister::setSeed(unsigned long s)
{
    mt[0]= s & 0xffffffffUL;
    for (mti=1; mti<N; mti++) {
        mt[mti] = 
            (1812433253UL * (mt[mti-1] ^ (mt[mti-1] >> 30)) + mti); 
        /* See Knuth TAOCP Vol2. 3rd Ed. P.106 for multiplier. */
        /* In the previous versions, MSBs of the seed affect   */
        /* only MSBs of the array mt[].                        */
        /* 2002/01/09 modified by Makoto Matsumoto             */
        mt[mti] &= 0xffffffffUL;
        /* for >32 bit machines */
    }
}

/*****************************************************************************
******************************************************************************/
void aie::MersenneTwister::setSeed(
    unsigned long init_key[], int key_length )
{
    int i, j, k;
    setSeed(19650218UL);
    i=1; j=0;
    k = (N>key_length ? N : key_length);
    for (; k; k--) {
        mt[i] = (mt[i] ^ ((mt[i-1] ^ (mt[i-1] >> 30)) * 1664525UL))
            + init_key[j] + j; /* non linear */
        mt[i] &= 0xffffffffUL; /* for WORDSIZE > 32 machines */
        i++; j++;
        if (i>=N) { mt[0] = mt[N-1]; i=1; }
        if (j>=key_length) j=0;
    }
    for (k=N-1; k; k--) {
        mt[i] = (mt[i] ^ ((mt[i-1] ^ (mt[i-1] >> 30)) * 1566083941UL))
            - i; /* non linear */
        mt[i] &= 0xffffffffUL; /* for WORDSIZE > 32 machines */
        i++;
        if (i>=N) { mt[0] = mt[N-1]; i=1; }
    }

    mt[0] = 0x80000000UL; /* MSB is 1; assuring non-zero initial array */ 
}

/*****************************************************************************
******************************************************************************/
unsigned aie::MersenneTwister::randInt()
{
    unsigned long y;
    static unsigned long mag01[2]={0x0UL, detail::MATRIX_A};
    /* mag01[x] = x * MATRIX_A  for x=0,1 */

    if (mti >= N) { /* generate N words at one time */
        int kk;

        if (mti == N+1)   /* if setSeed() has not been called, */
            setSeed(5489UL); /* a default initial seed is used */

        for (kk=0;kk<N-detail::M;kk++) {
            y = (mt[kk]&detail::UPPER_MASK)|(mt[kk+1]&detail::LOWER_MASK);
            mt[kk] = mt[kk+detail::M] ^ (y >> 1) ^ mag01[y & 0x1UL];
        }
        for (;kk<N-1;kk++) {
            y = (mt[kk]&detail::UPPER_MASK)|(mt[kk+1]&detail::LOWER_MASK);
            mt[kk] = mt[kk+(detail::M-N)] ^ (y >> 1) ^ mag01[y & 0x1UL];
        }
        y = (mt[N-1]&detail::UPPER_MASK)|(mt[0]&detail::LOWER_MASK);
        mt[N-1] = mt[detail::M-1] ^ (y >> 1) ^ mag01[y & 0x1UL];

        mti = 0;
    }

    y = mt[mti++];

    /* Tempering */
    y ^= (y >> 11);
    y ^= (y << 7) & 0x9d2c5680UL;
    y ^= (y << 15) & 0xefc60000UL;
    y ^= (y >> 18);

    return y;
}

/*****************************************************************************
******************************************************************************/
double aie::MersenneTwister::randReal32()
{
    return randInt()*(1.0/4294967296.0); 
    /* divided by 2^32 */
}

/*****************************************************************************
******************************************************************************/
double aie::MersenneTwister::randReal53()
{ 
    unsigned long a=randInt()>>5, b=randInt()>>6; 
    return(a*67108864.0+b)*(1.0/9007199254740992.0); 
} 
