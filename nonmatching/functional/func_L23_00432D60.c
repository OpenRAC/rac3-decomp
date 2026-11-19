/* functional: medium. Same reads/calls/return as retail; control flow restructured with continue. */
extern u8 *D_L23_0021C520[];
extern u8 D_001A4BE0[];
extern u8 D_L23_001E19C0[];
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CED8(void *);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038D0C8(f32);
extern u8 *func_00382348(u8 *);
extern void func_00382760(void *, f32, f32, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);

u8 *func_L23_00432D60(u8 *a0, f32 *a1, f32 *a2, f32 *yaw_out, f32 *pitch_out, f32 *height_out, f32 max_ang,
                      f32 best) {
    f32 v0[4];
    f32 v1[4];
    f32 q[4];
    f32 t[4];
    u8 *result;
    u8 **mp;
    u8 *m;
    u8 *o;
    u8 *p;
    f32 yaw;
    f32 pitch;
    f32 dist;
    f32 ang;
    f32 lim;
    f32 d;

    v0[0] = a1[0];
    v0[1] = a1[1];
    v0[2] = a1[2];
    v0[3] = a1[3];
    v1[0] = a2[0];
    v1[1] = a2[1];
    v1[2] = a2[2];
    v1[3] = a2[3];
    result = 0;
    *yaw_out = func_0038D160(v1[0], v1[1]);
    *pitch_out = -func_0038D160(func_0038CED8(v1), v1[2]);

    for (mp = D_L23_0021C520; (m = *mp) != 0; mp++) {
        if (m[0x20] < 0) {
            continue;
        }
        q[0] = *(f32 *)(m + 0x10);
        q[1] = *(f32 *)(m + 0x14);
        q[2] = *(f32 *)(m + 0x18);
        q[3] = *(f32 *)(m + 0x1C);
        o = func_00382348(m);
        if (o != 0) {
            q[2] = q[2] + *(f32 *)(o + 0x10);
        } else {
            q[2] = q[2] + 0.5f;
        }
        p = *(u8 **)(m + 0x24);
        if (p == 0 || p[0x46] != 5) {
            continue;
        }
        yaw = func_0038D160(q[0] - v0[0], q[1] - v0[1]);
        pitch = func_0038D160(func_0038CF38(v0, q), q[2] - v0[2]);
        dist = func_0038CF00(v0, q);
        if (dist < 7.5f) {
            ang = func_0038DBA0(*(f32 *)(a0 + 0xF8),
                                func_0038D160(*(f32 *)(m + 0x10) - *(f32 *)(a0 + 0x10),
                                              *(f32 *)(m + 0x14) - *(f32 *)(a0 + 0x14)));
            if (ang < 1.0472f && ((pitch < 0.0f ? -pitch : pitch) < 1.0472f)) {
                *pitch_out = -pitch;
                *yaw_out = yaw;
                return m;
            }
        }
        if (best < dist) {
            continue;
        }
        func_00382760(t, dist, *yaw_out, *pitch_out + *(f32 *)(D_001A4BE0 + 0x344) * 0.5f);
        t[0] = t[0] + v0[0];
        t[1] = t[1] + v0[1];
        t[2] = t[2] + v0[2];
        ang = func_0038D0C8(func_0038CF00(t, q) / (dist + dist));
        ang = ang + ang;
        if (max_ang < ang && o != 0) {
            lim = (f32)((s32)o[0xA] << 3) * 0.125f;
            d = func_0038D0C8(lim / dist);
            if (lim < dist) {
                ang = ang - d;
            }
        }
        if (ang < max_ang) {
            if (func_003D3CB0(D_L23_001E19C0, q, 6, a0, 0) == 0) {
                *pitch_out = -pitch;
                result = m;
                best = dist;
                *yaw_out = yaw;
                if (o != 0) {
                    *height_out = *(f32 *)(o + 0x10);
                } else {
                    *height_out = 0.5f;
                }
            }
        }
    }
    return result;
}
