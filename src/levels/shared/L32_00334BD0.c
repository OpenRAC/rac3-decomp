#include "common.h"

/* localdecomp:start func_L32_00334BD0 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x30];
    u8 b30[0x3C];
    s32 f6C;
    vu0_v4 home;
    u8 pad80[0x10];
    s32 f90;
    s32 f94;
    s32 snd;
    f32 f9C;
    s32 fA0;
    f32 fA4;
    f32 fA8;
    s32 fAC;
    u8 bB0[4];
    s32 fB4;
} V_00334BD0;
typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 state;
    u8 pad21[0x47];
    V_00334BD0 *v;
    u8 pad6C[0x44];
    u8 fB0;
    u8 padB1;
    u16 fB2;
    u8 padB4[0x3C];
    vu0_v4 rot;
} M_00334BD0;
extern s32 D_001D545C;
extern u8 D_001BBE90[];
extern u8 D_001BBC40[];
extern u8 D_001A30B0[];
extern u8 D_001A4BE0[];
typedef struct { u8 pad0[0x464]; u8 f464[1]; } T_00334BD0;
extern T_00334BD0 D_L32_00236080;
extern s32 func_L05_00328FF8(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_004AA710(void *, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern f32 func_0038CF00(void *, void *);
extern void func_003C41A0(f32 *, void *, f32, f32, f32, f32);
extern void func_003A4F28(s32);
extern s32 func_L01_004561B8(void *);
extern s32 func_00382380(void *, s32, s32);
extern void func_003C4DA8(void *, void *, void *, void *);

static __inline__ f32 heroZ_00334BD0(void) {
    u8 *hero = D_001A4BE0;
    return *(f32 *)(hero + 0x88);
}

void func_L32_00334BD0(M_00334BD0 *self) {
    V_00334BD0 *v = self->v;
    vu0_v4 *pp;
    vu0_v4 pos, rot, t;
    s32 s;
    u8 *p;

    pp = &self->pos;
    pos = *pp;
    rot = self->rot;
    switch (self->state) {
    case 0:
        v->fAC = 0;
        v->f6C |= 1;
        v->home = self->pos;
        self->state = 1;
        if (v->fA0 == 0) {
            v->fA4 = v->home.z;
            v->fA8 = v->f9C;
            v->f90 = 0;
        } else {
            v->f90 = 1;
            v->fA4 = v->f9C;
            v->fA8 = v->home.z;
        }
        v->f94 = 0;
        v->snd = -1;
        break;
    case 1: {
        s32 b;
        if (func_L05_00328FF8(self)) {
            v->fAC = 1;
            if (self->fB2 & 1) {
                p = &D_001BBE90[((s16)self->fB2 >> 1) + D_001D545C * 1024];
                if (((*p >> 4) & 7) != 7) *p += 0x10;
            } else {
                p = &D_001BBE90[((s16)self->fB2 >> 1) + D_001D545C * 1024];
                if ((*p & 7) != 7) *p += 1;
            }
            if (v->f90 == 0) {
                func_L01_004450F0(self, 3, -1);
                if (!func_L01_004AA710(self, v->snd)) {
                    v->snd = func_003A52A0(0, 4, self);
                }
            } else {
                func_L01_004450F0(self, 2, -1);
                if (!func_L01_004AA710(self, v->snd)) {
                    v->snd = func_003A52A0(0, 4, self);
                }
            }
        }
        if (fabs_asm(self->pos.z - heroZ_00334BD0()) > 3.0f && v->f90 == 0 && heroZ_00334BD0() < self->pos.z && (v->fAC == 1 || (D_001BBC40[self->fB0 + D_001D545C * 16] & 0x80)
                || D_L32_00236080.f464[(s16)self->fB2] != 0 || (b = D_001BBE90[((s16)self->fB2 >> 1) + D_001D545C * 1024], (self->fB2 & 1) ? ((b >> 4) & 7) : (b & 7)))) {
            if (!func_L01_004AA710(self, v->snd)) {
                v->snd = func_003A52A0(0, 4, self);
            }
            func_L01_004450F0(self, 3, -1);
        } else if (fabs_asm(self->pos.z - heroZ_00334BD0()) > 3.0f && v->f90 == 1 && self->pos.z < heroZ_00334BD0() && (v->fAC == 1 || (D_001BBC40[self->fB0 + D_001D545C * 16] & 0x80)
                || D_L32_00236080.f464[(s16)self->fB2] != 0 || (b = D_001BBE90[((s16)self->fB2 >> 1) + D_001D545C * 1024], (self->fB2 & 1) ? ((b >> 4) & 7) : (b & 7)))) {
            if (!func_L01_004AA710(self, v->snd)) {
                v->snd = func_003A52A0(0, 4, self);
            }
            func_L01_004450F0(self, 2, -1);
        }
        break;
    }
    case 2:
        t = pos;
        t.z = v->fA4;
        if (func_0038CF00(pp, &t) > 0.04f) {
            func_003C41A0(&self->pos.z, v->bB0, t.z, 0.00280000013f, 0.0024f, 0.120000005f);
            v->f94++;
        } else if (!func_L05_00328FF8(self)) {
            v->f90 = 0;
            s = v->snd;
            if (s != -1) {
                p = D_001A30B0 + (s << 7);
                if (*(void **)(p + 0xDC) == self && p[0xD0] != 0) func_003A4F28(s);
            }
            v->snd = -1;
            func_L01_004450F0(self, 1, -1);
            self->pos = t;
            v->f94 = 0;
        } else {
            s = v->snd;
            if (s != -1) {
                p = D_001A30B0 + (s << 7);
                if (*(void **)(p + 0xDC) == self && p[0xD0] != 0) func_003A4F28(s);
            }
            v->snd = -1;
        }
        break;
    case 3:
        func_L01_004561B8(self);
        if (v->fA8 < self->pos.z) {
            u8 *hero = D_001A4BE0;
            f32 hz = *(f32 *)(hero + 0x88);
            if (self->pos.z - hz < 2.8f && hz < self->pos.z) {
                if (func_00382380(hero + 0x80, v->fB4, 0) == 0) {
                    func_003C41A0(&self->pos.z, v->bB0, v->fA8, 0.00280000013f, 0.0024f, 0.120000005f);
                    v->f94++;
                }
            } else {
                func_003C41A0(&self->pos.z, v->bB0, v->fA8, 0.00280000013f, 0.0024f, 0.120000005f);
                v->f94++;
            }
        } else if (!func_L05_00328FF8(self) && self->pos.z <= v->fA8) {
            s = v->snd;
            v->f90 = 1;
            if (s != -1) {
                p = D_001A30B0 + (s << 7);
                if (*(void **)(p + 0xDC) == self && p[0xD0] != 0) func_003A4F28(s);
            }
            v->snd = -1;
            func_L01_004450F0(self, 1, -1);
            v->f94 = 0;
        } else {
            s = v->snd;
            if (s != -1) {
                p = D_001A30B0 + (s << 7);
                if (*(void **)(p + 0xDC) == self && p[0xD0] != 0) func_003A4F28(s);
            }
            v->snd = -1;
        }
        break;
    }
    vec_sub_ba(&t, &self->pos, &pos);
    func_003C4DA8(v->b30, &t, &rot, &self->rot);
}
/* localdecomp:end func_L32_00334BD0 */
