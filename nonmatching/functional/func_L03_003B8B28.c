/* functional: medium. Branch structure verified against asm (hit via func_003D3CB0 or func_L01_003FB640; D_001E9218 is the hit object; types 0x1C04 kinds 0/3/6 vs others vs 0x1C06). func_L03_003ADF38/ADF48 meanings unknown; arg is the hit object (register left in a0). */
/* localdecomp:start func_L03_003B8B28 */
typedef int Q_3B8B28 __attribute__((mode(TI)));
typedef struct { f32 f[4]; } __attribute__((aligned(16))) V_3B8B28;
extern u8 *D_L03_001E9218;
extern void func_003C2F58(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00446748(void *, u8 *, s32, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern void func_L03_003ADF48(u8 *);
extern void func_L03_003ADF38(u8 *);
extern void func_L03_003B8FA0(void *, s32, s32, s32);
extern void func_L01_004AAC98(s32, s32, u8 *, s32);
extern void func_L01_00446780(u8 *, void *, s32, s32, s32, s32, f32, f32, f32);
extern f32 func_0038CF38(void *, void *);
extern void func_003C2880(u8 *);
extern void func_L03_003B8F10(u8 *);

void func_L03_003B8B28(u8 *m) {
    u8 *s = *(u8 **)(m + 0x68);
    V_3B8B28 d, start;
    u8 coll[0x30];
    V_3B8B28 spark;
    u8 *h;
    s16 t;
    s32 kind;
    s32 hit;
    func_003C2F58(*(void **)(s + 0x28), *(s32 *)(s + 0x2C), s + 0x10);
    func_003C2F58(*(void **)(s + 0x28), *(s32 *)(s + 0x2C) - 0x20, s);
    *(f32 *)(s + 0x24) = *(f32 *)(s + 0x24) + *(f32 *)(s + 0x20);
    *(Q_3B8B28 *)&start = *(Q_3B8B28 *)(m + 0x10);
    d.f[0] = *(f32 *)(s + 0) - *(f32 *)(s + 0x10);
    d.f[1] = *(f32 *)(s + 4) - *(f32 *)(s + 0x14);
    d.f[2] = *(f32 *)(s + 8) - *(f32 *)(s + 0x18);
    d.f[3] = *(f32 *)(s + 0xC);
    func_0038CF68(&d, &d, *(f32 *)(s + 0x24));
    *(f32 *)(m + 0x10) = *(f32 *)(s + 0x10) + d.f[0];
    *(f32 *)(m + 0x14) = *(f32 *)(s + 0x14) + d.f[1];
    *(f32 *)(m + 0x18) = *(f32 *)(s + 0x18) + d.f[2];
    *(f32 *)(m + 0x1C) = *(f32 *)(s + 0x1C);
    func_L01_00446748(coll, m, 1, 1.0f);
    *(u16 *)(coll + 0x1A) = *(u16 *)(m + 0xAA);
    hit = func_003D3CB0(&start, m + 0x10, 0, m, coll);
    if (hit == 0) {
        hit = func_L01_003FB640(m + 0x10, 0, m, 0.3f);
        if (hit == 0) goto distance;
    }
    h = D_L03_001E9218;
    if (h == 0) goto distance;
    t = *(s16 *)(h + 0xAA);
    if (t != 0x1C04 && t != 0x1C06) goto distance;
    if (t == 0x1C06) {
        func_L03_003ADF38(h);
        *(Q_3B8B28 *)&spark = *(Q_3B8B28 *)(m + 0x10);
        func_L03_003B8FA0(&spark, 0x14, 0xDD0044FF, 0xFF0010FF);
        {
            u8 *owner = *(u8 **)(m + 0xB8);
            if (owner != 0 && *(s16 *)(owner + 0xAA) == 0x1AE0) {
                func_L01_004AAC98(0xA, 0, owner, 0x1AE0);
            }
        }
        func_003C2880(m);
        return;
    }
    kind = *(s32 *)(*(u8 **)(h + 0x68) + 0x24);
    if (kind == 0 || kind == 3 || kind == 6) {
        *(Q_3B8B28 *)&spark = *(Q_3B8B28 *)(m + 0x10);
        func_L03_003B8FA0(&spark, 100, 0xDD0044FF, 0xFF0010FF);
        func_L01_004AAC98(4, 0, *(u8 **)(m + 0xB8), 0x1AE0);
    } else {
        func_L03_003ADF48(h);
        *(Q_3B8B28 *)&spark = *(Q_3B8B28 *)(m + 0x10);
        func_L03_003B8FA0(&spark, 100, 0x88202020, 0x88208020);
        func_L01_004AAC98(0xB, 0, *(u8 **)(m + 0xB8), 0x1AE0);
    }
    func_L01_00446780(m, m + 0x10, 0x10000, 0, 1, 0, 0.3f, 1.0f, 0.0f);
    func_003C2880(m);
    return;
distance:
    if (func_0038CF38(m + 0x10, s) <= *(f32 *)(s + 0x20) * 0.88f) {
        func_003C2880(m);
    } else {
        func_L03_003B8F10(m);
    }
}
/* localdecomp:end func_L03_003B8B28 */
