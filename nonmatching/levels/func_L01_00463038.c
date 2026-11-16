/* PAL near miss (Codex wave 8): near miss: 24 words differ with the file's flags.
 * Worker's note: 24 diff in build/codex/w426/func_L01_00463038.f7.log and f9.log; VU/global address scheduling and scalar conversion register order at +0x0C0..+0x118; complete legal draft retained, fixed whole-file flags; helper variants spill (85-112 diff), no ordinary EE asm
 */
#include "common.h"
/* localdecomp:start func_L01_00463038 */
#include "vu0.h"
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern vu0_v4 D_L01_001E02A0_00463038;
extern f32 D_L01_001E02B0_00463038;
__asm__(".extern D_L01_001E02B0_00463038, 16");
extern f32 D_L01_001E02A8_00463038;
__asm__(".extern D_L01_001E02A8_00463038, 16");
void func_L01_00463038(u8 *p) {
    extern void func_003CD250(u8 *);
    extern f32 func_L01_00451768(void *);
    u8 *vars=p+0x30;
    vu0_v4 delta;
    s32 x,y;
    f32 oldx,oldy;
    f32 floor=*(f32 *)(vars+12);
    if(D_001D545C==15) {
        if(*(f32 *)(p+24)<floor) {func_003CD250(p);return;}
    } else if(*(f32 *)(p+24)<floor || *(f32 *)(p+16)<0.0f || *(f32 *)(p+20)<0.0f || *(f32 *)(p+16)>1024.0f || *(f32 *)(p+20)>1024.0f) goto kill;
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(delta) : "m"(*(vu0_v4 *)vars),"m"(D_L01_001E02A0_00463038) : "vf1","vf2");
    oldx=*(f32 *)(p+32);
    oldy=*(f32 *)(p+36);
    x=(s32)oldx;
    y=(s32)oldy;
    __asm__("lqc2 $vf2, %0\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "+m"(*(vu0_v4 *)(p+32)) : "m"(delta) : "vf1","vf2");
    __asm__("lqc2 $vf1, %0\n\tlqc2 $vf2, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "+m"(*(vu0_v4 *)(p+16)) : "m"(delta) : "vf1","vf2");
    if(*(s16 *)(p+10)!=2 && (x!=(s32)*(f32 *)(p+32) || y!=(s32)*(f32 *)(p+36))) {
        vu0_v4 first,second;
        first=*(vu0_v4 *)(p+32);
        if(func_L01_00451768(&first)<D_L01_001E02B0_00463038) floor=D_L01_001E02B0_00463038;
        else {second=*(vu0_v4 *)(p+32);floor=func_L01_00451768(&second);}
        if(*(f32 *)(p+40)<floor) {
kill:
            func_003CD250(p);
            return;
        }
    }
    *(f32 *)(vars+8)-=0.003920000046491623f;
    *(f32 *)(vars+12)=floor+D_L01_001E02A8_00463038;
    return;
}
/* localdecomp:end func_L01_00463038 */
