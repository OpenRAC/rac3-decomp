#include "common.h"

/* localdecomp:start func_L14_0035F7B8 */
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

extern char D_L14_001E2140[];
extern void func_0038CAD0(void *);
extern void func_L01_00451DF8(Moby *, void *, s32, s32, f32);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(Moby *);

void func_L14_0035F7B8(Moby *m) {
    char *v = m->vars;

    func_0038CAD0(v + 724);
    func_0038CAD0(v + 728);
    if (m->timer < 0xFFFF) {
        m->timer++;
    }
    func_L01_00451DF8(m, v + 576, 1, 1, 2.5f);
    if (m->unk31 != 0 && func_L01_0040E548(D_L14_001E2140, m->pos) < 1024.0f) {
        func_L01_004472C0(m);
        m->state = 30;
    }
}
/* localdecomp:end func_L14_0035F7B8 */
