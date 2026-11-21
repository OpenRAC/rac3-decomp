#include "common.h"

/* localdecomp:start func_L01_0043B260 */
#include "vu0.h"
typedef struct {
    s32 w0;
    u16 x, y, z;
    s16 hA;
    s16 hC;
    u8 bE;
    u8 bF;
    u8 col[3];
    u8 rgb[3];
    u8 b16;
    u8 b17, b18, b19;
    s16 h1A;
    s16 h1C;
    u8 pad1E[2];
} Pt_0043B260;
extern s32 D_L01_001E00B4_0043B260;
extern Pt_0043B260 *D_L01_001E00C0_0043B260;
extern s32 D_L01_001D6694_0043B260;
typedef struct {
    u8 p0[0x40];
    u8 r, g, b;
    u8 flags;
    u8 p44[0x70];
    s32 fB4;
} S_1A30B0_0043B260;
extern S_1A30B0_0043B260 D_001A30B0;
extern u8 D_L01_001DF9E4_0043B260;
extern u8 D_L01_001DF9E5_0043B260;
extern u8 D_L01_001DF9E6_0043B260;
extern f32 D_L01_001DF9E8_0043B260;
extern f32 D_L01_001DF9EC_0043B260;
extern f32 D_L01_001DF9F0_0043B260;
extern f32 D_L01_001DF9F4_0043B260;
extern f32 func_L01_0040E4C0_0043B260(void *);
extern void func_003C6F90(void *, s32, s32, s32, s32);
extern void func_003A1930(s32, s32, s32);
extern void func_003864C0(s32);

void func_L01_0043B260(u8 *self) {
    vu0_v4 p;
    vu0_v4 diff;
    s32 i;
    s32 best = -1;
    f32 bestd = 1000000.0f;
    f32 d;

    for (i = 0; i < D_L01_001E00B4_0043B260; i++) {
        p.x = D_L01_001E00C0_0043B260[i].x * 0.25f;
        p.y = D_L01_001E00C0_0043B260[i].y * 0.25f;
        p.z = D_L01_001E00C0_0043B260[i].z * 0.25f;
        vec_sub_ab(&diff, self + 0x10, &p);
        d = func_L01_0040E4C0_0043B260(&diff);
        if (d < bestd) {
            bestd = d;
            best = i;
        }
    }
    if (best == -1 || 400.0f < bestd) {
        return;
    }
    func_003C6F90(self, (D_L01_001E00C0_0043B260[best].col[2] << 16) + (D_L01_001E00C0_0043B260[best].col[1] << 8) | D_L01_001E00C0_0043B260[best].col[0], 0, 0, 0);
    *(s32 *)(self + 0x38) = D_L01_001E00C0_0043B260[best].w0;
    if (D_L01_001D6694_0043B260 != 2) {
        if (D_L01_001E00C0_0043B260[best].b16 != 0) {
            D_001A30B0.fB4 = D_L01_001E00C0_0043B260[best].hA;
            D_001A30B0.r = D_L01_001E00C0_0043B260[best].rgb[0];
            D_001A30B0.g = D_L01_001E00C0_0043B260[best].rgb[1];
            D_001A30B0.b = D_L01_001E00C0_0043B260[best].rgb[2];
            D_001A30B0.flags |= 7;
        }
    }
    if (D_L01_001D6694_0043B260 != 2) {
        func_003A1930(D_L01_001E00C0_0043B260[best].hC, 1, 0x400);
    }
    if (D_L01_001E00C0_0043B260[best].h1A < D_L01_001E00C0_0043B260[best].h1C) {
        D_L01_001DF9E4_0043B260 = D_L01_001E00C0_0043B260[best].b17;
        D_L01_001DF9E5_0043B260 = D_L01_001E00C0_0043B260[best].b18;
        D_L01_001DF9E6_0043B260 = D_L01_001E00C0_0043B260[best].b19;
        D_L01_001DF9E8_0043B260 = D_L01_001E00C0_0043B260[best].h1A * 1024.0f;
        D_L01_001DF9EC_0043B260 = D_L01_001E00C0_0043B260[best].h1C * 1024.0f;
        D_L01_001DF9F0_0043B260 = D_L01_001E00C0_0043B260[best].bE;
        D_L01_001DF9F4_0043B260 = D_L01_001E00C0_0043B260[best].bF;
        func_003864C0(0);
    }
}
/* localdecomp:end func_L01_0043B260 */

/* localdecomp:start func_L01_0043B510 */
extern u8 D_001BBC40[];
extern s32 D_001D545C;

void func_L01_0043B510(s32 arg0) {
    u8 *temp_v0;

    if (arg0 != 0xFF) {
        temp_v0 = arg0 + (D_001D545C * 0x10) + D_001BBC40;
        *temp_v0 |= 0x80;
    }
}
/* localdecomp:end func_L01_0043B510 */

/* localdecomp:start func_L01_0043B548 */
extern s32 func_L01_0043B568(s32 a0, s32 a1);
void func_L01_0043B548(void *p, s32 a) {
    ((void (*)(void *, s32, s32))func_L01_0043B568)(p, 0, a);
}
/* localdecomp:end func_L01_0043B548 */

/* localdecomp:start func_L01_0043B568 */
typedef s32 (*Fn438488)(s32, s32, void *);
extern u8 *func_L01_0045E420(s32);

s32 func_L01_0043B568(s32 a0, s32 a1) {
    s32 buf[4];
    u8 *p;
    p = func_L01_0045E420(a0);
    if (p == 0) {
        return 0;
    }
    if (*(Fn438488 *)(p + 24) == 0) {
        return 0;
    }
    return (*(Fn438488 *)(p + 24))(a0, a1, buf);
}
/* localdecomp:end func_L01_0043B568 */

/* localdecomp:start func_L01_0043B5C8 */
extern s32 D_L01_001E005C;
extern s32 D_L01_001E0058;
extern s32 D_L01_0021DE20[];
extern s32 D_L01_001E00C8;
void func_L01_0043B5C8(void) {
    s32 i;
    for (i = D_L01_001E005C; i < D_L01_001E0058; i++) {
        D_L01_0021DE20[i] = 0;
    }
    D_L01_001E00C8 = 0;
}
/* localdecomp:end func_L01_0043B5C8 */

/* localdecomp:start func_L01_0043B618 */
extern s32 D_L01_001E005C;
extern s32 D_L01_0021DE20[];
extern s32 D_L01_001E00C8;
typedef struct { s16 v[24]; } Ent_0043B618;
extern Ent_0043B618 D_L01_0021E260_0043B618[];
extern u8 *D_L01_001E001C;

s32 func_L01_0043B618(u8 *obj) {
    s32 i;
    s32 idx;

    for (i = 0; i < 32; i++) {
        idx = D_L01_001E005C + (D_L01_001E00C8 + i) % 32;
        if (D_L01_0021DE20[idx] == 0) {
            break;
        }
    }
    if (i == 32) {
        return 0xFF;
    }
    i = (D_L01_001E00C8 + i) % 32;
    D_L01_001E00C8 = (i + 1) % 32;
    *(Ent_0043B618 **)&D_L01_0021DE20[idx] = &D_L01_0021E260_0043B618[i];
    (*(Ent_0043B618 **)&D_L01_0021DE20[idx])->v[0] = ((obj - D_L01_001E001C) >> 8) | 0x8000;
    obj[33] = idx;
    return idx;
}
/* localdecomp:end func_L01_0043B618 */

LINKER_REMNANT("asm/levels", func_L01_0043B748);

/* localdecomp:start func_L01_0043B750 */
extern s32 D_L01_0021DE20[];
typedef struct { s16 v[24]; } Ent_00438670;
extern Ent_00438670 D_L01_0021E260[];
extern s32 D_L01_001E005C;
extern u8 *D_L01_001E001C;
s32 func_L01_0043B750(s32 idx, u8 *obj) {
    Ent_00438670 **slot;
    Ent_00438670 *e;
    Ent_00438670 *n;
    s32 i;
    slot = (Ent_00438670 **)((u8 *)((Ent_00438670 * *)&D_L01_0021DE20) + idx * 4);
    if (*slot == 0) {
        n = (Ent_00438670 *)((u8 *)D_L01_0021E260 + (idx - D_L01_001E005C) * 48);
        *slot = n;
        n->v[0] = ((obj - D_L01_001E001C) >> 8) | 0x8000;
        obj[33] = idx;
        return 1;
    }
    e = (Ent_00438670 *)((u8 *)D_L01_0021E260 + (idx - D_L01_001E005C) * 48);
    for (i = 0; i < 23; i++) {
        if (e->v[i] & 0x8000) {
            e->v[i] &= 0x7FFF;
            i++;
            *(s16 *)((u8 *)e + i * 2) = ((obj - D_L01_001E001C) >> 8) | 0x8000;
            obj[33] = idx;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_0043B750 */

/* localdecomp:start func_L01_0043B840 */
extern s32 D_L01_0021DE20[];
extern Ent_00438670 D_L01_0021E260[];
typedef struct { s16 v[24]; } Ent_00438760;
extern s32 D_L01_001E005C;
extern u8 *D_L01_001E001C;
s32 func_L01_0043B840(s32 idx, u8 *obj) {
    Ent_00438760 *e;
    s32 key;
    s32 i;
    if (*(Ent_00438760 **)((u8 *)((Ent_00438760 * *)&D_L01_0021DE20) + idx * 4) == 0) {
        return 0;
    }
    e = (Ent_00438760 *)((u8 *)((Ent_00438760 *)&D_L01_0021E260) + (idx - D_L01_001E005C) * 48);
    key = (obj - D_L01_001E001C) >> 8;
    for (i = 0; i < 24; i++) {
        if ((e->v[i] & 0x7FFF) == key) {
            obj[33] = 0xFF;
            if (e->v[i] & 0x8000) {
                if (i == 0) {
                    *(Ent_00438760 **)((u8 *)((Ent_00438760 * *)&D_L01_0021DE20) + idx * 4) = 0;
                } else {
                    e->v[i - 1] |= 0x8000;
                }
            } else {
                for (; i < 23; i++) {
                    e->v[i] = e->v[i + 1];
                }
            }
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_0043B840 */

/* localdecomp:start func_L01_0043B930 */
extern s32 D_L01_0021DE20[];

s32 func_L01_0043B930(s32 a0) {
    if (a0 == 255) {
        return 1;
    }
    return D_L01_0021DE20[a0] == 0;
}
/* localdecomp:end func_L01_0043B930 */
