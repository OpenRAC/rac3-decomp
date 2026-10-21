#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_0032ADF0);

/* localdecomp:start func_L01_0032B2C8 */
/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { u8 pad0[0x10]; u8 q10[16]; u8 pad20[4]; u8 *p24; u8 pad28[0xc]; u16 h34; u8 pad36[0x62]; s32 f98; u8 pad9c[0x24]; f32 m[12]; } S_A;
extern S_A *D_L01_0023AC70[];
extern void func_003C2EC0(void *, s32, f32 *);
extern void func_003C48A8(void *, void *);
extern void func_003C7DD8(void *);
void func_L01_0032B2C8(u8 *a0) {
    f32 v[16];
    s32 i = 0;
    s32 j;
    f32 *q;
    if (D_L01_0023AC70[0] != 0) {
        do {
            D_L01_0023AC70[i]->h34 &= 0xffbe;
            D_L01_0023AC70[i]->h34 |= *(u16 *)(D_L01_0023AC70[i]->p24 + 0x44) & 0x1000;
            D_L01_0023AC70[i]->f98 = *(s32 *)(D_L01_0023AC70[i]->p24 + 0x10);
            *(u128_t *)D_L01_0023AC70[i]->q10 = *(u128_t *)(a0 + 0x10);
            func_003C2EC0(a0, 0, v);
            for (j = 0, q = v; j < 3; j++) {
                *(f32 *)((u8 *)D_L01_0023AC70[i] + (j << 4) + 0xc0) = q[0];
                *(f32 *)((u8 *)D_L01_0023AC70[i] + (j << 4) + 0xc4) = q[1];
                *(f32 *)((u8 *)D_L01_0023AC70[i] + (j << 4) + 0xc8) = q[2];
                q += 4;
            }
            func_003C48A8(&D_L01_0023AC70[i]->m[0], &D_L01_0023AC70[i]->m[12]);
            func_003C7DD8(D_L01_0023AC70[i]);
            D_L01_0023AC70[i]->f98 = 0;
            i++;
        } while (D_L01_0023AC70[i] != 0);
    }
}
/* localdecomp:end func_L01_0032B2C8 */
