/* func_L40_003F47B0: near miss by c15 (2026-11-14), 6 aligned rows (two delay-slot/schedule swaps) at level 40.
   Flags: needs the file's line plus @ps2as (inline float constants; the file's other C still MATCHes with it)
   and a config/levels/divs_nops.txt line "func_L40_003F47B0 2 2 2" (three div.s in case 4).
   Left: case 0, first func_003C3D30 call: retail sets $a1 before `mov.s $f12, $f20` (second call: f12 first);
         case 3: retail's delay slot of the jal 0x484890 is `swc1 $f0, 0x230` (store sank past `move $a2, $zero`).
   Tried without gain: per-case variables, statement moves (movehill over cases 0 and 3), adjacent swaps,
   prototype float positions (448728 / 3C3D30 / 5B8978 chosen by protoperm), return-type flips. */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003F47B0;
typedef struct { u8 pad[0x88]; s32 arr[1]; } T_003F47B0;
typedef struct { u8 pad0[0xD0]; u8 bD0; u8 padD1[0xB]; void *pDC; } Slot_003F47B0;
extern struct { u8 pad[0x20C]; T_003F47B0 *p20C; } D_L40_00357260;
extern u8 D_001FE020[];
#define SLOT_003F47B0(w) ((Slot_003F47B0 *)(D_001FE020 + ((w) << 7)))
extern f32 D_L40_00246F0C;
__asm__(".extern D_L40_00246F0C, 4");
extern void func_L01_0044E820(void *, s32);
extern void func_L07_004522E8(void *, s32, void *, f32);
extern void func_L40_003F51A0(void *);
extern f32 func_L39_005B44C8(void);
extern void func_003C3A10(void *, s32, s32, s32);
extern f32  func_003C3D30(void *, f32, s32, s32);
extern s32 func_L40_0053DAE8(s32, s32);
extern f32 func_0038D160(f32, f32);
extern void  func_L01_00448728(void *, f32, f32, f32, f32, void *, s32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038CF38(void *, void *);
extern s32 func_L39_005F33E0(s32, s32, void *);
extern void func_L39_005F3088(s32);
extern s32 func_L01_004561B8(void *);
extern f32 func_L01_004395E0(void *);
extern void func_003C2F58(void *, s32, void *);
extern void func_L40_0042CE98(void *, void *, s32, void *, s32, f32);
extern s32 func_L01_0044E1B8(void *, f32);
extern void   func_L39_005B8978(void *, void *, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, s32, f32, s32, s32, s32, s32, s32);
extern void func_L40_003F52E0(void *);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_L01_00404A10(void *, void *);
extern void func_L40_003F5880();
extern void func_L39_0066C470(void *);
extern void func_L40_0053F6E0(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L39_005F2FF8(void *, s32);

void func_L40_003F47B0(u8 *m) {
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

    t = D_L40_00357260.p20C->arr[*(s32 *)(v + 0x2AC)];
    net[6] = t;
    if (t == 0) {
        func_L01_0044E820(m, 0xFF4F0000);
    } else if (t == 1) {
        func_L01_0044E820(m, 0xFF00004F);
    }
    func_L07_004522E8(m, 2, v + 0x260, 3.6f);
    if (v[0x3E] == 2) {
        func_L39_0066C470((void *)uid);
        func_L40_0053F6E0(m);
        func_L01_004450F0(m, 0x25, -1);
        *(s32 *)(m + 0x98) = 0;
        *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & 0xEFFF;
        func_L39_005F2FF8(m, 1);
        return;
    }
    func_L40_003F51A0(m);
    home = v + 0x2D0;
    tmp = *(V_003F47B0 *)(v + 0x2D0);
    switch (m[0x20]) {
    case 0:
        *(u16 *)(m + 0x34) |= 0x1000;
        *(f32 *)(v + 0x230) = 0.8f;
        *(f32 *)(v + 0x234) = func_L39_005B44C8();
        qzero(v + 0x2B0);
        *(f32 *)(v + 0x23C) = 0.041887905f;
        *(f32 *)(v + 0x30) = *(f32 *)(v + 0x300);
        v[0x58] = 15;
        v[0x5A] = 9;
        *(f32 *)(v + 0x238) = 0.5f;
        if (m[0x43] != 0) {
            func_003C3A10(m, 0, 0, 0);
        }
        m[0x20] = 1;
        *(V_003F47B0 *)(v + 0x1F0) = *(V_003F47B0 *)(m + 0x10);
        r = func_003C3D30(m + 0x10, 0.5f, 0, 0);
        if (*(f32 *)(m + 0x18) - 10.0f < r) {
            *(f32 *)(v + 0x1F8) = func_003C3D30(m + 0x10, 0.5f, 0, 0);
            *(s16 *)(v + 0x246) = 1;
        } else {
            *(f32 *)(v + 0x1F8) = *(f32 *)(m + 0x18);
            *(s16 *)(v + 0x246) = 0;
        }
        *(V_003F47B0 *)(v + 0x220) = *(V_003F47B0 *)(v + 0x1F0);
        v[0x39] = 0;
        func_L40_0053DAE8(uid, D_L40_00357260.p20C->arr[*(s32 *)(v + 0x2AC)]);
        *(s32 *)(v + 0x2CC) = -1;
        break;
    case 7:
        a7 = func_0038D160(*(f32 *)(v + 0x220) - *(f32 *)(m + 0x10), *(f32 *)(v + 0x224) - *(f32 *)(m + 0x14));
        func_L01_00448728(m + 0xF8, a7, 0.010053097f, 0.010053097f, 0.34906587f, v + 0x240, 0);
        if (func_0038DBA0(*(f32 *)(m + 0xF8), a7) < 0.7853982f) {
            k7 = 0.0048f;
            *(f32 *)(v + 0x2B0) += func_0038D098(*(f32 *)(m + 0xF8)) * k7;
            *(f32 *)(v + 0x2B4) += func_0038D0B0(*(f32 *)(m + 0xF8)) * k7;
        }
        if (func_0038CF38(m + 0x10, v + 0x220) < 0.5f) {
            if (m[0x43] != 0) {
                func_003C3A10(m, 0, 0, 3);
            }
            m[0x20] = 1;
        }
        goto slot;
    case 2:
        a2 = func_0038D160(tmp.x - *(f32 *)(m + 0x10), tmp.y - *(f32 *)(m + 0x14));
        func_L01_00448728(m + 0xF8, a2, 0.010053097f, 0.010053097f, 0.34906587f, v + 0x240, 0);
        if (func_0038DBA0(*(f32 *)(m + 0xF8), a2) < 0.7853982f) {
            k2 = 0.008f;
            *(f32 *)(v + 0x2B0) += func_0038D098(*(f32 *)(m + 0xF8)) * k2;
            *(f32 *)(v + 0x2B4) += func_0038D0B0(*(f32 *)(m + 0xF8)) * k2;
        }
        if (func_0038CF38(m + 0x10, home) < D_L40_00246F0C) {
            func_L01_004450F0(m, 4, -1);
            if (m[0x43] != 3) {
                func_003C3A10(m, 3, 0, 3);
            }
        }
        goto slot;
    case 3:
        a3 = func_0038D160(*(f32 *)(v + 0x1F0) - *(f32 *)(m + 0x10), *(f32 *)(v + 0x1F4) - *(f32 *)(m + 0x14));
        *(f32 *)(v + 0x230) = 0.8f;
        *(f32 *)(v + 0x238) = 0.5f;
        func_L01_00448728(m + 0xF8, a3, 0.010053097f, 0.010053097f, 0.34906587f, v + 0x240, 0);
        if (func_0038DBA0(*(f32 *)(m + 0xF8), a3) < 0.7853982f) {
            k3 = 0.008f;
            *(f32 *)(v + 0x2B0) += func_0038D098(*(f32 *)(m + 0xF8)) * k3;
            *(f32 *)(v + 0x2B4) += func_0038D0B0(*(f32 *)(m + 0xF8)) * k3;
        }
        if (func_0038CF38(m + 0x10, v + 0x1F0) < 1.0f && fabs_asm(*(f32 *)(v + 0x1F8) - *(f32 *)(m + 0x18)) >= 3.9f) {
            if (m[0x43] != 0) {
                func_003C3A10(m, 0, 0, 3);
            }
            m[0x20] = 1;
        }
    case 1:
    slot:
        w1 = *(s32 *)(v + 0x2CC);
        if (w1 == -1 || SLOT_003F47B0(w1)->pDC != m || SLOT_003F47B0(w1)->bD0 == 0) {
            *(s32 *)(v + 0x2CC) = func_L39_005F33E0(0, 4, m);
        }
        break;
    case 4:
        if (func_L01_004561B8(m)) {
            *(s32 *)(v + 0x2C8) = 1;
        }
        p4 = m + 0xF8;
        func_L01_00448728(p4, func_0038D160(tmp.x - *(f32 *)(m + 0x10), tmp.y - *(f32 *)(m + 0x14)), 0.010053097f, 0.010053097f, 0.34906587f, v + 0x240, 0);
        d = func_L01_004395E0(m);
        if (m[0x42] == m[0x43] && 9.0f <= d && d <= 14.0f) {
            if (*(s32 *)(v + 0x2C8) != 0) {
                *(s32 *)(v + 0x2C8) = 0;
                if (fabs_asm(*(f32 *)(m + 0x18) - *(f32 *)(v + 0x2D8)) < 5.0f) {
                    func_003C2F58(m, 3, &tmp2);
                    func_L40_0042CE98(&tmp2, m, 0, home, 1, *(f32 *)(v + 0x304));
                }
            }
            r = (d - 9.0f) / 5.0f;
            *(f32 *)(m + 0x48) = 0.6f;
            *(f32 *)(v + 0x20C) = r / 3.0f;
            *(f32 *)(v + 0x21C) = (r + r) / 3.0f;
            k4 = 0.25f;
            a4 = func_L39_005B44C8();
            *(f32 *)(v + 0x204) = func_0038D0B0(a4) * k4 * r;
            *(f32 *)(v + 0x208) = func_0038D098(a4) * k4 * r;
            *(f32 *)(v + 0x214) = func_0038D0B0(a4) * k4 * r;
            *(f32 *)(v + 0x218) = func_0038D098(a4) * k4 * r;
        } else {
            *(f32 *)(m + 0x48) = 1.0f;
        }
        if (func_L01_0044E1B8(m, 14.0f)) {
            *(f32 *)(v + 0x230) = 0.8f;
            *(f32 *)(v + 0x238) = 0.5f;
            if (m[0x43] != 2) {
                func_003C3A10(m, 2, 0, 3);
            }
            m[0x20] = 3;
        }
        break;
    case 6:
        break;
    case 0x63:
        tmp2 = *(V_003F47B0 *)(m + 0x10);
        tmp2.z += 1.0f;
        func_L39_005F33E0(1, 0, m);
        func_L39_005B8978(m, v + 0x2B0, &tmp2, 5, 2, 4, 2.0f, 0.0f, 2.0f, 1.0f, 9.0f, 1.0f, -1, 0.0f, 0, 1, -1, 0, 0x1010001);
        w = *(s32 *)(v + 0x2CC);
        if (w != -1 && SLOT_003F47B0(w)->pDC == m && SLOT_003F47B0(w)->bD0 != 0) {
            func_L39_005F3088(w);
        }
        *(s32 *)(v + 0x2CC) = -1;
        func_L01_004450F0(m, 0x25, -1);
        *(s32 *)(m + 0x98) = 0;
        *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & 0xEFFF;
        func_L39_005F2FF8(m, 1);
        return;
    }
    func_L40_003F52E0(m);
    if (m[0x20] != 5 && (s8)m[0x20] >= 0) {
        c = 0x7F20FF20;
        if (m[0x20] == 4 || m[0x20] == 6) {
            c = 0x7F2828A0;
        }
        *(s32 *)(m + 0x78) = func_0038DBD8(*(s32 *)(m + 0x78), c, 0.1f);
        func_003C2F58(m, 3, v + 0x250);
        func_L01_00404A10(func_L40_003F5880, m);
    }
}
