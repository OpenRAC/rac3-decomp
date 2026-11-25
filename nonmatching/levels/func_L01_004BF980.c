/* Exploratory PAL draft (W32, round 27). Level 01, the owning file's flags plus --as ps2as
 * (retail's bytes use the SN assembler's macro forms: lui $at for float globals, scalar lui/lw for
 * D_001D4B60 with the delay-slot copy in $gp form): 647 positional word differences, 345 aligned
 * instruction edits (difflib over check.py's instruction lines), frame 0x1C0 like retail (W10's
 * draft: 893 / 755 on the same scorer). The default assembler measures about 840 positional;
 * landing needs a file cut at 0x4BF980 with @ps2as. What helped: every access to the menu object
 * through the typed global itself (no u pointer: gcse builds the base register, $s1/$s5 as in
 * retail) and, for typed struct members instead of (u8 *)&D + off casts (the member form keeps
 * base register + offset like retail); one 0xF0-byte scratch struct plus slots[20] for the frame;
 * the shared tail placed inside mode 3's block (mode 5 jumps into it); mode 0 written out; the
 * mode-2 entry kept by pointer and re-read on every compare; plain scalar D_001D4B60; small-sized
 * D_001E13E0 / D_00251400. Still differs: register numbers of the hi halves and loop pointers in
 * modes 3/5, mode-3 store/constant order, mode-2 slot-loop strength reduction (retail indexes k,
 * ours walks a pointer), D_00143950 base not folded in retail.
 */
/* localdecomp:start func_L01_004BF980 */
extern S_00244740 D_L01_002446C0[];
typedef struct {
    s32 id[5];
} PreviewIds;
extern PreviewIds D_L01_001DADE0[];
extern s32 D_001D4B60;
extern s32 D_001DAC60_sda[2];
extern s16 D_001426A0[];
extern s32 D_00143950[];
extern f32 D_001DBD38;
extern u8 D_001E13E0[8];
extern f32 D_001E1400;
extern f32 D_001E1404;
extern f32 D_001E1408;
extern u8 D_00251400[8];
extern s32 D_001D54D0[];
extern s32 D_0016C580[];
extern s16 D_001D6700[];
extern s16 D_001D6706[];
extern s16 D_001D6708[];
extern s16 D_001D670A[];
extern s16 D_001D670C[];
extern s32 D_001DADF4_sda;
__asm__(".extern D_001DADF4_sda, 4");
typedef struct { s32 id; s32 b; s32 c; s32 d; } MEnt;
typedef struct { s32 f0; u8 b4; u8 p5[3]; s32 f8; u8 pc[5]; u8 b11; u8 p12[2]; } E14;
typedef struct { s32 e; s32 w4; u8 p8[0x1C]; } E24;
typedef struct {
    u8 p0[0x1C]; s32 f1c, f20, f24; u8 p28[4]; u8 *objs; u8 p30[4]; s32 idx; u8 p38[0x14]; s32 f4c; s32 mode; s32 f54[2]; u8 p5c[0x14]; s32 f70;
    u8 p74[0xC]; s32 cur; u8 b84[4]; u8 b88; u8 b89; u8 p8a[2]; s32 f8c; f32 ffxx90; f32 ff94; s32 f98; u8 p9c[4]; s32 fa0; f32 ffA4; f32 ffA8; f32 ffAC; u8 pb0[0x10]; f32 ffC0; f32 ffC4; f32 ffC8; u8 pcc[0x74]; union { struct { s32 w140; MEnt ent[8]; } m; E14 e14[8]; struct { u8 p[8]; E24 e[4]; } x24; } v; u8 p1e0[0x570]; s32 f750; u8 p754[0x14]; s32 f768;
} MG;
extern MG D_L01_002446C0_004BF980;
extern void func_L01_004BF950(void);
typedef int u128_t __attribute__((mode(TI)));
extern u128_t D_001DABF0_sda;
extern u8 D_001425C0_u8[];
extern u8 D_L01_002C5600[];
extern s32 func_L01_00419E60(u8 *, s32, s32);
extern void func_L01_0042D330(s32, s32);
extern void func_003A2750(s32);
extern char *func_00381FF0(s32);
extern void func_L01_004BC0B8(s32);
extern void func_L01_005147A8(s32);
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
    s32 sel, e, e0, n, i, k, cnt;
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
        sel = D_L01_002446C0_004BF980.cur;
        e = D_L01_002446C0_004BF980.v.m.ent[sel].id;
        if (e == 0) {
            func_L01_004BC0B8((s32)func_00381FF0(0x4AC));
        } else {
            if (D_001D4B60 != e && D_L01_002446C0_004BF980.f768 == 0) {
                if (e == -1) {
                    func_L01_005147A8(0);
                    func_L01_00425978(D_001426A0[0]);
                } else {
                    func_L01_005147A8(e);
                    func_L01_00425978(D_L01_002446C0_004BF980.v.m.ent[D_L01_002446C0_004BF980.cur].id);
                }
            }
            func_L01_004BC0B8((s32)func_00381FF0(D_001DAC60_sda[D_L01_002446C0_004BF980.v.m.ent[D_L01_002446C0_004BF980.cur].id]));
        }
        if (ids.id[D_L01_002446C0_004BF980.idx] >= 0) {
            do {
                n = D_L01_002446C0_004BF980.idx;
                o = D_L01_002446C0_004BF980.objs + (n << 8);
                func_003C25D8(o, ids.id[n]);
                func_003C6F90(o, 0x202020, 0xE, 0xE, 0);
                o[0x30] = 0;
                o[0x23] = 0;
                o[0x20] = 0;
                *(s32 *)(o + 0x98) = 0;
                *(s32 *)(o + 0xF0) = 0;
                *(s32 *)(o + 0xF4) = 0;
                *(s32 *)(o + 0x78) = 0x80808080;
                *(u16 *)(o + 0x32) = 0x40;
                o[0x31] = 1;
                *(u16 *)(o + 0x34) = 0x2010;
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
        func_0038CB78(D_001E13E0, 0, 0x40);
        func_L01_0043A430((s32)D_L01_002446C0_004BF980.objs, 0x18, D_001E13E0);
        fa = D_001DBD38;
        fb = fa * 0.97f;
        D_001E1408 = fa;
        D_001E1404 = fb;
        D_001E1400 = fb;
        if (D_001D4B60 < 3) {
            a = D_00251400;
            func_0038CB78(a, 0, 0x40);
            func_0038CB78(a + 0x40, 0, 0x40);
            for (j = 0; j < 2; j++, a += 0x40) {
                func_L01_0043A430((s32)D_L01_002446C0_004BF980.objs, 0x16 + j, a);
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
        sel = D_L01_002446C0_004BF980.cur;
        e = D_L01_002446C0_004BF980.v.m.ent[sel].id;
        if (e == 0) {
            func_L01_004BC0B8((s32)func_00381FF0(0x4AC));
        } else {
            if (D_001D4B60 != e && D_L01_002446C0_004BF980.f768 == 0) {
                func_L01_00425978(e);
            }
            func_L01_004BC0B8((s32)func_00381FF0(D_001DAC60_sda[D_L01_002446C0_004BF980.v.m.ent[D_L01_002446C0_004BF980.cur].id]));
        }
        if (ids.id[D_L01_002446C0_004BF980.idx] >= 0) {
            do {
                n = D_L01_002446C0_004BF980.idx;
                o = D_L01_002446C0_004BF980.objs + (n << 8);
                func_003C25D8(o, ids.id[n]);
                func_003C6F90(o, 0x202020, 0xE, 0xE, 0);
                o[0x30] = 0;
                o[0x23] = 0;
                o[0x20] = 0;
                *(s32 *)(o + 0x98) = 0;
                *(s32 *)(o + 0xF0) = 0;
                *(s32 *)(o + 0xF4) = 0;
                *(s32 *)(o + 0x78) = 0x80808080;
                o[0x62] = 0xFF;
                o[0x31] = 1;
                *(u16 *)(o + 0x34) = 0x2010;
                *(u16 *)(o + 0x32) = 0x40;
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
        func_0038CB78(D_001E13E0, 0, 0x40);
        func_L01_0043A430((s32)D_L01_002446C0_004BF980.objs, 0x18, D_001E13E0);
        fa = D_001DBD38;
        fb = fa * 0.97f;
        D_001E1408 = fa;
        D_001E1404 = fb;
        D_001E1400 = fb;
        if (D_001D4B60 < 3) {
            a = D_00251400;
            func_0038CB78(a, 0, 0x40);
            func_0038CB78(a + 0x40, 0, 0x40);
            for (j = 0; j < 2; j++, a += 0x40) {
                func_L01_0043A430((s32)D_L01_002446C0_004BF980.objs, 0x16 + j, a);
                *(f32 *)(a + 0x20) = 0.01f;
                *(f32 *)(a + 0x24) = 0.01f;
                *(f32 *)(a + 0x28) = 0.01f;
            }
        }
        tail:
        o = D_L01_002446C0_004BF980.objs;
        t6 = (u8 *)*(s32 *)(o + 0x24);
        a = (u8 *)*(s32 *)(t6 + o[0x42] * 4 + 0x48);
        if (*(u32 *)(a + 0x1C) & 0xF0000000) {
            func_L01_0043C8F8(a + 0x1C + a[0x10] * 4 + a[0x13] * 4, *(s32 *)(a + o[0x40] * 4 + 0x1C), D_L01_002446C0_004BF980.f20, t6[8]);
            *(s32 *)(o + 0x58) = D_L01_002446C0_004BF980.f20;
            t6 = (u8 *)*(s32 *)(o + 0x24);
        }
        a = (u8 *)*(s32 *)(t6 + o[0x43] * 4 + 0x48);
        if (*(u32 *)(a + 0x1C) & 0xF0000000) {
            func_L01_0043C8F8(a + 0x1C + a[0x10] * 4 + a[0x13] * 4, *(s32 *)(a + o[0x41] * 4 + 0x1C), D_L01_002446C0_004BF980.f24, t6[8]);
            *(s32 *)(o + 0x5C) = D_L01_002446C0_004BF980.f24;
        }
        D_L01_002446C0_004BF980.ffC0 = -9.0f;
        D_L01_002446C0_004BF980.ffC4 = 3.25f;
        D_L01_002446C0_004BF980.ffC8 = (((u8 *)D_00143950)[0xAD] != 0) ? -0.02f : 0.5f;
        D_L01_002446C0_004BF980.ff94 = 3.5f;
        D_L01_002446C0_004BF980.b88 = 1;
        D_L01_002446C0_004BF980.f8c = 0;
        D_L01_002446C0_004BF980.f98 = 0;
        D_L01_002446C0_004BF980.b89 = 0;
        return;
    }

    if (mode == 2) {
        sel = D_L01_002446C0_004BF980.cur;
        ep = &D_L01_002446C0_004BF980.v.x24.e[sel].e;
        D_L01_002446C0_004BF980.idx = 10;
        D_L01_002446C0_004BF980.f4c = (D_001D54D0[0] & ~*ep) | D_L01_002446C0_004BF980.v.x24.e[sel].w4;
        t6 = (u8 *)D_0016C580[0];
        slots[0] = (u32)((s32)*(s16 *)(t6 + 0xAA) << 16);
        if (*ep == 3) slots[0] |= 0x80000000;
        {
            s32 v = *(s16 *)((u8 *)D_001D6700 + ((D_L01_002446C0_004BF980.f4c & 0xC) >> 1));
            slots[1] = (u32)(v << 16);
            slots[2] = slots[1] | 0x8000;
            if (*ep == 0xC) { slots[2] |= 0x80000000; slots[1] |= 0x80000000; }
        }
        {
            s32 v = D_001D670C[0];
            slots[3] = (u32)(v << 16);
            slots[4] = slots[3] | 0x8000;
            if (*ep == 0xC00) { slots[4] |= 0x80000000; slots[3] |= 0x80000000; }
        }
        {
            s32 v = D_001D6706[0];
            slots[5] = (u32)(v << 16);
            if (*ep == 0x30) slots[5] |= 0x80000000;
        }
        {
            s32 v = D_001D6708[0];
            slots[6] = (u32)(v << 16);
            slots[7] = slots[6] | 0x8000;
            if (*ep == 0x40) { slots[7] |= 0x80000000; slots[6] |= 0x80000000; }
        }
        {
            s32 v = D_001D670A[0];
            slots[8] = (u32)(v << 16);
            slots[9] = slots[8] | 0x8000;
            if (*ep == 0x200) { slots[9] |= 0x80000000; slots[8] |= 0x80000000; }
        }
        D_L01_002446C0_004BF980.fa0 = 0;
        sq = slots;
        sq[D_L01_002446C0_004BF980.idx] = 0x10E30000;
        D_L01_002446C0_004BF980.idx = D_L01_002446C0_004BF980.idx + 1;
        if (*ep == 0xC00 || *ep == 0x200 || *ep == 0xC || *ep == 3 || *ep == 0x40) {
            D_L01_002446C0_004BF980.ffA4 = 0.346f;
            D_L01_002446C0_004BF980.ffA8 = 0.3227f;
            D_L01_002446C0_004BF980.ffAC = func_0038DAB8(0.8566f, 3.1415927f);
        } else if (*ep == 0x30 || *ep == 0x2000) {
            D_L01_002446C0_004BF980.ffA4 = 0.0225f;
            D_L01_002446C0_004BF980.ffA8 = 0.0239f;
            D_L01_002446C0_004BF980.ffAC = func_0038DB00(-3.0301f, 1.5707964f);
        } else {
            e = D_L01_002446C0_004BF980.v.x24.e[sel].e;
            if (e == 0x1000 || e == 0x180) {
                D_L01_002446C0_004BF980.ffA4 = -0.587f;
                D_L01_002446C0_004BF980.ffA8 = 0.165f;
                D_L01_002446C0_004BF980.ffAC = func_0038DAB8(2.055f, 1.5707964f);
            } else if (e == 0x1F0000) {
                D_L01_002446C0_004BF980.ffA4 = (sel & 1) ? 0.533f : 0.566f;
                D_L01_002446C0_004BF980.ffA8 = (sel & 1) ? 0.3203f : 0.165f;
                D_L01_002446C0_004BF980.ffAC = func_0038DAB8((sel & 1) ? 0.6699f : 1.4345f, 3.1415927f);
            } else if (e == 0xC000) {
                D_L01_002446C0_004BF980.ffA4 = -0.5f;
                D_L01_002446C0_004BF980.ffA8 = -0.4f;
                D_L01_002446C0_004BF980.ffAC = func_0038DB00(-2.1f, 1.5707964f);
            } else {
                D_L01_002446C0_004BF980.ffA4 = 0;
                D_L01_002446C0_004BF980.ffAC = -1.5707964f;
                D_L01_002446C0_004BF980.ffA8 = 0;
            }
        }
        D_L01_002446C0_004BF980.f54[1] = -1;
        D_L01_002446C0_004BF980.f54[0] = -1;
        k = 0;
        msk = 0x80000000;
        for (i = 0; i < D_L01_002446C0_004BF980.idx; i = i + 1) {
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
            o[0x23] = 0xFF;
            *(u16 *)(o + 0x34) = *(u16 *)&sq[i] | 0x2010;
            o[0x20] = 0;
            *(s32 *)(o + 0x98) = 0;
            *(f32 *)(o + 0x2C) = 1.0f;
            D_L01_002446C0_004BF980.ffC0 = -12.0f;
            D_L01_002446C0_004BF980.ff94 = 1.0f;
            D_L01_002446C0_004BF980.ffC4 = 0;
            D_L01_002446C0_004BF980.ffC8 = (((u8 *)D_00143950)[0xAD] != 0) ? 1.45f : 2.0f;
            *(s32 *)(o + 0xF0) = 0;
            *(s32 *)(o + 0xF4) = 0;
            *(f32 *)(o + 0xF8) = -1.5707964f;
            func_003C7C38(o);
        }
        D_L01_002446C0_004BF980.b88 = 1;
        D_L01_002446C0_004BF980.f98 = 0;
        D_L01_002446C0_004BF980.b89 = 0;
        D_L01_002446C0_004BF980.f8c = 0;
        if (D_001DADF4_sda != (D_L01_002446C0_004BF980.f4c & 3)) {
            func_00398BB8(D_L01_002446C0_004BF980.f4c & 3);
            D_001DADF4_sda = D_L01_002446C0_004BF980.f4c & 3;
        }
        if (D_0016C580[12] != ((*(u16 *)((u8 *)&D_L01_002446C0_004BF980 + 0x4E)) & 0x1F)) func_00398C80((*(u16 *)((u8 *)&D_L01_002446C0_004BF980 + 0x4E)) & 0x1F);
        return;
    }

    if (mode != 0) {
        D_L01_002446C0_004BF980.b88 = 0;
        D_L01_002446C0_004BF980.b89 = 0;
        return;
    }
    D_L01_002446C0_004BF980.f750 = 0;
    sel = D_L01_002446C0_004BF980.cur;
    {
        s32 t = D_L01_002446C0_004BF980.v.e14[sel].b4;
        if (t == 1) {
            func_003C25D8(o, 0xCDB);
            func_003C6F90(o, 0x202020, 0xE, 0xE, 0);
            *(u16 *)(o + 0x32) = 0x40;
            *(s32 *)(o + 0x78) = 0x80808080;
            *(u16 *)(o + 0x34) = 0x2010;
            *(u16 *)(o + 0x7C) = t;
            o[0x31] = t;
            o[0x30] = 0;
            o[0x23] = 0;
            o[0x20] = 0;
            *(s32 *)(o + 0x98) = 0;
            D_L01_002446C0_004BF980.ff94 = 3.5f;
            *(u128_t *)&D_L01_002446C0_004BF980.ffC0 = D_001DABF0_sda;
            if (((u8 *)D_00143950)[0xAD] != 0) {
                D_L01_002446C0_004BF980.ffC8 = D_L01_002446C0_004BF980.ffC8 - 0.55f;
            }
            *(s32 *)(o + 0xF0) = 0;
            *(s32 *)(o + 0xF4) = 0;
            *(s32 *)(o + 0xF8) = 0;
            func_003C7C38(o);
            D_L01_002446C0_004BF980.f98 = 0;
            D_L01_002446C0_004BF980.f8c = 0;
            D_L01_002446C0_004BF980.b88 = 1;
            return;
        }
        if (D_L01_002446C0_004BF980.v.e14[sel].b11 != 0) {
            func_L01_00419E60((u8 *)loc, D_L01_002446C0_004BF980.v.e14[sel].f0, 2);
            func_L01_004BC0B8((s32)func_00381FF0(*(s16 *)(loc + 0x42)));
        } else {
            e = D_L01_002446C0_004BF980.v.e14[sel].f0;
            func_L01_004BC0B8((s32)func_00381FF0(*(s16 *)((u8 *)D_L01_002C5600 + D_001425C0_u8[e] * 0xF0 + 0x42)));
        }
        func_003A2750(1);
        func_L01_0042D330(D_L01_002446C0_004BF980.v.e14[D_L01_002446C0_004BF980.cur].f8, D_L01_002446C0_004BF980.f1c);
        D_L01_002446C0_004BF980.b89 = 1;
        D_L01_002446C0_004BF980.f70 = D_L01_002446C0_004BF980.cur;
        D_L01_002446C0_004BF980.b88 = 0;
        return;
    }
}
/* localdecomp:end func_L01_004BF980 */
