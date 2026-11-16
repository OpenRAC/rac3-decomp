/* NTSC-U draft (Claude wave E): C of func_0012A950 as NTSC-U has it, with NTSC-U names and addresses.
 * near miss: 2 words differ on NTSC-U (the worker's best count) (NTSC-U twin "func_0012A950").
 * Study aid: it uses inline asm for EE instructions (cfc2.ni ctc2.ni nop sync.p), which matched C may not (nonmatching/README.md); plain C is still needed.
 * Worker's note: 2 diff with the file line (SN flags are right: leaf, no frame): VIF1 init (D1/FIFO regs 0x10003C10/0x10003C20 stores, COP2 control reg handshake cfc2/ctc2 $vi28 /= 0x200 then poll $vi29 & 0x100, ctc2 0x404, two lq/sq quads D_0013F8B0/D_0013F8C0 into ...
 */
#include "common.h"

/* localdecomp:start func_0012A950 */
typedef int u128_12A950 __attribute__((mode(TI)));
extern u128_12A950 D_0013F8B0;
extern u128_12A950 D_0013F8C0;
void func_0012A950(void) {
    s32 one;
    s32 v;
    one = 1;
    *(volatile u32 *)0x10003C10 = one;
    *(volatile u32 *)0x10003C20 = 2;
    v = 0;
    __asm__ __volatile__("sync");
    __asm__ __volatile__("cfc2.ni %0, $vi28\n\tnop" : "+r"(v));
    v |= 0x200;
    __asm__ __volatile__("ctc2.ni %0, $vi28" : : "r"(v));
    __asm__ __volatile__("sync.p");
    __asm__ __volatile__(
        ".set push\n\t"
        ".set noreorder\n"
        "1:\n\t"
        "cfc2.ni %0, $vi29\n\t"
        "nop\n\tnop\n\tnop\n\t"
        "andi %0, %0, 0x100\n\t"
        "bnez %0, 1b\n\t"
        "nop\n\t"
        ".set pop"
        : "=r"(v));
    v = 0x404;
    __asm__ __volatile__("ctc2.ni %0, $vi28\n\tnop" : : "r"(v));
    *(volatile u128_12A950 *)0x10005000 = D_0013F8B0;
    *(volatile u128_12A950 *)0x10005000 = D_0013F8C0;
    *(volatile u32 *)0x10003000 = one;
}
/* localdecomp:end func_0012A950 */
