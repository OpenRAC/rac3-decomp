/* functional: high. Compiles with file flags; 357 words differ (regalloc, VU load order, scheduling); whole function reviewed line by line against retail. */
/* localdecomp:start func_L01_0037D358 */
#include "vu0.h"
typedef struct {
    vu0_v4 p[4];
    u32 color[4];
    f32 uv[8];
    unsigned long tag[4];
} Packet_0037D358;
extern u8 D_00142627;
typedef struct { u8 data[240]; } Row_0037D358;
extern Row_0037D358 D_L01_002C5600[];
extern vu0_v4 D_L01_001E29C0[];
void func_L01_0037D358(s32 unused, s32 texture, vu0_v4 *points, s32 count)
{
    extern void func_L01_0037C798(vu0_v4 *p, s32 i);
    extern void func_L01_0037C7D8(u8 *p);
    extern unsigned long func_00389598(s32);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038D028(void *, void *, void *);
    extern u32 func_0038DBD8(u32, u32, f32);
    extern void func_0038CDF8(void *, void *, void *, f32);
    extern void func_003D2DA0(void *, s32, s32);
    Packet_0037D358 a, b;
    vu0_v4 matrix[4];
    vu0_v4 size0, size1;
    u8 *row = (u8 *)D_L01_002C5600 + (long)D_00142627*240;
    u32 color0=0x3FAF7F7F, color1=0x0FAF7F7F;
    u32 start0=0x3FFF8040, start1=0x0FFF8040;
    s32 i;
    vu0_v4 *camera=D_L01_001E29C0;
    if (row[1] >= 3) {
        color0=0x3F101070; color1=0x0F101070;
        start0=0x3F4080FF; start1=0x0F4080FF;
    }
    a.tag[1]=func_00389598(43);
    a.tag[2]=0xFF9000000260;
    a.tag[3]=((unsigned long)texture<<32)|104;
    a.tag[0]=0;
    a.color[0]=a.color[1]=start0;
    i=1;
    b.tag[1]=func_00389598(43);
    b.tag[2]=0xFF9000000260;
    b.tag[3]=((unsigned long)(texture/3)<<32)|104;
    b.tag[0]=0;
    b.color[0]=start1; b.color[1]=start1;
    size0.x=size0.y=size0.z=size0.w=0;
    size1.x=size1.y=size1.z=size1.w=0;
    size0.w=1.0f; size1.w=1.0f;
    size0.z=func_003824E0(0.01f,0.085f)*1.5f;
    size1.z=func_003824E0(0.15f,0.25f)*1.5f;
    func_L01_0037C798(points,count);
    func_L01_0037C7D8((u8 *)&a);
    func_L01_0037C7D8((u8 *)&b);
    vec_sub_ab(&matrix[0], &points[1], &points[0]);
    a.uv[0]=0; a.uv[1]=0; a.uv[2]=0; a.uv[3]=1;
    a.uv[4]=1; a.uv[5]=0; a.uv[6]=1; a.uv[7]=1;
    b.uv[0]=0; b.uv[1]=0; b.uv[2]=0; b.uv[3]=1;
    b.uv[4]=0.33f; b.uv[5]=0; b.uv[6]=0.33f; b.uv[7]=1;
    func_0038CF68(&matrix[0], &matrix[0], 1);
    vec_sub_ba(&matrix[1], camera, &points[0]);
    func_0038CE90(&matrix[2], &matrix[1], &matrix[0]);
    func_0038CF68(&matrix[2], &matrix[2], 1);
    func_0038CE90(&matrix[1], &matrix[0], &matrix[2]);
    *(vu0_v4 *)&matrix[3]=*(vu0_v4 *)&points[0];
    *(vu0_v4 *)&a.p[0]=*(vu0_v4 *)&size0;
    func_0038CE20(&a.p[1],&a.p[0],-1);
    func_0038D028(&a.p[0],&a.p[0],matrix);
    func_0038D028(&a.p[1],&a.p[1],matrix);
    *(vu0_v4 *)&b.p[0]=*(vu0_v4 *)&size1;
    func_0038CE20(&b.p[1],&b.p[0],-1);
    func_0038D028(&b.p[0],&b.p[0],matrix);
    func_0038D028(&b.p[1],&b.p[1],matrix);
    while (i<count-1) {
        f32 t, u, fi;
        fi=(f32)i;
        *(vu0_v4 *)&a.p[2]=*(vu0_v4 *)&size0;
        func_0038CE20(&a.p[3],&a.p[2],-1);
        *(vu0_v4 *)&b.p[2]=*(vu0_v4 *)&size1;
        func_0038CE20(&b.p[3],&b.p[2],-1);
        vec_sub_ab(&matrix[0], &points[i+1], &points[i]);
        func_0038CF68(&matrix[0], &matrix[0],1);
        vec_sub_ab(&matrix[1], camera, &points[i]);
        func_0038CE90(&matrix[2], &matrix[1], &matrix[0]);
        func_0038CF68(&matrix[2], &matrix[2],1);
        func_0038CE90(&matrix[1], &matrix[0], &matrix[2]);
        *(vu0_v4 *)&matrix[3]=*(vu0_v4 *)&points[i];
        func_0038D028(&a.p[2],&a.p[2],matrix);
        func_0038D028(&a.p[3],&a.p[3],matrix);
        func_0038D028(&b.p[2],&b.p[2],matrix);
        func_0038D028(&b.p[3],&b.p[3],matrix);
        t=(f32)count-2.0f;
        t=fi/t;
        a.color[2]=a.color[3]=func_0038DBD8(start0,color0,t);
        b.color[2]=b.color[3]=func_0038DBD8(start0,color1,t);
        if(i==count-2) {
            func_0038CDF8(&a.p[2],&a.p[2],&a.p[3],0.5f);
            func_0038CDF8(&b.p[2],&b.p[2],&b.p[3],0.5f);
            *(vu0_v4 *)&a.p[3]=*(vu0_v4 *)&a.p[2];
            *(vu0_v4 *)&b.p[3]=*(vu0_v4 *)&b.p[2];
        }
        func_003D2DA0(&a,0,0);
        func_003D2DA0(&b,0,0);
        t=fi*0.33f;
        u=t+0.33f;
        if(t>=1) { t-=1; u-=1; }
        *(vu0_v4 *)&a.p[0]=*(vu0_v4 *)&a.p[2];
        *(vu0_v4 *)&a.p[1]=*(vu0_v4 *)&a.p[3];
        *(vu0_v4 *)&b.p[0]=*(vu0_v4 *)&b.p[2];
        *(vu0_v4 *)&b.p[1]=*(vu0_v4 *)&b.p[3];
        a.color[0]=a.color[2];
        b.color[0]=b.color[2];
        b.uv[2]=t; b.uv[6]=u;
        a.color[1]=a.color[2];
        b.color[1]=b.color[2];
        b.uv[0]=t; b.uv[4]=u;
        i++;
    }
}
/* localdecomp:end func_L01_0037D358 */
