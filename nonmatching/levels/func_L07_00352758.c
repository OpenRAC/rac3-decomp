/* PAL near miss (Codex wave 10): near miss: 0 words differ with the file's flags.
 * Worker's note: 0 byte diff canonical MATCH; TYPE_CONTRACT_FAIL in build/codex/w495/func_L07_00352758.check-03.log: owner declares void func_0038CF38(void *,s32), retail consumes f0 and requires f32 return. Context correction required; no cast or alias workaround.
 */
#include "common.h"
/* localdecomp:start func_L07_00352758 */
#include "vu0.h"
extern u8 D_L07_001E1EC0[];
void func_L07_00352758(u8 *m) {
    extern s32 func_L01_00452FB0(void *,void *,s32,s32,s32);
    extern void func_L07_003333F8(s32,f32,f32);
    extern void func_L07_00334588(s32);
    extern void func_L01_00446A70(void *,void *,s32,void *,void *,f32);
    extern void func_L07_003315B0(void *);
    extern void func_L07_00331158(void *);
    extern void func_L01_00404808(void (*)(u8 *),void *);
    extern void func_L07_00353E10(u8 *);
    extern void func_003C2F58(u8 *,s32,void *);
    extern f32 func_0038D160(f32,f32);
    extern f32 func_0038DB00(f32,f32);
    /* Retail consumes f0; the owner's later void prototype needs correction. */
    extern f32 func_0038CF38(void *,s32);
    extern void func_L01_0044E850(void *,void *,s32,f32,f32);
    extern void func_L07_004522E8(void *,s32,void *,f32);
    extern f32 func_L01_0040E548(void *,void *);
    extern void func_L01_004472C0(void *);
    extern void func_L01_00446780(void *,void *,s32,f32,f32,f32,s32,s32,s32);
    vu0_v4 pos;
    u8 *v=*(u8 **)(m+0x68);
    f32 previous;
    if(m[0x20]==1) return;
    previous=*(f32 *)(v+0x30);
    if(func_L01_00452FB0(m,v+0x70,0,0,0)) {
        func_L07_003333F8(*(s32 *)(v+0x240),previous,*(f32 *)(v+0x30));
        v[0x467]=0;
        func_L07_00334588((s32)m);
    }
    if(*(s32 *)(v+0x228)==1) {
        qzero(&pos);
        func_L01_00446A70(m,m,0x10000,&pos,&pos,(f32)*(s16 *)(v+0x34));
    } else if(v[0x5E] || v[0x60] || v[0x3E]==2) {
        func_L07_003315B0(m);
        return;
    }
    func_L07_00331158(m);
    *(f32 *)(v+0x460) -= -0.12000000476837158f;
    if(*(f32 *)(v+0x460)<0.0f) *(f32 *)(v+0x460)+=1.0f;
    func_L01_00404808(func_L07_00353E10,m);
    if(*(s16 *)(v+0x144)==1) {
        f32 angle;
        f32 distance;
        func_003C2F58(m,9,&pos);
        angle=func_0038D160(*(f32 *)(*(u8 **)(v+0x140)+0x10)-pos.x,*(f32 *)(*(u8 **)(v+0x140)+0x14)-pos.y);
        angle=func_0038DB00(angle,*(f32 *)(m+0xF8));
        *(f32 *)(v+0x2C8)=angle;
        if(angle>0.7853981852531433f) *(f32 *)(v+0x2C8)=0.7853981852531433f;
        else if(angle< -0.7853981852531433f) *(f32 *)(v+0x2C8)= -0.7853981852531433f;
        distance=func_0038CF38(&pos,(s32)(*(u8 **)(v+0x140)+0x10));
        angle= -func_0038D160(distance,*(f32 *)(*(u8 **)(v+0x140)+0x18)-pos.z);
        *(f32 *)(v+0x2C4)=angle;
        if(angle>0.5235987901687622f) *(f32 *)(v+0x2C4)=0.5235987901687622f;
        else if(angle< -0.5235987901687622f) *(f32 *)(v+0x2C4)= -0.5235987901687622f;
    }
    func_L01_0044E850(m,v+0x260,9,0.04320000112056732f,0.4320000410079956f);
    func_L07_004522E8(m,10,v+0x2E0,2.5f);
    if(m[0x31] && func_L01_0040E548(D_L07_001E1EC0,m+0x10)<576.0f) {
        func_L01_004472C0(m);
        m[0x6F]=22;
    }
    func_L01_00446780(m,m+0x10,0x8000000,0.8f,1.0f,1.0f,0,1,0);
}
/* localdecomp:end func_L07_00352758 */
