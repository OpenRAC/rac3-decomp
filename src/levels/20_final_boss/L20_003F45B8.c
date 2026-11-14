#include "common.h"

typedef struct Vars_3F4A78 {
    u8 pad0[0x10];
    u8 slot[2][0x10];
    u8 pad30[0xA0 - 0x30];
    s32 wA0;
} Vars_3F4A78;

INCLUDE_ASM("asm/levels", func_L20_003F45B8);

INCLUDE_ASM("asm/levels", func_L20_003F47E8);

INCLUDE_ASM("asm/levels", func_L20_003F4918);

/* localdecomp:start func_L20_003F4A78 */
/* PAL port of the NTSC-U match src/us/levels/func_L20_003F2928.c */

extern s32 D_L20_001DF464;
__asm__(".extern D_L20_001DF464, 4");
extern s32 D_L20_001DF468;
__asm__(".extern D_L20_001DF468, 4");
extern s32 D_L20_001DF46C;
__asm__(".extern D_L20_001DF46C, 4");
extern s32 D_L20_001DF470;
__asm__(".extern D_L20_001DF470, 4");
extern s32 D_L20_001DF474;
__asm__(".extern D_L20_001DF474, 4");
extern f32 D_L20_001DF478;
__asm__(".extern D_L20_001DF478, 4");
extern f32 D_L20_001DF47C;
__asm__(".extern D_L20_001DF47C, 4");
extern f32 D_L20_001DF480;
__asm__(".extern D_L20_001DF480, 4");
extern f32 D_L20_001DF484;
__asm__(".extern D_L20_001DF484, 4");
extern f32 D_L20_001DF488;
__asm__(".extern D_L20_001DF488, 4");
extern f32 D_L20_001DF48C;
__asm__(".extern D_L20_001DF48C, 4");
extern s32 D_L20_001DF490;
__asm__(".extern D_L20_001DF490, 4");
extern s32 D_L20_001DF494;
__asm__(".extern D_L20_001DF494, 4");
extern f32 D_L20_001DF498;
__asm__(".extern D_L20_001DF498, 4");
extern f32 D_L20_001DF49C;
__asm__(".extern D_L20_001DF49C, 4");
extern f32 D_L20_001DF4A0;
__asm__(".extern D_L20_001DF4A0, 4");
extern f32 D_L20_001DF4A4;
__asm__(".extern D_L20_001DF4A4, 4");
extern f32 D_L20_001DF4A8;
__asm__(".extern D_L20_001DF4A8, 4");
extern f32 D_L20_001DF4AC;
__asm__(".extern D_L20_001DF4AC, 4");
extern void func_L20_003F43D0(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_00382468(s32);
extern void func_L20_003F4918(void *);
extern void func_L20_003F47E8(void *, s32, s32, s32, void *, f32, f32, f32, f32, f32, f32, f32);
extern s32 func_0038CAD0(void *);
extern void func_003C2880(void *);

void func_L20_003F4A78(void *arg0) {
    u8 *obj = (u8 *)arg0;
    Vars_3F4A78 *vars = *(Vars_3F4A78 **)(obj + 0x68);
    s32 i;
    s32 j;
    f32 k;
    s32 *tm;

    switch (obj[0x20]) {
    case 0:
        func_L20_003F43D0(obj);
        func_L01_004450F0(obj, 1, -1);
        vars->wA0 = (D_L20_001DF464 * 5 + 2) / 6;
        break;
    case 1:
        i = 0;
        tm = &vars->wA0;
        for (; i < 2; i++) {
            if (i <= 0) {
                if (func_00382468(D_L20_001DF46C) == 0) {
                    func_L20_003F4918(vars->slot[i]);
                }
            }
            if (func_00382468(D_L20_001DF470) == 0) {
                func_L20_003F47E8(vars->slot[i], D_L20_001DF474, 2, 3, vars, D_L20_001DF478, D_L20_001DF47C, D_L20_001DF480, 2.0f, D_L20_001DF484, D_L20_001DF488, D_L20_001DF48C);
            }
        }
        if (func_0038CAD0(tm) != 0) {
            func_L01_004450F0(obj, 2, -1);
            vars->wA0 = (D_L20_001DF468 * 5 + 2) / 6;
        }
        break;
    case 2:
        k = 0.75f;
        tm = &vars->wA0;
        for (j = 1; j >= 0; j--) {
            if (func_00382468(D_L20_001DF490) == 0) {
                if (func_00382468(2) != 0) {
                    func_L20_003F47E8(obj + 0x10, D_L20_001DF494, 2, 3, vars, D_L20_001DF498, D_L20_001DF49C, D_L20_001DF4A0, 0.25f, D_L20_001DF4A4, D_L20_001DF4A8, D_L20_001DF4AC);
                } else {
                    func_L20_003F47E8(obj + 0x10, D_L20_001DF494, 2, 3, vars, D_L20_001DF498, D_L20_001DF49C, D_L20_001DF4A0, 0.5f, D_L20_001DF4A4 * k, D_L20_001DF4A8, D_L20_001DF4AC);
                }
            }
        }
        if (func_0038CAD0(tm) != 0) {
            func_L01_004450F0(obj, 4, -1);
        }
        break;
    case 3:
        break;
    case 4:
        func_003C2880(obj);
        break;
    }
}
/* localdecomp:end func_L20_003F4A78 */

INCLUDE_ASM("asm/levels", func_L20_003F4CC8);

INCLUDE_ASM("asm/levels", func_L20_003F4E60);

INCLUDE_ASM("asm/levels", func_L20_003F51F8);
