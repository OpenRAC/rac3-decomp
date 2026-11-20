/* functional: medium. Moves a moby along an arc/ping-pong between waypoint records (modes 0 and 1), snaps to waypoints (modes 2/3), then orients it; the w lane of the mode 0 interpolated positions is the end waypoint's w (retail's vsub.xyz/vmulx.xyz/vadd.xyz keep it), and a zero period would trap on host where retail's div does not. */
extern Rec *D_L19_001DF800_003AC268;
extern s32 D_L19_001DF240;
extern Q D_L19_001E8E60[];
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_L01_0040E570(void *, void *);
extern f32 func_0038D160(f32, f32);
extern s32 func_L01_004561B8(void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);

void func_L19_003AE108(void *obj) {
    u8 *o = obj;
    u8 *p = *(u8 **)(o + 0x68);
    s32 mode = *(s32 *)p;
    s32 per = *(s32 *)(p + 4);
    f32 t = (f32)((D_L19_001DF240 + *(s32 *)(p + 0x1C)) % per) / (f32)per;
    f32 *op = (f32 *)(o + 0x10);
    f32 *tp = (f32 *)(p + 0x40);
    Rec *r = D_L19_001DF800_003AC268;
    s32 dir = 0;

    if (mode == 0) {
        f32 a = (t - 0.5f);
        a = (a + a) * 3.14159274f;
        t = func_0038D098(a) * 0.5f + 0.5f;
        if (!(p[0x18] & 1)) {
            f32 *a0 = (f32 *)&r[*(s32 *)(p + 0x20)].pos;
            f32 *b0 = (f32 *)&r[*(s32 *)(p + 0x24)].pos;
            op[0] = a0[0] + (b0[0] - a0[0]) * t;
            op[1] = a0[1] + (b0[1] - a0[1]) * t;
            op[2] = a0[2] + (b0[2] - a0[2]) * t;
            op[3] = b0[3];
        }
        if (!(*(s32 *)(p + 0x18) & 2)) {
            f32 *a0 = (f32 *)&r[*(s32 *)(p + 0x28)].pos;
            f32 *b0 = (f32 *)&r[*(s32 *)(p + 0x2C)].pos;
            tp[0] = a0[0] + (b0[0] - a0[0]) * t;
            tp[1] = a0[1] + (b0[1] - a0[1]) * t;
            tp[2] = a0[2] + (b0[2] - a0[2]) * t;
            tp[3] = b0[3];
        }
        if (!(p[0x18] & 1)) dir = 1;
    } else if (mode == 1) {
        f32 a = (t + t) - 1.0f;
        f32 s, c;
        Q c0, c1, c2;
        f32 *q0 = (f32 *)&c0, *q1 = (f32 *)&c1, *q2 = (f32 *)&c2;
        a *= 3.14159274f;
        s = func_0038D098(a);
        c = func_0038D0B0(a);
        c0 = r[*(s32 *)(p + 0x10)].pos;
        c1 = r[*(s32 *)(p + 0x20)].pos;
        c2 = r[*(s32 *)(p + 0x28)].pos;
        if (!(p[0x18] & 1)) {
            f32 dx = q1[0] - q0[0];
            f32 dy = q1[1] - q0[1];
            op[1] = q0[1] + (dy * s + dx * c);
            op[0] = q0[0] + (dx * s - dy * c);
        }
        if (!(*(s32 *)(p + 0x18) & 2)) {
            f32 dx = q2[0] - q0[0];
            f32 dy = q2[1] - q0[1];
            tp[0] = q0[0] + (dx * s - dy * c);
            tp[1] = q0[1] + (dy * s + dx * c);
        }
    } else if ((u32)(mode - 2) < 2) {
        if (func_L01_004561B8(o)) {
            *(Q *)(o + 0x10) = r[*(s32 *)(p + 0x20)].pos;
            *(Q *)(p + 0x40) = r[*(s32 *)(p + 0x28)].pos;
            if (!(p[0x18] & 1)) dir = 1;
        }
    }

    if (dir) {
        f32 v[4] __attribute__((aligned(16)));
        v[0] = op[0] - (tp[0] - op[0]);
        v[1] = op[1] - (tp[1] - op[1]);
        v[2] = op[2] - (tp[2] - op[2]);
        v[3] = op[3];
        if (func_003D3CB0(op, v, 2, o, 0)) {
            *(Q *)(o + 0x10) = D_L19_001E8E60[0];
        }
    }

    if (!(*(s32 *)(p + 0x18) & 4)) {
        f32 dist, dx, dy;
        *(f32 *)(o + 0xF0) = -3.14159274f;
        dist = func_0038CF38(op, tp);
        *(f32 *)(o + 0xF4) = -func_0038D160(dist, *(f32 *)(p + 0x48) - *(f32 *)(o + 0x18));
        if (0.0f < func_L01_0040E570(&r[*(s32 *)(p + 0x24)].pos, &r[*(s32 *)(p + 0x20)].pos)) {
            f32 *ra = (f32 *)&D_L19_001DF800_003AC268[*(s32 *)(p + 0x20)].pos;
            f32 *rb = (f32 *)&D_L19_001DF800_003AC268[*(s32 *)(p + 0x24)].pos;
            dx = ra[0] - rb[0];
            dy = ra[1] - rb[1];
        } else {
            dx = tp[0] - op[0];
            dy = tp[1] - op[1];
        }
        *(f32 *)(o + 0xF8) = func_0038D160(dx, dy);
    }
}
