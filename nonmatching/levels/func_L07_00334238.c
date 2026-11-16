/* PAL near miss (Codex wave 8): near miss: 18 words differ with the file's flags.
 * Worker's note: Best 18 diff / 56 words: func_L07_00334238.c03.log. VU sequence needs ordinary lq interleaved in retail; retained one valid asm block instead of splitting implicit vf state. Float operand allocation also differs. Existing vec_add_ab cannot compile with fixed ...
 */
#include "common.h"
/* localdecomp:start func_L07_00334238 */
typedef int Q_00334238 __attribute__((mode(TI)));
typedef union { Q_00334238 q; f32 f[4]; } V_00334238;
typedef struct { V_00334238 position; u8 pad10[0x370]; V_00334238 direction; } Camera_00334238;
extern Camera_00334238 D_L07_001E1EC0;
typedef struct { u8 pad0[0x80]; f32 position[4]; } Hero_00334238;
extern Hero_00334238 D_001A4BE0;
f32 func_L07_00334238(void *arg) {
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_L05_0043F7E0(void *, void *, f32 *, f32 *, void *, void *, void *, f32);
    extern f32 func_0038D160(f32, f32);
    V_00334238 start, end, result, hit, pos;
    f32 a, b;
    u8 *obj=arg;
    f32 x,y;
    start.q=D_L07_001E1EC0.position.q;
    end.q=D_L07_001E1EC0.direction.q;
    func_0038CF68(&end,&end,100.0f);
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(end) : "m"(start), "m"(end) : "vf1", "vf2");
    pos.q=*(Q_00334238 *)(obj+0x10);
    if (func_L05_0043F7E0(&result,&hit,&a,&b,&start,&end,&pos,40.0f)) {
        x=*(f32 *)(obj+0x10);
        y=*(f32 *)(obj+0x14);
        x=hit.f[0]-x;
        y=hit.f[1]-y;
    } else {
        x=*(f32 *)(obj+0x10);
        y=*(f32 *)(obj+0x14);
        x=D_001A4BE0.position[0]-x;
        y=D_001A4BE0.position[1]-y;
    }
    return func_0038D160(x,y);
}
/* localdecomp:end func_L07_00334238 */
