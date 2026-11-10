#include "common.h"
typedef struct { s32 id; s32 x4[4]; } Rec14;

INCLUDE_ASM("asm/levels", func_L23_003A6688);

/* localdecomp:start func_L23_003A6838 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct {
    s32 count;
    u8 pad4[0xC];
    V4 pts[1];
} Path_3A6838;
extern void *D_L23_0021D380[];
__asm__(".extern D_L23_001DE0C0, 4");
extern s32 D_L23_001DE0C0;
extern f32 func_0038CEA8(void *);
extern void func_003C4098(void *, void *, void *, f32);

void func_L23_003A6838(void *out, s32 idx, f32 dist, f32 *lens, s32 n) {
    Path_3A6838 *path;
    V4 a;
    V4 b;
    V4 d;
    f32 len;
    s32 i;

    path = D_L23_0021D380[idx];
    a = path->pts[0];
    if (D_L23_001DE0C0 < path->count) {
        D_L23_001DE0C0 = path->count;
    }
    for (i = 1; i < path->count; i++) {
        b = path->pts[i];
        if (lens == 0 || n < i) {
            vec_sub_ab(&d, &b, &a);
            len = func_0038CEA8(&d);
        } else {
            len = lens[i - 1];
        }
        if (dist < len) {
            func_003C4098(out, &a, &b, dist / len);
            return;
        }
        dist -= len;
        a = b;
    }
}
/* localdecomp:end func_L23_003A6838 */

/* localdecomp:start func_L23_003A6970 */
#include "vu0.h"
typedef struct {
    s32 count;
    u8 p4[0xC];
    vu0_v4 points[1];
} Path_003A6970;


extern void *D_L23_0021D380[];
extern f32 func_0038CEA8(void *);

f32 func_L23_003A6970(s32 index, f32 *lengths, s32 max) {
    Path_003A6970 *path = D_L23_0021D380[index];
    vu0_v4 prev;
    vu0_v4 cur;
    vu0_v4 d;
    f32 total = 0.0f;
    f32 len;
    s32 i;

    prev = path->points[0];
    for (i = 1; i < path->count; i++) {
        cur = path->points[i];
        vec_sub_ab(&d, &cur, &prev);
        len = func_0038CEA8(&d);
        total += len;
        if (lengths != 0 && i <= max) {
            lengths[i - 1] = len;
        }
        prev = cur;
    }
    return total;
}
/* localdecomp:end func_L23_003A6970 */

INCLUDE_ASM("asm/levels", func_L23_003A6A60);

/* localdecomp:start func_L23_003A6B98 */
extern u8 D_L23_001FDA19[];
extern u8 *D_L23_001FB440[];
extern s32 D_L23_001DE0D0;
__asm__(".extern D_L23_001DE0D0, 4");
extern s32 func_003A4FF8(u8 *, s32, s32, void *, s32);
extern void func_L01_004AB048(s32, s32);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_L23_003A6B98(u8 *self, f32 scale)
{
    s32 r;

    r = func_003A4FF8(*(u8 **)(D_L23_001FB440[D_L23_001FDA19[0]] + 0x28), 0, 0, self, 0x400);
    if (r >= 0 && scale > 1.5f)
        func_L01_004AB048(r, D_L23_001DE0D0);
    func_L01_003303B8(self, scale > 1.5f, 4, 10, 2, 10, 20, 4, scale, 0.0f, 0.0f, 0.0f,
                      0, 1, scale > 2.0f, 0, 1, 0, 0, 0, 0x388EF7, 0x63F7, 0x70000000, 0x700020FF, 0x8FAF,
                      0x70303280, 0x7F004020, 0x280000FF, 0x3064FF, 0);
}
/* localdecomp:end func_L23_003A6B98 */

/* localdecomp:start func_L23_003A6D18 */
extern s32 D_L23_001DE0D8;
__asm__(".extern D_L23_001DE0D8, 4");
extern s32 D_L23_001DEC40;

void func_L23_003A6D18(u8 *self)
{
    *(f32 *)(self + 0xF4) = (f32)(D_L23_001DEC40 % D_L23_001DE0D8) * 6.2831855f / (f32)D_L23_001DE0D8 + -3.1415927f;
}
/* localdecomp:end func_L23_003A6D18 */

/* localdecomp:start func_L23_003A6D70 */
extern f32 D_L23_001DE0DC;
extern f32 D_L23_001DE0E0;
__asm__(".extern D_L23_001DE0DC, 4");
__asm__(".extern D_L23_001DE0E0, 4");
extern s32 func_L01_00456250(void *);
extern s32 func_L01_004561B8(u8 *);
extern void func_003A52A0(s32, s32, void *);
extern f32 func_L01_00448890(u8 *a0, u8 *a1, f32 f12, f32 f13, f32 f14, f32 f15, s32 a2);
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L23_003A6D70(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    switch (m[0x20]) {
    case 0:
        if (func_L01_00456250(m) != 0) {
            func_L01_004450F0(m, 1, -1);
        }
        break;
    case 1:
        if (func_L01_004561B8(m) != 0) {
            func_003A52A0(0, 0, m);
            *(s32 *)v = 0;
        }
        if (func_L01_00448890(m + 0xF8, v, 1.3962634f, D_L23_001DE0DC, D_L23_001DE0DC, D_L23_001DE0E0, 0) <= 0.0f) {
            func_L01_004450F0(m, 2, -1);
        }
        break;
    case 2:
        *(u16 *)(m + 0x34) |= 2;
        break;
    }
}
/* localdecomp:end func_L23_003A6D70 */

/* localdecomp:start func_L23_003A6E68 */
extern f32 D_L23_001DE0E4;
extern f32 D_L23_001DE0E8;
__asm__(".extern D_L23_001DE0E4, 4");
__asm__(".extern D_L23_001DE0E8, 4");
extern s32 func_L01_00456250(void *);
extern s32 func_L01_004561B8(u8 *);
extern f32 func_L01_00448890(u8 *a0, u8 *a1, f32 f12, f32 f13, f32 f14, f32 f15, s32 a2);
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L23_003A6E68(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    switch (m[0x20]) {
    case 0:
        if (func_L01_00456250(m) != 0) {
            func_L01_004450F0(m, 1, -1);
        }
        break;
    case 1:
        if (func_L01_004561B8(m) != 0) {
            *(s32 *)v = 0;
        }
        if (func_L01_00448890(m + 0xF8, v, -1.3962634f, D_L23_001DE0E4, D_L23_001DE0E4, D_L23_001DE0E8, 0) >= 0.0f) {
            func_L01_004450F0(m, 2, -1);
        }
        break;
    case 2:
        *(u16 *)(m + 0x34) |= 2;
        break;
    }
}
/* localdecomp:end func_L23_003A6E68 */

/* localdecomp:start func_L23_003A6F50 */
__asm__(".extern D_L23_001DE0EC, 4");
__asm__(".extern D_L23_001DE0F0, 4");
extern f32 D_L23_001DE0EC;
extern f32 D_L23_001DE0F0;
extern s32 func_L01_00456250(void *);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern f32 func_L01_00448890(u8 *a0, u8 *a1, f32 f12, f32 f13, f32 f14, f32 f15, s32 a2);

void func_L23_003A6F50(u8 *self)
{
    u8 *s = *(u8 **)(self + 0x68);

    if (self[0x20] == 0) {
        *(s32 *)s = 0;
        func_L01_004450F0(self, 1, -1);
    } else if (self[0x20] == 1) {
        *(f32 *)(self + 0xF4) = 1.5707964f;
        if (func_L01_00456250(self)) {
            func_003A52A0(0, 0, self);
            func_L01_004450F0(self, 2, -1);
        }
    } else if (self[0x20] == 3) {
        *(f32 *)(self + 0xF4) = 0.0f;
        *(u16 *)(self + 0x34) |= 2;
    } else if (self[0x20] == 2) {
        func_L01_00448890(self + 0xF4, s, 0.0f, D_L23_001DE0EC, D_L23_001DE0EC, D_L23_001DE0F0, 0);
        if (*(f32 *)(self + 0xF4) == 0.0f)
            func_L01_004450F0(self, 3, -1);
    }
}
/* localdecomp:end func_L23_003A6F50 */

INCLUDE_ASM("asm/levels", func_L23_003A7048);

INCLUDE_ASM("asm/levels", func_L23_003A77F0);

INCLUDE_ASM("asm/levels", func_L23_003A7908);

INCLUDE_ASM("asm/levels", func_L23_003A7A90);

INCLUDE_ASM("asm/levels", func_L23_003A8028);

INCLUDE_ASM("asm/levels", func_L23_003A97B8);

/* localdecomp:start func_L23_003A9C40 */
extern u16 **D_L23_001D6764;
__asm__(".extern D_L23_001D6764, 16");
extern u8 *D_L23_001E0014;
__asm__(".extern D_L23_001E0014, 16");
extern s16 D_L23_0023A3C0[];
extern Rec14 D_L23_002BC7F8[];

s32 func_L23_003A9C40(s32 idx)
{
    u16 *p = D_L23_001D6764[idx];
    u8 *e;
    s32 id;
    s32 i;

    while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D6764[idx])) {
        e = D_L23_001E0014 + ((*p & 0x7FFF) << 5);
        if (e == 0)
            break;
        id = D_L23_0023A3C0[e[0x1D]];
        for (i = 0; D_L23_002BC7F8[i].id >= 0; i++) {
            if (id == D_L23_002BC7F8[i].id)
                return 1;
        }
        p++;
    }
    return 0;
}
/* localdecomp:end func_L23_003A9C40 */

INCLUDE_ASM("asm/levels", func_L23_003A9D00);
