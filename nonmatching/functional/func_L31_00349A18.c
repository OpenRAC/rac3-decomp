/* functional: high. 184 words differ: float constants (-pi/2, 1.0, 128.0) land in the gp pool in this build mode where retail builds them with lui/mtc1, plus frame size/regalloc; semantics (fields, call order, array fills) re-read against the asm. Needs vu0.h for the vu0_q copies (or plain 128-bit copies). */
/* localdecomp:start func_L31_00349A18 */
#include "vu0.h"
__asm__(".extern D_L31_001DD0A4, 4");
__asm__(".extern D_L31_001DD0AC, 4");
__asm__(".extern D_L31_001DD0B0, 4");
__asm__(".extern D_L31_001DD0C8, 4");
__asm__(".extern D_L31_001DD0CC, 4");
__asm__(".extern D_L31_001DD0D0, 4");
__asm__(".extern D_L31_001DD0D8, 4");
__asm__(".extern D_L31_001DD0DC, 4");
__asm__(".extern D_L31_001DD0E0, 4");
__asm__(".extern D_L31_001DD0E4, 4");
extern s32 D_L31_001DD0A4;
extern s32 D_L31_001DD0AC;
extern s32 D_L31_001DD0B0;
extern s32 D_L31_001DD0C8;
extern s32 D_L31_001DD0CC;
extern s32 D_L31_001DD0D0;
extern s32 D_L31_001DD0D8;
extern s32 D_L31_001DD0DC;
extern f32 D_L31_001DD0E0;
extern s32 D_L31_001DD0E4;
extern u8 *D_L31_001DF880;
extern u8 D_L31_001E1290[];
extern u32 D_L31_00283F90[];
extern f32 D_L31_00284010[];
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L31_003496E8(void *);
extern u8 *func_003C24B0(s32, s32);
extern void func_003C29B0(u8 *);
extern void func_003C6FE0(u8 *);
extern void func_L03_0034B218(u8 *, s32, s32, f32, s32, void *);
extern void func_L31_00349E10(void *);
void func_L31_00349A18(u8 *o) {
    u8 *p;
    vu0_q q;
    s32 i, n;
    f32 f, inv;

    *(f32 *)(o + 0xF8) = -1.5707964f;
    p = *(u8 **)(o + 0x68);
    *(s32 *)(o + 0x98) = 0;
    if (o[0x43] != 1) {
        func_003C3A10(o, 1, 0, 0);
    }
    *(s32 *)(p + 0x30) = 0;
    q = *(vu0_q *)(o + 0x10);
    *(vu0_q *)(p + 0x10) = q;
    if (*(s32 *)(p + 0x20) != -1) {
        q = *(vu0_q *)(D_L31_001DF880 + *(s32 *)(p + 0x20) * 0x80 + 0x30);
    }
    *(vu0_q *)p = q;
    *(s32 *)(p + 0x44) = 0;
    *(s32 *)(p + 0x40) = -1;
    func_L31_003496E8(o);
    n = D_L31_001DD0B0;
    for (i = 0; i < n; i++) {
        f = *(f32 *)(p + 0x30);
        if (*(s32 *)(p + 0x28) != 0 && *(s32 *)(p + 0x2C) != 0) {
            f = 1.0f - f;
        }
        *(f32 *)(p + 0x50 + i * 4) = f;
    }
    o[0x40] = *(u8 *)&D_L31_001DD0AC;
    o[0x41] = *(u8 *)&D_L31_001DD0AC + 1;
    for (i = 0; i < D_L31_001DD0AC; i++) {
        u8 *c = func_003C24B0(0x1649, 0xA0);
        *(u8 **)(p + 0x90 + i * 4) = c;
        if (c != 0) {
            *(f32 *)(c + 0xF8) = -1.5707964f;
            *(u16 *)(c + 0x34) &= 0xFFFB;
            *(u16 *)(c + 0x34) &= 0xFFFD;
            *(u16 *)(c + 0x34) &= 0xFFFE;
            *(s16 *)(c + 0x32) = 0xFF;
            *(s32 *)(*(u8 **)(c + 0x68) + 0x44) = 1;
            inv = *(f32 *)(o + 0x2C) / *(f32 *)(*(u8 **)(o + 0x24) + 0x24);
            *(f32 *)(c + 0x2C) = *(f32 *)(*(u8 **)(c + 0x24) + 0x24) * inv;
            *(vu0_q *)(c + 0x10) = *(vu0_q *)(o + 0x10);
            c[0x42] = o[0x43];
            c[0x43] = o[0x43];
            c[0x40] = *(u8 *)&D_L31_001DD0AC - 1 - i;
            c[0x41] = *(u8 *)&D_L31_001DD0AC - i;
            func_003C29B0(c);
            func_003C6FE0(c);
        }
    }
    if (D_L31_001DD0A4 == 0) {
        f32 cnt = (f32)D_L31_001DD0B0;
        D_L31_001DD0A4 = 0;
        for (i = 0; i < 32; i++) {
            s32 half = i / 2;
            f = (f32)half / cnt;
            D_L31_00283F90[i] = ((s32)(f * 128.0f) << 24) | (D_L31_001DD0C8 << 16) | (D_L31_001DD0CC << 8) | D_L31_001DD0D0;
            D_L31_00284010[i * 2] = (i & 1) ? 1.0f : 0.0f;
            D_L31_00284010[i * 2 + 1] = f;
        }
        func_L03_0034B218(D_L31_001E1290, D_L31_001DD0D8, D_L31_001DD0DC, D_L31_001DD0E0, D_L31_001DD0E4, func_L31_00349E10);
    }
}
/* localdecomp:end func_L31_00349A18 */
