/* functional: high. Verified vs asm: max(|x|,|y|,|z|), n=(s32)(m*10000/63) clamped to 1..255 (255 first, then 1), scale 1/(n*1e-4), components x*s+127.0, packed by func_0038D438(float[4]) into *b. abs.s inline asm is the allowed fabs macro form. 28 words differ (scheduling). */
extern s32 func_0038D438(f32 *);
void func_003C5238(void *a, void *b) {
    f32 *v = (f32 *)a;
    f32 t[4];
    f32 x, y, z, ax, ay, az, m, s;
    s32 n;
    x = v[0];
    y = v[1];
    z = v[2];
    __asm__("abs.s %0, %1" : "=f"(ax) : "f"(x));
    __asm__("abs.s %0, %1" : "=f"(ay) : "f"(y));
    __asm__("abs.s %0, %1" : "=f"(az) : "f"(z));
    if (ay < ax) ay = ax;
    m = ay;
    m = (az < m) ? m : az;
    n = (s32)(m * 10000.0f / 63.0f);
    if (n >= 256) n = 255;
    if (n <= 0) n = 1;
    t[3] = n;
    s = 1.0f / (t[3] * 0.0001f);
    t[0] = x * s + 127.0f;
    t[1] = y * s + 127.0f;
    t[2] = z * s + 127.0f;
    *(s32 *)b = func_0038D438(t);
}
