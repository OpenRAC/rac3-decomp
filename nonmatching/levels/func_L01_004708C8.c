/* NTSC-U draft (Codex wave 3): C of func_L01_0046D1D0, the NTSC-U twin of func_L01_004708C8, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 27 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L01_0046D1D0", whose code is not the PAL one).
 * Worker's note: 27 diff verified once; entire instruction body exact except incoming stack offset; residual sd/ld 8-byte saves and frame 0x60 vs retail sq/lq 16-byte saves and frame 0xb0; documented sq_ra class Matching-Patterns:331-335,886; permitted -fopt-stack fixes save ...
 */
#include "common.h"
/* localdecomp:start func_L01_0046D1D0 */
typedef int Quad_46D1D0 __attribute__((mode(TI)));
typedef struct {
    Quad_46D1D0 vector;
    int type, value;
    short count, extra;
    float duration;
} Sub_46D1D0;
typedef struct {
    u8 b0, b1, b2, b3;
    int type;
    u8 random, flags;
    short count;
    float duration;
    Quad_46D1D0 position;
    Sub_46D1D0 sub;
} Effect_46D1D0;
extern Effect_46D1D0 *func_L01_0045E438(int);
extern int func_0013D3E0(void);
extern u8 *D_L01_00221284[];
__asm__(".extern D_L01_00221284, 16");
Effect_46D1D0 *func_L01_0046D1D0(Quad_46D1D0 *pos, Quad_46D1D0 *vec, int type, int value,
                                  int count, int extra, int index, int color, int frame,
                                  float duration, float scale) {
    Effect_46D1D0 *effect;
    Sub_46D1D0 *sub;
    if (!count) return 0;
    effect=func_L01_0045E438(0x5b);
    if(effect) {
        effect->position=*pos;
        *(float *)((char *)&effect->position+12)=(float)frame;
        effect->type=type;
        effect->flags=0xa4;
        if(color!=-1) effect->b3=color;
        else effect->b3=0x48;
        effect->b1=0;
        effect->duration=duration;
        effect->random=func_0013D3E0();
        if(index==-1) effect->b2=D_L01_00221284[0][0];
        else effect->b2=D_L01_00221284[0][index];
        effect->count=count;
        sub=&effect->sub;
        sub->count=count;
        sub->duration=duration;
        sub->type=type;
        sub->value=value;
        sub->extra=extra;
        sub->vector=*vec;
        *(float *)((char *)&sub->vector+12)=scale*0.00027777778450399637f;
    }
    return effect;
}
/* localdecomp:end func_L01_0046D1D0 */
