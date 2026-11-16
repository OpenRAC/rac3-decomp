/* NTSC-U draft (Codex wave 3): C of func_L03_00397998, the NTSC-U twin of func_L03_00399010, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 14 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L03_00397998", whose code is not the PAL one).
 * Worker's note: 14 diff; best log w72/func_L03_00397998.check10.log. Improved inherited15 by fixing loop addu operand order with integer address sum. Remaining initial index s2 vs s0 and grouped index/state scaling vs retail index<<7 copy to s4. Long offset check04 ...
 */
#include "common.h"
/* localdecomp:start func_L03_00397998 */
typedef struct {u8 pad[0x4D0]; f32 target,speed;u8 pad4D8[0x10];s32 effect;s16 state;} Vars_397998;
extern f32 func_L03_00397B98(s32,s32);
extern f32 func_L01_00445758(void *,void *,f32,f32,f32,f32,s32);
extern f32 func_00389380(f32,f32);
extern f32 func_003893C8(f32,f32);
extern s32 D_001A74A4[];
__asm__(".extern D_001A74A4, 16");
extern u8 D_001A30B0[];
extern void func_L01_004FC518(s32,s32);
extern void func_0039FB08(s32);
extern s32 func_0039FE80(s32,s32,void *);
extern void func_L01_00441FB8(void *,s32,s32);
void func_L03_00397998(u8 *m,s32 index,s32 state) {
    Vars_397998 *v=*(Vars_397998 **)(m+0x68);
    f32 *angle;
    f32 step,target;
    s32 i;
    s32 offset;
    s32 effect;
    u8 *e;
    if(v->state==-1) {
        v->state=0;
        v->speed=0.0f;
        v->target=func_L03_00397B98(0,-1);
    }
    offset=index<<7;
    angle=(f32 *)((u8 *)v+0x3C0+(index*4+v->state)*0x20);
    target=func_L03_00397B98(3,-1);
    step=func_L01_00445758(angle,&v->speed,target,0.0004848137f,0.0004848137f,45.0f,0);
    for(i=3;i>v->state;i--) {
        f32 *p=(f32 *)(offset+(u32)v+(i<<5));
        *(f32 *)((u8 *)p+0x3C0)=func_00389380(*(f32 *)((u8 *)p+0x3C0),step);
    }
    if(func_003893C8(*(f32 *)((u8 *)v+((v->state<<5)+offset)+0x3C0),v->target)<=0.0f) {
        if(v->state<3) {
            v->state++;
            v->target=func_L03_00397B98(v->state,-1);
        } else {
            v->speed=0.0f;
            v->state=-1;
            D_001A74A4[0]=0;
            func_L01_004FC518(0,1);
            effect=v->effect;
            if(effect!=-1) {
                e=D_001A30B0+(effect<<7);
                if(*(u8 **)(e+0xDC)==m && e[0xD0])func_0039FB08(effect);
            }
            v->effect=-1;
            v->effect=func_0039FE80(0,4,m);
            func_L01_00441FB8(m,state,-1);
        }
    }
}
/* localdecomp:end func_L03_00397998 */
