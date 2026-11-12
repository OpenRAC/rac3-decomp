/* near miss (level 11, Obani Moons): 13 differences, measured with the file's flags plus -mvu0-use-vf0-vf2 (vec_add_ab needs it; the file's three C functions still match with it): in the two copies of a table entry's position into v + 0x100, retail loads the table pointer (lui/lw) before the index and keeps index, pointer and quadword in $v0/$a0/$v1; the C loads the index first ($v1/$a0/$v0). Everything else matches, including the $gp loads of the same pointers in branch delay slots. Tried typed entries, u8 arithmetic, TImode copies, a local table pointer and an unsized alias for the second reads */
#include "common.h"

/* localdecomp:start func_L11_00350EE0 */
#include "vu0.h"
typedef int q_350EE0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_350EE0;
typedef struct { u8 pad0[0x10]; V4_350EE0 pos; u8 pad20[0xE0]; } E_350EE0;
typedef struct { u8 pad0[0x30]; V4_350EE0 pos; u8 pad40[0x40]; } N_350EE0;
extern E_350EE0 *D_L11_001DEE1C;
extern N_350EE0 *D_L11_001DEF00;
extern u8 *D_001D52FC;
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D160(f32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00404808(void *, void *);
extern void func_L11_003510D0(u8 *);
extern void func_L11_003514D8(void);
extern s32 func_L01_00456250(void *);
extern s32 func_L01_004606E8(s32, s32, s32, s32);
extern void func_L01_00456230(void *, s32);

void func_L11_00350EE0(u8 *a0)
{
    u8 *v = *(u8 **)(a0 + 0x68);
    s32 i, j;

    if (a0[0x20] == 0) {
        i = *(s32 *)(v + 0x118);
        if (i == -1) {
            j = *(s32 *)(v + 0x11C);
            if (j == -1) {
                *(f32 *)(v + 0x100) = func_0038D098(*(f32 *)(a0 + 0xF8)) * 100.0f;
                *(f32 *)(v + 0x104) = func_0038D0B0(*(f32 *)(a0 + 0xF8)) * 100.0f;
                *(s32 *)(v + 0x108) = 0;
                vec_add_ab(v + 0x100, v + 0x100, a0 + 0x10);
            } else {
                *(f32 *)(a0 + 0xF8) = func_0038D160(D_L11_001DEE1C[j].pos.x - *(f32 *)(a0 + 0x10), D_L11_001DEE1C[j].pos.y - *(f32 *)(a0 + 0x14));
                *(V4_350EE0 *)(v + 0x100) = D_L11_001DEE1C[*(s32 *)(v + 0x11C)].pos;
            }
        } else {
            *(f32 *)(a0 + 0xF8) = func_0038D160(D_L11_001DEF00[i].pos.x - *(f32 *)(a0 + 0x10), D_L11_001DEF00[i].pos.y - *(f32 *)(a0 + 0x14));
            *(V4_350EE0 *)(v + 0x100) = D_L11_001DEF00[*(s32 *)(v + 0x118)].pos;
        }
        func_L01_004450F0(a0, 1, -1);
        return;
    }
    if (*(s32 *)(v + 0x114) != 0) {
        func_L01_00404808(func_L11_003510D0, a0);
        if (*(s32 *)(D_001D52FC + 0x1B0) & 0x20) {
            func_L01_00404808(func_L11_003514D8, a0);
        }
        return;
    }
    if (func_L01_00456250(a0) != 0 || (func_L01_004606E8(1, 0x32, 0, 0) != 0 && func_L01_004606E8(2, 0x32, 0, 0) != 0)) {
        *(s32 *)(v + 0x114) = 1;
        if (*(s32 *)(v + 0x120) != -1) {
            func_L01_00456230(&D_L11_001DEE1C[*(s32 *)(v + 0x120)], 1);
        }
    }
}
/* localdecomp:end func_L11_00350EE0 */
