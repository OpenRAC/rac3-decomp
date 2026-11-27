#include "common.h"

/* localdecomp:start func_L39_006A9E90 */
__asm__(".extern D_001DBC5C_sda, 4");
__asm__(".extern D_001DD26C_sda, 4");
__asm__(".extern D_001DD270_sda, 4");
__asm__(".extern D_001DD274_sda, 4");
__asm__(".extern D_001DD278_sda, 4");
__asm__(".extern D_001DD27C_sda, 4");
__asm__(".extern D_001DD280_sda, 4");
__asm__(".extern D_001DD284_sda, 4");
__asm__(".extern D_001DD288_sda, 4");
__asm__(".extern D_001DD28C_sda, 4");
__asm__(".extern D_001DD290_sda, 4");
__asm__(".extern D_001DD294_sda, 4");
__asm__(".extern D_001DD298_sda, 4");
__asm__(".extern D_001DD29C_sda, 4");
__asm__(".extern D_001DD2A0_sda, 4");
__asm__(".extern D_001DD2A4_sda, 4");
__asm__(".extern D_001DD2A8_sda, 4");
__asm__(".extern D_001DD2AC_sda, 4");
__asm__(".extern D_001DD2B0_sda, 4");
__asm__(".extern D_001DD2B4_sda, 4");
__asm__(".extern D_001DD2B8_sda, 4");
__asm__(".extern D_001DD2BC_sda, 4");
__asm__(".extern D_001DD2C0_sda, 4");
extern s32 D_001DBC5C_sda;
extern f32 D_001DD26C_sda, D_001DD270_sda, D_001DD274_sda, D_001DD278_sda, D_001DD27C_sda;
extern f32 D_001DD280_sda, D_001DD284_sda, D_001DD288_sda, D_001DD28C_sda, D_001DD290_sda;
extern f32 D_001DD294_sda, D_001DD298_sda, D_001DD29C_sda, D_001DD2A0_sda;
extern f32 D_001DD2A4_sda, D_001DD2A8_sda, D_001DD2AC_sda, D_001DD2B0_sda;
extern f32 D_001DD2B4_sda, D_001DD2B8_sda, D_001DD2BC_sda, D_001DD2C0_sda;
extern s32 func_L39_0067F1B0(void);
extern s32 func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E8EF0(s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_003E8630(s32, s32);
extern void func_L39_00688460(void *a0, void *p1, void *p2, void *p3, void *p4, void *p5, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5);

typedef struct {
    u8 pad0[0x39C];
    s32 f39C, f3A0, f3A4, f3A8, f3AC, f3B0, f3B4, f3B8;
} S_006A9E90;

void func_L39_006A9E90(void *a0)
{
    s32 v[4];
    S_006A9E90 *p = a0;

    func_003E9138(p->f3A4 = func_L39_0067F1B0(), 0x80000000, 0, D_001DD294_sda, D_001DD298_sda, D_001DD29C_sda, D_001DD2A0_sda);
    func_003E8630(D_001DBC5C_sda, p->f3A4);
    func_003E9138(p->f3A8 = func_L39_0067F1B0(), 0x331465B7, 0, D_001DD294_sda, D_001DD298_sda, D_001DD29C_sda, D_001DD2A0_sda);
    func_003E8630(D_001DBC5C_sda, p->f3A8);
    func_003E9138(p->f3B0 = func_L39_0067F1B0(), 0x80000000, 0, D_001DD2A4_sda, D_001DD2A8_sda, D_001DD2AC_sda, D_001DD2B0_sda);
    func_003E8630(D_001DBC5C_sda, p->f3B0);
    func_003E9138(p->f3B4 = func_L39_0067F1B0(), 0x331465B7, 0, D_001DD2A4_sda, D_001DD2A8_sda, D_001DD2AC_sda, D_001DD2B0_sda);
    func_003E8630(D_001DBC5C_sda, p->f3B4);
    func_003E9270(p->f3B8 = func_L39_0067F1B0(), 0x332299DE, D_001DD2B4_sda, D_001DD2B8_sda, D_001DD2BC_sda, D_001DD2C0_sda, 0.004f, 0.004f);
    func_003E8630(D_001DBC5C_sda, p->f3B8);
    func_003E8EF0(p->f39C = func_L39_0067F1B0(), 0x64, 0x332299DE, D_001DD26C_sda, D_001DD270_sda, D_001DD274_sda, D_001DD278_sda, D_001DD27C_sda);
    func_003E8630(D_001DBC5C_sda, p->f39C);
    func_003E8EF0(p->f3A0 = func_L39_0067F1B0(), 0x65, 0x332299DE, D_001DD280_sda, D_001DD284_sda, D_001DD288_sda, D_001DD28C_sda, D_001DD290_sda);
    func_003E8630(D_001DBC5C_sda, p->f3A0);
    func_003E9138(p->f3AC = func_L39_0067F1B0(), 0x8066CCFF, 0, 2.0f, 2.0f, 0.02f, 0.05f);
    func_003E8630(D_001DBC5C_sda, p->f3AC);
    func_L39_00688460(a0, v, v, v, v, v, 2.0f, 2.0f, 0.0f, 0.0f, 1.0f);
}
/* localdecomp:end func_L39_006A9E90 */

/* localdecomp:start func_L39_006AA0F0 */
typedef struct { f32 x, y, z, w; } V_006AA0F0;
typedef struct VT_006AA0F0 {
    u8 pad0[0x28];
    void (*f28)(void *, f32, f32);
    void (*f2C)(void *, f32, f32);
    u8 pad30[0x10];
    void (*f40)(void *, s32);
    void (*f44)(void *, s32, f32, f32);
    u8 pad48[4];
    void (*f4C)(void *, s32, s32);
} VT_006AA0F0;
typedef struct { u8 pad0[0x60]; VT_006AA0F0 *vt; } O_006AA0F0;
typedef struct {
    u8 pad0[0x118];
    O_006AA0F0 *items[52];
    u8 pad1E8[0x2AA - 0x1E8];
    u8 f2AA;
    u8 f2AB;
    s32 f2AC, f2B0, f2B4;
    s16 f2B8;
} S_006AA0F0;
__asm__(".extern D_L39_00248A18, 16");
__asm__(".extern D_L39_00248A1C, 16");
__asm__(".extern D_L39_00248A20, 16");
__asm__(".extern D_L39_00248A24, 16");
__asm__(".extern D_L39_00248A28, 16");
__asm__(".extern D_L39_00248A2C, 16");
__asm__(".extern D_L39_00248A30, 16");
__asm__(".extern D_L39_00248A34, 16");
__asm__(".extern D_L39_00248A38, 16");
__asm__(".extern D_L39_00248A3C, 16");
__asm__(".extern D_L39_00248A40, 16");
__asm__(".extern D_L39_00248A44, 16");
extern const f32 D_L39_00248A18, D_L39_00248A1C, D_L39_00248A20, D_L39_00248A24, D_L39_00248A28, D_L39_00248A2C, D_L39_00248A30, D_L39_00248A34, D_L39_00248A38, D_L39_00248A3C, D_L39_00248A40, D_L39_00248A44;

extern u8 D_001A58C7[];
extern u16 D_L39_004B0890[][5], D_L39_004B0A98[][5], D_L39_004B0CA0[][5], D_L39_004B0EA8[][5], D_L39_004B10B0[][5], D_L39_004B12B8[][5];
extern void func_L39_006A8E90(void);
extern void func_L39_006A8F08(u16 (*src)[5], s32 n);
extern s32 func_L39_0067F100(s32);
extern void func_L39_0068AAB8(void *);
extern void func_L39_006AB780(u8 *p, s32 a1, s32 a2);
extern void func_L39_006AB098(void *);
extern s32 func_L39_0068B2F8(void *, s32, s32);

void func_L39_006AA0F0(void *a0)
{
    S_006AA0F0 *p = a0;
    s32 i;

    func_L39_006A8E90();
    if (p->f2AB != 0) {
        p->f2B4 = 2;
        func_L39_006A8F08(D_L39_004B0890, 2);
    } else {
        switch (D_001A58C7[0]) {
        case 2:
            p->f2B4 = 3;
            func_L39_006A8F08(D_L39_004B0CA0, 3);
            break;
        case 3:
            p->f2B4 = 3;
            func_L39_006A8F08(D_L39_004B0EA8, 3);
            break;
        case 4:
            p->f2B4 = 3;
            func_L39_006A8F08(D_L39_004B10B0, 3);
            break;
        case 5:
            p->f2B4 = 4;
            func_L39_006A8F08(D_L39_004B12B8, 4);
            break;
        case 0:
        case 1:
        default:
            p->f2B4 = 4;
            func_L39_006A8F08(D_L39_004B0A98, 4);
            break;
        }
    }
    func_L39_0067F100(0x340000);
    func_L39_0068AAB8(p);
    {
    V_006AA0F0 v[52] = {
        { D_L39_00248A20 + D_L39_00248A40 * 0.0f, D_L39_00248A30, 0.055f, 0.055f },
        { D_L39_00248A24 + D_L39_00248A44 * 4.0f, D_L39_00248A34, 0.055f, 0.055f },
        { D_L39_00248A24 + D_L39_00248A44 * 2.0f, D_L39_00248A34, 0.055f, 0.055f },
        { D_L39_00248A20 + D_L39_00248A40 * 2.0f, D_L39_00248A30, 0.055f, 0.055f },
        { D_L39_00248A1C + D_L39_00248A3C * 2.0f, D_L39_00248A2C, 0.055f, 0.055f },
        { D_L39_00248A20 + D_L39_00248A40 * 3.0f, D_L39_00248A30, 0.055f, 0.055f },
        { D_L39_00248A20 + D_L39_00248A40 * 4.0f, D_L39_00248A30, 0.055f, 0.055f },
        { D_L39_00248A20 + D_L39_00248A40 * 5.0f, D_L39_00248A30, 0.055f, 0.055f },
        { D_L39_00248A1C + D_L39_00248A3C * 7.0f, D_L39_00248A2C, 0.055f, 0.055f },
        { D_L39_00248A20 + D_L39_00248A40 * 6.0f, D_L39_00248A30, 0.055f, 0.055f },
        { D_L39_00248A20 + D_L39_00248A40 * 7.0f, D_L39_00248A30, 0.055f, 0.055f },
        { D_L39_00248A20 + D_L39_00248A40 * 8.0f, D_L39_00248A30, 0.055f, 0.055f },
        { D_L39_00248A24 + D_L39_00248A44 * 6.0f, D_L39_00248A34, 0.055f, 0.055f },
        { D_L39_00248A24 + D_L39_00248A44 * 5.0f, D_L39_00248A34, 0.055f, 0.055f },
        { D_L39_00248A1C + D_L39_00248A3C * 8.0f, D_L39_00248A2C, 0.055f, 0.055f },
        { D_L39_00248A1C + D_L39_00248A3C * 9.0f, D_L39_00248A2C, 0.055f, 0.055f },
        { D_L39_00248A1C + D_L39_00248A3C * 0.0f, D_L39_00248A2C, 0.055f, 0.055f },
        { D_L39_00248A1C + D_L39_00248A3C * 3.0f, D_L39_00248A2C, 0.055f, 0.055f },
        { D_L39_00248A20 + D_L39_00248A40 * 1.0f, D_L39_00248A30, 0.055f, 0.055f },
        { D_L39_00248A1C + D_L39_00248A3C * 4.0f, D_L39_00248A2C, 0.055f, 0.055f },
        { D_L39_00248A1C + D_L39_00248A3C * 6.0f, D_L39_00248A2C, 0.055f, 0.055f },
        { D_L39_00248A24 + D_L39_00248A44 * 3.0f, D_L39_00248A34, 0.055f, 0.055f },
        { D_L39_00248A1C + D_L39_00248A3C * 1.0f, D_L39_00248A2C, 0.055f, 0.055f },
        { D_L39_00248A24 + D_L39_00248A44 * 1.0f, D_L39_00248A34, 0.055f, 0.055f },
        { D_L39_00248A1C + D_L39_00248A3C * 5.0f, D_L39_00248A2C, 0.055f, 0.055f },
        { D_L39_00248A24 + D_L39_00248A44 * 0.0f, D_L39_00248A34, 0.055f, 0.055f },
        { D_L39_00248A18 + D_L39_00248A38 * 0.0f, D_L39_00248A28, 0.055f, 0.055f },
        { D_L39_00248A18 + D_L39_00248A38 * 1.0f, D_L39_00248A28, 0.055f, 0.055f },
        { D_L39_00248A18 + D_L39_00248A38 * 2.0f, D_L39_00248A28, 0.055f, 0.055f },
        { D_L39_00248A18 + D_L39_00248A38 * 3.0f, D_L39_00248A28, 0.055f, 0.055f },
        { D_L39_00248A18 + D_L39_00248A38 * 4.0f, D_L39_00248A28, 0.055f, 0.055f },
        { D_L39_00248A18 + D_L39_00248A38 * 5.0f, D_L39_00248A28, 0.055f, 0.055f },
        { D_L39_00248A18 + D_L39_00248A38 * 6.0f, D_L39_00248A28, 0.055f, 0.055f },
        { D_L39_00248A18 + D_L39_00248A38 * 7.0f, D_L39_00248A28, 0.055f, 0.055f },
        { D_L39_00248A18 + D_L39_00248A38 * 8.0f, D_L39_00248A28, 0.055f, 0.055f },
        { D_L39_00248A18 + D_L39_00248A38 * 9.0f, D_L39_00248A28, 0.055f, 0.055f },
        { D_L39_00248A24 + D_L39_00248A44 * 7.0f, D_L39_00248A34, 0.055f, 0.055f },
        { D_L39_00248A24 + D_L39_00248A44 * 8.0f, D_L39_00248A34, 0.055f, 0.055f },
        { D_L39_00248A24 + D_L39_00248A44 * 9.0f, D_L39_00248A34, 0.055f, 0.055f },
        { D_L39_00248A20 + D_L39_00248A40 * 9.0f, D_L39_00248A30, 0.055f, 0.055f },
        { D_L39_00248A20 + D_L39_00248A40 * 10.0f, D_L39_00248A30, 0.055f, 0.055f },
        { D_L39_00248A1C + D_L39_00248A3C * 10.0f, D_L39_00248A2C, 0.055f, 0.055f },
        { D_L39_00248A1C + D_L39_00248A3C * 11.0f, D_L39_00248A2C, 0.055f, 0.055f },
        { D_L39_00248A18 + D_L39_00248A38 * 10.0f, D_L39_00248A28, 0.055f, 0.055f },
        { D_L39_00248A18 + D_L39_00248A38 * 11.0f, D_L39_00248A28, 0.055f, 0.055f },
        { 0.155f, D_L39_00248A34, 0.112f, 0.055f },
        { 0.143f, D_L39_00248A30, 0.09f, 0.055f },
        { 0.837f, D_L39_00248A34, 0.132f, 0.055f },
        { 0.85f, D_L39_00248A30, 0.105f, 0.055f },
        { 0.859f, D_L39_00248A28, 0.09f, 0.055f },
        { 0.0f, 0.0f, 0.05f, 0.05f },
        { 0.0f, 0.0f, 0.05f, 0.05f },
    };

    for (i = 2; i < 0x36; i++) {
        f32 x = v[i - 2].x;
        f32 y = v[i - 2].y;
        f32 z = v[i - 2].z;
        f32 w = v[i - 2].w;
        s32 f;
        p->items[i - 2]->vt->f28(p->items[i - 2], x, y);
        p->items[i - 2]->vt->f2C(p->items[i - 2], z, w);
        f = i >= 0x2F;
        p->items[i - 2]->vt->f40(p->items[i - 2], f);
        p->items[i - 2]->vt->f44(p->items[i - 2], f, z, 0.0f);
        p->items[i - 2]->vt->f4C(p->items[i - 2], 0x40, 1);
    }
    }
    func_L39_006AB780(a0, 1, 0);
    p->f2AC = 0;
    p->f2B0 = 0;
    p->f2AA = 0;
    p->f2B8 = 0;
    func_L39_006AB098(p);
    func_L39_0068B2F8(p, 8, 0);
}
/* localdecomp:end func_L39_006AA0F0 */
