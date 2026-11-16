/* NTSC-U draft (Claude wave K): C of func_L39_006009C8, the NTSC-U twin of func_L39_006030C8, with NTSC-U names and addresses (the two versions' code differs).
 * near miss on NTSC-U, no count recorded (NTSC-U twin "func_L39_006009C8", whose code is not the PAL one).
 * Worker's note: Full decode (352 B, held by bigbeno37 for PAL): `col = (t0 != -1) ? t0 : 0x78`; func_00120048(base + idx*0x230 + 0x4668, func_0037DF98(id), a3); n = *D_L39_002412A0; if (n >= 2) { w = (f32)(s32)(255/A[0]*A[n-1]); h = (f32)(s32)(135/B[0]*B[n-1]); flag = 0 } ...
 */
#include "common.h"

#include "vu0.h"

/* localdecomp:start func_L39_006009C8 */
typedef struct {
    u8 pad[0x230];
} E_6009C8;

__asm__(".extern D_L39_002412A0, 16");
extern s32 *D_L39_002412A0;
extern f32 D_L39_002412C0[];
extern f32 D_L39_002412D0[];
extern s32 func_0037DF98(s32);
extern void func_00120048(u8 *, s32, s32);
extern void func_L39_005FFE38(u8 *, s32, f32, f32, s32);

void func_L39_006009C8(u8 *b, s32 idx, s32 id, s32 a3, s32 t0) {
    s32 col = 0x78;
    s32 flag = 1;
    s32 n;
    f32 w = 255.0f;
    f32 h = 135.0f;
    u8 *base = b;

    if (t0 != -1) {
        col = t0;
    }
    func_00120048((u8 *)&((E_6009C8 *)base)[idx] + 0x4668, func_0037DF98(id), a3);
    n = *D_L39_002412A0;
    if (n >= 2) {
        w = (f32)(s32)(w / D_L39_002412C0[0] * D_L39_002412C0[n - 1]);
        h = (f32)(s32)(h / D_L39_002412D0[0] * D_L39_002412D0[n - 1]);
        flag = 0;
    }
    func_L39_005FFE38(base + (0x45E0 + idx * 0x230), flag, w, h, col);
}
/* localdecomp:end func_L39_006009C8 */
