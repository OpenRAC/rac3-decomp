#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00574F20);

/* localdecomp:start func_L39_00575528 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x18];
    u8 f18;
    u8 pad19[7];
} Ent_00575528;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00575528;
extern u8 D_L39_0024DE00[];
extern Ent_00575528 *D_L39_0024BB6C;
extern u8 D_001FE020[];
extern void func_0038D000(void *, void *, void *);
extern s32 func_0038CAD0(void *);
extern s32 func_L39_005F35D8(s32, s32, void *, s32);
extern s32 func_L39_005B4398(s32);
extern void func_L39_005F3088(s32);

void func_L39_00575528(u8 *self) {
    s32 *sub = *(s32 **)(self + 8);
    V4_00575528 d;
    V4_00575528 l;
    s32 flags = 0x19;
    u8 *slot;

    vec_sub_ab(&d, D_L39_0024DE00, self + 0x40);
    d.w = 0.0f;
    func_0038D000(&l, &d, self + 0x50);
    if (fabs_asm(l.x) <= 1.0f && fabs_asm(l.y) <= 1.0f && fabs_asm(l.z) <= 1.0f) {
        if (D_L39_0024BB6C[sub[0]].f18) flags |= 4;
        slot = D_001FE020 + (sub[4] << 7);
        if (*(u8 **)(slot + 0x100) != self || !slot[0xD0]) {
            if (func_0038CAD0(sub + 3)) {
                sub[4] = func_L39_005F35D8(sub[0], flags, self, 0x400);
                if (sub[2] > 0) {
                    sub[3] = (s32)((sub[1] + func_L39_005B4398(sub[2] - sub[1])) * 50.0f);
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
            u8 *slot2 = D_001FE020 + (index << 7);
            if (*(u8 **)(slot2 + 0x100) == self && slot2[0xD0]) func_L39_005F3088(index);
        }
        sub[4] = -1;
    }
}
/* localdecomp:end func_L39_00575528 */

INCLUDE_ASM("asm/levels", func_L39_005756C0);
