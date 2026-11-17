/* PAL near miss (Codex wave 6): near miss: 129 words differ with the file's flags.
 * Worker's note: 125 diff; literal pools versus retail inline constants, extra saved register and stack-pointer scheduling; three equivalent variants; best log build/codex/w255/func_L07_003AAF98.best.log
 */
#include "common.h"
/* localdecomp:start func_L07_003AAF98 */
typedef int Q_003AAF98 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_003AAF98;
void func_L07_003AAF98(u8 *obj) {
    extern void func_003C2EC0(u8 *, s32, f32 *);
    extern f32 func_0038CF38(void *, void *);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038DB48(f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_L01_0040E570(void *, void *);
    extern void func_L05_0043F7E0(void *, void *, f32 *, f32 *, void *, void *, void *, f32);
    extern f32 func_003C3D30(void *, s32, s32, f32);
    V_003AAF98 matrix[4];
    V_003AAF98 pos;
    V_003AAF98 delta;
    V_003AAF98 result;
    f32 weights[4];
    V_003AAF98 choices[2];
    V_003AAF98 target;
    u8 *p = *(u8 **)(obj + 0x68);
    f32 distance,angle,radius;
    s32 i,best;
    func_003C2EC0(obj, p[0x533]+3, (f32 *)matrix);
    pos = matrix[3];
    distance = func_0038CF38(&pos, p+0x130);
    if (distance > 12.0f) distance = 12.0f;
    else if (distance < 4.0f) distance = 4.0f;
    angle = func_0038D160(*(f32 *)(p+0x130)-pos.x, *(f32 *)(p+0x134)-pos.y);
    angle = func_0038DB48((angle-*(f32 *)(p+0x2A8))-*(f32 *)(obj+0xF8));
    if (angle > 0.2617993950843811f) angle = 0.2617993950843811f;
    else if (angle < -0.2617993950843811f) angle = -0.2617993950843811f;
    angle = func_0038DB48((angle+*(f32 *)(p+0x2A8))+*(f32 *)(obj+0xF8));
    delta.x = func_0038D098(angle)*(distance+1.0f);
    radius = distance+1.0f;
    delta.y = func_0038D0B0(angle)*radius;
    delta.z = 0;
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(result) : "m"(pos), "m"(delta) : "vf1", "vf2");
    if (func_L01_0040E570(*(u8 **)(p+0x240)+0x10, &result) > 615.04f) {
        target = *(V_003AAF98 *)(*(u8 **)(p+0x240)+0x10);
        func_L05_0043F7E0(choices, (u8 *)choices+16, &weights[0], &weights[1], &pos, &result, &target, 24.8f);
        best = -1;
        for (i=0;i<2;i++) if (weights[i]>0.0f) best=i;
        if (best!=-1) *(Q_003AAF98 *)&result=*(Q_003AAF98 *)&choices[best];
    }
    result.z = func_003C3D30(&result,0,0,0.5f);
    *(V_003AAF98 *)(p+0x520)=result;
}
/* localdecomp:end func_L07_003AAF98 */
