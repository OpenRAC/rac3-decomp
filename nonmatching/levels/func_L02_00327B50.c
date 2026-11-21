/* func_L02_00327B50: 64 diff with the file's flags (-mvu0-use-vf0-vf2 ... @ps2as), checked at its home place. Matches the prologue, the clamp of w14 (store before the test), the f18 clamp, the call to func_L02_00327960 and the 16-byte copy to v60. Still differs: gcc hoists the %hi of D_L02_001E1280 (lui $s4) above the loop, so the frame gets an extra s4 save and every later offset shifts; the loop counter lands in $s0 where retail has the pointer there (retail: counter $s2, pointer $s0). Tried: pointer loop (worse ordering), local vu0_v4 temp (stack temp, worse). */
#include "common.h"
#include "vu0.h"

extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_L02_00327960(void *, void *);

void func_L02_00327B50(void *a0, void *a1) {
    M_00326C90 *m = a0;
    S_00326C90 *s = a1;
    s32 i;
    s32 n;
    func_L01_004450F0(m, 1, -1);
    *(u8 *)((u8 *)m + 0x30) = 0xFF;
    n = s->w14 << 1;
    s->w14 = n;
    if (n >= 5) {
        s->w14 = 4;
    } else {
        if (n < 0) s->w14 = 0;
    }
    if (32.0f < s->f18) s->f18 = 32.0f;
    if (s->w14 > 0) {
        for (i = 0; i < s->w14; i++) {
            D_L02_001E0220[i].x = func_003824E0(0.0f, 1.0f);
            D_L02_001E0220[i].y = func_003824E0(0.0f, 1.0f);
        }
    }
    *(s32 *)&s->f4C = 0;
    func_L02_00327960(m, s);
    s->v60 = D_L02_001E1280;
}
