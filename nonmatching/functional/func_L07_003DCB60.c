/* functional: high. PAL near-miss draft re-read against PAL asm in full (both ribbon quad layouts, uv/colour/clamp words, frame matrix built from segment direction and D_L07_001E1E40, per-segment transform order, last-segment colour fade, uv scroll wrap at 1.0, the discarded 0x47 texture call); caller passes a sixth unused int arg. Only scheduling differs. */
#include "common.h"
#include "vu0.h"
typedef struct {
    vu0_v4 points[4];
    u32 colors[4];
    f32 uv[8];
    unsigned long alpha, tex, state, clamp;
} Ribbon_003DCB60;
extern vu0_v4 D_L07_001E1E40;
void func_L07_003DCB60(vu0_v4 *points, s32 count, s32 blend, u32 c0, u32 c1, f32 size, f32 ratio) {
    extern unsigned long func_00389598(s32);
    extern void func_L07_003DCAD8(void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038D028(void *, void *, void *);
    extern void func_003D2DA0(void *, s32, s32);
    vu0_v4 matrix[4];
    Ribbon_003DCB60 a,b;
    vu0_v4 width0,width1;
    s32 i;
    a.tex=func_00389598(0x2B);
    a.clamp=((unsigned long)blend<<32)|0x68;
    a.state=0xFF9000000260UL;
    a.colors[0]=a.colors[1]=a.colors[2]=a.colors[3]=c0;
    a.alpha=0;
    func_L07_003DCAD8(&a);
    a.uv[0]=0; a.uv[1]=0; a.uv[2]=0; a.uv[3]=1;
    a.uv[4]=1; a.uv[5]=0; a.uv[6]=1; a.uv[7]=1;
    b.tex=func_00389598(0x2B);
    b.state=0xFF9000000260UL;
    b.colors[0]=b.colors[1]=b.colors[2]=b.colors[3]=c1;
    b.alpha=0;
    b.clamp=((unsigned long)(blend/3)<<32)|0x68;
    func_L07_003DCAD8(&b);
    b.uv[0]=0; b.uv[1]=0; b.uv[2]=0; b.uv[3]=1;
    b.uv[4]=0.33f; b.uv[5]=0; b.uv[6]=0.33f; b.uv[7]=1;
    *(vu0_q *)&width0=0;
    *(vu0_q *)&width1=0;
    width0.z=size; width0.w=1;
    width1.z=size*ratio; width1.w=1;
    __asm__("lqc2 $vf1, %1\n\t"
            "lqc2 $vf2, %2\n\t"
            "vsub.xyz $vf2, $vf2, $vf1\n\t"
            "sqc2 $vf2, %0"
            : "=m"(matrix[0]) : "m"(points[0]), "m"(points[1]) : "vf1", "vf2");
    func_0038CF68(&matrix[0],&matrix[0],1);
    __asm__("lqc2 $vf2, %1\n\t"
            "lqc2 $vf1, %2\n\t"
            "vsub.xyz $vf1, $vf1, $vf2\n\t"
            "sqc2 $vf1, %0"
            : "=m"(matrix[1]) : "m"(points[0]), "m"(D_L07_001E1E40) : "vf1", "vf2");
    func_0038CE90(&matrix[2],&matrix[1],&matrix[0]);
    func_0038CF68(&matrix[2],&matrix[2],1);
    func_0038CE90(&matrix[1],&matrix[0],&matrix[2]);
    *(vu0_q *)&matrix[3]=*(vu0_q *)&points[0];
    *(vu0_q *)&a.points[0]=*(vu0_q *)&width0;
    func_0038CE20(&a.points[1],&a.points[0],-1);
    func_0038D028(&a.points[0],&a.points[0],matrix);
    func_0038D028(&a.points[1],&a.points[1],matrix);
    *(vu0_q *)&b.points[0]=*(vu0_q *)&width1;
    func_0038CE20(&b.points[1],&b.points[0],-1);
    func_0038D028(&b.points[0],&b.points[0],matrix);
    func_0038D028(&b.points[1],&b.points[1],matrix);
    for(i=1;i<count;i++) {
        *(vu0_q *)&a.points[2]=*(vu0_q *)&width0;
        func_0038CE20(&a.points[3],&a.points[2],-1);
        *(vu0_q *)&b.points[2]=*(vu0_q *)&width1;
        func_0038CE20(&b.points[3],&b.points[2],-1);
        __asm__("lqc2 $vf1, %1\n\t"
            "lqc2 $vf2, %2\n\t"
            "vsub.xyz $vf2, $vf2, $vf1\n\t"
            "sqc2 $vf2, %0"
            : "=m"(matrix[0]) : "m"(points[i]), "m"(points[i+1]) : "vf1", "vf2");
        func_0038CF68(&matrix[0],&matrix[0],1);
        __asm__("lqc2 $vf1, %1\n\t"
            "lqc2 $vf2, %2\n\t"
            "vsub.xyz $vf2, $vf2, $vf1\n\t"
            "sqc2 $vf2, %0"
            : "=m"(matrix[1]) : "m"(points[i]), "m"(D_L07_001E1E40) : "vf1", "vf2");
        func_0038CE90(&matrix[2],&matrix[1],&matrix[0]);
        func_0038CF68(&matrix[2],&matrix[2],1);
        func_0038CE90(&matrix[1],&matrix[0],&matrix[2]);
        *(vu0_q *)&matrix[3]=*(vu0_q *)&points[i];
        func_0038D028(&a.points[2],&a.points[2],matrix);
        func_0038D028(&a.points[3],&a.points[3],matrix);
        func_0038D028(&b.points[2],&b.points[2],matrix);
        func_0038D028(&b.points[3],&b.points[3],matrix);
        if(i==count-1) {
            a.colors[2]=0; a.colors[3]=0;
            b.colors[2]=0; b.colors[3]=0;
        }
        a.tex=func_00389598(0x47);
        a.clamp=((unsigned long)blend<<32)|0x68;
        a.tex=func_00389598(0x2B);
        func_003D2DA0(&a,0,0);
        func_003D2DA0(&b,0,0);
        {
            f32 u=(f32)i*0.33f;
            f32 next=u+0.33f;
            if(1.0f<=u) { u-=1.0f; next-=1.0f; }
            b.uv[2]=u; b.uv[6]=next;
            b.uv[0]=u; b.uv[4]=next;
        }
        *(vu0_q *)&a.points[0]=*(vu0_q *)&a.points[2];
        *(vu0_q *)&a.points[1]=*(vu0_q *)&a.points[3];
        *(vu0_q *)&b.points[0]=*(vu0_q *)&b.points[2];
        *(vu0_q *)&b.points[1]=*(vu0_q *)&b.points[3];
    }
}
