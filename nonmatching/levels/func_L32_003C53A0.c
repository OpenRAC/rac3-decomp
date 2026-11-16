/* PAL near miss (Codex wave 7): near miss: 277 words differ with the file's flags.
 * Worker's note: 278 diff; best build/codex/w350/func_L32_003C53A0.best.log; complete PAL C with operand/memory/clobber VU sequences; allocation and scheduling differ; fixed default assembler emits literal pool for 2pi. No alternate flags tried.
 */
#include "common.h"
/* localdecomp:start func_L32_003C53A0 */
typedef struct Vec_003C53A0 { f32 x,y,z,w; } __attribute__((aligned(16))) Vec_003C53A0;
extern f32 D_L32_001DF404, D_L32_001DF400;
extern u8 D_L32_001DF3F8;
extern s32 D_L32_001DF410[2];
extern u8 *D_L32_0021FAEC;
extern s32 D_L32_001DF3FC,D_L32_001DF3D4,D_L32_001DF3D0;
extern f32 D_L32_001DF3CC,D_L32_001DF3C8,D_L32_001DF3C4,D_L32_001DF3C0,D_L32_001DF3F4;
extern s32 D_L32_001DF420,D_L32_001DF3D8,D_L32_001DF3DC,D_L32_001DF3E0,D_L32_001DF3E4;
extern Vec_003C53A0 D_001A4C60;
void func_L32_003C53A0(u8 *m,u8 *s) {
    extern void func_00382580(void *,f32,f32);
    extern s32 func_00382498(s32,s32);
    extern f32 func_003824E0(f32,f32);
    extern s32 func_0038CB00(void *);
    extern f32 func_0038DB48(f32);
    extern void func_L32_00347C30(void *,void *,f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_0038CEA8(void *);
    extern void func_0038CF68(void *,void *,f32);
    extern void func_0038D890(void *,void *,void *,f32);
    extern f32 func_0038CF00(void *,void *);
    extern s32 func_0038DBD8(s32,s32,f32);
    u8 *owner,*st;
    Vec_003C53A0 delta,blend,toward,move;
    f32 length,phase,weight;
    s32 c1,c2,color;
    if (!s) return;
    owner=*(u8 **)s;
    if (!owner) return;
    st=*(u8 **)(owner+0x68);
    if (!st || !*(s32 *)(s+4)) return;
    if (*(u16 *)(s+0xa)&1) {
        func_00382580(m+0x10,0.0f,*(f32 *)(st+0x10));
        __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(Vec_003C53A0 *)(m+0x10)) : "m"(*(Vec_003C53A0 *)(m+0x10)), "m"(*(Vec_003C53A0 *)(owner+0x10)) : "vf1","vf2");
        *(s32 *)(m+4)=D_L32_001DF3E8;
        *(s16 *)(s+0xc)=0;
        *(f32 *)(s+0x18)=*(f32 *)(owner+0x10);
        *(f32 *)(s+0x1c)=*(f32 *)(owner+0x18);
        m[8]=func_00382498(0,255);
        *(f32 *)(m+0xc)=func_003824E0(D_L32_001DF404,D_L32_001DF400);
        m[3]=D_L32_001DF3F8;
        m[2]=D_L32_0021FAEC[D_L32_001DF410[func_00382498(0,2)]];
    }
    m[8]+=(*(s16 *)(s+0xe)%(D_L32_001DF3FC*2))-D_L32_001DF3FC;
    if (func_0038CB00(s+0xc)) {
        if (owner[0x20]==2 || owner[0x20]==3) {
            *(s16 *)(s+0xc)=func_00382498(D_L32_001DF3D4,D_L32_001DF3D0);
            *(f32 *)(s+0x10)=func_0038DB48(func_003824E0(0.0f,6.2831855f));
            *(f32 *)(s+0x14)=func_003824E0(D_L32_001DF3CC,D_L32_001DF3C8);
        } else goto other_mode;
    }
    if (owner[0x20]==2 || owner[0x20]==3) {
        *(u16 *)(m+0xa)+=1;
        if (owner[0x20]==2 || owner[0x20]==3) {
            func_L32_00347C30(m+0x10,s+0x18,*(f32 *)(owner+0x10));
            func_L32_00347C30(m+0x18,s+0x1c,*(f32 *)(owner+0x18));
            move.x=func_0038D098(*(f32 *)(s+0x10))**(f32 *)(s+0x14);
            move.z=func_0038D0B0(*(f32 *)(s+0x10))**(f32 *)(s+0x14);
            move.y=0;
            __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(Vec_003C53A0 *)(m+0x10)) : "m"(*(Vec_003C53A0 *)(m+0x10)), "m"(*(Vec_003C53A0 *)(&move)) : "vf1","vf2");
            __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(Vec_003C53A0 *)(&delta)) : "m"(*(Vec_003C53A0 *)(m+0x10)), "m"(*(Vec_003C53A0 *)(owner+0x10)) : "vf1","vf2");
            if (func_0038CEA8(&delta)<*(f32 *)(st+0x10)) length=func_0038CEA8(&delta);
            else length=*(f32 *)(st+0x10);
            func_0038CF68(&delta,&delta,length);
            __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(Vec_003C53A0 *)(m+0x10)) : "m"(*(Vec_003C53A0 *)(owner+0x10)), "m"(*(Vec_003C53A0 *)(&delta)) : "vf1","vf2");
            __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(Vec_003C53A0 *)(&toward)) : "m"(*(Vec_003C53A0 *)(&D_001A4C60)), "m"(*(Vec_003C53A0 *)(owner+0x10)) : "vf1","vf2");
            func_0038CF68(&toward,&toward,1.0f);
            __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(Vec_003C53A0 *)(&delta)) : "m"(*(Vec_003C53A0 *)(m+0x10)), "m"(*(Vec_003C53A0 *)(owner+0x10)) : "vf1","vf2");
            weight=func_003C4088(D_L32_001DF3C4,D_L32_001DF3C0,func_0038CEA8(&delta)/ *(f32 *)(st+0x10));
            func_0038D890(&blend,&delta,&toward,weight);
            __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(Vec_003C53A0 *)(m+0x10)) : "m"(*(Vec_003C53A0 *)(owner+0x10)), "m"(*(Vec_003C53A0 *)(&blend)) : "vf1","vf2");
        }
    } else {
other_mode:
        if (owner[0x20]==1) {
            __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(Vec_003C53A0 *)(&delta)) : "m"(*(Vec_003C53A0 *)(m+0x10)), "m"(*(Vec_003C53A0 *)(owner+0x10)) : "vf1","vf2");
            func_0038CF68(&delta,&delta,D_L32_001DF3F4);
            __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(Vec_003C53A0 *)(m+0x10)) : "m"(*(Vec_003C53A0 *)(m+0x10)), "m"(*(Vec_003C53A0 *)(&delta)) : "vf1","vf2");
        }
    }
    weight=(f32)s[0xe]*0.00390625f;
    phase=func_0038CF00(m+0x10,owner+0x10)/ *(f32 *)(st+0x10);
    phase+=(f32)(D_L32_001DF9C0%D_L32_001DF420)/(f32)D_L32_001DF420;
    phase-=(s32)phase;
    c1=func_0038DBD8(D_L32_001DF3D8,D_L32_001DF3DC,weight);
    c2=func_0038DBD8(D_L32_001DF3E0,D_L32_001DF3E4,weight);
    color=func_0038DBD8(c2,c1,func_0038D0B0(func_0038DB48(phase*6.2831855f))*0.5f+0.5f);
    if (owner[0x20]==3) {
        color=func_0038DBD8(color,D_L32_001DF3E8,(f32)*(s32 *)(st+0x18)/(f32)D_L32_001DF3B8);
        *(s32 *)(m+4)=color;
        *(s32 *)(m+4)=(color&0xffffff)|((s32)((f32)(D_L32_001DF3B8-*(s32 *)(st+0x18))*128.0f/(f32)D_L32_001DF3B8)<<24);
    } else if (owner[0x20]==2) {
        *(s32 *)(m+4)=(color&0xffffff)|0x80000000;
    } else if (owner[0x20]==1) {
        *(s32 *)(m+4)=color;
        *(s32 *)(m+4)=(color&0xffffff)|((s32)((f32)*(s16 *)(m+0xa)*128.0f/(f32)*(s16 *)(s+8))<<24);
    }
}
/* localdecomp:end func_L32_003C53A0 */
