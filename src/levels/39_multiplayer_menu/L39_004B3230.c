#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_004B3230);

/* localdecomp:start func_L39_004B3910 */
extern s32 func_L39_004B3230(s32, s32, s32, s32, s32, s32, s32);

s32 func_L39_004B3910(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4)
{
    if (a0 == 0) {
        return -11;
    }
    return func_L39_004B3230(a0, a1, a2, a3, 1, 0, a4);
}
/* localdecomp:end func_L39_004B3910 */

LINKER_REMNANT("asm/levels", func_L39_004B3948);

/* localdecomp:start func_L39_004B3950 */
typedef struct {
    u8 pad0[0x10688];
    unsigned long flags;
    u8 pad1[0x4];
    s32 unk10694;
    u8 pad2[0x20];
    s32 unk106B8;
    u8 pad3[0xC];
    s32 unk106C8;
    u8 pad4[0x14];
    s32 unk106E0;
    u8 pad5[0x1C];
    s32 unk10700[3];
} S_004B3950;

extern s32 D_L39_00453FAC;
extern S_004B3950 D_L39_00453FB0_004B3950;
extern s32 func_L39_004CDC00(void);
extern s32 func_L39_004CDDD8(void);
extern s32 func_L39_004D58E0(void);
extern void func_L39_004D5900(void);
extern void func_L39_004D5928(void);
extern s32 func_001262A0(s32);
extern void func_00126280(s32);

s32 func_L39_004B3950(s32 arg) {
    S_004B3950 *p = &D_L39_00453FB0_004B3950;
    s32 *q = p->unk10700;
    s32 r;

    if (arg == 0) {
        return -11;
    }
    if (D_L39_00453FAC == 0) {
        return -8;
    }
    r = func_L39_004CDC00();
    if (r > 0) {
        r = func_L39_004CDDD8();
        if (r < 0) {
            return r;
        }
        if (r == 0) {
            return -0x194;
        }
    } else if (r < 0) {
        return r;
    }
    if (func_L39_004D58E0() == 0) {
        return -3;
    }
    p->unk10694 = arg;
    p->flags = (((p->flags & ~0x3800) | 0x800) & ~0x700);
    r = func_L39_004CDC00();
    if (r > 0) {
        if (!(D_L39_00453FB0_004B3950.unk106B8 & 1)) {
            p->flags = (p->flags & ~0xC000) | 0x8000;
        } else {
            p->flags = p->flags & ~0xC000;
        }
    } else if (r != 0) {
        return r;
    } else {
        p->flags = p->flags & ~0xC000;
    }
    p->unk106E0 = 1;
    func_001262A0(D_L39_00453FB0_004B3950.unk106C8);
    q[0] = 9;
    q[2] = 1;
    func_00126280(D_L39_00453FB0_004B3950.unk106C8);
    func_L39_004D5900();
    func_L39_004D5928();
    return 0;
}
/* localdecomp:end func_L39_004B3950 */

/* localdecomp:start func_L39_004B3B18 */
typedef struct {
    u8 pad0[0x410];
    long unk410;           /* 0x410 */
    s32 unk418;            /* 0x418 */
    s32 unk41C;            /* 0x41C */
    s32 unk420;            /* 0x420 */
    u8 pad424[0x106BC - 0x424];
    s32 sema[8];           /* 0x106BC */
    u8 pad106DC[0x106F0 - 0x106DC];
    s32 unk106F0;          /* 0x106F0 */
} S_004B3B18;

extern s32 D_L39_00453FAC;
extern S_004B3B18 D_L39_00453FB0_004B3B18;
extern s32 func_L39_004CCE58(void);
extern s32 func_L39_004D58E0(void);
extern s32 func_L39_004D58F0(void);
extern void func_L39_004D5900(void);
extern void func_L39_004D5928(void);
extern void func_L01_004126A8(s32);
extern void func_L39_004B7A80(s32);
extern s32 func_L39_004D0C78(void);
extern void func_L39_004B76F8(void);
extern s32 func_001262A0(s32);
extern void func_00126280(s32);
extern void func_001260B0(s32);
extern void func_00126070(s32);
extern s32 func_00126270(s32);

s32 func_L39_004B3B18(void) {
    u8 *b;
    u32 i;
    s32 r;

    func_L39_004CCE58();
    if (D_L39_00453FAC != 0 && D_L39_00453FB0_004B3B18.unk106F0 <= 0) {
        func_001262A0(D_L39_00453FB0_004B3B18.sema[6]);
        func_00126280(D_L39_00453FB0_004B3B18.sema[6]);
        if (func_L39_004D58E0() == 0) {
            return -3;
        }
        D_L39_00453FB0_004B3B18.unk106F0 = 1;
        if (func_L39_004D58E0() > 0) {
            func_L39_004D5900();
        } else if (func_L39_004D58F0() > 0) {
            func_L39_004D5928();
        }
        func_001262A0(D_L39_00453FB0_004B3B18.sema[4]);
        if (D_L39_00453FB0_004B3B18.unk410 != 0) {
            func_001260B0(D_L39_00453FB0_004B3B18.unk41C);
            func_L01_004126A8(D_L39_00453FB0_004B3B18.unk41C);
            func_00126070(D_L39_00453FB0_004B3B18.unk41C);
            if (D_L39_00453FB0_004B3B18.sema[7] > 0) {
                func_00126270(D_L39_00453FB0_004B3B18.sema[7]);
            }
        }
        func_001260B0(D_L39_00453FB0_004B3B18.unk418);
        func_00126070(D_L39_00453FB0_004B3B18.unk418);
        if ((r = func_00126270(D_L39_00453FB0_004B3B18.sema[0])) != D_L39_00453FB0_004B3B18.sema[0]) return r;
        if ((r = func_00126270(D_L39_00453FB0_004B3B18.sema[1])) != D_L39_00453FB0_004B3B18.sema[1]) return r;
        if ((r = func_00126270(D_L39_00453FB0_004B3B18.sema[2])) != D_L39_00453FB0_004B3B18.sema[2]) return r;
        if ((r = func_00126270(D_L39_00453FB0_004B3B18.sema[3])) != D_L39_00453FB0_004B3B18.sema[3]) return r;
        if ((r = func_00126270(D_L39_00453FB0_004B3B18.sema[4])) != D_L39_00453FB0_004B3B18.sema[4]) return r;
        if ((r = func_00126270(D_L39_00453FB0_004B3B18.sema[5])) != D_L39_00453FB0_004B3B18.sema[5]) return r;
        if ((r = func_00126270(D_L39_00453FB0_004B3B18.sema[6])) != D_L39_00453FB0_004B3B18.sema[6]) return r;
        if (D_L39_00453FB0_004B3B18.unk420 != 0) {
            func_L39_004B7A80(D_L39_00453FB0_004B3B18.unk420);
        }
        b = (u8 *)&D_L39_00453FB0_004B3B18;
        for (i = 0; i <= 0x1073F; i++) {
            b[i] = (u32)((f32)func_L39_004D0C78() / 2147483647.0f * 256.0f);
        }
        func_L39_004B76F8();
        D_L39_00453FAC = 0;
    }
    return 0;
}
/* localdecomp:end func_L39_004B3B18 */

INCLUDE_ASM("asm/levels", func_L39_004B3E10);

/* localdecomp:start func_L39_004B3F28 */
extern s32 D_L39_00453FAC;
extern u8 D_L39_004646B0[];

s32 func_L39_004B3F28(u8 *p)
{
    s32 saved = *(s32 *)(p + 0xC);
    u8 *src;
    u32 i;

    if (p == 0) {
        return -11;
    }
    if (D_L39_00453FAC == 0) {
        return -8;
    }
    src = D_L39_004646B0;
    for (i = 0; i < 16; i++) {
        p[i] = src[i];
    }
    *(s32 *)(p + 0xC) = saved;
    return 0;
}
/* localdecomp:end func_L39_004B3F28 */

/* localdecomp:start func_L39_004B3F88 */
typedef struct {
    u8 pad0[0x204];
    s8 buf[0x200];
    s32 mode;
    u16 len;
} S_004B3F88;

extern s32 D_L39_00453FAC;
extern S_004B3F88 D_L39_00453FB0;
extern void func_00120D28(void *, void *, s32);

s32 func_L39_004B3F88(s32 mode, void *src, u16 len)
{
    if (src == 0 || len == 0) {
        return -11;
    }
    if (D_L39_00453FAC == 0) {
        return -8;
    }
    if (mode == 1) {
        func_00120D28(D_L39_00453FB0.buf, src, 0x200);
        D_L39_00453FB0.len = len;
        if (D_L39_00453FB0.buf[0x1FF] != 0) {
            return -5;
        }
        D_L39_00453FB0.mode = mode;
    } else {
        D_L39_00453FB0.mode = 0;
    }
    return 0;
}
/* localdecomp:end func_L39_004B3F88 */

INCLUDE_ASM("asm/levels", func_L39_004B4020);

/* localdecomp:start func_L39_004B40C8 */
extern u32 func_L39_004B5938(u32);

s32 func_L39_004B40C8(u16 *s)
{
    s[0] = func_L39_004B5938(2);
    s[1] = func_L39_004B5938(5);
    return 4;
}
/* localdecomp:end func_L39_004B40C8 */

INCLUDE_ASM("asm/levels", func_L39_004B4108);

INCLUDE_ASM("asm/levels", func_L39_004B4208);

INCLUDE_ASM("asm/levels", func_L39_004B4310);

INCLUDE_ASM("asm/levels", func_L39_004B4420);

INCLUDE_ASM("asm/levels", func_L39_004B4520);

INCLUDE_ASM("asm/levels", func_L39_004B4620);

INCLUDE_ASM("asm/levels", func_L39_004B4700);

INCLUDE_ASM("asm/levels", func_L39_004B4800);

INCLUDE_ASM("asm/levels", func_L39_004B48E0);

INCLUDE_ASM("asm/levels", func_L39_004B49C0);

INCLUDE_ASM("asm/levels", func_L39_004B4AA0);

INCLUDE_ASM("asm/levels", func_L39_004B4BA0);

INCLUDE_ASM("asm/levels", func_L39_004B4C88);

INCLUDE_ASM("asm/levels", func_L39_004B4D90);

INCLUDE_ASM("asm/levels", func_L39_004B4E98);

INCLUDE_ASM("asm/levels", func_L39_004B5000);

INCLUDE_ASM("asm/levels", func_L39_004B5118);

INCLUDE_ASM("asm/levels", func_L39_004B5200);

INCLUDE_ASM("asm/levels", func_L39_004B5308);

INCLUDE_ASM("asm/levels", func_L39_004B53E8);

INCLUDE_ASM("asm/levels", func_L39_004B54C8);

INCLUDE_ASM("asm/levels", func_L39_004B5630);

INCLUDE_ASM("asm/levels", func_L39_004B5748);
