/* functional: medium. No earlier draft; the whole function traced from the asm incl. the packet/uv reuse, but only compile-checked. */
typedef struct {
    S_38C110v p[4];
    s32 color[4];
    f32 uv[8];
    long zero, texture, state, mode;
} Packet_00360A48;
typedef struct { u8 first; u8 kind; u8 pad[238]; } Weapon_00360A48;
extern u8 D_001425C0[];
extern Weapon_00360A48 D_L01_002C5600[];
extern S_38C110v D_L01_001E2A40;
extern f32 D_001A4EC0[];
extern f32 D_L01_001DD718, D_L01_001DD71C, D_L01_001DD720, D_L01_001DD724, D_L01_001DD728, D_L01_001DD72C;

void func_L01_00360A48(u8 *m)
{
    extern f32 func_003824E0(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_003D9508(u8 *pos, s32 texture, u32 colour, s32 blend, f32 half, f32 push, f32 roll);
    extern void func_L01_0040AAC8(void *, s32, s32, u32, s32, f32, f32, f32, f32, f32, f32);
    extern f32 func_L01_0040E548(void *, void *);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_003D93B0(void *, s32, s32, s32);
    extern void func_003A9440(s32, s32);
    extern void func_003D2DA0(void *, void *, s32);
    extern void func_00389478(void *, void *, void *);
    u8 *v = *(u8 **)(m + 0x68);
    S_38C110v tmp, dir, side, up, centre, far, prev, cur, scaled;
    Packet_00360A48 packet;
    u32 c20 = 0x7F400505, c18 = 0x7F200505, c21 = 0x35FF0032, c22 = 0x35804020, c23 = 0x357F2020;
    f32 s, t, taper, angle, sa, ca, cx, cy;
    s32 kind, i, k, j;

    D_L01_001DD718 = func_0038DAB8(D_L01_001DD718, func_003824E0(-1.0f, -2.0f) * 0.01745329238474369f);
    D_L01_001DD724 = func_0038DAB8(D_L01_001DD724, func_003824E0(-2.0f, -4.0f) * 0.01745329238474369f);
    D_L01_001DD71C = func_0038DAB8(D_L01_001DD71C, func_003824E0(-1.0f, -3.0f) * 0.01745329238474369f);
    D_L01_001DD728 = func_0038DAB8(D_L01_001DD728, func_003824E0(-3.0f, -5.0f) * 0.01745329238474369f);
    D_L01_001DD720 = func_0038DAB8(D_L01_001DD720, func_003824E0(-1.0f, -3.0f) * 0.01745329238474369f);
    D_L01_001DD72C = func_0038DAB8(D_L01_001DD72C, func_003824E0(-1.0f, -4.0f) * 0.01745329238474369f);
    kind = D_L01_002C5600[D_001425C0[0x77]].kind;
    if (kind == 2) {
        c20 = 0x7F050510; c18 = 0x7F050520; c21 = 0x35104080; c22 = 0x35204080; c23 = 0x354080FF;
    } else if (kind == 3) {
        c20 = 0x7F050540; c18 = 0x7F050520; c21 = 0x3532007F; c22 = 0x35204080; c23 = 0x3520207F;
    }
    s = *(f32 *)(v + 0x18);
    func_003D9508(m + 0x10, 0x49, c20, 0, s * 1.2000000476837158f + s * 1.2000000476837158f, 0.009999999776482582f, D_L01_001DD728);
    func_003D9508(m + 0x10, 0x49, c18, 0, s * 1.100000023841858f + s * 1.100000023841858f, 0.009999999776482582f, -D_L01_001DD72C);
    func_003D9508(m + 0x10, 0x49, c20, 0, s * 0.8999999761581421f + s * 0.8999999761581421f, 0.009999999776482582f, D_L01_001DD724);
    func_003D9508(m + 0x10, 0x49, c18, 0, s + s, 0.009999999776482582f, -D_L01_001DD724);
    func_003D9508(m + 0x10, 0x4A, c20, 0, s * 1.2000000476837158f + s * 1.2000000476837158f, 0.009999999776482582f, -D_L01_001DD728);
    func_003D9508(m + 0x10, 0x4A, c18, 0, s * 1.100000023841858f + s * 1.100000023841858f, 0.009999999776482582f, D_L01_001DD72C);
    func_003D9508(m + 0x10, 0x4A, c20, 0, s * 0.8999999761581421f + s * 0.8999999761581421f, 0.009999999776482582f, -D_L01_001DD724);
    func_003D9508(m + 0x10, 0x4A, c18, 0, s + s, 0.009999999776482582f, D_L01_001DD724);
    func_L01_0040AAC8(m + 0x10, 0x47, 0x48, c21, 0, s * 1.399999976158142f + s * 1.399999976158142f, 1.0f, 1.0f,
                      D_L01_001DD718, -D_L01_001DD724, 0.0f);
    func_L01_0040AAC8(m + 0x10, 0x47, 0x48, c22, 0, s * 1.399999976158142f + s * 1.399999976158142f, 1.0f, 1.0f,
                      -D_L01_001DD71C, D_L01_001DD728, 0.05000000074505806f);
    func_L01_0040AAC8(m + 0x10, 0x47, 0x48, c23, 0, s * 1.399999976158142f + s * 1.399999976158142f, 1.0f, 1.0f,
                      D_L01_001DD720, -D_L01_001DD72C, 0.10000000149011612f);
    if (!(func_L01_0040E548(&D_L01_001E2A40, m + 0x10) > 36.0f)) return;

    t = *(f32 *)(v + 0x34);
    if (1.0f < t) *(f32 *)(v + 0x34) = 1.0f;
    else if (t < 0.0f) *(f32 *)(v + 0x34) = 0.0f;
    taper = (1.0f - func_0038D098(t * 3.1415927410125732f)) * 0.5f * 0.6000000238418579f;
    dir.x = D_L01_001E2A40.x - *(f32 *)(m + 0x10);
    dir.y = D_L01_001E2A40.y - *(f32 *)(m + 0x14);
    dir.z = D_L01_001E2A40.z - *(f32 *)(m + 0x18);
    dir.w = D_L01_001E2A40.w;
    func_0038CF68(&dir, &dir, *(f32 *)(v + 0x34) + 2.0f);
    func_0038CF68(&up, D_001A4EC0, 1.0f);
    func_0038CE90(&up, &dir, &up);
    func_0038CF68(&up, &up, *(f32 *)(v + 0x34) + 2.0f);
    func_0038CE90(&side, &up, &dir);
    func_0038CF68(&side, &side, *(f32 *)(v + 0x34) + 1.0f);
    func_0038CF68(&tmp, &up, -0.5f);
    centre.x = *(f32 *)(m + 0x10) + tmp.x; centre.y = *(f32 *)(m + 0x14) + tmp.y; centre.z = *(f32 *)(m + 0x18) + tmp.z;
    centre.w = *(f32 *)(m + 0x1C);
    far.x = centre.x + dir.x; far.y = centre.y + dir.y; far.z = centre.z + dir.z; far.w = centre.w;
    func_0038CE20(&tmp, &dir, 0.5f); /* result unused by retail */
    centre.x += dir.x; centre.y += dir.y; centre.z += dir.z;
    *(f32 *)(v + 0x30) = func_0038DAB8(*(f32 *)(v + 0x30), 0.05585053935647011f);
    angle = *(f32 *)(v + 0x30);
    for (i = 0; i < 0x21; i++) {
        cur = centre;
        sa = func_0038D098(angle);
        ca = func_0038D0B0(angle);
        if (sa != 0.0f) {
            func_0038CE20(&scaled, &up, sa);
            cur.x += scaled.x; cur.y += scaled.y; cur.z += scaled.z;
        }
        if (ca != 0.0f) {
            func_0038CE20(&scaled, &side, ca);
            cur.x += scaled.x; cur.y += scaled.y; cur.z += scaled.z;
        }
        if (i != 0) {
            func_003D93B0(&packet, 0x4D, 1, 0x80);
            packet.mode = (0x8000L << 24) | 0x4A;
            packet.p[0] = prev;
            packet.p[1] = cur;
            packet.p[2] = far;
            packet.p[3] = far;
            packet.color[3] = 0x80808080;
            packet.color[2] = 0x80808080;
            packet.color[1] = 0x80808080;
            packet.color[0] = 0x80808080;
            packet.uv[0] = 0.0f; packet.uv[1] = 0.0f; packet.uv[2] = 1.0f; packet.uv[3] = 0.0f;
            packet.uv[4] = 0.0f; packet.uv[5] = 1.0f; packet.uv[6] = 1.0f; packet.uv[7] = 1.0f;
            func_003A9440(0x47, 0x31001);
            func_003D2DA0(&packet, 0, 0);
            for (k = 0; k < 4; k++) func_00389478(&packet.p[k], &packet.uv[2 * k], &packet.uv[2 * k + 1]);
            cx = (packet.uv[0] + packet.uv[2]) * 0.5f;
            cy = (packet.uv[1] + packet.uv[3]) * 0.5f;
            for (j = 0; j < 2; j++) {
                packet.uv[4 + 2 * j] += (cx - packet.uv[4 + 2 * j]) * taper;
                packet.uv[5 + 2 * j] += (cy - packet.uv[5 + 2 * j]) * taper;
            }
            func_003D93B0(&packet, -1, 1, 0x80);
            packet.zero = 5;
            packet.mode = (0x8000L << 24) | 0x54;
            func_003A9440(0x47, 0x53001);
            func_003D2DA0(&packet, 0, 0);
            func_003A9440(0x47, 0x5360B);
        }
        prev = cur;
        angle = func_0038DAB8(angle, 0.19634954631328583f);
    }
}
