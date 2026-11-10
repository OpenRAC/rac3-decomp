#include "common.h"

/* localdecomp:start func_L39_0069EAA8 */
typedef struct V_0069EAA8 V_0069EAA8;
typedef struct O_0069EAA8 {
    u8 pad[0x60];
    struct { u8 pad[0x24]; void (*fn)(struct O_0069EAA8 *, s32); } *vt;
} O_0069EAA8;

void func_L39_0069EAA8(u8 *self, s32 a, s32 b, s32 c)
{
    O_0069EAA8 *o;
    o = *(O_0069EAA8 **)(self + 0x110);
    o->vt->fn(o, a);
    o = *(O_0069EAA8 **)(self + 0x114);
    o->vt->fn(o, b);
    self[0x2AC] = c;
}
/* localdecomp:end func_L39_0069EAA8 */

LINKER_REMNANT("asm/levels", func_L39_0069EB08);

INCLUDE_ASM("asm/levels", func_L39_0069EB18);

LINKER_REMNANT("asm/levels", func_L39_0069F0F8);

/* localdecomp:start func_L39_0069F100 */
extern u8 D_L39_0047D410[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_0069F100(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047D410;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_0069F100 */

/* localdecomp:start func_L39_0069F128 */
/* Same shape as func_L39_0069E768 (task 4); constants from the $gp slots 0x4B0..0x4C0. */
extern f32 D_001DCD60_sda;
extern f32 D_001DCD64_sda;
extern f32 D_001DCD68_sda;
extern f32 D_001DCD6C_sda;
extern f32 D_001DCD70_sda;
extern void func_L39_00688460(void *a0, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, void *p1, void *p2, void *p3, void *p4, void *p5);

void func_L39_0069F128(void *a0)
{
    s32 v[4];
    func_L39_00688460(a0, D_001DCD60_sda, D_001DCD64_sda, D_001DCD68_sda, D_001DCD6C_sda, D_001DCD70_sda, v, v, v, v, v);
}
/* localdecomp:end func_L39_0069F128 */

/* localdecomp:start func_L39_0069F168 */
typedef struct O_0069F168 O_0069F168;
typedef struct {
    char _p0[0x1C];
    void (*f1C)(O_0069F168 *, s32, s32);
    char _p20[0x4];
    void (*f24)(O_0069F168 *, s32);
    char _p28[0x18];
    void (*f40)(O_0069F168 *, s32);
    void (*f44)(O_0069F168 *, s32, f32, f32);
    char _p48[0x4];
    void (*f4C)(O_0069F168 *, s32, s32);
    void (*f50)(O_0069F168 *, u32);
} VT_0069F168;
struct O_0069F168 {
    char _p0[0x60];
    VT_0069F168 *vt;
};
typedef struct {
    char _p0[0x110];
    O_0069F168 *f110[8];
    O_0069F168 *f130;
    char _p134[0x174];
    u8 f2A8[8];
    s32 f2B0;
} S_0069F168;

extern s32 D_001DCD40_sda;
extern f32 D_001DCD74_sda;
extern f32 D_001DCD78_sda;
extern f32 D_001DCD7C_sda;
extern f32 D_001DCD80_sda;
extern f32 D_001DCD8C_sda;
extern s32 func_L39_0067F100(s32);
extern void func_L39_0068AAB8(void *);
extern void func_L39_0068A4A8(void *, s32, s32, u32, f32, f32, f32, f32);
extern s32 func_00381FF0(s32);

void func_L39_0069F168(S_0069F168 *arg0) {
    O_0069F168 *o;
    VT_0069F168 *vt;
    s32 i;

    func_L39_0067F100(0x320000);
    func_L39_0068AAB8(arg0);
    func_L39_0068A4A8(arg0, 0, 1, 0x332299DE, D_001DCD74_sda,
                      D_001DCD78_sda + ((D_001DCD80_sda - D_001DCD8C_sda) * 0.5f) / 3.0f, 0.0f,
                      D_001DCD7C_sda - D_001DCD8C_sda);
    o = arg0->f130;
    o->vt->f40(o, 0);
    o = arg0->f130;
    o->vt->f44(o, 1, D_001DCD7C_sda - D_001DCD8C_sda * 2.0f, 0.0f);
    o = arg0->f130;
    o->vt->f1C(o, 1, 0);
    vt = arg0->f130->vt;
    vt->f24(arg0->f130, func_00381FF0(D_001DCD40_sda));
    o = arg0->f130;
    o->vt->f4C(o, 0x40, 1);
    for (i = 0; i < 8; i++) {
        if (arg0->f2A8[i]) {
            o = arg0->f110[i];
            o->vt->f50(o, 0x706EC8FF);
        } else {
            o = arg0->f110[i];
            o->vt->f50(o, 0x80404040);
        }
    }
    arg0->f2B0 = 0;
}
/* localdecomp:end func_L39_0069F168 */

/* localdecomp:start func_L39_0069F310 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_0069F310(void *);

extern void func_L39_0067F168();
void func_L39_0069F310(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_0069F310 */

INCLUDE_ASM("asm/levels", func_L39_0069F340);
