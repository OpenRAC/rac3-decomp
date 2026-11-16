/* PAL near miss (Codex wave 8): near miss: does not compile in its file's context yet (declaration conflicts; the worker's note at the top has the details).
 * Worker's note: 1 diff in declaration-contract context (.05-contract.log): andi s1,a2,255 vs move. Ordinary checker fails: existing Part_00470258/Sub_00470258/s128_00470258 typedefs need moving earlier, before target; exact allocator signature preserved; no aliases/casts ...
 */
#include "common.h"
/* localdecomp:start func_L01_00472F58 */
typedef struct { u8 reserved; u8 mode; u8 rest[0xEE]; } Row_00472F58;
extern u8 D_001425D1[];
extern Row_00472F58 D_L01_002C5600[];
extern u8 *D_L01_0022124C[];
Part_00470258 *func_L01_00472F58(s128_00470258 *pos, s128_00470258 *velocity, u8 render, f32 scale) {
    extern Part_00470258 *func_L01_004618E0(s32);
    extern s32 func_00382468(s32);
    extern u8 func_00382498(s32, s32);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_0038DBD8(s32, s32, f32);
    Part_00470258 *p = func_L01_004618E0(109);
    Sub_00470258 *v;

    if (p != 0) {
        p->f10 = *pos;
        p->f3 = render;
        p->f1 = 0;
        p->f9 = 68;
        v = &p->sub;
        p->f8 = func_00382468(255);
        p->fA = (func_00382498(5, 50) * 5 + 2) / 6;
        v->v = *velocity;
        p->fC = scale * 210000.0f * 2.5f;
        if (((Row_00472F58 *)((s32)D_L01_002C5600 + D_001425D1[0] * 0xF0))->mode >= 4) {
            v->f10 = func_00382498(160, 192);
            p->f2 = *D_L01_0022124C[0];
            p->f4 = func_0038DBD8(0x803030, 0x7F7F7F, func_003824E0(0.0f, 0.5f)) | (v->f10 << 24);
        } else {
            v->f10 = func_00382498(64, 128);
            p->f2 = *D_L01_0022124C[0];
            p->f4 = func_0038DBD8(0x103080, 0, func_003824E0(0.0f, 0.5f)) | (v->f10 << 24);
        }
    }
    return p;
}
/* localdecomp:end func_L01_00472F58 */
