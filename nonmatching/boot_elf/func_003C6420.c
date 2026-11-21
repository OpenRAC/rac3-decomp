/* PAL near miss (Codex wave 11): flags: byte-exact only with "-O2 -G8 -mno-check-zero-division -mvu0-use-vf0-vf2 @ps2as" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division -mvu0-use-vf0-vf2 @ps2as").
 * Replaces the earlier draft (US draft of func_003C62D0: does not compile under tools/check.py with "-O2 -G8 -mno-check-zero-division -mvu0-use-vf0-vf2 @ps2as" and a config/boot_elf/sq_ra_funcs.txt row, compiled in its file as the full build does, measured 2026-11-21;
 * this one: MATCH).
 * Worker's note: body exact; 29 diff with the file line, 27 with --sq-ra injected (W/func_003C6420/check-file-flags*.log), all in the callee-saved slots: retail saves $s0-$s7,$fp,$ra with sq in 16-byte slots, frame 0xC0. Local experiment W/exp_flags.py with -fno-opt-stack plus injected sq_ra prints MATCH (W/func_003C6420/exp-nooptstack-sqra.log); -fno-opt-stack alone is 20 diff (slot order). NEEDS flags '-O2 -G8 -mno-check-zero-division -mvu0-use-vf0-vf2 @ps2as' (a file of its own at 0x003C6420, as the wiki says for 0x0038B500/0x003BFE80) and NEEDS sq_ra row 'func_003C6420'. C is the nonmatching draft without its typedefs, which the file already declares (E3C/P3C/S3C/O3C)
 * Landing test (2026-11-21, the file compiled as the full build does) with "-O2 -G8 -mno-check-zero-division -mvu0-use-vf0-vf2 @ps2as": byte-exact with that line and a config/boot_elf/sq_ra_funcs.txt row, but on 3C5A98.c it breaks func_003C5A98 (26 diff): needs a file of its own at 0x003C6420.
 */
#include "common.h"

/* localdecomp:start func_003C6420 */
s32 func_003C6420(O3C *obj, s32 key, s32 *idx, f32 *o1, f32 *o2, f32 *o3, f32 *o4, f32 *o5, f32 *o6, f32 *o7, u8 *o8) {
    E3C *e;
    s32 cnt = 0;
    s32 r;
    s32 i;
    s32 j;
    for (j = 0; j < obj->set->n; j++) {
        if (obj->set->arr[j]->e) {
            if (obj->set->arr[j]->e->key == key) cnt++;
        }
    }
    if (cnt == 0) return 0;
    r = func_00382848(cnt);
    for (i = 0; i < obj->set->n; i++) {
        e = obj->set->arr[i]->e;
        if (e && e->key == key) {
            if (r != 0) {
                r--;
            } else {
                *o1 = e->f8 * 0.020000001f;
                *o2 = e->fC * 0.020000001f;
                *o3 = e->f10 * 0.00040000002f;
                *o4 = e->f14 * 0.00040000002f;
                *o7 = e->f4 * 0.00040000002f;
                *o5 = e->f18;
                *o6 = e->f1C;
                if (e->b1) *o8 = e->b1;
                *o1 = func_003828C0(*o1 * 0.87f, *o1 * 1.13f);
                *o2 = func_003828C0(*o2 * 0.85f, *o2 * 1.15f);
                *o3 = func_003828C0(*o3 * 0.85f, *o3 * 1.15f);
                *o7 = func_003828C0(*o7 * 0.9f, *o7 * 1.1f);
                *idx = i;
                return 1;
            }
        }
    }
    return 0;
}
/* localdecomp:end func_003C6420 */
