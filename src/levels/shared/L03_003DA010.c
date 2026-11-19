#include "common.h"

/* localdecomp:start func_L03_003DA010 */
extern void func_L03_003DA058(s32 a0);
typedef struct { s32 w0; s32 w4; f32 f8; s32 wC; void *w10; } P_3D7F00;
typedef struct { u8 p0[0x3F0]; P_3D7F00 p; u8 pad[0x460 - 0x3F0 - 0x14]; } E_3D7F00;
extern E_3D7F00 D_L03_001E24C0[];

void func_L03_003DA010(s32 i) {
    E_3D7F00 *e = &D_L03_001E24C0[i];
    P_3D7F00 *p = &e->p;
    p->w4 = 0;
    e->p.w0 = 0;
    p->f8 = 10000.0f;
    p->wC = 0;
    p->w10 = ((void (*)(void))func_L03_003DA058);
}
/* localdecomp:end func_L03_003DA010 */

/* localdecomp:start func_L03_003DA058 */
extern E_3D7F00 D_L03_001E24C0[];
typedef struct {
    u8 pad0[1020];
    f32 f1020;
    u8 pad1[96];
} Ent1120;
extern void func_L01_003E8C70(f32 a, f32 b, s32 a0, s32 a1);
extern void func_L03_003DA0E0(void);
extern void func_L03_003E0F30(s32 a0, void (*cb)(void));
void func_L03_003DA058(s32 a0) {
    f32 v;
    v = (((Ent1120 *)&D_L03_001E24C0) + a0)->f1020;
    if (v != 0.0f) {
        func_L01_003E8C70(v * 0.35f + 0.0f, 0.005f, a0, 1);
        func_L03_003E0F30(a0, func_L03_003DA0E0);
    }
}
/* localdecomp:end func_L03_003DA058 */

/* localdecomp:start func_L03_003DA0E0 */
/* Ps2EeAs only uses $gp for this if it knows it is small before the use. */
__asm__(".extern D_L03_001DF0B4, 4");
extern f32 D_L03_001DF0B4;

void func_L03_003DA0E0_probe(s32 i) __asm__("func_L03_003DA0E0");
void func_L03_003DA0E0_probe(s32 i) {
    E_3D7F00 *e = &D_L03_001E24C0[i];
    P_3D7F00 *p = &e->p;
    p->f8 = 10000.0f;
    if (p->w4 == 0) {
        *(f32 *)&p->wC -= D_L03_001DF0B4;
        if (*(f32 *)&p->wC < 0.0f) {
            *(f32 *)&p->wC = 0.0f;
        }
    } else {
        p->w4 = 0;
    }
    p->w0 = 0;
}
/* localdecomp:end func_L03_003DA0E0 */

/* localdecomp:start func_L03_003DA148 */
extern E_3D7F00 D_L03_001E24C0_003DA148[];
#include "vu0.h"

__asm__(".extern D_L03_001DF0B4_003DA148, 4");
extern f32 D_L03_001DF0B4_003DA148;

typedef struct { u8 pad0[0x30]; vu0_v4 v30; u8 pad40[0x86 - 0x40]; s16 h86; } M_3DA148_003DA148;
typedef struct { u8 pad0[0x104]; f32 f104; } Q_3DA148_003DA148;
extern f32 func_0038CEA8(void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D0C8(f32);

void func_L03_003DA148(s32 i, s32 target) {
    E_3D7F00 *e = &D_L03_001E24C0_003DA148[i];
    M_3DA148_003DA148 *m = *(M_3DA148_003DA148 **)((u8 *)e + 0x50);
    P_3D7F00 *p;
    vu0_v4 d;
    f32 dist;
    f32 a;

    if (m->h86 != 0) {
        return;
    }
    if (0.05f < fabs_asm((*(Q_3DA148_003DA148 **)((u8 *)e + 0x284))->f104)) {
        return;
    }
    vec_sub_ab(&d, (void *)(target + 0x10), (u8 *)e + 0x190);
    p = &e->p;
    dist = func_0038CEA8(&d);
    if (dist < 22.0f && 0.0f < dist && dist < p->f8 && 0.0f < d.z) {
        a = 1.5707964f - func_0038D0C8(func_0038CE68(m, &d) / dist);
        if (a < 1.1170107f) {
            vec_sub_ba(&d, (void *)(target + 0x10), &m->v30);
            dist = func_0038CEA8(&d);
            if (dist == 0.0f) {
                dist = 0.0001f;
            }
            a = 1.5707964f - func_0038D0C8(func_0038CE68(m, &d) / dist);
            if (a < 0.62831855f) {
                p->f8 = dist;
                p->w4 = target;
                e->p.w0 = (s32)m;
                *(f32 *)&p->wC += D_L03_001DF0B4_003DA148;
                if (1.0f < *(f32 *)&p->wC) {
                    *(f32 *)&p->wC = 1.0f;
                }
            }
        }
    }
}
/* localdecomp:end func_L03_003DA148 */
