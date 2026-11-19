/* functional: high. Same control flow as retail (206 words differ only in scheduling/branch-delay layout); obfuscated slot check, case-2/1/5 pulse colours and the func_L01_00470150 sprite call transcribed with exact float constants. Arg order of func_0038DBD8 (colours then t) per existing callers. */
extern u8 D_L39_004997E0[];
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern s32 func_L01_00470150(void *, void *, s32, s32, s32, f32, f32, s32, s32, s32, f32, s32, s32);

void func_L39_00643B98(u8 *s) {
    u8 *o;
    u32 buf[2];
    s32 chk;
    s32 w470;
    s32 a;
    f32 vec[4];
    s32 c, c2, mask;
    f32 t;

    if (*(s32 *)(s + 0x450) == 0)
        return;
    chk = 0;
    if (s[0x19E4] != 0) {
        u8 *p = s + 0x19E4;
        u8 *b;
        s32 i, n, m, k;
        n = *p;
        m = n + 1;
        k = ((s32)p - n) & 7;
        b = (u8 *)buf;
        for (i = 0; i < 40; i += 5) {
            *b++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
        }
        buf[0] ^= (u32)p;
        buf[1] ^= buf[0];
        chk = buf[1];
    }
    if (chk == 0x63)
        return;
    o = *(u8 **)(s + 0x450);
    if (o[0x34] & 1)
        return;
    w470 = *(s32 *)(s + 0x470);
    if (w470 < 0x13)
        return;
    a = w470 - 12;
    if (a > 0x40)
        a = 0x40;
    if (a < 0)
        a = 0;
    a = (a << 24) | 0xFFFFFF;
    switch (*(s32 *)(s + 0x478)) {
    case 2:
        *(f32 *)(s + 0x47C) = func_0038DAB8(*(f32 *)(s + 0x47C), 0.06981317698955536f);
        t = func_0038D0B0(*(f32 *)(s + 0x47C)) * 0.5f + 0.5f;
        *(s32 *)(o + 0x78) = func_0038DBD8(0xFFDFDFDF, 0xFF20205F, t);
        break;
    case 1:
        vec[0] = 0.19499999284744263f;
        vec[1] = -0.31700000166893005f;
        vec[2] = 0.0f;
        vec[3] = 0.0f;
        if (s[0x1A07] != 0) {
            *(f32 *)(s + 0x47C) = func_0038DAB8(*(f32 *)(s + 0x47C), 0.13962635397911072f);
            t = func_0038D0B0(*(f32 *)(s + 0x47C)) * 0.5f + 0.5f;
            c = func_0038DBD8(0xFF0040FF, 0xFF10BEBE, t);
            c2 = func_0038DBD8(*(s32 *)(o + 0x78), c, 0.2639999985694885f);
            mask = 0x32FFFFFF;
        } else {
            *(f32 *)(s + 0x47C) = func_0038DAB8(*(f32 *)(s + 0x47C), 0.04886922240257263f);
            t = func_0038D0B0(*(f32 *)(s + 0x47C)) * 0.5f + 0.5f;
            c = func_0038DBD8(0xFF0028C8, 0xFF10B4B4, t);
            c2 = func_0038DBD8(*(s32 *)(o + 0x78), c, 0.18000000715255737f);
            mask = 0x38FFFFFF;
        }
        *(s32 *)(o + 0x78) = c2;
        if (a < mask)
            mask = a;
        func_L01_00470150(vec, o, c2 & mask, -1, 1, 50400.0f, 0.15000000596046448f, 2, 0, -1, 1.0f, 0, 0);
        break;
    case 5:
        *(f32 *)(s + 0x47C) = func_0038DAB8(*(f32 *)(s + 0x47C), 0.06283185631036758f);
        t = func_0038D0B0(*(f32 *)(s + 0x47C)) * 0.5f + 0.5f;
        c = func_0038DBD8(0xFF00FFFF, 0xFF104080, t);
        *(s32 *)(o + 0x78) = c;
        vec[0] = 0.3330000042915344f;
        vec[1] = -0.05000000074505806f;
        vec[2] = 0.0f;
        vec[3] = 0.0f;
        func_L01_00470150(vec, o, c & 0x35FFFFFF, -1, 1, 73500.0f, 0.15000000596046448f, 2, 0, -1, 1.0f, 0, 0);
        break;
    }
}
