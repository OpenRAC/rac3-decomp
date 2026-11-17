#include "common.h"

/* localdecomp:start func_L01_004792D8 */
extern s32 D_L01_001D8054;

void func_L01_004792D8(s32 a) {
    D_L01_001D8054 = a;
}
/* localdecomp:end func_L01_004792D8 */

/* localdecomp:start func_L01_004792E0 */
s32 func_L01_004792E0(s32 a) {
    s32 r = 0x10006;
    if (a == 0) {
        r = 0x10005;
    }
    return r;
}
/* localdecomp:end func_L01_004792E0 */

/* localdecomp:start func_L01_004792F8 */
__asm__(".extern D_L01_001D805C, 4");
extern s32 D_L01_001D805C;
extern s32 func_L01_005169C8(s32, f32);

void func_L01_004792F8(void) {
    f32 t;
    if (D_L01_001D805C == 0) {
        D_L01_001D805C = 1;
    }
    t = (f32)D_L01_001D805C / 7.0f;
    if (t < 0.0f) {
        t = 0.0f;
    }
    if (t > 1.0f) {
        t = 1.0f;
    }
    func_L01_005169C8(0x10001, t);
    func_L01_005169C8(0x10002, t);
}
/* localdecomp:end func_L01_004792F8 */

/* localdecomp:start func_L01_00479390 */
typedef struct {
    s32 amount;      /* 0x0: the +N/-N tally */
    u8 pad4[0xE - 0x4];
    s16 shown;       /* 0xE */
} Tally_00479390;
/* Ps2EeAs only uses $gp for these if it knows they are small before the use. */
__asm__(".extern D_L01_001D8050, 4");
__asm__(".extern D_L01_001D8054, 4");
__asm__(".extern D_L01_001D805C, 4");
extern s32 D_L01_001D8050;
extern s32 D_L01_001D805C;
/* The HUD's text buffers and tallies are small data to the compiler (one `la` each, rebuilt at
   every use); with no size hint Ps2EeAs expands that to lui/addiu. */
extern char D_L01_001E0370[] __attribute__((section(".sdata")));
extern char D_L01_001E0388[][24] __attribute__((section(".sdata")));
extern char D_L01_001E03B8[] __attribute__((section(".sdata")));
extern Tally_00479390 D_L01_001E03C0[] __attribute__((section(".sdata")));
extern char D_L01_001D8078[];
extern char D_L01_001D8080[];
extern char D_L01_001D8088[];
extern u8 D_00142660[];
extern u8 D_001A4BE0[];
extern void func_L01_00479738(void);
extern void func_L01_00479AB0(void);
extern void func_L01_004792F8(void);
extern s32 func_L01_004792E0(s32);
extern void func_L01_00516AA0(s32, s32, s32);
extern s32 func_0011B2E8(char *, char *, ...);
extern s32 func_0011B868(char *);

/* hud_bolts_draw: draws the bolt HUD with the doubler's x2: (challenge multiplier + 1)
   << bolt_multiplier_exp, shown while 2 or more. */
void func_L01_00479390(void) {
    s32 i;
    s32 multiplier;
    u8 *game;
    u8 *hero;

    func_L01_00479738();
    if (D_L01_001D8050 != 0) {
        D_L01_001D8050--;
        func_0011B2E8(D_L01_001E0370, D_L01_001D8078, *(s32 *)D_L01_001D8054);
        D_L01_001D805C = func_0011B868(D_L01_001E0370);
        /* the two tallies */
        for (i = 0; i < 2; i++) {
            if (D_L01_001E03C0[i].shown != 0) {
                func_L01_00516AA0(func_L01_004792E0(i), 1, 1);
                if (D_L01_001E03C0[i].amount > 0) {
                    func_0011B2E8(D_L01_001E0388[i], D_L01_001D8080, D_L01_001E03C0[i].amount);
                } else {
                    func_0011B2E8(D_L01_001E0388[i], D_L01_001D8078, D_L01_001E03C0[i].amount);
                }
            } else {
                func_L01_00516AA0(func_L01_004792E0(i), 1, 0);
            }
        }
        game = D_00142660;
        hero = D_001A4BE0;
        multiplier = (game[0x5A] + 1) << hero[0x28C8]; /* bolt_mult_exp */
        if (multiplier < 2) {
            func_L01_00516AA0(0x10007, 1, 0);
        } else {
            func_L01_00479AB0();
            func_L01_00516AA0(0x10007, 1, 1);
        }
        func_0011B2E8(D_L01_001E03B8, D_L01_001D8088, multiplier);
    } else {
        func_L01_00516AA0(0x10000, 1, 0);
    }
    func_L01_004792F8();
}
/* localdecomp:end func_L01_00479390 */

/* localdecomp:start func_L01_00479558 */
extern u8 D_L01_001D8058;
extern s32 func_L01_00517918();
void func_L01_00479558(void) {
    D_L01_001D8058 = 0;
    func_L01_00517918(5);
}
/* localdecomp:end func_L01_00479558 */

/* localdecomp:start func_L01_00479578 */
/* Ps2EeAs only uses $gp for these if it knows they are small before the use. */
__asm__(".extern D_L01_001E0308, 4");
__asm__(".extern D_L01_001E0328, 4");
__asm__(".extern D_L01_001E0348, 4");
__asm__(".extern D_L01_001E0368, 4");
__asm__(".extern D_L01_001E02F0, 8");
__asm__(".extern D_L01_001E0310, 8");
__asm__(".extern D_L01_001E0330, 8");
__asm__(".extern D_L01_001E0350, 8");
extern s32 func_L01_00479578(s32);
extern void func_L01_00479390();

typedef struct { u8 b[16]; } V16_3DF9E0;
extern void func_L01_00478BD0(s32);
extern void func_L01_00479558(void);
extern void func_L01_00479390(void);
extern s32 func_003E6FA0(s32 *, s32, s32, s32, s32, s32);
extern s32 D_L01_001E0308;
extern s32 D_L01_001E0328;
extern s32 D_L01_001E0348;
extern s32 D_L01_001E0368;
extern s32 D_L01_001E02F0[2];
extern s32 D_L01_001E0310[2];
extern s32 D_L01_001E0330[2];
extern s32 D_L01_001E0350[2];
extern V16_3DF9E0 D_L01_001D8090[];
s32 func_L01_00479578(s32 idx) {
    V16_3DF9E0 v;
    if (D_L01_001E0308 == 0) {
        func_003E6FA0(D_L01_001E02F0, (s32)func_L01_00478BD0, (s32)func_L01_00479558, (s32)func_L01_00479390, 0, 0);
        D_L01_001E0308 = 1;
    }
    if (D_L01_001E0328 == 0) {
        func_003E6FA0(D_L01_001E0310, (s32)func_L01_00478BD0, (s32)func_L01_00479558, (s32)func_L01_00479390, 0, 0);
        D_L01_001E0328 = 1;
    }
    if (D_L01_001E0348 == 0) {
        func_003E6FA0(D_L01_001E0330, (s32)func_L01_00478BD0, (s32)func_L01_00479558, (s32)func_L01_00479390, 0, 0);
        D_L01_001E0348 = 1;
    }
    if (D_L01_001E0368 == 0) {
        func_003E6FA0(D_L01_001E0350, (s32)func_L01_00478BD0, (s32)func_L01_00479558, (s32)func_L01_00479390, 0, 0);
        D_L01_001E0368 = 1;
    }
    v = D_L01_001D8090[0];
    return *(s32 *)(v.b + (idx << 2));
}
/* localdecomp:end func_L01_00479578 */

/* localdecomp:start func_L01_004796B8 */
extern u8 D_00142660[];
extern s32 D_L01_001E03E0, D_L01_001E03E4, D_L01_001E03EC, D_L01_001E03F0;
void func_L01_004796B8(void) {
    extern void func_L01_004792D8(s32);
    s32 i;
    D_L01_001E03E0 = *(s32 *)D_00142660;
    D_L01_001E03E4 = *(s32 *)D_00142660;
    (&D_L01_001E03E4)[1] = 0;
    func_L01_004792D8((s32)&D_L01_001E03E0);
    D_L01_001E03F0 = 0;
    D_L01_001E03EC = -1;
    for (i=0;i<2;i++) {
        D_L01_001E03C0[i].shown = 0;
        D_L01_001E03C0[i].amount = 0;
    }
}
/* localdecomp:end func_L01_004796B8 */

INCLUDE_ASM("asm/levels", func_L01_00479738);

LINKER_REMNANT("asm/levels", func_L01_00479AA8);

/* localdecomp:start func_L01_00479AB0 */
/* Ps2EeAs only uses $gp for these if it knows they are small before the use. */
__asm__(".extern D_L01_001D8060, 4");
__asm__(".extern D_L01_001D8068, 4");
extern f32 D_L01_001D8060; /* the x2's scale */
extern s32 D_L01_001D8068; /* the x2's red; green and blue follow it */
extern void func_L01_005170B8_00479AB0(s32, u32);
extern void func_L01_00517538(s32, f32, f32);

/* hud_doubler_pulse: the doubler's x2 pulses each beep (the hero's timer at 0x230): green and blue
   up 30 and the scale up 0.1 a frame, down, then up again, then back to the base colour and 1.5.
   Green and blue are reached as the words after red: as their own globals they are small data,
   which reorg puts in the branch delay slots (where Ps2EeAs makes them $gp stores). */
void func_L01_00479AB0(void)
{
    u32 base = 0x70000000;
    u32 colour = (((&D_L01_001D8068)[2] << 16) | (((&D_L01_001D8068)[1] << 8) | base)) | D_L01_001D8068;
    u8 *hero = D_001A4BE0;
    s32 t = *(s32 *)(hero + 0x230);

    if (t != 0) {
        if (t < 4) {
            D_L01_001D8060 -= 0.3f;
        } else if (*(s32 *)(hero + 0x230) == 51) {
            (&D_L01_001D8068)[1] += 30;
            (&D_L01_001D8068)[2] += 30;
            D_L01_001D8060 += 0.1f;
        } else if (*(s32 *)(hero + 0x230) >= 46 && *(s32 *)(hero + 0x230) < 51) {
            (&D_L01_001D8068)[1] -= 30;
            (&D_L01_001D8068)[2] -= 30;
            D_L01_001D8060 -= 0.1f;
        } else if (*(s32 *)(hero + 0x230) >= 43 && *(s32 *)(hero + 0x230) < 46) {
            (&D_L01_001D8068)[1] += 30;
            (&D_L01_001D8068)[2] += 30;
            D_L01_001D8060 += 0.1f;
        } else if (*(s32 *)(hero + 0x230) == 101) {
            (&D_L01_001D8068)[1] += 30;
            (&D_L01_001D8068)[2] += 30;
            D_L01_001D8060 += 0.1f;
        } else if (*(s32 *)(hero + 0x230) >= 96 && *(s32 *)(hero + 0x230) < 101) {
            (&D_L01_001D8068)[1] -= 30;
            (&D_L01_001D8068)[2] -= 30;
            D_L01_001D8060 -= 0.1f;
        } else if (*(s32 *)(hero + 0x230) >= 93 && *(s32 *)(hero + 0x230) < 96) {
            (&D_L01_001D8068)[1] += 30;
            (&D_L01_001D8068)[2] += 30;
            D_L01_001D8060 += 0.1f;
        } else if (*(s32 *)(hero + 0x230) == 151) {
            (&D_L01_001D8068)[1] += 30;
            (&D_L01_001D8068)[2] += 30;
            D_L01_001D8060 += 0.1f;
        } else if (*(s32 *)(hero + 0x230) >= 146 && *(s32 *)(hero + 0x230) < 151) {
            (&D_L01_001D8068)[1] -= 30;
            (&D_L01_001D8068)[2] -= 30;
            D_L01_001D8060 -= 0.1f;
        } else if (*(s32 *)(hero + 0x230) >= 143 && *(s32 *)(hero + 0x230) < 146) {
            (&D_L01_001D8068)[1] += 30;
            (&D_L01_001D8068)[2] += 30;
            D_L01_001D8060 += 0.1f;
        } else if (*(s32 *)(hero + 0x230) == 201) {
            (&D_L01_001D8068)[1] += 30;
            (&D_L01_001D8068)[2] += 30;
            D_L01_001D8060 += 0.1f;
        } else if (*(s32 *)(hero + 0x230) >= 196 && *(s32 *)(hero + 0x230) < 201) {
            (&D_L01_001D8068)[1] -= 30;
            (&D_L01_001D8068)[2] -= 30;
            D_L01_001D8060 -= 0.1f;
        } else if (*(s32 *)(hero + 0x230) >= 193 && *(s32 *)(hero + 0x230) < 196) {
            (&D_L01_001D8068)[1] += 30;
            (&D_L01_001D8068)[2] += 30;
            D_L01_001D8060 += 0.1f;
        } else if (*(s32 *)(hero + 0x230) == 251) {
            (&D_L01_001D8068)[1] += 30;
            (&D_L01_001D8068)[2] += 30;
            D_L01_001D8060 += 0.1f;
        } else if (*(s32 *)(hero + 0x230) >= 246 && *(s32 *)(hero + 0x230) < 251) {
            (&D_L01_001D8068)[1] -= 30;
            (&D_L01_001D8068)[2] -= 30;
            D_L01_001D8060 -= 0.1f;
        } else if (*(s32 *)(hero + 0x230) >= 243 && *(s32 *)(hero + 0x230) < 246) {
            (&D_L01_001D8068)[1] += 30;
            (&D_L01_001D8068)[2] += 30;
            D_L01_001D8060 += 0.1f;
        } else {
            D_L01_001D8068 = 0xFF;
            (&D_L01_001D8068)[1] = 0xD5;
            (&D_L01_001D8068)[2] = 0x7F;
            D_L01_001D8060 = 1.5f;
        }
    } else {
        D_L01_001D8068 = 0xFF;
        (&D_L01_001D8068)[1] = 0xD5;
        (&D_L01_001D8068)[2] = 0x7F;
        D_L01_001D8060 = 1.5f;
    }
    func_L01_005170B8_00479AB0(0x10007, colour);
    func_L01_00517538(0x10007, D_L01_001D8060, D_L01_001D8060);
}
/* localdecomp:end func_L01_00479AB0 */
