/* PAL near miss (Codex wave 8): near miss: 53 words differ with the file's flags.
 * Worker's note: 52 diff; w407/func_L01_00374790.attempt08.log. Complete spawn/initialization draft; initial flag helper shares 255. Residual duplicated -1 constant for stores/call, global-pointer and TI-copy scheduling; 380-byte candidate versus 376 retail. Nine compiles, ...
 */
#include "common.h"
/* localdecomp:start func_L01_00374790 */
typedef int Q_00374790 __attribute__((mode(TI)));
typedef struct {
    Q_00374790 data;
    f32 direction[4];
    Q_00374790 q20;
    f32 random;
    s32 zero34;
    u8 *owner;
    u8 pad3C[0x10];
    s32 zero4C;
    s32 pad50;
    s32 zero54;
    s32 pad58;
    s32 zero5C;
    s32 pad60;
    s32 index64;
    f32 size;
    s32 index6C;
    f32 f70, f74;
    s32 zero78, zero7C, zero80;
    u8 pad84[8];
    s32 handle;
    f32 timer;
    s32 zero94;
} Vars_00374790;
extern u8 *D_001A71A0[];
static __inline__ void draw_00374790(u8 *m, s32 n) {
    *(s16 *)(m + 0x32) = n;
    m[0x30] = n;
    m[0x20] = 0;
}
static __inline__ void init_00374790(Vars_00374790 *v, u8 *m, f32 size, s32 invalid) {
    extern s32 func_L01_004C85C8(u8 *, s32, s32, f32, f32, f32);
        v->q20 = *(Q_00374790 *)(D_001A71A0[0] + 0xD0);
        v->size = size;
        v->zero4C = 0;
        v->zero54 = 0;
        v->zero5C = 0;
        v->zero78 = 0;
        v->zero7C = 0;
        v->zero80 = 0;
        v->f74 = 2.25f;
        v->index6C = invalid;
        v->index64 = invalid;
        v->f70 = 2.25f;
        v->handle = func_L01_004C85C8(m, 0, invalid, 1.0f, 1.0f, 1.0f);
}
u8 *func_L01_00374790(u8 *owner, Q_00374790 *position, Q_00374790 *data, f32 size) {
    extern u8 *func_003C24B0(s32, s32);
    extern f32 func_00382538(void);
    extern f32 func_003824E0(f32, f32);
    extern void func_L01_004C7D98(void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_L01_004C85C8(u8 *, s32, s32, f32, f32, f32);
    extern void func_L01_004AA7E8(u8 *, s32);
    u8 *m = func_003C24B0(0x186B, 0x700);
    Vars_00374790 *v;
    u8 *pos;
    u8 *direction;
    if (m != 0) {
        draw_00374790(m, 255);
        v = *(Vars_00374790 **)(m + 0x68);
        pos = m + 0x10;
        *(Q_00374790 *)(m + 0x10) = *position;
        direction = (u8 *)v->direction;
        v->data = *data;
        v->owner = owner;
        v->random = func_00382538();
        v->zero34 = 0;
        func_L01_004C7D98(pos, direction);
        func_0038CF68(direction, direction, 0.1f);
        init_00374790(v, m, size, -1);
        v->timer = func_003824E0(7.0f, 23.0f);
        v->zero94 = 0;
        *(s32 *)(m + 0x98) = 0;
        *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & 0xEFFF;
        func_L01_004AA7E8(m, 1);
    }
    return m;
}
/* localdecomp:end func_L01_00374790 */
