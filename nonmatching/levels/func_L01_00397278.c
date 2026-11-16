/* PAL near miss (Codex wave 4): held at landing: the C matches at level 01 but not at levels 04, 05 and 07 (1 word differs at each), so it cannot be the one source of every place.
 * Replaces the earlier draft (Codex wave 8's draft, which does not compile in its file's context).
 */
#include "common.h"
/* localdecomp:start func_L01_00397278 */
/* Ported from rac2-decomp rac2-decomp/src/game/00327038.c:271-307. */
/* Reuse the owner file vector type; move its later definition before this block. */
typedef struct { f32 v[4]; } __attribute__((aligned(16))) Vec4_0039E0C8;


void func_L01_00397278(char *pos, int color, int alpha, char *texture_id, int blend_mode,
                                        char *direction, float size, float roll)
{
    extern void func_L01_00396FD8(u8 *);
    extern long func_00389598(char *);
    extern float func_0038D160(float, float);
    extern float func_0038CED8(char *);
    extern void func_0038D328(float *, float *);
    extern void func_0038CF68(Vec4_0039E0C8 *, Vec4_0039E0C8 *, f32);
    extern void func_L01_00397060(f32 *, f32);
    extern void func_003D2DA0(char *, float *, int);

    char packet[144];
    float matrix[16];
    float rotation[4];
    float offset[4];
    long texture_reg;

    func_L01_00396FD8((u8 *)packet);
    texture_reg = func_00389598(texture_id);

    *(int *)(packet + 76) = color + (alpha << 24);
    *(int *)(packet + 72) = color + (alpha << 24);
    *(int *)(packet + 68) = color + (alpha << 24);
    *(int *)(packet + 64) = color + (alpha << 24);
    *(long *)(packet + 112) = 0L;
    *(long *)(packet + 120) = texture_reg;
    *(long *)(packet + 128) = 280993940374112L;
    *(long *)(packet + 136) = ((long)blend_mode << 2) | 0x8000000040L;

    rotation[3] = 0.0f;
    rotation[2] = func_0038D160(*(float *)(direction + 0), *(float *)(direction + 4));
    rotation[1] = -func_0038D160(func_0038CED8(direction), *(float *)(direction + 8));
    rotation[0] = roll;

    func_0038D328(matrix, rotation);
    func_0038CF68((Vec4_0039E0C8 *)offset, (Vec4_0039E0C8 *)direction, 0.025f);

    matrix[12] = *(float *)(pos + 0) + offset[0];
    matrix[13] = *(float *)(pos + 4) + offset[1];
    matrix[14] = *(float *)(pos + 8) + offset[2];
    matrix[15] = 1.0f;

    func_L01_00397060((f32 *)packet, size);
    func_003D2DA0(packet, matrix, 0);
}
/* localdecomp:end func_L01_00397278 */
