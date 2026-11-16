#include "common.h"
#include "structs/moby.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L07_003AF398);

/* localdecomp:start func_L07_003AF600 */
void func_0038CB78(s32, s32, s32);
void func_L01_0043A430(void *, s32, s32);
void func_L01_004450F0(void *, s32, s32);
void func_L01_004AA760(s32, void *);

void func_L07_003AF600(void *arg0) {
    s32 temp_s0;

    if ((*(u8 *)((u8 *)arg0 + 0x20)) == 0) {
        temp_s0 = (*(s32 *)((u8 *)arg0 + 0x68)) + 0x90;
        func_0038CB78(temp_s0, 0, 0x40);
        func_L01_0043A430(arg0, 0, temp_s0);
        func_L01_004AA760(1, arg0);
        func_L01_004450F0(arg0, 1, -1);
    }
}
/* localdecomp:end func_L07_003AF600 */

/* localdecomp:start func_L07_003AF678 */
typedef struct {
    u8 pad[0x144];
    void *w144;
    s32 w148;
} Pool_003AF678;
extern u8 D_L07_001E1EC0[];

extern s32 func_L01_00456250(void *);
extern void func_L01_00456C98(void *, f32, f32, f32, s32, s32, s32, s32, s32,
                              s32, s32, s32, s32);
extern void func_L01_00404A10(void *, void *);
extern void func_L07_003AFC10(void *);

void func_L07_003AF678(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);

    if ((u32)(arg0[0x20] - 2) < 2 || func_L01_00456250(arg0) != 0) {
        func_L01_00456C98(arg0, 0.0f, 0.0f, 1.0f, *(s32 *)(p + 0xD0), 0, 1, 0, 0, 1,
                          0, 0, 0);
    }
    if (arg0[0x31] != 0) {
        func_L01_00404A10(func_L07_003AFC10, arg0);
    }
    if ((u32)(arg0[0x20] - 2) < 4) {
        if (((Pool_003AF678 *)D_L07_001E1EC0)->w144 == 0) {
            ((Pool_003AF678 *)D_L07_001E1EC0)->w144 = arg0;
            ((Pool_003AF678 *)D_L07_001E1EC0)->w148 = 0;
        }
    } else {
        if (((Pool_003AF678 *)D_L07_001E1EC0)->w144 == arg0) {
            ((Pool_003AF678 *)D_L07_001E1EC0)->w144 = 0;
        }
    }
}
/* localdecomp:end func_L07_003AF678 */

/* localdecomp:start func_L07_003AF758 */
extern s32 D_001A71A4[];
extern s32 func_L01_00456250(void *);
s32 func_L07_003AF758(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    s32 v;
    if (D_001A71A4[0] == 0x74) {
        return 0;
    }
    v = *(s16 *)(p + 0x44);
    if (v != 1) {
        return 0;
    }
    if (func_L01_00456250(arg0) == 0) {
        v = 0;
    }
    return v;
}
/* localdecomp:end func_L07_003AF758 */

/* localdecomp:start func_L07_003AF7B8 */
extern void func_0038D750(void *, s32, f32);
extern void func_0038D688(void *, void *, void *);
void func_L07_003AF7B8(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    f32 m[4];
    ((void (*)(void *, s32))func_0038D750)(m, 1);
    func_0038D688(p + 0xA0, p + 0xA0, m);
}
/* localdecomp:end func_L07_003AF7B8 */

INCLUDE_ASM("asm/levels", func_L07_003AF7F8);

INCLUDE_ASM("asm/levels", func_L07_003AF920);

INCLUDE_ASM("asm/levels", func_L07_003AFC10);

INCLUDE_ASM("asm/levels", func_L07_003AFD10);

/* localdecomp:start func_L07_003B0458 */
void func_L07_003B0530(void *);

void func_L07_003B0458(void *arg0) {
    if (*(u8 *)((u8 *)arg0 + 0x20) == 0) {
        u8 *s;
        u8 *p;
        s32 i;

        f32 f;
        u8 one;

        s = (u8 *)(*(s32 *)((u8 *)arg0 + 0x68));
        f = *(f32 *)((u8 *)arg0 + 0xF8);
        one = 1;
        s[0x3E] = 3;
        *(f32 *)(s + 0x90) = f;
        p = s + 0x44;
        s[0x3F] = 0;
        s[0x64] = 0;
        *(s32 *)(s + 0x94) = 0;
        i = 0;
        do {
            *p = one;
            p--;
            i--;
        } while (i >= 0);
        func_L07_003B0530(arg0);
    }
}
/* localdecomp:end func_L07_003B0458 */

/* localdecomp:start func_L07_003B04C8 */
void func_L07_003B04C8(u8 *a0, s32 a1) {
    u8 *base;
    u8 *a24;
    s32 f34;
    s32 t;
    s32 v;

    base = *(u8 **)(a0 + 0x68);
    if (*(u8 *)(base + a1 + 0x70) != 0) {
        f34 = *(u16 *)(a0 + 0x34);
        a24 = *(u8 **)(a0 + 0x24);
        t = f34 & 0xFFBE;
        *(u16 *)(a0 + 0x34) = t;
        t = t | (*(u16 *)(a24 + 0x44) & 0x1000);
        *(u16 *)(a0 + 0x34) = t;
        t = t & 0xFFFD;
        v = *(s32 *)(a24 + 0x10);
        *(u16 *)(a0 + 0x34) = t;
        *(s32 *)(a0 + 0x98) = v;
        base[0xA8] = 0;
        func_L01_004450F0(a0, 1, -1);
    }
}
/* localdecomp:end func_L07_003B04C8 */

/* localdecomp:start func_L07_003B0530 */
void func_L01_004AA7E8(void *, s32);
void func_L01_004450F0(void *, s32, s32);

void func_L07_003B0530(void *a0) {
    u8 *arg0 = (u8 *)a0;
    u8 *v1;

    *(s32 *)(arg0 + 0x98) = 0;
    v1 = *(u8 **)(arg0 + 0x68);
    *(u16 *)(arg0 + 0x34) = (*(u16 *)(arg0 + 0x34) | 0x43) & 0xEFFF;
    *(u8 *)(arg0 + 0xA8) = 0xFF;
    func_L01_004AA7E8(arg0, 1);
    *(f32 *)(arg0 + 0xF8) = *(f32 *)(v1 + 0x90);
    *(s32 *)(v1 + 0x94) = 0;
    func_L01_004450F0(arg0, 8, -1);
}
/* localdecomp:end func_L07_003B0530 */

/* localdecomp:start func_L07_003B05A0 */
s32 func_L07_003B05A0(void *arg0) {
    return (u32) ((*(u8 *)((u8 *)arg0 + 0x20)) - 7) < 2U;
}
/* localdecomp:end func_L07_003B05A0 */

/* localdecomp:start func_L07_003B05B0 */
s32 func_L01_00447490(void *, s32, s32);
void func_L01_00456BD0(void *, s32);
void func_L07_003B0458(void *);

s32 func_L07_003B05B0(void *arg0) {
    s32 kind = *(u8 *)((u8 *)arg0 + 0x20);

    if (kind == 0) {
        func_L07_003B0458(arg0);
        return 0;
    }
    kind -= 4;
    if ((u8)kind >= 2) {
        *(u8 *)((u8 *)arg0 + 0xA8) = 0xFF;
        *(u16 *)((u8 *)arg0 + 0x34) &= 0xEFFF;
        return 0;
    }
    {
        s32 r;

        *(u16 *)((u8 *)arg0 + 0x34) |= 0x1000;
        r = func_L01_00447490(arg0, 0x30000, 0);
        if (r != 0) {
            *(u8 *)((u8 *)arg0 + 0xA8) = 0xFF;
            func_L01_004450F0(arg0, 6, -1);
        }
        func_L01_00456BD0(arg0, 3);
        return 0;
    }
}
/* localdecomp:end func_L07_003B05B0 */

/* localdecomp:start func_L07_003B0660 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_003B0660;

extern void func_003C2F58(void *, s32, void *);
extern f32 func_00382538(void);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);

void func_L07_003B0660(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    V4_003B0660 v;
    f32 s1;
    f32 s2;

    s1 = (1.0f - (f32) * (s32 *)(p + 0xA0) / 50.0f) * 3.0f;
    func_003C2F58(arg0, 1, &v);
    func_003D9508(&v, 0x31, 0x60208040, 1, s1, 0.5f, func_00382538());
    s2 = s1 * 0.4f;
    func_003D9508(&v, 0x31, 0x7F208040, 1, s2, 0.5f, func_00382538());
}
/* localdecomp:end func_L07_003B0660 */

INCLUDE_ASM("asm/levels", func_L07_003B0738);

INCLUDE_ASM("asm/levels", func_L07_003B0970);

INCLUDE_ASM("asm/levels", func_L07_003B0B08);

INCLUDE_ASM("asm/levels", func_L07_003B0CF8);

INCLUDE_ASM("asm/levels", func_L07_003B0E08);

/* localdecomp:start func_L07_003B0F20 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003B0F20;
extern void func_003C2F58(void *, s32, void *);
extern void func_003C7C38(void *);
void func_L07_003B0F20(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    V4_003B0F20 v;
    func_003C2F58(arg0, 0, &v);
    *(V4_003B0F20 *)(*(u8 **)(p + 0x40) + 0x10) = v;
    func_003C7C38(*(u8 **)(p + 0x40));
    *(V4_003B0F20 *)(*(u8 **)(p + 0x44) + 0x10) = v;
    func_003C7C38(*(u8 **)(p + 0x44));
}
/* localdecomp:end func_L07_003B0F20 */

/* localdecomp:start func_L07_003B0F78 */
void func_003C7C38(void *);
void func_L07_003B0E08(void *, s32);

void func_L07_003B0F78(void *arg0) {
    void *temp_v0;

    temp_v0 = *(void **)((u8 *)arg0 + 0x68);
    *(s32 *)((u8 *)temp_v0 + 0x48) = 0;
    *(s32 *)((u8 *)((*(void **)((u8 *)temp_v0 + 0x44))) + 0xF0) = 0;
    func_003C7C38((*(void **)((u8 *)temp_v0 + 0x44)));
    func_L07_003B0E08(arg0, 1);
}
/* localdecomp:end func_L07_003B0F78 */

/* localdecomp:start func_L07_003B0FC0 */
/* from rac4-decomp's func_01EEBC54 */
void func_L07_003B0FC0(void *arg0) {
    func_L07_003B0E08(arg0, 3);
}
/* localdecomp:end func_L07_003B0FC0 */

INCLUDE_ASM("asm/levels", func_L07_003B0FE0);

/* localdecomp:start func_L07_003B12D8 */
extern s32 D_001A4F3C[];
extern u8 *func_L01_0045B958(u8 *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_003C2F58(void *, s32, void *);

s32 func_L07_003B12D8(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    f32 v[4];
    s32 i;
    s32 j;
    u8 *q;

    if (D_001A4F3C[0] == *(s32 *)(p + 0x40)) {
        return 0;
    }
    for (i = 0; i < 4; i++) {
        q = *(u8 **)(p + 0x20 + i * 4);
        if (q != 0 && q[0x20] >= 2 &&
            *(s32 *)(func_L01_0045B958(q) + 0x88) == *(s32 *)(p + 0x40)) {
            return 0;
        }
    }
    func_003C2F58(arg0, 1, v);
    for (j = 0; j < 4; j++) {
        q = *(u8 **)(p + 0x30 + j * 4);
        if (q != 0 && q[0x20] >= 2 &&
            func_L01_0040E548(q + 0x10, v) < 36.0f) {
            return 0;
        }
    }
    return 1;
}
/* localdecomp:end func_L07_003B12D8 */

INCLUDE_ASM("asm/levels", func_L07_003B13E8);

/* localdecomp:start func_L07_003B1578 */
typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x20];
    u8 f20;
};

/* from rac4-decomp's func_L05_004E00A8, renamed, constants adapted */
s32 func_L07_003B1578(Type1 *arg0) {
    s32 var_a0;
    u8 temp_v1;
    temp_v1 = arg0->f20;
    var_a0 = 0;
    if ((temp_v1 == 4) || (temp_v1 == 2) || (temp_v1 == 5)) {
        var_a0 = 1;
    }
    return var_a0;
}
/* localdecomp:end func_L07_003B1578 */

INCLUDE_ASM("asm/levels", func_L07_003B15A8);

INCLUDE_ASM("asm/levels", func_L07_003B1958);

INCLUDE_ASM("asm/levels", func_L07_003B1A30);

INCLUDE_ASM("asm/levels", func_L07_003B1C08);

INCLUDE_ASM("asm/levels", func_L07_003B24C8);

INCLUDE_ASM("asm/levels", func_L07_003B2738);

/* localdecomp:start func_L07_003B2870 */
extern void func_L07_003B2738(u8 *);
void func_L07_003B2870(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    arg0[0xBE] &= ~4;
    *(s32 *)(p + 0x14) = 0;
    func_L07_003B2738(arg0);
    func_L01_004450F0(arg0, 1, -1);
}
/* localdecomp:end func_L07_003B2870 */

/* localdecomp:start func_L07_003B28B8 */
typedef struct {
    char _p0[0x20];
    u8 state;
} S_3B28B8;

/* from rac4-decomp's func_L01_0045B5D8 */
s32 func_L07_003B28B8(S_3B28B8 *arg0) {
    return arg0->state < 2;
}
/* localdecomp:end func_L07_003B28B8 */

INCLUDE_ASM("asm/levels", func_L07_003B28C8);

/* localdecomp:start func_L07_003B3028 */
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern s32 func_L01_0044E7D8(void *);
extern void func_L07_003B34A0(u8 *);
extern void func_L07_003B3570(u8 *);

void func_L07_003B3028(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    u16 t;

    *(f32 *)(p + 0x40) = 1.0f;
    p[0x58] = 0x14;
    p[0x5A] = 0xE;
    p[0x3E] = 3;
    *(u16 *)(p + 0x672) = *(u16 *)(p + 0x34);
    p[0x3F] = 0;
    p[0x64] = 0;
    t = *(u16 *)(a0 + 0xB6);
    p[0x39] = 0;
    *(s32 *)(p + 0xD4) = 0;
    *(f32 *)(p + 0xA0) = 3.0f;
    *(f32 *)(p + 0xA4) = 1.0f;
    *(f32 *)(p + 0xA8) = 1.5f;
    *(f32 *)(p + 0xAC) = 0.25f;
    *(f32 *)(p + 0xB0) = 3.1415927f;
    *(f32 *)(p + 0xD0) = 0.17453292f;
    *(f32 *)(p + 0xCC) = 0.00392f;
    *(u16 *)(p + 0x674) = t;
    func_L01_0045BD78(a0, 0.008f, 0.20000002f, 0.0025132743f, 0.06283186f);
    *(void **)(p + 0x194) = func_L07_003B3570;
    *(void **)(p + 0x198) = func_L07_003B34A0;
    *(u8 *)(p + 0x1AD) = 0xFF;
    *(s16 *)(p + 0x19C) = -1;
    *(s32 *)(p + 0x67C) = func_L01_0044E7D8(a0);
    func_L07_003B34A0(a0);
}
/* localdecomp:end func_L07_003B3028 */

INCLUDE_ASM("asm/levels", func_L07_003B3160);

/* localdecomp:start func_L07_003B34A0 */
extern u8 D_L07_001E1EC0[];
extern void func_003C2C98(void *, void *);
extern void func_L07_00334740(void *);
extern void func_L07_003B37D0(u8 *, s32);

void func_L07_003B34A0(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    u8 *a = p + 0x1B0;
    u8 *b = p + 0x1B1;
    s32 i;

    for (i = 5; i >= 0; i--) {
        if (*b != 0) {
            func_003C2C98(arg0, a);
        }
        a += 0x40;
        b += 0x40;
    }
    if (p[0x391] != 0) {
        func_003C2C98(arg0, p + 0x390);
    }
    *(s32 *)(p + 0xD8) &= ~0x10;
    p[0x77] = 0;
    p[0x78] = 0;
    p[0x79] = 0;
    {
        u8 *g = D_L07_001E1EC0;

        if (*(u8 **)(g + 0x144) == arg0) {
            *(u8 **)(g + 0x144) = 0;
        }
    }
    func_L07_00334740(arg0);
    func_L07_003B37D0(arg0, 1);
}
/* localdecomp:end func_L07_003B34A0 */

INCLUDE_ASM("asm/levels", func_L07_003B3570);

/* localdecomp:start func_L07_003B3798 */
extern void func_L07_003B37D0(u8 *, s32);

void func_L07_003B3798(u8 *arg0, u8 arg1) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    s32 s = p[0x1AE] == 0 ? 4 : 5;

    arg0[0x95] = arg1;
    func_L07_003B37D0(arg0, s);
}
/* localdecomp:end func_L07_003B3798 */

INCLUDE_ASM("asm/levels", func_L07_003B37D0);

INCLUDE_ASM("asm/levels", func_L07_003B3A88);

INCLUDE_ASM("asm/levels", func_L07_003B3C78);

INCLUDE_ASM("asm/levels", func_L07_003B3DB0);

/* localdecomp:start func_L07_003B4250 */
extern f32 func_0038DBA0(f32, f32);
extern void func_L07_003B4978(void *, u8);

void func_L07_003B4250(u8 *obj) {
    u8 *base = *(u8 **)(obj + 0x68);
    s32 i;

    for (i = 0; i < 2; i++) {
        if ((base[0x667] >> i) & 1) {
            *(f32 *)(base + i * 0x80 + 0x434) = -1.5707964f;
            if (func_0038DBA0(*(f32 *)(base + i * 0x80 + 0x414), -1.5707964f) < 0.17453292f)
                func_L07_003B4978(obj, i);
        }
    }
}
/* localdecomp:end func_L07_003B4250 */

/* localdecomp:start func_L07_003B4308 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003B4308;
extern void func_003C2F58(void *, s32, void *);
extern u8 *func_L07_003BF158(u8 *, void *, void *, s32, u8, s32, s32);
void func_L07_003B4308(u8 *obj) {
    V4_003B4308 joint, sum;
    struct Moby *m = (struct Moby *)obj;
    u8 *p = m->pvar;
    func_003C2F58(obj, 13, (f32 *)&joint);
    vec_add_ba(&sum, &m->rotation, p + 0x610);
    func_L07_003BF158(obj, &joint, &sum, *(s32 *)(p + 0x90), p[0x45], 4, 0);
}
/* localdecomp:end func_L07_003B4308 */

/* localdecomp:start func_L07_003B4370 */
extern void func_L07_003B37D0(u8 *, s32);
extern s32 func_00382468(s32);

void func_L07_003B4370(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);

    switch (arg0[0x95]) {
    case 1:
        if (p[0x668] >= 6) {
            p[0x668] = 0;
            func_L07_003B37D0(arg0, 6);
            *(s16 *)(p + 0x660) = func_00382468(0x53) + 0xD0;
            break;
        }
        /* fall through */
    case 0:
        func_L07_003B37D0(arg0, 9);
        p[0x666] = 3;
        break;
    case 2:
        if (p[0x668] >= 3) {
            p[0x668] = 0;
            func_L07_003B37D0(arg0, 6);
            *(s16 *)(p + 0x660) = func_00382468(0xA7) + 0x1A1;
        } else {
            func_L07_003B37D0(arg0, 9);
            p[0x666] = func_00382468(2) + 3;
        }
        break;
    case 3:
        func_L07_003B37D0(arg0, 7);
        *(s16 *)(p + 0x660) = func_00382468(0x14D) + 0x341;
        break;
    }
}
/* localdecomp:end func_L07_003B4370 */

INCLUDE_ASM("asm/levels", func_L07_003B4470);

/* localdecomp:start func_L07_003B4688 */
extern void func_003C2F58(void *, s32, void *);

void func_L07_003B4688(void *arg0) {
    s32 i;
    u8 *p;

    i = 0;
    p = (u8 *)(*(s32 *)((u8 *)arg0 + 0x68)) + 0x330;
    do {
        func_003C2F58(arg0, i, p);
        i++;
        p += 0x10;
    } while (i < 6);
}
/* localdecomp:end func_L07_003B4688 */

INCLUDE_ASM("asm/levels", func_L07_003B46E8);

/* localdecomp:start func_L07_003B48E8 */
/* localdecomp:start func_L07_003B48E8 */
/* Fold x into [lo, hi]: relative position, absolute value, 0.4/0.5 wrap, sign back. */
f32 func_L07_003B48E8(f32 x, f32 lo, f32 hi) {
    f32 denom = hi - lo;
    f32 mid = (lo + hi) * 0.5f;
    f32 t;
    s32 neg = 0;

    t = x - mid / denom;
    if (t < 0.0f) {
        t = -t;
        neg = 1;
    }
    if (0.4f < t) {
        f32 u = (t - 0.4f) * 0.5f + 0.4f;

        if (0.5f < u)
            u = 0.5f;
        t = u;
    }
    if (neg)
        t = -t;
    return mid + denom * t;
}
/* localdecomp:end func_L07_003B48E8 */
/* localdecomp:end func_L07_003B48E8 */

INCLUDE_ASM("asm/levels", func_L07_003B4978);

/* localdecomp:start func_L07_003B4B68 */
void func_L07_003B4C30(void *, u8, f32, u8);

void func_L07_003B4B68(void *arg0, s16 arg1, f32 arg2) {
    s32 i;
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);

    if (arg1 != -1 && arg1 < 0x15) {
        return;
    }
    for (i = 0; i < 2; i++) {
        if ((arg1 & 3) == 0 && arg1 != -1) {
            func_L07_003B4C30(arg0, i, arg2, p[0x44]);
        } else {
            func_L07_003B4C30(arg0, i, arg2, 0);
        }
    }
}
/* localdecomp:end func_L07_003B4B68 */

INCLUDE_ASM("asm/levels", func_L07_003B4C30);

INCLUDE_ASM("asm/levels", func_L07_003B4DF8);

INCLUDE_ASM("asm/levels", func_L07_003B4FD0);

/* localdecomp:start func_L07_003B5CC8 */
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern s32 func_L01_0044E7D8(void *);
extern void func_L07_003B6320(u8 *);
extern void func_L07_003B62C8(u8 *);

void func_L07_003B5CC8(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    u16 t;

    p[0x58] = 0x14;
    p[0x5A] = 0xE;
    *(f32 *)(p + 0x40) = 1.0f;
    p[0x3E] = 3;
    *(u16 *)(p + 0x32C) = *(u16 *)(p + 0x34);
    p[0x3F] = 0;
    p[0x64] = 0;
    t = *(u16 *)(a0 + 0xB6);
    p[0x39] = 0;
    *(f32 *)(p + 0xA0) = 3.0f;
    *(f32 *)(p + 0xA4) = 1.2f;
    *(f32 *)(p + 0xA8) = 1.2f;
    *(f32 *)(p + 0xAC) = 1.2f;
    *(f32 *)(p + 0xB0) = 3.1415927f;
    *(f32 *)(p + 0xD0) = 0.7853982f;
    *(f32 *)(p + 0xCC) = 0.00392f;
    *(f32 *)(p + 0xD4) = 0.2f;
    *(u16 *)(p + 0x32E) = t;
    func_L01_0045BD78(a0, 0.072000005f, 0.40000004f, 0.0012566372f, 0.06283186f);
    *(void **)(p + 0x194) = func_L07_003B6320;
    *(void **)(p + 0x198) = func_L07_003B62C8;
    *(u8 *)(p + 0x1AD) = 0xFF;
    *(s16 *)(p + 0x19C) = -1;
    *(s32 *)(p + 0x33C) = func_L01_0044E7D8(a0);
    func_L07_003B62C8(a0);
}
/* localdecomp:end func_L07_003B5CC8 */

INCLUDE_ASM("asm/levels", func_L07_003B5E08);

/* localdecomp:start func_L07_003B62C8 */
extern u8 D_L07_001E1EC0[];
extern void func_L07_00334740(void *);
extern void func_L07_003B64D0(u8 *, s32);
void func_L07_003B62C8(u8 *arg0) {
    u8 *g = D_L07_001E1EC0;
    u8 *p = *(u8 **)(arg0 + 0x68);
    p[0x77] = 0;
    p[0x78] = 0;
    p[0x79] = 0;
    if (*(u8 **)(g + 0x144) == arg0) *(u8 **)(g + 0x144) = 0;
    func_L07_00334740(arg0);
    func_L07_003B64D0(arg0, 1);
}
/* localdecomp:end func_L07_003B62C8 */

INCLUDE_ASM("asm/levels", func_L07_003B6320);

INCLUDE_ASM("asm/levels", func_L07_003B64D0);

/* localdecomp:start func_L07_003B6800 */
extern f32 func_0038CF38(void *a, void *b);
extern f32 func_0038D160(f32 x, f32 y);

void func_L07_003B6800(u8 *arg0) {
    u8 *p;
    f32 v[3];
    f32 d;

    p = *(u8 **)(arg0 + 0x68);
    func_003C2F58(arg0, (u8)(p[0x31D] + 2), v);
    d = -func_0038D160(func_0038CF38(v, p + 0x80), *(f32 *)(p + 0x88) - v[2]);
    *(f32 *)(p + 0x294) = d;
    *(f32 *)(p + 0x214) = d * 1.4f;
}
/* localdecomp:end func_L07_003B6800 */

/* localdecomp:start func_L07_003B6870 */
extern void func_L01_0044E850(void *, void *, s32, f32, f32);

void func_L07_003B6870(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);

    func_L01_0044E850(a0, s + 0x1B0, 0, 0.0432f, 0.43200004f);
    func_L01_0044E850(a0, s + 0x230, 1, 0.0432f, 0.43200004f);
}
/* localdecomp:end func_L07_003B6870 */

/* localdecomp:start func_L07_003B68F0 */
extern f32 func_0038D160(f32, f32);
extern void func_L01_00448890(char *a0, char *a1, int a2, float f12, float f13,
                              float f14, float f15);

void func_L07_003B68F0(u8 *arg0) {
    u8 *s;
    u8 *p;
    u8 *q;
    u8 flag;
    f32 r;

    s = *(u8 **)(arg0 + 0x68);
    flag = s[0x323];
    if (0.0f < *(f32 *)(s + 0x148)) {
        if (flag & 1) {
            p = *(u8 **)(s + 0x190) + 0x10;
        } else {
            p = s + 0x80;
        }
    } else {
        if (flag & 2) {
            p = *(u8 **)(s + 0x190) + 0x10;
        } else {
            p = s + 0x80;
        }
    }
    q = arg0 + 0xF8;
    r = func_0038D160(*(f32 *)p - *(f32 *)(arg0 + 0x10),
                      *(f32 *)(p + 4) - *(f32 *)(arg0 + 0x14));
    func_L01_00448890((char *)q, (char *)s + 0x154, 0, r,
                      *(f32 *)(s + 0xB4), *(f32 *)(s + 0xB8), *(f32 *)(s + 0xBC));
}
/* localdecomp:end func_L07_003B68F0 */

/* localdecomp:start func_L07_003B6998 */
extern f32 func_0038D160(f32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern void func_L03_0032FAF0(f32 *, f32 *, f32, f32);
extern void func_L07_003B64D0(u8 *, s32);

void func_L07_003B6998(u8 *arg0) {
    u8 *s = *(u8 **)(arg0 + 0x68);
    f32 a = func_0038D160(
        *(f32 *)(s + 0x80) - *(f32 *)(*(u8 **)(s + 0x190) + 0x10),
        *(f32 *)(s + 0x84) - *(f32 *)(*(u8 **)(s + 0x190) + 0x14));
    f32 b = func_0038D160(
        *(f32 *)(arg0 + 0x10) - *(f32 *)(*(u8 **)(s + 0x190) + 0x10),
        *(f32 *)(arg0 + 0x14) - *(f32 *)(*(u8 **)(s + 0x190) + 0x14));
    f32 r = func_003824E0(1.3962633609771729f, 2.7925267219543457f);

    if (0.0f < func_0038DB00(b, a)) {
        r = func_0038DAB8(b, r);
    } else {
        r = func_0038DB00(b, r);
    }
    func_L03_0032FAF0((f32 *)(s + 0x2F0), (f32 *)(*(u8 **)(s + 0x190) + 0x10),
                      (f32)(s32)(r / 0.785398006439209f) * 0.785398006439209f,
                      20.0f);
    s[0x323] = 0;
    s[0x322] = 0xFF;
    func_L07_003B64D0(arg0, 0x13);
}
/* localdecomp:end func_L07_003B6998 */

/* localdecomp:start func_L07_003B6AE8 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *D_L07_001DF500_003B6AE8;
extern void func_L07_003B64D0(u8 *, s32);

void func_L07_003B6AE8(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);

    p[0x324] = 0;
    *(u128_t *)(p + 0x2F0) = *(u128_t *)(&D_L07_001DF500_003B6AE8[(*(s32 *)(p + 0x30C) << 7) + 0x30]);
    p[0x323] = 2;
    p[0x322] = 0x16;
    func_L07_003B64D0(a0, 0x13);
}
/* localdecomp:end func_L07_003B6AE8 */

INCLUDE_ASM("asm/levels", func_L07_003B6B38);

/* localdecomp:start func_L07_003B6BD8 */
extern void func_L07_003B64D0(u8 *, s32);
extern s32 func_L07_003A2380(u8, s32, u8, s16);
extern s32 func_00382468(s32);
extern void func_L01_00456230(void *, s32);

void func_L07_003B6BD8(u8 *arg0, s32 arg1) {
    u8 *s = *(u8 **)(arg0 + 0x68);
    u32 diff = (u32)s[0x31F] ^ (u32)arg1;
    s32 changed = diff != 0;

    if (changed) {
        f32 t = *(f32 *)(s + 0x30);

        s[0x31F] = arg1;
        *(f32 *)(s + 0x310) = t;
        s[0x320] = 0;
    }
    if (arg1 == 0) {
        if (changed || func_00382468(4) == 0) {
            func_L07_003B64D0(arg0, 6);
        } else {
            func_L07_003B64D0(arg0, 7);
        }
    } else if (arg1 == 1) {
        if (*(s16 *)(s + 0x328) == 0) {
            func_L07_003A2380(4, (s32)arg0, 0, 0x64);
            *(s16 *)(s + 0x328) = 0x1F4;
        }
        if (changed || func_00382468(4) == 0) {
            func_L07_003B64D0(arg0, 0xB);
        } else {
            func_L07_003B64D0(arg0, 0xC);
        }
    }
    func_L01_00456230(arg0, 0);
}
/* localdecomp:end func_L07_003B6BD8 */

/* localdecomp:start func_L07_003B6CD8 */
extern u8 *D_L07_001DF41C_003B6CD8;
extern s32 func_L01_00456250(void *);
extern s32 func_L07_003A2380(u8, s32, u8, s16);

s32 func_L07_003B6CD8(u8 *arg0, u8 arg1) {
    u8 *s = *(u8 **)(arg0 + 0x68);
    u8 *p;
    f32 d;

    if (s[0x321] != 0) {
        return 0;
    }
    if (s[0x320] >= 4) {
        return 1;
    }
    if (func_L01_00456250(arg0) != 0) {
        if (*(s16 *)(s + 0x32A) == 0) {
            p = D_L07_001DF41C_003B6CD8 + (*(s32 *)(s + 0x300) << 8);
            if (p[0xBC] == 0) {
                p[0xBC] = 1;
            }
            func_L07_003A2380(0xC, (s32)p, 0, 0x64);
            *(s16 *)(s + 0x32A) = 0x3E8;
        }
        return 1;
    }
    if (arg1 != 0) {
        return 0;
    }
    d = *(f32 *)(s + 0x310) - *(f32 *)(s + 0x30);
    if ((f32)*(s16 *)(s + 0x34) * 0.1f < d) {
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L07_003B6CD8 */

/* localdecomp:start func_L07_003B6DC8 */
extern f32 func_0038CF38(void *a, void *b);
extern f32 func_0038D160(f32 x, f32 y);
extern f32 func_0038DAB8(f32 a, f32 b);

f32 func_L07_003B6DC8(u8 *arg0, u8 *arg1) {
    f32 t;
    f32 off;
    f32 a;

    t = func_0038CF38(arg0 + 0x10, arg1) / 50.0f;
    if (t > 1.0f) {
        t = 1.0f;
    } else if (t < 0.0f) {
        t = 0.0f;
    }
    off = t * -0.139626339f + 0.17453292f;
    a = func_0038D160(*(f32 *)(arg1 + 0) - *(f32 *)(arg0 + 0x10),
                      *(f32 *)(arg1 + 4) - *(f32 *)(arg0 + 0x14));
    return func_0038DAB8(a, off);
}
/* localdecomp:end func_L07_003B6DC8 */

INCLUDE_ASM("asm/levels", func_L07_003B6E98);

INCLUDE_ASM("asm/levels", func_L07_003B70F0);

/* localdecomp:start func_L07_003B7230 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_003B7230;

typedef struct {
    V4_003B7230 v;
    void *owner;
    s32 f14;
    u8 f18;
    u8 f19;
    u16 f1A;
    f32 f1C;
    s32 f20;
    f32 f24;
    s32 f28;
} S_003B7230;

extern void func_0038CE20(void *, void *, f32);
extern void func_003C2F58(void *, s32, void *);
extern s32 func_003D4D00(void *, s32, f32, void *, void *);

void func_L07_003B7230(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    S_003B7230 s;
    V4_003B7230 v;

    s.owner = arg0;
    s.f1A = *(u16 *)(arg0 + 0xAA);
    s.f24 = (f32)p[0x46];
    s.f1C = (f32)p[0x46];
    s.f14 = 1;
    s.f20 = 1;
    s.f19 = 2;
    s.f28 = -1;
    s.f18 = 0;
    func_0038CE20(&s.v, arg0 + 0xC0, 6.0f);
    s.v.z = 2.0f;
    s.v.w = 5627.925f;
    func_003C2F58(arg0, 1, &v);
    func_003D4D00(&v, 0, 2.0f, arg0, &s);
    func_003C2F58(arg0, 0xC, &v);
    func_003D4D00(&v, 0, 2.5f, arg0, &s);
    func_003C2F58(arg0, 0xD, &v);
    func_003D4D00(&v, 0, 2.5f, arg0, &s);
}
/* localdecomp:end func_L07_003B7230 */

/* localdecomp:start func_L07_003B7378 */
extern void func_L07_003B7408(void *, s32, f32, f32);

void func_L07_003B7378(void *self) {
    f32 a;
    f32 b;

    func_L07_003B7408(self, 14, 1.0f, 0.43633232f);
    a = 0.4f;
    b = 0.7853982f;
    func_L07_003B7408(self, 15, a, b);
    func_L07_003B7408(self, 16, a, b);
}
/* localdecomp:end func_L07_003B7378 */
