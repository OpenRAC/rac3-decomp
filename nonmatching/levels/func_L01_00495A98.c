/* NTSC-U draft (2026-11-14, Claude worker): C of func_L01_004922A0, the NTSC-U twin of func_L01_00495A98, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L01_00494540.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* NTSC-U counterpart of func_L01_00495A98 (src/levels/shared/L01_00494540.c). check_native MATCH (2128 B) with the PAL line
   + @ps2as (the line alone: 310 diff, lui/ori/mtc1 float literals and $gp forms in delay slots are Ps2EeAs's).
   func_L01_005130C8 is declared s32 (its v0 return makes the table-index temps v1 as retail). D_001D52FC is ONE plain extern.
   D_001D55A0 is declared u16[4] (8 bytes, small data for cc1): cc1 then loads its address with one unsplit `la`, which
   Ps2EeAs expands into lui/addiu; that single insn gives retail's sll, lui, addiu, addu, li order of the lookup. */

/* localdecomp:start func_L01_004922A0 */
typedef struct {
    void (*f0)(s32);
    s32 (*f1)(s32);
    void (*f2)(s32);
} Ops_4922A0;
extern s32 D_001D52FC;
extern s32 D_001D9058_sda;
extern s32 D_001D9170_sda;
extern u8 D_001D9104_sda;
extern s32 D_001D90F0_sda[2];
extern char D_001E0BB0_sda[8];
extern char D_001E0BC0_sda[8];
extern u8 D_001426E0[];
extern u8 D_001BBB18[];
extern u16 D_001D55A0[4];
extern char D_L01_001D9180[];
extern char D_L01_001D9198[];
extern char D_L01_001D91A0[];
extern char D_L01_001D91B0[];
__asm__(".extern D_001D9058_sda, 4");
__asm__(".extern D_001D9170_sda, 4");
__asm__(".extern D_001D9104_sda, 4");
__asm__(".extern D_001D90F0_sda, 4");
__asm__(".extern D_001E0BB0_sda, 8");
__asm__(".extern D_001E0BC0_sda, 8");
extern Ops_4922A0 *func_L01_00438468(s32, s32);
extern char *func_0037DF98(s32);
extern s32 func_003B4220(s32, s32, s32, char *, s32);
extern s32 func_003B42D0(void);
extern s32 func_L01_004948D0(void);
extern void func_00399F90(void);
extern void func_L01_00512D70(s32, s32);
extern void func_L01_00512FE8(s32, char *);
extern s32 func_L01_005130C8(s32, s32);
extern void func_L01_00513548(s32, f32, f32);
extern void func_L01_005131A0(s32, s32);
extern void func_0039FF28(s32, s32, s32);
extern s32 func_0037E368(u32, u32, s32, s32, s32, s32);
extern s32 func_0011B2E8(char *, char *, ...);
extern s32 func_L01_00417EA0(void);
extern s32 func_L01_0047B380(void);
extern void func_L01_00513758(s32);
extern void func_L01_005120B8(s32);

void func_L01_004922A0(s32 a0) {
    Ops_4922A0 *ops = func_L01_00438468(0x18E2, 0xC);
    u8 buf[5] = {0x1F, 0x21, 0x22, 0x20, 0x23};
    s32 st;
    s32 k;
    s32 ok;
    s32 s5;
    s32 old;
    s32 t;
    s32 buttons;
    s32 b2;

    st = D_001D9170_sda;
    switch (st) {
    case 1:
        func_003B4220(0, func_0037DF98(0x8E2), func_0037DF98(0x177), D_L01_001D9180, 0);
        D_001D9170_sda = 2;
        return;
    case 2:
        if (func_003B42D0() != 0) {
            return;
        }
        D_001D9170_sda = 0;
        if (func_L01_004948D0() == st) {
            ops->f0(D_001D9058_sda);
            func_L01_00513758(func_L01_0047B380());
            func_L01_005120B8(a0);
            return;
        }
        if ((u8)(buf[D_001D9058_sda] - 0x1E) < 8) {
            D_001426E0[0x54] |= 1 << (buf[D_001D9058_sda] - 0x1E);
        }
        func_00399F90();
        ops->f2(buf[D_001D9058_sda]);
        if (buf[D_001D9058_sda] == 0x1F) {
            D_001426E0[0xB] = 1;
            func_00399F90();
        }
        return;
    case 0:
    default:
        buttons = *(s32 *)(D_001D52FC + 0x1C4);
        old = D_001D9058_sda;
        if (buttons & 0x1000) {
            func_0039FF28(3, 0, 0);
            func_0037E368(0x332299DE, 0x8066CCFF, 0x28, 0, 1, 1);
            func_L01_005130C8(D_001D9058_sda + 0x11000C, 0x332299DE);
            do {
                D_001D9058_sda = D_001D9058_sda - 1;
                if (D_001D9058_sda < 0) {
                    D_001D9058_sda = 5;
                }
            } while (ops->f1(D_001D9058_sda) == 0 && D_001D9058_sda != old);
            func_L01_005131A0(0x110022, D_001D9058_sda + 1);
        } else if (buttons & 0x4000) {
            func_0039FF28(3, 0, 0);
            func_0037E368(0x332299DE, 0x8066CCFF, 0x28, 0, 1, 1);
            func_L01_005130C8(D_001D9058_sda + 0x11000C, 0x332299DE);
            do {
                D_001D9058_sda = D_001D9058_sda + 1;
                if (D_001D9058_sda >= 6) {
                    D_001D9058_sda = 0;
                }
            } while (ops->f1(D_001D9058_sda) == 0 && D_001D9058_sda != old);
            func_L01_005131A0(0x110022, D_001D9058_sda + 1);
        }
        t = func_0037E368(0x332299DE, 0x8066CCFF, 0x28, 0, 0, 1);
        s5 = 1;
        func_L01_005130C8(D_001D9058_sda + 0x11000C, t);
        func_L01_00512FE8(0x110023, func_0037DF98(D_001D90F0_sda[D_001D9058_sda]));
        k = buf[D_001D9058_sda] - 0x1E;
        if (buf[D_001D9058_sda] != 0x1F
            && ((u8)(buf[D_001D9058_sda - 1] - 0x1E) >= 8 || (((D_001426E0[0x54] >> (buf[D_001D9058_sda - 1] - 0x1E)) ^ 1) & 1))) {
            s5 = 0;
            func_L01_00512FE8(0x11002C, func_0037DF98(0x1873));
            func_L01_00513548(0x11002C, 0.8f, 1.0f);
            func_L01_00512D70(0x11002C, 1);
            func_L01_00512D70(0x110024, 0);
            func_L01_00512D70(0x110025, 0);
            func_L01_00512D70(0x110026, 0);
            func_L01_00512D70(0x110027, 0);
            func_L01_00512D70(0x110028, 0);
            func_L01_00512D70(0x110029, 0);
            func_L01_00512D70(0x11002A, 0);
            func_L01_00512D70(0x11002B, 0);
        } else {
            ok = (u32)k < 8;
            if (ok && ((D_001426E0[0x54] >> k) & 1)) {
                if (D_001BBB18[buf[D_001D9058_sda] - 5] != 0) {
                    func_L01_00512FE8(0x11002B, func_0037DF98(0x14F0));
                } else {
                    func_L01_00512FE8(0x11002B, func_0037DF98(0x14F1));
                }
                if (ok && ((D_001426E0[0x51] >> k) & 1)) {
                    func_L01_00512FE8(0x110029, func_0037DF98(0x14F0));
                } else {
                    func_L01_00512FE8(0x110029, func_0037DF98(0x14F1));
                }
                func_0011B2E8(D_001E0BB0_sda, D_L01_001D9198, D_001426E0[0x4A + k]);
                func_L01_00512FE8(0x110027, D_001E0BB0_sda);
                t = D_001D55A0[k];
                if (t / 60 % 60 < 10) {
                    func_0011B2E8(D_001E0BC0_sda, D_L01_001D91A0, t / 3600 % 60, t / 60 % 60, t / 6 % 10);
                } else {
                    func_0011B2E8(D_001E0BC0_sda, D_L01_001D91B0, t / 3600 % 60, t / 60 % 60, t / 6 % 10);
                }
                func_L01_00512FE8(0x110025, D_001E0BC0_sda);
                func_L01_00512D70(0x11002C, 0);
                func_L01_00512D70(0x110024, 1);
                func_L01_00512D70(0x110025, 1);
                func_L01_00512D70(0x110026, 1);
                func_L01_00512D70(0x110027, 1);
                func_L01_00512D70(0x110028, 1);
                func_L01_00512D70(0x110029, 1);
                func_L01_00512D70(0x11002A, 1);
                func_L01_00512D70(0x11002B, 1);
            } else {
                func_L01_00512FE8(0x11002C, func_0037DF98(0x14F7));
                func_L01_00513548(0x11002C, 1.0f, 1.0f);
                func_L01_00512D70(0x11002C, 1);
                func_L01_00512D70(0x110024, 0);
                func_L01_00512D70(0x110025, 0);
                func_L01_00512D70(0x110026, 0);
                func_L01_00512D70(0x110027, 0);
                func_L01_00512D70(0x110028, 0);
                func_L01_00512D70(0x110029, 0);
                func_L01_00512D70(0x11002A, 0);
                func_L01_00512D70(0x11002B, 0);
            }
        }
        if (*(s32 *)(D_001D52FC + 0x1C4) & 0x80) {
            D_001D9104_sda = 1;
            func_0039FF28(4, 0, 0);
            func_L01_00513758(func_L01_0047B380());
            func_L01_005120B8(a0);
        }
        b2 = *(s32 *)(D_001D52FC + 0x1C4);
        if (b2 & 0x10) {
            func_0039FF28(4, 0, 0);
            func_L01_00513758(func_L01_0047B380());
            func_L01_005120B8(a0);
            return;
        }
        if (s5 != 0 && (b2 & 0x40)) {
            func_0039FF28(4, 0, 0);
            if (func_L01_00417EA0() != 0) {
                D_001D9170_sda = 1;
                return;
            }
            ops->f0(D_001D9058_sda);
            func_L01_00513758(func_L01_0047B380());
            func_L01_005120B8(a0);
            return;
        }
        func_L01_00512D70(0x11002D, 1);
        break;
    }
}
/* localdecomp:end func_L01_004922A0 */
