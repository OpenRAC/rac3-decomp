#include "common.h"

INCLUDE_ASM("asm/levels", func_L18_00350FB0);

INCLUDE_ASM("asm/levels", func_L18_00351068);

INCLUDE_ASM("asm/levels", func_L18_00351298);

/* localdecomp:start func_L18_003514B8 */
typedef int u128_t __attribute__((mode(TI)));
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
void func_L18_003514B8(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 104);
    *(u128_t *)(s + 752) = *(u128_t *)(s + 960);
    func_0038CE90(s + 736, s + 752, s + 720);
    func_0038CF68(s + 736, s + 736, 1.0f);
    func_0038CE90(s + 720, s + 736, s + 752);
    *(s32 *)(s + 732) = 0;
    *(s32 *)(s + 748) = 0;
    *(s32 *)(s + 764) = 0;
}
/* localdecomp:end func_L18_003514B8 */

INCLUDE_ASM("asm/levels", func_L18_00351548);

INCLUDE_ASM("asm/levels", func_L18_00351908);

INCLUDE_ASM("asm/levels", func_L18_00352288);

INCLUDE_ASM("asm/levels", func_L18_00352350);

INCLUDE_ASM("asm/levels", func_L18_00352AF8);

INCLUDE_ASM("asm/levels", func_L18_00352D30);

INCLUDE_ASM("asm/levels", func_L18_00353110);

INCLUDE_ASM("asm/levels", func_L18_00353138);

INCLUDE_ASM("asm/levels", func_L18_00353280);

INCLUDE_ASM("asm/levels", func_L18_00353658);

/* localdecomp:start func_L18_003537D8 */
s32 func_L18_003537D8(u8 *obj) {
    return obj[149] == 5;
}
/* localdecomp:end func_L18_003537D8 */

INCLUDE_ASM("asm/levels", func_L18_003537E8);

INCLUDE_ASM("asm/levels", func_L18_00353870);

INCLUDE_ASM("asm/levels", func_L18_00353F58);

/* localdecomp:start func_L18_00354198 */
typedef struct {
    void (*fn0)(void *);
} Iface;

typedef struct {
    char pad0[0x30];
    f32 unk30;
    char pad34[0x80 - 0x34];
    s32 unk80;
} Vars;

typedef struct {
    char pad0[0x68];
    Vars *vars;
    char pad6C[0x96 - 0x6C];
    s16 unk96;
} Moby;

extern Moby *D_001A65C0[];
extern s32 D_001D545C;
extern void func_L18_00351068(Moby *);
extern void func_L01_003F1F20(s32, s32);
extern Iface *func_L01_0043B548(s32, s32);

void func_L18_00354198(Moby *m, s32 arg1) {
    Vars *v = m->vars;

    if (D_001A65C0[0] == m) {
        if (v->unk30 > 0.0f || D_001D545C == 20) {
            func_L18_00351068(m);
        }
        func_L01_003F1F20(28, 0);
    }
    if (v->unk80 != 0) {
        if (arg1 == 0) {
            func_L01_0043B548(6625, 108)->fn0(m);
        }
    } else {
        m->unk96 = 0;
    }
}
/* localdecomp:end func_L18_00354198 */

INCLUDE_ASM("asm/levels", func_L18_00354250);

INCLUDE_ASM("asm/levels", func_L18_003543C8);

INCLUDE_ASM("asm/levels", func_L18_003545D0);

INCLUDE_ASM("asm/levels", func_L18_00354C60);
