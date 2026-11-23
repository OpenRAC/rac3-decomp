/* near miss (round 19 worker J5B): 14 aligned rows of 300 words, 14 raw diffs (same length as retail) with the file's flags. The level's main loop:
 * the callback tables at D_L01_001DF9C0 / 001DF9D0, the 64-bit timer accumulate (D_001D4AC0 += timer; timer = 0), three arms on D_L01_001D6698 that each run
 * func_L01_003F17C0 and a chain of func_L01_003F1850 calls (written out, no loop), the three-way func_0038AF30 frame (`if == 1 / == 2 / else`), the two timer-limit
 * tests and the frame counters. Callees and same-file symbols use the `_003F19B8` alias scheme (the same file defines func_L01_003F1740 .. 003F1850); no other
 * level was checked.
 * What fixed most (44 -> 14): the first chain is a `switch` with `case 3: default:` as one body (retail's tree: root 2, left child 1, the right child's compare
 * disappears), the limit idiom of func_L01_003F1600 (`limit = 0x2580; ... if (c != 0) limit = 0x2D00;` gives movn) with `t = timer;` between the limit and the flag read,
 * the flag in its own variable `c`, D_001D4BC4 as a scalar with `.extern ..., 16`, and the FIRST read of D_001D4BC4 (arm 1's first func_0038AF30) through a per-use
 * alias that is an UNSIZED ARRAY (`D_001D4BC4_003F19B8a[0]`): sched then keeps `move $a0,$zero` first in arm 1 and reorg puts it into the first `bne`'s delay slot, as
 * retail (with the scalar the `lw $a1,D` macro heads the block, takes the slot, is written $gp-relative there and makes the default arm's own load redundant).
 * Left (14 rows): (1) the unsized array gives `lui $v0,0x1d; lw $a1,0x4bc4($v0)` where retail has `lui $a1; lw $a1,..($a1)` (the same register; 2 rows), and the
 * second bne's slot now takes the default arm's `lw $a1,D` ($gp form; retail: `addiu $a2,$zero,0xff`) with `lui/lw` missing at the default arm (4 rows; an unsized
 * alias at that use as well: 15 aligned, worse); (2) the registers of the two limit tests: retail has flag $a0, limit $v1, other constant $v0, timer $a1 (here flag $a1,
 * timer $a0: 8 rows; declaration order, statement order, block-scoped locals, a ternary: no change). It contains a `switch` without a jump table (compare tree). */
#include "common.h"

/* localdecomp:start func_L01_003F19B8 */
extern void (*D_L01_001DF9C0_003F19B8[])(void);
extern void (*D_L01_001DF9D0_003F19B8[])(void);
extern void func_L01_003F1740_003F19B8(void);
extern void func_L01_003F1760_003F19B8(void);
extern void func_L01_003F1780_003F19B8(void);
extern void func_L01_003F17A0_003F19B8(void);
extern void func_L01_003F17C0_003F19B8(s32, s32 *);
extern void func_L01_003F1850_003F19B8(s32, s32, s32, s32);
extern void func_L01_003F19B0_003F19B8(void);
extern void func_L01_003F6F10_003F19B8(s32);
extern void func_L01_00403168_003F19B8(s32);
extern void func_L01_00407950_003F19B8(void);
extern void func_L01_0045A550_003F19B8(void);
extern void func_L01_00459F60_003F19B8(void);
extern void func_003A92F0(s32);
extern void func_003A9108(void);
extern void func_0013B620(void);
extern void func_0038E138(void);
extern void func_00387F68(void);
extern void func_003A9440(s32, unsigned long);
extern void func_0038AF30(s32, s32, s32, s32, unsigned long);
extern void func_00389240(s32);
extern s32 func_003A0EA8(s32);
extern void func_003B3158(s32);
extern void func_00389370(void);
extern void func_003A91D0(void);
extern void func_003A9150(void);
extern void func_003923D0(void);
extern void func_00392748(s32);
extern void func_003922B8(void);
extern s32 func_0012C908(s32);
extern s32 D_L01_001D6694;
__asm__(".extern D_L01_001D6694, 16");
extern s32 D_L01_001D6698;
__asm__(".extern D_L01_001D6698, 16");
extern s32 D_001D52F4;
extern s32 D_L01_001DF944;
extern s32 D_L01_001DF948;
extern s32 D_L01_001DFB48;
extern unsigned long D_001D4AC0;
__asm__(".extern D_001D4AC0, 16");
extern s32 D_001D4BC4;
extern s32 D_001D4BC4_003F19B8a[];
__asm__(".extern D_001D4BC4, 16");
extern s32 D_00143950[];

void func_L01_003F19B8(void) {
    s32 out[8];
    s32 limit;
    s32 t;
    s32 c;

    D_L01_001DF9C0_003F19B8[0] = func_L01_003F1740_003F19B8;
    D_L01_001DF9C0_003F19B8[1] = func_L01_003F1760_003F19B8;
    D_L01_001DF9C0_003F19B8[2] = func_L01_003F1780_003F19B8;
    D_L01_001DF9C0_003F19B8[3] = func_L01_003F17A0_003F19B8;
    D_L01_001DF9D0_003F19B8[0] = 0;
    D_L01_001DF9D0_003F19B8[1] = 0;
    D_L01_001DF9D0_003F19B8[2] = 0;
    D_L01_001DF9D0_003F19B8[3] = 0;
    func_003A92F0(1);
    func_003A9108();
    while (D_L01_001D6694 == 0 && D_L01_001D6698 != 0) {
        D_001D4AC0 += *(volatile u32 *)0x10000800;
        *(volatile u32 *)0x10000800 = 0;
        D_001D52F4 = 1;
        func_0013B620();
        func_L01_00407950_003F19B8();
        D_L01_001DF944 = 0xBF;
        switch (D_L01_001D6698) {
        case 1:
            func_L01_003F17C0_003F19B8(2, &out[0]);
            func_L01_003F1850_003F19B8(out[0], out[0] + 1, 1, 0);
            func_0038E138();
            func_L01_003F1850_003F19B8(out[1], out[1] + 1, 0, 1);
            break;
        case 2:
            func_L01_003F17C0_003F19B8(3, &out[4]);
            func_L01_003F1850_003F19B8(out[4], out[4] + 3, 1, 0);
            func_0038E138();
            func_L01_003F1850_003F19B8(out[5], out[5] + 3, 0, 0);
            func_0038E138();
            func_L01_003F1850_003F19B8(out[6], out[6] + 3, 0, 1);
            break;
        case 3:
        default:
            func_L01_003F17C0_003F19B8(4, &out[0]);
            func_L01_003F1850_003F19B8(out[0], out[0] + 6, 1, 0);
            func_0038E138();
            func_L01_003F1850_003F19B8(out[1], out[1] + 6, 0, 0);
            func_0038E138();
            func_L01_003F1850_003F19B8(out[2], out[2] + 6, 0, 0);
            func_0038E138();
            func_L01_003F1850_003F19B8(out[3], out[3] + 6, 0, 1);
            break;
        }
        func_L01_003F6F10_003F19B8(0);
        func_L01_00403168_003F19B8(0);
        func_00387F68();
        func_003A9440(0x47, 0x33001);
        if (D_L01_001D6698 == 1) {
            func_0038AF30(0, D_001D4BC4_003F19B8a[0] >> 1, 0x155, 0x200, 0x80000000UL);
            func_0038AF30(D_001D4BC4 >> 1, D_001D4BC4, 0, 0xAA, 0x80000000UL);
            func_0038AF30((D_001D4BC4 >> 1) - 1, D_001D4BC4 >> 1, 0, 0x200, 0x80000000UL);
        } else if (D_L01_001D6698 == 2) {
            func_0038AF30(D_001D4BC4 >> 1, D_001D4BC4, 0x100, 0x200, 0x80000000UL);
            func_0038AF30(0, D_001D4BC4, 0xFF, 0x100, 0x80000000UL);
            func_0038AF30((D_001D4BC4 >> 1) - 1, D_001D4BC4 >> 1, 0, 0x200, 0x80000000UL);
        } else {
            func_0038AF30(0, D_001D4BC4, 0xFF, 0x100, 0x80000000UL);
            func_0038AF30((D_001D4BC4 >> 1) - 1, D_001D4BC4 >> 1, 0, 0x200, 0x80000000UL);
        }
        func_00389240(0);
        if (func_003A0EA8(3) == 0) {
            func_003A9440(0x47, 0x33001);
            func_0038E138();
            func_003B3158(4);
        }
        func_00389370();
        func_003A92F0(1);
        func_003A91D0();
        func_003A9150();
        func_L01_0045A550_003F19B8();
        func_L01_003F19B0_003F19B8();
        func_L01_003F6F10_003F19B8(0);
        limit = 0x2580;
        t = *(volatile s32 *)0x10000800;
        c = D_00143950[0];
        if (c != 0) {
            limit = 0x2D00;
        }
        if (t < limit) {
            func_0012C908(0);
        }
        func_L01_003F19B0_003F19B8();
        limit = 0x4B00;
        t = *(volatile s32 *)0x10000800;
        c = D_00143950[0];
        if (c != 0) {
            limit = 0x5A00;
        }
        if (limit < t) {
            D_001D52F4 = 2;
            func_L01_003F6F10_003F19B8(0);
            func_L01_003F19B0_003F19B8();
        }
        D_L01_001DFB48 += 1;
        func_L01_00459F60_003F19B8();
        func_003923D0();
        func_00392748(1);
        func_003922B8();
        func_003A92F0(1);
        func_0012C908(0);
        D_L01_001DF948 += 1;
        func_003A91D0();
        func_003A9150();
    }
}
/* localdecomp:end func_L01_003F19B8 */
