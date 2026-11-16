/* PAL near miss (Codex wave 10): near miss: does not compile in its file's context yet (declaration conflicts; the worker's note at the top has the details).
 * Worker's note: Ordinary wrapper blocked by exact S_00369D80 typedef declared only after target in owner (.01.log); no incompatible prototype/alias workaround. Full real C compiles with declaration-only contract: 298 positional diff (.contract01diff.log); ...
 */
#include "common.h"
/* localdecomp:start func_L01_00369700 */
#include "vu0.h"
typedef struct { u8 pad0; u8 kind; u8 pad2[0xEE]; } Row_00369700;
typedef struct { u8 pad0[0x1A4]; u8 *table; } Table_00369700;
extern s32 D_L01_001E1D10;
extern u16 D_001A8BB0;
extern u8 D_001425C0[];
extern Row_00369700 D_L01_002C5600[];
extern s128 D_L01_001DD7F0[] __attribute__((section(".sdata")));
extern f32 D_L01_001DD7F4;
extern s32 D_L01_001D6694;
extern u8 *D_001D52FC;
extern s128 D_L01_001E29E0[1] __attribute__((section(".sdata")));
extern Table_00369700 D_L01_00221098;
extern u8 D_L01_001D66B0[] __attribute__((section(".sdata")));
void func_L01_00369700(u8 *moby) {
    extern void func_L01_004CB2D8(u8 *);
    extern void func_L01_0041A5B0(s32, s32);
    extern void func_L01_005003D0(s32, s32);
    extern void func_0038D000(void *, void *, void *);
    extern s32 func_0038CAD0(void *);
    extern void func_L01_00444F38(u8 *, s32, s32, s32, s32);
    extern s32 func_L01_005118D0(s32, s32);
    extern void func_003A52A0(s32, s32, u8 *);
    extern void func_L01_004EA7D8(s32);
    extern void func_003C3A10(u8 *, s32, s32, s32);
    extern void func_L01_00369D80(S_00369D80 *, void *, void *);
    extern void func_L01_00369E28(u8 *, void *, void *);
    extern void func_L01_004EAA80(void);
    extern s32 func_L01_005119E0(s32);
    extern s32 func_00382498(s32, s32);
    extern u8 *func_L01_004713C8(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
    extern void func_L01_004C7D98(void *, void *);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_0013D3E0(void);
    extern void func_L01_00466F50(void *, void *, s32, f32, f32);
    s128 pos;
    s128 direction;
    u8 *vars = *(u8 **)(moby + 0x68);
    u8 *hero;
    func_L01_004CB2D8(moby);
    if (moby[0x20] == 0) {
        *(s32 *)vars = 0;
        moby[0x20] = 1;
        *(s32 *)(vars + 12) = 0;
        D_L01_001E1D10 = 1;
        *(s32 *)(vars + 24) = 25;
    }
    if (D_001A8BB0 == 0 && ((Row_00369700 *)(D_001425C0[0x37] * 0xF0 + (s32)D_L01_002C5600))->kind == 0) func_L01_0041A5B0(0x1517, 0x122);
    if (*(s32 *)((u8 *)&D_001A4BE0 + 0x25C4) == 1) func_L01_005003D0(29, 1);
    func_0038D000(&pos, D_L01_001DD7F0, moby + 0xC0);
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(pos) : "m"(pos), "m"(*(vu0_v4 *)(moby + 0x10)) : "vf1", "vf2");
    if (((Row_00369700 *)(D_001425C0[0x37] * 0xF0 + (s32)D_L01_002C5600))->kind >= 3) *(s16 *)(moby + 0x7C) = 7;
    if (((Row_00369700 *)(D_001425C0[0x37] * 0xF0 + (s32)D_L01_002C5600))->kind == 2) *(s16 *)(moby + 0x7C) = 3;
    else if (((Row_00369700 *)(D_001425C0[0x37] * 0xF0 + (s32)D_L01_002C5600))->kind == 1) *(s16 *)(moby + 0x7C) = 1;
    D_L01_001DD7F4 = ((Row_00369700 *)(D_001425C0[0x37] * 0xF0 + (s32)D_L01_002C5600))->kind == 0 ? -0.75f : -0.8199999928474426f;
    func_0038CAD0(vars);
    if (moby[0x42] == moby[0x43] && (moby[0x60] & 2)) func_L01_00444F38(moby, 1, 0, 2, 0);
    hero = (u8 *)&D_001A4BE0;
    if (D_L01_001D6694 == 0 && hero[0x25ED] == 0 &&
        ((*(s32 *)(D_001D52FC + 0x1A4) & *(s32 *)(hero + 0x1210)) ||
         ((*(s32 *)(D_001D52FC + 0x1A0) & 8) && *(s32 *)(hero + 0x25C4) == 29)) &&
        *(s32 *)(hero + 0x1220) >= 19) {
        if (*(s32 *)vars == 0) {
            if (func_L01_005118D0(-1, 1)) {
                func_003A52A0(0, 0, moby);
                D_L01_001E1D10 = 1;
                func_L01_004EA7D8(-1);
                func_003C3A10(moby, 2, 0, 0);
                *(s32 *)vars = 37;
                if (*(s16 *)(hero + 0x2874)) func_0038CE20(&direction, (s128 *)(moby + 0xD0), -1.0f);
                else if (*(s32 *)(hero + 0x25C4) == 29 || *(s32 *)(hero + 0x16B0) != 0) direction = D_L01_001E29E0[0];
                else direction = *(s128 *)(*(u8 **)(hero + 0x25C0) + 0xC0);
                func_L01_00369D80((S_00369D80 *)moby, &pos, &direction);
                func_L01_00369E28(moby, &pos, &direction);
            } else {
                if ((*(s32 *)(D_001D52FC + 0x1A4) & *(s32 *)(hero + 0x1210)) || D_L01_001E1D10 == 1) {
                    func_003A52A0(2, 0, moby);
                    D_L01_001E1D10 = 0;
                }
                func_L01_004EAA80();
            }
        }
    } else func_L01_004EAA80();
    hero = (u8 *)&D_001A4BE0;
    if (hero[0x25ED] == 0 && *(s32 *)(hero + 0x1220) >= 19 && func_L01_005119E0(-1)) {
        s32 i;
        for (i = 0; i >= 0; i--) {
            s32 life = (func_00382498(10, 20) * 5 + 2) / 6;
            u8 *particle = func_L01_004713C8(&pos, D_L01_001D66B0, life, 0x5A182, func_00382498(1, 4), 0x30, 0, 0, 63000.00390625f, 31500.001953125f, 0.000800000037997961f);
            if (particle) particle[2] = *D_L01_00221098.table;
        }
        func_L01_004C7D98(hero + 0x80, &direction);
        func_0038CF68(&direction, &direction, func_003824E0(0.004999999888241291f, 0.014999999664723873f));
        ((f32 *)&pos)[0] += func_003824E0(-0.07500000298023224f, 0.07500000298023224f);
        ((f32 *)&pos)[1] += func_003824E0(-0.07500000298023224f, 0.07500000298023224f);
        ((f32 *)&pos)[2] += func_003824E0(-0.07500000298023224f, 0.07500000298023224f);
        if (func_0013D3E0() % 12 == 0) func_L01_00466F50(&pos, &direction, 0x4005A182, -1.0f, 0.0f);
    }
}
/* localdecomp:end func_L01_00369700 */
