/* Near miss (level 4, Marcadia): 37 differences with @ps2as: prologue/base scheduling, outer-loop saved registers, and inner-loop initialization; improved from 105 differences. Full level still uses INCLUDE_ASM. */
#include "common.h"

/* localdecomp:start func_L04_00434098 */

typedef struct S_434098 {
    u8 p0[0x34];
    u16 h34;
    u8 p36[0x63 - 0x36];
    u8 b63;
    u8 p64[0x68 - 0x64];
    u8 *p68;
    u8 p6C[0xAA - 0x6C];
    s16 hAA;
} S_434098;

typedef struct G_434098 {
    u8 p0[0x30];
    s32 w30;
    u8 p34[0x44 - 0x34];
    s16 h44;
    u8 p46[0x1A0 - 0x46];
    S_434098 *arr[8];
} G_434098;

extern G_434098 D_L04_001E6B80[];
__asm__(".extern D_L04_001E6B80, 16");
extern S_434098 *D_L04_002397F0[];
__asm__(".extern D_L04_002397F0, 16");
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern u8 D_L04_001D6A94[4];
__asm__(".extern D_L04_001D6A94, 16");
extern u8 D_L04_001D6A98[4];
__asm__(".extern D_L04_001D6A98, 16");
extern u8 D_001D6A90_sda[4];
__asm__(".extern D_001D6A90_sda, 4");

extern void func_L01_00423AB8(void);
extern void func_L04_004CA0B0(void);
extern void func_003A58C0(void *, s32);
extern void func_003A7AF8(void);
extern void func_L01_00404A10(void *, void *);
extern void func_L01_00404808(void *, void *);
extern void func_L01_00424168(void);
extern void func_L01_00451DB8(void *, void *, s32, s32, f32);

void func_L04_00434098(void) {
    G_434098 *g;
    S_434098 *p;
    S_434098 **q;
    s32 i;
    S_434098 **arr;

    func_L01_00423AB8();
    i = 0;
    if (D_L04_001E6B80[0].h44 > 0) {
    g = D_L04_001E6B80;
    arr = g->arr;
    do {
        p = arr[i];
        if (p != 0 && p->hAA == 0xE29) {
            p->h34 |= 0x800;
        }
        if (p->hAA == 0xD54) {
            p->b63 = 0;
            if (D_L04_002397F0[0] != 0) {
                for (q = D_L04_002397F0; *q != 0; q++) {
                    if ((*q)->b63 != 0) {
                        (*q)->b63 = 1;
                    }
                }
            }
            func_003A58C0(p, 0);
            func_L01_00404A10(func_003A7AF8, p);
        }
        if (p != 0) {
            if (p->hAA == 0xFA0) {
                if (p->p68 != 0) {
                    func_L01_00451DB8(p, p->p68 + 0xC, 0x80AAAAD2, 0x80396464, 0.07330383f);
                }
            } else if (p->hAA == 0x1DEE || p->hAA == 0x19BC) {
                func_L01_00451DB8(p, D_001D6A90_sda, 0x80505080, 0x80404038, 0.038397245f);
            } else if (p->hAA == 0x1977) {
                func_L01_00451DB8(p, D_L04_001D6A94, 0x8080AAAA, 0x80464646, 0.045378566f);
            } else if (p->hAA == 0x1766) {
                func_L01_00451DB8(p, D_L04_001D6A98, 0x80AAAAFF, 0x80646496, 0.13264504f);
            } else if (p->hAA == 0x195B || p->hAA == 0x1B58 || p->hAA == 0x195C || p->hAA == 0x175A) {
                func_L01_00404808(func_L01_00424168, p);
            }
        }
        i++;
    } while (i < g->h44);
    }
    if (D_001D545C == 4) {
        if (D_L04_001E6B80[0].w30 == 5) {
            func_L04_004CA0B0();
        }
    }
}
/* localdecomp:end func_L04_00434098 */
