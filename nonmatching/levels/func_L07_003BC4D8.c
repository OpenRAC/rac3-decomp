/* PAL near miss (Codex wave 7): near miss: 98 words differ with the file's flags.
 * Worker's note: 92 diff; build/codex/w349/logs/func_L07_003BC4D8.wrap1.log; fixed assembler adds three nop hazards after mfc1 that retail omits (compiler asm saved as L07-compiler-asm.txt); tail store scheduling/FPU allocation also differ; no alternate flags used
 */
#include "common.h"
/* localdecomp:start func_L07_003BC4D8 */
typedef int Q_003BC4D8 __attribute__((mode(TI)));
void func_L07_003BC4D8(u8 *obj) {
    extern void func_L01_00445F40(void *,s32);
    extern s32 func_L07_003C1AF8(void);
    extern f32 func_L07_003C1B40(s32);
    extern void func_L01_00446058(void *,s32,s32);
    extern void func_L07_003BCD80(void *);
    u8 *p=*(u8 **)(obj+0x68);
    u8 *sub;
    u8 *g;
    u8 *other;
    s32 mode;
    f32 scale;
    func_L01_00445F40(obj,0x19D2);
    sub=p+0x120;
    mode=func_L07_003C1AF8();
    scale=func_L07_003C1B40(mode);
    *(s16 *)(sub+4)=(s16)(*(s16 *)(p+0x124)*scale);
    *(f32 *)(p+0x120)=*(s16 *)(sub+4);
    sub[0x14]=(u8)(p[0x134]*scale);
    sub[0x15]=(u8)(p[0x135]*scale);
    sub[0x16]=(u8)(p[0x136]*scale);
    if(mode==1 || mode==3) func_L01_00446058(obj,0x1D88,0x19D2);
    sub[0x28]=20;
    sub[0x2A]=14;
    *(f32 *)(sub+0x10)=0.25f;
    sub[9]=0;
    *(Q_003BC4D8 *)(p+0x240)=*(Q_003BC4D8 *)(obj+0x10);
    *(Q_003BC4D8 *)(p+0x250)=*(Q_003BC4D8 *)(obj+0xF0);
    other=p+0x160;
    other[0x12]=255;
    other[0x10]=7;
    other[0x48]=255;
    other[0x11]=255;
    g=p+0x30;
    *(f32 *)(p+0x30)=0.8f;
    *(u32 *)(g+0x38)|=0x404;
    *(f32 *)(g+4)=-0.3f;
    *(f32 *)(g+0x34)=0.3f;
    *(f32 *)(g+0x2C)=0.003920000046491623f;
    *(f32 *)(g+0xB4)=0.1256637126f;
    *(f32 *)(g+0x18)=0.005026548635214567f;
    *(s32 *)(g+0xEC)=0;
    *(f32 *)(g+0x14)=0.005026548635214567f;
    obj[0x62]=0;
    func_L07_003BCD80(obj);
}
/* localdecomp:end func_L07_003BC4D8 */
