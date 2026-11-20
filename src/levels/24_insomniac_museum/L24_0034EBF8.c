#include "common.h"

/* localdecomp:start func_L24_0034EBF8 */
void func_L01_003EB5E0(s32, s32);
void func_L01_003F2AF8(s32, s32);

void func_L24_0034EBF8(void *arg0) {
    s32 temp_a1;
    void *temp_s0;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    temp_a1 = *(s32 *)((u8 *)temp_s0 + 0x158);
    if (temp_a1 != 0) {
        func_L01_003F2AF8(0, temp_a1);
        *(s32 *)((u8 *)temp_s0 + 0x158) = 0;
        return;
    }
    func_L01_003EB5E0(0, 3);
}
/* localdecomp:end func_L24_0034EBF8 */

/* localdecomp:start func_L24_0034EC40 */
#include "vu0.h"
typedef struct S_0034EC40 {
    u8 pad0[0x30];
    f32 x30;
    s16 x34;
    u8 pad36[0x3E - 0x36];
    u8 x3E;
    u8 pad3F[0x58 - 0x3F];
    u8 x58;
    u8 pad59;
    u8 x5A;
    u8 pad5B[0x80 - 0x5B];
    u8 x80[0x40];
    u8 xC0[0x40];
    vu0_q x100;
    vu0_q x110;
    vu0_q x120;
    u8 pad130[0x10];
    s32 x140;
    s32 x144;
    s32 x148;
    s32 x14C;
    f32 x150;
    u8 pad154[8];
    s32 x15C;
    s32 x160;
    s16 x164;
    s16 x166;
    s16 x168;
    s16 x16A;
} S_0034EC40;
extern void func_L01_0043A430(void *, s32, void *);
extern void func_L01_004450F0(void *, s32, s32);
__asm__(".extern D_L24_001DD3D0, 4");
extern f32 D_L24_001DD3D0;

void func_L24_0034EC40(u8 *obj) {
    S_0034EC40 *s = *(S_0034EC40 **)(obj + 0x68);
    func_L01_0043A430(obj, 0, s->x80);
    func_L01_0043A430(obj, 1, s->xC0);
    s->x34 = 100;
    s->x30 = 100.0f;
    s->x3E = 1;
    s->x58 = 0x1E;
    s->x5A = 0x20;
    qzero(&s->x100);
    qzero(&s->x110);
    qzero(&s->x120);
    s->x144 = 0;
    s->x14C = 0;
    *(f32 *)(obj + 0x2C) = *(f32 *)(*(u8 **)(obj + 0x24) + 0x24) * 0.1f * D_L24_001DD3D0;
    s->x140 = 0;
    s->x148 = 0;
    s->x150 = *(f32 *)(obj + 0x18);
    s->x166 = 0;
    s->x168 = 0;
    s->x16A = 0;
    s->x15C = 0;
    s->x160 = 0;
    s->x164 = 0;
    func_L01_004450F0(obj, 0, 1);
}
/* localdecomp:end func_L24_0034EC40 */
