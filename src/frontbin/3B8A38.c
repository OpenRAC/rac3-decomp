#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern s32 func_00381FF0(s32);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_0038CC88_00391678(void *, void *, s32) __asm__("func_0038CC88");
extern s32 func_00381FF0();
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003B97B0(void);
extern s32 func_003B96D0(void);
extern s32 func_003B9700();
extern void func_003B9890(void);
extern void func_003B98A0();
extern void func_003B8A38(s32);
extern s32 func_003B9298(s32, s32, s32, s32, s32, s32, s32, s32, f32, s32, s32, s32, s32, s32, s32);


/* localdecomp:start func_003B8A38 */
/* the copy of func_003B8DF0 */
typedef struct { s32 f0; u8 p4[0x2E]; u8 f32; u8 p33[5]; s32 f38; s32 f3C; u8 p40[2]; s16 f42; s32 f44; u8 p48[0x12]; u8 f5A; u8 f5B; u8 p5C[0x24]; } S80_003B8A38;
typedef struct { u8 b[8]; } B8_003B8A38;
typedef struct { u8 p[0x120]; u16 f120; } S1A7E18_003B8A38;
typedef struct { u8 p[0x2884]; s16 f2884; } S1A4BE0_003B8A38;
typedef struct { u8 p[0x8A]; u16 f8A; u8 q[0xF0 - 0x8C]; } SDAA40_003B8A38;
typedef struct { s32 f0; u8 p[0x18]; } E_003B8A38;
typedef struct { u8 p0[0x18]; s16 f18; u8 p1a[0x16]; E_003B8A38 e[10]; u8 p148[0x148 - 0x30 - 10 * 0x1C]; s32 f148; u8 p14c[0x174 - 0x14C]; s32 f174; } S142430_003B8A38;

extern u8 D_001426E0[];
extern S80_003B8A38 D_00142660;
extern S1A7E18_003B8A38 D_001A7E18;
extern S1A4BE0_003B8A38 D_001A4BE0;
extern SDAA40_003B8A38 D_001DAA40[];
extern S142430_003B8A38 D_00142430;
extern B8_003B8A38 D_001D4BE0;
extern s32 D_001D5528;
extern s32 D_001D4C38;
extern s32 D_001D54D0;
extern u8 D_00142CA0[];
extern s32 D_00142DE0[];
extern u8 D_001425C0[];
extern s32 D_001427F0[];
extern u8 D_00142A60[];
extern u8 D_00142B00[];
extern u8 D_001D54B0[] __attribute__((section(".sdata")));
extern u8 D_001D5468[] __attribute__((section(".sdata")));
extern u8 D_001D5498[] __attribute__((section(".sdata")));
extern u16 D_001D55A0[] __attribute__((section(".sdata")));
extern u8 D_001D55B0[] __attribute__((section(".sdata")));
extern u16 D_001D54D8[] __attribute__((section(".sdata")));
extern u8 D_001BBB18[];
extern s32 D_001D4C60[] __attribute__((section(".sdata")));
extern s32 D_001D4C80[] __attribute__((section(".sdata")));
extern u8 D_00143950[];
__asm__(".extern D_001D8A9C, 4");
extern s32 D_001D8A9C;
extern void func_0038CC88(void *, void *, s32);
extern void func_0038CB78(void *, s32, s32);
extern void func_003C0CC8(s32);
extern void func_0039C300(void);
extern s32 func_00381D80(s32, s32);
extern void func_0039E5E0(s32);

void func_003B8A38(s32 a0) {
    s32 b0[0x9C];
    s32 b1[0x9C];
    s32 b2[0x9C];
    s32 b3[0x20];
    u8 b4[0x9C];
    u8 b5[5];
    s32 b6[0x20];
    u16 b7[6];
    u8 b8[6];
    s32 b9[0x13];
    s32 b10[0x13];
    S80_003B8A38 s80;
    B8_003B8A38 s8;
    u8 buf[0x1E0];
    s32 n5 = 5;
    s32 n15 = 15;
    s32 v54d0 = 0;
    s32 tmp[n15];
    u8 c3e = D_001426E0[0x3E];
    u8 c8 = D_001426E0[0xC8];
    u8 c1 = D_001426E0[0xC1];
    u16 h120 = D_001A7E18.f120;
    s32 v5528 = 0, v4c38 = 0;
    u8 c45 = 0;
    s32 i = 0;
    s32 j = 0;
    s32 *p = 0;
    s32 old = 0;

    D_00142660.f32++;
    D_00142660.f0 += 2;
    D_00142660.f5A = 0;
    D_00142660.f5B = 0;
    s80 = D_00142660;
    v5528 = D_001D5528;
    v4c38 = D_001D4C38;
    s8 = D_001D4BE0;
    for (i = 0; i < n15; i++) tmp[i] = D_001426E0[0xB0 + i];
    for (i = 0; i < 0x9C; i++) {
        b0[i] = D_00142CA0[i];
        b1[i] = D_00142DE0[i];
        b2[i] = D_001425C0[i];
    }
    v54d0 = D_001D54D0;
    for (i = 0; i < n5; i++) b5[i] = D_001426E0[0xC3 + i];
    for (i = 0; i < 0x20; i++) b3[i] = D_001D54B0[i];
    for (i = 0; i < 0x13; i++) {
        b9[i] = D_001D5468[i];
        b10[i] = D_001D5498[i];
    }
    for (i = 0; i < 6; i++) {
        b7[i] = D_001D55A0[i];
        b8[i] = D_001D55B0[i];
    }
    b0[27] = 0;
    b0[14] = 0;
    b0[11] = 0;
    b0[24] = 0;
    b0[30] = 0;
    b0[15] = 0;
    b0[2] = 0;
    b0[3] = 0;
    b0[4] = 0;
    b0[13] = 0;
    b0[8] = 0;
    b0[31] = 0;
    b0[18] = 0;
    b0[33] = 0;
    b0[34] = 0;
    func_0038CC88(buf, D_001BBB18, 0x128);
    c45 = D_001426E0[0x45];
    for (i = 0; i < 0x9C; i++) b4[i] = D_00142A60[i];
    for (j = 0; j < 0x20; j++) b6[j] = D_001D54D8[j];
    func_003C0CC8(func_00381FF0(0xBB7));
    func_0039C300();
    for (j = 0; j < 0x20; j++) D_001D54D8[j] = b6[j];
    D_001426E0[0x3E] = c3e;
    D_001426E0[0xC8] = c8;
    D_001426E0[0xC1] = c1;
    func_0038CC88(D_001BBB18, buf, 0x128);
    D_001426E0[0x45] = c45;
    for (i = 0; i < 6; i++) D_001D55A0[i] = b7[i];
    for (i = 0; i < n15; i++) D_001426E0[0xB0 + i] = tmp[i];
    func_0038CB78(D_00142B00, 0, 0x9C);
    for (i = 0; i < 0x9C; i++) D_00142A60[i] = b4[i];
    for (i = 0; i < 8; i++) {
        D_001D4C60[i] = 0;
        D_001D4C80[i] = 0;
    }
    D_001D5528 = v5528;
    D_001D4C38 = v4c38;
    D_001D4BE0 = s8;
    D_00142660 = s80;
    D_00142660.f42 = 0;
    D_00142660.f44 = 0;
    D_00142660.f38 = 0;
    D_00142660.f3C = 0;
    D_00143950[4] = 0;
    D_00143950[5] = 0;
    if (h120 != 0 && D_001A7E18.f120 == 0) D_001A7E18.f120 = 1;
    for (i = 0; i < n5; i++) D_001426E0[0xC3 + i] = b5[i];
    for (i = 0; i < 0x9C; i++) {
        D_00142CA0[i] = b0[i];
        D_00142DE0[i] = b1[i];
        D_001425C0[i] = b2[i];
        { SDAA40_003B8A38 *e = &D_001DAA40[D_001425C0[i]]; D_001427F0[i] = e->f8A; }
    }
    for (i = 0; i < 0x20; i++) D_001D54B0[i] = b3[i];
    for (i = 0; i < 0x13; i++) {
        D_001D5468[i] = b9[i];
        D_001D5498[i] = b10[i];
    }
    D_00143950[5] = 0;
    D_00143950[4] = 0;
    func_00381D80(9, 3);
    D_001A4BE0.f2884 = 1;
    D_001D54D0 = v54d0;
    if (a0 >= 0) {
        D_00142430.f18 = a0;
        p = &D_00142430.e[a0].f0;
        old = *p;
        *p = 1;
        func_0039E5E0(D_001D8A9C);
        *p = old;
        D_00142430.f174 = D_001D8A9C;
        D_00142430.f148 = 0;
    }
}
/* localdecomp:end func_003B8A38 */
