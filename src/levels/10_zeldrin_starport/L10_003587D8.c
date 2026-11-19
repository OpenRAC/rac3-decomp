#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L10_003587D8 */
typedef struct { u8 p0[0x30]; u8 path[0x3C]; s32 f6C; vu0_v4 home; vu0_v4 homerot; s32 pathid; f32 speed; f32 t; s16 pathnum; u8 startback; u8 oneshot; s8 animA; s8 animB; s8 animC; s8 animD; u8 fired; u8 alert; u8 snd; u8 sndloop; s32 sndh; } S_003587D8;
typedef struct { u8 p0[0x35C]; u8 *f35C; s32 f360; u8 p364[0xA]; s16 h36E; } H_003587D8;
extern H_003587D8 D_001A4BE0;
extern u8 D_001A30B0[];
extern s32 func_L01_0044C108(void *);
extern void func_003C3938(void *, s32, s32);
extern void func_L01_004450F0(s32, s32, s32);
extern void func_L05_00451150(void *,s32);
typedef struct { u8 pad0[0x30]; vu0_v4 pos; u8 pad40[0x30]; vu0_v4 rot; } Path53;
extern Path53 *D_L10_001DF380;
extern Path53 *D_L10_001DF380_003587D8;
__asm__(".extern D_L10_001DF380, 4");
extern f32 func_0038D098(f32);
extern void func_L05_004512F8(void *,void *,void *,s32,f32);
extern s32 func_L05_00360A10(u8 *);

extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_L01_00456250(void *);
extern s32 func_L01_004561B8(void *);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003A4F28(s32);
extern void func_003C4DA8(void *, void *, void *, void *);

void func_L10_003587D8(u8 *self) {
    S_003587D8 *d = *(S_003587D8 **)(self + 0x68);
    vu0_v4 pos, rot, dp;
    s32 ok, back;

    pos = *(vu0_v4 *)(self + 0x10);
    rot = *(vu0_v4 *)(self + 0xF0);
    if (func_L01_0044C108(self + 0x10) == 0) return;
    if (D_001A4BE0.f35C == self && D_001A4BE0.f360 >= 2 && D_001A4BE0.h36E <= 0) {
        d->alert++;
    } else if (D_001A4BE0.f35C != self && d->alert != 0) {
        d->alert--;
    }
    if (d->alert >= 9) d->alert = 8;
    switch (self[0x20]) {
    case 0:
        if (d->pathid==-1 && d->animA==-1) {
            *(u16 *)(self+0x34)|=2;
            func_L01_004450F0((s32)self,6,-1);
            return;
        }
        d->f6C |= 1;
        d->home = *(vu0_v4 *)(self + 0x10);
        d->homerot = *(vu0_v4 *)(self + 0xF0);
        func_L05_00451150(self,d->pathnum);
        d->fired = 0;
        if (d->startback) {
            if (d->pathid!=-1) {
                *(vu0_q *)(self+0x10)=*(vu0_q *)&D_L10_001DF380[d->pathid].pos;
                *(vu0_q *)(self+0xF0)=*(vu0_q *)&D_L10_001DF380_003587D8[d->pathid].rot;
            }
            d->t=1.0f;
            if (d->animC!=-1) func_003C3938(self,d->animC,0);
            func_L01_004450F0((s32)self,3,-1);
        } else {
        if (d->animA != -1) func_003C3938(self, d->animA, 0);
        d->t = 0.0f;
        func_L01_004450F0((s32)self, 1, -1);
        }
        break;
    case 1:
        ok = 1;
        if (self[0x60] & 2) {
            if (d->animA != -1) {
                if (self[0x43] != d->animA) func_003C3A10(self, d->animA, 0, 5);
                else *(s32 *)(self + 0x48) = 0;
            } else {
                *(s32 *)(self + 0x48) = 0;
            }
        }
        if (d->animA != -1 && self[0x42] != d->animA) ok = 0;
        back = func_L05_00360A10(self) == 0;
        if (ok && d->fired == 0) {
            if (func_L01_00456250(self) != 0 || back || d->alert >= 8) {
                d->fired = 1;
                if (d->animB != -1 && self[0x43] != d->animB) func_003C3A10(self, d->animB, 0, 5);
                func_L01_004450F0((s32)self, 2, -1);
                break;
            }
        }
        if (func_L01_00456250(self) == 0 && d->alert == 0) d->fired = 0;
        break;
    case 2:
        if (func_L01_004561B8(self) != 0) {
            if (d->sndloop) d->sndh = func_003A52A0(d->snd, 4, self);
            else func_003A52A0(d->snd, 0, self);
        }
        d->t += 1.0f / ((d->speed * 5.0f + 2.0f) / 6.0f);
        if (d->t>1.0f) d->t=1.0f;
        func_L05_004512F8(self,&d->home,&d->homerot,d->pathid,(1.0f-func_0038D098(d->t*3.1415927f))*0.5f);
        if (self[0x60] & 2) {
            if (d->animC != -1) {
                if (self[0x43] != d->animC) func_003C3A10(self, d->animC, 0, 5);
                else *(s32 *)(self + 0x48) = 0;
            } else {
                *(s32 *)(self + 0x48) = 0;
            }
        }
        if (1.0f <= d->t) {
            if (d->sndloop) {
                if (d->sndh != -1) {
                    u8 *e = &D_001A30B0[d->sndh << 7];
                    if (*(u8 **)(e + 0xDC) == self && e[0xD0] != 0) func_003A4F28(d->sndh);
                }
                d->sndh = -1;
            }
            d->t = 1.0f;
            if (d->oneshot) func_L01_004450F0((s32)self,5,-1);
            else func_L01_004450F0((s32)self, 3, -1);
        }
        break;
    case 3:
        ok = 1;
        if (self[0x60] & 2) {
            if (d->animC != -1) {
                if (self[0x43] != d->animC) func_003C3A10(self, d->animC, 0, 5);
                else *(s32 *)(self + 0x48) = 0;
            } else {
                *(s32 *)(self + 0x48) = 0;
            }
        }
        if (d->animC != -1 && self[0x42] != d->animC) ok = 0;
        back = func_L05_00360A10(self) == 1;
        if (ok && d->fired == 0) {
            if (func_L01_00456250(self) != 0 || back || d->alert >= 8) {
                d->fired = 1;
                if (d->animD != -1 && self[0x43] != d->animD) func_003C3A10(self, d->animD, 0, 5);
                func_L01_004450F0((s32)self, 4, -1);
                break;
            }
        }
        if (func_L01_00456250(self) == 0 && d->alert == 0) d->fired = 0;
        break;
    case 4:
        if (func_L01_004561B8(self) != 0) {
            if (d->sndloop) d->sndh = func_003A52A0(d->snd, 4, self);
            else func_003A52A0(d->snd, 0, self);
        }
        d->t -= 1.0f / ((d->speed * 5.0f + 2.0f) / 6.0f);
        if (d->t<0.0f) d->t=0.0f;
        func_L05_004512F8(self,&d->home,&d->homerot,d->pathid,(1.0f-func_0038D098(d->t*3.1415927f))*0.5f);
        if (self[0x60] & 2) {
            if (d->animA != -1) {
                if (self[0x43] != d->animA) func_003C3A10(self, d->animA, 0, 5);
                else *(s32 *)(self + 0x48) = 0;
            } else {
                *(s32 *)(self + 0x48) = 0;
            }
        }
        if (d->t <= 0.0f) {
            if (d->sndloop) {
                if (d->sndh != -1) {
                    u8 *e = &D_001A30B0[d->sndh << 7];
                    if (*(u8 **)(e + 0xDC) == self && e[0xD0] != 0) func_003A4F28(d->sndh);
                }
                d->sndh = -1;
            }
            d->t = 0.0f;
            if (d->oneshot) func_L01_004450F0((s32)self,5,-1);
            else func_L01_004450F0((s32)self, 1, -1);
        }
        break;
    case 5:
        *(u16 *)(self + 0x34) |= 2;
        break;
    }
    if (self[0x20] < 5) {
        vec_sub_ba(&dp, self + 0x10, &pos);
        func_003C4DA8(d->path, &dp, &rot, self + 0xF0);
    }
}
/* localdecomp:end func_L10_003587D8 */

/* localdecomp:start func_L10_00358F48 */
typedef struct {
    s32 mode;
    f32 height;
    s32 trigger;
    s32 trigger2;
    s32 pad10;
    s32 sound;
} S_358F48;
extern u8 D_001A4C60[];
extern u8 D_001A30B0[];
extern void func_L10_003591B0(void *);
extern int func_L10_003591F8(char *);
extern s32 func_00382380(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003A4F28(s32);

void func_L10_00358F48(u8 *m) {
    S_358F48 *v = *(S_358F48 **)(m + 0x68);
    u8 *e;
    s32 h;
    f32 f;

    func_L10_003591B0(m);
    switch (m[0x20]) {
    case 1:
        if (v->trigger != -1 && func_00382380(D_001A4C60, v->trigger, 0) != 0) {
            m[0x20] = 2;
            v->sound = func_003A52A0(0, 4, m);
        }
        break;
    case 2:
        *(f32 *)(m + 0x18) += 0.036000002f;
        if (v->height <= *(f32 *)(m + 0x18)) {
            h = v->sound;
            if (h != -1) {
                e = D_001A30B0 + (h << 7);
                if (*(u8 **)(e + 0xDC) == m && e[0xD0] != 0) {
                    func_003A4F28(h);
                }
            }
            v->sound = -1;
            *(f32 *)(m + 0x18) = v->height;
            if (v->mode == 1 && func_L10_003591F8((char *)m) == 0) {
                m[0x20] = 3;
            } else {
                m[0x20] = 6;
            }
        }
        break;
    case 3:
        if (v->trigger2 != -1 && func_00382380(D_001A4C60, v->trigger2, 0) != 0) {
            m[0x20] = 4;
            v->sound = func_003A52A0(0, 4, m);
        }
        break;
    case 4:
        if (func_00382380(D_001A4C60, v->trigger, 0) != 0) {
            m[0x20] = 2;
            break;
        }
        *(f32 *)(m + 0x18) -= 0.036000002f;
        if (*(f32 *)(m + 0x18) <= v->height - 5.0f) {
            h = v->sound;
            if (h != -1) {
                e = D_001A30B0 + (h << 7);
                if (*(u8 **)(e + 0xDC) == m && e[0xD0] != 0) {
                    func_003A4F28(h);
                }
            }
            f = v->height - 5.0f;
            v->sound = -1;
            m[0x20] = 5;
            *(f32 *)(m + 0x18) = f;
        }
        break;
    case 5:
        if (func_L10_003591F8((char *)m) != 0 || func_00382380(D_001A4C60, v->trigger, 0) != 0) {
            m[0x20] = 2;
            v->sound = func_003A52A0(0, 4, m);
        }
        break;
    case 6:
        *(u16 *)(m + 0x34) |= 2;
        break;
    }
}
/* localdecomp:end func_L10_00358F48 */

/* localdecomp:start func_L10_003591B0 */
void func_L10_003591B0(void *arg0) {
    void *temp_a1;

    temp_a1 = *(void **)((u8 *)arg0 + 0x68);
    if ((*(u8 *)((u8 *)arg0 + 0x20)) == 0) {
        *(f32 *)((u8 *)temp_a1 + 4) = (f32) ((*(f32 *)((u8 *)arg0 + 0x18)) + 5.0f);
        if ((*(s32 *)temp_a1) == 2) {
            *(u8 *)((u8 *)arg0 + 0x20) = 5U;
            return;
        }
        *(u8 *)((u8 *)arg0 + 0x20) = 1U;
    }
}
/* localdecomp:end func_L10_003591B0 */

/* localdecomp:start func_L10_003591F8 */
extern int func_L01_00445AD0(int, int, int);
int func_L10_003591F8(char *a) {
    int *p = *(int **)(a + 0x68);
    int x = p[4];
    if (x != -1) return func_L01_00445AD0(x, -1, 0) == 0;
    return 0;
}
/* localdecomp:end func_L10_003591F8 */

/* localdecomp:start func_L10_00359238 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_359238;
extern u8 *D_L10_001DF29C;
extern void func_L10_00359368(void *);
extern void func_L01_004450F0(s32, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32,
                          f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);

void func_L10_00359238(u8 *m) {
    s32 *v = *(s32 **)(m + 0x68);
    V4_359238 c;
    s32 i;

    func_L10_00359368(m);
    switch (m[0x20]) {
    case 1:
        i = v[0];
        if (i != -1 && *(D_L10_001DF29C + (i << 8) + 0x20) >= 0xFD) {
            func_L01_004450F0((s32)m, 2, -1);
        }
        break;
    case 2:
        func_0038CF68(&c, m + 0xC0, 0.10000001f);
        func_003A52A0(0, 0, m);
        func_L01_00451FE0(m, 0x3F, &c, 0xFF, 0xB4, 0, 0, 0x23, 0, 3, 3.0f, 6.0f,
                          3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
        func_L01_00451E78(m, 1, 0.0f);
        func_003C2880(m);
        break;
    }
}
/* localdecomp:end func_L10_00359238 */

/* localdecomp:start func_L10_00359368 */
void func_L01_004450F0(s32, s32, s32);
void func_L10_00359368(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x20)) == 0) {
        func_L01_004450F0((s32) arg0, 1, -1);
    }
}
/* localdecomp:end func_L10_00359368 */
