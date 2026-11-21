/* functional: high. Read block by block against the PAL asm; only scheduling around the VU0 vsub block differs (9 words). */
#include "common.h"
f32 func_L01_00476750(Vec4 *out, Vec4 *point, Vec4 *a, Vec4 *b) {
    extern void func_0038CFB8(Vec4 *, Vec4 *, f32);
    extern f32 func_0038CE68(Vec4 *, Vec4 *);
    extern void func_0038CF38(Vec4 *, Vec4 *);
    Vec4 delta, normal, start;
    Vec4 *n = &normal;
    f32 d, t;
    s32 i;
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(delta) : "m"(*a), "m"(*b) : "vf1", "vf2");
    start.q = a->q;
    normal.f[1] = delta.f[0];
    normal.f[2] = 0;
    normal.f[0] = -delta.f[1];
    start.f[2] = 0;
    func_0038CFB8(n, n, 1.0f);
    d = -func_0038CE68(n, &start);
    t = d + (normal.f[0] * point->f[0] + normal.f[1] * point->f[1]);
    out->f[0] = point->f[0] - t * normal.f[0];
    out->f[1] = point->f[1] - t * normal.f[1];
    out->f[2] = 0;
    {
    f32 *ap, *op, *bp;
    i=0; bp=b->f; op=out->f; ap=a->f;
    do {
        if (*ap+0.001f < *op && *bp+0.001f < *op) break;
        if (*op < *ap-0.001f && *op < *bp-0.001f) break;
        i++; bp++; op++; ap++;
    } while(i<2);
    }
    if(i<2) {
        f32 dist = ((f32 (*)(Vec4 *, Vec4 *))func_0038CF38)(out,a);
        if(dist < ((f32 (*)(Vec4 *, Vec4 *))func_0038CF38)(out,b)) out->q=a->q;
        else out->q=b->q;
        out->f[2]=0;
    }
    return ((f32 (*)(Vec4 *, Vec4 *))func_0038CF38)(point,out);
}
