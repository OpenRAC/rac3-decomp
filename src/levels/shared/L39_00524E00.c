#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00524E00);

INCLUDE_ASM("asm/levels", func_L39_00525030);

INCLUDE_ASM("asm/levels", func_L39_00525690);

INCLUDE_ASM("asm/levels", func_L39_00526280);

INCLUDE_ASM("asm/levels", func_L39_00526340);

INCLUDE_ASM("asm/levels", func_L39_00526FC0);

INCLUDE_ASM("asm/levels", func_L39_00527460);

INCLUDE_ASM("asm/levels", func_L39_00527A38);

INCLUDE_ASM("asm/levels", func_L39_00527C88);

INCLUDE_ASM("asm/levels", func_L39_005285A8);

/* localdecomp:start func_L39_005287B0 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_005287B0;
typedef struct { u8 pad0[0x10]; V_005287B0 pos; } O_005287B0;
typedef struct { u8 pad0[0x140]; f32 x; f32 y; } T_005287B0;
extern s32 D_L39_0024D4E0_b;
extern T_005287B0 D_L39_0024DCC0;
__asm__(".extern D_L39_0024AA70, 4");
extern f32 D_L39_0024AA70;
__asm__(".extern D_L39_0024AA74, 4");
extern f32 D_L39_0024AA74;
extern f32 func_L39_005B4410(f32, f32);
extern f32 func_L39_005B44C8(void);
extern f32 func_L39_005B4468(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern s32 func_L39_005B43C8(s32, s32);
extern void func_L39_005C8CA8(void *, void *, s32, s32, s32, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L39_005D2930(void *, void *, s32);
extern void func_L39_00528AF0(s32);
extern void func_003C2880(void *);
void func_L39_005287B0(O_005287B0 *o) {
    V_005287B0 v0;
    V_005287B0 v1;
    s32 i;
    f32 a, b, c;
    f32 ang, spd, dir, s;

    for (i = 0; i < 0x21 - D_L39_0024D4E0_b; i++) {
        a = func_L39_005B4410(0.0f, 0.37f);
        b = func_L39_005B44C8();
        c = func_L39_005B44C8();
        func_00382760(&v1, a, b, c);
        v1.z += func_L39_005B4410(0.35f, 0.6f);
        vec_add_ba(&v1, &v1, &o->pos);
        a = func_L39_005B4410(0.002f, 0.020000001f);
        b = func_L39_005B44C8();
        c = func_L39_005B44C8();
        func_00382760(&v0, a, b, c);
        func_L39_005C8CA8(&v1, &v0, 0x4F20507F, 0x102F, func_L39_005B43C8(0x19, 0x2F), 150000.0f);
    }
    for (i = 0; i < 0x32 - D_L39_0024D4E0_b; i++) {
        ang = func_0038D160(D_L39_0024DCC0.x - o->pos.x, D_L39_0024DCC0.y - o->pos.y);
        func_L39_005B4468(1.0f, 2.0f);
        v0.x = o->pos.x + func_L39_005B4468(0.0f, 0.15f);
        v0.y = o->pos.y + func_L39_005B4468(0.0f, 0.15f);
        v0.z = o->pos.z + func_L39_005B4468(0.0f, 0.15f);
        s = D_L39_0024AA70;
        spd = s * 0.020000001f;
        dir = func_0038DAB8(ang, func_L39_005B4468(0.0f, -1.5707964f));
        v1.x = func_0038D098(dir) * spd;
        v1.y = func_0038D0B0(dir) * spd;
        s = D_L39_0024AA74;
        v1.z = s * 0.020000001f;
        func_L39_005D2930(&v0, &v1, 0xFA);
    }
    func_L39_00528AF0((s32)o);
    func_003C2880(o);
}
/* localdecomp:end func_L39_005287B0 */
