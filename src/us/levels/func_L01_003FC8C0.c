#include "common.h"

/* NTSC-U counterpart of func_L01_003FEA68 (src/levels/shared/L01_003FE908.c) */
typedef struct {
    s32 v[10];
} S_003FF4E8;
extern s32 D_L01_001E6540[];
extern f32 D_L01_001DF9D0;
extern s32 D_L01_001E6540[];

/* localdecomp:start func_L01_003FC8C0 */
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
extern u8 D_L01_001D60C4_003FC8C0;
__asm__(".extern D_L01_001D60C4_003FC8C0, 1");
extern S_003FF4E8 D_L01_001E68D0[];
extern u8 D_L01_001EA840[];

extern s32 func_0039BEC0(s32, s32, s32, s32, s32);
extern void func_L01_003FD578(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, u32);
extern s32 func_L01_004573E8(void);
extern s32 func_0039D510(s32, s32, s32);
extern void func_L01_003FE190(void);
void func_00388398(void *);
extern f32 func_003BEBF8(f32 *, f32, f32);
extern void func_L01_003FE258(void);
extern void func_L01_003FE278(void);
extern s32 func_0039BF98(s32, s32);
extern s32 func_0038E2E8(void *, s32);
extern s32 func_0038E440(void *);
extern s32 func_L01_004B6C68(void);
extern void func_0039EE68(void);

/* from rac2-decomp's func_00278FC0 */
void func_L01_003FC8C0(void)
{
    s32 lang;
    s32 n;

    D_L01_001D60C4_003FC8C0 = 0;
    if (D_001D4CEC & 1) {
        D_L01_001D60C4_003FC8C0 = 1;
        func_0039BEC0(4, 1, 1, 0, 0);
        return;
    }

    if (((S_003FEA68 *)D_L01_001E6540)->state >= 1 && ((S_003FEA68 *)D_L01_001E6540)->state <= 4 && (*(unsigned long *)(D_001D52FC + 0x1A0) & 0xF000000000UL)) {
        ((S_003FEA68 *)D_L01_001E6540)->state = 5;
    }
    switch (((S_003FEA68 *)D_L01_001E6540)->state) {
    case 0:
        if (D_001CCFD4[0])
            break;
        n = 0;
        func_L01_003FD578(0x1EC1, 0x1EC2, 0x1F3B, 1, 40, 80, 1, 10, 32, 0, n++);
        func_L01_003FD578(0x1F9E, 0x1F9F, 0x1FA0, 2, 40, 80, 0, 2, 130, 2, n++);
        func_L01_003FD578(0, 0x1F3C, 0x1F3C, 3, 0, 160, 0, 1, 100, 1, n++);
        func_L01_003FD578(0x1F3D, 0x1F3E, 0x1F41, 4, 40, 80, 0, 4, 80, 5, n++);
        func_L01_003FD578(0x1F42, 0x1F43, 0x1F45, 5, 40, 80, 0, 3, 104, 4, n++);
        func_L01_003FD578(0x1F42, 0x1F46, 0x1F46, 6, 40, 80, 0, 1, 200, 5, n++);
        func_L01_003FD578(0x1F47, 0x1F48, 0x1F49, 7, 40, 80, 0, 2, 84, 2, n++);
        func_L01_003FD578(0x1F4A, 0x1F4B, 0x1F4F, 8, 40, 80, 0, 2, 160, 1, n++);
        func_L01_003FD578(0x1F50, 0x1F51, 0x1F55, 9, 40, 80, 0, 5, 64, 6, n++);
        func_L01_003FD578(0x1F50, 0x1F56, 0x1F57, 10, 40, 80, 0, 2, 160, 6, n++);
        func_L01_003FD578(0x1F50, 0x1F58, 0x1F5A, 11, 40, 80, 0, 1, 0x12C, 10, n++);
        func_L01_003FD578(0x1F5B, 0x1F5C, 0x1F60, 12, 40, 80, 0, 5, 56, 6, n++);
        func_L01_003FD578(0x1F5B, 0x1F61, 0x1F61, 13, 40, 80, 0, 1, 200, 9, n++);
        func_L01_003FD578(0x1F5B, 0x1F62, 0x1F65, 14, 40, 80, 0, 4, 56, 4, n++);
        func_L01_003FD578(0x1F5B, 0x1F66, 0x1F66, 15, 40, 80, 0, 1, 200, 6, n++);
        func_L01_003FD578(0x1F5B, 0x1F67, 0x1F69, 16, 40, 80, 0, 3, 84, 3, n++);
        func_L01_003FD578(0x1F5B, 0x1F6A, 0x1F6A, 17, 40, 80, 0, 1, 200, 4, n++);
        func_L01_003FD578(0x1F5B, 0x1F6B, 0x1F6E, 18, 40, 80, 0, 4, 56, 4, n++);
        func_L01_003FD578(0x1FA7, 0x1FA8, 0x1FB5, 19, 40, 80, 0, 2, 150, 5, n++);
        func_L01_003FD578(0x1FA1, 0x1FA2, 0x1FA6, 20, 40, 80, 0, 5, 56, 5, n++);
        func_L01_003FD578(0, 0x1F70, 0x1F70, 21, 0, 160, 0, 1, 100, 1, n++);
        func_L01_003FD578(0, 0x1FCC, 0x1FCC, 22, 0, 160, 0, 1, 100, 1, n++);
        func_L01_003FD578(0, 0x1F6F, 0x1F6F, 23, 0, 160, 0, 1, 100, 1, n++);
        func_L01_003FD578(0, 0x1FB6, 0x1FB6, 24, 0, 160, 0, 1, 100, 1, n++);
        func_L01_003FD578(0, 0x1FB8, 0x1FB8, 25, 0, 80, 0, 1, 200, 6, n++);
        func_L01_003FD578(0x1FB9, 0x1FBA, 0x1FC9, 26, 40, 80, 0, 5, 56, 5, n++);
        func_L01_003FD578(0x1FB9, 0x1FCA, 0x1FCB, 27, 40, 80, 0, 2, 150, 9, n++);
        func_L01_003FD578(0, 0x1FCD, 0x1FCD, 28, 0, 80, 0, 1, 200, 6, n++);
        D_L01_001E68D0[32].v[0] = n;
        ((S_003FEA68 *)D_L01_001E6540)->frame = 0;
        ((S_003FEA68 *)D_L01_001E6540)->buffer = 0;
        ((S_003FEA68 *)D_L01_001E6540)->ready = 0;
        if (func_L01_004573E8() == 3)
            ((S_003FEA68 *)D_L01_001E6540)->timer = 0;
        else
            ((S_003FEA68 *)D_L01_001E6540)->timer = 120;
        ((S_003FEA68 *)D_L01_001E6540)->row = -1;
        ((S_003FEA68 *)D_L01_001E6540)->subrow = -1;
        ((S_003FEA68 *)D_L01_001E6540)->step = 10;
        ((S_003FEA68 *)D_L01_001E6540)->base = 460;
        ((S_003FEA68 *)D_L01_001E6540)->duration = (f32)D_001D4BC0 * 2.2f;
        ((S_003FEA68 *)D_L01_001E6540)->rate = 0.10869565f;
        ((S_003FEA68 *)D_L01_001E6540)->repeats = 5;
        ((S_003FEA68 *)D_L01_001E6540)->speed = 0.03f;
        ((S_003FEA68 *)D_L01_001E6540)->limit = 18;
        lang = D_00143A07[0];
        func_0039D510(((S_003FEA68 *)D_L01_001E6540)->buffers[2], D_00160C40.intro[lang].offset + D_00160C40.base,
                      D_00160C40.intro[lang].size);
        ((S_003FEA68 *)D_L01_001E6540)->state = 1;
        break;
    case 1:
        if (D_001CCFD4[0])
            break;
        func_L01_003FE190();
        ((S_003FEA68 *)D_L01_001E6540)->state = 2;
        break;
    case 2:
        func_0039D510(((S_003FEA68 *)D_L01_001E6540)->buffers[((S_003FEA68 *)D_L01_001E6540)->buffer], D_00160C40.frames[((S_003FEA68 *)D_L01_001E6540)->frame].offset + D_00160C40.base,
                      D_00160C40.frames[((S_003FEA68 *)D_L01_001E6540)->frame].size);
        ((S_003FEA68 *)D_L01_001E6540)->state = 3;
        break;
    case 3:
        if (D_001CCFD4[0])
            break;
        if (((s32 (*)(void *))func_00388398)(&((S_003FEA68 *)D_L01_001E6540)->timer)) {
            ((S_003FEA68 *)D_L01_001E6540)->ready = 1;
            ((S_003FEA68 *)D_L01_001E6540)->buffer ^= 1;
            ((S_003FEA68 *)D_L01_001E6540)->frame++;
            if (((S_003FEA68 *)D_L01_001E6540)->frame >= 13)
                ((S_003FEA68 *)D_L01_001E6540)->frame -= 13;
            func_0039D510(((S_003FEA68 *)D_L01_001E6540)->buffers[((S_003FEA68 *)D_L01_001E6540)->buffer], D_00160C40.frames[((S_003FEA68 *)D_L01_001E6540)->frame].offset + D_00160C40.base,
                          D_00160C40.frames[((S_003FEA68 *)D_L01_001E6540)->frame].size);
            ((S_003FEA68 *)D_L01_001E6540)->state = 4;
        }
        break;
    case 4:
        func_003BEBF8(&D_L01_001DF9D0, 0.0f, 0.06666667f);
        if (((s32 (*)(void))func_L01_003FE258)()) {
            func_L01_003FE278();
            if (((S_003FEA68 *)D_L01_001E6540)->state != 5) {
                if (++((S_003FEA68 *)D_L01_001E6540)->tries >= 5) {
                    ((S_003FEA68 *)D_L01_001E6540)->tries = 0;
                    ((S_003FEA68 *)D_L01_001E6540)->state = 3;
                }
            }
        }
        break;
    case 5:
        if (func_L01_004573E8() == 3) {
            func_0039BF98(0, 0);
            ((S_003FEA68 *)D_L01_001E6540)->state = 0;
        } else if (func_0038E2E8(D_L01_001EA840, 0x1C)) {
            func_0038E440(D_L01_001EA840);
            ((S_003FEA68 *)D_L01_001E6540)->state = 6;
        }
        break;
    case 6:
        if (D_00142BBC & 0x10000000) {
            if (!func_L01_004B6C68()) {
                func_0039BEC0(3, 1, 7, 0, 0);
                ((S_003FEA68 *)D_L01_001E6540)->state = 0;
            }
        }
        break;
    }
    func_0039EE68();
}
/* localdecomp:end func_L01_003FC8C0 */
