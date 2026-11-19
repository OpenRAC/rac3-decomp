/* functional: medium. retail reads uninitialised sp+0x10 vector (previous segment) on first non-first iteration; C zero-initialises it */
/* localdecomp:start func_L07_003BEB50 */
#include "vu0.h"
typedef struct { f32 x,y,z,w; } V_003BEB50;
extern V_003BEB50 D_L07_001E1EC0;
extern f32 D_L07_001E16A0[];
extern u8 D_L07_002A28B0[];
extern u8 D_L07_002A28BC[];
extern u32 D_L07_002A29A0[][2];
extern V_003BEB50 D_L07_002A29F0[];
static __inline__ void sub_003BEB50(V_003BEB50 *d, V_003BEB50 *a,V_003BEB50 *b) {
    __asm__ volatile("lqc2 $vf2,%1\n lqc2 $vf1,%2\n vsub.xyz $vf2,$vf2,$vf1\n sqc2 $vf2,%0" : "=m"(*d) : "m"(*a),"m"(*b):"vf1","vf2");
}
static __inline__ void add_003BEB50(V_003BEB50 *d, V_003BEB50 *a,V_003BEB50 *b) {
    __asm__ volatile("lqc2 $vf1,%1\n lqc2 $vf2,%2\n vadd.xyz $vf1,$vf1,$vf2\n sqc2 $vf1,%0" : "=m"(*d) : "m"(*a),"m"(*b):"vf1","vf2");
}
void func_L07_003BEB50(void *arg0, void *arg1, s32 count, s32 start, s32 arg4) {
    extern void func_0038C750(void);
    extern long func_00389598(s32);
    extern void func_003A9440(s32,long);
    extern f32 func_0038CEA8(V_003BEB50 *);
    extern void func_0038CE90(V_003BEB50 *,V_003BEB50 *,V_003BEB50 *);
    extern void func_0038CF68(V_003BEB50 *,V_003BEB50 *,f32);
    extern void func_0038CC88(void *,void *,s32);
    extern u32 func_0038DBD8(u32,u32,f32);
    extern void func_003D3A24(s32,void *,void *,void *,s32);
    V_003BEB50 delta,previous,normal,offset,tmp;
    V_003BEB50 *points=arg1;
    f32 total,t,length;
    s32 i,index,next;
    previous.x=0.0f; previous.y=0.0f; previous.z=0.0f; previous.w=0.0f;
    if(count<2)return;
    func_0038C750();
    total=0.0f;
    func_003A9440(6,func_00389598(arg4));
    func_003A9440(20,0xFF9000000260L);
    func_003A9440(8,0);
    func_003A9440(0x42,0x4000000044L);
    for(i=0;i<count;i++) {
        index=(i+start)%count;
        next=(index+1)%count;
        if(i!=count-1) {
            sub_003BEB50(&delta,&points[index],&points[next]);
            length=func_0038CEA8(&delta);
            total+=length;
            D_L07_001E16A0[i]=length;
        }
        if(i!=0 && i!=count-1) add_003BEB50(&normal,&delta,&previous);
        else *(u128_t *)&normal=*(u128_t *)&delta;
        if(((u8 *)arg0)[0x42]==7) {
            qzero(&offset);
            offset.z=0.5f;
        } else {
            sub_003BEB50(&tmp,&D_L07_001E1EC0,&points[index]);
            func_0038CE90(&offset,&tmp,&normal);
            func_0038CF68(&offset,&offset,0.5f);
        }
        add_003BEB50(&tmp,&points[index],&offset);
        func_0038CC88(D_L07_002A28B0+i*24,&tmp,12);
        sub_003BEB50(&tmp,&points[index],&offset);
        func_0038CC88(D_L07_002A28BC+i*24,&tmp,12);
    }
    total=1.0f/total;
    t=0.0f;
    for(i=0;i<count;i++) {
        u32 color=func_0038DBD8(0x804020,0x30202080,t);
        D_L07_002A29A0[i][0]=color;
        D_L07_002A29F0[i].x=t;
        D_L07_002A29F0[i].z=t;
        D_L07_002A29A0[i][1]=color;
        D_L07_002A29F0[i].y=0;
        D_L07_002A29F0[i].w=1;
        t+=D_L07_001E16A0[i]*total;
    }
    func_003D3A24(count*2,D_L07_002A28B0,D_L07_002A29A0,D_L07_002A29F0,1);
    func_003A9440(0x47,0x5360B);
}
/* localdecomp:end func_L07_003BEB50 */
