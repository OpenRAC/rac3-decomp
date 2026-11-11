#include "common.h"

typedef void (*FnVt_006C7F08)(void *, s32, s32);

/* localdecomp:start func_L39_006C7C40 */
void func_L39_0068B2F8(s32, s32, s32);
typedef struct O_006C7C40 O_006C7C40;
typedef struct Vt_006C7C40 { u8 pad[0x1C]; void (*f1C)(O_006C7C40 *, s32, s32); } Vt_006C7C40;
struct O_006C7C40 { u8 pad[0x60]; Vt_006C7C40 *vt; };
typedef struct S_006C7C40 { u8 pad[0x110]; O_006C7C40 *objs[0x296]; s32 unkB68; } S_006C7C40;

void func_L39_006C7C40(S_006C7C40 *self, s32 arg1) {
    s32 i;

    self->unkB68 = arg1;
    func_L39_0068B2F8((s32)self, arg1 + 0xF, 0);
    self->objs[arg1 + 0x19]->vt->f1C(self->objs[arg1 + 0x19], 4, 0);
    for (i = 0; i < 10; i++) {
        if (i != arg1) {
            self->objs[i + 0x19]->vt->f1C(self->objs[i + 0x19], 1, 0);
        }
    }
}
/* localdecomp:end func_L39_006C7C40 */

/* localdecomp:start func_L39_006C7CE8 */
s32 func_L39_006C8020(void *arg0);

s32 func_L39_006C7CE8(void *arg0) {
    if (func_L39_006C8020(arg0) != 0) {
        *(s32 *)((u8 *)arg0 + 0xB68) = *(s32 *)((u8 *)arg0 + 0x290) - 0xF;
    }
    return *(s32 *)((u8 *)arg0 + 0xB68);
}
/* localdecomp:end func_L39_006C7CE8 */

/* localdecomp:start func_L39_006C7D28 */
typedef struct {
    u8 pad[0x14C];
    s32 *a[10];
    s32 *b[10];
} S_006C7D28;
typedef void (*FnVt_006C7D28)(void *, void *);
extern u8 D_00249758[];
s32 func_00120884(s32);
void func_L39_005958F8(s32 *, s32, s32);

void func_L39_006C7D28(u8 *arg0, s32 arg1, s32 arg2, s32 *arg3) {
    S_006C7D28 *s = (S_006C7D28 *)arg0;
    s32 local[16];
    s32 i;
    s32 *v;

    for (i = 0; i < 10; i++) {
        if (i < arg2) {
            if (arg1 == 0) {
                func_L39_005958F8(local, arg3[i], func_00120884(arg3[i]));
                v = s->a[i];
                ((FnVt_006C7D28)(*(s32 *)(*(s32 *)((u8 *)v + 0x60) + 0x24)))(v, local);
            } else {
                v = s->b[i];
                ((FnVt_006C7D28)(*(s32 *)(*(s32 *)((u8 *)v + 0x60) + 0x24)))(v, (void *)arg3[i]);
            }
        } else if (arg1 == 0) {
            v = s->a[i];
            ((FnVt_006C7D28)(*(s32 *)(*(s32 *)((u8 *)v + 0x60) + 0x24)))(v, D_00249758);
        } else {
            v = s->b[i];
            ((FnVt_006C7D28)(*(s32 *)(*(s32 *)((u8 *)v + 0x60) + 0x24)))(v, D_00249758);
        }
    }
}
/* localdecomp:end func_L39_006C7D28 */

INCLUDE_ASM("asm/levels", func_L39_006C7E10);

/* localdecomp:start func_L39_006C7E98 */
void func_L39_006C7E98(u8 *arg0) {
    s32 **p = (s32 **)(arg0 + 0x174);
    s32 i;

    for (i = 9; i >= 0; i--) {
        s32 *v = p[-10];
        ((FnVt_006C7F08)(*(s32 *)(*(s32 *)((u8 *)v + 0x60) + 0x1C)))(v, 0, 0);
        v = *p;
        ((FnVt_006C7F08)(*(s32 *)(*(s32 *)((u8 *)v + 0x60) + 0x1C)))(v, 0, 0);
        p++;
    }
}
/* localdecomp:end func_L39_006C7E98 */

/* localdecomp:start func_L39_006C7F08 */
void func_L39_006C7F08(u8 *arg0) {
    s32 **p = (s32 **)(arg0 + 0x174);
    s32 i;

    for (i = 9; i >= 0; i--) {
        s32 *v = p[-10];
        ((FnVt_006C7F08)(*(s32 *)(*(s32 *)((u8 *)v + 0x60) + 0x1C)))(v, 3, 0);
        v = *p;
        ((FnVt_006C7F08)(*(s32 *)(*(s32 *)((u8 *)v + 0x60) + 0x1C)))(v, 3, 0);
        p++;
    }
}
/* localdecomp:end func_L39_006C7F08 */

/* localdecomp:start func_L39_006C7F78 */
void func_L39_0068B2F8(s32, s32, s32);
void func_L39_006C7F78(void *arg0) {
    func_L39_0068B2F8((s32) arg0, (*(s32 *)((u8 *)arg0 + 0xB68)) + 0xF, 0);
}
/* localdecomp:end func_L39_006C7F78 */

/* localdecomp:start func_L39_006C7FA0 */
void func_L39_006C7FA0(u8 *arg0, s32 arg1) {
    s32 **p = (s32 **)(arg0 + 0x174);
    s32 i;

    for (i = 9; i >= 0; i--) {
        s32 *v = p[-10];
        ((FnVt_006C7F08)(*(s32 *)(*(s32 *)((u8 *)v + 0x60) + 0x1C)))(v, arg1, 0);
        v = *p;
        ((FnVt_006C7F08)(*(s32 *)(*(s32 *)((u8 *)v + 0x60) + 0x1C)))(v, arg1, 0);
        p++;
    }
}
/* localdecomp:end func_L39_006C7FA0 */

/* localdecomp:start func_L39_006C8020 */
s32 func_L39_006C8020(void *arg0) {
    return (u32) ((*(s32 *)((u8 *)arg0 + 0x290)) - 0xF) < 0xAU;
}
/* localdecomp:end func_L39_006C8020 */

LINKER_REMNANT("asm/levels", func_L39_006C8030);

INCLUDE_ASM("asm/levels", func_L39_006C8050);

LINKER_REMNANT("asm/levels", func_L39_006C8248);

/* localdecomp:start func_L39_006C8250 */
extern u8 D_L39_0047EBA0[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_006C8250(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047EBA0;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_006C8250 */
