#include "common.h"

/* NTSC-U counterpart of func_L39_005287B0 (src/levels/shared/L39_00524E00.c): 0.002 -> 0.00166667; 0.02 -> 0.0166667; 25 -> 30; 47 -> 57; 250 -> 300 */
/* localdecomp:start func_L39_00528298 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_005287B0;
typedef struct { u8 pad0[0x10]; V_005287B0 pos; } O_005287B0;
typedef struct { u8 pad0[0x140]; f32 x; f32 y; } T_005287B0;
extern s32 D_L39_0024D5E0_b;
extern T_005287B0 D_L39_0024DDC0;
__asm__(".extern D_L39_0024AB80, 4");
extern f32 D_L39_0024AB80;
__asm__(".extern D_L39_0024AB84, 4");
extern f32 D_L39_0024AB84;
extern f32 func_L39_005B2510(f32, f32);
extern f32 func_L39_005B25C8_00528298(void);
extern f32 func_L39_005B2568(f32, f32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern s32 func_L39_005B24C8(s32, s32);
extern void func_L39_005C6980(void *, void *, s32, s32, s32, f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_L39_005D04C0(void *, void *, s32);
extern void func_L39_005285D8(s32);
extern void func_003BD360(void *);
void func_L39_00528298(O_005287B0 *o) {
    V_005287B0 v0;
    V_005287B0 v1;
    s32 i;
    f32 a, b, c;
    f32 ang, spd, dir, s;

    for (i = 0; i < 0x21 - D_L39_0024D5E0_b; i++) {
        a = func_L39_005B2510(0.0f, 0.37f);
        b = func_L39_005B25C8_00528298();
        c = func_L39_005B25C8_00528298();
        func_0037E4B8(&v1, a, b, c);
        v1.z += func_L39_005B2510(0.35f, 0.6f);
        vec_add_ba(&v1, &v1, &o->pos);
        a = func_L39_005B2510(0.00166666682f, 0.0166666675f);
        b = func_L39_005B25C8_00528298();
        c = func_L39_005B25C8_00528298();
        func_0037E4B8(&v0, a, b, c);
        func_L39_005C6980(&v1, &v0, 0x4F20507F, 0x102F, func_L39_005B24C8(0x1E, 0x39), 150000.0f);
    }
    for (i = 0; i < 0x32 - D_L39_0024D5E0_b; i++) {
        ang = func_00388A28(D_L39_0024DDC0.x - o->pos.x, D_L39_0024DDC0.y - o->pos.y);
        func_L39_005B2568(1.0f, 2.0f);
        v0.x = o->pos.x + func_L39_005B2568(0.0f, 0.15f);
        v0.y = o->pos.y + func_L39_005B2568(0.0f, 0.15f);
        v0.z = o->pos.z + func_L39_005B2568(0.0f, 0.15f);
        s = D_L39_0024AB80;
        spd = s * 0.0166666675f;
        dir = func_00389380(ang, func_L39_005B2568(0.0f, -1.5707964f));
        v1.x = func_00388960(dir) * spd;
        v1.y = func_00388978(dir) * spd;
        s = D_L39_0024AB84;
        v1.z = s * 0.0166666675f;
        func_L39_005D04C0(&v0, &v1, 0x12C);
    }
    func_L39_005285D8((s32)o);
    func_003BD360(o);
}
/* localdecomp:end func_L39_00528298 */
