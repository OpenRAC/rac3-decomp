/* functional: high. Rewritten from the asm; vector subtractions (VU0 vsub.xyz, w unused) are scalar; the entity table D_L03_001E24C0 (0x460 per entry) is used through byte offsets like the neighbours. Not byte-matched. */
__asm__(".extern D_L03_001DF0B4, 4");
extern f32 D_L03_001DF0B4;
extern f32 func_0038CEA8(void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D0C8(f32);
void func_L03_003DA148(s32 i, u8 *pt) {
    f32 d[4] __attribute__((aligned(16)));
    u8 *e = (u8 *)&D_L03_001E24C0[i];
    u8 *target = *(u8 **)(e + 0x50);
    u8 *best = e + 0x3F0;
    f32 len;
    f32 zero;
    f32 ang;
    f32 side;
    if (*(s16 *)(target + 0x86) != 0) {
        return;
    }
    side = *(f32 *)(*(u8 **)(e + 0x284) + 0x104);
    if (side < 0.0f) {
        side = -side;
    }
    if (0.05f < side) {
        return;
    }
    d[0] = *(f32 *)(pt + 0x10) - *(f32 *)(e + 0x190);
    d[1] = *(f32 *)(pt + 0x14) - *(f32 *)(e + 0x194);
    d[2] = *(f32 *)(pt + 0x18) - *(f32 *)(e + 0x198);
    len = func_0038CEA8(d);
    zero = 0.0f;
    if (!(len < 22.0f)) {
        return;
    }
    if (!(zero < len)) {
        return;
    }
    if (!(len < *(f32 *)(best + 8))) {
        return;
    }
    if (!(zero < d[2])) {
        return;
    }
    ang = func_0038D0C8(func_0038CE68(target, d) / len);
    if (!(1.5707964f - ang < 1.1170107f)) {
        return;
    }
    d[0] = *(f32 *)(pt + 0x10) - *(f32 *)(target + 0x30);
    d[1] = *(f32 *)(pt + 0x14) - *(f32 *)(target + 0x34);
    d[2] = *(f32 *)(pt + 0x18) - *(f32 *)(target + 0x38);
    len = func_0038CEA8(d);
    if (len == zero) {
        len = 9.9999997e-05f;
    }
    ang = func_0038D0C8(func_0038CE68(target, d) / len);
    if (!(1.5707964f - ang < 0.62831855f)) {
        return;
    }
    *(f32 *)(best + 8) = len;
    *(u8 **)(best + 4) = pt;
    *(u8 **)best = target;
    *(f32 *)(best + 0xC) = *(f32 *)(best + 0xC) + D_L03_001DF0B4;
    if (1.0f < *(f32 *)(best + 0xC)) {
        *(f32 *)(best + 0xC) = 1.0f;
    }
}
