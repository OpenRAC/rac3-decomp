#include "common.h"

typedef int s128 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x28];
    s32 w28;
} S_311A18m;
typedef struct {
    u8 pad0[0x10];
    s128 q10;
    u8 b20;
    u8 pad21[0x68 - 0x21];
    S_311A18m *p68;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
} S_311A18;


/* localdecomp:start func_L01_00310A20 */
extern void func_0038CE20(f32 *, f32 *, f32);
void func_L01_00310A20(f32 *m, f32 s) {
    func_0038CE20(m, m, s);
    func_0038CE20(m + 4, m + 4, s);
    func_0038CE20(m + 8, m + 8, s);
    func_0038CE20(m + 12, m + 12, s);
}
/* localdecomp:end func_L01_00310A20 */

INCLUDE_ASM("asm/levels", func_L01_00310A88);

/* localdecomp:start func_L01_00310C38 */
extern void func_L01_00310998(char *pkt);
extern void func_L01_00310A20(f32 *, f32);
extern long func_00389598(char *p);
extern float func_0038D160(float x, float y);
extern float func_0038CED8(char *p);
extern void func_0038D328(float *matrix, float *quat);
extern void func_0038CF68(float *off, char *src, float scale);
extern void func_003D2DA0(char *pkt, float *matrix, int mode);

void func_L01_00310C38(char *pos, int color, int alpha, char *texture_id, int blend_mode,
                       char *direction, float size, float roll) {
    char packet[144];
    float matrix[16];
    float rotation[4];
    float offset[4];
    long texture_reg;

    func_L01_00310998(packet);
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
    func_0038CF68(offset, direction, 0.025f);

    matrix[12] = *(float *)(pos + 0) + offset[0];
    matrix[13] = *(float *)(pos + 4) + offset[1];
    matrix[14] = *(float *)(pos + 8) + offset[2];
    matrix[15] = 1.0f;

    func_L01_00310A20((f32 *)packet, size);
    func_003D2DA0(packet, matrix, 0);
}
/* localdecomp:end func_L01_00310C38 */

INCLUDE_ASM("asm/levels", func_L01_00310DB8);
