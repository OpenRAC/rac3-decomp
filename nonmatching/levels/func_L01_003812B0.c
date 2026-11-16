/* PAL near miss (Codex wave 8): near miss: 67 words differ with the file's flags.
 * Worker's note: 68 diff: third-best.log; three matrix/load wordings leave same residual; initial dli expansion, RGB branch/registers and matrix setup scheduling; type contract compiles third-contract.log
 */
#include "common.h"
/* localdecomp:start func_L01_003812B0 */
#include "structs/weapon.h"
typedef int Q_003812B0 __attribute__((mode(TI)));
typedef struct {
    Q_003812B0 vertex[4];
    u32 colour[4];
    f32 uv[8];
    long flags, texture, primitive, blend;
} Draw_003812B0;
extern u8 D_0014264F __attribute__((section(".data")));
extern struct WeaponRow D_L01_002C5600[];
extern s32 D_L01_001DDC34, D_L01_001DDC30;
extern u8 D_L01_001E1E80[] __attribute__((section(".sdata")));
extern f32 D_L01_001E1E70[], D_L01_001E1E50[];
extern Q_003812B0 D_L01_001E1E10[], D_L01_001E1DE0[];
extern Q_003812B0 D_001A4EC0;
extern Q_003812B0 D_L01_001DDC80[] __attribute__((section(".sdata")));
void func_L01_003812B0(void) {
    extern long func_00389598(s32);
    extern void func_0038CE20(Q_003812B0 *, Q_003812B0 *, f32);
    extern void func_0038CE90(Q_003812B0 *, Q_003812B0 *, Q_003812B0 *);
    extern void func_0038CF68(Q_003812B0 *, Q_003812B0 *, f32);
    extern void func_0038D028(Q_003812B0 *, Q_003812B0 *, Q_003812B0 *);
    extern void func_003D2DA0(Draw_003812B0 *, s32, s32);
    Draw_003812B0 draw;
    Q_003812B0 matrix[4];
    Q_003812B0 temp;
    s32 rgb;
    s32 i;
    draw.texture = func_00389598(8);
    draw.flags = 0;
    draw.blend = (0x8000L << 24) | 0x48;
    draw.primitive = 0xFF9000000260L;
    draw.uv[0] = 0; draw.uv[1] = 0; draw.uv[2] = 0; draw.uv[3] = 1;
    draw.uv[4] = 1; draw.uv[5] = 0; draw.uv[6] = 1; draw.uv[7] = 1;
    rgb = (D_L01_002C5600[D_0014264F].level < 4 ? D_L01_001DDC30 : D_L01_001DDC34) & 0xFFFFFF;
    for (i=0; i<3; ) {
        s32 next = i + 1;
        if (D_L01_001E1E80[i]) {
            u32 colour;
            s32 j;
            Q_003812B0 *src;
            Q_003812B0 *dst;
            colour = (s32)D_L01_001E1E50[i];
            { Q_003812B0 dir = D_L01_001E1E10[i];
              Q_003812B0 pos = D_L01_001E1DE0[i];
              matrix[0] = dir; matrix[3] = pos; }
            colour = rgb | (colour << 24);
            draw.colour[0] = colour; draw.colour[3] = colour;
            draw.colour[2] = colour; draw.colour[1] = colour;
            func_0038CE20(&matrix[2], &D_001A4EC0, -1.0f);
            func_0038CE90(&matrix[1], &matrix[0], &matrix[2]);
            func_0038CF68(&matrix[1], &matrix[1], 1.0f);
            func_0038CE90(&matrix[2], &matrix[1], &matrix[0]);
            src = D_L01_001DDC80;
            dst = draw.vertex;
            for (j=3; j>=0; j--) {
                func_0038CE20(&temp, src++, D_L01_001E1E70[i]);
                func_0038D028(dst++, &temp, matrix);
            }
            func_003D2DA0(&draw, 0, 0);
        }
        i = next;

    }
}
/* localdecomp:end func_L01_003812B0 */
