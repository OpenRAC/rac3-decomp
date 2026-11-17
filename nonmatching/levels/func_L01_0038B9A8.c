/* func_L01_0038B9A8: retail saves $s0-$s3 and $ra with sq in ascending 16-byte slots
 * ($s0 at 0x0, $ra at 0x40) in a 0x50 frame, so the function belongs in
 * config/levels/sq_ra_funcs.txt and its file must be compiled without -fopt-stack
 * (docs/wiki/Matching-Patterns.md, "Functions that save $ra with sq"). The body below
 * matches with the file's other flags; only the saves/restores need that rewrite. */
#include "common.h"
/* localdecomp:start func_L01_0038B9A8 */
typedef int Q_0038B9A8 __attribute__((mode(TI)));
extern float D_L01_001DDF30 __attribute__((section(".sdata")));
extern float D_L01_001DDF44 __attribute__((section(".sdata")));
extern float D_L01_001DDF48 __attribute__((section(".sdata")));
extern s32 D_L01_001DDF34 __attribute__((section(".sdata")));
extern s32 D_L01_001DDF38 __attribute__((section(".sdata")));
extern s32 D_L01_001DDF4C __attribute__((section(".sdata")));
extern s32 D_L01_001E1F1C;
extern float D_L01_001E1F20;
extern float D_L01_001E1F24;
extern float D_L01_001E1F28;
extern float D_L01_001E1F2C;
extern float D_L01_001E1F30;
extern float D_L01_001E1F34;
extern float D_L01_001E1F38;
extern float D_L01_001E1F3C;
extern float D_L01_001E1F40;
extern float D_L01_001E1F44;
extern float D_L01_001E1F48;
extern float D_L01_001E1F4C;
__asm__(".extern D_L01_001DDF30, 4");
__asm__(".extern D_L01_001DDF34, 4");
__asm__(".extern D_L01_001DDF38, 4");
__asm__(".extern D_L01_001DDF44, 4");
__asm__(".extern D_L01_001DDF48, 4");
__asm__(".extern D_L01_001DDF4C, 4");
u8 *func_L01_0038B9A8(void *position, void *direction, void *origin) {
    extern u8 *func_003C24B0(s32, s32);
    extern float func_00382538(void);
    u8 *obj=func_003C24B0(0x1888,0x80);
    if(obj) {
        u8 *vars=*(u8 **)(obj+0x68);
        *(Q_0038B9A8 *)(obj+0x10)=*(Q_0038B9A8 *)position;
        obj[0x30]=255;
        *(u16 *)(obj+0x32)=255;
        obj[0x20]=0;
        *(s32 *)(vars+0x24)=0x57;
        *(float *)(vars+0x28)=2.0f;
        *(s32 *)(vars+0x2C)=0x19;
        *(s32 *)(vars+0x20)=0;
        D_L01_001DDF34=0;
        D_L01_001DDF38=0;
        *(s32 *)(vars+0x30)=0x50;
        *(float *)(vars+0x34)=1.0f;
        D_L01_001DDF30=1.0f;
        *(Q_0038B9A8 *)(vars+0x10)=*(Q_0038B9A8 *)direction;
        *(s32 *)(vars+0x3C)=0x11;
        D_L01_001DDF44=1.0f;
        D_L01_001DDF48=1.0f;
        *(Q_0038B9A8 *)vars=*(Q_0038B9A8 *)origin;
        D_L01_001E1F1C=(D_L01_001DDF4C*5+2)/6;
        *(s32 *)(vars+0x38)=-1;
        D_L01_001E1F20=func_00382538();
        D_L01_001E1F24=func_00382538();
        D_L01_001E1F28=func_00382538();
        D_L01_001E1F2C=func_00382538();
        D_L01_001E1F30=func_00382538();
        D_L01_001E1F34=func_00382538();
        D_L01_001E1F38=func_00382538();
        D_L01_001E1F3C=func_00382538();
        D_L01_001E1F40=func_00382538();
        D_L01_001E1F44=func_00382538();
        D_L01_001E1F48=func_00382538();
        D_L01_001E1F4C=func_00382538();
    }
    return obj;
}
/* localdecomp:end func_L01_0038B9A8 */
