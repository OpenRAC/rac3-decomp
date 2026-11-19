/* functional: medium. Helper prototypes (func_L01_003E8xxx hero-state setters taking the player slot index first) inferred from register use only; all branches and constants re-read against the asm; 524 byte diffs are codegen/order. */
#include "common.h"
extern f32 D_001DFF80_sda;
__asm__(".extern D_001DFF80_sda, 4");
extern s32 D_001DFF9C_sda;
__asm__(".extern D_001DFF9C_sda, 4");
extern s32 D_002429BC[];
extern f32 D_00242388[];
extern s32 D_0024B858[];
extern f32 D_0024DE80[];
extern u8 *D_002637C0[];
s32 func_L01_003F2B58(s32);
void func_L01_003E8E10(s32, f32, f32);
f32 func_0038DAB8(f32, f32);
f32 func_0038D098(f32);
f32 func_0038D0B0(f32);
void func_L01_003E9250(s32, void *, f32, f32);
void func_L01_003E8EA8(s32);
void func_L01_003E8C28(s32, f32, f32);
void func_L01_003E8EE8(s32, s32);
void func_L01_003E8BD0(s32, s32, f32, f32);
void func_L01_003E8D80(s32, s32);
void func_L01_003E92B0(s32, void *, f32, f32);
void func_L01_003E8DB8(s32, f32, f32);
void func_L01_003E8E70(s32);
void func_L01_003E8F20(s32, f32, f32, f32);
f32 func_0038DBA0(f32, f32);
s32 func_0038CAD0(void *);
s32 func_0038CB00(void *);
s32 func_003D4D00(void *, s32, s32, s32, f32);
u8 *func_00382348(void *);

void func_L39_0056B080(u8 *obj) {
    s32 idx = *(s32 *)(obj + 0x94);
    u8 *st = *(u8 **)(obj + 0x70);
    u8 *fp = st + 0x260;
    u8 *sb = st + 0x60;
    u8 *G = (u8 *)(D_0024DE80 + idx * 0x118);
    u8 *H = G + 0x150;
    u8 *s;
    u8 *chk;
    f32 sv[4];
    f32 ang[3];
    f32 f3, f20, f1, w;
    s32 flag10 = 0;
    s32 r19, i, count, cv;

    r19 = func_L01_003F2B58(idx);
    if (*(s32 *)(H + 0x100) == 0x7E || *(s32 *)(H + 0x100) == 0x7A || *(s32 *)(H + 0x100) == 0x90)
        *(s16 *)(st + 0x25E) = 1;
    if (*(s32 *)(H + 0x11C) == 0 || *(s32 *)(sb + 0x114) != 0) {
        f3 = *(f32 *)(sb + 0x110);
        if (2.0f < f3) f3 = 2.0f;
        *(f32 *)(sb + 0x104) = (D_001DFF80_sda - 0.002f) * (f3 * 0.5f) + 0.002f;
        if (*(s32 *)(H + 0x11C) != 0) func_0038CAD0(sb + 0x114);
        else *(s32 *)(sb + 0x114) = 0xC;
    }
    if (*(s32 *)(H + 0x104) == 0x1E) {
        *(f32 *)(*(u8 **)(obj + 0x70) + 0x130) = 0.75f;
        func_L01_003E8E10(idx, 0.04f, 0.2f);
    }
    if (*(s32 *)(H + 0xFC) == 0xD && *(s32 *)(H + 0x144) != 0) {
        f20 = func_0038DAB8(*(f32 *)(H + 0x148), 3.1415927f);
        ang[0] = func_0038D098(f20);
        ang[2] = 0.0f;
        ang[1] = func_0038D0B0(f20);
        func_L01_003E9250(idx, ang, 0.20943952f, ang[2]);
        func_L01_003E8EA8(idx);
    }
    if (*(s32 *)(H + 0x104) == 0x11) {
        *(f32 *)(sb + 0xD0) = 0.25f;
        func_L01_003E8C28(idx, 0.5f, 0.003f);
        D_0024B858[idx] = 0xB4;
    } else {
        func_L01_003E8EE8(idx, 0x14);
        D_0024B858[idx] = 0x94;
    }
    if (*(s32 *)(H + 0x104) == 5 && D_002429BC[0] == 0) {
        *(f32 *)(*(u8 **)(obj + 0x70) + 0x130) = 0.25f;
        flag10 = 1;
        func_L01_003E8C28(idx, 2.5f, 0.003f);
    }
    if (*(s32 *)(H + 0x104) == 0x10) *(f32 *)(sb + 0xD0) = 0.25f;
    if (H[0x12C] != 0 && H[0x133] != 0 && *(s32 *)fp == 0 && r19 == -1) {
        func_L01_003E8BD0(idx, 1, 6.75f, 0.003f);
        if (flag10 == 0) {
            *(f32 *)(sb + 0xD0) = 2.0f;
            func_L01_003E8C28(idx, 2.75f, 0.003f);
        }
    }
    if (*(s32 *)(G + 0x400) != 0) ((void (*)(s32))*(s32 *)(G + 0x400))(idx);

    G = (u8 *)(D_0024DE80 + idx * 0x118);
    if (*(s32 *)(G + 0x144) != 0) {
        if (*(s32 *)(fp + 0x10) < 2) {
            u8 *tgt = *(u8 **)(G + 0x144);
            if (tgt[0x20] == 0xFE || tgt[0x20] == 0xFD) {
                *(s32 *)(G + 0x144) = 0;
            } else {
                u8 *pp = *(u8 **)(H + 0x134);
                f32 a0 = *(f32 *)(pp + 0x100);
                if (a0 < 0.0f) a0 = -a0;
                if (0.3f <= a0) {
                    *(s32 *)(G + 0x148) = 0x215;
                } else {
                    f32 a1 = *(f32 *)(pp + 0x104);
                    if (a1 < 0.0f) a1 = -a1;
                    if (0.3f <= a1) *(s32 *)(G + 0x148) = 0x215;
                }
                cv = *(s32 *)(G + 0x148);
                if (cv >= 0x14E) {
                    func_0038CAD0(G + 0x148);
                    if (*(s32 *)(G + 0x148) < 0x14E) *(s32 *)(G + 0x148) = 0;
                } else {
                    *(s32 *)(G + 0x148) = cv + 1;
                    if (cv + 1 >= 0x14E) *(s32 *)(G + 0x148) = 0x14D;
                    w = (f32)*(s32 *)(G + 0x148) / 333.0f * 1.5707964f;
                    func_L01_003E92B0(idx, *(u8 **)(G + 0x144) + 0x10, w, 0.0f);
                    func_L01_003E8EA8(idx);
                    func_L01_003E8DB8(idx, 0.03f, 0.2f);
                }
            }
        }
    }
    if (*(s32 *)(H + 0x100) == 0x83) {
        func_L01_003E8EA8(idx);
        func_L01_003E8DB8(idx, 1.0f, 1.0f);
        func_L01_003E8E10(idx, 0.06f, 0.2f);
        func_L01_003E8E70(idx);
    }
    if (*(s32 *)(H + 0x100) == 0x7D) {
        func_L01_003E8DB8(idx, 0.04f, 0.2f);
        func_L01_003E9250(idx, *(u8 **)(H + 0xF0) + 0xC0, 0.7853982f, 0.017453292f);
        func_L01_003E8BD0(idx, 0, 3.0f, 0.003f);
        func_L01_003E8F20(idx, -1.0f, -1.0f, 0.18f);
        func_L01_003E8E70(idx);
    }
    chk = G + 0x190;
    {
        s32 mode = 0;
        if (*(s32 *)(fp + 0x10) < 2 && *(s32 *)(H + 0x100) != 0x83 && *(s32 *)(H + 0x100) != 0x7D) {
            if (*(s16 *)(H + 0x126) != 0) {
                mode = 1;
            } else if (*(s32 *)(H + 0x100) == 0x80 || *(s32 *)(H + 0x100) == 0x84) {
                if ((*(s32 *)(*(u8 **)(H + 0x134) + 0x1A0) & 3) != 0) mode = 1;
            }
        }
        if (mode) {
            func_L01_003E8D80(idx, 0);
            func_L01_003E8EA8(idx);
            func_L01_003E8DB8(idx, 0.04f, 0.2f);
            st = *(u8 **)(obj + 0x70);
            *(s16 *)(st + 0x14) = 0;
            *(s16 *)(st + 0x16) = 0;
            *(s16 *)(st + 0x12) = 0;
        } else if (D_001DFF9C_sda != 0) {
            s = *(u8 **)(obj + 0x70);
            f20 = 0.0f;
            for (i = 0; i < 4; i++) {
                sv[i] = func_0038DBA0(*(f32 *)(G + 0x10C + i * 4), *(f32 *)(G + 0x110 + i * 4));
                f20 = f20 + sv[i];
            }
            f20 = f20 * 0.25f;
            f1 = f20 * 5.0f;
            if (1.0f < f1) f1 = 1.0f;
            f1 = 1.0f - f1;
            if (f1 < 0.3f) *(s16 *)(s + 0x12) = 0x1B;
            if (*(s16 *)(s + 0x12) != 0) {
                if (func_0038CB00(s + 0x12) != 0) *(s16 *)(s + 0x14) = 0x25;
                func_L01_003E8EA8(idx);
                cv = (u16)*(s16 *)(s + 0x16) + 1;
                *(s16 *)(s + 0x16) = cv;
                if ((s16)cv >= 0x1A) *(s16 *)(s + 0x16) = 0x19;
                func_L01_003E8DB8(idx, (f32)*(s16 *)(s + 0x16) / 25.0f * 0.0249999985f + 0.015f, 0.2f);
                D_00242388[idx] = 0.0f;
            } else if (*(s16 *)(s + 0x14) != 0) {
                func_0038CB00(s + 0x14);
                D_00242388[idx] = (f32)*(s16 *)(s + 0x14) / 37.0f * -0.85f + 0.85f;
                *(s16 *)(s + 0x16) = 0;
            } else {
                *(s16 *)(s + 0x16) = 0;
                D_00242388[idx] = 0.85f;
            }
        }
    }
    *(s32 *)(fp + 0x10) = 0;
    count = func_003D4D00(chk, 1, *(s32 *)(H + 0xF0), 0, 15.0f);
    if (count > 0) {
        for (i = 0; i < count; i++) {
            u8 *hp = func_00382348(D_002637C0[i]);
            if (hp == 0) continue;
            if ((f32)hp[0xD] == 0.0f) continue;
            *(s32 *)(fp + 0x10) = 1;
            break;
        }
    }
}
