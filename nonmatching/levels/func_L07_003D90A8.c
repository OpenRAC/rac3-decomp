#include "common.h"

/*
 * PAL reconstruction; stock check.py: 1 difference in 364 bytes.
 * Flags: -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as.
 * The null arm stores $zero instead of retail's $s0 at +0xAC.
 * A shared tail gives the correct store but swaps the slot pointer and loop
 * counter registers. Explicit if/else, integer and widened pointer tests
 * repeated the one-word residual; stopped after eight compiles.
 * No source marker replaced. Full PAL/US build verification remains pending.
 */
typedef int Quad_3D90A8 __attribute__((mode(TI)));
extern u8 *D_L07_001DF41C_003D90A8;
extern u8 *func_003C24B0(s32, s32);
extern void func_003C7C38(void *);
extern void func_L07_003D9218(s32);
extern void func_L07_003D9260(s32);

void func_L07_003D90A8(s32 arg0) {
    u8 *obj = (u8 *)arg0;
    u8 *vars;
    u8 *out;
    u8 **slot;
    u8 *row;
    s32 i;
    if (obj[0x20] == 0) {
        vars = *(u8 **)(obj + 0x68);
        row = D_L07_001DF41C_003D90A8 + (*(s32 *)(vars + 0x30) << 8);
        *(Quad_3D90A8 *)(row + 0x10) = *(Quad_3D90A8 *)(obj + 0x10);
        *(Quad_3D90A8 *)(row + 0xF0) = *(Quad_3D90A8 *)(obj + 0xF0);
        row[0x30] = obj[0x30];
        *(u16 *)(row + 0x32) = *(u16 *)(obj + 0x32);
        slot = (u8 **)(vars + 0x34);
        i = 0;
        do {
            out = func_003C24B0(0x1CA1, 0x80);
            if (out != 0) {
                out[0x31] = 1;
                *(u16 *)(out + 0x32) = *(u16 *)(obj + 0x32);
                out[0x30] = obj[0x30];
                *(unsigned long *)(out + 0x38) = *(unsigned long *)(obj + 0x38);
                if (i != 0) {
                    *(u16 *)(out + 0x34) |= 0x8000;
                }
                *(Quad_3D90A8 *)(out + 0x10) = *(Quad_3D90A8 *)(obj + 0x10);
                *(f32 *)(out + 0x14) -= 7.07f;
                *(f32 *)(out + 0xF8) = (f32)i * 3.1415927f;
                func_003C7C38(out);
                *slot = out;
            } else {
                *slot = out;
            }
            i++;
            slot++;
        } while (i < 2);
        *(void (**)(s32))(vars + 4) = func_L07_003D9218;
        *(void (**)(s32))(vars + 8) = func_L07_003D9260;
        func_L07_003D9218(arg0);
    }
}
