/* functional: high. Same reads/writes/calls; the unused quad copy retail makes to the stack is omitted. */
extern u8 *D_L19_001DF71C;
extern void func_0038CE20(void *, void *, f32);

void func_L19_003AF080(u8 *e) {
    u8 *p = *(u8 **)(e + 0x68);
    f32 t = (f32)*(s32 *)(p + 4) / (f32)*(s32 *)(p + 8);
    f32 rem = 1.0f - t;
    f32 d[4] __attribute__((aligned(16)));
    f32 s[4] __attribute__((aligned(16)));
    f32 *a = (f32 *)(p + 0x50);
    f32 *b = (f32 *)(p + 0x40);
    s32 i;
    d[0] = a[0] - b[0];
    d[1] = a[1] - b[1];
    d[2] = a[2] - b[2];
    d[3] = a[3];
    func_0038CE20(s, d, rem * (f32)*(s32 *)(p + 0xC));
    for (i = 0; i < *(s32 *)(p + 0xC);) {
        u8 *tgt = D_L19_001DF71C + (*(s32 *)(p + 0x20 + i * 4) << 8);
        Q v = *(Q *)(p + 0x40 + i * 16);
        f32 *vf = (f32 *)&v;
        vf[0] -= s[0];
        vf[1] -= s[1];
        vf[2] -= s[2];
        *(Q *)(tgt + 0x10) = v;
        i++;
        if ((f32)i / (f32)*(s32 *)(p + 0xC) <= rem) {
            *(u16 *)(tgt + 0x34) |= 0x41;
            *(s32 *)(tgt + 0x98) = 0;
        } else {
            *(u16 *)(tgt + 0x34) &= 0xFFBE;
            *(s32 *)(tgt + 0x98) = *(s32 *)(*(u8 **)(tgt + 0x24) + 0x10);
        }
    }
}
