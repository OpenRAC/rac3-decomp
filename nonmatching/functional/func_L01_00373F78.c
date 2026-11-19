/* functional: high. Verified vs PAL asm: pos/step VU maths, 12-iteration spark loop (rand ranges, tex args, particle byte copies from D_00221098 tables at 0xD4/0x16C), 25-iteration ring loop with rotation of velocity, particle field writes; multi-line asm strings compile under the file's compiler. */
#include "vu0.h"
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_00373F78;
typedef int Q_00373F78 __attribute__((mode(TI)));
extern s32 D_L01_001DDA44;
__asm__(".extern D_L01_001DDA44,4");
typedef struct { u8 p[0xD4]; u8 *a; u8 pad[0x16C-0xD8];u8 *b;} S_00373F78;
extern S_00373F78 D_L01_00221098;
extern u8 D_L01_001D66B0[] __attribute__((section(".sdata")));
extern V_00373F78 D_001A52A0[];
void func_L01_00373F78(u8 *obj) {
    extern void func_0038CE20(void *,void *,f32);
    extern f32 func_L01_00443A18(f32,f32);
    extern s32 func_00382468(s32);
    extern s32 func_00382498(s32,s32);
    extern u8 *func_L01_0046FB40(void *,void *,s32,u32,s32,s32,s32,s32,f32,f32,f32);
    extern void func_0038D890(void *,void *,void *,f32);
    extern f32 func_003824E0(f32,f32);
    extern f32 func_0038DAB8(f32,f32);
    extern u8 *func_L01_004660F8(void *,void *);
    extern void func_003C4840(void *,void *,f32);
    extern void func_0038D850(void *,void *,void *);
    V_00373F78 pos;
    V_00373F78 off;
    V_00373F78 step;
    V_00373F78 work;
    V_00373F78 rotation;
    V_00373F78 velocity;
    V_00373F78 axis;
    V_00373F78 temp;
    f32 spread,size,angle;
    s32 i,seed;
    u8 *particle;
    u8 *p;
    pos=*(V_00373F78 *)(*(u8 **)(obj+0x68)+0x10);
    func_0038CE20(&off,obj+0xD0,-0.15f);
    __asm__("lqc2 $vf2,%2
	lqc2 $vf1,%1
	vadd.xyz $vf1,$vf1,$vf2
	sqc2 $vf1,%0"
       : "=m"(pos) : "m"(pos),"m"(off) : "vf1","vf2");
    func_0038CE20(&step,obj+0xE0,0.3f);
    __asm__("lqc2 $vf1,%1
	lqc2 $vf2,%2
	vadd.xyz $vf1,$vf1,$vf2
	sqc2 $vf1,%0"
       : "=m"(pos) : "m"(pos),"m"(step) : "vf1","vf2");
    func_0038CE20(&step,obj+0xE0,-0.033333335f);
    if (D_L01_001DDA44) {size=0.4f;spread=0.3f;}
    else {size=0.175f;spread=0.1f;}
    for(i=11;i>=0;i--) {
        u8 *first,*second;
        work.x=pos.x+func_L01_00443A18(0.0f,spread);
        work.y=pos.y+func_L01_00443A18(0.0f,spread);
        work.z=pos.z+func_L01_00443A18(0.0f,spread);
        seed=func_00382468(255);
        first=func_L01_0046FB40(&work,D_L01_001D66B0,(func_00382498(7,12)*5+2)/6,0x808080,seed,127,127,1,size*210000.0f,size*210000.0f,0.0f);
        if (first) first[2]=D_L01_00221098.b[1];
        second=func_L01_0046FB40(&pos,D_L01_001D66B0,(func_00382498(7,12)*5+2)/6,0x203080,seed,16,16,1,472500.0f,472500.0f,0.0f);
        if (second) second[2]=D_L01_00221098.a[0];
        __asm__("lqc2 $vf2,%1
	lqc2 $vf1,%2
	vadd.xyz $vf2,$vf2,$vf1
	sqc2 $vf2,%0"
           : "=m"(pos) : "m"(pos),"m"(step) : "vf1","vf2");
    }
    work=pos;
    *(Q_00373F78 *)&axis=0;
    axis.x=0.3f;axis.y=-1.0f;axis.w=1.0f;
    func_0038D890(&axis,D_001A52A0,D_001A52A0+1,0.34906584f);
    velocity=axis;
    angle=0.0f;
    for (i=24;i>=0;i--) {
        angle=func_0038DAB8(angle,func_003824E0(0.0f,0.62831855f));
        func_0038CE20(&temp,&velocity,func_003824E0(0.120000005f,0.36f));
        particle=func_L01_004660F8(&work,&temp);
        if (particle) {
            func_0038CE20(&temp,&velocity,0.75f);
            p=particle+0x30;
            __asm__("lqc2 $vf2,%1
	lqc2 $vf1,%2
	vadd.xyz $vf2,$vf2,$vf1
	sqc2 $vf2,%0"
               : "=m"(*(V_00373F78 *)(particle+0x10)) : "m"(work),"m"(temp) : "vf1","vf2");
            *(V_00373F78 *)(particle+0x20)=work;
            *(f32 *)(p+12)=2.0f;
            *(u32 *)(particle+12)=0x507F7FFF;
            *(f32 *)(particle+0x1C)=0.05f;
            *(f32 *)(particle+0x2C)=0.5f;
            *(u32 *)(particle+4)=0x507F7F7F;
        }
        if (fabs_asm(angle)>0.00001f) {
            func_003C4840(&rotation,D_001A52A0,angle);
            func_0038D850(&velocity,&axis,&rotation);
        }
    }
}
