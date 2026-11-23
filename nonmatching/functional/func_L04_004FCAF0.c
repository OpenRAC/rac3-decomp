/* functional: medium. Checked at L04 with -mvu0-use-vf0-vf2 added (file flag line lacks it; needs #include vu0.h). Frame size, registers, calls, constants and offsets line up; the ~320 diff lines are 1-2 instruction shifts from a different early-return layout and swapped sb order for D_00142660+0x5A/0x5B. Read block by block against the assembly. Hero union at D_001A4BE0. Caveat: vector v0 is left unset for hero modes other than 0,1,3 (state 2), as retail leaves stack garbage there; flag for the gate. */
/* localdecomp:start func_L04_004FCAF0 */
typedef int vu0_q __attribute__((mode(TI)));
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) vu0_v4;
static void vec_sub_ab(void *d, void *a, void *b) { vu0_v4 *D=d,*A=a,*B=b; vu0_v4 r=*A; r.x=A->x-B->x; r.y=A->y-B->y; r.z=A->z-B->z; *D=r; }
static void vec_sub_ba(void *d, void *a, void *b) { vu0_v4 *D=d,*A=a,*B=b; vu0_v4 r=*B; r.x=A->x-B->x; r.y=A->y-B->y; r.z=A->z-B->z; *D=r; }
static void vec_add_ab(void *d, void *a, void *b) { vu0_v4 *D=d,*A=a,*B=b; vu0_v4 r=*A; r.x=A->x+B->x; r.y=A->y+B->y; r.z=A->z+B->z; *D=r; }
static void vec_add_ba(void *d, void *a, void *b) { vu0_v4 *D=d,*A=a,*B=b; vu0_v4 r=*A; r.x=A->x+B->x; r.y=A->y+B->y; r.z=A->z+B->z; *D=r; }
static void vec_copy(void *d, void *s) { *(vu0_v4 *)d = *(vu0_v4 *)s; }
typedef int s128_dummy __attribute__((mode(TI)));
typedef union { u8 b[0x2900]; s8 c[0x2900]; s16 h[0x1480]; s32 i[0xA40]; f32 f[0xA40]; void *ptr[0xA40]; } Hero_004FCAF0;
extern u8 D_001A4BE0[];
extern u8 D_001ED800[];
extern u8 D_00142660[];
extern s16 D_001426A0;
extern s32 D_001D6694[];
extern u8 D_001A4CD0[];
extern s32 func_L01_0041A4F0(void);
extern f32 func_L01_004C93D8(void);
extern f32 func_L01_004C9360(f32);
extern f32 func_L01_004DFE88(s32);
extern void func_L01_004E1560(void);
extern void func_L01_005110E8(void *, s32, f32, f32, f32);
extern void func_L01_004ED838(void *, s32, f32, f32);
extern void func_L01_00511618(void *, void *, f32);
extern u8 *func_L01_00447490(void *, s32, s32);
extern void func_L01_004DFEA0(s32);
extern s32 func_L04_0050CB28(s32, s32);
extern void func_L01_003F1F20(s32, s32);
extern void func_L01_004F4E70(s32, s32);

s32 func_L04_004FCAF0(s32 hit) {
    vu0_v4 v0 = {0.0f, 0.0f, 0.0f, 0.0f};
    vu0_v4 v1;
    u8 *e;
    u8 *x;
    u8 *o;
    u8 k;
    s32 flags;
    s32 w;
    s32 st;
    if (((Hero_004FCAF0 *)D_001A4BE0)->i[0x25CC / 4] == 0x14 || ((Hero_004FCAF0 *)D_001A4BE0)->i[0x25CC / 4] == 7 || ((Hero_004FCAF0 *)D_001A4BE0)->i[0x25C4 / 4] == 0x74) {
        return 0;
    }
    if (((Hero_004FCAF0 *)D_001A4BE0)->i[0x25C4 / 4] == 0x31) {
        return 0;
    }
    if (((Hero_004FCAF0 *)D_001A4BE0)->h[0x1DC / 2] != 0) {
        return 0;
    }
    if (D_001D6694[0] != 0) {
        return 0;
    }
    ((Hero_004FCAF0 *)D_001A4BE0)->i[0x2808 / 4] = 0;
    k = *(u8 *)(((Hero_004FCAF0 *)D_001A4BE0)->ptr[0x25C0 / 4] + 0xA8);
    if (k == 0xFF) {
        return 0;
    }
    e = D_001ED800 + k * 64;
    if (*(void **)(e + 0x38) != ((Hero_004FCAF0 *)D_001A4BE0)->ptr[0x25C0 / 4]) {
        return 0;
    }
    if ((*(s32 *)(e + 0x24) & 9) == 0) {
        return 0;
    }
    if (((Hero_004FCAF0 *)D_001A4BE0)->i[0x234 / 4] != 0) {
        return 0;
    }
    if (*(f32 *)(e + 0x2C) != 0.0f) {
        if (func_L01_0041A4F0() != 0 && D_001A4BE0[0x25E4] != 5) {
            D_00142660[0x5B] = 0;
            D_00142660[0x5A] = 0;
        }
    }
    if (func_L01_004C93D8() == 0.0f || D_001A4BE0[0x25E4] != 0) {
        flags = *(s32 *)(e + 0x24);
    } else {
        flags = *(s32 *)(e + 0x24);
        if (!(flags & 0x20000000)) {
            *(f32 *)(e + 0x2C) = func_L01_004C9360(*(f32 *)(e + 0x2C));
            if (*(f32 *)(e + 0x2C) == 0.0f) {
                return 0;
            }
            flags = *(s32 *)(e + 0x24);
        }
    }
    if (flags & 0x20000000) {
        if (D_001A4BE0[0x25E4] == 0) {
            s32 lv = D_001426A0;
            lv = lv < 5 ? lv : 4;
            lv = lv > -1 ? lv : 0;
            *(f32 *)(e + 0x2C) = *(f32 *)(e + 0x2C) / func_L01_004DFE88(lv);
        }
    }
    ((Hero_004FCAF0 *)D_001A4BE0)->i[0x2808 / 4] = *(s32 *)(e + 0x20);
    if (hit == 0) {
        if (((Hero_004FCAF0 *)D_001A4BE0)->h[0x1DC / 2] != 0) {
            return 1;
        }
        o = func_L01_00447490(((Hero_004FCAF0 *)D_001A4BE0)->ptr[0x25C0 / 4], 1, 0);
        if (o != 0) {
            func_L01_004DFEA0((s32)*(f32 *)(o + 0x2C));
        } else {
            func_L01_004DFEA0(1);
        }
        ((Hero_004FCAF0 *)D_001A4BE0)->h[0x1DC / 2] = 0x40;
        return 1;
    }
    func_L01_004E1560();
    hit = 0;
    if (*(s32 *)(e + 0x30) & 1) {
        *(s128_dummy *)&v0 = *(s128_dummy *)(e + 0x10);
        if (*(f32 *)(e + 0x1C) == 5627.9248f) {
            hit = 1;
        }
    } else {
        x = *(u8 **)(e + 0x20);
        if (x != 0) {
            vec_sub_ba(&v0, D_001A4BE0 + 0x80, x + 0x10);
        } else {
            func_L01_005110E8(&v0, 0, -1.0f, 0.0f, 0.0f);
        }
    }
    st = D_001A4BE0[0x25E4];
    if (st == 1) {
        func_L04_0050CB28(0x42, 1);
        func_L01_004ED838(&v0, hit, 0.06f, 0.06f);
    } else if (st == 0) {
        x = ((Hero_004FCAF0 *)D_001A4BE0)->ptr[0x2808 / 4];
        if (x != 0) {
            s32 key = *(s16 *)(x + 0xAA);
            if (key == 0x4EB || key == 0x558 || key == 0x1C5F) {
                func_L04_0050CB28(0x82, 1);
                return 1;
            }
        }
        w = ((Hero_004FCAF0 *)D_001A4BE0)->i[0x25C4 / 4];
        if (w == 1 || w == 0x1D || ((Hero_004FCAF0 *)D_001A4BE0)->i[0x16B0 / 4] == 2) {
            if (!(*(s32 *)(e + 0x24) & 8)) {
                o = func_L01_00447490(((Hero_004FCAF0 *)D_001A4BE0)->ptr[0x25C0 / 4], 1, 0);
                if (o != 0) {
                    func_L01_004DFEA0((s32)*(f32 *)(o + 0x2C));
                }
                if (((Hero_004FCAF0 *)D_001A4BE0)->i[0x2850 / 4] == 0) {
                    func_L04_0050CB28(0x16, 1);
                } else {
                    func_L01_003F1F20(0x12, 0);
                }
                ((Hero_004FCAF0 *)D_001A4BE0)->h[0x1DC / 2] = 0x40;
                if (((Hero_004FCAF0 *)D_001A4BE0)->h[0x21C / 2] == 0) {
                    ((Hero_004FCAF0 *)D_001A4BE0)->h[0x21C / 2] = 0xF;
                }
                func_L01_004F4E70(0x14, 0);
                return 0;
            }
        }
        w = ((Hero_004FCAF0 *)D_001A4BE0)->i[0x25CC / 4];
        if (w == 0x12) {
            func_L04_0050CB28(0x77, 1);
        } else if (w == 0x11) {
            func_L04_0050CB28(0x78, 1);
        } else if (*(s32 *)(e + 0x24) & 8) {
            func_L04_0050CB28(0x91, 1);
        } else {
            func_L04_0050CB28(0x16, 1);
        }
        if (((Hero_004FCAF0 *)D_001A4BE0)->i[0x25C4 / 4] == 0x91) {
            v0.x = 0.0f; v0.y = 0.0f; v0.z = 0.0f; v0.w = 0.0f;
        } else {
            f32 f12 = 0.066f;
            if (D_001A4BE0[0x1479] != 0) {
                f12 = 0.0f;
            }
            func_L01_004ED838(&v0, hit, f12, 0.034f);
            if (hit != 0 && e[0x28] == 4) {
                func_L01_00511618(&v0, &v0, 2.0f);
            }
        }
    } else if (st == 3) {
        func_L04_0050CB28(0x55, 1);
        func_L01_004ED838(&v0, hit, 0.1f, 0.048f);
    }
    vec_copy(&v1, &v0);
    vec_add_ba(D_001A4CD0, D_001A4CD0, &v0);
    vec_add_ab(D_001A4CD0 + 0x20, D_001A4CD0 + 0x20, &v1);
    return 1;
}
/* localdecomp:end func_L04_004FCAF0 */
