#include "common.h"

/* localdecomp:start func_L39_006AF7A8 */
__asm__(".extern D_L39_0024D760, 16");
extern u8 *D_L39_0024D760;
extern void func_L39_006DCAD0(s32, s32);

/* from rac4-decomp's func_L00_00708980 */
void func_L39_006AF7A8(void) {
    func_L39_006DCAD0(*(s32 *)(D_L39_0024D760 + 0x50), 0);
}
/* localdecomp:end func_L39_006AF7A8 */

/* localdecomp:start func_L39_006AF7D0 */
__asm__(".extern D_L39_0024D760, 16");
extern u8 *D_L39_0024D760;
extern s32 func_L39_006DE180(s32);
extern s32 func_L01_003A4720(s32);

void func_L39_006AF7D0(void) {
    func_L39_006DE180(*(s32 *)(D_L39_0024D760 + 0x54));
    func_L01_003A4720(*(s32 *)(D_L39_0024D760 + 0x30));
}
/* localdecomp:end func_L39_006AF7D0 */

LINKER_REMNANT("asm/levels", func_L39_006AF808);

INCLUDE_ASM("asm/levels", func_L39_006AF810);

LINKER_REMNANT("asm/levels", func_L39_006AFF40);

/* localdecomp:start func_L39_006AFF48 */
extern u8 D_L39_0047DFA0[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_006AFF48(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047DFA0;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_006AFF48 */

INCLUDE_ASM("asm/levels", func_L39_006AFF70);

/* localdecomp:start func_L39_006B03B8 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_006B03B8(void *);

extern void func_L39_0067F168();
void func_L39_006B03B8(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_006B03B8 */

/* localdecomp:start func_L39_006B03E8 */
extern f32 D_001DD5B0_sda;
extern f32 D_001DD5B4_sda;
extern f32 D_001DD5B8_sda;
extern f32 D_001DD5BC_sda;
extern f32 D_001DD5C0_sda;
extern f32 D_001DD60C_sda;
extern f32 D_001DD610_sda;
extern f32 D_001DD614_sda;
extern f32 D_001DD618_sda;
extern f32 D_001DD61C_sda;
extern f32 D_001DD620_sda;
extern f32 D_001DD62C_sda;
extern f32 D_001DD630_sda;
extern f32 D_001DD634_sda;
extern f32 D_001DD638_sda;
extern f32 D_001DD63C_sda;
extern f32 D_001DD640_sda;
extern f32 D_001DD644_sda;
extern f32 D_001DD648_sda;
extern f32 D_001DD64C_sda;
extern f32 D_001DD650_sda;
extern f32 D_001DD654_sda;
extern f32 D_001DD658_sda;
extern f32 D_001DD65C_sda;
extern f32 D_001DD660_sda;
extern f32 D_001DD664_sda;
extern f32 D_001DD668_sda;
extern f32 D_001DD66C_sda;
extern f32 D_001DD670_sda;
extern f32 D_001DD674_sda;
extern f32 D_001DD678_sda;
extern f32 D_001DD67C_sda;
extern f32 D_001DD680_sda;
extern f32 D_001DD684_sda;
extern f32 D_001DD688_sda;
extern f32 D_001DD68C_sda;
extern f32 D_001DD690_sda;
extern f32 D_001DD694_sda;
extern f32 D_001DD698_sda;
extern f32 D_001DD69C_sda;
extern f32 D_001DD6A0_sda;
extern s32 *D_L39_00241120;
__asm__(".extern D_L39_00241120, 16");
extern u8 *D_L39_00241640;
__asm__(".extern D_L39_00241640, 16");
extern void func_L39_0068A8F8(s32, s32, f32, f32, f32, f32, f32);
extern void func_L39_0068A7B8(void *, s32, s32, f32, f32, f32, f32);
extern void func_L39_0068A4A8(void *, s32, s32, f32, f32, f32, f32, u32);
extern void func_L39_00689A70(void);
extern s32 func_00195530(s32);
extern s32 func_00195810(void);
extern void func_L39_0059A578(s32, s32);
extern s32 func_L39_0068AEF8(void *, s32);
extern void func_L39_00689F00(void *, s32, s32, s32, f32, f32, f32, f32, f32, f32);

typedef struct G_006B03E8 {
    u8 pad0[0x14];
    s32 x14;
    u8 pad18[0x12C - 0x18];
    s32 x12C;
    u8 pad130[0x148 - 0x130];
    s32 x148;
    u8 pad14C[0x170 - 0x14C];
    s32 x170;
    s32 x174;
    u8 pad178[0x6AD - 0x178];
    u8 x6AD;
} G_006B03E8;
extern G_006B03E8 D_001A5CD0;

typedef struct O_006B03E8 {
    u8 pad[0x60];
    void **vt;
} O_006B03E8;

typedef struct T_006B03E8 {
    u8 pad[0xC0];
    s16 c0[8];
    s16 d0[8];
} T_006B03E8;

typedef struct S_006B03E8 {
    u8 pad[0x11C];
    O_006B03E8 *a[4];
    O_006B03E8 *b[4];
} S_006B03E8;

typedef struct V_006B03E8 {
    u8 pad[0x110];
    O_006B03E8 *f110[(0x290 - 0x110) / 4];
    s32 f290;
} V_006B03E8;

s32 func_L39_006B03E8(u8 *self, s32 arg1) {
    f32 pos[2];
    O_006B03E8 *o;
    s32 i;
    S_006B03E8 *me = (S_006B03E8 *)self;

    if (*D_L39_00241120 < 3) {
    func_L39_0068A8F8(0, 0x332299DE, D_001DD62C_sda, D_001DD630_sda, D_001DD634_sda, D_001DD638_sda, D_001DD63C_sda);
    func_L39_0068A8F8(1, 0x332299DE, D_001DD640_sda, D_001DD644_sda, D_001DD648_sda, D_001DD64C_sda, D_001DD650_sda);
    } else {
    func_L39_0068A8F8(0, 0x332299DE, D_001DD654_sda, D_001DD658_sda, D_001DD65C_sda, D_001DD660_sda, D_001DD664_sda);
    func_L39_0068A8F8(1, 0x332299DE, D_001DD668_sda, D_001DD66C_sda, D_001DD670_sda, D_001DD674_sda, D_001DD678_sda);
    func_L39_0068A8F8(2, 0x332299DE, D_001DD67C_sda, D_001DD680_sda, D_001DD684_sda, D_001DD688_sda, D_001DD68C_sda);
    func_L39_0068A8F8(3, 0x332299DE, D_001DD690_sda, D_001DD694_sda, D_001DD698_sda, D_001DD69C_sda, D_001DD6A0_sda);
    }
    func_L39_0068A7B8(self, 2, 0x331465B7, D_001DD5B0_sda, D_001DD5B4_sda, D_001DD5B8_sda, D_001DD5BC_sda);
    func_L39_0068A4A8(self, 0, 1, D_001DD5B0_sda, D_001DD5C0_sda, 0.0f, D_001DD5BC_sda, 0x332299DE);
    if (arg1 == 7 && ((V_006B03E8 *)self)->f290 == 2) {
        o = (O_006B03E8 *)self;
        ((void (*)(void *))o->vt[0xF0 / 4])(self);
        func_L39_00689A70();
        D_001A5CD0.x170 = 1;
        D_001A5CD0.x174 = 1;
        D_001A5CD0.x148 = 0;
        D_001A5CD0.x6AD = 0;
        D_001A5CD0.x12C = 1;
        func_00195530(0);
        func_00195810();
        for (i = 0; i < *D_L39_00241120; i++) {
            o = me->b[i];
            ((T_006B03E8 *)D_L39_00241640)->c0[i] = ((s32 (*)(void *))o->vt[0x8C / 4])(o);
            o = me->a[i];
            ((T_006B03E8 *)D_L39_00241640)->d0[i] = ((s32 (*)(void *))o->vt[0x8C / 4])(o);
        }
        arg1 = D_001A5CD0.x14;
        if (*D_L39_00241120 >= 2 && arg1 <= 0x2D) {
            arg1 += 10;
        }
        func_L39_0059A578(arg1, 0);
        return 1;
    }
    if (func_L39_0068AEF8(self, arg1) == 1) {
        return 1;
    }
    o = ((V_006B03E8 *)self)->f110[((V_006B03E8 *)self)->f290];
    ((void (*)(void *, f32 *, f32 *))o->vt[0x30 / 4])(o, &pos[0], &pos[1]);
    func_L39_00689F00(self, 0, 3, 3, D_001DD60C_sda + pos[0], D_001DD610_sda + pos[1], D_001DD614_sda, D_001DD618_sda, D_001DD61C_sda, D_001DD620_sda);
    return 0;
}
/* localdecomp:end func_L39_006B03E8 */
