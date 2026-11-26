#include "common.h"
/* func_L39_005771D0 (k4 Sonnet first pass, 1436 B, 15 places): NEAR, 226 differing rows of 363 by the check listing
 * (all but ~12 are offset/shift noise: an LCS alignment of retail vs this C matches 286/363 instructions, 79%).
 * Flags: file's own (-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as), checked at place 39 only.
 * Equal: whole loop body from the 0xBF store through the switch (needs the `case 3:` fall-through label
 *   before `default:` to get retail's compare tree beq 2 / slti 3 / bne 1), the three 0x58B2C8 branches with
 *   their shared jal, all the timer/0x241120 conditionals, the epilogue loop test (while form, D_2914 via gp).
 * Differs: (1) prologue: retail has two dead insns before the first call (`lw $v1,D_2914`, `addiu $v0,$zero,1`)
 *   and so different register numbers (C9F4 in $a2, not $t6); source store order of D_CA58/BA40/BA50 does not
 *   change the output (tried all 6 orders of the CA58 group). (2) the first 0x240304 read in the `D_2914 == 1`
 *   path: this C fills the bne delay slot with `lw $a1,-0x7cbc($gp)`; retail fills with `move $a0,$zero` and
 *   does lui/lw after. Tried: .extern size 16 (no effect), section(".data") (lui hoisted into $s regs), array
 *   [1] at D_00240300 (address hoisted). (3) `ori $a1` / `addiu $a0,0x47` order of the first func_005FD068 call.
 * Prototypes: all inferred from call sites; func_L39_005FCF18 is K&R () because it is called with 4 and 1 args;
 *   func_L39_0058B2C8 takes a 5th arg unsigned long 0x80000000 ($t0). Confidence: structure high, the two types
 *   of D_BA40/D_BA50 (void *[4]) medium.
 * Next: find what emits the dead `lw $v1,2914` + `li $v0,1` before the first jal (loop-entry test duplication?),
 *   then re-try the 0x240304 slot fill; places 40..53 not checked. */
/* localdecomp:start func_L39_005771D0 */
extern s32 D_L39_00242914;
extern s32 D_L39_0024C9F4;
extern s32 D_L39_0024CA58[2];
extern s32 D_L39_0024CA20;
extern void *D_L39_0024BA40[4];
extern void *D_L39_0024BA50[4];
extern s32 D_L39_00241128;
extern s32 D_L39_00242A00;
extern s32 D_L39_0024111C;
extern s32 D_L39_0024B9C4;
extern s32 D_L39_0024B9C8;
extern s32 D_L39_0024BB44;
extern s32 D_L39_00240304;
extern unsigned long D_L39_00240200;
extern s32 *D_L39_00241120;
extern s32 D_001A5810[];
extern s32 D_L39_0024B9C8;
extern s32 D_L39_00242A00;
extern void func_L39_00576D38(void);
extern void func_L39_00576D58(void);
extern void func_L39_00576D78(void);
extern void func_L39_00576D98(void);
extern void func_L39_005FCF18();
extern void func_L39_005FCD30(void);
extern void func_L39_005FCD78(void);
extern void func_L39_005FCDF8(void);
extern void func_00193590(void);
extern void func_L39_0058CC68(void);
extern void func_L39_00576DB8(s32, s32 *);
extern void func_L39_00576E48(s32, s32, s32, s32);
extern void func_L39_00591B88(void);
extern void func_L39_0057C260(s32);
extern void func_L39_00588A08(s32);
extern void func_L39_00587E80(void);
extern void func_L39_005FD068(s32, s32);
extern void func_L39_0058B2C8(s32, s32, s32, s32, unsigned long);
extern void func_L39_00589538(s32);
extern s32 func_L39_005BF780(s32);
extern void func_L39_005D69C0(s32);
extern void func_L39_00589668(void);
extern void func_L39_005BF758(void);
extern void func_L39_00577148(void);
extern void func_00139E08(s32);
extern void func_L39_0057B1C0();
extern void func_L39_005BF490(void);
extern void func_L39_00597F88(void);
extern void func_L39_00598300(s32);
extern void func_L39_00597E70(void);

void func_L39_005771D0(void) {
    s32 a[4];
    s32 b[3];
    D_L39_0024CA58[0] = D_L39_0024C9F4;
    D_L39_0024CA20 = 0x8000;
    D_L39_0024CA58[1] = D_L39_0024C9F4 + 0x80000;
    D_L39_0024BA40[0] = func_L39_00576D38;
    D_L39_0024BA40[1] = func_L39_00576D58;
    D_L39_0024BA40[2] = func_L39_00576D78;
    D_L39_0024BA40[3] = func_L39_00576D98;
    D_L39_0024BA50[0] = 0;
    D_L39_0024BA50[1] = 0;
    D_L39_0024BA50[2] = 0;
    D_L39_0024BA50[3] = 0;
    func_L39_005FCF18(1, D_L39_0024BA50, func_L39_00576D58, func_L39_00576D78);
    func_L39_005FCD30();
    D_L39_00242A00 = 1;
    while (D_L39_00241128 == 0 && D_L39_00242914 != 0) {
            D_L39_00240200 += *(volatile u32 *)0x10000800;
            *(volatile u32 *)0x10000800 = 0;
            D_L39_0024111C = 1;
            func_00193590();
            func_L39_0058CC68();
            D_L39_0024B9C4 = 0xBF;
            switch (D_L39_00242914) {
            case 1:
                func_L39_00576DB8(2, a);
                func_L39_00576E48(a[0], a[0] + 1, 1, 0);
                func_L39_00591B88();
                func_L39_00576E48(a[1], a[1] + 1, 0, 1);
                break;
            case 2:
                func_L39_00576DB8(3, b);
                func_L39_00576E48(b[0], b[0] + 3, 1, 0);
                func_L39_00591B88();
                func_L39_00576E48(b[1], b[1] + 3, 0, 0);
                func_L39_00591B88();
                func_L39_00576E48(b[2], b[2] + 3, 0, 1);
                break;
            case 3:
            default:
                func_L39_00576DB8(4, a);
                func_L39_00576E48(a[0], a[0] + 6, 1, 0);
                func_L39_00591B88();
                func_L39_00576E48(a[1], a[1] + 6, 0, 0);
                func_L39_00591B88();
                func_L39_00576E48(a[2], a[2] + 6, 0, 0);
                func_L39_00591B88();
                func_L39_00576E48(a[3], a[3] + 6, 0, 1);
                break;
            }
            func_L39_0057C260(0);
            func_L39_00588A08(0);
            func_L39_00587E80();
            func_L39_005FD068(0x47, 0x33001);
            if (D_L39_00242914 == 1) {
                func_L39_0058B2C8(0, D_L39_00240304 >> 1, 0x155, 0x200, 0x80000000);
                func_L39_0058B2C8(D_L39_00240304 >> 1, D_L39_00240304, 0, 0xAA, 0x80000000);
                func_L39_0058B2C8((D_L39_00240304 >> 1) - 1, D_L39_00240304 >> 1, 0, 0x200, 0x80000000);
            } else if (D_L39_00242914 == 2) {
                func_L39_0058B2C8(D_L39_00240304 >> 1, D_L39_00240304, 0x100, 0x200, 0x80000000);
                func_L39_0058B2C8(0, D_L39_00240304, 0xFF, 0x100, 0x80000000);
                func_L39_0058B2C8((D_L39_00240304 >> 1) - 1, D_L39_00240304 >> 1, 0, 0x200, 0x80000000);
            } else {
                func_L39_0058B2C8(0, D_L39_00240304, 0xFF, 0x100, 0x80000000);
                func_L39_0058B2C8((D_L39_00240304 >> 1) - 1, D_L39_00240304 >> 1, 0, 0x200, 0x80000000);
            }
            func_L39_00589538(0);
            if (func_L39_005BF780(3) == 0) {
                func_L39_005FD068(0x47, 0x33001);
                func_L39_00591B88();
                func_L39_005D69C0(4);
            }
            func_L39_00589668();
            func_L39_005FCF18(1);
            func_L39_005FCDF8();
            func_L39_005FCD78();
            func_L39_005BF758();
            func_L39_00577148();
            if (*D_L39_00241120 >= 3) {
                D_L39_00242A00 ^= 1;
            }
            func_L39_0057C260(0);
            if (*(volatile s32 *)0x10000800 < (D_001A5810[0] != 0 ? 0x2D00 : 0x2580)) {
                func_00139E08(0);
            }
            func_L39_00577148();
            if (*D_L39_00241120 >= 3) {
                D_L39_00242A00 ^= 1;
            }
            if (*D_L39_00241120 >= 2) {
                func_L39_0057B1C0(D_001A5810[0]);
            }
            if ((D_001A5810[0] != 0 ? 0x5A00 : 0x4B00) < *(volatile s32 *)0x10000800) {
                D_L39_0024111C = 2;
                func_L39_0057C260(0);
                func_L39_00577148();
                if (*D_L39_00241120 >= 3) {
                    D_L39_00242A00 ^= 1;
                }
                if (*D_L39_00241120 >= 2) {
                    func_L39_0057B1C0();
                }
            }
            D_L39_0024BB44 = D_L39_0024BB44 + 1;
            func_L39_005BF490();
            func_L39_00597F88();
            func_L39_00598300(1);
            func_L39_00597E70();
            func_L39_005FCF18(1);
            func_00139E08(0);
            D_L39_0024B9C8 = D_L39_0024B9C8 + 1;
            func_L39_005FCDF8();
            func_L39_005FCD78();
    }
}
/* localdecomp:end func_L39_005771D0 */
