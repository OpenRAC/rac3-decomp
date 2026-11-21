#include "common.h"

typedef struct {
    s32 v[10];
} S_003FF4E8;

typedef struct WeightTap_00400390 {
    u8 row;
    u8 col;
    s16 weight;
} WeightTap_00400390;

typedef struct {
    char pad00[0x22];
    s16 f22;
    char pad24[0x8];
    s32 f2C;
    char pad30[0x340];
    s32 f370;
    s32 f374;
} S_004001E8;

INCLUDE_ASM("asm/levels", func_L01_003FE908);

/* localdecomp:start func_L01_003FE938 */
extern s32 D_L01_001E64C0[];
extern s32 D_L01_001EA940[];
extern s32 D_L01_001DF948;
extern s32 D_L01_001E1070;
extern s32 D_L01_001D66A4;
extern s32 D_L01_001D4BB4;
extern f32 D_L01_001DF950;
extern void func_003A92F0(s32);
extern s32 func_0012C908(s32);
extern void func_003A9108(void);
extern void func_003A5430(void);

/* from rac2-decomp's func_00278EB0 */
void func_L01_003FE938(void) {
    s32 *state;
    s32 x, y, z;
    func_003A92F0(1);
    func_0012C908(0);
    D_L01_001DF948++;
    y = D_L01_001EA940[4];
    x = D_L01_001EA940[3];
    z = D_L01_001E1070;
    state = D_L01_001E64C0;
    state[5] = z - 0x60000;
    D_L01_001E1070 = 0x60000;
    state[0] = x + 0x60000;
    state[1] = y + 0x60000;
    state[2] = state[0] + 0xD0800;
    D_L01_001D66A4 = 0x2000;
    func_003A9108();
    func_003A5430();
    state[6] = D_L01_001D4BB4;
    D_L01_001DF950 = 1.0f;
}
/* localdecomp:end func_L01_003FE938 */

/* localdecomp:start func_L01_003FEA00 */
extern s32 D_L01_001E64C0[];
extern s32 D_L01_001D4BB4;
extern s32 D_001D4CEC_sda;
__asm__(".extern D_L01_001D4BB4, 4");
__asm__(".extern D_001D4CEC_sda, 4");
void func_L01_003FEA00(void) {
    extern void func_003A92F0(s32);
    extern void func_003A9050(void);
    extern void func_003A9108(void);
    extern void func_0038A238(s32);
    extern s32 func_003A0EA8(s32);
    u8 *g;
    func_003A92F0(1);
    func_003A9050();
    func_003A9108();
    g=(u8 *)D_L01_001E64C0;
    D_L01_001D4BB4=*(s32 *)(g+0x18);
    func_0038A238(30);
    if(func_003A0EA8(4) && (D_001D4CEC_sda&1)) *(s16 *)(g+0x28)=0;
}
/* localdecomp:end func_L01_003FEA00 */

/* localdecomp:start func_L01_003FEA68 */
typedef struct {
    s32 buffers[7];     /* 0x00 */
    s16 buffer;         /* 0x1C */
    s16 frame;          /* 0x1E */
    s16 tries;          /* 0x20 */
    s16 row;            /* 0x22 */
    s16 subrow;         /* 0x24 */
    s16 ready;          /* 0x26 */
    s16 state;          /* 0x28 */
    s32 timer;          /* 0x2C */
    u8 pad30[0x370 - 0x30];
    s32 step;           /* 0x370 */
    s32 base;           /* 0x374 */
    f32 duration;       /* 0x378 */
    f32 rate;           /* 0x37C */
    s32 repeats;        /* 0x380 */
    f32 speed;          /* 0x384 */
    s32 limit;          /* 0x388 */
} S_003FEA68;

typedef struct { s32 offset, size; } TocFile_003FEA68;
typedef struct {
    u8 pad0[0x694];
    s32 base;                       /* 0x694 */
    u8 pad698[0xC50 - 0x698];
    TocFile_003FEA68 intro[6];      /* 0xC50 */
    TocFile_003FEA68 frames[13];    /* 0xC80 */
} Toc_003FEA68;

extern Toc_003FEA68 D_00160C40;
extern u8 D_00143A07[];
extern s16 D_001CCFD4[];
extern u32 D_00142BBC __attribute__((section(".data")));
extern s32 D_001D4CEC;
extern u8 *D_001D52FC;
extern s32 D_001D4BC0;
extern u8 D_L01_001D60C4;
__asm__(".extern D_L01_001D60C4, 1");
extern S_003FF4E8 D_L01_001E6850[];
extern u8 D_L01_001EA7C0[];

extern s32 func_003A0EC0(s32, s32, s32, s32, s32);
extern void func_L01_003FF4E8(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, u32);
extern s32 func_L01_0045A6F0(void);
extern s32 func_003A2598(s32, s32, s32);
extern void func_L01_00400100(void);
void func_0038CAD0(void *);
extern f32 func_003C4138(f32 *, f32, f32);
extern void func_L01_004001C8(void);
extern void func_L01_004001E8(void);
extern s32 func_003A0F98(s32, s32);
extern s32 func_00392B20(void *, s32);
extern s32 func_00392C78(void *);
extern s32 func_L01_004BA800(void);
extern void func_003A4288(void);

/* from rac2-decomp's func_00278FC0 */
void func_L01_003FEA68(void)
{
    s32 lang;
    s32 n;

    D_L01_001D60C4 = 0;
    if (D_001D4CEC & 1) {
        D_L01_001D60C4 = 1;
        func_003A0EC0(4, 1, 1, 0, 0);
        return;
    }

    if (((S_003FEA68 *)D_L01_001E64C0)->state >= 1 && ((S_003FEA68 *)D_L01_001E64C0)->state <= 4 && (*(unsigned long *)(D_001D52FC + 0x1A0) & 0xF000000000UL)) {
        ((S_003FEA68 *)D_L01_001E64C0)->state = 5;
    }
    switch (((S_003FEA68 *)D_L01_001E64C0)->state) {
    case 0:
        if (D_001CCFD4[0])
            break;
        n = 0;
        func_L01_003FF4E8(0x1FDC, 0x1FDD, 0x2056, 1, 40, 80, 1, 10, 32, 0, n++);
        func_L01_003FF4E8(0x20B9, 0x20BA, 0x20BB, 2, 40, 80, 0, 2, 130, 2, n++);
        func_L01_003FF4E8(0x2090, 0x2091, 0x2096, 3, 40, 80, 0, 6, 56, 6, n++);
        func_L01_003FF4E8(0x2097, 0x2098, 0x2099, 4, 40, 80, 0, 2, 80, 2, n++);
        func_L01_003FF4E8(0x209A, 0x209B, 0x20A4, 5, 40, 80, 0, 10, 32, 10, n++);
        func_L01_003FF4E8(0x2090, 0x20A5, 0x20B4, 6, 40, 80, 0, 2, 160, 6, n++);
        func_L01_003FF4E8(0x20B5, 0x20B6, 0x20B8, 7, 40, 80, 0, 2, 160, 6, n++);
        func_L01_003FF4E8(0x20C2, 0x20C3, 0x20D0, 8, 40, 80, 0, 2, 150, 5, n++);
        func_L01_003FF4E8(0x20BC, 0x20BD, 0x20C1, 9, 40, 80, 0, 5, 56, 5, n++);
        func_L01_003FF4E8(0, 0x208B, 0x208B, 10, 0, 160, 0, 1, 100, 1, n++);
        func_L01_003FF4E8(0, 0x20E8, 0x20E8, 11, 0, 160, 0, 1, 100, 1, n++);
        func_L01_003FF4E8(0, 0x208A, 0x208A, 12, 0, 160, 0, 1, 100, 1, n++);
        func_L01_003FF4E8(0, 0x20D2, 0x20D2, 13, 0, 160, 0, 1, 100, 1, n++);
        func_L01_003FF4E8(0, 0x20D4, 0x20D4, 14, 0, 80, 0, 1, 200, 6, n++);
        func_L01_003FF4E8(0x20D5, 0x20D6, 0x20E5, 15, 40, 80, 0, 5, 56, 5, n++);
        func_L01_003FF4E8(0x20D5, 0x20E6, 0x20E7, 16, 40, 80, 0, 2, 150, 9, n++);
        func_L01_003FF4E8(0, 0x20E9, 0x20E9, 17, 0, 80, 0, 1, 200, 6, n++);
        D_L01_001E6850[32].v[0] = n;
        ((S_003FEA68 *)D_L01_001E64C0)->frame = 0;
        ((S_003FEA68 *)D_L01_001E64C0)->buffer = 0;
        ((S_003FEA68 *)D_L01_001E64C0)->ready = 0;
        if (func_L01_0045A6F0() == 3)
            ((S_003FEA68 *)D_L01_001E64C0)->timer = 0;
        else
            ((S_003FEA68 *)D_L01_001E64C0)->timer = 100;
        ((S_003FEA68 *)D_L01_001E64C0)->row = -1;
        ((S_003FEA68 *)D_L01_001E64C0)->subrow = -1;
        ((S_003FEA68 *)D_L01_001E64C0)->step = 8;
        ((S_003FEA68 *)D_L01_001E64C0)->base = 383;
        ((S_003FEA68 *)D_L01_001E64C0)->duration = (f32)D_001D4BC0 * 2.2f * 1.2f;
        ((S_003FEA68 *)D_L01_001E64C0)->rate = 0.1305483f;
        ((S_003FEA68 *)D_L01_001E64C0)->repeats = 5;
        ((S_003FEA68 *)D_L01_001E64C0)->speed = 0.03f;
        ((S_003FEA68 *)D_L01_001E64C0)->limit = 18;
        lang = D_00143A07[0];
        func_003A2598(((S_003FEA68 *)D_L01_001E64C0)->buffers[2], D_00160C40.intro[lang].offset + D_00160C40.base,
                      D_00160C40.intro[lang].size);
        ((S_003FEA68 *)D_L01_001E64C0)->state = 1;
        break;
    case 1:
        if (D_001CCFD4[0])
            break;
        func_L01_00400100();
        ((S_003FEA68 *)D_L01_001E64C0)->state = 2;
        break;
    case 2:
        func_003A2598(((S_003FEA68 *)D_L01_001E64C0)->buffers[((S_003FEA68 *)D_L01_001E64C0)->buffer], D_00160C40.frames[((S_003FEA68 *)D_L01_001E64C0)->frame].offset + D_00160C40.base,
                      D_00160C40.frames[((S_003FEA68 *)D_L01_001E64C0)->frame].size);
        ((S_003FEA68 *)D_L01_001E64C0)->state = 3;
        break;
    case 3:
        if (D_001CCFD4[0])
            break;
        if (((s32 (*)(void *))func_0038CAD0)(&((S_003FEA68 *)D_L01_001E64C0)->timer)) {
            ((S_003FEA68 *)D_L01_001E64C0)->ready = 1;
            ((S_003FEA68 *)D_L01_001E64C0)->buffer ^= 1;
            ((S_003FEA68 *)D_L01_001E64C0)->frame++;
            if (((S_003FEA68 *)D_L01_001E64C0)->frame >= 13)
                ((S_003FEA68 *)D_L01_001E64C0)->frame -= 13;
            func_003A2598(((S_003FEA68 *)D_L01_001E64C0)->buffers[((S_003FEA68 *)D_L01_001E64C0)->buffer], D_00160C40.frames[((S_003FEA68 *)D_L01_001E64C0)->frame].offset + D_00160C40.base,
                          D_00160C40.frames[((S_003FEA68 *)D_L01_001E64C0)->frame].size);
            ((S_003FEA68 *)D_L01_001E64C0)->state = 4;
        }
        break;
    case 4:
        func_003C4138(&D_L01_001DF950, 0.0f, 0.080000006f);
        if (((s32 (*)(void))func_L01_004001C8)()) {
            func_L01_004001E8();
            if (((S_003FEA68 *)D_L01_001E64C0)->state != 5) {
                if (++((S_003FEA68 *)D_L01_001E64C0)->tries >= 5) {
                    ((S_003FEA68 *)D_L01_001E64C0)->tries = 0;
                    ((S_003FEA68 *)D_L01_001E64C0)->state = 3;
                }
            }
        }
        break;
    case 5:
        if (func_L01_0045A6F0() == 3) {
            func_003A0F98(0, 0);
            ((S_003FEA68 *)D_L01_001E64C0)->state = 0;
        } else if (func_00392B20(D_L01_001EA7C0, 0x1C)) {
            func_00392C78(D_L01_001EA7C0);
            ((S_003FEA68 *)D_L01_001E64C0)->state = 6;
        }
        break;
    case 6:
        if (D_00142BBC & 0x10000000) {
            if (!func_L01_004BA800()) {
                func_003A0EC0(3, 1, 7, 0, 0);
                ((S_003FEA68 *)D_L01_001E64C0)->state = 0;
            }
        }
        break;
    }
    func_003A4288();
}
/* localdecomp:end func_L01_003FEA68 */

/* localdecomp:start func_L01_003FF240 */
typedef struct {
    s32 buffers[7];     /* 0x00 */
    u16 buffer;         /* 0x1C: the buffer drawn last */
    u8 pad1E[0x22 - 0x1E];
    s16 layout;         /* 0x22: index into D_L01_001E6850 */
    u8 pad24[0x26 - 0x24];
    s16 active;         /* 0x26 */
    u8 pad28[0x2C - 0x28];
    s32 timer;          /* 0x2C */
    u8 pad30[0x370 - 0x30];
    s32 delay;          /* 0x370 */
    s32 fade;           /* 0x374 */
} TextScreen_003FF240;
extern S_003FF4E8 D_L01_001E6850[];
extern s32 D_001A1ED4[];
extern s32 D_L01_001D60C0;
__asm__(".extern D_L01_001D60C0, 4");
extern void func_00389240(s32);
extern long func_003A9830(s32, s32, s32, s32);
extern void func_L01_003FFED0(void);
extern void func_L01_003FFC88(s32, f32);
extern void func_L01_003FF570(s32, f32);
extern void func_00389370(void);
extern void func_0038AE20(s32, s32, s32, s32);

void func_L01_003FF240(void)
{
    TextScreen_003FF240 *g = (TextScreen_003FF240 *)D_L01_001E64C0;
    s32 i, fade;
    f32 t;

    if (g->active) {
        func_00389240(0);
        func_003A9830(g->buffers[(s16)(g->buffer ^ 1)] + 16, D_001A1ED4[0], 512, 416);
        func_L01_003FFED0();
        switch (D_L01_001E6850[g->layout].v[6]) {
        case 0:
            for (i = 0; i < D_L01_001E6850[g->layout].v[7]; i++) {
                fade = (D_L01_001D60C0 * 5 + 2) / 6;
                if (g->timer < fade)
                    t = (f32)g->timer / (f32)fade;
                else if (D_L01_001E6850[g->layout].v[9] - fade < g->timer)
                    t = (f32)(D_L01_001E6850[g->layout].v[9] - g->timer) / (f32)fade;
                else
                    t = 1.0f;
                func_L01_003FFC88(i, t);
            }
            break;
        case 1:
        case 2: {
            TextScreen_003FF240 *s;
            s32 j, n;
            for (j = 0; j < D_L01_001E6850[((TextScreen_003FF240 *)D_L01_001E64C0)->layout].v[7]; j = n) {
                n = j + 1;
                s = (TextScreen_003FF240 *)D_L01_001E64C0;
                func_L01_003FF570(j, 1.0f - ((f32)s->timer - (f32)(D_L01_001E6850[s->layout].v[7] - n) * (f32)s->delay) / (f32)s->fade);
            }
            break;
        }
        }
        func_00389370();
    }
    func_0038AE20(0, 0, 0, (s32)(D_L01_001DF950 * 128.0f));
}
/* localdecomp:end func_L01_003FF240 */

/* localdecomp:start func_L01_003FF4E8 */
extern S_003FF4E8 D_L01_001E6850[];

void func_L01_003FF4E8(s32 p0, s32 p1, s32 p2, s32 p3, s32 p4, s32 p5,
                       s32 p6, s32 p7, s32 p8, s32 p9, u32 idx)
{
    if (idx >= 32u)
        return;
    D_L01_001E6850[idx].v[0] = p0;
    D_L01_001E6850[idx].v[1] = p1;
    D_L01_001E6850[idx].v[2] = p2;
    D_L01_001E6850[idx].v[3] = p3;
    D_L01_001E6850[idx].v[4] = p4;
    D_L01_001E6850[idx].v[5] = p5;
    D_L01_001E6850[idx].v[6] = p6;
    D_L01_001E6850[idx].v[7] = p7;
    D_L01_001E6850[idx].v[8] = p8;
    D_L01_001E6850[idx].v[9] = p9 * 37 + 200;
}
/* localdecomp:end func_L01_003FF4E8 */

INCLUDE_ASM("asm/levels", func_L01_003FF570);

INCLUDE_ASM("asm/levels", func_L01_003FF9F0);

/* localdecomp:start func_L01_003FFC88 */
typedef struct {
    char pad00[0x22];
    s16 f22;
    char pad24[0x364];
    s32 f388;
} S_003FFC88;
extern s32 D_L01_001E64C0[];
extern s32 D_L01_001D4BC0;
extern s32 D_L01_001D60B8;
__asm__(".extern D_L01_001D60B8, 4");
extern s32 func_L01_00400160(s32 a0, s32 *a1, s32 *a2);
extern s32 func_L01_004000C0(s32);
extern void func_003A9440(s32, unsigned long);
extern void func_0038AF30_003FFC88(s32, s32, s32, s32, unsigned long);
extern void func_003910C0(void *,s32,s32,s32,s32,s32,s32,s32,s32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_0038FA18(void *,s32,s32,s32,long,f32,f32);

void func_L01_003FFC88(s32 row, f32 t) {
    s32 rect[8];
    s32 entry, offset;
    s32 text;
    s32 y;
    S_003FFC88 *g;
    if (func_L01_00400160(row, &entry, &offset)) {
        text = func_L01_004000C0(D_L01_001E6850[entry].v[1] + offset);
        if (text) {
            func_003A9440(0x47, 0x33001);
            g = (S_003FFC88 *)D_L01_001E64C0;
            y = D_L01_001E6850[g->f22].v[5] + row * D_L01_001E6850[g->f22].v[8];
            func_0038AF30_003FFC88(y + 2, y + D_L01_001E6850[g->f22].v[8] - 2,
                                   0, D_L01_001D4BC0, (s32)(t * 96.0f) << 24);
            func_003910C0(rect, y, y + D_L01_001E6850[g->f22].v[8], 0, D_L01_001D4BC0, D_L01_001D4BC0 / 2 + 2,
                          y + D_L01_001E6850[g->f22].v[8] / 2 + 1, g->f388, 3);
            func_0038FA18(rect, func_0038DBD8(0, 0x80000000, t), text, -1, 0x80000000L, 1.0f, 1.0f);
            func_003910C0(rect, y, y + D_L01_001E6850[g->f22].v[8], 0, D_L01_001D4BC0, D_L01_001D4BC0 / 2,
                          y + D_L01_001E6850[g->f22].v[8] / 2, g->f388, 3);
            func_0038FA18(rect, func_0038DBD8(D_L01_001D60B8 & 0xFFFFFF, D_L01_001D60B8, t), text, -1, 0x80000000L, 1.0f, 1.0f);
        }
    }
}
/* localdecomp:end func_L01_003FFC88 */

/* localdecomp:start func_L01_003FFED0 */
extern s32 D_L01_001E64C0[];
extern s32 D_L01_001D4BC0;
extern s32 D_L01_001D60B8;
__asm__(".extern D_L01_001D60B8, 4");
void func_L01_003FFED0(void) {
    extern s32 func_L01_004000C0(s32);
    extern void func_003910C0(void *,s32,s32,s32,s32,s32,s32,s32,s32);
    extern void func_0038FA18(void *,s32,s32,s32,long,f32,f32);
    extern void func_0038AF30(s32,s32,s32,s32,u32);
    s32 rect[8];
    s32 text;
    s32 end,start,i,divisor;
    text=func_L01_004000C0(D_L01_001E6850[((S_004001E8 *)D_L01_001E64C0)->f22].v[0]);
    if(text) {
        { S_004001E8 *g=(S_004001E8 *)D_L01_001E64C0;
        func_003910C0(rect,0,D_L01_001E6850[((S_004001E8 *)D_L01_001E64C0)->f22].v[5],0,D_L01_001D4BC0,D_L01_001D4BC0/2,D_L01_001E6850[((S_004001E8 *)D_L01_001E64C0)->f22].v[4],18,1);
        func_0038FA18(rect,D_L01_001D60B8,text,-1,0x80000000L,1.0f,1.0f);
        }
        end=D_L01_001E6850[((S_004001E8 *)D_L01_001E64C0)->f22].v[5]-2;
        start=D_L01_001E6850[((S_004001E8 *)D_L01_001E64C0)->f22].v[5]-4;
        divisor=6;
        for(i=5;i>=0;i--) {
            func_0038AF30(end-start,end,-D_L01_001D4BC0,D_L01_001D4BC0*2,0x18000000);
            start=start*5/divisor;
        }
        { S_004001E8 *g=(S_004001E8 *)D_L01_001E64C0;
        func_003910C0(rect,0,D_L01_001E6850[g->f22].v[5],0,D_L01_001D4BC0,D_L01_001D4BC0/2,D_L01_001E6850[g->f22].v[4],18,1);
        func_0038FA18(rect,D_L01_001D60B8,text,-1,0x80000000L,1.0f,1.0f);
        }
    }
}
/* localdecomp:end func_L01_003FFED0 */

/* localdecomp:start func_L01_004000C0 */
typedef struct {
    s32 value;          
    s32 key;            
    char pad08[8];
} Rec_2e36f8;
extern s32 D_L01_001E64C0[];

/* from rac2-decomp's func_L00_002E36F8, renamed */
s32 func_L01_004000C0(s32 key)
{
    Rec_2e36f8 *entry;
    s32 count = D_L01_001E64C0[4];
    s32 i;
    if (count > 0) {
        i = 0;
        entry = (Rec_2e36f8 *)D_L01_001E64C0[3];
        do {
            if (entry->key == key)
                return entry->value;
            entry++;
            i++;
        } while (i < count);
    }
    return 0;
}
/* localdecomp:end func_L01_004000C0 */

/* localdecomp:start func_L01_00400100 */
void func_L01_00400100(void) {
    s32 i;

    D_L01_001E64C0[3] = D_L01_001E64C0[2];
    D_L01_001E64C0[4] = *(u32 *)D_L01_001E64C0[3] >> 4;
    for (i = 0; i < D_L01_001E64C0[4]; i++) {
        ((Rec_2e36f8 *)D_L01_001E64C0[3])[i].value += D_L01_001E64C0[3];
    }
}
/* localdecomp:end func_L01_00400100 */

/* localdecomp:start func_L01_00400160 */
s32 func_L01_00400160(s32 a0, s32 *a1, s32 *a2) {
    u8 *g = (u8 *)D_L01_001E64C0;

    *a1 = *(s16 *)(g + 0x22);
    *a2 = *(s16 *)(g + 0x24) + a0;
    if (*a1 >= 0 && *a1 < D_L01_001E6850[32].v[0]) {
        return !(D_L01_001E6850[*a1].v[2] < D_L01_001E6850[*a1].v[1] + *a2);
    }
    return 0;
}
/* localdecomp:end func_L01_00400160 */

/* localdecomp:start func_L01_004001C8 */
void func_0038CAD0(void *);
extern u8 D_L01_001E64EC[];

void func_L01_004001C8(void) {
    func_0038CAD0(D_L01_001E64EC);
}
/* localdecomp:end func_L01_004001C8 */

/* localdecomp:start func_L01_004001E8 */
extern s32 D_L01_001E64C0[];
extern s16 D_L01_001E64E8[];
extern s32 func_L01_00400280(void);

void func_L01_004001E8(void)
{
    S_004001E8 *g;
    s32 v;
    if (func_L01_00400280() != 0) {
        g = (S_004001E8 *)D_L01_001E64C0;
        v = D_L01_001E6850[g->f22].v[6];
        if (v == 0) {
            g->f2C = D_L01_001E6850[g->f22].v[9];
        } else if (v >= 0) {
            if (v < 3) {
                g->f2C = g->f374 + g->f370 * (D_L01_001E6850[g->f22].v[7] - 1);
            }
        }
    } else {
        D_L01_001E64E8[0] = 5;
    }
}
/* localdecomp:end func_L01_004001E8 */

/* localdecomp:start func_L01_00400280 */
s32 func_L01_00400280(void) {
    extern s32 func_L01_00400160(s32 a0, s32 *a1, s32 *a2);
    s32 a, b;
    S_004001E8 *g = (S_004001E8 *)D_L01_001E64C0;
    if (g->f22 == -1) {
        g->f22 = 0;
        ((s16 *)g)[18] = 0;
        return 1;
    }
    if (func_L01_00400160(D_L01_001E6850[g->f22].v[7], &a, &b)) {
        if (D_L01_001E6850[g->f22].v[7] != 0) {
            g->f22 = a;
            ((s16 *)g)[18] = b;
            return 1;
        }
    }
    ((S_004001E8 *)D_L01_001E64C0)->f22++;
    ((s16 *)D_L01_001E64C0)[18] = 0;
    return ((S_004001E8 *)D_L01_001E64C0)->f22 < D_L01_001E6850[32].v[0];
}
/* localdecomp:end func_L01_00400280 */

/* localdecomp:start func_L01_00400368 */
/* from rac2-decomp's func_L00_002E3A68, renamed */
s32 func_L01_00400368(f32 a,f32 b,f32 t) {
 f32 difference=b-a;
 f32 squared=t*t;
 a=a*t;
 difference=difference*squared;
 a=a+difference;
 return (s32)a;
}
/* localdecomp:end func_L01_00400368 */

/* localdecomp:start func_L01_00400390 */
extern u8 D_00142692[];
extern WeightTap_00400390 D_L01_002C0160[][16][10];
extern s32 D_1C5290[][16];

s32 func_L01_00400390(s32 a0, s32 a1) {
    WeightTap_00400390 *tap;
    s32 sum;
    s32 n;

    if (D_00142692[0] != 0) {
        return 0;
    }
    if (a0 >= 30) {
        return 0;
    }
    if (a1 >= 16) {
        return 0;
    }
    tap = D_L01_002C0160[a0][a1];
    sum = 0;
    for (n = 9; n >= 0; n--) {
        sum += tap->weight * D_1C5290[tap->row][tap->col];
        tap++;
    }
    return sum;
}
/* localdecomp:end func_L01_00400390 */

/* localdecomp:start func_L01_00400430 */
extern u8 D_00142692[];
extern s32 D_001D545C;
extern s32 func_L01_00400390(s32 a0, s32 a1);
s32 func_L01_00400430(s32 a0) {
    u8 s = D_00142692[0];
    s32 v;
    if (s != 0) {
        return 3;
    }
    v = 3 - func_L01_00400390(D_001D545C, a0) / 100;
    if (s < v) {
        return v;
    }
    return 1;
}
/* localdecomp:end func_L01_00400430 */

/* localdecomp:start func_L01_00400490 */
extern u8 D_00142692[];
extern s32 D_001D545C;          /* the level number: no size hint, so Ps2EeAs reads it with `lui` here */
extern WeightTap_00400390 D_L01_002C0160[][16][10];

/* help_checkpoint_refund: 100 / the area's first help weight, rounded up; 0 in challenge mode. */
s32 func_L01_00400490(s32 area) {
    WeightTap_00400390 *tap;
    s32 refund;

    if (D_00142692[0] != 0) {
        return 0;
    }
    tap = D_L01_002C0160[D_001D545C][area];
    refund = 100 / tap->weight;
    if (100 % tap->weight != 0) {
        return refund + 1;
    }
    return refund;
}
/* localdecomp:end func_L01_00400490 */

/* localdecomp:start func_L01_004004F8 */
typedef struct { u8 pad[0x46]; u8 kind; } Parent_004004F8;
typedef struct {
    u8 pad[0x24]; Parent_004004F8 *parent;
    u8 pad28[0x82]; s16 kind;
} Object_004004F8;
typedef struct {
    f32 value; s16 amount; u8 pad06[0xE]; u8 color[3];
} Result_004004F8;
extern u8 D_00142692[];
extern u8 D_0014275B[];
extern s32 D_001D545C;
extern f32 D_L01_002F16F0[];
extern f32 D_L01_002F1510[];
extern f32 D_L01_001DAA38;
extern f32 D_L01_001DAA30;
__asm__(".extern D_L01_001DAA38, 4");
__asm__(".extern D_L01_001DAA30, 4");
void func_L01_004004F8(Object_004004F8 *obj) {
    extern Result_004004F8 *func_00382348(void);
    Result_004004F8 *r;
    f32 amount_scale, color_scale;
    s32 p, end;
    s32 n;
    s32 limit;
    if (D_00142692[0] == 0) return;
    if (obj->kind == 500 || obj->kind == 502 || obj->kind == 505 || obj->kind == 512) return;
    if (D_001D545C >= 60) return;
    r = func_00382348();
    if (r == 0) return;
    if (obj->parent != 0 && obj->parent->kind == 13) {
        amount_scale = D_001D545C == 7 && D_0014275B[0] ? D_L01_001DAA38 : D_L01_002F16F0[D_001D545C];
        color_scale = D_001D545C == 7 && D_0014275B[0] ? D_L01_001DAA30 : D_L01_002F1510[D_001D545C];
    } else {
        amount_scale = D_001D545C == 7 && D_0014275B[0] ? D_L01_001DAA30 : D_L01_002F1510[D_001D545C];
        color_scale = D_001D545C == 7 && D_0014275B[0] ? D_L01_001DAA38 : D_L01_002F16F0[D_001D545C];
    }
    limit = 255;
    p = (s32)r->color;
    r->amount = (s32)(r->amount * amount_scale);
    r->value = r->amount;
    end = p + 3;
    do {
        n = (s32)(*(u8 *)p * color_scale);
        if (n >= 256) n = limit;
        *(u8 *)p = n;
        p++;
    } while (p < end);
}
/* localdecomp:end func_L01_004004F8 */

/* localdecomp:start func_L01_004006C8 */
extern u8 D_1BBE90[][1024];

s32 func_L01_004006C8(u8 *a0, s32 a1, s32 a2) {
    s32 c = D_1BBE90[*(s32 *)0x1D545C][a2 >> 1];

    return (a0[(a2 & 1) ? ((c >> 4) & 7) : (c & 7)] * a1) / 100;
}
/* localdecomp:end func_L01_004006C8 */
