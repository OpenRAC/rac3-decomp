/* functional: high. Read block-by-block against PAL asm; check.py differs only by register allocation/schedule; all calls, args, stores identical. */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L05_003BD5E0 */
typedef struct { u8 pad[0x10]; vu0_v4 pos; u8 state; u8 pad21[0x47]; u8 *vars; u8 pad6C[0x3E]; s16 type; u8 padAC[0xC]; u8 *parent; } M_003BD5E0;
extern void func_003C2F58(void *, s32, void *);
extern void func_003C5180(void *, void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038D890(void *, void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_0038CE20(void *, void *, f32);
extern u8 *func_00382348(void *);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_003D4D00(void *, s32, void *, void *, f32);
extern s32 func_0038CAD0(void *);
extern void func_003C2880(void *);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_00404A10();
extern void func_L05_003BDB68();
extern void func_L05_003BD078(void *);
extern void func_L05_003BDFA8();
extern M_003BD5E0 *D_001A71A0[];
extern f32 D_L05_001DEAE4;
__asm__(".extern D_L05_001DEAE4, 4");
extern vu0_v4 D_L05_001EA6E0[];
extern u8 D_L05_001D66B0[16];
extern u8 *D_L05_00220758[];

void func_L05_003BD5E0(M_003BD5E0 *m) {
    vu0_v4 p0, p10, p20, p30, hit, dir;
    u8 damage[0x30] __attribute__((aligned(16)));
    u8 *v = *(u8 **)((u8 *)m + 0x68);
    f32 angle;
    s32 i;
    u8 *part;
    u8 *other;
    f32 size;

    func_003C2F58(m->parent, *(s32 *)(v + 0x1C), &p0);
    *(vu0_q *)&m->pos = *(vu0_q *)&p0;
    func_003C5180(&m->pos, &p10, 1);
    *(vu0_q *)&p20 = *(vu0_q *)&m->pos;
    vec_sub_ba(&p30, v + 0x30, &m->pos);
    func_0038CF68(&p30, &p30, 1.0f);
    angle = func_0038D160(*(f32 *)(v + 0x30) - (*D_001A71A0)->pos.x, *(f32 *)(v + 0x34) - (*D_001A71A0)->pos.y);
    if (angle < 1.5707964f) {
        angle = func_003824E0(0.0f, -0.7853982f);
    } else {
        angle = func_003824E0(0.0f, 0.7853982f);
    }
    *(vu0_q *)(v + 0x40) = *(vu0_q *)&m->pos;
    *(f32 *)(v + 0x48) -= D_L05_001DEAE4;
    vec_sub_ba(v + 0x40, v + 0x40, &m->pos);
    func_0038D890(v + 0x40, v + 0x40, &p30, angle);
    vec_add_ab(v + 0x40, &m->pos, v + 0x40);
    switch (m->state) {
    case 0:
        if (*(s16 *)(m->parent + 0xAA) != 0x1BF6) {
            if (func_003D3CB0(&m->pos, v + 0x30, 2, m->parent, 0)) {
                *(vu0_q *)(v + 0x30) = *(vu0_q *)D_L05_001EA6E0;
            }
            if (func_003D3CB0(&m->pos, v + 0x30, 0, m->parent, 0)) {
                f32 scale = 1.0f;
                *(vu0_q *)&hit = *(vu0_q *)D_L05_001EA6E0;
                vec_sub_ba(&dir, v + 0x30, &m->pos);
                func_0038CF68(&dir, &dir, 1.0f);
                func_0038CE20(&dir, &dir, 1.0f);
                dir.w = 5627.9248046875f;
                other = func_00382348(m->parent);
                if (other) {
                    scale = (f32)other[0x14];
                }
                func_L01_00446760(damage, m, 1, &dir, scale);
                damage[0x19] = 1;
                *(u16 *)(damage + 0x1A) = m->type;
                damage[0x18] = 1;
                func_003D4D00(&hit, 0, m, damage, 0.25f);
                other = *(u8 **)((u8 *)D_L05_001EA6E0 - 8);
                if (!other) {
                    func_L05_003BDFA8(&hit, 15, m);
                } else if (*(s32 *)(other + 0x98)) {
                    func_L05_003BDFA8(&hit, 10, m);
                }
            }
        }
        m->state = 1;
        *(s32 *)(v + 0x10) = (D_L05_001DEAE0 * 5 + 2) / 6;
        if (*(s16 *)(m->parent + 0xAA) == 0x1BF6) {
            *(s32 *)(v + 0x10) <<= 3;
        }
        break;
    case 1:
        if (func_0038CAD0(v + 0x10)) {
            *(s32 *)(v + 0xC) = 0;
            D_L05_002A64C0[*(s32 *)(v + 0x60)][0] = 0;
            func_003C2880(m);
            return;
        }
        for (i = 9; i >= 0; i--) {
            size = func_003824E0(0.15f, 0.25f) * 210000.0f;
            part = func_L01_0046FB40(&m->pos, D_L05_001D66B0, 2, 0x1010FF, 2, 0x7F, 0x10, 0, size, size, 0.0f);
            if (part) {
                part[2] = **(u8 **)((u8 *)D_L05_00220758 + 0x64);
            }
            part = func_L01_0046FB40(&m->pos, D_L05_001D66B0, 2, 0x1010FF, -1, 0x7F, 0x10, 0, size, size, 0.0f);
            if (part) {
                part[2] = **(u8 **)((u8 *)D_L05_00220758 + 0x1A0);
            }
        }
        if (*(s32 *)(v + 0x10) >= 6) {
            func_L05_003BD078(m);
        }
        func_L01_00404A10(func_L05_003BDB68, m);
        break;
    }
    if (m->pos.x < 2.0f || m->pos.x > 1021.0f || m->pos.y < 2.0f || m->pos.y > 1021.0f || m->pos.z < 2.0f || m->pos.z > 1021.0f) {
        D_L05_002A64C0[*(s32 *)(v + 0x60)][0] = 0;
        func_003C2880(m);
    }
}
/* localdecomp:end func_L05_003BD5E0 */
