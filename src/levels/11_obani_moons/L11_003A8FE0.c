#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L11_003A8FE0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) q_3A8FE0;
typedef struct { u8 pad[0x464]; u8 spent[1]; } S_3A8FE0;
extern S_3A8FE0 D_L11_00234CC0;
__asm__(".extern D_L11_00234CC0, 16");
extern u8 *D_L11_001DEE1C;
extern u8 D_001BBE90[];
extern s32 D_001D545C;
extern u8 D_001A30B0[];
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_00456250(void *);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00451290(void *, void *, s32);
extern void func_003C4098(void *, void *, void *, f32);
extern void func_L01_004515D8(void *, void *, void *);
extern void func_003A4F28(s32);

void func_L11_003A8FE0(u8 *a0)
{
    s32 *v = *(s32 **)(a0 + 0x68);
    q_3A8FE0 mtx;
    q_3A8FE0 rot;
    q_3A8FE0 out;
    s32 idx;
    u8 *e;
    u16 id;
    u8 *p;
    s32 b;

    if (v == 0) {
        return;
    }
    switch (a0[0x20]) {
    case 0:
        *(u16 *)(a0 + 0x34) |= 0x100;
        func_L01_004450F0(a0, 1, -1);
        break;
    case 1:
        if (func_L01_00456250(D_L11_001DEE1C + (v[0] << 8)) == 0) {
            id = *(u16 *)(a0 + 0xB2);
            if (D_L11_00234CC0.spent[(s16)id] == 0) {
                b = D_001BBE90[((s16)id >> 1) + (D_001D545C << 10)];
                if (id & 1) {
                    if (((b >> 4) & 7) != 0) {
                        goto spawn;
                    }
                    break;
                }
                if ((b & 7) == 0) {
                    break;
                }
            }
        }
spawn:
        func_L01_004450F0(a0, 2, -1);
        func_003A52A0(0, 0, a0);
        break;
    case 2:
        if (*(u16 *)(a0 + 0x96) < 200) {
            *(u16 *)(a0 + 0x96) += 1;
        }
        func_L01_00451290(a0, &mtx, 1);
        rot = *(q_3A8FE0 *)(a0 + 0xE0);
        func_003C4098(&out, &rot, &mtx, -0.02f);
        func_L01_004515D8(a0 + 0xC0, &out, 0);
        if (*(u16 *)(a0 + 0x96) >= 100) {
            idx = v[1];
            if (idx != -1) {
                e = D_001A30B0 + (idx << 7);
                if (*(u8 **)(e + 0xDC) == a0 && e[0xD0] != 0) {
                    func_003A4F28(idx);
                }
            }
            v[1] = -1;
        }
        if (*(u16 *)(a0 + 0xB2) & 1) {
            p = &D_001BBE90[(*(s16 *)(a0 + 0xB2) >> 1) + (D_001D545C << 10)];
            if (((*p >> 4) & 7) != 7) {
                *p += 0x10;
            }
        } else {
            p = &D_001BBE90[(*(s16 *)(a0 + 0xB2) >> 1) + (D_001D545C << 10)];
            if ((*p & 7) != 7) {
                *p += 1;
            }
        }
        break;
    }
}
/* localdecomp:end func_L11_003A8FE0 */

/* localdecomp:start func_L11_003A9260 */
extern u8 *D_L11_0021CB80[];

extern s32 func_L11_003A9860(u8 *);
extern void func_L11_003A9CB0(u8 *);
extern void func_L11_003A9D50(void *);
extern void func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32,
                              s32, s32, s32, s32);
extern void func_003C2880(u8 *);
extern s32 func_L01_004561E0(u8 *);
extern s32 func_00382498(s32, s32);
extern void func_003E8B18(void *, void *, void *, f32);
extern s32 func_003E7938(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern s32 func_L01_00454370(u8 *, u8 *);
extern void func_L01_00315900(u8 *, s32, s32);
extern s32 func_L01_004561B8(u8 *);
extern f32 func_003E7E28(void *, void *);
extern void func_003E7F68(void *, void *, f32);

void func_L11_003A9260(u8 *a0)
{
    u8 *v = *(u8 **)(a0 + 0x68);
    vu0_v4 d;
    u8 *e;
    u8 *p;
    f32 best;
    s32 i;
    s32 r;

    if (func_L11_003A9860(a0) != 0) {
        func_003C2880(a0);
        return;
    }
    if (*(f32 *)(v + 0x30) <= 0.0f) {
        func_L11_003A9CB0(a0);
        func_L01_003303B8(a0 + 0x10, 1, 0x28, 0x28, 0x28, 0x28, 0x41, 0, 3.0f, 0.0f, 0.0f, 2.0f,
                          0, 1, 1, 1, 1, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                          0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_003C2880(a0);
        return;
    }
    switch (a0[0x95]) {
    case 0:
        if (func_L01_004561E0(a0) != 0) {
            *(u16 *)(v + 0x2D6) = (func_00382498(0, 0x1E) * 5 + 2) / 6;
        }
        func_003E8B18(a0 + 0xD0, a0 + 0xD0, a0 + 0xE0, 0.041887905f);
        func_003E8B18(a0 + 0xC0, a0 + 0xC0, a0 + 0xE0, 0.041887905f);
        if (*(s16 *)(v + 0x234) == 1) {
            if (func_003E7938(v + 0x2D6) != 0) {
                break;
            }
        }
        if (*(s32 *)(v + 0x2D8) == 0) {
            break;
        }
        if (func_003E7938(v + 0x2D6) == 0) {
            break;
        }
        *(s32 *)(v + 0x2D8) = 0;
        if (*(s32 *)(v + 0x2D0) < 250) {
            *(s32 *)(v + 0x2D0) = (func_00382498(0x1E0, 0x258) * 5 + 2) / 6;
        }
        break;
    case 1:
        if (*(s16 *)(v + 0x234) == 1) {
            func_L01_004450F0(a0, 3, 2);
        } else if (*(s32 *)(v + 0x2D0) == 0) {
            func_L01_004450F0(a0, 1, 0);
        }
        break;
    case 2:
        if (a0[0x42] == 2) {
            if (a0[0x20] != 4 && a0[0x43] != 3) {
                func_003C3A10(a0, 3, 0, 2);
            }
        }
        if (a0[0x42] == 3 && (a0[0x60] & 2) != 0 && a0[0x43] != 0) {
            func_003C3A10(a0, 0, 0, 2);
        }
        if (*(s16 *)(v + 0x234) != 1) {
            func_L01_004561E0(a0);
        }
        break;
    case 3:
        r = func_L01_00454370(a0, v + 0x160);
        if (r & 1) {
            func_L11_003A9CB0(a0);
            func_L01_00315900(a0, 0, 0);
            return;
        }
        if (r & 2) {
            if (*(s16 *)(v + 0x234) == 1) {
                func_L01_004450F0(a0, 3, 2);
            } else {
                func_L01_004450F0(a0, 2, 1);
                *(s32 *)(v + 0x2D0) = (func_00382498(0x244, 0x258) * 5 + 2) / 6;
            }
        }
        break;
    }
    switch (a0[0x20]) {
    case 1:
        break;
    case 2:
        break;
    case 3:
        if (func_L01_004561B8(a0) != 0 && a0[0x94] != 4) {
            e = D_L11_0021CB80[*(s32 *)(v + 0x2E4)];
            best = 1.0e9f;
            for (i = 0; i < *(s32 *)e - 1; i++) {
                if (func_003E7E28(a0 + 0x10, e + 0x10 + i * 0x10) < best) {
                    best = func_003E7E28(a0 + 0x10, e + 0x10 + i * 0x10);
                    *(s32 *)(v + 0x2E8) = i;
                }
            }
        }
        if (*(s32 *)(v + 0x2E4) != -1) {
            p = D_L11_0021CB80[*(s32 *)(v + 0x2E4)];
            vec_sub_ba(&d, p + 0x10 + *(s32 *)(v + 0x2E8) * 0x10, a0 + 0x10);
            func_003E7F68(&d, &d, *(s32 *)(v + 0x2E4) * 0.020000001f);
            if (func_003E7E28(a0 + 0x10, p + 0x10 + *(s32 *)(v + 0x2E8) * 0x10) < 1.0f) {
                *(s32 *)(v + 0x2E8) += 1;
                if (*(s32 *)(v + 0x2E8) >= *(s32 *)p) {
                    *(s32 *)(v + 0x2E8) = 0;
                }
            }
        }
        if (*(u16 *)(a0 + 0x96) >= 0xC9) {
            func_L01_004450F0(a0, 4, -1);
            if (a0[0x43] != 1) {
                func_003C3A10(a0, 1, 0, 8);
            }
        }
        break;
    case 4:
        if (a0[0x42] == 1 && (a0[0x60] & 2) != 0 && a0[0x43] != 2) {
            func_003C3A10(a0, 2, 0, 2);
        }
        func_003E8B18(a0 + 0xD0, a0 + 0xD0, a0 + 0xE0, 0.041887905f);
        func_003E8B18(a0 + 0xC0, a0 + 0xC0, a0 + 0xE0, 0.041887905f);
        if (*(u16 *)(a0 + 0x96) >= 0x33) {
            func_L01_004450F0(a0, 3, -1);
        }
        break;
    case 5:
        break;
    }
    func_L11_003A9D50(a0);
}
/* localdecomp:end func_L11_003A9260 */

/* localdecomp:start func_L11_003A9860 */
extern vu0_v4 D_001A4C60;
extern s32 func_L11_003A9B30(u8 *);
extern void func_L11_003A9CB0(u8 *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern void func_0038D810(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern void func_L02_0034FD58(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_00452860(void *, void *, s32);
extern void func_L01_00404A10(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);

s32 func_L11_003A9860(u8 *a0)
{
    u8 *v = *(u8 **)(a0 + 0x68);
    vu0_v4 d;
    vu0_v4 m[3];
    vu0_v4 q;
    vu0_v4 e;
    f32 t;
    f32 h;

    if (a0[0x20] == 0 && func_L11_003A9B30(a0) != 0) {
        return 1;
    }
    *(u16 *)(a0 + 0x34) |= 0x100;
    vec_sub_ba(&d, &D_001A4C60, a0 + 0x10);
    func_0038CF68(&d, &d, 1.0f);
    func_0038CF68(&e, &d, 1.0f);
    func_0038CE90(&q, &e, a0 + 0xE0);
    func_0038CE20(&q, &q, 0.5f);
    t = func_0038CEA8(&q);
    q.w = -sqrt_asm(1.0f - t * t);
    func_0038D810(&q, m);
    func_0038D5F0(a0 + 0xC0, m, a0 + 0xC0);
    if (v[0x3E] == 2) {
        goto die;
    }
    h = *(f32 *)(v + 0x30);
    if (func_L01_00452FB0(a0, v + 0x160, 0, 0, 1) != 0) {
        func_L02_0034FD58(a0);
    }
    if (*(f32 *)(v + 0x30) < h && a0[0x95] != 2) {
        func_L01_004450F0(a0, 3, 2);
    }
    func_L01_00452860(a0, v + 0x30, 0);
    if (v[0x5E] != 0) {
die:
        func_L11_003A9CB0(a0);
        return 1;
    }
    if (v[0x5F] != 0) {
        func_L01_00404A10(a0, 5);
        if (a0[0x95] == 0) {
            func_L01_00456C98(a0, *(s32 *)(v + 0x2C0), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(v + 0x2C4), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(a0, *(s32 *)(v + 0x2C8), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(v + 0x2CC), 10.0f, 1.0f);
        }
    } else {
        func_L01_00404A10(a0, 3);
        if (a0[0x95] == 0) {
            func_L01_00456C98(a0, *(s32 *)(v + 0x2C0), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(v + 0x2C4), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(a0, *(s32 *)(v + 0x2C8), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(v + 0x2CC), 10.0f, 1.0f);
        }
    }
    return 0;
}
/* localdecomp:end func_L11_003A9860 */

/* localdecomp:start func_L11_003A9B30 */
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(u8 *, s32, s32, s32);

s32 func_L11_003A9B30(u8 *a0)
{
    u8 *v = *(u8 **)(a0 + 0x68);

    *(u16 *)(a0 + 0x7C) = 0xFF;
    *(f32 *)(v + 0x190) = 0.5f;
    *(f32 *)(v + 0x194) = 0.5f;
    v[0x1D7] = 1;
    v[0x1D8] = 0;
    v[0x1D9] = 0;
    v[0x1DA] = 0;
    v[0x170] = 6;
    v[0x1A8] = 3;
    *(f32 *)(v + 0x19C) = 0.150000006f;
    v[0x1DB] = 0xFF;
    *(f32 *)(v + 0x70) = 0.699999988f;
    *(f32 *)(v + 0x74) = 0.5f;
    *(f32 *)(v + 0x78) = 0.5f;
    *(f32 *)(v + 0x7C) = 1.0f;
    *(f32 *)(v + 0x80) = 0.785398185f;
    *(f32 *)(v + 0xA0) = 0.34906584f;
    *(f32 *)(v + 0x9C) = 0.00392f;
    func_L01_0045BD78(a0, 0.020000001f, 0.40000004f, 0.010053097f, 0.25132743f);
    v[0x58] = 0x14;
    v[0x5A] = 0xE;
    if (*(s16 *)(v + 0x34) == 0) {
        *(u16 *)(v + 0x34) = 100;
        *(f32 *)(v + 0x30) = 100.0f;
    }
    v[0x39] = 1;
    v[0x3E] = 1;
    *(f32 *)(v + 0x40) = 2.0f;
    func_L01_004450F0(a0, 1, 0);
    if (a0[0x43] != 2) {
        func_003C3A10(a0, 2, 0, 0);
    }
    return 0;
}
/* localdecomp:end func_L11_003A9B30 */

/* localdecomp:start func_L11_003A9CB0 */
__asm__(".extern D_L11_001D66B0, 16");
extern u8 D_L11_001D66B0;
extern void func_L01_00451FE0(void *, s32, u8 *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_004443E8(void *, s32, s32);

void func_L11_003A9CB0(u8 *a0)
{
    func_L01_00451FE0(a0, 0x3FFF, &D_L11_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0, 3);
    func_003A52A0(0, 0, a0);
    func_L01_004443E8(a0, 0, 3);
}
/* localdecomp:end func_L11_003A9CB0 */

/* localdecomp:start func_L11_003A9D50 */
void func_0038CAD0(s32);
void func_0038CB00(s32);

void func_L11_003A9D50(void *arg0) {
    s32 temp_s0;
    u16 temp_v1;

    temp_s0 = *(s32 *)((u8 *)arg0 + 0x68);
    func_0038CAD0(temp_s0 + 0x2D0);
    func_0038CB00(temp_s0 + 0x2D4);
    temp_v1 = *(u16 *)((u8 *)arg0 + 0x96);
    if (temp_v1 <= 0xFFFEU) {
        *(u16 *)((u8 *)arg0 + 0x96) = (u16) (temp_v1 + 1);
    }
}
/* localdecomp:end func_L11_003A9D50 */
