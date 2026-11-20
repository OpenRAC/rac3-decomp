/* functional: medium. Moves a moby along an arc/ping-pong between waypoint records (modes 0 and 1), snaps to waypoints (modes 2/3), then orients it. Written as retail's vector-library shape (VU0 .xyz subtract, func_0038CE20 scale, .xyz add, four quadword locals at sp+0..0x30) so the frame is retail's 0x70: callees given a pointer into it see the same stack. The w lanes follow retail's .xyz ops; a zero period would trap on host where retail's div does not. */
extern Rec *D_L19_001DF800_003AC268;
extern s32 D_L19_001DF240;
extern Q D_L19_001E8E60[];
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_L01_0040E570(void *, void *);
extern f32 func_0038D160(f32, f32);
extern s32 func_L01_004561B8(void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);

/* d.xyz = a - b, d.w = a.w (lqc2, vsub.xyz, sqc2 as retail) */
static __inline__ void sub_3AE108(void *d, void *a, void *b) {
    __asm__(
        "lqc2 vf1,%1\n"
        "lqc2 vf2,%2\n"
        "vsub.xyz vf1,vf1,vf2\n"
        "sqc2 vf1,%0"
        : "=m"(*(vu0_v4 *)d)
        : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b)
        : "vf1", "vf2");
}
/* d.xyz = a + b, d.w = a.w */
static __inline__ void add_3AE108(void *d, void *a, void *b) {
    __asm__(
        "lqc2 vf2,%1\n"
        "lqc2 vf1,%2\n"
        "vadd.xyz vf2,vf2,vf1\n"
        "sqc2 vf2,%0"
        : "=m"(*(vu0_v4 *)d)
        : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b)
        : "vf1", "vf2");
}

void func_L19_003AE108(void *obj) {
    u8 *o = obj;
    u8 *p = *(u8 **)(o + 0x68);
    vu0_v4 v0, v1, v2, v3;
    s32 mode;
    f32 t, a, s, c;

    mode = *(s32 *)p;
    t = (f32)((D_L19_001DF240 + *(s32 *)(p + 0x1C)) % *(s32 *)(p + 4)) / (f32)*(s32 *)(p + 4);
    if (mode == 0) {
        a = t - 0.5f;
        a = (a + a) * 3.14159274f;
        t = func_0038D098(a) * 0.5f + 0.5f;
        if (!(p[0x18] & 1)) {
            sub_3AE108(&v0, &D_L19_001DF800_003AC268[*(s32 *)(p + 0x24)].pos, &D_L19_001DF800_003AC268[*(s32 *)(p + 0x20)].pos);
            func_0038CE20(&v0, &v0, t);
            add_3AE108(o + 0x10, &v0, &D_L19_001DF800_003AC268[*(s32 *)(p + 0x20)].pos);
        }
        if (!(*(s32 *)(p + 0x18) & 2)) {
            sub_3AE108(&v0, &D_L19_001DF800_003AC268[*(s32 *)(p + 0x2C)].pos, &D_L19_001DF800_003AC268[*(s32 *)(p + 0x28)].pos);
            func_0038CE20(&v0, &v0, t);
            add_3AE108(p + 0x40, &v0, &D_L19_001DF800_003AC268[*(s32 *)(p + 0x28)].pos);
        }
        if (!(p[0x18] & 1)) {
            goto collide;
        }
    } else if (mode == 1) {
        a = (t + t) - 1.0f;
        a = a * 3.14159274f;
        s = func_0038D098(a);
        c = func_0038D0B0(a);
        *(Q *)&v0 = D_L19_001DF800_003AC268[*(s32 *)(p + 0x10)].pos;
        *(Q *)&v1 = D_L19_001DF800_003AC268[*(s32 *)(p + 0x20)].pos;
        *(Q *)&v2 = D_L19_001DF800_003AC268[*(s32 *)(p + 0x28)].pos;
        if (!(p[0x18] & 1)) {
            sub_3AE108(&v3, &v1, &v0);
            *(f32 *)(o + 0x14) = v0.y + (v3.y * s + v3.x * c);
            *(f32 *)(o + 0x10) = v0.x + (v3.x * s - v3.y * c);
        }
        if (!(*(s32 *)(p + 0x18) & 2)) {
            sub_3AE108(&v3, &v2, &v0);
            *(f32 *)(p + 0x40) = v0.x + (v3.x * s - v3.y * c);
            *(f32 *)(p + 0x44) = v0.y + (v3.y * s + v3.x * c);
        }
    } else if ((u32)(mode - 2) < 2) {
        if (func_L01_004561B8(o)) {
            *(Q *)(o + 0x10) = D_L19_001DF800_003AC268[*(s32 *)(p + 0x20)].pos;
            *(Q *)(p + 0x40) = D_L19_001DF800_003AC268[*(s32 *)(p + 0x28)].pos;
            if (!(p[0x18] & 1)) {
            collide:
                sub_3AE108(&v0, p + 0x40, o + 0x10);
                sub_3AE108(&v0, o + 0x10, &v0);
                if (func_003D3CB0(o + 0x10, &v0, 2, o, 0)) {
                    *(Q *)(o + 0x10) = D_L19_001E8E60[0];
                }
            }
        }
    }

    if (!(*(s32 *)(p + 0x18) & 4)) {
        f32 dist, dx, dy;
        *(f32 *)(o + 0xF0) = -3.14159274f;
        dist = func_0038CF38(o + 0x10, p + 0x40);
        *(f32 *)(o + 0xF4) = -func_0038D160(dist, *(f32 *)(p + 0x48) - *(f32 *)(o + 0x18));
        if (0.0f < func_L01_0040E570(&D_L19_001DF800_003AC268[*(s32 *)(p + 0x24)].pos, &D_L19_001DF800_003AC268[*(s32 *)(p + 0x20)].pos)) {
            f32 *ra = (f32 *)&D_L19_001DF800_003AC268[*(s32 *)(p + 0x20)].pos;
            f32 *rb = (f32 *)&D_L19_001DF800_003AC268[*(s32 *)(p + 0x24)].pos;
            dx = ra[0] - rb[0];
            dy = ra[1] - rb[1];
        } else {
            dx = *(f32 *)(p + 0x40) - *(f32 *)(o + 0x10);
            dy = *(f32 *)(p + 0x44) - *(f32 *)(o + 0x14);
        }
        *(f32 *)(o + 0xF8) = func_0038D160(dx, dy);
    }
}
