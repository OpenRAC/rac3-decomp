/* functional: high. Plain-C vector math replaces retail VU0 xyz ops (file flags do have -mvu0-use-vf0-vf2, so a byte match with vec_sub_ba etc. may be reachable); all constants taken from the asm bit patterns. Not byte-matched (271 diff lines in first compile). */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00543410;
extern f32 func_0038CEA8(void *);
extern f32 func_0038DBA0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_00448690(f32 *, s32, f32, f32);
extern void func_L01_00448728(f32 *, f32 *, s32, f32, f32, f32, f32);
extern void func_L39_00543AA8(void *);
extern void func_L39_0066A398(void *, f32);
extern void func_L39_00543278(void *);

void func_L39_00543410(u8 *o) {
    u8 *s = *(u8 **)(o + 0x68);
    u8 *g = *(u8 **)(s + 0x384);
    u8 *p;
    V_00543410 d;
    V_00543410 *pos = (V_00543410 *)(o + 0x10);
    V_00543410 *src;
    f32 len, k, ang, rate;

    if ((*(u32 *)(g + 0x2F8) & 2) == 0) {
        p = *(u8 **)(g + 0x2D8);
        if (p != 0 && *(u8 *)(p + 0x1A14) == 0 && (*(u32 *)(*(u8 **)(p + 0x2558) + 0x1AC) & 4)) {
            src = (V_00543410 *)(p + 0x4D30);
            d.x = src->x - pos->x; d.y = src->y - pos->y; d.z = src->z - pos->z; d.w = src->w;
            len = func_0038CEA8(&d);
            k = 0.0f;
            if (len < 1.5f) {
                k = 1.0f;
            } else if (len < 3.0f) {
                k = 1.75f;
            } else if (len < 5.0f) {
                k = 2.5f;
            }
            if (0.0f < k) {
                func_0038CE20(&d, &d, k / 10.0f);
            }
            pos->x = pos->x + d.x; pos->y = pos->y + d.y; pos->z = pos->z + d.z;
            *(f32 *)(s + 0x368) = *(f32 *)(o + 0x18);
            ang = func_0038DBA0(*(f32 *)(o + 0xF8), *(f32 *)(g + 0x208));
            k = 10.0f;
            if (0.7853982f < ang) {
                k = 120.0f;
            }
            rate = k * 0.017453292f;
            rate = rate * 0.020000001f;
            func_L01_00448690((f32 *)(o + 0xF8), 0, *(f32 *)(p + 0x4D68), rate);
        } else {
            src = (V_00543410 *)(g + 0x1F0);
            d.x = src->x - pos->x; d.y = src->y - pos->y; d.z = src->z - pos->z; d.w = src->w;
            func_0038CE20(&d, &d, 0.1f);
            pos->x = pos->x + d.x; pos->y = pos->y + d.y; pos->z = pos->z + d.z;
            *(f32 *)(s + 0x368) = *(f32 *)(o + 0x18);
            ang = func_0038DBA0(*(f32 *)(o + 0xF8), *(f32 *)(g + 0x208));
            k = 10.0f;
            if (0.7853982f < ang) {
                k = 120.0f;
            }
            rate = k * 0.017453292f;
            rate = rate * 0.020000001f;
            func_L01_00448690((f32 *)(o + 0xF8), 0, *(f32 *)(g + 0x208), rate);
        }
        if ((*(u32 *)(g + 0x2F8) & 2) == 0) {
            func_L39_00543278(o);
            return;
        }
    }
    {
        V_00543410 *t = (V_00543410 *)(s + 0x290);
        src = (V_00543410 *)(g + 0xB0);
        t->x = src->x - pos->x; t->y = src->y - pos->y; t->z = src->z - pos->z; t->w = src->w;
        *(V_00543410 *)(g + 0x270) = *t;
        len = func_0038CEA8(t);
        *(f32 *)(g + 0x310) = len;
        if (len < 0.002f) {
            *(s32 *)(g + 0x310) = 0;
        }
    }
    func_L39_00543AA8(o);
    func_L39_0066A398(g, 50.0f);
    func_L01_00448728((f32 *)(o + 0xF0), (f32 *)(g + 0x280), 0, *(f32 *)(g + 0x200), 0.0029321531765162945f, 0.014400000683963299f, 0.20943951606750488f);
    func_L01_00448728((f32 *)(o + 0xF4), (f32 *)(g + 0x284), 0, *(f32 *)(g + 0x204), 0.0029321531765162945f, 0.014400000683963299f, 0.20943951606750488f);
    func_L01_00448728((f32 *)(o + 0xF8), (f32 *)(g + 0x288), 0, *(f32 *)(g + 0x208), 0.0029321531765162945f, 0.014400000683963299f, 0.20943951606750488f);
}
