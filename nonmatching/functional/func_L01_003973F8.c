/* functional: medium. 215 diffs are register allocation/spill offsets; one extra move, same opcode multiset; Vec4_0039E0C8 typedef must precede it. */
#include "common.h"
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4_0039E0C8;
/* localdecomp:start func_L01_003973F8 */
#include "vu0.h"
typedef union { vu0_q q; f32 f[4]; } V_003973F8;
typedef struct {
    V_003973F8 pos[4];
    u32 color[4];
    f32 uv[4][2];
    u8 tail[0x20];
} Poly_003973F8;
extern vu0_v4 D_L01_001E29C0;
void func_L01_003973F8(V_003973F8 *start,V_003973F8 *points,u32 color,s32 count,f32 phase,f32 width,f32 step)
{
    extern void func_003D93B0(void *,s32,s32,s32);
    extern s32 func_0013D3E0(void);
    extern void func_0038CF68(Vec4_0039E0C8 *,Vec4_0039E0C8 *,f32);
    extern void func_0038CE90(void *,void *,void *);
    extern void func_0038CE20(f32 *,f32 *,f32);
    extern void func_0038D028(void *,void *,void *);
    extern void func_003D2DA0(void *,s32,s32);
    V_003973F8 origin;
    Poly_003973F8 outer,inner;
    V_003973F8 matrix[4];
    V_003973F8 offset,offset2;
    s32 i,next;
    s32 bytes;
    V_003973F8 *point;
    f32 u,v;
    origin.q=start->q;
    start=&origin;
    func_003D93B0(&outer,43,1,128);
    func_003D93B0(&inner,43,1,128);
    offset2.q=offset.q=0;
    width*=0.25f;
    outer.color[0]=outer.color[1]=color;
    inner.color[0]=inner.color[1]=color;
    outer.color[2]=outer.color[3]=color;
    inner.color[2]=inner.color[3]=color;
    offset.f[3]=1.0f;
    offset2.f[2]=width+width;
    offset2.f[3]=1.0f;
    offset.f[2]=width;
    if ((func_0013D3E0()&1)==0) {
        outer.uv[0][0]=phase+0.0f;
        outer.uv[0][1]=0.0f;
        outer.uv[1][0]=phase+0.0f;
        outer.uv[1][1]=1.0f;
        outer.uv[2][0]=step+phase;
        outer.uv[2][1]=0.0f;
        outer.uv[3][0]=step+phase;
        outer.uv[3][1]=1.0f;
        inner.uv[0][0]=phase+0.0f;
        inner.uv[0][1]=0.0f;
        inner.uv[1][0]=phase+0.0f;
        inner.uv[1][1]=1.0f;
        inner.uv[2][0]=step+phase;
        inner.uv[2][1]=0.0f;
        inner.uv[3][0]=step+phase;
        inner.uv[3][1]=1.0f;
    } else {
        outer.uv[0][0]=phase+0.0f;
        outer.uv[0][1]=1.0f;
        outer.uv[1][0]=phase+0.0f;
        outer.uv[1][1]=0.0f;
        outer.uv[2][0]=step+phase;
        outer.uv[2][1]=1.0f;
        outer.uv[3][0]=step+phase;
        outer.uv[3][1]=0.0f;
        inner.uv[0][0]=phase+0.0f;
        inner.uv[0][1]=1.0f;
        inner.uv[1][0]=phase+0.0f;
        inner.uv[1][1]=0.0f;
        inner.uv[2][0]=step+phase;
        inner.uv[2][1]=1.0f;
        inner.uv[3][0]=step+phase;
        inner.uv[3][1]=0.0f;
    }
    vec_sub_ba(&matrix[0],points,start);
    func_0038CF68((Vec4_0039E0C8 *)&matrix[0],(Vec4_0039E0C8 *)&matrix[0],1.0f);
    vec_sub_ba(&matrix[1],&D_L01_001E29C0,start);
    func_0038CE90(&matrix[2],&matrix[1],&matrix[0]);
    i=0;
    bytes=count<<4;
    func_0038CF68((Vec4_0039E0C8 *)&matrix[2],(Vec4_0039E0C8 *)&matrix[2],1.0f);
    func_0038CE90(&matrix[1],&matrix[0],&matrix[2]);
    matrix[3].q=start->q;
    outer.pos[0].q=offset.q;
    inner.pos[0].q=offset2.q;
    func_0038CE20(outer.pos[1].f,outer.pos[0].f,-1.0f);
    func_0038CE20(inner.pos[1].f,inner.pos[0].f,-1.0f);
    func_0038D028(&outer.pos[0],&outer.pos[0],matrix);
    func_0038D028(&outer.pos[1],&outer.pos[1],matrix);
    func_0038D028(&inner.pos[0],&inner.pos[0],matrix);
    func_0038D028(&inner.pos[1],&inner.pos[1],matrix);
    while (i<count-1) {
        point=(V_003973F8 *)((i<<4)+(s32)points);
        next=i+1;
        vec_sub_ab(&matrix[0],point+1,point);
        func_0038CF68((Vec4_0039E0C8 *)&matrix[0],(Vec4_0039E0C8 *)&matrix[0],1.0f);
        vec_sub_ab(&matrix[1],&D_L01_001E29C0,point);
        func_0038CE90(&matrix[2],&matrix[1],&matrix[0]);
        func_0038CF68((Vec4_0039E0C8 *)&matrix[2],(Vec4_0039E0C8 *)&matrix[2],1.0f);
        func_0038CE90(&matrix[1],&matrix[0],&matrix[2]);
        offset.f[2]*=0.7f;
        matrix[3].q=point->q;
        offset2.f[2]=offset.f[2]+offset.f[2];
        outer.pos[2].q=offset.q;
        inner.pos[2].q=offset2.q;
        func_0038CE20(outer.pos[3].f,outer.pos[2].f,-1.0f);
        func_0038CE20(inner.pos[3].f,inner.pos[2].f,-1.0f);
        func_0038D028(&outer.pos[2],&outer.pos[2],matrix);
        func_0038D028(&outer.pos[3],&outer.pos[3],matrix);
        func_0038D028(&inner.pos[2],&inner.pos[2],matrix);
        func_0038D028(&inner.pos[3],&inner.pos[3],matrix);
        u=step*(f32)next; v=u+step;
        if (u>=1.0f) {u-=1.0f;v-=1.0f;}
        v+=phase;u+=phase;
        outer.uv[0][0]=u;outer.uv[1][0]=u;
        outer.uv[2][0]=v;outer.uv[3][0]=v;
        inner.uv[0][0]=u;inner.uv[1][0]=u;
        inner.uv[2][0]=v;inner.uv[3][0]=v;
        func_003D2DA0(&outer,0,0);
        func_003D2DA0(&inner,0,0);
        if (i!=0) {
            outer.color[0]=outer.color[1]=color|0x7F000000;
            inner.color[0]=inner.color[1]=color|0x3F000000;
        }
        i=next;
        outer.pos[0].q=outer.pos[2].q;
        outer.pos[1].q=outer.pos[3].q;
        inner.pos[0].q=inner.pos[2].q;
        inner.pos[1].q=inner.pos[3].q;
        outer.color[2]=outer.color[3]=color|0x7F000000;
        inner.color[2]=inner.color[3]=color|0x3F000000;
    }
    offset.f[2]*=0.7f;
    matrix[3].q=((V_003973F8 *)((s32)points+bytes))[-1].q;
    offset2.f[2]=offset.f[2]+offset.f[2];
    outer.pos[2].q=offset.q;
    inner.pos[2].q=offset2.q;
    func_0038CE20(outer.pos[3].f,outer.pos[2].f,-1.0f);
    func_0038CE20(inner.pos[3].f,inner.pos[2].f,-1.0f);
    func_0038D028(&outer.pos[2],&outer.pos[2],matrix);
    func_0038D028(&outer.pos[3],&outer.pos[3],matrix);
    func_0038D028(&inner.pos[2],&inner.pos[2],matrix);
    func_0038D028(&inner.pos[3],&inner.pos[3],matrix);
    u=step*(f32)(i+1);v=u+step;
    outer.color[2]=outer.color[3]=color;
    inner.color[2]=inner.color[3]=color;
    if (u>=1.0f) {u-=1.0f;v-=1.0f;}
    u+=phase;v+=phase;
    outer.uv[0][0]=u;outer.uv[1][0]=u;
    outer.uv[2][0]=v;outer.uv[3][0]=v;
    inner.uv[0][0]=u;inner.uv[1][0]=u;
    inner.uv[2][0]=v;inner.uv[3][0]=v;
    func_003D2DA0(&outer,0,0);
    func_003D2DA0(&inner,0,0);
}
/* localdecomp:end func_L01_003973F8 */
