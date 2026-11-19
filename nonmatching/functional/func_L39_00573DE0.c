/* functional: medium. Plain C; constants/offsets verified vs PAL asm; needs #include vu0.h for sqrt_asm. */
#include "vu0.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V_3DE0;
typedef struct { s32 id, lo, hi, vol, slotA, slotB, active; } S_3DE0;
extern u8 D_L39_0024DE00[];
extern u8 *D_L39_0024BB6C;
extern u8 D_001FE020[];
extern u8 D_001FE100[];
extern f32 func_0038D000(void *dst, void *src, void *mat);
extern float func_0038CEA8(void *v);
extern int func_0038CAD0(void *p);
extern s32 func_L39_005F35D8(s32 id, s32 flags, void *owner, s32 range);
extern void func_L39_005F3088(s32 slot);
extern void func_L39_005F3760(s32 slot, s32 vol);
extern s32 func_L39_005B4398(s32 n);

static int owns_3DE0(s32 slot, void *obj) {
    u8 *e = D_001FE020 + (slot << 7);
    return *(void **)(e + 0x100) == obj && e[0xD0] != 0;
}

void func_L39_00573DE0(u8 *obj) {
    S_3DE0 *s = *(S_3DE0 **)(obj + 8);
    V_3DE0 d, v, w;
    u8 *tab;
    s32 inrange, flags, a, vol, vol2;
    float len, t, tn, tm, k;
    V_3DE0 *c;

    if (s->active == 0 || s->id == -1) return;
    c = (V_3DE0 *)D_L39_0024DE00;
    {
        V_3DE0 *o = (V_3DE0 *)(obj + 0x40);
        d.x = c->x - o->x; d.y = c->y - o->y; d.z = c->z - o->z; d.w = 0.0f;
    }
    inrange = 1;
    func_0038D000(&v, &d, obj + 0x50);
    if (1.0f < v.x) { v.x = 1.0f; inrange = 0; }
    if (v.x < -1.0f) { v.x = -1.0f; inrange = 0; }
    if (1.0f < v.y) { v.y = 1.0f; inrange = 0; }
    else if (v.y < -1.0f) { v.y = -1.0f; inrange = 0; }
    if (v.z > 1.0f) { v.z = 1.0f; inrange = 0; }
    else if (v.z < -1.0f) { v.z = -1.0f; inrange = 0; }
    tab = D_L39_0024BB6C + (s->id << 5);
    flags = tab[0x18] ? 4 : 0;
    if (inrange == 1) {
        if (s->slotA != -1 && owns_3DE0(s->slotA, obj)) func_L39_005F3088(s->slotA);
        a = s->slotB;
        s->slotA = -1;
        if (a != -1 && owns_3DE0(a, obj)) {
            func_L39_005F3760(a, *(s32 *)(tab + 0xC));
            return;
        }
        if (func_0038CAD0(&s->vol) == 0) return;
        s->slotB = func_L39_005F35D8(s->id, flags | 0x110, obj, 0x400);
        if (s->hi <= 0) return;
        a = func_L39_005B4398(s->hi - s->lo);
        {
            float f = (float)(s->lo + a) * 50.0f;
            s->vol = (s32)f;
        }
        return;
    }
    func_0038D000(&v, &v, obj + 0x10);
    {
        V_3DE0 *o = (V_3DE0 *)(obj + 0x40);
        v.x += o->x; v.y += o->y; v.z += o->z;
        w.x = c->x - v.x; w.y = c->y - v.y; w.z = c->z - v.z;
    }
    len = func_0038CEA8(&w);
    t = 1.0f;
    if (*(float *)(tab + 4) < len) {
        if (s->slotA != -1 && owns_3DE0(s->slotA, obj)) func_L39_005F3088(s->slotA);
        s->slotA = -1;
        if (s->slotB != -1 && owns_3DE0(s->slotB, obj)) func_L39_005F3088(s->slotB);
        s->slotB = -1;
    } else {
        t = len * (1.0f / (*(float *)(tab + 4) - *(float *)tab));
    }
    if (t < 0.2f) {
        tn = (0.2f - t) * 5.0f;
        tm = 1.0f - tn;
        k = (float)*(s32 *)(tab + 0xC) / sqrt_asm(tn * tn + tm * tm);
        vol = (s32)(tm * k);
        vol2 = (s32)(tn * k);
        if (!(s->slotB != -1 && owns_3DE0(s->slotB, obj)))
            s->slotB = func_L39_005F35D8(s->id, flags | 0x110, obj, 0x400);
        func_L39_005F3760(s->slotB, vol2);
    } else {
        if (s->slotB != -1 && owns_3DE0(s->slotB, obj)) {
            func_L39_005F3088(s->slotB);
            s->slotB = -1;
        }
        vol = (s32)((float)*(s32 *)(tab + 0xC) * (1.0f - t));
    }
    if (!(s->slotA != -1 && owns_3DE0(s->slotA, obj))) {
        if (vol > 0) s->slotA = func_L39_005F35D8(s->id, flags | 0x10, obj, 0x400);
    }
    if (s->slotA != -1) *(V_3DE0 *)(D_001FE100 + (s->slotA << 7)) = v;
    func_L39_005F3760(s->slotA, vol);
}
