/* functional: high. Checked at L04 with -mvu0-use-vf0-vf2 added (this file's flag line lacks it; needs #include vu0.h and flag-line change to compile): all operands and calls match, 39 diff lines are float register numbering and scheduling. Local decl of func_L01_0043B548 differs from the later typedef in the file. */
/* localdecomp:start func_L04_003E6038 */
typedef int vu0_q __attribute__((mode(TI)));
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) vu0_v4;
static void vec_sub_ab(void *d, void *a, void *b) { vu0_v4 *D=d,*A=a,*B=b; vu0_v4 r=*A; r.x=A->x-B->x; r.y=A->y-B->y; r.z=A->z-B->z; *D=r; }
static void vec_sub_ba(void *d, void *a, void *b) { vu0_v4 *D=d,*A=a,*B=b; vu0_v4 r=*B; r.x=A->x-B->x; r.y=A->y-B->y; r.z=A->z-B->z; *D=r; }
static void vec_add_ab(void *d, void *a, void *b) { vu0_v4 *D=d,*A=a,*B=b; vu0_v4 r=*A; r.x=A->x+B->x; r.y=A->y+B->y; r.z=A->z+B->z; *D=r; }
static void vec_add_ba(void *d, void *a, void *b) { vu0_v4 *D=d,*A=a,*B=b; vu0_v4 r=*A; r.x=A->x+B->x; r.y=A->y+B->y; r.z=A->z+B->z; *D=r; }
static void vec_copy(void *d, void *s) { *(vu0_v4 *)d = *(vu0_v4 *)s; }
extern void func_L04_004DB090(void *);
extern void (**func_L01_0043B548(s32, s32))(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_0044ABD0(void *, void *);
extern u8 *func_L01_00447490(void *, s32, s32);
extern s32 func_0038CB00(void *);
extern f32 func_L01_004474E8(void *, void *);
extern s32 func_L01_00455E18(void *, void *, void *);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L04_00325460(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, s32, s32, s32, s32);
extern void func_L04_003E6308(void *, s32);
typedef int s128_003E6038 __attribute__((mode(TI)));

void func_L04_003E6038(u8 *self) {
    u8 *m = *(u8 **)(self + 0x68);
    u8 *t;
    f32 dmg;
    s32 state = self[0x20];
    switch (state) {
    case 0:
        func_L04_004DB090(self);
        if (*(s32 *)(m + 0x150) > 0) {
            void (**tbl)(void *) = func_L01_0043B548(0x19E1, 0x6C);
            m[0x15E] = 2;
            *(s32 *)(m + 0x150) = -1;
            tbl[0](self);
            return;
        }
        func_L01_004450F0(self, 1, -1);
        m[0x82] = 0xFF;
        *(f32 *)(m + 0xC8) = 0.01f;
        *(s32 *)(m + 0x140) = 0;
        *(f32 *)(m + 0x30) = (f32)*(s16 *)(m + 0x34);
        m[0x81] = 0xFF;
    case 1:
        break;
    default:
        return;
    }
    func_L01_0044ABD0(self, m + 0x70);
    t = func_L01_00447490(self, 1, 1);
    if (func_0038CB00(m + 0x36) == 0) {
        t = 0;
    }
    if (t != 0) {
        if (*(f32 *)(m + 0x118) != 0.0f) {
            u8 *o = *(u8 **)(t + 0x20);
            if (o != 0 && *(s16 *)(self + 0xAA) == *(s16 *)(o + 0xAA)) {
                *(f32 *)(t + 0x2C) = *(f32 *)(t + 0x2C) * *(f32 *)(m + 0x118);
            }
        }
    } else {
        t = func_L01_00447490(self, -1, 0);
        if (t != 0) {
            *(f32 *)(t + 0x2C) = *(f32 *)(t + 0x2C) * 0.5f;
            if (*(f32 *)(m + 0x118) != 0.0f) {
                u8 *o = *(u8 **)(t + 0x20);
                if (o != 0 && *(s16 *)(self + 0xAA) == *(s16 *)(o + 0xAA)) {
                    *(f32 *)(t + 0x2C) = *(f32 *)(t + 0x2C) * *(f32 *)(m + 0x118);
                }
            }
        }
    }
    self[0xA8] = 0xFF;
    dmg = func_L01_004474E8(self, t);
    self[0xA8] = 0xFF;
    *(f32 *)(m + 0x30) = *(f32 *)(m + 0x30) - dmg;
    if (func_L01_00455E18(self, m + 0x130, m + 0x30)) {
        func_003A52A0(0, 0, self);
    }
    if (*(f32 *)(m + 0x30) <= 0.0f) {
        vu0_v4 p __attribute__((aligned(16)));
        vu0_v4 q __attribute__((aligned(16)));
        vu0_v4 r __attribute__((aligned(16)));
        *(s128_003E6038 *)&p = *(s128_003E6038 *)(self + 0x10);
        func_0038CF68(&r, self + 0xD0, -2.0f);
        vec_add_ba(&p, &r, &p);
        func_0038CF68(&q, self + 0xC0, 1.5f);
        vec_add_ab(&p, &q, &p);
        func_L04_00325460(&p, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 1, 0.75f, 20.0f, 1, 0, 0, 0);
        func_003A52A0(0, 0, self);
        func_L04_003E6308(self, 1);
    }
}
/* localdecomp:end func_L04_003E6038 */
