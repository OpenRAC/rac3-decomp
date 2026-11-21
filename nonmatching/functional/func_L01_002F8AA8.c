/* functional: medium. Near-miss draft, 8 words differ (detach flag register, frame-counter temp, call scheduling). */
/* localdecomp:start func_L01_002F8AA8 */
#include "vu0.h"
typedef struct {
    u8 pad[0xAA];
    u16 f_AA;
} S_002F94F8;
extern vu0_v4 D_L01_0026E040[][2];
extern u8 *D_L01_001E001C;
extern s32 D_L01_001DFB40 __attribute__((section(".data")));
void func_L01_002F8AA8(u8 *obj, vu0_q *out_pos, vu0_q *out_rot) {
    extern s32 func_L01_002F94F8(S_002F94F8 *);
    extern void func_0038D688(void *, void *, void *);
    extern void func_L01_0044C998(void *, void *, void *, void *, void *, void *);
    extern void func_003C3FC0(void *, void *);
    extern void func_0038D850(void *, void *, void *);
    extern s32 func_L01_003FB640(void *, s32, f32, void *);
    extern void func_L01_004450F0(void *, s32, s32);
    extern u8 *func_003C4D58(void *);
    extern void func_0038D810(void *, void *);
    extern void func_0038CE20(f32 *, f32 *, f32);
    vu0_v4 offset, position, rotation, direction, angles, parent_matrix;
    u8 *vars = *(u8 **)(obj + 0x68);
    s32 kind = func_L01_002F94F8((S_002F94F8 *)obj);
    Src_002F7888 *settings;
    func_0038D688(vars + 0x50, &D_L01_0026E040[kind][vars[0x6D] & 1], vars + 0x50);
    func_0038D688(vars + 0x10, vars + 0x10, vars + 0x30);
    func_0038D688(&rotation, vars + 0x50, vars + 0x10);
    if (*(u8 **)(vars + 0x64)) {
        s32 detach;
        u8 *parent;
        qzero(&angles);
        func_L01_0044C998(obj, *(u8 **)(vars + 0x64), vars, &angles, &position, &angles);
        func_003C3FC0(&parent_matrix, &angles);
        func_0038D688(&rotation, &rotation, &parent_matrix);
        func_0038D850(&direction, vars + 0x40, &parent_matrix);
        if (obj[0x20] == 3) {
            detach = 0;
            parent = *(u8 **)(vars + 0x64);
            if (parent == 0 || parent[0x20] == 0xFE || parent[0x20] == 0xFD) {
                detach = 1;
            } else if (((D_L01_001DFB40 + ((obj - D_L01_001E001C) >> 8)) & 7) == 0) {
                detach = !func_L01_003FB640(obj + 0x10, 0x22, 0.25f, obj);
            }
            if (detach) {
                u8 *p;
                func_L01_004450F0(obj, 1, -1);
                qzero(vars + 0x20);
                *(f32 *)(vars + 0x2C) = 1.0f;
                p = func_003C4D58(*(u8 **)(vars + 0x64));
                if (p) *(vu0_q *)(vars + 0x30) = *(vu0_q *)(p + 0x10);
                else qzero(vars + 0x30);
                *(s32 *)(vars + 0x64) = 0;
            }
        }
    } else {
        *(vu0_q *)&position = *(vu0_q *)vars;
        *(vu0_q *)&direction = *(vu0_q *)(vars + 0x40);
    }
    func_0038D810(&rotation, obj + 0xC0);
    kind = func_L01_002F94F8((S_002F94F8 *)obj);
    settings = &D_L01_002BE708[kind];
    func_0038CE20((f32 *)(obj + 0x10), (f32 *)&direction, *(f32 *)((u8 *)settings + 4));
    func_0038CE20((f32 *)&offset, (f32 *)(obj + 0xC0), *(f32 *)((u8 *)settings + 8));
    vec_add_ba(obj + 0x10, obj + 0x10, &offset);
    vec_add_ab(obj + 0x10, obj + 0x10, &position);
    if (out_pos) *out_pos = *(vu0_q *)&position;
    if (out_rot) *out_rot = *(vu0_q *)&rotation;
}
/* localdecomp:end func_L01_002F8AA8 */
