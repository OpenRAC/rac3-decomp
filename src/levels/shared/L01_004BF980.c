#include "common.h"

/* localdecomp:start func_L01_004BF980 */
typedef struct {
    s32 id[5];
} PreviewIds;
extern PreviewIds D_L01_001DADE0[];
extern s32 D_001D4B60;
extern s32 D_L01_001DAC60[2];
__asm__(".extern D_L01_001DAC60, 8");
extern s16 D_001426A0[];
extern s32 D_00143950[];
extern f32 D_L01_001DBD38;
extern u8 D_L01_001E13E0[8];
extern f32 D_L01_001E1404;
extern u8 D_L01_00251400[0x80];
extern s32 D_001D54D0;
extern s32 D_0016C580[];
extern s16 D_L01_001D6700[4];
extern s16 D_L01_001D6706;
extern s16 D_L01_001D6708;
extern s16 D_L01_001D670A;
extern s16 D_L01_001D670C;
extern s32 D_L01_001DADF4;
__asm__(".extern D_L01_001DADF4, 4");
typedef struct { s32 id; s32 b; s32 c; s32 d; } MEnt;
typedef struct { s32 f0; u8 b4; u8 p5[3]; s32 f8; u8 pc[5]; u8 b11; u8 p12[2]; } E14;
typedef struct { s32 e; s32 w4; u8 p8[0x1C]; } E24;
typedef struct {
    u8 p0[0x1C]; s32 f1c, f20, f24; u8 p28[4]; u8 *objs; u8 p30[4]; s32 idx; u8 p38[0x14]; u32 f4c; s32 mode; s32 f54[2]; u8 p5c[0x14]; s32 f70;
    u8 p74[0xC]; s32 cur; u8 b84[4]; u8 b88; u8 b89; u8 p8a[2]; s32 f8c; f32 ffxx90; f32 ff94; s32 f98; u8 p9c[4]; s32 fa0; f32 ffA4; f32 ffA8; f32 ffAC; u8 pb0[0x10]; f32 ffC0; f32 ffC4; f32 ffC8; u8 pcc[0x74]; union { struct { s32 w140[2]; MEnt ent[8]; } m; E14 e14[8]; struct { u8 p[8]; E24 e[4]; } x24; } v; u8 p1e0[0x570]; s32 f750; u8 p754[0x14]; s32 f768;
} MG;
extern MG D_L01_002446C0_004BF980;
extern void func_L01_004BF950(void);
typedef int u128_t __attribute__((mode(TI)));
extern u8 D_L01_001DABF0[8];
__asm__(".extern D_L01_001DABF0, 8");
extern u8 D_001425C0_u8[];
extern u8 D_L01_002C5600[];
extern s32 func_L01_00419E60(u8 *, s32, s32);
extern void func_L01_0042D330(s32, s32);
extern s32 func_003A2750(s32);
extern char *func_00381FF0(s32);
extern void func_L01_004BC0B8(s32);
extern s32 func_L01_005147A8(s32);
extern void func_L01_00425978(s32);
extern void func_003C25D8(u8 *, s32);
extern void func_003C6F90(u8 *, s32, s32, s32, s32);
extern void func_003C7C38(u8 *);
extern void func_003C29B0(u8 *);
extern s32 func_00381CB0(void);
extern f32 func_0038DB48(f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern void func_0038CB78(u8 *, s32, s32);
extern void func_L01_0043A430(s32, s32, u8 *);
extern void func_L01_0043C8F8(u8 *, s32, s32, s32);
extern void func_00398BB8(s32);
extern void func_00398C80(s32);

void func_L01_004BF980(void) {
    s32 mode;
    PreviewIds ids;
    u32 slots[20];
    s32 j5, j3, v, sel, sel5, sel3, sel0, e, e5, e3, e0, n, n5, n3, i, k, cnt;
    s32 odd, od1;
    s32 sz;
    u8 *o;
    u8 *a;
    u8 *t6;
    s32 j;
    f32 fa, fb;
    u8 loc[0xF0];
    u32 msk;
    s32 *ep;
    u32 *sq;
    u8 *base;
    u8 *pp, *pq;
    u8 *to, *ta, *tt, *tm;
    E24 *eb;
    s32 fl, fv;
    f32 cv, cv2;
    s32 ix, ix2, jx, jx2;
    u8 *pl;

    if (D_L01_002446C0_004BF980.mode == 0) {
        return;
    }
    if (D_L01_002446C0_004BF980.b89 != 0) {
        func_L01_004BF950();
    }
    mode = D_L01_002446C0_004BF980.mode;
    o = D_L01_002446C0_004BF980.objs;
    D_L01_002446C0_004BF980.idx = 1;

    if (mode == 5) {
        D_L01_002446C0_004BF980.idx = 0;
        ids = D_L01_001DADE0[0];
        sel5 = D_L01_002446C0_004BF980.cur;
        e5 = D_L01_002446C0_004BF980.v.m.ent[sel5].id;
        if (e5 == 0) {
            func_L01_004BC0B8((s32)func_00381FF0(0x4AC));
        } else {
            if (D_001D4B60 != e5 && D_L01_002446C0_004BF980.f768 == 0) {
                if (e5 == -1) {
                    func_L01_005147A8(0);
                    func_L01_00425978(D_001426A0[0]);
                } else {
                    func_L01_005147A8(e5);
                    func_L01_00425978(D_L01_002446C0_004BF980.v.m.ent[D_L01_002446C0_004BF980.cur].id);
                }
            }
            func_L01_004BC0B8((s32)func_00381FF0(D_L01_001DAC60[D_L01_002446C0_004BF980.v.m.ent[D_L01_002446C0_004BF980.cur].id]));
        }
        if (ids.id[D_L01_002446C0_004BF980.idx] >= 0) {
            do {
                n5 = D_L01_002446C0_004BF980.idx;
                o = D_L01_002446C0_004BF980.objs + (n5 << 8);
                func_003C25D8(o, ids.id[n5]);
                func_003C6F90(o, 0x202020, 0xE, 0xE, 0);
                *(s32 *)(o + 0x78) = 0x80808080;
                *(u16 *)(o + 0x32) = 0x40;
                o[0x31] = 1;
                *(u16 *)(o + 0x34) = 0x2010;
                o[0x30] = 0;
                o[0x23] = 0;
                o[0x20] = 0;
                *(s32 *)(o + 0x98) = 0;
                *(s32 *)(o + 0xF0) = 0;
                *(s32 *)(o + 0xF4) = 0;
                o[0x62] = 0xFF;
                *(f32 *)(o + 0xF8) = 2.0f;
                func_003C7C38(o);
                o[0x42] = 0;
                o[0x43] = 0;
                func_003C29B0(o);
                if (D_001D4B60 >= 4 || func_00381CB0() > 0) {
                    if (*(s16 *)(o + 0xAA) == 0x50A) *(u16 *)(o + 0x34) |= 1;
                }
                if (!(D_001D4B60 < 3)) {
                    if (*(s16 *)(o + 0xAA) == 0xA73) *(u16 *)(o + 0x34) |= 1;
                }
                D_L01_002446C0_004BF980.idx = D_L01_002446C0_004BF980.idx + 1;
            } while (ids.id[D_L01_002446C0_004BF980.idx] >= 0);
        }
        func_0038CB78(D_L01_001E13E0, 0, 0x40);
        func_L01_0043A430((s32)D_L01_002446C0_004BF980.objs, 0x18, D_L01_001E13E0);
        fb = 0.97f;
        fa = D_L01_001DBD38;
        fb = fa * fb;
        (&D_L01_001E1404)[1] = fa;
        (&D_L01_001E1404)[-1] = fb;
        D_L01_001E1404 = fb;
        if (D_001D4B60 < 3) {
            func_0038CB78(D_L01_00251400, 0, 0x40);
            func_0038CB78(D_L01_00251400 + 0x40, 0, 0x40);
            for (j5 = 0; j5 < 2; j5++) {
                a = D_L01_00251400 + j5 * 0x40;
                func_L01_0043A430((s32)D_L01_002446C0_004BF980.objs, 0x16 + j5, a);
                *(f32 *)(a + 0x20) = 0.01f;
                *(f32 *)(a + 0x24) = 0.01f;
                *(f32 *)(a + 0x28) = 0.01f;
            }
        }
        goto tail;
    }

    if (mode == 3) {
        D_L01_002446C0_004BF980.idx = 0;
        ids = D_L01_001DADE0[0];
        sel3 = D_L01_002446C0_004BF980.cur;
        e3 = D_L01_002446C0_004BF980.v.m.ent[sel3].id;
        if (e3 == 0) {
            func_L01_004BC0B8((s32)func_00381FF0(0x4AC));
        } else {
            if (D_001D4B60 != e3 && D_L01_002446C0_004BF980.f768 == 0) {
                func_L01_00425978(e3);
            }
            func_L01_004BC0B8((s32)func_00381FF0(D_L01_001DAC60[D_L01_002446C0_004BF980.v.m.ent[D_L01_002446C0_004BF980.cur].id]));
        }
        if (ids.id[D_L01_002446C0_004BF980.idx] >= 0) {
            do {
                n3 = D_L01_002446C0_004BF980.idx;
                o = D_L01_002446C0_004BF980.objs + (n3 << 8);
                func_003C25D8(o, ids.id[n3]);
                func_003C6F90(o, 0x202020, 0xE, 0xE, 0);
                o[0x30] = 0;
                o[0x23] = 0;
                o[0x20] = 0;
                *(s32 *)(o + 0x98) = 0;
                *(s32 *)(o + 0xF0) = 0;
                *(s32 *)(o + 0xF4) = 0;
                o[0x31] = 1;
                *(s32 *)(o + 0x78) = 0x80808080;
                *(u16 *)(o + 0x34) = 0x2010;
                *(u16 *)(o + 0x32) = 0x40;
                o[0x62] = 0xFF;
                *(f32 *)(o + 0xF8) = func_0038DB48(*(f32 *)(o + 0xF8));
                func_003C7C38(o);
                o[0x42] = 0;
                o[0x43] = 0;
                func_003C29B0(o);
                if (D_001D4B60 == 4) {
                    if (*(s16 *)(o + 0xAA) == 0x50A) *(u16 *)(o + 0x34) |= 1;
                }
                if (!(D_001D4B60 < 3)) {
                    if (*(s16 *)(o + 0xAA) == 0xA73) *(u16 *)(o + 0x34) |= 1;
                }
                D_L01_002446C0_004BF980.idx = D_L01_002446C0_004BF980.idx + 1;
            } while (ids.id[D_L01_002446C0_004BF980.idx] >= 0);
        }
        func_0038CB78(D_L01_001E13E0, 0, 0x40);
        func_L01_0043A430((s32)D_L01_002446C0_004BF980.objs, 0x18, D_L01_001E13E0);
        fb = 0.97f;
        fa = D_L01_001DBD38;
        fb = fa * fb;
        (&D_L01_001E1404)[1] = fa;
        (&D_L01_001E1404)[-1] = fb;
        D_L01_001E1404 = fb;
        if (D_001D4B60 < 3) {
            func_0038CB78(D_L01_00251400, 0, 0x40);
            func_0038CB78(D_L01_00251400 + 0x40, 0, 0x40);
            for (j3 = 0; j3 < 2; j3++) {
                a = D_L01_00251400 + j3 * 0x40;
                func_L01_0043A430((s32)D_L01_002446C0_004BF980.objs, 0x16 + j3, a);
                *(f32 *)(a + 0x20) = 0.01f;
                *(f32 *)(a + 0x24) = 0.01f;
                *(f32 *)(a + 0x28) = 0.01f;
            }
        }
        tail:
        to = D_L01_002446C0_004BF980.objs;
        ix = to[0x42] * 4;
        ta = (u8 *)*(s32 *)(*(s32 *)(to + 0x24) + ix + 0x48);
        if (*(u32 *)(ta + 0x1C) & 0xF0000000) {
            jx = to[0x40] * 4;
            func_L01_0043C8F8(ta + 0x1C + ta[0x10] * 4 + ta[0x13] * 4, *(s32 *)(ta + jx + 0x1C), D_L01_002446C0_004BF980.f20, ((u8 *)*(s32 *)(to + 0x24))[8]);
            *(s32 *)(to + 0x58) = D_L01_002446C0_004BF980.f20;
        }
        ix2 = to[0x43] * 4;
        ta = (u8 *)*(s32 *)(*(s32 *)(to + 0x24) + ix2 + 0x48);
        if (*(u32 *)(ta + 0x1C) & 0xF0000000) {
            jx2 = to[0x41] * 4;
            func_L01_0043C8F8(ta + 0x1C + ta[0x10] * 4 + ta[0x13] * 4, *(s32 *)(ta + jx2 + 0x1C), D_L01_002446C0_004BF980.f24, ((u8 *)*(s32 *)(to + 0x24))[8]);
            *(s32 *)(to + 0x5C) = D_L01_002446C0_004BF980.f24;
        }
        D_L01_002446C0_004BF980.ffC0 = -9.0f;
        D_L01_002446C0_004BF980.ffC4 = 3.25f;
        pp = (u8 *)D_00143950;
        D_L01_002446C0_004BF980.ffC8 = (pp[0xAD] != 0) ? -0.02f : 0.5f;
        D_L01_002446C0_004BF980.ff94 = 3.5f;
        D_L01_002446C0_004BF980.b88 = 1;
        D_L01_002446C0_004BF980.f98 = 0;
        D_L01_002446C0_004BF980.b89 = 0;
        D_L01_002446C0_004BF980.f8c = 0;
        return;
    }

    if (mode == 2) {
        sel = D_L01_002446C0_004BF980.cur;
        eb = D_L01_002446C0_004BF980.v.x24.e;
        ep = &eb[sel].e;
        D_L01_002446C0_004BF980.idx = 10;
        D_L01_002446C0_004BF980.f4c = (D_001D54D0 & ~*ep) | D_L01_002446C0_004BF980.v.x24.e[sel].w4;
        tm = (u8 *)D_0016C580[0];
        slots[0] = (u32)((s32)*(s16 *)(tm + 0xAA) << 16);
        if (*ep == 3) slots[0] |= 0x80000000;
        {
            s32 v = *(s16 *)((u8 *)D_L01_001D6700 + ((D_L01_002446C0_004BF980.f4c & 0xC) >> 1));
            slots[1] = (u32)(v << 16);
            slots[2] = slots[1] | 0x8000;
            if (*ep == 0xC) { slots[1] |= 0x80000000; slots[2] |= 0x80000000; }
        }
        sz = 0x24;
        {
            s32 v = D_L01_001D670C;
            slots[3] = (u32)(v << 16);
            slots[4] = slots[3] | 0x8000;
            if (*ep == 0xC00) { slots[3] |= 0x80000000; slots[4] |= 0x80000000; }
        }
        {
            s32 v = D_L01_001D6706;
            slots[5] = (u32)(v << 16);
            if (*ep == 0x30) slots[5] |= 0x80000000;
        }
        {
            s32 v = D_L01_001D6708;
            slots[6] = (u32)(v << 16);
            slots[7] = slots[6] | 0x8000;
            if (*ep == 0x40) { slots[6] |= 0x80000000; slots[7] |= 0x80000000; }
        }
        {
            s32 v = D_L01_001D670A;
            slots[8] = (u32)(v << 16);
            slots[9] = slots[8] | 0x8000;
            if (*ep == 0x200) { slots[8] |= 0x80000000; slots[9] |= 0x80000000; }
        }
        D_L01_002446C0_004BF980.fa0 = 0;
        slots[D_L01_002446C0_004BF980.idx++] = 0x10E30000;
        if (*ep == 0xC00 || *ep == 0x200 || *ep == 0xC || *ep == 3 || *ep == 0x40) {
            D_L01_002446C0_004BF980.ffA4 = 0.346f;
            D_L01_002446C0_004BF980.ffA8 = 0.3227f;
            D_L01_002446C0_004BF980.ffAC = func_0038DAB8(0.8566f, 3.1415927f);
        } else if (*ep == 0x30 || *ep == 0x2000) {
            D_L01_002446C0_004BF980.ffA4 = 0.0225f;
            D_L01_002446C0_004BF980.ffA8 = 0.0239f;
            D_L01_002446C0_004BF980.ffAC = func_0038DB00(-3.0301f, 1.5707964f);
        } else {
            e = *(s32 *)((u8 *)eb + sel * sz);
            if (e == 0x1000 || e == 0x180) {
                D_L01_002446C0_004BF980.ffA4 = -0.587f;
                D_L01_002446C0_004BF980.ffA8 = 0.165f;
                D_L01_002446C0_004BF980.ffAC = func_0038DAB8(2.055f, 1.5707964f);
            } else if (e == 0x1F0000) {
                od1 = sel & 1;
                D_L01_002446C0_004BF980.ffA4 = (u8)od1 ? 0.533f : 0.566f;
                odd = sel & 1;
                D_L01_002446C0_004BF980.ffA8 = (u8)odd ? 0.3203f : 0.165f;
                if ((u8)odd) cv2 = 0.6699f; else cv2 = 1.4345f;
                D_L01_002446C0_004BF980.ffAC = func_0038DAB8(cv2, 3.1415927f);
            } else if (e == 0xC000) {
                D_L01_002446C0_004BF980.ffA4 = -0.5f;
                D_L01_002446C0_004BF980.ffA8 = -0.4f;
                D_L01_002446C0_004BF980.ffAC = func_0038DB00(-2.1f, 1.5707964f);
            } else {
                D_L01_002446C0_004BF980.ffA4 = 0;
                D_L01_002446C0_004BF980.ffA8 = 0;
                D_L01_002446C0_004BF980.ffAC = -1.5707964f;
            }
        }
        D_L01_002446C0_004BF980.f54[0] = -1;
        D_L01_002446C0_004BF980.f54[1] = -1;
        k = 0;
        sq = slots;
        for (i = 0; i < D_L01_002446C0_004BF980.idx; i = i + 1) {
            pl = (u8 *)D_00143950;
            msk = 0x80000000;
            o = D_L01_002446C0_004BF980.objs + (i << 8);
            func_003C25D8(o, *(u16 *)((u8 *)&sq[i] + 2) & 0x7FFF);
            func_003C6F90(o, 0x202020, 0xE, 0xE, 0);
            if (sq[i] & msk) {
                D_L01_002446C0_004BF980.f54[k] = i;
                k++;
            }
            if (o[0x63] != 0) o[0x63] = 0xF;
            *(u16 *)(o + 0x32) = 0x100;
            o[0x31] = 1;
            *(s32 *)(o + 0x78) = 0x80808080;
            o[0x30] = 0;
            *(u16 *)(o + 0x34) = *(u16 *)&sq[i] | 0x2010;
            o[0x23] = 0xFF;
            o[0x20] = 0;
            *(s32 *)(o + 0x98) = 0;
            *(f32 *)(o + 0x2C) = 1.0f;
            D_L01_002446C0_004BF980.ffC0 = -12.0f;
            D_L01_002446C0_004BF980.ff94 = 1.0f;
            D_L01_002446C0_004BF980.ffC4 = 0;
            fl = pl[0xAD] != 0;
            cv = fl ? 1.45f : 2.0f;
            D_L01_002446C0_004BF980.ffC8 = cv;
            *(s32 *)(o + 0xF0) = 0;
            *(s32 *)(o + 0xF4) = 0;
            *(f32 *)(o + 0xF8) = -1.5707964f;
            func_003C7C38(o);
        }
        D_L01_002446C0_004BF980.b88 = 1;
        D_L01_002446C0_004BF980.f98 = 0;
        D_L01_002446C0_004BF980.b89 = 0;
        D_L01_002446C0_004BF980.f8c = 0;
        if (D_L01_001DADF4 != (D_L01_002446C0_004BF980.f4c & 3)) {
            func_00398BB8(D_L01_002446C0_004BF980.f4c & 3);
            D_L01_001DADF4 = D_L01_002446C0_004BF980.f4c & 3;
        }
        fv = (*(u16 *)((u8 *)&D_L01_002446C0_004BF980 + 0x4E)) & 0x1F;
        if (D_0016C580[12] != fv) func_00398C80(fv);
        return;
    }

    if (mode == 0) {
    D_L01_002446C0_004BF980.f750 = 0;
    sel0 = D_L01_002446C0_004BF980.cur;
    {
        s32 t = D_L01_002446C0_004BF980.v.e14[sel0].b4;
        if (t == 1) {
            func_003C25D8(o, 0xCDB);
            func_003C6F90(o, 0x202020, 0xE, 0xE, 0);
            *(u16 *)(o + 0x32) = 0x40;
            *(s32 *)(o + 0x78) = 0x80808080;
            *(u16 *)(o + 0x34) = 0x2010;
            o[0x31] = t;
            *(u16 *)(o + 0x7C) = 1;
            o[0x30] = 0;
            o[0x23] = 0;
            o[0x20] = 0;
            *(s32 *)(o + 0x98) = 0;
            D_L01_002446C0_004BF980.ff94 = 3.5f;
            *(u128_t *)&D_L01_002446C0_004BF980.ffC0 = *(u128_t *)D_L01_001DABF0;
            if (((u8 *)D_00143950)[0xAD] != 0) {
                D_L01_002446C0_004BF980.ffC8 = D_L01_002446C0_004BF980.ffC8 - 0.55f;
            }
            *(s32 *)(o + 0xF0) = 0;
            *(s32 *)(o + 0xF4) = 0;
            *(s32 *)(o + 0xF8) = 0;
            D_L01_002446C0_004BF980.f98 = 0;
            func_003C7C38(o);
            D_L01_002446C0_004BF980.f8c = 0;
            D_L01_002446C0_004BF980.b89 = 0;
            D_L01_002446C0_004BF980.b88 = 1;
            return;
        }
        if (D_L01_002446C0_004BF980.v.e14[sel0].b11 != 0) {
            func_L01_00419E60((u8 *)loc, D_L01_002446C0_004BF980.v.e14[sel0].f0, 2);
            func_L01_004BC0B8((s32)func_00381FF0(*(s16 *)(loc + 0x42)));
        } else {
            e0 = D_L01_002446C0_004BF980.v.e14[sel0].f0;
            pq = (u8 *)D_L01_002C5600;
            func_L01_004BC0B8((s32)func_00381FF0(*(s16 *)(pq + D_001425C0_u8[e0] * 0xF0 + 0x42)));
        }
        func_003A2750(1);
        func_L01_0042D330(D_L01_002446C0_004BF980.v.e14[D_L01_002446C0_004BF980.cur].f8, D_L01_002446C0_004BF980.f1c);
        D_L01_002446C0_004BF980.b89 = 1;
        D_L01_002446C0_004BF980.f70 = D_L01_002446C0_004BF980.cur;
        D_L01_002446C0_004BF980.b88 = 0;
        return;
    }
    }
    D_L01_002446C0_004BF980.b89 = 0;
    D_L01_002446C0_004BF980.b88 = 0;
}
/* localdecomp:end func_L01_004BF980 */
