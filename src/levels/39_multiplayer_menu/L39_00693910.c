#include "common.h"

/* declared by functions of L39_006928D0.c, which this file was cut from */
typedef struct {
    s32 f0;
    char pad[0x30];
    u8 f34;
} S_006928D0_inner;
typedef struct {
    char pad[0x38];
    S_006928D0_inner *f38;
} S_006928D0_outer;
extern S_006928D0_outer *D_L39_0024D760;

/* localdecomp:start func_L39_00693910 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct V_00693910 V_00693910;
typedef struct W_00693910 {
    u8 pad[0x60];
    V_00693910 *vt;
} W_00693910;
struct V_00693910 {
    u8 pad0[0x1C];
    void (*f1C)(W_00693910 *, s32, s32);
    u8 pad20[0x24 - 0x20];
    void (*f24)(W_00693910 *, char *);
    u8 pad28[0x40 - 0x28];
    void (*f40)(W_00693910 *, s32);
    void (*f44)(W_00693910 *, s32, f32, f32);
    u8 pad48[0x4C - 0x48];
    void (*f4C)(W_00693910 *, s32, s32);
    u8 pad50[0x54 - 0x50];
    void (*f54)(W_00693910 *, s32);
    u8 pad58[0x5C - 0x58];
    void (*f5C)(W_00693910 *, f32);
    u8 pad60[0x6C - 0x60];
    s32 (*f6C)(W_00693910 *, s32, char **);
    u8 pad70[0x84 - 0x70];
    void (*f84)(W_00693910 *, s32);
    u8 pad88[0x90 - 0x88];
    void (*f90)(W_00693910 *, f32);
    u8 pad94[0xB4 - 0x94];
    void (*fB4)(W_00693910 *);
    void (*fB8)(W_00693910 *, char *);
};
typedef struct T_00693910 {
    u8 pad0[0x110];
    W_00693910 *w[12];
    u8 pad140[0x2A8 - 0x140];
    s32 f2A8;
    u8 f2AC;
    s32 f2B0;
    u8 pad2B4[0x2BC - 0x2B4];
    u8 f2BC;
    u8 pad2BD[0x3C8 - 0x2BD];
    s32 f3C8;
    s32 f3CC;
    s32 f3D0;
    s32 f3D4;
} T_00693910;
extern char D_L39_00247EE0[];
extern char D_L39_00247EE8[];
extern void func_L39_0067F100(s32);
extern void func_L39_0068A9B8(s32);
extern char *func_00381FF0(s32);
extern void func_L39_00689BD8(void *, void *);
extern void func_L39_00689D28(void *, char *);
extern void func_L39_00689DB8(void *, char *);
extern void func_L39_0068A6D0(void *, s32, f32, f32, f32, f32, u32);
extern void func_L39_0068A4A8(void *, s32, s32, f32, f32, f32, f32, u32);
extern void func_L39_0068A7B8(void *, s32, f32, f32, f32, f32, u32);
extern void func_L39_0068AAB8(void *);
extern void func_L39_0068B2F8(void *, s32, s32);
extern s32 func_00120048(char *, char *, ...);

void func_L39_00693910(T_00693910 *self)
{
    s32 i;
    s32 j;

    func_L39_0067F100(0x270000);
    func_L39_0068A9B8(0);
    func_L39_00689BD8(self, (u8 *)D_L39_0024D760->f38 + 4);
    func_L39_00689D28(self, func_00381FF0(0x124));
    func_L39_00689DB8(self, func_00381FF0(0xCD5));
    func_L39_0068A6D0(self, 0, 0.274f, 0.5f, 0.365f, 0.72f, 0x332299DE);
    func_L39_0068A6D0(self, 1, 0.688f, 0.289f, 0.445f, 0.298f, 0x332299DE);
    func_L39_0068A6D0(self, 2, 0.688f, 0.525f, 0.445f, 0.155f, 0x332299DE);
    func_L39_0068A6D0(self, 3, 0.688f, 0.734f, 0.445f, 0.247f, 0x332299DE);
    func_L39_0068A4A8(self, 0, 1, 0.274f, 0.24499997f, 0.048f, 0.32500002f, 0x331465B7);
    func_L39_0068A4A8(self, 1, 5, 0.688f, 0.19633335f, 0.046333343f, 0.405f, 0x331465B7);
    func_L39_0068A4A8(self, 2, 2, 0.688f, 0.5025f, 0.045000017f, 0.405f, 0x331465B7);
    func_L39_0068A7B8(self, 0, 0.274f, 0.19999999f, 0.6400001f, 0.34500003f, 0x332299DE);
    func_L39_0068AAB8(self);

    {
        char *list[2] = { D_L39_00247EE0, func_00381FF0(0x100E) };
        char buf[0x50];

        self->w[1]->vt->f6C(self->w[1], 2, list);
        self->w[1]->vt->f1C(self->w[1], 2, 0);
        self->w[1]->vt->f84(self->w[1], 1);
        self->w[1]->vt->f40(self->w[1], 1);
        self->w[1]->vt->f90(self->w[1], 0.049999982f);

        for (i = 8; i < 11; i++) {
            self->w[i]->vt->f1C(self->w[i], 3, 0);
            self->w[i]->vt->f4C(self->w[i], 0x40, 1);
            self->w[i]->vt->f44(self->w[i], 1, 0.405f, 0.0f);
        }
        self->w[9]->vt->f1C(self->w[9], 2, 0);
        self->w[7]->vt->fB4(self->w[7]);
        for (j = 3; j < 8; j++) {
            self->w[j]->vt->f1C(self->w[j], 1, 0);
            self->w[j]->vt->f40(self->w[j], 1);
            self->w[j]->vt->f54(self->w[j], 1);
            self->w[j]->vt->f5C(self->w[j], 0.405f);
            self->w[j]->vt->f4C(self->w[j], 0x40, 1);
        }

        func_00120048(buf, D_L39_00247EE8, func_00381FF0(0x1334), func_00381FF0(0x1335));
        self->w[5]->vt->f24(self->w[5], buf);
        func_00120048(buf, D_L39_00247EE8, func_00381FF0(0x1336), func_00381FF0(0x1337));
        self->w[6]->vt->f24(self->w[6], buf);

        self->w[2]->vt->f4C(self->w[2], 0x40, 1);
        self->w[0]->vt->f4C(self->w[0], 0x40, 1);
        self->w[2]->vt->f1C(self->w[2], 1, 0);
        self->w[0]->vt->f1C(self->w[0], 1, 0);
        self->w[2]->vt->f44(self->w[2], 1, 0.405f, 0.0f);
        self->w[0]->vt->f44(self->w[0], 1, 0.32500002f, 0.0f);

        self->w[11]->vt->fB8(self->w[11], func_00381FF0(0x1010));
        self->w[11]->vt->f1C(self->w[11], 2, 0);
        self->w[11]->vt->f40(self->w[11], 1);

        func_L39_0068B2F8(self, 8, 0);
        self->f3C8 = 8;
        self->f2A8 = 0;
        self->f3D0 = -1;
        self->f3CC = 0;
        self->f2BC = 1;
        self->f2AC = 1;
        self->f3D4 = -1;
        self->f2B0 = 0;
    }
}
/* localdecomp:end func_L39_00693910 */
