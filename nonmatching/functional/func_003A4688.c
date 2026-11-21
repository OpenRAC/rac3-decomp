/* functional: medium. Written from the PAL assembly; 781 words differ (regalloc/frame/scheduling). VU0 vadd/vsub.xyz written as FPU xyz ops keeping w as retail does. Register passthrough fixed: retail reads v0 after func_003A41C8, whose C is void, so the C calls func_003A40F0 with the same arguments directly. Retail also calls func_003A4030 into a stack vector it never reads (kept for its side effects). Medium because of the size (52-channel two-pass mixer) and inferred struct offsets (Ch_3A4688/Def_3A4688/Obj_3A4688); every offset was taken from the assembly. */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A4688;
typedef struct {
    u8 p0[0x18]; u8 b18; u8 b19; s16 h1A; s32 i1C;
} Def_3A4688;
typedef struct {
    u8 p0[0x10]; V4_3A4688 pos; u8 b20; u8 p21[0xC0 - 0x21]; u8 mtx[0x40];
} Obj_3A4688;
typedef struct {
    s32 handle;            /* 0x00 */
    Def_3A4688 *def;       /* 0x04 */
    u8 p8[4];
    s16 vol;               /* 0x0C */
    u8 pE[2];
    u8 state;              /* 0x10 */
    u8 p11[2];
    u8 b13;                /* 0x13 */
    s32 i14;               /* 0x14 */
    s32 pitch;             /* 0x18 */
    Obj_3A4688 *obj;       /* 0x1C */
    V4_3A4688 pos;         /* 0x20 */
    V4_3A4688 offset;      /* 0x30 */
    s32 i40;               /* 0x40 */
    u8 p44[8];
    s32 i4C;               /* 0x4C */
    u8 p50[4];
    u8 timer[4];           /* 0x54 */
    s32 flags;             /* 0x58 */
    u8 p5C[0x80 - 0x5C];
} Ch_3A4688;
extern u8 D_1A3170[];
extern s32 D_2228D0;
extern f32 D_1A4F30;
extern u8 D_001D5BDC;
extern s32 D_001D5B70;
extern s16 D_16C5A0;
extern V4_3A4688 D_1A4D30;
extern void func_0013B620(void);
extern void func_0013CF80(s32, s32, s32, s32, s32);
extern void func_0013CFF8(s32, s32, s32, s32);
extern void func_0013C118(s32);
extern void func_0013C200(s32, void *, void *);
extern void func_0013C2C0(s32, s32, s32, s32, s32, s32, void *, void *);
extern void func_0013C0B8(s32, s32, s32, s32, s32, s32, void *, void *);
extern s32 func_0013D1E8(s32);
extern void func_0013CA28(void);
extern void func_0013CA20(void);
extern void func_003A2330(void);
extern void func_003A5950();
extern void func_003A5908();
extern s32 func_0038CEB0(void *);
extern void func_0038CF58(void *, s32, s32);
extern void func_0038D3E0(void *, void *, void *);
extern void func_0038D348(s32 a, s32 b, f32 x);
extern f32 func_0038D248(void *, void *);
extern f32 func_0038D288(void *);

s32 func_003A4688(void) {
    u8 *m = D_1A30B0;
    V4_3A4688 *ring = (V4_3A4688 *)(m + 0x50);
    V4_3A4688 lis, acc, d, vel, tmp, rel;
    s32 vol_a[52];      /* per-channel action flags (sp+0x30) */
    s32 vol_c[52];      /* per-channel volume (sp+0x100) */
    f32 dop[52];        /* per-channel approach speed (sp+0x1D0) */
    s32 has_x, n, a, b, cnt, i, r, v, flags, pan, pitch, h, snd;
    s16 s;
    f32 cut, speed, f, div;
    Ch_3A4688 *ch;
    Obj_3A4688 *obj;
    s32 dead;

    has_x = D_2228D0;
    cut = 0.0f;
    if (has_x) cut = D_1A4F30;
    func_0013B620();
    func_003A43E0();
    b = m[0x43];
    if (b & 8)
        func_0013CF80(2, 0, 0, 0, 0);
    else if (b & 0x13)
        func_0013CF80(2, m[0x40], *(s32 *)(m + 0xB4), m[0x41], m[0x42]);
    else if (b & 4)
        func_0013CFF8(2, *(s32 *)(m + 0xB4), 0xC, 3);
    m[0x43] = 0;
    if ((D_001D5B94 == 0 || D_001D5B94 == 2) && D_001D5BDC == 0)
        func_003A4030(&lis, 0);

    /* listener history: 4-entry ring of camera positions, averaged velocity */
    n = (*(s32 *)(m + 0x48) + 1) % 4;
    *(u128_t *)&acc = 0;
    *(s32 *)(m + 0x48) = n;
    ring[n] = *(V4_3A4688 *)D_00222400;
    speed = func_0038D288(&D_1A4D30);
    a = *(s32 *)(m + 0x48);
    b = (a + 3) % 4;
    cnt = 0;
    while (b != *(s32 *)(m + 0x48)) {
        d = ring[a];
        d.x = ring[a].x - ring[b].x;
        d.y = ring[a].y - ring[b].y;
        d.z = ring[a].z - ring[b].z;
        if (!(func_0038D288(&d) < speed + 1.2f)) break;
        acc.x = acc.x + d.x;
        acc.y = acc.y + d.y;
        acc.z = acc.z + d.z;
        a = b;
        b = (b + 3) % 4;
        cnt++;
    }
    if (cnt >= 2) func_0038D200((f32 *)&acc, &acc, 1.0f / (f32)cnt);

    /* master volumes */
    if (D_001D5B70 != 0 || *(s16 *)(m + 0xAC) > 0) {
        div = 1.0f;
        f = (f32)*(s32 *)m;
        if (D_001D5B70 == 0) {
            if (*(s16 *)(m + 0xAC) == 2) {
                *(s16 *)(m + 0xAE) = 25;
                *(s16 *)(m + 0xAC) = 3;
            }
        } else if (*(s16 *)(m + 0xAC) == 0) {
            if (D_001D5B70 == 2) {
                *(s16 *)(m + 0xAC) = 2;
            } else {
                *(s16 *)(m + 0xAE) = 25;
                *(s16 *)(m + 0xAC) = 1;
            }
        }
        s = *(u16 *)(m + 0xAE) - 1;
        *(s16 *)(m + 0xAE) = s;
        switch (*(s16 *)(m + 0xAC)) {
        case 2:
            div = 4.0f;
            break;
        case 1:
            div = (1.0f - (f32)s / 25.0f) * 3.0f + 1.0f;
            if (s <= 0) *(s16 *)(m + 0xAC) = 2;
            break;
        case 3:
            div = ((f32)s / 25.0f) * 3.0f + 1.0f;
            if (s <= 0) *(s16 *)(m + 0xAC) = 0;
            break;
        }
        v = (s32)(f / div);
        func_0013BF30(0, v);
        func_0013BF30(3, v);
    } else if (D_001D5B94 == 2 || (D_001D5B94 == 6 && (D_16C5A0 == 3 || D_16C5A0 == 0))) {
        *(s32 *)(m + 4) = 0;
        func_0013BF30(1, 0);
        *(s32 *)m = *(s32 *)m >> 1;
        func_0013BF30(0, *(s32 *)m);
        *(s32 *)(m + 0xC) = *(s32 *)(m + 0xC) >> 1;
        func_0013BF30(3, *(s32 *)(m + 0xC));
    } else {
        if (*(s32 *)(m + 0x1B20) & 2) {
            v = *(s32 *)(m + 4);
            if (has_x) v = v * 3 / 5;
            *(s32 *)(m + 4) = v;
            func_0013BF30(1, v);
        }
        if (*(s32 *)(m + 0x1B20) & 1) func_0013BF30(0, *(s32 *)m);
        if (*(s32 *)(m + 0x1B20) & 8) func_0013BF30(3, *(s32 *)(m + 0xC));
    }
    if (*(s32 *)(m + 0x1B20) & 0x10) func_0013BF30(4, *(s32 *)(m + 0x10));
    if (*(s32 *)(m + 0x1B20) & 4) {
        func_0013BF30(2, *(s32 *)(m + 8));
        func_0013BF30(6, *(s32 *)(m + 8));
    }
    if (*(s32 *)(m + 0x1B20) & 0x20) func_0013BF30(5, *(s32 *)(m + 0x14));

    func_0038CF58(vol_a, 0, 0xD0);
    func_0038CF58(vol_c, 0, 0xD0);
    func_0038CF58(dop, 0, 0xD0);

    /* pass 1: decide what each of the 52 channels needs */
    for (i = 0; i < 52; i++) {
        ch = (Ch_3A4688 *)(D_1A3170 + i * 0x80);
        if (ch->state != 7 && (ch->handle == 0 || ch->handle == -1)) continue;
        obj = ch->obj;
        dead = 0;
        if (obj != 0 && (obj->b20 == 0xFE || obj->b20 == 0xFD)) dead = 1;
        if (dead) ch->obj = 0;
        if (!func_0038CEB0(ch->timer)) continue;
        if (ch->state == 4) {
            vol_a[i] = 0x20;
            continue;
        }
        if (ch->state != 6 && dead && ch->def->b18 != 0) {
            vol_a[i] = 0x20;
            continue;
        }
        if (D_001D5B94 != 0 && D_001D5B94 != 2 && D_001D5B94 != 6 && ch->state != 7) {
            vol_a[i] = 0x10;
            continue;
        }
        if (ch->flags & 0x100) ch->pos = *(V4_3A4688 *)D_00222400;
        obj = ch->obj;
        if (obj != 0 && !(ch->flags & 8)) {
            if (ch->flags & 0x40) {
                func_0038D3E0(&tmp, &ch->offset, obj->mtx);
                tmp.x = tmp.x + obj->pos.x;
                tmp.y = tmp.y + obj->pos.y;
                tmp.z = tmp.z + obj->pos.z;
                vel = tmp;
                vel.x = tmp.x - ch->pos.x;
                vel.y = tmp.y - ch->pos.y;
                vel.z = tmp.z - ch->pos.z;
                ch->pos = tmp;
            } else {
                ch->pos.z = ch->pos.z - 1.0f;
                vel = obj->pos;
                vel.x = obj->pos.x - ch->pos.x;
                vel.y = obj->pos.y - ch->pos.y;
                vel.z = obj->pos.z - ch->pos.z;
                ch->pos = obj->pos;
                ch->pos.z = ch->pos.z + 1.0f;
            }
        } else {
            *(u128_t *)&vel = 0;
        }
        /* velocity relative to the listener, dotted with the direction to the listener */
        rel = vel;
        rel.x = vel.x - acc.x;
        rel.y = vel.y - acc.y;
        rel.z = vel.z - acc.z;
        vel = rel;
        tmp = *(V4_3A4688 *)D_00222400;
        tmp.x = tmp.x - ch->pos.x;
        tmp.y = tmp.y - ch->pos.y;
        tmp.z = tmp.z - ch->pos.z;
        func_0038D348((s32)&tmp, (s32)&tmp, 1.0f);
        dop[i] = func_0038D248(&tmp, &vel);
        if (!(ch->flags & 0x10)) {
            /* func_003A41C8(ch, &ch->pos, 0, 0) returns func_003A40F0's result in v0 */
            f32 *q = *(f32 **)&ch->def;
            r = func_003A40F0(q, 0, func_0038D2E0(&ch->pos, D_00222400), q[0], q[1]);
            vol_c[i] = (ch->vol * r) / 1024;
            if (!(ch->def->b19 & 2)) vol_a[i] |= 8;
        } else {
            r = 0x400;
            vol_c[i] = ch->vol;
            if (ch->flags & 0x200) vol_a[i] |= 8;
        }
        if (has_x && !(ch->def->b19 & 4) && cut < ch->pos.z) vol_c[i] = vol_c[i] / 2;
        vol_a[i] |= 1;
        if (r < 0x20 && vol_c[i] < 0x20 && (ch->flags & 4)) {
            vol_a[i] = 0x20;
            continue;
        }
        if (*(u8 *)&ch->flags & 1) continue;
        v = vol_a[i];
        vol_a[i] = v | 2;
        if (ch->flags & 0x20) continue;
        if (ch->def->b19 & 0x10) continue;
        vol_a[i] = v | 6;
    }

    /* pass 2: apply to the sound library voices */
    for (i = 0; i < 52; i++) {
        ch = (Ch_3A4688 *)(D_1A3170 + i * 0x80);
        a = vol_a[i];
        if (a == 0) continue;
        h = ch->handle;
        ch->handle = -1;
        if (a & 0x20) {
            if (ch->state == 7) {
                ch->obj = 0;
                ch->i40 = 0;
                ch->state = 0;
                continue;
            }
            func_0013C118(h);
            ch->state = 6;
            func_0013C200(h, func_003A5950, ch);
            ch->i4C = ch->b13;
            continue;
        }
        if (a & 0x10) {
            func_0013C200(h, func_003A5950, ch);
            ch->i4C = ch->b13;
            continue;
        }
        pan = 0;
        pitch = 0;
        flags = 1;
        if ((a & 2) && !(ch->flags & 0x100)) {
            pan = func_003A4228((O_3A40E8 *)ch, (u128_t *)&ch->pos);
            flags = 7;
        }
        if (vol_a[i] & 4) {
            flags |= 8;
            pitch = func_0013D1E8((s32)(dop[i] * ((ch->flags & 2) ? 500.0f : 300.0f)));
        }
        if (ch->i14 != 0) flags |= 0x10;
        if (ch->pitch != 0) {
            pitch += ch->pitch;
            flags |= 8;
        }
        if (has_x && !(ch->def->b19 & 8)) {
            flags |= 8;
            pitch -= 0x5F4;
        }
        if (ch->state != 7) {
            v = vol_c[i];
            if (v > 0x400) v = 0x400;
            func_0013C2C0(h, flags, v, pan, pitch, ch->i14, func_003A5950, ch);
            ch->i4C = ch->b13;
            continue;
        }
        if (ch->def == 0) goto stop;
        snd = ((s32 *)(m + 0x90))[ch->def->i1C];
        if (snd == -1 || snd == 0) {
        stop:
            ch->obj = 0;
            ch->i40 = 0;
            ch->state = 0;
            continue;
        }
        ch->state = 1;
        v = vol_c[i];
        if (v > 0x400) v = 0x400;
        func_0013C0B8(((s32 *)(m + 0x90))[ch->def->i1C], ch->def->h1A, v, pan, pitch, ch->i14, func_003A5908, ch);
    }
    func_003A2330();
    func_0013CA28();
    func_0013B620();
    func_0013CA20();
    *(s32 *)(m + 0x1B20) = 0;
    *(s32 *)(m + 0x44) = 0;
    return 0;
}
