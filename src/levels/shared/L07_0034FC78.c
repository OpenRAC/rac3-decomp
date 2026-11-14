#include "common.h"

typedef struct {
    u8 pad00[0x10];
    f32 pos[4];
    u8 b20;
    u8 pad21[0x21];
    u8 b42;
    u8 b43;
    u8 pad44[0x24];
    struct Data_0034FC78 *d;
    u8 pad6C[0x29];
    u8 b95;
    u16 h96;
} Self_0034FC78;
typedef struct Data_0034FC78 {
    u8 pad00[0x44];
    u8 b44;
    u8 b45;
    u8 pad46[0x160 - 0x46];
    u8 a160[0xC0];
    f32 v220[4];
    u8 pad230[0x298 - 0x230];
    s32 i298;
    u8 pad29C[2];
    s16 h29E;
    s32 i2A0;
    s32 i2A4;
    u8 pad2A8[4];
    s32 i2AC;
    u8 pad2B0[0x3B4 - 0x2B0];
    s32 i3B4;
    u8 pad3B8[0x444 - 0x3B8];
    s32 i444;
    u8 pad448[4];
    s32 i44C;
    u8 pad450[4];
    s32 i454;
    s32 i458;
} Data_0034FC78;
typedef struct {
    u8 pad00[0xD0];
    u8 bD0;
    u8 padD1[0xB];
    void *fDC;
    u8 padE0[0x20];
} Ent_0034FC78;
typedef struct {
    s32 n;
} Node_0034FC78;
typedef struct {
    u8 pad00[0x20];
    f32 f20;
    u8 pad24[4];
    s32 i28;
    s32 i2C;
    u8 pad30[0x10];
    f32 f40;
    u8 pad44[4];
    s32 i48;
} Cfg_0034FC78;
typedef struct {
    u8 pad00[0x5C];
    u8 *p5C;
} Tab_0034FC78;

/* localdecomp:start func_L07_0034FC78 */
/* func_L07_0034FC78 (levels 07, 16). Case 3's 0x32 store goes through $a3 because sched1 issues the
   func_L01_00452310 argument moves before it: D_L07_001D66B0 is an 8-byte object, so its address is
   one `la` (adjacent lui/addiu) instead of a split %hi that took an ALU slot. The trailing stub call
   names its level-07 place: the catalogue pairs the 8-byte stub copies of levels 07 and 16 the other
   way round (level 16 calls the copy it files under func_L01_00356C90). */
#include "vu0.h"


extern u8 D_1A30B0[];
extern s32 D_001D545C;
extern Node_0034FC78 *D_L07_0021D2C0[];
extern Cfg_0034FC78 D_L07_001E1EC0;
extern u8 D_L07_001D66B0[8];
extern Tab_0034FC78 D_L07_0021EC98;

extern void func_L07_00350DD8(void *);
extern s32 func_L01_004561E0(void *);
extern s32 func_00382468(s32);
extern s32 func_L01_00445AD0(s32, s32, s32);
extern s32 func_0038CB00(void *);
extern s32 func_0038CAD0(void *);
extern void func_L01_0045C150(void *, void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_00382498(s32, s32);
extern s32 func_L01_00454370(void *, void *);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L07_0034AC60(f32, void *, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00452310(void *m, s32 a, void *b, s32 c, s32 d, f32 x0, f32 x1, f32 x2,
                              f32 x3, f32 x4, u8 e, f32 x5, f32 x6, s32 f, s32 g);
extern void func_L01_004443E8(void *, s32, s32);
extern void func_003C2880(void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_L01_004561B8(void *);
extern s32 func_L01_0045BDE8(void *, s32);
extern void func_003A4F28(s32);
extern f32 func_0038CF38(void *, void *);
extern void func_003C2EC0(void *, s32, void *);
extern void func_003C2F58(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_L01_00446780(void *, void *, f32, f32, s32, f32, s32, s32, s32);
extern void func_003C4C18(void *, f32);
extern f32 func_L01_00443A18(f32, f32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_L01_0044E1B8(void *, f32);
extern s32 func_L07_003E3C90(void *, void *, void *, s32, s32, s32, f32, f32, f32);
extern void func_L07_00351240(void *);
extern void func_L07_00351568(void *);

void func_L07_0034FC78(Self_0034FC78 *self) {
    Data_0034FC78 *d;
    vu0_v4 buf[4];
    vu0_v4 v50;
    vu0_v4 v60;
    vu0_v4 v70;
    vu0_v4 v80;
    vu0_v4 v90;
    vu0_v4 vA0;
    vu0_v4 vB0;
    s32 flag;
    s32 id;
    s32 r;
    s32 cnt0;
    s32 cnt1;
    s32 k;
    s32 k4;
    Node_0034FC78 *p;
    u8 *e;
    u8 *q;

    d = self->d;
    func_L07_00350DD8(self);
    switch (self->b95) {
    case 0:
        if (func_L01_004561E0(self)) {
            d->h29E = func_00382468(30);
        }
        if (d->i44C == -1) {
            flag = 1;
        } else {
            r = func_L01_00445AD0(d->i44C, -1, 1);
            flag = 1;
            if (r) flag = 0;
        }
        if (d->i2A0 == 1 && func_0038CB00(&d->h29E) && flag) {
            if (d->i2AC != -1) {
                p = D_L07_0021D2C0[d->i2AC];
                func_L01_0045C150(self, p, p->n - 1, 0);
            }
            if (self->b43 != 2) {
                func_003C3A10(self, 2, 0, 8);
            }
            func_L01_004450F0(self, 3, 2);
        } else if (d->i2A4 != 0) {
            func_L01_004450F0(self, 2, 1);
            d->i2A4 = 0;
            if (d->i298 < 250) {
                d->i298 = (func_00382498(0x1E0, 0x258) * 5 + 2) / 6;
            }
        }
        break;
    case 1:
        if (d->i3B4 == 1 || d->i2A0 == 1) {
            if (d->i2AC != -1) {
                p = D_L07_0021D2C0[d->i2AC];
                func_L01_0045C150(self, p, p->n - 1, 0);
            }
            func_L01_004450F0(self, 3, 2);
        }
        break;
    case 2:
        if (d->i2A0 != 1 && d->i3B4 != 1) {
            func_L01_004450F0(self, 2, 1);
            d->i298 = (func_00382498(0x244, 0x258) * 5 + 2) / 6;
        }
        break;
    case 3:
        r = func_L01_00454370(self, d->a160);
        if (r & 1) {
            func_003A52A0(4, 0, self);
            func_L07_0034AC60(1.0f, self->pos, 0, 0x2D, 0x28, 0x28, 0x28, 0x2D, 1, 1, 1);
            D_L07_001E1EC0.f40 = 0.1f;
            D_L07_001E1EC0.i48 = 0x4B;
            D_L07_001E1EC0.f20 = 0.2f;
            D_L07_001E1EC0.i28 = 0x32;
            D_L07_001E1EC0.i2C = 0;
            func_L01_00452310(self, 0x3FF, D_L07_001D66B0, 3, 0x28, 1.5f, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0);
            func_L01_004443E8(self, 0, 3);
            func_003C2880(self);
            return;
        }
        if (r & 2) {
            if (d->i2A0 == 1 || d->i3B4 == 1) {
                if (self->b43 != 2) {
                    func_003C3A10(self, 2, 0, 8);
                }
                func_L01_004450F0(self, 3, 2);
            } else {
                func_L01_004450F0(self, 2, 1);
                d->i298 = (func_00382498(0x244, 0x258) * 5 + 2) / 6;
            }
        } else {
            if (func_L01_004561B8(self)) {
                func_003A52A0(3, 0, self);
            }
        }
        break;
    }

    switch (self->b20) {
    case 1:
    case 2:
        break;
    case 3:
        if (func_L01_004561B8(self)) {
            if (d->i444 == -1 || *(void **)((e = D_1A30B0 + (d->i444 << 7)) + 0xDC) != self || e[0xD0] == 0) {
                d->i444 = func_003A52A0(2, 4, self);
            }
        }
        id = d->i2AC;
        if (id != -1 && func_L01_0045BDE8(self, id)) {
            if (d->i444 != -1) {
                e = D_1A30B0 + (d->i444 << 7);
                if (*(void **)(e + 0xDC) == self && e[0xD0] != 0) {
                    func_003A4F28(d->i444);
                }
            }
            d->i444 = -1;
            func_L01_004450F0(self, 4, -1);
            p = D_L07_0021D2C0[d->i2AC];
            func_L01_0045C150(self, p, 0, p->n - 1);
        }
        if (func_0038CF38(self->pos, d->v220) < 12.0f) {
            d->i458 = 0;
            if (self->b43 != 2) {
                func_003C3A10(self, 2, 0, 8);
            }
            func_003C2EC0(self, 3, buf);
            v50 = buf[1];
            v60 = buf[3];
            func_0038CF68(&v70, &v50, -0.85f);
            func_0038CF68(&v80, &v50, -2.6f);
            func_0038CF68(&v90, &v50, -5.0f);
            func_0038CF68(&vA0, &v50, -7.5f);
            vec_add_ba(&v70, &v70, &v60);
            vec_add_ba(&v80, &v80, &v60);
            vec_add_ba(&v90, &v90, &v60);
            vec_add_ab(&vA0, &vA0, &v60);
            v70.z -= 0.1f;
            v80.z -= 0.1f;
            func_0038CF68(&vB0, &buf[1], -(func_003824E0(15.0f, 25.0f) * 0.0200000007f));
            func_L01_00446780(self, &v70, 0.5f, (f32)d->b44, 1, 1.0f, 0, 1, 0);
            func_L01_00446780(self, &v80, 0.75f, (f32)d->b44, 1, 1.0f, 0, 1, 0);
            func_L01_00446780(self, &v90, 1.25f, (f32)d->b44, 1, 1.0f, 0, 1, 0);
            func_L01_00446780(self, &vA0, 1.25f, (f32)d->b44, 1, 1.0f, 0, 1, 0);
            for (cnt0 = 0; cnt0 < 3; cnt0++) {
                func_003C4C18(&v60, 0.1f);
                func_003C4C18(&vB0, 0.02f);
                func_L01_0046FB40(&v60, &vB0, 0x15, 0x808080, 0x1E, 0x7F, 0x20, 0,
                                  func_003824E0(0.4f, 0.6f) * 210000.0f,
                                  func_003824E0(1.0f, 1.5f) * 210000.0f,
                                  func_L01_00443A18(0.0f, 0.002f));
            }
            for (k = 0; k < 3; k++) {
                func_003C4C18(&v60, 0.1f);
                func_003C4C18(&vB0, 0.02f);
                q = func_L01_0046FB40(&v60, &vB0, 0x15, 0x800000, 0x1E, 0x7F, 0x60, 0,
                                      func_003824E0(0.4f, 0.6f) * 210000.0f,
                                      func_003824E0(1.0f, 1.5f) * 210000.0f,
                                      func_L01_00443A18(0.0f, 0.002f));
                if (q != 0) {
                    q[2] = *D_L07_0021EC98.p5C;
                }
            }
        } else {
            if (d->i444 != -1) {
                e = D_1A30B0 + (d->i444 << 7);
                if (*(void **)(e + 0xDC) == self && e[0xD0] != 0) {
                    func_003A4F28(d->i444);
                }
            }
            d->i444 = -1;
            if (func_0038CAD0(&d->i454)) {
                if (self->b43 != 1) {
                    func_003C3A10(self, 1, 0, 8);
                }
            } else {
                if (self->b43 != 0) {
                    func_003C3A10(self, 0, 0, 8);
                }
            }
            if (func_L01_0044E1B8(self, 0.5f) && self->b42 == 1) {
                func_003C2F58(self, 4, buf);
                vec_sub_ba(&buf[1], d->v220, &buf[0]);
                func_0038CF68(&buf[1], &buf[1], 0.90000004f);
                func_003A52A0(5, 0, self);
                func_L07_003E3C90(self, &buf[0], &buf[1], 1, 0x96, 0, (f32)d->b45, 2.0f, 0.0f);
                d->i454 = 0x25;
                if (D_001D545C == 7) {
                    d->i458++;
                    if (d->i458 >= 10) {
                        d->i458 = 0x4B;
                    } else {
                        d->i458 = 0x25;
                    }
                }
            }
        }
        break;
    case 4:
        if (func_L01_004561B8(self)) {
            if (d->i444 == -1 || *(void **)((e = D_1A30B0 + (d->i444 << 7)) + 0xDC) != self || e[0xD0] == 0) {
                d->i444 = func_003A52A0(2, 4, self);
            }
        }
        id = d->i2AC;
        if (id != -1 && func_L01_0045BDE8(self, id)) {
            p = D_L07_0021D2C0[d->i2AC];
            func_L01_0045C150(self, p, p->n - 1, 0);
            if (d->i444 != -1) {
                e = D_1A30B0 + (d->i444 << 7);
                if (*(void **)(e + 0xDC) == self && e[0xD0] != 0) {
                    func_003A4F28(d->i444);
                }
            }
            d->i444 = -1;
            func_L01_004450F0(self, 3, -1);
        }
        if (func_0038CF38(self->pos, d->v220) < 7.0f) {
            if (self->b43 != 2) {
                func_003C3A10(self, 2, 0, 8);
            }
            func_003C2EC0(self, 3, buf);
            v50 = buf[1];
            v60 = buf[3];
            func_0038CF68(&v70, &v50, -0.85f);
            func_0038CF68(&v80, &v50, -2.6f);
            func_0038CF68(&v90, &v50, -5.0f);
            func_0038CF68(&vA0, &v50, -7.5f);
            vec_add_ba(&v70, &v70, &v60);
            vec_add_ba(&v80, &v80, &v60);
            vec_add_ba(&v90, &v90, &v60);
            vec_add_ab(&vA0, &vA0, &v60);
            v70.z -= 0.1f;
            v80.z -= 0.1f;
            func_0038CF68(&vB0, &buf[1], -(func_003824E0(15.0f, 25.0f) * 0.0200000007f));
            func_L01_00446780(self, &v70, 0.5f, (f32)d->b44, 1, 1.0f, 0, 1, 0);
            func_L01_00446780(self, &v80, 0.75f, (f32)d->b44, 1, 1.0f, 0, 1, 0);
            func_L01_00446780(self, &v90, 1.25f, (f32)d->b44, 1, 1.0f, 0, 1, 0);
            func_L01_00446780(self, &vA0, 1.25f, (f32)d->b44, 1, 1.0f, 0, 1, 0);
            for (cnt1 = 0; cnt1 < 3; cnt1++) {
                func_003C4C18(&v60, 0.1f);
                func_003C4C18(&vB0, 0.02f);
                func_L01_0046FB40(&v60, &vB0, 0x15, 0x808080, 0x1E, 0x7F, 0x20, 0,
                                  func_003824E0(0.4f, 0.6f) * 210000.0f,
                                  func_003824E0(1.0f, 1.5f) * 210000.0f,
                                  func_L01_00443A18(0.0f, 0.002f));
            }
            for (k4 = 0; k4 < 3; k4++) {
                func_003C4C18(&v60, 0.1f);
                func_003C4C18(&vB0, 0.02f);
                q = func_L01_0046FB40(&v60, &vB0, 0x15, 0x800000, 0x1E, 0x7F, 0x60, 0,
                                      func_003824E0(0.4f, 0.6f) * 210000.0f,
                                      func_003824E0(1.0f, 1.5f) * 210000.0f,
                                      func_L01_00443A18(0.0f, 0.002f));
                if (q != 0) {
                    q[2] = *D_L07_0021EC98.p5C;
                }
            }
        } else {
            if (d->i444 != -1) {
                e = D_1A30B0 + (d->i444 << 7);
                if (*(void **)(e + 0xDC) == self && e[0xD0] != 0) {
                    func_003A4F28(d->i444);
                }
            }
            d->i444 = -1;
            if (func_0038CAD0(&d->i454)) {
                if (self->b43 != 1) {
                    func_003C3A10(self, 1, 0, 8);
                }
            } else {
                if (self->b43 != 0) {
                    func_003C3A10(self, 0, 0, 8);
                }
            }
            if (func_L01_0044E1B8(self, 0.5f) && self->b42 == 1) {
                func_003C2F58(self, 4, buf);
                vec_sub_ba(&buf[1], d->v220, &buf[0]);
                func_0038CF68(&buf[1], &buf[1], 0.90000004f);
                func_003A52A0(5, 0, self);
                func_L07_003E3C90(self, &buf[0], &buf[1], 1, 0x96, 0, (f32)d->b45, 2.0f, 0.0f);
                d->i454 = 0x25;
            }
        }
        break;
    case 5:
        id = d->i2AC;
        if (id != -1) {
            func_L01_0045BDE8(self, id);
        }
        if (self->h96 > 0xB4) {
            if (self->b43 != 2) {
                func_003C3A10(self, 2, 0, 8);
            }
            func_L01_004450F0(self, 3, -1);
        }
        break;
    }
    func_L07_00351240(self);
    func_L07_00351568(self);
}
/* localdecomp:end func_L07_0034FC78 */

INCLUDE_ASM("asm/levels", func_L07_00350DD8);
