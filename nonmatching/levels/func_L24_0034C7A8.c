/* func_L24_0034C7A8: 2 differences (level 24, file L24_0034C618.c, @ps2as). Two independent instructions in the second
   loop's setup are swapped: retail has `move $s1,$s4` (the copy of the second buffer's address) before `addiu $s0,$s5,4`
   (the pointer to the second array), this C has them the other way round. Everything else matches, including the
   register roles of both loops (the second loop takes a separate counter `m`, which swaps $s1/$s2 as retail has them).
   Tried (about 20 compiles): declaration order of q/p/m, p as `s32 *q; q + 1`, a second pointer p2, setting m first,
   a separate pointer copy of the buffer for one or both loops (frame size changes, 10 to 60 differences). */
#include "common.h"
extern void func_003C2F58(void *, s32, void *);
extern void func_L24_0034C8D0(void *, void *, void *);

void func_L24_0034C7A8(u8 *obj) {
    u8 a[16];
    u8 b[16];
    u8 *s = *(u8 **)(obj + 0x68);


    s32 *p;
    s32 n;
    s32 m;
    u8 *q;
    f32 f;

    f = *(f32 *)(s + 0x580) + 0.1f;
    *(f32 *)(s + 0x580) = f;
    if (f >= 4.0f) {
        *(f32 *)(s + 0x580) = f - 4.0f;
    }
    q = s + 0x560;
    p = (s32 *)(s + 0x544);
    n = 3;
    do {
        func_003C2F58((void *)p[-1], 0, a);
        n--;
        func_003C2F58((void *)p[0], 1, b);
        p++;
        func_L24_0034C8D0(obj, a, b);
    } while (n >= 0);
    m = 3;
    p = (s32 *)(q + 4);
    do {
        func_003C2F58((void *)p[-1], 0, a);
        m--;
        func_003C2F58((void *)p[0], 1, b);
        p++;
        func_L24_0034C8D0(obj, a, b);
    } while (m >= 0);
}
