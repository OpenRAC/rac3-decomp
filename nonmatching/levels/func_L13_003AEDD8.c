/* NTSC-U draft (Codex wave 3): C of func_L13_003ACFF0, the NTSC-U twin of func_L13_003AEDD8, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 38 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L13_003ACFF0", whose code is not the PAL one).
 * Worker's note: 38 diff; reverified allowed-flags inline-literal assembler blocker: two lit4 lwc1 loads versus retail lui/ori/mtc1 at +0x38 and +0x44; rest aligns after length shift; no permitted alternative assembler; best log func_L13_003ACFF0.01.log
 */
#include "common.h"
/* localdecomp:start func_L13_003ACFF0 */
extern int func_L01_00458AE0(void *);
extern float D_001DE710_sda, D_001DE70C_sda;
extern float func_00389380(float, float);
extern float func_00388978(float);
extern float func_00388A28(float, float);
extern void func_L13_003AD0C8(void *,void *,float);
extern void func_L01_00458A08(void *,float);
int func_L13_003ACFF0(unsigned char *obj) {
    unsigned char *sub=*(unsigned char **)(obj+0x68);
    int result;
    float a;
    *(float *)(obj+0x18)-=*(float *)(sub+0x3B4);
    result=func_L01_00458AE0(obj);
    a=func_00389380(*(float *)(sub+0x3B0),D_001DE710_sda * 0.017453292f * 0.016666667f);
    *(float *)(sub+0x3B0)=a;
    *(float *)(sub+0x3B4)=func_00388978(a)*D_001DE70C_sda;
    *(float *)(obj+0x18)+=*(float *)(sub+0x3B4);
    func_L13_003AD0C8(obj,sub+0x1F0,*(float *)(sub+0x204));
    a=func_00388A28(*(float *)(sub+0x130)-*(float *)(obj+0x10),*(float *)(sub+0x134)-*(float *)(obj+0x14));
    func_L01_00458A08(obj,a);
    return result;
}
/* localdecomp:end func_L13_003ACFF0 */
