#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L39_00521728 */
extern char D_L39_00242AB0[8];
typedef struct { char pad[0xd4]; unsigned char *value; } EffectData;
extern EffectData D_L39_00296918[];
extern void func_003886E8(void *,void *,float);
extern float func_L39_005B2568(float,float);
extern int func_L39_005B2498(int);
extern unsigned char *func_L01_0046C468(void *,void *,int,int,int,int,int,float,float,float,int);
void func_L39_00521728(void *moby) {
    vu0_v4 pos,offset,step,particle; void *data=*(void **)((char *)moby+0x68); float scale, factor, large, jitter; int i,color; unsigned char *q;
    if(*(short *)((char *)data+0x64)) *(vu0_q *)&pos=*(vu0_q *)data;
    else *(vu0_q *)&pos=*(vu0_q *)((char *)data+0x10);
    scale=0.2f;
    func_003886E8(&offset,(char *)moby+0xd0,-0.1f);
    vec_add_ab(&pos,&pos,&offset);
    func_003886E8(&step,(char *)moby+0xe0,0.15f);
    vec_add_ab(&pos,&pos,&step);
    func_003886E8(&step,(char *)moby+0xe0,-0.033333335f);
    jitter=0.15f;
    for(i=8;i>=0;i--) {
        particle.x=pos.x+func_L39_005B2568(0.0f,jitter);
        particle.y=pos.y+func_L39_005B2568(0.0f,jitter);
        particle.z=pos.z+func_L39_005B2568(0.0f,jitter);
        color=func_L39_005B2498(255);
        factor=scale*210000.0f;
        func_L01_0046C468(&particle,D_L39_00242AB0,4,0x808080,color,127,127,factor,factor,0.0f,1);
        large=262500.0f;
        q=func_L01_0046C468(&pos,D_L39_00242AB0,4,0x203080,color,16,16,large,large,0.0f,1);
        if(q) q[2]=*D_L39_00296918[0].value;
        vec_add_ab(&pos,&pos,&step);
    }
}
/* localdecomp:end func_L39_00521728 */
