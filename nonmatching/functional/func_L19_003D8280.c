/* functional: medium-high. Written from the asm; compiles in context (586 diff, frame size 0x130 equal; retail uses lqc2 for the d vector, here plain floats; the d.w lane is kept). Death-effect block mirrors the matched siblings func_L19_003D7F80/003D8BC0 (gp floats D_L19_001DED00.. = $gp+0x2450..0x2468; D_L19_001DED08 is an s32). Unverified: exact meaning of func_0038CE90/func_L01_0040EE50/func_0038D000 as a 3-row matrix build + rotate (called as retail does). */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3D8280;
__asm__(".extern D_L19_001DED00, 4");
extern f32 D_L19_001DED00;
__asm__(".extern D_L19_001DED04, 4");
extern f32 D_L19_001DED04;
__asm__(".extern D_L19_001DED08, 4");
extern s32 D_L19_001DED08;
__asm__(".extern D_L19_001DED0C, 4");
extern f32 D_L19_001DED0C;
__asm__(".extern D_L19_001DED10, 4");
extern f32 D_L19_001DED10;
__asm__(".extern D_L19_001DED14, 4");
extern f32 D_L19_001DED14;
__asm__(".extern D_L19_001DED18, 4");
extern f32 D_L19_001DED18;
extern V4_3D8280 D_001A4C60;
extern u8 D_001A30B0[];
extern f32 func_0038CE68(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0040EE50(void *, void *);
extern f32 func_003824E0(f32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003A4F28(s32);
extern s32 func_L02_003E6F38(f32, f32, f32);
extern void func_L19_003D81D0(u8 *);

static void snd_stop_3D8280(u8 *obj) {
    s32 h = *(s32 *)(obj + 0x48);
    u8 *s;
    if (h != -1 && (s = D_001A30B0 + (h << 7), *(u8 **)(s + 0xDC) == obj) && s[0xD0] != 0)
        func_003A4F28(h);
    *(s32 *)(obj + 0x48) = -1;
}

static void snd_ensure_3D8280(u8 *obj) {
    s32 h = *(s32 *)(obj + 0x48);
    u8 *s;
    if (h == -1 || (s = D_001A30B0 + (h << 7), *(u8 **)(s + 0xDC) != obj) || s[0xD0] == 0)
        *(s32 *)(obj + 0x48) = func_003A52A0(1, 4, obj);
}

void func_L19_003D8280(u8 *obj) {
    V4_3D8280 d;
    V4_3D8280 m[3];
    V4_3D8280 r;
    V4_3D8280 q;
    f32 dist;
    f32 step;
    f32 v;
    f32 lim;
    f32 old;
    f32 t;
    f32 sc;
    u8 *p;

    d.x = D_001A4C60.x - *(f32 *)(obj + 0x10);
    d.y = D_001A4C60.y - *(f32 *)(obj + 0x14);
    d.z = D_001A4C60.z - *(f32 *)(obj + 0x18);
    d.w = D_001A4C60.w;

    switch (obj[0x20]) {
    case 0:
        *(s32 *)(obj + 0x48) = -1;
        *(u16 *)(obj + 0x34) |= 0x100;
        *(V4_3D8280 *)(obj + 0xF0) = *(V4_3D8280 *)(obj + 0xC0);
        v = func_003824E0(-D_L19_001DED0C, D_L19_001DED0C);
        *(f32 *)(obj + 0xFC) = v;
        func_L01_004450F0(obj, v < 0.0f ? 2 : 1, -1);
        break;
    case 1:
        if ((D_L19_001DED08 * 5 + 2) / 6 < *(u16 *)(obj + 0x96)) {
            snd_ensure_3D8280(obj);
            step = (D_L19_001DED10 * 5.0f + 2.0f) / 6.0f;
            v = *(f32 *)(obj + 0xFC) - step;
            *(f32 *)(obj + 0xFC) = v;
            if (v < -D_L19_001DED0C) {
                snd_stop_3D8280(obj);
                *(f32 *)(obj + 0xFC) = -D_L19_001DED0C;
                func_L01_004450F0(obj, 2, -1);
            }
        }
        break;
    case 2:
        if ((D_L19_001DED08 * 5 + 2) / 6 < *(u16 *)(obj + 0x96)) {
            snd_ensure_3D8280(obj);
            step = (D_L19_001DED10 * 5.0f + 2.0f) / 6.0f;
            v = *(f32 *)(obj + 0xFC) + step;
            *(f32 *)(obj + 0xFC) = v;
            if (D_L19_001DED0C < v) {
                snd_stop_3D8280(obj);
                *(f32 *)(obj + 0xFC) = D_L19_001DED0C;
                func_L01_004450F0(obj, 1, -1);
            }
        }
        break;
    case 3:
        if ((D_L19_001DED08 * 5 + 2) / 6 < *(u16 *)(obj + 0x96)) {
            m[2] = *(V4_3D8280 *)(obj + 0xE0);
            m[0] = *(V4_3D8280 *)(obj + 0xF0);
            old = *(f32 *)(obj + 0xFC);
            func_0038CE90(&m[1], &m[2], &m[0]);
            func_L01_0040EE50(&m[0], &m[0]);
            func_0038D000(&r, &d, &m[0]);
            r.z = 0.0f;
            func_0038CF68(&r, &r, 1.0f);
            if (r.x < 0.0f) {
                if (r.y < 0.0f)
                    lim = -D_L19_001DED0C;
                else
                    lim = D_L19_001DED0C;
            } else {
                t = r.y * 180.0f / 3.1415927f;
                if (t < -D_L19_001DED0C)
                    lim = -D_L19_001DED0C;
                else if (D_L19_001DED0C < t)
                    lim = D_L19_001DED0C;
                else
                    lim = t;
            }
            v = *(f32 *)(obj + 0xFC);
            step = (D_L19_001DED10 * 5.0f + 2.0f) / 6.0f;
            if (lim < v) {
                v = v - step;
                *(f32 *)(obj + 0xFC) = v;
                if (v < lim)
                    *(f32 *)(obj + 0xFC) = lim;
            } else {
                v = v + step;
                *(f32 *)(obj + 0xFC) = v;
                if (lim < v)
                    *(f32 *)(obj + 0xFC) = lim;
            }
            if (func_L02_003E6F38(old, *(f32 *)(obj + 0xFC), 0.01f) != 0)
                snd_stop_3D8280(obj);
            else
                snd_ensure_3D8280(obj);
        }
        break;
    }
    d.z = 0.0f;
    dist = func_0038CE68(&d, &d);
    if (obj[0x20] == 3) {
        if (D_L19_001DED18 < dist) {
            snd_stop_3D8280(obj);
            func_L01_004450F0(obj, 0.0f < *(f32 *)(obj + 0xFC) ? 1 : 2, -1);
        }
    } else if (dist < D_L19_001DED14) {
        func_L01_004450F0(obj, 3, -1);
        snd_stop_3D8280(obj);
    }
    func_L19_003D81D0(obj);
    if (*(u16 *)(obj + 0x96) <= 0xFFFE)
        (*(u16 *)(obj + 0x96))++;
    if (func_L01_00447490(obj, -1, 0) != 0) {
        snd_stop_3D8280(obj);
        func_003A52A0(0, 0, obj);
        func_L01_00451FE0(obj, 0x1F, &D_L19_001D66F0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f,
                          1.0f, 0, 3);
        p = *(u8 **)(obj + 0x24);
        sc = 1.0f / *(f32 *)(p + 0x24);
        r.x = 0.1f;
        r.y = 0.0f;
        r.z = 0.4f;
        r.w = 0.0f;
        func_0038CE20(&r, &r, sc);
        q.x = 0.0f;
        q.y = 0.0f;
        q.z = -0.14000002f;
        q.w = 0.0f;
        func_L02_003E2E38(obj, &r, 0.1f, &q, 0x14, 0, 0.18f, D_L19_001DED04 * sc * *(f32 *)(obj + 0x2C), 20.0f, 1.0f, 0);
        func_0038CE20(&r, &r, *(f32 *)(obj + 0x2C));
        func_0038D000(&r, &r, obj + 0xC0);
        r.x += *(f32 *)(obj + 0x10);
        r.y += *(f32 *)(obj + 0x14);
        r.z += *(f32 *)(obj + 0x18);
        func_L01_003303B8(&r, 0, 0, 0, 0, 2, 5, 0, D_L19_001DED00 * sc * *(f32 *)(obj + 0x2C), 0.0f, 0.0f, 0.0f,
                          0, 1, 0, 0, 0, 0, 0x01000000, 0, 0x27B2F3, 0xBDFFF, 0, 0, 0, 0, 0x7F27B2F3, 0x280BDFFF, 0, 0);
        func_L01_00451E78(obj, 1, 0.0f);
        func_003C2880(obj);
    }
}
