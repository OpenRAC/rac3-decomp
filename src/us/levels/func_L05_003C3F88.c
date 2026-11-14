#include "common.h"

/* NTSC-U counterpart of func_L05_003C6080 (src/levels/shared/L05_003C4F88.c); cf. func_L28_0039AF78.
 * func_L01_004539A8 takes its floats at parameters 3, 4 and 13 (float-position sweep). */

/* localdecomp:start func_L05_003C3F88 */
typedef struct { u8 b[0x80]; } Snd80_003C3F88;
extern Snd80_003C3F88 D_001A30B0[];
extern s32 D_001D545C;

extern s32 func_L05_003C42B0(void);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L05_003C45F8(void *);
extern s32 func_L01_0044FCD0(void *, void *, s32, s32, s32);
extern void func_L05_003C4828(void *);
extern void func_L01_00452B20(void *, void *, void *);
extern s32 func_L01_0044F5E8(void *, void *, s32);
extern void func_L01_004538E0(void *, s32);
extern void func_L01_004539A8(void *, s32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, f32);

s32 func_L05_003C3F88(u8 *o) {
    u8 *t;
    s32 id;
    Snd80_003C3F88 *e;

    t = *(u8 **)(o + 0x68);
    if (o[0x20] == 0) {
        if (func_L05_003C42B0() != 0) {
            return 1;
        }
    }
    id = *(s32 *)(t + 0x420);
    if (id == -1 || (e = &D_001A30B0[id], *(u8 **)&e->b[0xDC] != o) || e->b[0xD0] == 0) {
        *(s32 *)(t + 0x420) = func_0039FE80(3, 4, o);
    }
    if (t[0x3E] == 2) {
        func_L05_003C45F8(o);
        return 1;
    }
    if (o[0xBC] != 0) {
        o[0xBC] = o[0xBC] - 1;
    }
    if (o[0x20] == 4 && D_001D545C == 0xB) {
        if (func_L01_0044FCD0(o, t + 0x160, 0, 0, 1) != 0) {
            if (o[0xBC] == 0) {
                func_0039FE80(4, 0, o);
                o[0xBC] = 0x1E;
            }
            *(s16 *)(t + 0x42A) = 1;
            func_L05_003C4828(o);
        }
    } else {
        if (func_L01_0044FCD0(o, t + 0x160, 0, 0, 0) != 0) {
            if (o[0xBC] == 0) {
                func_0039FE80(4, 0, o);
                o[0xBC] = 0x1E;
            }
            *(s16 *)(t + 0x42A) = 1;
            func_L05_003C4828(o);
        }
    }
    func_L01_00452B20(o, t + 0x240, t + 0x30);
    func_L01_0044F5E8(o, t + 0x30, 0);
    if (t[0x5E] != 0) {
        func_L05_003C45F8(o);
        return 1;
    }
    if (t[0x5F] != 0) {
        func_L01_004538E0(o, 5);
        if (o[0x95] == 0) {
            func_L01_004539A8(o, *(s32 *)(t + 0x2E0), *(f32 *)(t + 0x2E4), 10.0f, 0, 0, 0, 0, 3, 0, 0, 0, 1.0f);
        } else {
            func_L01_004539A8(o, *(s32 *)(t + 0x2E8), *(f32 *)(t + 0x2EC), 10.0f, 0, 0, 0, 0, 3, 0, 0, 0, 1.0f);
        }
    } else {
        func_L01_004538E0(o, 3);
        if (*(s16 *)(t + 0x42A) != 0) {
            func_L01_004539A8(o, -1, 256.0f, 256.0f, 0, 0, 0, 0, 1, 0, 0, 0, 1.0f);
        } else if (o[0x95] == 0) {
            func_L01_004539A8(o, *(s32 *)(t + 0x2E0), *(f32 *)(t + 0x2E4), 10.0f, 0, 0, 0, 0, 1, 0, 0, 0, 1.0f);
        } else {
            func_L01_004539A8(o, *(s32 *)(t + 0x2E8), *(f32 *)(t + 0x2EC), 10.0f, 0, 0, 0, 0, 1, 0, 0, 0, 1.0f);
        }
    }
    return 0;
}
/* localdecomp:end func_L05_003C3F88 */
