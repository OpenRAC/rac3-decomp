/* PAL near miss (Codex wave 10): near miss: 179 words differ with the file's flags.
 * Worker's note: 8 diff in 04-detail.log; 6 words interleave ordinary EE operations inside VU sequence (cannot split under P10), 2 tail argument moves; tested divs 2,0,2,2,2,0,0
 */
#include "common.h"
/* localdecomp:start func_L01_00368478 */
#include "vu0.h"
extern s32 D_L01_001DFB40;
extern f32 D_L01_001E1C28;
void func_L01_00368478(u8 *data) {
    extern f32 func_L01_0040F518(f32,f32);
    extern f32 func_0038D0B0(f32);
    extern s32 func_0038DBD8(s32,s32,f32);
    extern f32 func_0038CED8(void *);
    extern f32 func_0038D160(f32,f32);
    extern f32 func_0038DB48(f32);
    extern void func_003D9740(void *,s32,s32,s32,s32,f32);
    S_38C110v angles, delta;
    s128 out[4], basis[4], spin[4];
    s32 color;
    f32 progress, phase;
    color=func_0038DBD8(*(s32 *)(data+8),*(s32 *)(data+12),
          (func_0038D0B0(func_L01_0040F518((f32)D_L01_001DFB40,112.83333587646484f)/112.83333587646484f*6.2831855f)+1.0f)*0.5f);
    progress=func_L01_0040F518((f32)D_L01_001DFB40,(*(f32 *)(data+4)*60.0f*5.0f+2.0f)/6.0f)/
             ((*(f32 *)(data+4)*60.0f*5.0f+2.0f)/6.0f);
    phase=func_L01_0040F518((f32)D_L01_001DFB40,(*(f32 *)(data+4)*60.0f*10.0f*5.0f+2.0f)/6.0f)/
          ((*(f32 *)(data+4)*60.0f*10.0f*5.0f+2.0f)/6.0f)*6.2831855f;
    __asm__ (
        "lqc2 $vf2,%2\n"
        "lqc2 $vf1,%1\n"
        "vsub.xyz $vf1,$vf1,$vf2\n"
        "sqc2 $vf1,%0"
        : "=m"(delta)
        : "m"(*(S_38C110v *)(data+0x30)), "m"(*(S_38C110v *)(data+0x20))
        : "vf1", "vf2");
    angles.x=0.0f;
    angles.y=-func_0038D160(func_0038CED8(&delta),delta.z)+1.5707964f;
    angles.z=func_0038D160(delta.x,delta.y);
    angles.w=1.0f;
    func_0038D328(basis,&angles);
    qzero(&angles);
    angles.z=func_0038DB48(phase);
    func_0038D328(spin,&angles);
    func_0038D640(out,basis,spin);
    out[3]=*(s128 *)(data+0x20);
    func_0038CE20(&out[0],&out[0],D_L01_001E1C28);
    func_0038CE20(&out[1],&out[1],D_L01_001E1C28);
    func_0038CE20(&out[2],&out[2],D_L01_001E1C28);
    func_003D9740(out,*(s32 *)data,color,*(s32 *)(data+0x10),1,progress);
    progress+=0.5f;
    angles.z=func_0038DB48(-phase);
    func_0038D328(spin,&angles);
    func_0038D640(out,basis,spin);
    out[3]=*(s128 *)(data+0x20);
    func_0038CE20(&out[0],&out[0],D_L01_001E1C28);
    func_0038CE20(&out[1],&out[1],D_L01_001E1C28);
    func_0038CE20(&out[2],&out[2],D_L01_001E1C28);
    func_003D9740(out,*(s32 *)data,color,*(s32 *)(data+0x10),1,progress);
}
/* localdecomp:end func_L01_00368478 */
