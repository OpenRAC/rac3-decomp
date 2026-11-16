/* PAL near miss (Codex wave 8): near miss: 149 words differ with the file's flags.
 * Worker's note: 149 diff/242 words: .01.log; explicit VU sequences cannot interleave argument moves/constants; approved vu0.h helpers fail VU_REGS allocation with fixed flags (.03.log). No flag change tested.
 */
#include "common.h"
/* localdecomp:start func_L01_0036B078 */
typedef struct { float x,y,z,w; } __attribute__((aligned(16))) V_0036B078;
typedef struct { V_0036B078 pos[4]; u32 color[4]; float uv[8]; u8 tail[0x20]; } R_0036B078;
extern s32 D_001DD800_sda, D_001DD804_sda;
extern V_0036B078 D_L01_001E29C0;
void func_L01_0036B078(u8 *m) {
    extern void func_003D93B0(void *, s32, s32, s32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038CF68(void *, void *, float);
    extern void func_003D2DA0(void *, s32, s32);
    R_0036B078 r;
    V_0036B078 diff, delta, end, side, tmp;
    u8 *p = *(u8 **)(m+0x68);
    float alpha;
    s32 i;
    if (!m || m[0x20] == 0xFE || m[0x20] == 0xFD || !p) return;
    alpha = (float)*(s32 *)(p+0x38) * *(float *)(p+0x3C);
    func_003D93B0(&r,D_001DD800_sda,0,128);
    r.color[0] = r.color[1] = ((s32)(alpha*64.0f)<<24)|0x4080FF;
    r.color[2] = r.color[3] = ((s32)(alpha*64.0f)<<24)|0x909090;
    r.uv[0]=0; r.uv[1]=0; r.uv[2]=0; r.uv[3]=1;
    r.uv[4]=1; r.uv[5]=0; r.uv[6]=1; r.uv[7]=1;
    for (i=0;i<4;i++) {
        r.uv[i*2] += *(float *)(p+0x30);
        if (r.uv[i*2]>=7.0f) r.uv[i*2]-=7.0f;
    }
    *(float *)(p+0x30)+=0.1f;
    if (*(float *)(p+0x30)>=4.0f) *(float *)(p+0x30)-=4.0f;
    __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(diff) : "m"(*(V_0036B078 *)(m+0x10)), "m"(D_L01_001E29C0) : "vf1","vf2");
    __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(delta) : "m"(*(V_0036B078 *)(p+0x50)), "m"(*(V_0036B078 *)(m+0x10)) : "vf1","vf2");
    func_0038CE20((s128 *)&delta,(s128 *)&delta,0.5f);
    __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(end) : "m"(*(V_0036B078 *)(m+0x10)), "m"(delta) : "vf1","vf2");
    func_0038CE90(&side,&diff,&delta);
    func_0038CF68(&side,&side,1.4f);
    __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(r.pos[0]) : "m"(*(V_0036B078 *)(m+0x10)), "m"(side) : "vf1","vf2");
    __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(r.pos[1]) : "m"(*(V_0036B078 *)(m+0x10)), "m"(side) : "vf1","vf2");
    func_0038CF68(&side,&side,0.6f);
    __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(r.pos[2]) : "m"(end), "m"(side) : "vf1","vf2");
    __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(r.pos[3]) : "m"(end), "m"(side) : "vf1","vf2");
    func_003D2DA0(&r,0,0);
    r.color[0]=r.color[2]; r.color[1]=r.color[3];
    r.pos[0]=r.pos[2]; r.pos[1]=r.pos[3];
    r.color[2]=r.color[3]=0x804020;
    __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(r.pos[2]) : "m"(r.pos[2]), "m"(delta) : "vf1","vf2");
    __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(r.pos[3]) : "m"(r.pos[3]), "m"(delta) : "vf1","vf2");
    func_003D2DA0(&r,0,0);
    func_003D93B0(&r,D_001DD804_sda,1,128);
    r.color[0]=r.color[1]=((s32)(alpha*64.0f)<<24)|0x40FF;
    r.color[2]=r.color[3]=0x40FF;
    r.uv[0]=0; r.uv[1]=0; r.uv[2]=0; r.uv[3]=1;
    r.uv[4]=1; r.uv[5]=0; r.uv[6]=1; r.uv[7]=1;
    func_0038CF68(&side,&side,0.6f);
    __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(r.pos[0]) : "m"(*(V_0036B078 *)(m+0x10)), "m"(side) : "vf1","vf2");
    __asm__("lqc2 $vf1,%1\n\tsqc2 $vf1,%0" : "=m"(tmp) : "m"(*(V_0036B078 *)(m+0x10)) : "vf1");
    __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(r.pos[1]) : "m"(*(V_0036B078 *)(m+0x10)), "m"(side) : "vf1","vf2");
    __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(end) : "m"(tmp), "m"(delta) : "vf1","vf2");
    __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(end) : "m"(end), "m"(delta) : "vf1","vf2");
    __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(r.pos[2]) : "m"(end), "m"(side) : "vf1","vf2");
    __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(r.pos[3]) : "m"(end), "m"(side) : "vf1","vf2");
    func_003D2DA0(&r,0,0);
}
/* localdecomp:end func_L01_0036B078 */
