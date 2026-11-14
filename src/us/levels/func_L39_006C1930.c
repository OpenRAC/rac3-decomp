#include "common.h"

/* NTSC-U counterpart of func_L39_006C4448 (src/levels/39_multiplayer_menu/L39_006C4448.c) */
/* localdecomp:start func_L39_006C1930 */
__asm__(".extern D_L39_002417C0, 16");
__asm__(".extern D_L39_002412A0, 16");


typedef struct {
    u8 pad[0xF0];
    void (*fF0)(void *);
} VT_006C4448;

extern u8 *D_L39_002417C0;
extern s32 *D_L39_002412A0;
extern s32 D_L39_00240640_006C1930;

extern s32 func_L39_006C1AB0(void *, s32, void **);
extern void func_L39_00599368(void *);
extern void func_L39_00686EC8(void);
extern void func_L39_006C1630(void *);
extern void func_0019C060(void);
extern void func_0019BFF8(s32);
extern void func_0019CB68(s32);
extern void func_L39_005992A8(s32, s32);

void func_L39_006C1930(u8 *obj) {
    void *buf;
    s32 i;
    s32 n;

    if (D_L39_002417C0 == 0) {
        return;
    }
    for (i = 0; i < 8; i++) {
        if (func_L39_006C1AB0(obj, i, &buf) != 0) {
            func_L39_00599368(buf);
        }
    }
    (*(VT_006C4448 **)(obj + 0x60))->fF0(obj);
    func_L39_00686EC8();
    func_L39_006C1630(obj);
    n = *(s16 *)(D_L39_002417C0 + 0x17C);
    if (*D_L39_002412A0 >= 2 && n <= 0x2D) {
        n += 10;
    }
    func_0019C060();
    func_0019BFF8(0);
    if (*(s32 *)(D_L39_002417C0 + 0x180) != 2) {
        func_0019CB68(0);
    }
    func_L39_005992A8(n, 0);
    D_L39_00240640_006C1930 = -1;
    {
        s32 j;
        s32 k;
        for (j = 0; j < 32 && D_L39_002417C0 != 0; j++) {
            D_L39_00240640_006C1930 ^= D_L39_002417C0[j];
            for (k = 7; k >= 0; k--) {
                if (D_L39_00240640_006C1930 & 1) {
                    D_L39_00240640_006C1930 = (D_L39_00240640_006C1930 >> 1) ^ 0xEDB88320;
                } else {
                    D_L39_00240640_006C1930 = D_L39_00240640_006C1930 >> 1;
                }
            }
        }
    }
}
/* localdecomp:end func_L39_006C1930 */
