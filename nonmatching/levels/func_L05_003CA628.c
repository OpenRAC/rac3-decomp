/* NTSC-U draft (2026-11-14, Codex worker): C of func_L05_003C8498, the NTSC-U twin of func_L05_003CA628, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" when tried; not with src/levels/shared/L05_003CA628.c's current line.
 * Worker's note: 134 diff; inline-literal assembler mismatch at 1021.0f; stack/register and VU0 branch scheduling also differ; retail div.s nop counts 2 2 (not injected, other diffs remain); best log func_L05_003C8498.02.log 134 diff; reverified allowed-flags lit4 load versus retail inline 1021.0f (0x447F4000); stac
 */
#include "common.h"
/* localdecomp:start func_L05_003C8498 */
typedef int Quad_3C8498 __attribute__((mode(TI)));
extern s32 func_L01_00452EC8(void),func_00388398(void *);
extern void func_003BD360(void *);
extern f32 func_00388770(void *),func_003887C8(void *,void *);
extern void func_00388830(void *,void *,f32);
extern void func_L01_00443628(void *,void *,s32,void *,f32);
extern u8 D_L05_001D66B0[];
extern void func_L01_004C76B8(void),func_L01_004C76F0(void);
extern s32 func_003CE740(void *,void *,s32,void *,void *);
extern u8 *D_L05_001EA758[];
extern Quad_3C8498 D_L05_001EA760[];
extern void func_L05_003C8EE8(void *),func_L05_003C8CC8(void *);
extern void func_L01_004026A0(void *,void *);
extern void func_L05_003C8748(void *);
void func_L05_003C8498(u8 *obj) {
    struct { Quad_3C8498 old, dest, work[3]; } collision;
    u8 *sub;
    u8 *hit;
    s32 result;
    f32 len;
    collision.old=*(Quad_3C8498 *)(obj+0x10);
    sub=*(u8 **)(obj+0x68);
    if(!obj[0x20]) {
        if(!func_L01_00452EC8()) {
            __asm__("lqc2 $vf1, 16(%0)
	lqc2 $vf2, 0(%1)
	vadd.xyz $vf1, $vf1, $vf2
	sqc2 $vf1, 16(%0)"
                : : "r"(obj),"r"(sub) : "vf1","vf2","memory");
        }
        if(func_00388398(sub+0x24)) {
            func_003BD360(obj);
            return;
        }
        if(!*(s32 *)(sub+0x30)) {
            if(func_00388770(sub)>*(f32 *)(sub+0x20)) {
                __asm__("lqc2 $vf2, 0(%2)
	lqc2 $vf1, 16(%1)
	vadd.xyz $vf1, $vf1, $vf2
	sqc2 $vf1, %0"
                    : "=m"(collision.dest) : "r"(obj),"r"(sub) : "vf1","vf2");
            } else {
                func_00388830(&collision.dest,sub,*(f32 *)(sub+0x20));
                __asm__("lqc2 $vf1, %0
	lqc2 $vf2, 16(%1)
	vadd.xyz $vf1, $vf1, $vf2
	sqc2 $vf1, %0"
                    : "+m"(collision.dest) : "r"(obj) : "vf1","vf2");
            }
            func_L01_00443628(collision.work,obj,0x10001,D_L05_001D66B0,*(f32 *)(sub+0x34));
            func_L01_004C76B8();
            result=func_003CE740(obj+0x10,&collision.dest,16,obj,collision.work);
            if(result && (hit=D_L05_001EA758[0]) && *(s16 *)(hit+0xAA)==0x186D && hit[0x20]!=2 && hit[0x20]!=5) hit[0x20]=4;
            func_L01_004C76F0();
            if(result) {
                *(s32 *)(sub+0x30)=1;
                *(Quad_3C8498 *)(sub+0x10)=D_L05_001EA760[0];
                len=func_003887C8(obj+0x10,sub+0x10);
                len=len/func_00388770(sub);
                *(s32 *)(sub+0x24)=(s32)len;
                *(f32 *)(sub+0x28)=1.0f/(f32)*(s32 *)(sub+0x24);
                if(!D_L05_001EA758[0]) func_L05_003C8EE8(obj);
                else func_L05_003C8CC8(sub+0x10);
            }
        }
        func_L01_004026A0(func_L05_003C8748,obj);
    }
    if(*(f32 *)(obj+0x10)<2.0f || *(f32 *)(obj+0x10)>1021.0f ||
       *(f32 *)(obj+0x14)<2.0f || *(f32 *)(obj+0x14)>1021.0f ||
       *(f32 *)(obj+0x18)<2.0f || *(f32 *)(obj+0x18)>1021.0f) func_003BD360(obj);
}
/* localdecomp:end func_L05_003C8498 */
