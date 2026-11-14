#include "common.h"

/* NTSC-U counterpart of func_L24_00350560 (src/levels/24_insomniac_museum/L24_0034F040.c) */
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
extern s32 func_L24_00419D90(s32, s32, s32);
extern s32 func_L01_004FC518(s32, s32);
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"
extern s32 func_003883C8(void *);
extern u8 *D_001D52FC;
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"
extern u8 *D_001D52FC;

/* localdecomp:start func_L24_0034F640 */
__asm__(".extern D_L24_001DD410, 4");
__asm__(".extern D_L24_001DD4C8, 4");
__asm__(".extern D_L24_001DD428, 4");
__asm__(".extern D_L24_001DD42C, 4");
extern f32 D_L24_001DD410;
extern f32 D_L24_001DD4C8;
extern f32 D_L24_001DD428;
extern s32 D_L24_001DD42C;
extern void func_L24_0034F4D0(u8 *);
extern void func_L24_0034DD70(void *);
extern s32 func_L01_0038A648(void *);
extern f32 func_L18_0044AA78(void *, void *);
extern s32 func_L01_0044F2E8(s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_0050BB98(s32, s32, f32);
extern void func_L24_0034E160(u8 *);
extern s32 func_L24_0034D4E8(void);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L24_0034D870(void *, s32);
extern void func_L24_0034E2D8(void *);
extern void func_L24_0034F368(u8 *);
extern void func_L24_0034DD28(void *);
extern void func_L24_0034E1A0(u8 *);
extern void func_L24_0034E5F0(u8 *);
extern void func_L01_00447D00(void *, void *, s32, f32, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003BD360(void *);

void func_L24_0034F640(u8 *obj) {
    u8 *s;
    u8 *b;
    u8 *t;
    s32 r;
    s32 ok;
    f32 k;

    s = *(u8 **)(obj + 0x68);
    func_L24_0034F4D0(obj);
    switch (obj[0x95]) {
    case 0:
        func_L24_0034DD70(obj);
        break;
    case 1:
        r = func_L01_0038A648(obj);
        k = D_L24_001DD410;
        *(f32 *)(obj + 0x2C) += (*(f32 *)(*(u8 **)(obj + 0x24) + 0x24) * k - *(f32 *)(obj + 0x2C)) * 0.05f;
        if (*(f32 *)(*(u8 **)(obj + 0x24) + 0x24) * k * 0.98f < *(f32 *)(obj + 0x2C) && r != 0) {
            *(f32 *)(obj + 0x2C) = *(f32 *)(*(u8 **)(obj + 0x24) + 0x24) * k;
            func_L01_00441FB8(obj, 0, 2);
        }
        break;
    case 2:
        *(f32 *)(s + 0x154) -= D_L24_001DD4C8;
        if (*(f32 *)(s + 0x154) < 0.0f) {
            *(f32 *)(s + 0x154) = 0.0f;
        }
        func_L01_0038A648(obj);
        b = (u8 *)&D_001A4BE0;
        t = *(u8 **)(b + 0x35C);
        if (t != 0 && *(s16 *)(t + 0xAA) == 0xF51) {
            break;
        }
        if (func_L18_0044AA78(obj, *(u8 **)(b + 0x25C0)) < D_L24_001DD428 && *(s32 *)(b + 0x25C4) != 0x31) {
            ok = func_L01_0044F2E8(0, 8, 0x855, 1, 0, 0, 0) != 0;
            if ((*(s32 *)(D_001D52FC + 0x1A4) & 0x10) && ok) {
                func_L01_004FC518(0x31, 0);
                func_L01_0050BB98(D_L24_001DD42C, 0, 15.0f);
                func_L24_0034E160(obj);
                *(u8 **)(b + 0x19E0) = obj;
                *(f32 *)(b + 0x19EC) = *(f32 *)(s + 0x30);
                *(f32 *)(b + 0x19F0) = *(s16 *)(s + 0x34);
                func_L24_00419D90(0, (s32)func_L24_0034D4E8, 1);
                *(s32 *)(*(u8 **)(b + 0x25C0) + 0x9C) = -1;
                func_L01_00441FB8(obj, 0, 3);
            }
        }
        break;
    case 3:
        *(f32 *)(s + 0x154) = D_L24_001DD4C8;
        func_L01_0038A648(obj);
        func_L24_0034E160(obj);
        func_L24_0034D870(obj, 1);
        func_L01_00441FB8(obj, 0, 4);
        break;
    case 4:
        *(f32 *)(s + 0x154) += D_L24_001DD4C8;
        if (1.0f < *(f32 *)(s + 0x154)) {
            *(f32 *)(s + 0x154) = 1.0f;
        }
        func_L24_0034E2D8(obj);
        func_L24_0034E160(obj);
        if (*(s32 *)(D_001D52FC + 0x1A4) & 0x10) {
            func_L01_00441FB8(obj, 0, 5);
        } else {
            func_L24_0034F368(obj);
        }
        break;
    case 5:
        *(f32 *)(s + 0x154) -= D_L24_001DD4C8;
        if (*(f32 *)(s + 0x154) < 0.0f) {
            *(f32 *)(s + 0x154) = 0.0f;
        }
        func_L24_0034DD28(obj);
        func_L24_0034E1A0(obj);
        func_L01_0038A648(obj);
        func_L01_00441FB8(obj, 0, 2);
        break;
    case 6:
        func_L24_0034DD28(obj);
        func_L01_00447D00(obj, s + 0x100, 0, 2.0f, 4.0f, 4.0f, 2.0f, 9.0f, 1.0f, 15.0f, 10, 3, 16, -1, 1, 1, -1, 0, 0x1010001);
        func_L24_0034E1A0(obj);
        func_L01_0038A648(obj);
        func_003BD360(obj);
        return;
    }
    func_003883C8(s + 0x166);
    func_003883C8(s + 0x168);
    func_003883C8(s + 0x16A);
    func_L24_0034E5F0(obj);
}
/* localdecomp:end func_L24_0034F640 */
