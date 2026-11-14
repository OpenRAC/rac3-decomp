#include "common.h"

typedef struct Ent_00573C58 {
    u8 pad0[0x18];
    u8 f18;
    u8 pad19[7];
} Ent_00573C58;

/* localdecomp:start func_L39_00573C58 */
extern u8 D_L39_0024DE00[];
extern Ent_00573C58 *D_L39_0024BB6C;
extern u8 D_001FE020[];
extern f32 func_0038CF00(void *, void *);
extern s32 func_0038CAD0(void *);
extern s32 func_L39_005F35D8(s32, s32, void *, s32);
extern s32 func_L39_005B4398(s32);
extern void func_L39_005F3088(s32);

void func_L39_00573C58(u8 *self) {
    s32 *sub = *(s32 **)(self + 8);
    f32 distance;
    s32 flags;
    u8 *slot;
    s32 four = 4;
    if (sub[5] == 0) return;
    if (sub[0] < 0) return;
    distance = func_0038CF00(D_L39_0024DE00, self + 0x40);
    if (distance < *(f32 *)(self + 0xC)) {
        flags = 0;
        if (D_L39_0024BB6C[sub[0]].f18) flags |= 4;
        slot = D_001FE020 + (sub[4] << 7);
        if (*(u8 **)(slot + 0x100) == self && slot[0xD0]) return;
        if (func_0038CAD0(sub + 3)) {
            sub[4] = func_L39_005F35D8(sub[0], flags, self, 0x400);
            if (sub[2] > 0) {
                sub[3] = (s32)((sub[1] + func_L39_005B4398(sub[2] - sub[1])) * 50.0f);
            }
        }
    } else if (*(f32 *)(self + 0xC) + 1.0f < distance) {
        s32 index = sub[4];
        if (index != -1) {
            u8 *slot2 = D_001FE020 + (index << 7);
            if (*(u8 **)(slot2 + 0x100) == self && slot2[0xD0]) func_L39_005F3088(index);
        }
        sub[4] = -1;
    }
}
/* localdecomp:end func_L39_00573C58 */
