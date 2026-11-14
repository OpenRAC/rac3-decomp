#include "common.h"

/* NTSC-U counterpart of func_L39_00686048 (src/levels/39_multiplayer_menu/L39_00686048.c) */
typedef struct Vt_00685FF0 {
    u8 pad0[8];
    void (*f8)(void *, s32);
} Vt_00685FF0;
typedef struct O_00685FF0 {
    u8 pad0[0x60];
    Vt_00685FF0 *f60;
} O_00685FF0;
extern O_00685FF0 *D_001DC1E4_sda;

/* localdecomp:start func_L39_00683528 */
__asm__(".extern D_001DC1E4_sda, 4");
extern u8 *D_L39_0024D860_00683528;
extern u8 D_001A5E50[];
extern void func_001206F4(void *, void *);
extern s32 func_L39_0067A388(void *);
extern void func_L39_006DA120(void *);

void func_L39_00683528(void) {
    u8 *g = D_L39_0024D860_00683528;
    u8 *d = D_001A5E50;
    u8 *a;
    u8 *b;
    u8 *c;
    s32 t;
    u8 x, y;

    *(s32 *)(g + 0x14) = 0;
    *(s32 *)(g + 0x10) = 0;
    a = *(u8 **)(g + 0x50);
    x = d[0x180];
    y = d[0x2E5];
    t = *(s32 *)(d + 0x2C4);
    c = *(u8 **)(g + 0x38);
    b = *(u8 **)(g + 0x30);
    a[0x9D] = y;
    a[0x98] = x;
    func_001206F4(a + 0x11, d + 0x182);
    *(s32 *)(a + 0x94) = t;
    if (func_L39_0067A388(a)) {
        func_L39_006DA120(a);
    }

    *(s32 *)b = *(s32 *)(d + 0x34);
    func_001206F4(b + 4, d + 0x5E);
    *(s32 *)(b + 0x28) = *(s32 *)(d + 0x70);
    b[0x2C] = d[0x74];

    *(s32 *)c = *(s32 *)(d + 0x38);
    c[0x34] = d[0x5D];
    func_001206F4(c + 4, d + 0x3C);

    {
        u8 *p = *(u8 **)((u8 *)D_001DC1E4_sda + 0x64);
        p[0x2B8] = 1;
        p[0x2B9] = 1;
    }
}
/* localdecomp:end func_L39_00683528 */
