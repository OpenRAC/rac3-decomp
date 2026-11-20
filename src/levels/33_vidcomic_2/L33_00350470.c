#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L33_00350470 */
extern f32 func_0038DAB8(f32, f32);
extern void func_L30_0034C8A8(void *, void *);
extern s32 func_L01_003FB640(void *, s32, f32, void *);
extern f32 func_0038CE68(void *, void *);
extern void func_L01_00446BC8(void *, void *, s32, void *, f32);
extern void func_L33_00350188(void *, void *);
extern void func_L01_004450F0(void *, s32, s32);

typedef struct {
    u8 obj[0x10];
    s32 val;
} E_00350470;

typedef struct {
    u8 pad0[0x18];
    u8 *moby;
    u8 pad1C[4];
    vu0_v4 pos;
} T_00350470;

typedef struct {
    u8 pad[0x25C0];
    u8 *moby;
} H_00350470;

extern E_00350470 D_L33_001E1830_00350470 __attribute__((section(".sdata")));
extern T_00350470 D_L33_001E9600;
extern H_00350470 D_001A4BE0;

void func_L33_00350470(u8 *m) {
    u8 *v;
    u8 *t;
    vu0_v4 d;

    v = *(u8 **)(m + 0x68);
    *(f32 *)(v + 0x8) += *(f32 *)(v + 0x14);
    vec_add_ba(m + 0x10, m + 0x10, v);
    *(f32 *)(m + 0xF4) = func_0038DAB8(*(f32 *)(m + 0xF4), *(f32 *)(v + 0x28));
    func_L30_0034C8A8(D_L33_001E1830_00350470.obj, m);
    if (func_L01_003FB640(m + 0x10, 0x10, *(f32 *)(v + 0x20), *(void **)(v + 0x1C)) == 0) {
        return;
    }
    vec_sub_ba(&d, &D_L33_001E9600.pos, m + 0x10);
    if (!(0.0f < func_0038CE68(&d, v))) {
        return;
    }
    t = D_L33_001E9600.moby;
    if (t != 0) {
        if (t == *(void **)(v + 0x1C)) {
            return;
        }
        if (*(s16 *)(t + 0xAA) == 0x1761) {
            return;
        }
        if (*(s16 *)(t + 0xAA) == 0x1760) {
            return;
        }
        if (*(s16 *)(t + 0xAA) == 0x175F) {
            return;
        }
        if (t != 0 && t == D_001A4BE0.moby) {
            func_L01_00446BC8(t, m, 0x30001, &D_L33_001E9600.pos, 20.0f);
        }
    }
    func_L33_00350188(m, &D_L33_001E9600.pos);
    *(vu0_q *)(m + 0x10) = *(vu0_q *)&D_L33_001E9600.pos;
    func_L01_004450F0(m, 0, -1);
}
/* localdecomp:end func_L33_00350470 */

/* localdecomp:start func_L33_003505D8 */
extern f32 func_0038DB48(f32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003A4F28(s32);
extern void func_L02_003BA9F8(void *, void *, void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern u8 D_L33_001E1830[] __attribute__((section(".sdata")));
extern u8 D_001A30B0[];
extern u8 *D_001A71A0[];
extern f32 D_L33_001DD84C;
__asm__(".extern D_L33_001DD84C, 4");
extern f32 D_L33_001DD850;
__asm__(".extern D_L33_001DD850, 4");

/* the target was reached: stop the looping sound if it is still this moby's, then burst */
static __inline__ void explode_003505D8(u8 *self, u8 *p) {
    s32 h = *(s32 *)(p + 0x24);
    u8 *e;

    if (h != -1) {
        e = D_001A30B0 + h * 128;
        if (*(u8 **)(e + 0xDC) == self && e[0xD0] != 0) {
            func_003A4F28(h);
        }
    }
    *(s32 *)(p + 0x24) = -1;
    func_L33_00350188(self, &D_L33_001E9600.pos);
    func_L01_004450F0(self, 0, -1);
}

void func_L33_003505D8(u8 *self) {
    vu0_v4 grav;
    vu0_v4 d;
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40;
    u8 *p = *(u8 **)(self + 0x68);
    u8 *m;

    qzero(&grav);
    grav.z = D_L33_001DD84C;
    func_L30_0034C8A8(D_L33_001E1830, self);
    vec_add_ba(self + 0x10, self + 0x10, p);
    *(f32 *)(self + 0xF4) = func_0038DAB8(*(f32 *)(self + 0xF4), func_0038DB48(*(f32 *)p / *(f32 *)(p + 0x20)));
    {
        s32 h = *(s32 *)(p + 0x24);
        u8 *e;
        if (h == -1 || (e = D_001A30B0 + h * 128, *(u8 **)(e + 0xDC) != self) || e[0xD0] == 0) {
            *(s32 *)(p + 0x24) = func_003A52A0(1, 4, self);
        }
    }
    if (func_L01_003FB640(self + 0x10, 0, *(f32 *)(p + 0x20), self) != 0) {
        vec_sub_ba(&d, &D_L33_001E9600.pos, self + 0x10);
        d.y = 0.0f;
        m = D_L33_001E9600.moby;
        if (m != 0) {
            if (*(s16 *)(m + 0xAA) == *(s16 *)(D_001A71A0[0] + 0xAA)) {
                explode_003505D8(self, p);
            }
        } else if (D_L33_001DD850 * fabs_asm(d.z) < fabs_asm(d.x)) {
            explode_003505D8(self, p);
        } else {
            func_L02_003BA9F8(p, &d, &v30, &v20);
            *(vu0_q *)p = *(vu0_q *)&v20;
            if (func_0038CEA8(&d) < *(f32 *)(p + 0x20)) {
                func_0038CF68(&v40, &d, func_0038CEA8(&d) - *(f32 *)(p + 0x20));
                vec_add_ab(self + 0x10, self + 0x10, &v40);
            }
        }
    } else {
        vec_add_ab(p, p, &grav);
    }
}
/* localdecomp:end func_L33_003505D8 */
