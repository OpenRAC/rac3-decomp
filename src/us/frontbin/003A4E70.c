#include "common.h"

/* NTSC-U counterpart of func_003AA3C8 (frontbin). */
extern u8 D_U_001D8060;
extern void func_U_00388F08();
extern u32 *D_U_001DA0D0_g;
extern void func_U_003A4A20(void);
extern u8 D_U_001D8060;
extern s32 D_001D4BC0;
extern s32 D_001D4BC4;
extern void func_U_00388B68(void *);
__asm__(".extern D_U_001D8060, 1");
typedef struct { u8 p0[0xC]; f32 fC; } O_A4DC8;
extern void func_U_00388B68();
extern void func_U_003A4E70(O_A4DC8 *, f32, f32, s32, f32, f32 *);

/* localdecomp:start func_U_003A4E70 */
#include "vu0.h"
typedef struct { unsigned long v; u16 h8; u16 hA; u16 hC; u16 hE; } T_003AA3C8;
typedef struct { s32 w0; s16 h4; s16 h6; s32 w8; u8 bC; u8 bD; s16 hE; } C_003AA3C8;
typedef struct {
    s16 h0; s16 h2; u8 p4[2]; s16 h6; s16 h8; u8 pA[2]; f32 fC;
    void *p10; u8 *p14; T_003AA3C8 *p18; u8 *p1C; u8 p20[4]; s32 w24; s32 w28;
} V_003AA3C8;
typedef struct { u8 p0[0xB0]; f32 fB0; f32 fB4; } S_003AA3C8;
typedef struct { u8 p0[0xAD]; u8 bAD; } G_003AA3C8;
__asm__(".extern D_U_001D8060, 1");
__asm__(".extern D_U_001D8070, 4");
__asm__(".extern D_U_001D8020, 8");
__asm__(".extern D_U_001DA0D0_g, 4");
extern u8 D_U_001D8060;
extern f32 D_U_001D8070;
extern long D_U_001D8020;
extern u8 *D_U_001DA0D0_003A4E70;
extern u32 *D_U_001DA0D0_g;
extern C_003AA3C8 D_U_00225C80[];
extern s32 D_001D4BB0;
extern s32 D_U_001D9C7C;
extern s32 D_001D4BC0;
extern s32 D_001D4BC4;
extern s32 D_001D4BD0;
extern s32 D_001D4BD4;
extern S_003AA3C8 D_U_00225980_003A4E70;
extern G_003AA3C8 D_00143950_b_003AA3C8;
extern void func_U_003A4A20(void);
extern void func_U_00388B68();
extern void func_U_00388F08();
extern void func_U_003886E8_003A4E70(f32 *, f32 *, f32);
extern void func_U_003A4860_003A4E70(V_003AA3C8 *, void *, f32);
extern void func_U_0039B4E8_003A4E70(void *, f32 *, s32, s32);
extern void func_U_0039B628_003A4E70(void *, f32 *, s32, s32, s32);
void func_U_003A4E70(O_A4DC8 *oa, f32 x, f32 y, s32 flag, f32 z, f32 *m) {
    V_003AA3C8 *o = (V_003AA3C8 *)oa;
    f32 s[16];
    s32 i;
    s32 base;
    unsigned long tex;
    unsigned long prim;
    u8 *q;
    T_003AA3C8 *e;
    if ((flag >> 24) != 0) {
        for (i = 0; i < o->h6; i++) {
            s32 w, b0, b1, n, sz;
            unsigned long t;
            e = &o->p18[i];
            base = D_001D4BB0;
            sz = 1 << ((s16)e->hC + (s16)e->hE);
            w = (s16)e->hC - 6;
            if (w < 0) w = 0;
            w = 1 << w;
            b0 = base >> 8;
            base += 0x400;
            b1 = base >> 8;
            n = D_U_001D9C7C;
            t = ((unsigned long)b1 | ((unsigned long)w << 14) | ((unsigned long)0x13 << 20) | (((long)e->hC << 48) >> 22) |
                (((long)e->hE << 48) >> 18) | ((unsigned long)1 << 34) | ((unsigned long)b0 << 37) | ((unsigned long)4 << 61));
            D_001D4BB0 = base + sz;
            e->v = t;
            if (n < 0x40) {
                D_U_00225C80[n].w0 = (s32)o->p1C + (e->hA << 4);
                D_U_00225C80[n].h4 = 0;
                D_U_00225C80[n].h6 = b0;
                D_U_00225C80[n].w8 = (s32)o->p1C + (e->h8 << 4);
                D_U_00225C80[n].bC = e->hC;
                D_U_00225C80[n].bD = e->hE;
                D_U_00225C80[n].hE = b1;
                D_U_001D9C7C = n + 1;
            }
        }
        func_U_003A4A20();
        if (D_U_001D8060 != 0) {
            m[0] *= 1.18f;
            m[10] *= 1.126f;
        }
        func_U_003886E8_003A4E70(m + 12, m + 12, 166.666f);
        {
            f32 a, b;
            f32 *p = &D_U_001D8070;
            a = (f32)(D_001D4BC0 >> 1) / D_U_00225980_003A4E70.fB0;
            b = -((f32)(D_001D4BC4 >> 1) / D_U_00225980_003A4E70.fB4);
            D_U_001D8070 = a;
            (&D_U_001D8070)[9] = b;
            if (D_00143950_b_003AA3C8.bAD != 0) (&D_U_001D8070)[9] = b * 0.75000006f;
            func_U_00388F08(s, p, m);
        }
        s[12] += (f32)D_001D4BD0 + x * 16.0f;
        s[13] += (f32)D_001D4BD4 + y * 16.0f;
        func_U_00388B68((void *)0x70001FC0);
        if (o->h8 != 0) func_U_003A4860_003A4E70(o, (void *)0x70002000, z);
        if (o->w24 == 0) func_U_0039B4E8_003A4E70(o->p10, s, o->h0, flag);
        else func_U_0039B628_003A4E70(o->p10, s, o->h0, o->w28, flag);
        tex = 0x80000004CC007FFBUL;
        e = (T_003AA3C8 *)0x70000000;
        if (o->h6 != 0) { q = o->p14; prim = 0x5C; }
        else { q = o->p14 + 4; prim = 0x4C; }
        for (base = 0; base < o->h2; base++, q += 4) {
            unsigned long *d, *v;
            if (o->h6 != 0 && (*(s32 *)q >> 8) == -1) {
                if (q[0] < o->h6) tex = o->p18[q[0]].v;
                else tex = 0x80000004CC007FFBUL;
                base--;
                continue;
            }
            D_U_001DA0D0_g[0] = 0x10000008;
            ((u32 *)D_U_001DA0D0_003A4E70)[1] = 0;
            ((u32 *)D_U_001DA0D0_003A4E70)[2] = 0;
            ((u32 *)D_U_001DA0D0_003A4E70)[3] = 0x50000008;
            D_U_001DA0D0_003A4E70 += 0x10;
            *(vu0_q *)D_U_001DA0D0_003A4E70 = *(vu0_q *)&D_U_001D8020;
            D_U_001DA0D0_003A4E70 += 0x10;
            d = (unsigned long *)D_U_001DA0D0_003A4E70;
            d[0] = tex;
            d[1] = prim;
            v = (unsigned long *)((u8 *)e + q[0] * 32);
            d[2] = *v++; d[3] = v[0]; d[4] = v[1];
            v = (unsigned long *)((u8 *)e + q[1] * 32);
            d[5] = *v++; d[6] = v[0]; d[7] = v[1];
            v = (unsigned long *)((u8 *)e + q[3] * 32);
            d[8] = *v++; d[9] = v[0]; d[10] = v[1];
            v = (unsigned long *)((u8 *)e + q[2] * 32);
            d[11] = *v++; d[12] = v[0]; d[13] = v[1];
            D_U_001DA0D0_003A4E70 += 0x70;
        }
    }
}
/* localdecomp:end func_U_003A4E70 */
