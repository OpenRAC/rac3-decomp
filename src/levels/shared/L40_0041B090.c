#include "common.h"

/* localdecomp:start func_L40_0041B090 */
#include "vu0.h"
typedef struct { s32 w0; s32 w4; s32 w8; s16 h0C; s16 h0E; u8 pad10[0x10]; } V_0041B090;
typedef struct { u8 pad0[0x188]; s8 b188; s8 b189; s8 b18A; } G_0041B090;
__asm__(".extern D_L39_00241640, 4");
extern G_0041B090 *D_L39_00241640;
__asm__(".extern D_L40_0024845C, 4");
extern u8 *D_L40_0024845C;
extern void func_L40_00489BC0(void *, void *, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern u8 *func_L39_00668620(void *);
extern f32 func_0038CE68(void *, void *);

void func_L40_0041B090(u8 *self) {
    s32 idx = -1;
    V_0041B090 *vars = *(V_0041B090 **)(self + 0x68);
    u8 st = self[0x20];
    u8 *e;
    u8 *m;
    u32 d[4] __attribute__((aligned(16)));

    if (st == 0) {
        self[0x30] = 0xFF;
        func_L40_00489BC0(self, &vars->pad10, -1);
        func_L01_004450F0(self, 1, -1);
    } else if (st == 1) {
        if (vars->h0C != 0) {
            switch (vars->h0C) {
            case 1:
                idx = vars->w0;
                break;
            case 2:
                idx = vars->w4;
                break;
            case 3:
                idx = vars->w8;
                break;
            case 4:
                if (vars->w0 >= 0 && D_L39_00241640->b188 != 0) {
                    idx = vars->w0;
                } else if (vars->w4 >= 0 && D_L39_00241640->b189 != 0) {
                    idx = vars->w4;
                } else if (vars->w8 >= 0 && D_L39_00241640->b18A != 0) {
                    idx = vars->w8;
                }
                break;
            }
            vars->h0C = 0;
        }
        func_L40_00489BC0(self, &vars->pad10, -1);
    }
    if (idx >= 0) {
        e = D_L40_0024845C + idx * 256;
        m = func_L39_00668620(e);
        vec_sub_ba(d, m + 0x290, e + 0x10);
        if (vars->h0E != -1) {
            if (func_0038CE68(d, d) < 0.2f || e[0xBC] == 8 || e[0xBC] == 10 || e[0xBC] == 7) {
                *(u32 *)(m + 0x2F8) |= 0x400;
            }
        }
        if (vars->h0E == 0) {
            *(u32 *)(m + 0x2F8) = (*(u32 *)(m + 0x2F8) & ~0x200) | 0x100;
        } else if (vars->h0E == 1) {
            *(u32 *)(m + 0x2F8) = (*(u32 *)(m + 0x2F8) & ~0x100) | 0x200;
        }
        if (e[0xBC] == 8) {
            e[0xBC] = 7;
            *(s32 *)(m + 0x2F0) = 1;
        }
    }
}
/* localdecomp:end func_L40_0041B090 */
