/* functional: high. 190 words differ (table address hoisting, byte-index allocation); slot loop, random-call order, all float constants, particle field stores verified vs retail. */
/* PAL near miss (Codex wave 10): near miss: 190 words differ with the file's flags.
 * Worker's note: Best 190 diff: w489/func_L01_0031B4F8.c05.log; table address hoisted across outer loop versus retail rematerialization; residual inner-call/byte-index allocation; no metadata or flags changed
 */
#include "common.h"
/* localdecomp:start func_L01_0031B4F8 */
#include "vu0.h"
typedef struct { u8 bytes[8]; } Colors_0031B4F8;
extern Colors_0031B4F8 D_L01_001DC820;
extern u8 D_L01_00274580_0031B4F8[] __attribute__((section(".sdata")));
void func_L01_0031B4F8(void) {
    extern void func_003C5180(void *, f32 *, s32);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_00382538(void);
    extern void func_00382760(void *, f32, f32, f32);
    extern s32 func_00382498(s32, s32);
    extern s32 func_0013D3E0(void);
    extern u8 *func_L01_004669B0(void *, s32, void *, s32, f32, f32, f32, f32, s32);
    f32 pos[4], dir[4], velocity[4];
    Colors_0031B4F8 colors;
    s32 i, j, count;
    u8 *particle;
    u8 *p;
    E_31ABE0 *e;
    f32 speed,yaw,pitch;
    for(i=0;i<30;i++) {
        if (!((E_31ABE0 *)D_L01_00274580_0031B4F8)[i].id) continue;
        e=(E_31ABE0 *)(i*32+(u32)D_L01_00274580_0031B4F8);
        func_003C5180((u8 *)e->id+0x10,pos,1);
        func_0038CE20(pos,pos,((f32 *)e->id)[3]*0.0009765f*0.8f);
        pos[0]+=((f32 *)e->id)[0]*0.0009765f;
        pos[1]+=((f32 *)e->id)[1]*0.0009765f;
        pos[2]+=((f32 *)e->id)[2]*0.0009765f;
        for(j=2;j>=0;j--) {
            qzero(velocity);
            velocity[2]=func_003824E0(0.0200000014f,0.0300000012f);
            speed=((f32 *)e->id)[3]*0.0009765f*func_003824E0(0.5f,0.75f);
            yaw=func_00382538(); pitch=func_00382538();
            func_00382760(dir,speed,yaw,pitch);
            dir[0]+=((f32 *)e->id)[0]*0.0009765f;
            dir[1]+=((f32 *)e->id)[1]*0.0009765f;
            dir[2]+=((f32 *)e->id)[2]*0.0009765f;
            count=func_00382498(1,5);
            particle=func_L01_004669B0(dir,count,velocity,0x802040,0.0f,1.0f,1.01f,func_003824E0(0.25f,1.0f)*210000.0f,1);
            colors=D_L01_001DC820;
            if(particle) {
                p=particle+0x20;
                particle[3]=colors.bytes[(func_0013D3E0()%2)*4];
                *(s16 *)(particle+0xa)=29;
                particle[9]=0x44;
                *(f32 *)(p+0x1c)=4.0f;
                *(s32 *)(p+4)=3;
                p[0xa]=func_00382498(64,128);
                p[0xb]=particle[0xa];
            }
        }
    }
}
/* localdecomp:end func_L01_0031B4F8 */
