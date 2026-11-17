/* NTSC-U draft (2026-11-14, Claude worker): C of func_L04_00354138, the NTSC-U twin of func_L04_00355058, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division -mvu0-use-vf0-vf2 @ps2as" (src/levels/shared/L04_00354AE8.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

#include "vu0.h"

/* localdecomp:start func_L04_00354138 */
typedef struct {
    vu0_v4 vel;
    s32 x10;
    s32 x14;
    s32 x18;
    s32 x1C;
    s32 x20;
    s32 x24;
    s32 x28;
    s32 x2C;
    u32 x30;
    s32 x34;
    f32 x38;
    f32 x3C;
} S_354138;

extern u8 *D_L04_001E9618[];
extern u8 *D_L04_001E9600[];
extern void func_L04_00354758(void *);
extern void func_L04_00353C08(f32, void *, u32, u32, u32, u32, u32);
extern void func_L01_00443648(s32, f32, s32, s32, f32, f32, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00443628(void *, void *, s32, void *, f32);
extern void func_L01_004C76B8(void);
extern void func_L01_004C76F0(void);
extern s32 func_003CE740(void *, void *, s32, void *, void *);
extern s32 func_003CF790(s32, s32, f32, s32, s32);
extern void func_003886E8(void *, void *, f32);
extern void func_003BD360(void *);
extern void func_00389158(void *, void *, void *, f32);
extern void func_L01_004026A0(void *, void *);

void func_L04_00354138(u8 *p) {
    S_354138 *st;
    u8 *t;
    u8 *h;
    u8 *g;
    vu0_v4 np;
    u8 info[0x30];
    vu0_v4 dir;
    u8 info2[0x30];
    s32 hit;

    st = *(S_354138 **)(p + 0x68);
    t = p;
    if (st->x30 != 0xFFFFFFFF) {
        t = (u8 *)st->x10;
    }
    st->x24++;
    if (st->x24 >= 0x79) {
        func_L01_00443648((s32)p, 0.6f, (s32)(p + 0x10), st->x2C, *(f32 *)&st->x14, 0.0f, 0, 1, 0);
        func_L01_00441FB8(p, 1, -1);
    }
    switch (p[0x20]) {
    case 0:
        st->x38 = st->x38 + st->x3C;
        vec_add_ba(&np, p + 0x10, st);
        func_L01_00443628(info, p, st->x2C, st, *(f32 *)&st->x14);
        *(u16 *)(info + 0x1A) = *(u16 *)(p + 0xAA);
        *(s32 *)(info + 0x10) = st->x10;
        *(s32 *)(info + 0x28) = st->x30;
        info[0x19] = 1;
        info[0x18] = 0;
        func_L01_004C76B8();
        hit = func_003CE740(p + 0x10, &np, 0, t, info);
        if (hit != 0) {
            h = D_L04_001E9618[0];
            if (h != 0 && *(s16 *)(h + 0xAA) == 0x186D && h[0x20] != 2 && h[0x20] != 5) {
                h[0x20] = 4;
            }
        }
        func_L01_004C76F0();
        if (hit != 0) {
            g = (u8 *)D_L04_001E9600;
            if (*(s32 *)(g + 0x18) != 0) {
                if (*(s32 *)(g + 0x18) != st->x10) {
                    dir = *(vu0_v4 *)st;
                    func_003886E8(&dir, &dir, 2.0f);
                    dir.w = 5627.925f;
                    func_L01_00443628(info2, p, st->x2C, &dir, *(f32 *)&st->x14);
                    info2[0x19] = 1;
                    *(u16 *)(info2 + 0x1A) = *(u16 *)(p + 0xAA);
                    *(s32 *)(info2 + 0x14) = 0x10000;
                    info2[0x18] = 0;
                    *(s32 *)(info2 + 0x10) = st->x10;
                    *(s32 *)(info2 + 0x28) = st->x30;
                    func_003CF790((s32)(g + 0x20), 0, 0.3f, (s32)p, (s32)info2);
                    func_L01_00441FB8(p, 1, -1);
                    return;
                }
            } else {
                dir = *(vu0_v4 *)st;
                func_003886E8(&dir, &dir, 3.0f);
                dir.w = 5627.925f;
                func_L01_00443628(info2, p, st->x2C, &dir, *(f32 *)&st->x14);
                info2[0x19] = 1;
                *(u16 *)(info2 + 0x1A) = *(u16 *)(p + 0xAA);
                info2[0x18] = 0;
                *(s32 *)(info2 + 0x10) = st->x10;
                *(s32 *)(info2 + 0x28) = st->x30;
                func_003CF790((s32)(g + 0x20), 0, 0.6f, (s32)t, (s32)info2);
                func_L01_00441FB8(p, 1, -1);
                return;
            }
        }
        *(vu0_v4 *)(p + 0x10) = np;
        func_003886E8(&dir, st, -0.5f);
        qzero(info2);
        break;
    case 1:
        func_L04_00353C08(5.85f, p + 0x10, 0x803B0612, 0x80DA5615, 0x64FFFFFF, 0x507030FF, 0x320000FF);
        func_003BD360(p);
        return;
    }
    func_00389158(p + 0xE0, p + 0xE0, p + 0xD0, 0.0f);
    func_00389158(p + 0xC0, p + 0xC0, p + 0xD0, 0.0f);
    func_L01_004026A0(func_L04_00354758, p);
}
/* localdecomp:end func_L04_00354138 */
