/* functional: medium. Near-miss draft, 5 words differ (load order of effect-call args). Uses sda alias externs from the draft (D_*_sda); fold into the file's own globals when porting. */
/* localdecomp:start func_L01_002F9310 */
#include "vu0.h"
extern s32 D_001DC310_sda, D_001DC2E0_sda, D_001DC308_sda, D_001DC30C_sda;
extern f32 D_001DC300_sda, D_001DC2D0_sda, D_001DC2C8_sda;
extern f32 D_L01_001DC304;
extern f32 D_L01_001DC2CC;
extern f32 D_L01_001DC2D8;
extern s32 D_L01_001DC2E4;
extern s32 D_L01_001DC2F4;
extern s32 D_L01_001DC2F8;
extern u32 D_L01_001DC2E4_002F9310[] __attribute__((section(".sdata")));
extern u32 D_L01_001DC2EC;
extern u8 D_L01_001D66B0[] __attribute__((section(".sdata")));
extern u8 *D_L01_00221190 __attribute__((section(".data")));
extern s32 D_L01_001DFB40;
__asm__(".extern D_001DC310_sda, 4");
__asm__(".extern D_001DC2E0_sda, 4");
__asm__(".extern D_001DC308_sda, 4");
__asm__(".extern D_001DC30C_sda, 4");
__asm__(".extern D_001DC300_sda, 4");
__asm__(".extern D_001DC2D0_sda, 4");
__asm__(".extern D_001DC2C8_sda, 4");
void func_L01_002F9310(u8 *m, s32 disabled) {
    extern s32 func_00382468(s32);
    extern f32 func_003824E0(f32,f32);
    extern s32 func_00382498(s32,s32);
    extern u32 func_0038DBD8(u32,u32,f32);
    extern void func_L01_0046B458(void *,f32,f32,s32,s32,s32,s32,void *,f32,s32);
    extern u8 *func_L01_0046C2E8(void *,s32,s32,s32,s32,s32,s32,s32,f32);
    extern void func_L01_00443B88(void *,f32,f32);
    extern void func_L01_0046C470(void *,void *,u32,s32,s32,s32,s32,s32,f32);
    vu0_v4 velocity, position;
    s32 direction, life;
    u32 color;
    u8 *effect;
    qzero(&velocity);
    if (!func_00382468(D_001DC310_sda)) {
        u8 *point=m+0x10;
        direction = func_00382468(1) ? -D_001DC308_sda : D_001DC308_sda;
        func_L01_0046B458(point,D_001DC300_sda,D_L01_001DC304,D_001DC30C_sda,D_L01_001DC2E4,2,direction,D_L01_001D66B0,0.0f,0);
    }
    effect=func_L01_0046C2E8(m+0x10,D_001DC2E0_sda,0,0,0,2,0,0,D_001DC2D0_sda);
    if(effect) effect[2]=*D_L01_00221190;
    if(!disabled && (D_L01_001DFB40 & 1)) {
        func_L01_00443B88(&position,0.0f,0.05f);
        vec_add_ba(&position,&position,m+0x10);
        velocity.z=-(func_003824E0(D_001DC2C8_sda,D_L01_001DC2CC)*0.020000001415610313f);
        life=(func_00382498(D_L01_001DC2F4,D_L01_001DC2F8)*5+2)/6;
        { f32 blend=func_003824E0(0.0f,1.0f); color=func_0038DBD8(D_L01_001DC2E4_002F9310[1],D_L01_001DC2EC,blend); }
        func_L01_0046C470(&position,&velocity,color,life,func_00382468(255)&255,0,64,0,D_L01_001DC2D8);
    }
}
/* localdecomp:end func_L01_002F9310 */
