/* functional: high. From the PAL near-miss draft (189 words differ: stack size 0x250 vs 0x260 and VU/EE scheduling); logic read against the asm: same calls, args and vector ops. Honest vector asm helpers (lqc2/sqc2/vsub/vadd) kept. */
typedef int Q_00409658 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_00409658;
static __inline__ void copy_00409658(void *d, void *a) {
    __asm__("lqc2 $vf1, %1\n\tsqc2 $vf1, %0" : "=m"(*(V_00409658 *)d) : "m"(*(V_00409658 *)a) : "vf1");
}
static __inline__ void copy2_00409658(void *d, void *a) {
    __asm__("lqc2 $vf2, %1\n\tsqc2 $vf2, %0" : "=m"(*(V_00409658 *)d) : "m"(*(V_00409658 *)a) : "vf2");
}
static __inline__ void sub_ab1_00409658(void *d, void *a, void *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(V_00409658 *)d) : "m"(*(V_00409658 *)a), "m"(*(V_00409658 *)b) : "vf1", "vf2");
}
static __inline__ void sub_ab_r1_00409658(void *d, void *a, void *b) {
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf1, $vf2, $vf1\n\tsqc2 $vf1, %0" : "=m"(*(V_00409658 *)d) : "m"(*(V_00409658 *)a), "m"(*(V_00409658 *)b) : "vf1", "vf2");
}
static __inline__ void sub_ab_00409658(void *d, void *a, void *b) {
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(*(V_00409658 *)d) : "m"(*(V_00409658 *)a), "m"(*(V_00409658 *)b) : "vf1", "vf2");
}
static __inline__ void sub_ba_00409658(void *d, void *a, void *b) {
    __asm__("lqc2 $vf1, %2\n\tlqc2 $vf2, %1\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(*(V_00409658 *)d) : "m"(*(V_00409658 *)a), "m"(*(V_00409658 *)b) : "vf1", "vf2");
}
static __inline__ void add_ba_00409658(void *d, void *a, void *b) {
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(V_00409658 *)d) : "m"(*(V_00409658 *)a), "m"(*(V_00409658 *)b) : "vf1", "vf2");
}
typedef struct {
    Q_00409658 pos[4];
    s32 color[4];
    f32 uv[4][2];
    u8 data[32];
} Packet_00409658;
extern V_00409658 D_L01_001E29C0;
void func_L01_00409658(V_00409658 *points, s32 texture, s32 texture2,
    s32 count, s32 color, s32 color2, s32 closed, f32 unused, f32 scale, f32 scroll) {
    extern void func_003D93B0(void *, s32, s32, s32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_003D2DA0(void *, s32, s32);
    Packet_00409658 a, b;
    V_00409658 normal, offset, camera, direction;
    Q_00409658 first[2], first2[2];
    V_00409658 delta, previous, current;
    V_00409658 *p;
    f32 zero, start, end;
    s32 i;
    func_003D93B0(&a, texture, 1, 128);
    *(s32 *)&a.uv[0][0] = 0;
    zero = a.uv[0][0];
    end = scroll + 1.0f;
    start = scroll + zero;
    a.color[3] = color;
    a.color[2] = color;
    a.color[1] = color;
    a.color[0] = color;
    *(s32 *)&a.uv[0][1] = 0;
    a.uv[1][1] = 1.0f;
    *(s32 *)&a.uv[2][1] = 0;
    a.uv[3][1] = 1.0f;
    a.uv[1][0] = start;
    a.uv[0][0] = start;
    a.uv[3][0] = end;
    a.uv[2][0] = end;
    func_003D93B0(&b, texture2, 1, 128);
    copy_00409658(&current, &points[0]);
    sub_ba_00409658(&delta, &current, &D_L01_001E29C0);
    sub_ab_00409658(&direction, &points[1], &points[0]);
    b.color[3] = color2;
    b.color[2] = color2;
    b.color[1] = color2;
    b.color[0] = color2;
    b.uv[2][1] = zero;
    b.uv[3][1] = 1.0f;
    b.uv[0][0] = start;
    b.uv[2][0] = end;
    b.uv[0][1] = zero;
    b.uv[1][1] = 1.0f;
    b.uv[1][0] = start;
    b.uv[3][0] = end;
    copy_00409658(&camera, &delta);
    func_0038CE90(&normal, &direction, &camera);
    func_0038CF68(&offset, &normal, points[0].w);
    add_ba_00409658(&a.pos[0], &points[0], &offset);
    sub_ab_00409658(&a.pos[1], &points[0], &offset);
    first[0] = a.pos[0];
    first[1] = a.pos[1];
    func_0038CE20(&offset, &offset, scale);
    add_ba_00409658(&b.pos[0], &points[0], &offset);
    sub_ab_00409658(&b.pos[1], &points[0], &offset);
    first2[0] = b.pos[0];
    first2[1] = b.pos[1];
    for (i = 1; i < count; i++) {
        p = &points[i];
        if (i >= count - 1 && closed == 0) continue;
        {
            sub_ab_00409658(&current, p, &D_L01_001E29C0);
            copy2_00409658(&previous, p - 1);
            copy2_00409658(&camera, &current);
            sub_ab1_00409658(&direction, p, &previous);
            func_0038CE90(&normal, &direction, &camera);
            func_0038CF68(&offset, &normal, p->w);
            add_ba_00409658(&a.pos[2], p, &offset);
            sub_ab_00409658(&a.pos[3], p, &offset);
            func_0038CE20(&offset, &offset, scale);
            add_ba_00409658(&b.pos[2], p, &offset);
            sub_ab_r1_00409658(&b.pos[3], p, &offset);
            if (i == count - 1) {
                a.pos[2] = first[0]; a.pos[3] = first[1];
                b.pos[2] = first2[0]; b.pos[3] = first2[1];
            }
            func_003D2DA0(&a, 0, 0);
            func_003D2DA0(&b, 0, 0);
            a.pos[0] = a.pos[2]; a.pos[1] = a.pos[3];
            b.pos[0] = b.pos[2]; b.pos[1] = b.pos[3];
        }
    }
}
