#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 382780.c's earlier functions (tools/port_from_us.py) */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_37E0F0;
typedef int Q_37E0F0 __attribute__((mode(TI)));
extern u8 *D_001D9A20;
extern void func_0038D3E0_00382760(void *, void *, void *);

/* localdecomp:start func_00382848 */
extern s32 func_0013D3E0(void);
s32 func_00382848(s32 a) {
    return func_0013D3E0() % a;
}
/* localdecomp:end func_00382848 */

/* localdecomp:start func_00382878 */
extern s32 func_0013D3E0(void);
s32 func_00382878(s32 lo, s32 hi) {
    return func_0013D3E0() % (hi - lo + 1) + lo;
}
/* localdecomp:end func_00382878 */

/* localdecomp:start func_003828C0 */
extern s32 func_13D3E0(void);
f32 func_003828C0(f32 a, f32 b) {
    return a + (f32)func_13D3E0() * (b - a) * (1.0f / 32768.0f);
}
/* localdecomp:end func_003828C0 */

extern s32 func_0013D3E0(void);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00382918);

/* localdecomp:start func_00382960 */
extern f32 func_00382918(void);
extern f32 func_003828C0(f32, f32);
extern void func_00382B40(void *, f32, f32, f32);
void func_00382960(s32 a, f32 x, f32 y) {
    f32 p = func_00382918();
    f32 q = func_00382918();
    func_00382B40(a, func_003828C0(x, y), p, q);
}
/* localdecomp:end func_00382960 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003829D8);

extern s32 D_001D9A28_003829F8[2];
extern s32 D_001D9A30_003829F8[2];
extern s32 D_001D9D08_003829F8;
extern f32 func_0038D478(f32);
extern void func_0038DFB8(s32, s32, f32);

/* localdecomp:start func_00382B40 */
extern f32 func_0038D478(f32);
extern f32 func_0038D490(f32);

void func_00382B40(void *arg0, f32 fparg0, f32 fparg1, f32 fparg2) {
    f32 temp_f22;

    temp_f22 = func_0038D478(fparg2);
    (*(f32 *)((u8 *)(arg0) + 0)) = (f32) (func_0038D478(fparg1) * fparg0 * temp_f22);
    (*(f32 *)((u8 *)(arg0) + 4)) = (f32) (func_0038D490(fparg1) * fparg0 * temp_f22);
    (*(f32 *)((u8 *)(arg0) + 8)) = (f32) (func_0038D490(fparg2) * fparg0);
}
/* localdecomp:end func_00382B40 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00382BD0);

typedef struct { u8 pad[0x424]; f32 f424; f32 f428; f32 f42C; f32 f430; f32 f434; u8 b438; u8 b439; u16 h43A; f32 f43C; f32 f440; u8 pad2[0x1C]; } E_0037E568;
extern E_0037E568 D_00222480_00382BF0[];
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00382BF0);

typedef struct { u8 pad[0x424]; f32 f424; f32 f428; f32 f42C; f32 f430; f32 f434; u8 b438; u8 b439; s16 h43A; f32 f43C; f32 f440; u8 pad2[0x1C]; } E_0037E630;
extern E_0037E630 D_00222480_00382CB8[];
extern f32 D_002259B0[];
extern void func_00383038(f32 *, f32, f32, f32, f32, f32);
extern s32 func_0038CEE0(void *);
extern f32 func_0038D478(f32);
extern f32 func_0038D490(f32);
extern f32 func_003C3FA0(f32, f32, f32);
extern void func_003877A0();
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00382CB8);

LINKER_REMNANT("asm/boot_elf/remnants", func_00382E50);

/* localdecomp:start func_00382E60 */
void func_0038D108(void *, void *, s32);
typedef struct { u8 pad0[0x50]; void *f50; u8 pad54[0x460 - 0x54]; } S_00222500_0037E7D8;
extern S_00222500_0037E7D8 D_00222480[];
extern u8 D_00224B10[];
extern u8 D_00225450[];

void func_00382E60(s32 arg0) {
    s32 temp_s1;
    void *temp_s0;
    void *temp_s2;

    temp_s2 = (arg0 * 0xB0) + D_00224B10;
    { S_00222500_0037E7D8 *p = &D_00222480[arg0]; func_0038D108(temp_s2, p->f50, 0xB0); }
    temp_s1 = arg0 * 0x780;
    temp_s0 = temp_s1 + D_00225450;
    func_0038D108(temp_s0, temp_s1 + (D_00225450 - 0x500), 0x280);
    (*(void **)((u8 *)(temp_s2) + 0x70)) = temp_s0;
}
/* localdecomp:end func_00382E60 */
TEXT_PADDING(2);
