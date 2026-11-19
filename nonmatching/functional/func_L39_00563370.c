/* functional: high. PAL port of the NTSC-U draft shape; 141 byte diffs are codegen only (retail vadd.xyz/lq/sq quad copies written as float/128-bit copies, v+0xC copied from m+0xCC like sqc2 does). */
#include "common.h"
typedef int u128_t __attribute__((mode(TI)));
extern f32 D_001DFE08_sda;
__asm__(".extern D_001DFE08_sda, 4");
extern f32 D_001E2004_sda;
__asm__(".extern D_001E2004_sda, 4");
extern u8 D_003CCF80[];
extern u8 D_0024D640[];
extern u8 D_0024D650[];
extern u8 D_0024D660[];
extern u8 D_0024D670[];
extern s32 D_0024D680[];
extern s32 D_0024D690[];
extern s16 D_0024D6D0[];
u8 *func_003C24B0(s32, s32);
void func_0038D308(void *, void *);
void func_0038CF68(void *, void *, f32);
void func_0038CE90(void *, void *, void *);
void func_L01_004C93E0(s32);
f32 func_L01_004C93D8(void);
s32 func_L39_005F33E0(s32, s32, void *);

u8 *func_L39_00563370(u8 *arg0) {
    u8 *m;
    u8 *d;
    u8 *g;
    u8 *v;
    u8 *p0;
    u8 *p1;
    u8 *p2;
    s16 *h;
    s32 *w;
    s32 i;

    m = func_003C24B0(0x1B37, 0x80);
    if (m != 0) {
        d = *(u8 **)(m + 0x68);
        p0 = m + 0xC0;
        *(u8 **)(d + 0x40) = arg0;
        m[0x30] = 0xFF;
        m[0x20] = 1;
        *(u16 *)(m + 0x34) |= 0x41;
        p2 = m + 0xE0;
        p1 = m + 0xD0;
        func_0038D308(p0, m + 0xF0);
        for (i = 3; i >= 0; i--) {
            D_0024D680[i] = 0;
        }
        g = D_003CCF80;
        v = g + 0x3C0;
        h = (s16 *)(d + 0x18);
        w = (s32 *)(d + 0x20);
        func_0038CF68(g, p0, D_001DFE08_sda);
        *(u128_t *)D_0024D640 = *(u128_t *)(m + 0xE0);
        func_0038CF68(g + 0x140, p1, D_001DFE08_sda);
        *(u128_t *)D_0024D650 = *(u128_t *)(m + 0xC0);
        func_0038CF68(g + 0x280, p2, D_001DFE08_sda);
        *(u128_t *)D_0024D660 = *(u128_t *)(m + 0xD0);
        *(f32 *)(v + 0x0) = *(f32 *)(m + 0xC0) + *(f32 *)(m + 0xE0);
        *(f32 *)(v + 0x4) = *(f32 *)(m + 0xC4) + *(f32 *)(m + 0xE4);
        *(f32 *)(v + 0x8) = *(f32 *)(m + 0xC8) + *(f32 *)(m + 0xE8);
        *(f32 *)(v + 0xC) = *(f32 *)(m + 0xCC);
        func_0038CF68(v, v, D_001DFE08_sda);
        func_0038CE90(D_0024D670, v, p1);
        for (i = 7; i >= 0; i--) {
            D_0024D690[i] = 0;
        }
        for (i = 4; i >= 0; i--) {
            D_0024D6D0[i] = 0;
        }
        D_001E2004_sda = 1.0f;
        func_L01_004C93E0(0);
        *(f32 *)d = func_L01_004C93D8();
        *(u128_t *)(m + 0x10) = *(u128_t *)(*(u8 **)(d + 0x40) + 0xA0);
        *(s32 *)(d + 0x14) = 0x19;
        *(s32 *)(d + 0xC) = -1;
        *(s32 *)(d + 0x10) = 0;
        for (i = 3; i >= 0; i--) {
            h[i] = 0;
        }
        for (i = 3; i >= 0; i--) {
            w[i] = 0;
        }
        func_L39_005F33E0(1, 0, m);
    }
    return m;
}
