/* functional: high. Draft read against asm, all branches (hero state 29, 0x2874==1, 0x16B0==1 w/o target, target, default) agree. Compiles in file context. */
#include "common.h"
/* localdecomp:start func_L01_00383FB8 */
#include "vu0.h"
#include "structs/weapon.h"
typedef int Q_00383FB8 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_00383FB8;
extern V_00383FB8 D_L01_001E29E0[];
extern V_00383FB8 D_L01_001E29C0;
extern V_00383FB8 D_L01_001EAA20;
extern u8 D_L01_001E0140[];
extern u8 D_001425C0[];
extern struct WeaponRow D_L01_002C5600[];
u8 *func_L01_00383FB8(u8 *owner,Q_00383FB8 *position,u8 *target,Q_00383FB8 *data) {
    extern void func_L01_004CB128(void *,void *,s32);
    extern void func_0038CE20(Q_00383FB8 *,Q_00383FB8 *,f32);
    extern void func_0038CF68(void *,void *,f32);
    extern s32 func_003D3CB0(void *,void *,s32,void *,s32);
    extern void func_0038CE90(void *,void *,void *);
    extern f32 func_003824E0(f32,f32);
    extern f32 func_L01_00443A18(f32,f32);
    extern f32 func_00382538(void);
    extern void func_L01_0044BE50(void *,void *,s32);
    V_00383FB8 target_pos, start, off1, off2, end, delta;
    u8 *obj=(u8 *)func_003C24B0(0x1873,128);
    u8 *d;
    u8 *hero;
    V_00383FB8 *axes;
    if(obj) {
        *(Q_00383FB8 *)(obj+0x10)=*position;
        d=*(u8 **)(obj+0x68);
        obj[0x30]=255;
        *(u16 *)(obj+0x32)=255;
        obj[0x31]=1;
        *(u16 *)(obj+0x34)|=0x100;
        obj[0x20]=0;
        *(s32 *)(d+0x50)=-1;
        if(target) {
            func_L01_004CB128(&target_pos,target,0);
            *(u8 **)(d+0x10)=target;
        } else qzero(&target_pos);
        hero=(u8 *)&D_001A4BE0;
        if(*(s32 *)(hero+0x25C4)==29) {
            axes=D_L01_001E29E0;
            *(Q_00383FB8 *)(obj+0xC0)=*(Q_00383FB8 *)&axes[0];
            *(Q_00383FB8 *)(obj+0xD0)=*(Q_00383FB8 *)&axes[1];
            *(Q_00383FB8 *)(obj+0xE0)=*(Q_00383FB8 *)&axes[2];
            *(Q_00383FB8 *)(obj+0x10)=*(Q_00383FB8 *)&D_L01_001E29C0;
            func_0038CE20((Q_00383FB8 *)&start,(Q_00383FB8 *)&axes[2],-0.2f);
            __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(V_00383FB8 *)(obj+0x10)) : "m"(start), "m"(*(V_00383FB8 *)(obj+0x10)) : "vf1","vf2");
            func_0038CE20((Q_00383FB8 *)&off1,(Q_00383FB8 *)&axes[1],-0.25f);
            __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(V_00383FB8 *)(obj+0x10)) : "m"(off1), "m"(*(V_00383FB8 *)(obj+0x10)) : "vf1","vf2");
            func_0038CE20((Q_00383FB8 *)&off2,(Q_00383FB8 *)&axes[0],0.0f);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(V_00383FB8 *)(obj+0x10)) : "m"(*(V_00383FB8 *)(obj+0x10)), "m"(off2) : "vf1","vf2");
            if(target) {
                __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(V_00383FB8 *)(obj+0xC0)) : "m"(target_pos), "m"(*(V_00383FB8 *)(obj+0x10)) : "vf1","vf2");
                func_0038CF68(obj+0xC0,obj+0xC0,1.0f);
            } else {
                func_0038CE20((Q_00383FB8 *)&end,(Q_00383FB8 *)axes,30.0f);
                __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(end) : "m"(D_L01_001E29C0), "m"(end) : "vf1","vf2");
                if(func_003D3CB0(&D_L01_001E29C0,&end,0,*(u8 **)(hero+0x25C0),0)) end=D_L01_001EAA20;
                __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(delta) : "m"(end), "m"(*(V_00383FB8 *)(obj+0x10)) : "vf1","vf2");
                func_0038CF68(obj+0xC0,&delta,1.0f);
            }
            func_0038CE90(obj+0xD0,obj+0xC0,*(u8 **)(hero+0x25C0)+0xE0);
            func_0038CF68(obj+0xD0,obj+0xD0,1.0f);
            func_0038CE90(obj+0xE0,obj+0xD0,obj+0xC0);
        } else if(*(s16 *)(hero+0x2874)==1) {
            func_0038CF68(obj+0xC0,owner+0xD0,-1.0f);
            func_0038CE20((Q_00383FB8 *)(obj+0xD0),(Q_00383FB8 *)(owner+0xC0),-1.0f);
            *(Q_00383FB8 *)(obj+0xE0)=*(Q_00383FB8 *)(owner+0xE0);
        } else if(*(s32 *)(hero+0x16B0)==1 && !target) {
            axes=D_L01_001E29E0;
            *(Q_00383FB8 *)(obj+0xC0)=*(Q_00383FB8 *)&axes[0];
            *(Q_00383FB8 *)(obj+0xD0)=*(Q_00383FB8 *)&axes[1];
            *(Q_00383FB8 *)(obj+0xE0)=*(Q_00383FB8 *)&axes[2];
        } else if(target) {
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(V_00383FB8 *)(obj+0xC0)) : "m"(target_pos), "m"(*(V_00383FB8 *)(obj+0x10)) : "vf1","vf2");
            func_0038CF68(obj+0xC0,obj+0xC0,1.0f);
            func_0038CE90(obj+0xD0,obj+0xC0,*(u8 **)(hero+0x25C0)+0xE0);
            func_0038CF68(obj+0xD0,obj+0xD0,1.0f);
            func_0038CE90(obj+0xE0,obj+0xD0,obj+0xC0);
        } else {
            *(Q_00383FB8 *)(obj+0xC0)=*(Q_00383FB8 *)(hero+0x6F0);
            func_0038CE90(obj+0xD0,obj+0xC0,hero+0x6E0);
            func_0038CF68(obj+0xD0,obj+0xD0,1.0f);
            func_0038CE90(obj+0xE0,obj+0xD0,obj+0xC0);
        }
        *(f32 *)(obj+0xCC)=0;
        *(f32 *)(obj+0xEC)=0;
        *(f32 *)(obj+0xDC)=0;
        *(u8 **)(d+0xC)=owner;
        *(f32 *)(d+0x1C)=func_003824E0(4.0f,10.0f);
        *(f32 *)(d+0x20)=func_L01_00443A18(6.0f,10.0f);
        *(f32 *)(d+0x18)=D_L01_002C5600[D_001425C0[0x97]].shot_speed*0.020000001415610313f;
        *(f32 *)(d+0x28)=func_00382538();
        d[0x27]=1;
        d[0x26]=1;
        *(Q_00383FB8 *)(d+0x30)=*(Q_00383FB8 *)(obj+0xC0);
        *(Q_00383FB8 *)(d+0x40)=*data;
        *(s16 *)(d+0x24)=250;
        if(target) {
            f32 *p=(f32 *)(target+0x10);
            *(f32 *)d=p[0];
            *(f32 *)(d+4)=p[1];
            *(f32 *)(d+8)=p[2];
        }
        start=*(V_00383FB8 *)(owner+0x10);
        start.z=((f32 *)position)[2];
        if(func_003D3CB0(&start,position,0,*(u8 **)(hero+0x25C0),0)) {
            obj[0xBC]=1;
            *(V_00383FB8 *)(obj+0x10)=D_L01_001EAA20;
        }
        func_003C7C38(obj);
        func_L01_0044BE50(obj,D_L01_001E0140,31);
        *(s32 *)(d+0x54)=func_L01_004C85C8(obj,0,0.6f,1.0f,1.0f);
        *(f32 *)(obj+0x2C)*=2.5f;
    }
    return obj;
}
/* localdecomp:end func_L01_00383FB8 */
