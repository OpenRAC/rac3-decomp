#include "common.h"

/* NTSC-U counterpart of func_L40_003F47B0 (src/levels/shared/L40_003F4638.c): 0.0418879 -> 0.0349066; 0.0100531 -> 0.00698132; 0.349066 -> 0.290888; 0.0048 -> 0.00333333; 0.008 -> 0.00555556 */
#include "vu0.h"
extern void func_L40_003F42F0(u8 *m);

/* localdecomp:start func_L40_003F42F0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003F47B0;
typedef struct { u8 pad[0x88]; s32 arr[1]; } T_003F47B0;
typedef struct { u8 pad0[0xD0]; u8 bD0; u8 padD1[0xB]; void *pDC; } Slot_003F47B0;
extern struct { u8 pad[0x20C]; T_003F47B0 *p20C; } D_L40_003573E0;
extern u8 D_L40_001FE1A0[];
extern f32 D_L40_0024708C;
__asm__(".extern D_L40_0024708C, 4");
extern void func_L01_0044B598(void *, s32);
extern void func_L07_0044F0E8(void *, s32, void *, f32);
extern void func_L40_003F4CE0(u8 *);
extern f32 func_L39_005B25C8_003F42F0(void);
extern void func_003BE4F0(void *, s32, s32, s32);
extern f32 func_003BE7F0(void *, s32, f32, s32);
extern s32 func_L40_0053B238(s32, s32);
extern f32 func_00388A28(f32, f32);
extern f32  func_L01_004455F0(void *, f32, f32, f32, f32, void *, s32);
extern f32 func_00389468(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_00388800(void *, void *);
extern s32 func_L39_005F0CE0(s32, s32, void *);
extern void func_L39_005F0988(s32);
extern s32 func_L01_00452EC8(void *);
extern f32 func_L01_00436500(void *);
extern void func_003BDA38(void *, s32, void *);
extern void func_L40_0042C490(void *, void *, s32, void *, s32, f32);
extern s32 func_L01_0044AF40(void *, f32);
extern void   func_L39_005B69C0(void *, void *, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, s32, f32, s32, s32, s32, s32, s32);
extern void func_L40_003F4E20(void *);
extern s32 func_003894A0(s32, s32, f32);
extern void func_L01_004026A0(void *, void *);
extern void func_L40_003F53A8();
extern void func_L39_00669B68(void *);
extern void func_L40_0053CE30(void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L39_005F08F8(void *, s32);

void func_L40_003F42F0(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    s32 *net = *(s32 **)(m + 0x90);
    s32 uid = *net;
    s32 t;
    s32 w;
    s32 w1;
    s32 c;
    f32 a7, a2, a3, a4;
    f32 d;
    f32 r;
    f32 k7, k2, k3, k4;
    u8 *home;
    V_003F47B0 tmp;
    V_003F47B0 tmp2;
    u8 *p4;

    t = D_L40_003573E0.p20C->arr[*(s32 *)(v + 0x2AC)];
    net[6] = t;
    if (t == 0) {
        func_L01_0044B598(m, 0xFF4F0000);
    } else if (t == 1) {
        func_L01_0044B598(m, 0xFF00004F);
    }
    func_L07_0044F0E8(m, 2, v + 0x260, 3.6f);
    if (v[0x3E] == 2) {
        func_L39_00669B68((void *)uid);
        func_L40_0053CE30(m);
        func_L01_00441FB8(m, 0x25, -1);
        *(s32 *)(m + 0x98) = 0;
        *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & 0xEFFF;
        func_L39_005F08F8(m, 1);
        return;
    }
    func_L40_003F4CE0(m);
    home = v + 0x2D0;
    tmp = *(V_003F47B0 *)(v + 0x2D0);
    switch (m[0x20]) {
    case 0:
        *(u16 *)(m + 0x34) |= 0x1000;
        *(f32 *)(v + 0x230) = 0.8f;
        *(f32 *)(v + 0x234) = func_L39_005B25C8_003F42F0();
        qzero(v + 0x2B0);
        *(f32 *)(v + 0x23C) = 0.0349065885f;
        *(f32 *)(v + 0x30) = *(f32 *)(v + 0x300);
        v[0x58] = 15;
        v[0x5A] = 9;
        *(f32 *)(v + 0x238) = 0.5f;
        if (m[0x43] != 0) {
            func_003BE4F0(m, 0, 0, 0);
        }
        m[0x20] = 1;
        *(V_003F47B0 *)(v + 0x1F0) = *(V_003F47B0 *)(m + 0x10);
        r = func_003BE7F0(m + 0x10, 0, 0.5f, 0);
        if (*(f32 *)(m + 0x18) - 10.0f < r) {
            *(f32 *)(v + 0x1F8) = func_003BE7F0(m + 0x10, 0, 0.5f, 0);
            *(s16 *)(v + 0x246) = 1;
        } else {
            *(f32 *)(v + 0x1F8) = *(f32 *)(m + 0x18);
            *(s16 *)(v + 0x246) = 0;
        }
        *(V_003F47B0 *)(v + 0x220) = *(V_003F47B0 *)(v + 0x1F0);
        v[0x39] = 0;
        func_L40_0053B238(uid, D_L40_003573E0.p20C->arr[*(s32 *)(v + 0x2AC)]);
        *(s32 *)(v + 0x2CC) = -1;
        break;
    case 7:
        a7 = func_00388A28(*(f32 *)(v + 0x220) - *(f32 *)(m + 0x10), *(f32 *)(v + 0x224) - *(f32 *)(m + 0x14));
        func_L01_004455F0(m + 0xF8, a7, 0.00698131742f, 0.00698131742f, 0.29088822f, v + 0x240, 0);
        if (func_00389468(*(f32 *)(m + 0xF8), a7) < 0.7853982f) {
            k7 = 0.00333333341f;
            *(f32 *)(v + 0x2B0) += func_00388960(*(f32 *)(m + 0xF8)) * k7;
            *(f32 *)(v + 0x2B4) += func_00388978(*(f32 *)(m + 0xF8)) * k7;
        }
        if (func_00388800(m + 0x10, v + 0x220) < 0.5f) {
            if (m[0x43] != 0) {
                func_003BE4F0(m, 0, 0, 3);
            }
            m[0x20] = 1;
        }
        goto slot;
    case 2:
        a2 = func_00388A28(tmp.x - *(f32 *)(m + 0x10), tmp.y - *(f32 *)(m + 0x14));
        func_L01_004455F0(m + 0xF8, a2, 0.00698131742f, 0.00698131742f, 0.29088822f, v + 0x240, 0);
        if (func_00389468(*(f32 *)(m + 0xF8), a2) < 0.7853982f) {
            k2 = 0.00555555569f;
            *(f32 *)(v + 0x2B0) += func_00388960(*(f32 *)(m + 0xF8)) * k2;
            *(f32 *)(v + 0x2B4) += func_00388978(*(f32 *)(m + 0xF8)) * k2;
        }
        if (func_00388800(m + 0x10, home) < D_L40_0024708C) {
            func_L01_00441FB8(m, 4, -1);
            if (m[0x43] != 3) {
                func_003BE4F0(m, 3, 0, 3);
            }
        }
        goto slot;
    case 3:
        a3 = func_00388A28(*(f32 *)(v + 0x1F0) - *(f32 *)(m + 0x10), *(f32 *)(v + 0x1F4) - *(f32 *)(m + 0x14));
        *(f32 *)(v + 0x230) = 0.8f;
        *(f32 *)(v + 0x238) = 0.5f;
        func_L01_004455F0(m + 0xF8, a3, 0.00698131742f, 0.00698131742f, 0.29088822f, v + 0x240, 0);
        if (func_00389468(*(f32 *)(m + 0xF8), a3) < 0.7853982f) {
            k3 = 0.00555555569f;
            *(f32 *)(v + 0x2B0) += func_00388960(*(f32 *)(m + 0xF8)) * k3;
            *(f32 *)(v + 0x2B4) += func_00388978(*(f32 *)(m + 0xF8)) * k3;
        }
        if (func_00388800(m + 0x10, v + 0x1F0) < 1.0f && fabs_asm(*(f32 *)(v + 0x1F8) - *(f32 *)(m + 0x18)) >= 3.9f) {
            if (m[0x43] != 0) {
                func_003BE4F0(m, 0, 0, 3);
            }
            m[0x20] = 1;
        }
    case 1:
    slot:
        w1 = *(s32 *)(v + 0x2CC);
        if (w1 == -1 || ((Slot_003F47B0 *)(D_L40_001FE1A0 + (w1 << 7)))->pDC != m || ((Slot_003F47B0 *)(D_L40_001FE1A0 + (w1 << 7)))->bD0 == 0) {
            *(s32 *)(v + 0x2CC) = func_L39_005F0CE0(0, 4, m);
        }
        break;
    case 4:
        if (func_L01_00452EC8(m)) {
            *(s32 *)(v + 0x2C8) = 1;
        }
        p4 = m + 0xF8;
        func_L01_004455F0(p4, func_00388A28(tmp.x - *(f32 *)(m + 0x10), tmp.y - *(f32 *)(m + 0x14)), 0.00698131742f, 0.00698131742f, 0.29088822f, v + 0x240, 0);
        d = func_L01_00436500(m);
        if (m[0x42] == m[0x43] && 9.0f <= d && d <= 14.0f) {
            if (*(s32 *)(v + 0x2C8) != 0) {
                *(s32 *)(v + 0x2C8) = 0;
                if (fabs_asm(*(f32 *)(m + 0x18) - *(f32 *)(v + 0x2D8)) < 5.0f) {
                    func_003BDA38(m, 3, &tmp2);
                    func_L40_0042C490(&tmp2, m, 0, home, 1, *(f32 *)(v + 0x304));
                }
            }
            r = (d - 9.0f) / 5.0f;
            *(f32 *)(m + 0x48) = 0.6f;
            *(f32 *)(v + 0x20C) = r / 3.0f;
            *(f32 *)(v + 0x21C) = (r + r) / 3.0f;
            k4 = 0.25f;
            a4 = func_L39_005B25C8_003F42F0();
            *(f32 *)(v + 0x204) = func_00388978(a4) * k4 * r;
            *(f32 *)(v + 0x208) = func_00388960(a4) * k4 * r;
            *(f32 *)(v + 0x214) = func_00388978(a4) * k4 * r;
            *(f32 *)(v + 0x218) = func_00388960(a4) * k4 * r;
        } else {
            *(f32 *)(m + 0x48) = 1.0f;
        }
        if (func_L01_0044AF40(m, 14.0f)) {
            *(f32 *)(v + 0x230) = 0.8f;
            *(f32 *)(v + 0x238) = 0.5f;
            if (m[0x43] != 2) {
                func_003BE4F0(m, 2, 0, 3);
            }
            m[0x20] = 3;
        }
        break;
    case 6:
        break;
    case 0x63:
        tmp2 = *(V_003F47B0 *)(m + 0x10);
        tmp2.z += 1.0f;
        func_L39_005F0CE0(1, 0, m);
        func_L39_005B69C0(m, v + 0x2B0, &tmp2, 5, 2, 4, 2.0f, 0.0f, 2.0f, 1.0f, 9.0f, 1.0f, -1, 0.0f, 0, 1, -1, 0, 0x1010001);
        w = *(s32 *)(v + 0x2CC);
        if (w != -1 && ((Slot_003F47B0 *)(D_L40_001FE1A0 + (w << 7)))->pDC == m && ((Slot_003F47B0 *)(D_L40_001FE1A0 + (w << 7)))->bD0 != 0) {
            func_L39_005F0988(w);
        }
        *(s32 *)(v + 0x2CC) = -1;
        func_L01_00441FB8(m, 0x25, -1);
        *(s32 *)(m + 0x98) = 0;
        *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & 0xEFFF;
        func_L39_005F08F8(m, 1);
        return;
    }
    func_L40_003F4E20(m);
    if (m[0x20] != 5 && (s8)m[0x20] >= 0) {
        c = 0x7F20FF20;
        if (m[0x20] == 4 || m[0x20] == 6) {
            c = 0x7F2828A0;
        }
        *(s32 *)(m + 0x78) = func_003894A0(*(s32 *)(m + 0x78), c, 0.1f);
        func_003BDA38(m, 3, v + 0x250);
        func_L01_004026A0(func_L40_003F53A8, m);
    }
}
/* localdecomp:end func_L40_003F42F0 */
