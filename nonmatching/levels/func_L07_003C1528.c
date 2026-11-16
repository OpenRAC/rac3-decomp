/* PAL near miss (Codex wave 10): near miss: 90 words differ with the file's flags.
 * Worker's note: 90 diff; build/codex/w502/func_L07_003C1528.02.log; branch tail merging and constant 0x3D75C290 materialization differ with fixed default assembler; three equivalent control-flow formulations retain residual
 */
#include "common.h"
/* localdecomp:start func_L07_003C1528 */
extern u8 *D_001D52FC __attribute__((section(".data")));
extern u8 *D_001D52FC_sda;
extern u8 D_00142CA0[];
s32 func_L07_003C1528(void) {
    extern void func_L01_00452560(s32,s32,s32,s32,s32,s32,s32);
    extern void func_003A5348(s32,s32,s32);
    extern void func_L07_003C17C0(void *);
    extern void func_L07_003C0D00(s32);
    extern void func_L07_003C0F40(u8 *);
    extern s32 func_L07_00334A70(s32);
    extern void func_003A2CD8(void *);
    extern void func_L01_00516558(s32,f32 *,f32 *);
    extern void func_L01_00516470(s32,f32,f32);
    extern s32 func_0038DBD8(s32,s32,f32);
    extern void func_L01_005170B8(s32,s32);
    f32 xy[2];
    u8 *m = D_001DE550_sda;
    u8 *d = *(u8 **)(m + 0x68);
    s32 result = 0;
    u32 buttons;
    s32 id;
    f32 alpha;
    func_L01_00452560(0,5,0,1,0,0,0);
    buttons = *(u32 *)(D_001D52FC + 0x1C4);
    if (buttons & 0x1000) {
        if (D_L07_001DE554) {
            func_003A5348(3,0,0);
            D_L07_001DE554 = D_L07_001DE554 - 1;
            if (!(D_L07_001DE554 >= D_L07_001DE555)) { D_L07_001DE555 = D_L07_001DE555 - 1; }
            func_L07_003C17C0(m);
        }
        goto consume;
    }
    if (buttons & 0x4000) {
        if (D_L07_001DE554 < d[0x39] + d[0x3A] - 1) {
            func_003A5348(3,0,0);
            D_L07_001DE554 = D_L07_001DE554 + 1;
            if (!(D_L07_001DE554 - D_L07_001DE555 < 5)) { D_L07_001DE555 = D_L07_001DE555 + 1; }
            func_L07_003C17C0(m);
        }
        goto consume;
    }
    if (buttons & 0x10) {
        result=1;
        func_L07_003C0D00((s32)m);
    } else {
      if (buttons & 0x40) {
        E_003C0F40 *e = &((E_003C0F40 *)D_L07_002BC920)[d[0x38]];
        if (e->b0 == 0) {
            s32 index=func_L07_00334A70(e->h2);
            if (index != -1 && D_00142CA0[index] == 0) {
                func_003A5348(5,0,0);
                return 2;
            }
        }
        result=3;
        func_003A5348(4,0,0);
        func_L07_003C0F40(m);
        func_003A2CD8(D_001D52FC_sda);
        goto animate;
    } else goto animate;
    }
consume:
    func_003A2CD8(D_001D52FC_sda);
animate:
    { union { u32 u; f32 f; } step; step.u = 0x3D75C290;
    *(f32 *)(d+0x28) += step.f; }
    if (*(f32 *)(d+0x28) > 2.0f) *(f32 *)(d+0x28) -= 2.0f;
    id = D_L07_001DE554-D_L07_001DE555+0x470024;
    func_L01_00516558(id,&xy[0],&xy[1]);
    func_L01_00516470(0x470023,xy[0],xy[1]);
    if (*(f32 *)(d+0x28) <= 1.0f) alpha=*(f32 *)(d+0x28);
    else alpha=2.0f-*(f32 *)(d+0x28);
    { s32 color=func_0038DBD8(0x66D6EEFA,0x80FFFFFF,alpha);
    func_L01_005170B8(id,color); }
    return result;
}
/* localdecomp:end func_L07_003C1528 */
