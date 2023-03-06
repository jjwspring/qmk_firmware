

#include "quantum.h"

#define ___ KC_NO

#define LAYOUT_18( \
             k00, k01, k02,           k03, k04, k05,      \
        k06, k07, k08, k09,           k10, k11, k12, k13, \
                       k14, k15, k16, k17                 \
    ) \
    { \
        { k00, k01, k02, ___, ___, ___, }, \
        { ___, ___, ___, k03, k04, k05, }, \
        { k07, k08, k09, ___, ___, ___, }, \
        { ___, ___, ___, k10, k11, k12, }, \
        { k06, k14, k15, k16, k17, k13, }  \
    }

#define LAYOUT LAYOUT_18

