#include "common.h"

/* localdecomp:start func_L01_00423AB8 */
typedef struct {
    s16 id;
    s16 arg;
    f32 f;
} B_00420D88;

typedef struct {
    u8 b0;
    u8 b1;
    u8 pad2[30];
    f32 f20;
    f32 f24;
    f32 f28;
    u8 pad2C[20];
} T_00420D88;

extern u8 D_001D5471;
typedef struct {
    u8 pad0[68];
    s16 count;
    u8 pad46[346];
    u8 *list[1];
} G_00420D88;

extern G_00420D88 D_L01_001E6D80;
extern T_00420D88 D_L01_00244500[];
extern void func_0011A264(void *buf, s32 c, s32 n);
extern void func_L01_0043A430(u8 *m, s32 arg, T_00420D88 *e);

void func_L01_00423AB8(void) {
    B_00420D88 buf[2];
    u8 *m;
    T_00420D88 *e;
    s32 i;
    s32 j;
    s32 k;
    f32 f;

    if (D_001D5471 == 0) {
        return;
    }
    func_0011A264(buf, 0, 8);
    for (i = 0; i < D_L01_001E6D80.count; i++) {
        m = D_L01_001E6D80.list[i];
        if (*(s32 *)(m + 84) == 0) {
            for (j = 0; buf[j].id != 0; j++) {
                if (*(s16 *)(m + 170) != buf[j].id) {
                    continue;
                }
                f = buf[j].f;
                for (k = 0; k < 7; k++) {
                    if (D_L01_00244500[k].b1 == 0) {
                        break;
                    }
                }
                if (k < 7) {
                    e = &D_L01_00244500[k];
                    func_L01_0043A430(m, buf[j].arg, e);
                    e->f20 = f;
                    e->f24 = f;
                    e->f28 = f;
                }
            }
        }
    }
}
/* localdecomp:end func_L01_00423AB8 */

INCLUDE_ASM("asm/levels", func_L01_00423C48);

/* localdecomp:start func_L01_00423DF0 */
extern s32 D_L01_001E6DB4[];
extern void func_0013D3D0(s32);

void func_L01_00423DF0(void) {
    if (D_L01_001E6DB4[0] == 1) {
        func_0013D3D0(100);
    }
}
/* localdecomp:end func_L01_00423DF0 */
