/* PAL near miss (Codex wave 8): near miss: 278 words differ with the file's flags.
 * Worker's note: Best 233 diff; full PAL draw reconstruction; stack temporaries, register allocation and opaque VU scheduling remain. Trial --divs 2,2,2,2,1 (not proven metadata). build/codex/w423/360398-07.log
 */
#include "common.h"
/* localdecomp:start func_L01_00360398 */
typedef struct {
    S_38C110v p[4];
    s32 color[4];
    f32 uv[8];
    long zero, texture, state, mode;
} Packet_00360398;
typedef struct { u8 first; u8 kind; u8 pad[238]; } Weapon_00360398;
extern u8 D_00142637[];
extern Weapon_00360398 D_L01_002C5600[];
extern S_38C110v D_L01_001E2A40;
extern f32 D_001DD714_sda;
__asm__(".extern D_001DD714_sda, 4");
void func_L01_00360398(S_38C110v *points, s32 alpha0, s32 alpha1, s32 count, f32 width0, f32 width1, f32 stretch) {
    extern long func_00389598(s32);
    extern void func_0038CE90(s128 *,s128 *,s128 *);
    extern f32 func_0038CEA8(void *);
    extern void func_0038CE20(s128 *,s128 *,f32);
    extern void func_003D2DA0(void *,void *,s32);
    extern void func_003A9440(s32,s32);
    Packet_00360398 inner;
    Packet_00360398 outer;
    S_38C110v cross;
    S_38C110v offset;
    S_38C110v view;
    S_38C110v tangent;
    S_38C110v p0, p1;
    S_38C110v r0, r1;
    S_38C110v toward;
    S_38C110v extend;
    S_38C110v initial_view;
    S_38C110v end_copy;
    S_38C110v camera0;
    S_38C110v camera1;
    S_38C110v point_copy;
    f32 length;
    f32 length0;
    f32 length1;
    s32 color0, color1;
    s32 kind;
    s32 i;
    inner.texture = func_00389598(14);
    color0 = (alpha0 << 24) | 0x7F7F7F;
    inner.mode = 0x8000000048L;
    inner.state = 0xFF9000000260L;
    inner.zero = 0;
    inner.color[3] = color0;
    inner.color[2] = color0;
    inner.color[1] = color0;
    inner.color[0] = color0;
    outer.texture = func_00389598(16);
    color1 = (alpha1 << 24) | 0x7F2020;
    kind = ((Weapon_00360398 *)(D_00142637[0] * 0xF0 + (u32)D_L01_002C5600))->kind;
    if (kind == 2) color1 = (alpha1 << 24) | 0x204080;
    else if (kind == 3) color1 = (alpha1 << 24) | 0x10107F;
    outer.uv[0] = 0.0f;
    __asm__("lqc2 $vf1, %1\n\tsqc2 $vf1, %0" : "=m"(point_copy) : "m"(points[0]) : "vf1");
    __asm__("lqc2 $vf1, %2\n\tlqc2 $vf2, %1\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(initial_view) : "m"(point_copy), "m"(D_L01_001E2A40) : "vf1", "vf2");
    outer.mode = inner.mode;
    outer.state = inner.state;
    outer.zero = inner.zero;
    outer.color[3] = color1;
    outer.color[2] = color1;
    outer.color[1] = color1;
    outer.color[0] = color1;
    outer.uv[1] = 0.0f;
    outer.uv[2] = 0.0f;
    outer.uv[3] = 1.0f;
    outer.uv[4] = 1.0f;
    outer.uv[5] = 0.0f;
    outer.uv[6] = 1.0f;
    outer.uv[7] = 1.0f;
    inner.uv[0] = D_001DD714_sda + 0.0f;
    inner.uv[1] = 0.0f;
    inner.uv[2] = D_001DD714_sda + 0.0f;
    inner.uv[3] = 1.0f;
    inner.uv[4] = D_001DD714_sda + 1.0f;
    inner.uv[5] = 0.0f;
    inner.uv[6] = D_001DD714_sda + 1.0f;
    inner.uv[7] = 1.0f;
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(tangent) : "m"(points[1]), "m"(points[0]) : "vf1", "vf2");
    __asm__("lqc2 $vf1, %1\n\tsqc2 $vf1, %0" : "=m"(view) : "m"(initial_view) : "vf1");
    func_0038CE90((s128 *)&cross,(s128 *)&tangent,(s128 *)&view);
    length = func_0038CEA8(&cross);
    if (length != 0.0f) length = 1.0f / length;
    func_0038CE20((s128 *)&cross,(s128 *)&cross,width0 * length);
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(inner.p[0]) : "m"(points[0]), "m"(cross) : "vf1", "vf2");
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(inner.p[1]) : "m"(points[0]), "m"(cross) : "vf1", "vf2");
    for (i = 1; i < count - 1; i++) {
    __asm__("lqc2 $vf1, %1\n\tsqc2 $vf1, %0" : "=m"(point_copy) : "m"(points[i]) : "vf1");
    __asm__("lqc2 $vf1, %2\n\tlqc2 $vf2, %1\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(point_copy) : "m"(point_copy), "m"(D_L01_001E2A40) : "vf1", "vf2");
    __asm__("lqc2 $vf1, %1\n\tsqc2 $vf1, %0" : "=m"(end_copy) : "m"(points[i]) : "vf1");
    __asm__("lqc2 $vf1, %1\n\tsqc2 $vf1, %0" : "=m"(view) : "m"(point_copy) : "vf1");
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(tangent) : "m"(points[i+1]), "m"(end_copy) : "vf1", "vf2");
        func_0038CE90((s128 *)&cross,(s128 *)&tangent,(s128 *)&view);
        length = func_0038CEA8(&cross);
        if (length != 0.0f) length = 1.0f / length;
        func_0038CE20((s128 *)&cross,(s128 *)&cross,width0 * length);
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(inner.p[2]) : "m"(points[i]), "m"(cross) : "vf1", "vf2");
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf1, $vf2, $vf1\n\tsqc2 $vf1, %0" : "=m"(inner.p[3]) : "m"(points[i]), "m"(cross) : "vf1", "vf2");
        if (i == 1) {
            inner.color[1] = 0x7F7F7F;
            inner.color[0] = 0x7F7F7F;
        } else if (i == count - 2) {
            inner.color[3] = 0x7F7F7F;
            inner.color[2] = 0x7F7F7F;
        } else if (i == 2) {
            inner.color[1] = color0;
            inner.color[0] = color0;
        }
        func_003D2DA0(&inner, 0, 0);
        *(s128 *)&inner.p[0] = *(s128 *)&inner.p[2];
        *(s128 *)&inner.p[1] = *(s128 *)&inner.p[3];
    }
    for (i = 0; i < count - 1; i++) {
    __asm__("lqc2 $vf1, %1\n\tsqc2 $vf1, %0" : "=m"(point_copy) : "m"(points[i]) : "vf1");
    __asm__("lqc2 $vf1, %2\n\tlqc2 $vf2, %1\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(point_copy) : "m"(point_copy), "m"(D_L01_001E2A40) : "vf1", "vf2");
    __asm__("lqc2 $vf1, %1\n\tsqc2 $vf1, %0" : "=m"(camera0) : "m"(D_L01_001E2A40) : "vf1");
    __asm__("lqc2 $vf1, %1\n\tsqc2 $vf1, %0" : "=m"(r0) : "m"(point_copy) : "vf1");
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(r1) : "m"(points[i+1]), "m"(camera0) : "vf1", "vf2");
        length0 = func_0038CEA8(&r0);
        length1 = func_0038CEA8(&r1);
        if (length1 < length0) {
            if (length1 == 0.0f) *(s128 *)&r1 = *(s128 *)&r0;
            else func_0038CE20((s128 *)&r1,(s128 *)&r1,length0 / length1);
        } else {
            if (length0 == 0.0f) *(s128 *)&r0 = *(s128 *)&r1;
            else func_0038CE20((s128 *)&r0,(s128 *)&r0,length1 / length0);
        }
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(p0) : "m"(D_L01_001E2A40), "m"(r0) : "vf1", "vf2");
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(p1) : "m"(D_L01_001E2A40), "m"(r1) : "vf1", "vf2");
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(tangent) : "m"(p1), "m"(p0) : "vf1", "vf2");
        func_0038CE20((s128 *)&extend,(s128 *)&tangent,stretch);
    __asm__("lqc2 $vf1, %2\n\tlqc2 $vf2, %1\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(p0) : "m"(p0), "m"(extend) : "vf1", "vf2");
    __asm__("lqc2 $vf1, %2\n\tlqc2 $vf2, %1\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(p1) : "m"(p1), "m"(extend) : "vf1", "vf2");
    __asm__("lqc2 $vf1, %1\n\tsqc2 $vf1, %0" : "=m"(camera1) : "m"(D_L01_001E2A40) : "vf1");
    __asm__("lqc2 $vf1, %2\n\tlqc2 $vf2, %1\n\tvsub.xyz $vf1, $vf2, $vf1\n\tsqc2 $vf1, %0" : "=m"(toward) : "m"(camera1), "m"(p0) : "vf1", "vf2");
        func_0038CE90((s128 *)&cross,(s128 *)&toward,(s128 *)&tangent);
        length = func_0038CEA8(&cross);
        if (length != 0.0f) length = 1.0f / length;
        func_0038CE20((s128 *)&offset,(s128 *)&cross,width1 * length);
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(outer.p[0]) : "m"(p0), "m"(offset) : "vf1", "vf2");
    __asm__("lqc2 $vf1, %2\n\tlqc2 $vf2, %1\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(outer.p[1]) : "m"(p0), "m"(offset) : "vf1", "vf2");
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(outer.p[2]) : "m"(p1), "m"(offset) : "vf1", "vf2");
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(outer.p[3]) : "m"(p1), "m"(offset) : "vf1", "vf2");
        if (i == 0) {
            outer.color[1] = 0x7F2020;
            outer.color[0] = 0x7F2020;
        } else if (i == count - 2) {
            outer.color[3] = 0x7F2020;
            outer.color[2] = 0x7F2020;
        } else if (i == 1) {
            outer.color[1] = color1;
            outer.color[0] = color1;
        }
        func_003D2DA0(&outer,0,0);
    }
    func_003A9440(0x47,0x5360B);
}
/* localdecomp:end func_L01_00360398 */
