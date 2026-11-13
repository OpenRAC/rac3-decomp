#include "common.h"

LINKER_REMNANT("asm/levels", func_L39_0067F8A8);

/* localdecomp:start func_L39_0067F8B0 */
void func_00120D28(s32, s32, s32);
void func_L39_0067F8B0(void *arg0, s32 arg1) {
    if (arg1 != 0) {
        func_00120D28(arg0 + 0x14, arg1, 0x33);
        *(s8 *)((u8 *)arg0 + 0x47) = 0;
    }
}
/* localdecomp:end func_L39_0067F8B0 */

/* localdecomp:start func_L39_0067F8E8 */
typedef struct S_0067F8E8_V { u8 pad0[0x30]; void (*f30)(void *, f32 *, f32 *); } S_0067F8E8_V;
typedef struct S_0067F8E8_O { u8 pad0[0x60]; S_0067F8E8_V *vt; } S_0067F8E8_O;
typedef struct S_0067F8E8 { u8 pad0[0x10]; S_0067F8E8_O *obj; u8 pad14[0x3C]; f32 x50; f32 x54; } S_0067F8E8;

void func_L39_0067F8E8(S_0067F8E8 *a0, f32 *a1, f32 *a2) {
    *a1 = 0.0f;
    *a2 = 0.0f;
    if (a0->obj != 0) {
        a0->obj->vt->f30(a0->obj, a1, a2);
    }
    *a1 += a0->x50;
    *a2 += a0->x54;
}
/* localdecomp:end func_L39_0067F8E8 */

/* localdecomp:start func_L39_0067F968 */
void func_L39_0067F968(void *arg0, f32 *arg1, f32 *arg2) {
    *arg1 = *(f32 *)((u8 *)arg0 + 0x58);
    *arg2 = *(f32 *)((u8 *)arg0 + 0x5C);
}
/* localdecomp:end func_L39_0067F968 */

INCLUDE_ASM("asm/levels", func_L39_0067F980);
