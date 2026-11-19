/* functional: high. 171 words differ (register allocation and scheduling; the file line has no vu0 flag and the code needs none); all branches, constants and callee args re-read against the asm. */
/* localdecomp:start func_L31_00344C30 */
#include "vu0.h"
__asm__(".extern D_L31_001DCFB4, 4");
__asm__(".extern D_L31_001DF880, 4");
extern f32 D_L31_001DCFB4;
extern u8 *D_L31_001DF880;
extern u8 D_001A4BE0[];
extern vu0_v4 D_001A4C60;
extern void func_L30_0034CDC0(f32 *, f32 *, f32 *, f32 *, f32);
extern void func_L30_0034CCD0(u8 *, f32 *, f32 *, f32 *, f32 *);
extern f32 func_003C4088(f32, f32, f32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern f32 func_003824E0(f32, f32);
void func_L31_00344C30(u8 *o, s32 idx, vu0_v4 *out) {
    u8 *p = *(u8 **)(o + 0x68);
    u8 *e;
    vu0_v4 s;
    f32 b0, b1, b2, b3;
    f32 c0, c1, c2, c3;
    s32 found = 0;
    s32 i;
    s32 id;

    func_L30_0034CDC0(&b0, &b1, &b2, &b3, D_L31_001DCFB4);
    e = p + idx * 0x30;
    if (e[3] < 2) {
        f32 r;
        s = D_001A4C60;
        s.x = e[3] != 0 ? b1 : b0;
        id = *(s32 *)(e + 4);
        if (id >= 0) {
            s.z = *(f32 *)(D_L31_001DF880 + id * 0x80 + 0x38);
            *out = s;
            return;
        }
        i = 0;
        do {
            s.z = func_003C4088(*(f32 *)(D_001A4BE0 + 0x88), b3, (f32)i / 3.0f);
            r = func_003C3D30(&s, 0, 0, 0.5f);
            s.z = r;
            if (b2 < r && r < b3) {
                *out = s;
                found = 1;
            }
            i++;
        } while (i < 4 && !found);
        if (!found) {
            *out = D_001A4C60;
        }
    } else if ((u8)(e[3] - 2) < 2) {
        *out = D_001A4C60;
        out->z = e[3] == 2 ? b3 : b2;
        id = *(s32 *)(e + 4);
        if (id >= 0) {
            func_L30_0034CCD0(D_L31_001DF880 + id * 0x80, &c0, &c1, &c2, &c3);
            out->x = func_003824E0(c0, c1);
        } else {
            f32 t = func_003824E0(0.15f, 0.85f);
            out->x = func_003C4088(b0, b1, t);
        }
    } else if (e[3] == 4) {
        id = *(s32 *)(e + 4);
        *out = *(vu0_v4 *)(D_L31_001DF880 + id * 0x80 + 0x30);
        func_L30_0034CCD0(D_L31_001DF880 + *(s32 *)(e + 4) * 0x80, &c0, &c1, &c2, &c3);
        out->x = func_003824E0(c0, c1);
        out->z = func_003824E0(c2, c3);
    }
}
/* localdecomp:end func_L31_00344C30 */
