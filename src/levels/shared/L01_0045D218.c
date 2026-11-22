#include "common.h"
#include "vu0.h"

typedef struct { u8 pad[0x10]; f32 x; f32 y; } M_4574A0;
typedef struct {
    u8 pad[0xDC];
    f32 fDC;
    s16 hE0;
    s16 hE2;
    s16 hE4;
} S_4574A0;

/* localdecomp:start func_L01_0045D218 */
extern s32 func_L01_0045D248(void *, void *, void *);

s32 func_L01_0045D218(u8 *a, u8 *b) {
    vu0_v4 d;

    vec_sub_ab(&d, b, a + 0x10);
    return func_L01_0045D248(a, b, &d);
}
/* localdecomp:end func_L01_0045D218 */
