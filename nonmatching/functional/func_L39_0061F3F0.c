/* functional: high. Near miss (div.s scheduling differs); needs vu0 helpers, which only compile with -mvu0-use-vf0-vf2 that this file's flag line lacks. Logic re-read against PAL asm: lq/sq slide of 160->170->180 when w15C passed, then position/velocity integration. */
typedef struct {
    u8 p0[0x30];
    vu0_v4 v30;
    vu0_v4 v40;
    u8 p50[0x20];
    vu0_v4 v70;
    u8 p80[0x10];
    vu0_v4 v90;
    vu0_v4 vA0;
    vu0_v4 vB0;
    u8 pC0[0x34];
    s32 wF4;
    u8 pF8[4];
    s32 wFC;
    u8 p100[0x5C];
    s32 w15C;
    vu0_v4 v160;
    vu0_v4 v170;
    vu0_v4 v180;
} O_0061F3F0;

extern s32 D_001A5DF8[];
extern f32 D_L39_0024118C;
__asm__(".extern D_L39_0024118C, 16");
extern void func_0038CE20(void *, void *, f32);

void func_L39_0061F3F0(O_0061F3F0 *o) {
    s32 now;
    vu0_v4 a, b, c, d, e, f, g;
    f32 t, inv;
    vu0_v4 *pv;

    now = D_001A5DF8[0];
    if (now == o->wFC) {
        return;
    }
    if (o->w15C >= 0 && now >= o->w15C) {
        *(vu0_q *)&o->v180 = *(vu0_q *)&o->v170;
        *(vu0_q *)&o->v170 = *(vu0_q *)&o->v160;
        o->w15C = -1;
    }
    t = (f32)(now - o->wF4) / (D_L39_0024118C * 1000.0f);
    a = o->v90;
    pv = &o->vA0;
    b = *pv;
    func_0038CE20(&c, &o->v30, t);
    func_0038CE20(&d, &o->v40, t * 0.5f * t);
    vec_add_ba(&e, &c, &d);
    vec_copy(&g, &o->v70);
    vec_copy(&f, &a);
    vec_add_ba(&o->v90, &g, &e);
    vec_sub_ba(&o->vA0, &f, &o->v90);
    t = (f32)(now - o->wFC) / (D_L39_0024118C * 1000.0f);
    inv = 1.0f / t;
    func_0038CE20(pv, pv, inv);
    vec_sub_ba(&o->vB0, &b, &o->vA0);
    func_0038CE20(&o->vB0, &o->vB0, inv);
    o->wFC = now;
}
