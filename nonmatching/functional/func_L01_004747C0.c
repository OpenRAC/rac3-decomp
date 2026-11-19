/* functional: high. Needs the __asm__(.extern D_L01_001D7F88, 4) line for gp-relative addressing. */
/* localdecomp:start func_L01_004747C0 */
#include "vu0.h"
extern f32 D_L01_001D7F88;
__asm__(".extern D_L01_001D7F88, 4");
void func_L01_004747C0(u8 *p) {
    extern s32 func_0038CB00(void *);
    extern void func_003CD250(u8 *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_004CAB30(void *, void *);
    vu0_v4 delta;
    u8 *s = p + 0x30;
    u8 *pos;
    u8 *tail;
    f32 t, blend;
    s32 alpha;
    if (func_0038CB00(p + 0xA)) { func_003CD250(p); return; }
    t = (f32)*(s16 *)(p + 0xA) / (f32)*(s16 *)(s + 0xC);
    blend = *(f32 *)(s + 8) + (1.0f - *(f32 *)(s + 8)) * t;
    pos = p + 0x10;
    *(f32 *)(p + 0x1C) = *(f32 *)(s + 4) * blend;
    *(f32 *)s -= 0.014f;
    tail = p + 0x20;
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(delta) : "m"(*(vu0_v4 *)pos), "m"(*(vu0_v4 *)tail) : "vf1", "vf2");
    delta.w = 0;
    func_0038CF68(&delta, &delta, *(f32 *)s);
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %0\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "+m"(*(vu0_v4 *)pos) : "m"(delta) : "vf1", "vf2");
    func_0038CF68(&delta, &delta, *(f32 *)s * D_L01_001D7F88);
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %0\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "+m"(*(vu0_v4 *)tail) : "m"(delta) : "vf1", "vf2");
    func_L01_004CAB30(pos, pos);
    func_L01_004CAB30(tail, tail);
    if (*(s16 *)(p + 0xA) < p[8]) {
        alpha = (s32)((f32)*(s16 *)(p + 0xA) / (f32)p[8] * 127.0f);
        *(u32 *)(p + 4) = (alpha << 24) | (*(u32 *)(p + 4) & 0xFFFFFF);
        *(u32 *)(p + 0xC) = (alpha << 24) | (*(u32 *)(p + 0xC) & 0xFFFFFF);
    }
}
/* localdecomp:end func_L01_004747C0 */
