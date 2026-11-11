#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_006AC860);

INCLUDE_ASM("asm/levels", func_L39_006ACC60);

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

INCLUDE_ASM("asm/levels", func_L39_006AE238);
