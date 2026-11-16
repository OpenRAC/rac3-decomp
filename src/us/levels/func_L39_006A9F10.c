#include "common.h"

/* NTSC-U counterpart of func_L39_006AC860 (src/levels/39_multiplayer_menu/L39_006AC860.c) */
/* localdecomp:start func_L39_006A9F10 */
typedef struct S_006AC860_Vtbl {
    u8 pad[0x8C];
    s32 (*f8C)(void *);
    u8 pad90[0x1C];
    s32 (*fAC)(void *);
} S_006AC860_Vtbl;
typedef struct S_006AC860_Obj {
    u8 pad[0x60];
    S_006AC860_Vtbl *vtbl;
} S_006AC860_Obj;
typedef struct S_006AC860_This {
    u8 pad[0x110];
    S_006AC860_Obj *f110;
    S_006AC860_Obj *f114;
    S_006AC860_Obj *f118;
    u8 pad11C[0x18C];
    s32 f2A8;
    s32 f2AC;
    s32 f2B0;
    s32 f2B4;
    s32 f2B8;
    s32 f2BC;
    s32 f2C0;
    s32 f2C4;
    s32 f2C8;
    s32 f2CC;
    u8 f2D0[8];
    s32 f2D8;
    s32 f2DC;
    s32 f2E0;
    u8 f2E4;
} S_006AC860_This;
typedef struct S_006AC860_Game {
    u8 pad[0x14];
    s32 f14;
    u8 pad18[0x114];
    s32 f12C;
    u8 pad130[0x18];
    s32 f148;
    u8 pad14C[0x24];
    s32 f170;
    s32 f174;
    u8 pad178[0x535];
    u8 f6AD;
} S_006AC860_Game;
extern S_006AC860_Game D_001A5E50;
__asm__(".extern D_L39_002412A0, 16");
extern s32 *D_L39_002412A0;
typedef struct S_006AC860_Cfg {
    u8 b[0x16];
} S_006AC860_Cfg;
typedef struct S_006AC860_Net {
    s32 w[4];
} S_006AC860_Net;
extern S_006AC860_Cfg D_L39_002417C8 __attribute__((section(".sdata")));
extern S_006AC860_Net D_L39_002407A8 __attribute__((section(".sdata")));
extern u8 D_001D5F38_sda_006A9F10;
extern void *func_L39_006C9630(void *);
extern void func_L39_006C9850(s32 *, s32, s32);
extern void func_L39_006C9668(void *, s32);
extern s32 func_00195620(s32);
extern s32 func_00195900(void);

s32 func_L39_006A9F10(S_006AC860_This *this) {
    s32 buf[120];
    s32 n;
    s32 i;
    u8 mask;
    s32 on = 1;
    S_006AC860_Game *g;

    n = this->f110->vtbl->f8C(this->f110) + 1;
    func_L39_006C9630(buf);
    func_L39_006C9850(buf, 1, 4);
    func_L39_006C9850(buf, 16, n);
    func_L39_006C9850(buf, 15, this->f2D8 / 5);
    func_L39_006C9850(buf, 17, this->f2A8);
    func_L39_006C9850(buf, 20, this->f2B4);
    func_L39_006C9850(buf, 21, this->f2DC / 5);
    func_L39_006C9850(buf, 22, this->f2B8);
    func_L39_006C9850(buf, 24, this->f2BC);
    func_L39_006C9850(buf, 23, this->f2E0);
    func_L39_006C9850(buf, 25, this->f2C0);
    func_L39_006C9850(buf, 26, this->f2CC);
    func_L39_006C9850(buf, 27, this->f2C8);
    func_L39_006C9850(buf, 28, this->f2C4);
    func_L39_006C9850(buf, 19, this->f2B0);
    func_L39_006C9850(buf, 4, this->f2D0[0] ? 0 : on);
    func_L39_006C9850(buf, 5, this->f2D0[1] ? 0 : on);
    func_L39_006C9850(buf, 6, this->f2D0[2] ? 0 : on);
    func_L39_006C9850(buf, 7, this->f2D0[3] ? 0 : on);
    func_L39_006C9850(buf, 8, this->f2D0[4] ? 0 : on);
    func_L39_006C9850(buf, 9, this->f2D0[5] ? 0 : on);
    func_L39_006C9850(buf, 10, this->f2D0[6] ? 0 : on);
    func_L39_006C9850(buf, 11, this->f2D0[7] ? 0 : on);
    if (n >= 7) {
        D_L39_002417C8.b[8] = 0;
    }
    D_L39_002417C8.b[7] = this->f2E4;
    if (this->f2B0 == 0) {
        D_L39_002417C8.b[0] = on;
        D_L39_002417C8.b[1] = on;
        D_L39_002417C8.b[2] = on;
        D_L39_002417C8.b[3] = on;
    } else {
        D_001D5F38_sda_006A9F10 = 0;
        D_L39_002417C8.b[1] = 0;
        D_L39_002417C8.b[2] = 0;
        D_L39_002417C8.b[3] = 0;
    }
    D_L39_002417C8.b[14] = 0;
    if (this->f2BC == 1) {
        D_L39_002417C8.b[14] = 1;
    }
    D_L39_002417C8.b[15] = this->f2DC;
    D_L39_002417C8.b[16] = this->f2E0;
    if (this->f2A8 == 2) {
        D_L39_002417C8.b[12] = 0;
    } else {
        D_L39_002417C8.b[12] = this->f2C0;
    }
    D_L39_002417C8.b[18] = this->f2CC;
    D_L39_002417C8.b[19] = this->f2C4;
    D_L39_002417C8.b[20] = this->f2C8;
    D_L39_002417C8.b[21] = this->f2B4;
    D_L39_002407A8.w[0] = this->f2A8;
    D_L39_002407A8.w[1] = 0;
    D_L39_002407A8.w[3] = 0;
    mask = 0;
    for (i = 0; i < 8; i++) {
        if (this->f2D0[i]) {
            mask |= 1 << i;
        }
    }
    D_L39_002417C8.b[17] = mask;
    *D_L39_002412A0 = 4;
    g = &D_001A5E50;
    g->f14 = this->f110->vtbl->f8C(this->f110) + 40;
    D_L39_002407A8.w[2] = this->f118->vtbl->fAC(this->f118);
    D_L39_002407A8.w[3] = this->f2B8 == 1;
    g->f170 = 1;
    g->f174 = 1;
    g->f148 = 0;
    g->f6AD = 0;
    g->f12C = 1;
    func_00195620(0);
    func_00195900();
    func_L39_006C9668(buf, 2);
    return 1;
}
/* localdecomp:end func_L39_006A9F10 */
