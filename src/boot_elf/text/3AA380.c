#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3AA060.c's earlier functions */
extern u8 D_001D8064;

/* localdecomp:start func_003AA380 */
typedef struct { s16 count; u8 pad2[6]; s16 animated; u8 padA[2]; f32 scale; void *vertices; u8 pad14[0x10]; s32 packed; } A_003AA380;
typedef struct { long point; u8 pad8[8]; } E_003AA380;
typedef struct { f32 x,y,z,w; } V_003AA380;
extern f32 D_001D8060;
__asm__(".extern D_001D8060, 4");
__asm__(".extern D_001D8064, 1");
extern s32 D_001D4BC0, D_001D4BC4;
typedef struct { u8 pad[0xB0]; f32 x,y; } C_003AA380;
extern C_003AA380 D_00225900;
extern void func_0038CF80(void *,s32);
extern void func_0038D680(f32 *);
extern void func_003AA168(A_003AA380 *,void *,f32);
extern void func_0038D460(void *,long);
extern void func_0038D408(void *,void *,void *);
extern void func_0038D1B0(void *,void *,void *);
extern void func_0038D198(void *,void *,void *);
void func_003AA380(A_003AA380 *a,f32 *outx,f32 *outy,f32 x,f32 y,f32 time) {
    f32 matrix[16];
    V_003AA380 minimum,maximum;
    union { long q; s32 xy[2]; V_003AA380 v; } temp;
    V_003AA380 point;
    E_003AA380 *v;
    s32 *packed;
    s32 i,j,bone;
    /* The EE scratchpad holds the animation matrices and identity matrix. */
    f32 (*scratch)[16];
    if(D_001D8064) {
        x *= a->scale*1.18f;
        y *= (a->scale*1.126f)*D_001D8060;
    } else {
        x *= a->scale;
        y *= a->scale;
    }
    func_0038CF80(matrix,0x40);
    scratch=(f32 (*)[16])0x70002000;
    matrix[0]=((f32)(D_001D4BC0>>1)/D_00225900.x)*x;
    matrix[9]=-((f32)(D_001D4BC4>>1)/D_00225900.y)*y;
    func_0038D680((f32 *)0x70001FC0);
    if(a->animated) func_003AA168(a,scratch,time);
    minimum.x=100000.0f;
    minimum.y=1000000.0f;
    maximum.x=-100000.0f;
    maximum.y=-1000000.0f;
    if(!a->packed) {
        v=a->vertices;
        for(i=0;i<a->count;i++) {
            func_0038D460(&temp,v->point);
            temp.v.w=1.0f;
            func_0038D408(&temp,&temp,scratch[*(s16 *)((u8 *)v+6)]);
            v++;
            func_0038D408(&temp,&temp,matrix);
            func_0038D1B0(&minimum,&minimum,&temp);
            func_0038D198(&maximum,&maximum,&temp);
        }
    } else {
        packed=a->vertices;
        for(j=0;j<a->count;j++) {
            temp.xy[0]=(*packed<<18)>>16;
            temp.xy[1]=(*packed<<4)>>16;
            bone=*packed>>28;
            packed++;
            func_0038D460(&point,temp.q);
            point.w=1.0f;
            func_0038D408(&point,&point,scratch[bone]);
            func_0038D408(&point,&point,matrix);
            func_0038D1B0(&minimum,&minimum,&point);
            func_0038D198(&maximum,&maximum,&point);
        }
    }
    *outx=(maximum.x-minimum.x)*0.0625f;
    *outy=(maximum.y-minimum.y)*0.0625f;
}
/* localdecomp:end func_003AA380 */

/* US draft of func_003AA6D8 (rac3-uya-decomp func_003AA588, commit 13cf5c5), names moved to PAL addresses
   where known. The called helper is func_003AA780 in PAL (func_003AA630 in the US build). */


/* localdecomp:start func_003AA6D8 */
typedef struct { u8 p0[0xC]; f32 fC; } O_A4DC8;
extern void func_0038D680();
extern void func_003AA780(O_A4DC8 *, f32, f32, s32, f32, f32 *);
void func_003AA6D8(O_A4DC8 *o, s32 flag, f32 a, f32 b, f32 c, f32 d, f32 e) {
    f32 m[16];
    if ((flag >> 24) != 0) {
        func_0038D680(m);
        m[0] = c * o->fC;
        m[10] = d * o->fC;
        func_003AA780(o, a, b, flag, e, m);
    }
}
/* localdecomp:end func_003AA6D8 */

/* PAL front-end twin of func_003AA3C8 in src/frontbin/3A9FC8.c. */
/* localdecomp:start func_003AA780 */
#include "vu0.h"
typedef struct { unsigned long v; u16 h8; u16 hA; u16 hC; u16 hE; } T_003AA780;
typedef struct { s32 w0; s16 h4; s16 h6; s32 w8; u8 bC; u8 bD; s16 hE; } C_003AA780;
typedef struct {
    s16 h0; s16 h2; u8 p4[2]; s16 h6; s16 h8; u8 pA[2]; f32 fC;
    void *p10; u8 *p14; T_003AA780 *p18; u8 *p1C; u8 p20[4]; s32 w24; s32 w28;
} V_003AA780;
typedef struct { u8 p0[0xB0]; f32 fB0; f32 fB4; } S_003AA780;
typedef struct { u8 p0[0xAD]; u8 bAD; } G_003AA780;
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
extern u8 *D_001DA050_003AA780;
extern u32 *D_001DA050_g;
extern C_003AA780 D_00225C00[];
extern s32 D_001D4BB0;
extern s32 D_001D9BFC;
extern s32 D_001D4BC0;
extern s32 D_001D4BC4;
extern s32 D_001D4BD0;
extern s32 D_001D4BD4;
extern S_003AA780 D_00225900_003AA780;
extern G_003AA780 D_00143950_b_003AA780;
extern void func_003AA328(void);
extern void func_0038D680();
extern void func_0038DA20();
extern void func_0038D200_003AA780(f32 *, f32 *, f32);
extern void func_003AA168_003AA780(V_003AA780 *, void *, f32);
extern void func_003A08E8_003AA780(void *, f32 *, s32, s32);
extern void func_003A0A28_003AA780(void *, f32 *, s32, s32, s32);
void func_003AA780(O_A4DC8 *oa, f32 x, f32 y, s32 flag, f32 z, f32 *m) {
    V_003AA780 *o = (V_003AA780 *)oa;
    f32 s[16];
    s32 i;
    s32 base;
    unsigned long tex;
    unsigned long prim;
    u8 *q;
    T_003AA780 *e;
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
        func_003AA328();
        if (D_001D8064 != 0) {
            f32 k = D_001D8060 * 1.126f;
            m[0] *= 1.18f;
            m[10] *= k;
        }
        func_0038D200_003AA780(m + 12, m + 12, 166.666f);
        {
            f32 a, b;
            f32 *p = &D_001D8070;
            a = (f32)(D_001D4BC0 >> 1) / D_00225900_003AA780.fB0;
            b = -((f32)(D_001D4BC4 >> 1) / D_00225900_003AA780.fB4);
            D_001D8070 = a;
            (&D_001D8070)[9] = b;
            if (D_00143950_b_003AA780.bAD != 0) (&D_001D8070)[9] = b * 0.75000006f;
            func_0038DA20(s, p, m);
        }
        s[12] += (f32)D_001D4BD0 + x * 16.0f;
        s[13] += (f32)D_001D4BD4 + y * 16.0f;
        func_0038D680((void *)0x70001FC0);
        if (o->h8 != 0) func_003AA168_003AA780(o, (void *)0x70002000, z);
        if (o->w24 == 0) func_003A08E8_003AA780(o->p10, s, o->h0, flag);
        else func_003A0A28_003AA780(o->p10, s, o->h0, o->w28, flag);
        tex = 0x80000004CC007FFBUL;
        e = (T_003AA780 *)0x70000000;
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
            ((u32 *)D_001DA050_003AA780)[1] = 0;
            ((u32 *)D_001DA050_003AA780)[2] = 0;
            ((u32 *)D_001DA050_003AA780)[3] = 0x50000008;
            D_001DA050_003AA780 += 0x10;
            *(vu0_q *)D_001DA050_003AA780 = *(vu0_q *)&D_001D8020;
            D_001DA050_003AA780 += 0x10;
            d = (unsigned long *)D_001DA050_003AA780;
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
            D_001DA050_003AA780 += 0x70;
        }
    }
}
/* localdecomp:end func_003AA780 */
