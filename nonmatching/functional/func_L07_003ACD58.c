/* functional: high. Same ops as retail under ps2as (72 diff, scheduling/allocation only); VU0 inline asm for the delta. */
typedef int TI_003ACD58 __attribute__((mode(TI)));
extern s32 D_L07_001DEF40 __attribute__((section(".data")));
void func_L07_003ACD58(u8 *obj, f32 dt) {
    extern void func_L03_0032FAF0(void *, void *, f32, f32);
    extern void func_L07_00333DB8(void *, void *, s32, s32, f32);
    extern f32 func_0038DB00(f32, f32);
    extern f32 func_L07_00332CF0(void *, void *, void *, f32);
    extern void func_L01_0045A7A8(void *, void *, f32);
    extern f32 func_0038CE68(void *, void *);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_L01_0040E570(void *, void *);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038DBA0(f32, f32);
    extern void func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);
    f32 vec[4] __attribute__((aligned(16)));
    f32 old[4] __attribute__((aligned(16)));
    f32 delta[4] __attribute__((aligned(16)));
    u8 *s = *(u8 **)(obj + 0x68);
    u8 *pos;
    f32 angle;
    f32 other;
    func_L03_0032FAF0(vec, s + 0x130, *(f32 *)(s + 0x254), dt);
    if ((((s32)obj >> 8) & 7) == (D_L07_001DEF40 & 7)) {
        func_L07_00333DB8(*(void **)(s + 0x240), obj, 0, 0, dt);
        *(f32 *)(s + 0x258) = func_L07_00332CF0(*(void **)(s + 0x240), obj, vec, func_0038DB00(*(f32 *)(s + 0x250), *(f32 *)(s + 0x254)) * 0.25f);
    }
    *(TI_003ACD58 *)old = *(TI_003ACD58 *)(obj + 0x10);
    pos = obj + 0x10;
    func_L01_0045A7A8(obj, vec, *(f32 *)(s + 0x258));
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(*(TI_003ACD58 *)delta)
            : "m"(*(TI_003ACD58 *)old), "m"(*(TI_003ACD58 *)(obj + 0x10))
            : "vf1", "vf2");
    *(f32 *)(s + 0x56C) = func_0038DAB8(*(f32 *)(s + 0x56C), func_0038CE68(delta, obj + 0xC0) / 0.3f);
    if ((*(s32 *)(s + 0x188) & 0x10) && func_L01_0040E570(old, pos) > 0.0001f) {
        angle = func_0038D160(*(f32 *)(obj + 0x10) - old[0], *(f32 *)(obj + 0x14) - old[1]);
        other = func_0038D160(*(f32 *)(s + 0x130) - *(f32 *)(obj + 0x10), *(f32 *)(s + 0x134) - *(f32 *)(obj + 0x14));
        if (func_0038DBA0(other, angle) > 1.57079637f) {
            angle = func_0038DAB8(angle, 3.14159274f);
        }
        func_L01_00448890(obj + 0xF8, s + 0x204, 0, angle, *(f32 *)(s + 0x164), *(f32 *)(s + 0x168), *(f32 *)(s + 0x16C));
    }
}
