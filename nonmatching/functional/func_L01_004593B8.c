/* functional: high. From the repo's near-miss draft (written for this PAL asm), re-read against retail: control flow, offsets and constants (3.0, 100.0, gp 0x376C = D_001E001C) all agree; callee renamed func_L01_0040E518 -> func_0038CF38 (catalogue name of the frontbin distance fn). 53 diff words in register allocation only. */
typedef int Q_004593B8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_004593B8;
extern u8 *D_L01_001E001C;

static __inline__ u8 *pick_004593B8(u8 *x, u8 **list, s32 n) {
    s32 i;
    s32 found = 0;
    for (i = 0; i < n; i++) {
        if (x == list[i]) {
            found = 1;
        }
    }
    if (found) {
        return 0;
    }
    return x;
}

u8 *func_L01_004593B8(s32 a0, u8 *obj, u8 **list, s32 *n, V_004593B8 *pos) {
    V_004593B8 p;
    V_004593B8 *pp;
    u8 *a;
    u8 *b;
    u8 *v;
    u8 *r;
    s32 i;
    s32 found;
    f32 da;
    f32 db;
    pp = &p;
    a = 0;
    b = 0;
    *(Q_004593B8 *)&p = *(Q_004593B8 *)pos;
    list[*n] = obj;
    (*n)++;
    v = *(u8 **)(obj + 0x68);
    if (*(s32 *)v != -1) {
        a = D_L01_001E001C + (*(s32 *)v << 8);
    }
    if (*(s32 *)(v + 4) != -1) {
        b = D_L01_001E001C + (*(s32 *)(v + 4) << 8);
    }
    if (a != 0 && b == 0) {
        return pick_004593B8(a, list, *n);
    }
    if (b != 0 && a == 0) {
        return pick_004593B8(b, list, *n);
    }
    db = 0.0f;
    db += func_0038CF38(b + 0x10, pp);
    if (3.0f < __builtin_fabsf(*(f32 *)(b + 0x18) - pp->z)) {
        db += 100.0f;
    }
    da = 0.0f;
    da += func_0038CF38(a + 0x10, pp);
    if (3.0f < __builtin_fabsf(*(f32 *)(a + 0x18) - pp->z)) {
        da += 100.0f;
    }
    r = b;
    if (da < db) {
        r = a;
    }
    return r;
}
