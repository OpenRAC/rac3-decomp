/* functional: high. Builds the neighbour graph of the entry table D_L40_002926E0: for every entry pair within distance 40 that passes three visibility tests (centre line and the two lines offset by +-0.5 along diff x up), links them via func_L40_004903C8 with their distance; then for every entry computes the min/max z of its linked neighbours (+-5.0) into f14/f18 and its max link distance + 2.0 into f10. The VU0 vector ops (lqc2/vsub.xyz/vadd.xyz) are written as plain float math keeping w from the first operand; it compiles. */
typedef struct V4_00490080 {
    float x, y, z, w;
} V4_00490080 __attribute__((aligned(16)));

typedef struct S_00490080 {
    V4_00490080 pos;
    float f10;
    float f14;
    float f18;
    int i1C;
    short h20[8];
    unsigned char pad30[0x30];
} S_00490080 __attribute__((aligned(16)));

extern int D_L40_00248628;
extern S_00490080 D_L40_002926E0[];
extern float func_0038CF38(void *, void *);
extern float func_0038CF00(void *, void *);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, float);
extern int func_L39_005BEAF8(void *, void *, int);
extern void func_L40_004903C8(int, int, float);

void func_L40_00490080(void) {
    V4_00490080 up;
    V4_00490080 out;
    V4_00490080 diff;
    V4_00490080 pa;
    V4_00490080 pb;
    S_00490080 *a;
    S_00490080 *b;
    float lo;
    float hi;
    float z;
    int i;
    int j;
    int cnt;
    int k;

    for (i = 0; i < D_L40_00248628; i++) {
        a = &D_L40_002926E0[i];
        for (j = i + 1; j < D_L40_00248628; j++) {
            b = &D_L40_002926E0[j];
            if (40.0f < func_0038CF38(a, b)) {
                continue;
            }
            if (!func_L39_005BEAF8(a, b, 0)) {
                continue;
            }
            up.x = 0.0f;
            up.y = 0.0f;
            up.z = 1.0f;
            up.w = 0.0f;
            diff.x = a->pos.x - b->pos.x;
            diff.y = a->pos.y - b->pos.y;
            diff.z = a->pos.z - b->pos.z;
            diff.w = a->pos.w;
            func_0038CE90(&out, &diff, &up);
            func_0038CF68(&out, &out, 0.5f);
            pa.x = a->pos.x + out.x;
            pa.y = a->pos.y + out.y;
            pa.z = a->pos.z + out.z;
            pa.w = a->pos.w;
            pb.x = b->pos.x + out.x;
            pb.y = b->pos.y + out.y;
            pb.z = b->pos.z + out.z;
            pb.w = b->pos.w;
            if (!func_L39_005BEAF8(&pa, &pb, 0)) {
                continue;
            }
            pa.x = a->pos.x - out.x;
            pa.y = a->pos.y - out.y;
            pa.z = a->pos.z - out.z;
            pa.w = a->pos.w;
            pb.x = b->pos.x - out.x;
            pb.y = b->pos.y - out.y;
            pb.z = b->pos.z - out.z;
            pb.w = b->pos.w;
            if (func_L39_005BEAF8(&pa, &pb, 0)) {
                func_L40_004903C8(i, j, func_0038CF00(a, b));
            }
        }
    }
    for (i = 0; i < D_L40_00248628; i++) {
        a = &D_L40_002926E0[i];
        lo = a->pos.z;
        hi = lo;
        cnt = 0;
        k = a->h20[0];
        if (k != -1) {
            while (1) {
                float d = func_0038CF00(a, &D_L40_002926E0[k]);
                if (a->f10 < d) {
                    a->f10 = d;
                }
                z = D_L40_002926E0[k].pos.z;
                if (z < lo) {
                    lo = z;
                } else if (hi < z) {
                    hi = z;
                }
                cnt++;
                if (cnt >= 8) {
                    break;
                }
                k = a->h20[cnt];
                if (k == -1) {
                    break;
                }
            }
        }
        a->f14 = lo - 5.0f;
        a->f18 = hi + 5.0f;
        a->f10 = a->f10 + 2.0f;
    }
}
