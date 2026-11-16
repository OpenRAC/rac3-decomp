/* PAL near miss (Codex wave 10): near miss: 13 words differ with the file's flags.
 * Worker's note: Best 11 diff with --sq-ra: build/codex/w512/func_L01_0035F340.08.log; fixed -fopt-stack leaves 0x30 frame/8-byte save slots vs retail 0x50/16-byte slots; no MATCH; ordinary .09.log. Existing spawn alias reused with exact declared type. Stack argument at ...
 */
#include "common.h"
/* localdecomp:start func_L01_0035F340 */
typedef struct { s128 velocity; s32 x10; s32 x14; f32 x18; s32 x1c; s32 x20; f32 x24; s32 owner; s32 x2c; s32 x30; s32 x34; s32 x38; } Vars_0035F340;
__asm__(".extern D_L01_001DD708, 4");
__asm__(".extern D_L01_001DD70C, 4");
__asm__(".extern D_L01_001DD704, 4");
__asm__(".extern D_L01_001DD710, 4");
extern s32 D_L01_001DD708, D_L01_001DD70C;
extern f32 D_L01_001DD704, D_L01_001DD710;
extern f32 D_L01_001E1AA0, D_L01_001E1AA4, D_L01_001E1AA8, D_L01_001E1AAC, D_L01_001E1AB0, D_L01_001E1AB4;
extern u8 D_00142A60[];
extern u8 D_00142637[];
typedef struct { u8 x0, kind; u8 pad[0xee]; } Gun_0035F340;
extern Gun_0035F340 D_L01_002C5600_0035F340[];
u8 *func_L01_0035F340(s32 owner, s128 *position, s128 *velocity, s32 unused, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 value)
{
    extern u8 *func_003C24B0_0035E638(s32, s32);
    extern f32 func_00382538(void);
    u8 *m = func_003C24B0_0035E638(0x1858, 0x80);
    Vars_0035F340 *v;
    if (m != 0) {
        *(s128 *)(m+0x10) = *position;
        v = *(Vars_0035F340 **)(m+0x68);
        m[0x30] = 255;
        *(s16 *)(m+0x32) = 255;
        m[0x20] = 0;
        v->x14 = 83;
        v->x18 = 1.5f;
        v->x1c = 17;
        v->x10 = 0;
        D_L01_001DD708 = 0;
        D_L01_001DD70C = 0;
        v->x20 = 60;
        v->x24 = 1.0f;
        D_L01_001DD704 = 1.0f;
        v->owner = owner;
        v->velocity = *velocity;
        D_L01_001DD710 = 1.0f;
        v->x38 = value;
        v->x34 = 0;
        D_L01_001E1AA0 = func_00382538();
        D_L01_001E1AA4 = func_00382538();
        D_L01_001E1AA8 = func_00382538();
        D_L01_001E1AAC = func_00382538();
        D_L01_001E1AB0 = func_00382538();
        D_L01_001E1AB4 = func_00382538();
        if (((Gun_0035F340 *)((s32)D_L01_002C5600_0035F340 + D_00142637[0]*0xF0))->kind != 0) D_00142A60[0x77] |= 8;
    }
    return m;
}
/* localdecomp:end func_L01_0035F340 */
