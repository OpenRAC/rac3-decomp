#include "common.h"
/* localdecomp:start func_L01_0045FB90 */
#include "vu0.h"
extern s32 D_001D545C_0045FB90;
__asm__(".extern D_001D545C_0045FB90, 16");
extern f32 D_L01_001E0320;
__asm__(".extern D_L01_001E0320, 16");
extern f32 D_L01_001E0330_0045FB90;
__asm__(".extern D_L01_001E0330_0045FB90, 16");
extern f32 D_L01_001E0328_0045FB90;
__asm__(".extern D_L01_001E0328_0045FB90, 16");
void func_L01_0045FB90(u8 *p) {
    extern void func_003C7CE0(u8 *);
    extern f32 func_L01_0044E4E8(void *);
    u8 *vars=p+0x30;
    vu0_v4 delta;
    s32 x,y;
    f32 oldx,oldy;
    f32 floor=*(f32 *)(vars+12);
    if(D_001D545C_0045FB90==15) {
        if(*(f32 *)(p+24)<floor) {func_003C7CE0(p);return;}
    } else if(*(f32 *)(p+24)<floor || *(f32 *)(p+16)<0.0f || *(f32 *)(p+20)<0.0f || *(f32 *)(p+16)>1024.0f || *(f32 *)(p+20)>1024.0f) goto kill;
    vec_add_ab(&delta, vars, &D_L01_001E0320);
    oldx=*(f32 *)(p+32);
    oldy=*(f32 *)(p+36);
    x=(s32)oldx;
    y=(s32)oldy;
    vec_add_ab(p+32, p+32, &delta);
    vec_add_ab(p+16, p+16, &delta);
    if(*(s16 *)(p+10)!=2 && (x!=(s32)*(f32 *)(p+32) || y!=(s32)*(f32 *)(p+36))) {
        vu0_v4 first,second;
        first=*(vu0_v4 *)(p+32);
        if(func_L01_0044E4E8(&first)<D_L01_001E0330_0045FB90) floor=D_L01_001E0330_0045FB90;
        else {second=*(vu0_v4 *)(p+32);floor=func_L01_0044E4E8(&second);}
        if(*(f32 *)(p+40)<floor) {
kill:
            func_003C7CE0(p);
            return;
        }
    }
    *(f32 *)(vars+8)-=0.00272222236f;
    *(f32 *)(vars+12)=floor+D_L01_001E0328_0045FB90;
    return;
}
/* localdecomp:end func_L01_0045FB90 */
