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

INCLUDE_ASM("asm/levels", func_L39_006ACEA8);

LINKER_REMNANT("asm/levels", func_L39_006AD970);

/* localdecomp:start func_L39_006AD978 */
extern u8 D_L39_0047DDA0[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_006AD978(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047DDA0;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_006AD978 */

INCLUDE_ASM("asm/levels", func_L39_006AD9A0);

/* localdecomp:start func_L39_006AE208 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_006AE208(void *);

extern void func_L39_0067F168();
void func_L39_006AE208(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_006AE208 */

/* localdecomp:start func_L39_006AE238 */
typedef struct S_006AE238_Vtbl {
    u8 pad[0x30];
    void (*f30)(void *, s32 *, f32 *);
} S_006AE238_Vtbl;
typedef struct S_006AE238_Item {
    s32 f0;
    s32 type;
} S_006AE238_Item;
typedef struct S_006AE238_Obj {
    u8 pad[0x60];
    S_006AE238_Vtbl *vtbl;
} S_006AE238_Obj;
typedef struct S_006AE238_This {
    u8 pad[0x110];
    S_006AE238_Obj *items[4];
    u8 pad120[0x170];
    s32 f290;
} S_006AE238_This;
extern void func_L39_006AEF20(u8 *);
extern void func_L39_006AED18(void *);
extern void func_L39_006AF070(void *);
extern void func_L39_00688340(s32, s32, s32);
extern void func_L39_006AEF70(void *, s32, s32, s32);
extern s32 func_L39_0068AEF8(void *, s32);
extern void func_L39_006AE3D8(void *);
extern void func_L39_00689F00(void *, s32, s32, s32, f32, f32, f32, f32, f32, f32);
extern f32 D_001DD414_sda;
extern f32 D_001DD41C_sda;
extern f32 D_001DD444_sda;
extern f32 D_001DD474_sda;
extern f32 D_001DD478_sda;

s32 func_L39_006AE238(S_006AE238_This *this, s32 cmd) {
    s32 a;
    f32 b;
    s32 first;
    s32 last;
    s32 i;
    s32 type;
    s32 sel;
    S_006AE238_Obj *obj;

    func_L39_006AEF20((u8 *)this);
    func_L39_006AED18(this);
    if (cmd == 7 && this->f290 == 3) {
        func_L39_006AF070(this);
        return 1;
    }
    if (cmd == 5) {
        func_L39_00688340(0x17, 0, 0);
        func_L39_006AEF70(this, 0, 1, -1);
        return 1;
    }
    if (func_L39_0068AEF8(this, cmd)) {
        return 1;
    }
    func_L39_006AE3D8(this);
    obj = this->items[this->f290];
    obj->vtbl->f30(obj, &a, &b);
    first = -1;
    last = -1;
    for (i = 3; i < 4; i++) {
        if ((type = ((S_006AE238_Item *)this->items[i])->type) == 3 || type == 4 || type == 5) {
            if (first == -1) {
                first = i;
            }
            last = i;
        }
    }
    sel = this->f290 != first;
    if (this->f290 != last) {
        sel |= 2;
    }
    func_L39_00689F00(this, sel, 3, 3, D_001DD414_sda, b, D_001DD41C_sda - D_001DD444_sda, D_001DD474_sda, D_001DD478_sda, 1.0f);
    return 0;
}
/* localdecomp:end func_L39_006AE238 */
