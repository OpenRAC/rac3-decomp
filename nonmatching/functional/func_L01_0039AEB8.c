/* functional: medium. Codex PAL draft re-checked in context: 388 words (frame 0x340 vs 0x2C0, same jal list, signature checked against retail registers and callers) differs only in scheduling/register allocation/addressing, same calls in the same order.  */
#include "vu0.h"
typedef struct {
    vu0_v4 pos[4];
    u32 color[4];
    f32 uv[8];
    unsigned long tag[4];
} Quad_0039AEB8;
extern vu0_v4 D_L01_001E29C0;
void func_L01_0039AEB8(u8 *points, s32 alpha, s32 alpha2, s32 count, u32 color, u32 color2, f32 width, f32 width2, f32 spread)
{
    extern unsigned long func_00389598(s32);
    extern void func_0038CE90(void *, void *, void *);
    extern f32 func_0038CEA8(void *);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern void func_003D2DA0(void *, s32, s32);
    extern void func_003A9440(s32, s32);
    Quad_0039AEB8 q, q2;
    f32 cross[4], scaled[4], rel[4], dir[4], a[4], b[4], ra[4], rb[4], inv[4], offset[4];
    s32 last;
    f32 t0[4], t1[4], t2[4], t3[4], t4[4], t5[4], t6[4];
    f32 len, la, lb;
    s32 i;
    u32 c1, c2;
    q.tag[1] = func_00389598(14);
    c1 = color | (alpha << 24);
    q.tag[3] = 0x8000000048;
    q.tag[2] = 0xFF9000000260;
    q.tag[0] = 0;
    q.color[0] = q.color[1] = q.color[2] = q.color[3] = c1;
    q2.tag[1] = func_00389598(16);
    vec_copy(&t6, points);
    q2.tag[3] = q.tag[3];
    c2 = color2 | (alpha2 << 24);
    vec_sub_ba(&t0, &t6, &D_L01_001E29C0);
    q2.tag[2] = q.tag[2];
    q2.tag[0] = q.tag[0];
    q2.color[0] = q2.color[1] = q2.color[2] = q2.color[3] = c2;
    q2.uv[0]=0.0f; q2.uv[1]=0.0f; q2.uv[2]=0.0f; q2.uv[3]=1.0f;
    q2.uv[4]=1.0f; q2.uv[5]=0.0f; q2.uv[6]=1.0f; q2.uv[7]=1.0f;
    q.uv[0]=0.0f; q.uv[1]=0.0f; q.uv[2]=0.0f; q.uv[3]=1.0f;
    q.uv[4]=1.0f; q.uv[5]=0.0f; q.uv[6]=1.0f; q.uv[7]=1.0f;
    vec_sub_ba(&dir, points+16, points);
    vec_copy(&rel, &t0);
    func_0038CE90(&cross, &dir, &rel);
    len=func_0038CEA8(&cross);
    if(len!=0) len=1.0f/len;
    func_0038CE20((f32 *)&cross,(f32 *)&cross,width*len);
    vec_add_ba(&q.pos[0],points,&cross);
    vec_sub_ab(&q.pos[1],points,&cross);
    last=count-1;
    for(i=1;i<last;i++) {
        vec_copy(&t6,points+i*16);
        vec_sub_ba(&t6,&t6,&D_L01_001E29C0);
        vec_copy(&t1,points+i*16);
        vec_copy(&rel,&t6);
        vec_sub_ab(&dir,points+i*16+16,&t1);
        func_0038CE90(&cross,&dir,&rel);
        len=func_0038CEA8(&cross);
        if(len!=0) len=1.0f/len;
        func_0038CE20((f32 *)&cross,(f32 *)&cross,width*len);
        vec_add_ba(&q.pos[2],points+i*16,&cross);
        vec_sub_ba(&q.pos[3],points+i*16,&cross);
        if(i==1) q.color[0]=q.color[1]=color;
        else if(i==count-2) q.color[2]=q.color[3]=color;
        else if(i==2) q.color[0]=q.color[1]=c1;
        func_003D2DA0(&q,0,0);
        *(vu0_q *)&q.pos[0]=*(vu0_q *)&q.pos[2];
        *(vu0_q *)&q.pos[1]=*(vu0_q *)&q.pos[3];
    }
    for(i=0;i<last;i++) {
        vec_copy(&t6,points+i*16);
        vec_sub_ba(&t6,&t6,&D_L01_001E29C0);
        vec_copy(&t3,&D_L01_001E29C0);
        vec_copy(&ra,&t6);
        vec_sub_ab(&rb,points+i*16+16,&t3);
        la=func_0038CEA8(&ra);
        lb=func_0038CEA8(&rb);
        if(lb<la) {
            if(lb==0) *(vu0_q *)&rb=*(vu0_q *)&ra;
            else func_0038CE20((f32 *)&rb,(f32 *)&rb,la/lb);
        } else {
            if(la==0) *(vu0_q *)&ra=*(vu0_q *)&rb;
            else func_0038CE20((f32 *)&ra,(f32 *)&ra,lb/la);
        }
        vec_add_ba(&a,&D_L01_001E29C0,&ra);
        vec_add_ab(&b,&D_L01_001E29C0,&rb);
        vec_sub_ba(&dir,&b,&a);
        func_0038CE20((f32 *)&offset,(f32 *)&dir,spread);
        vec_sub_ba(&a,&a,&offset);
        vec_copy(&t4,&D_L01_001E29C0);
        vec_add_ba(&b,&b,&offset);
        vec_sub_ab(&inv,&t4,&a);
        func_0038CE90(&cross,&inv,&dir);
        len=func_0038CEA8(&cross);
        if(len!=0) len=1.0f/len;
        func_0038CE20((f32 *)&scaled,(f32 *)&cross,width2*len);
        vec_add_ba(&q2.pos[0],&a,&scaled);
        vec_sub_ab(&q2.pos[1],&a,&scaled);
        vec_add_ba(&q2.pos[2],&b,&scaled);
        vec_sub_ba(&q2.pos[3],&b,&scaled);
        if(i==0) q2.color[0]=q2.color[1]=color2;
        else if(i==count-2) q2.color[2]=q2.color[3]=color2;
        else if(i==1) q2.color[0]=q2.color[1]=c2;
        func_003D2DA0(&q2,0,0);
    }
    func_003A9440(0x47,0x5360B);
}
