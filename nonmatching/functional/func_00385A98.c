/* functional: high. Rewritten from the PAL assembly (the US draft used 1/60 frame steps; PAL uses 0x3CA3D70B = 0.020000001f). Retail adds the 0x10 position with VU0 vadd.xyz (w kept); written as three FPU adds (same truncating PS2 rounding). Byte diffs: regalloc, frame, $gp vs lui loads. Uses the file context of 385778.c (S_3813E0, P_3813E0, D_001D57xx externs). */
extern s32 func_0038DFB8(s32, s32, f32);
void func_00385A98(void) {
    S_3813E0 *s = &D_001A4BE0;
    f32 scr[4];
    f32 pos[2];
    V4_3813E0 v;
    s32 rgb4[4];
    s32 clr2[4];
    u8 *obj;
    P_3813E0 *info;
    f32 total, part, zoom, size, ang, sc, half;
    long tex, x, y;
    s32 rgba, i;

    if (s->f1430 == 0 && s->f1464 == 0.0f) return;
    if (s->f1430 != (s32)s->f1460) {
        func_003C44F0(&s->f1464, 0.0f, D_001D57D4 * 0.020000001f);
        if (s->f1464 <= 0.0f) s->f1460 = (u8 *)s->f1430;
    } else if (s->f1430 != 0 && s->f1464 < 1.0f) {
        func_003C44F0(&s->f1464, 1.0f, D_001D57D4 * 0.020000001f);
        s->f1468 = ((f32 (*)(f32, f32))func_0038DE98)(s->f1468, D_001D5808 * 0.017453292f * 0.020000001f);
    }
    s->f1468 = ((f32 (*)(f32, f32))func_0038DE98)(s->f1468, D_001D5808 * 0.017453292f * 0.020000001f);
    obj = s->f1460;
    if (obj == 0) return;
    if (s->f1464 == 0.0f) return;
    part = 0.0f;
    total = 0.0f;
    info = func_00382728(obj);
    if (info != 0) {
        func_0038D348((s32)&v, (s32)(obj + 0xE0), info->f10);
        /* retail: lqc2/vadd.xyz/sqc2 (w kept) */
        v.x = v.x + ((V4_3813E0 *)(obj + 0x10))->x;
        v.y = v.y + ((V4_3813E0 *)(obj + 0x10))->y;
        v.z = v.z + ((V4_3813E0 *)(obj + 0x10))->z;
        total = (f32)info->h4;
        part = info->f0;
    } else {
        v = *(V4_3813E0 *)(obj + 0x10);
    }
    zoom = 0.75f;
    func_00386488(scr, &v);
    pos[0] = (scr[0] - (f32)D_001D4BD0_00385A98) * 0.0625f;
    pos[1] = (scr[1] - (f32)D_001D4BD4_00385A98) * 0.0625f;
    if (info != 0) zoom = info->f10;
    if (zoom > 2.0f) zoom = 2.0f;
    size = func_0038D540(func_0038D2E0(D_00222480, obj + 0x10), zoom) * D_001D57C8;
    if (size > D_001D57CC) size = D_001D57CC;
    else if (size < D_001D57D0) size = D_001D57D0;
    for (i = 0; i < 3; i++) {
        if (i == 1) ang = -s->f1468;
        else if (i == 0) ang = s->f1468;
        else ang = D_001D5804 * 0.017453292f;
        tex = func_00389978(i + 0x33);
        rgba = func_0038DFB8((&D_001D57E8)[i], (&D_001D57D8)[i], s->f1464);
        sc = (((&D_001D57F8)[i] - 1.0f) * (1.0f - s->f1464) + 1.0f) * size;
        func_0038C0B8(pos[0], pos[1], sc, sc, ang, 0x40, 0x40, tex, 0xFFFFF3, rgba, 0, 0, 0.0f, 0.0f);
        func_0038C0B8(pos[0], pos[1], sc, sc, ((f32 (*)(f32, f32))func_0038DE98)(ang, 1.5707964f), 0x40, 0x40, tex, 0xFFFFF3, rgba, 0, 0, 0.0f, 0.0f);
        func_0038C0B8(pos[0], pos[1], sc, sc, ((f32 (*)(f32, f32))func_0038DE98)(ang, 3.1415927f), 0x40, 0x40, tex, 0xFFFFF3, rgba, 0, 0, 0.0f, 0.0f);
        func_0038C0B8(pos[0], pos[1], sc, sc, func_0038DEE0(ang, 1.5707964f), 0x40, 0x40, tex, 0xFFFFF3, rgba, 0, 0, 0.0f, 0.0f);
    }
    if (total == 0.0f) return;
    clr2[0] = D_001D5810;
    clr2[1] = D_001D5814;
    clr2[2] = D_001D5818;
    clr2[3] = D_001D581C;
    rgba = func_0038DFB8(D_001D5828 & 0xFFFFFF, D_001D5828, s->f1464);
    rgb4[0] = rgba;
    rgb4[3] = rgba;
    rgb4[2] = rgba;
    rgb4[1] = rgba;
    x = (s32)scr[0];
    y = (s32)scr[1];
    half = D_001D5834 * func_0038D540(D_001D5830, total);
    func_0038C8E0(x, y, (s32)(size * (f32)D_001D5820), (s32)(size * (f32)D_001D5824), rgb4, clr2,
                  D_001D580C, 0x10, half, -half);
    rgba = func_0038DFB8(D_001D582C & 0xFFFFFF, D_001D582C, s->f1464);
    rgb4[0] = rgba;
    rgb4[3] = rgba;
    rgb4[2] = rgba;
    rgb4[1] = rgba;
    func_0038C8E0(x, y, (s32)(size * (f32)D_001D5820), (s32)(size * (f32)D_001D5824), rgb4, clr2,
                  D_001D580C, 0x10, half, half - (half + half) * (part / total));
}
