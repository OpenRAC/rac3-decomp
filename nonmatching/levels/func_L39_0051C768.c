/* NTSC-U draft (Codex wave 3): C of func_L39_0051C418, the NTSC-U twin of func_L39_0051C768, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 292 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L39_0051C418", whose code is not the PAL one).
 * Worker's note: 292 diff without injection (c418-1.log); 243 diff with actual divs_table [2,0] (best log c418-2.log); retail total pre-div nops 2 0; four checks; nested collision control and initialization reorder give same 243 wrong bytes; allocation/VU0 scheduling remain; ...
 */
#include "common.h"
typedef int Q20 __attribute__((mode(TI)));
typedef struct { float x,y,z,w; } __attribute__((aligned(16))) vu0_v4;
typedef struct { float x,y,z; } Params418;
typedef union { Q20 q[3]; u8 b[48]; float f[12]; int w[12]; } Query418;
static __inline__ void add20(void *d, void *a, void *b) {
    __asm__("lqc2 $vf1, %1; lqc2 $vf2, %2; vadd.xyz $vf1, $vf1, $vf2; sqc2 $vf1, %0" : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a),"m"(*(vu0_v4 *)b) : "vf1", "vf2");
}
static __inline__ void sub20(void *d, void *a, void *b) {
    __asm__("lqc2 $vf1, %1; lqc2 $vf2, %2; vsub.xyz $vf1, $vf1, $vf2; sqc2 $vf1, %0" : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a),"m"(*(vu0_v4 *)b) : "vf1", "vf2");
}
static __inline__ void add_ba418(void *d, void *a, void *b) {
    __asm__("lqc2 $vf2, %1; lqc2 $vf1, %2; vadd.xyz $vf2, $vf2, $vf1; sqc2 $vf2, %0" : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a),"m"(*(vu0_v4 *)b) : "vf1", "vf2");
}
/* localdecomp:start func_L39_0051C418 */
extern Params418 D_L39_0024A960;
extern float D_001DF0C8_sda;
__asm__(".extern D_001DF0C8_sda, 4");
extern u8 *D_L39_0024CF1C;
extern Q20 D_L39_0025F860;
extern Q20 D_L39_0024DF40;
extern void func_00388880(void *,void *,float);
extern int func_00388398(void *);
extern void func_L39_005FD658(int);
extern void func_L39_005FD6D8(void);
extern int func_003CE740(void *,void *,int,void *,void *);
extern int func_003D00C0(void);
extern int func_003CF790(void *,int,void *,void *,float);
extern int func_L01_0032FE90(void *,int,int,int,int,int,int,int,float,float,float,float,
int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int);
extern void func_L39_0051C918(void *,int);
extern void func_003BD360(void *);
extern float func_00389380(float,float);
extern void func_00388830(void *,void *,float);
extern float func_L39_005B2568(float,float);
extern void func_003886E8(void *,void *,float);
extern int func_L39_005B2498(int);
extern void func_00388758(void *,void *,void *);
extern void func_00389158(void *,void *,void *,float);
extern float func_00388770(void *);
extern float func_L39_005B2510(float,float);
extern int func_L39_005B24C8(int,int);
extern void func_L39_005C7680(void *,void *,int,int,float);
void func_L39_0051C418(u8 *a) {
    struct { Q20 old; Params418 params; Query418 query; Q20 delta, current, cross, spark; } local;
    u8 *d;
    u8 *pos=a+0x10;
    int result,n,i,remain;
    u8 **slot;
    float scale,length;
    local.params=D_L39_0024A960;
    d=*(u8 **)(a+0x68);
    local.old=*(Q20 *)pos;
    add20(pos,pos,d);
    if(*(float *)(a+0x10)<0.0f || *(float *)(a+0x14)<0.0f || *(float *)(a+0x18)<0.0f) goto destroy;
    local.query.w[4]=*(int *)(d+0x18);
    local.query.w[5]=0x10001;
    local.query.f[7]=D_001DF0C8_sda;
    local.query.w[8]=1;
    local.query.q[0]=*(Q20 *)d;
    func_00388880(&local.query,&local.query,1.0f);
    local.query.f[2]=1.0f; local.query.f[3]=5627.925f;
    local.query.b[0x19]=1; *(unsigned short *)(local.query.b+0x1A)=*(unsigned short *)(a+0xAA);
    local.query.b[0x18]=1; local.query.w[10]=*(int *)(d+0x60);
    if(func_00388398(d+0x10)) goto destroy;
    n=*(int *)(d+0x18);
    func_L39_005FD658(D_L39_0024CF1C?*(int *)(D_L39_0024CF1C+0x2548):-1);
    result=func_003CE740(&local.old,pos,0,(void *)n,&local.query);
    func_L39_005FD6D8();
    if(result && func_003D00C0()) {
            *(Q20 *)pos=D_L39_0025F860;
            local.query.f[7]=D_001DF0C8_sda*0.5f;
            func_003CF790(pos,0,*(void **)(d+0x18),&local.query,2.0f);
            func_L01_0032FE90(pos,0,2,3,2,4,0,0,0.4f,0.0f,0.0f,2.0f,
                0,0,0,0,0,0,0x1010000,0,0x388EF7,0x63F7,0x407FFF,0x20FF,0x8FFF,0x3064FF,0x7F60A0FF,0x280000FF,0x3064FF,0);
            goto destroy;
    }
    if(result && *(int *)(d+0x10)>=4) *(int *)(d+0x10)=3;
    goto proceed;
destroy:
    func_L39_0051C918(a,0);
    func_003BD360(a);
    return;
proceed:
    *(float *)(a+0xF4)=func_00389380(*(float *)(a+0xF4),local.params.y);
    remain=*(int *)(d+0x14)-*(int *)(d+0x10);
    if(remain<13) scale=((float)remain/13.0f)*0.15f;
    else scale=0.15f;
    sub20(&local.delta,&local.old,pos);
    func_00388830(&local.delta,&local.delta,scale);
    local.current=*(Q20 *)pos;
    if(*(u8 **)(d+0x1C)) *(Q20 *)(*(u8 **)(d+0x1C)+0x10)=local.current;
    slot=(u8 **)(d+0x20);
    for(i=15;i>=0;i--,slot++) {
        u8 *m=*slot;
        if(m) {
            add_ba418(m+0x10,&local.current,&local.delta);
            local.current=*(Q20 *)(m+0x10);
            *(float *)(m+0x10)+=func_L39_005B2568(0.0f,0.125f);
            *(float *)(m+0x14)+=func_L39_005B2568(0.0f,0.125f);
            *(float *)(m+0x18)+=func_L39_005B2568(0.0f,0.125f);
            func_003886E8(&local.delta,&local.delta,1.05f);
        }
    }
    if(func_L39_005B2498(5)) return;
    func_00388758(&local.cross,&local.delta,&D_L39_0024DF40);
    func_00389158(&local.cross,&local.cross,&local.delta,func_L39_005B2568(0.0f,3.14159274f));
    length=func_00388770(&local.cross);
    if(length==0.0f) return;
    func_003886E8(&local.spark,&local.cross,func_L39_005B2510(0.00833333377f,0.0333333351f)/length);
    n=func_L39_005B24C8(10,15);
    func_L39_005C7680(a+0x10,&local.spark,0x7F2F4F6F,n,70000.0f);
    return;
}
/* localdecomp:end func_L39_0051C418 */
