#include "common.h"

/* localdecomp:start func_L39_006AC860 */
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
extern S_006AC860_Game D_001A5CD0;
__asm__(".extern D_L39_00241120, 16");
extern s32 *D_L39_00241120;
typedef struct S_006AC860_Cfg {
    u8 b[0x16];
} S_006AC860_Cfg;
typedef struct S_006AC860_Net {
    s32 w[4];
} S_006AC860_Net;
extern S_006AC860_Cfg D_L39_00241648 __attribute__((section(".sdata")));
extern S_006AC860_Net D_L39_00240628 __attribute__((section(".sdata")));
extern u8 D_001D5F38_sda;
extern void *func_L39_006CC120(void *);
extern void func_L39_006CC340(s32 *, s32, s32);
extern void func_L39_006CC158(void *, s32);
extern s32 func_00195530(s32);
extern s32 func_00195810(void);

s32 func_L39_006AC860(S_006AC860_This *this) {
    s32 buf[120];
    s32 n;
    s32 i;
    u8 mask;
    s32 on = 1;
    S_006AC860_Game *g;

    n = this->f110->vtbl->f8C(this->f110) + 1;
    func_L39_006CC120(buf);
    func_L39_006CC340(buf, 1, 4);
    func_L39_006CC340(buf, 16, n);
    func_L39_006CC340(buf, 15, this->f2D8 / 5);
    func_L39_006CC340(buf, 17, this->f2A8);
    func_L39_006CC340(buf, 20, this->f2B4);
    func_L39_006CC340(buf, 21, this->f2DC / 5);
    func_L39_006CC340(buf, 22, this->f2B8);
    func_L39_006CC340(buf, 24, this->f2BC);
    func_L39_006CC340(buf, 23, this->f2E0);
    func_L39_006CC340(buf, 25, this->f2C0);
    func_L39_006CC340(buf, 26, this->f2CC);
    func_L39_006CC340(buf, 27, this->f2C8);
    func_L39_006CC340(buf, 28, this->f2C4);
    func_L39_006CC340(buf, 19, this->f2B0);
    func_L39_006CC340(buf, 4, this->f2D0[0] ? 0 : on);
    func_L39_006CC340(buf, 5, this->f2D0[1] ? 0 : on);
    func_L39_006CC340(buf, 6, this->f2D0[2] ? 0 : on);
    func_L39_006CC340(buf, 7, this->f2D0[3] ? 0 : on);
    func_L39_006CC340(buf, 8, this->f2D0[4] ? 0 : on);
    func_L39_006CC340(buf, 9, this->f2D0[5] ? 0 : on);
    func_L39_006CC340(buf, 10, this->f2D0[6] ? 0 : on);
    func_L39_006CC340(buf, 11, this->f2D0[7] ? 0 : on);
    if (n >= 7) {
        D_L39_00241648.b[8] = 0;
    }
    D_L39_00241648.b[7] = this->f2E4;
    if (this->f2B0 == 0) {
        D_L39_00241648.b[0] = on;
        D_L39_00241648.b[1] = on;
        D_L39_00241648.b[2] = on;
        D_L39_00241648.b[3] = on;
    } else {
        D_001D5F38_sda = 0;
        D_L39_00241648.b[1] = 0;
        D_L39_00241648.b[2] = 0;
        D_L39_00241648.b[3] = 0;
    }
    D_L39_00241648.b[14] = 0;
    if (this->f2BC == 1) {
        D_L39_00241648.b[14] = 1;
    }
    D_L39_00241648.b[15] = this->f2DC;
    D_L39_00241648.b[16] = this->f2E0;
    if (this->f2A8 == 2) {
        D_L39_00241648.b[12] = 0;
    } else {
        D_L39_00241648.b[12] = this->f2C0;
    }
    D_L39_00241648.b[18] = this->f2CC;
    D_L39_00241648.b[19] = this->f2C4;
    D_L39_00241648.b[20] = this->f2C8;
    D_L39_00241648.b[21] = this->f2B4;
    D_L39_00240628.w[0] = this->f2A8;
    D_L39_00240628.w[1] = 0;
    D_L39_00240628.w[3] = 0;
    mask = 0;
    for (i = 0; i < 8; i++) {
        if (this->f2D0[i]) {
            mask |= 1 << i;
        }
    }
    D_L39_00241648.b[17] = mask;
    *D_L39_00241120 = 4;
    g = &D_001A5CD0;
    g->f14 = this->f110->vtbl->f8C(this->f110) + 40;
    D_L39_00240628.w[2] = this->f118->vtbl->fAC(this->f118);
    D_L39_00240628.w[3] = this->f2B8 == 1;
    g->f170 = 1;
    g->f174 = 1;
    g->f148 = 0;
    g->f6AD = 0;
    g->f12C = 1;
    func_00195530(0);
    func_00195810();
    func_L39_006CC158(buf, 2);
    return 1;
}
/* localdecomp:end func_L39_006AC860 */

/* localdecomp:start func_L39_006ACC60 */
typedef struct S_006ACC60_Vtbl {
    u8 pad[0x6C];
    s32 (*f6C)(void *, s32, s32 *);
    u8 pad70[0x18];
    void (*f88)(void *, s32);
    s32 (*f8C)(void *);
    u8 pad90[0x4C];
    void (*fDC)(void *, s32);
} S_006ACC60_Vtbl;
typedef struct S_006ACC60_Obj {
    u8 pad[0x60];
    S_006ACC60_Vtbl *vtbl;
} S_006ACC60_Obj;
typedef struct S_006ACC60_This {
    u8 pad[0x110];
    S_006ACC60_Obj *f110;
    S_006ACC60_Obj *f114;
    u8 pad118[0xC];
    S_006ACC60_Obj *f124;
    S_006ACC60_Obj *f128;
    u8 pad12C[0x17C];
    s32 f2A8;
    s32 f2AC;
} S_006ACC60_This;
extern s32 func_00381FF0(s32);
struct S_006ACE10_This;
extern void func_L39_006ACE10(struct S_006ACE10_This *);
extern s32 D_001DD39C_sda;

void func_L39_006ACC60(S_006ACC60_This *this) {
    S_006ACC60_Obj *obj;
    s32 changed = 0;
    s32 n = this->f110->vtbl->f8C(this->f110);

    if ((u32)n < 10) {
        this->f124->vtbl->fDC(this->f124, n + 7);
        this->f128->vtbl->fDC(this->f128, n + 17);
    }
    if (n >= 6 && D_001DD39C_sda < 6) {
        this->f2AC = this->f2A8;
        {
            s32 ids[2] = { func_00381FF0(0x10E2), func_00381FF0(0x1026) };
            obj = this->f114;
            obj->vtbl->f6C(obj, 2, ids);
            if (this->f2AC == 0) {
                this->f114->vtbl->f88(this->f114, 2);
            } else {
                this->f114->vtbl->f88(this->f114, this->f2AC - 1);
            }
            changed = 1;
        }
    } else if (D_001DD39C_sda >= 6 && n < 6) {
        s32 ids[3] = { func_00381FF0(0x1024), func_00381FF0(0x10E2), func_00381FF0(0x1026) };
        changed = 1;
        obj = this->f114;
        obj->vtbl->f6C(obj, 3, ids);
        this->f114->vtbl->f88(this->f114, this->f2AC);
    }
    if (changed) {
        func_L39_006ACE10((struct S_006ACE10_This *)this);
    }
    D_001DD39C_sda = n;
}
/* localdecomp:end func_L39_006ACC60 */

/* localdecomp:start func_L39_006ACE10 */
typedef struct S_006ACE10_Vtbl {
    u8 pad[0x78];
    s32 (*f78)(void *);
    u8 pad7C[0x10];
    s32 (*f8C)(void *);
} S_006ACE10_Vtbl;
typedef struct S_006ACE10_Obj {
    u8 pad[0x60];
    S_006ACE10_Vtbl *vtbl;
} S_006ACE10_Obj;
typedef struct S_006ACE10_This {
    u8 pad[0x114];
    S_006ACE10_Obj *obj;
    u8 pad118[0x190];
    s32 f2A8;
    u8 pad2AC[8];
    s32 f2B4;
    u8 pad2B8[0x2C];
    u8 f2E4;
} S_006ACE10_This;
extern void func_0019AE90(s32);

void func_L39_006ACE10(S_006ACE10_This *this) {
    this->f2A8 = this->obj->vtbl->f8C(this->obj);
    if (this->obj->vtbl->f78(this->obj) - 1 != 2) {
        this->f2A8++;
    }
    if (this->f2A8 == 2) {
        this->f2B4 = 0;
        this->f2E4 = 0;
    } else {
        this->f2E4 = this->f2B4 = 1;
    }
    func_0019AE90(this->f2A8);
}
/* localdecomp:end func_L39_006ACE10 */

LINKER_REMNANT("asm/levels", func_L39_006ACEA0);
