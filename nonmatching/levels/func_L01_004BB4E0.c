/* func_L01_004BB4E0 (Claude wave 14 r63, 2026-11-28). First draft kept here. */
/* PAL near miss, wave 14 r63 (2026-11-28): func_L01_004BB4E0 (2220 B, 34 places), fresh entry (from the
 * functional C of nonmatching/functional/). Flag-line blocker: retail has Ps2EeAs float constants
 * (lui/ori/mtc1 for li.s) and VU0 macro code. Under the file's own line "-O2 -G8 -fopt-stack
 * -mno-check-zero-division" this C (the two vector adds as one-block VU0 asm) gives 521 diff
 * (build/codex/wave10/p10/check.py, level 01). Under text_parts line 667 (L01_004BBD90.c),
 * "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as", the same C with
 * vec_add_ab(obj + 0x10, &D_L01_001E29C0, &sp0) and vec_add_ab(&pos, &pos, obj + 0x10) in place of the
 * two asm blocks gives 114 diff (tools/check.py --flags "@ps2as -mvu0-use-vf0-vf2", level 01). The
 * function starts at 0x004BB4E0 (8-aligned) and is the last function of L01_004BB330.c; with its padding
 * it ends at 0x004BBD90, where L01_004BBD90.c (line 667, vu0.h helpers) starts, so that file can start
 * at 0x004BB4E0. D_001D5477 is declared volatile here: otherwise its store lands in the beqz delay slot,
 * where Ps2EeAs makes it gp-relative (one word short of retail's lui $at / sb). Left under line 667:
 * the sel copy in that delay slot, the order of the 0x46/0x41 and -1 stores, the first slot search
 * loop's layout and the hoisted half of cnt / 2. Levers: if/else for the 1.0769230f store (ends CSE's block),
 * case 0/2 stores in reverse order, a T pointer taken before func_L01_0041FE30, base = EA940[4] +
 * 0x60000, array-indexed globals for base+offset addressing. */
#include "common.h"

/* localdecomp:start func_L01_004BB4E0 */
#include "vu0.h"
typedef int Q_004BB4E0 __attribute__((mode(TI)));
typedef struct {
    s32 id;
    u8 b4;
    u8 pad5[15];
} Slot_004BB4E0;
typedef struct {
    s32 f0;
    u8 pad4[4];
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    u8 pad18[4];
    s32 f1C;
    u8 pad20[8];
    u8 *obj;
    u8 pad2C[0x38 - 0x2C];
    s32 f38;
    u8 pad3C[8];
    s32 f44;
    u8 pad48[4];
    s32 f4C;
    s32 mode;
    u8 pad54[8];
    s32 f5C;
    s32 f60;
    s32 f64;
    s32 f68;
    u8 pad6C[0x78 - 0x6C];
    s32 f78;
    s32 f7C;
    s32 cur;
    s32 f84;
    u8 b88;
    u8 b89;
    u8 pad8A[0x9C - 0x8A];
    s32 f9C;
    s32 fA0;
    u8 padA4[0xB0 - 0xA4];
    s32 fB0;
    s32 fB4;
    f32 fB8;
    u8 padBC[0xD0 - 0xBC];
    vu0_v4 pos;
    vu0_v4 rot;
    u8 padF0[0x140 - 0xF0];
    Slot_004BB4E0 slots[76];
    u8 pad730[0x10];
    s32 count;
    s32 f744;
    u8 pad748[0x758 - 0x748];
    u8 b758;
    u8 pad759[7];
    s32 f760;
    s32 f764;
} T_004BB4E0;
extern u8 D_00143950[];
extern s16 D_001426A0[];
extern volatile u8 D_001D5477;
extern s32 D_001D4BC0;
extern s32 D_001D4BC4;
extern s16 D_0016C690[];
extern u8 D_001426E0[];
extern u8 D_00142CA0[];
extern s32 D_001427F0[];
extern u8 D_001425C0[];
extern u8 D_L01_002C5600[][240];
extern f32 D_L01_001E0FD0;
extern s32 D_L01_001E0FE0;
extern s32 D_L01_001E0FE4;
extern s32 D_L01_001E0FE8;
extern s32 D_L01_001E0F84;
extern s32 D_L01_001E0F90;
extern s32 D_L01_001E0F94;
extern s32 D_L01_001E0FD4;
extern s32 D_L01_001E0FD8;
extern s32 D_L01_001E0FDC;
extern s32 D_L01_001DAC50;
extern f32 D_L01_001DAC54;
extern f32 D_L01_001DAC58;
extern s32 D_L01_001DABA4;
extern s32 D_L01_001DABA8;
extern s32 D_L01_001DABD4;
extern s32 D_L01_001DABE0;
extern s32 D_L01_001D7BE0;
extern s32 D_L01_001D673C;
extern s32 D_L01_001D6694;
extern s32 D_L01_001DF950;
extern s32 D_L01_001DF958;
__asm__(".extern D_L01_001E0FDC, 4");
__asm__(".extern D_L01_001DAC50, 4");
__asm__(".extern D_L01_001DAC54, 4");
__asm__(".extern D_L01_001DAC58, 4");
__asm__(".extern D_L01_001DABA4, 4");
__asm__(".extern D_L01_001DABA8, 4");
__asm__(".extern D_L01_001DABD4, 4");
__asm__(".extern D_L01_001DABE0, 4");
__asm__(".extern D_L01_001DF958, 4");
extern u8 D_L01_001DAC00[] __attribute__((section(".sdata")));
extern u8 D_L01_001DAC10[] __attribute__((section(".sdata")));
extern u8 D_L01_001DAC30[] __attribute__((section(".sdata")));
extern u8 D_L01_001DAC40[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DAC00, 8");
__asm__(".extern D_L01_001DAC10, 8");
__asm__(".extern D_L01_001DAC30, 8");
__asm__(".extern D_L01_001DAC40, 8");
extern vu0_v4 D_L01_001E29C0;
extern u8 D_L01_001E2A40[];
extern s32 D_L01_001EA940[];
extern u8 D_L01_001F1AD0[];
extern u8 D_001A4BE0[];
extern void func_0038CB78(void *, s32, s32);
extern u8 *func_003C24B0(s32, s32);
extern void func_003C7C38(u8 *);
extern void func_L01_004C2548(void);
extern void func_L01_004C4380(void);
extern void func_L01_004C3910(void);
extern void func_L01_004C4FE8(void);
extern void func_0013C1A0(s32);
extern void func_L01_0045F328(s32);
extern void func_0013B620(void);
extern void func_L01_004BAA20(s32);
extern void func_L01_004BAFB8(void);
extern void func_L01_004BB140(void);
extern void func_L01_0041FE30(void);
extern void func_003E54E0(s32);
extern void func_L01_0047B798(s32, s32);
extern void func_L01_0047B820(s32, s32);
extern void func_L01_0047B9B8(s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_0041A6E0(void);
extern void func_L01_005108C0(s32);
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_003C5180(void *, void *, s32);
extern void func_L01_004515D8(void *, void *, s32);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_003C48A8(void *, void *);
extern void func_L01_003EB438(s32, void *, void *, s32, s32, s32);
extern void func_L01_003EB350(s32, void *);
extern void func_L01_003EB3C0(s32, void *);
extern void func_00384D88(void);

void func_L01_004BB4E0(s32 arg) {
    vu0_v4 sp0;
    vu0_v4 sp10;
    vu0_v4 sp20;
    vu0_v4 sp30;
    u8 *o2;
    u8 *rec;
    u8 saved;
    s32 savedId;
    s32 sel;
    s32 mode;
    s32 cnt;
    T_004BB4E0 *t;
    s32 base;
    s32 i;
    s32 id;
    s32 v;
    Q_004BB4E0 q;

    saved = ((T_004BB4E0 *)D_L01_002446C0)->b758;
    savedId = ((T_004BB4E0 *)D_L01_002446C0)->f760;
    func_0038CB78(D_L01_002446C0, 0, 0x790);
    if (*(s32 *)D_00143950 != 0) {
        D_L01_001E0FD0 = 1.0769230f;
    } else {
        D_L01_001E0FD0 = 1.0f;
    }
    D_L01_001DABA4 = D_001D5477;
    D_L01_001DABD4 = D_001426A0[0];
    ((T_004BB4E0 *)D_L01_002446C0)->f60 = 0;
    D_001D5477 = 0;
    if ((u32)arg < 7) {
        sel = arg;
        ((T_004BB4E0 *)D_L01_002446C0)->f60 = 1;
        if (arg == 4) {
            ((T_004BB4E0 *)D_L01_002446C0)->f5C = 1;
            sel = 0;
        }
        arg = (s32)func_003C24B0(0xB, 0x80);
        *(s16 *)(((u8 *)arg) + 0x32) = 0x40;
        *(u16 *)(((u8 *)arg) + 0x34) |= 0x80;
        if (D_00143950[0xAD] != 0) {
            *(Q_004BB4E0 *)&sp0 = *(Q_004BB4E0 *)D_L01_001DAC10;
        } else {
            *(Q_004BB4E0 *)&sp0 = *(Q_004BB4E0 *)D_L01_001DAC00;
        }
        sp0.z = -sp0.z;
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
                : "=m"(*(vu0_v4 *)(((u8 *)arg) + 0x10))
                : "m"(D_L01_001E29C0), "m"(sp0)
                : "vf1", "vf2");
        qzero(((u8 *)arg) + 0xF0);
        *(f32 *)(((u8 *)arg) + 0xF8) = 3.1415927f;
        func_003C7C38(((u8 *)arg));
        ((T_004BB4E0 *)D_L01_002446C0)->f60 = 1;
        ((T_004BB4E0 *)D_L01_002446C0)->f744 = 0;
        ((u8 *)arg)[0x20] = 3;
        switch (sel) {
        case 0:
            ((T_004BB4E0 *)D_L01_002446C0)->f744 = 0;
            ((T_004BB4E0 *)D_L01_002446C0)->mode = 0;
            func_L01_004C2548();
            break;
        case 2:
            ((T_004BB4E0 *)D_L01_002446C0)->mode = 2;
            ((T_004BB4E0 *)D_L01_002446C0)->fB8 = -1.5707964f;
            ((T_004BB4E0 *)D_L01_002446C0)->fB0 = 0;
            ((T_004BB4E0 *)D_L01_002446C0)->fB4 = 0;
            ((T_004BB4E0 *)D_L01_002446C0)->fA0 = 0;
            func_L01_004C4380();
            break;
        case 3:
            ((T_004BB4E0 *)D_L01_002446C0)->mode = 3;
            func_L01_004C3910();
            break;
        case 5:
            ((T_004BB4E0 *)D_L01_002446C0)->mode = 5;
            D_L01_001DABA8 = D_L01_001D7BE0;
            func_L01_004C4FE8();
            break;
        case 6:
            ((T_004BB4E0 *)D_L01_002446C0)->f744 = 1;
            ((T_004BB4E0 *)D_L01_002446C0)->mode = 0;
            func_L01_004C2548();
            break;
        }
    } else {
        if (*(s16 *)(((u8 *)arg) + 0xAA) == 0xB) {
            v = *(s32 *)(*(u8 **)(((u8 *)arg) + 0x68) + 0x94);
            if (v == 0) {
                ((T_004BB4E0 *)D_L01_002446C0)->mode = 0;
                func_L01_004C2548();
            } else if (v == 4) {
                ((T_004BB4E0 *)D_L01_002446C0)->mode = 2;
                func_L01_004C4380();
            } else if (v == 2) {
                ((T_004BB4E0 *)D_L01_002446C0)->mode = 3;
                func_L01_004C3910();
            } else if (v == 5) {
                ((T_004BB4E0 *)D_L01_002446C0)->mode = 5;
                func_L01_004C4FE8();
            } else if (v == 3) {
                ((T_004BB4E0 *)D_L01_002446C0)->mode = 0;
                ((T_004BB4E0 *)D_L01_002446C0)->f744 = 1;
                func_L01_004C2548();
            }
        } else if (*(s16 *)(((u8 *)arg) + 0xAA) == 0x1D99) {
            ((T_004BB4E0 *)D_L01_002446C0)->obj = ((u8 *)arg);
            ((T_004BB4E0 *)D_L01_002446C0)->mode = 2;
            func_L01_004C4380();
        }
    }
    if (D_L01_001DABE0 != -1) {
        ((T_004BB4E0 *)D_L01_002446C0)->mode = D_L01_001DABE0;
    }
    v = D_00143950[0xB7] - 1;
    ((T_004BB4E0 *)D_L01_002446C0)->b88 = 0;
    ((T_004BB4E0 *)D_L01_002446C0)->b89 = 0;
    ((T_004BB4E0 *)D_L01_002446C0)->f38 = (((T_004BB4E0 *)D_L01_002446C0)->mode == 0) ? 2 : 6;
    ((T_004BB4E0 *)D_L01_002446C0)->f44 = v;
    if (v < 0) {
        ((T_004BB4E0 *)D_L01_002446C0)->f44 = 0;
    }
    D_L01_001E0FE0 = 0x41;
    D_L01_001DAC54 = 0.8f;
    D_L01_001DAC58 = 1.0f;
    D_L01_001E0FE8 = 0x46;
    D_L01_001E0FE4 = 0x60;
    ((T_004BB4E0 *)D_L01_002446C0)->f78 = -1;
    ((T_004BB4E0 *)D_L01_002446C0)->f7C = -1;
    ((T_004BB4E0 *)D_L01_002446C0)->f68 = -1;
    ((T_004BB4E0 *)D_L01_002446C0)->f64 = 0;
    ((T_004BB4E0 *)D_L01_002446C0)->cur = 0;
    D_L01_001E0F90 = 0;
    ((T_004BB4E0 *)D_L01_002446C0)->f84 = 0;
    D_L01_001E0F94 = 0;
    D_L01_001E0F84 = 0;
    D_L01_001DAC50 = 0;
    D_L01_001E0FD4 = 0;
    D_L01_001E0FD8 = 0;
    D_L01_001E0FDC = 0;
    func_0013C1A0(0x4D);
    func_L01_0045F328(0);
    func_0013B620();
    mode = ((T_004BB4E0 *)D_L01_002446C0)->mode;
    if (mode == 0) {
        func_L01_004BAA20(0);
    } else if (mode == 3) {
        func_L01_004BAFB8();
        D_001426E0[0x75] |= D_001426E0[0x3E];
    } else if (mode == 2) {
        func_L01_004BB330();
    } else if (mode == 5) {
        func_L01_004BB140();
    }
    cnt = ((T_004BB4E0 *)D_L01_002446C0)->count;
    if (saved != 0) {
        ((T_004BB4E0 *)D_L01_002446C0)->cur = 0;
        i = 0;
        if (cnt > 0) {
            if (((T_004BB4E0 *)D_L01_002446C0)->slots[0].id != savedId) {
            next:
                i++;
                if (i < ((T_004BB4E0 *)D_L01_002446C0)->count) {
                    if (((T_004BB4E0 *)D_L01_002446C0)->slots[i].id != savedId) {
                        goto next;
                    }
                    ((T_004BB4E0 *)D_L01_002446C0)->cur = i;
                }
            }
        }
    } else {
        mode = ((T_004BB4E0 *)D_L01_002446C0)->mode;
        if (mode == 3 || mode == 5) {
            ((T_004BB4E0 *)D_L01_002446C0)->cur = 0;
        } else if (((T_004BB4E0 *)D_L01_002446C0)->f744 == 0) {
            i = 0;
            while (i < cnt && ((T_004BB4E0 *)D_L01_002446C0)->slots[i].b4 == 0) {
                ((T_004BB4E0 *)D_L01_002446C0)->cur = i;
                i++;
            }
        } else {
            ((T_004BB4E0 *)D_L01_002446C0)->cur = cnt / 2;
        }
    }
    t = ((T_004BB4E0 *)D_L01_002446C0);
    func_L01_0041FE30();
    func_003E54E0(0);
    if (t->mode == 0) {
        i = t->cur;
        if (t->slots[i].b4 == 1) {
            id = t->slots[i].id;
            rec = D_L01_002C5600[D_001425C0[id]];
            if (rec[0] != 0 && D_00142CA0[id] != 0) {
                func_L01_0047B798(*(u16 *)(rec + 0x38), 0);
                func_L01_0047B820(D_001427F0[id], *(u16 *)(D_L01_002C5600[D_001425C0[id]] + 0x8A));
                func_L01_0047B9B8(id);
            }
        }
    }
    ((T_004BB4E0 *)D_L01_002446C0)->f764 = D_L01_001E2A40[0x27D];
    base = D_L01_001EA940[4] + 0x60000;
    ((T_004BB4E0 *)D_L01_002446C0)->f14 = D_L01_001EA940[3] + 0x60000;
    ((T_004BB4E0 *)D_L01_002446C0)->f1C = base + D_001D4BC0 * D_001D4BC4 * 4;
    ((T_004BB4E0 *)D_L01_002446C0)->f0 = 0;
    ((T_004BB4E0 *)D_L01_002446C0)->f10 = base;
    ((T_004BB4E0 *)D_L01_002446C0)->f8 = 0;
    ((T_004BB4E0 *)D_L01_002446C0)->fC = 1;
    ((T_004BB4E0 *)D_L01_002446C0)->obj = ((u8 *)arg);
    func_003A52A0(3, 0x11, ((u8 *)arg));
    ((T_004BB4E0 *)D_L01_002446C0)->f4C = D_001D54D0;
    ((T_004BB4E0 *)D_L01_002446C0)->f9C = D_0016C690[10];
    func_L01_0041A6E0();
    D_L01_001D6694 = 5;
    D_L01_001DF950 = 0;
    D_L01_001DF958 = 0;
    if (((T_004BB4E0 *)D_L01_002446C0)->f5C == 0) {
        if (((T_004BB4E0 *)D_L01_002446C0)->f60 == 0) {
            D_001A4BE0[0x25ED] = 1;
            D_001A4BE0[0x25E5] = 1;
            func_L01_005108C0(0);
        }
    }
    if (((T_004BB4E0 *)D_L01_002446C0)->f60 == 0) {
        if (D_00143950[0xAD] != 0) {
            func_0038D000(&((T_004BB4E0 *)D_L01_002446C0)->pos, D_L01_001DAC10, ((T_004BB4E0 *)D_L01_002446C0)->obj + 0xC0);
        } else {
            func_0038D000(&((T_004BB4E0 *)D_L01_002446C0)->pos, D_L01_001DAC00, ((T_004BB4E0 *)D_L01_002446C0)->obj + 0xC0);
        }
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(((T_004BB4E0 *)D_L01_002446C0)->pos)
                : "m"(((T_004BB4E0 *)D_L01_002446C0)->pos), "m"(*(vu0_v4 *)(((T_004BB4E0 *)D_L01_002446C0)->obj + 0x10))
                : "vf1", "vf2");
        ((T_004BB4E0 *)D_L01_002446C0)->rot.z = func_0038DAB8(*(f32 *)(((T_004BB4E0 *)D_L01_002446C0)->obj + 0xF8), 3.1415927f);
        if (D_L01_001D673C != 0) {
            o2 = ((T_004BB4E0 *)D_L01_002446C0)->obj;
            *(Q_004BB4E0 *)&sp10 = *(Q_004BB4E0 *)(o2 + 0xC0);
            *(Q_004BB4E0 *)&sp20 = *(Q_004BB4E0 *)(o2 + 0xD0);
            *(Q_004BB4E0 *)&sp30 = *(Q_004BB4E0 *)(o2 + 0xE0);
            func_003C5180(&((T_004BB4E0 *)D_L01_002446C0)->pos, &sp0, 1);
            func_L01_004515D8(&sp10, &sp0, 0);
            func_0038D890(&sp10, &sp10, &sp30, 3.1415927f);
            func_0038D890(&sp20, &sp20, &sp30, 3.1415927f);
            func_003C48A8(&sp10, &((T_004BB4E0 *)D_L01_002446C0)->rot);
        }
        func_L01_003EB438(0, &((T_004BB4E0 *)D_L01_002446C0)->pos, &((T_004BB4E0 *)D_L01_002446C0)->rot, 1, 0, 0);
        sp0 = ((T_004BB4E0 *)D_L01_002446C0)->pos;
        if (((T_004BB4E0 *)D_L01_002446C0)->mode == 2) {
            sp0.y += 5.0f;
        }
        func_L01_003EB350(0, &sp0);
        func_L01_003EB3C0(0, &((T_004BB4E0 *)D_L01_002446C0)->rot);
        D_L01_001E2A40[0x27D] = 0;
        func_00384D88();
    }
    func_0038D000(D_L01_001F1AD0, D_L01_001DAC30, ((T_004BB4E0 *)D_L01_002446C0)->obj + 0xC0);
    q = *(Q_004BB4E0 *)D_L01_001DAC40;
    qzero(D_L01_001F1AD0 + 0x10);
    qzero(D_L01_001F1AD0 + 0x20);
    *(Q_004BB4E0 *)(D_L01_001F1AD0 - 0x10) = q;
}
/* localdecomp:end func_L01_004BB4E0 */
