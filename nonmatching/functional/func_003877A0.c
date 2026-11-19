/* functional: high. EXACT under mode S + @ps2as (check.py --target boot_elf --all-modes: "mode S, assembler ps2as: MATCH"); the file 3877A0.c line in config/boot_elf/text_parts.txt needs @ps2as added (default assembler gives 433 diff from literal-pool vs lui constants only). C is the matched frontbin twin func_003873C0 with boot_elf callees (+0x3E0: 0038D540, 0038D478, 0038D068; 003CF1B0) and names suffixed _003877A0 (D_00225900_003877A0, D_00143950_003877A0 need symbol_addrs rows). */
typedef int Q_003877A0 __attribute__((mode(TI)));
typedef union { Q_003877A0 q; f32 f[4]; s32 i[4]; } V_003877A0;
typedef struct {
    s32 fog_color; s32 unk4; s32 unk8; s32 unkC;     /* 0x00 */
    V_003877A0 regs[5];                               /* 0x10 */
    V_003877A0 gif[4];                                /* 0x60 */
    f32 near_clip, far_clip, aspect_x, aspect_y;      /* 0xA0 */
    V_003877A0 fov;                                   /* 0xB0 */
    f32 proj[16];                                     /* 0xC0 */
    f32 proj2[16];                                    /* 0x100 */
    f32 proj3[16];                                    /* 0x140 */
    V_003877A0 inverse_screen_scale;                  /* 0x180 */
    V_003877A0 screen_scale;                          /* 0x190 */
    V_003877A0 screen_bias;                           /* 0x1A0 */
    V_003877A0 inverse_projection_scale;              /* 0x1B0 */
    V_003877A0 viewport_aspect;                       /* 0x1C0 */
    V_003877A0 inverse_viewport_aspect;               /* 0x1D0 */
    V_003877A0 aspect_scale;                          /* 0x1E0 */
    V_003877A0 clip_scale;                            /* 0x1F0 */
    V_003877A0 clip_distances;                        /* 0x200 */
    f32 half_width, half_height, scr_x, scr_y;        /* 0x210 */
    f32 fog_mul, fog_add, fog_near_dist, fog_far_dist; /* 0x220 */
    f32 fog_slope, fog_base, fog_near_int, fog_far_int; /* 0x230 */
    u8 pad240[0x28];
    s32 f268;                                         /* 0x268 */
} S_003877A0;
typedef struct { s32 pal; u8 pad4[0xA9]; u8 fAD; } P_003877A0;
typedef struct { u8 pad[0x28]; s32 mul, max, far_int, near_int; u8 pad38[8]; V_003877A0 scale, bias; } F_003877A0;
typedef struct { u8 pad[0x10]; s32 mul, far_int, near_int; u8 pad1c[0x44]; V_003877A0 constants[3]; u8 pad90[0x10]; s32 x, y; } T_003877A0;

extern S_003877A0 D_00225900_003877A0;
extern P_003877A0 D_00143950_003877A0;
extern V_003877A0 D_00225BC0[4];
extern f32 D_001D9A10[];
extern f32 D_00335D50[];
extern f32 D_001D7B10;
__asm__(".extern D_001D7B10, 16");
extern F_003877A0 D_00335150;
extern F_003877A0 D_00335100;
extern T_003877A0 D_00334F00;
extern f32 D_001D75A0[4];
extern void func_003CF1B0(void);
extern void func_0038D068();

void func_003877A0(void) {
    S_003877A0 *view;
    S_003877A0 *clip_view;
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
    if (D_00143950_003877A0.pal != 0) {
        D_00225900_003877A0.fov.f[1] = D_00225900_003877A0.fov.f[0] * 0.756f;
    } else {
        D_00225900_003877A0.fov.f[1] = D_00225900_003877A0.fov.f[0] * 0.775f;
    }
    if (D_00143950_003877A0.fAD || (D_001D5B98 == 1 && D_00225900_003877A0.f268 != 0)) {
        D_00225900_003877A0.fov.f[1] /= 1.3333333f;
    }
    view = &D_00225900_003877A0;
    view->aspect_x = view->scr_x / view->half_width;
    view->aspect_y = view->scr_y / view->half_height;
    view->fov.f[2] = 1.0f / func_0038D478(func_0038D540(1.0f, view->fov.f[0]));
    view->fov.f[3] = 1.0f / func_0038D478(func_0038D540(1.0f, view->fov.f[1]));
    horizontal_clip_scale = 1.0f / func_0038D478(func_0038D540(1.0f, view->fov.f[0] * view->aspect_x));
    vertical_clip_scale = 1.0f / func_0038D478(func_0038D540(1.0f, view->fov.f[1] * view->aspect_y));
    horizontal_clip_scale /= view->fov.f[2];
    vertical_clip_scale /= view->fov.f[3];
    horizontal_clip_scale += vertical_clip_scale;
    horizontal_clip_scale *= 0.5f;
    if (D_001D5B94 == 2 && view->fov.f[0] < 0.62f)
        horizontal_clip_scale *= 1.15f;
    clip_view = &D_00225900_003877A0;
    clip_view->aspect_scale.f[2] = 1.0f / clip_view->aspect_x;
    clip_view->aspect_scale.f[3] = 1.0f / clip_view->aspect_y;
    clip_view->clip_scale.f[0] = clip_view->fov.f[2];
    clip_view->clip_scale.f[1] = clip_view->fov.f[3];
    clip_view->clip_scale.f[2] = horizontal_clip_scale;
    clip_view->clip_distances.f[0] = clip_view->far_clip;
    clip_view->clip_distances.f[1] = clip_view->near_clip;
    clip_view->aspect_scale.f[0] = clip_view->aspect_x;
    clip_view->aspect_scale.f[1] = clip_view->aspect_y;
    D_00225BC0[0].q = clip_view->fov.q;
    D_00225BC0[1].q = clip_view->aspect_scale.q;
    D_00225BC0[2].q = clip_view->clip_scale.q;
    D_00225BC0[3].q = clip_view->clip_distances.q;

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
    D_001D7B10 = fog_multiplier;
    D_00335D50[0] = fog_multiplier;
    D_001D9A10[0] = fog_multiplier;
    mul_bits = *(s32 *)&clip_view->fog_mul;
    D_00334F00.mul = mul_bits;
    D_00334F00.far_int = far_bits;
    D_00334F00.near_int = near_bits;
    D_00335100.mul = mul_bits;
    D_00335100.far_int = far_bits;
    D_00335100.near_int = near_bits;
    D_00335150.mul = mul_bits;
    D_00335150.far_int = far_bits;
    D_00335150.near_int = near_bits;
    D_00335100.max = 0x437EFFFF;
    D_00335150.max = 0x437EFFFF;
    func_003CF1B0();

    near_clip = clip_view->near_clip;
    far_clip = clip_view->far_clip;
    horizontal_fov = clip_view->fov.f[0];
    vertical_fov = clip_view->fov.f[1];
    viewport_width = clip_view->half_width;
    viewport_height = clip_view->half_height;
    projection_fog_multiplier = clip_view->fog_mul;
    D_001D75A0[0] = 0.5f / 210000.0f;
    D_001D75A0[1] = -0.5f / 210000.0f;
    D_001D75A0[2] = 0.5f;
    D_001D75A0[3] = viewport_width / (horizontal_fov * 210000.0f);
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
    func_0038D068(clip_view->proj2, clip_view->proj, 0x40);
    clip_view->proj2[11] = 1.0f / clip_view->near_clip;
    func_0038D068(clip_view->proj3, clip_view->proj2, 0x40);
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
    D_00334F00.constants[0].q = clip_view->screen_bias.q;
    D_00334F00.constants[1].q = clip_view->inverse_screen_scale.q;
    D_00334F00.constants[2].q = clip_view->screen_scale.q;
    D_00334F00.x = clip_view->viewport_aspect.i[0];
    D_00334F00.y = clip_view->viewport_aspect.i[1];
    D_00335150.scale.q = clip_view->screen_scale.q;
    D_00335150.bias.q = clip_view->screen_bias.q;
}
