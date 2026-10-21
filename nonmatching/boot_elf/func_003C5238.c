/* US draft of func_003C5238 (rac3-uya-decomp func_003C50D0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003C5238 */
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
/* localdecomp:end func_003C5238 */
