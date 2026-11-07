#include "common.h"

/* localdecomp:start func_L01_0041A910 */
extern s32 func_00381FF0_0041A910(s32);
extern s32 func_00382030_0041A910();
void func_L01_0041A910(void) {
    func_00381FF0_0041A910(func_00382030_0041A910());
}
/* localdecomp:end func_L01_0041A910 */

INCLUDE_ASM("asm/levels", func_L01_0041A938);

/* localdecomp:start func_L01_0041A990 */
extern s16 D_L01_002E5F68[];

void func_L01_0041A990(void) {
    D_L01_002E5F68[0] = 0;
}
/* localdecomp:end func_L01_0041A990 */

/* localdecomp:start func_L01_0041A9A0 */
typedef struct {
    s32 state;        /* 0x00: 1 while open */
    s32 timer;        /* 0x04 */
    s32 half_width;   /* 0x08 */
    s32 half_height;  /* 0x0C */
    s32 x10;          /* 0x10 */
    s32 top;          /* 0x14 */
    s32 open_frames;  /* 0x18 */
    s32 close_frames; /* 0x1C */
    s32 index;        /* 0x20: row in the help table */
    u8 pad24[0x48 - 0x24];
    s32 shown;        /* 0x48: frames the text shows */
} Help_0041A9A0;
typedef struct {
    s16 f0;
    u16 f2;
    s16 f4, f6, f8, fA;
    u16 width;        /* 0x0C */
    u16 height;       /* 0x0E */
    s16 f10;
    u16 flags;        /* 0x12 */
    s16 f14, f16, f18, f1A;
} TextBox_0041A9A0;
typedef struct {
    char *text;
    s32 id;
    s32 voice;
    s32 next;
} HelpRow_0041A9A0;
extern Help_0041A9A0 D_L01_002E5F30;
extern HelpRow_0041A9A0 *D_L01_001DFCC0;
extern s32 D_00143950[];
extern s32 D_001D55C4;
extern s32 D_001D4BC4;
__asm__(".extern D_L01_001D67E0, 8");
extern s32 D_L01_001D67E0[2];
extern void func_003A5348(s32, s32, s32);
extern void func_003910C0(TextBox_0041A9A0 *, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_0038E150(s32);
extern long func_00389598(s32);
extern void func_003911F0(TextBox_0041A9A0 *, unsigned long, char *, s32, long, s32, unsigned long, f32);
extern s32 func_0011B868(char *);

/* help_open: opens a help message: its box 60 lines above the screen's bottom, drawn in
   (255, 204, 102). */
void func_L01_0041A9A0(void) {
    Help_0041A9A0 *help = &D_L01_002E5F30;
    TextBox_0041A9A0 box;
    char *text;
    s32 bottom;
    s32 depth;
    s32 top;
    s32 reach;
    u8 *settings = (u8 *)D_00143950; /* +0: language, +4: help sound on */

    help->state = 1;
    help->timer = 0;
    if (*(u16 *)(settings + 4) != 0) {
        /* the help sound */
        func_003A5348(0, 1, 0);
    }
    text = D_L01_001DFCC0[help->index].text;
    depth = 0x100;
    func_003910C0(&box, 0xF0, 0x1E0, 0x2C, 0x1D4, depth, 0x168, 0x10, 7);
    box.flags |= 0x20;
    box.f18 = 2;
    box.f1A = 2;
    func_0038E150(1);
    /* RGBA (255, 204, 102, 0x80) */
    func_003911F0(&box, 0x8066CCFF, text, -1, func_00389598(1), D_001D55C4, 0x80000000, 1.0f);
    help->half_width = ((s16)box.width >> 1) + 10;
    help->half_height = ((s16)box.height >> 1) + 5;
    help->x10 = depth;
    help->top = D_L01_001D67E0[D_00143950[0]]; /* per language */
    help->open_frames = 8;
    help->close_frames = 8;
    help->shown = 0;
    /* shown for 7 frames a character */
    if (text != 0) {
        help->shown = func_0011B868(text) * 7;
    }
    /* 60 lines above the screen's bottom, and at least 12 from it */
    bottom = D_001D4BC4;
    top = bottom - 60;
    help->top = top;
    if (top + help->half_height > bottom - 12) {
        reach = help->half_height + 12;
        help->top = bottom - reach;
    }
}
/* localdecomp:end func_L01_0041A9A0 */

INCLUDE_ASM("asm/levels", func_L01_0041AB50);

/* localdecomp:start func_L01_0041B600 */
void func_L01_0041B600(void) {

}
/* localdecomp:end func_L01_0041B600 */

INCLUDE_ASM("asm/levels", func_L01_0041B608);

LINKER_REMNANT("asm/levels", func_L01_0041BD40);

/* localdecomp:start func_L01_0041BD48 */
extern s32 D_001D5598;
extern u16 D_001A8EC8[];

void func_L01_0041BD48(u16 id) {
    s32 i;

    for (i = 0; D_001A8EC8[i] != id && i < D_001D5598; i++) {
    }
    if (i < D_001D5598) {
        for (; i < D_001D5598 - 1; i++) {
            D_001A8EC8[i] = D_001A8EC8[i + 1];
        }
        D_001A8EC8[i] = 0;
        D_001D5598--;
    }
    D_001A8EC8[D_001D5598++] = id;
}
/* localdecomp:end func_L01_0041BD48 */

LINKER_REMNANT("asm/levels", func_L01_0041BE18);

/* localdecomp:start func_L01_0041BE20 */
void func_L01_0041BE20(void) {

}
/* localdecomp:end func_L01_0041BE20 */

INCLUDE_ASM("asm/levels", func_L01_0041BE28);

/* localdecomp:start func_L01_0041BF08 */
extern u8 D_L01_001DFCF2;
extern u8 D_L01_001DFCF3;
extern s16 D_L01_001DFCE0;
extern s16 D_L01_001DFCC8;
extern s32 func_L01_0041A5B0(s32 a0, s32 a1);
void func_L01_0041BF08(void) {
    if (D_L01_001DFCF2 != 0) {
        if (func_L01_0041A5B0((&D_L01_001DFCC8)[D_L01_001DFCF3], (&D_L01_001DFCE0)[D_L01_001DFCF3]) != 0) {
            D_L01_001DFCF2 = D_L01_001DFCF2 - 1;
            D_L01_001DFCF3 = (D_L01_001DFCF3 + 1) % 9;
        }
    }
}
/* localdecomp:end func_L01_0041BF08 */
