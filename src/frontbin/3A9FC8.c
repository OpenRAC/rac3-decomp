#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3A9CA8.c's earlier functions */
extern u8 D_001D8064;
extern void func_0038D640();
extern int D_001DA050[];
extern u32 *D_001DA050_g;
extern void func_003A9F70(void);

/* localdecomp:start func_003A9FC8 */
/* from the NTSC decomp's (OpenRAC games/rac3/ntsc) func_003A4A78 */
typedef struct { s16 n; u8 p2[4]; s16 bone; u8 p8[8]; } E_003A9FC8;
typedef struct { s16 n; u8 p2[6]; s16 h8; u8 pA[2]; f32 fC; void *e10; u8 p14[0x10]; s32 f24; } O_003A9FC8;
typedef struct { u8 p0[0xB0]; f32 fB0; f32 fB4; } S_003A9FC8;
__asm__(".extern D_001D8064, 1");
__asm__(".extern D_001D8060, 4");
extern u8 D_001D8064;
extern f32 D_001D8060;
extern s32 D_001D4BC0;
extern s32 D_001D4BC4;
extern S_003A9FC8 D_00225900_003A9FC8;
extern void func_0038CBA0(void *, s32);
extern void func_0038D2A0(void *);
extern void func_003A9DB0(O_003A9FC8 *, void *, f32);
extern void func_0038D080_003A9FC8(void *, long);
extern void func_0038D028_003A9FC8(void *, void *, void *);
extern void func_0038CDD0_003A9FC8(void *, void *, void *);
extern void func_0038CDB8_003A9FC8(void *, void *, void *);

void func_003A9FC8(O_003A9FC8 *a, f32 *ow, f32 *oh, f32 sx, f32 sy, f32 t) {
    f32 m[16];
    f32 mn[4];
    f32 mx[4];
    f32 v[4];
    f32 v2[4];
    u8 *spr;

    if (D_001D8064 != 0) {
        sx *= a->fC * 1.18f;
        sy *= a->fC * 1.126f * D_001D8060;
    } else {
        sx *= a->fC;
        sy *= a->fC;
    }
    func_0038CBA0(m, 0x40);
    spr = (u8 *)0x70002000;
    m[0] = ((f32)(D_001D4BC0 >> 1) / D_00225900_003A9FC8.fB0) * sx;
    m[9] = -((f32)(D_001D4BC4 >> 1) / D_00225900_003A9FC8.fB4) * sy;
    func_0038D2A0((void *)0x70001FC0);
    if (a->h8 != 0) {
        func_003A9DB0(a, (void *)0x70002000, t);
    }
    mn[0] = 100000.0f;
    mn[1] = 1000000.0f;
    mx[0] = -100000.0f;
    mx[1] = -1000000.0f;
    if (a->f24 == 0) {
        E_003A9FC8 *p = a->e10;
        s32 i;
        for (i = 0; i < a->n; i++) {
            func_0038D080_003A9FC8(v, *(long *)p);
            v[3] = 1.0f;
            func_0038D028_003A9FC8(v, v, spr + p->bone * 64);
            func_0038D028_003A9FC8(v, v, m);
            func_0038CDD0_003A9FC8(mn, mn, v);
            func_0038CDB8_003A9FC8(mx, mx, v);
            p++;
        }
    } else {
        s32 *p = a->e10;
        s32 i;
        for (i = 0; i < a->n; i++) {
            s32 j;
            ((s32 *)v)[0] = (*p << 18) >> 16;
            ((s32 *)v)[1] = (*p << 4) >> 16;
            j = *p >> 28;
            func_0038D080_003A9FC8(v2, *(long *)v);
            v2[3] = 1.0f;
            func_0038D028_003A9FC8(v2, v2, spr + j * 64);
            func_0038D028_003A9FC8(v2, v2, m);
            func_0038CDD0_003A9FC8(mn, mn, v2);
            func_0038CDB8_003A9FC8(mx, mx, v2);
            p++;
        }
    }
    *ow = (mx[0] - mn[0]) * 0.0625f;
    *oh = (mx[1] - mn[1]) * 0.0625f;
}
/* localdecomp:end func_003A9FC8 */

/* PAL draft of func_003AA320 (rac3-uya-decomp func_003A4DC8, commit 13cf5c5), names moved to PAL addresses
   where known. The US callee func_003A4E70 is func_003AA3C8 in PAL. */


/* localdecomp:start func_003AA320 */
typedef struct { u8 p0[0xC]; f32 fC; } O_A4DC8;
extern void func_0038D2A0();
extern void func_003AA3C8(O_A4DC8 *, f32, f32, s32, f32, f32 *);
void func_003AA320(O_A4DC8 *o, s32 flag, f32 a, f32 b, f32 c, f32 d, f32 e) {
    f32 m[16];
    if ((flag >> 24) != 0) {
        func_0038D2A0(m);
        m[0] = c * o->fC;
        m[10] = d * o->fC;
        func_003AA3C8(o, a, b, flag, e, m);
    }
}
/* localdecomp:end func_003AA320 */

/* localdecomp:start func_003AA3C8 */
#include "vu0.h"
typedef struct { unsigned long v; u16 h8; u16 hA; u16 hC; u16 hE; } T_003AA3C8;
typedef struct { s32 w0; s16 h4; s16 h6; s32 w8; u8 bC; u8 bD; s16 hE; } C_003AA3C8;
typedef struct {
    s16 h0; s16 h2; u8 p4[2]; s16 h6; s16 h8; u8 pA[2]; f32 fC;
    void *p10; u8 *p14; T_003AA3C8 *p18; u8 *p1C; u8 p20[4]; s32 w24; s32 w28;
} V_003AA3C8;
typedef struct { u8 p0[0xB0]; f32 fB0; f32 fB4; } S_003AA3C8;
typedef struct { u8 p0[0xAD]; u8 bAD; } G_003AA3C8;
__asm__(".extern D_001D8064, 1");
__asm__(".extern D_001D8060, 4");
__asm__(".extern D_001D8070, 4");
__asm__(".extern D_001D8020, 8");
__asm__(".extern D_001DA050_g, 4");
extern u8 D_001D8064;
extern f32 D_001D8060;
extern f32 D_001D8070;
extern long D_001D8020;
extern int D_001DA050[];
extern u8 *D_001DA050_003AA3C8;
extern u32 *D_001DA050_g;
extern C_003AA3C8 D_00225C00[];
extern s32 D_001D4BB0;
extern s32 D_001D9BFC;
extern s32 D_001D4BC0;
extern s32 D_001D4BC4;
extern s32 D_001D4BD0;
extern s32 D_001D4BD4;
extern S_003AA3C8 D_00225900_003AA3C8;
extern G_003AA3C8 D_00143950_b_003AA3C8;
extern void func_003A9F70(void);
extern void func_0038D2A0();
extern void func_0038D640();
extern void func_0038CE20_003AA3C8(f32 *, f32 *, f32);
extern void func_003A9DB0_003AA3C8(V_003AA3C8 *, void *, f32);
extern void func_003A04E8_003AA3C8(void *, f32 *, s32, s32);
extern void func_003A0628_003AA3C8(void *, f32 *, s32, s32, s32);
void func_003AA3C8(O_A4DC8 *oa, f32 x, f32 y, s32 flag, f32 z, f32 *m) {
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
            n = D_001D9BFC;
            t = ((unsigned long)b1 | ((unsigned long)w << 14) | ((unsigned long)0x13 << 20) | (((long)e->hC << 48) >> 22) |
                (((long)e->hE << 48) >> 18) | ((unsigned long)1 << 34) | ((unsigned long)b0 << 37) | ((unsigned long)4 << 61));
            D_001D4BB0 = base + sz;
            e->v = t;
            if (n < 0x40) {
                D_00225C00[n].w0 = (s32)o->p1C + (e->hA << 4);
                D_00225C00[n].h4 = 0;
                D_00225C00[n].h6 = b0;
                D_00225C00[n].w8 = (s32)o->p1C + (e->h8 << 4);
                D_00225C00[n].bC = e->hC;
                D_00225C00[n].bD = e->hE;
                D_00225C00[n].hE = b1;
                D_001D9BFC = n + 1;
            }
        }
        func_003A9F70();
        if (D_001D8064 != 0) {
            f32 k = D_001D8060 * 1.126f;
            m[0] *= 1.18f;
            m[10] *= k;
        }
        func_0038CE20_003AA3C8(m + 12, m + 12, 166.666f);
        {
            f32 a, b;
            f32 *p = &D_001D8070;
            a = (f32)(D_001D4BC0 >> 1) / D_00225900_003AA3C8.fB0;
            b = -((f32)(D_001D4BC4 >> 1) / D_00225900_003AA3C8.fB4);
            D_001D8070 = a;
            (&D_001D8070)[9] = b;
            if (D_00143950_b_003AA3C8.bAD != 0) (&D_001D8070)[9] = b * 0.75000006f;
            func_0038D640(s, p, m);
        }
        s[12] += (f32)D_001D4BD0 + x * 16.0f;
        s[13] += (f32)D_001D4BD4 + y * 16.0f;
        func_0038D2A0((void *)0x70001FC0);
        if (o->h8 != 0) func_003A9DB0_003AA3C8(o, (void *)0x70002000, z);
        if (o->w24 == 0) func_003A04E8_003AA3C8(o->p10, s, o->h0, flag);
        else func_003A0628_003AA3C8(o->p10, s, o->h0, o->w28, flag);
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
            D_001DA050_g[0] = 0x10000008;
            ((u32 *)D_001DA050_003AA3C8)[1] = 0;
            ((u32 *)D_001DA050_003AA3C8)[2] = 0;
            ((u32 *)D_001DA050_003AA3C8)[3] = 0x50000008;
            D_001DA050_003AA3C8 += 0x10;
            *(vu0_q *)D_001DA050_003AA3C8 = *(vu0_q *)&D_001D8020;
            D_001DA050_003AA3C8 += 0x10;
            d = (unsigned long *)D_001DA050_003AA3C8;
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
            D_001DA050_003AA3C8 += 0x70;
        }
    }
}
/* localdecomp:end func_003AA3C8 */
