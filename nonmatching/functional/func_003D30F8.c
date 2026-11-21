/* functional: medium. VU0 closest-point-on-segment: dst.xyz = p0 + (p1-p0)*clamp(t,0,1), t = ((p1-p0).(p2-p0)) / |p1-p0|^2, dst.w = p0.w; returns the UNCLAMPED t in $f0 (qmfc2 of the vdiv result before vmini/vmax). Retail is hand-written VU0 asm (whole body lqc2/vadd/.../sqc2); this is plain-C semantics. VU divide never traps: x/0 gives 0x7FFFFFFF or 0xFFFFFFFF (the sign of x), not FLT_MAX: written explicitly (the fuzz gate found it). Operation order follows the VU lanes: (x*x+y*y)+z*z. Boundary: retail's final `sqc2 $vf1,0($4)` sits in the jr delay slot and is split off as func_003D3154 (4 bytes), so this function is really 0x60 bytes; VU rounding (round-toward-zero) differs from host IEEE in the last bit: the gate decides. */
typedef struct { f32 x, y, z, w; } V4_003D30F8;

f32 func_003D30F8(V4_003D30F8 *dst, V4_003D30F8 *p0, V4_003D30F8 *p1, V4_003D30F8 *p2)
{
    f32 ax = p1->x - p0->x, ay = p1->y - p0->y, az = p1->z - p0->z;
    f32 bx = p2->x - p0->x, by = p2->y - p0->y, bz = p2->z - p0->z;
    f32 den = (ax * ax + ay * ay) + az * az;
    f32 num = (ax * bx + ay * by) + az * bz;
    f32 t, s;
    f32 ox = p0->x, oy = p0->y, oz = p0->z, ow = p0->w;

    if (den == 0.0f) {
        /* VU0's vdiv by zero gives the largest magnitude its floats have, 0x7FFFFFFF (or
         * 0xFFFFFFFF), with the sign of the numerator, not IEEE's FLT_MAX */
        union { u32 u; f32 f; } big;
        big.u = (num < 0.0f) ? 0xFFFFFFFFu : 0x7FFFFFFFu;
        t = big.f;
    } else {
        t = num / den;
    }
    s = t;
    if (s > 1.0f) {
        s = 1.0f;
    }
    if (s < 0.0f) {
        s = 0.0f;
    }
    dst->x = ax * s + ox;
    dst->y = ay * s + oy;
    dst->z = az * s + oz;
    dst->w = ow;
    return t;
}
