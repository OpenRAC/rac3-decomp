#include "common.h"
/* localdecomp:start func_L39_00601DE0 */
typedef struct { u8 p0[0x18]; f32 f18; s32 f1C; s32 f20; f32 f24; s8 b28; u8 p29[3]; s32 f2C; u8 p30[0x50]; s32 f80; s32 f84; } S_3A7E80_006044E0;
typedef struct { u8 pad[0x30]; f32 m[4][4]; f32 v[4]; } S_3A7F90_006044E0;
typedef struct { f32 a[3]; f32 b[3]; } V_7FC8_006044E0;
typedef struct { s32 pad0[0xE]; u8 pad38[2]; u8 flag3A; u8 pad3B; } T3C_003AD7D8;
typedef struct { s32 pad0[0xC]; } T30_003AD7D8;
typedef struct { s32 pad0[0x10]; } T40_003AD7D8;
typedef struct { s32 pad0[0x22]; } T88_003AD7D8;
typedef struct {
    T3C_003AD7D8 w000;
    T3C_003AD7D8 w03C;
    T3C_003AD7D8 w078;
    u8 bufB4[0x18];
    u8 padCC[4];
    T40_003AD7D8 w0D0;
    T30_003AD7D8 w110;
    T3C_003AD7D8 w140;
    T3C_003AD7D8 w17C;
    u8 buf1B8[0x18];
    T40_003AD7D8 w1D0;
    T30_003AD7D8 w210;
    u8 pad240[4];
    T3C_003AD7D8 w244;
    T3C_003AD7D8 w280;
    T3C_003AD7D8 items[8];
    T3C_003AD7D8 w49C;
    T3C_003AD7D8 w4D8;
    T3C_003AD7D8 w514;
    T3C_003AD7D8 w550;
    T3C_003AD7D8 w58C;
    T30_003AD7D8 w5C8;
    T30_003AD7D8 w5F8;
    T3C_003AD7D8 w628;
    T30_003AD7D8 rings[8];
    f32 *f7E4;
    T88_003AD7D8 fx7E8;
    T88_003AD7D8 fx870;
    T88_003AD7D8 fx8F8;
    T88_003AD7D8 fx980;
    T88_003AD7D8 fxA08;
    T88_003AD7D8 fxA90;
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
} S_003AD7D8;

extern u8 D_L39_00245668[];
extern u8 D_L39_00245678[];
extern u8 D_L39_00245688[];
extern u8 D_L39_00245690[];
extern u8 D_L39_002456A0[];
extern u8 D_L39_002456B0[];
extern u8 D_L39_002456C0[];
extern u8 D_L39_002456D0[];
extern u8 D_L39_002456E0[];
extern u8 D_L39_002456F0[];
extern u8 D_L39_00245700[];
extern u8 D_L39_00245710[];
extern u8 D_L39_00245720_00601DE0[];
extern u8 D_L39_00245730[];
extern u8 D_L39_00245740[];
extern u8 D_L39_00245750[];
extern u8 D_L39_00245768[];
extern u8 D_L39_00245778[];
extern u8 D_L39_00245788[];
extern u8 D_L39_00245798[];
extern u8 D_L39_002457A8[];
extern s32 D_L39_002457B4;
extern s32 D_L39_002457B8;
extern f32 D_L39_002457BC;
extern f32 D_L39_002457C0_00601DE0;
extern f32 D_L39_002457C4;
extern s32 D_L39_002457C8;
extern s32 D_L39_002457CC;
extern s32 D_L39_002457D0;
extern s32 D_L39_002457D4;
extern f32 D_L39_002457D8_00601DE0;
extern f32 D_L39_002457DC;
extern f32 D_L39_002457E0;
extern s32 D_L39_002457E4;
extern s32 D_L39_002457E8;
extern s32 D_L39_002457EC;
extern s32 D_001A5990[];
__asm__(".extern D_L39_002457B4, 4");
__asm__(".extern D_L39_002457B8, 4");
__asm__(".extern D_L39_002457BC, 4");
__asm__(".extern D_L39_002457C0_00601DE0, 4");
__asm__(".extern D_L39_002457C4, 4");
__asm__(".extern D_L39_002457C8, 4");
__asm__(".extern D_L39_002457CC, 4");
__asm__(".extern D_L39_002457D0, 4");
__asm__(".extern D_L39_002457D4, 4");
__asm__(".extern D_L39_002457D8_00601DE0, 4");
__asm__(".extern D_L39_002457DC, 4");
__asm__(".extern D_L39_002457E0, 4");
__asm__(".extern D_L39_002457E4, 4");
__asm__(".extern D_L39_002457E8, 4");
__asm__(".extern D_L39_002457EC, 4");


extern void func_0011D534(void *, s32, s32);
extern void func_00120048();
extern f32 func_00389380(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern s32 func_L39_005FE928(void *);
extern s32 *func_L39_005FE930();
extern void func_003A5928(void *, f32, f32, f32, f32);
extern void func_003A5978(void *, s32);
extern void func_003A59E8(void *, s32);
extern void func_003A5A50(void *, f32, f32, f32, f32);
extern void func_003A5CA8();
extern void func_003A5E80(u8 *, u8 *, s32);
extern void func_003A61D0();
extern void func_003A63E0(u8 *, s32, s32);
extern void func_003A6450();
extern void func_003A64D8(void *, s32);
extern void func_L01_004C9720(void *, s32);
extern void *func_L39_005FF9E0();
extern s32 func_L01_0051DC40(s32, s32);

extern void func_003A7E80(S_3A7E80_006044E0 *);
extern void func_L01_004CB6D0(void *, s32);
extern void func_003A7F78(void *, s32);
extern u8 func_003A7F80(void *, u8);
extern void func_003A7F90(S_3A7F90_006044E0 *, s32, f32, f32, f32, f32, f32);
extern void func_003A7FC8(V_7FC8_006044E0 *, s32, f32, f32);
extern void func_003A7FE0(void *, s32);
extern void func_003A7FE8(u8 *, s32);
extern void func_003A8028(void *, s32);
extern void func_003A8030(void *, f32);

typedef void (*Init_003AD7D8)(void *, s32);

void func_L39_00601DE0(S_003AD7D8 *p, u8 *base, s32 c) {
    char buf[16];
    s32 j;
    f32 *v;
    f32 x, y, a;
    s32 col;
    f32 fcf;

    p->fB40 = 0;
    p->fB44 = 0;
    func_003A5CA8(&p->w000, D_L39_00245668, c);
    func_003A5E80((u8 *)&p->w000, base + 0x7090, 0);
    func_003A5928(&p->w000, 10.0f, 10.0f, 0.0f, 0.0f);
    p->w000.flag3A = 1;
    func_003A5CA8(&p->w03C, D_L39_00245678, c);
    func_003A5928(&p->w03C, 10.0f, 10.0f, 0.0f, 0.0f);
    func_003A5E80((u8 *)&p->w03C, base + 0x7090, 0);
    p->w03C.flag3A = 1;
    func_003A5CA8(&p->w078, D_L39_00245688, c);
    func_003A5928(&p->w078, 10.0f, 18.5f, 0.0f, 0.0f);
    func_003A5E80((u8 *)&p->w078, base + 0x7090, 0);
    p->w078.flag3A = 1;

    func_0011D534(p->bufB4, 0, 0x18);
    func_003A6450(&p->w0D0, D_L39_00245690, c);
    func_003A5A50(&p->w0D0, 0.9f, 0.0f, 0.0f, 0.0f);
    func_L01_004C9720(&p->w0D0, (s32)p->bufB4);
    func_003A5928(&p->w0D0, 64.0f, 15.0f, 0.0f, 0.0f);
    func_003A64D8(&p->w0D0, 0);
    func_003A61D0(&p->w110, D_L39_002456A0, c);
    func_003A5A50(&p->w110, 32.0f, 32.0f, 0.0f, 0.0f);
    func_003A5928(&p->w110, 20.0f, 15.0f, 0.0f, 0.0f);
    *(s32 *)func_L39_005FE930(&p->w110) = 0x60F0F0B0;

    func_003A5CA8(&p->w140, D_L39_002456B0, c);
    func_003A5928(&p->w140, 498.0f, 10.0f, 0.0f, 0.0f);
    func_003A5E80((u8 *)&p->w140, base + 0x7090, 0);
    func_003A5CA8(&p->w17C, D_L39_002456C0, c);
    func_003A5928(&p->w17C, 498.0f, 10.0f, 0.0f, 0.0f);
    func_003A5E80((u8 *)&p->w17C, base + 0x7090, 0);

    func_0011D534(p->buf1B8, 0, 0x18);
    func_003A6450(&p->w1D0, D_L39_002456D0, c);
    func_003A5A50(&p->w1D0, 0.9f, 0.0f, 0.0f, 0.0f);
    func_L01_004C9720(&p->w1D0, (s32)p->buf1B8);
    func_003A5928(&p->w1D0, 440.0f, 15.0f, 0.0f, 0.0f);
    func_003A64D8(&p->w1D0, 2);
    func_003A61D0(&p->w210, D_L39_002456E0, c);
    func_003A5A50(&p->w210, 32.0f, 32.0f, 0.0f, 0.0f);
    func_003A5928(&p->w210, 457.0f, 15.0f, 0.0f, 0.0f);
    func_003A63E0((u8 *)&p->w210, 0x7567, 0);

    if (c != 0) {
        v = (f32 *)func_L01_0051DC40(0x10, (s32)func_L39_005FF9E0(c));
        p->f7E4 = v;
        v[1] = 0.0f;
        v[2] = 0.0f;
        v[3] = 0.0f;
        v[0] = 0.0f;
    }

    col = 0x1465B7;
    func_003A5CA8(&p->w244, D_L39_002456F0, c);
    func_003A5E80((u8 *)&p->w244, base + 0x7090, 0x29);
    func_003A5A50(&p->w244, 1.0f, 1.0f, 0.0f, 0.0f);
    func_003A5928(&p->w244, 125.0f, 208.0f, 0.0f, 0.0f);
    *(s32 *)func_L39_005FE930(&p->w244) = col;
    func_003A59E8(&p->w244, (s32)p->f7E4);
    p->w244.flag3A = 1;

    col = 0x2299DE;
    func_003A5CA8(&p->w280, D_L39_00245700, c);
    func_003A5E80((u8 *)&p->w280, base + 0x7090, 0x25);
    func_003A5A50(&p->w280, 1.0f, 1.0f, 0.0f, 0.0f);
    func_003A5928(&p->w280, 125.0f, 208.0f, 0.0f, 0.0f);
    *(s32 *)func_L39_005FE930(&p->w280) = col;
    func_003A59E8(&p->w280, (s32)p->f7E4);
    p->w280.flag3A = 1;

    col = 0xFFFEED;
    func_003A5CA8(&p->w628, D_L39_00245710, c);
    func_003A5E80((u8 *)&p->w628, base + 0x7090, 0x2A);
    func_003A5928(&p->w628, 125.0f, 208.0f, 0.0f, 0.0f);
    *(s32 *)func_L39_005FE930(&p->w628) = col;
    func_003A5958(&p->w628, 0);
    p->w628.flag3A = 1;

    col = 0x8000FFFF;
    func_003A5CA8(&p->w49C, D_L39_00245720_00601DE0, c);
    func_003A5E80((u8 *)&p->w49C, base + 0x7090, 0x27);
    func_003A5928(&p->w49C, 125.0f, 208.0f, 0.0f, 0.0f);
    *(s32 *)func_L39_005FE930(&p->w49C) = col;
    func_003A59E8(&p->w49C, (s32)p->f7E4);
    p->w49C.flag3A = 1;

    col = 0x80FFFF00;
    func_003A5CA8(&p->w4D8, D_L39_00245730, c);
    func_003A5E80((u8 *)&p->w4D8, base + 0x7090, 0x28);
    func_003A5928(&p->w4D8, 125.0f, 208.0f, 0.0f, 0.0f);
    *(s32 *)func_L39_005FE930(&p->w4D8) = col;
    func_003A59E8(&p->w4D8, (s32)p->f7E4);
    p->w4D8.flag3A = 1;

    col = 0x800000FF;
    func_003A5CA8(&p->w514, D_L39_00245740, c);
    func_003A5E80((u8 *)&p->w514, base + 0x7090, 0x26);
    func_003A5928(&p->w514, 125.0f, 208.0f, 0.0f, 0.0f);
    *(s32 *)func_L39_005FE930(&p->w514) = col;
    func_003A59E8(&p->w514, (s32)p->f7E4);
    p->w514.flag3A = 1;

    col = 0x800000FF;
    func_003A5CA8(&p->w550, D_L39_00245750, c);
    func_003A5E80((u8 *)&p->w550, base + 0x7090, 0x8B);
    func_003A5928(&p->w550, 52.0f, 281.0f, 0.0f, 0.0f);
    *(s32 *)func_L39_005FE930(&p->w550) = col;
    func_003A59E8(&p->w550, (s32)p->f7E4);
    p->w550.flag3A = 1;
    v = (f32 *)func_L39_005FE928(&p->w550);
    *v = -*v;

    col = 0x800000FF;
    func_003A5CA8(&p->w58C, D_L39_00245768, c);
    func_003A5E80((u8 *)&p->w58C, base + 0x7090, 0x8A);
    func_003A5928(&p->w58C, 52.0f, 281.0f, 0.0f, 0.0f);
    *(s32 *)func_L39_005FE930(&p->w58C) = col;
    func_003A59E8(&p->w58C, (s32)p->f7E4);
    p->w58C.flag3A = 1;
    v = (f32 *)func_L39_005FE928(&p->w58C);
    *v = -*v;

    func_003A61D0(&p->w5C8, D_L39_00245778, c);
    func_003A5A50(&p->w5C8, 32.0f, 32.0f, 0.0f, 0.0f);
    func_003A5928(&p->w5C8, 24.0f, 278.0f, 0.0f, 0.0f);
    func_003A63E0((u8 *)&p->w5C8, 0xED51, 0);
    func_003A5958(&p->w5C8, 0);
    *(s32 *)func_L39_005FE930(&p->w5C8) = 0xF0F0B0;

    func_003A61D0(&p->w5F8, D_L39_00245788, c);
    func_003A5A50(&p->w5F8, 32.0f, 32.0f, 0.0f, 0.0f);
    func_003A5928(&p->w5F8, 23.0f, 277.0f, 0.0f, 0.0f);
    func_003A63E0((u8 *)&p->w5F8, 0xED56, 0);
    func_003A5958(&p->w5F8, 0);
    *(s32 *)func_L39_005FE930(&p->w5F8) = 0xF0F0B0;

    {
    s32 i;
    for (i = 0; i < 8; i++) {
        col = 0x1465B7;
        func_00120048(buf, D_L39_00245798, i);
        func_003A5CA8(&p->items[i], buf, c);
        func_003A5E80((u8 *)&p->items[i], base + 0x7090, i + 3);
        func_003A5A50(&p->items[i], 1.0f, 1.0f, 0.0f, 0.0f);
        func_003A5928(&p->items[i], 125.0f, 208.0f, 0.0f, 0.0f);
        func_003A59E8(&p->items[i], (s32)p->f7E4);
        p->items[i].flag3A = 1;
        *(s32 *)func_L39_005FE930(&p->items[i]) = col;

        col = 0xF0F0B0;
        func_00120048(buf, D_L39_002457A8, i);
        func_003A61D0(&p->rings[i], buf, c);
        func_003A5958(&p->rings[i], 0);
        a = func_00389380((f32)i * 2.0f * 3.1415927f * 0.125f - 3.1415927f, 1.5707964f);
        x = (f32)(D_L39_002457C8 + D_L39_002457B4 + (s32)(D_L39_002457BC * func_00388960(a) * D_L39_002457C0_00601DE0));
        y = (f32)(D_L39_002457CC + D_L39_002457B8 + (s32)(D_L39_002457BC * func_00388978(a) * D_L39_002457C4));
        func_003A5928(&p->rings[i], x, y, 0.0f, 0.0f);
        func_003A5A50(&p->rings[i], 32.0f, 32.0f, 0.0f, 0.0f);
        *(s32 *)func_L39_005FE930(&p->rings[i]) = col;
    }
    }

    {
        s32 *q = (s32 *)func_L39_005FE930(&p->w5C8);
        *q = (*q & 0xFF000000) | 0x1465B7;
    }
    {
        s32 *q = (s32 *)func_L39_005FE930(&p->w5F8);
        *q = (*q & 0xFF000000) | 0x1465B7;
    }

    for (j = 0; j < 8; j++) {
        a = func_00389380((f32)j * 2.0f * 3.1415927f * 0.125f - 3.1415927f, 1.5707964f);
        x = (f32)(D_L39_002457E4 + D_L39_002457D0 + (s32)(D_L39_002457D8_00601DE0 * func_00388960(a) * D_L39_002457DC));
        y = (f32)(D_L39_002457E8 + D_L39_002457D4 + (s32)(D_L39_002457D8_00601DE0 * func_00388978(a) * D_L39_002457E0));
        func_003A5928(&p->rings[j], x, y, 0.0f, 0.0f);
        func_003A5A50(&p->rings[j], 32.0f, 32.0f, 0.0f, 0.0f);
        {
            s32 *q = (s32 *)func_L39_005FE930(&p->rings[j]);
            *q = (*q & 0xFF000000) | (D_L39_002457EC & 0xFFFFFF);
        }
    }

    for (j = 1; j < 8; j++) {
        func_003A5978(&p->items[j], func_L39_005FE928(&p->items[0]));
        func_003A5978(&p->rings[j], func_L39_005FE928(&p->rings[0]));
    }
    func_003A5978(&p->w244, func_L39_005FE928(&p->items[0]));

    ((Init_003AD7D8)func_003A7E80)(&p->fx7E8, c);
    func_003A7FE0(&p->fx7E8, 3);
    *(u32 *)&fcf = 0x442D00;
    func_003A7F90((S_3A7F90_006044E0 *)&p->fx7E8, 0, 0.0f, fcf, 0.0f, 0.0f, 0.0f);
    *(u32 *)&fcf = 0x331465B7;
    func_003A7F90((S_3A7F90_006044E0 *)&p->fx7E8, 1, 0.3f, fcf, 0.0f, 0.0f, 0.0f);
    *(u32 *)&fcf = 0x331465B7;
    func_003A7F90((S_3A7F90_006044E0 *)&p->fx7E8, 2, 1.0f, fcf, 0.0f, 0.0f, 0.0f);
    func_003A7FC8((V_7FC8_006044E0 *)&p->fx7E8, 1, 0.0f, 2.0f);
    func_L01_004CB6D0(&p->fx7E8, (s32)func_L39_005FE930(&p->items[0]));
    func_003A8028(&p->fx7E8, 0);
    func_003A7F78(&p->fx7E8, (s32)&p->fB1C);
    func_003A7FE8((u8 *)&p->fx7E8, -1);
    func_003A8030(&p->fx7E8, D_001A5990[0] ? 1.0f : 0.8333333f);
    func_003A7F80(&p->fx7E8, 0);

    ((Init_003AD7D8)func_003A7E80)(&p->fx870, c);
    func_003A7FE0(&p->fx870, 3);
    func_003A7F90((S_3A7F90_006044E0 *)&p->fx870, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    func_003A7F90((S_3A7F90_006044E0 *)&p->fx870, 1, 0.3f, 1.0f, 1.0f, 0.0f, 0.0f);
    func_003A7F90((S_3A7F90_006044E0 *)&p->fx870, 2, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f);
    func_L01_004CB6D0(&p->fx870, func_L39_005FE928(&p->items[0]));
    func_003A8028(&p->fx870, 0);
    func_003A7F78(&p->fx870, (s32)&p->fB18);
    func_003A7FE8((u8 *)&p->fx870, -1);
    func_003A8030(&p->fx870, D_001A5990[0] ? 1.0f : 0.8333333f);
    func_003A7F80(&p->fx870, 0);

    ((Init_003AD7D8)func_003A7E80)(&p->fxA08, c);
    func_003A7FE0(&p->fxA08, 3);
    *(u32 *)&fcf = 0xF0F0B0;
    func_003A7F90((S_3A7F90_006044E0 *)&p->fxA08, 0, 0.0f, fcf, 0.0f, 0.0f, 0.0f);
    *(u32 *)&fcf = 0xF0F0B0;
    func_003A7F90((S_3A7F90_006044E0 *)&p->fxA08, 1, 0.5f, fcf, 0.0f, 0.0f, 0.0f);
    func_003A7FC8((V_7FC8_006044E0 *)&p->fxA08, 0, 0.0f, 0.0f);
    *(u32 *)&fcf = 0x80FFFFFF;
    func_003A7F90((S_3A7F90_006044E0 *)&p->fxA08, 2, 1.0f, fcf, 0.0f, 0.0f, 0.0f);
    func_003A7FC8((V_7FC8_006044E0 *)&p->fxA08, 1, 0.0f, 0.0f);
    func_L01_004CB6D0(&p->fxA08, (s32)func_L39_005FE930(&p->rings[0]));
    func_003A8028(&p->fxA08, 0);
    func_003A7F78(&p->fxA08, (s32)&p->fB1C);
    func_003A7FE8((u8 *)&p->fxA08, -1);
    func_003A8030(&p->fxA08, D_001A5990[0] ? 1.0f : 0.8333333f);
    func_003A7F80(&p->fxA08, 0);

    ((Init_003AD7D8)func_003A7E80)(&p->fx8F8, c);
    func_003A7FE0(&p->fx8F8, 3);
    *(u32 *)&fcf = 0xF0C070;
    func_003A7F90((S_3A7F90_006044E0 *)&p->fx8F8, 0, 0.0f, fcf, 0.0f, 0.0f, 0.0f);
    *(u32 *)&fcf = 0x332299DE;
    func_003A7F90((S_3A7F90_006044E0 *)&p->fx8F8, 1, 0.3f, fcf, 0.0f, 0.0f, 0.0f);
    *(u32 *)&fcf = 0x332299DE;
    func_003A7F90((S_3A7F90_006044E0 *)&p->fx8F8, 2, 1.0f, fcf, 0.0f, 0.0f, 0.0f);
    func_003A7FC8((V_7FC8_006044E0 *)&p->fx8F8, 1, 0.0f, 3.0f);
    func_L01_004CB6D0(&p->fx8F8, (s32)func_L39_005FE930(&p->w280));
    func_003A8028(&p->fx8F8, 0);
    func_003A7F78(&p->fx8F8, (s32)&p->fB1C);
    func_003A7FE8((u8 *)&p->fx8F8, -1);
    func_003A8030(&p->fx8F8, D_001A5990[0] ? 1.0f : 0.8333333f);
    func_003A7F80(&p->fx8F8, 0);

    ((Init_003AD7D8)func_003A7E80)(&p->fx980, c);
    func_003A7FE0(&p->fx980, 3);
    func_003A7F90((S_3A7F90_006044E0 *)&p->fx980, 0, 0.0f, 1.2f, 1.2f, 0.0f, 0.0f);
    func_003A7F90((S_3A7F90_006044E0 *)&p->fx980, 1, 0.3f, 1.0f, 1.0f, 0.0f, 0.0f);
    func_003A7F90((S_3A7F90_006044E0 *)&p->fx980, 2, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f);
    func_L01_004CB6D0(&p->fx980, func_L39_005FE928(&p->w280));
    func_003A8028(&p->fx980, 0);
    func_003A7F78(&p->fx980, (s32)&p->fB18);
    func_003A7FE8((u8 *)&p->fx980, -1);
    func_003A8030(&p->fx980, D_001A5990[0] ? 1.0f : 0.8333333f);
    func_003A7F80(&p->fx980, 0);

    ((Init_003AD7D8)func_003A7E80)(&p->fxA90, c);
    func_003A7FE0(&p->fxA90, 3);
    func_003A7F90((S_3A7F90_006044E0 *)&p->fxA90, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    func_003A7F90((S_3A7F90_006044E0 *)&p->fxA90, 1, 0.01f, 1.0f, 1.0f, 0.0f, 0.0f);
    func_003A7F90((S_3A7F90_006044E0 *)&p->fxA90, 2, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f);
    func_L01_004CB6D0(&p->fxA90, (s32)p->f7E4);
    func_003A8028(&p->fxA90, 0);
    func_003A7F78(&p->fxA90, (s32)&p->fB18);
    func_003A7FE8((u8 *)&p->fxA90, -1);
    func_003A8030(&p->fxA90, D_001A5990[0] ? 1.0f : 0.8333333f);
    func_003A7F80(&p->fxA90, 0);

    p->fB28 = 0;
    p->fB2C = -1;
    p->fB30 = 0;
    p->fB34 = -1;
    p->fB38 = 0;
    p->fB3C = -1;
}
/* localdecomp:end func_L39_00601DE0 */
