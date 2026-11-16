/* PAL near miss (Codex wave 8): near miss: 128 words differ with the file's flags.
 * Worker's note: 122 actual word differences: build/codex/w435/func_L07_003AB678-02.log. Fixed default assembler emits lit4 loads where retail materializes floats inline; no alternate flags tested. Existing vu0.h helpers fail without VU allocation flag (01.log); retained two ...
 */
#include "common.h"
/* localdecomp:start func_L07_003AB678 */
#include "vu0.h"
typedef struct { u8 pad0[0x164]; u8 *texture; } Effects_003AB678;
extern Effects_003AB678 D_L07_0021EC98;
void func_L07_003AB678(u8 *object) {
    extern void func_003C2F58(u8 *,s32,f32 *);
    extern void func_0038CE20(void *,void *,f32);
    extern s32 func_00382498(s32,s32);
    extern s32 func_00382468(s32);
    extern f32 func_003824E0(f32,f32);
    extern f32 func_00382538(void);
    extern void func_003C4C18(void *,f32);
    extern void func_00382760(void *,f32,f32,f32);
    extern u8 *func_L01_0046FB40(void *,void *,s32,u32,s32,s32,s32,s32,f32,f32,f32);
    vu0_v4 origin,position,velocity;
    u8 *state=*(u8 **)(object+0x68);
    f32 speed,angle,size;
    s32 n;
    s32 duration;
    u8 kind;
    u8 frame;
    u8 *effect;
    if(*(f32 *)(state+0x538)==1.0f) {
        *(vu0_q *)&origin=*(vu0_q *)(state+0x520);
    } else {
        func_003C2F58(object,state[0x533],(f32 *)&position);
        /* The fixed file flags do not enable the header's VU register operands. */
        __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(origin) : "m"(*(vu0_v4 *)(state+0x520)), "m"(position) : "vf1", "vf2");
        func_0038CE20(&origin,&origin,*(f32 *)(state+0x538));
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(origin) : "m"(position), "m"(origin) : "vf1", "vf2");
    }
    n=func_00382498(0,2);
    if(n>0) do {
        *(vu0_q *)&position=*(vu0_q *)&origin;
        func_003C4C18(&position,0.3f);
        speed=func_003824E0(3.0f,5.5f)*0.020000001415610313f;
        angle=func_00382538();
        func_00382760(&velocity,speed,angle,func_003824E0(1.0471975803375244f,3.1415927410125732f));
        kind=253;
        if(func_00382468(2)==0) kind=3;
        frame=func_00382468(256);
        duration=(func_00382498(20,40)*5+2)/6;
        size=func_003824E0(0.25f,0.75f)*210000.0f;
        effect=func_L01_0046FB40(&position,&velocity,duration,0x806020,kind,127,0,0,size,size,0.003920000046491623f);
        size*=0.3f;
        if(effect) {
            effect[2]=*D_L07_0021EC98.texture;
            frame=effect[8]+32;
        }
        effect=func_L01_0046FB40(&position,&velocity,duration,0xFFFFFF,kind,127,64,0,size,size,0.003920000046491623f);
        if(effect) {
            effect[8]=frame;
            effect[2]=*D_L07_0021EC98.texture;
        }
    } while(--n);
}
/* localdecomp:end func_L07_003AB678 */
