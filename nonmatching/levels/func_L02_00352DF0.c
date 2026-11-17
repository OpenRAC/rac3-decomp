/* NTSC-U draft (Codex wave 3): C of func_L02_00351CE0, the NTSC-U twin of func_L02_00352DF0, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 37 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L02_00351CE0", whose code is not the PAL one).
 * Worker's note: 37 diff; reverified allowed-flags lit4 assembler blocker for 1/60 at +0x130; VU0 sequence uses real operands/clobbers; VU0 call-delay scheduling and float temporary allocation also differ; best log func_L02_00351CE0.01.log
 */
#include "common.h"
/* localdecomp:start func_L02_00351CE0 */
typedef struct { f32 v[4]; } Vec_351CE0;
extern void func_00388BD0(void *,void *);
extern f32 func_003BE7F0(void *,s32,s32,f32);
extern u8 *D_001DEB00_sda;
extern f32 D_001DCFC0_sda;
extern f32 func_00388770(void *);
extern void func_L01_00441FB8(void *,s32,s32);
void func_L02_00351CE0(u8 *obj,u8 *sub) {
    Vec_351CE0 vec;
    f32 a,b;
    s32 i;
    u8 *p;
    func_00388BD0(obj+0xC0,obj+0xF0);
    if(*(s32 *)(sub+0x20)>32) *(s32 *)(sub+0x20)=32;
    *(s32 *)(sub+0x2C)=0;
    *(s32 *)(sub+0x4C)=0;
    *(s32 *)(sub+0x58)=0;
    if(sub[9]) *(f32 *)(obj+0x18)=func_003BE7F0(obj+0x10,0,0,0.5f);
    if(*(s32 *)(sub+0x10)!=-1) {
        p=D_001DEB00_sda+(*(s32 *)(sub+0x10)<<7);
        *(f32 *)(obj+0x10)=*(f32 *)(p+0x30);
        *(f32 *)(obj+0x14)=*(f32 *)(p+0x34);
        __asm__("lqc2 $vf2, 16(%1)\n\tlqc2 $vf1, 0(%1)\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(vec) : "r"(p) : "vf1","vf2","memory");
        a=func_00388770(&vec);
        b=*(f32 *)(sub+4);
    } else { a=*(f32 *)(sub+4); b=*(f32 *)(sub+0x14); }
    a=a+b+D_001DCFC0_sda;
    *(s16 *)(obj+0x32)=(s32)a;
    if(a>255.0f) a=255.0f;
    obj[0x30]=(s32)a;
    for(i=0;i<*(s32 *)(sub+0x20);i++) *(s32 *)(sub+0x74+i*0x20)=-1;
    *(f32 *)(sub+0x30)*=0.016666667f;
    *(f32 *)(sub+0x34)*=0.016666667f;
    func_L01_00441FB8(obj,1,-1);
}
/* localdecomp:end func_L02_00351CE0 */
