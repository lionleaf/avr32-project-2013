#include "tones.h"

#include <stdlib.h>
#include <math.h>

// Generates tones
void tones_init() {
    // Allocate memory
    tones = (sample_t**)malloc(sizeof(sample_t*) * TONES_TOTAL);
    
    // Generate silent sample
    silence = sample_gen_silence();
    
    // Generate tones from octave [0,5)
    int16_t i;
    for (i = 3; i < 5 ; i++) {
        int16_t base = i * 12;
        int16_t mult = pow( 2, (5-i) );
        
        tones[base + 0] = sample_gen_square(262 / mult);
        tones[base + 1] = sample_gen_square(277 / mult);
        tones[base + 2] = sample_gen_square(294 / mult);
        tones[base + 3] = sample_gen_square(311 / mult);
        tones[base + 4] = sample_gen_square(330 / mult);
        tones[base + 5] = sample_gen_square(349 / mult);
        tones[base + 6] = sample_gen_square(370 / mult);
        tones[base + 7] = sample_gen_square(392 / mult);
        tones[base + 8] = sample_gen_square(415 / mult);
        tones[base + 9] = sample_gen_square(440 / mult);
        tones[base +10] = sample_gen_square(466 / mult);
        tones[base +11] = sample_gen_square(494 / mult);
    }
    
    // Generate tones from octave [5,10)
    for (i = 5; i < 10 ; i++) {
        int16_t base = i * 12;
        int16_t mult = pow( 2, (i-5) );
        
        tones[base + 0] = sample_gen_square(262 * mult);
        tones[base + 1] = sample_gen_square(277 * mult);
        tones[base + 2] = sample_gen_square(294 * mult);
        tones[base + 3] = sample_gen_square(311 * mult);
        tones[base + 4] = sample_gen_square(330 * mult);
        tones[base + 5] = sample_gen_square(349 * mult);
        tones[base + 6] = sample_gen_square(370 * mult);
        tones[base + 7] = sample_gen_square(392 * mult);
        tones[base + 8] = sample_gen_square(415 * mult);
        tones[base + 9] = sample_gen_square(440 * mult);
        tones[base +10] = sample_gen_square(466 * mult);
        tones[base +11] = sample_gen_square(494 * mult);
    }
}
