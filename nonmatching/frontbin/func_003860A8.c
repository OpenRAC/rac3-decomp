/* US draft of func_003860A8 (rac3-uya-decomp func_00381DD0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003860A8 */
typedef struct { u8 p0[0x140]; f32 f140, f144, f148; } S_222340_381DD0;
typedef struct { u8 p0[0x1A0]; f32 f1A0, f1A4; u8 p1A8[0x220 - 0x1A8]; f32 f220; } S_225980_381DD0;
extern S_222340_381DD0 D_002222C0_003860A8;
extern S_225980_381DD0 D_00225900_003860A8;
extern void func_0038D2A0();
extern void func_0038D640();
extern void func_0038CE20(f32 *, void *, f32);
extern void func_0038D028();
void func_003860A8(f32 *out, void *arg1) {
    f32 m[16];
    f32 r[16];
    f32 v[4];
    f32 w[4];
    f32 t;
    func_0038D2A0(m);
    m[12] = -D_002222C0_003860A8.f140 * 1024.0f;
    m[13] = -D_002222C0_003860A8.f144 * 1024.0f;
    m[14] = -D_002222C0_003860A8.f148 * 1024.0f;
    func_0038D640(r, (u8 *)&D_002222C0_003860A8 + 0x40, m);
    func_0038CE20(v, arg1, 1024.0f);
    v[3] = 1.0f;
    func_0038D028(w, v, r);
    t = D_00225900_003860A8.f220 / w[3];
    w[0] = w[0] * t + D_00225900_003860A8.f1A0;
    w[1] = w[1] * t + D_00225900_003860A8.f1A4;
    out[2] = w[2] * 0.0009765625f;
    out[1] = w[1] * 16.0f;
    out[0] = w[0] * 16.0f;
}
/* localdecomp:end func_003860A8 */
