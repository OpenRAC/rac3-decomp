#include "common.h"
/* localdecomp:start func_L01_003CCE70 */
typedef int W76Quad __attribute__((mode(TI)));
extern u8 *func_003BCFB0(int,int);
extern void func_L01_00441FB8(void *,int,int);
extern float func_003887A0(void *);
extern float func_00388A28(float,float);
extern void func_00388BD0(void *,void *);
extern float D_L01_001DF218;
extern int D_L01_001DF230;
__asm__(".extern D_L01_001DF218,4");
__asm__(".extern D_L01_001DF230,4");
typedef struct { W76Quad q0; int x10; float x14; int x18; int x1c; float x20; float x24; int x28; int x2c; } D_3CE780;
u8 *func_L01_003CCE70(void *parent,void *position,u8 *direction,int kind,int other,float scale) {
    u8 *m;
    D_3CE780 *d;
    float speed; int color;
    m=func_003BCFB0(0x1B62,0x80);
    if(m) {
        *(void **)(m+0xB8)=parent;
        *(u16 *)(m+0x34)|=1;
        m[0x31]=0;
        d=*(D_3CE780 **)(m+0x68);
        m[0x30]=255;
        func_L01_00441FB8(m,1,-1);
        *(W76Quad *)(m+0x10)=*(W76Quad *)position;
        *(float *)(m+0xF4)=-func_00388A28(func_003887A0(direction),*(float *)(direction+8));
        *(float *)(m+0xF8)=func_00388A28(*(float *)direction,*(float *)(direction+4));
        func_00388BD0(m+0xC0,m+0xF0);
        *(W76Quad *)d=*(W76Quad *)direction;
        d->x14=scale;
        speed=D_L01_001DF218;
        color=D_L01_001DF230;
        d->x20=speed;
        d->x1c=color;
        d->x24=1.0f;
        d->x18=600;
        d->x28=kind;
        d->x2c=other;
    }
    return m;
}
/* localdecomp:end func_L01_003CCE70 */
