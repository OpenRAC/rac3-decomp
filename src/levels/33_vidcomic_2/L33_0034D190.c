#include "common.h"

/* localdecomp:start func_L33_0034D190 */
#include "vu0.h"

extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_00369C48(void *);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_00466F50(void *, void *, s32, f32, f32);
typedef struct { u8 pad[0x25C0]; void *f25C0; } S_1A4BE0_0034D190;
extern S_1A4BE0_0034D190 D_001A4BE0;
extern vu0_v4 D_L33_001E9620;
extern u8 D_L33_001E2700[];
extern u8 *D_L33_0021F598[];
extern f32 D_L33_001DD7B8;
__asm__(".extern D_L33_001DD7B8, 4");

void func_L33_0034D190(u8 *p, vu0_v4 *pos, vu0_v4 *vel) {
    vu0_v4 dir __attribute__((aligned(16)));
    vu0_v4 cur __attribute__((aligned(16)));
    vu0_v4 col __attribute__((aligned(16)));
    vu0_v4 end __attribute__((aligned(16)));
    s32 count = 2;
    s32 i;
    s32 j, k;
    u8 *r;
    f32 f;

    *(vu0_q *)&dir = 0;
    cur = *pos;
    dir.z = -5.0f;
    cur.x += *(f32 *)(p + 0xC0) * 2.5f;
    cur.z += 1.5f;
    for (j = 0; j < 10; j++) {
        vec_add_ab(&end, &cur, &dir);
        if (func_003D3CB0(&cur, &end, 2, D_001A4BE0.f25C0, 0) != 0) {
            col = D_L33_001E9620;
            col.y += func_003824E0(-0.5f, 0.5f);
            func_L01_00369C48(&col);
        }
        cur.x -= *(f32 *)(p + 0xC0) * 0.5f;
    }

    for (i = 0; i < count * 4 + 2; i++) {
        func_0038D890(vel, vel, D_L33_001E2700, func_003824E0(-2.0f, 1.0f) * 0.017453292f);
        func_0038D890(vel, vel, D_L33_001E2700 + 0x20, func_003824E0(-3.0f, 3.0f) * 0.017453292f);
        func_0038CF68(vel, vel, func_003824E0(D_L33_001DD7B8 * 0.25f, D_L33_001DD7B8));
        r = func_L01_004713C8(pos, vel, (func_00382498(30, 50) * 5 + 2) / 6, 0x5A182, func_00382498(1, 4), 0x30, 0, 0, 63000.004f, 42000.0f, 0.002f);
        if (r != 0) {
            r[3] = func_00382468(2) ? 0x48 : 0x44;
            r[2] = *D_L33_0021F598[0x1A4 / 4];
        }
    }

    for (i = 0; i < count * 4; i++) {
        func_0038D890(vel, vel, D_L33_001E2700, func_003824E0(-0.5f, 1.0f) * 0.017453292f);
        func_0038D890(vel, vel, D_L33_001E2700 + 0x20, func_003824E0(-1.0f, 1.0f) * 0.017453292f);
        f = D_L33_001DD7B8;
        func_0038CF68(vel, vel, func_003824E0(f * 0.25f, f - 0.1f));
        r = func_L01_004713C8(pos, vel, (func_00382498(30, 50) * 5 + 2) / 6, 0x5A182, func_00382498(-1, -3), 0x20, 0, 0, 84000.0f, 168000.0f, 0.002f);
        if (r != 0) {
            r[3] = func_00382468(2) ? 0x48 : 0x44;
            r[2] = *D_L33_0021F598[0x5C / 4];
        }
    }

    for (i = 0; i < count * 2 + 2; i++) {
        func_0038D890(vel, vel, D_L33_001E2700, func_003824E0(-2.0f, 1.0f) * 0.017453292f);
        func_0038D890(vel, vel, D_L33_001E2700 + 0x20, func_003824E0(-3.0f, 3.0f) * 0.017453292f);
        func_0038CF68(vel, vel, func_003824E0(D_L33_001DD7B8 * 0.25f, D_L33_001DD7B8));
        r = func_L01_004713C8(pos, vel, (func_00382498(30, 50) * 5 + 2) / 6, 0x5A182, -1, 0x30, 0, 0, 63000.004f, 21000.0f, 0.00160000008f);
        if (r != 0) {
            r[3] = func_00382468(2) ? 0x48 : 0x44;
            r[2] = *D_L33_0021F598[0x88 / 4];
        }
        f = D_L33_001DD7B8;
        func_0038CF68(vel, vel, func_003824E0(f * 0.25f, f - 0.1f));
    }

    for (k = 0; k < count * 2 + 2; k++) {
        func_0038D890(vel, vel, D_L33_001E2700, func_003824E0(-2.0f, 1.0f) * 0.017453292f);
        func_0038D890(vel, vel, D_L33_001E2700 + 0x20, func_003824E0(-3.0f, 3.0f) * 0.017453292f);
        func_0038CF68(vel, vel, func_003824E0(D_L33_001DD7B8 * 0.25f, D_L33_001DD7B8 - 0.1f));
        func_L01_00466F50(pos, vel, 0x4005A182, -1.0f, -0.008f);
    }
}
/* localdecomp:end func_L33_0034D190 */

/* localdecomp:start func_L33_0034D838 */
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_0034D838;

typedef struct {
    u8 pad0[0x60];
    f32 f60;
    u8 pad64[4];
    f32 f68;
    u8 pad6C[0x14];
    V_0034D838 v80;
    s32 f90;
    s32 f94;
    s32 f98;
    s32 f9C;
    u8 padA0[4];
    s32 fA4;
    s32 fA8;
    f32 fAC;
    s32 fB0;
    u8 padB4[4];
    f32 fB8;
    f32 fBC;
    u8 padC0[4];
    s32 fC4;
} Vars_0034D838;

typedef struct {
    u8 pad0[0x10];
    s32 f10;
    u8 pad14[0x30];
    u16 f44;
} Ref_0034D838;

typedef struct {
    u8 pad0[0x10];
    V_0034D838 pos;
    u8 state;
    u8 pad21[3];
    Ref_0034D838 *f24;
    u8 pad28[0xC];
    u16 f34;
    u8 pad36[0x12];
    f32 f48;
    u8 pad4C[0x14];
    u8 flags;
    u8 pad61[7];
    Vars_0034D838 *vars;
    u8 pad6C[0x2C];
    s32 f98;
    u8 pad9C[0x24];
    V_0034D838 vC0;
    V_0034D838 vD0;
    u8 padE0[0x18];
    f32 fF8;
} Moby_0034D838;

extern s32 func_L31_00346798(void *, f32, f32, f32);
extern s32 func_L31_00346800(void *, void *, s32, f32);
extern void func_L31_00346470(f32, f32, f32, f32, f32, f32);
extern void func_L31_003464C0(f32, f32, f32, f32, f32, f32, f32);
extern void func_L31_00346B10(void *, void *, f32, f32, f32, f32, f32);
extern s32 func_L30_0034D1E8(void *, void *, void *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern void func_L30_0034C8A8(void *, void *);
extern void func_L30_0034CCD0(void *, f32 *, f32 *, f32 *, f32 *);
extern s32 func_L32_00349630(u8 *, f32 *, f32, f32, f32, f32, f32, f32, f32);
extern void *func_L33_0034FEE8(void *, void *, void *, s32, f32, f32, f32, f32, f32, s32);
void func_L33_0034F9D8(u8 *, f32, f32, s32, s32, s32, f32, f32, f32);
void func_L33_0034EA80(u8 *);
void func_L33_0034EC28(u8 *, s32);
void func_L33_0034E8C0(u8 *);
extern s32 func_L01_004561B8(void *);
extern s32 func_L01_0044E1B8(void *, f32);
extern s32 func_L01_00456250(void *);
extern void func_L01_004AA7E8(void *, s32);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038CF00(void *, void *);
extern s32 func_0038CAD0(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D890(void *, void *, void *, f32);
extern s32 func_00382380(void *, s32, s32);
extern void func_00382580(void *, f32, f32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003A4F28(s32);
extern void func_003C2F58(void *, s32, void *);
extern void func_003C2880(void *);

typedef struct {
    u8 pad0[0x80];
    f32 pos[4];
    u8 pad90[0x10];
} Hero_0034D838;

extern f32 D_001A4C60[];
extern u8 D_001A30B0[];
extern u8 *D_001DFC00;
typedef struct {
    u8 pad0[0x88];
    u8 *p88;
    u8 pad8C[0x1A4 - 0x8C];
    u8 *p1A4;
} Tbl_0034D838;

extern Tbl_0034D838 D_0021F598;
extern u8 D_L33_001D66B0[8];
typedef struct {
    u8 pad0[8];
    f32 f8;
    u8 padC[4];
} H_0034D838;

typedef struct {
    u8 obj[0x10];
    s32 val;
} E_0034D838;

extern H_0034D838 D_L33_001E17A0_0034D838 __attribute__((section(".sdata")));
extern E_0034D838 D_L33_001E17D0_0034D838 __attribute__((section(".sdata")));

extern f32 D_L33_001DD580;
__asm__(".extern D_L33_001DD580, 4");
extern f32 D_L33_001DD584;
__asm__(".extern D_L33_001DD584, 4");
extern f32 D_L33_001DD590;
__asm__(".extern D_L33_001DD590, 4");
extern f32 D_L33_001DD594;
__asm__(".extern D_L33_001DD594, 4");
extern f32 D_L33_001DD5A4;
__asm__(".extern D_L33_001DD5A4, 4");
extern f32 D_L33_001DD5A8;
__asm__(".extern D_L33_001DD5A8, 4");
extern f32 D_L33_001DD5B0;
__asm__(".extern D_L33_001DD5B0, 4");
extern f32 D_L33_001DD5B4;
__asm__(".extern D_L33_001DD5B4, 4");
extern f32 D_L33_001DD5B8;
__asm__(".extern D_L33_001DD5B8, 4");
extern f32 D_L33_001DD5CC;
__asm__(".extern D_L33_001DD5CC, 4");
extern f32 D_L33_001DD5D0;
__asm__(".extern D_L33_001DD5D0, 4");
extern f32 D_L33_001DD5D4;
__asm__(".extern D_L33_001DD5D4, 4");
extern f32 D_L33_001DD5D8;
__asm__(".extern D_L33_001DD5D8, 4");
extern f32 D_L33_001DD5EC;
__asm__(".extern D_L33_001DD5EC, 4");
extern f32 D_L33_001DD5F0;
__asm__(".extern D_L33_001DD5F0, 4");
extern f32 D_L33_001DD5F8;
__asm__(".extern D_L33_001DD5F8, 4");
extern f32 D_L33_001DD5FC;
__asm__(".extern D_L33_001DD5FC, 4");
extern f32 D_L33_001DD600;
__asm__(".extern D_L33_001DD600, 4");
extern f32 D_L33_001DD60C;
__asm__(".extern D_L33_001DD60C, 4");
extern f32 D_L33_001DD614;
__asm__(".extern D_L33_001DD614, 4");
extern f32 D_L33_001DD618;
__asm__(".extern D_L33_001DD618, 4");
extern f32 D_L33_001DD61C;
__asm__(".extern D_L33_001DD61C, 4");
extern f32 D_L33_001DD620;
__asm__(".extern D_L33_001DD620, 4");
extern f32 D_L33_001DD624;
__asm__(".extern D_L33_001DD624, 4");
extern f32 D_L33_001DD630;
__asm__(".extern D_L33_001DD630, 4");
extern s32 D_L33_001DD760;
__asm__(".extern D_L33_001DD760, 4");
extern s32 D_L33_001DD764;
__asm__(".extern D_L33_001DD764, 4");
extern f32 D_L33_001DD768;
__asm__(".extern D_L33_001DD768, 4");
extern f32 D_L33_001DD76C;
__asm__(".extern D_L33_001DD76C, 4");
extern f32 D_L33_001DD770;
__asm__(".extern D_L33_001DD770, 4");
extern f32 D_L33_001DD77C;
__asm__(".extern D_L33_001DD77C, 4");
extern f32 D_L33_001DD780;
__asm__(".extern D_L33_001DD780, 4");
extern s32 D_L33_001DD784;
__asm__(".extern D_L33_001DD784, 4");
extern f32 D_L33_001DD788;
__asm__(".extern D_L33_001DD788, 4");
extern f32 D_L33_001DD78C;
__asm__(".extern D_L33_001DD78C, 4");
extern f32 D_L33_001DD790;
__asm__(".extern D_L33_001DD790, 4");
extern f32 D_L33_001DD794;
__asm__(".extern D_L33_001DD794, 4");
extern f32 D_L33_001DD798;
__asm__(".extern D_L33_001DD798, 4");
extern f32 D_L33_001DD79C;
__asm__(".extern D_L33_001DD79C, 4");
extern s32 D_L33_001DD7A0;
__asm__(".extern D_L33_001DD7A0, 4");
extern s32 D_L33_001DD7A4;
__asm__(".extern D_L33_001DD7A4, 4");
extern f32 D_L33_001DD7A8;
__asm__(".extern D_L33_001DD7A8, 4");
extern f32 D_L33_001DD7AC;
__asm__(".extern D_L33_001DD7AC, 4");
extern f32 D_L33_001DD7B0;
__asm__(".extern D_L33_001DD7B0, 4");
extern f32 D_L33_001DD7B4;
__asm__(".extern D_L33_001DD7B4, 4");
extern f32 D_L33_001DD7B8;
__asm__(".extern D_L33_001DD7B8, 4");
extern f32 D_L33_001DD7BC;
__asm__(".extern D_L33_001DD7BC, 4");
extern f32 D_L33_001DD7C0;
__asm__(".extern D_L33_001DD7C0, 4");

void func_L33_0034D838(Moby_0034D838 *p) {
    Vars_0034D838 *s = p->vars;
    f32 rateB = D_L33_001DD76C * s->fAC / D_L33_001DD770;
    f32 rateA = D_L33_001DD618 * fabs_asm(s->f60) / D_L33_001DD620;
    s32 facing = func_L31_00346798(p, D_L33_001DD580, D_L33_001DD584, D_L33_001DD5CC) != 0;
    s32 left;
    s32 inZ;
    s32 inX;
    s32 seen;
    s32 ground;
    u8 *e;
    u8 *r;
    s32 v;
    s32 w;
    s32 i;
    u8 *o;
    f32 side;
    f32 spd;
    f32 a;
    f32 b;
    V_0034D838 v10;
    V_0034D838 v20;
    V_0034D838 v30;
    V_0034D838 v40;
    V_0034D838 v50;
    f32 x;
    f32 x2;
    f32 e2;
    f32 r2;
    f32 m2;
    f32 z;
    f32 lo;
    f32 hi;

    a = fabs_asm(func_0038DB00(D_L33_001DD580, p->fF8));
    left = 1;
    if (!(a < fabs_asm(func_0038DB00(D_L33_001DD584, p->fF8)))) {
        left = 0;
    }
    inZ = 0;
    if (((Hero_0034D838 *)&D_001A4BE0)->pos[2] < s->fBC + p->pos.z) {
        if (p->pos.z - s->fBC < ((Hero_0034D838 *)&D_001A4BE0)->pos[2]) {
            inZ = 1;
        }
    }
    inX = fabs_asm(((Hero_0034D838 *)&D_001A4BE0)->pos[0] - p->pos.x) < s->fB8;
    seen = 0;
    if (s->f90 == -1 || func_00382380(((Hero_0034D838 *)&D_001A4BE0)->pos, s->f90, 0) != 0) {
        seen = 1;
    }
    ground = func_L31_00346800(p, &p->pos, 0, D_L33_001DD61C) != 0;

    switch (p->state) {
    case 1:
        D_L33_001E17A0_0034D838.f8 = 0.0f < s->f68 ? D_L33_001DD5B8 : D_L33_001DD5B4;
        if (func_L01_004561B8(p)) {
            *(vu0_q *)&s->v80 = *(vu0_q *)&p->vC0;
            s->v80.w = p->pos.z + 2.4f;
            func_L30_0034D1E8(p, &p->pos, &s->f60, &D_L33_001E17A0_0034D838, D_L33_001DD61C, D_L33_001DD61C,
                              D_L33_001DD5D0, 0.0f, 0.0f, D_L33_001DD5B0, 1, 1, 1, 1);
        }
        v10 = p->pos;
        z = v10.z;
        if (z < s->v80.w) {
            z = s->v80.w - 0.08f;
        }
        v10.z = z;
        func_0038CE20(&v20, &p->vD0, -1.0f);
        func_0038D890(&s->v80, &s->v80, &v20, D_L33_001DD7BC);
        func_0038CE20(&v30, &s->v80, D_L33_001DD7B8 * 0.020000001f);
        func_L33_0034D190((u8 *)p, (vu0_v4 *)&v10, (vu0_v4 *)&v30);
        s->v80.w = v10.z;
        func_L30_0034D1E8(p, &p->pos, &s->f60, &D_L33_001E17A0_0034D838, D_L33_001DD61C, D_L33_001DD61C,
                          D_L33_001DD5D0, 0.0f, 0.0f, D_L33_001DD5B0, 1, 1, 1, 1);
        func_L32_00349630((u8 *)p, &p->pos.x, D_L33_001DD61C, s->f68, D_L33_001DD5B8, D_L33_001DD5A8,
                          D_L33_001DD5A4, D_L33_001DD5B4, -1.0f);
        if (!(p->flags & 2)) {
            break;
        }
        for (i = 0; i < 30; i++) {
            func_00382580(&v50, D_L33_001DD7C0 * 0.5f * 0.020000001f, D_L33_001DD7C0 * 0.020000001f);
            v50.y = -fabs_asm(v50.y);
            v50.z += D_L33_001DD7C0 * 0.4f * 0.020000001f;
            func_00382580(&v40, 0.0f, 0.016f);
            vec_add_ab(&v40, &v40, &p->pos);
            o = func_L01_00475C60(&v40, &v50, 0x19, func_00382498(-3, 3), 0x7F05A182, 0x1005A182, 0,
                                  252000.02f, 42000.0f, 20.0f);
            if (o != 0) {
                o[3] = func_00382468(2) ? 0x48 : 0x44;
                o[2] = func_00382468(2) ? *D_0021F598.p1A4 : *D_0021F598.p88;
            }
        }
        func_L01_00451FE0(p, 0xFF, D_L33_001D66B0, 2.5f, 5.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23,
                          1.0f, 1.0f, 0, 3);
        func_003A52A0(9, 0, p);
        func_003C2880(p);
        return;
    case 2:
        func_L30_0034D1E8(p, &p->pos, &s->f60, &D_L33_001E17A0_0034D838, D_L33_001DD61C, D_L33_001DD61C,
                          D_L33_001DD5D0, ground ? 0.0f : D_L33_001DD620, 0.0f, D_L33_001DD624, 1, 1, 1, 0);
        if (!ground) {
            break;
        }
        if (facing && inX && inZ) {
            func_L33_0034EC28((u8 *)p, 3);
        } else if (seen && inZ) {
            func_L33_0034EC28((u8 *)p, 9);
        } else {
            func_L33_0034EC28((u8 *)p, 7);
        }
        break;
    case 3:
        if (func_L01_004561B8(p)) {
            if (s->fB0 > 0) {
                s->fA8 = s->fB0;
            } else {
                s->fA8 = D_L33_001DD760;
            }
            func_003A52A0(8, 0, p);
        }
        func_L30_0034C8A8(D_L33_001E17D0_0034D838.obj, p);
        if (!ground) {
            func_L33_0034EC28((u8 *)p, 2);
        }
        if (func_0038CAD0(&s->fA8)) {
            func_L33_0034EC28((u8 *)p, 5);
        }
        break;
    case 4:
        if (!ground) {
            func_L33_0034EC28((u8 *)p, 2);
        }
        if (facing && inX && inZ) {
            func_L33_0034EC28((u8 *)p, 3);
        } else if (p->flags & 2) {
            if (seen && inZ) {
                func_L33_0034EC28((u8 *)p, 9);
            } else {
                func_L33_0034EC28((u8 *)p, 7);
            }
        }
        break;
    case 5:
        if (func_L01_004561B8(p)) {
            s->fA8 = -1;
            s->fA4 = 1;
            s->fAC = 0.0f;
        }
        if (func_L01_0044E1B8(p, D_L33_001DD5D4)) {
            p->f48 = 0.0f;
            s->fA8 = D_L33_001DD764;
        }
        if (s->fA8 >= 0) {
            if (func_0038CAD0(&s->fA8)) {
                p->f48 = 1.0f;
                v = s->fC4;
                if (v != -1 && (e = D_001A30B0 + v * 128, *(u8 **)(e + 0xDC) == (u8 *)p) && e[0xD0] != 0) {
                    func_003A4F28(v);
                }
                s->fC4 = -1;
            } else if (s->fA8 % D_L33_001DD784 == 0) {
                w = s->fC4;
                if (w == -1 || (e = D_001A30B0 + w * 128, *(u8 **)(e + 0xDC) != (u8 *)p) || e[0xD0] == 0) {
                    s->fC4 = func_003A52A0(0, 4, p);
                }
                func_003C2F58(p, 1, &v10);
                if (fabs_asm(func_0038DB00(D_L33_001DD580, p->fF8)) <
                    fabs_asm(func_0038DB00(D_L33_001DD584, p->fF8))) {
                    a = 3.1415927f;
                    v20.x = func_0038D098(a) * D_L33_001DD7B4;
                    v20.z = func_0038D0B0(a) * D_L33_001DD7B4;
                    v20.y = 0.0f;
                } else {
                    a = 0.0f;
                    v20.x = func_0038D098(a) * D_L33_001DD7B4;
                    v20.z = func_0038D0B0(a) * D_L33_001DD7B4;
                    v20.y = 0.0f;
                }
                a = func_003C4088(D_L33_001DD780, D_L33_001DD77C, (f32)s->fA8 / (f32)D_L33_001DD764);
                b = func_003C4088(D_L33_001DD790, D_L33_001DD794, (f32)s->fA8 / (f32)D_L33_001DD764);
                r = func_L33_0034FEE8(&v10, &v20, p, 0, a, 0.0f, D_L33_001DD788, b, D_L33_001DD78C, s->fA4);
                s->fA4 = 0;
                if (r != 0) {
                    func_L33_0034F9D8(r, D_L33_001DD798, D_L33_001DD79C, D_L33_001DD7A0, D_L33_001DD7A4, 0x174B,
                                      D_L33_001DD7A8, D_L33_001DD7AC, D_L33_001DD7B0);
                }
            }
        }
        ((void (*)(void *, void *, f32, f32, f32, f32, f32, f32))func_L31_00346470)(
            p, &s->fAC, D_L33_001DD580, D_L33_001DD584, D_L33_001DD770, D_L33_001DD768, D_L33_001DD768, D_L33_001DD5CC);
        if (!ground) {
            func_L33_0034EC28((u8 *)p, 2);
        }
        if (!(p->flags & 2)) {
            break;
        }
        if (facing && inX && inZ) {
            func_L33_0034EC28((u8 *)p, 3);
        } else if (seen && !facing && inZ) {
            func_L33_0034EC28((u8 *)p, 9);
        } else {
            func_L33_0034EC28((u8 *)p, 4);
        }
        break;
    case 6:
        D_L33_001E17A0_0034D838.f8 = 0.0f < s->f68 ? D_L33_001DD600 : D_L33_001DD5FC;
        if (func_L01_004561B8(p)) {
            func_L30_0034D1E8(p, &p->pos, &s->f60, &D_L33_001E17A0_0034D838, D_L33_001DD61C, D_L33_001DD61C,
                              D_L33_001DD5D0, 0.0f, 0.0f, D_L33_001DD5F8, 1, 1, 1, 1);
        }
        func_L30_0034D1E8(p, &p->pos, &s->f60, &D_L33_001E17A0_0034D838, D_L33_001DD61C, D_L33_001DD61C,
                          D_L33_001DD5D0, 0.0f, 0.0f, D_L33_001DD5F8, 1, 1, 1, 1);
        func_L32_00349630((u8 *)p, &p->pos.x, D_L33_001DD61C, s->f68, D_L33_001DD600, D_L33_001DD5F0,
                          D_L33_001DD5EC, D_L33_001DD5FC, -1.0f);
        if (!(p->flags & 2)) {
            break;
        }
        D_L33_001E17A0_0034D838.f8 = D_L33_001DD5D8;
        if (ground) {
            if (facing && inX && inZ) {
                func_L33_0034EC28((u8 *)p, 3);
            } else if (seen && inZ) {
                func_L33_0034EC28((u8 *)p, 9);
            } else {
                func_L33_0034EC28((u8 *)p, 7);
            }
        } else {
            func_L33_0034EC28((u8 *)p, 2);
        }
        break;
    case 7:
        if (!ground) {
            func_L33_0034EC28((u8 *)p, 2);
        } else if (facing && inX && inZ) {
            func_L33_0034EC28((u8 *)p, 3);
        } else if (seen && inZ) {
            func_L33_0034EC28((u8 *)p, 9);
        } else if (p->flags & 2) {
            func_L33_0034EC28((u8 *)p, 8);
        }
        break;
    case 8:
        side = s->v80.x < p->pos.x ? D_L33_001DD580 : D_L33_001DD584;
        if (func_L01_004561B8(p)) {
            s->fAC = 0.0f;
            *(vu0_q *)&s->v80 = *(vu0_q *)&p->pos;
            w = s->f94;
            if (w == -1) {
                x = s->v80.x;
                if (left) {
                    s->v80.x = x + D_L33_001DD60C;
                } else {
                    s->v80.x = x - D_L33_001DD60C;
                }
            } else {
                func_L30_0034CCD0(D_001DFC00 + w * 128, &lo, &hi, 0, 0);
                x2 = s->v80.x;
                if (left) {
                    e2 = hi;
                    s->v80.x = x2 + func_003C4088(p->pos.x, e2, func_003824E0(0.4f, 0.8f));
                } else {
                    e2 = lo;
                    s->v80.x = x2 + func_003C4088(e2, p->pos.x, func_003824E0(0.4f, 0.8f));
                }
            }
        }
        if (!((s32 (*)(void *, void *, f32, f32, f32, f32, f32, f32, f32))func_L31_003464C0)(
                p, &s->fAC, s->v80.x, D_L33_001DD580, D_L33_001DD584, D_L33_001DD770, D_L33_001DD768,
                D_L33_001DD768, D_L33_001DD5CC)) {
            f32 c = func_0038D098(func_0038DB48(func_0038DB00(
                s->v80.x < p->pos.x ? D_L33_001DD580 : D_L33_001DD584, p->fF8)));
            if (c < 0.0f) {
                c = 0.0f;
            }
            spd = D_L33_001DD620 * fabs_asm(c);
        } else {
            spd = D_L33_001DD620;
        }
        func_L31_00346B10(p, &s->f60, s->v80.x, 0.0f, spd, D_L33_001DD614, D_L33_001DD614);
        func_L30_0034D1E8(p, &p->pos, &s->f60, &D_L33_001E17A0_0034D838, D_L33_001DD61C, D_L33_001DD61C,
                          D_L33_001DD5D0, spd, 0.0f, D_L33_001DD624, 1, 1, 1, 0);
        r2 = fabs_asm(func_0038DB00(p->fF8, side));
        m2 = func_003C4088(rateA, rateB, r2 / fabs_asm(func_0038DB00(D_L33_001DD580, D_L33_001DD584)));
        p->f48 = m2;
        if (m2 < D_L33_001DD590) {
            p->f48 = D_L33_001DD590;
        }
        if (!ground) {
            func_L33_0034EC28((u8 *)p, 2);
        } else if (facing && inX && inZ) {
            func_L33_0034EC28((u8 *)p, 3);
        } else if (seen && inZ) {
            func_L33_0034EC28((u8 *)p, 9);
        } else if (func_0038CF00(&s->v80, &p->pos) < D_L33_001DD594) {
            func_L33_0034EC28((u8 *)p, 7);
        }
        break;
    case 0:
        func_L33_0034EA80((u8 *)p);
        func_L33_0034EC28((u8 *)p, 10);
        break;
    case 9:
        side = ((Hero_0034D838 *)&D_001A4BE0)->pos[0] < p->pos.x ? D_L33_001DD580 : D_L33_001DD584;
        if (func_L01_004561B8(p)) {
            s->fAC = 0.0f;
        }
        if (!((s32 (*)(void *, void *, f32, f32, f32, f32, f32, f32))func_L31_00346470)(
                p, &s->fAC, D_L33_001DD580, D_L33_001DD584, D_L33_001DD770, D_L33_001DD768, D_L33_001DD768,
                D_L33_001DD5CC)) {
            f32 c = func_0038D098(func_0038DB48(func_0038DB00(
                ((Hero_0034D838 *)&D_001A4BE0)->pos[0] < p->pos.x ? D_L33_001DD580 : D_L33_001DD584,
                p->fF8)));
            if (c < 0.0f) {
                c = 0.0f;
            }
            spd = D_L33_001DD620 * fabs_asm(c);
        } else {
            spd = D_L33_001DD620;
        }
        func_L31_00346B10(p, &s->f60, ((Hero_0034D838 *)&D_001A4BE0)->pos[0], 0.0f, spd, D_L33_001DD614, D_L33_001DD614);
        func_L30_0034D1E8(p, &p->pos, &s->f60, &D_L33_001E17A0_0034D838, D_L33_001DD61C, D_L33_001DD61C,
                          D_L33_001DD5D0, spd, 0.0f, D_L33_001DD624, 1, 1, 1, 0);
        r2 = fabs_asm(func_0038DB00(p->fF8, side));
        m2 = func_003C4088(rateA, rateB, r2 / fabs_asm(func_0038DB00(D_L33_001DD580, D_L33_001DD584)));
        p->f48 = m2;
        if (m2 < D_L33_001DD590) {
            p->f48 = D_L33_001DD590;
        }
        if (!ground) {
            func_L33_0034EC28((u8 *)p, 2);
        } else if (facing && inX && inZ) {
            func_L33_0034EC28((u8 *)p, 3);
        } else if (!seen || (inX && !inZ)) {
            func_L33_0034EC28((u8 *)p, 7);
        }
        break;
    case 10:
        if (func_L01_004561B8(p) && s->f9C != 0) {
            p->f98 = 0;
            p->f34 = (p->f34 | 0x41) & ~0x1000;
            func_L01_004AA7E8(p, 1);
        }
        if (s->f9C == 0) {
            func_L30_0034D1E8(p, &p->pos, &s->f60, &D_L33_001E17A0_0034D838, D_L33_001DD61C, D_L33_001DD61C, 1.0f,
                              0.0f, D_L33_001DD630, 0.0f, 1, 1, 0, 0);
        }
        if ((s->f98 == -1 && func_00382380(D_001A4C60, s->f90, 0)) ||
            func_00382380(D_001A4C60, s->f98, 0)) {
            if (s->f9C != 0) {
                if (!func_L01_00456250(p)) {
                    break;
                }
                if (s->f9C != 0) {
                    Ref_0034D838 *q;
                    p->f34 &= 0xFFBE;
                    q = p->f24;
                    p->f34 |= q->f44 & 0x1000;
                    p->f98 = q->f10;
                }
            }
            func_L33_0034EC28((u8 *)p, 7);
        }
        break;
    }
    func_L33_0034E8C0((u8 *)p);
}
/* localdecomp:end func_L33_0034D838 */
