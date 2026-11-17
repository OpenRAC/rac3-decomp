/* PAL near miss (Codex wave 7): near miss: 57 words differ with the file's flags.
 * Worker's note: 57 diff best; VU/global-base scheduling, extra first-call delay nop, division register allocation and output load order. Three scalar/local formulations produce the same wrong 60-diff object; original 57-diff draft retained. Log ...
 */
#include "common.h"
/* localdecomp:start func_00389858 */
#include "vu0.h"
extern f32 D_222400[];
extern f32 D_225B20[];
extern s32 D_1D4BC0[];
extern s32 D_1D4BC4[];
void func_00389858(f32 *point, f32 *x, f32 *y) {
    f32 v[4] __attribute__((aligned(16)));
    vec_sub_ba(v,point,D_222400);
    func_0038D200(v,v,1024.0f);
    v[3]=1.0f;
    func_0038D408(v,v,D_222400-64);
    func_0038D200(v,v,D_225B20[0]/v[3]);
    *x=v[0]+(f32)(D_1D4BC0[0]>>1);
    *x/=(f32)D_1D4BC0[0];
    *y=v[1]+(f32)(D_1D4BC4[0]>>1);
    *y/=(f32)D_1D4BC4[0];
}
/* localdecomp:end func_00389858 */
