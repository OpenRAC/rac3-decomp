#include "common.h"

/* localdecomp:start func_L39_005872D8 */
typedef int Q_005872D8 __attribute__((mode(TI)));
typedef union { Q_005872D8 q; f32 f[4]; s32 i[4]; } V_005872D8;
typedef struct {
    s32 fog_color; s32 unk4; s32 unk8; s32 unkC;     /* 0x00 */
    V_005872D8 regs[5];                               /* 0x10 */
    V_005872D8 gif[4];                                /* 0x60 */
    f32 near_clip, far_clip, aspect_x, aspect_y;      /* 0xA0 */
    V_005872D8 fov;                                   /* 0xB0 */
    f32 proj[16];                                     /* 0xC0 */
    f32 proj2[16];                                    /* 0x100 */
    f32 proj3[16];                                    /* 0x140 */
    V_005872D8 inverse_screen_scale;                  /* 0x180 */
    V_005872D8 screen_scale;                          /* 0x190 */
    V_005872D8 screen_bias;                           /* 0x1A0 */
    V_005872D8 inverse_projection_scale;              /* 0x1B0 */
    V_005872D8 viewport_aspect;                       /* 0x1C0 */
    V_005872D8 inverse_viewport_aspect;               /* 0x1D0 */
    V_005872D8 aspect_scale;                          /* 0x1E0 */
    V_005872D8 clip_scale;                            /* 0x1F0 */
    V_005872D8 clip_distances;                        /* 0x200 */
    f32 half_width, half_height, scr_x, scr_y;        /* 0x210 */
    f32 fog_mul, fog_add, fog_near_dist, fog_far_dist; /* 0x220 */
    f32 fog_slope, fog_base, fog_near_int, fog_far_int; /* 0x230 */
    u8 pad240[0x28];
    s32 f268;                                         /* 0x268 */
} S_005872D8;
typedef struct { u8 pad[0x28]; s32 mul, max, far_int, near_int; u8 pad38[8]; V_005872D8 scale, bias; } F_005872D8;
typedef struct { u8 pad[0x10]; s32 mul, far_int, near_int; u8 pad1c[0x44]; V_005872D8 constants[3]; u8 pad90[0x10]; s32 x, y; } T_005872D8;

typedef struct { s32 pal; u8 pad4[0xA9]; u8 fAD; } P_005872D8;
extern s32 D_001A5810[];
extern s32 D_L39_00242914_005872D8;
extern s32 D_L39_00241128_005872D8;
extern V_005872D8 D_L39_0025D980_005872D8[4];
extern f32 D_L39_0049C150_005872D8[];
extern f32 D_L39_0049BD10_005872D8[];
extern f32 D_L39_00244890_005872D8;
__asm__(".extern D_L39_00244890_005872D8, 16");
extern F_005872D8 D_L39_0049B130_005872D8;
extern F_005872D8 D_L39_0049B0E0_005872D8;
extern T_005872D8 D_L39_0049A8C0_005872D8;
extern f32 D_L39_00244320_005872D8[4];
extern f32 func_0038D160(f32, f32);
extern f32 func_0038D098(f32);
extern void func_003CEDF8(void);
extern void func_0038CC88();

void func_L39_005872D8(void) {
    extern S_005872D8 D_L39_0025D6C0_005872D8;
    S_005872D8 *view;
    S_005872D8 *clip_view;
    f32 depth_scale;
    f32 depth_bias;
    f32 horizontal_clip_scale;
    f32 vertical_clip_scale;
    f32 fog_distance_range;
    f32 fog_intensity_range;
    f32 fog_distance_slope;
    f32 near_clip;
    f32 far_clip;
    f32 fog_multiplier;
    f32 projection_fog_multiplier;
    f32 horizontal_fov;
    f32 vertical_fov;
    f32 viewport_width;
    f32 viewport_height;
    s32 near_bits;
    s32 far_bits;
    s32 mul_bits;

    depth_scale = -8388080.0f;
    depth_bias = 8388112.0f;
    if (((P_005872D8 *)D_001A5810)->pal != 0) {
        D_L39_0025D6C0_005872D8.fov.f[1] = D_L39_0025D6C0_005872D8.fov.f[0] * 0.756f;
    } else {
        D_L39_0025D6C0_005872D8.fov.f[1] = D_L39_0025D6C0_005872D8.fov.f[0] * 0.775f;
    }
    if (((P_005872D8 *)D_001A5810)->fAD || (D_L39_00242914_005872D8 == 1 && D_L39_0025D6C0_005872D8.f268 != 0)) {
        D_L39_0025D6C0_005872D8.fov.f[1] /= 1.3333333f;
    }
    view = &D_L39_0025D6C0_005872D8;
    view->aspect_x = view->scr_x / view->half_width;
    view->aspect_y = view->scr_y / view->half_height;
    view->fov.f[2] = 1.0f / func_0038D098(func_0038D160(1.0f, view->fov.f[0]));
    view->fov.f[3] = 1.0f / func_0038D098(func_0038D160(1.0f, view->fov.f[1]));
    horizontal_clip_scale = 1.0f / func_0038D098(func_0038D160(1.0f, view->fov.f[0] * view->aspect_x));
    vertical_clip_scale = 1.0f / func_0038D098(func_0038D160(1.0f, view->fov.f[1] * view->aspect_y));
    horizontal_clip_scale /= view->fov.f[2];
    vertical_clip_scale /= view->fov.f[3];
    horizontal_clip_scale += vertical_clip_scale;
    horizontal_clip_scale *= 0.5f;
    if (D_L39_00241128_005872D8 == 2 && view->fov.f[0] < 0.62f)
        horizontal_clip_scale *= 1.15f;
    clip_view = &D_L39_0025D6C0_005872D8;
    clip_view->aspect_scale.f[2] = 1.0f / clip_view->aspect_x;
    clip_view->aspect_scale.f[3] = 1.0f / clip_view->aspect_y;
    clip_view->clip_scale.f[0] = clip_view->fov.f[2];
    clip_view->clip_scale.f[1] = clip_view->fov.f[3];
    clip_view->clip_scale.f[2] = horizontal_clip_scale;
    clip_view->clip_distances.f[0] = clip_view->far_clip;
    clip_view->clip_distances.f[1] = clip_view->near_clip;
    clip_view->aspect_scale.f[0] = clip_view->aspect_x;
    clip_view->aspect_scale.f[1] = clip_view->aspect_y;
    D_L39_0025D980_005872D8[0].q = clip_view->fov.q;
    D_L39_0025D980_005872D8[1].q = clip_view->aspect_scale.q;
    D_L39_0025D980_005872D8[2].q = clip_view->clip_scale.q;
    D_L39_0025D980_005872D8[3].q = clip_view->clip_distances.q;

    if (clip_view->fog_far_dist < clip_view->fog_near_dist + 1024.0f)
        clip_view->fog_far_dist = clip_view->fog_near_dist + 1024.0f;

    far_bits = *(s32 *)&clip_view->fog_far_int;
    near_bits = *(s32 *)&clip_view->fog_near_int;
    fog_distance_range = clip_view->fog_far_dist - clip_view->fog_near_dist;
    fog_intensity_range = clip_view->fog_far_int - clip_view->fog_near_int;
    fog_multiplier = fog_intensity_range * clip_view->near_clip / fog_distance_range;
    fog_distance_slope = fog_intensity_range / (fog_distance_range / 1024.0f);
    clip_view->fog_add =
        (clip_view->fog_near_int * clip_view->fog_far_dist - clip_view->fog_far_int * clip_view->fog_near_dist) /
        fog_distance_range;
    clip_view->fog_slope = fog_distance_slope;
    clip_view->fog_base = clip_view->fog_near_int - clip_view->fog_near_dist / 1024.0f * fog_distance_slope;
    clip_view->fog_mul = fog_multiplier;
    D_L39_00244890_005872D8 = fog_multiplier;
    D_L39_0049BD10_005872D8[0] = fog_multiplier;
    D_L39_0049C150_005872D8[0] = fog_multiplier;
    mul_bits = *(s32 *)&clip_view->fog_mul;
    D_L39_0049A8C0_005872D8.mul = mul_bits;
    D_L39_0049A8C0_005872D8.far_int = far_bits;
    D_L39_0049A8C0_005872D8.near_int = near_bits;
    D_L39_0049B0E0_005872D8.mul = mul_bits;
    D_L39_0049B0E0_005872D8.far_int = far_bits;
    D_L39_0049B0E0_005872D8.near_int = near_bits;
    D_L39_0049B130_005872D8.mul = mul_bits;
    D_L39_0049B130_005872D8.far_int = far_bits;
    D_L39_0049B130_005872D8.near_int = near_bits;
    D_L39_0049B0E0_005872D8.max = 0x437EFFFF;
    D_L39_0049B130_005872D8.max = 0x437EFFFF;
    func_003CEDF8();

    near_clip = clip_view->near_clip;
    far_clip = clip_view->far_clip;
    horizontal_fov = clip_view->fov.f[0];
    vertical_fov = clip_view->fov.f[1];
    viewport_width = clip_view->half_width;
    viewport_height = clip_view->half_height;
    projection_fog_multiplier = clip_view->fog_mul;
    D_L39_00244320_005872D8[0] = 0.5f / 210000.0f;
    D_L39_00244320_005872D8[1] = -0.5f / 210000.0f;
    D_L39_00244320_005872D8[2] = 0.5f;
    D_L39_00244320_005872D8[3] = viewport_width / (horizontal_fov * 210000.0f);
    clip_view->proj[0] = viewport_width / (horizontal_fov * near_clip);
    clip_view->proj[1] = 0.0f;
    clip_view->proj[2] = 0.0f;
    clip_view->proj[3] = 0.0f;
    clip_view->proj[4] = 0.0f;
    clip_view->proj[5] = viewport_height / (vertical_fov * near_clip);
    clip_view->proj[6] = 0.0f;
    clip_view->proj[7] = 0.0f;
    clip_view->proj[8] = 0.0f;
    clip_view->proj[9] = 0.0f;
    clip_view->proj[10] = (far_clip + near_clip) / (near_clip * (far_clip - near_clip)) * depth_scale;
    clip_view->proj[11] = 1.0f / near_clip * projection_fog_multiplier;
    clip_view->proj[12] = 0.0f;
    clip_view->proj[13] = 0.0f;
    clip_view->proj[14] = -2.0f * near_clip * far_clip / (near_clip * (far_clip - near_clip)) * depth_scale;
    clip_view->proj[15] = 0.0f;
    func_0038CC88(clip_view->proj2, clip_view->proj, 0x40);
    clip_view->proj2[11] = 1.0f / clip_view->near_clip;
    func_0038CC88(clip_view->proj3, clip_view->proj2, 0x40);
    clip_view->proj3[0] /= clip_view->scr_x;
    clip_view->proj3[5] /= clip_view->scr_y;
    clip_view->proj3[10] /= depth_scale;
    clip_view->proj3[14] /= depth_scale;
    clip_view->inverse_screen_scale.f[0] = 1.0f / clip_view->scr_x;
    clip_view->inverse_screen_scale.f[1] = 1.0f / clip_view->scr_y;
    clip_view->inverse_screen_scale.f[2] = 1.0f / depth_scale;
    clip_view->inverse_screen_scale.f[3] = 1.0f / clip_view->fog_mul;
    clip_view->screen_scale.f[0] = clip_view->scr_x;
    clip_view->screen_scale.f[1] = clip_view->scr_y;
    clip_view->screen_scale.f[2] = depth_scale;
    clip_view->screen_scale.f[3] = clip_view->fog_mul;
    clip_view->inverse_projection_scale.f[0] = clip_view->scr_x / clip_view->proj[0];
    clip_view->inverse_projection_scale.f[1] = clip_view->scr_y / clip_view->proj[5];
    clip_view->inverse_projection_scale.f[2] = depth_scale / clip_view->proj[10];
    clip_view->inverse_projection_scale.f[3] = clip_view->fog_mul;
    clip_view->screen_bias.f[2] = depth_bias;
    clip_view->screen_bias.f[3] = clip_view->fog_add;
    clip_view->viewport_aspect.f[0] = clip_view->scr_x / clip_view->half_width;
    clip_view->viewport_aspect.f[1] = clip_view->scr_y / clip_view->half_height;
    clip_view->viewport_aspect.f[2] = 1.0f;
    clip_view->viewport_aspect.f[3] = 1.0f;
    clip_view->inverse_viewport_aspect.f[0] = 1.0f / clip_view->viewport_aspect.f[0];
    clip_view->inverse_viewport_aspect.f[1] = 1.0f / clip_view->viewport_aspect.f[1];
    clip_view->inverse_viewport_aspect.f[2] = 1.0f;
    clip_view->inverse_viewport_aspect.f[3] = 1.0f;
    clip_view->fog_color = *(s32 *)&clip_view->fog_far_int;
    clip_view->unk4 = 0x103E4000;
    clip_view->unk8 = 0xE;
    clip_view->unkC = 0;

    clip_view->gif[0].i[0] = *(s32 *)&clip_view->fog_mul;
    clip_view->gif[0].i[1] = 0x303E4000;
    clip_view->gif[0].i[2] = 0x412;
    clip_view->gif[0].i[3] = 0x303EC000;
    clip_view->gif[1].i[0] = *(s32 *)&clip_view->fog_mul;
    clip_view->gif[1].i[1] = 0x302E4000;
    clip_view->gif[1].i[2] = 0x412;
    clip_view->gif[1].i[3] = 0x302EC000;
    clip_view->gif[2].i[0] = *(s32 *)&clip_view->fog_mul;
    clip_view->gif[2].i[1] = 0x20364000;
    clip_view->gif[2].i[2] = 0x41;
    clip_view->gif[2].i[3] = 0;
    clip_view->gif[3].i[0] = *(s32 *)&clip_view->fog_mul;
    clip_view->gif[3].i[1] = 0x20264000;
    clip_view->gif[3].i[2] = 0x41;
    clip_view->gif[3].i[3] = 0;
    clip_view->regs[0].q = clip_view->gif[0].q;
    clip_view->regs[1].q = clip_view->viewport_aspect.q;
    clip_view->regs[2].q = clip_view->inverse_screen_scale.q;
    clip_view->regs[3].q = clip_view->screen_scale.q;
    clip_view->regs[4].q = clip_view->screen_bias.q;
    D_L39_0049A8C0_005872D8.constants[0].q = clip_view->screen_bias.q;
    D_L39_0049A8C0_005872D8.constants[1].q = clip_view->inverse_screen_scale.q;
    D_L39_0049A8C0_005872D8.constants[2].q = clip_view->screen_scale.q;
    D_L39_0049A8C0_005872D8.x = clip_view->viewport_aspect.i[0];
    D_L39_0049A8C0_005872D8.y = clip_view->viewport_aspect.i[1];
    D_L39_0049B130_005872D8.scale.q = clip_view->screen_scale.q;
    D_L39_0049B130_005872D8.bias.q = clip_view->screen_bias.q;
}
/* localdecomp:end func_L39_005872D8 */

/* localdecomp:start func_L39_00587A30 */
typedef struct { s32 display, depth, draw, tex_base, f10, f14, f18, f1C, f20; } Vram_00587A30;
typedef struct { u8 pad[0x150]; s16 display_width, display_height, psm, fbp0, storage_width, storage_height; } FsAa_00587A30;
typedef struct { s32 x0, x1, y0, y1; } Rect_00587A30;
typedef struct { u8 pad[0x240]; Rect_00587A30 scissor; } View_00587A30;
typedef struct {
    unsigned long pad0[2];
    unsigned long frame1, pad18, frame2, pad28, zbuf1, pad38, zbuf2, pad48, xyoffset1, pad58, xyoffset2;
} DrawEnv_00587A30;
typedef struct { u8 b[0x60]; } LoadImage_00587A30;

extern Vram_00587A30 D_001FC450;
extern FsAa_00587A30 D_00228580;
extern s32 D_001A5810[];
extern s32 D_L39_002413A0; __asm__(".extern D_L39_002413A0, 16");
extern View_00587A30 D_L39_0025D6C0;
extern DrawEnv_00587A30 D_001A40D0;
extern unsigned long D_001A42A0[];
extern unsigned long D_001A4310[];
extern unsigned long D_L39_002411B0[];
extern u8 D_L39_0025F7C0[];
extern s32 D_L39_002402F0; __asm__(".extern D_L39_002402F0, 16");
extern s32 D_L39_002402F4; __asm__(".extern D_L39_002402F4, 16");
typedef struct { s32 width, height, half_width, half_height, left, top, right, bottom; } Extent_00587A30;
extern Extent_00587A30 D_L39_00240300 __attribute__((section(".sdata")));
extern void func_001264E0(s32);
extern s32 func_001331A0(s32, s32);
extern void func_00139EA0(LoadImage_00587A30 *, s16, s16, s16, s16, s16, s16, s16);
extern void func_0013A1C8(LoadImage_00587A30 *, u8 *);
extern void func_L39_00597230(s32, s32, s32, s32, s32, s32);
extern void func_L39_00597E70(void);
extern void func_00392350(s32);
extern void func_L39_00597E48(void);
extern void func_0038CB78(void *, s32, s32);
extern void func_003D9338(void);

/* from rac2-decomp's func_0027B440 (SetPalMode) */
void func_L39_00587A30(s32 clear) {
    LoadImage_00587A30 image;
    s32 n;
    s32 i;
    unsigned long zbuf;
    unsigned long frame;

    func_001264E0(0);
    if (D_001A5810[0] != 0) {
        D_001FC450.draw = 0x100000;
        D_001FC450.depth = 0x1E0000;
        D_001FC450.display = 0;
        D_001FC450.tex_base = 0x2C0000;
        func_L39_00597230(0x200, 0x1C0, 0x200, 0x200, 4, 0);
    } else if (D_L39_002413A0 != 0) {
        D_001FC450.draw = 0x118000;
        D_001FC450.depth = 0x1E8000;
        D_001FC450.display = 0;
        D_001FC450.tex_base = 0x2C0000;
        func_L39_00597230(0x200, 0x1A0, 0x280, 0x1C0, 0, 0);
    } else {
        D_001FC450.draw = 0x118000;
        D_001FC450.depth = 0x1E8000;
        D_001FC450.display = 0;
        D_001FC450.tex_base = 0x2C0000;
        func_L39_00597230(0x200, 0x1A0, 0x200, 0x1C0, 0, 0);
    }
    D_001FC450.f10 = D_001FC450.tex_base;
    D_001FC450.f14 = D_001FC450.tex_base + 0x1000;
    D_001FC450.f18 = D_001FC450.tex_base + 0x1400;
    D_001FC450.f1C = D_001FC450.tex_base + 0x1800;
    D_001FC450.f20 = D_001FC450.tex_base + 0x1C00;
    D_L39_00240300.width = D_00228580.display_width;
    D_L39_00240300.height = D_00228580.display_height;
    D_L39_00240300.half_width = D_L39_00240300.width >> 1;
    D_L39_00240300.half_height = D_L39_00240300.height >> 1;
    D_L39_00240300.left = (0x800 - D_L39_00240300.half_width) << 4;
    D_L39_00240300.top = (0x800 - D_L39_00240300.half_height) << 4;
    D_L39_00240300.right = (D_L39_00240300.half_width + 0x800) << 4;
    D_L39_00240300.bottom = (D_L39_00240300.half_height + 0x800) << 4;
    D_L39_0025D6C0.scissor.x0 = 0;
    D_L39_0025D6C0.scissor.x1 = D_L39_00240300.width - 1;
    D_L39_0025D6C0.scissor.y0 = 0;
    D_L39_0025D6C0.scissor.y1 = D_L39_00240300.height - 1;
    frame = (D_001FC450.depth >> 13) | ((unsigned long)(D_L39_00240300.width >> 6) << 16);
    D_001A40D0.frame1 = frame;
    zbuf = (D_001FC450.draw >> 13) | 0x1000000;
    D_001A40D0.frame2 = frame;
    D_001A40D0.xyoffset1 = D_L39_00240300.left | ((unsigned long)D_L39_00240300.top << 32);
    D_001A40D0.zbuf1 = zbuf;
    D_001A40D0.zbuf2 = zbuf;
    D_001A40D0.xyoffset2 = D_L39_00240300.left | ((unsigned long)D_L39_00240300.top << 32);
    D_L39_002411B0[2] = D_L39_0025D6C0.scissor.x0 | ((unsigned long)D_L39_0025D6C0.scissor.x1 << 16) | ((unsigned long)D_L39_0025D6C0.scissor.y0 << 32) | ((unsigned long)D_L39_0025D6C0.scissor.y1 << 48);
    D_001A4310[0] = zbuf | ((unsigned long)0x8000 << 17);
    D_001A42A0[0] = zbuf;
    D_L39_002411B0[4] = D_L39_0025D6C0.scissor.x0 | ((unsigned long)D_L39_0025D6C0.scissor.x1 << 16) | ((unsigned long)D_L39_0025D6C0.scissor.y0 << 32) | ((unsigned long)D_L39_0025D6C0.scissor.y1 << 48);
    if (clear) {
        D_L39_002402F0 = D_001FC450.tex_base;
        D_L39_002402F4 = D_001FC450.tex_base;
        func_001264E0(0);
        func_001331A0(0, 0);
        func_001264E0(0);
        func_L39_00597E70();
        func_00392350(0);
        func_001264E0(0);
        func_001331A0(0, 0);
        func_L39_00597E48();
        func_0038CB78(D_L39_0025F7C0, 0, 0x1000);
        n = (D_00228580.storage_width * D_00228580.storage_height) >> 10;
        for (i = 0; i < n; i++) {
            func_00139EA0(&image, i << 4, 1, 0, 0, 0, 32, 32);
            func_001264E0(0);
            func_0013A1C8(&image, D_L39_0025F7C0);
            func_001331A0(0, 0);
        }
    }
    func_003D9338();
}
/* localdecomp:end func_L39_00587A30 */
