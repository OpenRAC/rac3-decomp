#include "common.h"

/* NTSC-U counterpart of func_003BFD60 (frontbin). */
typedef struct { u8 pad[0x34]; u16 h34; u8 pad2[0x2E]; void *x64; u8 pad3[0x42]; s16 hAA; } S_3BA368;
extern void func_U_003BA850(S_3BA368 *p);

/* localdecomp:start func_U_003BA850 */
/* US draft of func_U_003BA850 (rac3-uya-decomp func_003C0010, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


__asm__(".extern D_U_001D8E94_003BA850, 4");
__asm__(".extern D_U_001D8E98_003BA850, 4");
__asm__(".extern D_U_001D8E9C_003BA850, 4");
__asm__(".extern D_U_001D8EA0_003BA850, 4");
extern u8 *D_U_001DA39C_003BFD60_003BFD60[2];
extern u8 D_U_0037C0B0_003BA850[];
typedef struct { u8 p[0x1C]; f32 f1C; } S_3BA850_003BFD60;
extern u8 D_U_001DA398_003BA850[8];
extern f32 D_U_001D8E94_003BA850;
extern s32 D_U_001D8E98_003BA850;
extern f32 D_U_001D8E9C_003BA850;
extern f32 D_U_001D8EA0_003BA850;
extern u8 *func_U_003BA5B8_003BA850(u8 *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
void func_U_003BA850(S_3BA368 *a) {
    s32 i;
    u8 **p = D_U_001DA39C_003BFD60_003BFD60;
    u8 *e = D_U_0037C0B0_003BA850;
    u8 *r;
    for (i = 5; i >= 0; i--) {
        if (*p == 0) {
            r = func_U_003BA5B8_003BA850(e, (s32)a, D_U_001D8E98_003BA850, 0, 0, -1, 0, -1, 0, 0, D_U_001D8E9C_003BA850 * 210000.0f, D_U_001D8EA0_003BA850, 1.0f);
            *p = r;
            if (r != 0) r[3] = 0x44;
        }
        e += 0x10;
        p++;
    }
    { S_3BA850_003BFD60 *q = (S_3BA850_003BFD60 *)D_U_001DA398_003BA850; q->f1C = D_U_001D8E94_003BA850 * 0.0166666675f; }
}
/* localdecomp:end func_U_003BA850 */
