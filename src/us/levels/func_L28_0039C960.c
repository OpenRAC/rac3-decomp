#include "common.h"

/* NTSC-U counterpart of func_L28_0039E820 (src/levels/28_aquatos_sewers/L28_0039D530.c): 17 -> 20 */
#include "vu0.h"

/* localdecomp:start func_L28_0039C960 */
typedef int q_0039E820 __attribute__((mode(TI)));
extern s32 func_L28_0039CD08(void *);
extern void func_003BD360(void *);
extern u8 *func_L01_00444358(void *, s32, s32);
extern s32 func_003883C8(void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern u8 func_L01_00449C10(void *);
extern void func_00388830(void *, void *, f32);
extern f32 func_00388730(void *, void *);
extern void func_00388758(void *, void *, void *);
extern void func_L02_003A3218(void *);
extern s32 func_L01_0044F5E8(void *, void *, s32);
extern void func_L28_0039CEF8(u8 *);
extern void func_L01_004479A8(void *, void *);
extern void func_003BF4F8(void *, void *);
extern void func_L01_004538E0(void *, s32);
extern void func_L01_004539A8(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
s32 func_L28_0039C960(u8 *a0) {
    u8 *st = *(u8 **)(a0 + 0x68);
    u8 *p;
    s32 t;
    vu0_v4 v;
    if (a0[0x20] == 0) {
        if (func_L28_0039CD08(a0) != 0) return 1;
    }
    if (*(f32 *)(a0 + 0x18) < *(f32 *)(st + 0x1A8) - 200.0f) {
        func_003BD360(a0);
        return 1;
    }
    func_L01_004479A8(a0, st + 0x180);
    p = func_L01_00444358(a0, 0x10000, 0);
    if (func_003883C8(st + 0x36) == 0) p = 0;
    if (p != 0) {
        *(f32 *)(st + 0x30) -= *(f32 *)(p + 0x2C);
        if (*(u8 **)(p + 0x20) != a0) goto chase;
    } else {
        if (!(*(f32 *)(st + 0x30) <= 0.0f)) goto done;
        if (a0[0x20] == 8) goto done;
        if (a0[0x20] == 9) goto done;
    }
    func_L01_00441FB8(a0, 9, -1);
    goto hit;
chase:
            st[0x47] = func_L01_00449C10(*(u8 **)(p + 0x20));
            func_00388830(&v, p + 0x10, -1.0f);
            if (abs_asm(func_00388730(&v, a0 + 0xE0) < 0.9f)) *(q_0039E820 *)(a0 + 0xC0) = *(q_0039E820 *)&v;
            func_00388758(a0 + 0xD0, a0 + 0xE0, a0 + 0xC0);
            func_00388830(a0 + 0xD0, a0 + 0xD0, 1.0f);
            func_00388758(a0 + 0xC0, a0 + 0xD0, a0 + 0xE0);
            func_00388830(a0 + 0xC0, a0 + 0xC0, 1.0f);
            *(s16 *)(st + 0x36) = 0x14;
            func_003BF4F8(a0, st + 0x180);
            func_L01_00441FB8(a0, 8, -1);
hit:
    func_L02_003A3218(a0);
done:
    a0[0xA8] = 0xFF;
    func_L01_0044F5E8(a0, st + 0x30, 0);
    if (st[0x5E] != 0) {
        func_L28_0039CEF8(a0);
        return 1;
    }
    if (st[0x3E] == 2) return 1;
    if (st[0x5F] != 0) {
        func_L01_004538E0(a0, 5);
        t = a0[0x20];
        if ((u32)(t - 3) < 2 || t == 1) {
            func_L01_004539A8(a0, *(s32 *)(st + 0x190), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(st + 0x194), 10.0f, 1.0f);
        } else {
            func_L01_004539A8(a0, *(s32 *)(st + 0x198), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(st + 0x19C), 10.0f, 1.0f);
        }
    } else {
        func_L01_004538E0(a0, 3);
        t = a0[0x20];
        if ((u32)(t - 3) < 2 || t == 1) {
            func_L01_004539A8(a0, *(s32 *)(st + 0x190), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(st + 0x194), 10.0f, 1.0f);
        } else {
            func_L01_004539A8(a0, *(s32 *)(st + 0x198), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(st + 0x19C), 10.0f, 1.0f);
        }
    }
    return 0;
}
/* localdecomp:end func_L28_0039C960 */
