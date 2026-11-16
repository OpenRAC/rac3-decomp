/* PAL near miss (Codex wave 6): near miss: 2 words differ with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (the file's line: "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as").
 * Worker's note: 2 diff; build/codex/w267/func_L07_003C80C0.02.log; sw stack argument at +0xF0 and swc1 position at +0xF8 reversed; separate update, call-argument update and named z field yield identical bytes
 */
#include "common.h"
/* localdecomp:start func_L07_003C80C0 */

#include "vu0.h"
typedef int Q_003C80C0 __attribute__((mode(TI)));
typedef struct { f32 f[4]; } __attribute__((aligned(16))) V_003C80C0;
extern s32 D_L07_001DEF40;
extern u8 D_L07_001D66B0[] __attribute__((section(".sdata")));
extern u8 D_L07_001E1EC0[];
void func_L07_003C80C0(char *o) {
    extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
    extern void func_L01_003303B8(void *, f32,f32,f32,f32,
        s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32);
    extern void func_L01_00451FE0(void *,s32,void *,s32,
        f32,f32,f32,f32,f32,f32,f32,f32,s32,s32,s32,s32,s32,s32);
    extern void func_L01_004443E8(void *,s32,s32);
    extern void func_L07_003C86D0(char *);
    extern s32 func_003A52A0(s32,s32,void *);
    extern void func_L01_00446A70(void *,void *,s32,void *,void *,f32);
    extern s32 func_L01_00452860(void *,void *,s32);
    extern void func_L01_00456BD0(void *,s32);
    extern void func_L01_00456C98(void *,s32,s32,s32,s32,s32,s32,s32,f32,f32,f32,s32,s32);
    extern void func_L07_004522E8(void *,s32,void *,f32);
    extern f32 func_L01_0040E548(void *,void *);
    extern void func_L01_004472C0(void *);
    extern void func_003A4F28(s32);
    V_003C80C0 pos;
    s32 sound;
    f32 volume;
    u8 *s = *(u8 **)(o + 0x68);
    if (func_L01_00452FB0(o,s+0x70,0,0,0)) *(s32 *)(s+0x188) &= ~0x10;
    if (*(f32 *)(s+0x30) <= 0.0f) {
        *(Q_003C80C0 *)&pos = *(Q_003C80C0 *)(o+0x10);
        pos.f[2] += *(f32 *)(s+0x40);
        func_L01_003303B8(&pos,0.5f,0.0f,0.0f,2.0f,0,10,5,4,10,15,0,
            0,0,0,0,0,1,0x1010000,0,0x388EF7,0x63F7,0x407FFF,0x20FF,0x8FFF,0x3064FF,0x7F60A0FF,0x280000FF,0x3064FF,0);
        func_L01_00451FE0(o,0x7FFF,D_L07_001D66B0,0xFF,
            3.0f,6.0f,3.0f,6.0f,-1.0f,-1.0f,1.0f,1.0f,180,0,0,35,0,3);
        func_L01_004443E8(o,0,3);
        func_L07_003C86D0(o);
        func_003A52A0(8,0,o);
        return;
    }
    if (*(s32 *)(s+0x228)==1 || *(s32 *)(s+0x228)==11) {
        qzero(&pos);
        func_L01_00446A70(o,o,0x10000,&pos,&pos,(f32)*(s16 *)(s+0x34));
    } else if (s[0x5E] || s[0x60] || s[0x3E]==2) {
        func_L01_004443E8(o,0,3);
        func_L07_003C86D0(o);
        return;
    }
    func_L01_00452860(o,s+0x30,0);
    if (s[0x5F]) {
        func_L01_00456BD0(o,5);
        if ((D_L07_001DEF40&15)==(((s32)o>>8)&15)) {
            func_L01_00456C98(o,((u8)o[0x20]>=8 ? *(s32 *)(s+0x498) : *(s32 *)(s+0x490)),0,0,0,0,3,0,
                ((u8)o[0x20]>=8 ? *(f32 *)(s+0x49C) : *(f32 *)(s+0x494)),10.0f,1.0f,0,0);
        }
    } else {
        func_L01_00456BD0(o,3);
        if ((D_L07_001DEF40&15)==(((s32)o>>8)&15)) {
            func_L01_00456C98(o,((u8)o[0x20]>=8 ? *(s32 *)(s+0x498) : *(s32 *)(s+0x490)),0,0,0,0,1,0,
                ((u8)o[0x20]>=8 ? *(f32 *)(s+0x49C) : *(f32 *)(s+0x494)),10.0f,1.0f,0,0);
        }
    }
    func_L07_004522E8(o,8,s+0x400,2.5f);
    if (*((u8 *)o+0x31) && func_L01_0040E548(D_L07_001E1EC0,o+0x10)<576.0f) {
        func_L01_004472C0(o);
        o[0x6F] = 22;
    }
    if ((u8)o[0x20] >= 24) {
        if (*(s32 *)(s+0x4D8)==-1) *(s32 *)(s+0x4D8) = func_003A52A0(11,4,o);
    } else {
        if (*(s32 *)(s+0x4D8)!=-1) {
            func_003A4F28(*(s32 *)(s+0x4D8));
            *(s32 *)(s+0x4D8)=-1;
        }
    }
}
/* localdecomp:end func_L07_003C80C0 */
