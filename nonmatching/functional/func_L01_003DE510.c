/* functional: high. Codex near miss, 312 words differ but only in spill-slot choice, store order, float register naming and VU0 scheduling; same instruction multiset (395 vs 396 words). */
#include "common.h"
/* localdecomp:start func_L01_003DE510 */
#include "vu0.h"
typedef struct { vu0_q p[4]; u32 c[4]; f32 uv[4][2]; u8 pad[32]; } Packet_003DE510;
extern vu0_v4 D_L01_001E29C0;
void func_L01_003DE510(u128_t *start, u8 *points, s32 color, s32 count, f32 offset, f32 width, f32 step) {
    extern void func_003D93B0(void *, s32, s32, s32);
    extern s32 func_0013D3E0(void);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038D028(void *, void *, void *);
    extern void func_003D2DA0(void *, s32, s32);
    vu0_q origin[1];
    Packet_003DE510 a, b;
    struct { vu0_v4 dir, view, cross, pos; } mat;
    vu0_v4 left, right;
    s32 i;
    f32 u,v;
    origin[0] = *start;
    func_003D93B0(&a,43,1,128);
    func_003D93B0(&b,43,1,128);
    *(vu0_q *)&left=0; *(vu0_q *)&right=0;
    width *= 0.25f;
    a.c[0]=a.c[1]=b.c[0]=b.c[1]=color;
    a.c[2]=a.c[3]=b.c[2]=b.c[3]=color;
    left.z=width; right.z=width+width; left.w=1.0f; right.w=1.0f;
    if (!(func_0013D3E0()&1)) {
        a.uv[0][0]=offset+0.0f;
        a.uv[1][0]=offset+0.0f;
        b.uv[0][0]=offset+0.0f;
        b.uv[1][0]=offset+0.0f;
        a.uv[2][0]=step+offset;
        a.uv[3][0]=step+offset;
        b.uv[2][0]=step+offset;
        b.uv[3][0]=step+offset;
        a.uv[0][1]=0.0f;
        a.uv[2][1]=0.0f;
        b.uv[0][1]=0.0f;
        b.uv[2][1]=0.0f;
        a.uv[1][1]=1.0f;
        a.uv[3][1]=1.0f;
        b.uv[1][1]=1.0f;
        b.uv[3][1]=1.0f;
    } else {
        a.uv[0][0]=offset+0.0f;
        a.uv[1][0]=offset+0.0f;
        b.uv[0][0]=offset+0.0f;
        b.uv[1][0]=offset+0.0f;
        a.uv[2][0]=step+offset;
        a.uv[3][0]=step+offset;
        b.uv[2][0]=step+offset;
        b.uv[3][0]=step+offset;
        a.uv[0][1]=1.0f;
        a.uv[2][1]=1.0f;
        b.uv[0][1]=1.0f;
        b.uv[2][1]=1.0f;
        a.uv[1][1]=0.0f;
        a.uv[3][1]=0.0f;
        b.uv[1][1]=0.0f;
        b.uv[3][1]=0.0f;
    }
    vec_sub_ba(&mat.dir,points,origin);
    func_0038CF68(&mat.dir,&mat.dir,1.0f);
    vec_sub_ba(&mat.view,&D_L01_001E29C0,origin);
    func_0038CE90(&mat.cross,&mat.view,&mat);
    func_0038CF68(&mat.cross,&mat.cross,1.0f);
    func_0038CE90(&mat.view,&mat.dir,&mat.cross);
    mat.pos=*(vu0_v4 *)origin;
    a.p[0]=*(vu0_q *)&left; b.p[0]=*(vu0_q *)&right;
    func_0038CE20(&a.p[1],&a.p[0],-1.0f);
    func_0038CE20(&b.p[1],&b.p[0],-1.0f);
    func_0038D028(&a.p[0],&a.p[0],&mat);
    func_0038D028(&a.p[1],&a.p[1],&mat);
    func_0038D028(&b.p[0],&b.p[0],&mat);
    func_0038D028(&b.p[1],&b.p[1],&mat);
    for(i=0;i<count-1;i++) {
        vu0_v4 *point=(vu0_v4 *)(points+i*16);
        vec_sub_ab(&mat.dir,point+1,point);
        func_0038CF68(&mat.dir,&mat.dir,1.0f);
        vec_sub_ab(&mat.view,&D_L01_001E29C0,point);
        func_0038CE90(&mat.cross,&mat.view,&mat);
        func_0038CF68(&mat.cross,&mat.cross,1.0f);
        func_0038CE90(&mat.view,&mat.dir,&mat.cross);
        left.z*=0.7f; right.z=left.z+left.z;
        mat.pos=*point;
        a.p[2]=*(vu0_q *)&left; b.p[2]=*(vu0_q *)&right;
        func_0038CE20(&a.p[3],&a.p[2],-1.0f);
        func_0038CE20(&b.p[3],&b.p[2],-1.0f);
        func_0038D028(&a.p[2],&a.p[2],&mat);
        func_0038D028(&a.p[3],&a.p[3],&mat);
        func_0038D028(&b.p[2],&b.p[2],&mat);
        func_0038D028(&b.p[3],&b.p[3],&mat);
        u=step*(i+1); v=u+step;
        if(u>=1.0f){u-=1.0f;v-=1.0f;}
        u+=offset;v+=offset;
        a.uv[0][0]=u; a.uv[1][0]=u; b.uv[0][0]=u; b.uv[1][0]=u;
        a.uv[2][0]=v; a.uv[3][0]=v; b.uv[2][0]=v; b.uv[3][0]=v;
        func_003D2DA0(&a,0,0);func_003D2DA0(&b,0,0);
        if(i){a.c[0]=a.c[1]=color|0x7F000000;b.c[0]=b.c[1]=color|0x3F000000;}
        a.p[0]=a.p[2];a.p[1]=a.p[3];b.p[0]=b.p[2];b.p[1]=b.p[3];
        a.c[2]=a.c[3]=color|0x7F000000;b.c[2]=b.c[3]=color|0x3F000000;
    }
    left.z*=0.7f;right.z=left.z+left.z;
    mat.pos=*(vu0_v4 *)(points+(count-1)*16);
    a.p[2]=*(vu0_q *)&left;b.p[2]=*(vu0_q *)&right;
    func_0038CE20(&a.p[3],&a.p[2],-1.0f);func_0038CE20(&b.p[3],&b.p[2],-1.0f);
    func_0038D028(&a.p[2],&a.p[2],&mat);func_0038D028(&a.p[3],&a.p[3],&mat);
    func_0038D028(&b.p[2],&b.p[2],&mat);func_0038D028(&b.p[3],&b.p[3],&mat);
    a.c[2]=a.c[3]=b.c[2]=b.c[3]=color;
    u=step*(i+1);v=u+step;if(u>=1.0f){v-=1.0f;u-=1.0f;}
    u+=offset;v+=offset;
    a.uv[0][0]=u; a.uv[1][0]=u; b.uv[0][0]=u; b.uv[1][0]=u;
    a.uv[2][0]=v; a.uv[3][0]=v; b.uv[2][0]=v; b.uv[3][0]=v;
    func_003D2DA0(&a,0,0);func_003D2DA0(&b,0,0);
}
/* localdecomp:end func_L01_003DE510 */
