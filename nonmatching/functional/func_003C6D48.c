/* functional: high. Rewritten from the PAL assembly (the nonmatching draft is a US port from the rac3-uya-decomp lineage and was not used; it also had the US re-arm count 10 where PAL stores 8). VU0 vadd/vsub.xyz written as FPU xyz ops with retail's w lanes (o->pos.w ends as c->f0.w, as the retail register flow does). 323 words differ (regalloc/scheduling). Uses 3C6718.c context types. */
/* types and callee declarations come from 3C6718.c's context (V_3C1440, O_3C1440, C_3C1440, D_1A4BE0) */
void func_003C6D48(O_3C1440 *o, C_3C1440 *c, V_3C1440 *tgt) {
    V_3C1440 a, b, e, f, g, h[4], i, k, l, d;
    f32 cc[4] __attribute__((aligned(16)));
    f32 v;
    s32 n, r;

    a = o->pos;
    b = o->fF0;
    func_0011A264(cc, 0, 0x10);
    if (tgt != 0 || (D_1A4BE0.f35C == o && D_1A4BE0.f360 >= 2)) {
        /* spring the camera-follow offset toward the target (or the player position) */
        e = tgt != 0 ? *tgt : D_1A4BE0.f80;
        e.x = e.x - o->pos.x;
        e.y = e.y - o->pos.y;
        e.z = e.z - o->pos.z;
        func_003C5418(o, &e, &e, 0);
        e.x = e.x - c->f10.x;
        e.y = e.y - c->f10.y;
        e.z = e.z - c->f10.z;
        cc[0] = -e.y * c->f6C;
        cc[1] = e.x * c->f70;
        cc[2] = -c->f74;
        if (c->fAC == 0) {
            for (n = 0; n < 3; n++) c->f3C[n] = c->f3C[n] + cc[n] * c->f78[n];
            c->fAC = 8;
        }
    } else {
        func_0038CEB0(&c->fAC);
    }
    for (n = 0; n < 3; n++) {
        c->f3C[n] = c->f3C[n] + c->f48[n] * (cc[n] - c->f30[n]);
        c->f3C[n] = c->f3C[n] - c->f54[n] * c->f3C[n];
        c->f30[n] = c->f30[n] + c->f3C[n];
        c->f84[n] = func_0038DE98_003C6D48(c->f84[n], c->f90[n]);
        (&e.x)[n] = c->f9C[n] * func_0038D490(c->f84[n]);
    }
    *(Q_3C1440 *)&f = 0;
    f.x = c->f30[0] + e.x;
    f.y = c->f30[1] + e.y;
    g = f;
    if (c->f60 < g.x) g.x = c->f60;
    else if (g.x < -c->f60) g.x = -c->f60;
    if (c->f64 < g.y) g.y = c->f64;
    else if (g.y < -c->f64) g.y = -c->f64;
    func_0038D6E8(h, &g);
    func_0038D6E8(o->fC0, c->f20);
    func_0038D9D0(o->fC0, o->fC0, h);
    f = c->f10;
    f.z = f.z + e.z;
    func_0038D3E0(&i, &f, o->fC0);
    i.x = i.x + o->pos.x;
    i.y = i.y + o->pos.y;
    i.z = i.z + o->pos.z;
    d = o->pos;
    k = c->f0;
    k.x = k.x - i.x;
    k.y = k.y - i.y;
    k.z = k.z - i.z;
    /* retail: vadd.xyz into the register holding k, so pos.w becomes c->f0.w */
    o->pos.x = d.x + k.x;
    o->pos.y = d.y + k.y;
    o->pos.z = d.z + k.z;
    o->pos.w = k.w;
    v = -c->f30[2];
    if (c->f68 < v) v = c->f68;
    else if (v < -c->f68) v = -c->f68;
    func_003C56B0(o, &o->pos, &o->pos, v);
    r = func_003C5110(o);
    if (r != 0) {
        l = o->pos;
        l.x = l.x - a.x;
        l.y = l.y - a.y;
        l.z = l.z - a.z;
        func_003C5160(r, &l, &b, &o->fF0);
    }
}
