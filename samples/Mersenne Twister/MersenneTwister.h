#pragma once

namespace aie
{
    /**************************************************************************
    'MersenneTwister' is a high-performance random-number generate that offers
    a number of advantages over the C library's rand() function, namely:
        
        - twice as fast
    
        - carries internal state (allowing multiple and independent random
          number sequences to exist at the same time within an application)
    
        - has very high periodicity, making the quality of the random numbers
          much better than rand().
    ***************************************************************************/
    class MersenneTwister
    {
    public:

        MersenneTwister();

        // Specify the seed value to use (as a single integer). If this function
        // is not called, the seed will default to a null value.
        void setSeed( unsigned long s );

        // Specifies the seed as an array of integers
        void setSeed( unsigned long initKey[], int keyLength );

        // These methods return the next random number in the sequence, either 
        // as an int or double.
        unsigned randInt();
        double randReal32();
        double randReal53(void);

    private:
        static const unsigned N = 624;
        unsigned long mt[N];
        int mti;       
    };

} // namespace aie

