#include "common.h"

/* NTSC-U counterpart of func_L03_00396FF0 (src/levels/03_starship_phoenix/L03_003967C8.c): 0.00251327 -> 0.00174533; 0.125664 -> 0.10472 */
/* localdecomp:start func_L03_00395978 */
typedef struct { u8 b[0x100]; } E_00396FF0;
typedef struct { u8 pad0[0x140]; s32 idx; } S_00396FF0;
typedef struct { u8 pad0[0x10]; f32 pos[4]; u8 pad1[0x11]; u8 on; u8 pad2[0x35]; S_00396FF0 *p; u8 pad3[0x8c]; f32 f; } A_00396FF0;
extern E_00396FF0 *D_L03_001DFA1C;
extern E_00396FF0 *D_001DFA1C_sda;
__asm__(".extern D_001DFA1C_sda, 4");
extern u8 D_L03_001E2540[];
extern void func_003C2F58(void *, s32, void *);
extern void func_L01_00445758(void *, void *, s32, f32, f32, f32, f32);
extern f32 func_L01_0040C018(void *, void *);
extern void func_L01_00444188(void *);
void func_L03_00395978(void *arg) {
    A_00396FF0 *a = arg;
    S_00396FF0 *p = a->p;
    func_003C2F58(a, 0, D_L03_001DFA1C[p->idx].b + 0x10);
    func_L01_00445758(D_L03_001DFA1C[p->idx].b + 0xF8, (u8 *)p + 0x144, 0, a->f, 0.00174532935f, 0.00174532935f, 0.104719765f);
    if (a->on) {
        if (func_L01_0040C018(D_L03_001E2540, a->pos) < 576.0f) {
            func_L01_00444188(a);
            ((u8 *)a)[0x6F] = 0x16;
        }
    }
    {
        E_00396FF0 *e;
        if (D_L03_001DFA1C[p->idx].b[0x31]) {
            e = D_L03_001DFA1C + p->idx;
            if (func_L01_0040C018(D_L03_001E2540, e->b + 0x10) < 576.0f) {
                func_L01_00444188(D_001DFA1C_sda[p->idx].b);
                D_L03_001DFA1C[p->idx].b[0x6F] = 0x16;
            }
        }
    }
}
/* localdecomp:end func_L03_00395978 */
