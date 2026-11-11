#include "common.h"

/* localdecomp:start func_L39_00695368 */
/* ptr is passed to vt->fnB8 as its 2nd arg: retail leaves it live in $a1 for the jalr */
typedef struct VT_00695368 {
    u8 pad0[0x1C];
    void (*fn1C)(void *, s32, s32);
    u8 pad20[0xB8 - 0x20];
    void (*fnB8)(void *, s32);
} VT_00695368;
typedef struct Obj_00695368 {
    u8 pad0[0x60];
    VT_00695368 *vt;
} Obj_00695368;
typedef struct Item_00695368 {
    u8 pad0[4];
    s32 f4;
    s32 **f8;
} Item_00695368;
typedef struct G_00695368 { u8 pad[0x38]; u8 *f38; } G_00695368;
typedef struct P_00695368 { u8 pad[0xC8]; u8 fC8; s32 fCC; s32 fD0; } P_00695368;
__asm__(".extern D_L39_0024D760, 16");
extern s32 *D_L39_0024D760;
extern s32 func_00381FF0(s32);
extern void func_L39_006D0DD0(void *);
extern void func_L39_00689E58(void *, s32, u32, f32, f32);

void func_L39_00695368(u8 *arg0)
{
    u8 *s0;
    Item_00695368 *p;
    s32 v3;
    s32 t;
    VT_00695368 *vt;
    P_00695368 *ptr;
    Obj_00695368 *o;

    p = 0;
    s0 = (u8 *)D_L39_0024D760[0x38 / 4];
    if (s0[0x3EC] != 0) {
        s32 idx = *(s32 *)(s0 + 0x3F0);
        if (idx >= 0) {
            p = (Item_00695368 *)(s0 + 0x404 + idx * 12);
        }
    }
    if (arg0[0x2AC] != 0) {
        if (s0[0x3F4] == 0) {
            *(s32 *)(arg0 + 0x2A8) = *(s32 *)(s0 + 0x3FC);
            func_L39_006D0DD0(s0);
            arg0[0x2AC] = 0;
        }
        if (arg0[0x2AC] != 0) {
            return;
        }
    }
    v3 = *(s32 *)(s0 + 0x3FC);
    if (*(s32 *)(arg0 + 0x2A8) == v3) {
        return;
    }
    *(s32 *)(arg0 + 0x2A8) = v3;
    t = p->f4;
    *(s32 *)(arg0 + 0x2B0) = t;
    if (t == 0) {
        vt = (*(Obj_00695368 **)(arg0 + 0x114))->vt;
        vt->fnB8(*(void **)(arg0 + 0x114), func_00381FF0(0x101E));
        o = *(Obj_00695368 **)(arg0 + 0x114);
        o->vt->fn1C(o, 2, 0);
        if (s0[0x34] != 0) {
            func_L39_00689E58(arg0, func_00381FF0(0xFD5), 0x706EC8FF, 1.0f, 1.0f);
        }
    } else {
        ptr = *(P_00695368 **)p->f8;
        if (ptr->fC8 != 0) {
            *(s32 *)(arg0 + 0x2B4) = ptr->fCC;
            *(s32 *)(arg0 + 0x2B8) = ptr->fD0;
        } else {
            *(s32 *)(arg0 + 0x2B4) = -1;
        }
        o = *(Obj_00695368 **)(arg0 + 0x114);
        o->vt->fnB8(o, (s32)ptr);
        o = *(Obj_00695368 **)(arg0 + 0x114);
        o->vt->fn1C(o, 1, 0);
        if (s0[0x34] != 0) {
            func_L39_00689E58(arg0, func_00381FF0(0xFD6), 0x706EC8FF, 1.0f, 1.0f);
        }
    }
}
/* localdecomp:end func_L39_00695368 */

LINKER_REMNANT("asm/levels", func_L39_00695520);

INCLUDE_ASM("asm/levels", func_L39_00695530);

/* localdecomp:start func_L39_00695798 */
extern u8 D_L39_0047CC68[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_00695798(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047CC68;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_00695798 */
