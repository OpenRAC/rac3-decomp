/* PAL near miss (Codex wave 6): near miss: 100 words differ with the file's flags.
 * Worker's note: 83 instruction differences with injected divs 1,0: loop induction, saved registers, constant hoisting and fixed VU0 sequence scheduling; w302/func_L01_00366240.03.log; metadata not proven exact
 */
#include "common.h"
/* localdecomp:start func_L01_00366240 */
#include "vu0.h"
static __inline__ void sub_ba_00366240(void *d, void *a, void *b) {
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)b), "m"(*(vu0_v4 *)a) : "vf1", "vf2");
}
static __inline__ void add_ba_00366240(void *d, void *a, void *b) {
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)b), "m"(*(vu0_v4 *)a) : "vf1", "vf2");
}
static __inline__ void add_ab_00366240(void *d, void *a, void *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b) : "vf1", "vf2");
}
extern f32 D_001DD784_sda;
extern s32 D_001DD778_sda;
extern s32 D_001DD7DC_sda;
extern s32 D_001DD774_sda;
extern u8 D_L01_0028CAA0[];
extern vu0_v4 D_L01_0028E390[];
__asm__(".extern D_001DD784_sda, 4");
__asm__(".extern D_001DD778_sda, 4");
__asm__(".extern D_001DD774_sda, 4");
void func_L01_00366240(void *arg) {
    extern f32 func_0038CEA8(void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_003661D8(void *);
    vu0_v4 a, b, c;
    u8 *row;
    s32 offset;
    u8 *obj;
    f32 length;
    D_001DD784_sda *= 0.5f;
    D_001DD778_sda = 1;
    D_001DD7DC_sda = 0;
    D_001DD774_sda = 1;
    offset = 0;
    row = D_L01_0028CAA0;
    do {
        obj = *(u8 **)(D_L01_0028CAA0 + 0x1C + offset);
        if (obj != 0) {
            *(u8 **)(D_L01_0028CAA0 + 0x1C + offset) = 0;
            sub_ba_00366240(&a, &D_L01_0028E390[*(s16 *)row], &D_L01_0028E390[1 + *(s16 *)row]);
            length = func_0038CEA8(&a);
            func_0038CE20((s128 *)&a, (s128 *)&a, *(f32 *)(D_L01_0028CAA0 + offset + 4) / length);
            add_ba_00366240(&b, &D_L01_0028E390[1 + *(s16 *)row], &a);
            sub_ba_00366240(&c, obj + 0x10, &b);
            func_0038CF68(&c, &c, 0.03f);
            func_0038CE20((s128 *)&a, (s128 *)&a, 0.1f / length);
            add_ab_00366240(obj + 0x30, &c, &a);
            if (*(s32 *)(row + 0xC) != 0) *(s16 *)(obj + 0xA) = 10;
            else *(s16 *)(obj + 0xA) = 70;
            *(s32 *)(row + 0xC) = 0;
        }
        row += 0x20;
        offset += 0x20;
    } while ((s32)row < (s32)(D_L01_0028CAA0 + 0x1900));
    func_L01_003661D8(arg);
}
/* localdecomp:end func_L01_00366240 */
