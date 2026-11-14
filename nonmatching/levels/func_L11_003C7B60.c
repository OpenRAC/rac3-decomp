/* near miss (level 11, Obani Moons): 345-word diff with --as ps2as and the temporary
   divs_nops row `func_L11_003C7B60 2 2` (472 without the row; 477 with the default
   assembler). The owning file src/levels/11_obani_moons/L11_003C7B60.c needs @ps2as: retail
   builds every float constant inline (lui/ori/mtc1). Left: the prologue's table-pointer load
   order, the hero-base register ($s2 hi / $s0 base in retail), func_0038CAD0's bc1tl versus
   bc1fl+b (+1 word), and a few float load/mul.s schedules; 60 of the diffs are
   register/immediate only.

   WARNING: the function reads $s3 before ever writing it (retail does the same; the sole
   caller does not set it). This C reproduces that with an uninitialized local, which is
   undefined behaviour and AGENTS.md's "reads registers it never sets" stop signal, so it stays
   a near miss. A K&R definition is required: a later block of the file calls it with no
   arguments. The function never sets $2, so it is effectively void. */
#include "common.h"


typedef struct {
    u8 pad_0[0x70];
    u8 *follow;              /* 0x70 */
    u8 pad_74[0x84 - 0x74];
    s16 record_index;        /* 0x84 */
    s16 cls;                 /* 0x86 */
    u8 pad_88[0x94 - 0x88];
    s32 player;              /* 0x94 */
} CU_3C7B60;

typedef struct {
    u8 pad_0[0x20];
    s32 state;               /* 0x20 */
    f32 f24;                 /* 0x24 */
    s32 ids[6];              /* 0x28 */
    f32 f40;                 /* 0x40 */
    f32 f44;                 /* 0x44 */
    f32 f48;                 /* 0x48 */
    f32 f4C;                 /* 0x4C */
    s32 timer;               /* 0x50 */
} M_3C7B60;

typedef struct {
    f32 x, y, z;             /* 0x00 */
    u8 pad_C[0x1C - 0xC];
    M_3C7B60 *m;             /* 0x1C */
} R_3C7B60;

typedef struct {
    u8 pad_0[0x170];
    f32 f170;                /* 0x170 */
    u8 pad_174[0x46E - 0x174];
    u8 b46E;                 /* 0x46E */
    u8 pad_46F[0x4F0 - 0x46F];
    f32 f4F0;                /* 0x4F0 */
    u8 pad_4F4[0x1434 - 0x4F4];
    s16 h1434;               /* 0x1434 */
    u8 pad_1436[0x25C0 - 0x1436];
    u8 *f25C0;               /* 0x25C0 */
    s32 f25C4;               /* 0x25C4 */
    u8 pad_25C8[0x25CC - 0x25C8];
    s32 f25CC;               /* 0x25CC */
    u8 pad_25D0[0x25E4 - 0x25D0];
    u8 vehicle_mode;         /* 0x25E4 */
} H_3C7B60;

typedef struct { u8 pad_100[0x100]; f32 right_x; f32 right_y; } P_3C7B60;

extern u8 *D_L11_001DE604[];
extern u8 D_L11_001E1780[];
extern s32 D_L11_001D673C[];
extern s32 D_001D545C[];
__asm__(".extern D_001D545C_sda, 4");
extern s32 D_001D545C_sda;
extern s32 D_001A71A4[];
extern P_3C7B60 *D_001D52FC[];
__asm__(".extern D_001D52FC_sda, 4");
extern P_3C7B60 *D_001D52FC_sda;
__asm__(".extern D_001FE990_sda, 4");
extern s32 D_001FE990_sda;
extern u8 D_001A4C60[];
extern u8 D_001A4C90[];
extern u8 D_001A4BE0[];

extern f32 D_001DE4B4_sda;
__asm__(".extern D_001DE4B4_sda, 4");
extern f32 D_001DE4B8_sda;
__asm__(".extern D_001DE4B8_sda, 4");
extern f32 D_001DE4BC_sda;
__asm__(".extern D_001DE4BC_sda, 4");
extern f32 D_001DE4C0_sda;
__asm__(".extern D_001DE4C0_sda, 4");
extern f32 D_001DE4C4_sda;
__asm__(".extern D_001DE4C4_sda, 4");
extern f32 D_001DE4C8_sda;
__asm__(".extern D_001DE4C8_sda, 4");
extern f32 D_001DE4CC_sda;
__asm__(".extern D_001DE4CC_sda, 4");
extern f32 D_001DE4D0_sda;
__asm__(".extern D_001DE4D0_sda, 4");
extern f32 D_001DE4D4_sda;
__asm__(".extern D_001DE4D4_sda, 4");
extern f32 D_001DE4D8_sda;
__asm__(".extern D_001DE4D8_sda, 4");
extern f32 D_001DE4DC_sda;
__asm__(".extern D_001DE4DC_sda, 4");
extern f32 D_001DE4E0_sda;
__asm__(".extern D_001DE4E0_sda, 4");

extern f32 func_0038CF00(void *, void *);
extern s32 func_00382380(void *, s32, s32);
extern s32 func_0038CAD0(void *);
extern s32 func_L01_003E8AD8(u8 *);
extern s32 func_L01_003E8B28(u8 *);
extern f32 func_L01_00451580(void *);
extern void func_L01_003E8E70(s32);
extern void func_L01_003E8D80(s32, s32);
extern void func_L01_003E8EA8(s32);
extern void func_L01_003E8DB8(s32, f32, f32);
extern void func_L01_003E9250(s32, f32 *, f32, f32);
extern f32 func_L01_00510478(f32, f32, f32);
extern void func_L11_003C36A8(s32, f32, f32);
extern void func_L01_003E8E10(s32, f32, f32);
extern void func_L01_003E8C70(s32, s32, f32, f32);
extern void func_L01_003E8BD0(s32, s32, f32, f32);
extern void func_L01_003E8C28(s32, f32, f32);
extern void func_L01_003E8D48(s32, f32);

s32 *func_L11_003C7B60(cam)
CU_3C7B60 *cam;
{
    R_3C7B60 *r;
    M_3C7B60 *m;
    CU_3C7B60 *u2;
    u8 *u;
    u8 *gc;
    P_3C7B60 *pad;
    f32 v[4];
    s32 n;
    s32 i;
    s32 id;

    r = (R_3C7B60 *)((u8 *)D_L11_001DE604[0] + cam->record_index * 0x20);
    m = r->m;
    if (m->state == 0) {
        if (!D_L11_001D673C[0] &&
            (D_001D545C[0] != 0x10 || D_001A71A4[0] != 0x86))
            return;
        v[0] = r->x;
        v[1] = r->y;
        v[2] = r->z;
        v[3] = 0.0f;
        m->f24 = func_0038CF00(v, D_001A4C90);
        m->state = 1;
        return;
    }

    gc = (u8 *)D_L11_001E1780 + cam->player * 0x460;
    u = *(u8 **)(gc + 0x50);
    if (*(s16 *)(u + 0x86) != 0 ||
        !(D_L11_001D673C[0] ||
          (D_001D545C_sda == 0x10 && D_001A71A4[0] == 0x86))) {
        if (func_L01_00451580((u8 *)D_L11_001E1780 + cam->player * 0x460) >
            D_001DE4E0_sda) {
            if (D_001D545C_sda != 0xB)
                D_001FE990_sda = 3;
        } else if (D_001D545C_sda != 0xB) {
            D_001FE990_sda = 0;
        }
        func_L01_003E8AD8((u8 *)cam);
        return;
    }

    if (func_L01_003E8B28((u8 *)cam) <= 0)
        return;
    i = 0;
    do {
        id = m->ids[i];
        if (id < 0)
            break;
        if (func_00382380(D_001A4C60, id, 0) != 0) {
            func_L11_003C36A8(cam->player, 0.04f, 0.2f);
            func_L01_003E8BD0(cam->player, 0, m->f40, 0.003f);
            func_L01_003E8C28(cam->player, m->f44, 0.003f);
            return;
        }
        i++;
    } while (i < 6);

    if (((H_3C7B60 *)D_001A4BE0)->vehicle_mode == 2) {
        if (((H_3C7B60 *)D_001A4BE0)->h1434 != 0 || ((H_3C7B60 *)D_001A4BE0)->f25C4 == 0x5F ||
            __builtin_fabsf(D_001D52FC_sda->right_x) >= 0.3f ||
            __builtin_fabsf(D_001D52FC_sda->right_y) >= 0.3f) {
            func_L01_003E8E70(cam->player);
            func_L01_003E8D80(cam->player, 0);
        }
    } else {
        func_L01_003E8E70(cam->player);
        func_L01_003E8D80(cam->player, 0);
    }
    func_L01_003E8EA8(cam->player);
    func_L01_003E8DB8(cam->player, D_001DE4B8_sda, 0.2f);
    if (func_0038CAD0(&m->timer) != 0) {
        if (0.005f < ((H_3C7B60 *)D_001A4BE0)->f170) {
            pad = D_001D52FC_sda;
            goto checks;
        }
        func_L01_003E9250(cam->player, (f32 *)((u8 *)((H_3C7B60 *)D_001A4BE0)->f25C0 + 0xC0),
                          0.0052359877f, 0.0f);
    }
    pad = D_001D52FC[0];
checks:
    if (__builtin_fabsf(pad->right_x) >= 0.3f ||
        __builtin_fabsf(pad->right_y) >= 0.3f)
        m->timer = 0xFA;

    {
        H_3C7B60 *h = (H_3C7B60 *)D_001A4BE0;
        if (h->vehicle_mode == 2) {
            u8 *gc2 = (u8 *)D_L11_001E1780 + u2->player * 0x460;
            u2 = *(CU_3C7B60 **)(gc2 + 0x50);
            *(s32 *)(u2->follow + 0x270) = 2;
            n = 0;
            if (h->b46E)
                n = (s32)func_L01_00510478(90.0f, h->f4F0, -1.0f);
            if (h->f25C4 == 0x5F &&
                (!h->b46E || n >= 0x11)) {
                func_L01_003E8DB8(u2->player, 0.5f, 1.0f);
                func_L11_003C36A8(u2->player, 0.05f, 0.2f);
                func_L01_003E8E10(u2->player, 0.04f, 0.0f);
                func_L01_003E8C70(u2->player, 0, D_001DE4D8_sda, 0.005f);
                func_L01_003E8BD0(u2->player, 1, D_001DE4CC_sda, 0.01f);
                func_L01_003E8C28(u2->player, D_001DE4D0_sda, 0.01f);
                func_L01_003E8D48(u2->player, D_001DE4DC_sda * 0.017453292f);
            } else {
                f32 f;
                f32 a;
                f32 b;
                f32 t;
                func_L01_003E8C70(u2->player, 0, D_001DE4D4_sda, 0.03f);
                if (h->f25CC == 2)
                    func_L11_003C36A8(u2->player, 0.04f, 0.2f);
                else
                    func_L11_003C36A8(u2->player, 0.015f, 0.2f);
                f = func_0038CF00(D_001A4C60, D_001A4C60 + 0x30);
                f = f - m->f24;
                if (D_001DE4B4_sda < f)
                    f = D_001DE4B4_sda;
                else if (f < 0.0f)
                    f = 0.0f;
                t = f / D_001DE4B4_sda;
                a = (D_001DE4C4_sda - D_001DE4BC_sda) * t + D_001DE4BC_sda;
                b = (D_001DE4C8_sda - D_001DE4C0_sda) * t + D_001DE4C0_sda;
                func_L01_003E8BD0(u2->player, 1, a, 0.005f);
                func_L01_003E8C28(u2->player, b, 0.005f);
            }
            {
                f32 f;
                f = func_L01_00451580((u8 *)D_L11_001E1780 + u2->player * 0x460);
                D_001FE990_sda = D_001DE4E0_sda < f ? 3 : 0;
            }
            return;
        }

        if (h->f25C4 == 0x86) {
            func_L11_003C36A8(cam->player, 0.05f, 0.2f);
            func_L01_003E8E10(cam->player, 0.04f, 0.0f);
            if (D_001D545C[0] == 0x10) {
                func_L01_003E8C70(cam->player, 0, 0.5f, 0.04f);
                func_L01_003E8BD0(cam->player, 0, 4.0f, 0.002f);
                func_L01_003E8C28(cam->player, 2.0f, 0.04f);
            } else {
                func_L01_003E8C70(cam->player, 0, 1.0f, 0.04f);
                func_L01_003E8BD0(cam->player, 0, 2.0f, 0.002f);
                func_L01_003E8C28(cam->player, 7.0f, 0.04f);
            }
            return;
        }

        if (h->f25CC == 2) {
            if (D_001D545C_sda == 0xB) {
                func_L01_003E8BD0(cam->player, 0, 4.0f, 0.003f);
                func_L01_003E8C28(cam->player, 7.5f, 0.003f);
            }
            func_L11_003C36A8(cam->player, 0.04f, 0.2f);
        } else {
            func_L11_003C36A8(cam->player, 0.015f, 0.2f);
        }

        if (h->f25CC == 5) {
            func_L01_003E8BD0(cam->player, 0, 4.0f, 0.003f);
            func_L01_003E8C28(cam->player, 6.0f, 0.003f);
            if (D_001D545C[0] == 0xB) {
                func_L01_003E8BD0(cam->player, 0, 4.0f, 0.003f);
                func_L01_003E8C28(cam->player, 7.5f, 0.003f);
            }
            return;
        }

    }
    {
        f32 f;
        f32 a;
        f32 b;
        f32 t;
        f = func_0038CF00((u8 *)D_001A4BE0 + 0x80, (u8 *)D_001A4BE0 + 0xB0);
        f = f - m->f24;
        if (D_001D545C[0] == 0xB) {
            if (f > 31.0f)
                f -= 31.0f;
            if (f > 29.0f)
                f -= 29.0f;
            if (f > 17.0f)
                f -= 17.0f;
        }
        if (f > D_001DE4B4_sda)
            f = D_001DE4B4_sda;
        else if (f < 0.0f)
            f = 0.0f;
        t = f / D_001DE4B4_sda;
        if (D_001D545C[0] == 0xB) {
            m->f40 = 7.0f;
            m->f44 = 4.0f;
        }
        a = (m->f48 - m->f40) * t + m->f40;
        b = (m->f4C - m->f44) * t + m->f44;
        func_L01_003E8BD0(cam->player, 0, a, 0.003f);
        func_L01_003E8C28(cam->player, b, 0.003f);
    }
    return;
}
