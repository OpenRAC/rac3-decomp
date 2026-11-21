#include "common.h"

/* NTSC-U counterpart of func_L11_0033CFB0 (src/levels/shared/L11_0033CFB0.c): 60 Hz step 1/60.0f for PAL 0.02f, NTSC-U data addresses */
/* localdecomp:start func_L11_0033C2F8 */
#include "vu0.h"
typedef struct {
    f32 f00;
    f32 f04;
    u8 pad08[8];
    f32 f10[4];
    f32 f20[4];
    f32 f30[4];
} P_0033C2F8;

extern void func_003BFC18(void *, void *, s32);
extern void func_L01_0044E358(void *, void *, void *);
extern void func_00388830(void *, void *, f32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_0037E250(f32, f32);
extern f32 func_003887C8(void *, void *);
extern s32 func_0039FE80(s32, s32, void *);
extern f32 func_00388730(void *, void *);
extern void func_L11_0033C658(void *);
extern void func_L11_0033C840(void *);
extern void func_L01_00402498(void *, void *);
extern f32 func_00389380(f32, f32);
extern f32 func_00388978(f32);
extern s32 func_003894A0(s32, s32, f32);
extern u8 D_L11_001E84E0[];
extern f32 D_L11_001DBBE8;
extern s32 D_001D545C;
extern u8 D_001A4C60[];
extern u8 D_001A4EC0[];
extern f32 D_L11_001DCFD8[2], D_L11_001DCFE0[2];
extern f32 D_L11_001DCFF0;
extern s32 D_L11_001DCFE8[2];
__asm__(".extern D_L11_001DCFE8, 8");

void func_L11_0033C2F8(u8 *obj) {
    vu0_v4 v0;
    vu0_v4 v1;
    vu0_v4 u20;
    vu0_v4 u30;
    vu0_v4 v40;
    vu0_v4 v50;
    vu0_v4 v60;
    vu0_v4 v70;
    vu0_v4 u80;
    vu0_v4 u90;
    P_0033C2F8 *p;
    s32 i;
    f32 c;
    u8 *hero;
    u8 state;

    state = obj[0x20];
    p = *(P_0033C2F8 **)(obj + 0x68);
    switch (state) {
    case 0:
        *(u16 *)(obj + 0x34) |= 0x100;
        func_003BFC18(obj + 0x10, &v0, 0);
        func_L01_0044E358(obj + 0xC0, &v0, &v1);
        func_00388830(&v40, obj + 0xE0, 0.5f);
        func_00388830(&v50, obj + 0xE0, -4.0f);
        vec_add_ba(&v40, &v40, obj + 0x10);
        vec_add_ba(&v50, &v50, obj + 0x10);
        if (func_003CE740(&v40, &v50, 2, obj, 0) != 0) {
            *(vu0_q *)(obj + 0x10) = *(vu0_q *)D_L11_001E84E0;
            func_00388830(&v50, obj + 0xE0, -0.1f);
            vec_add_ba(obj + 0x10, &v50, obj + 0x10);
            func_003BFC18(obj + 0x10, &v60, 0);
            func_L01_0044E358(obj + 0xC0, &v60, &v70);
        }
        func_L01_00441FB8(obj, 1, -1);
        *(s16 *)(obj + 0x32) = 0xFF;
        for (i = 0; i < 4; i++) {
            p->f20[i] = (f32)i * 0.25f;
            p->f30[i] = func_0037E250(D_L11_001DCFD8[0], D_L11_001DCFD8[1]) * 0.0166666675f;
            p->f10[i] = func_0037E250(D_L11_001DCFE0[0], D_L11_001DCFE0[1]);
        }
        break;
    case 1:
        if (D_001D545C == 0xB) {
            func_003BFC18(obj + 0x10, &v0, 0);
            func_L01_0044E358(obj + 0xC0, &v0, &v1);
        }
        if (func_003887C8(D_001A4C60, obj + 0x10) < 3.0f) {
            D_L11_001DBBE8 = p->f00;
        }
        hero = D_001A4C60 - 0x80;
        if (*(s32 *)(hero + 0x25C4) == 0x86) {
            if (*(s32 *)(hero + 0x1B8) == state) {
                func_0039FE80(0, 0, obj);
            }
        }
        if (func_00388730(obj + 0xE0, D_001A4EC0) < -0.6f) {
            func_L11_0033C658(obj);
            func_L01_00402498(func_L11_0033C840, obj);
        }
        break;
    }
    if (obj[0x31] != 0) {
        c = func_00389380(p->f04, D_L11_001DCFF0 * 0.017453292f * 0.0166666675f);
        p->f04 = c;
        c = func_00388978(c);
        c = c * c;
        c = c * c;
        *(s32 *)(obj + 0x78) = func_003894A0(D_L11_001DCFE8[0], D_L11_001DCFE8[1], c * c);
    }
}
/* localdecomp:end func_L11_0033C2F8 */
