/* functional: medium. Needs #include vu0.h (sqrt_asm); see 573DE0. */
#include "vu0.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V_56C0;
typedef struct { s32 ids[4], lo, hi, vol, slotA, slotB, sel, pad28, next; } S_56C0;
extern u8 D_L39_0024DE00[];
extern u8 D_001FE020[];
extern u8 D_001FE100[];
extern float func_0038CEA8(void *v);
extern int func_0038CAD0(void *p);
extern s32 func_L39_005F35D8(s32 id, s32 flags, void *owner, s32 range);
extern void func_L39_005F3088(s32 slot);
extern s32 func_L39_005B4398(s32 n);

static int owns_56C0(s32 slot, void *obj) {
    u8 *e = D_001FE020 + (slot << 7);
    return *(void **)(e + 0x100) == obj && e[0xD0] != 0;
}

void func_L39_005756C0(u8 *obj) {
    S_56C0 *s = *(S_56C0 **)(obj + 8);
    V_56C0 d, v, w;
    u8 *tab;
    s32 inrange, flags, vol, vol2;
    float len, t, tn, tm, k;
    V_56C0 *c;

    if (s->next != -1) {
        if (s->slotA != -1 && owns_56C0(s->slotA, obj)) func_L39_005F3088(s->slotA);
        s->slotA = -1;
        if (s->slotB != -1 && owns_56C0(s->slotB, obj)) func_L39_005F3088(s->slotB);
        s->sel = s->next;
        s->next = -1;
        s->slotB = -1;
    }
    c = (V_56C0 *)D_L39_0024DE00;
    {
        V_56C0 *o = (V_56C0 *)(obj + 0x40);
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
    tab = (u8 *)D_L39_0024BB6C + (s->ids[s->sel] << 5);
    flags = tab[0x18] ? 4 : 0;
    if (inrange == 1) {
        if (s->slotA != -1 && owns_56C0(s->slotA, obj)) func_L39_005F3088(s->slotA);
        s->slotA = -1;
        if (s->slotB != -1 && owns_56C0(s->slotB, obj)) return;
        if (func_0038CAD0(&s->vol) == 0) return;
        s->slotB = func_L39_005F35D8(s->ids[s->sel], flags | 0x110, obj, 0x400);
        if (s->hi <= 0) return;
        {
            s32 r = func_L39_005B4398(s->hi - s->lo);
            s->vol = (s32)((float)(s->lo + r) * 50.0f);
        }
        return;
    }
    func_0038D000(&v, &v, obj + 0x10);
    {
        V_56C0 *o = (V_56C0 *)(obj + 0x40);
        v.x += o->x; v.y += o->y; v.z += o->z;
        w.x = c->x - v.x; w.y = c->y - v.y; w.z = c->z - v.z;
    }
    len = func_0038CEA8(&w);
    t = 1.0f;
    if (*(float *)(tab + 4) < len) {
        if (s->slotA != -1 && owns_56C0(s->slotA, obj)) func_L39_005F3088(s->slotA);
        s->slotA = -1;
        if (s->slotB != -1 && owns_56C0(s->slotB, obj)) func_L39_005F3088(s->slotB);
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
        if (!(s->slotB != -1 && owns_56C0(s->slotB, obj)))
            s->slotB = func_L39_005F35D8(s->ids[s->sel], flags | 0x110, obj, 0x400);
        func_L39_005F3760(s->slotB, vol2);
    } else {
        if (s->slotB != -1 && owns_56C0(s->slotB, obj)) {
            func_L39_005F3088(s->slotB);
            s->slotB = -1;
        }
        vol = (s32)((float)*(s32 *)(tab + 0xC) * (1.0f - t));
    }
    if (!(s->slotA != -1 && owns_56C0(s->slotA, obj))) {
        if (vol > 0) s->slotA = func_L39_005F35D8(s->ids[s->sel], flags | 0x10, obj, 0x400);
    }
    if (s->slotA != -1) *(V_56C0 *)(D_001FE100 + (s->slotA << 7)) = v;
    func_L39_005F3760(s->slotA, vol);
}
