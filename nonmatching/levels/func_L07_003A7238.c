/* PAL near miss (Codex wave 8): near miss: 7 words differ with the file's flags.
 * Worker's note: 7 word diffs in build/codex/w395/func_L07_003A7238.01.log; first VU sequence requires interleaved scalar scheduling; vu0.h helpers fail allocation under fixed flags (02.log); retained valid single VU blocks.
 */
#include "common.h"
/* localdecomp:start func_L07_003A7238 */
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) Vec_003A7238;
typedef struct { u8 pad[0x130]; u128_t result; u8 gap[0x290-0x140]; s32 state,target; s32 reserved; f32 rate; Vec_003A7238 position; s32 unknown; Vec_003A7238 *destination; s16 remaining; u8 p[2]; u8 pending; } Vars_003A7238;
void func_L07_003A7238(u8 *moby) {
    extern s32 func_0038CB00(s16 *);
    extern void func_0038CE20(Vec_003A7238 *,Vec_003A7238 *,f32);
    extern void func_L07_003A75E0(u8 *);
    extern void func_L07_003A7E88(u8 *);
    extern void func_L01_00404808(void (*)(u8 *),u8 *);
    extern void func_L07_003A7C10(u8 *);
    Vars_003A7238 *vars=*(Vars_003A7238 **)(moby+0x68);
    switch (moby[0x20]) {
    case 0:case 1:case 2: break;
    case 3:
        if (func_0038CB00(&vars->remaining)) {
            vars->result=*(u128_t *)vars->destination;
        } else {
            f32 one=1.0f;
            Vec_003A7238 delta;
            __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(delta) : "m"(*vars->destination), "m"(vars->position) : "vf1","vf2");
            func_0038CE20(&delta,&delta,one/(f32)vars->remaining);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(vars->position) : "m"(vars->position), "m"(delta) : "vf1","vf2");
            vars->result=*(u128_t *)&vars->position;
        }
        break;
    }
    if (vars->state!=vars->target) {
        (*(u16 *)(moby+0x96))++;
        if ((f32)*(u16 *)(moby+0x96)*vars->rate>=1.0f) vars->state=vars->target;
    }
    func_L07_003A75E0(moby);
    func_L01_00404808(func_L07_003A7E88,moby);
    if (vars->pending) {
        func_L07_003A7C10(moby);
        vars->pending=0;
    }
}
/* localdecomp:end func_L07_003A7238 */
