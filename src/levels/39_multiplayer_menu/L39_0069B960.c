#include "common.h"

typedef struct Vt_0069C088 Vt_0069C088;
typedef struct Obj_0069C088 Obj_0069C088;
typedef struct Self_0069C088 Self_0069C088;
struct Vt_0069C088 {
    u8 pad0[0x78];
    s32 (*f78)(void *);
    u8 pad1[0x10];
    s32 (*f8C)(void *);
};
struct Obj_0069C088 {
    u8 pad0[0x60];
    Vt_0069C088 *f60;
};
struct Self_0069C088 {
    u8 pad0[0x118];
    Obj_0069C088 *f118;
    u8 pad1[0x2A8 - 0x11C];
    s32 f2A8;
    s32 f2AC;
    u8 pad2[0x2B8 - 0x2B0];
    s32 f2B8;
    u8 pad3[0x2C4 - 0x2BC];
    s32 f2C4;
    u8 pad4[0x2E8 - 0x2C8];
    u8 f2E8;
};

/* localdecomp:start func_L39_0069B960 */
extern u8 D_1A5D8E[];
extern u8 D_00248268[];
extern void func_L39_006CC798(void *, void *);
extern void func_1206F4(void *, void *);
extern void func_1200E0(void *, void *, void *);

typedef struct S_0069B960 {
    u8 pad0[0x2A8];
    s32 f2A8;
    u8 pad1[0x2B8 - 0x2AC];
    s32 f2B8;
    u8 pad2[0x2EC - 0x2BC];
    s32 f2EC;
    s32 f2F0;
    s32 f2F4;
    u8 pad3[0x2FC - 0x2F8];
    s32 f2FC;
    s32 f300;
    u8 pad4[0x344 - 0x304];
    u8 f344[0x18];
    u8 pad5[0x35E - 0x35C];
    u8 f35E[0x384 - 0x35E];
    u8 f384[1];
} S_0069B960;

void func_L39_0069B960(S_0069B960 *self, s32 mode, s32 a, s32 b, s32 c)
{
    s32 i;
    u8 *p;

    self->f2A8 = mode;
    self->f300 = 0;
    self->f2B8 = (mode == 3) ? 1 : self->f2B8;
    if (mode == 3) {
        self->f2EC = a;
        self->f2F0 = b;
        self->f2F4 = c;
    } else if (mode == 4) {
        func_L39_006CC798(self->f384, &D_1A5D8E[0x3CE]);
        self->f2FC = *(s32 *)&D_1A5D8E[0x3CE + 0x14];
        func_1206F4(self->f344, D_1A5D8E);
        func_1200E0(self->f35E, D_00248268, &self->f300);
        self->f300++;
        if (self->f344[0] == '#' || self->f344[0] == '@') {
            p = &self->f344[1];
            for (i = 15; i >= 0; i--) {
                p[-1] = p[0];
                p++;
            }
            self->f344[0x11] = ' ';
        }
        self->f344[0x12] = 0;
    }
}
/* localdecomp:end func_L39_0069B960 */

/* localdecomp:start func_L39_0069BA50 */
__asm__(".extern D_00241648, 16");
__asm__(".extern D_00241654, 16");
__asm__(".extern D_00241656, 16");
__asm__(".extern D_00241657, 16");
__asm__(".extern D_00241658, 16");
__asm__(".extern D_00241659, 16");
__asm__(".extern D_0024165A, 16");
__asm__(".extern D_0024165B, 16");
__asm__(".extern D_0024165C, 16");
__asm__(".extern D_0024165D, 16");
extern void func_0019AE90(s32);
extern s32 func_L39_006CC350(s32 *, s32);
extern void func_L39_0069C088(Self_0069C088 *);
extern void func_L39_0069BED8(void *);
extern s32 func_00120884(char *);
extern void func_00120048(char *, char *);
extern u8 D_001A5CD0[];
typedef struct {
    u8 pad0[0xC];
    s32 fC;
    u8 pad10[0xEE];
    u8 fFE[1];
    u8 pad_FF[0x140 - 0xFF];
    s32 f140;
    s32 f144;
} G_0069BA50;
extern char D_00248138[];
extern s8 D_00241648;
extern s8 D_00241654;
extern s8 D_00241656;
extern s8 D_00241657;
extern s8 D_00241658;
extern s8 D_00241659;
extern s8 D_0024165A;
extern s8 D_0024165B;
extern s8 D_0024165C;
extern s8 D_0024165D;

typedef struct Vt_0069BA50 {
    u8 pad0[0x1C];
    void (*f1C)(void *, s32, s32);
    u8 pad1[0x24 - 0x20];
    void (*f24)(void *, char *);
    u8 pad2[0x60 - 0x28];
    void (*f60)(void *, s32);
    u8 pad3[0x88 - 0x64];
    void (*f88)(void *, s32);
    u8 pad4[0xA8 - 0x8C];
    void (*fA8)(void *, s32);
    u8 pad5[0xB8 - 0xAC];
    void (*fB8)(void *, char *);
} Vt_0069BA50;
typedef struct Obj_0069BA50 {
    u8 pad0[0x60];
    Vt_0069BA50 *f60;
} Obj_0069BA50;
typedef struct Self_0069BA50 {
    u8 pad0[0x110];
    Obj_0069BA50 *f110;
    Obj_0069BA50 *f114;
    Obj_0069BA50 *f118;
    Obj_0069BA50 *f11C;
    Obj_0069BA50 *f120;
    Obj_0069BA50 *f124;
    Obj_0069BA50 *f128;
    Obj_0069BA50 *f12C;
    Obj_0069BA50 *f130;
    Obj_0069BA50 *f134;
    u8 pad1[0x2A8 - 0x138];
    s32 f2A8;
    s32 f2AC;
    s32 f2B0;
    s32 f2B4;
    s32 f2B8;
    s32 f2BC;
    s32 f2C0;
    s32 f2C4;
    s32 f2C8;
    s32 f2CC;
    s32 f2D0;
    u8 f2D4[8];
    s32 f2DC;
    s32 f2E0;
    s32 f2E4;
    u8 pad2[0x304 - 0x2E8];
    char f304[0x40];
    char f344[0x40];
    s32 f384[1];
} Self_0069BA50;

void func_L39_0069BA50(void *arg0)
{
    Self_0069BA50 *self = (Self_0069BA50 *)arg0;
    u32 mode;
    s32 i;
    s32 len;
    s32 t;
    u8 *p;
    u8 *e;

    mode = self->f2A8;
    if (mode < 2) {
        self->f130->f60->f1C(self->f130, 3, 0);
        self->f134->f60->f1C(self->f134, 0, 0);
        self->f120->f60->f1C(self->f120, 3, 0);
        self->f124->f60->f1C(self->f124, 3, 0);
        func_0019AE90(self->f2AC);
    } else {
        if (mode == 2) {
            self->f130->f60->f1C(self->f130, 2, 0);
            self->f134->f60->f1C(self->f134, 0, 0);
            self->f120->f60->f1C(self->f120, 2, 0);
            self->f124->f60->f1C(self->f124, 2, 0);
            self->f120->f60->fA8(self->f120, 0);
            self->f124->f60->fA8(self->f124, 0);
            func_0019AE90(self->f2AC);
        } else if (mode == 3) {
            self->f130->f60->f1C(self->f130, 2, 0);
            self->f134->f60->f1C(self->f134, 0, 0);
            self->f120->f60->f1C(self->f120, 2, 0);
            self->f124->f60->f1C(self->f124, 2, 0);
            self->f120->f60->fA8(self->f120, 0);
            self->f124->f60->fA8(self->f124, 0);
            func_0019AE90(self->f2AC);
        } else if (mode == 4) {
            self->f2B4 = D_00241648 == 0;
            self->f2C0 = D_00241656 != 0;
            self->f2E0 = D_00241657;
            self->f2E4 = D_00241658;
            self->f2C4 = D_00241654 != 0;
            self->f2D0 = D_0024165A != 0;
            self->f2C8 = D_0024165B != 0;
            self->f2CC = D_0024165C != 0;
            self->f2B8 = D_0024165D != 0;
            for (i = 0; i < 8; i++) {
                self->f2D4[i] = (D_00241659 & (1 << i)) > 0;
        }
            self->f2AC = func_L39_006CC350(self->f384, 0x11);
            self->f118->f60->f88(self->f118, self->f2AC);
            func_L39_0069C088((Self_0069C088 *)self);
            self->f2BC = func_L39_006CC350(self->f384, 0x16);
            t = func_L39_006CC350(self->f384, 1);
            self->f11C->f60->fA8(self->f11C, t);
            self->f2DC = func_L39_006CC350(self->f384, 0xF) * 5;
            self->f12C->f60->fA8(self->f12C, self->f2DC);
            t = func_L39_006CC350(self->f384, 0x10) - 1;
            self->f114->f60->f88(self->f114, t);
            func_L39_0069BED8(self);
            len = func_00120884(self->f344);
            e = (u8 *)&self->f344[len];
            for (p = e - 1; (u8 *)self->f344 < p && *p == ' '; p--) {
                *p = 0;
        }
            self->f110->f60->fB8(self->f110, self->f344);
            func_00120048(self->f304, self->f344);
            if (func_L39_006CC350(self->f384, 0xC) == 0) {
                self->f120->f60->fA8(self->f120, ((G_0069BA50 *)D_001A5CD0)->f140);
                self->f124->f60->fA8(self->f124, ((G_0069BA50 *)D_001A5CD0)->f144);
        } else {
                self->f120->f60->fA8(self->f120, 0);
                self->f124->f60->fA8(self->f124, 0);
        }
            if (((G_0069BA50 *)D_001A5CD0)->fFE[0] != 0) {
                self->f130->f60->f60(self->f130, 1);
                self->f134->f60->f24(self->f134, (char *)((G_0069BA50 *)D_001A5CD0)->fFE);
        } else {
                self->f130->f60->f60(self->f130, 0);
                self->f134->f60->f24(self->f134, D_00248138);
        }
            self->f128->f60->fA8(self->f128, ((G_0069BA50 *)D_001A5CD0)->fC);
            self->f130->f60->f1C(self->f130, 2, 0);
            self->f134->f60->f1C(self->f134, 2, 0);
        }
    }
}
/* localdecomp:end func_L39_0069BA50 */

INCLUDE_ASM("asm/levels", func_L39_0069BED8);

/* localdecomp:start func_L39_0069C088 */
extern void func_19AE90(s32);

void func_L39_0069C088(Self_0069C088 *self)
{
    Obj_0069C088 *p;
    s32 v;
    s32 t;

    p = self->f118;
    self->f2AC = p->f60->f8C(p);
    p = self->f118;
    v = p->f60->f78(p);
    if (v - 1 != 2) {
        self->f2AC++;
    }
    t = self->f2AC;
    if (t == 2) {
        self->f2E8 = 0;
        v = self->f2A8 == 3;
    } else {
        v = 1;
        self->f2E8 = v;
    }
    do {
        self->f2B8 = v;
    } while (0);
    if (self->f2AC == 1) {
        self->f2C4 = 0;
    } else {
        self->f2C4 = 1;
    }
    func_19AE90(self->f2AC);
}
/* localdecomp:end func_L39_0069C088 */
