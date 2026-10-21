#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_00383038(f32 *, f32, f32, f32, f32, f32);
/* --- end of declarations from other files --- */

/* declarations of 382780.c's earlier functions (tools/port_from_us.py) */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_37E0F0;
typedef int Q_37E0F0 __attribute__((mode(TI)));
extern u8 *D_001D9A20;
extern void func_0038D3E0_00382760(void *, void *, void *);
extern s32 func_0013D3E0(void);
extern s32 func_0013D3E0(void);
extern s32 func_13D3E0(void);
extern s32 func_0013D3E0(void);
extern f32 func_00382918(void);
extern f32 func_003828C0(f32, f32);
extern void func_00382B40(void *, f32, f32, f32);
extern f32 func_0038D478(f32);
extern f32 func_0038D490(f32);
typedef struct { u8 pad[0x424]; f32 f424; f32 f428; f32 f42C; f32 f430; f32 f434; u8 b438; u8 b439; u16 h43A; f32 f43C; f32 f440; u8 pad2[0x1C]; } E_0037E568;
extern E_0037E568 D_00222480_00382BF0[];
typedef struct { u8 pad[0x424]; f32 f424; f32 f428; f32 f42C; f32 f430; f32 f434; u8 b438; u8 b439; s16 h43A; f32 f43C; f32 f440; u8 pad2[0x1C]; } E_0037E630;
extern E_0037E630 D_00222480_00382CB8[];
extern f32 D_002259B0[];
extern s32 func_0038CEE0(void *);
extern f32 func_0038D478(f32);
extern f32 func_0038D490(f32);
extern f32 func_003C3FA0(f32, f32, f32);
extern void func_003877A0();
void func_0038D108(void *, void *, s32);
typedef struct { u8 pad0[0x50]; void *f50; u8 pad54[0x460 - 0x54]; } S_00222500_0037E7D8;
extern S_00222500_0037E7D8 D_00222480[];
extern u8 D_00224B10[];
extern u8 D_00225450[];
extern s32 D_001D9A80[2];
extern void (*D_001D9A40[2])(s32);

/* localdecomp:start func_00383038 */
extern void func_0038DE98(f32, f32);
extern f32 func_0038DEE0(f32, f32);
void func_00383038(f32 *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4) {
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 var_f0;
    f32 var_f16;

    var_f16 = fparg4;
    temp_f0 = func_0038DEE0(fparg1, fparg0);
    temp_f1 = *arg0;
    temp_f1_2 = temp_f1 + ((fparg2 * temp_f0) - (fparg3 * temp_f1));
    *arg0 = temp_f1_2;
    if (var_f16 != 0.0f) {
        if (var_f16 < temp_f1_2) {
            *arg0 = var_f16;
        } else {
            f32 n = -var_f16;
            if (temp_f1_2 < n) {
                *arg0 = n;
            }
        }
    }
    temp_f1_3 = *arg0;
    __asm__("abs.s %0, %1" : "=f"(var_f0) : "f"(temp_f0));
    if ((var_f0 < temp_f1_3) || (var_f0 = -var_f0, (temp_f1_3 < var_f0))) {
        *arg0 = var_f0;
    }
    func_0038DE98(fparg0, *arg0);
}
/* localdecomp:end func_00383038 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00383120);

/* localdecomp:start func_00383128 */
s32 func_00381C88(void *, s32, s32, s32);           /* extern */
extern void func_003C2C38(s32 p);
extern u8 D_002224E0[];

void func_00383128(s32 arg0, void *arg1) {
    s32 temp_a0;
    s32 temp_a2;
    void *temp_s0;

    temp_a2 = arg0 * 0x460;
    temp_s0 = temp_a2 + D_002224E0;
    if ((*(s16 *)((u8 *)(arg1) + 0x86)) == 0) {
        if ((*(s32 *)((u8 *)(temp_s0) + 0xC4)) == 0) {
            (*(s32 *)((u8 *)(temp_s0) + 0xC4)) = func_00381C88(temp_a2 + (D_002224E0 - 0x60), arg0, temp_a2, arg0);
        }
    } else {
        temp_a0 = (*(s32 *)((u8 *)(temp_s0) + 0xC4));
        if (temp_a0 != 0) {
            func_003C2C38(temp_a0);
            (*(s32 *)((u8 *)(temp_s0) + 0xC4)) = 0;
        }
    }
}
/* localdecomp:end func_00383128 */
TEXT_PADDING(2);

/* localdecomp:start func_003831A8 */
typedef struct { s32 a, b, c, d, e; } S_37D000;
extern S_37D000 D_00380F80[];
void func_003831A8(u8 *p) {
    void (*f)(u8 *) = (void (*)(u8 *))D_00380F80[*(s16 *)(p + 0x8C)].c;
    if (f != 0) {
        f(p);
    }
}
/* localdecomp:end func_003831A8 */
