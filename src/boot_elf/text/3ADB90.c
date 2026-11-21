#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003AB2B8(void *, s32);
/* --- end of declarations from other files --- */

/* declarations of 3AD6E0.c's earlier functions */
typedef struct { u8 p0[0x18]; f32 f18; s32 f1C; s32 f20; f32 f24; s8 b28; u8 p29[3]; s32 f2C; u8 p30[0x50]; s32 f80; s32 f84; } S_3A7E80;
typedef struct { u8 pad[0x30]; f32 m[4][4]; f32 v[4]; } S_3A7F90;
typedef struct { f32 a[3]; f32 b[3]; } V_7FC8;
extern void func_003AD7E0(S_3A7E80 *o);
extern void func_003AD8A0(void *p, s32 value);
extern void func_003AD8D8(void *p, s32 value);
extern u8 func_003AD8E0(void *p, u8 value);
extern void func_003AD8F0(S_3A7F90 *p, s32 i, f32 a, f32 b, f32 c, f32 d, f32 e);
extern void func_003AD928(V_7FC8 *s, s32 i, f32 x, f32 y);
extern void func_003AD940(void *p, s32 value);
extern void func_003AD948(u8 *p, s32 a);
extern void func_003AD988(void *p, s32 value);
extern void func_003AD990(void *p, f32 value);

/* localdecomp:start func_003ADB90 */
typedef struct { s32 pad0[0xE]; u8 pad38[2]; u8 flag3A; u8 pad3B; } T3C_003ADB90;
typedef struct { s32 pad0[0xC]; } T30_003ADB90;
typedef struct { s32 pad0[0x10]; } T40_003ADB90;
typedef struct { s32 pad0[0x22]; } T88_003ADB90;
typedef struct {
    T3C_003ADB90 w000;
    T3C_003ADB90 w03C;
    T3C_003ADB90 w078;
    u8 bufB4[0x18];
    u8 padCC[4];
    T40_003ADB90 w0D0;
    T30_003ADB90 w110;
    T3C_003ADB90 w140;
    T3C_003ADB90 w17C;
    u8 buf1B8[0x18];
    T40_003ADB90 w1D0;
    T30_003ADB90 w210;
    u8 pad240[4];
    T3C_003ADB90 w244;
    T3C_003ADB90 w280;
    T3C_003ADB90 items[8];
    T3C_003ADB90 w49C;
    T3C_003ADB90 w4D8;
    T3C_003ADB90 w514;
    T3C_003ADB90 w550;
    T3C_003ADB90 w58C;
    T30_003ADB90 w5C8;
    T30_003ADB90 w5F8;
    T3C_003ADB90 w628;
    T30_003ADB90 rings[8];
    f32 *f7E4;
    T88_003ADB90 fx7E8;
    T88_003ADB90 fx870;
    T88_003ADB90 fx8F8;
    T88_003ADB90 fx980;
    T88_003ADB90 fxA08;
    T88_003ADB90 fxA90;
    void *fB18;
    void *fB1C;
    u8 padB20[8];
    s32 fB28;
    s32 fB2C;
    s32 fB30;
    s32 fB34;
    s32 fB38;
    s32 fB3C;
    u8 fB40;
    u8 padB41[3];
    s32 fB44;
} S_003ADB90;

extern u8 D_001D8530[];
extern u8 D_001D8540[];
extern u8 D_001D8550[];
extern u8 D_001D8558[];
extern u8 D_001D8568[];
extern u8 D_001D8578[];
extern u8 D_001D8588[];
extern u8 D_001D8598[];
extern u8 D_001D85A8[];
extern u8 D_001D85B8[];
extern u8 D_001D85C8[];
extern u8 D_001D85D8[];
extern u8 D_001D85E8[];
extern u8 D_001D85F8[];
extern u8 D_001D8608[];
extern u8 D_001D8618[];
extern u8 D_001D8630[];
extern u8 D_001D8640[];
extern u8 D_001D8650[];
extern u8 D_001D8660[];
extern u8 D_001D8670[];
extern s32 D_001D867C;
extern s32 D_001D8680;
extern f32 D_001D8684;
extern f32 D_001D8688;
extern f32 D_001D868C;
extern s32 D_001D8690;
extern s32 D_001D8694;
extern s32 D_001D8698;
extern s32 D_001D869C;
extern f32 D_001D86A0;
extern f32 D_001D86A4;
extern f32 D_001D86A8;
extern s32 D_001D86AC;
extern s32 D_001D86B0;
extern s32 D_001D86B4;
extern s32 D_00143950[];
__asm__(".extern D_001D867C, 4");
__asm__(".extern D_001D8680, 4");
__asm__(".extern D_001D8684, 4");
__asm__(".extern D_001D8688, 4");
__asm__(".extern D_001D868C, 4");
__asm__(".extern D_001D8690, 4");
__asm__(".extern D_001D8694, 4");
__asm__(".extern D_001D8698, 4");
__asm__(".extern D_001D869C, 4");
__asm__(".extern D_001D86A0, 4");
__asm__(".extern D_001D86A4, 4");
__asm__(".extern D_001D86A8, 4");
__asm__(".extern D_001D86AC, 4");
__asm__(".extern D_001D86B0, 4");
__asm__(".extern D_001D86B4, 4");


extern void func_0011A264(void *, s32, s32);
extern void func_0011B2E8();
extern f32 func_0038DE98(f32, f32);
extern f32 func_0038D478(f32);
extern f32 func_0038D490(f32);
extern s32 func_003AB268(void *);
extern s32 *func_003AB270();
extern void func_003AB288(void *, f32, f32, f32, f32);
extern void func_003AB2D8(void *, s32);
extern void func_003AB348(void *, s32);
extern void func_003AB3B0(void *, f32, f32, f32, f32);
extern void func_003AB608();
extern void func_003AB7E0(u8 *, u8 *, s32);
extern void func_003ABB30();
extern void func_003ABD40(u8 *, s32, s32);
extern void func_003ABDB0();
extern void func_003ABE38(void *, s32);
extern void func_003ABE40(void *, s32);
extern void *func_003AC270();
extern s32 func_003F2740(s32, s32);

extern void func_003AD7E0(S_3A7E80 *);
extern void func_003AD8A0(void *, s32);
extern void func_003AD8D8(void *, s32);
extern u8 func_003AD8E0(void *, u8);
extern void func_003AD8F0(S_3A7F90 *, s32, f32, f32, f32, f32, f32);
extern void func_003AD928(V_7FC8 *, s32, f32, f32);
extern void func_003AD940(void *, s32);
extern void func_003AD948(u8 *, s32);
extern void func_003AD988(void *, s32);
extern void func_003AD990(void *, f32);

typedef void (*Init_003ADB90)(void *, s32);

void func_003ADB90(S_003ADB90 *p, u8 *base, s32 c) {
    char buf[16];
    s32 j;
    f32 *v;
    f32 x, y, a;
    s32 col;
    f32 fcf;

    p->fB40 = 0;
    p->fB44 = 0;
    func_003AB608(&p->w000, D_001D8530, c);
    func_003AB7E0((u8 *)&p->w000, base + 0x7090, 0);
    func_003AB288(&p->w000, 10.0f, 10.0f, 0.0f, 0.0f);
    p->w000.flag3A = 1;
    func_003AB608(&p->w03C, D_001D8540, c);
    func_003AB288(&p->w03C, 10.0f, 10.0f, 0.0f, 0.0f);
    func_003AB7E0((u8 *)&p->w03C, base + 0x7090, 0);
    p->w03C.flag3A = 1;
    func_003AB608(&p->w078, D_001D8550, c);
    func_003AB288(&p->w078, 10.0f, 18.5f, 0.0f, 0.0f);
    func_003AB7E0((u8 *)&p->w078, base + 0x7090, 0);
    p->w078.flag3A = 1;

    func_0011A264(p->bufB4, 0, 0x18);
    func_003ABDB0(&p->w0D0, D_001D8558, c);
    func_003AB3B0(&p->w0D0, 0.9f, 0.0f, 0.0f, 0.0f);
    func_003ABE40(&p->w0D0, (s32)p->bufB4);
    func_003AB288(&p->w0D0, 64.0f, 15.0f, 0.0f, 0.0f);
    func_003ABE38(&p->w0D0, 0);
    func_003ABB30(&p->w110, D_001D8568, c);
    func_003AB3B0(&p->w110, 32.0f, 32.0f, 0.0f, 0.0f);
    func_003AB288(&p->w110, 20.0f, 15.0f, 0.0f, 0.0f);
    *(s32 *)func_003AB270(&p->w110) = 0x60F0F0B0;

    func_003AB608(&p->w140, D_001D8578, c);
    func_003AB288(&p->w140, 498.0f, 10.0f, 0.0f, 0.0f);
    func_003AB7E0((u8 *)&p->w140, base + 0x7090, 0);
    func_003AB608(&p->w17C, D_001D8588, c);
    func_003AB288(&p->w17C, 498.0f, 10.0f, 0.0f, 0.0f);
    func_003AB7E0((u8 *)&p->w17C, base + 0x7090, 0);

    func_0011A264(p->buf1B8, 0, 0x18);
    func_003ABDB0(&p->w1D0, D_001D8598, c);
    func_003AB3B0(&p->w1D0, 0.9f, 0.0f, 0.0f, 0.0f);
    func_003ABE40(&p->w1D0, (s32)p->buf1B8);
    func_003AB288(&p->w1D0, 440.0f, 15.0f, 0.0f, 0.0f);
    func_003ABE38(&p->w1D0, 2);
    func_003ABB30(&p->w210, D_001D85A8, c);
    func_003AB3B0(&p->w210, 32.0f, 32.0f, 0.0f, 0.0f);
    func_003AB288(&p->w210, 457.0f, 15.0f, 0.0f, 0.0f);
    func_003ABD40((u8 *)&p->w210, 0x7567, 0);

    if (c != 0) {
        v = (f32 *)func_003F2740(0x10, (s32)func_003AC270(c));
        p->f7E4 = v;
        v[1] = 0.0f;
        v[2] = 0.0f;
        v[3] = 0.0f;
        v[0] = 0.0f;
    }

    col = 0x1465B7;
    func_003AB608(&p->w244, D_001D85B8, c);
    func_003AB7E0((u8 *)&p->w244, base + 0x7090, 0x29);
    func_003AB3B0(&p->w244, 1.0f, 1.0f, 0.0f, 0.0f);
    func_003AB288(&p->w244, 125.0f, 208.0f, 0.0f, 0.0f);
    *(s32 *)func_003AB270(&p->w244) = col;
    func_003AB348(&p->w244, (s32)p->f7E4);
    p->w244.flag3A = 1;

    col = 0x2299DE;
    func_003AB608(&p->w280, D_001D85C8, c);
    func_003AB7E0((u8 *)&p->w280, base + 0x7090, 0x25);
    func_003AB3B0(&p->w280, 1.0f, 1.0f, 0.0f, 0.0f);
    func_003AB288(&p->w280, 125.0f, 208.0f, 0.0f, 0.0f);
    *(s32 *)func_003AB270(&p->w280) = col;
    func_003AB348(&p->w280, (s32)p->f7E4);
    p->w280.flag3A = 1;

    col = 0xFFFEED;
    func_003AB608(&p->w628, D_001D85D8, c);
    func_003AB7E0((u8 *)&p->w628, base + 0x7090, 0x2A);
    func_003AB288(&p->w628, 125.0f, 208.0f, 0.0f, 0.0f);
    *(s32 *)func_003AB270(&p->w628) = col;
    func_003AB2B8(&p->w628, 0);
    p->w628.flag3A = 1;

    col = 0x8000FFFF;
    func_003AB608(&p->w49C, D_001D85E8, c);
    func_003AB7E0((u8 *)&p->w49C, base + 0x7090, 0x27);
    func_003AB288(&p->w49C, 125.0f, 208.0f, 0.0f, 0.0f);
    *(s32 *)func_003AB270(&p->w49C) = col;
    func_003AB348(&p->w49C, (s32)p->f7E4);
    p->w49C.flag3A = 1;

    col = 0x80FFFF00;
    func_003AB608(&p->w4D8, D_001D85F8, c);
    func_003AB7E0((u8 *)&p->w4D8, base + 0x7090, 0x28);
    func_003AB288(&p->w4D8, 125.0f, 208.0f, 0.0f, 0.0f);
    *(s32 *)func_003AB270(&p->w4D8) = col;
    func_003AB348(&p->w4D8, (s32)p->f7E4);
    p->w4D8.flag3A = 1;

    col = 0x800000FF;
    func_003AB608(&p->w514, D_001D8608, c);
    func_003AB7E0((u8 *)&p->w514, base + 0x7090, 0x26);
    func_003AB288(&p->w514, 125.0f, 208.0f, 0.0f, 0.0f);
    *(s32 *)func_003AB270(&p->w514) = col;
    func_003AB348(&p->w514, (s32)p->f7E4);
    p->w514.flag3A = 1;

    col = 0x800000FF;
    func_003AB608(&p->w550, D_001D8618, c);
    func_003AB7E0((u8 *)&p->w550, base + 0x7090, 0x8B);
    func_003AB288(&p->w550, 52.0f, 281.0f, 0.0f, 0.0f);
    *(s32 *)func_003AB270(&p->w550) = col;
    func_003AB348(&p->w550, (s32)p->f7E4);
    p->w550.flag3A = 1;
    v = (f32 *)func_003AB268(&p->w550);
    *v = -*v;

    col = 0x800000FF;
    func_003AB608(&p->w58C, D_001D8630, c);
    func_003AB7E0((u8 *)&p->w58C, base + 0x7090, 0x8A);
    func_003AB288(&p->w58C, 52.0f, 281.0f, 0.0f, 0.0f);
    *(s32 *)func_003AB270(&p->w58C) = col;
    func_003AB348(&p->w58C, (s32)p->f7E4);
    p->w58C.flag3A = 1;
    v = (f32 *)func_003AB268(&p->w58C);
    *v = -*v;

    func_003ABB30(&p->w5C8, D_001D8640, c);
    func_003AB3B0(&p->w5C8, 32.0f, 32.0f, 0.0f, 0.0f);
    func_003AB288(&p->w5C8, 24.0f, 278.0f, 0.0f, 0.0f);
    func_003ABD40((u8 *)&p->w5C8, 0xED51, 0);
    func_003AB2B8(&p->w5C8, 0);
    *(s32 *)func_003AB270(&p->w5C8) = 0xF0F0B0;

    func_003ABB30(&p->w5F8, D_001D8650, c);
    func_003AB3B0(&p->w5F8, 32.0f, 32.0f, 0.0f, 0.0f);
    func_003AB288(&p->w5F8, 23.0f, 277.0f, 0.0f, 0.0f);
    func_003ABD40((u8 *)&p->w5F8, 0xED56, 0);
    func_003AB2B8(&p->w5F8, 0);
    *(s32 *)func_003AB270(&p->w5F8) = 0xF0F0B0;

    {
    s32 i;
    for (i = 0; i < 8; i++) {
        col = 0x1465B7;
        func_0011B2E8(buf, D_001D8660, i);
        func_003AB608(&p->items[i], buf, c);
        func_003AB7E0((u8 *)&p->items[i], base + 0x7090, i + 3);
        func_003AB3B0(&p->items[i], 1.0f, 1.0f, 0.0f, 0.0f);
        func_003AB288(&p->items[i], 125.0f, 208.0f, 0.0f, 0.0f);
        func_003AB348(&p->items[i], (s32)p->f7E4);
        p->items[i].flag3A = 1;
        *(s32 *)func_003AB270(&p->items[i]) = col;

        col = 0xF0F0B0;
        func_0011B2E8(buf, D_001D8670, i);
        func_003ABB30(&p->rings[i], buf, c);
        func_003AB2B8(&p->rings[i], 0);
        a = func_0038DE98((f32)i * 2.0f * 3.1415927f * 0.125f - 3.1415927f, 1.5707964f);
        x = (f32)(D_001D8690 + D_001D867C + (s32)(D_001D8684 * func_0038D478(a) * D_001D8688));
        y = (f32)(D_001D8694 + D_001D8680 + (s32)(D_001D8684 * func_0038D490(a) * D_001D868C));
        func_003AB288(&p->rings[i], x, y, 0.0f, 0.0f);
        func_003AB3B0(&p->rings[i], 32.0f, 32.0f, 0.0f, 0.0f);
        *(s32 *)func_003AB270(&p->rings[i]) = col;
    }
    }

    {
        s32 *q = (s32 *)func_003AB270(&p->w5C8);
        *q = (*q & 0xFF000000) | 0x1465B7;
    }
    {
        s32 *q = (s32 *)func_003AB270(&p->w5F8);
        *q = (*q & 0xFF000000) | 0x1465B7;
    }

    for (j = 0; j < 8; j++) {
        a = func_0038DE98((f32)j * 2.0f * 3.1415927f * 0.125f - 3.1415927f, 1.5707964f);
        x = (f32)(D_001D86AC + D_001D8698 + (s32)(D_001D86A0 * func_0038D478(a) * D_001D86A4));
        y = (f32)(D_001D86B0 + D_001D869C + (s32)(D_001D86A0 * func_0038D490(a) * D_001D86A8));
        func_003AB288(&p->rings[j], x, y, 0.0f, 0.0f);
        func_003AB3B0(&p->rings[j], 32.0f, 32.0f, 0.0f, 0.0f);
        {
            s32 *q = (s32 *)func_003AB270(&p->rings[j]);
            *q = (*q & 0xFF000000) | (D_001D86B4 & 0xFFFFFF);
        }
    }

    for (j = 1; j < 8; j++) {
        func_003AB2D8(&p->items[j], func_003AB268(&p->items[0]));
        func_003AB2D8(&p->rings[j], func_003AB268(&p->rings[0]));
    }
    func_003AB2D8(&p->w244, func_003AB268(&p->items[0]));

    ((Init_003ADB90)func_003AD7E0)(&p->fx7E8, c);
    func_003AD940(&p->fx7E8, 3);
    *(u32 *)&fcf = 0x442D00;
    func_003AD8F0((S_3A7F90 *)&p->fx7E8, 0, 0.0f, fcf, 0.0f, 0.0f, 0.0f);
    *(u32 *)&fcf = 0x331465B7;
    func_003AD8F0((S_3A7F90 *)&p->fx7E8, 1, 0.3f, fcf, 0.0f, 0.0f, 0.0f);
    *(u32 *)&fcf = 0x331465B7;
    func_003AD8F0((S_3A7F90 *)&p->fx7E8, 2, 1.0f, fcf, 0.0f, 0.0f, 0.0f);
    func_003AD928((V_7FC8 *)&p->fx7E8, 1, 0.0f, 2.0f);
    func_003AD8A0(&p->fx7E8, (s32)func_003AB270(&p->items[0]));
    func_003AD988(&p->fx7E8, 0);
    func_003AD8D8(&p->fx7E8, (s32)&p->fB1C);
    func_003AD948((u8 *)&p->fx7E8, -1);
    func_003AD990(&p->fx7E8, D_00143950[0] ? 1.0f : 0.8333333f);
    func_003AD8E0(&p->fx7E8, 0);

    ((Init_003ADB90)func_003AD7E0)(&p->fx870, c);
    func_003AD940(&p->fx870, 3);
    func_003AD8F0((S_3A7F90 *)&p->fx870, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    func_003AD8F0((S_3A7F90 *)&p->fx870, 1, 0.3f, 1.0f, 1.0f, 0.0f, 0.0f);
    func_003AD8F0((S_3A7F90 *)&p->fx870, 2, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f);
    func_003AD8A0(&p->fx870, func_003AB268(&p->items[0]));
    func_003AD988(&p->fx870, 0);
    func_003AD8D8(&p->fx870, (s32)&p->fB18);
    func_003AD948((u8 *)&p->fx870, -1);
    func_003AD990(&p->fx870, D_00143950[0] ? 1.0f : 0.8333333f);
    func_003AD8E0(&p->fx870, 0);

    ((Init_003ADB90)func_003AD7E0)(&p->fxA08, c);
    func_003AD940(&p->fxA08, 3);
    *(u32 *)&fcf = 0xF0F0B0;
    func_003AD8F0((S_3A7F90 *)&p->fxA08, 0, 0.0f, fcf, 0.0f, 0.0f, 0.0f);
    *(u32 *)&fcf = 0xF0F0B0;
    func_003AD8F0((S_3A7F90 *)&p->fxA08, 1, 0.5f, fcf, 0.0f, 0.0f, 0.0f);
    func_003AD928((V_7FC8 *)&p->fxA08, 0, 0.0f, 0.0f);
    *(u32 *)&fcf = 0x80FFFFFF;
    func_003AD8F0((S_3A7F90 *)&p->fxA08, 2, 1.0f, fcf, 0.0f, 0.0f, 0.0f);
    func_003AD928((V_7FC8 *)&p->fxA08, 1, 0.0f, 0.0f);
    func_003AD8A0(&p->fxA08, (s32)func_003AB270(&p->rings[0]));
    func_003AD988(&p->fxA08, 0);
    func_003AD8D8(&p->fxA08, (s32)&p->fB1C);
    func_003AD948((u8 *)&p->fxA08, -1);
    func_003AD990(&p->fxA08, D_00143950[0] ? 1.0f : 0.8333333f);
    func_003AD8E0(&p->fxA08, 0);

    ((Init_003ADB90)func_003AD7E0)(&p->fx8F8, c);
    func_003AD940(&p->fx8F8, 3);
    *(u32 *)&fcf = 0xF0C070;
    func_003AD8F0((S_3A7F90 *)&p->fx8F8, 0, 0.0f, fcf, 0.0f, 0.0f, 0.0f);
    *(u32 *)&fcf = 0x332299DE;
    func_003AD8F0((S_3A7F90 *)&p->fx8F8, 1, 0.3f, fcf, 0.0f, 0.0f, 0.0f);
    *(u32 *)&fcf = 0x332299DE;
    func_003AD8F0((S_3A7F90 *)&p->fx8F8, 2, 1.0f, fcf, 0.0f, 0.0f, 0.0f);
    func_003AD928((V_7FC8 *)&p->fx8F8, 1, 0.0f, 3.0f);
    func_003AD8A0(&p->fx8F8, (s32)func_003AB270(&p->w280));
    func_003AD988(&p->fx8F8, 0);
    func_003AD8D8(&p->fx8F8, (s32)&p->fB1C);
    func_003AD948((u8 *)&p->fx8F8, -1);
    func_003AD990(&p->fx8F8, D_00143950[0] ? 1.0f : 0.8333333f);
    func_003AD8E0(&p->fx8F8, 0);

    ((Init_003ADB90)func_003AD7E0)(&p->fx980, c);
    func_003AD940(&p->fx980, 3);
    func_003AD8F0((S_3A7F90 *)&p->fx980, 0, 0.0f, 1.2f, 1.2f, 0.0f, 0.0f);
    func_003AD8F0((S_3A7F90 *)&p->fx980, 1, 0.3f, 1.0f, 1.0f, 0.0f, 0.0f);
    func_003AD8F0((S_3A7F90 *)&p->fx980, 2, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f);
    func_003AD8A0(&p->fx980, func_003AB268(&p->w280));
    func_003AD988(&p->fx980, 0);
    func_003AD8D8(&p->fx980, (s32)&p->fB18);
    func_003AD948((u8 *)&p->fx980, -1);
    func_003AD990(&p->fx980, D_00143950[0] ? 1.0f : 0.8333333f);
    func_003AD8E0(&p->fx980, 0);

    ((Init_003ADB90)func_003AD7E0)(&p->fxA90, c);
    func_003AD940(&p->fxA90, 3);
    func_003AD8F0((S_3A7F90 *)&p->fxA90, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    func_003AD8F0((S_3A7F90 *)&p->fxA90, 1, 0.01f, 1.0f, 1.0f, 0.0f, 0.0f);
    func_003AD8F0((S_3A7F90 *)&p->fxA90, 2, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f);
    func_003AD8A0(&p->fxA90, (s32)p->f7E4);
    func_003AD988(&p->fxA90, 0);
    func_003AD8D8(&p->fxA90, (s32)&p->fB18);
    func_003AD948((u8 *)&p->fxA90, -1);
    func_003AD990(&p->fxA90, D_00143950[0] ? 1.0f : 0.8333333f);
    func_003AD8E0(&p->fxA90, 0);

    p->fB28 = 0;
    p->fB2C = -1;
    p->fB30 = 0;
    p->fB34 = -1;
    p->fB38 = 0;
    p->fB3C = -1;
}
/* localdecomp:end func_003ADB90 */
