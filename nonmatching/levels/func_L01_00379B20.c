/* PAL near miss (Codex wave 8): near miss: 181 words differ with the file's flags.
 * Worker's note: 181 diff in w386/func_L01_00379B20.04.log; 8 checks; six angle-update calls and fade calculations match; remaining alpha clamp emits srl instead of dsrl, 127 alpha scale emits float constant instead of integer conversion, and call/store scheduling differs. No ...
 */
#include "common.h"
/* localdecomp:start func_L01_00379B20 */
extern f32 D_001DDB14_sda;
__asm__(".extern D_001DDB14_sda, 4");
extern f32 D_001DDB18_sda;
__asm__(".extern D_001DDB18_sda, 4");
extern f32 D_001DDB1C_sda;
__asm__(".extern D_001DDB1C_sda, 4");
extern f32 D_001DDB20_sda;
__asm__(".extern D_001DDB20_sda, 4");
extern s32 D_001DDB44_sda;
__asm__(".extern D_001DDB44_sda, 4");
extern s32 D_001DDB48_sda;
__asm__(".extern D_001DDB48_sda, 4");
extern s32 D_001DDB4C_sda;
__asm__(".extern D_001DDB4C_sda, 4");
extern s32 D_001DDB50_sda;
__asm__(".extern D_001DDB50_sda, 4");
extern s32 D_001DDB54_sda;
__asm__(".extern D_001DDB54_sda, 4");
extern u8 D_L01_001E29C0[];
static __inline__ f32 fade_00379B20(f32 distance,f32 start,f32 end) {
    f32 t;
    if(distance<end) t=(distance-start)/(end-start);
    else t=1.0f;
    return t<0.0f ? 0.0f : t;
}
static __inline__ u32 color_00379B20(f32 opacity,u32 full) {
    u32 color=full;
    if(opacity!=1.0f) {
        s32 clamped=127;
        u8 alpha=(u8)(s32)(opacity*(s32)(full>>24));
        unsigned long high=alpha;
        high>>=7;
        if(!high) clamped=alpha;
        color=(clamped<<24)|(full&0xffffff);
    }
    return color;
}
void func_L01_00379B20(u8 *obj) {
    extern f32 func_003824E0(f32,f32);
    extern f32 func_0038DAB8(f32,f32);
    extern f32 func_L01_0040E570(void *,void *);
    extern void func_L01_0037BE80(u8 *,void *,s32,s32,u32,s32,f32,f32,f32,f32,f32,f32);
    extern void func_L01_0037BCF8(u8 *,void *,s32,u32,s32,f32,f32,f32);
    u8 *vars=*(u8 **)(obj+0x68);
    f32 distance;
    f32 nearFade,farFade;
    u32 color;
    *(f32 *)(vars+0x44)=func_0038DAB8(*(f32 *)(vars+0x44),func_003824E0(-0.5f,-1.0f)*0.017453292f);
    *(f32 *)(vars+0x34)=func_0038DAB8(*(f32 *)(vars+0x34),func_003824E0(-1.0f,-2.0f)*0.017453292f);
    *(f32 *)(vars+0x48)=func_0038DAB8(*(f32 *)(vars+0x48),func_003824E0(-1.0f,-1.5f)*0.017453292f);
    *(f32 *)(vars+0x38)=func_0038DAB8(*(f32 *)(vars+0x38),func_003824E0(1.5f,2.5f)*0.017453292f);
    *(f32 *)(vars+0x4c)=func_0038DAB8(*(f32 *)(vars+0x4c),func_003824E0(-0.5f,-1.5f)*0.017453292f);
    *(f32 *)(vars+0x3c)=func_0038DAB8(*(f32 *)(vars+0x3c),func_003824E0(0.5f,1.5f)*0.017453292f);
    distance=func_L01_0040E570(obj+0x10,D_L01_001E29C0);
    nearFade=fade_00379B20(distance,D_001DDB14_sda,D_001DDB18_sda);
    farFade=fade_00379B20(distance,D_001DDB1C_sda,D_001DDB20_sda);
    if(D_001DDB44_sda) {
        func_L01_0037BE80(obj,obj+0x10,0x47,0x48,0x8fff0032,0,1.0f,1.0f,1.7f,*(f32 *)(vars+0x44),*(f32 *)(vars+0x34),0.0f);
    }
    if(nearFade>0.0f && D_001DDB48_sda) {
        color=color_00379B20(nearFade,0x2f804020);
        func_L01_0037BCF8(obj,obj+0x10,0x1b,color,1,1.15f,0.0f,*(f32 *)(vars+0x34));
        func_L01_0037BCF8(obj,obj+0x10,0x1b,color,1,1.15f,0.0f,*(f32 *)(vars+0x38));
    }
    if(farFade>0.0f && D_001DDB4C_sda) {
        color=color_00379B20(farFade,0x7fff0032);
        func_L01_0037BCF8(obj,obj+0x10,0x4c,color,1,0.5f,0.0f,-*(f32 *)(vars+0x38));
        color=color_00379B20(farFade,0x7f300505);
        func_L01_0037BCF8(obj,obj+0x10,0x4c,color,1,0.2f,0.0f,*(f32 *)(vars+0x38));
    }
    if(nearFade>0.0f && D_001DDB50_sda) {
        color=color_00379B20(nearFade,0x8f804020);
        func_L01_0037BE80(obj,obj+0x10,0x47,0x48,color,0,1.0f,1.0f,1.7f,*(f32 *)(vars+0x48),*(f32 *)(vars+0x38),0.05f);
        color=color_00379B20(nearFade,0x8f20207f);
        func_L01_0037BE80(obj,obj+0x10,0x47,0x48,color,0,1.0f,1.0f,1.7f,*(f32 *)(vars+0x4c),*(f32 *)(vars+0x3c),0.1f);
    }
    if(farFade>0.0f && D_001DDB54_sda) {
        color=color_00379B20(farFade,0x7f204080);
        func_L01_0037BCF8(obj,obj+0x10,0x4b,color,0,0.6f,0.0f,*(f32 *)(vars+0x34));
    }
}
/* localdecomp:end func_L01_00379B20 */
