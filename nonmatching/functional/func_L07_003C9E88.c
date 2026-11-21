/* functional: high. Renderer-facing (draw packet); port may replace, kept as functional. */
#include "common.h"
/* localdecomp:start func_L07_003C9E88 */
#include "vu0.h"
static __inline__ void copy_003C9E88(vu0_v4 *d, vu0_v4 *a) {
    __asm__("lqc2 $vf1, %1\n\tsqc2 $vf1, %0" : "=m"(*d) : "m"(*a) : "vf1");
}
static __inline__ void sub_003C9E88(vu0_v4 *d, vu0_v4 *a, vu0_v4 *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
static __inline__ void add_003C9E88(vu0_v4 *d, vu0_v4 *a, vu0_v4 *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
static __inline__ void subba_003C9E88(vu0_v4 *d, vu0_v4 *a, vu0_v4 *b) {
    __asm__("lqc2 $vf1, %2\n\tlqc2 $vf2, %1\n\tvsub.xyz $vf1, $vf2, $vf1\n\tsqc2 $vf1, %0" : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
static __inline__ void addba_003C9E88(vu0_v4 *d, vu0_v4 *a, vu0_v4 *b) {
    __asm__("lqc2 $vf1, %2\n\tlqc2 $vf2, %1\n\tvadd.xyz $vf1, $vf2, $vf1\n\tsqc2 $vf1, %0" : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
static __inline__ void subba2_003C9E88(vu0_v4 *d, vu0_v4 *a, vu0_v4 *b) {
    __asm__("lqc2 $vf1, %2\n\tlqc2 $vf2, %1\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
static __inline__ void addba2_003C9E88(vu0_v4 *d, vu0_v4 *a, vu0_v4 *b) {
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
typedef struct { vu0_v4 pos[4]; s32 color[4]; f32 uv[8]; u8 rest[32]; } Draw_003C9E88;
void func_L07_003C9E88(vu0_v4 *arg0, vu0_v4 *arg1, f32 width, f32 offset) {
    extern void func_0038CE90(vu0_v4 *, vu0_v4 *, vu0_v4 *);
    extern void func_003D93B0(void *, s32, s32, s32);
    extern void func_003D2DA0(void *, s32, s32);
    extern f32 func_0038CF38(vu0_v4 *, vu0_v4 *);
    extern f32 func_00382538(void);
    extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
    vu0_v4 a, b, delta;
    Draw_003C9E88 draw;
    vu0_v4 t0, t1, t2, t3, t4, t5, t6;
    f32 w, distance;
    vu0_v4 *axis = &delta;
    w = width * 0.25f;
    copy_003C9E88(&t6, arg1);
    subba2_003C9E88(&t0, &t6, arg0);
    subba2_003C9E88(&a, arg0, (vu0_v4 *)D_L07_001E1EC0);
    copy_003C9E88(&delta, &t0);
    func_0038CE90(&a, &a, axis);
    func_0038CF68(&a, &a, w);
    subba_003C9E88(&b, arg1, (vu0_v4 *)D_L07_001E1EC0);
    func_0038CE90(&b, &b, axis);
    func_0038CF68(&b, &b, w);
    func_003D93B0(&draw, 43, 1, 128);
    copy_003C9E88(&t1, arg0);
    copy_003C9E88(&t2, arg1);
    copy_003C9E88(&t3, arg1);
    draw.color[0] = 0x40802020;
    draw.color[3] = 0x40802020;
    draw.color[2] = 0x40802020;
    draw.color[1] = 0x40802020;
    addba2_003C9E88(&draw.pos[0], arg0, &a);
    subba_003C9E88(&draw.pos[1], &t1, &a);
    addba_003C9E88(&draw.pos[2], &t2, &b);
    subba_003C9E88(&draw.pos[3], &t3, &b);
    draw.uv[0]=0; draw.uv[1]=0; draw.uv[2]=0; draw.uv[3]=1;
    draw.uv[4]=1; draw.uv[5]=0; draw.uv[6]=1; draw.uv[7]=1;
    func_003D2DA0(&draw, 0, 0);
    func_003D93B0(&draw, 39, 1, 128);
    draw.color[0]=-256; draw.color[2]=0x80FF0000;
    draw.color[1]=-256; draw.color[3]=0x80FF0000;
    width *= 0.35f;
    func_0038CF68(&a, &a, width);
    func_0038CF68(&b, &b, width);
    addba_003C9E88(&draw.pos[0], arg0, &a);
    copy_003C9E88(&t6, arg0);
    copy_003C9E88(&t4, arg1);
    copy_003C9E88(&t5, arg1);
    subba_003C9E88(&draw.pos[1], &t6, &a);
    addba_003C9E88(&draw.pos[2], &t4, &b);
    subba_003C9E88(&draw.pos[3], &t5, &b);
    distance=func_0038CF38(arg0,arg1)*0.6f;
    if (distance > 14.0f) distance=14.0f;
    draw.uv[7]=1; draw.uv[3]=1; draw.uv[1]=0; draw.uv[5]=0;
    draw.uv[2]=-7.0f-offset; draw.uv[0]=-7.0f-offset;
    draw.uv[6]=(distance + -7.0f)-offset; draw.uv[4]=(distance + -7.0f)-offset;
    func_003D2DA0(&draw,0,0);
    func_003D9508(arg0,71,0x60606020,1,0.9f,0.4f,func_00382538());
    func_003D9508(arg0,71,0x80FFFFFF,1,0.25f,0.4f,func_00382538());
    func_003D9508(arg1,71,0x60604020,0,0.75f,0.0f,func_00382538());
    func_003D9508(arg1,71,0x80FFFFFF,0,0.5f,0.0f,func_00382538());
}
/* localdecomp:end func_L07_003C9E88 */
