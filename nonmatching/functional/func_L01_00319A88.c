/* functional: high. 42 words differ (constant hoisting, store scheduling, loop-tail allocation); packet layout, both quad strips, uv scroll, basis construction and call order verified vs retail. */
/* PAL near miss (Codex wave 8): near miss: 42 words differ with the file's flags.
 * Worker's note: 42 instruction diffs; constant hoisting, texture-store scheduling and loop-tail allocation; three different source forms unchanged; log build/codex/w419/func_L01_00319A88.05.log
 */
#include "common.h"
/* localdecomp:start func_L01_00319A88 */
#include "vu0.h"
typedef struct { vu0_v4 p[4]; s32 color[4]; f32 uv[4][2]; unsigned long zero, texture, fixed, flags; } Packet_00319A88;
extern vu0_v4 D_L01_001E29C0;
void func_L01_00319A88(s32 unused, s32 color, vu0_v4 *points, s32 count) {
    extern unsigned long func_00389598(s32);
    extern void func_L01_00319A48(vu0_v4 *, s32);
    extern void func_L01_00318FB8(u8 *);
    extern void func_0038CF68(f32 *, f32 *, f32);
    extern void func_0038CE90(f32 *, f32 *, f32 *);
    extern void func_0038D028(void *, void *, void *);
    extern void func_003D2DA0(void *, s32, s32);
    Packet_00319A88 a,b;
    vu0_v4 basis[4];
    vu0_v4 widthA, widthB;
    s32 i = 1;
    f32 u,v;
    a.texture = func_00389598(43);
    a.fixed = 0xFF9000000260;
    a.flags = ((unsigned long)color << 32) | 0x68;
    a.zero = 0;
    a.color[0] = a.color[1] = 0x7FFFFFFF;
    b.texture = func_00389598(43);
    *(vu0_q *)&widthA = 0;
    *(vu0_q *)&widthB = 0;
    b.fixed = 0xFF9000000260;
    b.flags = ((unsigned long)(color / 3) << 32) | 0x68;
    b.zero = 0;
    a.color[1] = b.color[0] = 0x80FF0000;
    widthA.z = 0.04f; widthA.w = 1.0f;
    widthB.z = 0.16f; widthB.w = 1.0f;
    func_L01_00319A48(points,count);
    func_L01_00318FB8((u8 *)&a);
    func_L01_00318FB8((u8 *)&b);
    a.uv[0][0]=0; a.uv[0][1]=0; a.uv[1][0]=0; a.uv[1][1]=1;
    a.uv[2][0]=1; a.uv[2][1]=0; a.uv[3][0]=1; a.uv[3][1]=1;
    b.uv[0][0]=0; b.uv[0][1]=0; b.uv[1][0]=0; b.uv[1][1]=1;
    b.uv[2][0]=0.33f; b.uv[2][1]=0; b.uv[3][0]=0.33f; b.uv[3][1]=1;
    vec_sub_ab(&basis[0],&points[1],&points[0]);
    func_0038CF68((f32 *)&basis[0],(f32 *)&basis[0],1.0f);
    vec_sub_ba(&basis[1],&D_L01_001E29C0,&points[0]);
    func_0038CE90((f32 *)&basis[2],(f32 *)&basis[1],(f32 *)&basis[0]);
    func_0038CF68((f32 *)&basis[2],(f32 *)&basis[2],1.0f);
    func_0038CE90((f32 *)&basis[1],(f32 *)&basis[0],(f32 *)&basis[2]);
    *(vu0_q *)&basis[3]=*(vu0_q *)&points[0];
    *(vu0_q *)&a.p[0]=*(vu0_q *)&widthA;
    func_0038CE20((f32 *)&a.p[1],(f32 *)&a.p[0],-1.0f);
    func_0038D028(&a.p[0],&a.p[0],basis);
    func_0038D028(&a.p[1],&a.p[1],basis);
    *(vu0_q *)&b.p[0]=*(vu0_q *)&widthB;
    func_0038CE20((f32 *)&b.p[1],(f32 *)&b.p[0],-1.0f);
    func_0038D028(&b.p[0],&b.p[0],basis);
    func_0038D028(&b.p[1],&b.p[1],basis);
    for (;i<count-1;) {
        s32 next;
        *(vu0_q *)&a.p[2]=*(vu0_q *)&widthA;
        func_0038CE20((f32 *)&a.p[3],(f32 *)&a.p[2],-1.0f);
        *(vu0_q *)&b.p[2]=*(vu0_q *)&widthB;
        func_0038CE20((f32 *)&b.p[3],(f32 *)&b.p[2],-1.0f);
        vec_sub_ab(&basis[0],&points[i+1],&points[i]);
        func_0038CF68((f32 *)&basis[0],(f32 *)&basis[0],1.0f);
        vec_sub_ab(&basis[1],&D_L01_001E29C0,&points[i]);
        func_0038CE90((f32 *)&basis[2],(f32 *)&basis[1],(f32 *)&basis[0]);
        func_0038CF68((f32 *)&basis[2],(f32 *)&basis[2],1.0f);
        func_0038CE90((f32 *)&basis[1],(f32 *)&basis[0],(f32 *)&basis[2]);
        *(vu0_q *)&basis[3]=*(vu0_q *)&points[i];
        func_0038D028(&a.p[2],&a.p[2],basis);func_0038D028(&a.p[3],&a.p[3],basis);
        func_0038D028(&b.p[2],&b.p[2],basis);func_0038D028(&b.p[3],&b.p[3],basis);
        a.color[2]=a.color[3]=0x7F7F7F7F;
        b.color[2]=b.color[3]=0x80FF0000UL;
        func_003D2DA0(&a,0,0);func_003D2DA0(&b,0,0);
        u=(f32)i*0.33f;v=u+0.33f;
        if(u>=1.0f){u-=1.0f;v-=1.0f;}
        b.uv[0][0]=u;b.uv[1][0]=u;b.uv[2][0]=v;b.uv[3][0]=v;
        i=i+1;
        *(vu0_q *)&a.p[0]=*(vu0_q *)&a.p[2];*(vu0_q *)&a.p[1]=*(vu0_q *)&a.p[3];
        *(vu0_q *)&b.p[0]=*(vu0_q *)&b.p[2];*(vu0_q *)&b.p[1]=*(vu0_q *)&b.p[3];
    }
}
/* localdecomp:end func_L01_00319A88 */
