#include "common.h"

/* NTSC-U counterpart of func_L01_004708C8 (src/levels/shared/L01_004708C8.c): 0.0004 -> 0.000277778 */
typedef int Quad_4708C8 __attribute__((mode(TI)));
typedef struct {
    Quad_4708C8 vector;
    int type, value;
    short count, extra;
    float duration;
} Sub_4708C8;
typedef struct {
    u8 b0, b1, b2, b3;
    int type;
    u8 random, flags;
    short count;
    float duration;
    Quad_4708C8 position;
    Sub_4708C8 sub;
} Effect_4708C8;
extern Effect_4708C8 *func_L01_0045E438(int);
extern int func_0013D3E0(void);
extern u8 *D_L01_00221284[];
__asm__(".extern D_L01_00221284, 16");

/* localdecomp:start func_L01_0046D1D0 */
Effect_4708C8 *func_L01_0046D1D0(Quad_4708C8 *pos, Quad_4708C8 *vec, int type, int value,
                                 int count, int extra, int index, int color, int frame,
                                 float duration, float scale)
{
    Effect_4708C8 *effect;
    Sub_4708C8 *sub;

    if (!count) {
        return 0;
    }
    effect = func_L01_0045E438(0x5b);
    if (effect) {
        effect->position = *pos;
        *(float *)((char *)&effect->position + 12) = (float)frame;
        effect->type = type;
        effect->flags = 0xa4;
        if (color != -1) {
            effect->b3 = color;
        } else {
            effect->b3 = 0x48;
        }
        effect->b1 = 0;
        effect->duration = duration;
        effect->random = func_0013D3E0();
        if (index == -1) {
            effect->b2 = D_L01_00221284[0][0];
        } else {
            effect->b2 = D_L01_00221284[0][index];
        }
        effect->count = count;
        sub = &effect->sub;
        sub->count = count;
        sub->duration = duration;
        sub->type = type;
        sub->value = value;
        sub->extra = extra;
        sub->vector = *vec;
        *(float *)((char *)&sub->vector + 12) = scale * 0.000277777785f;
    }
    return effect;
}
/* localdecomp:end func_L01_0046D1D0 */
