#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* localdecomp:start func_00381080 */
typedef unsigned int U128_00381080 __attribute__((mode(TI)));
extern u8 *D_1DA050;
extern u8 *D_001DA050;
__asm__(".extern D_1DA050, 16");
extern U128_00381080 D_001D7710;

void func_00381080(void) {
    *(u32 *)(D_1DA050 + 0) = 0x10000003;
    *(u32 *)(D_1DA050 + 4) = 0;
    *(u32 *)(D_1DA050 + 8) = 0;
    *(u32 *)(D_1DA050 + 12) = 0x50000003;
    { u8 *p = D_1DA050; D_1DA050 = p + 16; *(U128_00381080 *)(p + 16) = D_001D7710; }
    { u8 *p = D_1DA050; u8 *q = p + 16; D_1DA050 = q;
    *(unsigned long *)(p + 16) = 0x101;
    *(unsigned long *)(q + 8) = 0x80000000UL;
    *(unsigned long *)(q + 16) = 0x8FE86FF8UL;
    *(unsigned long *)(q + 24) = 0x8FE88FF8UL;
    }
    D_001DA050 = D_1DA050 + 32;
}
/* localdecomp:end func_00381080 */

/* localdecomp:start func_00381140 */
extern void func_00398128(s32, s32);

void func_00381140(void) {
    func_00398128(0, 0);
}
/* localdecomp:end func_00381140 */

/* localdecomp:start func_00381160 */
extern void func_003BBB68(s32);
extern void func_003B35E0(void *);
extern s32 func_003A12C0(s32, s32, s32, s32, u8 *);
extern u8 D_001E22C0[];

void func_00381160(void) {
    func_003BBB68(1);
    func_003B35E0(D_001E22C0);
    func_003A12C0(0x12, 1, 7, 0, 0);
}
/* localdecomp:end func_00381160 */

/* localdecomp:start func_003811A0 */
extern void func_003BBB68(s32);
extern s32 func_003A12C0(s32, s32, s32, s32, u8 *);

void func_003811A0(void) {
    func_003BBB68(1);
    func_003A12C0(0x12, 1, 8, 0, 0);
}
/* localdecomp:end func_003811A0 */

/* localdecomp:start func_003811D8 */
s32 func_003811D8(void) {
}
/* localdecomp:end func_003811D8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003811E0);

/* localdecomp:start func_003811E8 */
typedef struct { u8 pad[0x84]; s32 f84; } S_003811E8;
extern S_003811E8 D_00227580_003811E8;
extern s32 D_00143950_003811E8[];
extern s32 D_001D5C78_003811E8;
__asm__(".extern D_001D5C78_003811E8, 16");
extern s32 func_0011A264(s32, s32, s32);
extern s32 func_003F2740(s32, s32);
extern void *func_003AF470();
extern void func_003AB218(s32);

void func_003811E8(void) {
    func_0011A264(D_00227580_003811E8.f84, 0xCD, 0x40000);
    D_001D5C78_003811E8 = (s32)func_003AF470(func_003F2740(0x24F10, D_00227580_003811E8.f84), 0x40000);
    func_003AB218(D_00143950_003811E8[0]);
}
/* localdecomp:end func_003811E8 */
