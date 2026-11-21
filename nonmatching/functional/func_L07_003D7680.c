/* functional: high. PAL near-miss draft re-read against PAL asm in full (6 faces, point interpolation, 0.11 smoothing, 0.02 and 8.0 offsets, index/total bookkeeping, both draw submissions); only VU scheduling and spills differ. */
#include "common.h"
#include "vu0.h"
extern vu0_v4 D_L07_002A2DC0[];
extern vu0_v4 D_L07_001E1EC0[];
extern f32 D_L07_002A2E40[][3];
extern f32 D_L07_002A32C0[][3];
extern s32 D_L07_002A3740[], D_L07_002A38C0[];
extern f32 D_L07_002A3A40[][2];
static __inline__ void add_ab_003D7680(void *d,void *a,void *b)
{
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
       : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a),"m"(*(vu0_v4 *)b) : "vf1","vf2");
}
static __inline__ void add_ba_003D7680(void *d,void *a,void *b)
{
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
       : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a),"m"(*(vu0_v4 *)b) : "vf1","vf2");
}
static __inline__ void sub_ab_003D7680(void *d,void *a,void *b)
{
    __asm__("lqc2 $vf1, %2\n\tlqc2 $vf2, %1\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
       : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a),"m"(*(vu0_v4 *)b) : "vf1","vf2");
}
void func_L07_003D7680(void *arg0, f32 radius, f32 offset, s32 count)
{
    extern f32 func_0038DAB8(f32,f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern void func_0038CE20(void *,void *,f32);
    extern void func_0038CE90(void *,void *,void *);
    extern void func_0038CF68(void *,void *,f32);
    extern void func_003C4C18(void *,f32);
    extern long func_00389598(s32);
    extern void func_003A9440(s32,long);
    extern void func_0038C750(void);
    extern void func_003D3A24(s32,void *,void *,void *,s32);
    vu0_v4 origin, previous, next, step, view, normal, temp, minus;
    s32 last=count-1;
    s32 face, i;
    s32 total=0, outer_index=0, inner_index=0;
    f32 angle, inv;
    f32 *inner,*outer;
    u8 *obj=arg0;
    *(vu0_q *)&origin=*(vu0_q *)(obj+0x10);
    origin.z+=0.45f;
    angle=func_0038DAB8(*(f32 *)(obj+0xF8),offset);
    inv=1.0f/last;
    previous.x=func_0038D098(angle)*radius;
    previous.y=func_0038D0B0(angle)*radius;
    previous.z=0.0f;
    add_ab_003D7680(&previous,&origin,&previous);
    face=0;
    do {
        face++;
        angle=func_0038DAB8(angle,1.0471976f);
        next.x=func_0038D098(angle)*radius;
        next.y=func_0038D0B0(angle)*radius;
        next.z=0.0f;
        add_ba_003D7680(&next,&origin,&next);
        sub_ab_003D7680(&step,&next,&previous);
        func_0038CE20(&step,&step,inv);
        *(vu0_q *)&D_L07_002A2DC0[0]=*(vu0_q *)&previous;
        for(i=1;i<count;i++) {
            if(i==last) *(vu0_q *)&D_L07_002A2DC0[i]=*(vu0_q *)&next;
            else add_ab_003D7680(&D_L07_002A2DC0[i],&D_L07_002A2DC0[i-1],&step);
        }
        for(i=1;i<last;i++) func_003C4C18(&D_L07_002A2DC0[i],0.11f);
        inner=(f32 *)((u8 *)D_L07_002A2E40+inner_index);
        outer=(f32 *)((u8 *)D_L07_002A32C0+outer_index);
        for(i=0;i<count;i++) {
            if(i!=0 || total==0) {
                sub_ab_003D7680(&view,D_L07_001E1EC0,&D_L07_002A2DC0[i]);
                func_0038CE90(&normal,&step,&view);
                func_0038CF68(&normal,&normal,0.02f);
                add_ba_003D7680(&temp,&D_L07_002A2DC0[i],&normal);
                inner[0]=temp.x; inner[1]=temp.y; inner[2]=temp.z;
                sub_ab_003D7680(&minus,&D_L07_002A2DC0[i],&normal);
                inner[3]=minus.x; inner[4]=minus.y; inner[5]=minus.z;
                func_0038CE20(&normal,&normal,8.0f);
                add_ba_003D7680(&temp,&D_L07_002A2DC0[i],&normal);
                outer[0]=temp.x; outer[1]=temp.y; outer[2]=temp.z;
                sub_ab_003D7680(&minus,&D_L07_002A2DC0[i],&normal);
                outer[3]=minus.x; outer[4]=minus.y; outer[5]=minus.z;
                total+=2;
                inner_index+=24;
                outer_index+=24;
                inner+=6;
                outer+=6;
            }
        }
        *(vu0_q *)&previous=*(vu0_q *)&next;
    } while(face<6);
    func_003A9440(6,func_00389598(0x2B));
    func_003A9440(8,0);
    func_003A9440(0x42,0x8000000048L);
    func_0038C750();
    func_003D3A24(total,D_L07_002A2E40,D_L07_002A3740,D_L07_002A3A40,1);
    func_003A9440(6,func_00389598(0x2B));
    func_0038C750();
    func_003D3A24(total,D_L07_002A32C0,D_L07_002A38C0,D_L07_002A3A40,1);
}
