/* functional: medium. Argument roles (pts ring buffer, modulus, two textures, colours, start/end/count, widths) read from the retail register/stack use and the caller func_L39_00564498; vadd/vsub.xyz w lanes follow the destination register as retail does; 448 byte diffs are codegen/stack layout. */
#include "common.h"
extern s32 D_00241118[];
extern f32 D_0024DE80[];
void func_003D93B0(void *, s32, s32, s32);
void func_0038CE90(void *, void *, void *);
void func_0038CF68(void *, void *, f32);
void func_0038CE20(void *, void *, f32);
f32 func_0038CEA8(void *);
s32 func_0038DBD8(s32, s32, f32);
void func_003D2DA0(void *, void *, s32);
void func_003A9440(s32, unsigned long);

static void bf148_v4(f32 *d, f32 *a, f32 *b, s32 sub, f32 w) {
    if (sub) {
        d[0] = a[0] - b[0]; d[1] = a[1] - b[1]; d[2] = a[2] - b[2];
    } else {
        d[0] = a[0] + b[0]; d[1] = a[1] + b[1]; d[2] = a[2] + b[2];
    }
    d[3] = w;
}
static void bf148_c4(f32 *d, f32 *s) {
    f32 a = s[0], b = s[1], c = s[2], e = s[3];
    d[0] = a; d[1] = b; d[2] = c; d[3] = e;
}

void func_L39_00564800(void *pts_, s32 n, s32 texA, s32 texB, s32 colA, s32 colAmask,
                       s32 colBmix, s32 colB, s32 start, s32 end, s32 count,
                       f32 width, f32 halfw, f32 ext) {
    f32 (*pts)[4] = pts_;
    u8 q1[0x90];
    u8 q2[0x90];
    f32 P[4];
    f32 d140[4], d150[4], S[4], d180[4], d190[4], s1B0[4], s1C0[4], tmp[4];
    f32 A[4], B[4], X[4], d1A0[4], W[4];
    f32 *v1 = (f32 *)q1;
    f32 *v2 = (f32 *)q2;
    f32 *uv;
    s32 j, prev, col;
    f32 step, t, len0, len1, k;
    f32 *tv;

    *(s32 *)(q1 + 0x70) = 0;
    func_003D93B0(q1, texA, 1, 0x80);
    *(s32 *)(q1 + 0x4C) = colAmask;
    *(s32 *)(q1 + 0x48) = colAmask;
    *(s32 *)(q1 + 0x44) = colAmask;
    *(s32 *)(q1 + 0x40) = colAmask;
    uv = (f32 *)(q1 + 0x50);
    uv[0] = 0.0f; uv[1] = 0.0f; uv[2] = 0.0f; uv[3] = 1.0f;
    uv[4] = 1.0f; uv[5] = 0.0f; uv[6] = 1.0f; uv[7] = 1.0f;
    func_003D93B0(q2, texB, 1, 0x80);
    *(s32 *)(q2 + 0x4C) = colB;
    *(s32 *)(q2 + 0x48) = colB;
    *(s32 *)(q2 + 0x44) = colB;
    *(s32 *)(q2 + 0x40) = colB;
    uv = (f32 *)(q2 + 0x50);
    uv[0] = 0.0f; uv[1] = 0.0f; uv[2] = 0.0f; uv[3] = 1.0f;
    uv[4] = 1.0f; uv[5] = 0.0f; uv[6] = 1.0f; uv[7] = 1.0f;

    count = count - 1;
    j = (start + 1) % n;
    tv = D_0024DE80 + D_00241118[0] * 0x118;
    bf148_c4(P, pts[start]);
    bf148_v4(d140, pts[start], tv, 1, pts[start][3]);
    bf148_v4(d150, pts[j], P, 1, pts[j][3]);
    func_0038CE90(S, d150, d140);
    func_0038CF68(S, S, width);
    step = 1.0f / (f32)count;
    t = step;
    bf148_v4(v1 + 0, P, S, 0, S[3]);
    bf148_v4(v1 + 4, P, S, 1, S[3]);
    prev = start;
    if (j != end) {
        do {
            f32 *pj = pts[j];
            tv = D_0024DE80 + D_00241118[0] * 0x118;
            bf148_v4(d140, pj, tv, 1, pj[3]);
            bf148_v4(d150, pj, pts[prev], 1, pj[3]);
            func_0038CE90(S, d150, d140);
            func_0038CF68(S, S, width);
            bf148_v4(v1 + 8, pj, S, 0, pj[3]);
            bf148_v4(v1 + 12, pj, S, 1, pj[3]);
            col = func_0038DBD8(colAmask, colA, t);
            t = t + step;
            *(s32 *)(q1 + 0x48) = col;
            *(s32 *)(q1 + 0x4C) = col;
            func_003D2DA0(q1, 0, 0);
            bf148_c4(v1 + 4, v1 + 12);
            bf148_c4(v1 + 0, v1 + 8);
            col = *(s32 *)(q1 + 0x48);
            *(s32 *)(q1 + 0x40) = col;
            *(s32 *)(q1 + 0x44) = col;
            prev = j;
            j = (j + 1) % n;
        } while (j != end);
    }

    j = (start + 1) % n;
    t = step;
    tv = D_0024DE80 + D_00241118[0] * 0x118;
    bf148_v4(d190, pts[start], tv, 1, pts[start][3]);
    len0 = func_0038CEA8(d190);
    if (j != end) {
        do {
            f32 *pj = pts[j];
            tv = D_0024DE80 + D_00241118[0] * 0x118;
            bf148_v4(d180, pj, tv, 1, pj[3]);
            len1 = func_0038CEA8(d180);
            if (len0 < len1) {
                if (len0 == 0.0f) bf148_c4(s1B0, d180);
                else func_0038CE20(s1B0, d190, len1 / len0);
                tv = D_0024DE80 + D_00241118[0] * 0x118;
                bf148_v4(A, tv, d180, 0, tv[3]);
                bf148_v4(B, tv, s1B0, 0, s1B0[3]);
            } else {
                if (len1 == 0.0f) bf148_c4(s1C0, d190);
                else func_0038CE20(s1C0, d180, len0 / len1);
                tv = D_0024DE80 + D_00241118[0] * 0x118;
                bf148_v4(A, tv, s1C0, 0, tv[3]);
                bf148_v4(B, tv, d190, 0, d190[3]);
            }
            bf148_v4(d150, B, A, 1, B[3]);
            len0 = len1;
            func_0038CE20(X, d150, ext);
            bf148_v4(A, A, X, 1, A[3]);
            tv = D_0024DE80 + D_00241118[0] * 0x118;
            bf148_v4(B, B, X, 0, B[3]);
            bf148_v4(d1A0, tv, A, 1, tv[3]);
            func_0038CE90(S, d1A0, d150);
            func_0038CF68(W, S, halfw);
            bf148_v4(v2 + 0, A, W, 0, A[3]);
            bf148_v4(v2 + 4, A, W, 1, A[3]);
            bf148_v4(v2 + 8, B, W, 0, B[3]);
            bf148_v4(v2 + 12, B, W, 1, B[3]);
            col = func_0038DBD8(colB, colBmix, t);
            t = t + step;
            *(s32 *)(q2 + 0x48) = col;
            *(s32 *)(q2 + 0x4C) = col;
            func_003D2DA0(q2, 0, 0);
            bf148_c4(d190, d180);
            col = *(s32 *)(q2 + 0x48);
            *(s32 *)(q2 + 0x40) = col;
            *(s32 *)(q2 + 0x44) = col;
            j = (j + 1) % n;
        } while (j != end);
    }
    func_003A9440(0x47, 0x5360B);
}
