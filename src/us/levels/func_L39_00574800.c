#include "common.h"

/* NTSC-U counterpart of func_L39_00575528 (src/levels/shared/L39_00574F20.c) */
/* localdecomp:start func_L39_00574800 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x18];
    u8 f18;
    u8 pad19[7];
} Ent_00575528;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00575528;
extern u8 D_L39_0024DF00[];
extern Ent_00575528 *D_L39_0024BC6C;
extern u8 D_L39_001FE1A0[];
extern void func_003888C8(void *, void *, void *);
extern s32 func_00388398(void *);
extern s32 func_L39_005F0ED8(s32, s32, void *, s32);
extern s32 func_L39_005B2498(s32);
extern void func_L39_005F0988(s32);

void func_L39_00574800(u8 *self) {
    s32 *sub = *(s32 **)(self + 8);
    V4_00575528 d;
    V4_00575528 l;
    s32 flags = 0x19;
    u8 *slot;

    vec_sub_ab(&d, D_L39_0024DF00, self + 0x40);
    d.w = 0.0f;
    func_003888C8(&l, &d, self + 0x50);
    if (fabs_asm(l.x) <= 1.0f && fabs_asm(l.y) <= 1.0f && fabs_asm(l.z) <= 1.0f) {
        if (D_L39_0024BC6C[sub[0]].f18) flags |= 4;
        slot = D_L39_001FE1A0 + (sub[4] << 7);
        if (*(u8 **)(slot + 0x100) != self || !slot[0xD0]) {
            if (func_00388398(sub + 3)) {
                sub[4] = func_L39_005F0ED8(sub[0], flags, self, 0x400);
                if (sub[2] > 0) {
                    sub[3] = (s32)((sub[1] + func_L39_005B2498(sub[2] - sub[1])) * 60.0f);
                }
            } else {
                sub[4] = -1;
            }
        } else {
            *(s32 *)(slot + 0x118) = flags;
        }
    } else {
        s32 index = sub[4];
        if (index != -1) {
            u8 *slot2 = D_L39_001FE1A0 + (index << 7);
            if (*(u8 **)(slot2 + 0x100) == self && slot2[0xD0]) func_L39_005F0988(index);
        }
        sub[4] = -1;
    }
}
/* localdecomp:end func_L39_00574800 */
