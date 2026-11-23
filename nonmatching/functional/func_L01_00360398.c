/* functional: high. Retail's VU0 vadd/vsub.xyz are two small static helpers with the w lane taken from the register retail used as destination; draw packets, colours, uv and loop bounds verified against the asm. */
typedef struct {
    S_38C110v p[4];
    s32 color[4];
    f32 uv[8];
    long zero, texture, state, mode;
} Packet_00360398;
typedef struct { u8 first; u8 kind; u8 pad[238]; } Weapon_00360398;
extern u8 D_001425C0[];
extern Weapon_00360398 D_L01_002C5600[];
extern S_38C110v D_L01_001E2A40;
extern f32 D_L01_001DD714;

/* d = a +/- b on xyz; w comes from wsrc, as the VU0 vadd/vsub.xyz that retail used leaves the destination's w */
static __inline__ void v3add_w(S_38C110v *d, S_38C110v *a, S_38C110v *b, S_38C110v *wsrc)
{
    S_38C110v t;
    t.x = a->x + b->x; t.y = a->y + b->y; t.z = a->z + b->z; t.w = wsrc->w;
    *d = t;
}
static __inline__ void v3sub_w(S_38C110v *d, S_38C110v *a, S_38C110v *b, S_38C110v *wsrc)
{
    S_38C110v t;
    t.x = a->x - b->x; t.y = a->y - b->y; t.z = a->z - b->z; t.w = wsrc->w;
    *d = t;
}

void func_L01_00360398(S_38C110v *points, s32 alpha0, s32 alpha1, s32 count, f32 width0, f32 width1, f32 stretch)
{
    extern long func_00389598(s32);
    extern void func_0038CE90(void *, void *, void *);
    extern f32 func_0038CEA8(void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_003D2DA0(void *, void *, s32);
    extern void func_003A9440(s32, s32);
    Packet_00360398 inner;
    Packet_00360398 outer;
    S_38C110v cross, offset, view, tangent;
    S_38C110v p0, p1, r0, r1, toward, extend;
    S_38C110v initial_view, end_copy, camera0, camera1, point_copy;
    f32 length, length0, length1;
    s32 color0, color1, kind, i;

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
    kind = D_L01_002C5600[D_001425C0[0x77]].kind;
    if (kind == 2) color1 = (alpha1 << 24) | 0x204080;
    else if (kind == 3) color1 = (alpha1 << 24) | 0x10107F;
    outer.uv[0] = 0.0f;
    point_copy = points[0];
    v3sub_w(&initial_view, &point_copy, &D_L01_001E2A40, &point_copy);
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
    inner.uv[0] = D_L01_001DD714 + 0.0f;
    inner.uv[1] = 0.0f;
    inner.uv[2] = D_L01_001DD714 + 0.0f;
    inner.uv[3] = 1.0f;
    inner.uv[4] = D_L01_001DD714 + 1.0f;
    inner.uv[5] = 0.0f;
    inner.uv[6] = D_L01_001DD714 + 1.0f;
    inner.uv[7] = 1.0f;
    v3sub_w(&tangent, &points[1], &points[0], &points[1]);
    view = initial_view;
    func_0038CE90(&cross, &tangent, &view);
    length = func_0038CEA8(&cross);
    if (length != 0.0f) length = 1.0f / length;
    func_0038CE20(&cross, &cross, width0 * length);
    v3add_w(&inner.p[0], &points[0], &cross, &points[0]);
    v3sub_w(&inner.p[1], &points[0], &cross, &points[0]);
    for (i = 1; i < count - 1; i++) {
        point_copy = points[i];
        v3sub_w(&point_copy, &point_copy, &D_L01_001E2A40, &point_copy);
        end_copy = points[i];
        view = point_copy;
        v3sub_w(&tangent, &points[i + 1], &end_copy, &points[i + 1]);
        func_0038CE90(&cross, &tangent, &view);
        length = func_0038CEA8(&cross);
        if (length != 0.0f) length = 1.0f / length;
        func_0038CE20(&cross, &cross, width0 * length);
        v3add_w(&inner.p[2], &points[i], &cross, &points[i]);
        v3sub_w(&inner.p[3], &points[i], &cross, &cross);
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
        inner.p[0] = inner.p[2];
        inner.p[1] = inner.p[3];
    }
    for (i = 0; i < count - 1; i++) {
        point_copy = points[i];
        v3sub_w(&point_copy, &point_copy, &D_L01_001E2A40, &point_copy);
        camera0 = D_L01_001E2A40;
        r0 = point_copy;
        v3sub_w(&r1, &points[i + 1], &camera0, &points[i + 1]);
        length0 = func_0038CEA8(&r0);
        length1 = func_0038CEA8(&r1);
        if (length1 < length0) {
            if (length1 == 0.0f) r1 = r0;
            else func_0038CE20(&r1, &r1, length0 / length1);
        } else {
            if (length0 == 0.0f) r0 = r1;
            else func_0038CE20(&r0, &r0, length1 / length0);
        }
        v3add_w(&p0, &D_L01_001E2A40, &r0, &D_L01_001E2A40);
        v3add_w(&p1, &D_L01_001E2A40, &r1, &D_L01_001E2A40);
        v3sub_w(&tangent, &p1, &p0, &p1);
        func_0038CE20(&extend, &tangent, stretch);
        v3sub_w(&p0, &p0, &extend, &p0);
        v3add_w(&p1, &p1, &extend, &p1);
        camera1 = D_L01_001E2A40;
        v3sub_w(&toward, &camera1, &p0, &p0);
        func_0038CE90(&cross, &toward, &tangent);
        length = func_0038CEA8(&cross);
        if (length != 0.0f) length = 1.0f / length;
        func_0038CE20(&offset, &cross, width1 * length);
        v3add_w(&outer.p[0], &p0, &offset, &p0);
        v3sub_w(&outer.p[1], &p0, &offset, &p0);
        v3add_w(&outer.p[2], &p1, &offset, &p1);
        v3sub_w(&outer.p[3], &p1, &offset, &p1);
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
        func_003D2DA0(&outer, 0, 0);
    }
    func_003A9440(0x47, 0x5360B);
}
