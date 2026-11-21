/* functional: medium. Same reads, writes and calls as retail in state order 1..7 (state byte at +0x20, jump table); a few scratch-vector layouts and the effect-spawn argument block are written the way sibling levels' matched C writes them, so bytes differ but behaviour should not. */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) s128_003D3938;
extern s32 func_L01_004561B8(void *);
extern s32 func_00382468(s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0044C280(void *, void *, f32, void *, s32);
extern f32 func_0038CEA8(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CED8(void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_0038D308(void *, void *);
extern void func_L06_00359A88(void *, void *);
extern s32 func_0038CAD0(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_004AA7E8(void *, s32);
extern void func_003C2880(void *);
extern void func_003A4FF8(void *, s32, s32, void *, s32);
extern void func_L01_00404808(void *, void *);
extern s32 func_L07_003D4330(void *, void *);
extern void func_L07_003D48D0(void *);
extern void *func_L01_004CB320(void);
extern void func_L01_004CB358(void);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern s32 func_003D4D00(void *, s32, void *, void *, f32);
extern void func_L01_00456230(void *, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void *func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                               s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s16 D_L07_001DE7C0[2];
extern u8 D_L07_001D9AE0[];
extern u8 *D_L07_001E8C18;
extern u32 D_L07_001ECC80[];
extern u8 D_001A4BE0[];

#define SPAWN_BURST(p) func_L01_003303B8((p), 0, 0, 6, 6, 3, 0, 0, 0.75f, 0.0f, 0.0f, 2.0f, \
    0, 0, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0)

void func_L07_003D3938(u8 *m) {
    u8 *pv = *(u8 **)(m + 0x68);
    s128_003D3938 sp90, spA0[3], spD0;
    u8 *q = (u8 *)spA0;
    u32 st = (u32)m[0x20] - 1;
    f32 f4;
    s32 hit, n, i;

    if (st >= 7) return;
    switch (st) {
    case 0: {
        if (func_L01_004561B8(m) && (pv[0xC] & 4)) {
            s32 v = *(s32 *)pv;
            *(s32 *)pv = (v >> 2) + func_00382468(v - (v >> 2));
        }
        f4 = (f32)*(s32 *)pv / 100.0f;
        *(f32 *)(m + 0x2C) = *(f32 *)(*(u8 **)(m + 0x24) + 0x24) * 1.25f * f4;
        *(s16 *)(pv + 0x38) = (s16)(s32)((f32)D_L07_001DE7C0[0] * f4);
        *(s16 *)(pv + 0x3A) = (s16)(s32)((f32)D_L07_001DE7C0[1] * f4);
        func_0038CF68(&spD0, pv + 0x10, 1.0f);
        func_L01_0044C280(&spD0, &spD0, 0.0096f, D_L07_001D9AE0, 1);
        func_0038CF68(pv + 0x10, &spD0, func_0038CEA8(pv + 0x10));
        *(f32 *)(m + 0xF8) = func_0038D160(*(f32 *)(pv + 0x10), *(f32 *)(pv + 0x14));
        *(f32 *)(m + 0xF4) = -func_0038D160(func_0038CED8(pv + 0x10), *(f32 *)(pv + 0x18));
        *(f32 *)(m + 0xF0) = func_0038DAB8(*(f32 *)(m + 0xF0), 0.11170108f);
        sp90 = *(s128_003D3938 *)(m + 0x10);
        ((f32 *)&sp90)[0] += *(f32 *)(pv + 0x10);
        ((f32 *)&sp90)[1] += *(f32 *)(pv + 0x14);
        ((f32 *)&sp90)[2] += *(f32 *)(pv + 0x18);
        func_0038D308(m + 0xC0, m + 0xF0);
        *(s128_003D3938 *)(m + 0x10) = sp90;
        func_L06_00359A88(m, pv);
        if (!func_0038CAD0(pv)) return;
        if (pv[0xC] & 4) {
            func_L01_004450F0(m, 6, -1);
            return;
        }
        func_L01_004450F0(m, 2, -1);
        *(s32 *)(m + 0x98) = 0;
        *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & 0xEFFF;
        func_L01_004AA7E8(m, 1);
        *(s32 *)pv = (pv[0xC] & 2) ? 200 : 8;
        return;
    }
    case 1:
        if (!func_0038CAD0(pv)) return;
        func_L01_004450F0(m, 3, -1);
        if (!func_L07_003D4330(m, pv)) {
            func_003C2880(m);
            return;
        }
        *(s32 *)pv = 0x32;
        func_003A4FF8(*(u8 **)(*(u8 **)(m + 0x24) + 0x28) + 0x20, 0, 0, pv + 0x20, 0x400);
        return;
    case 2:
        func_L01_00404808(func_L07_003D48D0, m);
        if (!func_0038CAD0(pv)) return;
        func_L01_004450F0(m, 4, -1);
        *(s32 *)pv = 4;
        return;
    case 3: {
        u8 *owner;
        u16 fl;
        func_L01_00404808(func_L07_003D48D0, m);
        if (!func_0038CAD0(pv)) return;
        func_L01_004450F0(m, 5, -1);
        owner = *(u8 **)(m + 0x24);
        fl = *(u16 *)(m + 0x34) & 0xFFBE;
        *(u16 *)(m + 0x34) = fl;
        *(u16 *)(m + 0x34) = fl | (*(u16 *)(owner + 0x44) & 0x1000);
        *(s32 *)(m + 0x98) = *(s32 *)(owner + 0x10);
        *(u32 *)(pv + 0x10) = 0; *(u32 *)(pv + 0x14) = 0; *(u32 *)(pv + 0x18) = 0; *(u32 *)(pv + 0x1C) = 0;
        *(f32 *)(pv + 0x18) = -*(f32 *)(pv + 0x8);
        *(f32 *)(m + 0xF8) = func_0038D160(*(f32 *)(pv + 0x10), *(f32 *)(pv + 0x14));
        *(f32 *)(m + 0xF4) = -func_0038D160(func_0038CED8(pv + 0x10), *(f32 *)(pv + 0x18));
        func_0038D308(m + 0xC0, m + 0xF0);
        *(s128_003D3938 *)(m + 0x10) = *(s128_003D3938 *)(pv + 0x20);
        *(f32 *)(m + 0x18) += 20.0f;
        *(s32 *)pv = 200;
        return;
    }
    case 4: {
        u8 *owner = *(u8 **)(m + 0x24);
        f32 ratio;
        func_L01_00404808(func_L07_003D48D0, m);
        ratio = *(f32 *)(m + 0x2C) / *(f32 *)(owner + 0x24) + 0.037499998f;
        if (1.25f < ratio) ratio = 1.25f;
        *(f32 *)(m + 0x2C) = *(f32 *)(owner + 0x24) * ratio;
        f4 = ratio * 0.8f;
        *(s16 *)(pv + 0x38) = (s16)(s32)((f32)D_L07_001DE7C0[0] * f4);
        *(s16 *)(pv + 0x3A) = (s16)(s32)((f32)D_L07_001DE7C0[1] * f4);
        sp90 = *(s128_003D3938 *)(m + 0x10);
        ((f32 *)&sp90)[0] += *(f32 *)(pv + 0x10);
        ((f32 *)&sp90)[1] += *(f32 *)(pv + 0x14);
        ((f32 *)&sp90)[2] += *(f32 *)(pv + 0x18);
        *(f32 *)(pv + 0x18) -= 0.004000000f;
        {
            u8 *tgt = *(u8 **)(m + 0xB8);
            f32 *a = (f32 *)spA0;
            spA0[0] = *(s128_003D3938 *)(m + 0x10);
            *(s32 *)(q + 0x14) = 0x10001;
            *(u8 **)(q + 0x10) = tgt;
            *(f32 *)(q + 0x1C) = *(f32 *)(pv + 4);
            *(u16 *)(q + 0x1A) = *(u16 *)(m + 0xAA);
            *(f32 *)(q + 0x24) = *(f32 *)(pv + 4);
            *(s32 *)(q + 0x20) = 0;
            a[0] -= *(f32 *)(tgt + 0x10);
            a[1] -= *(f32 *)(tgt + 0x14);
            a[2] = 0.0f;
            a[3] = *(f32 *)(m + 0x1C);
            *(f32 *)(q + 0x8) = 0.0f;
        }
        func_0038CF68(spA0, spA0, 2.0000002f);
        q[0x18] = 3;
        *(f32 *)(q + 0xC) = 5627.9248f;
        *(s32 *)(q + 0x20) |= 1;
        func_L01_004CB320();
        hit = func_003D3CB0(m + 0x10, &sp90, 0, *(u8 **)(m + 0xB8), spA0);
        if (hit) {
            u8 *t = D_L07_001E8C18;
            if (t && *(s16 *)(t + 0xAA) == 0x186D && t[0x20] != 2 && t[0x20] != 5) t[0x20] = 4;
        }
        func_L01_004CB358();
        if (!hit) {
            if (!func_L01_003FB640(m + 0x10, 1, *(u8 **)(m + 0xB8), 0.2f) && !func_0038CAD0(pv)) {
                *(s128_003D3938 *)(m + 0x10) = sp90;
                func_L06_00359A88(m, pv);
                return;
            }
        }
        n = func_003D4D00(m + 0x10, 0, *(u8 **)(m + 0xB8), spA0, 1.5f);
        for (i = 0; i < n; i++) {
            if (D_L07_001ECC80[i] == *(u32 *)(D_001A4BE0 + 0x25C0)) func_L01_00456230(*(u8 **)(m + 0xB8), 1);
        }
        func_003A52A0(0, 0, m);
        SPAWN_BURST(m + 0x10);
        *(s32 *)(m + 0x98) = 0;
        *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & 0xEFFF;
        func_L01_004AA7E8(m, 1);
        func_L01_004450F0(m, 7, -1);
        return;
    }
    case 5:
        func_003A52A0(0, 0, m);
        *(s32 *)(m + 0x98) = 0;
        *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & 0xEFFF;
        func_L01_004AA7E8(m, 1);
        SPAWN_BURST(m + 0x10);
        func_L01_004450F0(m, 7, -1);
        return;
    case 6:
        if (func_L01_004561B8(m)) *(s32 *)pv = 0x32;
        if (func_0038CAD0(pv)) func_003C2880(m);
        return;
    }
}
