#include "common.h"

/* NTSC-U counterpart of func_L03_003A14D0 (src/levels/03_starship_phoenix/L03_0039E470.c): 0.904 -> 0.92 */
void func_003C2F58(void *, s32, void *);
void func_0038CF68(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
void func_003C2F58(void *, s32, void *);
void func_0038CF68(void *, void *, f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
void func_003C2F58(void *, s32, void *);
void func_0038CF68(void *, void *, f32);

/* localdecomp:start func_L03_0039FCE8 */
#include "vu0.h"
typedef struct { u8 pad0[0x130]; vu0_v4 v130; u8 pad140[0x1C0]; void *p300; } P_003A14D0;
extern void func_003C2F58(void *, s32, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_003C4098(void *, void *, void *, f32);
void func_L03_0039FCE8(void *a, void *out, void *opt, s32 flag) {
    P_003A14D0 *p = *(P_003A14D0 **)((u8 *)a + 0x68);
    vu0_v4 v0;
    vu0_v4 d;
    vu0_v4 pos;
    vu0_v4 t;
    f32 len;
    u8 f = flag;
    pos = p->v130;
    func_003C2F58(p->p300, 0, &v0);
    if (opt != 0) *(vu0_v4 *)opt = v0;
    vec_sub_ab(&d, &pos, &v0);
    d.z = 0;
    len = func_0038CEA8(&d);
    if (len > 6.0f) len = 6.0f;
    else if (len < 4.0f) len = 4.0f;
    func_0038CF68(&pos, &d, len);
    vec_add_ab(&pos, &v0, &pos);
    pos.z = func_003C3D30(&pos, 0, 0, 0.5f);
    if (f != 0) {
        *(vu0_v4 *)out = pos;
    } else {
        t = *(vu0_v4 *)out;
        func_003C4098(out, &pos, &t, 0.920000017f);
    }
}
/* localdecomp:end func_L03_0039FCE8 */
