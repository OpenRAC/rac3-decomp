/* functional: medium. Draws a textured ribbon (beam/trail) through n points: two 4-vertex packets per segment (a core quad and a longer glow quad), widths/colours interpolated by how close each end is to a moving wavefront (state 3: |t - dist/1.1| < pv+0xCC, state 2: dist < pv+0xCC), vertices offset sideways by cross(segment, view). VU0 xyz-masked adds/subs are small static helpers (w from first operand); vu0.h cannot be used because the file lacks -mvu0-use-vf0-vf2. In the retail the colours set before the first setlen call are overwritten before the draw (kept). Float lerp func_003C4088 arg order (a,b,t) assumed from the call pattern. */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) vu0_v4;
/* d = a (op) b on x,y,z; w is taken from a, as the VU0 xyz-masked ops leave it */
static void v3add_00335898(void *d, void *a, void *b) {
    vu0_v4 r = *(vu0_v4 *)a;
    r.x = r.x + ((vu0_v4 *)b)->x;
    r.y = r.y + ((vu0_v4 *)b)->y;
    r.z = r.z + ((vu0_v4 *)b)->z;
    *(vu0_v4 *)d = r;
}
static void v3sub_00335898(void *d, void *a, void *b) {
    vu0_v4 r = *(vu0_v4 *)a;
    r.x = r.x - ((vu0_v4 *)b)->x;
    r.y = r.y - ((vu0_v4 *)b)->y;
    r.z = r.z - ((vu0_v4 *)b)->z;
    *(vu0_v4 *)d = r;
}
typedef struct {
    vu0_v4 v[4];
    u32 col[4];
    f32 uv[4][2];
    long w70, w78, w80, w88;
} Pkt_00335898;
extern vu0_v4 D_L19_001E2080[];
extern vu0_v4 D_L19_00276E50[];
extern void func_L19_00336088(u8 *, s32, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CEA8(void *);
extern f32 func_003C4088(f32, f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_003D2DA0(void *, s32, s32);
extern void func_003A9440(s32, unsigned long);

void func_L19_00335898(void *arg0, E_003357A0 *arg1, s32 n, s32 a3, s32 a4, s32 a5, s32 a6, f32 fa, f32 fb, f32 fc, f32 fd, f32 fe) {
    u8 *obj = (u8 *)arg0;
    u8 *pv = *(u8 **)(obj + 0x68);
    vu0_v4 *pt = (vu0_v4 *)arg1;
    Pkt_00335898 A, B;
    vu0_v4 P, d160, d130, dir, mid, seg, nrm;
    f32 t = 0.0f;
    f32 wA, wB, len, scale, dist, cc, x;
    s32 colA0, colA1, colB0, colB1;
    s32 i, j;

    func_L19_00336088((u8 *)&A, *(s32 *)(pv + 0x9C), 1, a3);
    A.w70 = 0;
    for (j = 0; j < 4; j++) {
        A.uv[j][0] = A.uv[j][0] + *(f32 *)(pv + 0x84);
    }
    func_L19_00336088((u8 *)&B, *(s32 *)(pv + 0x80), 1, a5);
    P = *(vu0_v4 *)(obj + 0x10);
    P.z = P.z + 1.1f;
    B.w70 = 0;
    if (obj[0x20] == 3) {
        cc = *(f32 *)(pv + 0xCC);
        x = (f32)*(s32 *)(pv + 0x24) / (f32)*(s32 *)(pv + 0x1C);
        t = (2.0f * cc + 1.0f) * (1.0f - x) - cc;
        if (1.0f - cc < t) {
            if (*(s32 *)(pv + 0x3C) & 2) {
                func_0038CF68(&d160, D_L19_00276E50, *(f32 *)(pv + 0xD0));
                v3add_00335898(obj + 0x10, pv, &d160);
            }
        }
    }
    for (i = 0; i < n - 1; i++) {
        wA = 0.0f;
        wB = 0.0f;
        if (obj[0x20] == 3) {
            v3sub_00335898(&d160, &P, &pt[i]);
            dist = func_0038CEA8(&d160) / 1.1f;
            cc = *(f32 *)(pv + 0xCC);
            x = t - dist;
            if (x < 0.0f) x = -x;
            if (x < cc) {
                wA = 1.0f - x / cc;
            }
            v3sub_00335898(&d160, &P, &pt[i + 1]);
            dist = func_0038CEA8(&d160) / 1.1f;
            cc = *(f32 *)(pv + 0xCC);
            x = t - dist;
            if (x < 0.0f) x = -x;
            if (x < cc) {
                wB = 1.0f - x / cc;
            }
        } else if (obj[0x20] == 2) {
            v3sub_00335898(&d160, &P, &pt[i]);
            dist = func_0038CEA8(&d160) / 1.1f;
            cc = *(f32 *)(pv + 0xCC);
            if (dist < cc) {
                x = (f32)*(s32 *)(pv + 0x24) / (f32)*(s32 *)(pv + 0x18);
                wA = (1.0f - dist / cc) * (1.0f - x);
            }
            v3sub_00335898(&d160, &P, &pt[i + 1]);
            dist = func_0038CEA8(&d160) / 1.1f;
            cc = *(f32 *)(pv + 0xCC);
            if (dist < cc) {
                wB = 1.0f - dist / cc;
            }
        }
        colA0 = func_0038DBD8(a3, a4, wA);
        colB0 = func_0038DBD8(a5, a6, wA);
        x = func_003C4088(fa, fb, wA);
        {
            f32 y = func_003C4088(fc, fd, wA);
            colA1 = func_0038DBD8(a3, a4, wB);
            colB1 = func_0038DBD8(a5, a6, wB);
            wA = func_003C4088(fa, fb, wB);
            wB = func_003C4088(fc, fd, wB);
            scale = 1.0f;
            if (*(s32 *)(pv + 0x3C) & 4) {
                v3sub_00335898(&d130, &pt[i], &P);
                dist = func_0038CEA8(&d130);
                if (dist < *(f32 *)(pv + 0xB0)) {
                    scale = *(f32 *)(pv + 0xAC) * (1.0f - dist / *(f32 *)(pv + 0xB0)) + scale;
                }
            }
            mid = pt[i];
            seg = pt[i + 1];
            v3sub_00335898(&dir, &mid, D_L19_001E2080);
            v3sub_00335898(&seg, &seg, &pt[i]);
            d130 = seg;
            len = func_0038CEA8(&d130);
            func_0038CE90(&nrm, &d130, &dir);
            A.col[0] = colA0;
            A.col[3] = colA0;
            A.col[2] = colA0;
            A.col[1] = colA0;
            func_0038CF68(&nrm, &nrm, scale * x * len);
            v3add_00335898(&A.v[0], &pt[i], &nrm);
            v3sub_00335898(&A.v[1], &pt[i], &nrm);
            A.col[0] = colA1;
            A.col[3] = colA1;
            A.col[2] = colA1;
            A.col[1] = colA1;
            func_0038CF68(&nrm, &nrm, scale * wA * len);
            v3add_00335898(&A.v[2], &pt[i + 1], &nrm);
            v3sub_00335898(&A.v[3], &pt[i + 1], &nrm);
            func_003D2DA0(&A, 0, 0);
            B.col[0] = colB0;
            B.col[3] = colB0;
            B.col[2] = colB0;
            B.col[1] = colB0;
            func_0038CF68(&nrm, &nrm, scale * y * len);
            v3add_00335898(&B.v[0], &pt[i], &nrm);
            v3sub_00335898(&B.v[1], &pt[i], &nrm);
            B.col[0] = colB1;
            B.col[3] = colB1;
            B.col[2] = colB1;
            B.col[1] = colB1;
            func_0038CF68(&nrm, &nrm, scale * wB * len);
            v3add_00335898(&B.v[2], &pt[i + 1], &nrm);
            v3sub_00335898(&B.v[3], &pt[i + 1], &nrm);
            func_0038CE20(&d130, &d130, fe);
            v3sub_00335898(&B.v[0], &B.v[0], &d130);
            v3sub_00335898(&B.v[1], &B.v[1], &d130);
            v3add_00335898(&B.v[2], &B.v[2], &d130);
            v3add_00335898(&B.v[3], &B.v[3], &d130);
            func_003D2DA0(&B, 0, 0);
        }
    }
    func_003A9440(0x47, 0x5360B);
}
