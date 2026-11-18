/* func_L02_00352DF0: near miss, 9 diff with the file's flags (-mvu0-use-vf0-vf2 ... @ps2as). PAL port of the NTSC-U draft func_L02_00351CE0 (callees,
 * $gp slots D_001DEA80_sda / D_001DCF80_sda with their .extern size hints, 0.020000001f, vec_add_ab instead of the draft's raw asm).
 * Only the float block after the join differs: retail loads D_001DCF80_sda ($f2) first, then add.s a+b, add.s +D, then the 255.0 constant ($f1) and
 * cvt.w.s into $f2; this C issues the add first and loads D into $f1 (b's register, since b has died). Wordings of `a = a + b + D` (split adds, a local
 * for D, parenthesised) did not change it. */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L02_00352DF0 */
typedef struct { f32 v[4]; } Vec_351CE0;
extern void func_0038D308(void *,void *);
extern f32 func_003C3D30(void *,s32,s32,f32);
extern u8 *D_001DEA80_sda;
__asm__(".extern D_001DEA80_sda, 4");
extern f32 D_001DCF80_sda;
__asm__(".extern D_001DCF80_sda, 4");
extern f32 func_0038CEA8(void *);
extern void func_L01_004450F0(void *,s32,s32);
void func_L02_00352DF0(u8 *obj,u8 *sub) {
    Vec_351CE0 vec;
    f32 a,b;
    s32 i;
    u8 *p;
    func_0038D308(obj+0xC0,obj+0xF0);
    if(*(s32 *)(sub+0x20)>32) *(s32 *)(sub+0x20)=32;
    *(s32 *)(sub+0x2C)=0;
    *(s32 *)(sub+0x4C)=0;
    *(s32 *)(sub+0x58)=0;
    if(sub[9]) *(f32 *)(obj+0x18)=func_003C3D30(obj+0x10,0,0,0.5f);
    if(*(s32 *)(sub+0x10)!=-1) {
        p=D_001DEA80_sda+(*(s32 *)(sub+0x10)<<7);
        *(f32 *)(obj+0x10)=*(f32 *)(p+0x30);
        *(f32 *)(obj+0x14)=*(f32 *)(p+0x34);
        vec_add_ab(&vec, p, p + 0x10);
        a=func_0038CEA8(&vec);
        b=*(f32 *)(sub+4);
    } else { a=*(f32 *)(sub+4); b=*(f32 *)(sub+0x14); }
    a=a+b+D_001DCF80_sda;
    *(s16 *)(obj+0x32)=(s32)a;
    if(a>255.0f) a=255.0f;
    obj[0x30]=(s32)a;
    for(i=0;i<*(s32 *)(sub+0x20);i++) *(s32 *)(sub+0x74+i*0x20)=-1;
    *(f32 *)(sub+0x30)*=0.020000001f;
    *(f32 *)(sub+0x34)*=0.020000001f;
    func_L01_004450F0(obj,1,-1);
}
/* localdecomp:end func_L02_00352DF0 */
