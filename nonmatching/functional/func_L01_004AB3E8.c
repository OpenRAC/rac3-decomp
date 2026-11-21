/* functional: high. Same reads, writes and calls as retail; sqrt_asm is the game's sqrt.s on a squared distance (never negative). 94 diff vs bytes only from register allocation of the loop counter/ids pointer. Callees func_003A52A0/func_003A53E8/func_003A4F28 are the frontbin names of retail 004AABF0/004AB018/004AA878 at L01. */
#include "vu0.h"
typedef struct {
    u8 pad0[0xD0];
    u8 active;
    u8 padD1[0xDC - 0xD1];
    s32 owner;
    vu0_v4 pos;
} E_004AB3E8;

typedef struct {
    s8 pad0;
    s8 ids[3];
    u8 pad4[4];
    f32 range;
    u8 padC[4];
    s32 x10;
    s32 owner;
    s32 x18;
    u8 pad1C[0x40 - 0x1C];
    vu0_v4 a;
    vu0_v4 b;
} S_004AB3E8;

extern u8 D_001A30B0[][0x80];
extern u8 D_L01_001E2A40[];
extern s8 func_L01_004AAC98(s32, s32, s32, s32);
extern s8 func_003A52A0(s32, s32, s32);
extern void func_L01_004464C8(vu0_v4 *, vu0_v4 *, vu0_v4 *, u8 *);
extern f32 func_L01_0040E548(void *a, void *b);
extern void func_003A4F28(s32);
extern void func_003A53E8(s32, s32);

void func_L01_004AB3E8(S_004AB3E8 *s) {
    vu0_v4 v;
    s8 *ids = s->ids;
    s8 *p;
    s32 k;
    s32 id;
    f32 d;
    f32 t;
    f32 f;
    s32 n;

    for (k = 2, p = ids; k >= 0; k--, p++) {
        if (*p != -1 && ((E_004AB3E8 *)D_001A30B0[*p])->owner == s->owner && ((E_004AB3E8 *)D_001A30B0[*p])->active) {
            continue;
        }
        if (s->x18 != -1) {
            *p = func_L01_004AAC98(s->x10, 0x1C, s->owner, s->x18);
        } else {
            *p = func_003A52A0(s->x10, 0x1C, s->owner);
        }
    }
    func_L01_004464C8(&v, &s->a, &s->b, D_L01_001E2A40);
    d = func_L01_0040E548(&v, D_L01_001E2A40);
    if (s->range * s->range < d) {
        for (k = 2, p = ids; k >= 0; k--, p++) {
            id = *p;
            if (id != -1 && ((E_004AB3E8 *)D_001A30B0[id])->owner == s->owner && ((E_004AB3E8 *)D_001A30B0[id])->active) {
                func_003A4F28(id);
            }
            *p = -1;
        }
        return;
    }
    t = sqrt_asm(d) * (1.0f / s->range);
    f = 0.0f;
    if (t < 1.0f) {
        f = 1.0f - t;
    }
    n = (s32)(f * 1024.0f);
    id = s->ids[0];
    if (id != -1 && ((E_004AB3E8 *)D_001A30B0[id])->owner == s->owner && ((E_004AB3E8 *)D_001A30B0[id])->active) {
        func_003A53E8(id, n);
        ((E_004AB3E8 *)D_001A30B0[s->ids[0]])->pos = v;
    }
    id = s->ids[1];
    if (id != -1 && ((E_004AB3E8 *)D_001A30B0[id])->owner == s->owner && ((E_004AB3E8 *)D_001A30B0[id])->active) {
        func_003A53E8(id, n);
        ((E_004AB3E8 *)D_001A30B0[s->ids[1]])->pos = s->a;
    }
    id = s->ids[2];
    if (id != -1 && ((E_004AB3E8 *)D_001A30B0[id])->owner == s->owner && ((E_004AB3E8 *)D_001A30B0[id])->active) {
        func_003A53E8(id, n);
        ((E_004AB3E8 *)D_001A30B0[s->ids[2]])->pos = s->b;
    }
}
