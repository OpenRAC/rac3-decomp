#include "common.h"

/* NTSC-U counterpart of func_L39_00573DE0 (src/levels/shared/L39_00573DE0.c) */
/* localdecomp:start func_L39_005730B8 */
#include "vu0.h"

typedef struct Ent_00573DE0 {
    f32 f0;
    f32 f4;
    u8 pad8[4];
    s32 fC;
    u8 pad10[8];
    u8 f18;
    u8 pad19[7];
} Ent_00573DE0;

extern s32 D_L39_0024BC6C;
extern u8 D_L39_0024DF00[];
extern u8 D_L39_001FE1A0[];
extern u8 D_L39_001FE280[];
extern f32 func_003888C8(void *, void *, void *);
extern f32 func_00388770(void *);
extern s32 func_00388398(void *);
extern s32 func_L39_005F0ED8(s32, s32, void *, s32);
extern void func_L39_005F0988(s32);
extern s32 func_L39_005F1060(u32, s32);
extern s32 func_L39_005B2498(s32);

void func_L39_005730B8(u8 *self) {
    s32 *sub = *(s32 **)(self + 8);
    vu0_v4 d;
    vu0_v4 v;
    vu0_v4 w;
    Ent_00573DE0 *ent;
    s32 inside;
    s32 flags;
    f32 scale;
    f32 len;
    s32 a;
    s32 b;

    if (sub[6] == 0) return;
    if (sub[0] == -1) return;
    vec_sub_ba(&d, D_L39_0024DF00, self + 0x40);
    d.w = 0;
    inside = 1;
    func_003888C8(&v, &d, self + 0x50);
    if (v.x > 1.0f) {
        v.x = 1.0f;
        inside = 0;
    }
    if (v.x < -1.0f) {
        v.x = -1.0f;
        inside = 0;
    }
    if (v.y > 1.0f) {
        v.y = 1.0f;
        inside = 0;
    } else if (v.y < -1.0f) {
        v.y = -1.0f;
        inside = 0;
    }
    if (v.z > 1.0f) {
        v.z = 1.0f;
        inside = 0;
    } else if (v.z < -1.0f) {
        v.z = -1.0f;
        inside = 0;
    }
    ent = (Ent_00573DE0 *)(sub[0] * 32 + D_L39_0024BC6C);
    flags = 0;
    if (ent->f18) flags |= 4;
    if (inside == 1) {
        {
            s32 idx = sub[4];
            u8 *slot;

            if (idx != -1) {
                slot = D_L39_001FE1A0 + (idx << 7);
                if (*(u8 **)(slot + 0x100) == self && slot[0xD0]) func_L39_005F0988(idx);
            }
        }
        sub[4] = -1;
        {
            s32 idx = sub[5];
            u8 *slot;

            if (idx == -1 || (slot = D_L39_001FE1A0 + (idx << 7), *(u8 **)(slot + 0x100) != self) || slot[0xD0] == 0) {
                if (func_00388398(sub + 3)) {
                    sub[5] = func_L39_005F0ED8(sub[0], flags | 0x110, self, 0x400);
                    if (sub[2] > 0) {
                        sub[3] = (s32)((sub[1] + func_L39_005B2498(sub[2] - sub[1])) * 60.0f);
                    }
                }
            } else {
                func_L39_005F1060(idx, ent->fC);
            }
        }
        return;
    }
    scale = 1.0f;
    func_003888C8(&v, &v, self + 0x10);
    vec_add_ba(&v, &v, self + 0x40);
    vec_sub_ba(&w, D_L39_0024DF00, &v);
    len = func_00388770(&w);
    if (ent->f4 < len) {
        {
            s32 idx = sub[4];
            u8 *slot;

            if (idx != -1) {
                slot = D_L39_001FE1A0 + (idx << 7);
                if (*(u8 **)(slot + 0x100) == self && slot[0xD0]) func_L39_005F0988(idx);
            }
        }
        sub[4] = -1;
        {
            s32 idx = sub[5];
            u8 *slot;

            if (idx != -1) {
                slot = D_L39_001FE1A0 + (idx << 7);
                if (*(u8 **)(slot + 0x100) == self && slot[0xD0]) func_L39_005F0988(idx);
            }
        }
        sub[5] = -1;
    } else {
        scale = len * (scale / (ent->f4 - ent->f0));
    }
    if (scale < 0.2f) {
        f32 t = (0.2f - scale) * 5.0f;
        f32 u = 1.0f - t;
        f32 k = ent->fC / sqrt_asm(t * t + u * u);

        b = t * k;
        a = u * k;
        {
            s32 idx = sub[5];
            u8 *slot;

            if (idx == -1 || (slot = D_L39_001FE1A0 + (idx << 7), *(u8 **)(slot + 0x100) != self) || slot[0xD0] == 0) {
                sub[5] = func_L39_005F0ED8(sub[0], flags | 0x110, self, 0x400);
            }
        }
        func_L39_005F1060(sub[5], b);
    } else {
        {
            s32 idx = sub[5];
            u8 *slot;

            if (idx != -1) {
                slot = D_L39_001FE1A0 + (idx << 7);
                if (*(u8 **)(slot + 0x100) == self && slot[0xD0]) {
                    func_L39_005F0988(idx);
                    sub[5] = -1;
                }
            }
        }
        a = ent->fC * (1.0f - scale);
    }
    {
        s32 idx = sub[4];
        u8 *slot;

        if (idx == -1 || (slot = D_L39_001FE1A0 + (idx << 7), *(u8 **)(slot + 0x100) != self) || slot[0xD0] == 0) {
            if (a > 0) sub[4] = func_L39_005F0ED8(sub[0], flags | 0x10, self, 0x400);
        }
    }
    if (sub[4] != -1) {
        *(vu0_q *)(D_L39_001FE280 + (sub[4] << 7)) = *(vu0_q *)&v;
    }
    func_L39_005F1060(sub[4], a);
}
/* localdecomp:end func_L39_005730B8 */
