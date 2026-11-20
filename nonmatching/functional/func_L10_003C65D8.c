/* functional: high. Near miss (3 instrs, scheduling of two stack-arg constants only); callees, constants and stack slots verified against retail asm. Needs -mvu0-use-vf0-vf2 flag + vu0.h to compile. */
#include "vu0.h"
/* plain-C stand-ins for the VU0 vector ops (xyz lanes, w from the first source) */
static __inline__ void vc_add(void *d, void *a, void *b) { float *D = (float *)d, *A = (float *)a, *B = (float *)b; float x = A[0] + B[0], y = A[1] + B[1], z = A[2] + B[2], w = A[3]; D[0] = x; D[1] = y; D[2] = z; D[3] = w; }
static __inline__ void vc_sub(void *d, void *a, void *b) { float *D = (float *)d, *A = (float *)a, *B = (float *)b; float x = A[0] - B[0], y = A[1] - B[1], z = A[2] - B[2], w = A[3]; D[0] = x; D[1] = y; D[2] = z; D[3] = w; }
typedef int u128_t_3C65D8 __attribute__((mode(TI)));
__asm__(".extern D_L10_001DE8A4, 4");
extern f32 D_L10_001DE8A4;
extern u8 D_L10_001D66B0[8];
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32,
                          f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);
extern void func_0038D000(void *, void *, void *);
extern void func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_L10_003C65D8(u8 *m) {
    V4_3C64B0 p;
    V4_3C64B0 a;

    if (func_L01_00447490(m, -1, 0) != 0) {
        func_003A52A0(0, 0, m);
        func_L01_00451FE0(m, 0xF, D_L10_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 0, 3, 3.0f, 6.0f,
                          3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
        func_L10_003C64B0(m, 0x1EB2, 0);
        *(u128_t_3C65D8 *)&a = 0;
        a.z = D_L10_001DE8A4 * 29.976019f * *(f32 *)(m + 0x2C);
        p = a;
        func_0038D000(&p, &p, m + 0xC0);
        vc_add(&p, &p, m + 0x10);
        func_L01_003303B8(&p, 0, 0, 0, 0, 2, 5, 0, *(f32 *)(m + 0x2C) * 10.491607f, 0.0f, 0.0f, 0.0f,
                          0, 1, 0, 0, 0, 0, 0x1000000, 0, 0x27B2F3, 0xBDFFF, 0, 0, 0, 0, 0x7F27B2F3, 0x280BDFFF, 0, 0);
        func_L01_00451E78(m, 1, 0.0f);
        func_003C2880(m);
    }
}
