#include "common.h"

/* NTSC-U counterpart of func_L01_0032F4E0 (src/levels/shared/L01_0032C6B8.c) */
#include "vu0.h"
#include "vu0.h"
extern u8 D_001425C0[];
extern void func_00388830(void *, void *, f32);
extern void func_003886E8(void *, void *, f32);
extern void func_003BDA38(void *, s32, void *);
extern void func_00388830(void *, void *, f32);
extern u8 D_001425C0[];
extern void func_00388830(void *, void *, f32);
extern void func_003886E8(void *, void *, f32);
#include "vu0.h"
extern u8 D_001425C0[];
extern void func_00388830(void *, void *, f32);
extern void func_003886E8(void *, void *, f32);
extern u8 D_001425C0[];
extern void func_003886E8(void *, void *, f32);
extern void func_00388830(void *, void *, f32);
#include "vu0.h"
extern void func_003886E8(void *, void *, f32);
extern void func_003886E8(void *, void *, f32);
extern void func_003BDA38(void *, s32, void *);
#include "vu0.h"
extern u8 *func_0037E0B8(void *);
extern void func_003886E8(void *, void *, f32);
extern void func_003BDA38(void *, s32, void *);

/* localdecomp:start func_L01_0032EFE8 */
#include "vu0.h"

extern s32 D_L01_001DFBC0_0032EFE8;
extern s32 D_L01_001DCF08_0032EFE8;
__asm__(".extern D_L01_001DCF08_0032EFE8, 4");
extern u8 D_001425C0[];
extern u8 D_L01_002C5640_0032EFE8[];
extern void func_003BDA38(void *, s32, void *);
extern void func_L01_004C41E8_0032EFE8(void *, void *);
extern u8 *func_0037E0B8(void *);
extern void func_003886E8(void *, void *, f32);
extern void func_00388830(void *, void *, f32);
extern s32 func_L01_004A72A8_0032EFE8(s32, s32, void *, s32);
extern u8 *func_L01_003441D0_0032EFE8(void *, void *, u8, u8, u8, u8, u16, f32, f32, f32, f32, void *, s32, s32);

void func_L01_0032EFE8(u8 *a0) {
    vu0_v4 axis, pos, dir, base, off;
    u8 *v = *(u8 **)(a0 + 0x68);
    u8 *t;
    u8 *m;
    u8 *r;

    if (D_L01_001DFBC0_0032EFE8 & 1) {
        func_003BDA38(a0, 1, &base);
    } else {
        func_003BDA38(a0, 2, &base);
    }
    func_L01_004C41E8_0032EFE8(a0 + 0x10, &axis);
    if (*(f32 *)(v + 0x5C) == 0.0f && *(s32 *)(v + 0x50) != 0 && *(void **)(v + 0x64) != 0) {
        t = func_0037E0B8(*(void **)(v + 0x64));
        *(vu0_q *)&pos = *(vu0_q *)(*(u8 **)(v + 0x64) + 0x10);
        if (t != 0) {
            func_003886E8(&off, *(u8 **)(v + 0x64) + 0xE0, *(f32 *)(t + 0x10));
            vec_add_ab(&pos, &pos, &off);
        }
        vec_sub_ab(&dir, &pos, &base);
        r = D_L01_002C5640_0032EFE8 + D_001425C0[0x15] * 0xF0;
        func_00388830(&dir, &dir, *(f32 *)(r + 0x4C) * 0.016666668f);
        func_L01_004A72A8_0032EFE8(0, 0, a0, 0x1367);
        m = func_L01_003441D0_0032EFE8(&base, &dir, 0x50, 0xC8, 1, 0, 0x10E, 2.0f, 15.0f, 0.5f,
                              *(f32 *)(D_L01_002C5640_0032EFE8 + D_001425C0[0x15] * 0xF0 + 0x6C), *(void **)(v + 0x64), 0, 0);
        if (m != 0) {
            *(s32 *)(m + 0xB8) = *(s32 *)(v + 0x68);
        }
        *(s32 *)(v + 0x40) = D_L01_001DCF08_0032EFE8;
        *(s32 *)(v + 0x44) = 6;
        if (--*(s32 *)(v + 0x60) <= 0) {
            a0[0x20] = 8;
        }
        *(f32 *)(v + 0x5C) = 0.41666669f;
    }
}
/* localdecomp:end func_L01_0032EFE8 */
