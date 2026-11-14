/* NTSC-U draft (2026-11-14, Claude worker): C of func_L09_003BD098, the NTSC-U twin of func_L09_003BE910, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/09_tyhrranosis/L09_003B8580.c's line: "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L09_003BE910 (src/levels/09_tyhrranosis/L09_003B8580.c). MATCH with the PAL file's flags
   (-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division) plus @ps2as (lui/ori/mtc1 float literals). */

/* localdecomp:start func_L09_003BD098 */
extern u8 *D_L09_001E011C;
typedef struct { u8 p0[0xD0]; f32 pos[3]; } H_3BD098;
extern H_3BD098 D_001A4BE0;
extern s32 func_003883C8(void *);
extern void func_003BDA38(void *, s32, void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_00388800(void *, void *);
extern void func_0037E4B8(void *, f32, f32, f32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L01_003CB388(f32, void *, void *, void *, u8);

void func_L09_003BD098(u8 *a0, s32 a1, f32 *a2) {
    u8 *vars = *(u8 **)(a0 + 0x68);
    u8 *obj = D_L09_001E011C + (*(s32 *)(vars + 0xCD0) << 8);
    s32 i;
    s32 flag;
    vu0_v4 v0;
    vu0_v4 v10;
    vu0_v4 v20;
    f32 yaw;

    if (func_003883C8(vars + 0xD36) != 0) {
        for (i = 0; a1 ? i < 2 : i < 1; i++) {
            func_003BDA38(obj, i == 0 ? 9 : 0xD, &v0);
            func_003BDA38(obj, i == 0 ? 0xA : 0xE, &v10);
            if (a2 == 0) {
                if (a1 != 0) {
                    yaw = func_00389380(func_00388A28(v10.x - v0.x, v10.y - v0.y), i == 0 ? -0.43633232f : 0.43633232f);
                } else {
                    yaw = func_00388A28(v10.x - v0.x, v10.y - v0.y);
                }
            } else {
                yaw = func_00388A28(a2[0] - v0.x, a2[1] - v0.y);
            }
            func_0037E4B8(&v20, 1.0f, yaw, func_00388A28(func_00388800(&v10, D_001A4BE0.pos), D_001A4BE0.pos[2] - v10.z));
            if (*(s16 *)(vars + 0xD5A) == -1) {
                *(s16 *)(vars + 0xD5A) = func_0039FE80(0, 4, obj);
            }
            flag = a2 != 0;
            func_L01_003CB388((f32)vars[0x46], a0, &v10, &v20, flag);
        }
        *(s16 *)(vars + 0xD36) = 3;
    }
}
/* localdecomp:end func_L09_003BD098 */
