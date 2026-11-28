/* c51 (wave 14c): r67's near unchanged, re-measured under the line "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as"
 * (L01_00480800.c's, the next file): tools/check.py --flags=@ps2as --target level_01 184 diff, 97 aligned rows
 * (wc51/func_L01_00480170/try-01.log, wc51/aln.py). Groups left: the init block's li.s constants (registers/order of the
 * 0x1C-0x28 stores), the row loop's saved registers (retail s2 row, s3 i, s4 i*24, s5 &arr[i].arg giv set before the
 * func_003BABB0 calls, s6 base, s7 0x11, fp; the else arm's arg address as s4 + D_L01_002EA238, not the giv), and the
 * final 19-byte copy: retail counts down v1 = 18 with `bne v1, -1` and pointer givs; a pointer for-loop gives the bgez
 * form (try-03.log, 91 aligned / 220 positional), while (n--) keeps a copy of the old count (try-02.log). */
#include "common.h"
/* PAL near miss (wave 14, r67), first C from the retail assembly (types and flow from nonmatching/functional/):
 * 280 diffs with the file's own line, 184 with @ps2as added (tools/check.py --flags @ps2as, wr67/func_L01_00480170.cutline.log).
 * Line: retail's non-trivial float constants are Ps2EeAs li.s (lui/ori/mtc1, e.g. 0.79f = 0x3F4A3D71); without @ps2as GNU as
 * loads them from .lit4 through $gp, which shifts every later word. NEEDS '-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as'
 * (the line of L01_00480800.c, which starts right where this function ends; this function is the last of L01_0047FDC0.c and
 * starts 8-aligned at 0x00480170, so the boundary can move to 0x00480170; the file's other blocks have no float constant).
 * Under @ps2as the code has retail's shape: calls, the gp-relative globals (.extern hints), func_L01_00518D40 (retail's
 * 0x518D40), D_00160C40 as a struct, the init stores (in ascending offsets the scheduler gives retail's order), the row
 * loop (row pointer for the row fields, D_L01_002EA230[i] for the check test and the two arg prints, so the check is reloaded
 * as in retail). Still differs there: the saved-register permutation of the loop (row/i/offset/arg pointers), the order and
 * registers of the four init constants 0.45/0.053/0.11/0.89, and the preheader's &D_L01_002EA230[0].arg (retail lui/addiu of
 * the symbol+8, here base+8). */

/* localdecomp:start func_L01_00480170 */
typedef struct {
    s32 strId;
    s32 type;
    s32 arg;
    u8 on;
    u8 on2;
    u8 pad[2];
    s32 (*check)(s32);
    s32 pad14;
} OptRow_00480170;
extern u8 D_L01_00233A00[];
extern OptRow_00480170 D_L01_002EA230[];
typedef struct { u8 pad0[0x694]; s32 f694; u8 pad698[0x10E0 - 0x698]; u8 f10E0[1]; } S_160C40_00480170;
extern S_160C40_00480170 D_00160C40;
extern u8 D_001D5468[];
extern u8 D_001D5480[];
extern s32 D_L01_001E06A8;
extern s32 D_L01_001D8318;
extern f32 D_L01_001D831C;
extern f32 D_L01_001D8320;
extern f32 D_L01_001D8324;
extern f32 D_L01_001D8328;
extern f32 D_L01_001D832C;
extern f32 D_L01_001D8330;
extern f32 D_L01_001D8334;
extern f32 D_L01_001D8338;
extern f32 D_L01_001D833C;
extern f32 D_L01_001D8340;
extern f32 D_L01_001D8344;
extern f32 D_L01_001D8348;
extern f32 D_L01_001D834C;
__asm__(".extern D_L01_001E06A8, 4");
__asm__(".extern D_L01_001D8318, 4");
__asm__(".extern D_L01_001D831C, 4");
__asm__(".extern D_L01_001D8320, 4");
__asm__(".extern D_L01_001D8324, 4");
__asm__(".extern D_L01_001D8328, 4");
__asm__(".extern D_L01_001D832C, 4");
__asm__(".extern D_L01_001D8330, 4");
__asm__(".extern D_L01_001D8334, 4");
__asm__(".extern D_L01_001D8338, 4");
__asm__(".extern D_L01_001D833C, 4");
__asm__(".extern D_L01_001D8340, 4");
__asm__(".extern D_L01_001D8344, 4");
__asm__(".extern D_L01_001D8348, 4");
__asm__(".extern D_L01_001D834C, 4");
extern char D_L01_001D8350[];
extern char D_L01_001D8358[];
extern char D_L01_001D8360[];
extern void func_003B9298(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32);
extern s32 func_L01_00518D40(s32);
extern s32 func_003E8348(s32, s32);
extern s32 func_003E9138(s32, s32, f32, f32, f32, f32, s32);
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern void *func_003BB3A8(s32);
extern void *func_003B42F8(s32);
extern s32 func_003B4528(void *, s32, s32, s32, s32);
extern s32 func_003E8710(s32, s32);
extern s32 func_003E8630(s32, s32);
extern s32 func_0011A264(void *, s32, s32);
extern void func_L01_0047DE68(void);
extern s32 func_L01_0047DAE0(void);
extern s32 func_003BB118(s32);
extern s32 func_003B9BD0(s32);
extern s32 func_003B9C68(s32, void *);
extern void func_003BABB0(s32, f32, f32, f32, f32, f32, s32);
extern void func_003BABD0(s32, f32, f32, f32, f32);
extern s32 func_003B9E30(s32, s32, s32);
extern void func_L01_00498948(s32, s32, s32);
extern s32 func_0011B2E8(char *, ...);
extern void func_003BA358(s32, s32, s32, s32);
extern s32 func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E8A08(s32, s32, s32);

void func_L01_00480170(void) {
    char *dst;
    u8 *s;
    u32 i;
    s32 on;
    s32 sub;
    s32 n;
    s32 off;
    OptRow_00480170 *row;

    func_003B9298(0x10, 0xD000B, 0xD0002, 0xD0003, 0xD0004, 0xD0000, 0xD0001, 0xD0005, 0xD0008,
                  func_00381FF0(0x1C1), 0xD0006, 0xFF, 0xD0007, 0x177, 8.5f);
    func_L01_00518D40(0x520000);
    func_003E8348(0x11, 0x520000);
    func_003E9138(0x520003, 0x80808080, D_L01_001D831C, D_L01_001D8320, D_L01_001D8324, D_L01_001D8328, 1);
    func_003E8FE8(0x520004, func_00381FF0(0x1C1), 0x8066CCFF, D_L01_001D8344, D_L01_001D8348, 1.0f, 1.0f);
    func_003E8FE8(0x520005, func_00381FF0(0x1BF), 0x8066CCFF, D_L01_001D834C, D_L01_001D8348, 1.0f, 1.0f);
    D_L01_001D8318 = (s32)func_003BB3A8(0);
    func_003B4528(func_003B42F8(0), D_L01_001D8318, 0, D_00160C40.f694, (s32)D_00160C40.f10E0);
    func_003E8710(0x520003, (s32)func_003B42F8(0));
    func_003E8630(0x520000, 0x520003);
    func_003E8630(0x520000, 0x520004);
    func_003E8630(0x520000, 0x520005);
    if (D_L01_001E06A8 == 0) {
        s = D_L01_00233A00;
        func_0011A264(s, 0, 0x54);
        *(s32 *)(s + 0x8) = 0x14;
        *(s32 *)(s + 0xC) = 7;
        *(s32 *)(s + 0x10) = 7;
        *(s32 *)(s + 0x14) = 2;
        *(f32 *)(s + 0x18) = 1.0f;
        *(f32 *)(s + 0x1C) = 0.45f;
        *(f32 *)(s + 0x20) = 0.053f;
        *(f32 *)(s + 0x24) = 0.11f;
        *(f32 *)(s + 0x28) = 0.89f;
        *(f32 *)(s + 0x34) = 0.35f;
        *(f32 *)(s + 0x38) = 0.35f;
        D_L01_001E06A8 = 1;
        *(f32 *)(s + 0x44) = 0.75f;
        *(f32 *)(s + 0x48) = 0.75f;
    }
    func_L01_0047DE68();
    *(s32 *)D_L01_00233A00 = func_L01_0047DAE0();
    *(s32 *)(D_L01_00233A00 + 4) = func_003BB118(0);
    func_003B9C68(func_003B9BD0(0), D_L01_00233A00);
    func_003BABB0(func_003B9BD0(0), 0.5f, 0.79f, 0.045f, 0.38f, 0.35f, 1);
    func_003BABD0(func_003B9BD0(0), 0.5f, 0.58f, 0.81f, 0.56f);
    row = D_L01_002EA230;
    for (i = 0; i < 7; i++, row++) {
        if (D_L01_002EA230[i].check != 0 && row->check(row->arg) != 0) {
            dst = (char *)func_003B9E30(func_003B9BD0(0), 0, i);
            func_0011B2E8(dst, D_L01_001D8350, func_00381FF0(row->strId));
            if (row->type == 0x11) {
                dst = (char *)func_003B9E30(func_003B9BD0(0), 1, i);
                func_0011B2E8(dst, (char *)func_00381FF0(0x16FB));
            } else {
                dst = (char *)func_003B9E30(func_003B9BD0(0), 1, i);
                func_0011B2E8(dst, D_L01_001D8358, D_L01_002EA230[i].arg);
            }
            row->on = 1;
            on = D_001D5468[row->type] != 0;
            sub = 3;
            if (!on) {
                sub = 0;
            }
            row->on2 = on;
            func_L01_00498948(func_003B9BD0(0), i, sub);
        } else {
            dst = (char *)func_003B9E30(func_003B9BD0(0), 0, i);
            func_0011B2E8(dst, D_L01_001D8350, func_00381FF0(0x16CE));
            if (row->type == 0x11) {
                dst = (char *)func_003B9E30(func_003B9BD0(0), 1, i);
                func_0011B2E8(dst, (char *)func_00381FF0(0x16CE));
            } else {
                dst = (char *)func_003B9E30(func_003B9BD0(0), 1, i);
                func_0011B2E8(dst, D_L01_001D8360, D_L01_002EA230[i].arg, func_00381FF0(0x1BF));
            }
            row->on = 0;
            row->on2 = 0;
            func_L01_00498948(func_003B9BD0(0), i, 1);
        }
        }
    func_003BA358(func_003B9BD0(0), 0, 1, 3);
    func_003BA358(func_003B9BD0(0), 1, 3, 3);
    func_003E9270(0x520001, 0x332299DE, D_L01_001D8334, D_L01_001D8338, D_L01_001D833C, D_L01_001D8340, 0.0035f, 0.006f);
    func_003E9270(0x520002, 0x332299DE, D_L01_001D831C, D_L01_001D832C, D_L01_001D8324, D_L01_001D8330, 0.0035f, 0.006f);
    func_003E8A08(0x520000, 0x520001, 0x520002);
    for (n = 0; n < 19; n++) {
        D_001D5480[n] = D_001D5468[n];
    }
}
/* localdecomp:end func_L01_00480170 */
