/* PAL near miss (Codex wave 10): near miss: does not compile in its file's context yet (declaration conflicts; the worker's note at the top has the details).
 * Worker's note: all2.log: every placement MATCH with exact existing Vec4_0039E0C8 typedef but TYPE_CONTRACT_FAIL duplicate; retained source removes duplicate. Owner must move its later typedef before this entry; exact func_0038CF68 signature preserved. contract-only.log ...
 */
#include "common.h"
/* localdecomp:start func_L01_0039B478 */
#include "vu0.h"
typedef struct {
    u8 pad0[16]; vu0_v4 position;
    u8 state; u8 pad21[15]; u8 alpha; u8 pad31; s16 flags;
    u8 pad34[0x34]; u8 *vars; u8 pad6C[0x54];
    vu0_v4 c0, d0, e0;
} Obj_0039B478;
extern vu0_v4 D_L01_001E29C0;
extern u8 D_00142637[];
extern Ent_003985C0 D_L01_002C5600[];
extern s32 D_L01_001E205C;
extern f32 D_L01_001E2060;
extern s32 D_L01_001DE0F4;
extern s32 D_L01_001DE0F0;
__asm__(".extern D_L01_001DE0F0, 4");
__asm__(".extern D_L01_001DE0F4, 4");
extern u32 D_L01_001E2058;
extern f32 D_L01_001E2064;
Obj_0039B478 *func_L01_0039B478(vu0_q *pos, s32 arg1, s32 arg2) {
    extern Obj_0039B478 *func_003C24B0(s32, s32);
    extern void func_0038CF68(Vec4_0039E0C8 *, Vec4_0039E0C8 *, f32);
    extern void func_003C5180(void *, void *, s32);
    extern void func_0038CE90(void *, void *, void *);
    extern s32 func_00382498(s32, s32);
    vu0_v4 v, q;
    Obj_0039B478 *obj = func_003C24B0(6296, 128);
    u8 *vars;
    s32 kind;
    u8 *entry;
    f32 zero;
    if (obj) {
        vars = obj->vars;
        obj->alpha = 255;
        obj->flags = 255;
        obj->state = 0;
        *(s32 *)(vars + 4) = arg1;
        *(s32 *)(vars + 8) = arg2;
        *(vu0_q *)&obj->position = *pos;
        obj->position.w = 1.0f;
        vec_sub_ab(&v, &D_L01_001E29C0, &obj->position);
        func_0038CF68((Vec4_0039E0C8 *)&v, (Vec4_0039E0C8 *)&v, 1.0f);
        func_003C5180(&obj->position, &q, 1);
        *(vu0_q *)&obj->c0 = *(vu0_q *)&v;
        func_0038CE90(&obj->d0, &obj->c0, &q);
        func_0038CF68((Vec4_0039E0C8 *)(&obj->d0), (Vec4_0039E0C8 *)(&obj->d0), 1.0f);
        func_0038CE90(&obj->e0, &obj->d0, &obj->c0);
        zero = 0.0f;
        obj->e0.w = zero;
        obj->d0.w = zero;
        obj->c0.w = zero;
        *(s32 *)vars = 25;
        D_L01_001E205C = 96;
        D_L01_001E2060 = 0.005f;
        entry = (u8 *)(D_L01_002C5600 + D_00142637[0]);
        kind = entry[1];
        if (kind == 1) {
            D_L01_001DE0F0 = 8;
            D_L01_001DE0F4 = 8;
            D_L01_001E2058 = (func_00382498(180, 255) << 16) | 0x80000000;
            D_L01_001E2064 = 3.5f;
        } else if (kind == 2) {
            D_L01_001DE0F0 = 12;
            D_L01_001DE0F4 = 12;
            D_L01_001E2058 = func_00382498(200, 255) | 0x800A4000;
            D_L01_001E2064 = 3.75f;
        } else if (kind >= 3) {
            D_L01_001DE0F0 = 16;
            D_L01_001DE0F4 = 16;
            D_L01_001E2058 = 0x800000FF;
            D_L01_001E2064 = 4.0f;
        }
    }
    return obj;
}
/* localdecomp:end func_L01_0039B478 */
