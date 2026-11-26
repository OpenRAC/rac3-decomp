/* func_L19_00332948 (1008 B, 3 places): PAL near miss, k6 agent 4 (2026-11-26), from the functional draft.
 * check.py at level 19: 57 positional / 33 aligned diffs. Fixed here: $gp hints for the D_*_sda slots and
 * D_L19_001DF240, the integer abs as abs_asm (retail's blezl/neg). Left: (1) the five debug counters at
 * 0x1DF42C-0x1DF434: retail loads them with `lui $v0; lhu $v0` and stores with `lui $at; sh` (assembler
 * macros: the compiler saw a small symbol + offset, the assembler a large one), this C gives $gp accesses
 * (small scalars) or compiler-split lui pairs (arrays); (2) the order of the mov.s float-argument copies
 * before func_L01_00451FE0; (3) the D_1A4C60 address (hero + 0x80) reloc name. */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L19_00332948 */
extern s32 D_L19_001DF240;
__asm__(".extern D_L19_001DF240, 4");
extern s32 D_001DCBD4_sda, D_001DCBD8_sda;
__asm__(".extern D_001DCBD4_sda, 4");
__asm__(".extern D_001DCBD8_sda, 4");
extern u8 D_001E2100[];
extern u8 D_1A4C60[];
extern u16 D_L19_001DF42C __attribute__((section(".sdata")));
extern u16 D_L19_001DF42E __attribute__((section(".sdata")));
extern u16 D_L19_001DF430 __attribute__((section(".sdata")));
extern u16 D_L19_001DF432 __attribute__((section(".sdata")));
extern u16 D_L19_001DF434 __attribute__((section(".sdata")));
extern void func_L19_00333160(u8 *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(u8 *);
extern void func_L19_0044B008(u8 *);
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L04_00325460(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L01_004AA7E8(void *, s32);
extern f32 func_0038CF38(void *, void *);
extern void func_L19_00332D38(void *);

void func_L19_00332948(void *arg0) {
    u8 *obj = (u8 *)arg0;
    u8 *pv = *(u8 **)(obj + 0x68);
    u8 *hit;
    s32 t;

    if (obj[0x20] == 0) {
        func_L19_00333160(obj);
    }
    if (obj[0x20] != 0x17 && (*(unsigned long *)(obj + 0x30) & 0x104100000000ul) == 0x4100000000ul && *(s32 *)(obj + 0x98) == 0) {
        u8 *def = *(u8 **)(obj + 0x24);
        u16 f = *(u16 *)(obj + 0x34) & 0xFFBE;
        *(u16 *)(obj + 0x34) = f;
        *(u16 *)(obj + 0x34) = f | (*(u16 *)(def + 0x44) & 0x1000);
        *(s32 *)(obj + 0x98) = *(s32 *)(def + 0x10);
    }
    if (obj[0x31] != 0) {
        if (func_L01_0040E548(D_001E2100, obj + 0x10) < 576.0f) {
            func_L01_004472C0(obj);
            obj[0x6F] = 0x16;
        }
    }
    if (obj[0x20] >= 2 && obj[0x95] != 4 && obj[0x20] != 1) {
        func_L19_0044B008(obj);
    }
    hit = (u8 *)func_L01_00447490(obj, 1, 0);
    if (hit == 0 && !(*(f32 *)(obj + 0x18) <= *(f32 *)(pv + 0x3BC))) {
        goto after;
    }
    if ((*(unsigned long *)(obj + 0x30) & 0x104100000000ul) == 0x4100000000ul && *(s32 *)(obj + 0x98) == 0) {
        goto after;
    }
    if (!(*(f32 *)(obj + 0x18) <= *(f32 *)(pv + 0x3BC))) {
        u8 *other;
        if (hit == 0 || (other = *(u8 **)(hit + 0x20)) == 0 || *(s16 *)(other + 0xAA) != 0x1A8E) {
            t = abs_asm(D_001DCBD4_sda - D_L19_001DF240);
            if (!(D_001DCBD8_sda < t)) {
                obj[0xA8] = 0xFF;
                goto after;
            }
        }
    }
    D_001DCBD4_sda = D_L19_001DF240;
    func_L04_00325460(obj + 0x10, 0, 5, 5, 5, 10, 20, 0, 1, 0, 0, 0, 0.25f, 20.0f);
    if (*(s16 *)(obj + 0xAA) == 0x964) {
        func_L01_00451FE0(obj, 15, pv + 0x1E0, 255, 180, 0, 0, 35, 0, 3,
                          3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
    }
    *(s32 *)(obj + 0x98) = 0;
    *(u16 *)(obj + 0x34) = (*(u16 *)(obj + 0x34) | 0x41) & 0xEFFF;
    func_L01_004AA7E8(obj, 1);
    func_L01_004450F0(obj, 0x17, 0);
    obj[0xA8] = 0xFF;
after:
    if (obj[0x95] == 4) {
        D_L19_001DF42E++;
    }
    if (!((*(unsigned long *)(obj + 0x30) & 0x104100000000ul) == 0x4100000000ul && *(s32 *)(obj + 0x98) == 0) && obj[0x20] != 1) {
        if (func_0038CF38(obj + 0x10, D_1A4C60) < 16.0f) {
            D_L19_001DF42C++;
            switch (*(s16 *)(obj + 0xAA)) {
            case 0x940:
                D_L19_001DF430++;
                break;
            case 0x93C:
                D_L19_001DF432++;
                break;
            case 0xA59:
                D_L19_001DF434++;
                break;
            }
        }
    }
    func_L19_00332D38(obj);
}
/* localdecomp:end func_L19_00332948 */
