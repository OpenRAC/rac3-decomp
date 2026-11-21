/* PAL near miss (haiku-w2): 216 words differ with the file's flags; frame is 0x100 against retail's 0x110, register allocation of self/enabled/g/history differs, and the VU0 loop's scheduling remains. */
#include "common.h"
/* localdecomp:start func_L01_004EB978 */
#include "vu0.h"
extern u8 D_001A4BE0[];
extern s32 D_001DBD34_sda;
__asm__(".extern D_001DBD34_sda, 4");
void func_L01_004EB978(u8 *self, Vec4 *matrix, s32 enabled) {
    extern void func_0038D590(void *, void *);
    extern void func_L01_00448E10(void *);
    extern f32 func_L01_004EB918(f32 a[][4], f32 b[][4]);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_003C48A8(Vec4 *, Vec4 *);
    Vec4 sum[4];
    f32 scores[16];
    u8 *g = D_001A4BE0;
    u8 *history = g + 0x16E0;
    s32 i,j,k,n;
    s32 good,used;
    f32 maximum;
    func_0038D590(history + *(s32 *)(g + 0x26FC) * 48, matrix);
    func_L01_00448E10(history + *(s32 *)(g + 0x26FC) * 48);
    *(s32 *)(g + 0x26FC) = (*(s32 *)(g + 0x26FC) + 1) % 16;
    *(s32 *)(g + 0x2700) += 1;
    if (*(s32 *)(g + 0x2700) > 16) *(s32 *)(g + 0x2700) = 16;
    if (!enabled) return;
    for (k = 2; k >= 0; --k) qzero(&sum[k]);
    if (*(s32 *)(D_001A4BE0 + 0x25C4) == 2) D_001DBD34_sda = 5;
    else D_001DBD34_sda = 7;
    if (*(s32 *)(D_001A4BE0 + 0x2704) < D_001DBD34_sda) ++*(s32 *)(D_001A4BE0 + 0x2704);
    else if (*(s32 *)(D_001A4BE0 + 0x2704) > D_001DBD34_sda) --*(s32 *)(D_001A4BE0 + 0x2704);
    n = *(s32 *)(D_001A4BE0 + 0x2704);
    if (n < 2) n = 2;
    if (D_001A4BE0[0x25E9] && *(s32 *)(D_001A4BE0 + 0x1D8) < 8 && n > 3) n = 3;
    if (*(s32 *)(D_001A4BE0 + 0x2700) < n) return;
    used = 0;
    good = 0;
    for (i = 0; i < n;) {
        s32 next = i + 1;
        s32 back = i - 15;
        s32 row = (*(s32 *)(D_001A4BE0 + 0x26FC) - back) % 16;
        for (j = 0; j < n; j++) {
            if (i != j) {
                s32 back2 = j - 15;
                s32 other = (*(s32 *)(D_001A4BE0 + 0x26FC) - back2) % 16;
                scores[i] += func_L01_004EB918((f32 (*)[4])(history + row * 48), (f32 (*)[4])(history + other * 48));
            }
        }
        i = next;
    }
    maximum = 0.0f;
    for (i = 0; i < n; i++) if (scores[i] > maximum) maximum = scores[i];
    for (i = 0; i < n; i++) if (scores[i] > maximum * 0.2f) good++;
    for (i = 0; i < n;) {
        s32 next = i + 1;
        if (!(scores[i] > maximum * 0.2f && good > 0 && good < 3)) {
            s32 back = i - 15;
            s32 idx = (*(s32 *)(D_001A4BE0 + 0x26FC) - back) % 16;
            vu0_v4 *src = (vu0_v4 *)(history + idx * 48);
            Vec4 *dst = sum;
            used++;
            for (k = 2; k >= 0; --k) {
                __asm__("lqc2 vf2, %1\n\tlqc2 vf1, %2\n\tvadd.xyz vf2, vf2, vf1\n\tsqc2 vf2, %0" : "=m"(*dst) : "m"(*dst), "m"(*src) : "vf1", "vf2");
                src++; dst++;
            }
        }
        i = next;
    }
    for (k = 0; k < 3; k++) func_0038CE20(&sum[k], &sum[k], 1.0f / (f32)used);
    func_003C48A8(sum, (Vec4 *)(self + 0xF0));
}
/* localdecomp:end func_L01_004EB978 */
