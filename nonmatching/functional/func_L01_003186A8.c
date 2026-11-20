/* functional: high. 23 words differ from retail only in scheduling/VU register choice; same calls, args, order; qzero and vec_add_ab are plain C (xyz add, w kept); retail's $gp floats (0.1375f, 0.0275f: the same values at every level, in a different $gp slot per level, e.g. gp-0xD0 at 01, gp-0x1BC at 02) are written as literals, not as one level's sda slot. */
/* PAL near miss (Codex wave 10): near miss: 23 words differ with the file's flags.
 * Worker's note: 23 diff; loop count reversal and VU register/scheduling differences; best log build/codex/w503/func_L01_003186A8.04.log; 10 attempts; no linked build
 */
#include "common.h"
/* localdecomp:start func_L01_003186A8 */
#include "vu0.h"
extern vu0_v4 D_L01_00273FA0[];
extern G_00318408 D_001A4BE0;
void func_L01_003186A8(u8 *object) {
    extern s32 func_00382498(s32, s32);
    extern u8 *func_L01_0046B458(void *, s32, u32, s32, s32, void *, s32, f32, f32, f32);
    extern void func_L01_004C7D98(s32, void *);
    extern void func_0038CF68(f32 *, f32 *, f32);
    vu0_v4 zero;
    vu0_v4 delta;
    s32 color1 = 0x7F2020;
    s32 color2 = 0xFF4040;
    vu0_v4 *p;
    s32 i;
    s32 next;
    s32 alpha;
    u8 *particle;
    zero.x = 0.0f;
    zero.y = 0.0f;
    zero.z = 0.0f;
    zero.w = 0.0f;
    if (*(s32 *)(*(u8 **)(object+0x68)+0x18)) {
        color1=0x204060;
        color2=0x4080FF;
    }
    p=D_L01_00273FA0;
    i=0;
    do {
        alpha=func_00382498(0,111)<<24;
        next=i+1;
        i=next;

        particle=func_L01_0046B458(p,10,color1|alpha,0,1,&zero,0,0.1375f*0.5f,0.1375f,0.0f);
        if(particle) particle[9]=116;
        particle=func_L01_0046B458(p,10,color2|alpha,1,1,&zero,0,0.0275f*0.5f,0.0275f,0.0f);
        if(particle) particle[9]=116;
        func_L01_004C7D98(D_001A4BE0.x25C0+16,&delta);
        func_0038CF68((f32 *)&delta,(f32 *)&delta,-0.004f);
        p->x += delta.x;
        p->y += delta.y;
        p->z += delta.z;
        p++;
    } while(i<25);
}
/* localdecomp:end func_L01_003186A8 */
