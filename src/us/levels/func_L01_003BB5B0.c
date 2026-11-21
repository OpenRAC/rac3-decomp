#include "common.h"

/* NTSC-U counterpart of func_L01_003BCDF8 (src/levels/01_veldin/L01_003BCDF8.c) */
typedef struct { char p0[0x18]; float f18; char p1[4]; unsigned char b20; char p2[0x47]; char *p68; char p3[0x29]; unsigned char b95; } A;

/* localdecomp:start func_L01_003BB5B0 */
#include "vu0.h"
typedef struct {
    u8 p0[0x10]; vu0_v4 pos; u8 b20; u8 p21[0x22]; u8 b43; u8 p44[0x1C]; u8 b60; u8 p61[7]; u8 *vars;
    u8 p6C[0x29]; u8 b95; u8 p96[2]; s32 w98; u8 p9C[0x34]; f32 fD0; f32 fD4; u8 pD8[0x1C]; f32 fF4;
    f32 fF8;
} M_3BCDF8;
typedef struct {
    u8 p0[0x30]; f32 f30; u8 p34[0x32]; s16 h66; u8 p68[0xBC]; u8 v124[4]; u8 p128[0x38]; u8 v160[0xC0];
    f32 f220; f32 f224; f32 f228; u8 p22C[8]; s16 h234; u8 p236[0x9E]; f32 f2D4; u8 p2D8[0x40]; f32 f318;
    u8 p31C[4]; s32 w320; u8 p324[8]; s16 h32C; u8 p32E[2]; f32 f330; f32 f334; f32 f338; u8 p33C[0]; s16 h33C; s16 h33E;
} V_3BCDF8;
typedef struct { u8 p0[0x80]; } E_3BCDF8;
extern E_3BCDF8 D_001A30B0_003BB5B0[];
extern u8 *D_L01_0021F740_003BB5B0[];
__asm__(".extern D_L01_001DEA60, 8");
extern s32 D_L01_001DEA60[2];
extern int func_L01_003BBF90(A *);
extern void func_L01_003BC440(A *, int);
extern void func_L01_003BC6C8();
extern void func_L01_003BC750();
extern void func_L01_003BCA68();
extern void func_L01_0040AE68(void *, s32, void *, f32);
extern s32 func_L01_00452EC8(void *);
extern s32 func_L01_00452EF0(void *);
extern s32 func_L01_00451078(void *, void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00441FF8(void *, s32, s32);
extern void func_L01_00457728(void *, void *);
extern void func_L01_00445758(void *, f32, f32, f32, f32, void *, s32);
extern void func_L01_0032FE90_003BB5B0(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_0039FB08(s32);
extern void func_003BDA38(void *, s32, void *);
extern void func_003BEE20(void *, f32, f32, f32, f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_00388770(void *);
extern f32 func_00388800(void *, void *);
extern f32 func_003893C8(f32, f32);
extern void func_00388830(void *, void *, f32);
extern s32 func_003883C8(void *);
void func_L01_003BB5B0(M_3BCDF8 *self) {
    V_3BCDF8 *p = (V_3BCDF8 *)self->vars;
    s32 st;
    s32 r;
    s32 i1, i2, i3, i4, i5;
    f32 f20, f21, f12;
    u8 *e;
    u8 *t;
    u8 *ent;
    vu0_v4 sp90, spA0, spB0, spC0;

    if (func_L01_003BBF90((A *)self)) {
        func_L01_003BC440((A *)self, 1);
        return;
    }
    i1 = p->h33C;
    if (i1 == -1 || *(void **)((ent = (u8 *)&D_001A30B0_003BB5B0[i1]) + 0xDC) != self || *(u8 *)(ent + 0xD0) == 0) {
        p->h33C = func_0039FE80(1, 4, self);
    }
    st = self->b95;
    switch (st) {
    case 0:
        if (self->b20 != 8) {
            if (func_L01_00452EF0(self) != 0 || self->b20 == 3) {
                func_L01_00441FB8(self, 2, -1);
            }
            if (p->h234 == 1) {
                func_L01_00441FB8(self, 1, 1);
            }
        }
        break;
    case 1:
        if (self->b20 != 8) {
            func_L01_00452EF0(self);
            if (p->h234 == st) {
                func_L01_00441FF8(self, 4, -1);
            } else {
                i2 = p->h33E;
                if (i2 != -1) {
                    ent = (u8 *)&D_001A30B0_003BB5B0[i2];
                    if (*(void **)(ent + 0xDC) == self && *(u8 *)(ent + 0xD0) != 0) {
                        func_0039FB08(i2);
                    }
                    p->h33E = -1;
                }
                func_L01_00441FB8(self, 1, 0);
            }
        }
        break;
    default:
        break;
    }
    switch (self->b20) {
    case 2:
        if (self->b43 != 1) {
            func_003BE4F0(self, 1, 0, 10);
        }
        if (p->w320 != -1) {
            sp90.x = func_00388960(func_00388A28(p->f220 - self->pos.x, p->f224 - self->pos.y));
            sp90.y = func_00388978(func_00388A28(p->f220 - self->pos.x, p->f224 - self->pos.y));
            sp90.z = 0;
            *(vu0_q *)&spA0 = *(vu0_q *)(D_L01_0021F740_003BB5B0[p->w320] + 0x10);
            vec_sub_ab(&spA0, &spA0, &self->pos);
            f12 = func_00388770(&spA0);
            func_003BEE20(&p->f330, f12, p->f338 * 0.00027777778f, p->f338 * 0.00027777778f, p->f334 * 0.016666668f);
            func_00388830(&spA0, &spA0, p->f330);
            func_L01_00457728(self, &spA0);
        }
        if (self->b60 & 2) {
            func_L01_00441FB8(self, 3, -1);
        }
        break;
    case 4:
        if (func_L01_00452EC8(self)) {
            if (self->b43 != 0) {
                func_003BE4F0(self, 0, 0, 10);
            }
            p->h32C = 5;
            i3 = p->h33E;
            if (i3 == -1 || *(void **)((ent = (u8 *)&D_001A30B0_003BB5B0[i3]) + 0xDC) != self || *(u8 *)(ent + 0xD0) == 0) {
                p->h33E = func_0039FE80(0, 4, self);
            }
        }
        if (p->w320 != -1) {
            sp90.x = func_00388960(func_00388A28(p->f220 - self->pos.x, p->f224 - self->pos.y));
            sp90.y = func_00388978(func_00388A28(p->f220 - self->pos.x, p->f224 - self->pos.y));
            sp90.z = 0;
            f20 = self->fD0 * sp90.x + self->fD4 * sp90.y;
            f21 = sp90.z;
            e = D_L01_0021F740_003BB5B0[p->w320];
            t = e + 0x10;
            if (!(f21 < f20)) {
                t = t + (*(s32 *)e - 1) * 16;
            }
            *(vu0_q *)&spA0 = *(vu0_q *)t;
            vec_sub_ab(&spA0, &spA0, &self->pos);
            {
                f32 q = f20 / func_00388770(&sp90);
                if (!(f21 < f20)) q = -q;
                func_003BEE20(&p->f330, q, p->f338 * 0.00027777778f, p->f338 * 0.00027777778f, p->f334 * 0.016666668f);
            }
            func_00388830(&spA0, &spA0, p->f330);
            func_L01_00457728(self, &spA0);
        }
        func_L01_00445758(&self->fF8, p->f318, 0.027777778f, 0.027777778f, 1.6666667f, &p->v124, 0);
        func_003BDA38(self, 0, &sp90);
        f12 = func_003893C8(func_00388A28(func_00388800(&p->f220, &sp90), sp90.z - p->f228), self->fF4);
        if (1.5707964f < f12) {
            f12 = 1.5707964f;
        } else if (f12 < 0.0f) {
            f12 = 0.0f;
        }
        p->f2D4 = f12;
        if (func_003883C8(&p->h32C)) {
            func_003BDA38(self, 0xC, &spA0);
            func_003BDA38(self, 0xB, &spB0);
            vec_sub_ab(&spC0, &spB0, &spA0);
            func_00388830(&spC0, &spC0, 0.58333337f);
            func_L01_003BCA68(self, 0);
            p->h32C = 5;
        }
        break;
    case 8:
        if (func_L01_00452EC8(self)) {
            if (p->h66 < 3) {
                p->h66++;
            }
        }
        r = func_L01_00451078(self, p->v160);
        i4 = p->h33E;
        if (i4 != -1) {
            ent = (u8 *)&D_001A30B0_003BB5B0[i4];
            if (*(void **)(ent + 0xDC) == self && *(u8 *)(ent + 0xD0) != 0) {
                func_0039FB08(i4);
            }
            p->h33E = -1;
        }
        if ((r & 1) || p->f30 <= 0.0f) {
            i5 = p->h33C;
            if (i5 != -1) {
                ent = (u8 *)&D_001A30B0_003BB5B0[i5];
                if (*(void **)(ent + 0xDC) == self && *(u8 *)(ent + 0xD0) != 0) {
                    func_0039FB08(i5);
                }
            }
            p->h33C = -1;
            func_0039FE80(2, 0, self);
            self->w98 = 0;
            func_L01_003BC6C8(self);
            func_L01_0032FE90_003BB5B0((u8 *)&self->pos, 0, 0x19, 0x14, 0x14, 0x14, 0x14, 0, 1.25f, 0.0f, 0.0f, 2.0f, 0, 1, 0, 0, 0, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_L01_003BC440((A *)self, 1);
            return;
        }
        if (r & 2) {
            func_L01_00441FB8(self, 1, 0);
        }
        break;
    default:
        break;
    }
    if (self->b95 != 0) {
        func_L01_0040AE68(self, p->h66, D_L01_001DEA60, 1.0f);
    }
    func_L01_003BC750(self);
}
/* localdecomp:end func_L01_003BB5B0 */
