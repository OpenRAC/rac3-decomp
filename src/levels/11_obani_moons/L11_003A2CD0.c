#include "common.h"

typedef struct {
    char pad0[0x10];
    char pos[0x31 - 0x10];
    u8 unk31;
    char pad32[0x68 - 0x32];
    s32 vars;
    char pad6C[0x6F - 0x6C];
    u8 state;
    char pad70[0x96 - 0x70];
    u16 timer;
} Moby_003A46C8;

INCLUDE_ASM("asm/levels", func_L11_003A2CD0);

INCLUDE_ASM("asm/levels", func_L11_003A2DB0);

INCLUDE_ASM("asm/levels", func_L11_003A40B8);

INCLUDE_ASM("asm/levels", func_L11_003A41E0);

INCLUDE_ASM("asm/levels", func_L11_003A4410);

INCLUDE_ASM("asm/levels", func_L11_003A45D0);

/* localdecomp:start func_L11_003A46C8 */
extern u8 D_L11_001E1780[];
extern void func_0038CAD0(s32);
extern void func_0038CB00(s32);
extern void func_L11_003A40B8(void);
extern void func_L01_00404808(void (*)(void), void *);
extern void func_L01_00451DF8(void *, void *, s32, s32, f32);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);

void func_L11_003A46C8(Moby_003A46C8 *m) {
    s32 temp_s1;
    u16 temp_v1;

    temp_s1 = m->vars;
    func_0038CAD0(temp_s1 + 0x2D0);
    func_0038CB00(temp_s1 + 0x2D4);
    temp_v1 = m->timer;
    if (temp_v1 <= 0xFFFEU) {
        m->timer = (u16) (temp_v1 + 1);
    }
    func_L01_00404808(func_L11_003A40B8, m);
    func_L01_00451DF8(m, (u8 *)temp_s1 + 0x240, 2, 1, 2.5f);
    if (m->unk31 != 0 && func_L01_0040E548(D_L11_001E1780, &m->pos) < 1024.0f) {
        func_L01_004472C0(m);
        m->state = 30;
    }
}
/* localdecomp:end func_L11_003A46C8 */
