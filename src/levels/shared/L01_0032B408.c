#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L01_0032B408);

/* localdecomp:start func_L01_0032BCB0 */
typedef int s128 __attribute__((mode(TI)));

extern f32 D_L01_001DCE30;
__asm__(".extern D_L01_001DCE30, 4");
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
typedef struct {
    u8 pad0[0x100];
    s32 w100[0x40];
} T_0032BCB0;
extern T_0032BCB0 D_L01_00276E60;
extern void func_L01_004C7D40(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_L01_004CADE8(void *, void *);
extern void func_L01_0032CA80(void);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00444F38(void *, s32, s32, s32, s32);

void func_L01_0032BCB0(u8 *self) {
    f32 old[4] __attribute__((aligned(16)));
    u8 *s;

    *(s128 *)old = *(s128 *)(self + 0x10);
    s = *(u8 **)(self + 0x68);
    vec_add_ab(self + 0x10, self + 0x10, s);
    func_L01_004C7D40(self + 0x10, s, D_L01_001DCE30 * 0.00040000002f * 0.1f);
    if (func_003D3CB0(old, self + 0x10, 0x10, self, 0) != 0) {
        self[0x20] = 8;
        if (D_001D545C == 0x1C) {
            s[0x4E] = func_L01_004CADE8(&D_L01_00276E60, self);
            func_L01_0032CA80();
            if (D_L01_00276E60.w100[(s8)s[0x4E]] != 0) {
                self[0x20] = 2;
                func_003A52A0(1, 0, self);
                func_L01_00444F38(self, 1, 0, 0, 0);
            } else {
                self[0x20] = 6;
            }
        }
    }
}
/* localdecomp:end func_L01_0032BCB0 */

/* localdecomp:start func_L01_0032BDD8 */
/* from the NTSC-U draft of func_L01_0032B970 (nonmatching/levels/func_L01_0032BDD8.c) */
/* log: draft with PAL catalogue names (func_00382468, func_003C3EC8, func_0038CE20, func_003824E0, func_L01_00468678) -> MATCH under the file's @ps2as line */
extern s32 func_00382468(s32);
extern f32 func_003C3EC8(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_L01_00468678(void *, void *, f32, f32, s32);

void func_L01_0032BDD8(u8 *moby) {
    f32 velocity[4];
    f32 got;
    u8 *vars = *(u8 **)(moby + 0x68);

    if (func_00382468(4) != 0) {
        return;
    }
    got = func_003C3EC8(moby + 0x10, velocity);
    func_0038CE20(velocity, vars, 0.25f);
    func_L01_00468678(moby + 0x10, velocity, func_003824E0(0.05f, 0.1f) * 210000.0f, got, 0x88A0A0A0);
}
/* localdecomp:end func_L01_0032BDD8 */

/* localdecomp:start func_L01_0032BE90 */
extern void func_003C2F58(void *, s32, void *);
extern s32 func_L01_003FB640(f32 *, s32, u8 *, f32);
extern s32 D_L01_001EAA1C_0032BE90[];

void func_L01_0032BE90(u8 *a0) {
    f32 v[4];

    func_003C2F58(a0, 0, v);
    if (func_L01_003FB640(v, 2, a0, 0.2f) && D_L01_001EAA1C_0032BE90[0] > 0) {
        a0[32] = 8;
    }
}
/* localdecomp:end func_L01_0032BE90 */

/* localdecomp:start func_L01_0032BEF0 */
extern void func_L01_0044C638(void *, s32, void *, void *, void *, void *);
extern void func_003C3D30(void *, s32, s32, f32);
extern s32 D_001D545C;
extern s32 D_L01_001EAA18[];

void func_L01_0032BEF0(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);

    func_L01_0044C638(a0, *(s32 *)(s + 0x70), a0 + 0x10, a0 + 0xF0, a0 + 0x10, a0 + 0xF0);
    if (D_001D545C == 7) {
        func_003C3D30(a0 + 0x10, 0, 0, 0.5f);
        if (D_L01_001EAA18[0] == 0) {
            *(s32 *)(s + 0x70) = 0;
        }
    }
}
/* localdecomp:end func_L01_0032BEF0 */

/* localdecomp:start func_L01_0032BF70 */
typedef struct { s32 w[9]; } Params_0032BF70;
typedef struct { f32 x, y, z, w; } Vec_0032BF70;
typedef struct {
    u8 p0[0x10];
    vu0_q q10;
    Vec_0032BF70 v20;
    vu0_q q30;
    u8 p40[0xC];
    s16 h4C;
    u8 p4E[6];
    s32 w54;
    u8 p58[4];
    s32 w5C;
    u8 *w60;
    u8 p64[4];
    u8 *w68;
} S_0032BF70;
extern Params_0032BF70 D_L01_001DCE50;
extern u8 D_L01_001DAFF0;
__asm__(".extern D_L01_001DAFF0, 16");
extern f32 D_L01_001DCE44;
__asm__(".extern D_L01_001DCE44, 4");
extern void func_L01_004C7D98(void *, void *);
extern void func_003C2F58(void *, s32, void *);
extern u8 *func_L01_004501E8(void *, void *, f32, f32, f32, void *, s32, s32, s32, f32, f32, s32, void *, s32, s32, s32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C48A8(void *, void *);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_00382760(void *, f32, f32, f32);

void func_L01_0032BF70(u8 *self) {
    S_0032BF70 *s = *(S_0032BF70 **)(self + 0x68);
    vu0_v4 v20;
    vu0_v4 pos;
    vu0_v4 quat;
    vu0_v4 axis;
    vu0_v4 tail;
    vu0_v4 m[4];
    Vec_0032BF70 at;
    f32 a;
    f32 r;

    func_L01_004C7D98(self + 0x10, &v20);
    func_003C2F58(self, 0, &pos);
    if (s->w68 == 0) {
        *(Params_0032BF70 *)&quat = D_L01_001DCE50;
        if (D_L01_001DAFF0 != 0) {
            s->w68 = func_L01_004501E8(&pos, self + 0xC0, 6.2831855f, 6.2831855f, 35.0f, &at, 0, 0, 0, 0.0f, 0.0f, 0, &quat, 1, -1, 0);
        } else {
            s->w68 = func_L01_004501E8(&pos, self + 0xC0, 6.2831855f, 6.2831855f, D_L01_001DCE44, &at, 0, 0, 0, 0.0f, 0.0f, 1, &quat, 1, -1, 1);
        }
        if (s->w68 != 0) {
            u8 *t = s->w68;

            if (*(u8 **)(t + 0x24) != 0 && (*(u8 **)(t + 0x24))[0x46] == 0x16) {
                s->w60 = t;
            }
            self[0x20] = 4;
            s->w5C = 0;
        }
    }
    if (s->h4C != 0 || s->w68 != 0) {
        if (s->w68 == 0) {
            *(vu0_q *)&axis = 0;
            axis.z = 1.0f;
            m[0] = *(vu0_v4 *)&s->q30;
            func_0038CE90(&m[1], &m[0], &axis);
            func_0038CF68(&m[1], &m[1], 1.0f);
            func_0038CE90(&m[2], &m[1], &m[0]);
            m[3].x = 0.0f;
            m[3].y = 0.0f;
            m[3].z = 0.0f;
            m[3].w = 1.0f;
            func_003C48A8(&m[0], &quat);
            r = func_L01_00443A18(0.7853982f, 1.5707964f);
            a = func_0038DAB8(quat.z, r);
            r = func_003824E0(-0.1f, 0.45f);
            func_00382760(&s->v20, 1.0f, a, r);
        }
        s->h4C = 0;
        s->w54 = 0;
        s->q10 = s->q30;
    }
}
/* localdecomp:end func_L01_0032BF70 */

/* localdecomp:start func_L01_0032C220 */
extern void *func_00382348(void *);
extern void func_L01_004C7D98(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0040EE50(void *, void *);
extern void func_0038D000(void *, void *, void *);

void func_L01_0032C220(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    u8 *t;
    u8 *m;
    vu0_v4 v0;
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40[3];
    vu0_q qa, qb, qr;
    f32 f;

    t = func_00382348(*(void **)(s + 0x68));
    func_L01_004C7D98(a0 + 0x10, &v10);
    *(vu0_q *)&v0 = *(vu0_q *)(*(u8 **)(s + 0x68) + 0x10);
    if (t != 0) {
        func_0038CE20(&v30, *(u8 **)(s + 0x68) + 0xE0, *(f32 *)(t + 0x10));
        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(v0));
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(v30));
    } else {
        *(vu0_q *)&v0 = *(vu0_q *)(*(u8 **)(*(u8 **)(s + 0x68) + 0x24) + 0x30);
        f = *(f32 *)(*(u8 **)(s + 0x68) + 0x2C) * 0.0009765625f;
        func_0038CE20(&v0, &v0, f);
        v0.w = v0.w * f;
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(v0));
        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)(*(u8 **)(s + 0x68) + 0x10)));
    }
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(v0) : "j"(qr));
    m = *(u8 **)(s + 0x68);
    if (m == 0 || m[0x20] == 0xFE || m[0x20] == 0xFD || (*(u16 *)(m + 0x34) & 0x1000) == 0) {
        a0[0x20] = 3;
        *(s32 *)(s + 0x68) = 0;
    } else {
        s += 0x20;
        func_003C2F58(a0, 0, &v20);
        vec_sub_ab(&v30, &v0, &v20);
        func_0038CF68(s, &v30, 1.0f);
        func_L01_0040EE50(v40, a0 + 0xC0);
        func_0038D000(s, s, v40);
    }
}
/* localdecomp:end func_L01_0032C220 */

/* localdecomp:start func_L01_0032C390 */
typedef struct { u8 pad[0x15]; u8 index; } State_0032C390;
typedef struct { u8 pad[0x4C]; f32 speed, delay; u8 tail[0x9C]; } Row_0032C390;
extern State_0032C390 D_001425C0;
extern Row_0032C390 D_L01_002C5600[];
extern s32 D_L01_001DCE48;
__asm__(".extern D_L01_001DCE48, 4");
extern void func_L01_004CABD8(void *, void *, void *);
extern void func_L01_0032CAA0(void *, void *);
extern s32 func_003C4B50(void *);


void func_L01_0032C390(u8 *m) {
    vu0_v4 direction, target, delta, reference, forward;
    u8 *p = *(u8 **)(m + 0x68);
    u8 *desc;
    f32 scale;
    func_003C2F58(m, 1, &reference);
    func_L01_004C7D98(m + 0x10, &direction);
    if (*(f32 *)(p + 0x5C) == 0.0f && *(s32 *)(p + 0x50) && *(u8 **)(p + 0x68)) {
        desc = func_00382348(*(u8 **)(p + 0x68));
        target = *(vu0_v4 *)(*(u8 **)(p + 0x68) + 0x10);
        if (desc) {
            func_0038CE20(&forward, *(u8 **)(p + 0x68) + 0xE0, *(f32 *)(desc + 0x10));
            vec_add_ab(&target, &target, &forward);
        } else {
            target = *(vu0_v4 *)(*(u8 **)(*(u8 **)(p + 0x68) + 0x24) + 0x30);
            scale = *(f32 *)(*(u8 **)(p + 0x68) + 0x2C) * 0.0009765625f;
            func_0038CE20(&target, &target, scale);
            target.w *= scale;
            vec_add_ab(&target, *(u8 **)(p + 0x68) + 0x10, &target);
        }
        vec_sub_ab(&delta, &target, &reference);
        func_0038CF68(&delta, &delta, D_001425C0.index[D_L01_002C5600].speed * 0.020000001f);
        func_L01_004CABD8(&delta, &delta, &reference);
        func_L01_0032CAA0(m, &delta);
        func_003A52A0(0, 0, m);
        *(s32 *)(p + 0x40) = (D_L01_001DCE48 * 5 + 2) / 6;
        *(s32 *)(p + 0x44) = 5;
        if (!func_003C4B50(*(u8 **)(p + 0x68))) (*(u16 *)(p + 0x64))--;
        if (*(s16 *)(p + 0x64) <= 0) m[0x20] = 8;
        *(f32 *)(p + 0x5C) = 1.0f / D_L01_002C5600[D_001425C0.index].delay;
    }
}
/* localdecomp:end func_L01_0032C390 */
