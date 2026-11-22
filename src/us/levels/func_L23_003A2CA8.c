#include "common.h"
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x10];
    u8 x10;
    u8 pad11[0x1F];
    f32 x30;
    f32 x34;
    s16 x38;
    u8 pad3A[0x2];
    f32 x3C;
    u8 pad40[0x8];
    u8 x48;
    u8 pad49[0xE0 - 0x49];
} Move_3A5008;
typedef struct {
    u8 x0[0x10];
    u8 x10[0x30];
} Node_3A5008;
typedef struct {
    u8 pad0[0x30];
    f32 x30;
    s16 x34;
    u8 pad36[0x3A];
    f32 x70;
    f32 x74;
    f32 x78;
    f32 x7C;
    f32 x80;
    u8 pad84[0x18];
    s32 x9C;
    f32 xA0;
    f32 xA4;
    s32 xA8;
    u8 padAC[0xB4];
    Move_3A5008 x160;
    s32 x240;
    f32 x244;
    s32 x248;
    s32 x24C;
    s32 x250;
    f32 x254;
    u8 pad258[0x4];
    f32 x25C;
    Node_3A5008 x260;
    s32 x2A0;
    s32 x2A4;
    u8 pad2A8[0x4];
    s32 x2AC;
    u8 x2B0[16];
    f32 x2C0[4];
    u8 x2D0[16];
} S_3A5008;
typedef struct { f32 v[4]; } __attribute__((aligned(16))) V4_3A4460;
typedef struct {
    u8 p0[0x80];
    V4_3A4460 v80;
    V4_3A4460 v90;
    u8 pA0[0x40];
    V4_3A4460 vE0;
} Hero_3A4460;
typedef struct { u8 pad0[0x12]; s16 count; u8 pad14[0xC]; s32 *ids; u8 pad24[0xC]; } Path_3A4460;
typedef struct { s32 count; u8 pad4[0x1C]; Path_3A4460 paths[1]; } Paths_3A4460;
typedef struct { u8 pad0[0x30]; V4_3A4460 pos; u8 pad40[0x40]; } Node_3A4460;

extern s32 D_L23_001DE0D8_003A2CA8;
extern s32 D_L23_001DE0DC_003A2CA8;
extern f32 D_L23_001DE0E0_003A2CA8;

/* localdecomp:start func_L23_003A2CA8 */
#include "common.h"
#include "vu0.h"


extern Hero_3A4460 D_001A4BE0;
extern s32 D_001A71A0[];
extern s32 D_L23_001DECC0;
extern u8 *D_L23_001DE310;
extern u8 *D_L23_001DE2D0_3A4460;
__asm__(".extern D_L23_001DE2D0_3A4460, 4");
extern f32 D_L23_001DE070;
__asm__(".extern D_L23_001DE070, 4");
extern f32 D_L23_001DE074;
__asm__(".extern D_L23_001DE074, 4");
extern f32 D_L23_001DE078_003A2CA8;
__asm__(".extern D_L23_001DE078_003A2CA8, 4");
extern f32 D_L23_001DE07C_003A2CA8;
__asm__(".extern D_L23_001DE07C_003A2CA8, 4");
extern f32 D_L23_001DE080_003A2CA8;
__asm__(".extern D_L23_001DE080_003A2CA8, 4");
extern f32 D_L23_001DE084_003A2CA8;
__asm__(".extern D_L23_001DE084_003A2CA8, 4");
extern f32 D_L23_001DE088_003A2CA8;
__asm__(".extern D_L23_001DE088_003A2CA8, 4");
extern f32 D_L23_001DE08C_003A2CA8;
__asm__(".extern D_L23_001DE08C_003A2CA8, 4");
extern f32 D_L23_001DE090_003A2CA8;
__asm__(".extern D_L23_001DE090_003A2CA8, 4");
extern f32 D_L23_001DE094_003A2CA8;
__asm__(".extern D_L23_001DE094_003A2CA8, 4");
extern f32 D_L23_001DE098_003A2CA8;
__asm__(".extern D_L23_001DE098_003A2CA8, 4");
extern f32 D_L23_001DE0B0;
__asm__(".extern D_L23_001DE0B0, 4");
extern f32 D_L23_001DE0B4;
__asm__(".extern D_L23_001DE0B4, 4");
extern s32 D_L23_001DE0D0_003A2CA8;
__asm__(".extern D_L23_001DE0D0_003A2CA8, 4");
extern s32 D_L23_001DE0D8_003A2CA8;
__asm__(".extern D_L23_001DE0D8_003A2CA8, 4");
extern s32 D_L23_001DE0DC_003A2CA8;
__asm__(".extern D_L23_001DE0DC_003A2CA8, 4");
extern f32 D_L23_001DE0E0_003A2CA8;
__asm__(".extern D_L23_001DE0E0_003A2CA8, 4");
extern s32 D_L23_001DE0D4;
__asm__(".extern D_L23_001DE0D4, 4");
extern s32 D_L23_001DE0E4_003A2CA8;
__asm__(".extern D_L23_001DE0E4_003A2CA8, 4");
extern s32 D_L23_001DE0E8_003A2CA8;
__asm__(".extern D_L23_001DE0E8_003A2CA8, 4");
extern Paths_3A4460 *D_L23_001DEDCC;
__asm__(".extern D_L23_001DEDCC, 16");
extern Node_3A4460 *D_L23_001DF2C0;
__asm__(".extern D_L23_001DF2C0, 16");
extern u8 *D_L23_001DF1DC;
__asm__(".extern D_L23_001DF1DC, 16");
extern s32 D_L23_001DF218;
__asm__(".extern D_L23_001DF218, 16");
extern u16 *D_L23_0021C160[];
extern s32 func_L01_00448E90(void *);
extern s32 func_L01_00452EF0(void *);
extern s32 func_L01_00452EC8(void *);
extern void func_L01_004A6DF8(void *, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);
extern f32 func_00388A28(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_L01_00441FB8(u8 *, s32, s32);
extern f32 func_L01_0040C040(void *, void *);
extern void func_L01_00445558(f32 *, s32, f32, f32);
extern s32 func_L01_0044AF40(void *, f32);
extern void func_003BEB58(void *, void *, void *, f32);
extern s32 func_L01_00451078(void *, void *);
extern f32 func_003BE7F0(void *, s32, s32, f32);
extern s32 func_0037E0F0(void *, s32, s32);
extern f32 func_00389468(f32, f32);
extern f32 func_003893C8(f32, f32);
extern void func_L23_003A3DD8(void *);
extern void func_L23_003A3C18(u8 *, f32 *, f32, f32);
extern void func_L23_003A3B70(void *, void *);
extern void func_L23_003A3AD8(void *);
extern void func_L23_003A3850(u8 *);

void func_L23_003A2CA8(u8 *m)
{
    S_3A5008 *v;
    s32 r;
    f32 d;
    f32 range;
    s32 ok;
    s32 keep;
    s32 start;
    Path_3A4460 *path;
    Node_3A4460 *node;
    u16 *p;
    u8 *o;
    s32 id;
    f32 t[4];
    u128_t b[2];
    f32 a;
    f32 ang;

    if (func_L01_00448E90(m + 0x10) == 0) {
        return;
    }
    v = *(S_3A5008 **)(m + 0x68);
    func_L23_003A3850(m);
    switch (m[0x95]) {
    case 0:
    case 1:
    case 2:
    case 3:
        break;
    case 4:
        if (func_L01_00452EF0(m) != 0) {
            *(s32 *)(m + 0x98) = 0;
            *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & 0xEFFF;
            func_L01_004A6DF8(m, 1);
        }
        break;
    }
    switch (m[0x20]) {
    case 1:
        if (func_L01_00452EC8(m) != 0) {
            if (m[0x43] != 0) {
                func_003BE4F0(m, 0, 0, 0x14);
            }
        }
        if (v->x240 == 0) {
            v->x254 = func_0037E250(-3.1415927f, 3.1415927f);
            v->x240 = func_0037E208(0x3C, 240);
        }
        if (!(*(f32 *)(*(u8 **)(D_L23_001DE310 + 0x68) + 0x30) <= 0.0f) && v->x24C != 0) {
            if ((D_L23_001DECC0 & 0x3F) == (((s32)m >> 8) & 0x3F)) {
                *(u128_t *)v->x2C0 = *(u128_t *)&D_001A4BE0.v80;
                v->x254 = func_00388A28(D_001A4BE0.v80.v[0] - *(f32 *)(m + 0x10), D_001A4BE0.v80.v[1] - *(f32 *)(m + 0x14));
            }
            func_L23_003A3C18(m, v->x2C0, v->x254, D_L23_001DE074);
        } else {
            func_L23_003A3C18(m, v->x2C0, v->x254, D_L23_001DE074);
        }
        {
            f32 dist = func_L01_0040C040(m + 0x10, &D_001A4BE0.v80);
            if (!(*(f32 *)(*(u8 **)(D_L23_001DE310 + 0x68) + 0x30) <= 0.0f) && dist < D_L23_001DE080_003A2CA8) {
                func_L01_00441FB8(m, 2, 1);
            }
        }
        break;
    case 2:
        if (func_L01_00452EC8(m) != 0) {
            if (m[0x43] != 0) {
                func_003BE4F0(m, 0, 0, 0x14);
            }
            v->x250 = D_001A71A0[0];
        }
        if ((D_L23_001DECC0 & 0x1F) == (((s32)m >> 8) & 0x1F)) {
            *(u128_t *)v->x2C0 = *(u128_t *)&D_001A4BE0.v80;
            v->x254 = func_00388A28(D_001A4BE0.v80.v[0] - *(f32 *)(m + 0x10), D_001A4BE0.v80.v[1] - *(f32 *)(m + 0x14));
            t[0] = func_00388960(v->x254) * (D_L23_001DE094_003A2CA8 - 1.0f);
            t[1] = func_00388978(v->x254) * (D_L23_001DE094_003A2CA8 - 1.0f);
            t[2] = 0;
            vec_sub_ab(v->x2C0, v->x2C0, t);
        }
        func_L23_003A3C18(m, v->x2C0, v->x254, D_L23_001DE078_003A2CA8);
        func_L01_00441FB8(m, 3, 2);
        break;
    case 3:
        if (func_L01_00452EC8(m) != 0) {
            if (m[0x43] != 0) {
                func_003BE4F0(m, 0, 0, 0xA);
            }
        }
        if ((D_L23_001DECC0 & 7) == (((s32)m >> 8) & 7)) {
            v->x2C0[0] = func_00388960(D_001A4BE0.v90.v[2] + v->x244) * D_L23_001DE084_003A2CA8;
            v->x2C0[1] = func_00388978(D_001A4BE0.v90.v[2] + v->x244) * D_L23_001DE084_003A2CA8;
            v->x2C0[2] = 0;
            vec_add_ab(v->x2C0, v->x2C0, &D_001A4BE0.v80);
            v->x254 = func_00388A28(D_001A4BE0.v80.v[0] - *(f32 *)(m + 0x10), D_001A4BE0.v80.v[1] - *(f32 *)(m + 0x14));
        }
        func_L23_003A3C18(m, v->x2C0, v->x254, D_L23_001DE07C_003A2CA8);
        {
            f32 dist;

            dist = func_L01_0040C040(m + 0x10, &D_001A4BE0.v80);
            if (dist < D_L23_001DE090_003A2CA8) {
                func_L01_00441FB8(m, 4, -1);
            } else if (D_L23_001DE098_003A2CA8 < dist) {
                func_L01_00441FB8(m, 2, 1);
            }
        }
        break;
    case 5:
        if (func_L01_00452EC8(m) != 0) {
            if (m[0x43] != 0) {
                func_003BE4F0(m, 0, 0, 0xA);
            }
        }
        if ((D_L23_001DECC0 & 7) == (((s32)m >> 8) & 7)) {
            *(u128_t *)v->x2C0 = *(u128_t *)&D_001A4BE0.v80;
            v->x254 = func_00388A28(D_001A4BE0.v80.v[0] - *(f32 *)(m + 0x10), D_001A4BE0.v80.v[1] - *(f32 *)(m + 0x14));
            t[0] = func_00388960(v->x254) * D_L23_001DE094_003A2CA8;
            t[1] = func_00388978(v->x254) * D_L23_001DE094_003A2CA8;
            t[2] = 0;
            vec_sub_ab(v->x2C0, v->x2C0, t);
        }
        func_L23_003A3C18(m, v->x2C0, v->x254, D_L23_001DE074);
        {
            f32 dist;

            dist = func_L01_0040C040(m + 0x10, &D_001A4BE0.v80);
            if (D_L23_001DE098_003A2CA8 < dist) {
                func_L01_00441FB8(m, 2, 1);
            } else if (D_L23_001DE090_003A2CA8 < dist) {
                func_L01_00441FB8(m, 4, -1);
            }
        }
        break;
    case 4:
        if (func_L01_00452EC8(m) != 0) {
            if (m[0x43] != 0) {
                func_003BE4F0(m, 0, 0, 0xA);
            }
        }
        keep = 0;
        d = func_L01_0040C040(m + 0x10, &D_001A4BE0.v80);
        if (D_L23_001DE0D0_003A2CA8 < 9 && d < D_L23_001DE098_003A2CA8 && D_L23_001DE088_003A2CA8 < d) {
            if (func_00389468(*(f32 *)(m + 0xF8), func_00388A28(D_001A4BE0.v80.v[0] - *(f32 *)(m + 0x10), D_001A4BE0.v80.v[1] - *(f32 *)(m + 0x14))) < 0.5235988f) {
                keep = 1;
            }
        }
        if ((D_L23_001DECC0 & 7) == (((s32)m >> 8) & 7)) {
            a = func_00388A28(*(f32 *)(m + 0x10) - D_001A4BE0.v80.v[0], *(f32 *)(m + 0x14) - D_001A4BE0.v80.v[1]);
            func_L01_00445558(&a, 0, D_001A4BE0.v90.v[2] + v->x244, 0.34906584f);
            v->x2C0[0] = func_00388960(a) * D_L23_001DE08C_003A2CA8;
            v->x2C0[1] = func_00388978(a) * D_L23_001DE08C_003A2CA8;
            v->x2C0[2] = 0;
            vec_add_ab(v->x2C0, v->x2C0, &D_001A4BE0.v80);
            v->x254 = func_00388A28(D_001A4BE0.v80.v[0] - *(f32 *)(m + 0x10), D_001A4BE0.v80.v[1] - *(f32 *)(m + 0x14));
        }
        func_L23_003A3C18(m, v->x2C0, v->x254, D_L23_001DE074);
        if (keep == 0) {
            if (1.0f < D_L23_001DE0E0_003A2CA8 && d < D_L23_001DE088_003A2CA8) {
                func_L01_00441FB8(m, 5, -1);
            } else {
                func_L01_00441FB8(m, 2, 1);
            }
        }
        if (func_L01_0044AF40(m, D_L23_001DE070) != 0) {
            b[0] = *(u128_t *)&D_001A4BE0.v80;
            b[1] = *(u128_t *)&D_001A4BE0.vE0;
            func_003BEB58(t, &b[0], &b[1], func_0037E250(0.4f, 1.2f));
            func_L23_003A3B70(m, t);
        }
        break;
    case 6:
        r = func_L01_00451078(m, &v->x160);
        if (r & 1) {
            func_L23_003A3DD8(m);
        } else if (r & 2) {
            func_L01_00441FB8(m, 2, 1);
        }
        func_L23_003A3C18(m, (f32 *)(m + 0x10), *(f32 *)(m + 0xF8), D_L23_001DE07C_003A2CA8);
        break;
    case 7:
        if (func_L01_00452EC8(m) != 0) {
            D_L23_001DE0D4 = D_L23_001DE0D4 - 1 < 0 ? 0 : D_L23_001DE0D4 - 1;
        }
        if (D_L23_001DE0D4 < D_L23_001DE0DC_003A2CA8 && D_L23_001DE0D8_003A2CA8 != 0 && D_L23_001DE0E8_003A2CA8 <= D_L23_001DECC0) {
            if (D_L23_001DE0E0_003A2CA8 <= 1.0f) {
                D_L23_001DE0E8_003A2CA8 = D_L23_001DECC0 + 0x3C;
            }
            v->x24C = 1.0f <= D_L23_001DE0E0_003A2CA8;
            func_L01_00441FB8(m, 8, -1);
        }
        break;
    case 8:
        path = &D_L23_001DEDCC->paths[v->x248];
        start = D_L23_001DE0E4_003A2CA8;
        do {
            id = path->ids[D_L23_001DE0E4_003A2CA8];
            node = &D_L23_001DF2C0[id];
            D_L23_001DE0E4_003A2CA8++;
            if (D_L23_001DE0E4_003A2CA8 >= path->count) {
                D_L23_001DE0E4_003A2CA8 = 0;
            }
            ok = 1;
            range = func_L01_0040C040(&node->pos, &D_001A4BE0.v80);
            if (range < D_L23_001DE0B0) {
                ok = 0;
            }
            ang = func_00388A28(node->pos.v[0] - D_001A4BE0.v80.v[0], node->pos.v[1] - D_001A4BE0.v80.v[1]);
            if (range < D_L23_001DE0B4) {
                if (fabs_asm(func_003893C8(D_001A4BE0.v90.v[2], ang)) < 0.785398f) {
                    ok = 0;
                }
            }
            p = D_L23_0021C160[m[0x21]];
            while (m[0x21] != 0xFF && m[0x21] <= D_L23_001DF218 && p != 0 &&
                   ((s16)p[-1] >= 0 || p == D_L23_0021C160[m[0x21]])) {
                o = D_L23_001DF1DC + ((*p & 0x7FFF) << 8);
                if (o == 0) {
                    break;
                }
                if (o != m && (*(u16 *)(o + 0x34) & 1) == 0) {
                    if (func_0037E0F0(o + 0x10, id, 0) != 0) {
                        ok = 0;
                        break;
                    }
                }
                p++;
            }
            if (ok != 0) {
                *(u128_t *)v->x2C0 = *(u128_t *)(m + 0x10) = *(u128_t *)v->x2B0 = *(u128_t *)&node->pos;
                ((V4_3A4460 *)(m + 0x10))->v[2] = func_003BE7F0(m + 0x10, 0, 0, 0.5f) + v->x70;
                D_L23_001DE0D4 += 1;
                if (D_L23_001DE0D8_003A2CA8 > 0) {
                    D_L23_001DE0D8_003A2CA8 -= 1;
                }
                v->x160.x38 = 0;
                *(u16 *)(m + 0x34) &= 0xFFBE;
                *(u16 *)(m + 0x34) |= *(u16 *)(*(u8 **)(m + 0x24) + 0x44) & 0x1000;
                *(s32 *)(m + 0x98) = *(s32 *)(*(u8 **)(m + 0x24) + 0x10);
                func_L01_00441FB8(m, 1, 0);
                break;
            }
        } while (D_L23_001DE0E4_003A2CA8 != start);
        break;
    }
    func_L23_003A3AD8(m);
}
/* localdecomp:end func_L23_003A2CA8 */
