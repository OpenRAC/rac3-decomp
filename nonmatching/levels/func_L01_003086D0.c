/* PAL near miss (Codex wave 8): near miss: 0 words differ with the file's flags.
 * Worker's note: 0 word diffs at all 34 places, v3.log; TYPE_CONTRACT_FAIL: exact S_0030CD20 typedef lives later in owner. Standalone types.h copies its exact definition; Claude must hoist existing typedef before this function and remove reference include. No incompatible ...
 */
#include "common.h"
/* localdecomp:start func_L01_003086D0 */
#include "vu0.h"
/* Standalone reference: the existing S_0030CD20 typedef must be hoisted before integration. */
#include "build/codex/w384/func_L01_003086D0.types.h"
void func_L01_003086D0(u8 *object, vu0_v4 *origin, vu0_v4 *out, f32 radius) {
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern void func_0038D000(void *, void *, void *);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038CF68(S_0030CD20 *, S_0030CD20 *, f32);
    /* Retail reserves 0xD0 bytes for this point workspace. */
    vu0_v4 scratch[13];
    vu0_v4 a, b;
    vu0_v4 *p = (vu0_v4 *)&scratch;
    s32 i;
    f32 angle = 0.0f;
    for (i = 1; i >= 0; i--, p++) {
        angle = func_0038DAB8(angle, 0.5711987018585205f);
        p->w = 0.0f;
        p->y = 0.0f;
        p->x = func_0038D098(angle) * radius;
        p->z = -func_0038D0B0(angle) * radius;
        func_0038D000(p, p, object + 0xC0);
        vec_add_ab(p, p, origin);
    }
    vec_sub_ba(&a, &((vu0_v4 *)&scratch)[0], origin);
    vec_sub_ba(&b, &((vu0_v4 *)&scratch)[1], origin);
    func_0038CE90(out, &a, &b);
    func_0038CF68((S_0030CD20 *)out, (S_0030CD20 *)out, 1.0f);
}
/* localdecomp:end func_L01_003086D0 */
