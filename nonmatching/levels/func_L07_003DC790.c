/* PAL near miss (sol-3): 39 words differ with the file's flags. VU0 scheduling and saved registers differ. The signature uses types from the owning file. */
#include "common.h"
/* localdecomp:start func_L07_003DC790 */
typedef int Quad_003DC790 __attribute__((mode(TI)));
typedef struct { f32 v[4]; } __attribute__((aligned(16))) Vec_003DC790;
void func_L07_003DC790(S_3DC6E8 *obj, M_3DC6E8 *arg, Q_3DC6E8 *where, f32 radius)
{
    extern f32 func_L01_0040E570(void *, void *);
    extern void func_L01_00446630(void *, void *, void *, void *);
    extern f32 func_L01_0040E548(void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_L01_00446A70(void *, void *, s32, void *, void *, f32);
    Vec_003DC790 point;
    Vec_003DC790 projection;
    Vec_003DC790 normal;
    Vec_003DC790 *pp = &point;
    u8 *state = obj->f68;
    u8 *scan;
    s32 best = 0;
    s32 i;
    f32 distance, prev, d;
    *(Quad_003DC790 *)pp = *where;
    distance = func_L01_0040E570(pp, (u8 *)obj + 0x10);
    if (distance > radius) return;
    scan = state + 16;
    for (i = 1; i < 7; i++, scan += 16) {
        d = func_L01_0040E570(pp, scan);
        if (d < distance) {
            distance = d;
            best = i;
        }
    }
    prev = func_L01_0040E570(pp, state + ((best << 4) - 16));
    i = best + 1;
    d = func_L01_0040E570(pp, state + ((best << 4) + 16));
    if (prev < d) i = best - 1;
    scan = state + (best << 4);
    func_L01_00446630(&projection, scan, state + (i << 4), pp);
    if (func_L01_0040E548(pp, &projection) > 1.0f) return;
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
        : "=m"(normal) : "m"(*(Vec_003DC790 *)(scan + 0x80)),
          "m"(*(Vec_003DC790 *)(scan)) : "vf1", "vf2");
    func_0038CE20(&normal, &normal, 1.0f);
    func_L01_00446A70(arg, obj, 0x10001, &projection, &normal, *(f32 *)(state + 0x11C));
}
/* localdecomp:end func_L07_003DC790 */
