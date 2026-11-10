#include "common.h"

typedef struct Ent_00573C58 {
    u8 pad0[0x18];
    u8 f18;
    u8 pad19[7];
} Ent_00573C58;

/* localdecomp:start func_L39_00572F30 */
extern u8 D_L39_0024DF00[];
extern Ent_00573C58 *D_L39_0024BC6C;
extern u8 D_L39_001FE1A0[];
extern f32 func_003887C8(void *, void *);
extern s32 func_00388398(void *);
extern s32 func_L39_005F0ED8(s32, s32, void *, s32);
extern s32 func_L39_005B2498(s32);
extern void func_L39_005F0988(s32);

void func_L39_00572F30(u8 *self) {
    s32 *sub = *(s32 **)(self + 8);
    f32 distance;
    s32 flags;
    u8 *slot;
    s32 four = 4;
    if (sub[5] == 0) return;
    if (sub[0] < 0) return;
    distance = func_003887C8(D_L39_0024DF00, self + 0x40);
    if (distance < *(f32 *)(self + 0xC)) {
        flags = 0;
        if (D_L39_0024BC6C[sub[0]].f18) flags |= 4;
        slot = D_L39_001FE1A0 + (sub[4] << 7);
        if (*(u8 **)(slot + 0x100) == self && slot[0xD0]) return;
        if (func_00388398(sub + 3)) {
            sub[4] = func_L39_005F0ED8(sub[0], flags, self, 0x400);
            if (sub[2] > 0) {
                sub[3] = (s32)((sub[1] + func_L39_005B2498(sub[2] - sub[1])) * 60.0f);
            }
        }
    } else if (*(f32 *)(self + 0xC) + 1.0f < distance) {
        s32 index = sub[4];
        if (index != -1) {
            u8 *slot2 = D_L39_001FE1A0 + (index << 7);
            if (*(u8 **)(slot2 + 0x100) == self && slot2[0xD0]) func_L39_005F0988(index);
        }
        sub[4] = -1;
    }
}
/* localdecomp:end func_L39_00572F30 */
