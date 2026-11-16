/* NTSC-U draft (Codex wave 4): C of func_L01_00310948, the NTSC-U twin of func_L01_00310C38, with NTSC-U names and addresses.
 * near miss: 40 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L01_00310948").
 * Worker's note: 40 diff reproduced: dli 0x8000000040 expands as li 0x80; dsll32 rather than ori 0x8000; dsll 24, and li.s 0.025f becomes lit4 load instead of inline lui/ori/mtc1, shifting tail by two words; assigned flags have no @ps2as and no flags_alt; sister ...
 */
#include "common.h"

/* localdecomp:start func_L01_00310948 */
void func_L01_00310948(char *pos, int color, int alpha, char *texture_id, int blend_mode,
                                        char *direction, float size, float roll)
{
    extern void func_L01_003106A8(char *pkt);
    extern long func_00384EC0(char *p);
    extern float func_00388A28(float x, float y);
    extern float func_003887A0(char *p);
    extern void func_00388BF0(float *matrix, float *quat);
    extern void func_00388830(float *off, char *src, float scale);
    extern void func_L01_00310730(char *pkt, float angle);
    extern void func_003CD830(char *pkt, float *matrix, int mode);
    char packet[144];
    float matrix[16];
    float rotation[4];
    float offset[4];
    long texture_reg;

    func_L01_003106A8(packet);
    texture_reg = func_00384EC0(texture_id);

    *(int *)(packet + 76) = color + (alpha << 24);
    *(int *)(packet + 72) = color + (alpha << 24);
    *(int *)(packet + 68) = color + (alpha << 24);
    *(int *)(packet + 64) = color + (alpha << 24);
    *(long *)(packet + 112) = 0L;
    *(long *)(packet + 120) = texture_reg;
    *(long *)(packet + 128) = 280993940374112L;
    *(long *)(packet + 136) = ((long)blend_mode << 2) | 0x8000000040L;

    rotation[3] = 0.0f;
    rotation[2] = func_00388A28(*(float *)(direction + 0), *(float *)(direction + 4));
    rotation[1] = -func_00388A28(func_003887A0(direction), *(float *)(direction + 8));
    rotation[0] = roll;

    func_00388BF0(matrix, rotation);
    func_00388830(offset, direction, 0.025f);

    matrix[12] = *(float *)(pos + 0) + offset[0];
    matrix[13] = *(float *)(pos + 4) + offset[1];
    matrix[14] = *(float *)(pos + 8) + offset[2];
    matrix[15] = 1.0f;

    func_L01_00310730(packet, size);
    func_003CD830(packet, matrix, 0);
}
/* localdecomp:end func_L01_00310948 */
