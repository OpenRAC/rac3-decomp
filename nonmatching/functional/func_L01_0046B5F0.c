/* functional: high. Hand-translated from PAL asm into plain float C (vu0 vadd.xyz and the w-preserving store done per component); no known behavioural difference. */
extern void func_L01_004CAB30(void *, void *);
void func_L01_0046B5F0(f32 *f) {
    u8 *p = (u8 *)f;
    s32 total = *(s16 *)(p + 0x28);
    s32 life = *(s16 *)(p + 0xA);
    s32 d = total - life;
    s32 packed;
    f32 fd;
    f32 a;
    f32 b;
    u32 c;
    p[8] += p[0x2A];
    c = p[0x2B];
    if (d < 6) {
        fd = (f32)d / 5.0f;
        a = f[0x24 / 4];
        f[0xC / 4] = a + ((f[0x20 / 4] + a) * 0.5f - a) * fd;
        packed = (s32)((f32)c + (f32)((s32)(c >> 1) - (s32)c) * fd);
    } else {
        fd = (f32)life / (f32)(total - 6);
        a = f[0x20 / 4];
        f[0xC / 4] = a + ((a + f[0x24 / 4]) * 0.5f - a) * fd;
        packed = (s32)((f32)(c >> 1) * fd + 0.0f);
    }
    *(u32 *)(p + 4) = ((u32)packed << 24) | (*(u32 *)(p + 4) & 0xFFFFFF);
    {
        f32 vx = f[0x2C / 4], vy = f[0x30 / 4], vz = f[0x34 / 4];
        f[0x10 / 4] += vx;
        f[0x14 / 4] += vy;
        f[0x18 / 4] += vz;
    }
    f[0x34 / 4] -= f[0x38 / 4];
    if (f[0x1C / 4] != 0.0f) {
        if (f[0x1C / 4] == 2.0f) {
            func_L01_004CAB30(p + 0x10, p + 0x10);
        }
        f[0x1C / 4] = 2.0f;
    }
    if (f[0x10 / 4] < 2.0f || f[0x10 / 4] > 1021.0f || f[0x14 / 4] < 2.0f || f[0x14 / 4] > 1021.0f ||
        f[0x18 / 4] < 2.0f || f[0x18 / 4] > 1021.0f) {
        func_003CD250((Obj *)p);
    } else if (func_0038CB00((s16 *)(p + 0xA))) {
        func_003CD250((Obj *)p);
    }
}
