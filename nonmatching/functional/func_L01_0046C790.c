/* functional: medium. Written from PAL asm; a.w of the stack quad (written by func_003C2F58) is copied to p+0x1C as retail does. */
extern u8 *D_L01_0022118C[];
extern u8 D_L01_001E29C0[];
extern void func_0038CF68(void *, void *, f32);
void func_L01_0046C790(u8 *p) {
    u8 *v;
    f32 f, k, thr, fade;
    f32 *vf;
    vu0_v4 a, b;
    if (p == 0) {
        return;
    }
    v = p + 0x20;
    vf = (f32 *)v;
    if (func_0038CB00((s16 *)(p + 0xA)) || *(s32 *)(p + 0x20) == 0 || *(s8 *)(*(u8 **)(p + 0x20) + 0x20) < 0) {
        func_003CD250((Obj *)p);
        return;
    }
    *(u16 *)(v + 0xC) = (*(u16 *)(v + 0xC) + 1) & 0xF;
    k = 159600.0f;
    f = *(f32 *)(p + 0xC);
    if (f < k) {
        f = f + 4788.0f;
        *(f32 *)(p + 0xC) = f;
        if (k < f) {
            *(f32 *)(p + 0xC) = k;
        }
    } else if (k < f) {
        f = f - 19152.0f;
        *(f32 *)(p + 0xC) = f;
        if (f < k) {
            *(f32 *)(p + 0xC) = k;
        }
    }
    vf[2] = vf[2] + 0.0012f;
    p[8] = (s32)(vf[2] * 255.0f);
    p[2] = D_L01_0022118C[0][*(s16 *)(v + 0xC)];
    if (*(f32 *)(p + 0xC) <= k || vf[4] > 0.0f) {
        vf[1] = vf[1] + vf[4];
    }
    thr = (*(f32 *)(p + 0xC) <= k) ? 0.3f : 0.15f;
    if (thr < vf[1]) {
        f32 n = -vf[4];
        vf[1] = vf[1] + n;
        vf[4] = n;
    } else if (vf[1] < 0.0f) {
        func_003CD250((Obj *)p);
        return;
    }
    *(u32 *)(p + 4) = (*(u32 *)(p + 4) & 0xFFFFFF) + ((u32)(s32)(vf[1] * 256.0f) << 24);
    fade = vf[5];
    vf[5] = fade + (1.0f - fade) * 0.21f;
    func_003C2F58(*(u8 **)v, *(s16 *)(v + 0xE), &a);
    b = *(vu0_v4 *)D_L01_001E29C0;
    b.x = b.x - a.x;
    b.y = b.y - a.y;
    b.z = b.z - a.z;
    func_0038CF68(&b, &b, vf[5]);
    *(vu0_v4 *)(p + 0x10) = a;
    ((f32 *)(p + 0x10))[0] = a.x + b.x;
    ((f32 *)(p + 0x10))[1] = a.y + b.y;
    ((f32 *)(p + 0x10))[2] = a.z + b.z;
}
