#include "common.h"

INCLUDE_ASM("asm/levels", func_L06_0034A2B8);

INCLUDE_ASM("asm/levels", func_L06_0034A538);

INCLUDE_ASM("asm/levels", func_L06_0034A6C8);

INCLUDE_ASM("asm/levels", func_L06_0034A7A8);

INCLUDE_ASM("asm/levels", func_L06_0034F670);

INCLUDE_ASM("asm/levels", func_L06_0034F9B8);

INCLUDE_ASM("asm/levels", func_L06_0034FCC8);

/* localdecomp:start func_L06_0034FDA8 */
typedef struct {
    char pad0[0x10];
    char pos[0x31 - 0x10];
    u8 unk31;
    char pad32[0x68 - 0x32];
    char *vars;
    char pad6C[0x6F - 0x6C];
    u8 state;
    char pad70[0x96 - 0x70];
    u16 timer;
} Moby;

extern char D_L06_001E1700[];
extern void func_0038CAD0(void *);
extern void func_0038CB00(void *);
extern void func_L01_00451DF8(Moby *, void *, s32, s32, f32);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(Moby *);

void func_L06_0034FDA8(Moby *m) {
    char *v = m->vars;

    func_0038CAD0(v + 2256);
    func_0038CB00(v + 2260);
    if (m->timer < 0xFFFF) {
        m->timer++;
    }
    func_L01_00451DF8(m, v + 576, 10, 1, 2.5f);
    if (m->unk31 != 0 && func_L01_0040E548(D_L06_001E1700, m->pos) < 576.0f) {
        func_L01_004472C0(m);
        m->state = 22;
    }
}
/* localdecomp:end func_L06_0034FDA8 */

/* localdecomp:start func_L06_0034FE60 */
extern u16 *D_L06_0021B860[];
extern u8 *D_L06_001DED9C;
__asm__(".extern D_L06_001DED9C, 16");
extern s32 D_L06_001DEDD8;

void func_L06_0034FE60(u8 *a0) {
    u16 *p;
    u8 *e;
    u8 *s;
    if (a0[0x21] == 0xFF) return;
    p = D_L06_0021B860[a0[0x21]];
    while (a0[0x21] != 0xFF && a0[0x21] <= D_L06_001DEDD8 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L06_0021B860[a0[0x21]])) {
        e = D_L06_001DED9C + ((*p & 0x7FFF) << 8);
        if (e == 0) break;
        if (*(s16 *)(e + 0xAA) == *(s16 *)(a0 + 0xAA)) {
            s = *(u8 **)(e + 0x68);
            if (s != 0) *(s32 *)(s + 0x8D8) = 1;
        }
        if (*(s16 *)(e + 0xAA) == 0x1625) {
            s = *(u8 **)(e + 0x68);
            if (s != 0) *(s16 *)(s + 0x3D8) = 1;
        }
        p++;
    }
}
/* localdecomp:end func_L06_0034FE60 */
