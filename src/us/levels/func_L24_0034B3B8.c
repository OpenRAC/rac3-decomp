#include "common.h"

/* NTSC-U counterpart of func_L24_0034C208 (src/levels/24_insomniac_museum/L24_0034A2C8.c) */
extern s32 D_L24_001DF0C0_0034B3B8;
extern void func_L24_0034C088_0034B3B8(u8 *), func_L24_0034B3B8(u8 *), func_L24_0034C348_0034B3B8(u8 *), func_L24_0034CCA0_0034B3B8(void *), func_L24_0034BBD8_0034B3B8(void *);
#include "vu0.h"
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
#include "vu0.h"

/* localdecomp:start func_L24_0034B3B8 */
extern s32 D_L24_001DF0C0_0034B3B8;
__asm__(".extern D_L24_001DD3D8, 4");
extern f32 D_L24_001DD3D8 __attribute__((section(".sdata")));
__asm__(".extern D_L24_001DD3E4, 4");
extern f32 D_L24_001DD3E4 __attribute__((section(".sdata")));
extern void func_003BEB58(void *, void *, void *, f32);

void func_L24_0034B3B8(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    u8 *p;
    s32 n;
    f32 a[4];
    f32 b[4];

    if (D_L24_001DF0C0_0034B3B8 >= 5) {
        p = s;
        p += 0x250;
        n = 3;
        do {
            if (*(f32 *)(s + 0x584) >= D_L24_001DD3D8) {
                *(u128_t *)a = *(u128_t *)(p + 0x90);
                *(u128_t *)b = *(u128_t *)p;
                func_003BEB58(p, a, b, D_L24_001DD3E4 / *(f32 *)(s + 0x584) * 0.0166666675359f);
            } else {
                *(u128_t *)p = *(u128_t *)(p + 0x90);
            }
            p += 0x10;
            n--;
        } while (n >= 0);
        p = s;
        p += 0x380;
        n = 3;
        do {
            if (*(f32 *)(s + 0x584) >= D_L24_001DD3D8) {
                *(u128_t *)a = *(u128_t *)(p + 0x90);
                *(u128_t *)b = *(u128_t *)p;
                func_003BEB58(p, a, b, D_L24_001DD3E4 / *(f32 *)(s + 0x584) * 0.0166666675359f);
            } else {
                *(u128_t *)p = *(u128_t *)(p + 0x90);
            }
            p += 0x10;
            n--;
        } while (n >= 0);
    }
}
/* localdecomp:end func_L24_0034B3B8 */
