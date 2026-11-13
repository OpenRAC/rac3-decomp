#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_006AC860);

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
