#include "common.h"

/* localdecomp:start func_L39_006AB098 */
typedef struct O_006AB098 O_006AB098;
typedef struct V_006AB098 {
    u8 pad0[0x20];
    void (*f20)(O_006AB098 *, s32, s32);
    void (*f24)(O_006AB098 *, u8 *);
} V_006AB098;
struct O_006AB098 {
    u8 pad0[0x60];
    V_006AB098 *vt;
};
typedef struct S_006AB098 {
    u8 pad0[0x118];
    O_006AB098 *keys[45];
    O_006AB098 *f1CC;
    O_006AB098 *f1D0;
    O_006AB098 *f1D4;
    O_006AB098 *f1D8;
    O_006AB098 *f1DC;
    O_006AB098 *f1E0;
    O_006AB098 *f1E4;
    u8 pad1E8[0x2B0 - 0x1E8];
    s32 f2B0;
} S_006AB098;
extern s16 D_L39_004B0688[45][5];
extern u8 D_L39_002489D8[];
extern u8 D_L39_002489E0[];
extern u8 D_L39_002489E8[];
extern u8 D_L39_002489F0[];
extern u8 D_L39_002489F8[];
extern u8 D_L39_00248A00[];
extern u8 D_L39_00248A08[];
extern void func_0011D534(void *, s32, s32);
extern s32 func_00120048(u8 *, u8 *, ...);
extern u8 *func_00381FF0(s32);
extern s32 func_L39_006A8FB0(s16);

void func_L39_006AB098(void *arg0) {
    S_006AB098 *self = arg0;
    u8 buf[0x20];
    s32 i;
    O_006AB098 *o;

    ((void *(*)(void *, s32, s32))func_0011D534)(buf, 0, 0x20);
    for (i = 0; i < 45; i++) {
        s32 c = func_L39_006A8FB0(D_L39_004B0688[i][self->f2B0]);
        if (c & 0x8000) {
            buf[1] = c;
            buf[0] = c >> 8;
            buf[2] = 0;
        } else {
            buf[0] = c;
            buf[1] = 0;
        }
        o = self->keys[i];
        o->vt->f24(o, buf);
    }
    func_00120048(buf, D_L39_002489D8, func_00381FF0(0x11C2));
    o = self->f1D4;
    o->vt->f24(o, buf);
    func_00120048(buf, D_L39_002489E0, func_00381FF0(0x1396));
    o = self->f1DC;
    o->vt->f24(o, buf);
    func_00120048(buf, D_L39_002489E8, func_00381FF0(0x11C3));
    o = self->f1D0;
    o->vt->f24(o, buf);
    func_00120048(buf, D_L39_002489F0, func_00381FF0(0x11C4));
    o = self->f1CC;
    o->vt->f24(o, buf);
    func_00120048(buf, D_L39_002489F8, func_00381FF0(0x1397));
    o = self->f1D8;
    o->vt->f24(o, buf);
    func_00120048(buf, D_L39_00248A00, func_00381FF0(0x1398));
    o = self->f1E0;
    o->vt->f24(o, buf);
    o = self->f1E0;
    o->vt->f20(o, 0, 0);
    func_00120048(buf, D_L39_002489F0, D_L39_00248A08);
    o = self->f1E4;
    o->vt->f24(o, buf);
    o = self->f1E4;
    o->vt->f20(o, 0, 0);
}
/* localdecomp:end func_L39_006AB098 */
