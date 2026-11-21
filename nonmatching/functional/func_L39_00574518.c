/* functional: high. Plain C for retail's vsub/abs.s; f32 return of func_0038D000 declared to match file context. */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V_4518;
extern s32 D_L39_002412DC;
extern s32 *D_001D5A10_sda;
extern void func_L39_005F38D0(void *obj, s32 a, s32 b, s32 c, s32 d);
extern u8 *func_L39_0061BF38(s32 idx);
extern f32 func_0038D000(void *dst, void *src, void *mat);

void func_L39_00574518(u8 *obj) {
    V_4518 a, b, c;
    u8 *t = *(u8 **)(obj + 8);
    V_4518 *cam, *o;
    s32 v;
    float x;

    if (D_L39_002412DC == 0x30 || D_L39_002412DC == 0x15) {
        func_L39_005F38D0(0, t[0], *(s32 *)(t + 4), t[1], t[2]);
        return;
    }
    if (*D_001D5A10_sda >= 2) return;
    cam = (V_4518 *)(func_L39_0061BF38(0) + 0xA0);
    c = *cam;
    o = (V_4518 *)(obj + 0x40);
    a.x = c.x - o->x; a.y = c.y - o->y; a.z = c.z - o->z; a.w = 0.0f;
    func_0038D000(&b, &a, obj + 0x50);
    x = b.x;
    if ((x < 0 ? -x : x) <= 1.0f && (b.y < 0 ? -b.y : b.y) <= 1.0f && (b.z < 0 ? -b.z : b.z) <= 1.0f) {
        s32 lim = *(s32 *)(t + 4);
        v = (s32)((float)lim * ((x + 1.0f) * 0.5f));
        if (lim < v) v = lim;
        func_L39_005F38D0(obj, t[0], v, t[1], t[2]);
        t[3] = 1;
    } else if (t[3] != 0) {
        if (0.0f < b.x) func_L39_005F38D0(0, t[0], *(s32 *)(t + 4), t[1], t[2]);
        else func_L39_005F38D0(obj, 0, 0, 0, 0);
        t[3] = 0;
    }
}
