/* functional: medium. VU0 vsub/vadd.xyz as scalar math; signature (void*, s32) follows the file's earlier declaration. Not byte exact. */
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038CF38(void *, void *);
extern void func_0038CF68(f32 *, f32 *, f32);   /* as its file declares it */
extern void func_L01_0045A748(void *, void *);
extern void func_L01_0045C150(void *, void *, s32, s32);
s32 func_L01_0045BE38(void *a0, s32 a1) {
    u8 *self = (u8 *)a0;
    u8 *path = (u8 *)a1;
    f32 v[4] __attribute__((aligned(16)));
    f32 w[4] __attribute__((aligned(16)));
    f32 *sp = (f32 *)(self + 16);
    f32 *ei;
    f32 *other;
    f32 *ej;
    f32 lim, dist, thr, dotv;
    s32 i, j;
    u8 *s = (u8 *)func_L01_0045B958((M_4574A0 *)self);
    if (s == 0) {
        return 0;
    }
    if (path != *(u8 **)(s + 196) || (*(s32 *)(s + 156) & 4) != 0) {
        func_L01_0045C150(self, path, -1, 0);
    }
    i = *(s16 *)(s + 200);
    j = *(s16 *)(s + 202);
    if (i == j) {
        func_L01_0045A748(self, path + i * 16 + 16);
        return *(f32 *)(s + 204) <= *(f32 *)(s + 52);
    }
    if (j < i) {
        if (i < *(s32 *)path - 1) {
            other = (f32 *)(path + i * 16 + 32);
        } else {
            other = sp;
        }
    } else {
        if (i > 0) {
            other = (f32 *)(path + i * 16);
        } else {
            other = sp;
        }
    }
    ei = (f32 *)(path + i * 16 + 16);
    v[0] = ei[0] - other[0];
    v[1] = ei[1] - other[1];
    v[2] = ei[2] - other[2];
    v[3] = ei[3];
    if (*(u32 *)(s + 56) & 0x400) {
        func_0038CF68(v, v, 1.0f);
        ei = (f32 *)(path + (s32)*(s16 *)(s + 200) * 16 + 16);
        thr = func_0038CE68(v, ei) - *(f32 *)(s + 52);
        ej = (f32 *)(path + (s32)*(s16 *)(s + 202) * 16 + 16);
        dist = func_0038CF00(sp, ej);
    } else {
        v[2] = 0.0f;
        func_0038CF68(v, v, 1.0f);
        ei = (f32 *)(path + (s32)*(s16 *)(s + 200) * 16 + 16);
        ej = (f32 *)(path + (s32)*(s16 *)(s + 202) * 16 + 16);
        thr = (v[0] * ei[0] + v[1] * ei[1]) - *(f32 *)(s + 52);
        dist = func_0038CF38(sp, ej);
    }
    lim = *(f32 *)(s + 52) * 10.0f + 1.0f;
    if (dist < lim) {
        lim = dist;
    }
    ei = (f32 *)(path + (s32)*(s16 *)(s + 200) * 16 + 16);
    w[0] = ei[0] - sp[0];
    w[1] = ei[1] - sp[1];
    w[2] = ei[2] - sp[2];
    w[3] = ei[3];
    if ((*(u32 *)(s + 56) & 0x400) == 0) {
        w[2] = 0.0f;
    }
    func_0038CF68(w, w, lim);
    w[0] = w[0] + sp[0];
    w[1] = w[1] + sp[1];
    w[2] = w[2] + sp[2];
    func_L01_0045A748(self, w);
    if (*(u32 *)(s + 56) & 0x400) {
        dotv = func_0038CE68(v, sp);
    } else {
        dotv = v[0] * sp[0] + v[1] * sp[1];
    }
    if (thr <= dotv) {
        if (*(s16 *)(s + 202) < *(s16 *)(s + 200)) {
            *(s16 *)(s + 200) = *(u16 *)(s + 200) - 1;
        } else {
            *(s16 *)(s + 200) = *(u16 *)(s + 200) + 1;
        }
    }
    return 0;
}
