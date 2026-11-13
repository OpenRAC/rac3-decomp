/* func_L24_0034C348: 98 differences (level 24, file L24_0034A2C8.c, -mvu0-use-vf0-vf2 @ps2as). The two chain loops
   over the moby pointers at +0x540 and +0x560 (func_L24_0034C618 or func_L01_0044FD88 per link) match once they index
   from 1 (giving retail's -4/0 pointer offsets) and the base pointer a is assigned in both arms after the calls (so
   loop.c does not hoist it). What differs is register allocation in the third loop and the saved registers: retail
   keeps the sp+0x10 vector pointer in $s7 from the start and copies it to $s3 for the third loop, uses $s6 as that
   loop's counter and $s5 for s+0x250; this C takes other registers. Tried (about 12 compiles): a separate counter j, a
   pointer copy pw = pv before the loop, index from 0 (+4 offsets), the base hoisted or recomputed in the call. */
#include "common.h"
#include "vu0.h"
extern void func_L01_0044FD88(void *, void *, s32, s32);
extern void func_L24_0034C618(s32, s32, s32, void *, s32);
extern void func_L01_00446780(u8 *, u8 *, s32, s32, s32, s32, f32, f32, f32);
extern void func_L03_00433C70(void *, void *, void *, s32, s32, s32, s32, f32, f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_L01_00404808(void *, void *);
extern void func_L24_0034C7A8(u8 *);
__asm__(".extern D_L24_001DD398, 4");
extern f32 D_L24_001DD398;

void func_L24_0034C348(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    u8 **a;
    u8 **b;
    u8 **c;
    vu0_q t;
    f32 v0[4];
    f32 v1[4];
    s32 i;
    s32 j;
    f32 *pw;
    f32 *pv;

    func_L01_0044FD88(obj, *(u8 **)(s + 0x540), 1, 0);
    c = (u8 **)(s + 0x540);
    pv = v1;
    for (i = 1; i < 5; i++) {
        if (*(f32 *)(s + 0x584) >= D_L24_001DD398) {
            *(vu0_q *)v0 = *(vu0_q *)(s + 0x250 + (i - 1) * 16);
            func_L24_0034C618((s32)c[i - 1], (s32)c[i], 0, v0, 0);
            a = (u8 **)(s + 0x540);
        } else {
            func_L01_0044FD88(c[i - 1], c[i], 0, 0);
            a = (u8 **)(s + 0x540);
        }
    }
    func_L01_0044FD88(obj, *(u8 **)(s + 0x560), 0, 0);
    b = (u8 **)(s + 0x560);
    for (i = 1; i < 5; i++) {
        if (*(f32 *)(s + 0x584) >= D_L24_001DD398) {
            *(vu0_q *)v0 = *(vu0_q *)(s + 0x380 + (i - 1) * 16);
            func_L24_0034C618((s32)b[i - 1], (s32)b[i], 0, v0, 0);
        } else {
            func_L01_0044FD88(b[i - 1], b[i], 0, 0);
        }
    }
    pw = pv;
    for (j = 1; j < 5; j++) {
        func_L01_00446780(obj, s + 0x250 + (j - 1) * 16, 0x8000001, 0, 1, 0, 0.45f, 20.0f, 3.0f);
        func_L01_00446780(obj, s + 0x380 + (j - 1) * 16, 0x8000001, 0, 1, 0, 0.45f, 20.0f, 3.0f);
        func_003C2F58(a[j - 1], 0, v0);
        func_003C2F58(a[j], 1, pw);
        func_L03_00433C70(obj, v0, pw, 0x8000001, 0, 1, 0, 20.0f, 3.0f);
        func_003C2F58(b[j - 1], 0, v0);
        func_003C2F58(b[j], 1, pw);
        func_L03_00433C70(obj, v0, pw, 0x8000001, 0, 1, 0, 20.0f, 3.0f);
    }
    func_L01_00404808(func_L24_0034C7A8, obj);
}
