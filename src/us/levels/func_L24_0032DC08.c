#include "common.h"

/* NTSC-U counterpart of func_L24_0032E508 (src/levels/24_insomniac_museum/L24_0032E508.c) */
/* localdecomp:start func_L24_0032DC08 */
__asm__(".extern D_L24_001DF0C0_0032DC08, 4");
extern s32 D_L24_001DF0C0_0032DC08;
extern u8 D_001A4C60[];
extern u8 *D_001D52FC;
extern u8 D_L24_001DCBD8_0032DC08[];
extern u8 D_L24_001DCBE8[];
extern u8 D_L24_001DCBF8[];
extern u8 D_L24_001DCC00[];
extern u8 D_L24_001DCC08[];
extern u8 D_L24_001DCC10[];
extern u8 D_L24_001DCC18[];
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_00388800(void *, void *);
extern void func_L01_0044F2E8(s32, s32, s32, s32, s32, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern s32 func_L01_00452EC8(void *);
extern u8 *func_L03_00348048(void *);
extern void func_L03_003480D8(void *, void *, void *, s32, s32, s32);
extern s32 func_L03_0043BF68(f32, s32, s32);

typedef struct { s32 cnt; f32 rad; u8 *tgt; s32 pad; u32 col[2]; u8 c0[2]; u8 c1[2]; u8 c2[2]; u8 c3[2]; } S_32E508;

void func_L24_0032DC08(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    u8 *t;
    s32 i;
    s32 n;

    switch (obj[0x20]) {
    case 0:
        for (i = 0; i < 2; i++) {
            ((S_32E508 *)s)->col[i] = (((S_32E508 *)s)->c3[i] << 24) | (((S_32E508 *)s)->c2[i] << 16)
                | (((S_32E508 *)s)->c1[i] << 8) | ((S_32E508 *)s)->c0[i];
        }
        *(s32 *)s = 0;
        func_L01_00441FB8(obj, 1, -1);
        break;
    case 1:
        if (func_00388800(D_001A4C60, obj + 0x10) <= *(f32 *)(s + 4)) {
            func_L01_0044F2E8(0, 1, 0x16BE, 1, 0, 0, 0);
            if (*(s32 *)(D_001D52FC + 0x1A4) & 0x10) {
                (*(s32 *)s)++;
                if (*(s32 *)s >= (*(u8 **)(obj + 0x24))[0xC]) {
                    *(s32 *)s = 0;
                }
                if (obj[0x43] != *(s32 *)s) {
                    func_003BE4F0(obj, *(s32 *)s, 0, 10);
                }
            }
        }
        break;
    case 3:
        if (func_L01_00452EC8(obj) != 0) {
            *(u8 **)(s + 8) = func_L03_00348048(obj);
            func_L03_003480D8(*(u8 **)(s + 8), s + 0x18, D_L24_001DCBD8_0032DC08, 4, -1000, 1000);
            func_L03_003480D8(*(u8 **)(s + 8), s + 0x18, D_L24_001DCBE8, 4, -1000, 1000);
            func_L03_003480D8(*(u8 **)(s + 8), s + 0x18, D_L24_001DCBF8, 2, 0, 0xFF);
            func_L03_003480D8(*(u8 **)(s + 8), s + 0x1A, D_L24_001DCC00, 2, 0, 0xFF);
            func_L03_003480D8(*(u8 **)(s + 8), s + 0x1C, D_L24_001DCC08, 2, 0, 0xFF);
            func_L03_003480D8(*(u8 **)(s + 8), s + 0x1E, D_L24_001DCC10, 2, 0, 0xFF);
            func_L03_003480D8(*(u8 **)(s + 8), s + 0x19, D_L24_001DCC18, 4, -1000, 1000);
            func_L03_003480D8(*(u8 **)(s + 8), s + 0x19, D_L24_001DCBE8, 4, -1000, 1000);
            func_L03_003480D8(*(u8 **)(s + 8), s + 0x19, D_L24_001DCBF8, 2, 0, 0xFF);
            func_L03_003480D8(*(u8 **)(s + 8), s + 0x1B, D_L24_001DCC00, 2, 0, 0xFF);
            func_L03_003480D8(*(u8 **)(s + 8), s + 0x1D, D_L24_001DCC08, 2, 0, 0xFF);
            func_L03_003480D8(*(u8 **)(s + 8), s + 0x1F, D_L24_001DCC10, 2, 0, 0xFF);
        }
        func_L01_0044F2E8(0, 1, 0, 1, 0, 0, 0);
        t = *(u8 **)(s + 8);
        if (t == 0 || *(s16 *)(t + 0xAA) != 0x118A || t[0x20] == 0xFE || t[0x20] == 0xFD) {
            for (i = 0; i < 2; i++) {
                ((S_32E508 *)s)->col[i] = (((S_32E508 *)s)->c3[i] << 24) | (((S_32E508 *)s)->c2[i] << 16)
                | (((S_32E508 *)s)->c1[i] << 8) | ((S_32E508 *)s)->c0[i];
            }
            func_L01_00441FB8(obj, 1, -1);
        }
        break;
    }
    if (obj[0x31] != 0) {
        n = 10;
        *(s32 *)(obj + 0x78) = func_L03_0043BF68((f32)(D_L24_001DF0C0_0032DC08 % n) * 6.2831855f / (f32)n - 3.1415927f,
                                                 *(s32 *)(s + 0x10), *(s32 *)(s + 0x14));
    }
}
/* localdecomp:end func_L24_0032DC08 */
