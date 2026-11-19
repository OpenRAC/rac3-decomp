/* functional: medium. Same structure as func_L01_00314620 with different packed colour/flag words (0x407FFF, 0x20FF, 0x4F/0x4F, 0x20/0x10) and the particle-byte lookups kept as retail (D_L01_00221098+0x198, +0xD4, and the pointer table indexed by gp var); params and t are unused in retail too; velocity vector in the no-scratchpad branch is dead in retail. */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_314C90;
typedef struct {
    u8 *ptrs[53];
    u8 *w_D4;
    u8 pad_D8[0x198 - 0xD8];
    u8 *w_198;
} G_314C90;
typedef struct {
    u8 pad0[0x19];
    u8 b19;
} R_314C90;
extern u8 D_001D66B0[];
extern s32 D_001D52F0;
extern G_314C90 D_L01_00221098;
extern V_314C90 D_L01_001E2A40[];
extern f32 D_L01_001DC780;
extern s32 D_L01_001DC78C;
extern s32 D_L01_001DC788;
extern s32 func_003C2B88(void *, s32);
extern void func_00382580(void *, f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_004713C8(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_0038CDF8(void *, void *, void *, f32);
extern s32 func_00382468(s32);
extern R_314C90 *func_L01_00448FF0(void *);
extern s32 func_L01_00447938(void *, s32, void *, s32, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);

void func_L01_00314C90(u8 *obj, void *params, f32 t) {
    s32 n, i, r;
    V_314C90 *e;
    V_314C90 tmp0, v10, v20;
    V_314C90 pts[16];
    V_314C90 *pos;
    V_314C90 vel;
    f32 f20, f21, f22, f28;
    u8 *p;
    R_314C90 *rr;
    V_314C90 *cam;

    rr = func_L01_00448FF0(obj);
    if (rr == 0) {
        return;
    }
    n = func_003C2B88(obj, 0);
    if (n != 0) {
        if (n <= 0) {
            return;
        }
        e = (V_314C90 *)0x70000000; /* scratchpad: n entries of 0x20 bytes */
        do {
            if (e[1].w == 0.0f) {
                tmp0 = e[0];
                tmp0.w = 1.0f;
                func_00382580(&v10, 0.0f, e[0].w);
                tmp0.x = tmp0.x + v10.x;
                tmp0.y = tmp0.y + v10.y;
                tmp0.z = tmp0.z + v10.z;
                i = (s32)func_L01_00443A18(2.0f, 5.0f);
                f20 = func_003824E0(0.699999988079071f, 1.0f) * e[0].w;
                r = func_00382498(10, 15);
                func_L01_004713C8(&tmp0, D_001D66B0, (r * 5 + 2) / 6, 0x407FFF, i, 0x7F, 0x7F, 1,
                                  f20 * 210000.0f, 2100.0f, -0.0012000000569969416f);
                i = -(i << 1);
                r = func_00382498(10, 15);
                f20 = f20 * 6.0f;
                p = func_L01_004713C8(&tmp0, D_001D66B0, (r * 5 + 2) / 6, 0x20FF, i, 0x30, 0x30, 0,
                                      f20 * 210000.0f, 4200.0f, -0.0012000000569969416f);
                if (p != 0) {
                    p[2] = *D_L01_00221098.w_198;
                }
            } else {
                tmp0 = e[0];
                v10 = e[1];
                tmp0.w = 1.0f;
                v10.w = 1.0f;
                func_0038CDF8(&v20, &tmp0, &v10, func_003824E0(0.0f, 1.0f));
                v20.x = v20.x + func_003824E0(-e[0].w * 0.4000000059604645f, e[0].w * 0.4000000059604645f);
                v20.y = v20.y + func_003824E0(-e[0].w * 0.4000000059604645f, e[0].w * 0.4000000059604645f);
                v20.z = v20.z + func_003824E0(-e[0].w * 0.4000000059604645f, e[0].w * 0.4000000059604645f);
                i = (s32)func_L01_00443A18(2.0f, 5.0f);
                f20 = func_003824E0(0.699999988079071f, 1.0f) * e[0].w;
                r = func_00382498(10, 15);
                p = func_L01_004713C8(&v20, D_001D66B0, (r * 5 + 2) / 6, 0, i, 0x4F, 0x4F, 1,
                                      f20 * 210000.0f, 2100.0f, -0.0012000000569969416f);
                i = -(i << 1);
                if (p != 0) {
                    p[3] = 0x44;
                    p[2] = *D_L01_00221098.ptrs[D_L01_001DC78C];
                }
                r = func_00382498(10, 15);
                p = func_L01_004713C8(&v20, D_001D66B0, (r * 5 + 2) / 6, D_L01_001DC788, i, 0x20, 0x10, 0,
                                      f20 * 4.0f * 210000.0f, 4200.0f, -0.0012000000569969416f);
                if (p != 0) {
                    p[2] = *D_L01_00221098.w_D4;
                }
            }
            e += 2;
            n--;
        } while (n != 0);
        return;
    }
    n = func_L01_00447938(obj, 0x10, pts, rr->b19, D_L01_001DC780);
    cam = (V_314C90 *)((u8 *)D_L01_001E2A40 + D_001D52F0 * 0x460);
    f28 = func_0038D160(cam->x - *(f32 *)(obj + 0x10), cam->y - *(f32 *)(obj + 0x14));
    if (n <= 0) {
        return;
    }
    pos = pts;
    do {
        i = (s32)func_L01_00443A18(2.0f, 5.0f);
        f22 = func_003824E0(0.6000000238418579f, 1.0f) * 0.10000000149011612f;
        f21 = func_003824E0(9.0f, 12.0f) * 0.020000001415610313f;
        f20 = func_0038DAB8(f28, func_L01_00443A18(0.0f, 1.3962633609771729f));
        vel.x = func_0038D098(f20) * f21;
        vel.y = func_0038D0B0(f20) * f21;
        vel.z = 0.0f;
        vel.z = func_003824E0(0.0f, 12.0f) * 0.020000001415610313f;
        r = func_00382498(0x1E, 0x32);
        func_L01_004713C8(pos, D_001D66B0, (r * 5 + 2) / 6, 0x407FFF, i, 0x7F, 0x7F, 1,
                          f22 * 210000.0f, 2100.0f, 0.0012000000569969416f);
        i = -(i << 1);
        r = func_00382498(0x1E, 0x32);
        f22 = f22 * 6.0f;
        p = func_L01_004713C8(pos, D_001D66B0, (r * 5 + 2) / 6, 0x20FF, i, 0x30, 0x30, 0,
                              f22 * 210000.0f, 4200.0f, 0.0012000000569969416f);
        n--;
        if (p != 0) {
            p[2] = *D_L01_00221098.w_D4;
        }
        pos++;
    } while (n != 0);
}
