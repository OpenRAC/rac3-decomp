/* functional: medium. Draft verified against PAL asm (GS state constants, vertex build, uv/colour loop all match); retail reads the 'previous' vector at sp+0x10 that nothing writes (uninitialised stack), the C reads an unassigned local too; loop forms differ (159 diff). */
#include "vu0.h"
typedef struct { f32 x, y, z; } Point_003AD210;
extern vu0_v4 D_L07_001E1EC0[];
extern Point_003AD210 D_L07_002A22E0[];
extern f32 D_L07_001E1678[];
extern u32 D_L07_002A23D0[][2];
extern vu0_v4 D_L07_002A2420[];
void func_L07_003AD210(void *object, void *points, s32 count, s32 start, s32 texture)
{
    extern void func_0038C750(void);
    extern unsigned long func_00389598(s32);
    extern void func_003A9440(s32, unsigned long);
    extern f32 func_0038CEA8(void *);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern u32 func_0038DBD8(u32, u32, f32);
    extern void func_003D3A24(s32, void *, void *, void *, s32);
    vu0_v4 delta, previous, normal, view, cross, temp;
    f32 length, fraction, inv;
    s32 i, j, next, nverts;
    vu0_v4 *v = points;
    Point_003AD210 *out;
    if (count < 2) return;
    func_0038C750();
    length = 0.0f;
    func_003A9440(6, func_00389598(texture));
    func_003A9440(0x14, 0x0000FF9000000260UL);
    func_003A9440(8, 0);
    nverts = count << 1;
    func_003A9440(0x42, 0x0000004000000044UL);
    out = D_L07_002A22E0;
    for (i = 0; i < count; i++, out += 2) {
        j = (i + start) % count;
        next = (j + 1) % count;
        if (i != count - 1) {
            f32 d;
            __asm__("lqc2 $vf2,%1\n lqc2 $vf1,%2\n vsub.xyz $vf2,$vf2,$vf1\n sqc2 $vf2,%0"
                : "=m"(delta) : "m"(v[j]), "m"(v[next]) : "vf1", "vf2");
            d = func_0038CEA8(&delta);
            length += d;
            *(f32 *)((s32)D_L07_001E1678 + (i << 2)) = d;
        }
        if (i != 0 && i != count - 1) {
            __asm__("lqc2 $vf1,%1\n lqc2 $vf2,%2\n vadd.xyz $vf1,$vf1,$vf2\n sqc2 $vf1,%0"
                : "=m"(normal) : "m"(delta), "m"(previous) : "vf1", "vf2");
        } else {
            *(vu0_q *)&normal = *(vu0_q *)&delta;
        }
        __asm__("lqc2 $vf2,%1\n lqc2 $vf1,%2\n vsub.xyz $vf2,$vf2,$vf1\n sqc2 $vf2,%0"
            : "=m"(view) : "m"(D_L07_001E1EC0[0]), "m"(v[j]) : "vf1", "vf2");
        func_0038CE90(&cross, &view, &normal);
        func_0038CF68(&cross, &cross, 0.5f);
        __asm__("lqc2 $vf1,%1\n lqc2 $vf2,%2\n vadd.xyz $vf2,$vf2,$vf1\n sqc2 $vf2,%0"
            : "=m"(temp) : "m"(cross), "m"(v[j]) : "vf1", "vf2");
        out[0].x = temp.x;
        out[0].y = temp.y;
        out[0].z = temp.z;
        __asm__("lqc2 $vf2,%1\n lqc2 $vf1,%2\n vsub.xyz $vf1,$vf1,$vf2\n sqc2 $vf1,%0"
            : "=m"(temp) : "m"(cross), "m"(v[j]) : "vf1", "vf2");
        out[1].x = temp.x;
        out[1].y = temp.y;
        out[1].z = temp.z;
    }
    inv = 1.0f / length;
    fraction = 0.0f;
    {
    f32 *d = D_L07_001E1678;
    u32 *colors = &D_L07_002A23D0[0][0];
    vu0_v4 *uv = D_L07_002A2420;
    for (i = count; i != 0; i--) {
        u32 color = func_0038DBD8(0x00804020, 0x30202080, fraction);
        colors[1] = colors[0] = color;
        uv->x = fraction;
        uv->y = 0.0f;
        uv->z = fraction;
        uv->w = 1.0f;
        fraction += *d++ * inv;
        colors += 2;
        uv++;
    }
    }
    func_003D3A24(nverts, D_L07_002A22E0, D_L07_002A23D0, D_L07_002A2420, 1);
    func_003A9440(0x47, 0x5360B);
}
