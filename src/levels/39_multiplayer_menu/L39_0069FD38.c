#include "common.h"

/* localdecomp:start func_L39_0069FD38 */
extern void func_L39_00688460(void *a0, void *p1, void *p2, void *p3, void *p4, void *p5, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5);
void func_L39_0069FD38(void *a0)
{
    s32 v[4];
    func_L39_00688460(a0, v, v, v, v, v, 0.5f, 0.5f, 1.0f, 1.0f, 1.675f);
}
/* localdecomp:end func_L39_0069FD38 */

/* localdecomp:start func_L39_0069FD88 */
/* best: 32 diff under --mode S --as ps2as (file flags: far more, inline float constants need ps2as). Everything before the last loop matches. Last loop: retail tests f2AC[i] first, loads w[i+8] straight into $a0, bumps i in each arm and closes with slti/bnez (no bnel); mine hoists the 0x2AC load and the color constant and rotates with bnel. Tried swapping arms and an element local. */
typedef struct S_0069FD88_w S_0069FD88_w;
typedef struct {
    char _p0[0x1C];
    void (*f1C)(S_0069FD88_w *, s32, s32);
    char _p20[4];
    void (*f24)(S_0069FD88_w *, char *);
    char _p28[0x18];
    void (*f40)(S_0069FD88_w *, s32);
    void (*f44)(S_0069FD88_w *, s32, f32, f32);
    char _p48[8];
    void (*f50)(S_0069FD88_w *, u32);
} S_0069FD88_vt;
struct S_0069FD88_w {
    char _p0[0x60];
    S_0069FD88_vt *vt;
};
typedef struct {
    char _p0[0x110];
    S_0069FD88_w *w[16];
    char _p150[0x2A8 - 0x150];
    s32 f2A8;
    u8 *f2AC;
    s32 f2B0;
    u8 f2B4;
    char _p2B5[3];
    s32 f2B8;
    s32 f2BC;
    s32 f2C0;
    u8 f2C4;
    u8 f2C5;
    u8 f2C6;
    u8 f2C7;
    u8 f2C8;
} S_0069FD88;

extern void func_L39_0067F100(s32);
extern void func_L39_0068AAB8(S_0069FD88 *);
extern char *func_00381FF0(s32);
extern s32 func_00120048(char *, char *, ...);
extern void func_L39_0068A4A8(S_0069FD88 *, s32, s32, u32, f32, f32, f32, f32);
extern char D_00248508[];

void func_L39_0069FD88(S_0069FD88 *a0) {
    char buf[64];
    s32 i;

    func_L39_0067F100(0x320000);
    func_L39_0068AAB8(a0);
    for (i = 0; i < 8; i++) {
        a0->w[i]->vt->f40(a0->w[i], 1);
        a0->w[i]->vt->f44(a0->w[i], 1, 0.435f, 0.0f);
        a0->w[i]->vt->f1C(a0->w[i], 1, 0);
    }
    if (a0->f2B0 == 1) {
        a0->w[0]->vt->f24(a0->w[0], func_00381FF0(0x10E2));
        if (a0->f2BC == 0) {
            a0->w[7]->vt->f24(a0->w[7], func_00381FF0(0x166C));
        } else if (a0->f2BC == 1) {
            a0->w[7]->vt->f24(a0->w[7], func_00381FF0(0x166E));
        } else {
            func_00120048(buf, func_00381FF0(0x166D), a0->f2BC);
            a0->w[7]->vt->f24(a0->w[7], buf);
        }
        if (a0->f2C0 == 0) {
            a0->w[0]->vt->f24(a0->w[0], func_00381FF0(0x1670));
        } else {
            a0->w[0]->vt->f24(a0->w[0], func_00381FF0(0x166F));
        }
        func_L39_0068A4A8(a0, 0, 7, 0x332299DE, 0.502f, 0.2706f, 0.05859998f, 0.45499998f);
    } else if (a0->f2B0 == 0) {
        a0->w[0]->vt->f24(a0->w[0], func_00381FF0(0x1024));
        a0->w[7]->vt->f1C(a0->w[7], 0, 0);
        if (a0->f2C0 == 0) {
            a0->w[0]->vt->f24(a0->w[0], func_00381FF0(0x185A));
        } else {
            a0->w[0]->vt->f24(a0->w[0], func_00381FF0(0x185B));
        }
        func_L39_0068A4A8(a0, 0, 6, 0x332299DE, 0.502f, 0.2706f, 0.05859998f, 0.45499998f);
    } else {
        if (a0->f2C4 != 0) {
            a0->w[0]->vt->f24(a0->w[0], func_00381FF0(0x162A));
        } else {
            a0->w[0]->vt->f24(a0->w[0], func_00381FF0(0x1026));
        }
        a0->w[3]->vt->f1C(a0->w[3], 0, 0);
        if (a0->f2B8 == 0) {
            a0->w[7]->vt->f24(a0->w[7], func_00381FF0(0x168C));
        } else {
            func_00120048(buf, func_00381FF0(0x168D), a0->f2B8);
            a0->w[7]->vt->f24(a0->w[7], buf);
        }
        func_L39_0068A4A8(a0, 0, 7, 0x332299DE, 0.502f, 0.2706f, 0.05859998f, 0.45499998f);
    }
    if (a0->f2A8 == 0) {
        a0->w[1]->vt->f24(a0->w[1], func_00381FF0(0x1672));
    } else {
        func_00120048(buf, func_00381FF0(0x1671), a0->f2A8);
        a0->w[1]->vt->f24(a0->w[1], buf);
    }
    if (a0->f2B4 != 0) {
        a0->w[5]->vt->f24(a0->w[5], func_00381FF0(0x1673));
    } else {
        a0->w[5]->vt->f24(a0->w[5], func_00381FF0(0x1674));
    }
    if (a0->f2C6 != 0) {
        a0->w[3]->vt->f24(a0->w[3], func_00381FF0(0x1933));
    } else {
        a0->w[3]->vt->f24(a0->w[3], func_00381FF0(0x1934));
    }
    if (a0->f2C5 != 0) {
        a0->w[2]->vt->f24(a0->w[2], func_00381FF0(0x192F));
    } else {
        a0->w[2]->vt->f24(a0->w[2], func_00381FF0(0x1930));
    }
    if (a0->f2C7 != 0) {
        a0->w[4]->vt->f24(a0->w[4], func_00381FF0(0x1931));
    } else {
        a0->w[4]->vt->f24(a0->w[4], func_00381FF0(0x1932));
    }
    if (a0->f2C8 != 0) {
        a0->w[6]->vt->f24(a0->w[6], func_00381FF0(0x1935));
    } else {
        a0->w[6]->vt->f24(a0->w[6], D_00248508);
    }
    for (i = 0; i < 8; i++) {
        if (a0->f2AC[i] != 0) {
            a0->w[i + 8]->vt->f50(a0->w[i + 8], 0x706EC8FF);
        } else {
            a0->w[i + 8]->vt->f50(a0->w[i + 8], 0x80404040);
        }
    }
}
/* localdecomp:end func_L39_0069FD88 */
