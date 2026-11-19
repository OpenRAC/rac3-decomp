/* functional: high. Particle step: despawns via func_003CD608(p) if v10.z exceeds the ceiling stored in v30.w, or v10.x/.y leave [0,1024]; else adds v30.xyz to v20.xyz (v20.w becomes 0.0: retail's vadd.xyz leaves w from a velocity copy whose w was zeroed), adds v30.xyz to v10.xyz (v10.w kept), applies gravity v30.z -= 0.00392f and rewrites v30.w unchanged. VU0 adds rounded differently from host float add by at most 1 ulp. Written without the vec_* asm helpers. */
typedef struct { f32 x, y, z, w; } V4_003BF658;
typedef struct {
    u8 pad0[0x10];
    V4_003BF658 v10;
    V4_003BF658 v20;
    V4_003BF658 v30;
} S_003BF658;
extern void func_003CD608(void *);
void func_003BF658(S_003BF658 *p) {
    f32 height = p->v30.w;
    if (height < p->v10.z || p->v10.x < 0.0f || p->v10.y < 0.0f || 1024.0f < p->v10.x || 1024.0f < p->v10.y) {
        func_003CD608(p);
    } else {
        f32 vx = p->v30.x;
        f32 vy = p->v30.y;
        f32 vz = p->v30.z;
        f32 ox = p->v20.x;
        f32 oy = p->v20.y;
        f32 oz = p->v20.z;
        p->v20.x = ox + vx;
        p->v20.y = oy + vy;
        p->v20.z = oz + vz;
        p->v20.w = 0.0f;
        p->v10.x += vx;
        p->v10.y += vy;
        p->v10.z += vz;
        p->v30.z = vz - 0.003920000046491623f;
        p->v30.w = height;
    }
}
