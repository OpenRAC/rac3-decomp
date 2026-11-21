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

/* localdecomp:start func_L23_003A4448 */
extern s32 D_L23_001DE098;
__asm__(".extern D_L23_001DE098, 4");
extern s32 D_L23_001DE09C;
__asm__(".extern D_L23_001DE09C, 4");
extern f32 D_L23_001DE0A0;
__asm__(".extern D_L23_001DE0A0, 4");

void func_L23_003A4448(s32 arg0, s32 arg1, f32 fparg0) {
    D_L23_001DE098 = arg0;
    D_L23_001DE09C = arg1;
    D_L23_001DE0A0 = fparg0;
}
/* localdecomp:end func_L23_003A4448 */

LINKER_REMNANT("asm/levels", func_L23_003A4458);

/* localdecomp:start func_L23_003A4460 */
#include "common.h"
#include "vu0.h"


extern Hero_3A4460 D_001A4BE0;
extern s32 D_001A71A0[];
extern s32 D_L23_001DEC40;
extern u8 *D_L23_001DE2D0;
extern u8 *D_L23_001DE2D0_3A4460;
__asm__(".extern D_L23_001DE2D0_3A4460, 4");
extern f32 D_L23_001DE030;
__asm__(".extern D_L23_001DE030, 4");
extern f32 D_L23_001DE034;
__asm__(".extern D_L23_001DE034, 4");
extern f32 D_L23_001DE038;
__asm__(".extern D_L23_001DE038, 4");
extern f32 D_L23_001DE03C;
__asm__(".extern D_L23_001DE03C, 4");
extern f32 D_L23_001DE040;
__asm__(".extern D_L23_001DE040, 4");
extern f32 D_L23_001DE044;
__asm__(".extern D_L23_001DE044, 4");
extern f32 D_L23_001DE048;
__asm__(".extern D_L23_001DE048, 4");
extern f32 D_L23_001DE04C;
__asm__(".extern D_L23_001DE04C, 4");
extern f32 D_L23_001DE050;
__asm__(".extern D_L23_001DE050, 4");
extern f32 D_L23_001DE054;
__asm__(".extern D_L23_001DE054, 4");
extern f32 D_L23_001DE058;
__asm__(".extern D_L23_001DE058, 4");
extern f32 D_L23_001DE070;
__asm__(".extern D_L23_001DE070, 4");
extern f32 D_L23_001DE074;
__asm__(".extern D_L23_001DE074, 4");
extern s32 D_L23_001DE090;
__asm__(".extern D_L23_001DE090, 4");
extern s32 D_L23_001DE098;
__asm__(".extern D_L23_001DE098, 4");
extern s32 D_L23_001DE09C;
__asm__(".extern D_L23_001DE09C, 4");
extern f32 D_L23_001DE0A0;
__asm__(".extern D_L23_001DE0A0, 4");
extern s32 D_L23_001DE094;
__asm__(".extern D_L23_001DE094, 4");
extern s32 D_L23_001DE0A4;
__asm__(".extern D_L23_001DE0A4, 4");
extern s32 D_L23_001DE0A8;
__asm__(".extern D_L23_001DE0A8, 4");
extern Paths_3A4460 *D_L23_001DED4C;
__asm__(".extern D_L23_001DED4C, 16");
extern Node_3A4460 *D_L23_001DF240;
__asm__(".extern D_L23_001DF240, 16");
extern u8 *D_L23_001DF15C;
__asm__(".extern D_L23_001DF15C, 16");
extern s32 D_L23_001DF198;
__asm__(".extern D_L23_001DF198, 16");
extern u16 *D_L23_0021C0E0[];
extern s32 func_L01_0044C108(void *);
extern s32 func_L01_004561E0(void *);
extern s32 func_L01_004561B8(void *);
extern void func_L01_004AA7E8(void *, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern f32 func_L01_0040E570(void *, void *);
extern void func_L01_00448690(f32 *, s32, f32, f32);
extern s32 func_L01_0044E1B8(void *, f32);
extern void func_003C4098(void *, void *, void *, f32);
extern s32 func_L01_00454370(void *, void *);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern s32 func_00382380(void *, s32, s32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern void func_L23_003A5590(void *);
extern void func_L23_003A53D0(u8 *, f32 *, f32, f32);
extern void func_L23_003A5328(void *, void *);
extern void func_L23_003A5290(void *);
extern void func_L23_003A5008(u8 *);

void func_L23_003A4460(u8 *m)
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

    if (func_L01_0044C108(m + 0x10) == 0) {
        return;
    }
    v = *(S_3A5008 **)(m + 0x68);
    func_L23_003A5008(m);
    switch (m[0x95]) {
    case 0:
    case 1:
    case 2:
    case 3:
        break;
    case 4:
        if (func_L01_004561E0(m) != 0) {
            *(s32 *)(m + 0x98) = 0;
            *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & 0xEFFF;
            func_L01_004AA7E8(m, 1);
        }
        break;
    }
    switch (m[0x20]) {
    case 1:
        if (func_L01_004561B8(m) != 0) {
            if (m[0x43] != 0) {
                func_003C3A10(m, 0, 0, 0x11);
            }
        }
        if (v->x240 == 0) {
            v->x254 = func_003824E0(-3.1415927f, 3.1415927f);
            v->x240 = func_00382498(0x32, 200);
        }
        if (!(*(f32 *)(*(u8 **)(D_L23_001DE2D0 + 0x68) + 0x30) <= 0.0f) && v->x24C != 0) {
            if ((D_L23_001DEC40 & 0x3F) == (((s32)m >> 8) & 0x3F)) {
                *(u128_t *)v->x2C0 = *(u128_t *)&D_001A4BE0.v80;
                v->x254 = func_0038D160(D_001A4BE0.v80.v[0] - *(f32 *)(m + 0x10), D_001A4BE0.v80.v[1] - *(f32 *)(m + 0x14));
            }
            func_L23_003A53D0(m, v->x2C0, v->x254, D_L23_001DE034);
        } else {
            func_L23_003A53D0(m, v->x2C0, v->x254, D_L23_001DE034);
        }
        {
            f32 dist = func_L01_0040E570(m + 0x10, &D_001A4BE0.v80);
            if (!(*(f32 *)(*(u8 **)(D_L23_001DE2D0 + 0x68) + 0x30) <= 0.0f) && dist < D_L23_001DE040) {
                func_L01_004450F0(m, 2, 1);
            }
        }
        break;
    case 2:
        if (func_L01_004561B8(m) != 0) {
            if (m[0x43] != 0) {
                func_003C3A10(m, 0, 0, 0x11);
            }
            v->x250 = D_001A71A0[0];
        }
        if ((D_L23_001DEC40 & 0x1F) == (((s32)m >> 8) & 0x1F)) {
            *(u128_t *)v->x2C0 = *(u128_t *)&D_001A4BE0.v80;
            v->x254 = func_0038D160(D_001A4BE0.v80.v[0] - *(f32 *)(m + 0x10), D_001A4BE0.v80.v[1] - *(f32 *)(m + 0x14));
            t[0] = func_0038D098(v->x254) * (D_L23_001DE054 - 1.0f);
            t[1] = func_0038D0B0(v->x254) * (D_L23_001DE054 - 1.0f);
            t[2] = 0;
            vec_sub_ab(v->x2C0, v->x2C0, t);
        }
        func_L23_003A53D0(m, v->x2C0, v->x254, D_L23_001DE038);
        func_L01_004450F0(m, 3, 2);
        break;
    case 3:
        if (func_L01_004561B8(m) != 0) {
            if (m[0x43] != 0) {
                func_003C3A10(m, 0, 0, 8);
            }
        }
        if ((D_L23_001DEC40 & 7) == (((s32)m >> 8) & 7)) {
            v->x2C0[0] = func_0038D098(D_001A4BE0.v90.v[2] + v->x244) * D_L23_001DE044;
            v->x2C0[1] = func_0038D0B0(D_001A4BE0.v90.v[2] + v->x244) * D_L23_001DE044;
            v->x2C0[2] = 0;
            vec_add_ab(v->x2C0, v->x2C0, &D_001A4BE0.v80);
            v->x254 = func_0038D160(D_001A4BE0.v80.v[0] - *(f32 *)(m + 0x10), D_001A4BE0.v80.v[1] - *(f32 *)(m + 0x14));
        }
        func_L23_003A53D0(m, v->x2C0, v->x254, D_L23_001DE03C);
        {
            f32 dist;

            dist = func_L01_0040E570(m + 0x10, &D_001A4BE0.v80);
            if (dist < D_L23_001DE050) {
                func_L01_004450F0(m, 4, -1);
            } else if (D_L23_001DE058 < dist) {
                func_L01_004450F0(m, 2, 1);
            }
        }
        break;
    case 5:
        if (func_L01_004561B8(m) != 0) {
            if (m[0x43] != 0) {
                func_003C3A10(m, 0, 0, 8);
            }
        }
        if ((D_L23_001DEC40 & 7) == (((s32)m >> 8) & 7)) {
            *(u128_t *)v->x2C0 = *(u128_t *)&D_001A4BE0.v80;
            v->x254 = func_0038D160(D_001A4BE0.v80.v[0] - *(f32 *)(m + 0x10), D_001A4BE0.v80.v[1] - *(f32 *)(m + 0x14));
            t[0] = func_0038D098(v->x254) * D_L23_001DE054;
            t[1] = func_0038D0B0(v->x254) * D_L23_001DE054;
            t[2] = 0;
            vec_sub_ab(v->x2C0, v->x2C0, t);
        }
        func_L23_003A53D0(m, v->x2C0, v->x254, D_L23_001DE034);
        {
            f32 dist;

            dist = func_L01_0040E570(m + 0x10, &D_001A4BE0.v80);
            if (D_L23_001DE058 < dist) {
                func_L01_004450F0(m, 2, 1);
            } else if (D_L23_001DE050 < dist) {
                func_L01_004450F0(m, 4, -1);
            }
        }
        break;
    case 4:
        if (func_L01_004561B8(m) != 0) {
            if (m[0x43] != 0) {
                func_003C3A10(m, 0, 0, 8);
            }
        }
        keep = 0;
        d = func_L01_0040E570(m + 0x10, &D_001A4BE0.v80);
        if (D_L23_001DE090 < 9 && d < D_L23_001DE058 && D_L23_001DE048 < d) {
            if (func_0038DBA0(*(f32 *)(m + 0xF8), func_0038D160(D_001A4BE0.v80.v[0] - *(f32 *)(m + 0x10), D_001A4BE0.v80.v[1] - *(f32 *)(m + 0x14))) < 0.5235988f) {
                keep = 1;
            }
        }
        if ((D_L23_001DEC40 & 7) == (((s32)m >> 8) & 7)) {
            a = func_0038D160(*(f32 *)(m + 0x10) - D_001A4BE0.v80.v[0], *(f32 *)(m + 0x14) - D_001A4BE0.v80.v[1]);
            func_L01_00448690(&a, 0, D_001A4BE0.v90.v[2] + v->x244, 0.34906584f);
            v->x2C0[0] = func_0038D098(a) * D_L23_001DE04C;
            v->x2C0[1] = func_0038D0B0(a) * D_L23_001DE04C;
            v->x2C0[2] = 0;
            vec_add_ab(v->x2C0, v->x2C0, &D_001A4BE0.v80);
            v->x254 = func_0038D160(D_001A4BE0.v80.v[0] - *(f32 *)(m + 0x10), D_001A4BE0.v80.v[1] - *(f32 *)(m + 0x14));
        }
        func_L23_003A53D0(m, v->x2C0, v->x254, D_L23_001DE034);
        if (keep == 0) {
            if (1.0f < D_L23_001DE0A0 && d < D_L23_001DE048) {
                func_L01_004450F0(m, 5, -1);
            } else {
                func_L01_004450F0(m, 2, 1);
            }
        }
        if (func_L01_0044E1B8(m, D_L23_001DE030) != 0) {
            b[0] = *(u128_t *)&D_001A4BE0.v80;
            b[1] = *(u128_t *)&D_001A4BE0.vE0;
            func_003C4098(t, &b[0], &b[1], func_003824E0(0.4f, 1.2f));
            func_L23_003A5328(m, t);
        }
        break;
    case 6:
        r = func_L01_00454370(m, &v->x160);
        if (r & 1) {
            func_L23_003A5590(m);
        } else if (r & 2) {
            func_L01_004450F0(m, 2, 1);
        }
        func_L23_003A53D0(m, (f32 *)(m + 0x10), *(f32 *)(m + 0xF8), D_L23_001DE03C);
        break;
    case 7:
        if (func_L01_004561B8(m) != 0) {
            D_L23_001DE094 = D_L23_001DE094 - 1 < 0 ? 0 : D_L23_001DE094 - 1;
        }
        if (D_L23_001DE094 < D_L23_001DE09C && D_L23_001DE098 != 0 && D_L23_001DE0A8 <= D_L23_001DEC40) {
            if (D_L23_001DE0A0 <= 1.0f) {
                D_L23_001DE0A8 = D_L23_001DEC40 + 0x32;
            }
            v->x24C = 1.0f <= D_L23_001DE0A0;
            func_L01_004450F0(m, 8, -1);
        }
        break;
    case 8:
        path = &D_L23_001DED4C->paths[v->x248];
        start = D_L23_001DE0A4;
        do {
            id = path->ids[D_L23_001DE0A4];
            node = &D_L23_001DF240[id];
            D_L23_001DE0A4++;
            if (D_L23_001DE0A4 >= path->count) {
                D_L23_001DE0A4 = 0;
            }
            ok = 1;
            range = func_L01_0040E570(&node->pos, &D_001A4BE0.v80);
            if (range < D_L23_001DE070) {
                ok = 0;
            }
            ang = func_0038D160(node->pos.v[0] - D_001A4BE0.v80.v[0], node->pos.v[1] - D_001A4BE0.v80.v[1]);
            if (range < D_L23_001DE074) {
                if (fabs_asm(func_0038DB00(D_001A4BE0.v90.v[2], ang)) < 0.785398f) {
                    ok = 0;
                }
            }
            p = D_L23_0021C0E0[m[0x21]];
            while (m[0x21] != 0xFF && m[0x21] <= D_L23_001DF198 && p != 0 &&
                   ((s16)p[-1] >= 0 || p == D_L23_0021C0E0[m[0x21]])) {
                o = D_L23_001DF15C + ((*p & 0x7FFF) << 8);
                if (o == 0) {
                    break;
                }
                if (o != m && (*(u16 *)(o + 0x34) & 1) == 0) {
                    if (func_00382380(o + 0x10, id, 0) != 0) {
                        ok = 0;
                        break;
                    }
                }
                p++;
            }
            if (ok != 0) {
                *(u128_t *)v->x2C0 = *(u128_t *)(m + 0x10) = *(u128_t *)v->x2B0 = *(u128_t *)&node->pos;
                ((V4_3A4460 *)(m + 0x10))->v[2] = func_003C3D30(m + 0x10, 0, 0, 0.5f) + v->x70;
                D_L23_001DE094 += 1;
                if (D_L23_001DE098 > 0) {
                    D_L23_001DE098 -= 1;
                }
                v->x160.x38 = 0;
                *(u16 *)(m + 0x34) &= 0xFFBE;
                *(u16 *)(m + 0x34) |= *(u16 *)(*(u8 **)(m + 0x24) + 0x44) & 0x1000;
                *(s32 *)(m + 0x98) = *(s32 *)(*(u8 **)(m + 0x24) + 0x10);
                func_L01_004450F0(m, 1, 0);
                break;
            }
        } while (D_L23_001DE0A4 != start);
        break;
    }
    func_L23_003A5290(m);
}
/* localdecomp:end func_L23_003A4460 */

/* localdecomp:start func_L23_003A5008 */
extern f32 D_L23_001DE02C;
extern s32 D_L23_001DE090;
__asm__(".extern D_L23_001DE090, 4");
extern u8 *D_L23_001DE2D0;
extern void func_L23_003A5110(u8 *);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern void func_0038D750(void *, s32, f32);
extern f32 func_0038DB00(f32, f32);
extern void func_L01_004450F0(u8 *, s32, s32);


void func_L23_003A5008(u8 *m) {
    S_3A5008 *v = *(S_3A5008 **)(m + 0x68);
    if (m[0x20] == 0) {
        func_L23_003A5110(m);
    }
    if (m[0x95] != 4) {
        func_L01_00452FB0(m, &v->x160, 0, 0, 0);
        if (m[0x31] != 0) {
            func_0038D750(v->x260.x10, 2, v->x25C);
            v->x25C = func_0038DB00(v->x25C, D_L23_001DE02C);
        }
    }
    if (v->x2A0 != 0) {
        if (m[0x95] != 2) {
            v->x2A0 = 0;
            D_L23_001DE090--;
        }
    } else if (m[0x95] == 2) {
        v->x2A0 = 1;
        D_L23_001DE090++;
    }
    if (m[0x95] != 4 && *(f32 *)(*(u8 **)(D_L23_001DE2D0 + 0x68) + 0x30) <= 0.0f) {
        func_L01_004450F0(m, 1, 0);
    }
}
/* localdecomp:end func_L23_003A5008 */

/* localdecomp:start func_L23_003A5110 */
extern float D_L23_001DE028;
__asm__(".extern D_L23_001DE028, 4");
extern f32 D_L23_001DE06C;
__asm__(".extern D_L23_001DE06C, 4");
extern f32 D_L23_001DE078;
__asm__(".extern D_L23_001DE078, 4");
extern f32 D_L23_001DE07C;
__asm__(".extern D_L23_001DE07C, 4");
extern f32 D_L23_001DE080;
__asm__(".extern D_L23_001DE080, 4");
extern f32 D_L23_001DE084;
__asm__(".extern D_L23_001DE084, 4");
extern s32 D_L23_001DE094;
__asm__(".extern D_L23_001DE094, 4");
extern s32 D_L23_001DE0A8;
__asm__(".extern D_L23_001DE0A8, 4");
extern s32 D_L23_001DE098;
__asm__(".extern D_L23_001DE098, 4");
extern s32 D_L23_001DE09C;
__asm__(".extern D_L23_001DE09C, 4");
extern f32 D_L23_001DE0A0;
__asm__(".extern D_L23_001DE0A0, 4");
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern f32 func_00382538(void);
extern void func_L01_0043A430(u8 *, s32, u8 *);

void func_L23_003A5110(u8 *m)
{
    S_3A5008 *v;

    *(f32 *)(m + 0x2C) = *(f32 *)(m + 0x2C) * D_L23_001DE028;
    *(s16 *)(m + 0x7C) = 0xFF;
    v = *(S_3A5008 **)(m + 0x68);
    v->x160.x10 = 6;
    v->x160.x48 = 3;
    v->x160.x3C = 0.15f;
    v->x160.x30 = 0.5f;
    v->x160.x34 = 0.5f;
    if (v->x34 == 0) {
        v->x34 = 1;
        v->x30 = 1.0f;
    }
    v->x74 = -D_L23_001DE06C;
    v->xA0 = 0.08726646f;
    v->xA8 |= 0x514;
    v->x78 = 20.0f;
    v->x7C = 20.0f;
    v->x80 = 1.5707964f;
    v->xA4 = 0.5f;
    v->x70 = D_L23_001DE06C;
    v->x9C = 0;
    func_L01_0045BD78(m, D_L23_001DE07C, D_L23_001DE078, D_L23_001DE084, D_L23_001DE080);
    v->x244 = func_00382538() * 0.5f;
    v->x240 = 0;
    v->x24C = 0;
    v->x250 = 0;
    v->x254 = 0;
    v->x25C = 0.0f;
    qzero(v->x2B0);
    qzero(v->x2C0);
    qzero(v->x2D0);
    v->x2A4 = 0;
    v->x2A0 = 0;
    v->x2AC = -1;
    func_L01_0043A430(m, 0, (u8 *)&v->x260);
    D_L23_001DE0A0 = 0.5f;
    D_L23_001DE090 = 0;
    D_L23_001DE094 = 0;
    D_L23_001DE0A8 = 0;
    D_L23_001DE098 = 0;
    D_L23_001DE09C = 0;
    func_L01_004450F0(m, 7, 4);
}
/* localdecomp:end func_L23_003A5110 */

/* localdecomp:start func_L23_003A5290 */
extern s32 func_0038CAD0(void *);
f32 func_L01_0040E548(void *, void *);
void func_L01_004472C0(void *);
extern u8 D_L23_001E1A40[];

void func_L23_003A5290(void *arg0) {
    u8 *temp_s1;
    u16 temp_v1;

    temp_s1 = *(u8 **)((u8 *)arg0 + 0x68);
    if (((*(u8 *)((u8 *)arg0 + 0x31)) != 0) && (func_L01_0040E548(D_L23_001E1A40, arg0 + 0x10) < 1024.0f)) {
        func_L01_004472C0(arg0);
        *(s8 *)((u8 *)arg0 + 0x6F) = 0x1E;
    }
    func_0038CAD0(temp_s1 + 0x240);
    temp_v1 = *(u16 *)((u8 *)arg0 + 0x96);
    if (temp_v1 <= 0xFFFEU) {
        *(u16 *)((u8 *)arg0 + 0x96) = (u16) (temp_v1 + 1);
    }
}
/* localdecomp:end func_L23_003A5290 */

/* localdecomp:start func_L23_003A5328 */
extern float D_L23_001DE064;
__asm__(".extern D_L23_001DE064, 4");
extern float D_L23_001DE028;
__asm__(".extern D_L23_001DE028, 4");
extern s32 D_L23_001DE068;
__asm__(".extern D_L23_001DE068, 4");
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(void *, void *, float);
extern s32 func_003A52A0(s32, s32, void *);
extern void *func_L23_0032B060(void *, void *, void *, float);

void func_L23_003A5328(void *obj, void *arg1) {
    char matrix[64] __attribute__((aligned(16)));
    u128_t v[2];
    s32 i;

    for (i = 1; i < 3; i++) {
        func_003C2EC0(obj, i, matrix);
        v[0] = *(u128_t *)(matrix + 0x30);
        func_0038CF68(&v[1], matrix, D_L23_001DE064);
        func_003A52A0(2, 0, obj);
        func_L23_0032B060(&v[0], &v[1], &D_L23_001DE068, D_L23_001DE028);
    }
}
/* localdecomp:end func_L23_003A5328 */
