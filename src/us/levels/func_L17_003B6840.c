#include "common.h"

/* NTSC-U counterpart of func_L17_003B8400 (src/levels/shared/L17_003B8400.c): the 60 Hz smoothing factor 0.07f (PAL 0.084f = 0.07f * 1.2) */
/* localdecomp:start func_L17_003B6840 */
#include "vu0.h"

extern void func_00388BD0(void *, void *);
extern f32 func_00388770(void *);
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E1D8(s32);
extern void func_00388830(void *, void *, f32);
extern void func_L01_004026A0(void *, void *);
extern s32 func_L01_00421DE0(void *, s32, f32, f32);
extern void func_L17_003B6A98(u8 *);
extern void func_L17_003B6B88(u8 *);
extern void func_L17_003B6F58(u8 *);
extern s32 D_001D545C;
extern f32 D_L17_001DE604;
__asm__(".extern D_L17_001DE604, 4");
extern s32 D_L17_001DE5A0;
__asm__(".extern D_L17_001DE5A0, 4");
extern s32 D_L17_001DE5E8;
__asm__(".extern D_L17_001DE5E8, 4");
extern s32 D_L17_001DE5E4;
__asm__(".extern D_L17_001DE5E4, 4");
typedef int Q_003B6840 __attribute__((mode(TI)));
static __inline__ void qcopy_003B6840(void *d, void *s) { *(Q_003B6840 *)d = *(Q_003B6840 *)s; }
extern u8 D_L17_002A3270[];

void func_L17_003B6840(u8 *a0) {
    u8 *st = *(u8 **)(a0 + 0x68);
    u8 *t;
    s32 i;
    vu0_v4 v;
    vu0_v4 w;

    func_00388BD0(a0 + 0xC0, a0 + 0xF0);
    *(vu0_v4 *)(st + 0x10) = *(vu0_v4 *)st = *(vu0_v4 *)(a0 + 0x10);
    t = *(u8 **)(a0 + 0xB8);
    if (t != 0 && *(s16 *)(t + 0xAA) == 0x1AF1) {
        vec_sub_ba(&v, *(u8 **)(t + 0x68) + 0xD50, t + 0x10);
        D_L17_001DE604 = func_00388770(&v) / 15.0f;
    }
    *(f32 *)(st + 0x20) += (6.0f - *(f32 *)(st + 0x20)) * 0.07f + 12.0f;
    v.x = 0.0f;
    v.y = *(f32 *)(st + 0x20);
    v.z = 0.0f;
    vec_add_ab(st + 0x10, st, &v);
    v = *(vu0_v4 *)(st + 0x10);
    if (*(u8 **)(a0 + 0xB8) != 0 && *(s16 *)(*(u8 **)(a0 + 0xB8) + 0xAA) == 0x1AF1) {
        D_L17_001DE5A0 = func_0037E208(0xD, 0x14);
        D_L17_001DE5E8 = 0x800030;
        D_L17_001DE5E4 = 0x7F007F;
    } else {
        switch (D_001D545C) {
        default:
            D_L17_001DE5A0 = func_0037E1D8(20);
            break;
        case 4:
            D_L17_001DE5A0 = 20;
            break;
        case 11:
            D_L17_001DE5A0 = 20;
            break;
        }
    }
    func_L17_003B6A98(a0);
    func_L17_003B6B88(a0);
    for (i = D_L17_001DE5A0 - 4; i < D_L17_001DE5A0; i++) {
        func_00388830(&w, a0 + 0xC0, D_L17_001DE604 * (f32)i);
        vec_add_ab(&w, &w, a0 + 0x10);
        qcopy_003B6840(D_L17_002A3270 + *(s32 *)(st + 0x38) * 0x280 + i * 16, &w);
    }
    func_L01_004026A0(func_L17_003B6F58, a0);
    if (a0[0x20] == 0) {
        *(s32 *)(st + 0x24) = func_L01_00421DE0(st, 0, 0.0f, 0.0f);
        a0[0x20] = 1;
        *(s32 *)(st + 0x2C) = D_L17_001DE5A0;
        *(s32 *)(st + 0x30) = -1;
    }
}
/* localdecomp:end func_L17_003B6840 */
