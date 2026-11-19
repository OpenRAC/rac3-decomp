/*  */
typedef struct {
    u8 header[0x40];
    s32 colors[4];
    f32 uv[8];
    u8 pad70[0x20];
} Primitive_003A8850;
static __inline__ void add_003A8850(void *d, void *a, void *b) {
    __asm__(
        "lqc2 vf1, %1\n"
        "lqc2 vf2, %2\n"
        "vadd.xyz vf1, vf1, vf2\n"
        "sqc2 vf1, %0"
        : "=m"(*(vu0_v4 *)d)
        : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b)
        : "vf1", "vf2");
}
extern s32 D_L01_001DBCA0;
__asm__(".extern D_L01_001DBCA0, 16");
extern u8 D_001A4EC0[];
extern Vec4 D_L01_001D7C50[];
void func_L01_003A8850(Obj003A7510 *object) {
    extern void func_003D93B0(void *, s32, s32, s32);
    extern s32 func_L01_00448CC0(f32, f32, f32, f32);
    extern void func_0038CF68(u8 *, Vec4 *, f32);
    extern void func_0038CE90(u8 *, u8 *, u8 *);
    extern void func_0038D890(void *, void *, void *, f32);
    extern void func_0038D308(void *, void *);
    extern void func_0038D5F0(void *, void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038D028(void *, void *, void *);
    extern void func_003D2DA0(void *, s32, s32);
    extern f32 func_00382538(void);
    Primitive_003A8850 prim;
    Vec4 basis[3];
    Vec4 pos;
    Vec4 temp;
    Vec4 rotation[3];
    Vec4 *out;
    Vec4 *corners;
    u8 *m = (u8 *)object;
    f32 angle;
    f32 scale;
    f32 alpha;
    s32 color;
    s32 i;
    s32 j;
    D_L01_001DBCA0 |= 1;
    func_003D93B0(&prim, 0x3F, 1, 0x80);
    angle = 0.0f;
    alpha = 223.0f;
    scale = 0.8f;
    switch (object->timer) {
    case 1: alpha = 239.0f; scale = 0.4f; break;
    case 3: alpha = 127.0f; scale = 1.0f; break;
    case 4: alpha = 127.0f; scale = 0.75f; break;
    case 2:
    case 5: alpha = 175.0f; scale = 0.8f; break;
    }
    scale *= *(f32 *)(m + 0x1C);
    color = func_L01_00448CC0(128.0f,128.0f,128.0f,alpha);
    prim.colors[3] = color;
    prim.colors[2] = color;
    prim.colors[1] = color;
    prim.colors[0] = color;
    prim.uv[0] = 0.0f;
    prim.uv[1] = 0.0f;
    prim.uv[2] = 0.0f;
    prim.uv[3] = 1.0f;
    prim.uv[4] = 1.0f;
    prim.uv[5] = 0.0f;
    prim.uv[6] = 1.0f;
    prim.uv[7] = 1.0f;
    pos = *(Vec4 *)(m + 0x10);
    basis[0] = *(Vec4 *)(m + 0xC0);
    func_0038CF68((u8 *)&basis[0], &basis[0], 1.0f);
    func_0038CE90((u8 *)&basis[1], (u8 *)&basis[0], D_001A4EC0);
    func_0038CF68((u8 *)&basis[1], &basis[1], 1.0f);
    func_0038CE90((u8 *)&basis[2], (u8 *)&basis[1], (u8 *)&basis[0]);
    func_0038D890(&basis[0], &basis[0], &basis[2], 1.5707964f);
    func_0038D890(&basis[1], &basis[1], &basis[2], 1.5707964f);
    if (angle != 0.0f) {
        temp.q = 0;
        temp.f[0] = angle;
        func_0038D308(rotation, &temp);
        func_0038D5F0(basis, basis, rotation);
    }
    func_0038CE20(&temp, &basis[1], scale * -1.75f);
    add_003A8850(&pos, &pos, &temp);
    out = (Vec4 *)&prim;
    corners = D_L01_001D7C50;
    i = 3;
    do {
        func_0038CE20(out, corners, scale + scale);
        corners++;
        func_0038D028(out, out, basis);
        out++;
    } while (--i >= 0);
    func_003D2DA0(&prim, 0, 0);
    angle = func_00382538();
    func_003D93B0(&prim, 0x41, 1, 0x80);
    pos = *(Vec4 *)(m + 0x10);
    basis[0] = *(Vec4 *)(m + 0xC0);
    func_0038CF68((u8 *)&basis[0], &basis[0], 1.0f);
    func_0038CE90((u8 *)&basis[1], (u8 *)&basis[0], D_001A4EC0);
    func_0038CF68((u8 *)&basis[1], &basis[1], 1.0f);
    func_0038CE90((u8 *)&basis[2], (u8 *)&basis[1], (u8 *)&basis[0]);
    if (angle != 0.0f) {
        temp.q = 0;
        temp.f[0] = angle;
        func_0038D308(rotation, &temp);
        func_0038D5F0(basis, basis, rotation);
    }
    func_0038CE20(&temp, &basis[0], 0.1f);
    add_003A8850(&pos, &pos, &temp);
    out = (Vec4 *)&prim;
    j = 3;
    do {
        func_0038CE20(out, &D_L01_001D7C50[3 - j], scale * 1.8f);
        j--;
        func_0038D028(out, out, basis);
        out++;
    } while (j >= 0);
    func_003D2DA0(&prim, 0, 0);
}
