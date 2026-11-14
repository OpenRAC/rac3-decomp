#include "common.h"

/* NTSC-U counterpart of func_L24_00350980 (src/levels/24_insomniac_museum/L24_0034F040.c): 208 -> 250; 0.16 -> 0.133333; 0.04 -> 0.0333333 */
#include "vu0.h"
typedef struct {
    u8 p0[0x80];
    vu0_q x80;
    vu0_q x90;
    u8 pA0[0x30];
    vu0_q xD0;
    u8 pE0[0x108 - 0xE0];
    f32 x108;
    u8 p10C[0x19E0 - 0x10C];
    s32 x19E0;
    s16 x19E4;
    u8 p19E6[0x25C0 - 0x19E6];
    u8 *x25C0;
    u8 p25C4[0x25E5 - 0x25C4];
    u8 x25E5;
} S_34F040;
extern S_34F040 D_001A4BE0;
#include "vu0.h"
extern vu0_q D_L24_001E8F60_0034FA20;
extern void func_00388830(void *, void *, f32);
extern s32 func_003CE740(void *, void *, s32, void *, void *);
#include "vu0.h"
#include "vu0.h"
extern u8 *func_0037E0B8(void *);
extern s32 func_003CE740(void *, void *, s32, void *, void *);
#include "vu0.h"
extern u8 *func_0037E0B8(void *);
#include "vu0.h"
extern void func_0037E4B8(void *, f32, f32, f32);
extern s32 func_L24_0034FA20(u8 *, void *, s32, f32, f32, f32, f32, f32, f32, f32);
#include "vu0.h"
extern void func_0037E4B8(void *, f32, f32, f32);
extern s32 func_003CE740(void *, void *, s32, void *, void *);
#include "vu0.h"
extern void func_0037E4B8(void *, f32, f32, f32);
extern void func_L01_00447D00(void *, void *, s32, f32, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003BD360(void *);

/* localdecomp:start func_L24_0034FA20 */
#include "vu0.h"
extern u8 *func_003BCFB0(s32, s32);
extern u8 *func_0037E0B8(void *);
extern void func_003C26C8(void *);
extern void func_0039FE80(s32, s32, void *);
extern s32 func_003CE740(void *, void *, s32, void *, void *);
extern void func_0037E4B8(void *, f32, f32, f32);
extern void func_L01_0040C260(f32 *, f32 *, f32 *);
extern void func_00388830(void *, void *, f32);
extern void func_L01_00447D00(void *, void *, s32, f32, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003BD360(void *);
extern vu0_q D_L24_001E8F60_0034FA20;

s32 func_L24_0034FA20(u8 *owner, void *pos, s32 tgt, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g) {
    u8 *m;
    u8 *s;
    u8 *r;
    f32 v20[4];
    f32 v30[4];
    f32 v40[4];

    m = func_003BCFB0(0x15DB, 0x80);
    if (m != 0) {
        s = *(u8 **)(m + 0x68);
        *(u8 *)(m + 0x30) = 0xFF;
        *(s16 *)(m + 0x32) = 0xFF;
        *(u8 *)(m + 0x31) = 1;
        *(f32 *)(m + 0xF8) = d;
        *(f32 *)(m + 0xF4) = e;
        *(u8 *)(m + 0x20) = 0;
        *(u8 **)(s + 0x10) = owner;
        *(vu0_q *)(m + 0x10) = *(vu0_q *)pos;
        *(f32 *)(s + 0x20) = f;
        *(f32 *)(s + 0x38) = g;
        *(s32 *)(s + 0x24) = 0;
        *(s32 *)(s + 0x28) = 0;
        *(s32 *)(s + 0x18) = tgt;
        *(f32 *)(m + 0x2C) = *(f32 *)(*(u8 **)(m + 0x24) + 0x24) * 0.25f;
        if (tgt != 0) {
            *(s32 *)(s + 0x34) = *(s16 *)((u8 *)tgt + 0xAA);
            r = func_0037E0B8((void *)tgt);
            if (r != 0) {
                *(u16 *)(r + 0x1E) |= 0x80;
            }
            *(vu0_q *)s = *(vu0_q *)((u8 *)tgt + 0x10);
            *(f32 *)(s + 0x1C) = c;
            *(f32 *)(s + 8) = *(f32 *)(s + 8) + c;
        }
        *(f32 *)(s + 0x2C) = a;
        *(f32 *)(s + 0x30) = b;
        *(s32 *)(s + 0x14) = 0xFA;
        func_003C26C8(m);
        func_0039FE80(1, 0, m);
        *(vu0_q *)v40 = 0;
        v40[2] = 0.13333334f;
        *(vu0_q *)v30 = *(vu0_q *)(D_001A4BE0.x25C0 + 0x10);
        v30[2] = ((f32 *)pos)[2];
        if (func_003CE740(v30, pos, 0, *(void **)(s + 0x10), 0) != 0) {
            *(u8 *)(m + 0xBC) = 2;
            *(vu0_q *)(m + 0x10) = D_L24_001E8F60_0034FA20;
            func_0037E4B8(v20, *(f32 *)(s + 0x20), *(f32 *)(m + 0xF8), -*(f32 *)(m + 0xF4));
            func_L01_0040C260(v40, v20, (f32 *)((u8 *)&D_L24_001E8F60_0034FA20 + 0x20));
            func_00388830(v40, v40, 0.0333333351f);
            func_L01_00447D00(m, v40, 0, 0.0f, 0.0f, 4.0f, 2.0f, 9.0f, 1.0f, 15.0f, 10, 3, 9, 0, 1, 1, -1, 0, 0x1010001);

            func_003BD360(m);
            return 0;
        }
    }
    return (s32)m;
}
/* localdecomp:end func_L24_0034FA20 */
