#include "common.h"

/* NTSC-U counterpart of func_L39_006B03E8 (src/levels/39_multiplayer_menu/L39_006AF7A8.c) */
extern f32 D_001DD5F4_sda;
extern f32 D_001DD5F8_sda;
extern f32 D_001DD5FC_sda;
extern f32 D_001DD600_sda;
extern f32 D_001DD604_sda;
extern f32 D_001DD608_sda;
extern f32 D_001DD60C_sda_006ADA98;
extern f32 D_001DD610_sda_006ADA98;
extern f32 D_001DD614_sda_006ADA98;
extern f32 D_001DD618_sda_006ADA98;
extern f32 D_001DD61C_sda_006ADA98;
extern f32 D_001DD620_sda_006ADA98;
extern f32 D_001DD624_sda_006ADA98;
extern f32 D_001DD628_sda;
extern f32 D_001DD62C_sda_006ADA98;
extern f32 D_001DD630_sda_006ADA98;
extern f32 D_001DD634_sda_006ADA98;
extern f32 D_001DD638_sda_006ADA98;
extern f32 D_001DD63C_sda_006ADA98;
extern f32 D_001DD640_sda_006ADA98;
extern f32 D_001DD644_sda_006ADA98;
extern f32 D_001DD648_sda_006ADA98;
extern f32 D_001DD64C_sda_006ADA98;
extern f32 D_001DD650_sda_006ADA98;
extern f32 D_001DD654_sda_006ADA98;
extern f32 D_001DD658_sda_006ADA98;
extern f32 D_001DD65C_sda_006ADA98;
extern f32 D_001DD660_sda_006ADA98;
extern f32 D_001DD664_sda_006ADA98;
extern f32 D_001DD668_sda_006ADA98;
extern s32 *D_L39_002412A0;
extern void func_L39_00687D50(s32, s32, f32, f32, f32, f32, f32);

/* localdecomp:start func_L39_006ADA98 */
extern f32 D_001DD578_sda;
extern f32 D_001DD57C_sda;
extern f32 D_001DD580_sda;
extern f32 D_001DD584_sda_006ADA98;
extern f32 D_001DD588_sda_006ADA98;
extern f32 D_001DD5D4_sda;
extern f32 D_001DD5D8_sda_006ADA98;
extern f32 D_001DD5DC_sda;
extern f32 D_001DD5E0_sda;
extern f32 D_001DD5E4_sda;
extern f32 D_001DD5E8_sda;
extern f32 D_001DD5F4_sda;
extern f32 D_001DD5F8_sda;
extern f32 D_001DD5FC_sda;
extern f32 D_001DD600_sda;
extern f32 D_001DD604_sda;
extern f32 D_001DD608_sda;
extern f32 D_001DD60C_sda_006ADA98;
extern f32 D_001DD610_sda_006ADA98;
extern f32 D_001DD614_sda_006ADA98;
extern f32 D_001DD618_sda_006ADA98;
extern f32 D_001DD61C_sda_006ADA98;
extern f32 D_001DD620_sda_006ADA98;
extern f32 D_001DD624_sda_006ADA98;
extern f32 D_001DD628_sda;
extern f32 D_001DD62C_sda_006ADA98;
extern f32 D_001DD630_sda_006ADA98;
extern f32 D_001DD634_sda_006ADA98;
extern f32 D_001DD638_sda_006ADA98;
extern f32 D_001DD63C_sda_006ADA98;
extern f32 D_001DD640_sda_006ADA98;
extern f32 D_001DD644_sda_006ADA98;
extern f32 D_001DD648_sda_006ADA98;
extern f32 D_001DD64C_sda_006ADA98;
extern f32 D_001DD650_sda_006ADA98;
extern f32 D_001DD654_sda_006ADA98;
extern f32 D_001DD658_sda_006ADA98;
extern f32 D_001DD65C_sda_006ADA98;
extern f32 D_001DD660_sda_006ADA98;
extern f32 D_001DD664_sda_006ADA98;
extern f32 D_001DD668_sda_006ADA98;
extern s32 *D_L39_002412A0;
__asm__(".extern D_L39_002412A0, 16");
extern u8 *D_L39_002417C0;
__asm__(".extern D_L39_002417C0, 16");
extern void func_L39_00687D50(s32, s32, f32, f32, f32, f32, f32);
extern void func_L39_00687C10(void *, s32, s32, f32, f32, f32, f32);
extern void func_L39_00687900(void *, s32, s32, f32, f32, f32, f32, u32);
extern void func_L39_00686EC8(void);
extern s32 func_00195620(s32);
extern s32 func_00195900(void);
extern void func_L39_005992A8(s32, s32);
extern s32 func_L39_00688350(void *, s32);
extern void func_L39_00687358(void *, s32, s32, s32, f32, f32, f32, f32, f32, f32);

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
extern G_006B03E8 D_001A5E50;

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

s32 func_L39_006ADA98(u8 *self, s32 arg1) {
    f32 pos[2];
    O_006B03E8 *o;
    s32 i;
    S_006B03E8 *me = (S_006B03E8 *)self;

    if (*D_L39_002412A0 < 3) {
    func_L39_00687D50(0, 0x332299DE, D_001DD5F4_sda, D_001DD5F8_sda, D_001DD5FC_sda, D_001DD600_sda, D_001DD604_sda);
    func_L39_00687D50(1, 0x332299DE, D_001DD608_sda, D_001DD60C_sda_006ADA98, D_001DD610_sda_006ADA98, D_001DD614_sda_006ADA98, D_001DD618_sda_006ADA98);
    } else {
    func_L39_00687D50(0, 0x332299DE, D_001DD61C_sda_006ADA98, D_001DD620_sda_006ADA98, D_001DD624_sda_006ADA98, D_001DD628_sda, D_001DD62C_sda_006ADA98);
    func_L39_00687D50(1, 0x332299DE, D_001DD630_sda_006ADA98, D_001DD634_sda_006ADA98, D_001DD638_sda_006ADA98, D_001DD63C_sda_006ADA98, D_001DD640_sda_006ADA98);
    func_L39_00687D50(2, 0x332299DE, D_001DD644_sda_006ADA98, D_001DD648_sda_006ADA98, D_001DD64C_sda_006ADA98, D_001DD650_sda_006ADA98, D_001DD654_sda_006ADA98);
    func_L39_00687D50(3, 0x332299DE, D_001DD658_sda_006ADA98, D_001DD65C_sda_006ADA98, D_001DD660_sda_006ADA98, D_001DD664_sda_006ADA98, D_001DD668_sda_006ADA98);
    }
    func_L39_00687C10(self, 2, 0x331465B7, D_001DD578_sda, D_001DD57C_sda, D_001DD580_sda, D_001DD584_sda_006ADA98);
    func_L39_00687900(self, 0, 1, D_001DD578_sda, D_001DD588_sda_006ADA98, 0.0f, D_001DD584_sda_006ADA98, 0x332299DE);
    if (arg1 == 7 && ((V_006B03E8 *)self)->f290 == 2) {
        o = (O_006B03E8 *)self;
        ((void (*)(void *))o->vt[0xF0 / 4])(self);
        func_L39_00686EC8();
        D_001A5E50.x170 = 1;
        D_001A5E50.x174 = 1;
        D_001A5E50.x148 = 0;
        D_001A5E50.x6AD = 0;
        D_001A5E50.x12C = 1;
        func_00195620(0);
        func_00195900();
        for (i = 0; i < *D_L39_002412A0; i++) {
            o = me->b[i];
            ((T_006B03E8 *)D_L39_002417C0)->c0[i] = ((s32 (*)(void *))o->vt[0x8C / 4])(o);
            o = me->a[i];
            ((T_006B03E8 *)D_L39_002417C0)->d0[i] = ((s32 (*)(void *))o->vt[0x8C / 4])(o);
        }
        arg1 = D_001A5E50.x14;
        if (*D_L39_002412A0 >= 2 && arg1 <= 0x2D) {
            arg1 += 10;
        }
        func_L39_005992A8(arg1, 0);
        return 1;
    }
    if (func_L39_00688350(self, arg1) == 1) {
        return 1;
    }
    o = ((V_006B03E8 *)self)->f110[((V_006B03E8 *)self)->f290];
    ((void (*)(void *, f32 *, f32 *))o->vt[0x30 / 4])(o, &pos[0], &pos[1]);
    func_L39_00687358(self, 0, 3, 3, D_001DD5D4_sda + pos[0], D_001DD5D8_sda_006ADA98 + pos[1], D_001DD5DC_sda, D_001DD5E0_sda, D_001DD5E4_sda, D_001DD5E8_sda);
    return 0;
}
/* localdecomp:end func_L39_006ADA98 */
