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

INCLUDE_ASM("asm/levels", func_L06_0034FE60);
