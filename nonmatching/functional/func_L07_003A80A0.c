/* functional: medium. Scheduling and lit4 constant differences; packet builder. */
#include "common.h"
/* localdecomp:start func_L07_003A80A0 */
typedef int Q_003A80A0 __attribute__((mode(TI)));
typedef struct { float x,y,z,w; } __attribute__((aligned(16))) V_003A80A0;
typedef struct {
    V_003A80A0 v[4];
    u32 color[4];
    float uv[8];
    unsigned long zero, texture, state, dimensions;
} P_003A80A0;
extern s32 D_001DE3F0_sda, D_001DE3F4_sda;
extern V_003A80A0 D_L07_001E1E40;
void func_L07_003A80A0(V_003A80A0 *points, s32 count, s32 width, u32 color1, u32 color2, float length, float scale) {
    extern unsigned long func_00389598(s32);
    extern void func_L04_0041E590(void *);
    extern void func_0038CF68(void *, void *, float);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038CE20(void *, void *, float);
    extern void func_0038D028(void *, void *, void *);
    extern void func_003D2DA0(void *, s32, s32);
    V_003A80A0 delta, eye, normal, center;
    P_003A80A0 a,b;
    V_003A80A0 extent1,extent2;
    s32 i;
    float u,v;
    a.texture=func_00389598(D_001DE3F0_sda);
    a.state=0xFF9000000260UL;
    a.dimensions=((unsigned long)width<<32)|0x68;
    a.color[3]=color1;a.color[2]=color1;a.color[1]=color1;a.color[0]=color1;
    a.zero=0;
    func_L04_0041E590(&a);
    a.uv[0]=0;a.uv[1]=0;a.uv[2]=0;a.uv[3]=1;
    a.uv[4]=1;a.uv[5]=0;a.uv[6]=1;a.uv[7]=1;
    b.texture=func_00389598(D_001DE3F0_sda);
    b.state=0xFF9000000260UL;
    b.dimensions=((unsigned long)(width/3)<<32)|0x68;
    b.color[3]=color2;b.color[2]=color2;b.color[1]=color2;b.color[0]=color2;
    b.zero=0;
    func_L04_0041E590(&b);
    *(Q_003A80A0 *)&extent1=0;*(Q_003A80A0 *)&extent2=0;
    extent1.z=length;extent1.w=1;
    extent2.z=length*scale;extent2.w=1;
    b.uv[0]=0;b.uv[1]=0;b.uv[2]=0;b.uv[3]=1;
    b.uv[4]=0.33f;b.uv[5]=0;b.uv[6]=0.33f;b.uv[7]=1;
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
            : "=m"(delta) : "m"(points[0]),"m"(points[1]) : "vf1","vf2");
    func_0038CF68(&delta,&delta,1.0f);
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(eye) : "m"(points[0]),"m"(D_L07_001E1E40) : "vf1","vf2");
    func_0038CE90(&normal,&eye,&delta);
    func_0038CF68(&normal,&normal,1.0f);
    func_0038CE90(&eye,&delta,&normal);
    *(Q_003A80A0 *)&a.v[0]=*(Q_003A80A0 *)&extent1;
    *(Q_003A80A0 *)&center=*(Q_003A80A0 *)&points[0];
    func_0038CE20(&a.v[1],&a.v[0],-1.0f);
    func_0038D028(&a.v[0],&a.v[0],&delta);
    func_0038D028(&a.v[1],&a.v[1],&delta);
    *(Q_003A80A0 *)&b.v[0]=*(Q_003A80A0 *)&extent2;
    func_0038CE20(&b.v[1],&b.v[0],-1.0f);
    func_0038D028(&b.v[0],&b.v[0],&delta);
    func_0038D028(&b.v[1],&b.v[1],&delta);
    for(i=1;i<count;i++) {
        *(Q_003A80A0 *)&a.v[2]=*(Q_003A80A0 *)&extent1;
        func_0038CE20(&a.v[3],&a.v[2],-1.0f);
        *(Q_003A80A0 *)&b.v[2]=*(Q_003A80A0 *)&extent2;
        func_0038CE20(&b.v[3],&b.v[2],-1.0f);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
                : "=m"(delta) : "m"(points[i]),"m"(points[i+1]) : "vf1","vf2");
        func_0038CF68(&delta,&delta,1.0f);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
                : "=m"(eye) : "m"(points[i]),"m"(D_L07_001E1E40) : "vf1","vf2");
        func_0038CE90(&normal,&eye,&delta);
        func_0038CF68(&normal,&normal,1.0f);
        func_0038CE90(&eye,&delta,&normal);
        *(Q_003A80A0 *)&center=*(Q_003A80A0 *)&points[i];
        func_0038D028(&a.v[2],&a.v[2],&delta);
        func_0038D028(&a.v[3],&a.v[3],&delta);
        func_0038D028(&b.v[2],&b.v[2],&delta);
        func_0038D028(&b.v[3],&b.v[3],&delta);
        if(i==count-1) {
            a.color[2]=0;a.color[3]=0;b.color[2]=0;b.color[3]=0;
        }
        a.texture=func_00389598(D_001DE3F4_sda);
        a.dimensions=((unsigned long)width<<32)|0x68;
        a.texture=func_00389598(43);
        func_003D2DA0(&a,0,0);
        func_003D2DA0(&b,0,0);
        u=(float)i*0.33f;v=u+0.33f;
        if(u>=1.0f) {u-=1.0f;v-=1.0f;}
        b.uv[2]=u;b.uv[6]=v;
        *(Q_003A80A0 *)&a.v[0]=*(Q_003A80A0 *)&a.v[2];
        *(Q_003A80A0 *)&a.v[1]=*(Q_003A80A0 *)&a.v[3];
        *(Q_003A80A0 *)&b.v[0]=*(Q_003A80A0 *)&b.v[2];
        *(Q_003A80A0 *)&b.v[1]=*(Q_003A80A0 *)&b.v[3];
        b.uv[0]=u;b.uv[4]=v;
    }
}
/* localdecomp:end func_L07_003A80A0 */
