#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void func_003C3568(void);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003C3568();
extern void func_003C33A0();
/* --- end of declarations from other files --- */

LINKER_REMNANT("asm/boot_elf/remnants", func_003C3398);

/* localdecomp:start func_003C33A0 */
typedef struct { f32 x, y, z, w; } V4_3BDAC8;
typedef struct { f32 m[12]; V4_3BDAC8 v; } M_3BDAC8;
typedef int Q_3BDAC8 __attribute__((mode(TI)));
extern void func_003CA858();
extern void func_0038D200(f32 *, void *, f32);
extern void func_0038D950();
extern void func_0038DA20();
void func_003C33A0(u8 *a, s32 n, s32 c, u8 *out) {
    f32 buf[16];
    f32 scale;
    u8 *p, *q;
    s32 i;
    M_3BDAC8 *o;
    Q_3BDAC8 x, y;
    scale = *(f32 *)(a + 0x2C) * 0.0009765625f;
    func_0038D950(buf, a + 0xC0);
    func_003CA858(a, n, c, out);
    o = (M_3BDAC8 *)out;
    for (i = 0; i < n; i++) {
        func_0038DA20(&o[i], buf, &o[i]);
        func_0038D200((f32 *)&o[i].v, &o[i].v, scale);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V4_3BDAC8 *)&o[i].v));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V4_3BDAC8 *)(a + 0x10)));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(*(V4_3BDAC8 *)&o[i].v) : "j"(x));
    }

}
/* localdecomp:end func_003C33A0 */

/* localdecomp:start func_003C3478 */
extern int D_001DA050_003C3478;
__asm__(".extern D_001DA050_003C3478, 16");
extern int D_001DA490_003C3478;
__asm__(".extern D_001DA490_003C3478, 16");
extern s32 D_001D4BB0_003C3478;
__asm__(".extern D_001D4BB0_003C3478, 4");
extern void func_003CB408();
extern void func_003A99D0();
void func_003C3478(void) {
    u32 *s0, *t;
    u32 c;
    c = 0x20000000;
    t = ((u32 *)D_001DA050_003C3478);
    s0 = t;
    t += 4;
    D_001DA050_003C3478 = (int)t;
    ((u32 *)D_001DA490_003C3478)[0] = c;
    ((u32 *)D_001DA490_003C3478)[1] = D_001DA050_003C3478;
    ((u32 *)D_001DA490_003C3478)[2] = 0;
    ((u32 *)D_001DA490_003C3478)[3] = 0;
    func_003CB408(D_001D4BB0_003C3478);
    func_003A99D0();
    ((u32 *)D_001DA050_003C3478)[0] = c;
    ((u32 *)D_001DA050_003C3478)[1] = D_001DA490_003C3478 + 0x10;
    ((u32 *)D_001DA050_003C3478)[2] = 0;
    ((u32 *)D_001DA050_003C3478)[3] = 0;
    D_001DA050_003C3478 = (int)(((u32 *)D_001DA050_003C3478) + 4);
    s0[0] = c;
    s0[1] = D_001DA050_003C3478;
    s0[2] = 0;
    s0[3] = 0;
}
/* localdecomp:end func_003C3478 */

/* localdecomp:start func_003C3568 */
typedef struct { s16 a; s16 b; } T_BDC90;
typedef struct { u8 c[0xC]; s32 fC; } E_BDC90;
typedef struct { u8 p0[0x20]; E_BDC90 *f20; } O_BDC90;
extern s32 D_002DDFF0[];
extern O_BDC90 *D_002DA740[];
extern T_BDC90 D_002DD830[];
void func_003C3568(void) {
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
/* localdecomp:end func_003C3568 */

/* localdecomp:start func_003C3640 */
extern int D_001DA4E4_003C3640;
__asm__(".extern D_001DA4E4_003C3640, 16");
extern s32 D_001DA4E0;
__asm__(".extern D_001DA4E0, 16");
extern s32 D_001D9D34_003C3640;
__asm__(".extern D_001D9D34_003C3640, 4");
extern s32 D_001D5BA8_003C3640;
__asm__(".extern D_001D5BA8_003C3640, 16");
extern void func_003D1AC0();
extern void func_003D1768();
void func_003C3640(void) {
    u32 *s0, *t;
    u32 c;
    if (D_001DA4E0 == 0) {
        ((u32 *)D_001DA4E4_003C3640)[0] = 0x10000000;
        ((u32 *)D_001DA4E4_003C3640)[1] = 0;
        ((u32 *)D_001DA4E4_003C3640)[2] = 0;
        ((u32 *)D_001DA4E4_003C3640)[3] = 0;
    } else {
        c = 0x20000000;
        t = ((u32 *)D_001DA050_003C3478);
        s0 = t;
        t += 4;
        D_001DA050_003C3478 = (int)t;
        ((u32 *)D_001DA4E4_003C3640)[0] = c;
        ((u32 *)D_001DA4E4_003C3640)[1] = D_001DA050_003C3478;
        ((u32 *)D_001DA4E4_003C3640)[2] = 0;
        ((u32 *)D_001DA4E4_003C3640)[3] = 0;
        func_003D1AC0(D_001D9D34_003C3640, D_001D5BA8_003C3640);
        func_003D1768(D_001D9D34_003C3640);
        ((u32 *)D_001DA050_003C3478)[0] = c;
        ((u32 *)D_001DA050_003C3478)[1] = D_001DA4E4_003C3640 + 0x10;
        ((u32 *)D_001DA050_003C3478)[2] = 0;
        ((u32 *)D_001DA050_003C3478)[3] = 0;
        D_001DA050_003C3478 = (int)(((u32 *)D_001DA050_003C3478) + 4);
        s0[0] = c;
        s0[1] = D_001DA050_003C3478;
        s0[2] = 0;
        s0[3] = 0;
    }
}
/* localdecomp:end func_003C3640 */
