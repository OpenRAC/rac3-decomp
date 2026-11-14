#include "common.h"

/* NTSC-U counterpart of func_L17_003B3BF0 (src/levels/17_crash_site/L17_003B3790.c) */
#include "vu0.h"
extern s32 func_0039FE80(s32, s32, void *);

/* localdecomp:start func_L17_003B20F8 */
typedef struct { u8 p0[0x30]; u8 path[0x3C]; s32 f6C; vu0_v4 home; vu0_v4 homerot; f32 speed; f32 t; s8 animA; s8 animB; s8 animC; s8 animD; u8 fired; u8 alert; u8 snd; u8 sndloop; s32 sndh; } D_3B3BF0;
typedef struct { u8 p0[0x35C]; u8 *f35C; s32 f360; u8 p364[0xA]; s16 h36E; } H_3B3BF0;
extern H_3B3BF0 D_001A4BE0;
extern s32 D_001D545C;
extern s32 D_L17_001D6694_003B20F8;
extern u8 D_001A30B0[];
extern s32 func_L01_00448E90(void *);
extern void func_L01_004A6DF8(void *, s32);
extern void func_003BE418(void *, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L17_003B1E88();
extern s32 func_L17_003B1DB8();
extern void func_L17_003B1F80();
extern void func_003BE4F0(void *, s32, s32, s32);
extern s32 func_L01_00452F60(void *);
extern s32 func_L01_00452EC8(void *);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_0039FB08(s32);
extern void func_003BF838(void *, void *, void *, void *);

void func_L17_003B20F8(u8 *self) {
    D_3B3BF0 *d = *(D_3B3BF0 **)(self + 0x68);
    vu0_v4 pos, rot, dp;
    s32 ok, back;

    pos = *(vu0_v4 *)(self + 0x10);
    rot = *(vu0_v4 *)(self + 0xF0);
    if (func_L01_00448E90(self + 0x10) == 0) return;
    if (D_001A4BE0.f35C == self && D_001A4BE0.f360 >= 2 && D_001A4BE0.h36E <= 0) {
        d->alert++;
    } else if (D_001A4BE0.f35C != self && d->alert != 0) {
        d->alert--;
    }
    if (d->alert >= 11) d->alert = 10;
    if (D_001D545C == 10) {
        if (D_L17_001D6694_003B20F8 == 2) {
            *(s32 *)(self + 0x98) = 0;
            *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 0x41) & 0xEFFF;
            func_L01_004A6DF8(self, 1);
        } else {
            *(u16 *)(self + 0x34) &= 0xFFBE;
            *(u16 *)(self + 0x34) |= *(u16 *)(*(u8 **)(self + 0x24) + 0x44) & 0x1000;
            *(s32 *)(self + 0x98) = *(s32 *)(*(u8 **)(self + 0x24) + 0x10);
        }
    }
    switch (self[0x20]) {
    case 0:
        d->f6C |= 1;
        d->home = *(vu0_v4 *)(self + 0x10);
        d->homerot = *(vu0_v4 *)(self + 0xF0);
        d->fired = 0;
        if (d->animA != -1) func_003BE418(self, d->animA, 0);
        d->t = 0.0f;
        func_L01_00441FB8(self, 1, -1);
        func_L17_003B1E88(self);
        break;
    case 1:
        ok = 1;
        if (self[0x60] & 2) {
            if (d->animA != -1) {
                if (self[0x43] != d->animA) func_003BE4F0(self, d->animA, 0, 5);
                else *(s32 *)(self + 0x48) = 0;
            } else {
                *(s32 *)(self + 0x48) = 0;
            }
        }
        if (d->animA != -1 && self[0x42] != d->animA) ok = 0;
        back = func_L17_003B1DB8(self) == 0;
        if (ok && d->fired == 0) {
            if (func_L01_00452F60(self) != 0 || back || d->alert >= 10) {
                d->fired = 1;
                if (d->animB != -1 && self[0x43] != d->animB) func_003BE4F0(self, d->animB, 0, 5);
                func_L01_00441FB8(self, 2, -1);
                break;
            }
        }
        if (func_L01_00452F60(self) == 0 && d->alert == 0) d->fired = 0;
        break;
    case 2:
        if (func_L01_00452EC8(self) != 0) {
            if (d->sndloop) d->sndh = func_0039FE80(d->snd, 4, self);
            else func_0039FE80(d->snd, 0, self);
        }
        d->t += 1.0f / d->speed;
        func_L17_003B1F80(self);
        if (self[0x60] & 2) {
            if (d->animC != -1) {
                if (self[0x43] != d->animC) func_003BE4F0(self, d->animC, 0, 5);
                else *(s32 *)(self + 0x48) = 0;
            } else {
                *(s32 *)(self + 0x48) = 0;
            }
        }
        if (1.0f <= d->t) {
            if (d->sndloop) {
                if (d->sndh != -1) {
                    u8 *e = &D_001A30B0[d->sndh << 7];
                    if (*(u8 **)(e + 0xDC) == self && e[0xD0] != 0) func_0039FB08(d->sndh);
                }
                d->sndh = -1;
            }
            d->t = 1.0f;
            func_L01_00441FB8(self, 3, -1);
        }
        break;
    case 3:
        ok = 1;
        if (self[0x60] & 2) {
            if (d->animC != -1) {
                if (self[0x43] != d->animC) func_003BE4F0(self, d->animC, 0, 5);
                else *(s32 *)(self + 0x48) = 0;
            } else {
                *(s32 *)(self + 0x48) = 0;
            }
        }
        if (d->animC != -1 && self[0x42] != d->animC) ok = 0;
        back = func_L17_003B1DB8(self) == 1;
        if (ok && d->fired == 0) {
            if (func_L01_00452F60(self) != 0 || back || d->alert >= 10) {
                d->fired = 1;
                if (d->animD != -1 && self[0x43] != d->animD) func_003BE4F0(self, d->animD, 0, 5);
                func_L01_00441FB8(self, 4, -1);
                break;
            }
        }
        if (func_L01_00452F60(self) == 0 && d->alert == 0) d->fired = 0;
        break;
    case 4:
        if (func_L01_00452EC8(self) != 0) {
            if (d->sndloop) d->sndh = func_0039FE80(d->snd, 4, self);
            else func_0039FE80(d->snd, 0, self);
        }
        d->t -= 1.0f / d->speed;
        func_L17_003B1F80(self);
        if (self[0x60] & 2) {
            if (d->animA != -1) {
                if (self[0x43] != d->animA) func_003BE4F0(self, d->animA, 0, 5);
                else *(s32 *)(self + 0x48) = 0;
            } else {
                *(s32 *)(self + 0x48) = 0;
            }
        }
        if (d->t <= 0.0f) {
            if (d->sndloop) {
                if (d->sndh != -1) {
                    u8 *e = &D_001A30B0[d->sndh << 7];
                    if (*(u8 **)(e + 0xDC) == self && e[0xD0] != 0) func_0039FB08(d->sndh);
                }
                d->sndh = -1;
            }
            d->t = 0.0f;
            func_L01_00441FB8(self, 1, -1);
        }
        break;
    case 5:
        *(u16 *)(self + 0x34) |= 2;
        break;
    }
    if (self[0x20] < 5) {
        vec_sub_ba(&dp, self + 0x10, &pos);
        func_003BF838(d->path, &dp, &rot, self + 0xF0);
    }
}
/* localdecomp:end func_L17_003B20F8 */
