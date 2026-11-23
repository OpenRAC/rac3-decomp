#include "common.h"

/* NTSC-U counterpart of func_L19_003C2CC8 (src/levels/19_thran_asteroid_belt/L19_003C0938.c) */
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
extern void func_003BDA38(u8 *a0, s32 a1, u8 *a2);
extern void func_003886E8(void *, void *, f32);
s32 func_00388398(s32);
extern void func_L01_00441FB8(void *, int, int);
extern void func_003BD360(void *);
void func_L01_004412D0(s32, s32, s32);
extern void func_L01_00441FB8(void *a0, s32 a1, s32 a2);
extern void func_L01_00441FB8(void *, s32, s32);

/* localdecomp:start func_L19_003C0E40 */
typedef struct { f32 x, y, z, w; } V_3C2CC8 __attribute__((aligned(16)));
typedef struct { u8 pad[0xD0]; u8 fD0; u8 padD1[0xB]; void *fDC; u8 padE0[0x20]; } M_3C2CC8;

__asm__(".extern D_L19_001DE8C0, 4");
__asm__(".extern D_L19_001DE8C4, 4");
__asm__(".extern D_L19_001DE8C8, 4");
__asm__(".extern D_L19_001DE8CC, 4");
__asm__(".extern D_L19_001DE8D0, 4");
__asm__(".extern D_L19_001DE8D4, 4");
__asm__(".extern D_L19_001DE8D8, 4");
__asm__(".extern D_L19_001DE8DC, 4");
__asm__(".extern D_L19_001DE8E0, 4");
__asm__(".extern D_L19_001DE8E4, 4");
__asm__(".extern D_L19_001DF240_003C0E40, 4");
extern s32 D_L19_001DE8C0;
extern s32 D_L19_001DE8C4;
extern f32 D_L19_001DE8C8;
extern s32 D_L19_001DE8CC;
extern f32 D_L19_001DE8D0;
extern f32 D_L19_001DE8D4;
extern f32 D_L19_001DE8D8;
extern f32 D_L19_001DE8DC;
extern f32 D_L19_001DE8E0;
extern f32 D_L19_001DE8E4;
extern s32 D_L19_001DF240_003C0E40;
extern s32 D_L19_001DF240_003C0E40_b;
extern u8 D_001A4C60[];
extern u8 D_001A30B0[];

extern s32 func_L01_00448E90(void *);
extern f32 func_00388800(void *, void *);
extern void func_L01_00402498(void (*)(u8 *), u8 *);
extern void func_L19_003C1C68(u8 *);
extern void *func_L01_00444358(void *, s32, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_003BF4F8(void *, void *);
extern void func_L01_004479A8(void *, void *);
extern void func_L19_003C1890(u8 *);
extern s32 func_0037E0F0(void *, s32, s32);
extern s32 func_L01_00442998(s32, s32, s32);
extern s32 func_L01_00452EC8(void *);
extern s32 func_L19_003C1AA0(u8 *);
extern void func_L19_003C19A0(void *);
extern void func_0039FB08(s32);
extern f32 func_L01_00445758(void *, f32, void *, f32, f32, f32, s32);
extern void func_00389018(void *, s32, f32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern s32 func_L01_0044AF40(void *, f32);
extern f32 func_00389380(f32, f32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern u8 *func_L19_003C1B80(u8 *);
extern void func_L19_003C0D68(u8 *, u128_t *, f32 *);
extern f32 func_0037E250(f32, f32);
extern f32 func_0037E2A8(void);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern s32 func_003894A0(s32, s32, f32);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern s32 func_L01_0045FEC8(void *, void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_003C1A60(void *, s32 *, s32 *, s32 *);
extern void func_L01_00445110(void *, s32, s32);
extern void func_L01_00438908(void *, s32, s32, s32);
extern s32 func_L01_0032FE90_003C0E40(u8 *, f32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_0044ED60(void *, s32, void *, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32);

void func_L19_003C0E40(u8 *obj) {
    u8 *p;
    u8 *e;
    u8 *s;
    s32 z, y, x;
    V_3C2CC8 v90;
    V_3C2CC8 va0;
    V_3C2CC8 vb0;
    V_3C2CC8 vc0;
    s32 i;
    s32 col;
    f32 r;
    f32 w;
    f32 q;
    f32 q2;

    if (func_L01_00448E90(obj + 0x10) != 0) {
        if (obj[0x20] == 0 && func_00388800(obj + 0x10, D_001A4C60) < 9.0f) {
            func_003BD360(obj);
            return;
        }
        p = *(u8 **)(obj + 0x68);
        if (D_L19_001DE8C0 != 0)
            func_L01_00402498(func_L19_003C1C68, obj);
        e = func_L01_00444358(obj, 0x1170000, 0);
        if (e != 0) {
            if (D_L19_001DF240_003C0E40 >= *(s32 *)(p + 0xA4)) {
                func_0039FE80(2, 0, obj);
                *(f32 *)(p + 0x30) = *(f32 *)(p + 0x30) - *(f32 *)(e + 0x2C);
                if (*(f32 *)(p + 0x30) <= 0.0f)
                    func_L01_00441FB8(obj, 5, -1);
                p[0x77] = 0xFF;
                func_003BF4F8(obj, p + 0x70);
                *(s32 *)(p + 0xA4) = D_L19_001DF240_003C0E40_b + D_L19_001DE8C4;
            }
            obj[0xA8] = 0xFF;
        }
        if (obj[0x20] != 5)
            func_L01_004479A8(obj, p + 0x70);
        if (obj[0x20] == 0)
            func_L19_003C1890(obj);
        switch (obj[0x20]) {
        case 1:
            if ((D_L19_001DF240_003C0E40_b & 0x1F) == (((s32)obj >> 8) & 0x1F)) {
                if ((*(s32 *)(p + 0x88) == -1 || func_0037E0F0(D_001A4C60, *(s32 *)(p + 0x88), 0)) &&
                    (*(s32 *)(p + 0x8C) == -1 || func_L01_00442998(*(s32 *)(p + 0x8C), -1, 0) == 0))
                    func_L01_00441FB8(obj, 2, -1);
            }
            break;
        case 2:
            if (func_L01_00452EC8(obj) != 0) {
                if (*(s32 *)(p + 0x90) < 10)
                    *(s32 *)(p + 0x94) = (s32)((f32)*(s32 *)(p + 0x90) * 60.0f);
                else
                    *(s32 *)(p + 0x94) = *(s32 *)(p + 0x90);
            }
            func_00388398((s32)(p + 0x94));
            if (*(s32 *)(p + 0x98) != 0 && *(s32 *)(p + 0x94) <= 0 &&
                (D_L19_001DF240_003C0E40_b & 0xF) == (((s32)obj >> 8) & 0xF) && func_L19_003C1AA0(obj) > 0)
                func_L01_00441FB8(obj, 3, -1);
            break;
        case 3:
            if (func_L01_00452EC8(obj) != 0) {
                if (*(s32 *)(p + 0xA0) == -1 ||
                    ((M_3C2CC8 *)(D_001A30B0 + (*(s32 *)(p + 0xA0) << 7)))->fDC != obj ||
                    ((M_3C2CC8 *)(D_001A30B0 + (*(s32 *)(p + 0xA0) << 7)))->fD0 == 0)
                    *(s32 *)(p + 0xA0) = func_0039FE80(1, 4, obj);
                func_L19_003C19A0(obj);
            }
            func_L01_00445758(p + 0xB0, *(f32 *)(p + 0xAC), p + 0xA8, 0.00043633234f, 0.00043633234f, 0.026179942f, 0);
            func_00389018(p + 0xD0, 2, *(f32 *)(p + 0xB0));
            func_L01_00445758(p + 0xBC, *(f32 *)(p + 0xB8), p + 0xB4, 0.00043633234f, 0.00043633234f, 0.026179942f, 0);
            func_00389018(p + 0x110, 1, 1.5707964f - *(f32 *)(p + 0xBC));
            if (*(u16 *)(obj + 0x96) >= 0x3D && __builtin_fabsf(*(f32 *)(p + 0xB4)) < 0.00029088822f &&
                __builtin_fabsf(*(f32 *)(p + 0xA8)) < 0.00029088822f) {
                if (*(s32 *)(p + 0xA0) != -1 &&
                    ((M_3C2CC8 *)(D_001A30B0 + (*(s32 *)(p + 0xA0) << 7)))->fDC == obj &&
                    ((M_3C2CC8 *)(D_001A30B0 + (*(s32 *)(p + 0xA0) << 7)))->fD0 != 0)
                    func_0039FB08(*(s32 *)(p + 0xA0));
                *(s32 *)(p + 0xA0) = -1;
                func_L01_00441FB8(obj, 4, -1);
            }
            break;
        case 4:
            if (func_L01_00452EC8(obj) != 0) {
                if (obj[0x43] != 1)
                    func_003BE4F0(obj, 1, 0, 0);
                *(s32 *)(p + 0x98) = *(s32 *)(p + 0x98) - 1;
            }
            if (func_L01_0044AF40(obj, 8.0f) != 0) {
                func_0037E4B8(&v90, D_L19_001DE8C8, func_00389380(*(f32 *)(obj + 0xF8), *(f32 *)(p + 0xB0)), *(f32 *)(p + 0xBC));
                func_003BDA38(obj, 2, (u8 *)&va0);
                s = func_L19_003C1B80(obj);
                if (s != 0) {
                    func_L19_003C0D68(s, (u128_t *)&va0, (f32 *)&v90);
                    func_0039FE80(0, 0, obj);
                    for (i = 0; i < D_L19_001DE8CC; i++) {
                        func_003886E8(&vb0, &v90, func_0037E250(D_L19_001DE8E0, D_L19_001DE8E4));
                        r = func_0037E2A8();
                        func_0037E4B8(&vc0, D_L19_001DE8DC, r, func_0037E2A8());
                        vec_add_ab(&vb0, &vb0, &vc0);
                        w = func_0037E250(D_L19_001DE8D0, D_L19_001DE8D4);
                        qzero(&vc0);
                        vb0.w = w;
                        vc0.w = w + D_L19_001DE8D8;
                        col = func_003894A0(0x60202020, 0x60707070, func_0037E250(0.0f, 1.0f));
                        func_L01_0045FEC8(&va0, &vb0, &vc0, col, 0x30707070, 5, func_0037E1D8(0x1E) + 0x1E, 5, -1);
                    }
                }
            }
            if ((obj[0x60] & 2) && obj[0x42] == obj[0x43]) {
                if (obj[0x42] != 0)
                    func_003BE4F0(obj, 0, 0, 0);
                func_L01_00441FB8(obj, 2, -1);
            }
            break;
        case 5:
            if (*(s32 *)(p + 0xA0) != -1 &&
                ((M_3C2CC8 *)(D_001A30B0 + (*(s32 *)(p + 0xA0) << 7)))->fDC == obj &&
                ((M_3C2CC8 *)(D_001A30B0 + (*(s32 *)(p + 0xA0) << 7)))->fD0 != 0)
                func_0039FB08(*(s32 *)(p + 0xA0));
            *(s32 *)(p + 0xA0) = -1;
            if (-0.2617994f < *(f32 *)(p + 0xBC)) {
                func_L01_00445758(p + 0xBC, -1.5707964f, p + 0xB4, 0.00043633234f, 0.00043633234f, 0.026179942f, 0);
                func_00389018(p + 0x110, 1, 1.5707964f - *(f32 *)(p + 0xBC));
            }
            if (*(u16 *)(obj + 0x96) < 0x3C0) {
                V_3C2CC8 *pv = &v90;
                qzero(&v90);
                v90.z = func_0037E250(0.016666668f, 0.025000002f);
                qzero(&va0);
                v90.w = 0.1f;
                va0.w = 0.2f;
                q = func_0037E2A8();
                q2 = func_0037E250(-0.15f, 0.15f);
                vb0.x = func_00388960(q) * q2;
                vb0.y = func_00388978(q) * q2;
                vb0.z = 0.5f;
                vec_add_ba(&vb0, &vb0, obj + 0x10);
                func_L01_0045FEC8(&vb0, pv, &va0, 0x75000000, 0x60404040,
                                  func_0037E208(5, 10), func_0037E208(0x3C, 0x64),
                                  func_0037E208(0x14, 0x28), -1);
            }
            func_003C1A60(obj, &x, &y, &z);
            func_L01_00445110(&x, 0, 2);
            func_L01_00445110(&z, 0, 2);
            func_L01_00445110(&y, 0, 2);
            func_L01_00438908(obj, x, y, z);
            if (*(f32 *)(p + 0x30) < -1.0f)
                func_L01_00441FB8(obj, 6, -1);
            break;
        case 6:
            qzero(&v90);
            if (*(s32 *)(p + 0xA0) != -1 &&
                ((M_3C2CC8 *)(D_001A30B0 + (*(s32 *)(p + 0xA0) << 7)))->fDC == obj &&
                ((M_3C2CC8 *)(D_001A30B0 + (*(s32 *)(p + 0xA0) << 7)))->fD0 != 0)
                func_0039FB08(*(s32 *)(p + 0xA0));
            *(s32 *)(p + 0xA0) = -1;
            func_0039FE80(3, 0, obj);
            func_L01_0032FE90_003C0E40(obj + 0x10, 1.0f, 0, 8, 8, 8, 8, 10, 2, 0.0f, 0.0f, 2.0f,
                              0, 1, 1, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF,
                              0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_L01_0044ED60(obj, 0xFFFD, &v90, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, 0xB4, 0, 0, 0x23, 0, 3,
                              -1.0f, -1.0f, 1.0f, 1.0f);
            func_L01_004412D0((s32)obj, 0, 3);
            func_003BD360(obj);
            return;
        }
        if (*(u16 *)(obj + 0x96) < 0xFFFF)
            *(u16 *)(obj + 0x96) = *(u16 *)(obj + 0x96) + 1;
    }
}
/* localdecomp:end func_L19_003C0E40 */
