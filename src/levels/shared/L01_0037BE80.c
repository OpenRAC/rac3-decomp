#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_0037BE80 */
#include "vu0.h"
extern vu0_v4 D_L01_001D7C50[];
void func_L01_0037BE80(u8 *obj, vu0_v4 *pos, s32 tex0, s32 tex1, u32 color, f32 size, f32 zoom0, f32 zoom1, f32 rot0, f32 rot1, f32 offset, s32 mode) {
    extern unsigned long func_00389598(s32);
    extern void func_0038D308(void *, void *);
    extern void func_0038D5F0(void *, void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038D028(void *, void *, void *);
    extern void func_003A9440(s32, unsigned long);
    extern void func_003D2DA0(void *, s32, s32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    struct {
        vu0_v4 v[4];
        u32 colors[4];
        f32 uv[8];
        unsigned long tag, tex, alpha, prim;
    } packet;
    vu0_v4 mat[4];
    vu0_v4 off;
    vu0_v4 rotation[3];
    s32 i;
    f32 *u, *v;
    f32 *pu, *pv;
    unsigned long tex = func_00389598(tex0);
    packet.tex = tex;
    packet.alpha = 0xFF9000000260UL;
    packet.tag = 5;
    packet.prim = 0x800000006AUL;
    packet.colors[0] = packet.colors[1] = packet.colors[2] = packet.colors[3] = color;
    *(vu0_q *)&mat[3] = *(vu0_q *)pos;
    *(vu0_q *)&mat[0] = *(vu0_q *)(obj + 0xC0);
    *(vu0_q *)&mat[1] = *(vu0_q *)(obj + 0xD0);
    *(vu0_q *)&mat[2] = *(vu0_q *)(obj + 0xE0);
    packet.uv[0] = 0; packet.uv[1] = 0; packet.uv[2] = 0; packet.uv[3] = 1;
    packet.uv[4] = 1; packet.uv[5] = 0; packet.uv[6] = 1; packet.uv[7] = 1;
    if (rot0 != 0.0f) {
        *(vu0_q *)&off = 0;
        off.x = rot0;
        func_0038D308(rotation, &off);
        func_0038D5F0(mat, mat, rotation);
    }
    {
        f32 inv = 1.0f / zoom0;
        f32 *cv, *cu;
        s32 n;
        pu = &packet.uv[0]; pv = &packet.uv[1];
        cv = pv; cu = pu;
        for (n = 3; n >= 0; n--) {
            f32 x = *cu, y = *cv;
            *cu = (x - 0.5f) * inv + 0.5f;
            *cv = (y - 0.5f) * inv + 0.5f;
            cu += 2; cv += 2;
        }
    }
    func_0038CE20(&off, mat, offset);
    vec_add_ab(&mat[3], &mat[3], &off);
    for (i = 0; i < 4; i++) {
        func_0038CE20(&packet.v[i], &D_L01_001D7C50[i], size);
        func_0038D028(&packet.v[i], &packet.v[i], mat);
    }
    func_003A9440(0x47, 0x51001);
    func_003D2DA0(&packet, 0, 0);
    packet.tex = func_00389598(tex1);

    if (mode != 0) packet.prim = 0x8000000054UL;
    else packet.prim = 0x8000000058UL;

    packet.uv[0] = 0; packet.uv[1] = 0; packet.uv[2] = 0; packet.uv[3] = 1;
    packet.uv[4] = 1; packet.uv[5] = 0; packet.uv[6] = 1; packet.uv[7] = 1;
    v = pv; u = pu;
    for (i = 3; i >= 0; i--) {
        f32 x = *u - 0.5f;
        f32 y = *v - 0.5f;
        
        *u = (x * func_0038D098(rot1) - y * func_0038D0B0(rot1)) * (1.0f / zoom1) + 0.5f;
        *v = (y * func_0038D098(rot1) + x * func_0038D0B0(rot1)) * (1.0f / zoom1) + 0.5f;
        u += 2; v += 2;
    }
    func_003D2DA0(&packet, 0, 0);
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L01_0037BE80 */

/* localdecomp:start func_L01_0037C208 */
extern f32 func_0038DAB8(f32, f32);
extern void func_003D9508(u8 *, s32, u32, s32, f32, f32, f32);
extern f32 func_00382538(void);

void func_L01_0037C208(u8 *arg0) {
    u8 *sub;

    sub = *(u8 **)(arg0 + 104);
    *(f32 *)(sub + 16) = func_0038DAB8(*(f32 *)(sub + 16), 0.017453292f);
    func_003D9508(arg0 + 16, 57, 0x40505050, 1, 0.5f, 0.08f, func_0038DAB8(*(f32 *)(sub + 16) * 2.5f, 0.0f));
    func_003D9508(arg0 + 16, 42, 0x207F2040, 1, 0.5f, 0.08f, func_0038DAB8(-*(f32 *)(sub + 16) * 1.5f, 0.0f));
    func_003D9508(arg0 + 16, 44, 0x207F2040, 1, 0.5f, 0.08f, func_0038DAB8(*(f32 *)(sub + 16), 0.0f));
    func_003D9508(arg0 + 16, 49, 0x20FF7F00, 1, 0.36f, 0.08f, *(f32 *)(sub + 16) * 0.5f);
    func_003D9508(arg0 + 16, 49, 0x0020FF7F, 1, 0.36f, 0.08f, *(f32 *)(sub + 16) * -0.5f);
    func_003D9508(arg0 + 16, 47, 0x507F7F7F, 1, 0.11f, 0.08f, func_00382538());
}
/* localdecomp:end func_L01_0037C208 */
