/* functional: high. Retail uses gp-relative loads for the two float tables and VU0 vadd.xyz for the position add; C does the same adds with plain floats and lui-addressed tables (same memory, same results). Branch structure, offsets and callees verified against PAL asm. */
#include "common.h"
/* localdecomp:start func_L01_003C64E0 */
#include "vu0.h"
static __inline__ void add_xyz_3C64E0(vu0_v4 *d, f32 *b) { d->x += b[0]; d->y += b[1]; d->z += b[2]; }
extern vu0_v4 D_L01_002BB340[];
extern vu0_v4 D_L01_002BB390[];
extern f32 D_L01_001DEE28[];
extern f32 D_L01_001DEE40[];
__asm__(".extern D_L01_001DEE28, 16");
__asm__(".extern D_L01_001DEE40, 16");
extern int D_L01_001F3F40[];
extern u8 *D_L01_001E0100;
extern void func_0038D000(void *, void *, void *);
extern void func_0038D308(void *, void *);
extern f32 func_0038DAB8(f32, f32);
void func_L01_003C64E0(u8 *m, s32 idx, vu0_v4 *out, f32 *outf) {
    u8 *v = *(u8 **)(m + 0x68);
    f32 ang, tab;
    vu0_v4 tmp;
    if (v[0x101] != 0) {
        func_0038D000(out, &D_L01_002BB340[idx], m + 0xC0);
        add_xyz_3C64E0(out, (f32 *)(m + 0x10));
        tab = D_L01_001DEE28[idx];
        ang = *(f32 *)(m + 0xF8);
    } else {
        s32 n = *(s32 *)(v + 0xCC);
        if (n != -1 && D_L01_001F3F40[0] == *(s32 *)(v + 0xE0)) {
            u8 *node = D_L01_001E0100 + (n << 7);
            func_0038D308(&tmp, node + 0x70);
            func_0038D000(out, &D_L01_002BB390[idx], &tmp);
            add_xyz_3C64E0(out, (f32 *)(node + 0x30));
            tab = D_L01_001DEE40[idx];
            ang = *(f32 *)(node + 0x78);
        } else {
            func_0038D000(out, &D_L01_002BB390[idx], m + 0xC0);
            add_xyz_3C64E0(out, (f32 *)(m + 0x10));
            tab = D_L01_001DEE40[idx];
            ang = *(f32 *)(m + 0xF8);
        }
    }
    *outf = func_0038DAB8(ang, tab);
}
/* localdecomp:end func_L01_003C64E0 */
