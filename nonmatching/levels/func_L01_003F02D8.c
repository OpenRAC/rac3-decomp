/* Matches PAL byte for byte with check.py at its 34 places (round 19, sonnet xhigh), but the full level build rejects it:
 * func_L01_003F02D8, its word at +0x5D8: the instruction differs (30 of 34 levels; the rest are not built with it).
 * check.py masks relocated fields; tools/level_symbols.py compares them with the real symbols of each level: a callee or global name
 * (or its address) used at +0x5D8 is wrong. Compare the retail word with the C there before spending more compiles.
 * Needs a divs_nops.txt row `func_L01_003F02D8 0 2 2` (it was in the match commit).
 */
/* localdecomp:start func_L01_003F02D8 */
typedef struct Ent_003F02D8 {
    f32 f0;
    f32 f4;
    u8 pad8[4];
    s32 fC;
    u8 pad10[8];
    u8 f18;
    u8 pad19[7];
} Ent_003F02D8;

typedef struct Sub_003F02D8 {
    s32 ids[4];
    s32 s10;
    s32 s14;
    s32 s18;
    s32 sA;
    s32 sB;
    s32 k;
    s32 pad28;
    s32 w2C;
} Sub_003F02D8;

extern s32 D_L01_001DFB6C_003F02D8;
extern u8 D_001A30B0_003F02D8[];
extern u8 D_001A3190_003F02D8[];
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038CEA8(void *);
extern s32 func_0038CAD0(void *);
extern s32 func_L01_004AAE90(s32, s32, void *, s32);
extern void func_003A4F28(s32);
extern s32 func_003A53E8(u32, s32);
extern s32 func_00382468(s32);

void func_L01_003F02D8(u8 *self)
{
    Sub_003F02D8 *sub = *(Sub_003F02D8 **)(self + 8);
    vu0_v4 d;
    vu0_v4 v;
    vu0_v4 w;
    Ent_003F02D8 *ent;
    s32 inside;
    s32 flags;
    f32 scale;
    f32 len;
    s32 a;
    s32 b;

    if (sub->w2C != -1) {
        {
            s32 idx = sub->sA;
            u8 *slot;

            if (idx != -1) {
                slot = D_001A30B0_003F02D8 + (idx << 7);
                if (*(u8 **)(slot + 0x100) == self && slot[0xD0]) func_003A4F28(idx);
            }
        }
        sub->sA = -1;
        {
            s32 idx = sub->sB;
            u8 *slot;

            if (idx != -1) {
                slot = D_001A30B0_003F02D8 + (idx << 7);
                if (*(u8 **)(slot + 0x100) == self && slot[0xD0]) func_003A4F28(idx);
            }
        }
        sub->k = sub->w2C;
        sub->sB = -1;
        sub->w2C = -1;
    }
    vec_sub_ba(&d, D_L01_001E29C0, self + 0x40);
    d.w = 0;
    inside = 1;
    func_0038D000(&v, &d, self + 0x50);
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
    ent = (Ent_003F02D8 *)(sub->ids[sub->k] * 32 + D_L01_001DFB6C_003F02D8);
    flags = 0;
    if (ent->f18) flags |= 4;
    if (inside == 1) {
        {
            s32 idx = sub->sA;
            u8 *slot;

            if (idx != -1) {
                slot = D_001A30B0_003F02D8 + (idx << 7);
                if (*(u8 **)(slot + 0x100) == self && slot[0xD0]) func_003A4F28(idx);
            }
        }
        sub->sA = -1;
        {
            s32 idx = sub->sB;
            u8 *slot;

            if (idx == -1 || (slot = D_001A30B0_003F02D8 + (idx << 7), *(u8 **)(slot + 0x100) != self) || slot[0xD0] == 0) {
                if (func_0038CAD0(&sub->s18)) {
                    sub->sB = func_L01_004AAE90(sub->ids[sub->k], flags | 0x110, self, 0x400);
                    if (sub->s14 > 0) {
                        sub->s18 = (s32)((sub->s10 + func_00382468(sub->s14 - sub->s10)) * 50.0f);
                    }
                }
            }
        }
        return;
    }
    scale = 1.0f;
    func_0038D000(&v, &v, self + 0x10);
    vec_add_ba(&v, &v, self + 0x40);
    vec_sub_ab(&w, D_L01_001E29C0, &v);
    len = func_0038CEA8(&w);
    if (ent->f4 < len) {
        {
            s32 idx = sub->sA;
            u8 *slot;

            if (idx != -1) {
                slot = D_001A30B0_003F02D8 + (idx << 7);
                if (*(u8 **)(slot + 0x100) == self && slot[0xD0]) func_003A4F28(idx);
            }
        }
        sub->sA = -1;
        {
            s32 idx = sub->sB;
            u8 *slot;

            if (idx != -1) {
                slot = D_001A30B0_003F02D8 + (idx << 7);
                if (*(u8 **)(slot + 0x100) == self && slot[0xD0]) func_003A4F28(idx);
            }
        }
        sub->sB = -1;
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
            s32 idx = sub->sB;
            u8 *slot;

            if (idx == -1 || (slot = D_001A30B0_003F02D8 + (idx << 7), *(u8 **)(slot + 0x100) != self) || slot[0xD0] == 0) {
                sub->sB = func_L01_004AAE90(sub->ids[sub->k], flags | 0x110, self, 0x400);
            }
        }
        func_003A53E8(sub->sB, b);
    } else {
        {
            s32 idx = sub->sB;
            u8 *slot;

            if (idx != -1) {
                slot = D_001A30B0_003F02D8 + (idx << 7);
                if (*(u8 **)(slot + 0x100) == self && slot[0xD0]) {
                    func_003A4F28(idx);
                    sub->sB = -1;
                }
            }
        }
        a = ent->fC * (1.0f - scale);
    }
    {
        s32 idx = sub->sA;
        u8 *slot;

        if (idx == -1 || (slot = D_001A30B0_003F02D8 + (idx << 7), *(u8 **)(slot + 0x100) != self) || slot[0xD0] == 0) {
            if (a > 0) sub->sA = func_L01_004AAE90(sub->ids[sub->k], flags | 0x10, self, 0x400);
        }
    }
    if (sub->sA != -1) {
        *(vu0_q *)(D_001A3190_003F02D8 + (sub->sA << 7)) = *(vu0_q *)&v;
    }
    func_003A53E8(sub->sA, a);
}
/* localdecomp:end func_L01_003F02D8 */
