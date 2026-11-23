/* functional: high. Per-tick move of a particle by its velocity (q = obj+0x20), optionally carried by a parent object (kind 1: parent's +0x10 vector is added then removed from the stored offset), freed when it leaves the 2..1021 box or func_0038CB00 says so, else fades its colour word once life (s16 +0xA) is below 250; plain C for the VU0 vadd, same order of reads/writes/calls. */
/* localdecomp:start func_L39_005CDFD8 */
extern s32 func_0038DBD8(s32, s32, f32);

void func_L39_005CDFD8(u8 *p) {
    f32 v[4] __attribute__((aligned(16)));
    f32 g[4] __attribute__((aligned(16)));
    u8 *q = p + 0x20;
    s32 life;

    v[3] = 0.0f;
    v[0] = *(f32 *)(p + 0x20);
    v[1] = *(f32 *)(q + 4);
    v[2] = *(f32 *)(q + 8);
    if (*(s32 *)(q + 0x1C) == 1) {
        u8 *src = *(u8 **)(q + 0xC);

        g[0] = 0.0f;
        g[1] = 0.0f;
        g[2] = 0.0f;
        g[3] = 0.0f;
        if (src != 0) {
            g[0] = *(f32 *)(src + 0x10);
            g[1] = *(f32 *)(src + 0x14);
            g[2] = *(f32 *)(src + 0x18);
            g[3] = *(f32 *)(src + 0x1C);
        }
        *(f32 *)(p + 0x10) = g[0] + *(f32 *)(q + 0x10);
        *(f32 *)(p + 0x14) = g[1] + *(f32 *)(q + 0x14);
        *(f32 *)(p + 0x18) = g[2] + *(f32 *)(q + 0x18);
        *(f32 *)(p + 0x10) = *(f32 *)(p + 0x10) + v[0];
        *(f32 *)(p + 0x14) = *(f32 *)(p + 0x14) + v[1];
        *(f32 *)(p + 0x18) = *(f32 *)(p + 0x18) + v[2];
        *(f32 *)(q + 0x10) = *(f32 *)(p + 0x10) - g[0];
        *(f32 *)(q + 0x14) = *(f32 *)(p + 0x14) - g[1];
        *(f32 *)(q + 0x18) = *(f32 *)(p + 0x18) - g[2];
    } else {
        *(f32 *)(p + 0x10) = *(f32 *)(p + 0x10) + v[0];
        *(f32 *)(p + 0x14) = *(f32 *)(p + 0x14) + v[1];
        *(f32 *)(p + 0x18) = *(f32 *)(p + 0x18) + v[2];
    }
    if (*(f32 *)(p + 0x10) < 2.0f || 1021.0f < *(f32 *)(p + 0x10) ||
        *(f32 *)(p + 0x14) < 2.0f || 1021.0f < *(f32 *)(p + 0x14) ||
        *(f32 *)(p + 0x18) < 2.0f || 1021.0f < *(f32 *)(p + 0x18) ||
        func_0038CB00(p + 0xA) != 0) {
        func_003CD250(p);
        return;
    }
    life = *(s16 *)(p + 0xA);
    if (life < 250) {
        *(s32 *)(p + 4) = func_0038DBD8(*(s32 *)(p + 4) & 0xFFFFFF, *(s32 *)(p + 4), (f32)(life - 1) / (f32)life);
    }
}
/* localdecomp:end func_L39_005CDFD8 */
