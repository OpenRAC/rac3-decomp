/* functional: medium. Vector add as plain C; constants verified vs PAL asm. */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V_F368;
typedef struct { u8 pad[0x70]; u8 *data; u8 pad74[0x20]; int index; f32 f98; u8 pad9c[0x1C]; } M_F368;
extern u8 D_001A5810[];
extern s32 D_001A5990[];
extern f32 D_L39_00242398[];
extern u8 D_L39_0024E040[];
extern u8 D_L39_0024E290[];
extern s32 D_L39_002429BC;
extern f32 D_001DFFDC_sda;
extern s32 D_001DFF70_sda;
extern f32 D_001DFF74_sda;
extern void func_003C47E8(void *dst, void *src);
extern u8 *func_L39_0061BF38(s32 idx);
extern float func_0038DAB8(float a, float b);
extern void func_L01_003E4580(void *m, void *v);
extern void func_L39_0056B080(void *m);
extern void func_L39_0056A7B8(void *m);
extern void func_L01_003EA648(void *m);
extern void func_L01_003E5E50(void *m);
extern void func_0038D6C8(void *dst, void *a, void *b, float t);
extern void func_0038D830(void *a, void *b);
extern void func_0038D590(void *m, void *v);

void func_L39_0056F368(M_F368 *m) {
    V_F368 a, b, c, d, e;      /* a=sp0 b=sp10 c=sp20 d=sp30 e=sp40 (kept as separate quads) */
    V_F368 f;                   /* sp50 */
    u8 *st = m->data + 0x60;
    u8 *p;
    float d1, lim;
    int idx = m->index;
    s32 v4;

    func_003C47E8(&a, m);
    p = func_L39_0061BF38(m->index);
    v4 = *(s32 *)(p + 0x2544);
    D_L39_00242398[m->index] =
        (float)D_001A5990[v4 + (D_001A5810[v4 + 0xA4] << 3)] / 100.0f * 0.056723204f + 0.021816615f;
    e = *(V_F368 *)(D_L39_0024E040 + m->index * 0x460);
    d1 = e.z - m->f98;
    lim = D_001DFFDC_sda * 0.02f;
    if (0.0f < d1) {
        if (lim < d1) d1 = lim;
    } else if (d1 < 0.0f) {
        lim = -(D_001DFFDC_sda * 0.02f);
        if (d1 < lim) d1 = lim;
    }
    m->f98 = m->f98 + d1;
    if (e.z == 0.0f) {
        float t = m->f98;
        if (t < 0.0f) t = -t;
        if (t <= D_001DFFDC_sda * 0.02f) m->f98 = 0.0f;
    }
    e.z = m->f98;
    {
        V_F368 *o = (V_F368 *)(D_L39_0024E290 + m->index * 0x460);
        d.x = e.x + o->x; d.y = e.y + o->y; d.z = e.z + o->z;
    }
    {
        u8 *h = D_L39_0024E290 - 0x410 + idx * 0x460;
        float f12 = *(float *)(h + 0x1CC);
        if (D_L39_002429BC != 0) f12 = 0.0f;
        d.w = func_0038DAB8(f12, *(float *)(h + 0x41C));
    }
    func_L01_003E4580(m, &d);
    func_L39_0056B080(m);
    func_L39_0056A7B8(m);
    func_L01_003EA648(m);
    func_L01_003E5E50(m);
    if ((s8)st[0x10F] > 0) {
        float s, t;
        st[0x10F] = st[0x10F] - 1;
        func_003C47E8(&c, m);
        s = D_001DFF74_sda;
        t = (float)(s8)st[0x10F] / (float)D_001DFF70_sda;
        func_0038D6C8(&b, &a, &c, s + (1.0f - s) * (1.0f - t));
        func_0038D830(&b, &f);
        func_0038D590(m, &f);
        *(V_F368 *)((u8 *)m + 0x40) = *(V_F368 *)m;
    } else {
        st[0x10E] = 0;
    }
}
