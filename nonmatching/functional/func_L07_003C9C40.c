/* functional: high. Same reads/writes/calls as retail; only VU0 block scheduling differs (check.py 7 diff). */
#include "common.h"
/* localdecomp:start func_L07_003C9C40 */
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_003C9C40;
void func_L07_003C9C40(u8 *obj) {
    extern void func_0038CE20(void *, void *, f32);
    extern void func_L07_003C9E88(void *, void *, f32, f32);
    V_003C9C40 start, delta, end;
    u8 *p = *(u8 **)(obj + 0x68);
    f32 t;
    func_003C2F58(obj, p[0x4DC], &start);
    __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0"
            : "=m"(delta) : "m"(*(V_003C9C40 *)(p+0x470)), "m"(start) : "vf1", "vf2");
    if (*(f32 *)(p+0x488) == 1.0f) {
        *(u128_t *)&end = *(u128_t *)(p+0x470);
    } else {
        func_0038CE20(&end, &delta, *(f32 *)(p+0x488));
        __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0"
                : "=m"(end) : "m"(start), "m"(end) : "vf1", "vf2");
    }
    if (obj[0x20] != 0x1A) {
        t = *(s16 *)(p+0x4C6) / 10.0f;
        if (t > 1.0f) t = 1.0f;
        func_L07_003C9E88(&start, &end, t, *(f32 *)(p+0x48C));
    } else {
        func_L07_003C9E88(&start, &end, 1.0f, *(f32 *)(p+0x48C));
    }
}
/* localdecomp:end func_L07_003C9C40 */
