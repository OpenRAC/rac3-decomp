#include "common.h"

/* localdecomp:start func_L21_003A41F8 */
#include "vu0.h"
extern u8 D_001A4C60[];
extern vu0_v4 D_001D66E0 __attribute__((section(".sdata")));
__asm__(".extern D_001D66E0, 16");
extern void func_003C4098(void *, void *, void *, f32);
extern void func_L01_0040EE50(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038D308(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_003C47E8(void *, void *);
extern void func_0038D688(void *, void *, void *);

void func_L21_003A41F8(u8 *a, u8 *b) {
    vu0_v4 d;
    vu0_v4 up;
    vu0_v4 rot;
    vu0_v4 q;
    vu0_v4 m[3];
    vu0_v4 r[3];
    vu0_v4 basis[3];
    vu0_v4 rm[3];
    vu0_v4 from;
    vu0_v4 to;

    vec_sub_ab(&d, D_001A4C60, a + 0x10);
    if (fabs_asm(d.x) + fabs_asm(d.y) + fabs_asm(d.z) < 25.0f) {
        from = *(vu0_v4 *)(b + 0x40);
        to = *(vu0_v4 *)D_001A4C60;
        func_003C4098(b + 0x40, &from, &to, *(f32 *)(b + 0x54));
    } else {
        d = *(vu0_v4 *)(a + 0x10);
        from = *(vu0_v4 *)(b + 0x40);
        d.z -= 1.0f;
        func_003C4098(b + 0x40, &from, &d, *(f32 *)(b + 0x54));
    }
    func_L01_0040EE50(m, a + 0xC0);
    up = D_001D66E0;
    vec_sub_ba(&d, b + 0x40, a + 0x10);
    func_0038CF68(&basis[0], &d, 1.0f);
    func_0038CE90(&basis[1], &basis[0], &up);
    func_0038CF68(&basis[1], &basis[1], 1.0f);
    func_0038CE90(&basis[2], &basis[1], &basis[0]);
    rot.x = 0.0f;
    rot.y = -1.5707964f;
    rot.z = 0.0f;
    rot.w = 0.0f;
    func_0038D308(rm, &rot);
    func_0038D5F0(r, basis, rm);
    func_003C47E8(b + 0x10, r);
    func_003C47E8(&q, m);
    func_0038D688(b + 0x10, b + 0x10, &q);
}
/* localdecomp:end func_L21_003A41F8 */
