/* PAL port (2026-11-20) of the NTSC-U draft of func_L05_003C8498 (Codex worker, 2026-11-14), with PAL names, PAL's
 * 50 Hz timer `((s32)len * 5 + 2) / 6` and the VU0 sums as j-form statements, so that the two branches share retail's
 * `vadd`/`sqc2` tail.
 * Needs `-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as` on L05_003CA628.c's line (only
 * INCLUDE_ASM functions there) and a divs_nops.txt row `func_L05_003CA628 2 2`; with both, check.py counts 168
 * differences, 31 after aligning the listings. What differs: gcse keeps `&c.dest` (sp+0x10) in a saved register from
 * the `else` branch's call to the collision call (and adds it to the `then` branch), where retail recomputes it at each
 * use. So ours saves $s5 and has a 0xA0 frame, not 0x90. Passing another address to the first call
 * removes the difference (10 left), so retail's two expressions are not the same RTL; `(void *)` casts, a byte
 * offset from `&c` and a one-element array did not change it. `old` must stay in the struct, or its dead copy is
 * deleted.
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L05_003CA628 */
typedef int u128_003CA628 __attribute__((mode(TI)));

extern s32 func_L01_004561B8(void *);
extern s32 func_0038CAD0(void *);
extern void func_003C2880(void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CF00(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_L01_004CB320(void);
extern void func_L01_004CB358(void);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern void func_L05_003CB090(void *);
extern void func_L05_003CAE70(void *);
extern void func_L01_00404A10(void *, void *);
extern void func_L05_003CA8F0(void *);
extern u8 D_L05_001D66B0[];
extern u8 *D_L05_001EA6D8[];
extern u128_003CA628 D_L05_001EA6E0[];

void func_L05_003CA628(u8 *obj) {
    struct {
        u128_003CA628 old;
        u128_003CA628 dest;
        u128_003CA628 work[3];
    } c;
    u8 *sub;
    u8 *hit;
    s32 result;
    f32 len;
    vu0_q qa;
    vu0_q qb;
    vu0_q qr;

    c.old = *(u128_003CA628 *)(obj + 0x10);
    sub = *(u8 **)(obj + 0x68);
    if (obj[0x20] == 0) {
        if (func_L01_004561B8(obj) == 0) {
            vec_add_ab(obj + 0x10, obj + 0x10, sub);
        }
        if (func_0038CAD0(sub + 0x24)) {
            func_003C2880(obj);
            return;
        }
        if (*(s32 *)(sub + 0x30) == 0) {
            if (func_0038CEA8(sub) > *(f32 *)(sub + 0x20)) {
                __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)sub));
                __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)(obj + 0x10)));
            } else {
                func_0038CF68(&c.dest, sub, *(f32 *)(sub + 0x20));
                __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(c.dest));
                __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)(obj + 0x10)));
            }
            __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
            __asm__("sqc2 %1, %0" : "=m"(c.dest) : "j"(qr));
            func_L01_00446760(c.work, obj, 0x10001, D_L05_001D66B0, *(f32 *)(sub + 0x34));
            func_L01_004CB320();
            result = func_003D3CB0(obj + 0x10, &c.dest, 16, obj, c.work);
            if (result && (hit = D_L05_001EA6D8[0]) && *(s16 *)(hit + 0xAA) == 0x186D && hit[0x20] != 2 && hit[0x20] != 5) {
                hit[0x20] = 4;
            }
            func_L01_004CB358();
            if (result) {
                *(s32 *)(sub + 0x30) = 1;
                *(u128_003CA628 *)(sub + 0x10) = D_L05_001EA6E0[0];
                len = func_0038CF00(obj + 0x10, sub + 0x10);
                len = len / func_0038CEA8(sub);
                *(s32 *)(sub + 0x24) = ((s32)len * 5 + 2) / 6;
                *(f32 *)(sub + 0x28) = 1.0f / (f32)*(s32 *)(sub + 0x24);
                if (*(u8 **)((u8 *)D_L05_001EA6E0 - 8) == 0) {
                    func_L05_003CB090(obj);
                } else {
                    func_L05_003CAE70(sub + 0x10);
                }
            }
        }
        func_L01_00404A10(func_L05_003CA8F0, obj);
    }
    if (*(f32 *)(obj + 0x10) < 2.0f || *(f32 *)(obj + 0x10) > 1021.0f ||
        *(f32 *)(obj + 0x14) < 2.0f || *(f32 *)(obj + 0x14) > 1021.0f ||
        *(f32 *)(obj + 0x18) < 2.0f || *(f32 *)(obj + 0x18) > 1021.0f) {
        func_003C2880(obj);
    }
}
/* localdecomp:end func_L05_003CA628 */
