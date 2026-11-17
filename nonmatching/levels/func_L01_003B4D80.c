/* NTSC-U draft (Claude wave K): C of func_L01_003B3580, the NTSC-U twin of func_L01_003B4D80, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 84 words differ on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division (S mode: the entry's -mno-split-addresses must be dropped)" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses") (NTSC-U twin "func_L01_003B3580", whose code is not the PAL one).
 * Worker's note: 84 diff words of 140 (80 structural; yours 141 insns vs retail 140) in S mode '-O2 -G8 -fopt-stack -mno-check-zero-division' -- the entry's '-mno-split-addresses' is WRONG for retail (it shows `lui $a0,0x1E; lw $a0,-0x440($a0)` and `lui $v0; addiu ...
 */
/* NEAR (84 diff words of 140; yours 141 insns vs retail 140): flags: the entry's '-mno-split-addresses' must go (retail is S mode: lui $a0 / lw $a0,-0x440($a0), lui $v0 + addiu $a2,$v0,lo; N mode gives lui $at forms) -> '-O2 -G8 -fopt-stack -mno-check-zero-division'. No div.s. Remaining: list-search loop layout at 0x10C-0x130 (retail: found block falls through after the compare, `b` back via bnel delay lw 0x58), the table-scan loop 0x170-0x1E0, and the arg-order/delay-slot details of the first sprintf call. */
#include "common.h"

extern s32 func_0011B2E8(char *, char *, ...);
extern void func_L01_00512FE8(s32, char *);
extern s32 func_L01_003B3018(void *, void *);

/* localdecomp:start func_L01_003B3580 */
extern s32 D_L01_001DFBC0[];
__asm__(".extern D_L01_001DFBC0, 16");
extern u8 *D_001DE674_sda;
__asm__(".extern D_001DE674_sda, 4");
extern s32 D_001E00D8_sda;
__asm__(".extern D_001E00D8_sda, 4");
extern u8 *D_L01_001E009C;
extern u16 *D_L01_0021DEA0[];
extern char D_L01_001DE760[];
extern char D_L01_001DE768[];
extern char D_L01_001DE778[];
extern char D_L01_001DE780[];
extern char D_001E21B0_sda[4];
extern char D_001E21F0_sda[4];

void func_L01_003B3580(void *a0, u8 *a1) {
    s32 t;
    s32 rem;
    s32 mins;
    s32 secs;
    s32 diff;
    s32 idx;
    u8 *n;
    u8 *s;
    u16 *p;
    char *pad1;
    char *pad2;

    t = *(s32 *)(a1 + 0x24);
    if (t == 0) {
        return;
    }
    rem = t * 60 - (D_L01_001DFBC0[0] - *(s32 *)(*(u8 **)(*(u8 **)(a1 + 8) + 0x68) + 0x60));
    if (!(-1 < rem)) {
        rem = 0;
    }
    secs = rem / 60 % 60;
    mins = rem / 3600;
    if (rem % 60 != 0) {
        secs = secs + 1;
        if (!(secs < 60)) {
            mins = mins + 1;
            secs = 0;
        }
    }
    func_0011B2E8(D_001E21B0_sda, D_L01_001DE768, mins < 10 ? D_L01_001DE778 : D_L01_001DE760, mins,
                  secs < 10 ? D_L01_001DE778 : D_L01_001DE760, secs);
    func_L01_00512FE8(0x140004, D_001E21B0_sda);
    if (func_L01_003B3018(a0, a1) == 0) {
        return;
    }
    diff = 0;
    if (D_001DE674_sda != 0) {
        n = D_001DE674_sda;
        while (n != 0) {
            s = *(u8 **)(n + 0x68);
            if (*(s32 *)s != 0x1D75) {
                n = *(u8 **)(s + 0x58);
            } else {
                diff = *(s32 *)(s + 0xC0) - *(s32 *)(s + 0xC4);
                break;
            }
        }
    } else {
        idx = *(s32 *)(a1 + 0xC);
        if (idx == -1) {
            func_L01_00512FE8(0x140007, D_L01_001DE778);
            return;
        }
        p = D_L01_0021DEA0[idx];
        for (;;) {
            if ((idx & 0xFF) == 0xFF || D_001E00D8_sda < idx || p == 0) {
                break;
            }
            if (p[-1] >= 0x8000 && p != D_L01_0021DEA0[idx]) {
                break;
            }
            n = D_L01_001E009C + ((*p & 0x7FFF) << 8);
            if (n == 0) {
                break;
            }
            s = *(u8 **)(n + 0x68);
            if (*(s32 *)s == 0x1D75) {
                diff = *(s32 *)(s + 0xC0) - *(s32 *)(s + 0xC4);
                break;
            }
            p++;
        }
    }
    func_0011B2E8(D_001E21F0_sda, D_L01_001DE780, diff);
    func_L01_00512FE8(0x140007, D_001E21F0_sda);
}
/* localdecomp:end func_L01_003B3580 */
