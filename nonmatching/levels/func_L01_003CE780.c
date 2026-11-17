/* NTSC-U draft (2026-11-14, Codex worker): C of func_L01_003CCE70, the NTSC-U twin of func_L01_003CE780, with NTSC-U names
 * and addresses. Near miss on NTSC-U: 2 words differ with its file's flags.
 */
#include "common.h"
/* localdecomp:start func_L01_003CCE70 */
typedef int W76Quad __attribute__((mode(TI)));
extern u8 *func_003BCFB0(int,int);
extern void func_L01_00441FB8(void *,int,int);
extern float func_003887A0(void *);
extern float func_00388A28(float,float);
extern void func_00388BD0(void *,void *);
extern float D_001DF218_sda;
extern int D_001DF230_sda;
__asm__(".extern D_001DF218_sda,4");
__asm__(".extern D_001DF230_sda,4");
u8 *func_L01_003CCE70(void *parent,void *position,u8 *direction,int kind,int other,float scale) {
    u8 *m,*d;
    float speed; int color;
    m=func_003BCFB0(0x1B62,0x80);
    if(m) {
        *(void **)(m+0xB8)=parent;
        *(u16 *)(m+0x34)|=1;
        m[0x31]=0;
        d=*(u8 **)(m+0x68);
        m[0x30]=255;
        func_L01_00441FB8(m,1,-1);
        *(W76Quad *)(m+0x10)=*(W76Quad *)position;
        *(float *)(m+0xF4)=-func_00388A28(func_003887A0(direction),*(float *)(direction+8));
        *(float *)(m+0xF8)=func_00388A28(*(float *)direction,*(float *)(direction+4));
        func_00388BD0(m+0xC0,m+0xF0);
        *(W76Quad *)d=*(W76Quad *)direction;
        speed=D_001DF218_sda;
        *(float *)(d+0x14)=scale;
        color=D_001DF230_sda;
        *(float *)(d+0x20)=speed;
        *(int *)(d+0x1C)=color;
        *(float *)(d+0x24)=1.0f;
        *(int *)(d+0x18)=600;
        *(int *)(d+0x28)=kind;
        *(int *)(d+0x2C)=other;
    }
    return m;
}
/* localdecomp:end func_L01_003CCE70 */
