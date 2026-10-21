#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern f32 func_003C3BE8(f32, f32, f32);
extern void (*D_001D9A40[2])(s32);
typedef int u128_t __attribute__((mode(TI)));
extern void func_003C47E8();
extern void func_003C47E8(void *, void *);
extern f32 func_003C4138(f32 *, f32, f32);
extern void func_003C48A8();
extern f32 func_003C4088(f32, f32, f32);
extern void func_003C3860(void);
extern void func_003C31B0(void);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003C3860();
extern void func_003C31B0();
extern void func_003C2FE8();
extern int func_003C38E0();
/* --- end of declarations from other files --- */

LINKER_REMNANT("asm/remnants", func_003C2FE0);

/* localdecomp:start func_003C2FE8 */
typedef struct { f32 x, y, z, w; } V4_3BDAC8;
typedef struct { f32 m[12]; V4_3BDAC8 v; } M_3BDAC8;
typedef int Q_3BDAC8 __attribute__((mode(TI)));
extern void func_003CA4A0();
extern void func_0038CE20(f32 *, void *, f32);
extern void func_0038D570();
extern void func_0038D640();
void func_003C2FE8(u8 *a, s32 n, s32 c, u8 *out) {
    f32 buf[16];
    f32 scale;
    u8 *p, *q;
    s32 i;
    M_3BDAC8 *o;
    Q_3BDAC8 x, y;
    scale = *(f32 *)(a + 0x2C) * 0.0009765625f;
    func_0038D570(buf, a + 0xC0);
    func_003CA4A0(a, n, c, out);
    o = (M_3BDAC8 *)out;
    for (i = 0; i < n; i++) {
        func_0038D640(&o[i], buf, &o[i]);
        func_0038CE20((f32 *)&o[i].v, &o[i].v, scale);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V4_3BDAC8 *)&o[i].v));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V4_3BDAC8 *)(a + 0x10)));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(*(V4_3BDAC8 *)&o[i].v) : "j"(x));
    }

}
/* localdecomp:end func_003C2FE8 */

/* localdecomp:start func_003C30C0 */
extern int D_001DA050_003C30C0;
__asm__(".extern D_001DA050_003C30C0, 16");
extern int D_001DA490_003C30C0;
__asm__(".extern D_001DA490_003C30C0, 16");
extern s32 D_001D4BB0_003C30C0;
__asm__(".extern D_001D4BB0_003C30C0, 4");
extern void func_003CB050();
extern void func_003A9618();
void func_003C30C0(void) {
    u32 *s0, *t;
    u32 c;
    c = 0x20000000;
    t = ((u32 *)D_001DA050_003C30C0);
    s0 = t;
    t += 4;
    D_001DA050_003C30C0 = (int)t;
    ((u32 *)D_001DA490_003C30C0)[0] = c;
    ((u32 *)D_001DA490_003C30C0)[1] = D_001DA050_003C30C0;
    ((u32 *)D_001DA490_003C30C0)[2] = 0;
    ((u32 *)D_001DA490_003C30C0)[3] = 0;
    func_003CB050(D_001D4BB0_003C30C0);
    func_003A9618();
    ((u32 *)D_001DA050_003C30C0)[0] = c;
    ((u32 *)D_001DA050_003C30C0)[1] = D_001DA490_003C30C0 + 0x10;
    ((u32 *)D_001DA050_003C30C0)[2] = 0;
    ((u32 *)D_001DA050_003C30C0)[3] = 0;
    D_001DA050_003C30C0 = (int)(((u32 *)D_001DA050_003C30C0) + 4);
    s0[0] = c;
    s0[1] = D_001DA050_003C30C0;
    s0[2] = 0;
    s0[3] = 0;
}
/* localdecomp:end func_003C30C0 */

/* localdecomp:start func_003C31B0 */
typedef struct { s16 a; s16 b; } T_BDC90;
typedef struct { u8 c[0xC]; s32 fC; } E_BDC90;
typedef struct { u8 p0[0x20]; E_BDC90 *f20; } O_BDC90;
extern s32 D_002DDFF0[];
extern O_BDC90 *D_002DA740[];
extern T_BDC90 D_002DD830[];
void func_003C31B0(void) {
    s32 *p;
    E_BDC90 *e;
    u8 *c;
    u8 *o;
    T_BDC90 *t;
    for (p = D_002DDFF0; *p >= 0; p++) {
        e = D_002DA740[*p]->f20;
        for (;;) {
            o = (u8 *)(e->fC & 0x7FFFFFFF);
            c = e->c;
            if (*c != 0xFF) {
                do {
                    t = &D_002DD830[*c];
                    if (t->a != 0) { *(u32 *)(o + 0x30) = (*(u32 *)(o + 0x30) & 0xFFFFC000) | t->a; }
                    if (t->b != 0) { *(u32 *)(o + 0x40) = (*(u32 *)(o + 0x40) & 0xFFFFC000) | t->b; }
                    c++;
                    o += 0x40;
                } while (*c != 0xFF);
            }
            if (e->fC < 0) break;
            e++;
        }
    }
}
/* localdecomp:end func_003C31B0 */

/* localdecomp:start func_003C3288 */
extern int D_001DA4E4_003C3288;
__asm__(".extern D_001DA4E4_003C3288, 16");
extern s32 D_001DA4E0;
__asm__(".extern D_001DA4E0, 16");
extern s32 D_001D9D34_003C3288;
__asm__(".extern D_001D9D34_003C3288, 4");
extern s32 D_001D5BA8_003C3288;
__asm__(".extern D_001D5BA8_003C3288, 16");
extern void func_003D1708();
extern void func_003D13B0();
void func_003C3288(void) {
    u32 *s0, *t;
    u32 c;
    if (D_001DA4E0 == 0) {
        ((u32 *)D_001DA4E4_003C3288)[0] = 0x10000000;
        ((u32 *)D_001DA4E4_003C3288)[1] = 0;
        ((u32 *)D_001DA4E4_003C3288)[2] = 0;
        ((u32 *)D_001DA4E4_003C3288)[3] = 0;
    } else {
        c = 0x20000000;
        t = ((u32 *)D_001DA050_003C30C0);
        s0 = t;
        t += 4;
        D_001DA050_003C30C0 = (int)t;
        ((u32 *)D_001DA4E4_003C3288)[0] = c;
        ((u32 *)D_001DA4E4_003C3288)[1] = D_001DA050_003C30C0;
        ((u32 *)D_001DA4E4_003C3288)[2] = 0;
        ((u32 *)D_001DA4E4_003C3288)[3] = 0;
        func_003D1708(D_001D9D34_003C3288, D_001D5BA8_003C3288);
        func_003D13B0(D_001D9D34_003C3288);
        ((u32 *)D_001DA050_003C30C0)[0] = c;
        ((u32 *)D_001DA050_003C30C0)[1] = D_001DA4E4_003C3288 + 0x10;
        ((u32 *)D_001DA050_003C30C0)[2] = 0;
        ((u32 *)D_001DA050_003C30C0)[3] = 0;
        D_001DA050_003C30C0 = (int)(((u32 *)D_001DA050_003C30C0) + 4);
        s0[0] = c;
        s0[1] = D_001DA050_003C30C0;
        s0[2] = 0;
        s0[3] = 0;
    }
}
/* localdecomp:end func_003C3288 */

typedef struct { u8 pB_[0xB]; u8 bB; u8 pC[0x14]; s32 f20; } T_3BDEA8;
typedef struct { u8 p0[0x24]; T_3BDEA8 *f24; } O_3BDEA8;
extern u8 *D_001DA530;
extern u8 D_002FC1A0[];
extern u8 D_00380120[];
extern u8 D_001D7830[];
extern void func_0038CD28();
INCLUDE_ASM("asm/nonmatchings/text", func_003C33C8);

/* func_003C35F0: from the US C of func_003BE0D0 (rac3-uya-decomp, commit 13cf5c5), matched here with
   this file's flags. */

/* Retail reaches the word at 0x001D9D30 through lui/lw in the destination register, not $gp: the
   assembler's expansion, through an alias declared sized with an `.extern X, 16` hint (docs/wiki/Matching-Patterns.md: gcc leaves the access to the assembler as one macro, which the hint makes it expand with lui, as SN's single-pass Ps2EeAs did). */


/* localdecomp:start func_003C35F0 */
extern s32 D_001D9D30_003C35F0;
__asm__(".extern D_001D9D30_003C35F0, 16");
extern u8 D_00380250[];
extern s32 D_001D9D38;
extern void func_11F0A0(s32);
extern void func_0038CD28(u32 *, s32, s32);
extern void func_003CB300();
void func_003C35F0(void) {
    func_11F0A0(0);
    func_0038CD28((u32 *)0x70003800, (s32)D_00380250, 0x800);
    func_003CB300(D_001D9D30_003C35F0, D_001D9D38);
}
/* localdecomp:end func_003C35F0 */

/* localdecomp:start func_003C3638 */
extern void func_0038CB78();
 
void func_003C3638(void) {
    func_0038CB78(0x70003A00, 0x40000000, 0x3C0);
}
/* localdecomp:end func_003C3638 */

/* localdecomp:start func_003C3660 */
extern void func_0038CD28();
extern u8 D_002DA380[];
 
void func_003C3660(void) {
    func_0038CD28((s32)D_002DA380, 0x70003A00, 0x3C0);
}
/* localdecomp:end func_003C3660 */

/* localdecomp:start func_003C3690 */
extern void func_0038CD28();
 extern u8 D_002DA380[];

void func_003C3690(void) {
    func_0038CD28(0x70003A00, (s32)D_002DA380, 0x3C0);
}
/* localdecomp:end func_003C3690 */

extern void func_003A8F90(void *);
extern u8 D_002FC1A0[];
extern void func_003A9338();
extern void func_003A9440(s32, unsigned long);
extern u8 D_00110790[];
extern u8 D_00100080[];
extern u16 D_00110780[];
extern s32 D_001D9D1C_003C36C0;
extern s32 D_001DA050_003C36C0;
extern s32 D_001D9D38_003C36C0;
extern s32 D_001D9D30_003C36C0;
extern s32 D_001DA490_003C36C0;
extern u8 *D_001DA530_003C36C0;
extern s32 D_001DA054_003C36C0;
extern s32 D_001DA498_003C36C0;
extern s32 D_001DA4E4_003C36C0;
INCLUDE_ASM("asm/nonmatchings/text", func_003C36C0);

/* func_003C3780: from the US C of func_003BE260 (rac3-uya-decomp, commit 13cf5c5), matched here with
   this file's flags. */


/* localdecomp:start func_003C3780 */
extern void *D_001DA498_003C3780;
extern void *D_001DA498_003C3780_x;
__asm__(".extern D_001DA498_003C3780_x, 16");
extern void func_003A9440(s32, unsigned long);
extern void func_11F0A0(s32);
extern void func_003C3690(void);
extern void *func_003CB3E0(s32, void *, s32, s32);
extern void func_003C3660(void);
void func_003C3780(s32 a0, s32 a1) {
    func_003A9440(0x47, 0x5360B);
    func_11F0A0(0);
    func_003C3690();
    D_001DA498_003C3780 = func_003CB3E0(a0, D_001DA498_003C3780_x, a1, 0);
    func_003C3660();
    D_001DA498_003C3780_x = (u8 *)D_001DA498_003C3780_x - 0x10;
}
/* localdecomp:end func_003C3780 */

/* func_003C3800: retail reaches the word at 0x001DA4E4 and the word at 0x001DA530
   through lui/lw in the destination register, not $gp: the assembler's expansion
   (see func_003C35F0 in this file).
   The pointer compared against &D_002FC1A0 is read from the global D_001DA530
   (through $gp) before the test and re-read after the call in the taken path. */

/* localdecomp:start func_003C3800 */
/* Reached with lui in retail, as the assembler expands an access to a global it does not know to be
   small: declared sized (gcc leaves the access to the assembler as one macro), then with a section
   attribute, which keeps gcc's .extern size hint out of the assembly. */
extern s32 D_001DA4E4_003C3800;
extern u32 D_001DA530_003C3800;
__asm__(".extern D_001DA4E4_003C3800, 16");
__asm__(".extern D_001DA530_003C3800, 16");
extern void func_003C30C0(void);
extern void func_003C35F0(void);
extern void func_003C3288(void);
extern void func_003C33C8(void);
extern s32 D_001DA4E4[];
extern u8 *D_001DA530;
extern u8 D_002FC1A0[];
void func_003C3800(void) {
    u8 *p;
    func_003C30C0();
    func_003C35F0();
    p = D_001DA530;
    if (D_001DA4E4_003C3800 != 0) {
        func_003C3288();
        p = (u8 *)D_001DA530_003C3800;
    }
    if (p > D_002FC1A0) {
        func_003C33C8();
    }
}
/* localdecomp:end func_003C3800 */

extern void func_003C36C0();
extern void func_003C3800();
s32 func_003CB3E0_003C3860(s32, s32, s32, s32);
extern s32 D_001DA498;
extern s32 D_001DA49C;
extern s32 D_001DA4D4;
INCLUDE_ASM("asm/nonmatchings/text", func_003C3860);

LINKER_REMNANT("asm/remnants", func_003C38C0);

extern int D_001DA49C;
extern int D_001DA4A4;
INCLUDE_ASM("asm/nonmatchings/text", func_003C38E0);

LINKER_REMNANT("asm/remnants", func_003C3920);

/* localdecomp:start func_003C3938 */
typedef struct { u8 p10[0x10]; u8 n; u8 f11; } T_3BE418;
typedef struct { u8 p0[0x48]; T_3BE418 *e[1]; } Q_3BE418;
typedef struct {
    u8 p0[0x24]; Q_3BE418 *f24; u8 p28[0x18];
    u8 f40; u8 f41; u8 f42; u8 f43; s32 f44; f32 f48; f32 f4C; u8 p50[8]; f32 *f58; u8 p5c[4]; u8 f60; u8 p61[0xB]; u8 f6C;
} S_3BE418;
extern void func_003C29B0();
void func_003C3938(S_3BE418 *p, s32 idx, s32 lim) {
    s32 v;
    s32 n;
    v = lim;
    if (!(lim < p->f24->e[idx]->n)) v = p->f24->e[idx]->n - 1;
    p->f42 = idx;
    p->f40 = v;
    p->f41 = v + 1;
    n = p->f24->e[idx]->n - 1;
    if (n < p->f41) p->f41 = n;
    p->f43 = idx;
    p->f44 = 0;
    if (!(p->f41 < p->f24->e[idx]->n)) p->f41 = 0;
    func_003C29B0(p);
    p->f4C = *p->f58;
    p->f60 &= 0xFD;
    p->f6C = p->f24->e[idx]->f11;
}
/* localdecomp:end func_003C3938 */

INCLUDE_ASM("asm/nonmatchings/text", func_003C3A10);
TEXT_PADDING(4);

typedef struct {
    u8 p0[0x24]; Q_3BE418 *f24; u8 p28[0x18];
    u8 f40; u8 f41; u8 f42; u8 f43; f32 f44; f32 f48; f32 f4C; void *f50; void *f54; u8 p58[8]; u8 f60; u8 p61[0xB]; u8 f6C;
    u8 p6D[0x13]; u128_t f80; u8 p90[0x19]; u8 fA9;
} S_3BE4F0;
extern u128_t D_002DA100[];
extern void func_003C6EA0_003BE4F0();
extern s32 func_003C2D30();
extern void func_003C8B18();

LINKER_REMNANT("asm/remnants", func_003C3BC8);

extern f32 func_0038D098(f32);
INCLUDE_ASM("asm/nonmatchings/text", func_003C3BE8);

LINKER_REMNANT("asm/remnants", func_003C3C80);

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3BE7F0;
extern V_3BE7F0 D_00227660;
s32 func_003D3CB0(V_3BE7F0 *, V_3BE7F0 *, s32, s32, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003C3D30);

/* localdecomp:start func_003C3DA0 */
typedef int Q_3BE860 __attribute__((mode(TI)));
extern V_3BE7F0 D_001A4C90;
extern void func_003C5180_003C3DA0();
s32 func_003C3DA0(V_3BE7F0 *out, void *obj, s32 flags, s32 c, f32 scale) {
    V_3BE7F0 a, b, d;
    Q_3BE860 x, y;
    func_003C5180_003C3DA0(obj, &d, 1);
    a = D_001A4C90;
    func_0038CE20((f32 *)&b, &d, scale);

    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V_3BE7F0 *)obj));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(b));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(b) : "j"(x));
    if (func_003D3CB0(&b, &a, flags | 2, c, 0)) {
        *out = D_00227660;
        return 1;
    }
    *out = a;
    return 0;
}
/* localdecomp:end func_003C3DA0 */

LINKER_REMNANT("asm/remnants", func_003C3E88);

extern s32 D_001D99C0;
extern s32 D_001D99A8;
extern f32 D_001D99B8;
extern f32 D_001D99BC;
extern f32 D_001D99B0[];
extern s32 func_00381D50();
extern f32 func_0038CF38();
INCLUDE_ASM("asm/nonmatchings/text", func_003C3EC8);

/* localdecomp:start func_003C3FC0 */
extern s32 func_0038D688();
extern void func_0038D750(void *, s32, f32);
void func_003C3FC0(s32 *arg0, void *arg1) {
    s32 spv[12];

    func_0038D750(&spv[8], 0, (*(f32 *)((u8 *)arg1 + 0)));
    func_0038D750(&spv[4], 1, (*(f32 *)((u8 *)arg1 + 4)));
    func_0038D750(spv, 2, (*(f32 *)((u8 *)arg1 + 8)));
    ((s32 (*)())func_0038D688)(arg0, &spv[8], &spv[4]);
    ((s32 (*)())func_0038D688)(arg0, arg0, spv);
}
/* localdecomp:end func_003C3FC0 */

LINKER_REMNANT("asm/remnants", func_003C4058);

/* localdecomp:start func_003C4088 */
f32 func_003C4088(f32 a, f32 b, f32 t) {
    return a + (b - a) * t;
}
/* localdecomp:end func_003C4088 */

/* localdecomp:start func_003C4098 */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} __attribute__((aligned(16))) Vector_003BEB58;
extern f32 func_003C4088(f32, f32, f32);
void func_003C4098(Vector_003BEB58 *output, Vector_003BEB58 first, Vector_003BEB58 second, f32 fraction) {
    output->x = func_003C4088(first.x, second.x, fraction);
    output->y = func_003C4088(first.y, second.y, fraction);
    output->z = func_003C4088(first.z, second.z, fraction);
    output->w = func_003C4088(first.w, second.w, fraction);
}
/* localdecomp:end func_003C4098 */

LINKER_REMNANT("asm/remnants", func_003C4130);

/* localdecomp:start func_003C4138 */
f32 func_003C4138(f32 *arg0, f32 fparg0, f32 fparg1) {
    f32 temp_f1;
    f32 var_f0;
    f32 var_f13;

    var_f13 = fparg1;
    var_f0 = fparg0 - *arg0;
    if ((var_f13 < var_f0) || (var_f13 = -var_f13, (var_f0 < var_f13))) {
        var_f0 = var_f13;
    }
    temp_f1 = *arg0 + var_f0;
    *arg0 = temp_f1;
    { f32 r; __asm__("abs.s %0, %1" : "=f"(r) : "f"(fparg0 - temp_f1)); return r; }
}
/* localdecomp:end func_003C4138 */

LINKER_REMNANT("asm/remnants", func_003C4188);

INCLUDE_ASM("asm/nonmatchings/text", func_003C41A0);

LINKER_REMNANT("asm/remnants", func_003C4348);

INCLUDE_ASM("asm/nonmatchings/text", func_003C4360);
TEXT_PADDING(2);

LINKER_REMNANT("asm/remnants", func_003C4538);

INCLUDE_ASM("asm/nonmatchings/text", func_003C4598);

typedef struct { s32 v[3]; } N3_3BF058;
extern N3_3BF058 D_001D9118;
INCLUDE_ASM("asm/nonmatchings/text", func_003C45A0);

/* localdecomp:start func_003C47E8 */
extern void func_0038D570(void *, void *);
extern void func_003C45A0(void *, void *);
extern void func_0038D590(void *, void *);
void func_003C47E8(void *a, void *b) {
    u8 m[0x40];
    func_0038D570(m, b);
    func_003C45A0(a, m);
    func_0038D590(b, m);
}
/* localdecomp:end func_003C47E8 */

LINKER_REMNANT("asm/remnants", func_003C4838);

/* localdecomp:start func_003C4840 */
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern void func_0038CE20(f32 *, void *, f32);
void func_003C4840(f32 *q, void *axis, f32 angle) {
    f32 h = angle * 0.5f;
    func_0038CE20(q, axis, func_0038D0B0(h));
    q[3] = func_0038D098(h);
}
/* localdecomp:end func_003C4840 */

extern f32 func_0038CED8(f32 *);
extern f32 func_0038D160(f32, f32);
INCLUDE_ASM("asm/nonmatchings/text", func_003C48A8);

INCLUDE_ASM("asm/nonmatchings/text", func_003C4A40);

extern void func_003C6FB0(s32, s32 *, s32 *, s32 *);
typedef struct { s16 x0; s16 x2; u8 x4, x5, x6; u8 p7[5]; u16 xC; s16 xE; } S_BF;

LINKER_REMNANT("asm/remnants", func_003C4B30);
