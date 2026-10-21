/* US draft of func_003C6368 (rac3-uya-decomp func_003C0E10, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_003C6368 */
typedef int Q_3C0E10 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3C0E10;
typedef struct { u8 p0[0x10]; V_3C0E10 pos; } O_3C0E10;
typedef struct { u8 p0[0x46]; u8 b46; } P_3C0E10;
typedef struct { u8 p0[0x10]; f32 f10; f32 f14; u8 p18[0xC]; P_3C0E10 *f24; } E_3C0E10;
extern E_3C0E10 *D_0022B6C0[];
extern s32 func_003D4D00(void *, s32, void *, s32, f32);
extern s32 func_003C4B50();
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CED8(f32 *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CF68(void *, void *, f32);
s32 func_003C6368(void *, f32 *, f32 *, f32, f32, f32);
s32 func_003C6368(void *o, f32 *out, f32 *v, f32 a, f32 lim, f32 unused) {
    O_3C0E10 *obj = (O_3C0E10 *)o;
    f32 t[4] __attribute__((aligned(16)));
    f32 u[4] __attribute__((aligned(16)));
    f32 arr[16];
    f32 ang, d;
    s32 n, i, cnt;
    *(Q_3C0E10 *)out = *(Q_3C0E10 *)v;
    *(Q_3C0E10 *)t = *(Q_3C0E10 *)v;
    t[2] = 0.0f;
    func_0038CF68(t, t, a);
    __asm__(
        "lqc2 $vf2, %1\n"
        "lqc2 $vf1, %2\n"
        "vadd.xyz $vf1, $vf1, $vf2\n"
        "sqc2 $vf1, %0\n"
        : "=m"(*(V_3C0E10 *)u) : "m"(*(V_3C0E10 *)t), "m"(obj->pos));
    ang = func_0038D160(t[0], t[1]);
    n = func_003D4D00(u, 0, obj, 0, a);
    if (n != 0) {
    cnt = 0;
    for (i = 0; i < n && i < 16; i++) {
        if (func_003C4B50(D_0022B6C0[i]) != 0 || (D_0022B6C0[i]->f24 != 0 && D_0022B6C0[i]->f24->b46 == 0x16)) {
            d = func_0038D160(D_0022B6C0[i]->f10 - obj->pos.x, D_0022B6C0[i]->f14 - obj->pos.y);
            if (func_0038DBA0(ang, d) < lim) {
                arr[cnt++] = d;
            }
        }
    }
    if (cnt != 0) {
        s32 j, k;
        for (j = 0; j < cnt - 1; j++) {
            s32 jj = j + 1;
            for (k = 0; k < cnt - jj; k++) {
                if (arr[k + 1] < arr[k]) {
                    f32 tmp = arr[k];
                    arr[k] = arr[k + 1];
                    arr[k + 1] = tmp;
                }
            }
        }
        d = arr[cnt >> 1];
        ang = func_0038CED8(out);
        out[0] = func_0038D098(d) * ang;
        out[1] = func_0038D0B0(d) * ang;
    }
    return 1;
    }
    return 0;
}
/* localdecomp:end func_003C6368 */
