#include "common.h"

typedef struct { u8 pad[0x464]; u8 spent[1]; } S_00395B70;

/* localdecomp:start func_L28_00395B70 */
extern S_00395B70 D_L28_00234A80;
extern u8 D_1BBE90[];
extern s32 D_001D545C;
extern u8 D_L28_001D66B0[8];
extern s32 func_L01_00447490(u8 *, s32, s32);
extern void func_L01_00456230(u8 *, s32);
extern void func_003A52A0(s32, s32, void *);
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00456160(u8 *, u8 *);
extern void func_L01_00451FE0(u8 *, s32, void *, f32, f32, f32, f32, s32, f32, f32,
                              s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_003C2880(u8 *);

void func_L28_00395B70(u8 *a0) {
    s32 *s = *(s32 **)(a0 + 0x68);
    u8 *m;
    s32 id;
    s32 id2;
    s32 v;

    if (a0[0x20] == 0) {
        id = *(u16 *)(a0 + 0xB2);
        if (D_L28_00234A80.spent[(s16)id] == 0) {
            v = D_1BBE90[((s16)id >> 1) + (D_001D545C << 10)];
            if (id & 1)
                v = (v >> 4) & 7;
            else
                v = v & 7;
            if (v == 0) {
                s[0] = 2;
                a0[0x20] = 1;
                goto next;
            }
        }
        func_003C2880(a0);
        return;
    }
next:
    if (func_L01_00447490(a0, 0x10000, 0) != 0) {
        s[0] -= 1;
        func_L01_00456230(a0, 1);
        if (s[0] == 0) {
            func_003A52A0(0, 0, a0);
            m = func_003C24B0(0x8C4, 0x80);
            func_L01_00456160(m, a0);
            *(f32 *)(m + 0x18) += 1.5f;
            func_L01_00451FE0(a0, 15, D_L28_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 255,
                              -1.0f, -1.0f, 180, 0, 0, 35, 1.0f, 1.0f, 0, 3);
            id2 = *(u16 *)(a0 + 0xB2);
            if (id2 & 1) {
                if (((D_1BBE90[((s16)id2 >> 1) + (D_001D545C << 10)] >> 4) & 7) != 7)
                    D_1BBE90[((s16)id2 >> 1) + (D_001D545C << 10)] += 0x10;
            } else {
                if ((D_1BBE90[((s16)id2 >> 1) + (D_001D545C << 10)] & 7) != 7)
                    D_1BBE90[((s16)id2 >> 1) + (D_001D545C << 10)] += 1;
            }
            func_003C2880(a0);
        } else {
            a0[0xA8] = 0xFF;
        }
    }
}
/* localdecomp:end func_L28_00395B70 */
