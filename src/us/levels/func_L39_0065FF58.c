#include "common.h"

/* NTSC-U counterpart of func_L39_00662830 (src/levels/shared/L39_00662678.c) */
extern u8 D_001A5E50[];
extern s32 D_L39_0024D85C;

/* localdecomp:start func_L39_0065FF58 */
typedef struct S_00662830G { u8 pad0[4]; s32 f4; u8 pad8[0x120]; s32 f128; u8 pad12C[0x44]; s32 f170; u8 pad174[0x660]; u8 b7D4; } S_00662830G;
typedef struct N_00662830 { u8 pad0[0x4C]; s32 f4C; s32 f50; u8 pad54; u8 b55; u8 pad56[2]; struct N_00662830 *next; } N_00662830;
extern N_00662830 *D_001DAAE4_sda_0065FF58;
extern u8 D_001A5E50[];
__asm__(".extern D_L39_0024D85C, 16");
extern s32 D_L39_0024D85C;
__asm__(".extern D_L39_00240758, 16");
extern s32 D_L39_00240758;
extern u32 func_L39_006602F0(u32 *);
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);

void func_L39_0065FF58(void) {
    N_00662830 *n = D_001DAAE4_sda_0065FF58;
    while (n != 0) {
        if (n->b55 != 0 && ((S_00662830G *)D_001A5E50)->f128 >= n->f4C) {
            if (n->f50 != D_L39_0024D85C && ((S_00662830G *)D_001A5E50)->f170 == 0) {
                s32 a = ((S_00662830G *)D_001A5E50)->b7D4 | 0x40;
                func_0014AD08(a, ((S_00662830G *)D_001A5E50)->f4, n->f50, D_L39_00240758, func_L39_006602F0((u32 *)n), n);
            }
            n->b55 = 0;
        }
        n = n->next;
    }
}
/* localdecomp:end func_L39_0065FF58 */
