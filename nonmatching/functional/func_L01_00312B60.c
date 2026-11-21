/* functional: high. Same stores, calls and order as retail; the pool search loop runs a single 0x50-byte entry as the matched func_L01_00312C88 does; vadd.xyz and lq/sq copies are plain C. */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_312B60;
typedef struct {
    V_312B60 v0;
    V_312B60 v10;
    V_312B60 v20;
    void *owner;
    s32 w34;
    s32 w38;
    f32 f3C;
    s32 w40;
    s32 w44;
    u8 pad48[8];
} Ent_312B60;
extern Ent_312B60 *D_L01_001E1730;
extern f32 func_0038DAB8(f32, f32);
extern f32 func_00382538(void);
extern void func_0038CF68(float *off, char *src, float scale);
extern void func_0038CE90(void *, void *, void *);
extern void func_L01_00312DD8(void *, s32, void *, f32);
void func_L01_00312B60(f32 f, void *obj, s32 id, V_312B60 *b, V_312B60 *a) {
    V_312B60 tmp;
    Ent_312B60 *e;
    s32 i, n;
    f32 ang;

    e = D_L01_001E1730;
    for (i = 0; i < 1; i++, e++) {
        if (e->owner != 0) {
            continue;
        }
        e->owner = obj;
        e->w34 = id;
        e->f3C = f;
        e->w38 = 0;
        e->v0 = *a;
        e->v20 = *b;
        e->v20.z = *(f32 *)((u8 *)obj + 0x18);
        func_0038CF68(&tmp.x, (char *)a, 2.0f);
        tmp.x = tmp.x + e->v20.x;
        tmp.y = tmp.y + e->v20.y;
        tmp.z = tmp.z + e->v20.z;
        func_0038CE90(&e->v10, &e->v20, &tmp);
        ang = func_00382538();
        for (n = 0x2F; n >= 0; n--) {
            func_L01_00312DD8(e, 2, 0, ang);
            ang = func_0038DAB8(ang, 0.13368479907512665f);
        }
        e->w44 = 0;
        e->w40 = 0;
        break;
    }
}
